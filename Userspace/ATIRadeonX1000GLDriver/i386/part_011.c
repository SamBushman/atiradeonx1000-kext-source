#include "decls.h"

/* FUN_00074eba @ 0x74eba (104 bytes) */
int FUN_00074eba(param_1, param_2, param_3)
  uint *param_1;
  int param_2;
  uint param_3;
{
  if (param_2 == 1) {
    *param_1 = *param_1 & 0xfff8ffff | (param_3 & 7) << 0x10;
    return;
  }
  if (param_2 == 0) {
    *param_1 = *param_1 & 0xffff1fff | (param_3 & 7) << 0xd;
    return;
  }
  if (param_2 == 2) {
    *param_1 = *param_1 & 0xffc7ffff | (param_3 & 7) << 0x13;
    return;
  }
  if (param_2 != 3) {
    return;
  }
  *param_1 = *param_1 & 0xfe3fffff | (param_3 & 7) << 0x16;
  return;
}

/* FUN_00074f22 @ 0x74f22 (138 bytes) */
int FUN_00074f22(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
{
  int iVar1;
  int iVar2;
  
  if ((param_3 != param_2) && (*(char *)(param_3 + 0x30c50 + param_1) == '\0')) {
    *(undefined1 *)(param_3 + 0x30c50 + param_1) = 1;
    iVar1 = FUN_00074dcd(param_4,0,0,param_1 + 0x38);
    if (iVar1 != 0) {
      return iVar1;
    }
    for (iVar1 = *(int *)(param_1 + 0xc450 + param_3 * 4); iVar1 != 0;
        iVar1 = *(int *)(iVar1 + 0x10)) {
      iVar2 = ((int (*)())FUN_00074f22)(*(undefined4 *)(iVar1 + 4));
      if (iVar2 != 0) {
        return iVar2;
      }
    }
  }
  return 0;
}

/* FUN_00074fac @ 0x74fac (465 bytes) */
int FUN_00074fac(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
  int param_6;
{
  ushort *puVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  uint *puVar7;
  bool bVar8;
  byte local_14;
  int local_10;
  
  iVar3 = (param_6 + param_5 * 4) * 4;
  puVar1 = (ushort *)(iVar3 + 4 + param_2);
  iVar4 = FUN_00074e72();
  if ((1 < iVar4 - 4U) && (param_5 = param_5 + -1, -1 < param_5)) {
    puVar7 = (uint *)(param_2 + param_5 * 0x10);
    local_10 = 0;
    local_14 = (byte)iVar4;
    do {
      bVar2 = *(byte *)((int)puVar7 + 1) & 0xf;
      bVar6 = (byte)*puVar1 & 0xf;
      if (bVar6 == 1) {
        bVar8 = bVar2 == 5;
LAB_0007506c:
        if (((!bVar8) || ((*puVar7 >> 0xd & 0x7f) != (uint)(byte)(*puVar1 >> 5))) ||
           (iVar5 = FUN_000743b5(), iVar5 == 0)) goto LAB_00075048;
        if ((char)*puVar7 == 'A') {
          if (((**(uint **)(param_1 + 0x34) & 0x280) == 0) || (iVar4 != 3)) goto LAB_000750a3;
          ((int (*)())FUN_00074eba)();
          if (param_3 == 0) goto LAB_00075173;
          *(undefined4 *)(iVar3 + 4 + param_3) = *(undefined4 *)puVar1;
          bVar8 = true;
        }
        else if (((char)*puVar7 == 'D') && ((iVar4 == 0 || (iVar4 == 3)))) {
          ((int (*)())FUN_00074eba)();
          if ((param_3 == 0) || ((*(byte *)(*(int *)(param_1 + 0x34) + 1) & 2) == 0)) {
LAB_00075173:
            bVar8 = true;
          }
          else {
            *(undefined4 *)(iVar3 + 4 + param_3) = *(undefined4 *)puVar1;
            bVar8 = true;
          }
        }
        else {
LAB_000750a3:
          FUN_00074dcd(1 << (local_14 & 0x1f),0,0,param_4);
          bVar8 = true;
        }
      }
      else {
        if (bVar6 == 0) {
          bVar8 = bVar2 == 0;
          goto LAB_0007506c;
        }
        if (bVar6 == 3) {
          bVar8 = bVar2 == 4;
          goto LAB_0007506c;
        }
LAB_00075048:
        bVar8 = false;
      }
      if (param_5 == local_10) {
        return;
      }
      local_10 = local_10 + 1;
      puVar7 = puVar7 + -4;
    } while (!bVar8);
  }
  return;
}

/* FUN_0007517d @ 0x7517d (73 bytes) */
int FUN_0007517d(param_1)
  int param_1;
{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  
  if ((((*(byte *)(param_1 + 4) & 0xf) == 0) && ((*(byte *)(param_1 + 8) & 0xf) == 0)) &&
     ((*(byte *)(param_1 + 0xc) & 0xf) == 0)) {
    uVar2 = *(ushort *)(param_1 + 4) & 0x1fe0;
    uVar3 = *(ushort *)(param_1 + 8) & 0x1fe0;
    if (((uVar2 != uVar3) && (uVar1 = *(ushort *)(param_1 + 0xc) & 0x1fe0, uVar3 != uVar1)) &&
       (uVar2 != uVar1)) {
      return 1;
    }
  }
  return 0;
}

/* FUN_000751c6 @ 0x751c6 (434 bytes) */
int FUN_000751c6(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  byte bVar8;
  char cVar9;
  uint *puVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int *piVar15;
  int *local_1c;
  undefined4 local_14;
  
  uVar1 = *(uint *)(param_1 + 0x2a878);
  if (uVar1 != 0) {
    uVar13 = 0;
    local_14 = 6;
    bVar7 = false;
    do {
      iVar2 = *(int *)(param_1 + 0x28878 + uVar13 * 4);
      puVar10 = (uint *)(((unsigned char *)0x0001286c) + iVar2 * 0x10 + param_1);
      if ((((param_2 != '\0') && ((**(byte **)(param_1 + 0x34) & 0x40) != 0)) &&
          (bVar8 = (char)*puVar10 + 0xbc, bVar8 < 0xb)) &&
         (((1 << (bVar8 & 0x1f) & 0x601U) != 0 && (cVar9 = ((int (*)())FUN_0007517d)(), cVar9 != '\0')))) {
        bVar7 = true;
        local_14 = 8;
      }
      local_1c = *(int **)(param_1 + 0xa450 + iVar2 * 4);
      if (local_1c != (int *)0x0) {
        uVar14 = uVar13 + 1;
LAB_0007526f:
        do {
          if (uVar14 < uVar1) {
            uVar3 = *puVar10;
            iVar2 = *local_1c;
            piVar15 = (int *)(param_1 + uVar14 * 4 + 0x28878);
            uVar12 = uVar14;
            do {
              iVar4 = *piVar15;
              if (((*(uint *)(((unsigned char *)0x0001286c) + iVar4 * 0x10 + param_1) & 0xfef00) ==
                   (uVar3 & 0xfef00)) && (uVar11 = FUN_00073220(), (local_1c[1] & uVar11) != 0)) {
                bVar6 = true;
                bVar5 = true;
                if (uVar1 != uVar12 + 1) goto LAB_000752c4;
LAB_0007531d:
                if (bVar6) {
LAB_00075321:
                  if (iVar4 != iVar2) {
                    bVar7 = true;
                    local_14 = 9;
                    local_1c = (int *)local_1c[4];
                    if (local_1c == (int *)0x0) goto LAB_000752df;
                    goto LAB_0007526f;
                  }
                }
                break;
              }
              bVar5 = false;
              bVar6 = bVar5;
              if (uVar1 == uVar12 + 1) goto LAB_0007531d;
LAB_000752c4:
              uVar12 = uVar12 + 1;
              if (bVar5) goto LAB_00075321;
              piVar15 = piVar15 + 1;
            } while (iVar4 != iVar2);
          }
          local_1c = (int *)local_1c[4];
        } while (local_1c != (int *)0x0);
      }
LAB_000752df:
      uVar13 = uVar13 + 1;
    } while (uVar13 < uVar1);
    if (bVar7) {
      return local_14;
    }
  }
  return 0;
}

/* FUN_00075378 @ 0x75378 (25 bytes) */
int FUN_00075378(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x414) = 0;
  *(undefined4 *)(param_1 + 0x410) = 0;
  return;
}

/* FUN_00075391 @ 0x75391 (129 bytes) */
int FUN_00075391(param_1)
  int param_1;
{
  int iVar1;
  undefined4 local_10;
  
  if (*(int *)(param_1 + 0x408) == 0) {
    *(undefined4 *)(param_1 + 0x408) = 0;
    *(undefined4 *)(param_1 + 0x40c) = 0;
    ((int (*)())FUN_00075378)();
    return;
  }
  local_10 = 0;
  iVar1 = param_1;
  do {
    (**(code **)(param_1 + 4))(*(undefined4 *)(iVar1 + 8));
    *(undefined4 *)(iVar1 + 8) = 0;
    local_10 = local_10 + 1;
    iVar1 = iVar1 + 4;
  } while (local_10 < *(uint *)(param_1 + 0x408));
  *(undefined4 *)(param_1 + 0x408) = 0;
  *(undefined4 *)(param_1 + 0x40c) = 0;
  ((int (*)())FUN_00075378)();
  return;
}

/* FUN_00075412 @ 0x75412 (55 bytes) */
int FUN_00075412(param_1)
  int param_1;
{
  if (param_1 != 0) {
    ((int (*)())FUN_00075391)();
    ((int (*)())FUN_00075391)();
                    
                    
    (**(code **)(((unsigned char *)0x00012458) + param_1))();
    return;
  }
  return;
}

/* FUN_00075449 @ 0x75449 (18 bytes) */
int FUN_00075449(param_1)
  int param_1;
{
                    
                    
  (**(code **)(param_1 + 0xc))();
  return;
}

/* FUN_0007545b @ 0x7545b (18 bytes) */
int FUN_0007545b(param_1)
  int param_1;
{
                    
                    
  (**(code **)(param_1 + 0x18))();
  return;
}

/* FUN_0007546d @ 0x7546d (745 bytes) */
int FUN_0007546d(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  bool bVar4;
  byte bVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  uint *puVar11;
  uint local_44;
  int local_3c;
  int local_38;
  byte local_34;
  uint *local_1c;
  undefined4 *local_18;
  
  puVar6 = (uint *)(((unsigned char *)0x0001286c) + param_2 * 0x10 + param_1);
  uVar1 = *(uint *)(param_1 + 0x6450 + param_2 * 4);
  uVar7 = FUN_00073220();
  local_44 = 0;
  iVar8 = 0;
  do {
    if ((uVar7 & 1 << ((byte)iVar8 & 0x1f)) != 0) {
      local_44 = local_44 | 1 << ((byte)(param_3 >> ((byte)iVar8 * '\x04' & 0x1f)) & 0xf);
    }
    iVar8 = iVar8 + 1;
  } while (iVar8 != 4);
  if (uVar7 != local_44) {
    local_3c = 0;
    bVar5 = 0xd;
    do {
      if ((uVar7 & 1 << ((byte)local_3c & 0x1f)) != 0) {
        local_34 = ((byte)(param_3 >> ((byte)(local_3c << 2) & 0x1f)) & 0xf) * '\x03' + 0xd;
        iVar8 = 0;
        puVar11 = puVar6;
        do {
          if ((uVar1 & 1 << ((byte)iVar8 & 0x1f)) != 0) {
            uVar2 = puVar11[1];
            puVar11[1] = (~(7 << (bVar5 & 0x1f)) & uVar2 |
                         (uVar2 >> (local_34 & 0x1f) & 7) << (bVar5 & 0x1f)) &
                         ~(7 << (local_34 & 0x1f)) |
                         (uVar2 >> (bVar5 & 0x1f) & 7) << (local_34 & 0x1f);
          }
          iVar8 = iVar8 + 1;
          puVar11 = puVar11 + 1;
        } while (iVar8 != 3);
      }
      local_3c = local_3c + 1;
      bVar5 = bVar5 + 3;
    } while (local_3c != 4);
    *puVar6 = *puVar6 & 0xff0fffff | local_44 << 0x14;
    for (piVar3 = *(int **)(param_1 + 0xa450 + param_2 * 4); piVar3 != (int *)0x0;
        piVar3 = (int *)piVar3[4]) {
      iVar8 = *piVar3;
      local_1c = (uint *)(((unsigned char *)0x00012870) + iVar8 * 0x10 + param_1);
      uVar1 = *(uint *)(param_1 + 0x6450 + iVar8 * 4);
      uVar7 = 0;
      iVar9 = 0;
      do {
        if ((piVar3[1] & 1 << ((byte)iVar9 & 0x1f)) != 0) {
          uVar7 = uVar7 | 1 << ((byte)(param_3 >> ((byte)iVar9 * '\x04' & 0x1f)) & 0xf);
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 != 4);
      piVar3[1] = uVar7;
      local_18 = (undefined4 *)(param_1 + 0x450 + iVar8 * 0xc);
      local_38 = 0;
      do {
        if (((uVar1 & 1 << ((byte)local_38 & 0x1f)) != 0) &&
           (piVar10 = (int *)*local_18, piVar10 != (int *)0x0)) {
          bVar4 = false;
          do {
            while (param_2 != *piVar10) {
              piVar10 = (int *)piVar10[4];
              if (piVar10 == (int *)0x0) goto LAB_000756d6;
            }
            uVar7 = 0;
            iVar8 = 0;
            do {
              if ((piVar10[1] & 1 << ((byte)iVar8 & 0x1f)) != 0) {
                uVar7 = uVar7 | 1 << ((byte)(param_3 >> ((byte)iVar8 * '\x04' & 0x1f)) & 0xf);
              }
              iVar8 = iVar8 + 1;
            } while (iVar8 != 4);
            piVar10[1] = uVar7;
            bVar4 = true;
            piVar10 = (int *)piVar10[4];
          } while (piVar10 != (int *)0x0);
LAB_000756d6:
          if (bVar4) {
            *local_1c = *local_1c & 0x9fffffff |
                        (param_3 >> ((*(byte *)((int)local_1c + 3) >> 5 & 3) << 2) & 3) << 0x1d;
          }
        }
        local_38 = local_38 + 1;
        local_1c = local_1c + 1;
        local_18 = local_18 + 1;
      } while (local_38 != 3);
    }
    for (iVar8 = *(int *)(param_1 + 0xc450 + param_2 * 4); iVar8 != 0;
        iVar8 = *(int *)(iVar8 + 0x10)) {
      ((int (*)())FUN_0007546d)();
    }
  }
  return;
}

/* FUN_00075756 @ 0x75756 (1385 bytes) */
int FUN_00075756(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
  int param_5;
  undefined1 *param_6;
  uint *param_7;
{
  int *piVar1;
  bool bVar2;
  char cVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  byte bVar11;
  int *piVar12;
  int iVar13;
  int local_60;
  uint local_2c;
  int local_28;
  int local_24;
  uint local_20;
  
  puVar4 = (uint *)(param_5 * 0x10 + param_2);
  *param_6 = 0;
  *param_7 = 0xffffffff;
  cVar3 = FUN_000731c4();
  if (cVar3 == '\0') {
    cVar3 = FUN_000731ef();
    if (cVar3 != '\0') {
      uVar6 = FUN_0007361f();
      uVar9 = FUN_00073220();
      uVar10 = (uint)*(char *)(param_1 + 0x30b9c);
      uVar5 = 0;
      local_20 = 0x3210;
      iVar13 = 0;
      while (((uVar6 & uVar10 & 1 << ((byte)iVar13 & 0x1f)) == 0 || (4 < uVar5))) {
LAB_00075bc0:
        iVar13 = iVar13 + 1;
        if (iVar13 == 4) goto LAB_00075bcf;
      }
joined_r0x000759cb:
      if (uVar5 != 4) {
        if ((1 << ((byte)uVar5 & 0x1f) & ~(uVar6 | uVar10)) == 0) goto code_r0x000759de;
        bVar11 = (byte)iVar13 * '\x04';
        local_20 = local_20 & ~(0xf << (bVar11 & 0x1f)) | uVar5 << (bVar11 & 0x1f);
        uVar5 = uVar5 + 1;
        goto LAB_00075bc0;
      }
      local_2c = 0;
      iVar13 = 0;
      do {
        if ((uVar9 & 1 << ((byte)iVar13 & 0x1f)) != 0) {
          local_2c = local_2c | 1 << ((byte)(local_20 >> ((byte)iVar13 * '\x04' & 0x1f)) & 0xf);
        }
        iVar13 = iVar13 + 1;
      } while (iVar13 != 4);
      uVar5 = 0;
      iVar13 = 0;
      do {
        if ((uVar6 & 1 << ((byte)iVar13 & 0x1f)) != 0) {
          uVar5 = uVar5 | 1 << ((byte)(local_20 >> ((byte)iVar13 * '\x04' & 0x1f)) & 0xf);
        }
        iVar13 = iVar13 + 1;
      } while (iVar13 != 4);
      uVar10 = uVar10 & uVar5;
      if (uVar10 == 0) goto LAB_00075bcf;
      iVar13 = 0;
      local_60 = param_1;
      do {
        uVar5 = 1 << ((byte)iVar13 & 0x1f);
        if (((((uVar5 & uVar10) != 0) &&
             (piVar12 = *(int **)(local_60 + 0x30b7c), piVar12 != (int *)0x0)) &&
            (param_5 == *piVar12)) && (piVar12[1] == 0)) {
          uVar10 = uVar10 & ~uVar5;
        }
        iVar13 = iVar13 + 1;
        local_60 = local_60 + 4;
      } while (iVar13 != 4);
      if (uVar10 != 0) {
        local_24 = 0;
        iVar13 = param_1;
        do {
          uVar5 = 1 << ((byte)local_24 & 0x1f);
          if ((uVar5 & uVar10) != 0) {
            if ((local_2c & uVar5) == 0) {
              piVar12 = *(int **)(param_1 + 0xc450 + param_5 * 4);
              if (piVar12 != (int *)0x0) {
                do {
                  if (((piVar12[1] & uVar5) == 0) || (*piVar12 != *(int *)(iVar13 + 0x30b8c))) {
                    bVar2 = false;
                  }
                  else {
                    bVar2 = true;
                  }
                  piVar12 = (int *)piVar12[4];
                  if (piVar12 == (int *)0x0) {
                    if (!bVar2) goto LAB_00075adb;
                    break;
                  }
                } while (!bVar2);
LAB_00075c55:
                uVar10 = uVar10 & ~uVar5;
              }
            }
            else if (param_5 == *(int *)(iVar13 + 0x30b8c)) goto LAB_00075c55;
          }
LAB_00075adb:
          local_24 = local_24 + 1;
          iVar13 = iVar13 + 4;
        } while (local_24 != 4);
        if (uVar10 != 0) {
          local_28 = 0;
          iVar13 = param_1;
          do {
            uVar5 = 1 << ((byte)local_28 & 0x1f);
            if ((((uVar5 & uVar10) != 0) && ((local_2c & uVar5) == 0)) &&
               (piVar12 = *(int **)(param_1 + 0xe450 + param_5 * 4), piVar12 != (int *)0x0)) {
              do {
                if (((piVar12[1] & uVar5) == 0) || (*piVar12 != *(int *)(iVar13 + 0x30b8c))) {
                  bVar2 = false;
                }
                else {
                  bVar2 = true;
                }
                piVar12 = (int *)piVar12[4];
                if (piVar12 == (int *)0x0) {
                  if (!bVar2) goto LAB_00075b50;
                  break;
                }
              } while (!bVar2);
              uVar10 = uVar10 & ~uVar5;
            }
LAB_00075b50:
            local_28 = local_28 + 1;
            iVar13 = iVar13 + 4;
          } while (local_28 != 4);
          if (uVar10 != 0) {
            local_20 = 0xffffffff;
          }
        }
      }
LAB_00075bcf:
      *param_7 = local_20;
      if (local_20 == 0xffffffff) {
        return 0;
      }
      if (local_20 != 0x3210) {
        *param_6 = 1;
      }
    }
  }
  else if (((*(byte *)(param_1 + 0x3348d + param_5 * 4) & 0x10) == 0) ||
          (cVar3 = FUN_00073e3c(param_6,param_7), cVar3 == '\0')) {
    uVar5 = FUN_00073220();
    for (piVar12 = *(int **)(param_1 + 0xe450 + param_5 * 4); piVar12 != (int *)0x0;
        piVar12 = (int *)piVar12[4]) {
      iVar13 = *piVar12;
      uVar6 = FUN_00073220();
      if (((uVar5 & uVar6) != 0) && ((*(byte *)(param_1 + 0x3348e + iVar13 * 4) & 4) != 0)) {
        for (piVar1 = *(int **)(param_1 + 0xa450 + iVar13 * 4); piVar1 != (int *)0x0;
            piVar1 = (int *)piVar1[4]) {
          if (((param_5 != *piVar1) && ((piVar1[1] & uVar5 & uVar6) != 0)) &&
             ((*(byte *)(param_1 + 0x3348e + *piVar1 * 4) & 4) == 0)) {
            return 0;
          }
        }
      }
    }
    uVar7 = FUN_0007361f();
    cVar3 = FUN_00073610();
    if ((cVar3 == '\0') || ((*puVar4 >> 0xd & 0x7f) < param_4)) {
      uVar8 = FUN_00073220();
      cVar3 = FUN_00073652(uVar7,param_5,uVar8);
      if (cVar3 == '\0') {
        return 1;
      }
      cVar3 = FUN_00073610();
    }
    else {
      cVar3 = FUN_00073610();
    }
    if (cVar3 == '\0') {
      if (((*puVar4 & 0xf00) == 0x400) && (param_3 != '\0')) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      if (bVar2) {
        uVar7 = FUN_00073220();
        uVar5 = FUN_00073a18(param_5,uVar7);
        *param_7 = uVar5;
      }
    }
    else {
      uVar8 = FUN_00073220();
      if (param_4 != 0) {
        uVar5 = 0;
        do {
          cVar3 = FUN_00073652(uVar7,param_5,uVar8);
          if (cVar3 == '\0') {
            *param_7 = uVar5;
            goto LAB_0007588d;
          }
          uVar5 = uVar5 + 1;
        } while (param_4 != uVar5);
      }
      *param_7 = 0xffffffff;
    }
LAB_0007588d:
    if ((int)*param_7 < 0) {
      return 0;
    }
    *param_6 = 1;
    return 1;
  }
  return 1;
code_r0x000759de:
  uVar5 = uVar5 + 1;
  if (uVar5 == 5) goto LAB_00075bc0;
  goto joined_r0x000759cb;
}

/* FUN_00075cbf @ 0x75cbf (1452 bytes) */
int FUN_00075cbf(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  uint param_3;
  undefined1 *param_4;
  undefined4 *param_5;
  int param_6;
{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  bool bVar6;
  bool bVar7;
  char cVar8;
  byte bVar9;
  byte bVar10;
  int iVar11;
  int iVar12;
  byte *pbVar13;
  int iVar14;
  byte *pbVar15;
  byte *pbVar16;
  int iVar17;
  ushort *puVar18;
  undefined4 *local_a0;
  uint local_74;
  int local_70;
  undefined1 local_65;
  undefined4 local_64;
  int local_5c;
  int local_54;
  uint local_4c;
  int local_3c;
  int local_38;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_1e;
  undefined1 local_1d [13];
  
  local_1d[0] = 0;
  local_24 = 0;
  *param_4 = 0;
  if (param_2 == 0) {
    local_54 = 0;
    iVar14 = *(int *)(param_1 + 0x35490);
    if (iVar14 != 2) goto LAB_00075d17;
LAB_00075f40:
    iVar14 = *(int *)(param_1 + 0x35494);
    *(undefined4 *)(param_1 + 0x35490) = 3;
    cVar8 = FUN_00073e3c(param_4,param_5);
    if (cVar8 != '\0') {
      FUN_00073f79();
      return iVar14;
    }
  }
  else {
    iVar11 = 0;
    local_54 = 0;
    iVar14 = param_1;
    do {
      local_54 = local_54 + (uint)(*(char *)(iVar14 + 0x3087c) == '\0');
      iVar11 = iVar11 + 1;
      iVar14 = iVar14 + 1;
    } while (param_2 != iVar11);
    iVar14 = *(int *)(param_1 + 0x35490);
    if (iVar14 == 2) goto LAB_00075f40;
LAB_00075d17:
    if (iVar14 == 3) {
      *(undefined4 *)(param_1 + 0x35490) = 0;
      iVar14 = *(int *)(param_1 + 0x28874);
      goto joined_r0x00075d3b;
    }
    if (iVar14 == 1) {
      iVar14 = *(int *)(param_1 + 0x35498);
      local_1e = 0;
      cVar8 = ((int (*)())FUN_00075756)(param_2,iVar14,&local_1e,&local_28);
      *(undefined4 *)(param_1 + 0x35490) = 3;
      if (cVar8 != '\0') {
        *param_4 = local_1e;
        *param_5 = local_28;
        FUN_00073f79();
        return iVar14;
      }
    }
  }
  iVar14 = *(int *)(param_1 + 0x28874);
joined_r0x00075d3b:
  if (iVar14 != 0) {
    iVar14 = 0;
    local_70 = -1;
    local_74 = 0;
    local_65 = 0;
    local_64 = 0;
    bVar7 = false;
    local_38 = param_1;
    do {
      local_1d[0] = 0;
      iVar11 = 0;
      do {
        iVar11 = iVar11 + 1;
      } while (iVar11 != 3);
      cVar8 = ((int (*)())FUN_00075756)(param_2,*(undefined4 *)(local_38 + 0x26874),local_1d,&local_24);
      if (cVar8 != '\0') {
        if (*(uint *)(local_38 + 0x22870) < param_3) {
          iVar11 = 100;
        }
        else {
          iVar11 = 0;
        }
        iVar3 = *(int *)(local_38 + 0x26874);
        iVar11 = iVar11 + *(int *)(((unsigned char *)0x00010454) + iVar3 * 4 + param_1) * 2;
        iVar12 = iVar11 + 0x20;
        if (*(int *)(param_1 + 0x8450 + iVar3 * 4) == 0) {
          iVar12 = iVar11;
        }
        uVar4 = *(uint *)(param_1 + 0x6450 + iVar3 * 4);
        puVar18 = (ushort *)(param_6 + 4 + iVar3 * 0x10);
        local_5c = 0;
        iVar11 = 0;
        do {
          if (((uVar4 & 1 << ((byte)iVar11 & 0x1f)) != 0) && (cVar8 = FUN_00073a73(), cVar8 != '\0')
             ) {
            local_a0 = (undefined4 *)
                       (CONCAT11((DAT_001c63b0)[(byte)*puVar18 & 0xf],(char)(*puVar18 >> 5)) * 0x10
                        + 0x2a87c + param_1);
            bVar6 = true;
            iVar17 = 0;
            do {
              piVar5 = (int *)*local_a0;
              if ((piVar5 != (int *)0x0) && ((iVar3 != *piVar5 || (piVar5[1] != 0)))) {
                bVar6 = false;
              }
              if (iVar17 == 3) {
                local_5c = (local_5c + 1) - (uint)!bVar6;
                break;
              }
              iVar17 = iVar17 + 1;
              local_a0 = local_a0 + 1;
            } while (bVar6);
          }
          iVar11 = iVar11 + 1;
          puVar18 = puVar18 + 2;
        } while (iVar11 != 3);
        iVar12 = iVar12 + (param_2 - local_54) * local_5c * 2;
        if ((local_70 < iVar12) || (local_74 == 0)) {
          local_65 = local_1d[0];
          local_64 = local_24;
          bVar7 = true;
          local_70 = iVar12;
          iVar14 = iVar3;
        }
      }
      local_74 = local_74 + 1;
      local_38 = local_38 + 4;
    } while (local_74 < *(uint *)(param_1 + 0x28874));
    if (bVar7) {
      *param_4 = local_65;
      *param_5 = local_64;
      pbVar13 = (byte *)(iVar14 * 0x10 + param_6);
      bVar9 = *pbVar13 >> 6 & 1;
      cVar8 = (*(code *)(PTR_FUN_001fb680)[bVar9])(param_1,iVar14);
      if ((cVar8 != '\0') && (*(int *)(param_1 + 0x28874) != 0)) {
        pcVar1 = (char *)(param_1 + 0x3148c + iVar14 * 4);
        local_4c = 0;
        local_3c = param_1;
        do {
          iVar11 = *(int *)(local_3c + 0x26874);
          pbVar15 = (byte *)(iVar11 * 0x10 + param_6);
          bVar10 = *pbVar15 >> 6 & 1;
          cVar8 = (*(code *)(PTR_FUN_001fb680)[bVar10])(param_1,iVar11);
          if ((cVar8 != '\0') && (bVar9 != bVar10)) {
            pcVar2 = (char *)(param_1 + 0x3148c + iVar11 * 4);
            pbVar16 = pbVar13;
            if ((*pbVar13 & 0x40) != 0) {
              pbVar16 = pbVar15;
            }
            if (((((int)*pcVar1 + (int)*pcVar2 < 3) && ((int)pcVar1[1] + (int)pcVar2[1] < 2)) &&
                ((int)pcVar1[2] + (int)pcVar2[2] < 2)) &&
               (((int)pcVar1[3] + (int)pcVar2[3] < 2 && ((pbVar16[1] & 0xf) != 4)))) {
              if (bVar9 == 0) {
                *(int *)(param_1 + 0x35494) = iVar11;
                *(int *)(param_1 + 0x35498) = iVar14;
              }
              else {
                *(int *)(param_1 + 0x35494) = iVar14;
                *(int *)(param_1 + 0x35498) = iVar11;
              }
              if (*(int *)(param_1 + 0x35494) != iVar14) {
                *(undefined4 *)(param_1 + 0x35490) = 2;
                return iVar14;
              }
              cVar8 = FUN_00073e3c(&local_1e,&local_28);
              if (cVar8 != '\0') {
                *(undefined4 *)(param_1 + 0x35490) = 1;
                *param_4 = local_1e;
                *param_5 = local_28;
                return iVar14;
              }
              *(undefined4 *)(param_1 + 0x35490) = 0;
              return iVar14;
            }
          }
          local_4c = local_4c + 1;
          local_3c = local_3c + 4;
        } while (local_4c < *(uint *)(param_1 + 0x28874));
      }
      return iVar14;
    }
  }
  return -1;
}

/* FUN_0007626b @ 0x7626b (6872 bytes) */
int FUN_0007626b(param_1)
  int param_1;
{
  int iVar1;
  bool bVar2;
  undefined1 uVar3;
  char cVar4;
  byte bVar5;
  char *pcVar6;
  int iVar7;
  uint *puVar8;
  undefined4 uVar9;
  uint uVar10;
  uint *puVar11;
  int *piVar12;
  int iVar13;
  int *piVar14;
  int *piVar15;
  uint uVar16;
  uint uVar17;
  char *pcVar18;
  uint uVar19;
  undefined4 *puVar20;
  uint *puVar21;
  uint uVar22;
  int iVar23;
  int *piVar24;
  ushort *puVar25;
  byte *pbVar26;
  uint uVar27;
  uint *puVar28;
  undefined4 uVar29;
  int local_1b0;
  int local_19c;
  int local_198;
  uint local_188;
  uint local_14c;
  uint local_144;
  int local_130;
  uint local_128;
  byte local_124;
  int local_11c;
  int local_114;
  int local_104;
  int *local_fc;
  int local_f8;
  int *local_f0;
  int local_e4;
  uint local_e0;
  uint local_dc;
  uint local_d8;
  int local_d4;
  char local_c5;
  byte local_ad;
  byte local_a5;
  byte local_99;
  int local_90;
  ushort *local_8c;
  uint *local_84;
  int local_80;
  int local_7c;
  int local_78;
  uint *local_68;
  uint *local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_50;
  uint local_48 [4];
  uint local_38 [3];
  char local_2c;
  char local_2b;
  char local_2a;
  char local_29;
  char local_28;
  char local_27;
  char local_26;
  char local_25;
  undefined1 local_24 [7];
  char local_1d [13];
  
  puVar21 = *(uint **)(param_1 + 0x34);
  local_188 = *puVar21;
  local_144 = (-(uint)((local_188 >> 6 & 1) == 0) & 0xfffffffe) + 0xe;
  iVar7 = *(int *)(param_1 + 0x2286c);
  pcVar6 = ((unsigned char *)0x0001286c) + param_1;
  if ((((local_188 >> 6 & 1) != 0) && ((local_188 & 0x400) != 0)) && (iVar7 != 0)) {
    local_130 = 0;
    local_7c = 0;
    iVar23 = param_1 + 0x3348c;
    local_78 = param_1;
    do {
      pbVar26 = (byte *)(pcVar6 + local_130 * 0x10);
      FUN_00073ff9();
      if ((*pbVar26 & 0x40) == 0) {
        puVar28 = (uint *)(local_7c + iVar23);
        uVar16 = *puVar28;
        *puVar28 = uVar16 | 0x10;
        uVar27 = FUN_00073a81();
        if ((uVar27 & 4) == 0) {
          *puVar28 = uVar16 | 0x30;
        }
      }
      else {
        puVar28 = (uint *)(local_7c + iVar23);
        uVar16 = *puVar28;
        *puVar28 = uVar16 | 1;
        uVar27 = FUN_00073220();
        if ((((((uVar27 & uVar27 - 1) == 0) &&
              (iVar13 = (*pbVar26 & 0xffffffbf) * 0x14, *(int *)(&DAT_001c6240 + iVar13) != 0)) &&
             (((DAT_001c6250)[iVar13] == '\0' || ((local_188 >> 0xd & 1) != 0)))) &&
            (1 < (byte)((pbVar26[1] & 0xf) - 2))) &&
           ((*(int *)(&DAT_001c6244 + iVar13) == 1 ||
            ((*(int *)(&DAT_001c6244 + iVar13) == 2 &&
             ((*(uint *)(pbVar26 + *(int *)(&DAT_001c6248 + iVar13) * 4 + 4) & 0x60001fff) ==
              (*(uint *)(pbVar26 + *(int *)(&DAT_001c624c + iVar13) * 4 + 4) & 0x60001fff))))))) {
          *puVar28 = uVar16 | 3;
          piVar24 = *(int **)(local_78 + 0xc450);
          *puVar28 = uVar16 | 0x1003;
          for (; piVar24 != (int *)0x0; piVar24 = (int *)piVar24[4]) {
            puVar28 = (uint *)(iVar23 + *piVar24 * 4);
            *puVar28 = *puVar28 | 0x1000;
          }
        }
      }
      local_130 = local_130 + 1;
      local_7c = local_7c + 4;
      local_78 = local_78 + 4;
    } while (iVar7 != local_130);
    local_188 = *puVar21;
  }
  if (((local_188 & 2) != 0) && (iVar7 != 0)) {
    iVar23 = 0;
    pcVar18 = pcVar6;
    do {
      while (*pcVar18 != '\x04') {
        if (((local_188 >> 6 & 1) != 0) && (*pcVar18 == '\v')) {
          *pcVar18 = -0x7f;
        }
        iVar23 = iVar23 + 1;
        pcVar18 = pcVar18 + 0x10;
        if (iVar7 == iVar23) goto LAB_00076345;
      }
      *pcVar18 = -0x80;
      iVar23 = iVar23 + 1;
      pcVar18 = pcVar18 + 0x10;
    } while (iVar7 != iVar23);
  }
LAB_00076345:
  iVar7 = *(int *)(((unsigned char *)0x00010450) + param_1);
  if (*(int *)(((unsigned char *)0x00010450) + param_1) != 0) {
    do {
      piVar24 = (int *)(iVar7 + 0x10);
      iVar23 = iVar7;
      iVar7 = *piVar24;
    } while (*piVar24 != 0);
    while( true ) {
      do {
        iVar7 = iVar23;
        FUN_00073003();
        iVar23 = *(int *)(((unsigned char *)0x00010450) + param_1);
        if ((iVar23 == 0) || (iVar7 == iVar23)) goto LAB_00076396;
        iVar13 = *(int *)(iVar23 + 0x10);
      } while (iVar7 == iVar13);
      if (iVar13 == 0) break;
      while (iVar1 = *(int *)(iVar13 + 0x10), iVar23 = iVar13, iVar7 != iVar1) {
        iVar13 = iVar1;
        if (iVar1 == 0) {
          uVar16 = *(uint *)(param_1 + 0x26870);
          goto joined_r0x000767ba;
        }
      }
    }
  }
LAB_00076396:
  uVar16 = *(uint *)(param_1 + 0x26870);
joined_r0x000767ba:
  if (uVar16 != 0) {
    local_128 = 0;
    local_80 = param_1;
    do {
      for (piVar24 = *(int **)(param_1 + 0xa450 + *(int *)(local_80 + 0x24870) * 4);
          piVar24 != (int *)0x0; piVar24 = (int *)piVar24[4]) {
        while ((*(byte *)(param_1 + 0x3348e + *piVar24 * 4) & 1) != 0) {
          piVar24 = (int *)piVar24[4];
          if (piVar24 == (int *)0x0) goto LAB_0007682e;
        }
        FUN_000730be();
      }
LAB_0007682e:
      iVar7 = *(int *)(local_80 + 0x24870);
      for (piVar24 = *(int **)(param_1 + 0xc450 + iVar7 * 4); piVar24 != (int *)0x0;
          piVar24 = (int *)piVar24[4]) {
        while ((*(byte *)(param_1 + 0x3348e + *piVar24 * 4) & 1) != 0) {
          piVar24 = (int *)piVar24[4];
          if (piVar24 == (int *)0x0) goto LAB_00076879;
        }
        FUN_000730be();
        iVar7 = *(int *)(local_80 + 0x24870);
      }
LAB_00076879:
      for (piVar24 = *(int **)(param_1 + 0xe450 + iVar7 * 4); piVar24 != (int *)0x0;
          piVar24 = (int *)piVar24[4]) {
        while ((*(byte *)(param_1 + 0x3348e + *piVar24 * 4) & 1) != 0) {
          piVar24 = (int *)piVar24[4];
          if (piVar24 == (int *)0x0) goto LAB_000768c2;
        }
        FUN_000730be();
      }
LAB_000768c2:
      local_128 = local_128 + 1;
      local_80 = local_80 + 4;
    } while (local_128 < *(uint *)(param_1 + 0x26870));
  }
  uVar3 = DAT_001c63b1;
  if ((((**(byte **)(param_1 + 0x34) & 0x40) != 0) && (uVar16 != 0)) &&
     (iVar7 = uVar16 - 1, iVar7 != 0)) {
    local_8c = (ushort *)(pcVar6 + iVar7 * 0x10 + 4);
    local_84 = (uint *)(param_1 + 0x6450 + iVar7 * 4);
    local_90 = 0;
    do {
      if ((*(byte *)((int)local_84 + 0x2d03e) & 1) != 0) {
        uVar27 = *local_84;
        if ((*(byte *)((int)local_8c + -3) & 0xf) == 5) {
          bVar5 = (byte)local_8c[-1];
          if ((bVar5 & 0x10) != 0) {
            FUN_000742d6();
            bVar5 = (byte)local_8c[-1];
          }
          if ((bVar5 & 0x20) != 0) {
            FUN_000742d6();
            bVar5 = (byte)local_8c[-1];
          }
          if ((bVar5 & 0x40) != 0) {
            FUN_000742d6();
            bVar5 = (byte)local_8c[-1];
          }
          if ((char)bVar5 < '\0') {
            FUN_000742d6();
          }
        }
        local_11c = 0;
        puVar25 = local_8c;
        do {
          if (((uVar27 & 1 << ((byte)local_11c & 0x1f)) != 0) && ((*puVar25 & 0xf) == 1)) {
            iVar23 = (int)CONCAT11(uVar3,(char)(*puVar25 >> 5));
            uVar10 = 1 << ((byte)(puVar25[1] >> 6) & 7) | 1 << ((byte)puVar25[1] >> 3 & 7) |
                     1 << ((byte)puVar25[1] & 7) | 1 << (*(byte *)((int)puVar25 + 1) >> 5);
            piVar24 = (int *)(iVar23 * 0x10 + 0x2a87c + param_1);
            local_114 = 0;
            uVar17 = 1;
            uVar19 = uVar10 & 1;
            while( true ) {
              if (uVar19 != 0) {
                iVar13 = *piVar24;
                piVar15 = (int *)FUN_0007430a();
                if (piVar15 != (int *)0x0) {
                  *piVar15 = iVar7 - local_90;
                  piVar15[1] = iVar13;
                  *piVar24 = (int)piVar15;
                  local_124 = (byte)uVar17;
                  pbVar26 = (byte *)(iVar23 + 0x3087c + param_1);
                  *pbVar26 = *pbVar26 | local_124;
                  piVar24[0xc00] = -1;
                }
              }
              local_114 = local_114 + 1;
              piVar24 = piVar24 + 1;
              if (local_114 == 4) break;
              uVar17 = 1 << ((byte)local_114 & 0x1f);
              uVar19 = uVar10 & uVar17;
            }
          }
          local_11c = local_11c + 1;
          puVar25 = puVar25 + 2;
        } while (local_11c != 3);
      }
      local_90 = local_90 + 1;
      local_8c = local_8c + -8;
      local_84 = local_84 + -1;
    } while (local_90 != iVar7);
  }
  FUN_000730f5();
  uVar27 = 0;
  while (uVar27 < *(uint *)(param_1 + 0x26870)) {
    while (cVar4 = FUN_00073252(**(uint **)(param_1 + 0x34) >> 6 & 1), cVar4 == '\0') {
      uVar27 = uVar27 + 1;
      if (*(uint *)(param_1 + 0x26870) <= uVar27) goto LAB_00076421;
    }
    iVar7 = *(int *)(param_1 + 0x24870 + uVar27 * 4);
    iVar23 = *(int *)(param_1 + 0x28874);
    *(undefined4 *)(param_1 + 0x22870 + iVar23 * 4) = 0;
    *(int *)(param_1 + 0x26874 + iVar23 * 4) = iVar7;
    *(int *)(param_1 + 0x28874) = iVar23 + 1;
    FUN_00073192();
    *(uint *)(param_1 + 0x3348c + iVar7 * 4) =
         *(uint *)(param_1 + 0x3348c + iVar7 * 4) & 0xfffeffff | 0x20000;
  }
LAB_00076421:
  do {
    if (uVar16 <= *(uint *)(param_1 + 0x2a878)) {
      uVar27 = **(uint **)(param_1 + 0x34);
      if (uVar16 != 0) {
        uVar10 = 0;
        pcVar18 = pcVar6;
        do {
          cVar4 = ((int (*)())FUN_0007517d)();
          if (cVar4 != '\0') {
            if (*pcVar18 == '\x04') {
              *pcVar18 = -0x80;
            }
            else if (((uVar27 >> 6 & 1) != 0) && (*pcVar18 == '\v')) {
              *pcVar18 = -0x7f;
            }
          }
          uVar10 = uVar10 + 1;
          pcVar18 = pcVar18 + 0x10;
        } while (uVar16 != uVar10);
      }
      if (((*puVar21 & 0x20) != 0) && (iVar7 = ((int (*)())FUN_000751c6)(), iVar7 != 0)) {
        return iVar7;
      }
      iVar7 = *(int *)(param_1 + 0x34);
      if (*(int *)(param_1 + 0x2a878) == 0) {
        local_58 = 0;
        local_e4 = 0;
        local_e0 = 0;
        local_60 = 0;
        local_5c = 0;
        local_dc = 0;
        local_d4 = 0;
        goto LAB_000777aa;
      }
      local_d8 = 0;
      local_e4 = 0;
      local_e0 = 0;
      local_60 = 0;
      local_5c = 0;
      local_dc = 0;
      local_d4 = 0;
      local_58 = 0;
      do {
        iVar23 = *(int *)(param_1 + 0x28878 + local_d8 * 4);
        local_68 = (uint *)(pcVar6 + iVar23 * 0x10);
        puVar21 = (uint *)(local_58 * 0x10 + *(int *)(iVar7 + 0x18));
        if ((*(byte *)(param_1 + 0x3348d + iVar23 * 4) & 1) == 0) {
LAB_00077639:
          local_c5 = *(char *)(param_1 + 0x8450 + iVar23 * 4);
          uVar16 = *(uint *)(param_1 + 0x6450 + iVar23 * 4);
          local_99 = 0;
          iVar23 = 0;
          do {
            if ((uVar16 & 1 << ((byte)iVar23 & 0x1f)) != 0) {
              bVar5 = FUN_000735fe();
              local_99 = local_99 | bVar5;
            }
            iVar23 = iVar23 + 1;
          } while (iVar23 != 3);
        }
        else {
          iVar13 = *(int *)(param_1 + 0x2887c + local_d8 * 4);
          local_64 = (uint *)(pcVar6 + iVar13 * 0x10);
          puVar28 = local_68;
          if ((*local_68 & 0x40) == 0) {
            puVar28 = local_64;
            local_64 = local_68;
          }
          puVar8 = local_64 + 3;
          bVar5 = *(byte *)((int)puVar28 + 2);
          bVar5 = ((char)bVar5 >> 7) * -8 | (bVar5 >> 6 & 1) << 2 | (bVar5 >> 5 & 1) * '\x02' |
                  bVar5 >> 4 & 1;
          uVar16 = *puVar28;
          local_64[3] = 0;
          FUN_00073ff9();
          FUN_00073ff9();
          if ((((2 < (int)local_28 + (int)local_2c) || (1 < (int)local_27 + (int)local_2b)) ||
              (1 < (int)local_26 + (int)local_2a)) ||
             ((1 < (int)local_25 + (int)local_29 || ((*local_64 & 0xf00) == 0x400))))
          goto LAB_00077639;
          uVar10 = (*puVar28 & 0x6000) << 6;
          uVar27 = local_64[3];
          local_64[3] = uVar27 & 0xffe7ffff | uVar10;
          uVar19 = (uint)((byte)*puVar28 & 0xf) << 0x15;
          local_64[3] = uVar27 & 0xfe07ffff | uVar10 | uVar19;
          uVar17 = (byte)((byte)*puVar28 >> 2) & 4;
          uVar22 = uVar27 & 0xfe07fffb | uVar10 | uVar19 | uVar17;
          local_64[3] = uVar22;
          if (bVar5 == 2) {
            local_64[3] = uVar27 & 0xe607fffb | uVar10 | uVar19 | uVar17 | 0x8000000;
          }
          else if (bVar5 < 3) {
            if (bVar5 == 1) {
              *puVar8 = uVar27 & 0xe607fffb | uVar10 | uVar19 | uVar17;
            }
          }
          else if (bVar5 == 4) {
            local_64[3] = uVar27 & 0xe607fffb | uVar10 | uVar19 | uVar17 | 0x10000000;
          }
          else if (bVar5 == 8) {
            *puVar8 = uVar22 | 0x18000000;
          }
          iVar1 = ((byte)uVar16 & 0x1f) * 0x14;
          if (*(uint *)(&DAT_001c6248 + iVar1) < 3) {
            puVar11 = puVar28 + *(uint *)(&DAT_001c6248 + iVar1) + 1;
            uVar27 = ((byte)*puVar11 & 0xf) & 3;
            uVar16 = *puVar8;
            *puVar8 = uVar16 & 0xfffffffc | uVar27;
            uVar10 = ((byte)((byte)*puVar11 >> 4) & 1) << 4;
            *puVar8 = uVar16 & 0xffffffec | uVar27 | uVar10;
            uVar19 = (uint)(byte)((ushort)*puVar11 >> 5) << 5;
            *puVar8 = uVar16 & 0xffffe00c | uVar27 | uVar10 | uVar19;
            uVar17 = (*(byte *)((int)puVar11 + 3) >> 5 & 3) << 0x1d;
            *puVar8 = uVar16 & 0x9fffe00c | uVar27 | uVar10 | uVar19 | uVar17;
            uVar22 = (*(byte *)((int)puVar11 + 3) >> 4 & 1) << 0x19;
            *puVar8 = uVar16 & 0x9dffe00c | uVar27 | uVar10 | uVar19 | uVar17 | uVar22;
            *puVar8 = uVar16 & 0x9dff000c | uVar27 | uVar10 | uVar19 | uVar17 | uVar22 |
                      (*(ushort *)((int)puVar11 + 2) >> 6 & 7) << 0xd;
          }
          if (*(uint *)(&DAT_001c624c + iVar1) < 3) {
            puVar28 = puVar28 + *(uint *)(&DAT_001c624c + iVar1) + 1;
            uVar27 = ((byte)*puVar28 & 0xf) & 3;
            uVar16 = *puVar8;
            *puVar8 = uVar16 & 0xfffffffc | uVar27;
            uVar10 = ((byte)((byte)*puVar28 >> 4) & 1) << 4;
            *puVar8 = uVar16 & 0xffffffec | uVar27 | uVar10;
            uVar19 = (uint)(byte)((ushort)*puVar28 >> 5) << 5;
            *puVar8 = uVar16 & 0xffffe00c | uVar27 | uVar10 | uVar19;
            uVar17 = (*(byte *)((int)puVar28 + 3) >> 5 & 3) << 0x1d;
            *puVar8 = uVar16 & 0x9fffe00c | uVar27 | uVar10 | uVar19 | uVar17;
            uVar22 = (*(byte *)((int)puVar28 + 3) >> 4 & 1) << 0x1a;
            *puVar8 = uVar16 & 0x9bffe00c | uVar27 | uVar10 | uVar19 | uVar17 | uVar22;
            *puVar8 = uVar16 & 0x9bf8e00c | uVar27 | uVar10 | uVar19 | uVar17 | uVar22 |
                      (*(ushort *)((int)puVar28 + 2) >> 6 & 7) << 0x10;
          }
          *(byte *)((int)local_64 + 3) = *(byte *)((int)local_64 + 3) | 0x10;
          local_68 = local_64;
          if ((*(int *)(param_1 + 0x8450 + iVar23 * 4) == 0) &&
             (*(int *)(param_1 + 0x8450 + iVar13 * 4) == 0)) {
            local_c5 = '\0';
          }
          else {
            local_c5 = '\x01';
          }
          uVar16 = *(uint *)(param_1 + 0x6450 + iVar23 * 4);
          local_ad = 0;
          iVar23 = 0;
          do {
            if ((uVar16 & 1 << ((byte)iVar23 & 0x1f)) != 0) {
              bVar5 = FUN_000735fe();
              local_ad = local_ad | bVar5;
            }
            iVar23 = iVar23 + 1;
          } while (iVar23 != 3);
          if (local_ad == 0) {
            uVar16 = *(uint *)(param_1 + 0x6450 + iVar13 * 4);
            local_a5 = 0;
            iVar23 = 0;
            do {
              if ((uVar16 & 1 << ((byte)iVar23 & 0x1f)) != 0) {
                bVar5 = FUN_000735fe();
                local_a5 = local_a5 | bVar5;
              }
              iVar23 = iVar23 + 1;
            } while (iVar23 != 3);
            if (local_a5 != 0) goto LAB_00077c84;
            local_99 = 0;
          }
          else {
LAB_00077c84:
            local_99 = 1;
          }
          local_d4 = local_d4 + 1;
          local_d8 = local_d8 + 1;
        }
        if (local_c5 != '\0') {
          if (*(int *)(iVar7 + 0x20) != 0) {
            puVar28 = (uint *)(*(int *)(iVar7 + 0x20) + local_e4 * 0x10);
            *puVar28 = *local_68;
            puVar28[1] = local_68[1];
            puVar28[2] = local_68[2];
            puVar28[3] = local_68[3];
            local_e4 = local_e4 + 1;
          }
          local_e0 = local_58;
        }
        if (((*local_68 & 0xf00) == 0x800) && ((**(uint **)(param_1 + 0x34) >> 6 & 1) == 0)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        uVar16 = local_58;
        if (!bVar2) {
          uVar16 = local_5c;
        }
        uVar27 = local_58;
        if (local_99 == 0) {
          uVar27 = local_60;
        }
        cVar4 = FUN_00073610();
        uVar10 = local_dc;
        if ((cVar4 != '\0') && (uVar10 = (*local_68 >> 0xd & 0x7f) + 1, uVar10 <= local_dc)) {
          uVar10 = local_dc;
        }
        local_dc = uVar10;
        if (local_58 == 0x400) {
          return 10;
        }
        *puVar21 = *local_68;
        puVar21[1] = local_68[1];
        puVar21[2] = local_68[2];
        puVar21[3] = local_68[3];
        local_58 = local_58 + 1;
        local_d8 = local_d8 + 1;
        local_60 = uVar27;
        local_5c = uVar16;
        if (*(uint *)(param_1 + 0x2a878) <= local_d8) {
LAB_000777aa:
          **(uint **)(iVar7 + 0x1c) = local_58;
          puVar21 = *(uint **)(iVar7 + 0x28);
          if (puVar21 != (uint *)0x0) {
            if ((**(byte **)(param_1 + 0x34) & 0x40) == 0) {
              if (local_5c <= local_e0) {
                local_5c = local_e0;
              }
              *puVar21 = local_5c;
            }
            else {
              *puVar21 = local_e0;
            }
          }
          if (*(uint **)(iVar7 + 0x2c) != (uint *)0x0) {
            **(uint **)(iVar7 + 0x2c) = local_60;
          }
          if (*(uint **)(iVar7 + 0x30) != (uint *)0x0) {
            **(uint **)(iVar7 + 0x30) = local_dc;
          }
          if (*(int *)(iVar7 + 0x20) != 0) {
            **(int **)(iVar7 + 0x24) = local_e4;
          }
          *(int *)(param_1 + 0x3548c) = local_d4;
          return 0;
        }
      } while( true );
    }
    if (*(int *)(param_1 + 0x28874) == 0) {
      return 2;
    }
    iVar7 = ((int (*)())FUN_00075cbf)(local_1d,local_24,pcVar6,*puVar21,*puVar21 >> 6 & 1);
    while (iVar7 < 0) {
      uVar27 = **(uint **)(param_1 + 0x34) >> 6;
      if (((uVar27 & 1) == 0) || (0x1f < local_144)) {
        if (iVar7 < 0) {
          return 3;
        }
        break;
      }
      if (local_144 == 0x12) {
        local_144 = 0x18;
      }
      else if (local_144 == 0x18) {
        local_144 = 0x20;
      }
      else if (local_144 == 0xe) {
        local_144 = 0x12;
      }
      iVar7 = ((int (*)())FUN_00075cbf)(local_1d,local_24,pcVar6,*puVar21,uVar27 & 1);
    }
    puVar8 = (uint *)(pcVar6 + iVar7 * 0x10);
    iVar23 = 1;
    puVar28 = puVar8;
    do {
      puVar28 = puVar28 + 1;
      local_48[iVar23 + 3] = (uint)puVar28;
      iVar23 = iVar23 + 1;
    } while (iVar23 != 4);
    if (local_1d[0] == '\0') {
      puVar28 = *(uint **)(param_1 + 0x34);
    }
    else {
      puVar28 = *(uint **)(param_1 + 0x34);
      cVar4 = FUN_000731c4();
      if (cVar4 == '\0') {
        cVar4 = FUN_000731ef();
        if (cVar4 != '\0') {
          ((int (*)())FUN_0007546d)();
          puVar28 = *(uint **)(param_1 + 0x34);
        }
      }
      else {
        FUN_000740ef();
        puVar28 = *(uint **)(param_1 + 0x34);
      }
    }
    pcVar18 = pcVar6;
    iVar23 = FUN_000743fd(pcVar6,*puVar28 >> 6 & 1);
    if (iVar23 != 0) {
      return iVar23;
    }
    cVar4 = FUN_000731c4();
    if (cVar4 == '\0') {
      cVar4 = FUN_000731ef();
      if (cVar4 != '\0') {
        FUN_00073220();
        iVar23 = FUN_00073584(1);
        if (iVar23 != 0) {
          return iVar23;
        }
        for (iVar23 = *(int *)(param_1 + 0xc450 + iVar7 * 4); iVar23 != 0;
            iVar23 = *(int *)(iVar23 + 0x10)) {
          iVar13 = FUN_00073584(1);
          if (iVar13 != 0) {
            return iVar13;
          }
        }
        for (iVar23 = *(int *)(param_1 + 0xe450 + iVar7 * 4); iVar23 != 0;
            iVar23 = *(int *)(iVar23 + 0x10)) {
          FUN_00073584(1);
        }
        piVar24 = *(int **)(param_1 + 0xa450 + iVar7 * 4);
        local_f8 = 0;
        iVar23 = param_1;
        do {
          if (piVar24 != (int *)0x0) {
            bVar2 = false;
            piVar15 = piVar24;
            do {
              if ((piVar15[1] & 1 << ((byte)local_f8 & 0x1f)) != 0) {
                if (bVar2) {
                  piVar14 = *(int **)(iVar23 + 0x30b7c);
                  do {
                    local_f0 = piVar14;
                    if (*local_f0 == *piVar15) goto LAB_00077014;
                    piVar14 = (int *)local_f0[1];
                  } while ((int *)local_f0[1] != (int *)0x0);
                  piVar14 = (int *)FUN_0007430a();
                  local_f0[1] = (int)piVar14;
                  if (piVar14 == (int *)0x0) {
                    return 7;
                  }
                  *piVar14 = *piVar15;
                  piVar14[1] = 0;
                }
                else {
                  if (*(int *)(iVar23 + 0x30b7c) != 0) {
                    return 6;
                  }
                  piVar14 = (int *)FUN_0007430a();
                  *(int **)(iVar23 + 0x30b7c) = piVar14;
                  if (piVar14 == (int *)0x0) {
                    return 7;
                  }
                  *piVar14 = *piVar15;
                  *(undefined4 *)(*(int *)(iVar23 + 0x30b7c) + 4) = 0;
                  bVar2 = true;
                }
              }
LAB_00077014:
              piVar15 = (int *)piVar15[4];
            } while (piVar15 != (int *)0x0);
          }
          local_f8 = local_f8 + 1;
          iVar23 = iVar23 + 4;
        } while (local_f8 != 4);
      }
    }
    else {
      uVar29 = 1;
      uVar9 = FUN_00073220(pcVar18,1);
      iVar23 = FUN_000734fb(uVar9);
      if (iVar23 != 0) {
        return iVar23;
      }
      puVar28 = *(uint **)(param_1 + 0xc450 + iVar7 * 4);
      if (puVar28 == (uint *)0x0) {
        local_14c = 0;
      }
      else {
        local_14c = 0;
        do {
          while (uVar27 = *puVar28, (*(byte *)(param_1 + 0x3348e + uVar27 * 4) & 4) != 0) {
            puVar28 = (uint *)puVar28[4];
            if (puVar28 == (uint *)0x0) goto LAB_00076621;
          }
          uVar10 = FUN_00073220(uVar9,uVar29);
          iVar23 = 0;
          puVar11 = local_48;
          do {
            uVar19 = 1 << ((byte)iVar23 & 0x1f);
            if ((uVar10 & uVar19) != 0) {
              if ((local_14c & uVar19) == 0) {
                *puVar11 = uVar27;
                local_14c = local_14c | uVar19;
              }
              else if (uVar27 < *puVar11) {
                *puVar11 = uVar27;
              }
            }
            iVar23 = iVar23 + 1;
            puVar11 = puVar11 + 1;
          } while (iVar23 != 4);
          puVar28 = (uint *)puVar28[4];
        } while (puVar28 != (uint *)0x0);
      }
LAB_00076621:
      iVar23 = 0;
      do {
        uVar27 = 1 << ((byte)iVar23 & 0x1f);
        if (((local_14c & uVar27) != 0) && (iVar13 = FUN_000734fb(uVar27,0), iVar13 != 0)) {
          return iVar13;
        }
        iVar23 = iVar23 + 1;
      } while (iVar23 != 4);
      for (iVar23 = *(int *)(param_1 + 0xe450 + iVar7 * 4); iVar23 != 0;
          iVar23 = *(int *)(iVar23 + 0x10)) {
        FUN_000734fb(*(undefined4 *)(iVar23 + 4),0);
      }
      piVar15 = *(int **)(param_1 + 0xa450 + iVar7 * 4);
      piVar24 = (int *)(((char)(DAT_001c63a8)[*(byte *)((int)puVar8 + 1) & 0xf] * 0x100 +
                        (*puVar8 >> 0xd & 0x7f)) * 0x10 + 0x2a87c + param_1);
      local_104 = 0;
      do {
        if (piVar15 != (int *)0x0) {
          bVar2 = false;
          piVar14 = piVar15;
          do {
            if ((piVar14[1] & 1 << ((byte)local_104 & 0x1f)) != 0) {
              if (bVar2) {
                piVar12 = (int *)*piVar24;
                do {
                  local_fc = piVar12;
                  if (*local_fc == *piVar14) goto LAB_00076775;
                  piVar12 = (int *)local_fc[1];
                } while ((int *)local_fc[1] != (int *)0x0);
                piVar12 = (int *)FUN_0007430a();
                local_fc[1] = (int)piVar12;
                if (piVar12 == (int *)0x0) {
                  return 7;
                }
                *piVar12 = *piVar14;
                piVar12[1] = 0;
              }
              else {
                if (*piVar24 != 0) {
                  return 6;
                }
                piVar12 = (int *)FUN_0007430a();
                *piVar24 = (int)piVar12;
                if (piVar12 == (int *)0x0) {
                  return 7;
                }
                *piVar12 = *piVar14;
                *(undefined4 *)(*piVar24 + 4) = 0;
                bVar2 = true;
              }
            }
LAB_00076775:
            piVar14 = (int *)piVar14[4];
          } while (piVar14 != (int *)0x0);
        }
        local_104 = local_104 + 1;
        piVar24 = piVar24 + 1;
      } while (local_104 != 4);
    }
    iVar23 = *(int *)(param_1 + 0x2a878);
    *(int *)(param_1 + 0x28878 + iVar23 * 4) = iVar7;
    *(int *)(param_1 + 0x2a878) = iVar23 + 1;
    *(uint *)(param_1 + 0x3348c + iVar7 * 4) =
         *(uint *)(param_1 + 0x3348c + iVar7 * 4) & 0xfffdffff | 0x40000;
    uVar27 = *(uint *)(param_1 + 0x28874);
    if (uVar27 != 0) {
      local_50 = 0;
      local_198 = param_1 + 0x22874;
      local_19c = 0x22874;
      local_1b0 = param_1 + 0x22870;
      iVar23 = param_1;
      do {
        if ((iVar7 == *(int *)(iVar23 + 0x26874)) && (local_50 < uVar27 - 1)) {
          puVar20 = (undefined4 *)(param_1 + local_19c);
          uVar10 = local_50;
          do {
            uVar10 = uVar10 + 1;
            *(undefined4 *)((int)puVar20 + (local_1b0 - local_198)) = *puVar20;
            puVar20[0x1000] = puVar20[0x1001];
            puVar20 = puVar20 + 1;
          } while (uVar10 < uVar27 - 1);
        }
        local_50 = local_50 + 1;
        local_1b0 = local_1b0 + 4;
        local_19c = local_19c + 4;
        local_198 = local_198 + 4;
        iVar23 = iVar23 + 4;
      } while (local_50 < uVar27);
    }
    *(uint *)(param_1 + 0x28874) = uVar27 - 1;
    if ((*(int *)(param_1 + 0x35490) != 3) && (uVar27 - 1 != 0)) {
      uVar27 = 0;
      iVar7 = param_1;
      do {
        if (*(int *)(iVar7 + 0x22870) != 0) {
          *(int *)(iVar7 + 0x22870) = *(int *)(iVar7 + 0x22870) + -1;
        }
        uVar27 = uVar27 + 1;
        iVar7 = iVar7 + 4;
      } while (uVar27 < *(uint *)(param_1 + 0x28874));
    }
    FUN_000730f5();
    uVar27 = 0;
    while (uVar27 < *(uint *)(param_1 + 0x26870)) {
      while (cVar4 = FUN_00073252(**(uint **)(param_1 + 0x34) >> 6 & 1), cVar4 == '\0') {
        uVar27 = uVar27 + 1;
        if (*(uint *)(param_1 + 0x26870) <= uVar27) goto LAB_00076bf1;
      }
      iVar7 = *(int *)(param_1 + 0x24870 + uVar27 * 4);
      iVar23 = *(int *)(param_1 + 0x28874);
      *(undefined4 *)(param_1 + 0x22870 + iVar23 * 4) = 9;
      *(int *)(param_1 + 0x26874 + iVar23 * 4) = iVar7;
      *(int *)(param_1 + 0x28874) = iVar23 + 1;
      FUN_00073192();
      *(uint *)(param_1 + 0x3348c + iVar7 * 4) =
           *(uint *)(param_1 + 0x3348c + iVar7 * 4) & 0xfffeffff | 0x20000;
    }
LAB_00076bf1:
    if (((*puVar21 & 0x10) != 0) && (iVar7 = ((int (*)())FUN_000751c6)(), iVar7 != 0)) {
      return iVar7;
    }
  } while( true );
}

/* FUN_00077d43 @ 0x77d43 (5668 bytes) */
int FUN_00077d43(param_1)
  byte *param_1;
{
  ushort *puVar1;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  uint *puVar7;
  byte bVar8;
  char cVar9;
  byte bVar10;
  byte *pbVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  byte *pbVar20;
  byte bVar21;
  ushort uVar22;
  int iVar23;
  int *piVar24;
  uint uVar25;
  uint *puVar26;
  undefined4 *puVar27;
  byte *pbVar28;
  uint *puVar29;
  uint *puVar30;
  int iVar31;
  undefined4 *local_100;
  uint local_e8;
  int local_d0;
  int local_a8;
  int local_a0;
  uint local_98;
  int local_8c;
  byte *local_88;
  byte *local_84;
  byte *local_80;
  int local_7c;
  uint *local_64;
  uint *local_60;
  int local_5c;
  undefined4 *local_58;
  int local_40;
  uint local_38;
  uint local_34;
  uint local_30;
  uint *local_2c [3];
  uint local_20;
  
  if (0x800 < *(uint *)(param_1 + 8)) {
    return 10;
  }
  if (*(uint *)(param_1 + 8) == 0) {
    return 1;
  }
  *(byte **)(param_1 + 0x34) = param_1;
  ((int (*)())FUN_00075378)();
  param_1[0x28874] = 0;
  param_1[0x28875] = 0;
  param_1[0x28876] = 0;
  param_1[0x28877] = 0;
  param_1[0x2a878] = 0;
  param_1[0x2a879] = 0;
  param_1[0x2a87a] = 0;
  param_1[0x2a87b] = 0;
  iVar31 = 0;
  pbVar20 = param_1 + 0x2a870;
  pbVar28 = param_1;
  do {
    pbVar28[0x3087c] = 0;
    pbVar11 = pbVar20 + 0xc;
    iVar23 = 0;
    do {
      pbVar11[0] = 0;
      pbVar11[1] = 0;
      pbVar11[2] = 0;
      pbVar11[3] = 0;
      pbVar11[0x3000] = 0;
      pbVar11[0x3001] = 0;
      pbVar11[0x3002] = 0;
      pbVar11[0x3003] = 0;
      iVar23 = iVar23 + 1;
      pbVar11 = pbVar11 + 4;
    } while (iVar23 != 4);
    iVar31 = iVar31 + 1;
    pbVar20 = pbVar20 + 0x10;
    pbVar28 = pbVar28 + 1;
  } while (iVar31 != 0x300);
  param_1[0x30b9c] = 0;
  iVar31 = 0;
  pbVar28 = param_1;
  do {
    pbVar28[0x30b7c] = 0;
    pbVar28[0x30b7d] = 0;
    pbVar28[0x30b7e] = 0;
    pbVar28[0x30b7f] = 0;
    pbVar28[0x30b8c] = 0;
    pbVar28[0x30b8d] = 0;
    pbVar28[0x30b8e] = 0;
    pbVar28[0x30b8f] = 0;
    iVar31 = iVar31 + 1;
    pbVar28 = pbVar28 + 4;
  } while (iVar31 != 4);
  param_1[0x26870] = 0;
  param_1[0x26871] = 0;
  param_1[0x26872] = 0;
  param_1[0x26873] = 0;
  _memset(param_1 + 0x3148c,0,0x2000);
  iVar31 = 0;
  pbVar28 = param_1;
  do {
    pbVar28[0x3348c] = 0;
    pbVar28[0x3348d] = 0;
    pbVar28[0x3348e] = 0;
    pbVar28[0x3348f] = 0;
    iVar31 = iVar31 + 1;
    pbVar28 = pbVar28 + 4;
  } while (iVar31 != 0x800);
  param_1[0x3548c] = 0;
  param_1[0x3548d] = 0;
  param_1[0x3548e] = 0;
  param_1[0x3548f] = 0;
  local_88 = param_1 + 0x38;
  ((int (*)())FUN_00075378)();
  iVar31 = 0;
  pbVar20 = param_1 + 0x448;
  pbVar28 = local_88;
  do {
    pbVar11 = pbVar20 + 8;
    iVar23 = 0;
    do {
      pbVar11[0] = 0;
      pbVar11[1] = 0;
      pbVar11[2] = 0;
      pbVar11[3] = 0;
      iVar23 = iVar23 + 1;
      pbVar11 = pbVar11 + 4;
    } while (iVar23 != 3);
    pbVar28[0xa418] = 0;
    pbVar28[0xa419] = 0;
    pbVar28[0xa41a] = 0;
    pbVar28[0xa41b] = 0;
    pbVar28[0xc418] = 0;
    pbVar28[0xc419] = 0;
    pbVar28[0xc41a] = 0;
    pbVar28[0xc41b] = 0;
    pbVar28[0xe418] = 0;
    pbVar28[0xe419] = 0;
    pbVar28[0xe41a] = 0;
    pbVar28[0xe41b] = 0;
    param_1[0x10450] = 0;
    param_1[0x10451] = 0;
    param_1[0x10452] = 0;
    param_1[0x10453] = 0;
    pbVar28[0x6418] = 0;
    pbVar28[0x6419] = 0;
    pbVar28[0x641a] = 0;
    pbVar28[0x641b] = 0;
    pbVar28[0x8418] = 0;
    pbVar28[0x8419] = 0;
    pbVar28[0x841a] = 0;
    pbVar28[0x841b] = 0;
    pbVar28[0x1041c] = 0;
    pbVar28[0x1041d] = 0;
    pbVar28[0x1041e] = 0;
    pbVar28[0x1041f] = 0;
    iVar31 = iVar31 + 1;
    pbVar20 = pbVar20 + 0xc;
    pbVar28 = pbVar28 + 4;
  } while (iVar31 != 0x800);
  if ((*param_1 & 0x40) == 0) {
    *(int *)(param_1 + 0x2286c) = *(int *)(param_1 + 8);
    _memcpy(param_1 + 0x1286c,*(void **)(param_1 + 4),*(int *)(param_1 + 8) << 4);
    local_e8 = *(uint *)(param_1 + 0x2286c);
  }
  else {
    iVar31 = *(int *)(param_1 + 8);
    puVar27 = *(undefined4 **)(param_1 + 4);
    local_e8 = 0;
    param_1[0x2286c] = 0;
    param_1[0x2286d] = 0;
    param_1[0x2286e] = 0;
    param_1[0x2286f] = 0;
    if (iVar31 != 0) {
      pbVar20 = param_1 + 0x1286c;
      local_d0 = 0;
      pbVar28 = pbVar20;
      while( true ) {
        local_58 = puVar27 + 4;
        *(undefined4 *)pbVar28 = *puVar27;
        *(undefined4 *)(pbVar28 + 4) = puVar27[1];
        *(undefined4 *)(pbVar28 + 8) = puVar27[2];
        *(undefined4 *)(pbVar28 + 0xc) = puVar27[3];
        local_e8 = *(int *)(param_1 + 0x2286c) + 1;
        *(uint *)(param_1 + 0x2286c) = local_e8;
        if ((*(byte *)((int)puVar27 + 3) & 0x10) != 0) {
          puVar1 = (ushort *)(puVar27 + 3);
          puVar29 = (uint *)(pbVar20 + local_e8 * 0x10);
          iVar23 = (*(ushort *)((int)puVar27 + 0xe) >> 5 & 0xf) * 0x14;
          if (0x7ff < local_e8) {
            return 10;
          }
          pbVar28[3] = pbVar28[3] & 0xef;
          pbVar28[0xc] = 0;
          pbVar28[0xd] = 0x48;
          pbVar28[0xe] = 0x12;
          pbVar28[0xf] = 0;
          *puVar29 = 0;
          puVar29[1] = 0x124800;
          puVar29[2] = 0x124800;
          puVar29[3] = 0x124800;
          *(byte *)puVar29 = (byte)(*(ushort *)((int)puVar27 + 0xe) >> 5) & 0xf | 0x40;
          uVar17 = *puVar29;
          *puVar29 = uVar17 & 0xfffff0ff | 0x400;
          *puVar29 = uVar17 & 0xfff010ff | 0x400 | (*(byte *)((int)puVar27 + 0xe) >> 3 & 3) << 0xd;
          bVar21 = *(byte *)((int)puVar29 + 2) & 0xf;
          *(byte *)((int)puVar29 + 2) = bVar21;
          bVar8 = *(byte *)((int)puVar27 + 0xf) >> 3;
          bVar10 = bVar8 & 3;
          if (bVar10 == 1) {
            *(byte *)((int)puVar29 + 2) = bVar21 | 0x20;
          }
          else if ((bVar8 & 3) == 0) {
            if ((bVar8 & 3) == 0) {
              *(byte *)((int)puVar29 + 2) = bVar21 | 0x10;
            }
          }
          else if (bVar10 == 2) {
            *(byte *)((int)puVar29 + 2) = bVar21 | 0x40;
          }
          else if (bVar10 == 3) {
            *(byte *)((int)puVar29 + 2) = bVar21 | 0x80;
          }
          *(byte *)((int)puVar29 + 3) = *(byte *)((int)puVar29 + 3) & 0xef;
          uVar17 = *(uint *)(&DAT_001c6248 + iVar23);
          if (uVar17 < 3) {
            uVar12 = (uint)((byte)*puVar1 & 3);
            uVar25 = puVar29[uVar17 + 1];
            puVar29[uVar17 + 1] = uVar25 & 0xfffffff0 | uVar12;
            uVar13 = ((byte)((byte)*puVar1 >> 4) & 1) << 4;
            puVar29[uVar17 + 1] = uVar25 & 0xffffffe0 | uVar12 | uVar13;
            uVar14 = (uint)(byte)(*puVar1 >> 5) << 5;
            puVar29[uVar17 + 1] = uVar25 & 0xffffe000 | uVar12 | uVar13 | uVar14;
            uVar15 = (*(byte *)((int)puVar27 + 0xf) >> 5 & 3) << 0x1d;
            puVar29[uVar17 + 1] = uVar25 & 0x9fffe000 | uVar12 | uVar13 | uVar14 | uVar15;
            uVar16 = (*(byte *)((int)puVar27 + 0xf) >> 1 & 1) << 0x1c;
            puVar29[uVar17 + 1] = uVar25 & 0x8fffe000 | uVar12 | uVar13 | uVar14 | uVar15 | uVar16;
            puVar29[uVar17 + 1] =
                 uVar25 & 0x8e3fe000 | uVar12 | uVar13 | uVar14 | uVar15 | uVar16 |
                 (uint)(*(byte *)((int)puVar27 + 0xd) >> 5) << 0x16;
          }
          uVar17 = *(uint *)(&DAT_001c624c + iVar23);
          if (uVar17 < 3) {
            uVar12 = (uint)((byte)*puVar1 & 3);
            uVar25 = puVar29[uVar17 + 1];
            puVar29[uVar17 + 1] = uVar25 & 0xfffffff0 | uVar12;
            uVar13 = ((byte)((byte)*puVar1 >> 4) & 1) << 4;
            puVar29[uVar17 + 1] = uVar25 & 0xffffffe0 | uVar12 | uVar13;
            uVar14 = (uint)(byte)(*puVar1 >> 5) << 5;
            puVar29[uVar17 + 1] = uVar25 & 0xffffe000 | uVar12 | uVar13 | uVar14;
            uVar15 = (*(byte *)((int)puVar27 + 0xf) >> 5 & 3) << 0x1d;
            puVar29[uVar17 + 1] = uVar25 & 0x9fffe000 | uVar12 | uVar13 | uVar14 | uVar15;
            uVar16 = (*(byte *)((int)puVar27 + 0xf) >> 2 & 1) << 0x1c;
            puVar29[uVar17 + 1] = uVar25 & 0x8fffe000 | uVar12 | uVar13 | uVar14 | uVar15 | uVar16;
            puVar29[uVar17 + 1] =
                 uVar25 & 0x8e3fe000 | uVar12 | uVar13 | uVar14 | uVar15 | uVar16 |
                 (uint)(*(byte *)((int)puVar27 + 0xe) & 7) << 0x16;
          }
          local_e8 = *(int *)(param_1 + 0x2286c) + 1;
          *(uint *)(param_1 + 0x2286c) = local_e8;
        }
        local_d0 = local_d0 + 1;
        if (iVar31 == local_d0) break;
        pbVar28 = pbVar20 + local_e8 * 0x10;
        puVar27 = local_58;
        if (0x7ff < local_e8) {
          return 10;
        }
      }
    }
  }
  piVar2 = *(int **)(param_1 + 0x24);
  iVar31 = *(int *)(param_1 + 0x20);
  piVar3 = *(int **)(param_1 + 0x28);
  local_100 = *(undefined4 **)(param_1 + 0x18);
  if (*(uint **)(param_1 + 0x1c) != (uint *)0x0) {
    **(uint **)(param_1 + 0x1c) = local_e8;
  }
  if (piVar3 != (int *)0x0) {
    *piVar3 = local_e8 - 1;
  }
  local_8c = local_e8 - 1;
  if (-1 < local_8c) {
    local_64 = (uint *)(param_1 + (int)(((unsigned char *)0x0001286c) + local_8c * 0x10));
    local_5c = local_8c * 4;
    local_60 = (uint *)(local_88 + local_5c + 0x6418);
    local_a8 = local_8c;
    bVar5 = false;
    do {
      if (local_100 == (undefined4 *)0x0) {
        puVar29 = *(uint **)(param_1 + 0x34);
      }
      else {
        puVar29 = *(uint **)(param_1 + 0x34);
        if ((*puVar29 & 0x200) == 0) {
          puVar26 = local_100 + local_a8 * 4;
          iVar23 = 4;
          puVar29 = local_64;
          do {
            *puVar26 = *puVar29;
            puVar29 = puVar29 + 1;
            puVar26 = puVar26 + 1;
            iVar23 = iVar23 + -1;
          } while (iVar23 != 0);
          puVar29 = *(uint **)(param_1 + 0x34);
        }
      }
      pbVar20 = param_1 + (int)(((unsigned char *)0x0001286c) + local_5c * 4);
      iVar23 = 1;
      pbVar28 = pbVar20;
      do {
        pbVar28 = pbVar28 + 4;
        (&local_30)[iVar23] = (uint)pbVar28;
        iVar23 = iVar23 + 1;
      } while (iVar23 != 4);
      local_98 = FUN_00073220();
      if (local_98 == 0) {
LAB_000784c7:
        bVar6 = false;
      }
      else {
        if ((*puVar29 & 0x40) == 0) {
          bVar8 = *(byte *)((int)local_64 + 1);
          if ((bVar8 & 0xf) - 4 < 5) {
            piVar24 = *(int **)(param_1 + 0x10450);
            if (piVar24 != (int *)0x0) {
              do {
                local_20 = *(uint *)(param_1 + (int)(((unsigned char *)0x0001286c) + *piVar24 * 0x10));
                if ((*local_64 & 0xfef00) == (local_20 & 0xfef00)) {
                  uVar17 = FUN_00073220();
                  local_98 = local_98 & ~uVar17;
                  FUN_00074d85();
                }
                piVar24 = (int *)piVar24[4];
              } while (piVar24 != (int *)0x0);
              bVar8 = *(byte *)((int)local_64 + 1);
            }
            if (((bVar8 & 0xf) == 4) && (local_60[0x800] = 1, !bVar5)) {
              if (piVar3 != (int *)0x0) {
                *piVar3 = local_a8;
              }
              bVar5 = true;
            }
            iVar23 = FUN_00074dcd(local_98,0,0,local_88);
            if (iVar23 != 0) {
              return iVar23;
            }
            puVar29 = *(uint **)(param_1 + 0x34);
          }
          goto LAB_000784c7;
        }
        if (1 < (*(byte *)((int)local_64 + 1) & 0xf) - 2) goto LAB_000784c7;
        piVar24 = *(int **)(param_1 + 0x10450);
        if (piVar24 == (int *)0x0) {
          uVar17 = *local_64;
        }
        else {
          uVar17 = *local_64;
          do {
            local_20 = *(uint *)(param_1 + (int)(((unsigned char *)0x0001286c) + *piVar24 * 0x10));
            if ((uVar17 & 0xfe000) == (local_20 & 0xfe000)) {
              uVar17 = FUN_00073220();
              local_98 = local_98 & ~uVar17;
              FUN_00074d85();
              uVar17 = *local_64;
            }
            piVar24 = (int *)piVar24[4];
          } while (piVar24 != (int *)0x0);
        }
        if ((uVar17 & 0xfe000) == 0) {
          local_60[0x800] = 1;
        }
        if ((!bVar5) && ((*local_64 & 0xfe000) == 0)) {
          if (piVar3 != (int *)0x0) {
            *piVar3 = local_a8;
          }
          bVar5 = true;
        }
        iVar23 = FUN_00074dcd(local_98,0,0,local_88);
        if (iVar23 != 0) {
          return iVar23;
        }
        if ((*local_64 & 0xf00) != 0x300) {
          puVar29 = *(uint **)(param_1 + 0x34);
          goto LAB_000784c7;
        }
        bVar6 = true;
        puVar29 = *(uint **)(param_1 + 0x34);
      }
      cVar9 = FUN_000731c4();
      if (((cVar9 != '\0') || (cVar9 = FUN_000731ef(), cVar9 != '\0')) &&
         (piVar24 = (int *)local_60[0x1000], piVar24 != (int *)0x0)) {
        do {
          iVar23 = *(int *)(param_1 + *piVar24 * 4 + 0x8450);
          if (iVar23 != 0) {
            local_60[0x800] = 1;
          }
          piVar24 = (int *)piVar24[4];
          if (piVar24 == (int *)0x0) {
            puVar29 = *(uint **)(param_1 + 0x34);
            goto LAB_00078520;
          }
        } while (iVar23 == 0);
        puVar29 = *(uint **)(param_1 + 0x34);
      }
LAB_00078520:
      cVar9 = FUN_000731c4();
      if ((cVar9 != '\0') || (cVar9 = FUN_000731ef(), cVar9 != '\0')) {
        uVar17 = local_60[0x1000];
        if (uVar17 == 0) {
          uVar25 = 0;
        }
        else {
          uVar25 = 0;
          do {
            uVar25 = uVar25 | *(uint *)(uVar17 + 4);
            uVar17 = *(uint *)(uVar17 + 0x10);
          } while (uVar17 != 0);
        }
        if (local_98 != uVar25) {
          FUN_00074d85();
          puVar29 = *(uint **)(param_1 + 0x34);
        }
      }
      if ((((byte)*local_64 == 0x41) && ((char)(byte)*puVar29 < '\0')) &&
         (uVar17 = local_60[0x1000], uVar17 != 0)) {
        uVar25 = 0;
        do {
          uVar25 = uVar25 | *(uint *)(uVar17 + 4);
          uVar17 = *(uint *)(uVar17 + 0x10);
        } while (uVar17 != 0);
        if ((uVar25 & 7) == 2) {
          *(byte *)local_64 = 6;
          FUN_00074e72();
          ((int (*)())FUN_00074eba)();
          if (local_100 == (undefined4 *)0x0) {
            puVar29 = *(uint **)(param_1 + 0x34);
          }
          else {
            puVar27 = local_100 + local_5c;
            iVar23 = 4;
            pbVar28 = pbVar20;
            do {
              *puVar27 = *(undefined4 *)pbVar28;
              pbVar28 = pbVar28 + 4;
              puVar27 = puVar27 + 1;
              iVar23 = iVar23 + -1;
            } while (iVar23 != 0);
            puVar29 = *(uint **)(param_1 + 0x34);
          }
        }
      }
      if (((byte)*local_64 == 0x44) &&
         (cVar9 = FUN_000731c4(), puVar26 = local_2c[0], cVar9 != '\0')) {
        *(byte *)((int)local_64 + 2) = *(byte *)((int)local_64 + 2) & 0x6f;
        puVar29 = *(uint **)(param_1 + 0x34);
        if ((((*puVar29 >> 6 & 1) != 0) &&
            (((cVar9 = FUN_00073a73(), puVar7 = local_2c[1], cVar9 != '\0' &&
              (cVar9 = FUN_00073a73(), puVar30 = local_2c[2], cVar9 != '\0')) &&
             (cVar9 = FUN_00073a73(), cVar9 != '\0')))) &&
           ((uVar22 = (ushort)*puVar26 & 0x1fe0, uVar22 == ((ushort)*puVar7 & 0x1fe0) &&
            (uVar22 == ((ushort)*puVar30 & 0x1fe0))))) {
          uVar25 = (*(ushort *)((int)puVar7 + 2) >> 6 & 7) << 0xd;
          uVar17 = *puVar26;
          *puVar26 = uVar17 & 0xffff1fff | uVar25;
          *puVar26 = uVar17 & 0xfff81fff | uVar25 | (*(ushort *)((int)puVar30 + 2) >> 6 & 7) << 0x10
          ;
          uVar25 = (*(ushort *)((int)puVar26 + 2) >> 6 & 7) << 0xd;
          uVar17 = *puVar7;
          *puVar7 = uVar17 & 0xffff1fff | uVar25;
          *puVar7 = uVar17 & 0xfff81fff | uVar25 | (*(ushort *)((int)puVar30 + 2) >> 6 & 7) << 0x10;
          uVar25 = (*(ushort *)((int)puVar26 + 2) >> 6 & 7) << 0xd;
          uVar17 = *puVar30;
          *puVar30 = uVar17 & 0xffff1fff | uVar25;
          *puVar30 = uVar17 & 0xfff81fff | uVar25 | (*(ushort *)((int)puVar7 + 2) >> 6 & 7) << 0x10;
          puVar29 = *(uint **)(param_1 + 0x34);
        }
      }
      if ((local_100 != (undefined4 *)0x0) && ((*puVar29 & 0x200) != 0)) {
        puVar27 = local_100 + local_5c;
        iVar23 = 4;
        do {
          *puVar27 = *(undefined4 *)pbVar20;
          pbVar20 = pbVar20 + 4;
          puVar27 = puVar27 + 1;
          iVar23 = iVar23 + -1;
        } while (iVar23 != 0);
      }
      uVar17 = FUN_00073a81();
      puVar7 = local_2c[2];
      puVar26 = local_2c[1];
      puVar29 = local_2c;
      *local_60 = uVar17;
      local_40 = 0;
      do {
        if ((uVar17 & 1 << ((byte)local_40 & 0x1f)) == 0) {
          *local_2c[local_40] =
               *local_2c[local_40] & 0xfffffff0 |
               (uint)(byte)((-((**(uint **)(param_1 + 0x34) & 0x40) == 0) & 4U) + 5);
          goto LAB_000788ca;
        }
        uVar25 = **(uint **)(param_1 + 0x34) >> 6;
        puVar30 = local_2c[local_40];
        bVar8 = (byte)*puVar30;
        bVar10 = bVar8 & 0xf;
        if (bVar10 == 0) {
LAB_00078c27:
          bVar4 = true;
        }
        else {
          if (bVar10 == 3) {
            if ((uVar25 & 1) != 0) goto LAB_00078c27;
          }
          else if ((bVar10 == 1) && ((uVar25 & 1) != 0)) {
            bVar4 = true;
            goto LAB_00078660;
          }
          bVar4 = false;
        }
LAB_00078660:
        if (!bVar4) {
          cVar9 = FUN_000743a3();
          if (cVar9 != '\0') {
            if ((uVar25 & 1) == 0) {
              bVar8 = bVar8 >> 4 & 1;
            }
            else {
              bVar8 = ((char)*(byte *)((int)puVar30 + 3) >> 7) * -2 | bVar8 >> 4 & 1;
            }
            if (bVar8 == 1) {
              bVar8 = *(byte *)((int)puVar30 + 3);
              if (-1 < local_a8 + -1) {
                local_7c = 0;
                puVar30 = local_64;
                do {
                  puVar30 = puVar30 + -4;
                  local_20 = *puVar30;
                  cVar9 = FUN_000731ef();
                  if ((cVar9 == '\0') || (iVar23 = FUN_000743b5(), iVar23 == 0)) {
                    bVar4 = false;
                  }
                  else {
                    FUN_00074dcd(1 << (bVar8 >> 5 & 3),0,0,local_88);
                    bVar4 = true;
                  }
                } while ((local_7c != local_a8 + -1) && (local_7c = local_7c + 1, !bVar4));
              }
            }
          }
          goto switchD_00078682_caseD_0;
        }
        switch((byte)*local_64) {
        case 1:
          iVar23 = 0;
          do {
            iVar18 = FUN_00074e72();
            if (iVar18 != 4) {
              ((int (*)())FUN_00074fac)(local_88,local_a8,local_40,iVar23);
            }
            iVar23 = iVar23 + 1;
          } while (iVar23 != 4);
          break;
        case 2:
          iVar23 = 0;
          do {
            if (bVar6) {
              if (((iVar23 == 0) && (iVar18 = FUN_00073220(), iVar18 != 0)) &&
                 (iVar18 = FUN_00074e72(), iVar18 != 4)) {
                ((int (*)())FUN_00074fac)(local_88,local_a8,local_40,0);
              }
            }
            else {
              iVar18 = FUN_000743b5();
              if ((iVar18 != 0) && (iVar18 = FUN_00074e72(), iVar18 != 4)) {
                ((int (*)())FUN_00074fac)(local_88,local_a8,local_40,iVar23);
              }
            }
            iVar23 = iVar23 + 1;
          } while (iVar23 != 4);
          break;
        case 3:
        case 4:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 0xb:
        case 0xc:
        case 0xd:
        case 0xe:
        case 0x80:
        case 0x81:
          iVar23 = 0;
          do {
            if (bVar6) {
              if ((iVar23 == 0) && (iVar18 = FUN_00073220(), iVar18 != 0)) {
                iVar18 = 0;
LAB_000793b7:
                ((int (*)())FUN_00074fac)(local_88,local_a8,local_40,iVar18);
              }
            }
            else {
              iVar19 = FUN_000743b5();
              iVar18 = iVar23;
              if (iVar19 != 0) goto LAB_000793b7;
            }
            iVar23 = iVar23 + 1;
          } while (iVar23 != 4);
          break;
        case 5:
          iVar23 = 1;
          do {
            if (local_40 == 0) {
              if (iVar23 - 1U < 2) {
LAB_000790cf:
                iVar18 = FUN_000743b5();
                if (iVar18 != 0) {
                  ((int (*)())FUN_00074fac)(local_88,local_a8,local_40,iVar23);
                }
              }
            }
            else if ((local_40 == 1) && ((iVar23 == 1 || (iVar23 == 3)))) goto LAB_000790cf;
            iVar23 = iVar23 + 1;
          } while (iVar23 != 4);
          break;
        case 0x41:
        case 0x42:
        case 0x46:
        case 0x48:
        case 0x4b:
        case 0x4c:
        case 0x50:
        case 0x51:
          ((int (*)())FUN_00074fac)(local_88,local_a8,local_40,3);
          break;
        case 0x43:
        case 0x47:
        case 0x49:
          if ((uVar25 & 1) == 0) {
            ((int (*)())FUN_00074fac)(local_88,local_a8,local_40,0);
          }
          else {
            ((int (*)())FUN_00074fac)(local_88,local_a8,local_40,3);
          }
          break;
        case 0x44:
          if ((uVar25 & 1) == 0) {
            iVar23 = 0;
            do {
              ((int (*)())FUN_00074fac)(local_88,local_a8,local_40,iVar23);
              do {
                iVar23 = iVar23 + 1;
                if (3 < iVar23) goto switchD_00078682_caseD_0;
              } while (iVar23 == 2);
            } while( true );
          }
          if ((((*puVar29 & 0xf) == 0) && ((*puVar26 & 0xf) == 0)) &&
             (((*puVar7 & 0xf) == 0 &&
              ((uVar22 = (ushort)*puVar29 & 0x1fe0, uVar22 == ((ushort)*puVar26 & 0x1fe0) &&
               (uVar22 == ((ushort)*puVar7 & 0x1fe0))))))) {
            iVar23 = 0;
            do {
              ((int (*)())FUN_00074fac)(local_88,local_a8,local_40,iVar23);
              do {
                iVar23 = iVar23 + 1;
                if (3 < iVar23) goto switchD_00078682_caseD_0;
              } while (iVar23 == 2);
            } while( true );
          }
          goto LAB_00078b6e;
        case 0x45:
        case 0x4d:
        case 0x4e:
        case 0x4f:
          if ((uVar25 & 1) == 0) {
            iVar23 = 0;
            do {
              ((int (*)())FUN_00074fac)(local_88,local_a8,local_40,iVar23);
              do {
                iVar23 = iVar23 + 1;
                if (2 < iVar23) goto switchD_00078682_caseD_0;
              } while (((iVar23 == 1) && ((byte)*local_64 != 0xd)) && ((byte)*local_64 != 0xe));
            } while( true );
          }
LAB_00078b6e:
          ((int (*)())FUN_00074fac)(local_88,local_a8,local_40,3);
          break;
        case 0x4a:
          if ((uVar25 & 1) != 0) goto LAB_00078b6e;
          iVar23 = 0;
          do {
            ((int (*)())FUN_00074fac)(local_88,local_a8,local_40,iVar23);
            iVar23 = iVar23 + 1;
          } while (iVar23 != 2);
        }
switchD_00078682_caseD_0:
        for (iVar23 = *(int *)(param_1 + (local_a8 * 3 + local_40) * 4 + 0x450); iVar23 != 0;
            iVar23 = *(int *)(iVar23 + 0x10)) {
          iVar18 = FUN_00074dcd(*(undefined4 *)(iVar23 + 4),*(undefined4 *)(iVar23 + 8),0,local_88);
          if (iVar18 != 0) {
            return iVar18;
          }
        }
LAB_000788ca:
        local_40 = local_40 + 1;
      } while (local_40 != 3);
      local_a8 = local_a8 + -1;
      local_64 = local_64 + -4;
      local_60 = local_60 + -1;
      local_5c = local_5c + -4;
    } while (local_a8 != -1);
  }
  if (0 < (int)local_e8) {
    local_38 = 0;
    local_80 = local_88;
    do {
      for (piVar3 = *(int **)(local_80 + 0xa418); piVar3 != (int *)0x0; piVar3 = (int *)piVar3[4]) {
        uVar17 = *(uint *)(param_1 + *piVar3 * 4 + 0x6450);
        local_84 = param_1 + *piVar3 * 0xc + 0x450;
        local_a0 = 0;
        do {
          if (((uVar17 & 1 << ((byte)local_a0 & 0x1f)) != 0) &&
             (puVar29 = *(uint **)local_84, puVar29 != (uint *)0x0)) {
            bVar5 = false;
            puVar26 = puVar29;
            do {
              if (local_38 == *puVar26) {
                bVar5 = true;
              }
              puVar26 = (uint *)puVar26[4];
            } while (puVar26 != (uint *)0x0);
            if (bVar5) {
              do {
                if ((local_38 != *puVar29) &&
                   (iVar23 = FUN_00074dcd(puVar29[1],0,0,local_88), iVar23 != 0)) {
                  return iVar23;
                }
                puVar29 = (uint *)puVar29[4];
              } while (puVar29 != (uint *)0x0);
            }
          }
          local_a0 = local_a0 + 1;
          local_84 = local_84 + 4;
        } while (local_a0 != 3);
      }
      local_38 = local_38 + 1;
      local_80 = local_80 + 4;
    } while (local_e8 != local_38);
    local_34 = 0;
    pbVar28 = local_88;
    do {
      _memset(param_1 + 0x30c50,0,0x800);
      for (iVar23 = *(int *)(pbVar28 + 0xc418); iVar23 != 0; iVar23 = *(int *)(iVar23 + 0x10)) {
        ((int (*)())FUN_00074f22)(*(undefined4 *)(iVar23 + 4));
      }
      local_34 = local_34 + 1;
      pbVar28 = pbVar28 + 4;
    } while (local_e8 != local_34);
  }
  if (((piVar2 != (int *)0x0) && (iVar31 != 0)) && (*piVar2 = 0, 0 < (int)local_e8)) {
    local_30 = 0;
    do {
      if (*(int *)(local_88 + 0x8418) != 0) {
        iVar23 = 0;
        puVar27 = local_100;
        do {
          *(undefined4 *)(iVar31 + (iVar23 + *piVar2 * 4) * 4) = *puVar27;
          iVar23 = iVar23 + 1;
          puVar27 = puVar27 + 1;
        } while (iVar23 != 4);
        *piVar2 = *piVar2 + 1;
      }
      local_30 = local_30 + 1;
      local_88 = local_88 + 4;
      local_100 = local_100 + 4;
    } while (local_e8 != local_30);
  }
  if ((param_1[1] & 1) == 0) {
    iVar31 = ((int (*)())FUN_0007626b)();
    return iVar31;
  }
  return 0;
}

/* FUN_00079570 @ 0x79570 (46 bytes) */
int FUN_00079570(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(param_1 + 0x11b4);
  puVar2 = (undefined4 *)(**(code **)(param_1 + 0xc))(8);
  *puVar2 = param_2;
  puVar2[1] = *(undefined4 *)(iVar1 + 8);
  *(undefined4 **)(iVar1 + 8) = puVar2;
  return;
}

/* FUN_0007959e @ 0x7959e (99 bytes) */
int FUN_0007959e(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  iVar1 = *(int *)(param_1 + 0x11b4);
  if ((iVar1 != 0) && (piVar2 = *(int **)(iVar1 + 8), piVar2 != (int *)0x0)) {
    if (*piVar2 == param_2) {
      *(int *)(iVar1 + 8) = piVar2[1];
      (**(code **)(param_1 + 0x18))(piVar2);
    }
    else {
      do {
        piVar3 = piVar2;
        piVar2 = (int *)piVar3[1];
        if (piVar2 == (int *)0x0) {
          return 0;
        }
      } while (param_2 != *piVar2);
      piVar3[1] = piVar2[1];
      (**(code **)(param_1 + 0x18))(piVar2);
    }
    return 1;
  }
  return 0;
}

/* FUN_00079601 @ 0x79601 (12081 bytes) */
int FUN_00079601(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  byte bVar16;
  byte bVar17;
  byte bVar18;
  byte bVar19;
  float fVar20;
  float fVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  void *pvVar25;
  uint uVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  uint uVar29;
  int *piVar30;
  uint uVar31;
  bool bVar32;
  uint local_1b0;
  uint local_15c;
  uint local_e8;
  uint local_e4;
  byte local_dc;
  byte local_db;
  byte local_da;
  byte local_d9;
  uint local_d8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  uint local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  uint local_70;
  uint local_6c;
  uint local_68;
  byte local_40;
  byte local_3f;
  byte local_3e;
  byte local_3d;
  byte local_3c;
  byte local_3b;
  byte local_3a;
  byte local_39;
  uint local_38;
  char local_20;
  char local_1f;
  char local_1e;
  char local_1d [13];
  
  fVar21 = FLOAT_001c5bdc;
  fVar20 = FLOAT_001c5ba4;
  if (*(int *)(param_2 + 0x14) != 0) {
    uVar31 = 0;
LAB_00079632:
    iVar23 = *(int *)(param_2 + 0x18);
    piVar30 = (int *)(iVar23 + uVar31 * 0x74);
    if ((((((*piVar30 == 0x8799) && (piVar30[8] == 2)) && (piVar30[10] == 0x87d5)) &&
         ((piVar30[0xb] == 0x87d6 && (piVar30[0xc] == 0x87d7)))) && (piVar30[0xd] == 0x87d8)) &&
       ((iVar24 = *(int *)(param_2 + 0x20) + piVar30[9] * 0x54, *(int *)(iVar24 + 0x28) == 0x87c3 &&
        (*(int *)(iVar24 + 0x24) == 0x87bf)))) {
      pfVar6 = *(float **)(iVar24 + 0x38);
      fVar2 = *pfVar6;
      bVar7 = fVar2 == 0.0;
      bVar8 = fVar2 == fVar20;
      fVar3 = pfVar6[1];
      bVar32 = fVar3 == 0.0;
      bVar9 = fVar3 == fVar20;
      fVar4 = pfVar6[2];
      bVar10 = fVar4 == 0.0;
      bVar11 = fVar4 == fVar20;
      fVar5 = pfVar6[3];
      bVar12 = fVar5 == 0.0;
      bVar13 = fVar5 == fVar20;
      if (((((bVar7) || (((bVar8 || (fVar2 == fVar21)) || (bVar32)))) ||
           (((bVar9 || (fVar3 == fVar21)) || (bVar10)))) ||
          (((bVar11 || (fVar4 == fVar21)) || ((bVar12 || ((bVar13 || (fVar5 == fVar21)))))))) &&
         (uVar29 = uVar31 + 1, uVar29 < *(uint *)(param_2 + 0x14))) {
        iVar22 = uVar29 * 0x74;
        bVar15 = false;
        iVar24 = iVar22;
        local_e4 = uVar29;
        do {
          piVar1 = (int *)(iVar24 + iVar23);
          if (((*piVar1 == 0x879b) && (piVar1[1] == 2)) && (piVar1[2] == piVar30[2])) {
            if (((piVar1[3] != 0) || (bVar7)) || ((bVar8 || (fVar2 == fVar21)))) {
              bVar19 = 1;
            }
            else {
              bVar19 = 0;
            }
            if (((piVar1[4] != 0) || (bVar32)) || ((bVar9 || (fVar3 == fVar21)))) {
              bVar18 = 1;
            }
            else {
              bVar18 = 0;
            }
            if ((((piVar1[5] != 0) || (bVar10)) || (bVar11)) || (fVar4 == fVar21)) {
              bVar17 = 1;
            }
            else {
              bVar17 = 0;
            }
            if (((piVar1[6] != 0) || (bVar12)) || ((bVar13 || (fVar5 == fVar21)))) {
              bVar16 = 1;
            }
            else {
              bVar16 = 0;
            }
            bVar15 = (bool)(bVar19 & bVar18 & bVar17 & bVar16);
            if (bVar15) {
              if (piVar1[3] == 0) {
                piVar1[3] = 1;
                if (bVar7) {
                  piVar1[10] = 0x87dd;
                }
                else {
                  piVar1[10] = ((int)((uint)bVar8 << 0x1f) >> 0x1f) + 0x87df;
                }
              }
              if (piVar1[4] == 0) {
                piVar1[4] = 1;
                if (bVar32) {
                  piVar1[0xb] = 0x87dd;
                }
                else {
                  piVar1[0xb] = ((int)((uint)bVar9 << 0x1f) >> 0x1f) + 0x87df;
                }
              }
              if (piVar1[5] == 0) {
                piVar1[5] = 1;
                if (bVar10) {
                  piVar1[0xc] = 0x87dd;
                }
                else {
                  piVar1[0xc] = ((int)((uint)bVar11 << 0x1f) >> 0x1f) + 0x87df;
                }
              }
              if (piVar1[6] == 0) {
                piVar1[6] = 1;
                if (bVar12) {
                  piVar1[0xd] = 0x87dd;
                  bVar14 = true;
                }
                else if (bVar13) {
                  piVar1[0xd] = 0x87de;
                  bVar14 = true;
                }
                else {
                  piVar1[0xd] = 0x87df;
                  bVar14 = true;
                }
                goto LAB_00079b05;
              }
            }
            bVar14 = true;
          }
          else {
            bVar14 = false;
          }
LAB_00079b05:
          local_e4 = local_e4 + 1;
          if ((*(uint *)(param_2 + 0x14) <= local_e4) || (iVar24 = iVar24 + 0x74, bVar14))
          goto LAB_0007b997;
          iVar23 = *(int *)(param_2 + 0x18);
        } while( true );
      }
    }
    goto LAB_00079659;
  }
LAB_00079661:
  local_d8 = 0;
  local_15c = *(uint *)(param_2 + 0x14);
  do {
    if (local_15c < 2) {
      bVar7 = false;
    }
    else {
      bVar7 = false;
      uVar31 = local_15c;
      do {
        local_90 = uVar31 * 0x74;
        iVar23 = *(int *)(param_2 + 0x18) + local_90;
        if (((((*(int *)(iVar23 + -0x74) == 0x879b) || (*(int *)(iVar23 + -0x74) == 0x8799)) &&
             (*(int *)(iVar23 + -0x54) == 2)) &&
            ((*(char *)(iVar23 + -0x3c) == '\0' &&
             ((*(char *)(param_2 + 0x7b) == '\0' ||
              (*(int *)(*(int *)(param_2 + 0x20) + 0x28 + *(int *)(iVar23 + -0x6c) * 0x54) != 0x87c4
              )))))) &&
           ((*(int *)(iVar23 + -0x4c) == 0x87d5 &&
            (((*(int *)(iVar23 + -0x48) == 0x87d6 && (*(int *)(iVar23 + -0x44) == 0x87d7)) &&
             (*(int *)(iVar23 + -0x40) == 0x87d8)))))) {
          if (uVar31 < local_15c) {
            local_dc = 0;
            local_db = 0;
            local_da = 0;
            local_d9 = 0;
            bVar8 = true;
            iVar24 = iVar23;
            local_1b0 = uVar31;
            do {
              if (((*(int *)(iVar24 + 0x20) == 2) &&
                  (*(int *)(iVar24 + 0x24) == *(int *)(iVar23 + -0x50))) ||
                 (((*(int *)(iVar24 + 0x3c) == 2 &&
                   (*(int *)(iVar24 + 0x40) == *(int *)(iVar23 + -0x50))) ||
                  ((*(int *)(iVar24 + 0x58) == 2 &&
                   (*(int *)(iVar24 + 0x5c) == *(int *)(iVar23 + -0x50))))))) {
                bVar32 = true;
                bVar8 = false;
              }
              else {
                if ((*(int *)(iVar24 + 4) == 2) &&
                   (*(int *)(iVar24 + 8) == *(int *)(iVar23 + -0x50))) {
                  local_db = local_db | *(byte *)(iVar24 + 0x10);
                  local_da = local_da | *(byte *)(iVar24 + 0x14);
                  local_d9 = local_d9 | *(byte *)(iVar24 + 0x18);
                  local_dc = local_dc | *(byte *)(iVar24 + 0xc);
                  if ((local_dc != 0) && ((local_db != 0 && (local_da != 0)))) {
                    bVar32 = local_d9 != 0;
                    goto LAB_00079c1a;
                  }
                }
                bVar32 = false;
              }
LAB_00079c1a:
              local_1b0 = local_1b0 + 1;
            } while ((local_15c != local_1b0) && (iVar24 = iVar24 + 0x74, !bVar32));
            if (!bVar8) goto LAB_000796cd;
          }
          local_1b0 = uVar31 - 1;
          if (local_1b0 != 0) {
            local_39 = 0;
            local_3b = 0;
            local_3d = 0;
            local_3f = 0;
            bVar8 = false;
            piVar30 = (int *)(*(int *)(param_2 + 0x18) + -0x74 + local_1b0 * 0x74);
            do {
              if ((((piVar30[8] == 2) && (piVar30[9] == *(int *)(iVar23 + -0x50))) ||
                  ((piVar30[0xf] == 2 && (piVar30[0x10] == *(int *)(iVar23 + -0x50))))) ||
                 ((piVar30[0x16] == 2 && (piVar30[0x17] == *(int *)(iVar23 + -0x50))))) {
                local_d8 = local_1b0 - 1;
                bVar32 = true;
                bVar8 = true;
              }
              else if ((((piVar30[8] == 2) && (piVar30[9] == *(int *)(iVar23 + -0x6c))) ||
                       ((piVar30[0xf] == 2 && (piVar30[0x10] == *(int *)(iVar23 + -0x6c))))) ||
                      ((piVar30[0x16] == 2 && (piVar30[0x17] == *(int *)(iVar23 + -0x6c))))) {
                bVar32 = true;
                bVar8 = false;
              }
              else {
                bVar32 = false;
              }
              local_1b0 = local_1b0 - 1;
              if ((((uint *)*piVar30 != &UINT_0000879c) && (piVar30[1] == 2)) &&
                 (piVar30[2] == *(int *)(iVar23 + -0x50))) {
                local_3f = local_3f | *(byte *)(piVar30 + 3);
                local_3d = local_3d | *(byte *)(piVar30 + 4);
                local_3b = local_3b | *(byte *)(piVar30 + 5);
                local_39 = local_39 | *(byte *)(piVar30 + 6);
                if (((*(uint *)(iVar23 + -0x68) <= (uint)local_3f) &&
                    (*(uint *)(iVar23 + -100) <= (uint)local_3d)) &&
                   ((*(uint *)(iVar23 + -0x60) <= (uint)local_3b &&
                    (*(uint *)(iVar23 + -0x5c) <= (uint)local_39)))) {
                  local_d8 = local_1b0;
                  bVar32 = true;
                  bVar8 = true;
                }
              }
            } while ((local_1b0 != 0) && (piVar30 = piVar30 + -0x1d, !bVar32));
            if (bVar8) {
              FUN_000b5478(param_2 + 0x1c,iVar23 + -0x74,*(undefined4 *)(iVar23 + -0x50),local_1d,
                           &local_1e,&local_1f,&local_20);
              if ((local_1d[0] == '\0') || (local_3f != 0)) {
                if ((local_1e == '\0') || (local_3d != 0)) {
                  if ((local_1f == '\0') || (local_3b != 0)) {
                    if ((local_20 == '\0') || (local_39 != 0)) {
                      if (local_d8 < uVar31) {
                        local_88 = local_d8 * 0x74;
                        local_8c = 0;
                        do {
                          piVar30 = (int *)(local_88 + *(int *)(param_2 + 0x18));
                          if ((((uint *)*piVar30 != &UINT_0000879c) && (piVar30[1] == 2)) &&
                             (piVar30[2] == *(int *)(iVar23 + -0x50))) {
                            piVar30[1] = *(int *)(iVar23 + -0x70);
                            piVar30[2] = *(int *)(iVar23 + -0x6c);
                            piVar30[3] = piVar30[3] & *(uint *)(iVar23 + -0x68);
                            piVar30[4] = piVar30[4] & *(uint *)(iVar23 + -100);
                            piVar30[5] = piVar30[5] & *(uint *)(iVar23 + -0x60);
                            piVar30[6] = piVar30[6] & *(uint *)(iVar23 + -0x5c);
                          }
                          local_8c = local_8c + 1;
                          local_88 = local_88 + 0x74;
                        } while (uVar31 - local_d8 != local_8c);
                      }
                      local_15c = *(uint *)(param_2 + 0x14);
                      uVar29 = uVar31;
                      if (uVar31 < local_15c) {
                        do {
                          pvVar25 = (void *)(local_90 + *(int *)(param_2 + 0x18));
                          _memcpy((void *)((int)pvVar25 + -0x74),pvVar25,0x74);
                          uVar29 = uVar29 + 1;
                          local_15c = *(uint *)(param_2 + 0x14);
                          local_90 = local_90 + 0x74;
                        } while (uVar29 < local_15c);
                      }
                      local_15c = local_15c - 1;
                      *(uint *)(param_2 + 0x14) = local_15c;
                      bVar7 = true;
                    }
                    else {
                      local_15c = *(uint *)(param_2 + 0x14);
                    }
                  }
                  else {
                    local_15c = *(uint *)(param_2 + 0x14);
                  }
                }
                else {
                  local_15c = *(uint *)(param_2 + 0x14);
                }
              }
              else {
                local_15c = *(uint *)(param_2 + 0x14);
              }
            }
          }
        }
LAB_000796cd:
        uVar31 = uVar31 - 1;
      } while (1 < uVar31);
    }
    if (local_15c != 0) {
      local_38 = 0;
LAB_00079704:
      do {
        iVar23 = *(int *)(param_2 + 0x18);
        iVar22 = local_38 * 0x74;
        piVar30 = (int *)(iVar23 + iVar22);
        iVar24 = *piVar30;
        if (((iVar24 != 0x879b) && (iVar24 != 0x8799)) && (iVar24 != 0x879a)) goto LAB_000796f9;
        if ((((char)piVar30[0xe] == '\0') && (piVar30[1] == 2)) &&
           (((*(char *)(param_2 + 0x7b) == '\0' ||
             (*(int *)(*(int *)(param_2 + 0x20) + 0x28 + piVar30[2] * 0x54) != 0x87c4)) &&
            ((((piVar30[3] != 0 && (piVar30[4] != 0)) && (piVar30[5] != 0)) && (piVar30[6] != 0)))))
           ) {
          uVar29 = local_38 + 1;
          uVar31 = uVar29;
          if (uVar29 < local_15c) {
            local_d8 = local_15c;
            bVar8 = true;
            iVar24 = iVar23 + uVar29 * 0x74;
            do {
              if (*(int *)(iVar24 + 4) == 2) {
                bVar32 = *(int *)(iVar24 + 8) == piVar30[2];
                if (bVar32) {
                  local_d8 = uVar31 + 1;
                }
                if (piVar30[9] == *(int *)(iVar24 + 8)) {
                  bVar32 = true;
                  bVar8 = false;
                }
              }
              else {
                bVar32 = false;
              }
              uVar31 = uVar31 + 1;
              iVar24 = iVar24 + 0x74;
            } while ((uVar31 < local_15c) && (!bVar32));
            if (!bVar8) goto LAB_000796f9;
          }
          else {
            local_d8 = local_15c;
          }
          bVar8 = true;
          iVar24 = iVar23 + -0x74 + uVar31 * 0x74;
          local_40 = *(byte *)(iVar24 + 0xc);
          local_3e = *(byte *)(iVar24 + 0x10);
          local_3c = *(byte *)(iVar24 + 0x14);
          local_3a = *(byte *)(iVar24 + 0x18);
          if (local_d8 < *(uint *)(param_2 + 0x14)) {
            local_94 = local_d8 * 0x74;
            local_70 = local_d8;
            do {
              iVar23 = iVar23 + local_94;
              if ((((*(int *)(iVar23 + 0x20) == 2) && (*(int *)(iVar23 + 0x24) == piVar30[2])) ||
                  ((*(int *)(iVar23 + 0x3c) == 2 && (*(int *)(iVar23 + 0x40) == piVar30[2])))) ||
                 ((*(int *)(iVar23 + 0x58) == 2 && (*(int *)(iVar23 + 0x5c) == piVar30[2])))) {
                FUN_000b5478(param_2 + 0x1c,iVar23,piVar30[2],local_1d,&local_1e,&local_1f,&local_20
                            );
                if ((local_1d[0] == '\0') || (local_40 != 0)) {
                  if ((local_1e == '\0') || (local_3e != 0)) {
                    if ((local_1f == '\0') || (local_3c != 0)) {
                      if ((local_20 != '\0') && (local_3a == 0)) goto LAB_00079ea6;
                    }
                    else {
                      bVar8 = false;
                    }
                  }
                  else {
                    bVar8 = false;
                  }
                }
                else {
LAB_00079ea6:
                  bVar8 = false;
                }
              }
              if ((*(int *)(iVar23 + 4) == 2) && (*(int *)(iVar23 + 8) == piVar30[2])) {
                local_40 = local_40 | *(byte *)(iVar23 + 0xc);
                local_3e = local_3e | *(byte *)(iVar23 + 0x10);
                local_3c = local_3c | *(byte *)(iVar23 + 0x14);
                local_3a = local_3a | *(byte *)(iVar23 + 0x18);
              }
              local_70 = local_70 + 1;
              local_94 = local_94 + 0x74;
              if (*(uint *)(param_2 + 0x14) <= local_70) goto LAB_0007a1f1;
              iVar23 = *(int *)(param_2 + 0x18);
            } while( true );
          }
          goto LAB_0007a202;
        }
        local_38 = local_38 + 1;
      } while (local_38 < local_15c);
    }
LAB_0007974d: ;
  } while (bVar7);
  uVar31 = 0;
  if (local_15c != 0) {
    local_a0 = local_15c * 0x74;
    local_a4 = 0;
    do {
      uVar31 = local_15c - local_a4;
      iVar23 = local_a0 + *(int *)(param_2 + 0x18);
      if (((*(int *)(iVar23 + -0x74) == 0x879d) && (*(int *)(iVar23 + -0x70) == 2)) &&
         (iVar24 = FUN_00053994(param_2 + 0x1c,iVar23 + -0x54), iVar24 == 0x87bf)) {
        local_e8 = *(uint *)(param_2 + 0x14);
        if (uVar31 < local_e8) {
          iVar24 = local_a0 + *(int *)(param_2 + 0x18);
          bVar8 = true;
          bVar7 = false;
          local_6c = uVar31;
          do {
            if ((*(int *)(iVar24 + 4) == 2) && (*(int *)(iVar24 + 8) == *(int *)(iVar23 + -0x6c))) {
              if (((*(int *)(iVar24 + 0xc) == 0) || (*(int *)(iVar24 + 0x10) == 0)) ||
                 ((*(int *)(iVar24 + 0x14) == 0 || (*(int *)(iVar24 + 0x18) == 0)))) {
LAB_0007a3e7:
                bVar32 = true;
                bVar8 = false;
              }
              else {
                bVar32 = true;
              }
            }
            else if (bVar7) {
              if ((((*(int *)(iVar24 + 0x20) == 2) &&
                   (*(int *)(iVar24 + 0x24) == *(int *)(iVar23 + -0x6c))) ||
                  ((*(int *)(iVar24 + 0x3c) == 2 &&
                   (*(int *)(iVar24 + 0x40) == *(int *)(iVar23 + -0x6c))))) ||
                 ((*(int *)(iVar24 + 0x58) == 2 &&
                  (*(int *)(iVar24 + 0x5c) == *(int *)(iVar23 + -0x6c))))) goto LAB_0007a3e7;
              bVar32 = false;
            }
            else {
              if (((*(int *)(iVar24 + 4) == 2) && (*(int *)(iVar23 + -0x54) == 2)) &&
                 (*(int *)(iVar24 + 8) == *(int *)(iVar23 + -0x50))) {
                iVar22 = *(int *)(iVar23 + -0x34);
                if (iVar22 == 0) {
                  iVar22 = *(int *)(iVar24 + 0xc);
                }
                else if (iVar22 == 1) {
                  iVar22 = *(int *)(iVar24 + 0x10);
                }
                else if (iVar22 == 2) {
                  iVar22 = *(int *)(iVar24 + 0x14);
                }
                else {
                  if (iVar22 != 3) goto LAB_0007a401;
                  iVar22 = *(int *)(iVar24 + 0x18);
                }
                if (iVar22 != 0) {
                  bVar32 = false;
                  bVar7 = true;
                  goto LAB_00079875;
                }
              }
LAB_0007a401:
              bVar32 = false;
              bVar7 = false;
            }
LAB_00079875:
            local_6c = local_6c + 1;
          } while ((local_e8 != local_6c) && (iVar24 = iVar24 + 0x74, !bVar32));
          if (!bVar8) goto LAB_00079795;
        }
        iVar24 = *(int *)(iVar23 + -0x34);
        if (iVar24 == 1) {
          uVar28 = *(undefined4 *)(iVar23 + -0x48);
        }
        else if (iVar24 == 0) {
          uVar28 = *(undefined4 *)(iVar23 + -0x4c);
        }
        else if (iVar24 == 2) {
          uVar28 = *(undefined4 *)(iVar23 + -0x44);
        }
        else {
          uVar28 = *(undefined4 *)(iVar23 + -0x40);
        }
        if (uVar31 < local_e8) {
          local_a8 = local_a0;
          local_68 = uVar31;
          do {
            iVar24 = local_a8 + *(int *)(param_2 + 0x18);
            if ((*(int *)(iVar24 + 0x20) != 2) ||
               (*(int *)(iVar24 + 0x24) != *(int *)(iVar23 + -0x6c))) goto LAB_0007a915;
            *(undefined4 *)(iVar24 + 0x24) = *(undefined4 *)(iVar23 + -0x50);
            uVar27 = *(undefined4 *)(iVar24 + 0x28);
            switch(*(undefined4 *)(iVar24 + 0x28)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(uVar28) {
              case 0x87d5:
switchD_0007d968_caseD_87d5:
                uVar27 = 0x87d9;
                break;
              case 0x87d6:
switchD_0007d968_caseD_87d6:
                uVar27 = 0x87da;
                break;
              case 0x87d7:
switchD_0007d968_caseD_87d7:
                uVar27 = 0x87db;
                break;
              case 0x87d8:
switchD_0007d968_caseD_87d8:
                uVar27 = 0x87dc;
                break;
              case 0x87d9:
switchD_0007d968_caseD_87d9:
                uVar27 = 0x87d5;
                break;
              case 0x87da:
switchD_0007d968_caseD_87da:
                uVar27 = 0x87d6;
                break;
              case 0x87db:
switchD_0007d968_caseD_87db:
                uVar27 = 0x87d7;
                break;
              case 0x87dc:
switchD_0007d968_caseD_87dc:
                uVar27 = 0x87d8;
                break;
              default:
                goto switchD_0007a9b2_caseD_87d5;
              case 0x87de:
switchD_0007d968_caseD_87de:
                uVar27 = 0x87df;
                break;
              case 0x87df:
switchD_0007d968_caseD_87df:
                uVar27 = 0x87de;
              }
              goto switchD_0007a9b2_default;
            case 0x87da:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007d968_caseD_87d5;
              case 0x87d6:
                goto switchD_0007d968_caseD_87d6;
              case 0x87d7:
                goto switchD_0007d968_caseD_87d7;
              case 0x87d8:
                goto switchD_0007d968_caseD_87d8;
              case 0x87d9:
                goto switchD_0007d968_caseD_87d9;
              case 0x87da:
                goto switchD_0007d968_caseD_87da;
              case 0x87db:
                goto switchD_0007d968_caseD_87db;
              case 0x87dc:
                goto switchD_0007d968_caseD_87dc;
              case 0x87de:
                goto switchD_0007d968_caseD_87de;
              case 0x87df:
                goto switchD_0007d968_caseD_87df;
              }
              break;
            case 0x87db:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007d968_caseD_87d5;
              case 0x87d6:
                goto switchD_0007d968_caseD_87d6;
              case 0x87d7:
                goto switchD_0007d968_caseD_87d7;
              case 0x87d8:
                goto switchD_0007d968_caseD_87d8;
              case 0x87d9:
                goto switchD_0007d968_caseD_87d9;
              case 0x87da:
                goto switchD_0007d968_caseD_87da;
              case 0x87db:
                goto switchD_0007d968_caseD_87db;
              case 0x87dc:
                goto switchD_0007d968_caseD_87dc;
              case 0x87de:
                goto switchD_0007d968_caseD_87de;
              case 0x87df:
                goto switchD_0007d968_caseD_87df;
              }
              break;
            case 0x87dc:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007d968_caseD_87d5;
              case 0x87d6:
                goto switchD_0007d968_caseD_87d6;
              case 0x87d7:
                goto switchD_0007d968_caseD_87d7;
              case 0x87d8:
                goto switchD_0007d968_caseD_87d8;
              case 0x87d9:
                goto switchD_0007d968_caseD_87d9;
              case 0x87da:
                goto switchD_0007d968_caseD_87da;
              case 0x87db:
                goto switchD_0007d968_caseD_87db;
              case 0x87dc:
                goto switchD_0007d968_caseD_87dc;
              case 0x87de:
                goto switchD_0007d968_caseD_87de;
              case 0x87df:
                goto switchD_0007d968_caseD_87df;
              }
              break;
            default:
              goto switchD_0007a9b2_default;
            }
switchD_0007a9b2_caseD_87d5:
            uVar27 = uVar28;
switchD_0007a9b2_default:
            *(undefined4 *)(iVar24 + 0x28) = uVar27;
            uVar27 = *(undefined4 *)(iVar24 + 0x2c);
            switch(*(undefined4 *)(iVar24 + 0x2c)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(uVar28) {
              case 0x87d5:
switchD_0007d7e4_caseD_87d5:
                uVar27 = 0x87d9;
                break;
              case 0x87d6:
switchD_0007d7e4_caseD_87d6:
                uVar27 = 0x87da;
                break;
              case 0x87d7:
switchD_0007d7e4_caseD_87d7:
                uVar27 = 0x87db;
                break;
              case 0x87d8:
switchD_0007d7e4_caseD_87d8:
                uVar27 = 0x87dc;
                break;
              case 0x87d9:
switchD_0007d7e4_caseD_87d9:
                uVar27 = 0x87d5;
                break;
              case 0x87da:
switchD_0007d7e4_caseD_87da:
                uVar27 = 0x87d6;
                break;
              case 0x87db:
switchD_0007d7e4_caseD_87db:
                uVar27 = 0x87d7;
                break;
              case 0x87dc:
switchD_0007d7e4_caseD_87dc:
                uVar27 = 0x87d8;
                break;
              default:
                goto switchD_0007a9f5_caseD_87d5;
              case 0x87de:
switchD_0007d7e4_caseD_87de:
                uVar27 = 0x87df;
                break;
              case 0x87df:
switchD_0007d7e4_caseD_87df:
                uVar27 = 0x87de;
              }
              goto switchD_0007a9f5_default;
            case 0x87da:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007d7e4_caseD_87d5;
              case 0x87d6:
                goto switchD_0007d7e4_caseD_87d6;
              case 0x87d7:
                goto switchD_0007d7e4_caseD_87d7;
              case 0x87d8:
                goto switchD_0007d7e4_caseD_87d8;
              case 0x87d9:
                goto switchD_0007d7e4_caseD_87d9;
              case 0x87da:
                goto switchD_0007d7e4_caseD_87da;
              case 0x87db:
                goto switchD_0007d7e4_caseD_87db;
              case 0x87dc:
                goto switchD_0007d7e4_caseD_87dc;
              case 0x87de:
                goto switchD_0007d7e4_caseD_87de;
              case 0x87df:
                goto switchD_0007d7e4_caseD_87df;
              }
              break;
            case 0x87db:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007d7e4_caseD_87d5;
              case 0x87d6:
                goto switchD_0007d7e4_caseD_87d6;
              case 0x87d7:
                goto switchD_0007d7e4_caseD_87d7;
              case 0x87d8:
                goto switchD_0007d7e4_caseD_87d8;
              case 0x87d9:
                goto switchD_0007d7e4_caseD_87d9;
              case 0x87da:
                goto switchD_0007d7e4_caseD_87da;
              case 0x87db:
                goto switchD_0007d7e4_caseD_87db;
              case 0x87dc:
                goto switchD_0007d7e4_caseD_87dc;
              case 0x87de:
                goto switchD_0007d7e4_caseD_87de;
              case 0x87df:
                goto switchD_0007d7e4_caseD_87df;
              }
              break;
            case 0x87dc:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007d7e4_caseD_87d5;
              case 0x87d6:
                goto switchD_0007d7e4_caseD_87d6;
              case 0x87d7:
                goto switchD_0007d7e4_caseD_87d7;
              case 0x87d8:
                goto switchD_0007d7e4_caseD_87d8;
              case 0x87d9:
                goto switchD_0007d7e4_caseD_87d9;
              case 0x87da:
                goto switchD_0007d7e4_caseD_87da;
              case 0x87db:
                goto switchD_0007d7e4_caseD_87db;
              case 0x87dc:
                goto switchD_0007d7e4_caseD_87dc;
              case 0x87de:
                goto switchD_0007d7e4_caseD_87de;
              case 0x87df:
                goto switchD_0007d7e4_caseD_87df;
              }
              break;
            default:
              goto switchD_0007a9f5_default;
            }
switchD_0007a9f5_caseD_87d5:
            uVar27 = uVar28;
switchD_0007a9f5_default:
            *(undefined4 *)(iVar24 + 0x2c) = uVar27;
            uVar27 = *(undefined4 *)(iVar24 + 0x30);
            switch(*(undefined4 *)(iVar24 + 0x30)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(uVar28) {
              case 0x87d5:
switchD_0007b740_caseD_87d5:
                uVar27 = 0x87d9;
                break;
              case 0x87d6:
switchD_0007b740_caseD_87d6:
                uVar27 = 0x87da;
                break;
              case 0x87d7:
switchD_0007b740_caseD_87d7:
                uVar27 = 0x87db;
                break;
              case 0x87d8:
switchD_0007b740_caseD_87d8:
                uVar27 = 0x87dc;
                break;
              case 0x87d9:
switchD_0007b740_caseD_87d9:
                uVar27 = 0x87d5;
                break;
              case 0x87da:
switchD_0007b740_caseD_87da:
                uVar27 = 0x87d6;
                break;
              case 0x87db:
switchD_0007b740_caseD_87db:
                uVar27 = 0x87d7;
                break;
              case 0x87dc:
switchD_0007b740_caseD_87dc:
                uVar27 = 0x87d8;
                break;
              default:
                goto switchD_0007aa3a_caseD_87d5;
              case 0x87de:
switchD_0007b740_caseD_87de:
                uVar27 = 0x87df;
                break;
              case 0x87df:
switchD_0007b740_caseD_87df:
                uVar27 = 0x87de;
              }
              goto switchD_0007aa3a_default;
            case 0x87da:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007b740_caseD_87d5;
              case 0x87d6:
                goto switchD_0007b740_caseD_87d6;
              case 0x87d7:
                goto switchD_0007b740_caseD_87d7;
              case 0x87d8:
                goto switchD_0007b740_caseD_87d8;
              case 0x87d9:
                goto switchD_0007b740_caseD_87d9;
              case 0x87da:
                goto switchD_0007b740_caseD_87da;
              case 0x87db:
                goto switchD_0007b740_caseD_87db;
              case 0x87dc:
                goto switchD_0007b740_caseD_87dc;
              case 0x87de:
                goto switchD_0007b740_caseD_87de;
              case 0x87df:
                goto switchD_0007b740_caseD_87df;
              }
              break;
            case 0x87db:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007b740_caseD_87d5;
              case 0x87d6:
                goto switchD_0007b740_caseD_87d6;
              case 0x87d7:
                goto switchD_0007b740_caseD_87d7;
              case 0x87d8:
                goto switchD_0007b740_caseD_87d8;
              case 0x87d9:
                goto switchD_0007b740_caseD_87d9;
              case 0x87da:
                goto switchD_0007b740_caseD_87da;
              case 0x87db:
                goto switchD_0007b740_caseD_87db;
              case 0x87dc:
                goto switchD_0007b740_caseD_87dc;
              case 0x87de:
                goto switchD_0007b740_caseD_87de;
              case 0x87df:
                goto switchD_0007b740_caseD_87df;
              }
              break;
            case 0x87dc:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007b740_caseD_87d5;
              case 0x87d6:
                goto switchD_0007b740_caseD_87d6;
              case 0x87d7:
                goto switchD_0007b740_caseD_87d7;
              case 0x87d8:
                goto switchD_0007b740_caseD_87d8;
              case 0x87d9:
                goto switchD_0007b740_caseD_87d9;
              case 0x87da:
                goto switchD_0007b740_caseD_87da;
              case 0x87db:
                goto switchD_0007b740_caseD_87db;
              case 0x87dc:
                goto switchD_0007b740_caseD_87dc;
              case 0x87de:
                goto switchD_0007b740_caseD_87de;
              case 0x87df:
                goto switchD_0007b740_caseD_87df;
              }
              break;
            default:
              goto switchD_0007aa3a_default;
            }
switchD_0007aa3a_caseD_87d5:
            uVar27 = uVar28;
switchD_0007aa3a_default:
            *(undefined4 *)(iVar24 + 0x30) = uVar27;
            uVar27 = *(undefined4 *)(iVar24 + 0x34);
            switch(*(undefined4 *)(iVar24 + 0x34)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(uVar28) {
              case 0x87d5:
switchD_0007b5bc_caseD_87d5:
                uVar27 = 0x87d9;
                break;
              case 0x87d6:
switchD_0007b5bc_caseD_87d6:
                uVar27 = 0x87da;
                break;
              case 0x87d7:
switchD_0007b5bc_caseD_87d7:
                uVar27 = 0x87db;
                break;
              case 0x87d8:
switchD_0007b5bc_caseD_87d8:
                uVar27 = 0x87dc;
                break;
              case 0x87d9:
switchD_0007b5bc_caseD_87d9:
                uVar27 = 0x87d5;
                break;
              case 0x87da:
switchD_0007b5bc_caseD_87da:
                uVar27 = 0x87d6;
                break;
              case 0x87db:
switchD_0007b5bc_caseD_87db:
                uVar27 = 0x87d7;
                break;
              case 0x87dc:
switchD_0007b5bc_caseD_87dc:
                uVar27 = 0x87d8;
                break;
              default:
                goto switchD_0007aa7e_caseD_87d5;
              case 0x87de:
switchD_0007b5bc_caseD_87de:
                uVar27 = 0x87df;
                break;
              case 0x87df:
switchD_0007b5bc_caseD_87df:
                uVar27 = 0x87de;
              }
              goto switchD_0007aa7e_default;
            case 0x87da:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007b5bc_caseD_87d5;
              case 0x87d6:
                goto switchD_0007b5bc_caseD_87d6;
              case 0x87d7:
                goto switchD_0007b5bc_caseD_87d7;
              case 0x87d8:
                goto switchD_0007b5bc_caseD_87d8;
              case 0x87d9:
                goto switchD_0007b5bc_caseD_87d9;
              case 0x87da:
                goto switchD_0007b5bc_caseD_87da;
              case 0x87db:
                goto switchD_0007b5bc_caseD_87db;
              case 0x87dc:
                goto switchD_0007b5bc_caseD_87dc;
              case 0x87de:
                goto switchD_0007b5bc_caseD_87de;
              case 0x87df:
                goto switchD_0007b5bc_caseD_87df;
              }
              break;
            case 0x87db:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007b5bc_caseD_87d5;
              case 0x87d6:
                goto switchD_0007b5bc_caseD_87d6;
              case 0x87d7:
                goto switchD_0007b5bc_caseD_87d7;
              case 0x87d8:
                goto switchD_0007b5bc_caseD_87d8;
              case 0x87d9:
                goto switchD_0007b5bc_caseD_87d9;
              case 0x87da:
                goto switchD_0007b5bc_caseD_87da;
              case 0x87db:
                goto switchD_0007b5bc_caseD_87db;
              case 0x87dc:
                goto switchD_0007b5bc_caseD_87dc;
              case 0x87de:
                goto switchD_0007b5bc_caseD_87de;
              case 0x87df:
                goto switchD_0007b5bc_caseD_87df;
              }
              break;
            case 0x87dc:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007b5bc_caseD_87d5;
              case 0x87d6:
                goto switchD_0007b5bc_caseD_87d6;
              case 0x87d7:
                goto switchD_0007b5bc_caseD_87d7;
              case 0x87d8:
                goto switchD_0007b5bc_caseD_87d8;
              case 0x87d9:
                goto switchD_0007b5bc_caseD_87d9;
              case 0x87da:
                goto switchD_0007b5bc_caseD_87da;
              case 0x87db:
                goto switchD_0007b5bc_caseD_87db;
              case 0x87dc:
                goto switchD_0007b5bc_caseD_87dc;
              case 0x87de:
                goto switchD_0007b5bc_caseD_87de;
              case 0x87df:
                goto switchD_0007b5bc_caseD_87df;
              }
              break;
            default:
              goto switchD_0007aa7e_default;
            }
switchD_0007aa7e_caseD_87d5:
            uVar27 = uVar28;
switchD_0007aa7e_default:
            *(undefined4 *)(iVar24 + 0x34) = uVar27;
LAB_0007a915:
            if ((*(int *)(iVar24 + 0x3c) != 2) ||
               (*(int *)(iVar24 + 0x40) != *(int *)(iVar23 + -0x6c))) goto LAB_0007a922;
            *(undefined4 *)(iVar24 + 0x40) = *(undefined4 *)(iVar23 + -0x50);
            uVar27 = *(undefined4 *)(iVar24 + 0x44);
            switch(*(undefined4 *)(iVar24 + 0x44)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(uVar28) {
              case 0x87d5:
switchD_0007b438_caseD_87d5:
                uVar27 = 0x87d9;
                break;
              case 0x87d6:
switchD_0007b438_caseD_87d6:
                uVar27 = 0x87da;
                break;
              case 0x87d7:
switchD_0007b438_caseD_87d7:
                uVar27 = 0x87db;
                break;
              case 0x87d8:
switchD_0007b438_caseD_87d8:
                uVar27 = 0x87dc;
                break;
              case 0x87d9:
switchD_0007b438_caseD_87d9:
                uVar27 = 0x87d5;
                break;
              case 0x87da:
switchD_0007b438_caseD_87da:
                uVar27 = 0x87d6;
                break;
              case 0x87db:
switchD_0007b438_caseD_87db:
                uVar27 = 0x87d7;
                break;
              case 0x87dc:
switchD_0007b438_caseD_87dc:
                uVar27 = 0x87d8;
                break;
              default:
                goto switchD_0007ac37_caseD_87d5;
              case 0x87de:
switchD_0007b438_caseD_87de:
                uVar27 = 0x87df;
                break;
              case 0x87df:
switchD_0007b438_caseD_87df:
                uVar27 = 0x87de;
              }
              goto switchD_0007ac37_default;
            case 0x87da:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007b438_caseD_87d5;
              case 0x87d6:
                goto switchD_0007b438_caseD_87d6;
              case 0x87d7:
                goto switchD_0007b438_caseD_87d7;
              case 0x87d8:
                goto switchD_0007b438_caseD_87d8;
              case 0x87d9:
                goto switchD_0007b438_caseD_87d9;
              case 0x87da:
                goto switchD_0007b438_caseD_87da;
              case 0x87db:
                goto switchD_0007b438_caseD_87db;
              case 0x87dc:
                goto switchD_0007b438_caseD_87dc;
              case 0x87de:
                goto switchD_0007b438_caseD_87de;
              case 0x87df:
                goto switchD_0007b438_caseD_87df;
              }
              break;
            case 0x87db:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007b438_caseD_87d5;
              case 0x87d6:
                goto switchD_0007b438_caseD_87d6;
              case 0x87d7:
                goto switchD_0007b438_caseD_87d7;
              case 0x87d8:
                goto switchD_0007b438_caseD_87d8;
              case 0x87d9:
                goto switchD_0007b438_caseD_87d9;
              case 0x87da:
                goto switchD_0007b438_caseD_87da;
              case 0x87db:
                goto switchD_0007b438_caseD_87db;
              case 0x87dc:
                goto switchD_0007b438_caseD_87dc;
              case 0x87de:
                goto switchD_0007b438_caseD_87de;
              case 0x87df:
                goto switchD_0007b438_caseD_87df;
              }
              break;
            case 0x87dc:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007b438_caseD_87d5;
              case 0x87d6:
                goto switchD_0007b438_caseD_87d6;
              case 0x87d7:
                goto switchD_0007b438_caseD_87d7;
              case 0x87d8:
                goto switchD_0007b438_caseD_87d8;
              case 0x87d9:
                goto switchD_0007b438_caseD_87d9;
              case 0x87da:
                goto switchD_0007b438_caseD_87da;
              case 0x87db:
                goto switchD_0007b438_caseD_87db;
              case 0x87dc:
                goto switchD_0007b438_caseD_87dc;
              case 0x87de:
                goto switchD_0007b438_caseD_87de;
              case 0x87df:
                goto switchD_0007b438_caseD_87df;
              }
              break;
            default:
              goto switchD_0007ac37_default;
            }
switchD_0007ac37_caseD_87d5:
            uVar27 = uVar28;
switchD_0007ac37_default:
            *(undefined4 *)(iVar24 + 0x44) = uVar27;
            uVar27 = *(undefined4 *)(iVar24 + 0x48);
            switch(*(undefined4 *)(iVar24 + 0x48)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(uVar28) {
              case 0x87d5:
switchD_0007b1c0_caseD_87d5:
                uVar27 = 0x87d9;
                break;
              case 0x87d6:
switchD_0007b1c0_caseD_87d6:
                uVar27 = 0x87da;
                break;
              case 0x87d7:
switchD_0007b1c0_caseD_87d7:
                uVar27 = 0x87db;
                break;
              case 0x87d8:
switchD_0007b1c0_caseD_87d8:
                uVar27 = 0x87dc;
                break;
              case 0x87d9:
switchD_0007b1c0_caseD_87d9:
                uVar27 = 0x87d5;
                break;
              case 0x87da:
switchD_0007b1c0_caseD_87da:
                uVar27 = 0x87d6;
                break;
              case 0x87db:
switchD_0007b1c0_caseD_87db:
                uVar27 = 0x87d7;
                break;
              case 0x87dc:
switchD_0007b1c0_caseD_87dc:
                uVar27 = 0x87d8;
                break;
              default:
                goto switchD_0007ac7d_caseD_87d5;
              case 0x87de:
switchD_0007b1c0_caseD_87de:
                uVar27 = 0x87df;
                break;
              case 0x87df:
switchD_0007b1c0_caseD_87df:
                uVar27 = 0x87de;
              }
              goto switchD_0007ac7d_default;
            case 0x87da:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007b1c0_caseD_87d5;
              case 0x87d6:
                goto switchD_0007b1c0_caseD_87d6;
              case 0x87d7:
                goto switchD_0007b1c0_caseD_87d7;
              case 0x87d8:
                goto switchD_0007b1c0_caseD_87d8;
              case 0x87d9:
                goto switchD_0007b1c0_caseD_87d9;
              case 0x87da:
                goto switchD_0007b1c0_caseD_87da;
              case 0x87db:
                goto switchD_0007b1c0_caseD_87db;
              case 0x87dc:
                goto switchD_0007b1c0_caseD_87dc;
              case 0x87de:
                goto switchD_0007b1c0_caseD_87de;
              case 0x87df:
                goto switchD_0007b1c0_caseD_87df;
              }
              break;
            case 0x87db:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007b1c0_caseD_87d5;
              case 0x87d6:
                goto switchD_0007b1c0_caseD_87d6;
              case 0x87d7:
                goto switchD_0007b1c0_caseD_87d7;
              case 0x87d8:
                goto switchD_0007b1c0_caseD_87d8;
              case 0x87d9:
                goto switchD_0007b1c0_caseD_87d9;
              case 0x87da:
                goto switchD_0007b1c0_caseD_87da;
              case 0x87db:
                goto switchD_0007b1c0_caseD_87db;
              case 0x87dc:
                goto switchD_0007b1c0_caseD_87dc;
              case 0x87de:
                goto switchD_0007b1c0_caseD_87de;
              case 0x87df:
                goto switchD_0007b1c0_caseD_87df;
              }
              break;
            case 0x87dc:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007b1c0_caseD_87d5;
              case 0x87d6:
                goto switchD_0007b1c0_caseD_87d6;
              case 0x87d7:
                goto switchD_0007b1c0_caseD_87d7;
              case 0x87d8:
                goto switchD_0007b1c0_caseD_87d8;
              case 0x87d9:
                goto switchD_0007b1c0_caseD_87d9;
              case 0x87da:
                goto switchD_0007b1c0_caseD_87da;
              case 0x87db:
                goto switchD_0007b1c0_caseD_87db;
              case 0x87dc:
                goto switchD_0007b1c0_caseD_87dc;
              case 0x87de:
                goto switchD_0007b1c0_caseD_87de;
              case 0x87df:
                goto switchD_0007b1c0_caseD_87df;
              }
              break;
            default:
              goto switchD_0007ac7d_default;
            }
switchD_0007ac7d_caseD_87d5:
            uVar27 = uVar28;
switchD_0007ac7d_default:
            *(undefined4 *)(iVar24 + 0x48) = uVar27;
            uVar27 = *(undefined4 *)(iVar24 + 0x4c);
            switch(*(undefined4 *)(iVar24 + 0x4c)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(uVar28) {
              case 0x87d5:
switchD_0007be14_caseD_87d5:
                uVar27 = 0x87d9;
                break;
              case 0x87d6:
switchD_0007be14_caseD_87d6:
                uVar27 = 0x87da;
                break;
              case 0x87d7:
switchD_0007be14_caseD_87d7:
                uVar27 = 0x87db;
                break;
              case 0x87d8:
switchD_0007be14_caseD_87d8:
                uVar27 = 0x87dc;
                break;
              case 0x87d9:
switchD_0007be14_caseD_87d9:
                uVar27 = 0x87d5;
                break;
              case 0x87da:
switchD_0007be14_caseD_87da:
                uVar27 = 0x87d6;
                break;
              case 0x87db:
switchD_0007be14_caseD_87db:
                uVar27 = 0x87d7;
                break;
              case 0x87dc:
switchD_0007be14_caseD_87dc:
                uVar27 = 0x87d8;
                break;
              default:
                goto switchD_0007acc2_caseD_87d5;
              case 0x87de:
switchD_0007be14_caseD_87de:
                uVar27 = 0x87df;
                break;
              case 0x87df:
switchD_0007be14_caseD_87df:
                uVar27 = 0x87de;
              }
              goto switchD_0007acc2_default;
            case 0x87da:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007be14_caseD_87d5;
              case 0x87d6:
                goto switchD_0007be14_caseD_87d6;
              case 0x87d7:
                goto switchD_0007be14_caseD_87d7;
              case 0x87d8:
                goto switchD_0007be14_caseD_87d8;
              case 0x87d9:
                goto switchD_0007be14_caseD_87d9;
              case 0x87da:
                goto switchD_0007be14_caseD_87da;
              case 0x87db:
                goto switchD_0007be14_caseD_87db;
              case 0x87dc:
                goto switchD_0007be14_caseD_87dc;
              case 0x87de:
                goto switchD_0007be14_caseD_87de;
              case 0x87df:
                goto switchD_0007be14_caseD_87df;
              }
              break;
            case 0x87db:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007be14_caseD_87d5;
              case 0x87d6:
                goto switchD_0007be14_caseD_87d6;
              case 0x87d7:
                goto switchD_0007be14_caseD_87d7;
              case 0x87d8:
                goto switchD_0007be14_caseD_87d8;
              case 0x87d9:
                goto switchD_0007be14_caseD_87d9;
              case 0x87da:
                goto switchD_0007be14_caseD_87da;
              case 0x87db:
                goto switchD_0007be14_caseD_87db;
              case 0x87dc:
                goto switchD_0007be14_caseD_87dc;
              case 0x87de:
                goto switchD_0007be14_caseD_87de;
              case 0x87df:
                goto switchD_0007be14_caseD_87df;
              }
              break;
            case 0x87dc:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007be14_caseD_87d5;
              case 0x87d6:
                goto switchD_0007be14_caseD_87d6;
              case 0x87d7:
                goto switchD_0007be14_caseD_87d7;
              case 0x87d8:
                goto switchD_0007be14_caseD_87d8;
              case 0x87d9:
                goto switchD_0007be14_caseD_87d9;
              case 0x87da:
                goto switchD_0007be14_caseD_87da;
              case 0x87db:
                goto switchD_0007be14_caseD_87db;
              case 0x87dc:
                goto switchD_0007be14_caseD_87dc;
              case 0x87de:
                goto switchD_0007be14_caseD_87de;
              case 0x87df:
                goto switchD_0007be14_caseD_87df;
              }
              break;
            default:
              goto switchD_0007acc2_default;
            }
switchD_0007acc2_caseD_87d5:
            uVar27 = uVar28;
switchD_0007acc2_default:
            *(undefined4 *)(iVar24 + 0x4c) = uVar27;
            uVar27 = *(undefined4 *)(iVar24 + 0x50);
            switch(*(undefined4 *)(iVar24 + 0x50)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(uVar28) {
              case 0x87d5:
switchD_0007bc90_caseD_87d5:
                uVar27 = 0x87d9;
                break;
              case 0x87d6:
switchD_0007bc90_caseD_87d6:
                uVar27 = 0x87da;
                break;
              case 0x87d7:
switchD_0007bc90_caseD_87d7:
                uVar27 = 0x87db;
                break;
              case 0x87d8:
switchD_0007bc90_caseD_87d8:
                uVar27 = 0x87dc;
                break;
              case 0x87d9:
switchD_0007bc90_caseD_87d9:
                uVar27 = 0x87d5;
                break;
              case 0x87da:
switchD_0007bc90_caseD_87da:
                uVar27 = 0x87d6;
                break;
              case 0x87db:
switchD_0007bc90_caseD_87db:
                uVar27 = 0x87d7;
                break;
              case 0x87dc:
switchD_0007bc90_caseD_87dc:
                uVar27 = 0x87d8;
                break;
              default:
                goto switchD_0007ad06_caseD_87d5;
              case 0x87de:
switchD_0007bc90_caseD_87de:
                uVar27 = 0x87df;
                break;
              case 0x87df:
switchD_0007bc90_caseD_87df:
                uVar27 = 0x87de;
              }
              goto switchD_0007ad06_default;
            case 0x87da:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007bc90_caseD_87d5;
              case 0x87d6:
                goto switchD_0007bc90_caseD_87d6;
              case 0x87d7:
                goto switchD_0007bc90_caseD_87d7;
              case 0x87d8:
                goto switchD_0007bc90_caseD_87d8;
              case 0x87d9:
                goto switchD_0007bc90_caseD_87d9;
              case 0x87da:
                goto switchD_0007bc90_caseD_87da;
              case 0x87db:
                goto switchD_0007bc90_caseD_87db;
              case 0x87dc:
                goto switchD_0007bc90_caseD_87dc;
              case 0x87de:
                goto switchD_0007bc90_caseD_87de;
              case 0x87df:
                goto switchD_0007bc90_caseD_87df;
              }
              break;
            case 0x87db:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007bc90_caseD_87d5;
              case 0x87d6:
                goto switchD_0007bc90_caseD_87d6;
              case 0x87d7:
                goto switchD_0007bc90_caseD_87d7;
              case 0x87d8:
                goto switchD_0007bc90_caseD_87d8;
              case 0x87d9:
                goto switchD_0007bc90_caseD_87d9;
              case 0x87da:
                goto switchD_0007bc90_caseD_87da;
              case 0x87db:
                goto switchD_0007bc90_caseD_87db;
              case 0x87dc:
                goto switchD_0007bc90_caseD_87dc;
              case 0x87de:
                goto switchD_0007bc90_caseD_87de;
              case 0x87df:
                goto switchD_0007bc90_caseD_87df;
              }
              break;
            case 0x87dc:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007bc90_caseD_87d5;
              case 0x87d6:
                goto switchD_0007bc90_caseD_87d6;
              case 0x87d7:
                goto switchD_0007bc90_caseD_87d7;
              case 0x87d8:
                goto switchD_0007bc90_caseD_87d8;
              case 0x87d9:
                goto switchD_0007bc90_caseD_87d9;
              case 0x87da:
                goto switchD_0007bc90_caseD_87da;
              case 0x87db:
                goto switchD_0007bc90_caseD_87db;
              case 0x87dc:
                goto switchD_0007bc90_caseD_87dc;
              case 0x87de:
                goto switchD_0007bc90_caseD_87de;
              case 0x87df:
                goto switchD_0007bc90_caseD_87df;
              }
              break;
            default:
              goto switchD_0007ad06_default;
            }
switchD_0007ad06_caseD_87d5:
            uVar27 = uVar28;
switchD_0007ad06_default:
            *(undefined4 *)(iVar24 + 0x50) = uVar27;
LAB_0007a922:
            if ((*(int *)(iVar24 + 0x58) != 2) ||
               (*(int *)(iVar24 + 0x5c) != *(int *)(iVar23 + -0x6c))) goto LAB_0007a92f;
            *(undefined4 *)(iVar24 + 0x5c) = *(undefined4 *)(iVar23 + -0x50);
            uVar27 = *(undefined4 *)(iVar24 + 0x60);
            switch(*(undefined4 *)(iVar24 + 0x60)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(uVar28) {
              case 0x87d5:
switchD_0007d4bc_caseD_87d5:
                uVar27 = 0x87d9;
                break;
              case 0x87d6:
switchD_0007d4bc_caseD_87d6:
                uVar27 = 0x87da;
                break;
              case 0x87d7:
switchD_0007d4bc_caseD_87d7:
                uVar27 = 0x87db;
                break;
              case 0x87d8:
switchD_0007d4bc_caseD_87d8:
                uVar27 = 0x87dc;
                break;
              case 0x87d9:
switchD_0007d4bc_caseD_87d9:
                uVar27 = 0x87d5;
                break;
              case 0x87da:
switchD_0007d4bc_caseD_87da:
                uVar27 = 0x87d6;
                break;
              case 0x87db:
switchD_0007d4bc_caseD_87db:
                uVar27 = 0x87d7;
                break;
              case 0x87dc:
switchD_0007d4bc_caseD_87dc:
                uVar27 = 0x87d8;
                break;
              default:
                goto switchD_0007aaff_caseD_87d5;
              case 0x87de:
switchD_0007d4bc_caseD_87de:
                uVar27 = 0x87df;
                break;
              case 0x87df:
switchD_0007d4bc_caseD_87df:
                uVar27 = 0x87de;
              }
              goto switchD_0007aaff_default;
            case 0x87da:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007d4bc_caseD_87d5;
              case 0x87d6:
                goto switchD_0007d4bc_caseD_87d6;
              case 0x87d7:
                goto switchD_0007d4bc_caseD_87d7;
              case 0x87d8:
                goto switchD_0007d4bc_caseD_87d8;
              case 0x87d9:
                goto switchD_0007d4bc_caseD_87d9;
              case 0x87da:
                goto switchD_0007d4bc_caseD_87da;
              case 0x87db:
                goto switchD_0007d4bc_caseD_87db;
              case 0x87dc:
                goto switchD_0007d4bc_caseD_87dc;
              case 0x87de:
                goto switchD_0007d4bc_caseD_87de;
              case 0x87df:
                goto switchD_0007d4bc_caseD_87df;
              }
              break;
            case 0x87db:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007d4bc_caseD_87d5;
              case 0x87d6:
                goto switchD_0007d4bc_caseD_87d6;
              case 0x87d7:
                goto switchD_0007d4bc_caseD_87d7;
              case 0x87d8:
                goto switchD_0007d4bc_caseD_87d8;
              case 0x87d9:
                goto switchD_0007d4bc_caseD_87d9;
              case 0x87da:
                goto switchD_0007d4bc_caseD_87da;
              case 0x87db:
                goto switchD_0007d4bc_caseD_87db;
              case 0x87dc:
                goto switchD_0007d4bc_caseD_87dc;
              case 0x87de:
                goto switchD_0007d4bc_caseD_87de;
              case 0x87df:
                goto switchD_0007d4bc_caseD_87df;
              }
              break;
            case 0x87dc:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007d4bc_caseD_87d5;
              case 0x87d6:
                goto switchD_0007d4bc_caseD_87d6;
              case 0x87d7:
                goto switchD_0007d4bc_caseD_87d7;
              case 0x87d8:
                goto switchD_0007d4bc_caseD_87d8;
              case 0x87d9:
                goto switchD_0007d4bc_caseD_87d9;
              case 0x87da:
                goto switchD_0007d4bc_caseD_87da;
              case 0x87db:
                goto switchD_0007d4bc_caseD_87db;
              case 0x87dc:
                goto switchD_0007d4bc_caseD_87dc;
              case 0x87de:
                goto switchD_0007d4bc_caseD_87de;
              case 0x87df:
                goto switchD_0007d4bc_caseD_87df;
              }
              break;
            default:
              goto switchD_0007aaff_default;
            }
switchD_0007aaff_caseD_87d5:
            uVar27 = uVar28;
switchD_0007aaff_default:
            *(undefined4 *)(iVar24 + 0x60) = uVar27;
            uVar27 = *(undefined4 *)(iVar24 + 100);
            switch(*(undefined4 *)(iVar24 + 100)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(uVar28) {
              case 0x87d5:
switchD_0007d244_caseD_87d5:
                uVar27 = 0x87d9;
                break;
              case 0x87d6:
switchD_0007d244_caseD_87d6:
                uVar27 = 0x87da;
                break;
              case 0x87d7:
switchD_0007d244_caseD_87d7:
                uVar27 = 0x87db;
                break;
              case 0x87d8:
switchD_0007d244_caseD_87d8:
                uVar27 = 0x87dc;
                break;
              case 0x87d9:
switchD_0007d244_caseD_87d9:
                uVar27 = 0x87d5;
                break;
              case 0x87da:
switchD_0007d244_caseD_87da:
                uVar27 = 0x87d6;
                break;
              case 0x87db:
switchD_0007d244_caseD_87db:
                uVar27 = 0x87d7;
                break;
              case 0x87dc:
switchD_0007d244_caseD_87dc:
                uVar27 = 0x87d8;
                break;
              default:
                goto switchD_0007ab45_caseD_87d5;
              case 0x87de:
switchD_0007d244_caseD_87de:
                uVar27 = 0x87df;
                break;
              case 0x87df:
switchD_0007d244_caseD_87df:
                uVar27 = 0x87de;
              }
              goto switchD_0007ab45_default;
            case 0x87da:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007d244_caseD_87d5;
              case 0x87d6:
                goto switchD_0007d244_caseD_87d6;
              case 0x87d7:
                goto switchD_0007d244_caseD_87d7;
              case 0x87d8:
                goto switchD_0007d244_caseD_87d8;
              case 0x87d9:
                goto switchD_0007d244_caseD_87d9;
              case 0x87da:
                goto switchD_0007d244_caseD_87da;
              case 0x87db:
                goto switchD_0007d244_caseD_87db;
              case 0x87dc:
                goto switchD_0007d244_caseD_87dc;
              case 0x87de:
                goto switchD_0007d244_caseD_87de;
              case 0x87df:
                goto switchD_0007d244_caseD_87df;
              }
              break;
            case 0x87db:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007d244_caseD_87d5;
              case 0x87d6:
                goto switchD_0007d244_caseD_87d6;
              case 0x87d7:
                goto switchD_0007d244_caseD_87d7;
              case 0x87d8:
                goto switchD_0007d244_caseD_87d8;
              case 0x87d9:
                goto switchD_0007d244_caseD_87d9;
              case 0x87da:
                goto switchD_0007d244_caseD_87da;
              case 0x87db:
                goto switchD_0007d244_caseD_87db;
              case 0x87dc:
                goto switchD_0007d244_caseD_87dc;
              case 0x87de:
                goto switchD_0007d244_caseD_87de;
              case 0x87df:
                goto switchD_0007d244_caseD_87df;
              }
              break;
            case 0x87dc:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007d244_caseD_87d5;
              case 0x87d6:
                goto switchD_0007d244_caseD_87d6;
              case 0x87d7:
                goto switchD_0007d244_caseD_87d7;
              case 0x87d8:
                goto switchD_0007d244_caseD_87d8;
              case 0x87d9:
                goto switchD_0007d244_caseD_87d9;
              case 0x87da:
                goto switchD_0007d244_caseD_87da;
              case 0x87db:
                goto switchD_0007d244_caseD_87db;
              case 0x87dc:
                goto switchD_0007d244_caseD_87dc;
              case 0x87de:
                goto switchD_0007d244_caseD_87de;
              case 0x87df:
                goto switchD_0007d244_caseD_87df;
              }
              break;
            default:
              goto switchD_0007ab45_default;
            }
switchD_0007ab45_caseD_87d5:
            uVar27 = uVar28;
switchD_0007ab45_default:
            *(undefined4 *)(iVar24 + 100) = uVar27;
            uVar27 = *(undefined4 *)(iVar24 + 0x68);
            switch(*(undefined4 *)(iVar24 + 0x68)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(uVar28) {
              case 0x87d5:
switchD_0007d0c0_caseD_87d5:
                uVar27 = 0x87d9;
                break;
              case 0x87d6:
switchD_0007d0c0_caseD_87d6:
                uVar27 = 0x87da;
                break;
              case 0x87d7:
switchD_0007d0c0_caseD_87d7:
                uVar27 = 0x87db;
                break;
              case 0x87d8:
switchD_0007d0c0_caseD_87d8:
                uVar27 = 0x87dc;
                break;
              case 0x87d9:
switchD_0007d0c0_caseD_87d9:
                uVar27 = 0x87d5;
                break;
              case 0x87da:
switchD_0007d0c0_caseD_87da:
                uVar27 = 0x87d6;
                break;
              case 0x87db:
switchD_0007d0c0_caseD_87db:
                uVar27 = 0x87d7;
                break;
              case 0x87dc:
switchD_0007d0c0_caseD_87dc:
                uVar27 = 0x87d8;
                break;
              default:
                goto switchD_0007ab8a_caseD_87d5;
              case 0x87de:
switchD_0007d0c0_caseD_87de:
                uVar27 = 0x87df;
                break;
              case 0x87df:
switchD_0007d0c0_caseD_87df:
                uVar27 = 0x87de;
              }
              goto switchD_0007ab8a_default;
            case 0x87da:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007d0c0_caseD_87d5;
              case 0x87d6:
                goto switchD_0007d0c0_caseD_87d6;
              case 0x87d7:
                goto switchD_0007d0c0_caseD_87d7;
              case 0x87d8:
                goto switchD_0007d0c0_caseD_87d8;
              case 0x87d9:
                goto switchD_0007d0c0_caseD_87d9;
              case 0x87da:
                goto switchD_0007d0c0_caseD_87da;
              case 0x87db:
                goto switchD_0007d0c0_caseD_87db;
              case 0x87dc:
                goto switchD_0007d0c0_caseD_87dc;
              case 0x87de:
                goto switchD_0007d0c0_caseD_87de;
              case 0x87df:
                goto switchD_0007d0c0_caseD_87df;
              }
              break;
            case 0x87db:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007d0c0_caseD_87d5;
              case 0x87d6:
                goto switchD_0007d0c0_caseD_87d6;
              case 0x87d7:
                goto switchD_0007d0c0_caseD_87d7;
              case 0x87d8:
                goto switchD_0007d0c0_caseD_87d8;
              case 0x87d9:
                goto switchD_0007d0c0_caseD_87d9;
              case 0x87da:
                goto switchD_0007d0c0_caseD_87da;
              case 0x87db:
                goto switchD_0007d0c0_caseD_87db;
              case 0x87dc:
                goto switchD_0007d0c0_caseD_87dc;
              case 0x87de:
                goto switchD_0007d0c0_caseD_87de;
              case 0x87df:
                goto switchD_0007d0c0_caseD_87df;
              }
              break;
            case 0x87dc:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007d0c0_caseD_87d5;
              case 0x87d6:
                goto switchD_0007d0c0_caseD_87d6;
              case 0x87d7:
                goto switchD_0007d0c0_caseD_87d7;
              case 0x87d8:
                goto switchD_0007d0c0_caseD_87d8;
              case 0x87d9:
                goto switchD_0007d0c0_caseD_87d9;
              case 0x87da:
                goto switchD_0007d0c0_caseD_87da;
              case 0x87db:
                goto switchD_0007d0c0_caseD_87db;
              case 0x87dc:
                goto switchD_0007d0c0_caseD_87dc;
              case 0x87de:
                goto switchD_0007d0c0_caseD_87de;
              case 0x87df:
                goto switchD_0007d0c0_caseD_87df;
              }
              break;
            default:
              goto switchD_0007ab8a_default;
            }
switchD_0007ab8a_caseD_87d5:
            uVar27 = uVar28;
switchD_0007ab8a_default:
            *(undefined4 *)(iVar24 + 0x68) = uVar27;
            uVar27 = *(undefined4 *)(iVar24 + 0x6c);
            switch(*(undefined4 *)(iVar24 + 0x6c)) {
            case 0x87d5:
            case 0x87d6:
            case 0x87d7:
            case 0x87d8:
              break;
            case 0x87d9:
              switch(uVar28) {
              case 0x87d5:
switchD_0007cf3c_caseD_87d5:
                uVar27 = 0x87d9;
                break;
              case 0x87d6:
switchD_0007cf3c_caseD_87d6:
                uVar27 = 0x87da;
                break;
              case 0x87d7:
switchD_0007cf3c_caseD_87d7:
                uVar27 = 0x87db;
                break;
              case 0x87d8:
switchD_0007cf3c_caseD_87d8:
                uVar27 = 0x87dc;
                break;
              case 0x87d9:
switchD_0007cf3c_caseD_87d9:
                uVar27 = 0x87d5;
                break;
              case 0x87da:
switchD_0007cf3c_caseD_87da:
                uVar27 = 0x87d6;
                break;
              case 0x87db:
switchD_0007cf3c_caseD_87db:
                uVar27 = 0x87d7;
                break;
              case 0x87dc:
switchD_0007cf3c_caseD_87dc:
                uVar27 = 0x87d8;
                break;
              default:
                goto switchD_0007abce_caseD_87d5;
              case 0x87de:
switchD_0007cf3c_caseD_87de:
                uVar27 = 0x87df;
                break;
              case 0x87df:
switchD_0007cf3c_caseD_87df:
                uVar27 = 0x87de;
              }
              goto switchD_0007abce_default;
            case 0x87da:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007cf3c_caseD_87d5;
              case 0x87d6:
                goto switchD_0007cf3c_caseD_87d6;
              case 0x87d7:
                goto switchD_0007cf3c_caseD_87d7;
              case 0x87d8:
                goto switchD_0007cf3c_caseD_87d8;
              case 0x87d9:
                goto switchD_0007cf3c_caseD_87d9;
              case 0x87da:
                goto switchD_0007cf3c_caseD_87da;
              case 0x87db:
                goto switchD_0007cf3c_caseD_87db;
              case 0x87dc:
                goto switchD_0007cf3c_caseD_87dc;
              case 0x87de:
                goto switchD_0007cf3c_caseD_87de;
              case 0x87df:
                goto switchD_0007cf3c_caseD_87df;
              }
              break;
            case 0x87db:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007cf3c_caseD_87d5;
              case 0x87d6:
                goto switchD_0007cf3c_caseD_87d6;
              case 0x87d7:
                goto switchD_0007cf3c_caseD_87d7;
              case 0x87d8:
                goto switchD_0007cf3c_caseD_87d8;
              case 0x87d9:
                goto switchD_0007cf3c_caseD_87d9;
              case 0x87da:
                goto switchD_0007cf3c_caseD_87da;
              case 0x87db:
                goto switchD_0007cf3c_caseD_87db;
              case 0x87dc:
                goto switchD_0007cf3c_caseD_87dc;
              case 0x87de:
                goto switchD_0007cf3c_caseD_87de;
              case 0x87df:
                goto switchD_0007cf3c_caseD_87df;
              }
              break;
            case 0x87dc:
              switch(uVar28) {
              case 0x87d5:
                goto switchD_0007cf3c_caseD_87d5;
              case 0x87d6:
                goto switchD_0007cf3c_caseD_87d6;
              case 0x87d7:
                goto switchD_0007cf3c_caseD_87d7;
              case 0x87d8:
                goto switchD_0007cf3c_caseD_87d8;
              case 0x87d9:
                goto switchD_0007cf3c_caseD_87d9;
              case 0x87da:
                goto switchD_0007cf3c_caseD_87da;
              case 0x87db:
                goto switchD_0007cf3c_caseD_87db;
              case 0x87dc:
                goto switchD_0007cf3c_caseD_87dc;
              case 0x87de:
                goto switchD_0007cf3c_caseD_87de;
              case 0x87df:
                goto switchD_0007cf3c_caseD_87df;
              }
              break;
            default:
              goto switchD_0007abce_default;
            }
switchD_0007abce_caseD_87d5:
            uVar27 = uVar28;
switchD_0007abce_default:
            *(undefined4 *)(iVar24 + 0x6c) = uVar27;
LAB_0007a92f:
            if ((*(int *)(iVar24 + 4) == 2) && (*(int *)(iVar24 + 8) == *(int *)(iVar23 + -0x6c))) {
              bVar7 = true;
            }
            else {
              bVar7 = false;
            }
            local_68 = local_68 + 1;
          } while ((local_68 < *(uint *)(param_2 + 0x14)) && (local_a8 = local_a8 + 0x74, !bVar7));
          local_e8 = *(uint *)(param_2 + 0x14);
          if (uVar31 < local_e8) {
            local_ac = local_a0;
            do {
              pvVar25 = (void *)(local_ac + *(int *)(param_2 + 0x18));
              _memcpy((void *)((int)pvVar25 + -0x74),pvVar25,0x74);
              uVar31 = uVar31 + 1;
              local_e8 = *(uint *)(param_2 + 0x14);
              local_ac = local_ac + 0x74;
            } while (uVar31 < local_e8);
          }
        }
        *(uint *)(param_2 + 0x14) = local_e8 - 1;
      }
LAB_00079795:
      local_a4 = local_a4 + 1;
      local_a0 = local_a0 + -0x74;
    } while (local_15c != local_a4);
    uVar31 = *(uint *)(param_2 + 0x14);
  }
  do {
    while( true ) {
      uVar29 = uVar31;
      if (uVar29 < 2) {
        return;
      }
      iVar23 = uVar29 * 0x74;
      iVar24 = iVar23 + *(int *)(param_2 + 0x18);
      if (((*(uint **)(iVar24 + -0x74) == &UINT_0000879c) && (*(int *)(iVar24 + -0x54) == 2)) &&
         (iVar22 = FUN_00053994(param_2 + 0x1c,iVar24 + -0x54), iVar22 == 0x87be)) break;
LAB_00079ef9:
      uVar31 = uVar29 - 1;
    }
    if (uVar29 < *(uint *)(param_2 + 0x14)) {
      iVar22 = iVar23 + *(int *)(param_2 + 0x18);
      bVar7 = true;
      uVar31 = uVar29;
      do {
        if ((((*(int *)(iVar22 + 0x20) == 2) &&
             (*(int *)(iVar22 + 0x24) == *(int *)(iVar24 + -0x50))) ||
            ((*(int *)(iVar22 + 0x3c) == 2 && (*(int *)(iVar22 + 0x40) == *(int *)(iVar24 + -0x50)))
            )) || ((*(int *)(iVar22 + 0x58) == 2 &&
                   (*(int *)(iVar22 + 0x5c) == *(int *)(iVar24 + -0x50))))) {
          bVar8 = true;
          bVar7 = false;
        }
        else if ((*(int *)(iVar22 + 4) == 2) && (*(int *)(iVar22 + 8) == *(int *)(iVar24 + -0x50)))
        {
          bVar8 = true;
        }
        else {
          bVar8 = false;
        }
        uVar31 = uVar31 + 1;
      } while ((*(uint *)(param_2 + 0x14) != uVar31) && (iVar22 = iVar22 + 0x74, !bVar8));
      if (!bVar7) goto LAB_00079ef9;
    }
    uVar31 = uVar29 - 1;
    if (uVar31 != 0) {
      local_b0 = uVar31 * 0x74;
      bVar7 = false;
      local_b4 = 0;
      do {
        iVar22 = local_b0 + *(int *)(param_2 + 0x18);
        if ((*(int *)(iVar22 + -0x70) == 2) &&
           (*(int *)(iVar22 + -0x6c) == *(int *)(iVar24 + -0x50))) {
          if (*(int *)(iVar22 + -0x74) - 0x879bU < 2) {
LAB_0007a363:
            bVar8 = true;
          }
          else {
            *(undefined4 *)(iVar22 + -0x70) = *(undefined4 *)(iVar24 + -0x70);
            *(undefined4 *)(iVar22 + -0x6c) = *(undefined4 *)(iVar24 + -0x6c);
            *(undefined4 *)(iVar22 + -0x68) = *(undefined4 *)(iVar24 + -0x68);
            *(undefined4 *)(iVar22 + -100) = *(undefined4 *)(iVar24 + -100);
            *(undefined4 *)(iVar22 + -0x60) = *(undefined4 *)(iVar24 + -0x60);
            *(undefined4 *)(iVar22 + -0x5c) = *(undefined4 *)(iVar24 + -0x5c);
            bVar8 = true;
            bVar7 = true;
          }
        }
        else if ((*(int *)(iVar22 + -0x54) == 2) &&
                (*(int *)(iVar22 + -0x50) == *(int *)(iVar24 + -0x50))) {
          bVar8 = true;
        }
        else if ((*(int *)(iVar22 + -0x38) == 2) &&
                (*(int *)(iVar22 + -0x34) == *(int *)(iVar24 + -0x50))) {
          bVar8 = true;
        }
        else {
          if ((*(int *)(iVar22 + -0x1c) == 2) &&
             (*(int *)(iVar22 + -0x18) == *(int *)(iVar24 + -0x50))) goto LAB_0007a363;
          bVar8 = false;
        }
        if (uVar29 - 2 == local_b4) break;
        local_b4 = local_b4 + 1;
        local_b0 = local_b0 + -0x74;
      } while (!bVar8);
      if (bVar7) {
        uVar26 = *(uint *)(param_2 + 0x14);
        if (uVar29 < uVar26) {
          do {
            pvVar25 = (void *)(iVar23 + *(int *)(param_2 + 0x18));
            _memcpy((void *)((int)pvVar25 + -0x74),pvVar25,0x74);
            uVar29 = uVar29 + 1;
            uVar26 = *(uint *)(param_2 + 0x14);
            iVar23 = iVar23 + 0x74;
          } while (uVar29 < uVar26);
        }
        *(uint *)(param_2 + 0x14) = uVar26 - 1;
      }
    }
  } while( true );
LAB_0007b997:
  if (bVar15) {
    uVar26 = *(uint *)(param_2 + 0x14);
    if (uVar29 < uVar26) {
      do {
        pvVar25 = (void *)(iVar22 + *(int *)(param_2 + 0x18));
        _memcpy((void *)((int)pvVar25 + -0x74),pvVar25,0x74);
        uVar29 = uVar29 + 1;
        uVar26 = *(uint *)(param_2 + 0x14);
        iVar22 = iVar22 + 0x74;
      } while (uVar29 < uVar26);
    }
    *(uint *)(param_2 + 0x14) = uVar26 - 1;
  }
LAB_00079659:
  uVar31 = uVar31 + 1;
  if (*(uint *)(param_2 + 0x14) <= uVar31) goto LAB_00079661;
  goto LAB_00079632;
LAB_0007a1f1:
  if (bVar8) {
LAB_0007a202:
    if (uVar29 < local_d8) {
      local_98 = uVar29 * 0x74;
      local_9c = 0;
      do {
        iVar23 = local_98 + *(int *)(param_2 + 0x18);
        if ((*(int *)(iVar23 + 0x20) == 2) && (*(int *)(iVar23 + 0x24) == piVar30[2])) {
          *(int *)(iVar23 + 0x24) = piVar30[9];
          piVar1 = piVar30 + 10;
          iVar24 = *(int *)(iVar23 + 0x28);
          switch(iVar24) {
          case 0x87d5:
            iVar24 = *piVar1;
            break;
          case 0x87d6:
            iVar24 = piVar30[0xb];
            break;
          case 0x87d7:
            iVar24 = piVar30[0xc];
            break;
          case 0x87d8:
            iVar24 = piVar30[0xd];
            break;
          case 0x87d9:
            iVar24 = *piVar1;
            switch(iVar24) {
            case 0x87d5:
switchD_0007d5ff_caseD_87d5:
              iVar24 = 0x87d9;
              break;
            case 0x87d6:
switchD_0007d5ff_caseD_87d6:
              iVar24 = 0x87da;
              break;
            case 0x87d7:
switchD_0007d5ff_caseD_87d7:
              iVar24 = 0x87db;
              break;
            case 0x87d8:
switchD_0007d5ff_caseD_87d8:
              iVar24 = 0x87dc;
              break;
            case 0x87d9:
switchD_0007d5ff_caseD_87d9:
              iVar24 = 0x87d5;
              break;
            case 0x87da:
switchD_0007d5ff_caseD_87da:
              iVar24 = 0x87d6;
              break;
            case 0x87db:
switchD_0007d5ff_caseD_87db:
              iVar24 = 0x87d7;
              break;
            case 0x87dc:
switchD_0007d5ff_caseD_87dc:
              iVar24 = 0x87d8;
              break;
            case 0x87de:
switchD_0007d5ff_caseD_87de:
              iVar24 = 0x87df;
              break;
            case 0x87df:
switchD_0007d5ff_caseD_87df:
              iVar24 = 0x87de;
            }
            break;
          case 0x87da:
            iVar24 = piVar30[0xb];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007d5ff_caseD_87d5;
            case 0x87d6:
              goto switchD_0007d5ff_caseD_87d6;
            case 0x87d7:
              goto switchD_0007d5ff_caseD_87d7;
            case 0x87d8:
              goto switchD_0007d5ff_caseD_87d8;
            case 0x87d9:
              goto switchD_0007d5ff_caseD_87d9;
            case 0x87da:
              goto switchD_0007d5ff_caseD_87da;
            case 0x87db:
              goto switchD_0007d5ff_caseD_87db;
            case 0x87dc:
              goto switchD_0007d5ff_caseD_87dc;
            case 0x87de:
              goto switchD_0007d5ff_caseD_87de;
            case 0x87df:
              goto switchD_0007d5ff_caseD_87df;
            }
            break;
          case 0x87db:
            iVar24 = piVar30[0xc];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007d5ff_caseD_87d5;
            case 0x87d6:
              goto switchD_0007d5ff_caseD_87d6;
            case 0x87d7:
              goto switchD_0007d5ff_caseD_87d7;
            case 0x87d8:
              goto switchD_0007d5ff_caseD_87d8;
            case 0x87d9:
              goto switchD_0007d5ff_caseD_87d9;
            case 0x87da:
              goto switchD_0007d5ff_caseD_87da;
            case 0x87db:
              goto switchD_0007d5ff_caseD_87db;
            case 0x87dc:
              goto switchD_0007d5ff_caseD_87dc;
            case 0x87de:
              goto switchD_0007d5ff_caseD_87de;
            case 0x87df:
              goto switchD_0007d5ff_caseD_87df;
            }
            break;
          case 0x87dc:
            iVar24 = piVar30[0xd];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007d5ff_caseD_87d5;
            case 0x87d6:
              goto switchD_0007d5ff_caseD_87d6;
            case 0x87d7:
              goto switchD_0007d5ff_caseD_87d7;
            case 0x87d8:
              goto switchD_0007d5ff_caseD_87d8;
            case 0x87d9:
              goto switchD_0007d5ff_caseD_87d9;
            case 0x87da:
              goto switchD_0007d5ff_caseD_87da;
            case 0x87db:
              goto switchD_0007d5ff_caseD_87db;
            case 0x87dc:
              goto switchD_0007d5ff_caseD_87dc;
            case 0x87de:
              goto switchD_0007d5ff_caseD_87de;
            case 0x87df:
              goto switchD_0007d5ff_caseD_87df;
            }
          }
          *(int *)(iVar23 + 0x28) = iVar24;
          iVar24 = *(int *)(iVar23 + 0x2c);
          switch(iVar24) {
          case 0x87d5:
            iVar24 = *piVar1;
            break;
          case 0x87d6:
            iVar24 = piVar30[0xb];
            break;
          case 0x87d7:
            iVar24 = piVar30[0xc];
            break;
          case 0x87d8:
            iVar24 = piVar30[0xd];
            break;
          case 0x87d9:
            iVar24 = *piVar1;
            switch(iVar24) {
            case 0x87d5:
switchD_0007ce4b_caseD_87d5:
              iVar24 = 0x87d9;
              break;
            case 0x87d6:
switchD_0007ce4b_caseD_87d6:
              iVar24 = 0x87da;
              break;
            case 0x87d7:
switchD_0007ce4b_caseD_87d7:
              iVar24 = 0x87db;
              break;
            case 0x87d8:
switchD_0007ce4b_caseD_87d8:
              iVar24 = 0x87dc;
              break;
            case 0x87d9:
switchD_0007ce4b_caseD_87d9:
              iVar24 = 0x87d5;
              break;
            case 0x87da:
switchD_0007ce4b_caseD_87da:
              iVar24 = 0x87d6;
              break;
            case 0x87db:
switchD_0007ce4b_caseD_87db:
              iVar24 = 0x87d7;
              break;
            case 0x87dc:
switchD_0007ce4b_caseD_87dc:
              iVar24 = 0x87d8;
              break;
            case 0x87de:
switchD_0007ce4b_caseD_87de:
              iVar24 = 0x87df;
              break;
            case 0x87df:
switchD_0007ce4b_caseD_87df:
              iVar24 = 0x87de;
            }
            break;
          case 0x87da:
            iVar24 = piVar30[0xb];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007ce4b_caseD_87d5;
            case 0x87d6:
              goto switchD_0007ce4b_caseD_87d6;
            case 0x87d7:
              goto switchD_0007ce4b_caseD_87d7;
            case 0x87d8:
              goto switchD_0007ce4b_caseD_87d8;
            case 0x87d9:
              goto switchD_0007ce4b_caseD_87d9;
            case 0x87da:
              goto switchD_0007ce4b_caseD_87da;
            case 0x87db:
              goto switchD_0007ce4b_caseD_87db;
            case 0x87dc:
              goto switchD_0007ce4b_caseD_87dc;
            case 0x87de:
              goto switchD_0007ce4b_caseD_87de;
            case 0x87df:
              goto switchD_0007ce4b_caseD_87df;
            }
            break;
          case 0x87db:
            iVar24 = piVar30[0xc];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007ce4b_caseD_87d5;
            case 0x87d6:
              goto switchD_0007ce4b_caseD_87d6;
            case 0x87d7:
              goto switchD_0007ce4b_caseD_87d7;
            case 0x87d8:
              goto switchD_0007ce4b_caseD_87d8;
            case 0x87d9:
              goto switchD_0007ce4b_caseD_87d9;
            case 0x87da:
              goto switchD_0007ce4b_caseD_87da;
            case 0x87db:
              goto switchD_0007ce4b_caseD_87db;
            case 0x87dc:
              goto switchD_0007ce4b_caseD_87dc;
            case 0x87de:
              goto switchD_0007ce4b_caseD_87de;
            case 0x87df:
              goto switchD_0007ce4b_caseD_87df;
            }
            break;
          case 0x87dc:
            iVar24 = piVar30[0xd];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007ce4b_caseD_87d5;
            case 0x87d6:
              goto switchD_0007ce4b_caseD_87d6;
            case 0x87d7:
              goto switchD_0007ce4b_caseD_87d7;
            case 0x87d8:
              goto switchD_0007ce4b_caseD_87d8;
            case 0x87d9:
              goto switchD_0007ce4b_caseD_87d9;
            case 0x87da:
              goto switchD_0007ce4b_caseD_87da;
            case 0x87db:
              goto switchD_0007ce4b_caseD_87db;
            case 0x87dc:
              goto switchD_0007ce4b_caseD_87dc;
            case 0x87de:
              goto switchD_0007ce4b_caseD_87de;
            case 0x87df:
              goto switchD_0007ce4b_caseD_87df;
            }
          }
          *(int *)(iVar23 + 0x2c) = iVar24;
          iVar24 = *(int *)(iVar23 + 0x30);
          switch(iVar24) {
          case 0x87d5:
            iVar24 = *piVar1;
            break;
          case 0x87d6:
            iVar24 = piVar30[0xb];
            break;
          case 0x87d7:
            iVar24 = piVar30[0xc];
            break;
          case 0x87d8:
            iVar24 = piVar30[0xd];
            break;
          case 0x87d9:
            iVar24 = *piVar1;
            switch(iVar24) {
            case 0x87d5:
switchD_0007c4eb_caseD_87d5:
              iVar24 = 0x87d9;
              break;
            case 0x87d6:
switchD_0007c4eb_caseD_87d6:
              iVar24 = 0x87da;
              break;
            case 0x87d7:
switchD_0007c4eb_caseD_87d7:
              iVar24 = 0x87db;
              break;
            case 0x87d8:
switchD_0007c4eb_caseD_87d8:
              iVar24 = 0x87dc;
              break;
            case 0x87d9:
switchD_0007c4eb_caseD_87d9:
              iVar24 = 0x87d5;
              break;
            case 0x87da:
switchD_0007c4eb_caseD_87da:
              iVar24 = 0x87d6;
              break;
            case 0x87db:
switchD_0007c4eb_caseD_87db:
              iVar24 = 0x87d7;
              break;
            case 0x87dc:
switchD_0007c4eb_caseD_87dc:
              iVar24 = 0x87d8;
              break;
            case 0x87de:
switchD_0007c4eb_caseD_87de:
              iVar24 = 0x87df;
              break;
            case 0x87df:
switchD_0007c4eb_caseD_87df:
              iVar24 = 0x87de;
            }
            break;
          case 0x87da:
            iVar24 = piVar30[0xb];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007c4eb_caseD_87d5;
            case 0x87d6:
              goto switchD_0007c4eb_caseD_87d6;
            case 0x87d7:
              goto switchD_0007c4eb_caseD_87d7;
            case 0x87d8:
              goto switchD_0007c4eb_caseD_87d8;
            case 0x87d9:
              goto switchD_0007c4eb_caseD_87d9;
            case 0x87da:
              goto switchD_0007c4eb_caseD_87da;
            case 0x87db:
              goto switchD_0007c4eb_caseD_87db;
            case 0x87dc:
              goto switchD_0007c4eb_caseD_87dc;
            case 0x87de:
              goto switchD_0007c4eb_caseD_87de;
            case 0x87df:
              goto switchD_0007c4eb_caseD_87df;
            }
            break;
          case 0x87db:
            iVar24 = piVar30[0xc];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007c4eb_caseD_87d5;
            case 0x87d6:
              goto switchD_0007c4eb_caseD_87d6;
            case 0x87d7:
              goto switchD_0007c4eb_caseD_87d7;
            case 0x87d8:
              goto switchD_0007c4eb_caseD_87d8;
            case 0x87d9:
              goto switchD_0007c4eb_caseD_87d9;
            case 0x87da:
              goto switchD_0007c4eb_caseD_87da;
            case 0x87db:
              goto switchD_0007c4eb_caseD_87db;
            case 0x87dc:
              goto switchD_0007c4eb_caseD_87dc;
            case 0x87de:
              goto switchD_0007c4eb_caseD_87de;
            case 0x87df:
              goto switchD_0007c4eb_caseD_87df;
            }
            break;
          case 0x87dc:
            iVar24 = piVar30[0xd];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007c4eb_caseD_87d5;
            case 0x87d6:
              goto switchD_0007c4eb_caseD_87d6;
            case 0x87d7:
              goto switchD_0007c4eb_caseD_87d7;
            case 0x87d8:
              goto switchD_0007c4eb_caseD_87d8;
            case 0x87d9:
              goto switchD_0007c4eb_caseD_87d9;
            case 0x87da:
              goto switchD_0007c4eb_caseD_87da;
            case 0x87db:
              goto switchD_0007c4eb_caseD_87db;
            case 0x87dc:
              goto switchD_0007c4eb_caseD_87dc;
            case 0x87de:
              goto switchD_0007c4eb_caseD_87de;
            case 0x87df:
              goto switchD_0007c4eb_caseD_87df;
            }
          }
          *(int *)(iVar23 + 0x30) = iVar24;
          iVar24 = *(int *)(iVar23 + 0x34);
          switch(iVar24) {
          case 0x87d5:
            iVar24 = *piVar1;
            break;
          case 0x87d6:
            iVar24 = piVar30[0xb];
            break;
          case 0x87d7:
            iVar24 = piVar30[0xc];
            break;
          case 0x87d8:
            iVar24 = piVar30[0xd];
            break;
          case 0x87d9:
            iVar24 = *piVar1;
            switch(iVar24) {
            case 0x87d5:
switchD_0007c163_caseD_87d5:
              iVar24 = 0x87d9;
              break;
            case 0x87d6:
switchD_0007c163_caseD_87d6:
              iVar24 = 0x87da;
              break;
            case 0x87d7:
switchD_0007c163_caseD_87d7:
              iVar24 = 0x87db;
              break;
            case 0x87d8:
switchD_0007c163_caseD_87d8:
              iVar24 = 0x87dc;
              break;
            case 0x87d9:
switchD_0007c163_caseD_87d9:
              iVar24 = 0x87d5;
              break;
            case 0x87da:
switchD_0007c163_caseD_87da:
              iVar24 = 0x87d6;
              break;
            case 0x87db:
switchD_0007c163_caseD_87db:
              iVar24 = 0x87d7;
              break;
            case 0x87dc:
switchD_0007c163_caseD_87dc:
              iVar24 = 0x87d8;
              break;
            case 0x87de:
switchD_0007c163_caseD_87de:
              iVar24 = 0x87df;
              break;
            case 0x87df:
switchD_0007c163_caseD_87df:
              iVar24 = 0x87de;
            }
            break;
          case 0x87da:
            iVar24 = piVar30[0xb];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007c163_caseD_87d5;
            case 0x87d6:
              goto switchD_0007c163_caseD_87d6;
            case 0x87d7:
              goto switchD_0007c163_caseD_87d7;
            case 0x87d8:
              goto switchD_0007c163_caseD_87d8;
            case 0x87d9:
              goto switchD_0007c163_caseD_87d9;
            case 0x87da:
              goto switchD_0007c163_caseD_87da;
            case 0x87db:
              goto switchD_0007c163_caseD_87db;
            case 0x87dc:
              goto switchD_0007c163_caseD_87dc;
            case 0x87de:
              goto switchD_0007c163_caseD_87de;
            case 0x87df:
              goto switchD_0007c163_caseD_87df;
            }
            break;
          case 0x87db:
            iVar24 = piVar30[0xc];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007c163_caseD_87d5;
            case 0x87d6:
              goto switchD_0007c163_caseD_87d6;
            case 0x87d7:
              goto switchD_0007c163_caseD_87d7;
            case 0x87d8:
              goto switchD_0007c163_caseD_87d8;
            case 0x87d9:
              goto switchD_0007c163_caseD_87d9;
            case 0x87da:
              goto switchD_0007c163_caseD_87da;
            case 0x87db:
              goto switchD_0007c163_caseD_87db;
            case 0x87dc:
              goto switchD_0007c163_caseD_87dc;
            case 0x87de:
              goto switchD_0007c163_caseD_87de;
            case 0x87df:
              goto switchD_0007c163_caseD_87df;
            }
            break;
          case 0x87dc:
            iVar24 = piVar30[0xd];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007c163_caseD_87d5;
            case 0x87d6:
              goto switchD_0007c163_caseD_87d6;
            case 0x87d7:
              goto switchD_0007c163_caseD_87d7;
            case 0x87d8:
              goto switchD_0007c163_caseD_87d8;
            case 0x87d9:
              goto switchD_0007c163_caseD_87d9;
            case 0x87da:
              goto switchD_0007c163_caseD_87da;
            case 0x87db:
              goto switchD_0007c163_caseD_87db;
            case 0x87dc:
              goto switchD_0007c163_caseD_87dc;
            case 0x87de:
              goto switchD_0007c163_caseD_87de;
            case 0x87df:
              goto switchD_0007c163_caseD_87df;
            }
          }
          *(int *)(iVar23 + 0x34) = iVar24;
        }
        if ((*(int *)(iVar23 + 0x3c) == 2) && (*(int *)(iVar23 + 0x40) == piVar30[2])) {
          *(int *)(iVar23 + 0x40) = piVar30[9];
          piVar1 = piVar30 + 10;
          iVar24 = *(int *)(iVar23 + 0x44);
          switch(iVar24) {
          case 0x87d5:
            iVar24 = *piVar1;
            break;
          case 0x87d6:
            iVar24 = piVar30[0xb];
            break;
          case 0x87d7:
            iVar24 = piVar30[0xc];
            break;
          case 0x87d8:
            iVar24 = piVar30[0xd];
            break;
          case 0x87d9:
            iVar24 = *piVar1;
            switch(iVar24) {
            case 0x87d5:
switchD_0007c0a5_caseD_87d5:
              iVar24 = 0x87d9;
              break;
            case 0x87d6:
switchD_0007c0a5_caseD_87d6:
              iVar24 = 0x87da;
              break;
            case 0x87d7:
switchD_0007c0a5_caseD_87d7:
              iVar24 = 0x87db;
              break;
            case 0x87d8:
switchD_0007c0a5_caseD_87d8:
              iVar24 = 0x87dc;
              break;
            case 0x87d9:
switchD_0007c0a5_caseD_87d9:
              iVar24 = 0x87d5;
              break;
            case 0x87da:
switchD_0007c0a5_caseD_87da:
              iVar24 = 0x87d6;
              break;
            case 0x87db:
switchD_0007c0a5_caseD_87db:
              iVar24 = 0x87d7;
              break;
            case 0x87dc:
switchD_0007c0a5_caseD_87dc:
              iVar24 = 0x87d8;
              break;
            case 0x87de:
switchD_0007c0a5_caseD_87de:
              iVar24 = 0x87df;
              break;
            case 0x87df:
switchD_0007c0a5_caseD_87df:
              iVar24 = 0x87de;
            }
            break;
          case 0x87da:
            iVar24 = piVar30[0xb];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007c0a5_caseD_87d5;
            case 0x87d6:
              goto switchD_0007c0a5_caseD_87d6;
            case 0x87d7:
              goto switchD_0007c0a5_caseD_87d7;
            case 0x87d8:
              goto switchD_0007c0a5_caseD_87d8;
            case 0x87d9:
              goto switchD_0007c0a5_caseD_87d9;
            case 0x87da:
              goto switchD_0007c0a5_caseD_87da;
            case 0x87db:
              goto switchD_0007c0a5_caseD_87db;
            case 0x87dc:
              goto switchD_0007c0a5_caseD_87dc;
            case 0x87de:
              goto switchD_0007c0a5_caseD_87de;
            case 0x87df:
              goto switchD_0007c0a5_caseD_87df;
            }
            break;
          case 0x87db:
            iVar24 = piVar30[0xc];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007c0a5_caseD_87d5;
            case 0x87d6:
              goto switchD_0007c0a5_caseD_87d6;
            case 0x87d7:
              goto switchD_0007c0a5_caseD_87d7;
            case 0x87d8:
              goto switchD_0007c0a5_caseD_87d8;
            case 0x87d9:
              goto switchD_0007c0a5_caseD_87d9;
            case 0x87da:
              goto switchD_0007c0a5_caseD_87da;
            case 0x87db:
              goto switchD_0007c0a5_caseD_87db;
            case 0x87dc:
              goto switchD_0007c0a5_caseD_87dc;
            case 0x87de:
              goto switchD_0007c0a5_caseD_87de;
            case 0x87df:
              goto switchD_0007c0a5_caseD_87df;
            }
            break;
          case 0x87dc:
            iVar24 = piVar30[0xd];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007c0a5_caseD_87d5;
            case 0x87d6:
              goto switchD_0007c0a5_caseD_87d6;
            case 0x87d7:
              goto switchD_0007c0a5_caseD_87d7;
            case 0x87d8:
              goto switchD_0007c0a5_caseD_87d8;
            case 0x87d9:
              goto switchD_0007c0a5_caseD_87d9;
            case 0x87da:
              goto switchD_0007c0a5_caseD_87da;
            case 0x87db:
              goto switchD_0007c0a5_caseD_87db;
            case 0x87dc:
              goto switchD_0007c0a5_caseD_87dc;
            case 0x87de:
              goto switchD_0007c0a5_caseD_87de;
            case 0x87df:
              goto switchD_0007c0a5_caseD_87df;
            }
          }
          *(int *)(iVar23 + 0x44) = iVar24;
          iVar24 = *(int *)(iVar23 + 0x48);
          switch(iVar24) {
          case 0x87d5:
            iVar24 = *piVar1;
            break;
          case 0x87d6:
            iVar24 = piVar30[0xb];
            break;
          case 0x87d7:
            iVar24 = piVar30[0xc];
            break;
          case 0x87d8:
            iVar24 = piVar30[0xd];
            break;
          case 0x87d9:
            iVar24 = *piVar1;
            switch(iVar24) {
            case 0x87d5:
switchD_0007bba7_caseD_87d5:
              iVar24 = 0x87d9;
              break;
            case 0x87d6:
switchD_0007bba7_caseD_87d6:
              iVar24 = 0x87da;
              break;
            case 0x87d7:
switchD_0007bba7_caseD_87d7:
              iVar24 = 0x87db;
              break;
            case 0x87d8:
switchD_0007bba7_caseD_87d8:
              iVar24 = 0x87dc;
              break;
            case 0x87d9:
switchD_0007bba7_caseD_87d9:
              iVar24 = 0x87d5;
              break;
            case 0x87da:
switchD_0007bba7_caseD_87da:
              iVar24 = 0x87d6;
              break;
            case 0x87db:
switchD_0007bba7_caseD_87db:
              iVar24 = 0x87d7;
              break;
            case 0x87dc:
switchD_0007bba7_caseD_87dc:
              iVar24 = 0x87d8;
              break;
            case 0x87de:
switchD_0007bba7_caseD_87de:
              iVar24 = 0x87df;
              break;
            case 0x87df:
switchD_0007bba7_caseD_87df:
              iVar24 = 0x87de;
            }
            break;
          case 0x87da:
            iVar24 = piVar30[0xb];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007bba7_caseD_87d5;
            case 0x87d6:
              goto switchD_0007bba7_caseD_87d6;
            case 0x87d7:
              goto switchD_0007bba7_caseD_87d7;
            case 0x87d8:
              goto switchD_0007bba7_caseD_87d8;
            case 0x87d9:
              goto switchD_0007bba7_caseD_87d9;
            case 0x87da:
              goto switchD_0007bba7_caseD_87da;
            case 0x87db:
              goto switchD_0007bba7_caseD_87db;
            case 0x87dc:
              goto switchD_0007bba7_caseD_87dc;
            case 0x87de:
              goto switchD_0007bba7_caseD_87de;
            case 0x87df:
              goto switchD_0007bba7_caseD_87df;
            }
            break;
          case 0x87db:
            iVar24 = piVar30[0xc];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007bba7_caseD_87d5;
            case 0x87d6:
              goto switchD_0007bba7_caseD_87d6;
            case 0x87d7:
              goto switchD_0007bba7_caseD_87d7;
            case 0x87d8:
              goto switchD_0007bba7_caseD_87d8;
            case 0x87d9:
              goto switchD_0007bba7_caseD_87d9;
            case 0x87da:
              goto switchD_0007bba7_caseD_87da;
            case 0x87db:
              goto switchD_0007bba7_caseD_87db;
            case 0x87dc:
              goto switchD_0007bba7_caseD_87dc;
            case 0x87de:
              goto switchD_0007bba7_caseD_87de;
            case 0x87df:
              goto switchD_0007bba7_caseD_87df;
            }
            break;
          case 0x87dc:
            iVar24 = piVar30[0xd];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007bba7_caseD_87d5;
            case 0x87d6:
              goto switchD_0007bba7_caseD_87d6;
            case 0x87d7:
              goto switchD_0007bba7_caseD_87d7;
            case 0x87d8:
              goto switchD_0007bba7_caseD_87d8;
            case 0x87d9:
              goto switchD_0007bba7_caseD_87d9;
            case 0x87da:
              goto switchD_0007bba7_caseD_87da;
            case 0x87db:
              goto switchD_0007bba7_caseD_87db;
            case 0x87dc:
              goto switchD_0007bba7_caseD_87dc;
            case 0x87de:
              goto switchD_0007bba7_caseD_87de;
            case 0x87df:
              goto switchD_0007bba7_caseD_87df;
            }
          }
          *(int *)(iVar23 + 0x48) = iVar24;
          iVar24 = *(int *)(iVar23 + 0x4c);
          switch(iVar24) {
          case 0x87d5:
            iVar24 = *piVar1;
            break;
          case 0x87d6:
            iVar24 = piVar30[0xb];
            break;
          case 0x87d7:
            iVar24 = piVar30[0xc];
            break;
          case 0x87d8:
            iVar24 = piVar30[0xd];
            break;
          case 0x87d9:
            iVar24 = *piVar1;
            switch(iVar24) {
            case 0x87d5:
switchD_0007c953_caseD_87d5:
              iVar24 = 0x87d9;
              break;
            case 0x87d6:
switchD_0007c953_caseD_87d6:
              iVar24 = 0x87da;
              break;
            case 0x87d7:
switchD_0007c953_caseD_87d7:
              iVar24 = 0x87db;
              break;
            case 0x87d8:
switchD_0007c953_caseD_87d8:
              iVar24 = 0x87dc;
              break;
            case 0x87d9:
switchD_0007c953_caseD_87d9:
              iVar24 = 0x87d5;
              break;
            case 0x87da:
switchD_0007c953_caseD_87da:
              iVar24 = 0x87d6;
              break;
            case 0x87db:
switchD_0007c953_caseD_87db:
              iVar24 = 0x87d7;
              break;
            case 0x87dc:
switchD_0007c953_caseD_87dc:
              iVar24 = 0x87d8;
              break;
            case 0x87de:
switchD_0007c953_caseD_87de:
              iVar24 = 0x87df;
              break;
            case 0x87df:
switchD_0007c953_caseD_87df:
              iVar24 = 0x87de;
            }
            break;
          case 0x87da:
            iVar24 = piVar30[0xb];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007c953_caseD_87d5;
            case 0x87d6:
              goto switchD_0007c953_caseD_87d6;
            case 0x87d7:
              goto switchD_0007c953_caseD_87d7;
            case 0x87d8:
              goto switchD_0007c953_caseD_87d8;
            case 0x87d9:
              goto switchD_0007c953_caseD_87d9;
            case 0x87da:
              goto switchD_0007c953_caseD_87da;
            case 0x87db:
              goto switchD_0007c953_caseD_87db;
            case 0x87dc:
              goto switchD_0007c953_caseD_87dc;
            case 0x87de:
              goto switchD_0007c953_caseD_87de;
            case 0x87df:
              goto switchD_0007c953_caseD_87df;
            }
            break;
          case 0x87db:
            iVar24 = piVar30[0xc];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007c953_caseD_87d5;
            case 0x87d6:
              goto switchD_0007c953_caseD_87d6;
            case 0x87d7:
              goto switchD_0007c953_caseD_87d7;
            case 0x87d8:
              goto switchD_0007c953_caseD_87d8;
            case 0x87d9:
              goto switchD_0007c953_caseD_87d9;
            case 0x87da:
              goto switchD_0007c953_caseD_87da;
            case 0x87db:
              goto switchD_0007c953_caseD_87db;
            case 0x87dc:
              goto switchD_0007c953_caseD_87dc;
            case 0x87de:
              goto switchD_0007c953_caseD_87de;
            case 0x87df:
              goto switchD_0007c953_caseD_87df;
            }
            break;
          case 0x87dc:
            iVar24 = piVar30[0xd];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007c953_caseD_87d5;
            case 0x87d6:
              goto switchD_0007c953_caseD_87d6;
            case 0x87d7:
              goto switchD_0007c953_caseD_87d7;
            case 0x87d8:
              goto switchD_0007c953_caseD_87d8;
            case 0x87d9:
              goto switchD_0007c953_caseD_87d9;
            case 0x87da:
              goto switchD_0007c953_caseD_87da;
            case 0x87db:
              goto switchD_0007c953_caseD_87db;
            case 0x87dc:
              goto switchD_0007c953_caseD_87dc;
            case 0x87de:
              goto switchD_0007c953_caseD_87de;
            case 0x87df:
              goto switchD_0007c953_caseD_87df;
            }
          }
          *(int *)(iVar23 + 0x4c) = iVar24;
          iVar24 = *(int *)(iVar23 + 0x50);
          switch(iVar24) {
          case 0x87d5:
            iVar24 = *piVar1;
            break;
          case 0x87d6:
            iVar24 = piVar30[0xb];
            break;
          case 0x87d7:
            iVar24 = piVar30[0xc];
            break;
          case 0x87d8:
            iVar24 = piVar30[0xd];
            break;
          case 0x87d9:
            iVar24 = *piVar1;
            switch(iVar24) {
            case 0x87d5:
switchD_0007c693_caseD_87d5:
              iVar24 = 0x87d9;
              break;
            case 0x87d6:
switchD_0007c693_caseD_87d6:
              iVar24 = 0x87da;
              break;
            case 0x87d7:
switchD_0007c693_caseD_87d7:
              iVar24 = 0x87db;
              break;
            case 0x87d8:
switchD_0007c693_caseD_87d8:
              iVar24 = 0x87dc;
              break;
            case 0x87d9:
switchD_0007c693_caseD_87d9:
              iVar24 = 0x87d5;
              break;
            case 0x87da:
switchD_0007c693_caseD_87da:
              iVar24 = 0x87d6;
              break;
            case 0x87db:
switchD_0007c693_caseD_87db:
              iVar24 = 0x87d7;
              break;
            case 0x87dc:
switchD_0007c693_caseD_87dc:
              iVar24 = 0x87d8;
              break;
            case 0x87de:
switchD_0007c693_caseD_87de:
              iVar24 = 0x87df;
              break;
            case 0x87df:
switchD_0007c693_caseD_87df:
              iVar24 = 0x87de;
            }
            break;
          case 0x87da:
            iVar24 = piVar30[0xb];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007c693_caseD_87d5;
            case 0x87d6:
              goto switchD_0007c693_caseD_87d6;
            case 0x87d7:
              goto switchD_0007c693_caseD_87d7;
            case 0x87d8:
              goto switchD_0007c693_caseD_87d8;
            case 0x87d9:
              goto switchD_0007c693_caseD_87d9;
            case 0x87da:
              goto switchD_0007c693_caseD_87da;
            case 0x87db:
              goto switchD_0007c693_caseD_87db;
            case 0x87dc:
              goto switchD_0007c693_caseD_87dc;
            case 0x87de:
              goto switchD_0007c693_caseD_87de;
            case 0x87df:
              goto switchD_0007c693_caseD_87df;
            }
            break;
          case 0x87db:
            iVar24 = piVar30[0xc];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007c693_caseD_87d5;
            case 0x87d6:
              goto switchD_0007c693_caseD_87d6;
            case 0x87d7:
              goto switchD_0007c693_caseD_87d7;
            case 0x87d8:
              goto switchD_0007c693_caseD_87d8;
            case 0x87d9:
              goto switchD_0007c693_caseD_87d9;
            case 0x87da:
              goto switchD_0007c693_caseD_87da;
            case 0x87db:
              goto switchD_0007c693_caseD_87db;
            case 0x87dc:
              goto switchD_0007c693_caseD_87dc;
            case 0x87de:
              goto switchD_0007c693_caseD_87de;
            case 0x87df:
              goto switchD_0007c693_caseD_87df;
            }
            break;
          case 0x87dc:
            iVar24 = piVar30[0xd];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007c693_caseD_87d5;
            case 0x87d6:
              goto switchD_0007c693_caseD_87d6;
            case 0x87d7:
              goto switchD_0007c693_caseD_87d7;
            case 0x87d8:
              goto switchD_0007c693_caseD_87d8;
            case 0x87d9:
              goto switchD_0007c693_caseD_87d9;
            case 0x87da:
              goto switchD_0007c693_caseD_87da;
            case 0x87db:
              goto switchD_0007c693_caseD_87db;
            case 0x87dc:
              goto switchD_0007c693_caseD_87dc;
            case 0x87de:
              goto switchD_0007c693_caseD_87de;
            case 0x87df:
              goto switchD_0007c693_caseD_87df;
            }
          }
          *(int *)(iVar23 + 0x50) = iVar24;
        }
        if ((*(int *)(iVar23 + 0x58) == 2) && (*(int *)(iVar23 + 0x5c) == piVar30[2])) {
          *(int *)(iVar23 + 0x5c) = piVar30[9];
          piVar1 = piVar30 + 10;
          iVar24 = *(int *)(iVar23 + 0x60);
          switch(iVar24) {
          case 0x87d5:
            iVar24 = *piVar1;
            break;
          case 0x87d6:
            iVar24 = piVar30[0xb];
            break;
          case 0x87d7:
            iVar24 = piVar30[0xc];
            break;
          case 0x87d8:
            iVar24 = piVar30[0xd];
            break;
          case 0x87d9:
            iVar24 = *piVar1;
            switch(iVar24) {
            case 0x87d5:
switchD_0007ba63_caseD_87d5:
              iVar24 = 0x87d9;
              break;
            case 0x87d6:
switchD_0007ba63_caseD_87d6:
              iVar24 = 0x87da;
              break;
            case 0x87d7:
switchD_0007ba63_caseD_87d7:
              iVar24 = 0x87db;
              break;
            case 0x87d8:
switchD_0007ba63_caseD_87d8:
              iVar24 = 0x87dc;
              break;
            case 0x87d9:
switchD_0007ba63_caseD_87d9:
              iVar24 = 0x87d5;
              break;
            case 0x87da:
switchD_0007ba63_caseD_87da:
              iVar24 = 0x87d6;
              break;
            case 0x87db:
switchD_0007ba63_caseD_87db:
              iVar24 = 0x87d7;
              break;
            case 0x87dc:
switchD_0007ba63_caseD_87dc:
              iVar24 = 0x87d8;
              break;
            case 0x87de:
switchD_0007ba63_caseD_87de:
              iVar24 = 0x87df;
              break;
            case 0x87df:
switchD_0007ba63_caseD_87df:
              iVar24 = 0x87de;
            }
            break;
          case 0x87da:
            iVar24 = piVar30[0xb];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007ba63_caseD_87d5;
            case 0x87d6:
              goto switchD_0007ba63_caseD_87d6;
            case 0x87d7:
              goto switchD_0007ba63_caseD_87d7;
            case 0x87d8:
              goto switchD_0007ba63_caseD_87d8;
            case 0x87d9:
              goto switchD_0007ba63_caseD_87d9;
            case 0x87da:
              goto switchD_0007ba63_caseD_87da;
            case 0x87db:
              goto switchD_0007ba63_caseD_87db;
            case 0x87dc:
              goto switchD_0007ba63_caseD_87dc;
            case 0x87de:
              goto switchD_0007ba63_caseD_87de;
            case 0x87df:
              goto switchD_0007ba63_caseD_87df;
            }
            break;
          case 0x87db:
            iVar24 = piVar30[0xc];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007ba63_caseD_87d5;
            case 0x87d6:
              goto switchD_0007ba63_caseD_87d6;
            case 0x87d7:
              goto switchD_0007ba63_caseD_87d7;
            case 0x87d8:
              goto switchD_0007ba63_caseD_87d8;
            case 0x87d9:
              goto switchD_0007ba63_caseD_87d9;
            case 0x87da:
              goto switchD_0007ba63_caseD_87da;
            case 0x87db:
              goto switchD_0007ba63_caseD_87db;
            case 0x87dc:
              goto switchD_0007ba63_caseD_87dc;
            case 0x87de:
              goto switchD_0007ba63_caseD_87de;
            case 0x87df:
              goto switchD_0007ba63_caseD_87df;
            }
            break;
          case 0x87dc:
            iVar24 = piVar30[0xd];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007ba63_caseD_87d5;
            case 0x87d6:
              goto switchD_0007ba63_caseD_87d6;
            case 0x87d7:
              goto switchD_0007ba63_caseD_87d7;
            case 0x87d8:
              goto switchD_0007ba63_caseD_87d8;
            case 0x87d9:
              goto switchD_0007ba63_caseD_87d9;
            case 0x87da:
              goto switchD_0007ba63_caseD_87da;
            case 0x87db:
              goto switchD_0007ba63_caseD_87db;
            case 0x87dc:
              goto switchD_0007ba63_caseD_87dc;
            case 0x87de:
              goto switchD_0007ba63_caseD_87de;
            case 0x87df:
              goto switchD_0007ba63_caseD_87df;
            }
          }
          *(int *)(iVar23 + 0x60) = iVar24;
          iVar24 = *(int *)(iVar23 + 100);
          switch(iVar24) {
          case 0x87d5:
            iVar24 = *piVar1;
            break;
          case 0x87d6:
            iVar24 = piVar30[0xb];
            break;
          case 0x87d7:
            iVar24 = piVar30[0xc];
            break;
          case 0x87d8:
            iVar24 = piVar30[0xd];
            break;
          case 0x87d9:
            iVar24 = *piVar1;
            switch(iVar24) {
            case 0x87d5:
switchD_0007cca3_caseD_87d5:
              iVar24 = 0x87d9;
              break;
            case 0x87d6:
switchD_0007cca3_caseD_87d6:
              iVar24 = 0x87da;
              break;
            case 0x87d7:
switchD_0007cca3_caseD_87d7:
              iVar24 = 0x87db;
              break;
            case 0x87d8:
switchD_0007cca3_caseD_87d8:
              iVar24 = 0x87dc;
              break;
            case 0x87d9:
switchD_0007cca3_caseD_87d9:
              iVar24 = 0x87d5;
              break;
            case 0x87da:
switchD_0007cca3_caseD_87da:
              iVar24 = 0x87d6;
              break;
            case 0x87db:
switchD_0007cca3_caseD_87db:
              iVar24 = 0x87d7;
              break;
            case 0x87dc:
switchD_0007cca3_caseD_87dc:
              iVar24 = 0x87d8;
              break;
            case 0x87de:
switchD_0007cca3_caseD_87de:
              iVar24 = 0x87df;
              break;
            case 0x87df:
switchD_0007cca3_caseD_87df:
              iVar24 = 0x87de;
            }
            break;
          case 0x87da:
            iVar24 = piVar30[0xb];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007cca3_caseD_87d5;
            case 0x87d6:
              goto switchD_0007cca3_caseD_87d6;
            case 0x87d7:
              goto switchD_0007cca3_caseD_87d7;
            case 0x87d8:
              goto switchD_0007cca3_caseD_87d8;
            case 0x87d9:
              goto switchD_0007cca3_caseD_87d9;
            case 0x87da:
              goto switchD_0007cca3_caseD_87da;
            case 0x87db:
              goto switchD_0007cca3_caseD_87db;
            case 0x87dc:
              goto switchD_0007cca3_caseD_87dc;
            case 0x87de:
              goto switchD_0007cca3_caseD_87de;
            case 0x87df:
              goto switchD_0007cca3_caseD_87df;
            }
            break;
          case 0x87db:
            iVar24 = piVar30[0xc];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007cca3_caseD_87d5;
            case 0x87d6:
              goto switchD_0007cca3_caseD_87d6;
            case 0x87d7:
              goto switchD_0007cca3_caseD_87d7;
            case 0x87d8:
              goto switchD_0007cca3_caseD_87d8;
            case 0x87d9:
              goto switchD_0007cca3_caseD_87d9;
            case 0x87da:
              goto switchD_0007cca3_caseD_87da;
            case 0x87db:
              goto switchD_0007cca3_caseD_87db;
            case 0x87dc:
              goto switchD_0007cca3_caseD_87dc;
            case 0x87de:
              goto switchD_0007cca3_caseD_87de;
            case 0x87df:
              goto switchD_0007cca3_caseD_87df;
            }
            break;
          case 0x87dc:
            iVar24 = piVar30[0xd];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007cca3_caseD_87d5;
            case 0x87d6:
              goto switchD_0007cca3_caseD_87d6;
            case 0x87d7:
              goto switchD_0007cca3_caseD_87d7;
            case 0x87d8:
              goto switchD_0007cca3_caseD_87d8;
            case 0x87d9:
              goto switchD_0007cca3_caseD_87d9;
            case 0x87da:
              goto switchD_0007cca3_caseD_87da;
            case 0x87db:
              goto switchD_0007cca3_caseD_87db;
            case 0x87dc:
              goto switchD_0007cca3_caseD_87dc;
            case 0x87de:
              goto switchD_0007cca3_caseD_87de;
            case 0x87df:
              goto switchD_0007cca3_caseD_87df;
            }
          }
          *(int *)(iVar23 + 100) = iVar24;
          iVar24 = *(int *)(iVar23 + 0x68);
          switch(iVar24) {
          case 0x87d5:
            iVar24 = *piVar1;
            break;
          case 0x87d6:
            iVar24 = piVar30[0xb];
            break;
          case 0x87d7:
            iVar24 = piVar30[0xc];
            break;
          case 0x87d8:
            iVar24 = piVar30[0xd];
            break;
          case 0x87d9:
            iVar24 = *piVar1;
            switch(iVar24) {
            case 0x87d5:
switchD_0007cafb_caseD_87d5:
              iVar24 = 0x87d9;
              break;
            case 0x87d6:
switchD_0007cafb_caseD_87d6:
              iVar24 = 0x87da;
              break;
            case 0x87d7:
switchD_0007cafb_caseD_87d7:
              iVar24 = 0x87db;
              break;
            case 0x87d8:
switchD_0007cafb_caseD_87d8:
              iVar24 = 0x87dc;
              break;
            case 0x87d9:
switchD_0007cafb_caseD_87d9:
              iVar24 = 0x87d5;
              break;
            case 0x87da:
switchD_0007cafb_caseD_87da:
              iVar24 = 0x87d6;
              break;
            case 0x87db:
switchD_0007cafb_caseD_87db:
              iVar24 = 0x87d7;
              break;
            case 0x87dc:
switchD_0007cafb_caseD_87dc:
              iVar24 = 0x87d8;
              break;
            case 0x87de:
switchD_0007cafb_caseD_87de:
              iVar24 = 0x87df;
              break;
            case 0x87df:
switchD_0007cafb_caseD_87df:
              iVar24 = 0x87de;
            }
            break;
          case 0x87da:
            iVar24 = piVar30[0xb];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007cafb_caseD_87d5;
            case 0x87d6:
              goto switchD_0007cafb_caseD_87d6;
            case 0x87d7:
              goto switchD_0007cafb_caseD_87d7;
            case 0x87d8:
              goto switchD_0007cafb_caseD_87d8;
            case 0x87d9:
              goto switchD_0007cafb_caseD_87d9;
            case 0x87da:
              goto switchD_0007cafb_caseD_87da;
            case 0x87db:
              goto switchD_0007cafb_caseD_87db;
            case 0x87dc:
              goto switchD_0007cafb_caseD_87dc;
            case 0x87de:
              goto switchD_0007cafb_caseD_87de;
            case 0x87df:
              goto switchD_0007cafb_caseD_87df;
            }
            break;
          case 0x87db:
            iVar24 = piVar30[0xc];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007cafb_caseD_87d5;
            case 0x87d6:
              goto switchD_0007cafb_caseD_87d6;
            case 0x87d7:
              goto switchD_0007cafb_caseD_87d7;
            case 0x87d8:
              goto switchD_0007cafb_caseD_87d8;
            case 0x87d9:
              goto switchD_0007cafb_caseD_87d9;
            case 0x87da:
              goto switchD_0007cafb_caseD_87da;
            case 0x87db:
              goto switchD_0007cafb_caseD_87db;
            case 0x87dc:
              goto switchD_0007cafb_caseD_87dc;
            case 0x87de:
              goto switchD_0007cafb_caseD_87de;
            case 0x87df:
              goto switchD_0007cafb_caseD_87df;
            }
            break;
          case 0x87dc:
            iVar24 = piVar30[0xd];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007cafb_caseD_87d5;
            case 0x87d6:
              goto switchD_0007cafb_caseD_87d6;
            case 0x87d7:
              goto switchD_0007cafb_caseD_87d7;
            case 0x87d8:
              goto switchD_0007cafb_caseD_87d8;
            case 0x87d9:
              goto switchD_0007cafb_caseD_87d9;
            case 0x87da:
              goto switchD_0007cafb_caseD_87da;
            case 0x87db:
              goto switchD_0007cafb_caseD_87db;
            case 0x87dc:
              goto switchD_0007cafb_caseD_87dc;
            case 0x87de:
              goto switchD_0007cafb_caseD_87de;
            case 0x87df:
              goto switchD_0007cafb_caseD_87df;
            }
          }
          *(int *)(iVar23 + 0x68) = iVar24;
          iVar24 = *(int *)(iVar23 + 0x6c);
          switch(iVar24) {
          case 0x87d5:
            iVar24 = *piVar1;
            break;
          case 0x87d6:
            iVar24 = piVar30[0xb];
            break;
          case 0x87d7:
            iVar24 = piVar30[0xc];
            break;
          case 0x87d8:
            iVar24 = piVar30[0xd];
            break;
          case 0x87d9:
            iVar24 = *piVar1;
            switch(iVar24) {
            case 0x87d5:
switchD_0007c11a_caseD_87d5:
              iVar24 = 0x87d9;
              break;
            case 0x87d6:
switchD_0007c11a_caseD_87d6:
              iVar24 = 0x87da;
              break;
            case 0x87d7:
switchD_0007c11a_caseD_87d7:
              iVar24 = 0x87db;
              break;
            case 0x87d8:
switchD_0007c11a_caseD_87d8:
              iVar24 = 0x87dc;
              break;
            case 0x87d9:
switchD_0007c11a_caseD_87d9:
              iVar24 = 0x87d5;
              break;
            case 0x87da:
switchD_0007c11a_caseD_87da:
              iVar24 = 0x87d6;
              break;
            case 0x87db:
switchD_0007c11a_caseD_87db:
              iVar24 = 0x87d7;
              break;
            case 0x87dc:
switchD_0007c11a_caseD_87dc:
              iVar24 = 0x87d8;
              break;
            case 0x87de:
switchD_0007c11a_caseD_87de:
              iVar24 = 0x87df;
              break;
            case 0x87df:
switchD_0007c11a_caseD_87df:
              iVar24 = 0x87de;
            }
            break;
          case 0x87da:
            iVar24 = piVar30[0xb];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007c11a_caseD_87d5;
            case 0x87d6:
              goto switchD_0007c11a_caseD_87d6;
            case 0x87d7:
              goto switchD_0007c11a_caseD_87d7;
            case 0x87d8:
              goto switchD_0007c11a_caseD_87d8;
            case 0x87d9:
              goto switchD_0007c11a_caseD_87d9;
            case 0x87da:
              goto switchD_0007c11a_caseD_87da;
            case 0x87db:
              goto switchD_0007c11a_caseD_87db;
            case 0x87dc:
              goto switchD_0007c11a_caseD_87dc;
            case 0x87de:
              goto switchD_0007c11a_caseD_87de;
            case 0x87df:
              goto switchD_0007c11a_caseD_87df;
            }
            break;
          case 0x87db:
            iVar24 = piVar30[0xc];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007c11a_caseD_87d5;
            case 0x87d6:
              goto switchD_0007c11a_caseD_87d6;
            case 0x87d7:
              goto switchD_0007c11a_caseD_87d7;
            case 0x87d8:
              goto switchD_0007c11a_caseD_87d8;
            case 0x87d9:
              goto switchD_0007c11a_caseD_87d9;
            case 0x87da:
              goto switchD_0007c11a_caseD_87da;
            case 0x87db:
              goto switchD_0007c11a_caseD_87db;
            case 0x87dc:
              goto switchD_0007c11a_caseD_87dc;
            case 0x87de:
              goto switchD_0007c11a_caseD_87de;
            case 0x87df:
              goto switchD_0007c11a_caseD_87df;
            }
            break;
          case 0x87dc:
            iVar24 = piVar30[0xd];
            switch(iVar24) {
            case 0x87d5:
              goto switchD_0007c11a_caseD_87d5;
            case 0x87d6:
              goto switchD_0007c11a_caseD_87d6;
            case 0x87d7:
              goto switchD_0007c11a_caseD_87d7;
            case 0x87d8:
              goto switchD_0007c11a_caseD_87d8;
            case 0x87d9:
              goto switchD_0007c11a_caseD_87d9;
            case 0x87da:
              goto switchD_0007c11a_caseD_87da;
            case 0x87db:
              goto switchD_0007c11a_caseD_87db;
            case 0x87dc:
              goto switchD_0007c11a_caseD_87dc;
            case 0x87de:
              goto switchD_0007c11a_caseD_87de;
            case 0x87df:
              goto switchD_0007c11a_caseD_87df;
            }
          }
          *(int *)(iVar23 + 0x6c) = iVar24;
        }
        local_9c = local_9c + 1;
        local_98 = local_98 + 0x74;
      } while (local_d8 - uVar29 != local_9c);
    }
    uVar29 = *(int *)(param_2 + 0x14) - 1;
    *(uint *)(param_2 + 0x14) = uVar29;
    uVar31 = local_38;
    if (local_38 < uVar29) {
      do {
        pvVar25 = (void *)(iVar22 + *(int *)(param_2 + 0x18));
        _memcpy(pvVar25,(void *)((int)pvVar25 + 0x74),0x74);
        uVar31 = uVar31 + 1;
        iVar22 = iVar22 + 0x74;
      } while (uVar31 < *(uint *)(param_2 + 0x14));
    }
    bVar7 = true;
    local_15c = *(uint *)(param_2 + 0x14);
  }
  else {
    local_15c = *(uint *)(param_2 + 0x14);
  }
LAB_000796f9:
  local_38 = local_38 + 1;
  if (local_15c <= local_38) goto LAB_0007974d;
  goto LAB_00079704;
}

/* FUN_0007d998 @ 0x7d998 (880 bytes) */
int FUN_0007d998(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  int local_34;
  uint local_30;
  uint local_18;
  uint local_14;
  uint local_10;
  
  iVar4 = *(int *)(param_2 + 0x54);
  uVar1 = *(uint *)(iVar4 + 0x3cc);
  puVar3 = *(undefined4 **)(iVar4 + 0x3c8);
  if ((uVar1 != 0) && (puVar3 != (undefined4 *)0x0)) {
    bVar5 = *(byte *)(param_1 + 0x8d);
    if ((bVar5 & 0x20) != 0) {
      local_18 = 0;
      local_30 = 0;
      local_14 = 0;
      local_10 = 0;
      local_34 = *(int *)(param_1 + 0xd8);
      if (local_34 == 1) goto LAB_0007dcd4;
      do {
        if (local_34 == 0) {
          local_18 = *(uint *)(iVar4 + 0x3e4) >> 1;
          local_30 = (uint)(*(ushort *)(((unsigned char *)0x000013be) + param_1) >> 1);
          local_14 = local_18 - 2;
          local_10 = local_30;
        }
        else if (local_34 == 2) goto LAB_0007da51;
        while( true ) {
          while( true ) {
            if ((uVar1 <= local_14) && (*(uint *)(param_2 + 0x48) <= local_10)) {
              *(uint *)(param_1 + 0x3cc) = local_18;
              *(uint *)(param_1 + 0x3d0) = local_30;
              iVar4 = uVar1 * 4 + 5;
              puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,iVar4);
              *(undefined4 **)(param_1 + 0x274c) = puVar2;
              *puVar2 = 0x8a1;
              puVar2[1] = 0;
              puVar2[2] = 0x880;
              puVar2[3] = local_18;
              puVar2[4] = (uVar1 * 4 + -1) * 0x10000 | 0x8882;
              puVar2 = puVar2 + 5;
              uVar6 = 0;
              do {
                *puVar2 = *puVar3;
                puVar2[1] = puVar3[1];
                puVar2[2] = puVar3[2];
                puVar2[3] = puVar3[3];
                puVar2 = puVar2 + 4;
                puVar3 = puVar3 + 4;
                uVar6 = uVar6 + 1;
              } while (uVar1 != uVar6);
              iVar4 = *(int *)(param_1 + 0x274c) + iVar4 * 4;
              *(int *)(param_1 + 0x274c) = iVar4;
              (**(code **)(param_1 + 0x275c))(param_1,iVar4);
              if (*(int *)(param_1 + 0xd8) == 0) {
                *(byte *)(param_1 + 0x8d) = *(byte *)(param_1 + 0x8d) & 0xdf;
              }
              goto LAB_0007db3c;
            }
            if (local_34 != 0) break;
            *(undefined4 *)(param_1 + 0xd8) = 1;
            local_34 = 1;
LAB_0007dcd4:
            local_14 = *(int *)(iVar4 + 0x3e4) - 2;
            local_10 = (uint)*(ushort *)(((unsigned char *)0x000013be) + param_1);
            bVar5 = bVar5 | 0x80;
            *(byte *)(param_1 + 0x8d) = bVar5;
            local_18 = 0;
            local_30 = 0;
          }
          if (local_34 != 1) break;
          *(undefined4 *)(param_1 + 0xd8) = 2;
          local_34 = 2;
LAB_0007da51:
          local_14 = *(uint *)(iVar4 + 0x3e4);
          local_10 = (uint)*(ushort *)(((unsigned char *)0x000013be) + param_1);
          bVar5 = bVar5 | 0x80;
          *(byte *)(param_1 + 0x8d) = bVar5;
          *(byte *)(param_1 + 0x8e) = *(byte *)(param_1 + 0x8e) | 1;
          local_18 = 0;
          local_30 = 0;
        }
      } while( true );
    }
LAB_0007db3c:
    iVar4 = *(int *)(param_1 + 0x3cc);
    *(ushort *)(param_1 + 0x1b90) = *(ushort *)(param_1 + 0x1b90) & 0xfc00 | (ushort)iVar4 & 0x3ff;
    *(uint *)(param_1 + 0x1b90) =
         *(uint *)(param_1 + 0x1b90) & 0xfff003ff |
         ((uint)*(ushort *)(param_2 + 0x34) + iVar4 & 0x3ff) << 10;
    *(ushort *)(param_1 + 0x1b92) =
         *(ushort *)(param_1 + 0x1b92) & 0xc00f | (ushort)((iVar4 + -1 + uVar1 & 0xffff03ff) << 4);
    *(ushort *)(param_1 + 0x1b94) =
         *(ushort *)(param_1 + 0x1b94) & 0xfc00 | (ushort)iVar4 + *(short *)(param_2 + 0x38) & 0x3ff
    ;
    *(char *)(param_1 + 0x1b8c) = (char)*(undefined4 *)(param_1 + 0x3d0);
    *(char *)(param_1 + 0x1b8e) = (char)*(undefined4 *)(param_2 + 0x48);
    puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,4);
    *(undefined4 **)(param_1 + 0x274c) = puVar3;
    *puVar3 = 0x208b4;
    puVar3[1] = *(undefined4 *)(param_1 + 0x1b90);
    puVar3[2] = *(undefined4 *)(param_1 + 0x1b8c);
    puVar3[3] = *(undefined4 *)(param_1 + 0x1b94);
    iVar4 = *(int *)(param_1 + 0x274c) + 0x10;
    *(int *)(param_1 + 0x274c) = iVar4;
    (**(code **)(param_1 + 0x275c))(param_1,iVar4);
    puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
    *(undefined4 **)(param_1 + 0x274c) = puVar3;
    *puVar3 = 0x8b7;
    puVar3[1] = *(undefined4 *)(param_1 + 0x1b98);
    iVar4 = *(int *)(param_1 + 0x274c) + 8;
    *(int *)(param_1 + 0x274c) = iVar4;
    (**(code **)(param_1 + 0x275c))(param_1,iVar4);
    FUN_0004fd18(param_1,*(undefined4 *)(param_2 + 0x3c),*(undefined4 *)(param_2 + 0x40),
                 *(undefined4 *)(param_2 + 0x44));
  }
  return;
}

/* FUN_0007dd08 @ 0x7dd08 (638 bytes) */
int FUN_0007dd08(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
  *(undefined4 **)(param_1 + 0x274c) = puVar2;
  *puVar2 = 0x8a1;
  puVar2[1] = 0;
  iVar3 = *(int *)(param_1 + 0x274c) + 8;
  *(int *)(param_1 + 0x274c) = iVar3;
  (**(code **)(param_1 + 0x275c))(param_1,iVar3);
  if (*(char *)(param_2 + 0x58) != '\0') {
    puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x13);
    *(undefined4 **)(param_1 + 0x274c) = puVar2;
    *puVar2 = 0x880;
    puVar2[1] = *(int *)(param_1 + 0x2448) + *(int *)(param_1 + 0x3d0);
    puVar2[2] = 0xf8882;
    if ((*(byte *)((int)&switchdataD_000013c0 + param_1) & 4) == 0) {
      puVar2[3] = *(undefined4 *)(iVar1 + 0x2460);
      puVar2[4] = *(undefined4 *)(iVar1 + 0x2470);
      puVar2[5] = *(undefined4 *)(iVar1 + 0x2480);
      puVar2[6] = *(undefined4 *)(iVar1 + 0x2490);
      puVar2[7] = *(undefined4 *)(iVar1 + 0x2464);
      puVar2[8] = *(undefined4 *)(iVar1 + 0x2474);
      puVar2[9] = *(undefined4 *)(iVar1 + 0x2484);
      puVar2[10] = *(undefined4 *)(iVar1 + 0x2494);
      puVar2[0xb] = *(undefined4 *)(iVar1 + 0x2468);
      puVar2[0xc] = *(undefined4 *)(iVar1 + 0x2478);
      puVar2[0xd] = *(undefined4 *)(iVar1 + 0x2488);
      puVar2[0xe] = *(undefined4 *)(iVar1 + 0x2498);
      puVar2[0xf] = *(undefined4 *)(iVar1 + 0x246c);
      puVar2[0x10] = *(undefined4 *)(iVar1 + 0x247c);
      puVar2[0x11] = *(undefined4 *)(iVar1 + 0x248c);
      puVar2[0x12] = *(undefined4 *)(iVar1 + 0x249c);
    }
    else {
      puVar2[3] = *(undefined4 *)(iVar1 + 0x2460);
      puVar2[4] = *(undefined4 *)(iVar1 + 0x2464);
      puVar2[5] = *(undefined4 *)(iVar1 + 0x2468);
      puVar2[6] = *(undefined4 *)(iVar1 + 0x246c);
      puVar2[7] = *(undefined4 *)(iVar1 + 0x2470);
      puVar2[8] = *(undefined4 *)(iVar1 + 0x2474);
      puVar2[9] = *(undefined4 *)(iVar1 + 0x2478);
      puVar2[10] = *(undefined4 *)(iVar1 + 0x247c);
      puVar2[0xb] = *(undefined4 *)(iVar1 + 0x2480);
      puVar2[0xc] = *(undefined4 *)(iVar1 + 0x2484);
      puVar2[0xd] = *(undefined4 *)(iVar1 + 0x2488);
      puVar2[0xe] = *(undefined4 *)(iVar1 + 0x248c);
      puVar2[0xf] = *(undefined4 *)(iVar1 + 0x2490);
      puVar2[0x10] = *(undefined4 *)(iVar1 + 0x2494);
      puVar2[0x11] = *(undefined4 *)(iVar1 + 0x2498);
      puVar2[0x12] = *(undefined4 *)(iVar1 + 0x249c);
    }
    *(int *)(param_1 + 0x274c) = *(int *)(param_1 + 0x274c) + 0x4c;
                    
                    
    (**(code **)(param_1 + 0x275c))();
    return;
  }
  if (*(int *)(param_2 + 0x48) != 0) {
    puVar4 = *(undefined4 **)(param_2 + 0x4c);
    FUN_0009d07e(param_1,param_2);
    iVar1 = *(int *)(param_2 + 0x48) * 4 + 3;
    puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,iVar1);
    *(undefined4 **)(param_1 + 0x274c) = puVar2;
    *puVar2 = 0x880;
    puVar2[1] = *(int *)(param_1 + 0x2448) + *(int *)(param_1 + 0x3d0);
    puVar2[2] = (*(int *)(param_2 + 0x48) * 4 + -1) * 0x10000 | 0x8882;
    puVar2 = puVar2 + 3;
    if (*(int *)(param_2 + 0x48) != 0) {
      uVar5 = 0;
      do {
        *puVar2 = *puVar4;
        puVar2[1] = puVar4[1];
        puVar2[2] = puVar4[2];
        puVar2[3] = puVar4[3];
        puVar2 = puVar2 + 4;
        puVar4 = puVar4 + 4;
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(uint *)(param_2 + 0x48));
    }
    *(int *)(param_1 + 0x274c) = *(int *)(param_1 + 0x274c) + iVar1 * 4;
                    
                    
    (**(code **)(param_1 + 0x275c))();
    return;
  }
  return;
}

/* FUN_0007df86 @ 0x7df86 (386 bytes) */
int FUN_0007df86(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  uint *param_4;
{
  byte bVar1;
  uint uVar2;
  bool bVar3;
  
  _memset((void *)(param_2 + 0x68),-1,0x3c);
  bVar3 = (*(byte *)(param_1 + 0x1b9c) & 1) != 0;
  if (bVar3) {
    *(undefined4 *)(param_2 + 0x68) = 0;
  }
  uVar2 = (uint)bVar3;
  if ((*(byte *)(param_1 + 0x1b9e) & 1) != 0) {
    *(uint *)(param_2 + 0x6c) = uVar2;
    uVar2 = uVar2 + 1;
  }
  bVar1 = *(byte *)(param_1 + 0x1b9c);
  if ((bVar1 & 2) != 0) {
    *(uint *)(param_2 + 0x74) = uVar2;
    uVar2 = uVar2 + 1;
    bVar1 = *(byte *)(param_1 + 0x1b9c);
  }
  if ((bVar1 & 4) != 0) {
    *(uint *)(param_2 + 0x7c) = uVar2;
    if ((*(char *)(param_1 + 0x44) < '\0') && (*(char *)(param_1 + 0x121) == '\0')) {
      *(uint *)(param_2 + 0x70) = uVar2;
    }
    uVar2 = uVar2 + 1;
    bVar1 = *(byte *)(param_1 + 0x1b9c);
  }
  if ((bVar1 & 8) != 0) {
    *(uint *)(param_2 + 0x78) = uVar2;
    uVar2 = uVar2 + 1;
    bVar1 = *(byte *)(param_1 + 0x1b9c);
  }
  if ((bVar1 & 0x10) != 0) {
    *(uint *)(param_2 + 0x80) = uVar2;
    uVar2 = uVar2 + 1;
  }
  bVar1 = *(byte *)(param_1 + 0x1ba0);
  if ((bVar1 & 7) != 0) {
    *(uint *)(param_2 + 0x84) = uVar2;
    uVar2 = uVar2 + 1;
    bVar1 = *(byte *)(param_1 + 0x1ba0);
  }
  if ((bVar1 & 0x38) != 0) {
    *(uint *)(param_2 + 0x88) = uVar2;
    uVar2 = uVar2 + 1;
  }
  if ((*(ushort *)(param_1 + 0x1ba0) & 0x1c0) != 0) {
    *(uint *)(param_2 + 0x8c) = uVar2;
    uVar2 = uVar2 + 1;
  }
  bVar1 = *(byte *)(param_1 + 0x1ba1);
  if ((bVar1 & 0xe) != 0) {
    *(uint *)(param_2 + 0x90) = uVar2;
    uVar2 = uVar2 + 1;
    bVar1 = *(byte *)(param_1 + 0x1ba1);
  }
  if ((bVar1 & 0x70) != 0) {
    *(uint *)(param_2 + 0x94) = uVar2;
    uVar2 = uVar2 + 1;
  }
  if ((*(uint *)(param_1 + 0x1ba0) & 0x38000) != 0) {
    *(uint *)(param_2 + 0x98) = uVar2;
    uVar2 = uVar2 + 1;
  }
  bVar1 = *(byte *)(param_1 + 0x1ba2);
  if ((bVar1 & 0x1c) != 0) {
    *(uint *)(param_2 + 0x9c) = uVar2;
    uVar2 = uVar2 + 1;
    bVar1 = *(byte *)(param_1 + 0x1ba2);
  }
  if ((bVar1 & 0xe0) != 0) {
    *(uint *)(param_2 + 0xa0) = uVar2;
    uVar2 = uVar2 + 1;
  }
  (**(code **)(param_1 + 0x1334))(param_1,0);
  *param_4 = uVar2;
  return;
}

/* FUN_0007e108 @ 0x7e108 (5 bytes) */
int FUN_0007e108()
{
  return;
}

/* FUN_0007e10d @ 0x7e10d (998 bytes) */
int FUN_0007e10d(param_1)
  int param_1;
{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  undefined4 local_20;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  uVar2 = *(uint *)(param_1 + 0x1804);
  *(undefined4 *)(param_1 + 0x1ca0) = 1;
  *(undefined4 *)(param_1 + 0x1ca4) = 0;
  *(byte *)(param_1 + 0x1ca4) = *(byte *)(param_1 + 0x1ca4) & 0x80 | 4;
  FUN_0004ea07(param_1,0,3,0,0,0,0,0);
  *(undefined4 *)(param_1 + 0x1b9c) = 1;
  *(undefined4 *)(param_1 + 0x1ba0) = 0;
  *(undefined4 *)(param_1 + 0x1bb0) = 0;
  if ((uVar2 & 2) == 0) {
    local_20 = 1;
    local_10 = 2;
  }
  else {
    *(uint *)(param_1 + 0x1ca0) = *(uint *)(param_1 + 0x1ca0) | 0x40000;
    *(byte *)(param_1 + 0x1ca4) =
         *(byte *)(param_1 + 0x1ca4) & 0x80 | *(byte *)(param_1 + 0x1ca4) + 1 & 0x7f;
    FUN_0004ea07(param_1,1,0,0,1,0,0,0);
    *(byte *)(param_1 + 0x1b9e) = *(byte *)(param_1 + 0x1b9e) | 1;
    local_20 = 2;
    local_10 = 3;
  }
  *(uint *)(param_1 + 0x1ca0) = *(uint *)(param_1 + 0x1ca0) | 4;
  *(byte *)(param_1 + 0x1ca4) =
       *(byte *)(param_1 + 0x1ca4) & 0x80 | *(byte *)(param_1 + 0x1ca4) + 4 & 0x7f;
  FUN_0004ea07(param_1,local_20,3,0,local_20,0,0,0);
  *(byte *)(param_1 + 0x1b9c) = *(byte *)(param_1 + 0x1b9c) | 2;
  if ((uVar2 & 1) != 0) {
    *(uint *)(param_1 + 0x1ca0) = *(uint *)(param_1 + 0x1ca0) | 8;
    *(byte *)(param_1 + 0x1ca4) =
         *(byte *)(param_1 + 0x1ca4) & 0x80 | *(byte *)(param_1 + 0x1ca4) + 4 & 0x7f;
    FUN_0004ea07(param_1,local_10,3,0,local_10,0,0,0);
    local_10 = local_20 + 2;
    *(byte *)(param_1 + 0x1b9c) = *(byte *)(param_1 + 0x1b9c) | 4;
  }
  if ((uVar2 & 8) != 0) {
    *(uint *)(param_1 + 0x1ca0) = *(uint *)(param_1 + 0x1ca0) | 0x30;
    *(byte *)(param_1 + 0x1ca4) =
         *(byte *)(param_1 + 0x1ca4) & 0x80 | *(byte *)(param_1 + 0x1ca4) + 7 & 0x7f;
    FUN_0004ea07(param_1,local_10,3,0,local_10,0,0,0);
    FUN_0004ea07(param_1,local_10 + 1,2,0,local_10 + 1,0,0,0);
    local_10 = local_10 + 2;
    *(byte *)(param_1 + 0x1b9c) = *(byte *)(param_1 + 0x1b9c) | 0x18;
  }
  if (uVar2 >> 4 != 0) {
    local_14 = param_1;
    local_18 = 0;
    do {
      bVar4 = (byte)*(undefined4 *)(local_14 + 0x1824);
      *(uint *)(param_1 + 0x1ca0) = *(uint *)(param_1 + 0x1ca0) | 0x400 << (bVar4 & 0x1f);
      *(byte *)(param_1 + 0x1ca4) =
           *(byte *)(param_1 + 0x1ca4) & 0x80 | *(byte *)(param_1 + 0x1ca4) + 4 & 0x7f;
      FUN_0004ea07(param_1,local_10,3,0,local_10,0,0,0);
      local_10 = local_10 + 1;
      uVar3 = 4 << (bVar4 * '\x03' & 0x1f);
      *(uint *)(param_1 + 0x1ba0) = *(uint *)(param_1 + 0x1ba0) | uVar3;
      *(uint *)(param_1 + 0x1bb0) = *(uint *)(param_1 + 0x1bb0) | uVar3;
      local_18 = local_18 + 1;
      local_14 = local_14 + 4;
    } while (uVar2 >> 4 != local_18);
  }
  if ((*(byte *)(param_1 + 0x46) & 0x20) != 0) {
    uVar2 = 4 << (*(char *)(param_1 + 0x11d2) * '\x03' & 0x1fU);
    *(uint *)(param_1 + 0x1ba0) = *(uint *)(param_1 + 0x1ba0) | uVar2;
    *(uint *)(param_1 + 0x1bb0) = *(uint *)(param_1 + 0x1bb0) | uVar2;
  }
  uVar2 = local_10 - 1;
  if ((uVar2 & 1) == 0) {
    pbVar1 = (byte *)(param_1 + 0x1be5 + (uVar2 >> 1) * 4);
    *pbVar1 = *pbVar1 | 0x20;
  }
  else {
    pbVar1 = (byte *)(param_1 + 0x1be7 + (uVar2 >> 1) * 4);
    *pbVar1 = *pbVar1 | 0x20;
  }
  *(int *)(param_1 + 0x2438) = local_10;
  *(int *)(param_1 + 0x243c) = local_10;
  (**(code **)(param_1 + 0x1334))(param_1,1);
  (**(code **)(param_1 + 0x1330))(param_1,0xc0100000);
  return;
}

/* FUN_0007e4f3 @ 0x7e4f3 (1066 bytes) */
int FUN_0007e4f3(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  byte bVar5;
  char *pcVar6;
  char *pcVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  char *pcVar11;
  bool bVar12;
  char *local_70;
  int local_5c;
  int local_54;
  int local_50;
  uint local_48;
  uint local_44;
  uint local_40;
  char local_3c [8];
  undefined4 local_34;
  uint local_30;
  
  if (*(char *)(param_1 + 0x1868) != '\0') {
    FUN_000633b0(param_1);
    return;
  }
  pcVar6 = local_3c;
  for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
    pcVar6[0] = '\0';
    pcVar6[1] = '\0';
    pcVar6[2] = '\0';
    pcVar6[3] = '\0';
    pcVar6 = pcVar6 + 4;
  }
  local_3c[3] = local_3c[3] | 0x10;
  local_34 = *(undefined4 *)(param_1 + 0x1804);
  bVar5 = *(byte *)(param_1 + 0x46);
  if ((bVar5 & 0x30) == 0) {
    local_70 = *(char **)(param_1 + 0x14c);
    bVar12 = false;
    if (local_70 != (char *)0x0) {
LAB_0007e55b:
      iVar4 = 0x30;
      pcVar6 = local_70;
      pcVar10 = local_3c;
      do {
        pcVar7 = pcVar6;
        pcVar11 = pcVar10;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar11 = pcVar10 + 1;
        pcVar7 = pcVar6 + 1;
        bVar12 = *pcVar6 == *pcVar10;
        pcVar6 = pcVar7;
        pcVar10 = pcVar11;
      } while (bVar12);
      iVar4 = 0;
      if (!bVar12) {
        iVar4 = (uint)(byte)pcVar7[-1] - (uint)(byte)pcVar11[-1];
      }
      if (iVar4 == 0) goto LAB_0007e59d;
    }
  }
  else {
    local_30 = bVar5 >> 4 & 1 | (bVar5 >> 5 & 1) * 2 | (uint)*(byte *)(param_1 + 0x11d3) << 2;
    local_70 = *(char **)(param_1 + 0x14c);
    bVar12 = local_70 == (char *)0x0;
    if (!bVar12) goto LAB_0007e55b;
  }
  local_70 = (char *)FUN_0009cdff(param_1,local_3c);
  if (local_70 == (char *)0x0) {
    uVar1 = *(uint *)(param_1 + 0x1804);
    puVar3 = (undefined4 *)FUN_0008dbba(param_1,0,0);
    *puVar3 = 0;
    puVar3[0x1a] = 0;
    bVar5 = *(byte *)(param_1 + 0x46);
    if ((bVar5 & 0x20) == 0) {
      uVar8 = uVar1 >> 1 & 1;
      local_40 = uVar1 >> 3 & 1;
      local_50 = 0;
    }
    else {
      uVar8 = uVar1 >> 1 & 1;
      local_40 = uVar1 >> 3 & 1;
      local_50 = (-local_40 & 2) + ((uVar1 & 1) != 0) + uVar8 + 2 +
                 (uint)*(byte *)(param_1 + 0x11d2);
      puVar3[*(byte *)(param_1 + 0x11d2) + 0x21] = local_50;
      bVar5 = *(byte *)(param_1 + 0x46);
    }
    local_44 = uVar1 & 1;
    FUN_0008dd2f(puVar3,bVar5 >> 5 & 1,*(undefined1 *)(param_1 + 0x11d2));
    if (uVar8 == 0) {
      local_54 = 1;
      iVar9 = 1;
      local_5c = 2;
      iVar4 = 2;
    }
    else {
      puVar3[0x13] = 1;
      puVar3[0x1b] = 1;
      FUN_0008e180(puVar3);
      local_54 = 2;
      iVar9 = 2;
      local_5c = 3;
      iVar4 = 3;
    }
    puVar3[3] = local_54;
    puVar3[0x1d] = iVar9;
    FUN_0008de84(puVar3,3,0,0);
    if (local_44 != 0) {
      puVar3[4] = local_5c;
      puVar3[0x1f] = iVar4;
      FUN_0008de84(puVar3,4,1,0);
      if ((uVar1 & 4) != 0) {
        puVar3[0x14] = local_5c;
        puVar3[0x15] = 3;
        puVar3[0x1c] = iVar4;
        FUN_0008e212(puVar3);
      }
      local_5c = local_54 + 2;
      iVar4 = iVar9 + 2;
    }
    if (local_40 != 0) {
      puVar3[5] = local_5c;
      puVar3[0x1e] = iVar4;
      FUN_0008de84(puVar3,3,2,1);
      puVar3[6] = local_5c + 1;
      local_5c = local_5c + 2;
      puVar3[0x20] = iVar4 + 1;
      iVar4 = iVar4 + 2;
      FUN_0008de84(puVar3,4,3,1);
    }
    if (uVar1 >> 4 != 0) {
      local_48 = 0;
      iVar9 = param_1;
      do {
        iVar2 = *(int *)(iVar9 + 0x1824);
        puVar3[iVar2 + 0xb] = local_5c;
        local_5c = local_5c + 1;
        if (local_50 == iVar4) {
          iVar4 = iVar4 + 1;
        }
        puVar3[iVar2 + 0x21] = iVar4;
        iVar4 = iVar4 + 1;
        FUN_0008e025(puVar3,iVar2);
        local_48 = local_48 + 1;
        iVar9 = iVar9 + 4;
      } while (uVar1 >> 4 != local_48);
    }
    FUN_00098884(puVar3);
    if (local_50 == iVar4) {
      iVar4 = iVar4 + 1;
    }
    local_70 = (char *)FUN_0009a799(param_1,local_3c,puVar3,local_5c,iVar4,0,0,1);
    local_70[0x34] = '\0';
    local_70[0x35] = '\0';
    local_70[0x36] = '\0';
    local_70[0x37] = '\0';
    *(int *)(local_70 + 0x38) = *(int *)(*(int *)(local_70 + 0x54) + 0x3cc) + -1;
  }
LAB_0007e59d:
  if (local_70 == *(char **)(param_1 + 0x14c)) {
    return;
  }
  *(char **)(param_1 + 0x14c) = local_70;
  *(byte *)(param_1 + 0x8d) = *(byte *)(param_1 + 0x8d) | 0x20;
  (**(code **)(param_1 + 0x12d0))(param_1,local_70);
  return;
}

/* FUN_0007e91d @ 0x7e91d (162 bytes) */
int FUN_0007e91d(param_1)
  int param_1;
{
  undefined4 *puVar1;
  int iVar2;
  
  ((int (*)())FUN_0007e4f3)(param_1);
  ((int (*)())FUN_0007e10d)(param_1);
  puVar1 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,9);
  *(undefined4 **)(param_1 + 0x274c) = puVar1;
  *puVar1 = 0x861;
  puVar1[1] = *(undefined4 *)(param_1 + 0x1ca0);
  puVar1[2] = 0x10824;
  puVar1[3] = *(undefined4 *)(param_1 + 0x1b9c);
  puVar1[4] = *(undefined4 *)(param_1 + 0x1ba0);
  puVar1[5] = 0x82d;
  puVar1[6] = *(undefined4 *)(param_1 + 0x1ca4);
  puVar1[7] = 0x1047;
  puVar1[8] = *(undefined4 *)(param_1 + 0x1bb0);
  iVar2 = *(int *)(param_1 + 0x274c) + 0x24;
  *(int *)(param_1 + 0x274c) = iVar2;
  (**(code **)(param_1 + 0x275c))(param_1,iVar2);
  FUN_0004d534();
  return;
}

/* FUN_0007e9bf @ 0x7e9bf (990 bytes) */
int FUN_0007e9bf(param_1)
  int param_1;
{
  byte bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  byte *pbVar10;
  int local_48;
  uint local_40;
  undefined4 local_14;
  undefined4 local_10;
  
  *(undefined1 *)(param_1 + 0x126) = 0;
  *(undefined4 *)(param_1 + 0x1b98) = 0;
  cVar2 = *(char *)(param_1 + 0x29);
  FUN_0008b3f0(param_1);
  if (cVar2 == '\0') {
    iVar7 = *(int *)(param_1 + 0x13c);
    if (iVar7 == *(int *)(param_1 + 0x140)) {
      iVar5 = *(int *)(param_1 + 0x148);
      if (iVar5 == *(int *)(param_1 + 0x144)) {
        return;
      }
      goto LAB_0007ea2b;
    }
    *(int *)(param_1 + 0x140) = iVar7;
    *(undefined4 *)(param_1 + 0x144) = *(undefined4 *)(param_1 + 0x148);
    cVar2 = *(char *)(param_1 + 0x124);
  }
  else {
    iVar7 = *(int *)(param_1 + 0x13c);
    iVar5 = *(int *)(param_1 + 0x148);
LAB_0007ea2b:
    *(int *)(param_1 + 0x140) = iVar7;
    *(int *)(param_1 + 0x144) = iVar5;
    cVar2 = *(char *)(param_1 + 0x124);
  }
  if (cVar2 != '\0') {
LAB_0007ea10:
    ((int (*)())FUN_0007e91d)(param_1);
    return;
  }
  if ((*(byte *)(param_1 + 0x45) & 8) != 0) {
    return;
  }
  local_48 = FUN_0009cdff(param_1,param_1 + 0x1874);
  if (local_48 == 0) {
    FUN_0009afcf(param_1);
    uVar6 = FUN_00099e1d(param_1);
    iVar7 = ((void * (*)())FUN_0009b319)(param_1,0,&local_10,&local_14,uVar6);
    local_48 = FUN_0009a799(param_1,param_1 + 0x1874,iVar7,*(undefined1 *)(param_1 + 0x131),local_10
                            ,local_14,uVar6,*(undefined1 *)(param_1 + 0x126));
    puVar8 = (undefined4 *)
             FUN_00072f84(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x18));
    *puVar8 = 0x460;
    puVar8[3] = 0x20;
    puVar8[8] = 0;
    puVar8[9] = 0;
    cVar2 = FUN_0009aa35(param_1,local_48,puVar8,0x10);
    ((int (*)())FUN_00075412)(puVar8);
    if (*(uint *)(iVar7 + 0x3cc) <= *(uint *)(iVar7 + 0x3e4)) {
      *(undefined1 *)(local_48 + 0x59) = 0;
      *(undefined1 *)(param_1 + 0x126) = 0;
    }
    if (*(char *)(param_1 + 0x126) != '\0') {
      *(byte *)(param_1 + 0x8c) = *(byte *)(param_1 + 0x8c) | 2;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1020;
      *(undefined1 *)(param_1 + 0x2435) = 1;
      FUN_000a60e5(param_1);
      *(undefined1 *)(param_1 + 0x29) = 1;
      FUN_0008b3f0(param_1);
      ((int (*)())FUN_0007e91d)(param_1);
      return;
    }
    if (cVar2 == '\0') {
      iVar7 = *(int *)(local_48 + 0x54);
      iVar5 = *(int *)(iVar7 + 0x3cc);
      *(undefined4 *)(local_48 + 0x38) = 0;
      if (iVar5 != 0) {
        iVar9 = iVar5 * 0x10 + -0x10 + *(int *)(iVar7 + 0x3c8);
        do {
          if ((((*(byte *)(iVar9 + 4) & 7) == 1) || ((*(byte *)(iVar9 + 8) & 7) == 1)) ||
             ((*(byte *)(iVar9 + 0xc) & 7) == 1)) {
            *(int *)(local_48 + 0x38) = iVar5 + -1;
          }
          iVar9 = iVar9 + -0x10;
          iVar5 = iVar5 + -1;
        } while ((iVar5 != 0) && (*(int *)(local_48 + 0x38) == 0));
      }
    }
    else {
      iVar7 = *(int *)(local_48 + 0x54);
    }
    pbVar10 = *(byte **)(iVar7 + 0x3c8);
    if (*(int *)(iVar7 + 0x3cc) != 0) {
      local_40 = 0;
      do {
        bVar1 = *pbVar10;
        if ((bVar1 & 0x3f) == 4) {
          if ((((pbVar10[4] & 7) == 0) && ((pbVar10[8] & 7) == 0)) && ((pbVar10[0xc] & 7) == 0)) {
            cVar2 = (char)(*(ushort *)(pbVar10 + 4) >> 5);
            cVar3 = (char)(*(ushort *)(pbVar10 + 8) >> 5);
            if (((cVar2 != cVar3) &&
                (cVar4 = (char)(*(ushort *)(pbVar10 + 0xc) >> 5), cVar2 != cVar4)) &&
               (cVar3 != cVar4)) {
              *pbVar10 = bVar1 & 0xc0 | 0x80;
              iVar7 = *(int *)(local_48 + 0x54);
            }
          }
        }
        else if ((((bVar1 & 0x3f) == 0xb) && ((pbVar10[4] & 7) == 0)) &&
                (((pbVar10[8] & 7) == 0 && ((pbVar10[0xc] & 7) == 0)))) {
          cVar2 = (char)(*(ushort *)(pbVar10 + 4) >> 5);
          cVar3 = (char)(*(ushort *)(pbVar10 + 8) >> 5);
          if (((cVar2 != cVar3) && (cVar4 = (char)(*(ushort *)(pbVar10 + 0xc) >> 5), cVar2 != cVar4)
              ) && (cVar3 != cVar4)) {
            *pbVar10 = bVar1 & 0xc0 | 0x81;
            iVar7 = *(int *)(local_48 + 0x54);
          }
        }
        local_40 = local_40 + 1;
        pbVar10 = pbVar10 + 0x10;
      } while (local_40 < *(uint *)(iVar7 + 0x3cc));
    }
  }
  else if (*(char *)(local_48 + 0x59) != '\0') {
    *(byte *)(param_1 + 0x8c) = *(byte *)(param_1 + 0x8c) | 2;
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1020;
    *(undefined1 *)(param_1 + 0x2435) = 1;
    FUN_000a60e5(param_1);
    *(undefined1 *)(param_1 + 0x126) = 1;
    *(undefined1 *)(param_1 + 0x29) = 1;
    FUN_0008b3f0(param_1);
    goto LAB_0007ea10;
  }
  if (local_48 != *(int *)(param_1 + 0x14c)) {
    *(int *)(param_1 + 0x14c) = local_48;
    *(byte *)(param_1 + 0x8d) = *(byte *)(param_1 + 0x8d) | 0x20;
    (**(code **)(param_1 + 0x12d0))(param_1,local_48);
  }
  (**(code **)(param_1 + 0x12c4))(param_1,local_48);
  return;
}

/* FUN_0007ed9d @ 0x7ed9d (19 bytes) */
int FUN_0007ed9d(param_1)
  int param_1;
{
  *(undefined1 *)(param_1 + 0x29) = 1;
  ((int (*)())FUN_0007e9bf)();
  return;
}

/* FUN_0007edb0 @ 0x7edb0 (373 bytes) */
int FUN_0007edb0(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  
  *(undefined4 *)(param_1 + 0x148c) = 0;
  *(undefined1 *)(param_1 + 0x3d4) = 1;
  uVar1 = *(int *)(param_1 + 0x13f4) - 2;
  uVar3 = uVar1 & 0x3ff;
  uVar4 = *(int *)(param_1 + 0x13f4) - 1U & 0x3ff;
  DAT_001ee904 = DAT_001ee904 & 0xc0000000 | uVar3 | uVar3 << 10 | uVar4 << 0x14;
  DAT_001ee900 = DAT_001ee900 & 0xfffffc00 | uVar4;
  if ((*(byte *)(param_1 + 0x8e) & 1) != 0) {
    if (*(int *)(param_1 + 0xd8) == 2) {
      *(byte *)(param_1 + 0x8d) = *(byte *)(param_1 + 0x8d) | 0xa0;
      bVar2 = 0xc;
      goto LAB_0007ee59;
    }
    *(byte *)(param_1 + 0x8e) = *(byte *)(param_1 + 0x8e) & 0xfe;
  }
  bVar2 = 4;
LAB_0007ee59:
  if ((*(byte *)(param_1 + 0x45) & 8) != 0) {
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
    *(undefined1 *)(param_1 + 0x29) = 1;
    *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | bVar2;
  }
  *param_2 = 0x8a1;
  param_2[1] = 0;
  param_2[2] = 0x880;
  param_2[3] = uVar1;
  param_2[4] = 0x78882;
  param_2[5] = DAT_001ee920;
  param_2[6] = DAT_001ee924;
  param_2[7] = DAT_001ee928;
  param_2[8] = DAT_001ee92c;
  param_2[9] = DAT_001ee930;
  param_2[10] = DAT_001ee934;
  param_2[0xb] = DAT_001ee938;
  param_2[0xc] = DAT_001ee93c;
  param_2[0xd] = 0x208b4;
  param_2[0xe] = DAT_001ee904;
  param_2[0xf] = DAT_00210680;
  param_2[0x10] = DAT_001ee900;
  param_2[0x11] = 0x8b7;
  param_2[0x12] = 0;
  return param_2 + 0x13;
}

/* FUN_0007ef25 @ 0x7ef25 (927 bytes) */
int FUN_0007ef25(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15, param_16)
  int param_1;
  uint param_2;
  uint param_3;
  byte *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  byte *param_8;
  uint param_9;
  int param_10;
  byte *param_11;
  byte *param_12;
  uint param_13;
  int param_14;
  byte *param_15;
  byte *param_16;
{
  uint uVar1;
  void *pvVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  size_t sVar12;
  uint uVar13;
  
  iVar4 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar4 + 1U) {
    sVar12 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar2 = _calloc(sVar12 + 0x200,1);
    if (sVar12 != 0) {
      _memcpy(pvVar2,*(void **)(param_1 + 0x3c8),sVar12);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar2;
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
    iVar4 = *(int *)(param_1 + 0x3cc);
  }
  puVar3 = (uint *)(iVar4 * 0x10 + *(int *)(param_1 + 0x3c8));
  *(uint **)(param_1 + 0x3dc) = puVar3;
  *(int *)(param_1 + 0x3cc) = iVar4 + 1;
  *puVar3 = 0;
  *(undefined1 *)puVar3 = 0x44;
  uVar13 = (param_2 & 0xf) << 8;
  uVar1 = *puVar3;
  uVar8 = (param_3 & 0x7f) << 0xd;
  *puVar3 = uVar1 & 0xfff010ff | uVar13 | uVar8;
  uVar5 = (*param_4 & 1) << 0x14;
  *puVar3 = uVar1 & 0xffe010ff | uVar13 | uVar8 | uVar5;
  uVar6 = (param_4[4] & 1) << 0x15;
  *puVar3 = uVar1 & 0xffc010ff | uVar13 | uVar8 | uVar5 | uVar6;
  uVar7 = (param_4[8] & 1) << 0x16;
  *puVar3 = uVar1 & 0xff8010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7;
  *puVar3 = uVar1 & 0xff0010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7 | (param_4[0xc] & 1) << 0x17
  ;
  puVar3[1] = puVar3[1] & 0xfffffff0 | param_5 & 0xf;
  *(byte *)(puVar3 + 1) = (byte)puVar3[1] & 0xef;
  uVar8 = (uint)param_6 << 5;
  uVar1 = puVar3[1];
  puVar3[1] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_7 & 7) << 0xd;
  puVar3[1] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_7[4] & 7) << 0x10;
  puVar3[1] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_7[8] & 7) << 0x13;
  puVar3[1] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_7[0xc] & 7) << 0x16;
  puVar3[1] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_8 & 1) << 0x19;
  puVar3[1] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_8[4] & 1) << 0x1a;
  puVar3[1] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_8[8] & 1) << 0x1b;
  puVar3[1] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[1] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_8[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 7) = *(byte *)((int)puVar3 + 7) & 0x7f;
  puVar3[2] = puVar3[2] & 0xfffffff0 | param_9 & 0xf;
  *(byte *)(puVar3 + 2) = (byte)puVar3[2] & 0xef;
  uVar8 = (uint)param_10 << 5;
  uVar1 = puVar3[2];
  puVar3[2] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_11 & 7) << 0xd;
  puVar3[2] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_11[4] & 7) << 0x10;
  puVar3[2] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_11[8] & 7) << 0x13;
  puVar3[2] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_11[0xc] & 7) << 0x16;
  puVar3[2] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_12 & 1) << 0x19;
  puVar3[2] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_12[4] & 1) << 0x1a;
  puVar3[2] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_12[8] & 1) << 0x1b;
  puVar3[2] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[2] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_12[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)puVar3 + 0xb) & 0x7f;
  puVar3[3] = puVar3[3] & 0xfffffff0 | param_13 & 0xf;
  *(byte *)(puVar3 + 3) = (byte)puVar3[3] & 0xef;
  uVar8 = (uint)param_14 << 5;
  uVar1 = puVar3[3];
  puVar3[3] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_15 & 7) << 0xd;
  puVar3[3] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_15[4] & 7) << 0x10;
  puVar3[3] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_15[8] & 7) << 0x13;
  puVar3[3] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_15[0xc] & 7) << 0x16;
  puVar3[3] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_16 & 1) << 0x19;
  puVar3[3] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_16[4] & 1) << 0x1a;
  puVar3[3] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_16[8] & 1) << 0x1b;
  puVar3[3] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[3] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_16[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 0xf) = *(byte *)((int)puVar3 + 0xf) & 0x7f;
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_0007f2c4 @ 0x7f2c4 (727 bytes) */
int FUN_0007f2c4(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  uint param_2;
  uint param_3;
  byte *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  byte *param_8;
  uint param_9;
  int param_10;
  byte *param_11;
  byte *param_12;
{
  uint uVar1;
  void *pvVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  size_t sVar12;
  uint uVar13;
  
  iVar4 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar4 + 1U) {
    sVar12 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar2 = _calloc(sVar12 + 0x200,1);
    if (sVar12 != 0) {
      _memcpy(pvVar2,*(void **)(param_1 + 0x3c8),sVar12);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar2;
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
    iVar4 = *(int *)(param_1 + 0x3cc);
  }
  puVar3 = (uint *)(iVar4 * 0x10 + *(int *)(param_1 + 0x3c8));
  *(uint **)(param_1 + 0x3dc) = puVar3;
  *(int *)(param_1 + 0x3cc) = iVar4 + 1;
  *puVar3 = 0;
  *(undefined1 *)puVar3 = 1;
  uVar13 = (param_2 & 0xf) << 8;
  uVar1 = *puVar3;
  uVar8 = (param_3 & 0x7f) << 0xd;
  *puVar3 = uVar1 & 0xfff010ff | uVar13 | uVar8;
  uVar5 = (*param_4 & 1) << 0x14;
  *puVar3 = uVar1 & 0xffe010ff | uVar13 | uVar8 | uVar5;
  uVar6 = (param_4[4] & 1) << 0x15;
  *puVar3 = uVar1 & 0xffc010ff | uVar13 | uVar8 | uVar5 | uVar6;
  uVar7 = (param_4[8] & 1) << 0x16;
  *puVar3 = uVar1 & 0xff8010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7;
  *puVar3 = uVar1 & 0xff0010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7 | (param_4[0xc] & 1) << 0x17
  ;
  puVar3[1] = puVar3[1] & 0xfffffff0 | param_5 & 0xf;
  *(byte *)(puVar3 + 1) = (byte)puVar3[1] & 0xef;
  uVar8 = (uint)param_6 << 5;
  uVar1 = puVar3[1];
  puVar3[1] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_7 & 7) << 0xd;
  puVar3[1] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_7[4] & 7) << 0x10;
  puVar3[1] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_7[8] & 7) << 0x13;
  puVar3[1] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_7[0xc] & 7) << 0x16;
  puVar3[1] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_8 & 1) << 0x19;
  puVar3[1] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_8[4] & 1) << 0x1a;
  puVar3[1] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_8[8] & 1) << 0x1b;
  puVar3[1] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[1] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_8[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 7) = *(byte *)((int)puVar3 + 7) & 0x7f;
  puVar3[2] = puVar3[2] & 0xfffffff0 | param_9 & 0xf;
  *(byte *)(puVar3 + 2) = (byte)puVar3[2] & 0xef;
  uVar8 = (uint)param_10 << 5;
  uVar1 = puVar3[2];
  puVar3[2] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_11 & 7) << 0xd;
  puVar3[2] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_11[4] & 7) << 0x10;
  puVar3[2] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_11[8] & 7) << 0x13;
  puVar3[2] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_11[0xc] & 7) << 0x16;
  puVar3[2] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_12 & 1) << 0x19;
  puVar3[2] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_12[4] & 1) << 0x1a;
  puVar3[2] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_12[8] & 1) << 0x1b;
  puVar3[2] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[2] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_12[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)puVar3 + 0xb) & 0x7f;
  puVar3[3] = puVar3[2];
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_0007f59b @ 0x7f59b (578 bytes) */
int FUN_0007f59b(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  byte *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  byte *param_8;
{
  uint uVar1;
  void *pvVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  size_t sVar12;
  uint uVar13;
  
  iVar4 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar4 + 1U) {
    sVar12 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar2 = _calloc(sVar12 + 0x200,1);
    if (sVar12 != 0) {
      _memcpy(pvVar2,*(void **)(param_1 + 0x3c8),sVar12);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar2;
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
    iVar4 = *(int *)(param_1 + 0x3cc);
  }
  puVar3 = (uint *)(iVar4 * 0x10 + *(int *)(param_1 + 0x3c8));
  *(uint **)(param_1 + 0x3dc) = puVar3;
  *(int *)(param_1 + 0x3cc) = iVar4 + 1;
  *puVar3 = 0;
  *(undefined1 *)puVar3 = 2;
  uVar13 = (param_2 & 0xf) << 8;
  uVar1 = *puVar3;
  uVar8 = (param_3 & 0x7f) << 0xd;
  *puVar3 = uVar1 & 0xfff010ff | uVar13 | uVar8;
  uVar5 = (*param_4 & 1) << 0x14;
  *puVar3 = uVar1 & 0xffe010ff | uVar13 | uVar8 | uVar5;
  uVar6 = (param_4[4] & 1) << 0x15;
  *puVar3 = uVar1 & 0xffc010ff | uVar13 | uVar8 | uVar5 | uVar6;
  uVar7 = (param_4[8] & 1) << 0x16;
  *puVar3 = uVar1 & 0xff8010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7;
  *puVar3 = uVar1 & 0xff0010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7 | (param_4[0xc] & 1) << 0x17
  ;
  puVar3[1] = puVar3[1] & 0xfffffff0 | param_5 & 0xf;
  *(byte *)(puVar3 + 1) = (byte)puVar3[1] & 0xef;
  uVar11 = (uint)param_6 << 5;
  uVar1 = puVar3[1];
  puVar3[1] = uVar1 & 0xffffe01f | uVar11;
  uVar8 = (*param_7 & 7) << 0xd;
  puVar3[1] = uVar1 & 0xffff001f | uVar11 | uVar8;
  uVar5 = (param_7[4] & 7) << 0x10;
  puVar3[1] = uVar1 & 0xfff8001f | uVar11 | uVar8 | uVar5;
  uVar6 = (param_7[8] & 7) << 0x13;
  puVar3[1] = uVar1 & 0xffc0001f | uVar11 | uVar8 | uVar5 | uVar6;
  uVar7 = (param_7[0xc] & 7) << 0x16;
  puVar3[1] = uVar1 & 0xfe00001f | uVar11 | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (*param_8 & 1) << 0x19;
  puVar3[1] = uVar1 & 0xfc00001f | uVar11 | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (param_8[4] & 1) << 0x1a;
  puVar3[1] = uVar1 & 0xf800001f | uVar11 | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_8[8] & 1) << 0x1b;
  puVar3[1] = uVar1 & 0xf000001f | uVar11 | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  puVar3[1] = uVar1 & 0x8000001f | uVar11 | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10
              | (param_8[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 7) = *(byte *)((int)puVar3 + 7) & 0x7f;
  puVar3[2] = puVar3[2] & 0xfffffff0 | param_5 & 0xf;
  *(byte *)(puVar3 + 2) = (byte)puVar3[2] & 0xef;
  puVar3[2] = puVar3[2] & 0xfe00001f | uVar11 | 0x16da000;
  *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)puVar3 + 0xb) & 0xe1;
  puVar3[2] = puVar3[2] & 0x9fffffff;
  *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)puVar3 + 0xb) & 0x7f;
  puVar3[3] = puVar3[2];
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_0007f7dd @ 0x7f7dd (727 bytes) */
int FUN_0007f7dd(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  uint param_2;
  uint param_3;
  byte *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  byte *param_8;
  uint param_9;
  int param_10;
  byte *param_11;
  byte *param_12;
{
  uint uVar1;
  void *pvVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  size_t sVar12;
  uint uVar13;
  
  iVar4 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar4 + 1U) {
    sVar12 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar2 = _calloc(sVar12 + 0x200,1);
    if (sVar12 != 0) {
      _memcpy(pvVar2,*(void **)(param_1 + 0x3c8),sVar12);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar2;
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
    iVar4 = *(int *)(param_1 + 0x3cc);
  }
  puVar3 = (uint *)(iVar4 * 0x10 + *(int *)(param_1 + 0x3c8));
  *(uint **)(param_1 + 0x3dc) = puVar3;
  *(int *)(param_1 + 0x3cc) = iVar4 + 1;
  *puVar3 = 0;
  *(undefined1 *)puVar3 = 2;
  uVar13 = (param_2 & 0xf) << 8;
  uVar1 = *puVar3;
  uVar8 = (param_3 & 0x7f) << 0xd;
  *puVar3 = uVar1 & 0xfff010ff | uVar13 | uVar8;
  uVar5 = (*param_4 & 1) << 0x14;
  *puVar3 = uVar1 & 0xffe010ff | uVar13 | uVar8 | uVar5;
  uVar6 = (param_4[4] & 1) << 0x15;
  *puVar3 = uVar1 & 0xffc010ff | uVar13 | uVar8 | uVar5 | uVar6;
  uVar7 = (param_4[8] & 1) << 0x16;
  *puVar3 = uVar1 & 0xff8010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7;
  *puVar3 = uVar1 & 0xff0010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7 | (param_4[0xc] & 1) << 0x17
  ;
  puVar3[1] = puVar3[1] & 0xfffffff0 | param_5 & 0xf;
  *(byte *)(puVar3 + 1) = (byte)puVar3[1] & 0xef;
  uVar8 = (uint)param_6 << 5;
  uVar1 = puVar3[1];
  puVar3[1] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_7 & 7) << 0xd;
  puVar3[1] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_7[4] & 7) << 0x10;
  puVar3[1] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_7[8] & 7) << 0x13;
  puVar3[1] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_7[0xc] & 7) << 0x16;
  puVar3[1] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_8 & 1) << 0x19;
  puVar3[1] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_8[4] & 1) << 0x1a;
  puVar3[1] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_8[8] & 1) << 0x1b;
  puVar3[1] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[1] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_8[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 7) = *(byte *)((int)puVar3 + 7) & 0x7f;
  puVar3[2] = puVar3[2] & 0xfffffff0 | param_9 & 0xf;
  *(byte *)(puVar3 + 2) = (byte)puVar3[2] & 0xef;
  uVar8 = (uint)param_10 << 5;
  uVar1 = puVar3[2];
  puVar3[2] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_11 & 7) << 0xd;
  puVar3[2] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_11[4] & 7) << 0x10;
  puVar3[2] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_11[8] & 7) << 0x13;
  puVar3[2] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_11[0xc] & 7) << 0x16;
  puVar3[2] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_12 & 1) << 0x19;
  puVar3[2] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_12[4] & 1) << 0x1a;
  puVar3[2] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_12[8] & 1) << 0x1b;
  puVar3[2] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[2] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_12[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)puVar3 + 0xb) & 0x7f;
  puVar3[3] = puVar3[2];
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_0007fab4 @ 0x7fab4 (727 bytes) */
int FUN_0007fab4(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  uint param_2;
  uint param_3;
  byte *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  byte *param_8;
  uint param_9;
  int param_10;
  byte *param_11;
  byte *param_12;
{
  uint uVar1;
  void *pvVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  size_t sVar12;
  uint uVar13;
  
  iVar4 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar4 + 1U) {
    sVar12 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar2 = _calloc(sVar12 + 0x200,1);
    if (sVar12 != 0) {
      _memcpy(pvVar2,*(void **)(param_1 + 0x3c8),sVar12);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar2;
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
    iVar4 = *(int *)(param_1 + 0x3cc);
  }
  puVar3 = (uint *)(iVar4 * 0x10 + *(int *)(param_1 + 0x3c8));
  *(uint **)(param_1 + 0x3dc) = puVar3;
  *(int *)(param_1 + 0x3cc) = iVar4 + 1;
  *puVar3 = 0;
  *(undefined1 *)puVar3 = 3;
  uVar13 = (param_2 & 0xf) << 8;
  uVar1 = *puVar3;
  uVar8 = (param_3 & 0x7f) << 0xd;
  *puVar3 = uVar1 & 0xfff010ff | uVar13 | uVar8;
  uVar5 = (*param_4 & 1) << 0x14;
  *puVar3 = uVar1 & 0xffe010ff | uVar13 | uVar8 | uVar5;
  uVar6 = (param_4[4] & 1) << 0x15;
  *puVar3 = uVar1 & 0xffc010ff | uVar13 | uVar8 | uVar5 | uVar6;
  uVar7 = (param_4[8] & 1) << 0x16;
  *puVar3 = uVar1 & 0xff8010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7;
  *puVar3 = uVar1 & 0xff0010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7 | (param_4[0xc] & 1) << 0x17
  ;
  puVar3[1] = puVar3[1] & 0xfffffff0 | param_5 & 0xf;
  *(byte *)(puVar3 + 1) = (byte)puVar3[1] & 0xef;
  uVar8 = (uint)param_6 << 5;
  uVar1 = puVar3[1];
  puVar3[1] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_7 & 7) << 0xd;
  puVar3[1] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_7[4] & 7) << 0x10;
  puVar3[1] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_7[8] & 7) << 0x13;
  puVar3[1] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_7[0xc] & 7) << 0x16;
  puVar3[1] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_8 & 1) << 0x19;
  puVar3[1] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_8[4] & 1) << 0x1a;
  puVar3[1] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_8[8] & 1) << 0x1b;
  puVar3[1] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[1] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_8[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 7) = *(byte *)((int)puVar3 + 7) & 0x7f;
  puVar3[2] = puVar3[2] & 0xfffffff0 | param_9 & 0xf;
  *(byte *)(puVar3 + 2) = (byte)puVar3[2] & 0xef;
  uVar8 = (uint)param_10 << 5;
  uVar1 = puVar3[2];
  puVar3[2] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_11 & 7) << 0xd;
  puVar3[2] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_11[4] & 7) << 0x10;
  puVar3[2] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_11[8] & 7) << 0x13;
  puVar3[2] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_11[0xc] & 7) << 0x16;
  puVar3[2] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_12 & 1) << 0x19;
  puVar3[2] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_12[4] & 1) << 0x1a;
  puVar3[2] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_12[8] & 1) << 0x1b;
  puVar3[2] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[2] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_12[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)puVar3 + 0xb) & 0x7f;
  puVar3[3] = puVar3[2];
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_0007fd8b @ 0x7fd8b (927 bytes) */
int FUN_0007fd8b(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15, param_16)
  int param_1;
  uint param_2;
  uint param_3;
  byte *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  byte *param_8;
  uint param_9;
  int param_10;
  byte *param_11;
  byte *param_12;
  uint param_13;
  int param_14;
  byte *param_15;
  byte *param_16;
{
  uint uVar1;
  void *pvVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  size_t sVar12;
  uint uVar13;
  
  iVar4 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar4 + 1U) {
    sVar12 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar2 = _calloc(sVar12 + 0x200,1);
    if (sVar12 != 0) {
      _memcpy(pvVar2,*(void **)(param_1 + 0x3c8),sVar12);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar2;
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
    iVar4 = *(int *)(param_1 + 0x3cc);
  }
  puVar3 = (uint *)(iVar4 * 0x10 + *(int *)(param_1 + 0x3c8));
  *(uint **)(param_1 + 0x3dc) = puVar3;
  *(int *)(param_1 + 0x3cc) = iVar4 + 1;
  *puVar3 = 0;
  *(undefined1 *)puVar3 = 4;
  uVar13 = (param_2 & 0xf) << 8;
  uVar1 = *puVar3;
  uVar8 = (param_3 & 0x7f) << 0xd;
  *puVar3 = uVar1 & 0xfff010ff | uVar13 | uVar8;
  uVar5 = (*param_4 & 1) << 0x14;
  *puVar3 = uVar1 & 0xffe010ff | uVar13 | uVar8 | uVar5;
  uVar6 = (param_4[4] & 1) << 0x15;
  *puVar3 = uVar1 & 0xffc010ff | uVar13 | uVar8 | uVar5 | uVar6;
  uVar7 = (param_4[8] & 1) << 0x16;
  *puVar3 = uVar1 & 0xff8010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7;
  *puVar3 = uVar1 & 0xff0010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7 | (param_4[0xc] & 1) << 0x17
  ;
  puVar3[1] = puVar3[1] & 0xfffffff0 | param_5 & 0xf;
  *(byte *)(puVar3 + 1) = (byte)puVar3[1] & 0xef;
  uVar8 = (uint)param_6 << 5;
  uVar1 = puVar3[1];
  puVar3[1] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_7 & 7) << 0xd;
  puVar3[1] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_7[4] & 7) << 0x10;
  puVar3[1] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_7[8] & 7) << 0x13;
  puVar3[1] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_7[0xc] & 7) << 0x16;
  puVar3[1] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_8 & 1) << 0x19;
  puVar3[1] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_8[4] & 1) << 0x1a;
  puVar3[1] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_8[8] & 1) << 0x1b;
  puVar3[1] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[1] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_8[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 7) = *(byte *)((int)puVar3 + 7) & 0x7f;
  puVar3[2] = puVar3[2] & 0xfffffff0 | param_9 & 0xf;
  *(byte *)(puVar3 + 2) = (byte)puVar3[2] & 0xef;
  uVar8 = (uint)param_10 << 5;
  uVar1 = puVar3[2];
  puVar3[2] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_11 & 7) << 0xd;
  puVar3[2] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_11[4] & 7) << 0x10;
  puVar3[2] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_11[8] & 7) << 0x13;
  puVar3[2] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_11[0xc] & 7) << 0x16;
  puVar3[2] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_12 & 1) << 0x19;
  puVar3[2] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_12[4] & 1) << 0x1a;
  puVar3[2] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_12[8] & 1) << 0x1b;
  puVar3[2] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[2] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_12[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)puVar3 + 0xb) & 0x7f;
  puVar3[3] = puVar3[3] & 0xfffffff0 | param_13 & 0xf;
  *(byte *)(puVar3 + 3) = (byte)puVar3[3] & 0xef;
  uVar8 = (uint)param_14 << 5;
  uVar1 = puVar3[3];
  puVar3[3] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_15 & 7) << 0xd;
  puVar3[3] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_15[4] & 7) << 0x10;
  puVar3[3] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_15[8] & 7) << 0x13;
  puVar3[3] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_15[0xc] & 7) << 0x16;
  puVar3[3] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_16 & 1) << 0x19;
  puVar3[3] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_16[4] & 1) << 0x1a;
  puVar3[3] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_16[8] & 1) << 0x1b;
  puVar3[3] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[3] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_16[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 0xf) = *(byte *)((int)puVar3 + 0xf) & 0x7f;
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_0008012a @ 0x8012a (927 bytes) */
int FUN_0008012a(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15, param_16)
  int param_1;
  uint param_2;
  uint param_3;
  byte *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  byte *param_8;
  uint param_9;
  int param_10;
  byte *param_11;
  byte *param_12;
  uint param_13;
  int param_14;
  byte *param_15;
  byte *param_16;
{
  uint uVar1;
  void *pvVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  size_t sVar12;
  uint uVar13;
  
  iVar4 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar4 + 1U) {
    sVar12 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar2 = _calloc(sVar12 + 0x200,1);
    if (sVar12 != 0) {
      _memcpy(pvVar2,*(void **)(param_1 + 0x3c8),sVar12);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar2;
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
    iVar4 = *(int *)(param_1 + 0x3cc);
  }
  puVar3 = (uint *)(iVar4 * 0x10 + *(int *)(param_1 + 0x3c8));
  *(uint **)(param_1 + 0x3dc) = puVar3;
  *(int *)(param_1 + 0x3cc) = iVar4 + 1;
  *puVar3 = 0;
  *(undefined1 *)puVar3 = 0xb;
  uVar13 = (param_2 & 0xf) << 8;
  uVar1 = *puVar3;
  uVar8 = (param_3 & 0x7f) << 0xd;
  *puVar3 = uVar1 & 0xfff010ff | uVar13 | uVar8;
  uVar5 = (*param_4 & 1) << 0x14;
  *puVar3 = uVar1 & 0xffe010ff | uVar13 | uVar8 | uVar5;
  uVar6 = (param_4[4] & 1) << 0x15;
  *puVar3 = uVar1 & 0xffc010ff | uVar13 | uVar8 | uVar5 | uVar6;
  uVar7 = (param_4[8] & 1) << 0x16;
  *puVar3 = uVar1 & 0xff8010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7;
  *puVar3 = uVar1 & 0xff0010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7 | (param_4[0xc] & 1) << 0x17
  ;
  puVar3[1] = puVar3[1] & 0xfffffff0 | param_5 & 0xf;
  *(byte *)(puVar3 + 1) = (byte)puVar3[1] & 0xef;
  uVar8 = (uint)param_6 << 5;
  uVar1 = puVar3[1];
  puVar3[1] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_7 & 7) << 0xd;
  puVar3[1] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_7[4] & 7) << 0x10;
  puVar3[1] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_7[8] & 7) << 0x13;
  puVar3[1] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_7[0xc] & 7) << 0x16;
  puVar3[1] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_8 & 1) << 0x19;
  puVar3[1] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_8[4] & 1) << 0x1a;
  puVar3[1] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_8[8] & 1) << 0x1b;
  puVar3[1] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[1] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_8[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 7) = *(byte *)((int)puVar3 + 7) & 0x7f;
  puVar3[2] = puVar3[2] & 0xfffffff0 | param_9 & 0xf;
  *(byte *)(puVar3 + 2) = (byte)puVar3[2] & 0xef;
  uVar8 = (uint)param_10 << 5;
  uVar1 = puVar3[2];
  puVar3[2] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_11 & 7) << 0xd;
  puVar3[2] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_11[4] & 7) << 0x10;
  puVar3[2] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_11[8] & 7) << 0x13;
  puVar3[2] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_11[0xc] & 7) << 0x16;
  puVar3[2] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_12 & 1) << 0x19;
  puVar3[2] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_12[4] & 1) << 0x1a;
  puVar3[2] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_12[8] & 1) << 0x1b;
  puVar3[2] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[2] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_12[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)puVar3 + 0xb) & 0x7f;
  puVar3[3] = puVar3[3] & 0xfffffff0 | param_13 & 0xf;
  *(byte *)(puVar3 + 3) = (byte)puVar3[3] & 0xef;
  uVar8 = (uint)param_14 << 5;
  uVar1 = puVar3[3];
  puVar3[3] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_15 & 7) << 0xd;
  puVar3[3] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_15[4] & 7) << 0x10;
  puVar3[3] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_15[8] & 7) << 0x13;
  puVar3[3] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_15[0xc] & 7) << 0x16;
  puVar3[3] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_16 & 1) << 0x19;
  puVar3[3] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_16[4] & 1) << 0x1a;
  puVar3[3] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_16[8] & 1) << 0x1b;
  puVar3[3] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[3] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_16[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 0xf) = *(byte *)((int)puVar3 + 0xf) & 0x7f;
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_000804c9 @ 0x804c9 (927 bytes) */
int FUN_000804c9(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15, param_16)
  int param_1;
  uint param_2;
  uint param_3;
  byte *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  byte *param_8;
  uint param_9;
  int param_10;
  byte *param_11;
  byte *param_12;
  uint param_13;
  int param_14;
  byte *param_15;
  byte *param_16;
{
  uint uVar1;
  void *pvVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  size_t sVar12;
  uint uVar13;
  
  iVar4 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar4 + 1U) {
    sVar12 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar2 = _calloc(sVar12 + 0x200,1);
    if (sVar12 != 0) {
      _memcpy(pvVar2,*(void **)(param_1 + 0x3c8),sVar12);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar2;
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
    iVar4 = *(int *)(param_1 + 0x3cc);
  }
  puVar3 = (uint *)(iVar4 * 0x10 + *(int *)(param_1 + 0x3c8));
  *(uint **)(param_1 + 0x3dc) = puVar3;
  *(int *)(param_1 + 0x3cc) = iVar4 + 1;
  *puVar3 = 0;
  *(undefined1 *)puVar3 = 0xc;
  uVar13 = (param_2 & 0xf) << 8;
  uVar1 = *puVar3;
  uVar8 = (param_3 & 0x7f) << 0xd;
  *puVar3 = uVar1 & 0xfff010ff | uVar13 | uVar8;
  uVar5 = (*param_4 & 1) << 0x14;
  *puVar3 = uVar1 & 0xffe010ff | uVar13 | uVar8 | uVar5;
  uVar6 = (param_4[4] & 1) << 0x15;
  *puVar3 = uVar1 & 0xffc010ff | uVar13 | uVar8 | uVar5 | uVar6;
  uVar7 = (param_4[8] & 1) << 0x16;
  *puVar3 = uVar1 & 0xff8010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7;
  *puVar3 = uVar1 & 0xff0010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7 | (param_4[0xc] & 1) << 0x17
  ;
  puVar3[1] = puVar3[1] & 0xfffffff0 | param_5 & 0xf;
  *(byte *)(puVar3 + 1) = (byte)puVar3[1] & 0xef;
  uVar8 = (uint)param_6 << 5;
  uVar1 = puVar3[1];
  puVar3[1] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_7 & 7) << 0xd;
  puVar3[1] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_7[4] & 7) << 0x10;
  puVar3[1] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_7[8] & 7) << 0x13;
  puVar3[1] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_7[0xc] & 7) << 0x16;
  puVar3[1] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_8 & 1) << 0x19;
  puVar3[1] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_8[4] & 1) << 0x1a;
  puVar3[1] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_8[8] & 1) << 0x1b;
  puVar3[1] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[1] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_8[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 7) = *(byte *)((int)puVar3 + 7) & 0x7f;
  puVar3[2] = puVar3[2] & 0xfffffff0 | param_9 & 0xf;
  *(byte *)(puVar3 + 2) = (byte)puVar3[2] & 0xef;
  uVar8 = (uint)param_10 << 5;
  uVar1 = puVar3[2];
  puVar3[2] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_11 & 7) << 0xd;
  puVar3[2] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_11[4] & 7) << 0x10;
  puVar3[2] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_11[8] & 7) << 0x13;
  puVar3[2] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_11[0xc] & 7) << 0x16;
  puVar3[2] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_12 & 1) << 0x19;
  puVar3[2] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_12[4] & 1) << 0x1a;
  puVar3[2] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_12[8] & 1) << 0x1b;
  puVar3[2] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[2] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_12[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)puVar3 + 0xb) & 0x7f;
  puVar3[3] = puVar3[3] & 0xfffffff0 | param_13 & 0xf;
  *(byte *)(puVar3 + 3) = (byte)puVar3[3] & 0xef;
  uVar8 = (uint)param_14 << 5;
  uVar1 = puVar3[3];
  puVar3[3] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_15 & 7) << 0xd;
  puVar3[3] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_15[4] & 7) << 0x10;
  puVar3[3] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_15[8] & 7) << 0x13;
  puVar3[3] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_15[0xc] & 7) << 0x16;
  puVar3[3] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_16 & 1) << 0x19;
  puVar3[3] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_16[4] & 1) << 0x1a;
  puVar3[3] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_16[8] & 1) << 0x1b;
  puVar3[3] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[3] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_16[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 0xf) = *(byte *)((int)puVar3 + 0xf) & 0x7f;
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_00080868 @ 0x80868 (727 bytes) */
int FUN_00080868(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  uint param_2;
  uint param_3;
  byte *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  byte *param_8;
  uint param_9;
  int param_10;
  byte *param_11;
  byte *param_12;
{
  uint uVar1;
  void *pvVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  size_t sVar12;
  uint uVar13;
  
  iVar4 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar4 + 1U) {
    sVar12 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar2 = _calloc(sVar12 + 0x200,1);
    if (sVar12 != 0) {
      _memcpy(pvVar2,*(void **)(param_1 + 0x3c8),sVar12);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar2;
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
    iVar4 = *(int *)(param_1 + 0x3cc);
  }
  puVar3 = (uint *)(iVar4 * 0x10 + *(int *)(param_1 + 0x3c8));
  *(uint **)(param_1 + 0x3dc) = puVar3;
  *(int *)(param_1 + 0x3cc) = iVar4 + 1;
  *puVar3 = 0;
  *(undefined1 *)puVar3 = 8;
  uVar13 = (param_2 & 0xf) << 8;
  uVar1 = *puVar3;
  uVar8 = (param_3 & 0x7f) << 0xd;
  *puVar3 = uVar1 & 0xfff010ff | uVar13 | uVar8;
  uVar5 = (*param_4 & 1) << 0x14;
  *puVar3 = uVar1 & 0xffe010ff | uVar13 | uVar8 | uVar5;
  uVar6 = (param_4[4] & 1) << 0x15;
  *puVar3 = uVar1 & 0xffc010ff | uVar13 | uVar8 | uVar5 | uVar6;
  uVar7 = (param_4[8] & 1) << 0x16;
  *puVar3 = uVar1 & 0xff8010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7;
  *puVar3 = uVar1 & 0xff0010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7 | (param_4[0xc] & 1) << 0x17
  ;
  puVar3[1] = puVar3[1] & 0xfffffff0 | param_5 & 0xf;
  *(byte *)(puVar3 + 1) = (byte)puVar3[1] & 0xef;
  uVar8 = (uint)param_6 << 5;
  uVar1 = puVar3[1];
  puVar3[1] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_7 & 7) << 0xd;
  puVar3[1] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_7[4] & 7) << 0x10;
  puVar3[1] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_7[8] & 7) << 0x13;
  puVar3[1] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_7[0xc] & 7) << 0x16;
  puVar3[1] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_8 & 1) << 0x19;
  puVar3[1] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_8[4] & 1) << 0x1a;
  puVar3[1] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_8[8] & 1) << 0x1b;
  puVar3[1] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[1] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_8[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 7) = *(byte *)((int)puVar3 + 7) & 0x7f;
  puVar3[2] = puVar3[2] & 0xfffffff0 | param_9 & 0xf;
  *(byte *)(puVar3 + 2) = (byte)puVar3[2] & 0xef;
  uVar8 = (uint)param_10 << 5;
  uVar1 = puVar3[2];
  puVar3[2] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_11 & 7) << 0xd;
  puVar3[2] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_11[4] & 7) << 0x10;
  puVar3[2] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_11[8] & 7) << 0x13;
  puVar3[2] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_11[0xc] & 7) << 0x16;
  puVar3[2] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_12 & 1) << 0x19;
  puVar3[2] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_12[4] & 1) << 0x1a;
  puVar3[2] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_12[8] & 1) << 0x1b;
  puVar3[2] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[2] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_12[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)puVar3 + 0xb) & 0x7f;
  puVar3[3] = puVar3[2];
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_00080b3f @ 0x80b3f (727 bytes) */
int FUN_00080b3f(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  uint param_2;
  uint param_3;
  byte *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  byte *param_8;
  uint param_9;
  int param_10;
  byte *param_11;
  byte *param_12;
{
  uint uVar1;
  void *pvVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  size_t sVar12;
  uint uVar13;
  
  iVar4 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar4 + 1U) {
    sVar12 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar2 = _calloc(sVar12 + 0x200,1);
    if (sVar12 != 0) {
      _memcpy(pvVar2,*(void **)(param_1 + 0x3c8),sVar12);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar2;
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
    iVar4 = *(int *)(param_1 + 0x3cc);
  }
  puVar3 = (uint *)(iVar4 * 0x10 + *(int *)(param_1 + 0x3c8));
  *(uint **)(param_1 + 0x3dc) = puVar3;
  *(int *)(param_1 + 0x3cc) = iVar4 + 1;
  *puVar3 = 0;
  *(undefined1 *)puVar3 = 7;
  uVar13 = (param_2 & 0xf) << 8;
  uVar1 = *puVar3;
  uVar8 = (param_3 & 0x7f) << 0xd;
  *puVar3 = uVar1 & 0xfff010ff | uVar13 | uVar8;
  uVar5 = (*param_4 & 1) << 0x14;
  *puVar3 = uVar1 & 0xffe010ff | uVar13 | uVar8 | uVar5;
  uVar6 = (param_4[4] & 1) << 0x15;
  *puVar3 = uVar1 & 0xffc010ff | uVar13 | uVar8 | uVar5 | uVar6;
  uVar7 = (param_4[8] & 1) << 0x16;
  *puVar3 = uVar1 & 0xff8010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7;
  *puVar3 = uVar1 & 0xff0010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7 | (param_4[0xc] & 1) << 0x17
  ;
  puVar3[1] = puVar3[1] & 0xfffffff0 | param_5 & 0xf;
  *(byte *)(puVar3 + 1) = (byte)puVar3[1] & 0xef;
  uVar8 = (uint)param_6 << 5;
  uVar1 = puVar3[1];
  puVar3[1] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_7 & 7) << 0xd;
  puVar3[1] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_7[4] & 7) << 0x10;
  puVar3[1] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_7[8] & 7) << 0x13;
  puVar3[1] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_7[0xc] & 7) << 0x16;
  puVar3[1] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_8 & 1) << 0x19;
  puVar3[1] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_8[4] & 1) << 0x1a;
  puVar3[1] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_8[8] & 1) << 0x1b;
  puVar3[1] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[1] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_8[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 7) = *(byte *)((int)puVar3 + 7) & 0x7f;
  puVar3[2] = puVar3[2] & 0xfffffff0 | param_9 & 0xf;
  *(byte *)(puVar3 + 2) = (byte)puVar3[2] & 0xef;
  uVar8 = (uint)param_10 << 5;
  uVar1 = puVar3[2];
  puVar3[2] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_11 & 7) << 0xd;
  puVar3[2] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_11[4] & 7) << 0x10;
  puVar3[2] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_11[8] & 7) << 0x13;
  puVar3[2] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_11[0xc] & 7) << 0x16;
  puVar3[2] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_12 & 1) << 0x19;
  puVar3[2] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_12[4] & 1) << 0x1a;
  puVar3[2] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_12[8] & 1) << 0x1b;
  puVar3[2] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[2] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_12[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)puVar3 + 0xb) & 0x7f;
  puVar3[3] = puVar3[2];
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_00080e16 @ 0x80e16 (727 bytes) */
int FUN_00080e16(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  uint param_2;
  uint param_3;
  byte *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  byte *param_8;
  uint param_9;
  int param_10;
  byte *param_11;
  byte *param_12;
{
  uint uVar1;
  void *pvVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  size_t sVar12;
  uint uVar13;
  
  iVar4 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar4 + 1U) {
    sVar12 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar2 = _calloc(sVar12 + 0x200,1);
    if (sVar12 != 0) {
      _memcpy(pvVar2,*(void **)(param_1 + 0x3c8),sVar12);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar2;
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
    iVar4 = *(int *)(param_1 + 0x3cc);
  }
  puVar3 = (uint *)(iVar4 * 0x10 + *(int *)(param_1 + 0x3c8));
  *(uint **)(param_1 + 0x3dc) = puVar3;
  *(int *)(param_1 + 0x3cc) = iVar4 + 1;
  *puVar3 = 0;
  *(undefined1 *)puVar3 = 10;
  uVar13 = (param_2 & 0xf) << 8;
  uVar1 = *puVar3;
  uVar8 = (param_3 & 0x7f) << 0xd;
  *puVar3 = uVar1 & 0xfff010ff | uVar13 | uVar8;
  uVar5 = (*param_4 & 1) << 0x14;
  *puVar3 = uVar1 & 0xffe010ff | uVar13 | uVar8 | uVar5;
  uVar6 = (param_4[4] & 1) << 0x15;
  *puVar3 = uVar1 & 0xffc010ff | uVar13 | uVar8 | uVar5 | uVar6;
  uVar7 = (param_4[8] & 1) << 0x16;
  *puVar3 = uVar1 & 0xff8010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7;
  *puVar3 = uVar1 & 0xff0010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7 | (param_4[0xc] & 1) << 0x17
  ;
  puVar3[1] = puVar3[1] & 0xfffffff0 | param_5 & 0xf;
  *(byte *)(puVar3 + 1) = (byte)puVar3[1] & 0xef;
  uVar8 = (uint)param_6 << 5;
  uVar1 = puVar3[1];
  puVar3[1] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_7 & 7) << 0xd;
  puVar3[1] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_7[4] & 7) << 0x10;
  puVar3[1] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_7[8] & 7) << 0x13;
  puVar3[1] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_7[0xc] & 7) << 0x16;
  puVar3[1] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_8 & 1) << 0x19;
  puVar3[1] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_8[4] & 1) << 0x1a;
  puVar3[1] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_8[8] & 1) << 0x1b;
  puVar3[1] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[1] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_8[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 7) = *(byte *)((int)puVar3 + 7) & 0x7f;
  puVar3[2] = puVar3[2] & 0xfffffff0 | param_9 & 0xf;
  *(byte *)(puVar3 + 2) = (byte)puVar3[2] & 0xef;
  uVar8 = (uint)param_10 << 5;
  uVar1 = puVar3[2];
  puVar3[2] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_11 & 7) << 0xd;
  puVar3[2] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_11[4] & 7) << 0x10;
  puVar3[2] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_11[8] & 7) << 0x13;
  puVar3[2] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_11[0xc] & 7) << 0x16;
  puVar3[2] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_12 & 1) << 0x19;
  puVar3[2] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_12[4] & 1) << 0x1a;
  puVar3[2] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_12[8] & 1) << 0x1b;
  puVar3[2] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[2] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_12[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)puVar3 + 0xb) & 0x7f;
  puVar3[3] = puVar3[2];
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_000810ed @ 0x810ed (727 bytes) */
int FUN_000810ed(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  uint param_2;
  uint param_3;
  byte *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  byte *param_8;
  uint param_9;
  int param_10;
  byte *param_11;
  byte *param_12;
{
  uint uVar1;
  void *pvVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  size_t sVar12;
  uint uVar13;
  
  iVar4 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar4 + 1U) {
    sVar12 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar2 = _calloc(sVar12 + 0x200,1);
    if (sVar12 != 0) {
      _memcpy(pvVar2,*(void **)(param_1 + 0x3c8),sVar12);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar2;
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
    iVar4 = *(int *)(param_1 + 0x3cc);
  }
  puVar3 = (uint *)(iVar4 * 0x10 + *(int *)(param_1 + 0x3c8));
  *(uint **)(param_1 + 0x3dc) = puVar3;
  *(int *)(param_1 + 0x3cc) = iVar4 + 1;
  *puVar3 = 0;
  *(undefined1 *)puVar3 = 9;
  uVar13 = (param_2 & 0xf) << 8;
  uVar1 = *puVar3;
  uVar8 = (param_3 & 0x7f) << 0xd;
  *puVar3 = uVar1 & 0xfff010ff | uVar13 | uVar8;
  uVar5 = (*param_4 & 1) << 0x14;
  *puVar3 = uVar1 & 0xffe010ff | uVar13 | uVar8 | uVar5;
  uVar6 = (param_4[4] & 1) << 0x15;
  *puVar3 = uVar1 & 0xffc010ff | uVar13 | uVar8 | uVar5 | uVar6;
  uVar7 = (param_4[8] & 1) << 0x16;
  *puVar3 = uVar1 & 0xff8010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7;
  *puVar3 = uVar1 & 0xff0010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7 | (param_4[0xc] & 1) << 0x17
  ;
  puVar3[1] = puVar3[1] & 0xfffffff0 | param_5 & 0xf;
  *(byte *)(puVar3 + 1) = (byte)puVar3[1] & 0xef;
  uVar8 = (uint)param_6 << 5;
  uVar1 = puVar3[1];
  puVar3[1] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_7 & 7) << 0xd;
  puVar3[1] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_7[4] & 7) << 0x10;
  puVar3[1] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_7[8] & 7) << 0x13;
  puVar3[1] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_7[0xc] & 7) << 0x16;
  puVar3[1] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_8 & 1) << 0x19;
  puVar3[1] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_8[4] & 1) << 0x1a;
  puVar3[1] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_8[8] & 1) << 0x1b;
  puVar3[1] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[1] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_8[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 7) = *(byte *)((int)puVar3 + 7) & 0x7f;
  puVar3[2] = puVar3[2] & 0xfffffff0 | param_9 & 0xf;
  *(byte *)(puVar3 + 2) = (byte)puVar3[2] & 0xef;
  uVar8 = (uint)param_10 << 5;
  uVar1 = puVar3[2];
  puVar3[2] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_11 & 7) << 0xd;
  puVar3[2] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_11[4] & 7) << 0x10;
  puVar3[2] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_11[8] & 7) << 0x13;
  puVar3[2] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_11[0xc] & 7) << 0x16;
  puVar3[2] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_12 & 1) << 0x19;
  puVar3[2] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_12[4] & 1) << 0x1a;
  puVar3[2] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_12[8] & 1) << 0x1b;
  puVar3[2] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[2] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_12[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)puVar3 + 0xb) & 0x7f;
  puVar3[3] = puVar3[2];
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_000813c4 @ 0x813c4 (524 bytes) */
int FUN_000813c4(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  byte *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  byte *param_8;
{
  uint uVar1;
  void *pvVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  size_t sVar12;
  uint uVar13;
  
  iVar4 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar4 + 1U) {
    sVar12 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar2 = _calloc(sVar12 + 0x200,1);
    if (sVar12 != 0) {
      _memcpy(pvVar2,*(void **)(param_1 + 0x3c8),sVar12);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar2;
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
    iVar4 = *(int *)(param_1 + 0x3cc);
  }
  puVar3 = (uint *)(iVar4 * 0x10 + *(int *)(param_1 + 0x3c8));
  *(uint **)(param_1 + 0x3dc) = puVar3;
  *(int *)(param_1 + 0x3cc) = iVar4 + 1;
  *puVar3 = 0;
  *(undefined1 *)puVar3 = 0xe;
  uVar13 = (param_2 & 0xf) << 8;
  uVar1 = *puVar3;
  uVar8 = (param_3 & 0x7f) << 0xd;
  *puVar3 = uVar1 & 0xfff010ff | uVar13 | uVar8;
  uVar5 = (*param_4 & 1) << 0x14;
  *puVar3 = uVar1 & 0xffe010ff | uVar13 | uVar8 | uVar5;
  uVar6 = (param_4[4] & 1) << 0x15;
  *puVar3 = uVar1 & 0xffc010ff | uVar13 | uVar8 | uVar5 | uVar6;
  uVar7 = (param_4[8] & 1) << 0x16;
  *puVar3 = uVar1 & 0xff8010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7;
  *puVar3 = uVar1 & 0xff0010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7 | (param_4[0xc] & 1) << 0x17
  ;
  puVar3[1] = puVar3[1] & 0xfffffff0 | param_5 & 0xf;
  *(byte *)(puVar3 + 1) = (byte)puVar3[1] & 0xef;
  uVar8 = (uint)param_6 << 5;
  uVar1 = puVar3[1];
  puVar3[1] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_7 & 7) << 0xd;
  puVar3[1] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_7[4] & 7) << 0x10;
  puVar3[1] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_7[8] & 7) << 0x13;
  puVar3[1] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_7[0xc] & 7) << 0x16;
  puVar3[1] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_8 & 1) << 0x19;
  puVar3[1] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_8[4] & 1) << 0x1a;
  puVar3[1] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_8[8] & 1) << 0x1b;
  puVar3[1] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[1] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_8[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 7) = *(byte *)((int)puVar3 + 7) & 0x7f;
  puVar3[2] = puVar3[1];
  puVar3[3] = puVar3[1];
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_000815d0 @ 0x815d0 (524 bytes) */
int FUN_000815d0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  byte *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  byte *param_8;
{
  uint uVar1;
  void *pvVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  size_t sVar12;
  uint uVar13;
  
  iVar4 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar4 + 1U) {
    sVar12 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar2 = _calloc(sVar12 + 0x200,1);
    if (sVar12 != 0) {
      _memcpy(pvVar2,*(void **)(param_1 + 0x3c8),sVar12);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar2;
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
    iVar4 = *(int *)(param_1 + 0x3cc);
  }
  puVar3 = (uint *)(iVar4 * 0x10 + *(int *)(param_1 + 0x3c8));
  *(uint **)(param_1 + 0x3dc) = puVar3;
  *(int *)(param_1 + 0x3cc) = iVar4 + 1;
  *puVar3 = 0;
  *(undefined1 *)puVar3 = 0x47;
  uVar13 = (param_2 & 0xf) << 8;
  uVar1 = *puVar3;
  uVar8 = (param_3 & 0x7f) << 0xd;
  *puVar3 = uVar1 & 0xfff010ff | uVar13 | uVar8;
  uVar5 = (*param_4 & 1) << 0x14;
  *puVar3 = uVar1 & 0xffe010ff | uVar13 | uVar8 | uVar5;
  uVar6 = (param_4[4] & 1) << 0x15;
  *puVar3 = uVar1 & 0xffc010ff | uVar13 | uVar8 | uVar5 | uVar6;
  uVar7 = (param_4[8] & 1) << 0x16;
  *puVar3 = uVar1 & 0xff8010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7;
  *puVar3 = uVar1 & 0xff0010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7 | (param_4[0xc] & 1) << 0x17
  ;
  puVar3[1] = puVar3[1] & 0xfffffff0 | param_5 & 0xf;
  *(byte *)(puVar3 + 1) = (byte)puVar3[1] & 0xef;
  uVar8 = (uint)param_6 << 5;
  uVar1 = puVar3[1];
  puVar3[1] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_7 & 7) << 0xd;
  puVar3[1] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_7[4] & 7) << 0x10;
  puVar3[1] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_7[8] & 7) << 0x13;
  puVar3[1] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_7[0xc] & 7) << 0x16;
  puVar3[1] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_8 & 1) << 0x19;
  puVar3[1] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_8[4] & 1) << 0x1a;
  puVar3[1] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_8[8] & 1) << 0x1b;
  puVar3[1] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[1] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_8[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 7) = *(byte *)((int)puVar3 + 7) & 0x7f;
  puVar3[2] = puVar3[1];
  puVar3[3] = puVar3[1];
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_000817dc @ 0x817dc (524 bytes) */
int FUN_000817dc(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  byte *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  byte *param_8;
{
  uint uVar1;
  void *pvVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  size_t sVar12;
  uint uVar13;
  
  iVar4 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar4 + 1U) {
    sVar12 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar2 = _calloc(sVar12 + 0x200,1);
    if (sVar12 != 0) {
      _memcpy(pvVar2,*(void **)(param_1 + 0x3c8),sVar12);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar2;
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
    iVar4 = *(int *)(param_1 + 0x3cc);
  }
  puVar3 = (uint *)(iVar4 * 0x10 + *(int *)(param_1 + 0x3c8));
  *(uint **)(param_1 + 0x3dc) = puVar3;
  *(int *)(param_1 + 0x3cc) = iVar4 + 1;
  *puVar3 = 0;
  *(undefined1 *)puVar3 = 0x49;
  uVar13 = (param_2 & 0xf) << 8;
  uVar1 = *puVar3;
  uVar8 = (param_3 & 0x7f) << 0xd;
  *puVar3 = uVar1 & 0xfff010ff | uVar13 | uVar8;
  uVar5 = (*param_4 & 1) << 0x14;
  *puVar3 = uVar1 & 0xffe010ff | uVar13 | uVar8 | uVar5;
  uVar6 = (param_4[4] & 1) << 0x15;
  *puVar3 = uVar1 & 0xffc010ff | uVar13 | uVar8 | uVar5 | uVar6;
  uVar7 = (param_4[8] & 1) << 0x16;
  *puVar3 = uVar1 & 0xff8010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7;
  *puVar3 = uVar1 & 0xff0010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7 | (param_4[0xc] & 1) << 0x17
  ;
  puVar3[1] = puVar3[1] & 0xfffffff0 | param_5 & 0xf;
  *(byte *)(puVar3 + 1) = (byte)puVar3[1] & 0xef;
  uVar8 = (uint)param_6 << 5;
  uVar1 = puVar3[1];
  puVar3[1] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_7 & 7) << 0xd;
  puVar3[1] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_7[4] & 7) << 0x10;
  puVar3[1] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_7[8] & 7) << 0x13;
  puVar3[1] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_7[0xc] & 7) << 0x16;
  puVar3[1] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_8 & 1) << 0x19;
  puVar3[1] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_8[4] & 1) << 0x1a;
  puVar3[1] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_8[8] & 1) << 0x1b;
  puVar3[1] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[1] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_8[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 7) = *(byte *)((int)puVar3 + 7) & 0x7f;
  puVar3[2] = puVar3[1];
  puVar3[3] = puVar3[1];
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_000819e8 @ 0x819e8 (524 bytes) */
int FUN_000819e8(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  byte *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  byte *param_8;
{
  uint uVar1;
  void *pvVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  size_t sVar12;
  uint uVar13;
  
  iVar4 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar4 + 1U) {
    sVar12 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar2 = _calloc(sVar12 + 0x200,1);
    if (sVar12 != 0) {
      _memcpy(pvVar2,*(void **)(param_1 + 0x3c8),sVar12);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar2;
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
    iVar4 = *(int *)(param_1 + 0x3cc);
  }
  puVar3 = (uint *)(iVar4 * 0x10 + *(int *)(param_1 + 0x3c8));
  *(uint **)(param_1 + 0x3dc) = puVar3;
  *(int *)(param_1 + 0x3cc) = iVar4 + 1;
  *puVar3 = 0;
  *(undefined1 *)puVar3 = 0x4b;
  uVar13 = (param_2 & 0xf) << 8;
  uVar1 = *puVar3;
  uVar8 = (param_3 & 0x7f) << 0xd;
  *puVar3 = uVar1 & 0xfff010ff | uVar13 | uVar8;
  uVar5 = (*param_4 & 1) << 0x14;
  *puVar3 = uVar1 & 0xffe010ff | uVar13 | uVar8 | uVar5;
  uVar6 = (param_4[4] & 1) << 0x15;
  *puVar3 = uVar1 & 0xffc010ff | uVar13 | uVar8 | uVar5 | uVar6;
  uVar7 = (param_4[8] & 1) << 0x16;
  *puVar3 = uVar1 & 0xff8010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7;
  *puVar3 = uVar1 & 0xff0010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7 | (param_4[0xc] & 1) << 0x17
  ;
  puVar3[1] = puVar3[1] & 0xfffffff0 | param_5 & 0xf;
  *(byte *)(puVar3 + 1) = (byte)puVar3[1] & 0xef;
  uVar8 = (uint)param_6 << 5;
  uVar1 = puVar3[1];
  puVar3[1] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_7 & 7) << 0xd;
  puVar3[1] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_7[4] & 7) << 0x10;
  puVar3[1] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_7[8] & 7) << 0x13;
  puVar3[1] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_7[0xc] & 7) << 0x16;
  puVar3[1] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_8 & 1) << 0x19;
  puVar3[1] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_8[4] & 1) << 0x1a;
  puVar3[1] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_8[8] & 1) << 0x1b;
  puVar3[1] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[1] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_8[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 7) = *(byte *)((int)puVar3 + 7) & 0x7f;
  puVar3[2] = puVar3[1];
  puVar3[3] = puVar3[1];
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_00081bf4 @ 0x81bf4 (524 bytes) */
int FUN_00081bf4(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  byte *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  byte *param_8;
{
  uint uVar1;
  void *pvVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  size_t sVar12;
  uint uVar13;
  
  iVar4 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar4 + 1U) {
    sVar12 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar2 = _calloc(sVar12 + 0x200,1);
    if (sVar12 != 0) {
      _memcpy(pvVar2,*(void **)(param_1 + 0x3c8),sVar12);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar2;
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
    iVar4 = *(int *)(param_1 + 0x3cc);
  }
  puVar3 = (uint *)(iVar4 * 0x10 + *(int *)(param_1 + 0x3c8));
  *(uint **)(param_1 + 0x3dc) = puVar3;
  *(int *)(param_1 + 0x3cc) = iVar4 + 1;
  *puVar3 = 0;
  *(undefined1 *)puVar3 = 0x43;
  uVar13 = (param_2 & 0xf) << 8;
  uVar1 = *puVar3;
  uVar8 = (param_3 & 0x7f) << 0xd;
  *puVar3 = uVar1 & 0xfff010ff | uVar13 | uVar8;
  uVar5 = (*param_4 & 1) << 0x14;
  *puVar3 = uVar1 & 0xffe010ff | uVar13 | uVar8 | uVar5;
  uVar6 = (param_4[4] & 1) << 0x15;
  *puVar3 = uVar1 & 0xffc010ff | uVar13 | uVar8 | uVar5 | uVar6;
  uVar7 = (param_4[8] & 1) << 0x16;
  *puVar3 = uVar1 & 0xff8010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7;
  *puVar3 = uVar1 & 0xff0010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7 | (param_4[0xc] & 1) << 0x17
  ;
  puVar3[1] = puVar3[1] & 0xfffffff0 | param_5 & 0xf;
  *(byte *)(puVar3 + 1) = (byte)puVar3[1] & 0xef;
  uVar8 = (uint)param_6 << 5;
  uVar1 = puVar3[1];
  puVar3[1] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_7 & 7) << 0xd;
  puVar3[1] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_7[4] & 7) << 0x10;
  puVar3[1] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_7[8] & 7) << 0x13;
  puVar3[1] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_7[0xc] & 7) << 0x16;
  puVar3[1] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_8 & 1) << 0x19;
  puVar3[1] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_8[4] & 1) << 0x1a;
  puVar3[1] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_8[8] & 1) << 0x1b;
  puVar3[1] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[1] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_8[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 7) = *(byte *)((int)puVar3 + 7) & 0x7f;
  puVar3[2] = puVar3[1];
  puVar3[3] = puVar3[1];
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_00081e00 @ 0x81e00 (727 bytes) */
int FUN_00081e00(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  uint param_2;
  uint param_3;
  byte *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  byte *param_8;
  uint param_9;
  int param_10;
  byte *param_11;
  byte *param_12;
{
  uint uVar1;
  void *pvVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  size_t sVar12;
  uint uVar13;
  
  iVar4 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar4 + 1U) {
    sVar12 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar2 = _calloc(sVar12 + 0x200,1);
    if (sVar12 != 0) {
      _memcpy(pvVar2,*(void **)(param_1 + 0x3c8),sVar12);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar2;
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
    iVar4 = *(int *)(param_1 + 0x3cc);
  }
  puVar3 = (uint *)(iVar4 * 0x10 + *(int *)(param_1 + 0x3c8));
  *(uint **)(param_1 + 0x3dc) = puVar3;
  *(int *)(param_1 + 0x3cc) = iVar4 + 1;
  *puVar3 = 0;
  *(undefined1 *)puVar3 = 0x45;
  uVar13 = (param_2 & 0xf) << 8;
  uVar1 = *puVar3;
  uVar8 = (param_3 & 0x7f) << 0xd;
  *puVar3 = uVar1 & 0xfff010ff | uVar13 | uVar8;
  uVar5 = (*param_4 & 1) << 0x14;
  *puVar3 = uVar1 & 0xffe010ff | uVar13 | uVar8 | uVar5;
  uVar6 = (param_4[4] & 1) << 0x15;
  *puVar3 = uVar1 & 0xffc010ff | uVar13 | uVar8 | uVar5 | uVar6;
  uVar7 = (param_4[8] & 1) << 0x16;
  *puVar3 = uVar1 & 0xff8010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7;
  *puVar3 = uVar1 & 0xff0010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7 | (param_4[0xc] & 1) << 0x17
  ;
  puVar3[1] = puVar3[1] & 0xfffffff0 | param_5 & 0xf;
  *(byte *)(puVar3 + 1) = (byte)puVar3[1] & 0xef;
  uVar8 = (uint)param_6 << 5;
  uVar1 = puVar3[1];
  puVar3[1] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_7 & 7) << 0xd;
  puVar3[1] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_7[4] & 7) << 0x10;
  puVar3[1] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_7[8] & 7) << 0x13;
  puVar3[1] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_7[0xc] & 7) << 0x16;
  puVar3[1] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_8 & 1) << 0x19;
  puVar3[1] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_8[4] & 1) << 0x1a;
  puVar3[1] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_8[8] & 1) << 0x1b;
  puVar3[1] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[1] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_8[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 7) = *(byte *)((int)puVar3 + 7) & 0x7f;
  puVar3[2] = puVar3[2] & 0xfffffff0 | param_9 & 0xf;
  *(byte *)(puVar3 + 2) = (byte)puVar3[2] & 0xef;
  uVar8 = (uint)param_10 << 5;
  uVar1 = puVar3[2];
  puVar3[2] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_11 & 7) << 0xd;
  puVar3[2] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_11[4] & 7) << 0x10;
  puVar3[2] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_11[8] & 7) << 0x13;
  puVar3[2] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_11[0xc] & 7) << 0x16;
  puVar3[2] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_12 & 1) << 0x19;
  puVar3[2] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_12[4] & 1) << 0x1a;
  puVar3[2] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_12[8] & 1) << 0x1b;
  puVar3[2] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[2] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_12[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)puVar3 + 0xb) & 0x7f;
  puVar3[3] = puVar3[2];
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_000820d7 @ 0x820d7 (727 bytes) */
int FUN_000820d7(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  uint param_2;
  uint param_3;
  byte *param_4;
  uint param_5;
  int param_6;
  byte *param_7;
  byte *param_8;
  uint param_9;
  int param_10;
  byte *param_11;
  byte *param_12;
{
  uint uVar1;
  void *pvVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  size_t sVar12;
  uint uVar13;
  
  iVar4 = *(int *)(param_1 + 0x3cc);
  if (*(uint *)(param_1 + 0x3e0) < iVar4 + 1U) {
    sVar12 = *(uint *)(param_1 + 0x3e0) * 0x10;
    pvVar2 = _calloc(sVar12 + 0x200,1);
    if (sVar12 != 0) {
      _memcpy(pvVar2,*(void **)(param_1 + 0x3c8),sVar12);
      _free(*(void **)(param_1 + 0x3c8));
    }
    *(void **)(param_1 + 0x3c8) = pvVar2;
    *(int *)(param_1 + 0x3e0) = *(int *)(param_1 + 0x3e0) + 0x20;
    iVar4 = *(int *)(param_1 + 0x3cc);
  }
  puVar3 = (uint *)(iVar4 * 0x10 + *(int *)(param_1 + 0x3c8));
  *(uint **)(param_1 + 0x3dc) = puVar3;
  *(int *)(param_1 + 0x3cc) = iVar4 + 1;
  *puVar3 = 0;
  *(undefined1 *)puVar3 = 0x4f;
  uVar13 = (param_2 & 0xf) << 8;
  uVar1 = *puVar3;
  uVar8 = (param_3 & 0x7f) << 0xd;
  *puVar3 = uVar1 & 0xfff010ff | uVar13 | uVar8;
  uVar5 = (*param_4 & 1) << 0x14;
  *puVar3 = uVar1 & 0xffe010ff | uVar13 | uVar8 | uVar5;
  uVar6 = (param_4[4] & 1) << 0x15;
  *puVar3 = uVar1 & 0xffc010ff | uVar13 | uVar8 | uVar5 | uVar6;
  uVar7 = (param_4[8] & 1) << 0x16;
  *puVar3 = uVar1 & 0xff8010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7;
  *puVar3 = uVar1 & 0xff0010ff | uVar13 | uVar8 | uVar5 | uVar6 | uVar7 | (param_4[0xc] & 1) << 0x17
  ;
  puVar3[1] = puVar3[1] & 0xfffffff0 | param_5 & 0xf;
  *(byte *)(puVar3 + 1) = (byte)puVar3[1] & 0xef;
  uVar8 = (uint)param_6 << 5;
  uVar1 = puVar3[1];
  puVar3[1] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_7 & 7) << 0xd;
  puVar3[1] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_7[4] & 7) << 0x10;
  puVar3[1] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_7[8] & 7) << 0x13;
  puVar3[1] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_7[0xc] & 7) << 0x16;
  puVar3[1] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_8 & 1) << 0x19;
  puVar3[1] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_8[4] & 1) << 0x1a;
  puVar3[1] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_8[8] & 1) << 0x1b;
  puVar3[1] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[1] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_8[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 7) = *(byte *)((int)puVar3 + 7) & 0x7f;
  puVar3[2] = puVar3[2] & 0xfffffff0 | param_9 & 0xf;
  *(byte *)(puVar3 + 2) = (byte)puVar3[2] & 0xef;
  uVar8 = (uint)param_10 << 5;
  uVar1 = puVar3[2];
  puVar3[2] = uVar1 & 0xffffe01f | uVar8;
  uVar5 = (*param_11 & 7) << 0xd;
  puVar3[2] = uVar1 & 0xffff001f | uVar8 | uVar5;
  uVar6 = (param_11[4] & 7) << 0x10;
  puVar3[2] = uVar1 & 0xfff8001f | uVar8 | uVar5 | uVar6;
  uVar7 = (param_11[8] & 7) << 0x13;
  puVar3[2] = uVar1 & 0xffc0001f | uVar8 | uVar5 | uVar6 | uVar7;
  uVar13 = (param_11[0xc] & 7) << 0x16;
  puVar3[2] = uVar1 & 0xfe00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13;
  uVar9 = (*param_12 & 1) << 0x19;
  puVar3[2] = uVar1 & 0xfc00001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9;
  uVar10 = (param_12[4] & 1) << 0x1a;
  puVar3[2] = uVar1 & 0xf800001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10;
  uVar11 = (param_12[8] & 1) << 0x1b;
  puVar3[2] = uVar1 & 0xf000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11;
  puVar3[2] = uVar1 & 0x8000001f | uVar8 | uVar5 | uVar6 | uVar7 | uVar13 | uVar9 | uVar10 | uVar11
              | (param_12[0xc] & 1) << 0x1c;
  *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)puVar3 + 0xb) & 0x7f;
  puVar3[3] = puVar3[2];
  *(int *)(param_1 + 0x3dc) = *(int *)(param_1 + 0x3dc) + 0x10;
  return;
}

/* FUN_000823ae @ 0x823ae (125 bytes) */
int FUN_000823ae(param_1)
  int param_1;
{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,7);
  *(undefined4 **)(param_1 + 0x274c) = puVar1;
  *puVar1 = 0x880;
  puVar1[1] = *(undefined4 *)(param_1 + 0x244c);
  puVar1[2] = 0x38882;
  puVar1[3] = *(undefined4 *)(param_1 + 400);
  puVar1[4] = *(undefined4 *)(param_1 + 0x194);
  puVar1[5] = *(undefined4 *)(param_1 + 0xf0);
  puVar1[6] = *(undefined4 *)(param_1 + 0x198);
  iVar2 = *(int *)(param_1 + 0x274c) + 0x1c;
  *(int *)(param_1 + 0x274c) = iVar2;
  (**(code **)(param_1 + 0x275c))(param_1,iVar2);
  return;
}

/* FUN_0008242b @ 0x8242b (127 bytes) */
int FUN_0008242b(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = *(uint *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + 0x3e28);
  iVar3 = 0;
  uVar4 = *(uint *)(param_1 + 0x1930);
  do {
    if (((int)(uint)*(ushort *)(param_1 + 0x36) >> ((byte)iVar3 & 0x1f) & 1U) != 0) {
      uVar2 = 1 << ((byte)iVar3 & 0x1f);
      if ((uVar1 & uVar2) == 0) {
        *(uint *)(param_1 + 0x1b74) = *(uint *)(param_1 + 0x1b74) & ~uVar2;
      }
      else {
        *(uint *)(param_1 + 0x1b74) = *(uint *)(param_1 + 0x1b74) | uVar2;
        uVar4 = uVar4 | 0x1000000;
        *(uint *)(param_1 + 0x1930) = uVar4;
      }
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 6);
  *(uint *)(param_1 + 0x1930) = uVar4 | 0x400000;
  *(undefined2 *)(param_1 + 0x36) = 0;
  return;
}

/* FUN_000824aa @ 0x824aa (193 bytes) */
int FUN_000824aa(param_1)
  int param_1;
{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  uVar1 = *(uint *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + 0x3e28);
  puVar4 = (undefined4 *)(param_1 + 0x3d8);
  iVar5 = 0;
  do {
    while ((uVar1 & 1 << ((byte)iVar5 & 0x1f)) != 0) {
      puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,7);
      *(undefined4 **)(param_1 + 0x274c) = puVar2;
      *puVar2 = 0x880;
      puVar2[1] = iVar5 + *(int *)(param_1 + 0x1be0);
      puVar2[2] = 0x38882;
      puVar2[3] = *puVar4;
      puVar2[4] = puVar4[1];
      puVar2[5] = puVar4[2];
      puVar2[6] = puVar4[3];
      iVar3 = *(int *)(param_1 + 0x274c) + 0x1c;
      *(int *)(param_1 + 0x274c) = iVar3;
      (**(code **)(param_1 + 0x275c))(param_1,iVar3);
      iVar5 = iVar5 + 1;
      puVar4 = puVar4 + 4;
      if (iVar5 == 6) {
        return;
      }
    }
    iVar5 = iVar5 + 1;
    puVar4 = puVar4 + 4;
  } while (iVar5 != 6);
  return;
}

/* FUN_0008256b @ 0x8256b (161 bytes) */
int FUN_0008256b(int param_1,float param_2,float param_3)

{
  int iVar1;
  float fVar2;
  
  fVar2 = (float)*(uint *)(param_1 + 0x284c) * FLOAT_001c5c28 + param_3 + param_2;
  if ((fVar2 == FLOAT_001c5b9c) && (!NAN(fVar2) && !NAN(FLOAT_001c5b9c))) {
    return 0;
  }
  if ((fVar2 == FLOAT_001c5c2c) && (!NAN(fVar2) && !NAN(FLOAT_001c5c2c))) {
    return -0x10;
  }
  if ((FLOAT_001c5c30 <= fVar2) || (NAN(fVar2) || NAN(FLOAT_001c5c30))) {
    if (FLOAT_001c5c38 < fVar2) {
      iVar1 = (int)FLOAT_001c5c3c;
    }
    else {
      iVar1 = (int)(fVar2 * FLOAT_001c5bc0);
    }
  }
  else {
    iVar1 = (int)FLOAT_001c5c34;
  }
  return iVar1;
}

/* FUN_0008260c @ 0x8260c (87 bytes) */
int FUN_0008260c(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  undefined4 *param_3;
{
  undefined2 uVar1;
  
  if (param_3 != (undefined4 *)0x0) {
    uVar1 = ((int (*)())FUN_0008256b)(param_1,*(undefined4 *)(param_2 + 0x20),*param_3);
    *(undefined2 *)(param_2 + 0x1e) = uVar1;
    return;
  }
  uVar1 = ((int (*)())FUN_0008256b)(param_1,*(undefined4 *)(param_2 + 0x20),0);
  *(undefined2 *)(param_2 + 0x1e) = uVar1;
  return;
}

/* FUN_00082663 @ 0x82663 (329 bytes) */
int FUN_00082663(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *param_2 = *(undefined4 *)(param_1 + 0x1b74);
  param_2[1] = *(undefined4 *)(param_1 + 0x1b84);
  param_2[2] = *(undefined4 *)(param_1 + 0x1b30);
  param_2[3] = *(undefined4 *)(param_1 + 0x1aa0);
  param_2[4] = *(undefined4 *)(param_1 + 0x1ab0);
  param_2[5] = *(undefined4 *)(param_1 + 0x1aa4);
  param_2[6] = *(undefined4 *)(param_1 + 0x1aa8);
  param_2[8] = *(undefined4 *)(param_1 + 0x1ab8);
  param_2[9] = *(undefined4 *)(param_1 + 0x1aec);
  param_2[10] = *(undefined4 *)(param_1 + 0x1a4c);
  param_2[0xb] = *(undefined4 *)(param_1 + 0x1a50);
  param_2[0xc] = *(undefined4 *)(param_1 + 0x1a80);
  param_2[0xd] = *(undefined4 *)(param_1 + 0x1af8);
  param_2[0xe] = *(undefined4 *)(param_1 + 0x1b9c);
  param_2[0xf] = *(undefined4 *)(param_1 + 0x1ba0);
  param_2[0x10] = *(undefined4 *)(param_1 + 0x248c);
  param_2[0x11] = **(undefined4 **)(param_1 + 0x2440);
  param_2[0x12] = **(undefined4 **)(param_1 + 0x2444);
  param_2[0x15] = *(undefined4 *)(param_1 + 0x1ae0);
  param_2[0x13] = *(undefined4 *)(param_1 + 7000);
  param_2[0x14] = *(undefined4 *)(param_1 + 0x1b10);
  param_2[0x16] = *(undefined4 *)(param_1 + 0x1b3c);
  param_2[0x17] = *(undefined4 *)(param_1 + 0x1af4);
  param_2[0x18] = *(undefined4 *)(param_1 + 0x1b50);
  param_2[0x19] = *(undefined4 *)(param_1 + 0x1f2c);
  param_2[0x1a] = *(undefined4 *)(param_1 + 0x1a60);
  param_2[0x1b] = *(undefined4 *)(param_1 + 0x1a68);
  param_2[0x1c] = *(undefined4 *)(param_1 + 0x1a6c);
  param_2[0x1d] = *(undefined4 *)(param_1 + 0x1b60);
  param_2[0x1e] = *(undefined4 *)(param_1 + 0x23e0);
  param_2[0x1f] = *(undefined4 *)(param_1 + 0x1c8c);
  param_2[0x20] = *(undefined4 *)(param_1 + 0x1c94);
  param_2[0x21] = *(undefined4 *)(param_1 + 0x1bc0);
  param_2[0x22] = *(undefined4 *)(param_1 + 0x1bb0);
  return;
}

/* FUN_000827ac @ 0x827ac (1735 bytes) */
int FUN_000827ac(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  undefined4 *puVar5;
  byte bVar6;
  byte local_28;
  undefined4 *local_20;
  
  ((int (*)())FUN_00082663)(param_1,param_5);
  *(byte *)(param_1 + 0x1b76) = *(byte *)(param_1 + 0x1b76) | 1;
  *(byte *)(param_1 + 0x1b75) = *(byte *)(param_1 + 0x1b75) | 0xc0;
  *(undefined4 *)(param_1 + 0x23e0) = 0;
  *(byte *)(param_1 + 0x1b84) = *(byte *)(param_1 + 0x1b84) & 0xc5 | 5;
  *(undefined4 *)(param_1 + 0x1c8c) = *(undefined4 *)(param_1 + 0x2814);
  *(undefined4 *)(param_1 + 0x1c94) = *(undefined4 *)(param_1 + 0x2818);
  *(undefined4 *)(param_1 + 0x1aa0) = 0;
  local_28 = (byte)param_3;
  *(byte *)(param_1 + 0x1aa0) =
       *(byte *)(param_1 + 0x1aa0) & 0xf8 | (local_28 & 1) * '\x04' | (local_28 & 1) * '\x02' |
       (byte)param_4 & 1;
  if (param_3 == 0) {
    bVar6 = *(byte *)(param_1 + 0x1aa4) & 0xf8;
    *(byte *)(param_1 + 0x1aa4) = bVar6;
  }
  else {
    bVar6 = *(byte *)(param_1 + 0x1aa4) | 7;
    *(byte *)(param_1 + 0x1aa4) = bVar6;
  }
  if (param_4 == 0) {
    *(byte *)(param_1 + 0x1aa4) = bVar6 & 199;
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x10);
    *(byte *)(param_1 + 0x1aa4) = bVar6 | 0x38;
    *(byte *)(param_1 + 0x1aa5) = *(byte *)(param_1 + 0x1aa5) & 0xf1 | 4;
    *(uint *)(param_1 + 0x1aa4) = *(uint *)(param_1 + 0x1aa4) | 0x38000;
    *(byte *)(param_1 + 0x1aa6) = *(byte *)(param_1 + 0x1aa6) & 0x1f | 0x40;
    *(char *)(param_1 + 0x1aa8) = (char)*(undefined4 *)(iVar2 + 0x2db4);
    *(char *)(param_1 + 0x1aaa) = (char)*(undefined4 *)(iVar2 + 0x2e38);
  }
  *(undefined4 *)(param_1 + 0x1a80) = 0;
  *(byte *)(param_1 + 0x1a81) = *(byte *)(param_1 + 0x1a81) & 0x8f;
  *(byte *)(param_1 + 0x1a82) = *(byte *)(param_1 + 0x1a82) & 0xc0 | 0x20;
  *(byte *)(param_1 + 0x1a83) = *(byte *)(param_1 + 0x1a83) & 0xc0 | 0x20;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xfffffff0 | 3;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xffffff0f;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xffffe0ff;
  pbVar1 = (byte *)(*(int *)(param_1 + 0x2440) + 1);
  *pbVar1 = *pbVar1 & 0xdf;
  pbVar1 = (byte *)(*(int *)(param_1 + 0x2440) + 1);
  *pbVar1 = *pbVar1 & 0xbf;
  pbVar1 = (byte *)(*(int *)(param_1 + 0x2440) + 1);
  *pbVar1 = *pbVar1 & 0x7f;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xfff0ffff | 0x30000;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xff0fffff;
  **(uint **)(param_1 + 0x2440) = **(uint **)(param_1 + 0x2440) & 0xe0ffffff | 0x1000000;
  pbVar1 = (byte *)(*(int *)(param_1 + 0x2440) + 3);
  *pbVar1 = *pbVar1 | 0x20;
  pbVar1 = (byte *)(*(int *)(param_1 + 0x2440) + 3);
  *pbVar1 = *pbVar1 & 0xbf;
  pbVar1 = (byte *)(*(int *)(param_1 + 0x2440) + 3);
  *pbVar1 = *pbVar1 & 0x7f;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfffffff8;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xffffffc7 | 8;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfffffe3f | 0x80;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfffff1ff | 0x600;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) | 0xf000;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfff8ffff;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xffc7ffff | 0x80000;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xfe3fffff | 0x800000;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) & 0xf1ffffff | 0x6000000;
  **(uint **)(param_1 + 0x2444) = **(uint **)(param_1 + 0x2444) | 0xf0000000;
  *(ushort *)(param_1 + 7000) = *(ushort *)(param_1 + 7000) & 0xe000;
  *(uint *)(param_1 + 7000) = *(uint *)(param_1 + 7000) & 0xfc001fff;
  *(ushort *)(param_1 + 0x1b10) =
       *(ushort *)(param_1 + 0x1b10) & 0xe000 |
       (ushort)(int)((float)*(int *)(*(int *)(param_1 + 4) + 0x15c) * *(float *)(param_1 + 0x2814) +
                    0.0) & 0x1fff;
  *(uint *)(param_1 + 0x1b10) =
       *(uint *)(param_1 + 0x1b10) & 0xfc001fff |
       ((int)((float)*(int *)(*(int *)(param_1 + 4) + 0x160) * *(float *)(param_1 + 0x2818) + 0.0) &
       0x1fffU) << 0xd;
  *(undefined4 *)(param_1 + 0x1b30) = 0;
  *(undefined4 *)(param_1 + 0x1aec) = 0;
  *(undefined4 *)(param_1 + 0x1a4c) = 0;
  *(undefined4 *)(param_1 + 0x1a50) = 0;
  *(undefined4 *)(param_1 + 0x1af8) = 0;
  *(undefined4 *)(param_1 + 0x1b9c) = 3;
  *(undefined4 *)(param_1 + 0x1ba0) = 0;
  *(undefined4 *)(param_1 + 0x1bb0) = 0;
  *(undefined4 *)(param_1 + 0x248c) = 8;
  *(undefined4 *)(param_1 + 0x1b60) = 0xffffff;
  *(uint *)(param_1 + 0x1b50) = (uint)*(ushort *)(param_1 + 0x1b50);
  *(undefined4 *)(param_1 + 0x1bc0) = 0;
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x1af4) = 0;
  }
  *(undefined4 *)(param_1 + 0x1b3c) = 0;
  *(byte *)(param_1 + 0x1b3c) = *(byte *)(param_1 + 0x1b3c) & 0xfc;
  uVar3 = *(undefined4 *)(param_1 + 0x1930);
  FUN_0004a17c(param_1,*(uint *)(param_1 + 0x18a4) >> 6 & 0xffff);
  *(byte *)(param_1 + 0x1f2c) = *(byte *)(param_1 + 0x1f2c) & 0x80;
  *(ushort *)(param_1 + 0x1f2c) = *(ushort *)(param_1 + 0x1f2c) & 0xf87f | 0x80;
  (**(code **)(param_1 + 0x1330))(param_1,0xc0100000);
  *(undefined4 *)(param_1 + 0x1930) = uVar3;
  if (param_3 != 0) {
    *(byte *)(param_1 + 0x1ae0) = *(byte *)(param_1 + 0x1ae0) & 0xfe;
    *(byte *)(param_1 + 0x1ab0) = *(byte *)(param_1 + 0x1ab0) & 0xfe;
  }
  puVar5 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x3d);
  *(undefined4 **)(param_1 + 0x274c) = puVar5;
  *puVar5 = 0x887;
  puVar5[1] = *(undefined4 *)(param_1 + 0x1b74);
  puVar5[2] = 0x82c;
  puVar5[3] = *(undefined4 *)(param_1 + 0x1b84);
  puVar5[4] = 0x10ae;
  puVar5[5] = *(undefined4 *)(param_1 + 0x1b30);
  puVar5[6] = &switchdataD_000013c0;
  puVar5[7] = *(undefined4 *)(param_1 + 0x1aa0);
  puVar5[8] = 0x13c1;
  puVar5[9] = *(undefined4 *)(param_1 + 0x1aa4);
  puVar5[10] = 0x13c2;
  puVar5[0xb] = *(undefined4 *)(param_1 + 0x1aa8);
  puVar5[0xc] = 0x12f0;
  puVar5[0xd] = *(undefined4 *)(param_1 + 0x1aec);
  puVar5[0xe] = 0x12f5;
  puVar5[0xf] = *(undefined4 *)(param_1 + 0x1a4c);
  puVar5[0x10] = 0x12f6;
  puVar5[0x11] = *(undefined4 *)(param_1 + 0x1a50);
  puVar5[0x12] = 0x1381;
  puVar5[0x13] = *(undefined4 *)(param_1 + 0x1a80);
  puVar5[0x14] = 0x1386;
  puVar5[0x15] = *(undefined4 *)(param_1 + 0x1af8);
  puVar5[0x16] = 0x824;
  puVar5[0x17] = *(undefined4 *)(param_1 + 0x1b9c);
  puVar5[0x18] = 0x825;
  puVar5[0x19] = *(undefined4 *)(param_1 + 0x1ba0);
  puVar5[0x1a] = 0x82d;
  puVar5[0x1b] = *(undefined4 *)(param_1 + 0x248c);
  puVar5[0x1c] = 0x854;
  puVar5[0x1d] = **(undefined4 **)(param_1 + 0x2440);
  puVar5[0x1e] = 0x878;
  puVar5[0x1f] = **(undefined4 **)(param_1 + 0x2444);
  puVar5[0x20] = 0x10f8;
  puVar5[0x21] = *(undefined4 *)(param_1 + 7000);
  puVar5[0x22] = 0x10f9;
  puVar5[0x23] = *(undefined4 *)(param_1 + 0x1b10);
  puVar5[0x24] = 0x10a2;
  puVar5[0x25] = *(undefined4 *)(param_1 + 0x1b3c);
  puVar5[0x26] = 0x1383;
  puVar5[0x27] = *(undefined4 *)(param_1 + 0x1af4);
  puVar5[0x28] = 0x1002;
  puVar5[0x29] = *(undefined4 *)(param_1 + 0x1b50);
  puVar5[0x2a] = 0x10c0;
  puVar5[0x2b] = *(undefined4 *)(param_1 + 0x1f2c);
  puVar5[0x2c] = 0x825;
  puVar5[0x2d] = *(undefined4 *)(param_1 + 0x1ba0);
  puVar5[0x2e] = 0x766;
  puVar5[0x2f] = *(undefined4 *)(param_1 + 0x1c8c);
  puVar5[0x30] = 0x768;
  puVar5[0x31] = *(undefined4 *)(param_1 + 0x1c94);
  puVar5[0x32] = 0x10fa;
  puVar5[0x33] = *(undefined4 *)(param_1 + 0x1b60);
  local_20 = puVar5 + 0x34;
  if (param_3 != 0) {
    iVar2 = *(int *)(param_1 + 4);
    puVar4 = *(uint **)(iVar2 + 0x1d8);
    *puVar4 = *puVar4 | (int)local_20 - (int)puVar4 >> 2;
    *(undefined4 **)(iVar2 + 0x1d8) = local_20;
    puVar5[0x34] = 0x2f000000;
    puVar5[0x35] = 0x10e9;
    puVar5[0x36] = *(undefined4 *)(param_1 + 0x1ae0);
    puVar5[0x37] = 0x13c7;
    puVar5[0x38] = *(undefined4 *)(param_1 + 0x1ab0);
    local_20 = puVar5 + 0x39;
  }
  *local_20 = 0x1048;
  local_20[1] = *(undefined4 *)(param_1 + 0x1bc0);
  local_20[2] = 0x1047;
  local_20[3] = *(undefined4 *)(param_1 + 0x1bb0);
  *(undefined4 **)(param_1 + 0x274c) = local_20 + 4;
                    
                    
  (**(code **)(param_1 + 0x275c))();
  return;
}

/* FUN_00082e73 @ 0x82e73 (1362 bytes) */
int FUN_00082e73(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  undefined *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  *(undefined4 *)(param_1 + 0x1b74) = *param_2;
  *(undefined4 *)(param_1 + 0x1b84) = param_2[1];
  *(undefined4 *)(param_1 + 0x1b30) = param_2[2];
  *(undefined4 *)(param_1 + 0x1aa0) = param_2[3];
  *(undefined4 *)(param_1 + 0x1ab0) = param_2[4];
  *(undefined4 *)(param_1 + 0x1aa4) = param_2[5];
  *(undefined4 *)(param_1 + 0x1aa8) = param_2[6];
  *(undefined4 *)(param_1 + 0x1ab8) = param_2[8];
  *(undefined4 *)(param_1 + 0x1aec) = param_2[9];
  *(undefined4 *)(param_1 + 0x1a4c) = param_2[10];
  *(undefined4 *)(param_1 + 0x1a50) = param_2[0xb];
  *(undefined4 *)(param_1 + 0x1a80) = param_2[0xc];
  *(undefined4 *)(param_1 + 0x1af8) = param_2[0xd];
  *(undefined4 *)(param_1 + 0x1b9c) = param_2[0xe];
  *(undefined4 *)(param_1 + 0x1ba0) = param_2[0xf];
  *(undefined4 *)(param_1 + 0x248c) = param_2[0x10];
  **(undefined4 **)(param_1 + 0x2440) = param_2[0x11];
  **(undefined4 **)(param_1 + 0x2444) = param_2[0x12];
  *(undefined4 *)(param_1 + 0x1ae0) = param_2[0x15];
  *(undefined4 *)(param_1 + 7000) = param_2[0x13];
  *(undefined4 *)(param_1 + 0x1b10) = param_2[0x14];
  *(undefined4 *)(param_1 + 0x1b3c) = param_2[0x16];
  *(undefined4 *)(param_1 + 0x1af4) = param_2[0x17];
  *(undefined4 *)(param_1 + 0x1b50) = param_2[0x18];
  *(undefined4 *)(param_1 + 0x1f2c) = param_2[0x19];
  *(undefined4 *)(param_1 + 0x1a60) = param_2[0x1a];
  *(undefined4 *)(param_1 + 0x1a68) = param_2[0x1b];
  *(undefined4 *)(param_1 + 0x1a6c) = param_2[0x1c];
  *(undefined4 *)(param_1 + 0x1b60) = param_2[0x1d];
  *(undefined4 *)(param_1 + 0x23e0) = param_2[0x1e];
  *(undefined4 *)(param_1 + 0x1c8c) = param_2[0x1f];
  *(undefined4 *)(param_1 + 0x1c94) = param_2[0x20];
  *(undefined4 *)(param_1 + 0x1bc0) = param_2[0x21];
  *(undefined4 *)(param_1 + 0x1bb0) = param_2[0x22];
  (**(code **)(param_1 + 0x1334))(param_1,0);
  if (((*(byte *)(param_1 + 0x45) & 0x40) != 0) &&
     (puVar6 = *(undefined4 **)(param_1 + 0x1e70), puVar6 != (undefined4 *)0x0)) {
    if ((*(byte *)(param_1 + 0x46) & 4) == 0) {
      cVar1 = *(char *)(param_1 + 0x1136);
    }
    else {
      cVar1 = *(char *)(param_1 + 0x11d0);
    }
    if (cVar1 == '\0') goto LAB_0008300b;
  }
  puVar6 = *(undefined4 **)(param_1 + 0x1e5c);
LAB_0008300b:
  *(undefined1 *)((int)puVar6 + 0x10ef) = 0;
  if (*(int *)(param_1 + 0x23e0) == 0) {
    puVar6[0x4c1] = 0;
    *puVar6 = 0;
  }
  else {
    puVar6[0x54c] = 0;
    puVar6[7] = 0;
  }
  FUN_000495f8(param_1);
  (**(code **)(param_1 + 0x1330))(param_1,0xc0100000);
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) & 0x3fefffff;
  puVar6 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x55);
  *(undefined4 **)(param_1 + 0x274c) = puVar6;
  *puVar6 = 0x887;
  puVar6[1] = *(undefined4 *)(param_1 + 0x1b74);
  puVar6[2] = 0x82c;
  puVar6[3] = *(undefined4 *)(param_1 + 0x1b84);
  puVar6[4] = 0x10ae;
  puVar6[5] = *(undefined4 *)(param_1 + 0x1b30);
  puVar6[6] = &switchdataD_000013c0;
  puVar6[7] = *(undefined4 *)(param_1 + 0x1aa0);
  puVar6[8] = 0x13c1;
  puVar6[9] = *(undefined4 *)(param_1 + 0x1aa4);
  puVar6[10] = 0x13c2;
  puVar6[0xb] = *(undefined4 *)(param_1 + 0x1aa8);
  puVar6[0xc] = 0x12f0;
  uVar2 = *(uint *)(param_1 + 0x1aec);
  puVar6[0xd] = uVar2;
  puVar5 = PTR_DAT_002131c9;
  if ((PTR_DAT_002131c9[(uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x1a] & 1) == 0) {
    puVar6[0xd] = uVar2 & 0xfffffffe;
  }
  puVar6[0xe] = 0x12f5;
  uVar2 = *(uint *)(param_1 + 0x1a4c);
  puVar6[0xf] = uVar2;
  if ((puVar5[(uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x1a] & 1) == 0) {
    puVar6[0xf] = uVar2 & 0xfffff7ff;
  }
  puVar6[0x10] = 0x12f6;
  puVar6[0x11] = *(undefined4 *)(param_1 + 0x1a50);
  puVar6[0x12] = 0x1381;
  uVar2 = *(uint *)(param_1 + 0x1a80);
  puVar6[0x13] = uVar2;
  if ((puVar5[(uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x1a] & 2) == 0) {
    puVar6[0x13] = uVar2 & 0xfffffffc;
  }
  puVar6[0x14] = 0x1386;
  puVar6[0x15] = *(undefined4 *)(param_1 + 0x1af8);
  puVar6[0x16] = 0x824;
  puVar6[0x17] = *(undefined4 *)(param_1 + 0x1b9c);
  puVar6[0x18] = 0x825;
  puVar6[0x19] = *(undefined4 *)(param_1 + 0x1ba0);
  puVar6[0x1a] = 0x82d;
  puVar6[0x1b] = *(undefined4 *)(param_1 + 0x248c);
  puVar6[0x1c] = 0x854;
  puVar6[0x1d] = **(undefined4 **)(param_1 + 0x2440);
  puVar6[0x1e] = 0x878;
  puVar6[0x1f] = **(undefined4 **)(param_1 + 0x2444);
  puVar6[0x20] = 0x10a2;
  puVar6[0x21] = *(undefined4 *)(param_1 + 0x1b3c);
  puVar6[0x22] = 0x1383;
  puVar6[0x23] = *(undefined4 *)(param_1 + 0x1af4);
  puVar6[0x24] = 0x1002;
  puVar6[0x25] = *(undefined4 *)(param_1 + 0x1b50);
  puVar6[0x26] = 0x10c0;
  puVar6[0x27] = *(undefined4 *)(param_1 + 0x1f2c);
  puVar6[0x28] = 0x825;
  puVar6[0x29] = *(undefined4 *)(param_1 + 0x1ba0);
  puVar6[0x2a] = 0x1008;
  puVar6[0x2b] = *(undefined4 *)(param_1 + 0x1a60);
  puVar6[0x2c] = 0x1004;
  puVar6[0x2d] = *(undefined4 *)(param_1 + 0x1a68);
  puVar6[0x2e] = 0x1005;
  puVar6[0x2f] = *(undefined4 *)(param_1 + 0x1a6c);
  puVar6[0x30] = 0x10fa;
  puVar6[0x31] = *(undefined4 *)(param_1 + 0x1b60);
  puVar6[0x32] = 0x13c5;
  puVar6[0x33] = *(undefined4 *)(param_1 + 0x1ab8);
  puVar7 = puVar6 + 0x34;
  if ((*(byte *)(param_1 + 0x2454) & 0x10) != 0) {
    puVar6[0x34] = 0x13c5;
    puVar6[0x35] = *(undefined4 *)(param_1 + 0x1ab8);
    puVar7 = puVar6 + 0x36;
  }
  puVar6 = (undefined4 *)FUN_0004c95e(param_1,puVar7);
  *puVar6 = 0x766;
  puVar6[1] = *(undefined4 *)(param_1 + 0x1c8c);
  puVar6[2] = 0x768;
  puVar6[3] = *(undefined4 *)(param_1 + 0x1c94);
  puVar6[4] = 0x10fa;
  puVar6[5] = *(undefined4 *)(param_1 + 0x1b60);
  iVar3 = *(int *)(param_1 + 4);
  puVar4 = *(uint **)(iVar3 + 0x1d8);
  *puVar4 = *puVar4 | (int)(puVar6 + 6) - (int)puVar4 >> 2;
  *(undefined4 **)(iVar3 + 0x1d8) = puVar6 + 6;
  puVar6[6] = 0x2f000000;
  puVar6[7] = 0x10e9;
  puVar6[8] = *(undefined4 *)(param_1 + 0x1ae0);
  puVar6[9] = 0x13c7;
  puVar6[10] = *(undefined4 *)(param_1 + 0x1ab0);
  puVar6[0xb] = 0x1048;
  puVar6[0xc] = *(undefined4 *)(param_1 + 0x1bc0);
  puVar6[0xd] = 0x1047;
  puVar6[0xe] = *(undefined4 *)(param_1 + 0x1bb0);
  *(undefined4 **)(param_1 + 0x274c) = puVar6 + 0xf;
                    
                    
  (**(code **)(param_1 + 0x275c))();
  return;
}

/* FUN_000833c5 @ 0x833c5 (346 bytes) */
int FUN_000833c5(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar1 = *(int *)(*(int *)(param_2 + 0x70) + *(int *)(param_1 + 0x1130) * 4);
  iVar2 = *(int *)(param_2 + 0x74);
  if (0 < *(int *)(iVar2 + 0x84)) {
    local_24 = 0;
    local_20 = 0;
    do {
      iVar7 = local_20 + *(int *)(iVar2 + 0x80);
      if (*(int *)(iVar7 + 8) != 0x34) {
        FUN_00089a08(param_1,iVar7,&local_1c);
        iVar2 = FUN_0004951b(local_1c);
        iVar3 = FUN_0004951b(local_18);
        iVar4 = FUN_0004951b(local_14);
        iVar5 = FUN_0004951b(local_10);
        iVar6 = *(int *)(iVar7 + 4) * 0x10 + iVar1;
        if ((((iVar2 == *(int *)(iVar6 + 0x90)) && (iVar3 == *(int *)(iVar6 + 0x94))) &&
            (iVar4 == *(int *)(iVar6 + 0x98))) && (iVar5 == *(int *)(iVar6 + 0x9c))) {
          iVar2 = *(int *)(param_2 + 0x74);
        }
        else {
          *(int *)(*(int *)(iVar7 + 4) * 0x10 + 0x90 + iVar1) = iVar2;
          *(int *)(*(int *)(iVar7 + 4) * 0x10 + 0x94 + iVar1) = iVar3;
          *(int *)(*(int *)(iVar7 + 4) * 0x10 + 0x98 + iVar1) = iVar4;
          *(int *)(*(int *)(iVar7 + 4) * 0x10 + 0x9c + iVar1) = iVar5;
          *(undefined4 *)(param_1 + 0x1e64) = 0;
          iVar2 = *(int *)(param_2 + 0x74);
        }
      }
      local_24 = local_24 + 1;
      local_20 = local_20 + 0x14;
    } while (local_24 < *(int *)(iVar2 + 0x84));
  }
  return;
}

/* FUN_0008351f @ 0x8351f (139 bytes) */
int FUN_0008351f(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x11d8) = 0x400;
  *(undefined4 *)(param_1 + 0x11e0) = 0x40;
  *(undefined4 *)(param_1 + 0x11e4) = 0x40;
  *(undefined4 *)(param_1 + 0x11e8) = 0x40;
  *(undefined4 *)(param_1 + 0x11ec) = 10;
  *(undefined4 *)(param_1 + 0x11f0) = 10;
  *(undefined4 *)(param_1 + 0x11f4) = 0;
  *(undefined4 *)(param_1 + 0x11f8) = 0;
  *(undefined4 *)(param_1 + 0x11fc) = 0x40;
  *(undefined4 *)(param_1 + 0x1200) = 0x40;
  *(undefined4 *)(param_1 + 0x1210) = 0x200;
  *(undefined4 *)(param_1 + 0x1208) = 0x200;
  *(undefined4 *)(param_1 + 0x1214) = 0x200;
  *(undefined4 *)(param_1 + 0x120c) = 0x1ff;
  *(undefined4 *)(param_1 + 0x1218) = 4;
  *(undefined4 *)(param_1 + 0x11d4) = 0x600;
  *(undefined4 *)(param_1 + 0x11dc) = 0x8000;
  *(undefined4 *)(param_1 + 0x1204) = 0x400;
  return;
}

/* FUN_000835aa @ 0x835aa (5 bytes) */
int FUN_000835aa()
{
  return;
}

/* FUN_000835af @ 0x835af (883 bytes) */
int FUN_000835af(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
  undefined4 *param_5;
  int param_6;
  int param_7;
{
  byte bVar1;
  short sVar2;
  byte *pbVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int local_18;
  int local_14;
  int local_10;
  
  if (param_1 == 0) {
    local_14 = 0;
  }
  else {
    local_14 = *(int *)(param_1 + 0x276c);
  }
  _memset(param_5,0,0x80);
  local_10 = param_4;
  local_18 = 0;
  uVar6 = 0;
  pbVar3 = (byte *)(param_4 + 0xca);
  puVar5 = param_5;
  do {
    *puVar5 = 1;
    *(undefined1 *)((int)puVar5 + 0xb) = 0;
    *(undefined2 *)((int)puVar5 + 6) = 0;
    *(undefined1 *)((int)puVar5 + 0xe) = 0;
    *(undefined1 *)((int)puVar5 + 0xf) = 0;
    *(undefined4 *)(local_10 + 200) = 0;
    *(undefined1 *)((int)puVar5 + 9) = 0;
    if (*(char *)(local_18 + param_6) != '\0') {
      pbVar3[-0x41] = pbVar3[-0x41] & 0x1f;
      pbVar3[-0x40] = pbVar3[-0x40] & 0xc0 | 0x11;
      *(ushort *)(pbVar3 + -0x40) = *(ushort *)(pbVar3 + -0x40) & 0xfe3f | 0xc0;
      pbVar3[-2] = pbVar3[-2] & 0xc0 | (byte)uVar6;
      *(ushort *)(pbVar3 + -2) = *(ushort *)(pbVar3 + -2) & 0xf03f | ((short)uVar6 + 1) * 0x40;
      *(uint *)(pbVar3 + -2) = *(uint *)(pbVar3 + -2) & 0xfffc0fff | (uVar6 + 2) * 0x1000;
      *pbVar3 = *pbVar3 & 3 | (byte)uVar6 * '\x04' + 0xc;
      *(undefined1 *)((int)puVar5 + 9) = 1;
      *(undefined1 *)(puVar5 + 2) = (undefined1)local_18;
      *(short *)(puVar5 + 1) = (short)local_18 + 2;
      *(undefined1 *)(puVar5 + 3) = 0;
    }
    puVar5 = puVar5 + 0x12;
    local_18 = local_18 + 1;
    pbVar3 = pbVar3 + 4;
    local_10 = local_10 + 4;
    uVar6 = uVar6 + 4 & 0x3f;
  } while (local_18 != 8);
  if (*(char *)(param_3 + 0x118) != '\0') {
    param_5[0x90] = 1;
    *(undefined1 *)((int)param_5 + 0x24b) = 0;
    *(undefined2 *)((int)param_5 + 0x246) = 0;
    *(undefined1 *)((int)param_5 + 0x24a) = 0;
    *(undefined1 *)((int)param_5 + 0x24d) = 0;
    *(undefined1 *)((int)param_5 + 0x24e) = 0;
    *(undefined1 *)((int)param_5 + 0x24f) = 0;
    *(undefined1 *)((int)param_5 + 0x249) = 1;
    pbVar3 = (byte *)(param_4 + 0x89 + local_14 * 4);
    *pbVar3 = *pbVar3 & 0x1f;
    bVar1 = *(byte *)(param_4 + 0x8a + local_14 * 4);
    *(byte *)(param_4 + 0x8a + local_14 * 4) = bVar1 & 0xf8 | 1;
    *(byte *)(param_4 + 0x8a + local_14 * 4) =
         bVar1 & 0xc0 | 1 | ((*(int *)(param_4 + 0x210) == 2) * '\x02' + '\x02') * '\b';
    *(ushort *)(param_4 + 0x8a + local_14 * 4) =
         *(ushort *)(param_4 + 0x8a + local_14 * 4) & 0xfe3f | 0x140;
    bVar1 = (byte)(local_14 << 2);
    *(byte *)(param_4 + 200 + local_14 * 4) =
         *(byte *)(param_4 + 200 + local_14 * 4) & 0xc0 | bVar1 & 0x3f;
    *(ushort *)(param_4 + 200 + local_14 * 4) =
         *(ushort *)(param_4 + 200 + local_14 * 4) & 0xf03f | ((byte)(bVar1 + 1) & 0x3f) << 6;
    if (*(int *)(param_4 + 0x210) == 2) {
      uVar6 = 0x3e;
    }
    else {
      uVar6 = (uint)(bVar1 + 2 & 0x3f);
    }
    *(uint *)(param_4 + 200 + local_14 * 4) =
         *(uint *)(param_4 + 200 + local_14 * 4) & 0xfffc0fff | uVar6 << 0xc;
    pbVar3 = (byte *)(param_4 + 0xca + local_14 * 4);
    *pbVar3 = *pbVar3 | 0xfc;
    *(char *)(param_5 + 0x92) = (char)local_14;
    *(short *)(param_5 + 0x91) = (short)*(undefined4 *)(param_3 + 0x108);
    *(undefined1 *)(param_5 + 0x93) = 0;
  }
  *(undefined1 *)((int)param_5 + 10) = 0;
  *(undefined1 *)((int)param_5 + 0xb) = 1;
  *(undefined2 *)((int)param_5 + 6) = 0;
  *(undefined1 *)((int)param_5 + 0xd) = 0;
  *(ushort *)(param_4 + 0x88) = *(ushort *)(param_4 + 0x88) & 0xfe3f;
  *(byte *)(param_4 + 0x89) = *(byte *)(param_4 + 0x89) & 0xe1;
  *(byte *)(param_4 + 0xcb) = *(byte *)(param_4 + 0xcb) & 0x80;
  if (param_7 == '\0') {
    uVar4 = 1;
    sVar2 = 1;
  }
  else {
    *(undefined1 *)((int)param_5 + 0x52) = 1;
    *(undefined1 *)((int)param_5 + 0x53) = 1;
    *(undefined2 *)((int)param_5 + 0x4e) = 1;
    *(undefined1 *)((int)param_5 + 0x55) = 0;
    *(ushort *)(param_4 + 0x8c) = *(ushort *)(param_4 + 0x8c) & 0xfe3f | 0x40;
    *(byte *)(param_4 + 0x8d) = *(byte *)(param_4 + 0x8d) & 0xe1;
    *(byte *)(param_4 + 0xcf) = *(byte *)(param_4 + 0xcf) & 0x80 | 1;
    uVar4 = 2;
    sVar2 = 2;
  }
  *(ushort *)(param_4 + 0x208) = *(ushort *)(param_4 + 0x208) & 0xf87f | sVar2 << 7;
  *(undefined4 *)(param_4 + 0x20c) = uVar4;
  *(undefined4 *)(param_4 + 0x214) = 0;
  return (~-(uint)(*(char *)(param_3 + 0x118) == '\0') & 0x48) + 0x240 + (int)param_5;
}

/* FUN_00083922 @ 0x83922 (173 bytes) */
int FUN_00083922(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 0x130;
  if (param_2 == 0) {
    return;
  }
  if (iVar2 == *(int *)(param_1 + 0x1e70)) {
    *(undefined4 *)(param_1 + 0x1e70) = 0;
    FUN_0004a272(param_1,iVar2);
    iVar1 = *(int *)(param_1 + 0x1e64);
  }
  else {
    FUN_0004a272(param_1,iVar2);
    iVar1 = *(int *)(param_1 + 0x1e64);
  }
  if (iVar2 == iVar1) {
    *(undefined4 *)(param_1 + 0x1e64) = 0;
    iVar1 = *(int *)(param_1 + 0x1488);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x1488);
  }
  if (iVar1 == param_2) {
    *(undefined4 *)(param_1 + 0x1488) = 0;
    iVar1 = *(int *)(param_1 + 0x1e5c);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x1e5c);
  }
  if (iVar2 == iVar1) {
    FUN_0004a17c();
    return;
  }
  return;
}

