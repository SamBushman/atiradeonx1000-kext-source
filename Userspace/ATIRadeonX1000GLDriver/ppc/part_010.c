#include "decls.h"

/* FUN_0006c7c0 @ 0x6c7c0 (1308 bytes) */
int FUN_0006c7c0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  int *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint *puVar16;
  
  uVar12 = (param_2 & 0x3f) << 0x10 | param_3 & 0xffff;
  puVar16 = (uint *)(param_1 + 0x754);
  uVar15 = 0;
  uVar13 = 0;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    uVar12 = uVar12 | 0x400000;
    uVar13 = 0x55;
  }
  if (*param_4 == 0) {
    iVar14 = param_4[3];
    iVar8 = param_4[1];
    iVar2 = param_4[2];
LAB_0006c8a0:
    uVar12 = uVar12 | 0x400000;
    uVar13 = (uint)(iVar14 != 0) * 0x40 |
             (uint)(iVar2 != 0) * 0x10 | (uint)(iVar8 != 0) * 4 | (uint)(*param_4 != 0);
  }
  else {
    iVar8 = param_4[1];
    if (iVar8 == 0) {
      iVar14 = param_4[3];
      iVar2 = param_4[2];
      goto LAB_0006c8a0;
    }
    iVar2 = param_4[2];
    if (iVar2 == 0) {
      iVar14 = param_4[3];
      goto LAB_0006c8a0;
    }
    if (param_4[3] == 0) {
      iVar14 = 0;
      goto LAB_0006c8a0;
    }
  }
  uVar11 = (param_5 & 0x3f) << 0x10 | param_6 & 0xffff;
  if (*param_8 == 0) {
    uVar7 = param_8[1];
    if (uVar7 == 0) {
      uVar6 = param_8[2];
      if (uVar6 == 0) {
        uVar5 = param_8[3];
        if (uVar5 == 0) {
          uVar10 = *param_7;
          if (uVar10 == 0) {
            uVar3 = param_7[1];
            if (uVar3 == 1) {
              uVar1 = param_7[2];
              if (uVar1 == 2) {
                uVar9 = param_7[3];
                if (uVar9 == 3) goto LAB_0006ca14;
              }
              else {
                uVar9 = param_7[3];
              }
            }
            else {
              uVar9 = param_7[3];
              uVar1 = param_7[2];
            }
          }
          else {
            uVar9 = param_7[3];
            uVar3 = param_7[1];
            uVar1 = param_7[2];
          }
        }
        else {
          uVar9 = param_7[3];
          uVar10 = *param_7;
          uVar3 = param_7[1];
          uVar1 = param_7[2];
        }
      }
      else {
        uVar5 = param_8[3];
        uVar9 = param_7[3];
        uVar10 = *param_7;
        uVar3 = param_7[1];
        uVar1 = param_7[2];
      }
    }
    else {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar6 = param_8[2];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
    }
  }
  else {
    uVar5 = param_8[3];
    uVar9 = param_7[3];
    uVar7 = param_8[1];
    uVar6 = param_8[2];
    uVar10 = *param_7;
    uVar3 = param_7[1];
    uVar1 = param_7[2];
  }
  uVar11 = uVar11 | 0x400000;
  uVar15 = (uVar5 & 1) << 0xf |
           (uVar9 & 7) << 0xc |
           (uVar6 & 1) << 0xb |
           (uVar1 & 7) << 8 | (uVar7 & 1) << 7 | (uVar3 & 7) << 4 | (*param_8 & 1) << 3 | uVar10 & 7
  ;
LAB_0006ca14:
  uVar1 = *puVar16;
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar1) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar1 = *puVar16;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = 0x51;
  uVar1 = *puVar16 + 1;
  *puVar16 = uVar1;
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar1) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar1 = *puVar16;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = uVar12;
  uVar1 = *puVar16 + 1;
  *puVar16 = uVar1;
  if ((uVar12 & 0x400000) != 0) {
    iVar14 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar1) {
      uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar1 = *puVar16;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = uVar13;
    uVar1 = *puVar16 + 1;
    *puVar16 = uVar1;
  }
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar1) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar1 = *puVar16;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = uVar11;
  uVar12 = *puVar16 + 1;
  *puVar16 = uVar12;
  if ((uVar11 & 0x400000) != 0) {
    iVar14 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar12) {
      uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar12 = *puVar16;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar12 * 4 + *(int *)(param_1 + 0x75c)) = uVar15;
    *puVar16 = *puVar16 + 1;
  }
  return;
}

/* FUN_0006cd00 @ 0x6cd00 (1308 bytes) */
int FUN_0006cd00(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  int *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint *puVar16;
  
  uVar12 = (param_2 & 0x3f) << 0x10 | param_3 & 0xffff;
  puVar16 = (uint *)(param_1 + 0x754);
  uVar15 = 0;
  uVar13 = 0;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    uVar12 = uVar12 | 0x400000;
    uVar13 = 0x55;
  }
  if (*param_4 == 0) {
    iVar14 = param_4[3];
    iVar8 = param_4[1];
    iVar2 = param_4[2];
LAB_0006cde0:
    uVar12 = uVar12 | 0x400000;
    uVar13 = (uint)(iVar14 != 0) * 0x40 |
             (uint)(iVar2 != 0) * 0x10 | (uint)(iVar8 != 0) * 4 | (uint)(*param_4 != 0);
  }
  else {
    iVar8 = param_4[1];
    if (iVar8 == 0) {
      iVar14 = param_4[3];
      iVar2 = param_4[2];
      goto LAB_0006cde0;
    }
    iVar2 = param_4[2];
    if (iVar2 == 0) {
      iVar14 = param_4[3];
      goto LAB_0006cde0;
    }
    if (param_4[3] == 0) {
      iVar14 = 0;
      goto LAB_0006cde0;
    }
  }
  uVar11 = (param_5 & 0x3f) << 0x10 | param_6 & 0xffff;
  if (*param_8 == 0) {
    uVar7 = param_8[1];
    if (uVar7 == 0) {
      uVar6 = param_8[2];
      if (uVar6 == 0) {
        uVar5 = param_8[3];
        if (uVar5 == 0) {
          uVar10 = *param_7;
          if (uVar10 == 0) {
            uVar3 = param_7[1];
            if (uVar3 == 1) {
              uVar1 = param_7[2];
              if (uVar1 == 2) {
                uVar9 = param_7[3];
                if (uVar9 == 3) goto LAB_0006cf54;
              }
              else {
                uVar9 = param_7[3];
              }
            }
            else {
              uVar9 = param_7[3];
              uVar1 = param_7[2];
            }
          }
          else {
            uVar9 = param_7[3];
            uVar3 = param_7[1];
            uVar1 = param_7[2];
          }
        }
        else {
          uVar9 = param_7[3];
          uVar10 = *param_7;
          uVar3 = param_7[1];
          uVar1 = param_7[2];
        }
      }
      else {
        uVar5 = param_8[3];
        uVar9 = param_7[3];
        uVar10 = *param_7;
        uVar3 = param_7[1];
        uVar1 = param_7[2];
      }
    }
    else {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar6 = param_8[2];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
    }
  }
  else {
    uVar5 = param_8[3];
    uVar9 = param_7[3];
    uVar7 = param_8[1];
    uVar6 = param_8[2];
    uVar10 = *param_7;
    uVar3 = param_7[1];
    uVar1 = param_7[2];
  }
  uVar11 = uVar11 | 0x400000;
  uVar15 = (uVar5 & 1) << 0xf |
           (uVar9 & 7) << 0xc |
           (uVar6 & 1) << 0xb |
           (uVar1 & 7) << 8 | (uVar7 & 1) << 7 | (uVar3 & 7) << 4 | (*param_8 & 1) << 3 | uVar10 & 7
  ;
LAB_0006cf54:
  uVar1 = *puVar16;
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar1) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar1 = *puVar16;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = 0x55;
  uVar1 = *puVar16 + 1;
  *puVar16 = uVar1;
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar1) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar1 = *puVar16;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = uVar12;
  uVar1 = *puVar16 + 1;
  *puVar16 = uVar1;
  if ((uVar12 & 0x400000) != 0) {
    iVar14 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar1) {
      uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar1 = *puVar16;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = uVar13;
    uVar1 = *puVar16 + 1;
    *puVar16 = uVar1;
  }
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar1) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar1 = *puVar16;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = uVar11;
  uVar12 = *puVar16 + 1;
  *puVar16 = uVar12;
  if ((uVar11 & 0x400000) != 0) {
    iVar14 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar12) {
      uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar12 = *puVar16;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar12 * 4 + *(int *)(param_1 + 0x75c)) = uVar15;
    *puVar16 = *puVar16 + 1;
  }
  return;
}

/* FUN_0006d240 @ 0x6d240 (1308 bytes) */
int FUN_0006d240(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  int *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint *puVar16;
  
  uVar12 = (param_2 & 0x3f) << 0x10 | param_3 & 0xffff;
  puVar16 = (uint *)(param_1 + 0x754);
  uVar15 = 0;
  uVar13 = 0;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    uVar12 = uVar12 | 0x400000;
    uVar13 = 0x55;
  }
  if (*param_4 == 0) {
    iVar14 = param_4[3];
    iVar8 = param_4[1];
    iVar2 = param_4[2];
LAB_0006d320:
    uVar12 = uVar12 | 0x400000;
    uVar13 = (uint)(iVar14 != 0) * 0x40 |
             (uint)(iVar2 != 0) * 0x10 | (uint)(iVar8 != 0) * 4 | (uint)(*param_4 != 0);
  }
  else {
    iVar8 = param_4[1];
    if (iVar8 == 0) {
      iVar14 = param_4[3];
      iVar2 = param_4[2];
      goto LAB_0006d320;
    }
    iVar2 = param_4[2];
    if (iVar2 == 0) {
      iVar14 = param_4[3];
      goto LAB_0006d320;
    }
    if (param_4[3] == 0) {
      iVar14 = 0;
      goto LAB_0006d320;
    }
  }
  uVar11 = (param_5 & 0x3f) << 0x10 | param_6 & 0xffff;
  if (*param_8 == 0) {
    uVar7 = param_8[1];
    if (uVar7 == 0) {
      uVar6 = param_8[2];
      if (uVar6 == 0) {
        uVar5 = param_8[3];
        if (uVar5 == 0) {
          uVar10 = *param_7;
          if (uVar10 == 0) {
            uVar3 = param_7[1];
            if (uVar3 == 1) {
              uVar1 = param_7[2];
              if (uVar1 == 2) {
                uVar9 = param_7[3];
                if (uVar9 == 3) goto LAB_0006d494;
              }
              else {
                uVar9 = param_7[3];
              }
            }
            else {
              uVar9 = param_7[3];
              uVar1 = param_7[2];
            }
          }
          else {
            uVar9 = param_7[3];
            uVar3 = param_7[1];
            uVar1 = param_7[2];
          }
        }
        else {
          uVar9 = param_7[3];
          uVar10 = *param_7;
          uVar3 = param_7[1];
          uVar1 = param_7[2];
        }
      }
      else {
        uVar5 = param_8[3];
        uVar9 = param_7[3];
        uVar10 = *param_7;
        uVar3 = param_7[1];
        uVar1 = param_7[2];
      }
    }
    else {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar6 = param_8[2];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
    }
  }
  else {
    uVar5 = param_8[3];
    uVar9 = param_7[3];
    uVar7 = param_8[1];
    uVar6 = param_8[2];
    uVar10 = *param_7;
    uVar3 = param_7[1];
    uVar1 = param_7[2];
  }
  uVar11 = uVar11 | 0x400000;
  uVar15 = (uVar5 & 1) << 0xf |
           (uVar9 & 7) << 0xc |
           (uVar6 & 1) << 0xb |
           (uVar1 & 7) << 8 | (uVar7 & 1) << 7 | (uVar3 & 7) << 4 | (*param_8 & 1) << 3 | uVar10 & 7
  ;
LAB_0006d494:
  uVar1 = *puVar16;
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar1) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar1 = *puVar16;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = 0x2d;
  uVar1 = *puVar16 + 1;
  *puVar16 = uVar1;
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar1) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar1 = *puVar16;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = uVar12;
  uVar1 = *puVar16 + 1;
  *puVar16 = uVar1;
  if ((uVar12 & 0x400000) != 0) {
    iVar14 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar1) {
      uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar1 = *puVar16;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = uVar13;
    uVar1 = *puVar16 + 1;
    *puVar16 = uVar1;
  }
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar1) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar1 = *puVar16;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = uVar11;
  uVar12 = *puVar16 + 1;
  *puVar16 = uVar12;
  if ((uVar11 & 0x400000) != 0) {
    iVar14 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar12) {
      uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar12 = *puVar16;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar12 * 4 + *(int *)(param_1 + 0x75c)) = uVar15;
    *puVar16 = *puVar16 + 1;
  }
  return;
}

/* FUN_0006d780 @ 0x6d780 (1308 bytes) */
int FUN_0006d780(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  int *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint *puVar16;
  
  uVar12 = (param_2 & 0x3f) << 0x10 | param_3 & 0xffff;
  puVar16 = (uint *)(param_1 + 0x754);
  uVar15 = 0;
  uVar13 = 0;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    uVar12 = uVar12 | 0x400000;
    uVar13 = 0x55;
  }
  if (*param_4 == 0) {
    iVar14 = param_4[3];
    iVar8 = param_4[1];
    iVar2 = param_4[2];
LAB_0006d860:
    uVar12 = uVar12 | 0x400000;
    uVar13 = (uint)(iVar14 != 0) * 0x40 |
             (uint)(iVar2 != 0) * 0x10 | (uint)(iVar8 != 0) * 4 | (uint)(*param_4 != 0);
  }
  else {
    iVar8 = param_4[1];
    if (iVar8 == 0) {
      iVar14 = param_4[3];
      iVar2 = param_4[2];
      goto LAB_0006d860;
    }
    iVar2 = param_4[2];
    if (iVar2 == 0) {
      iVar14 = param_4[3];
      goto LAB_0006d860;
    }
    if (param_4[3] == 0) {
      iVar14 = 0;
      goto LAB_0006d860;
    }
  }
  uVar11 = (param_5 & 0x3f) << 0x10 | param_6 & 0xffff;
  if (*param_8 == 0) {
    uVar7 = param_8[1];
    if (uVar7 == 0) {
      uVar6 = param_8[2];
      if (uVar6 == 0) {
        uVar5 = param_8[3];
        if (uVar5 == 0) {
          uVar10 = *param_7;
          if (uVar10 == 0) {
            uVar3 = param_7[1];
            if (uVar3 == 1) {
              uVar1 = param_7[2];
              if (uVar1 == 2) {
                uVar9 = param_7[3];
                if (uVar9 == 3) goto LAB_0006d9d4;
              }
              else {
                uVar9 = param_7[3];
              }
            }
            else {
              uVar9 = param_7[3];
              uVar1 = param_7[2];
            }
          }
          else {
            uVar9 = param_7[3];
            uVar3 = param_7[1];
            uVar1 = param_7[2];
          }
        }
        else {
          uVar9 = param_7[3];
          uVar10 = *param_7;
          uVar3 = param_7[1];
          uVar1 = param_7[2];
        }
      }
      else {
        uVar5 = param_8[3];
        uVar9 = param_7[3];
        uVar10 = *param_7;
        uVar3 = param_7[1];
        uVar1 = param_7[2];
      }
    }
    else {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar6 = param_8[2];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
    }
  }
  else {
    uVar5 = param_8[3];
    uVar9 = param_7[3];
    uVar7 = param_8[1];
    uVar6 = param_8[2];
    uVar10 = *param_7;
    uVar3 = param_7[1];
    uVar1 = param_7[2];
  }
  uVar11 = uVar11 | 0x400000;
  uVar15 = (uVar5 & 1) << 0xf |
           (uVar9 & 7) << 0xc |
           (uVar6 & 1) << 0xb |
           (uVar1 & 7) << 8 | (uVar7 & 1) << 7 | (uVar3 & 7) << 4 | (*param_8 & 1) << 3 | uVar10 & 7
  ;
LAB_0006d9d4:
  uVar1 = *puVar16;
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar1) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar1 = *puVar16;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = 0x2c;
  uVar1 = *puVar16 + 1;
  *puVar16 = uVar1;
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar1) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar1 = *puVar16;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = uVar12;
  uVar1 = *puVar16 + 1;
  *puVar16 = uVar1;
  if ((uVar12 & 0x400000) != 0) {
    iVar14 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar1) {
      uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar1 = *puVar16;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = uVar13;
    uVar1 = *puVar16 + 1;
    *puVar16 = uVar1;
  }
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar1) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar1 = *puVar16;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = uVar11;
  uVar12 = *puVar16 + 1;
  *puVar16 = uVar12;
  if ((uVar11 & 0x400000) != 0) {
    iVar14 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar12) {
      uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar16 << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar12 = *puVar16;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar12 * 4 + *(int *)(param_1 + 0x75c)) = uVar15;
    *puVar16 = *puVar16 + 1;
  }
  return;
}

/* FUN_0006dcc0 @ 0x6dcc0 (1912 bytes) */
int FUN_0006dcc0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  uint param_2;
  uint param_3;
  int *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
  uint param_9;
  uint param_10;
  uint *param_11;
  uint *param_12;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint *puVar18;
  
  uVar13 = (param_2 & 0x3f) << 0x10 | param_3 & 0xffff;
  puVar18 = (uint *)(param_1 + 0x754);
  uVar15 = 0;
  uVar17 = 0;
  uVar14 = 0;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    uVar13 = uVar13 | 0x400000;
    uVar14 = 0x55;
  }
  if (*param_4 == 0) {
    iVar16 = param_4[3];
    iVar8 = param_4[1];
    iVar2 = param_4[2];
LAB_0006ddb0:
    uVar13 = uVar13 | 0x400000;
    uVar14 = (uint)(iVar16 != 0) * 0x40 |
             (uint)(iVar2 != 0) * 0x10 | (uint)(iVar8 != 0) * 4 | (uint)(*param_4 != 0);
  }
  else {
    iVar8 = param_4[1];
    if (iVar8 == 0) {
      iVar16 = param_4[3];
      iVar2 = param_4[2];
      goto LAB_0006ddb0;
    }
    iVar2 = param_4[2];
    if (iVar2 == 0) {
      iVar16 = param_4[3];
      goto LAB_0006ddb0;
    }
    if (param_4[3] == 0) {
      iVar16 = 0;
      goto LAB_0006ddb0;
    }
  }
  uVar12 = (param_5 & 0x3f) << 0x10 | param_6 & 0xffff;
  if (*param_8 == 0) {
    uVar7 = param_8[1];
    if (uVar7 != 0) {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar6 = param_8[2];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_0006df00;
    }
    uVar6 = param_8[2];
    if (uVar6 != 0) {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_0006df00;
    }
    uVar5 = param_8[3];
    if (uVar5 != 0) {
      uVar9 = param_7[3];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_0006df00;
    }
    uVar10 = *param_7;
    if (uVar10 != 0) {
      uVar9 = param_7[3];
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_0006df00;
    }
    uVar3 = param_7[1];
    if (uVar3 != 1) {
      uVar9 = param_7[3];
      uVar1 = param_7[2];
      goto LAB_0006df00;
    }
    uVar1 = param_7[2];
    if (uVar1 != 2) {
      uVar9 = param_7[3];
      goto LAB_0006df00;
    }
    uVar9 = param_7[3];
    if (uVar9 != 3) goto LAB_0006df00;
  }
  else {
    uVar5 = param_8[3];
    uVar9 = param_7[3];
    uVar7 = param_8[1];
    uVar6 = param_8[2];
    uVar10 = *param_7;
    uVar3 = param_7[1];
    uVar1 = param_7[2];
LAB_0006df00:
    uVar12 = uVar12 | 0x400000;
    uVar17 = (uVar5 & 1) << 0xf |
             (uVar9 & 7) << 0xc |
             (uVar6 & 1) << 0xb |
             (uVar1 & 7) << 8 |
             (uVar7 & 1) << 7 | (uVar3 & 7) << 4 | (*param_8 & 1) << 3 | uVar10 & 7;
  }
  uVar1 = (param_9 & 0x3f) << 0x10 | param_10 & 0xffff;
  if (*param_12 == 0) {
    uVar10 = param_12[1];
    if (uVar10 == 0) {
      uVar7 = param_12[2];
      if (uVar7 == 0) {
        uVar6 = param_12[3];
        if (uVar6 == 0) {
          uVar11 = *param_11;
          if (uVar11 == 0) {
            uVar5 = param_11[1];
            if (uVar5 == 1) {
              uVar3 = param_11[2];
              if (uVar3 == 2) {
                uVar9 = param_11[3];
                if (uVar9 == 3) goto LAB_0006e054;
              }
              else {
                uVar9 = param_11[3];
              }
            }
            else {
              uVar9 = param_11[3];
              uVar3 = param_11[2];
            }
          }
          else {
            uVar9 = param_11[3];
            uVar5 = param_11[1];
            uVar3 = param_11[2];
          }
        }
        else {
          uVar9 = param_11[3];
          uVar11 = *param_11;
          uVar5 = param_11[1];
          uVar3 = param_11[2];
        }
      }
      else {
        uVar6 = param_12[3];
        uVar9 = param_11[3];
        uVar11 = *param_11;
        uVar5 = param_11[1];
        uVar3 = param_11[2];
      }
    }
    else {
      uVar6 = param_12[3];
      uVar9 = param_11[3];
      uVar7 = param_12[2];
      uVar11 = *param_11;
      uVar5 = param_11[1];
      uVar3 = param_11[2];
    }
  }
  else {
    uVar6 = param_12[3];
    uVar9 = param_11[3];
    uVar10 = param_12[1];
    uVar7 = param_12[2];
    uVar11 = *param_11;
    uVar5 = param_11[1];
    uVar3 = param_11[2];
  }
  uVar1 = uVar1 | 0x400000;
  uVar15 = (uVar6 & 1) << 0xf |
           (uVar9 & 7) << 0xc |
           (uVar7 & 1) << 0xb |
           (uVar3 & 7) << 8 |
           (uVar10 & 1) << 7 | (uVar5 & 7) << 4 | (*param_12 & 1) << 3 | uVar11 & 7;
LAB_0006e054:
  uVar3 = *puVar18;
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = 0x4e;
  uVar3 = *puVar18 + 1;
  *puVar18 = uVar3;
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar13;
  uVar3 = *puVar18 + 1;
  *puVar18 = uVar3;
  if ((uVar13 & 0x400000) != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar3) {
      uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar3 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar14;
    uVar3 = *puVar18 + 1;
    *puVar18 = uVar3;
  }
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar12;
  uVar13 = *puVar18 + 1;
  *puVar18 = uVar13;
  if ((uVar12 & 0x400000) != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar13) {
      uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar13 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar17;
    uVar13 = *puVar18 + 1;
    *puVar18 = uVar13;
  }
  iVar16 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar13) {
    uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar13 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar1;
  uVar13 = *puVar18 + 1;
  *puVar18 = uVar13;
  if ((uVar1 & 0x400000) != 0) {
    iVar16 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar13) {
      uVar4 = (**(code **)(iVar16 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar13 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar13 * 4 + *(int *)(param_1 + 0x75c)) = uVar15;
    *puVar18 = *puVar18 + 1;
  }
  return;
}

/* FUN_0006e460 @ 0x6e460 (1928 bytes) */
int FUN_0006e460(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  uint param_2;
  uint param_3;
  int *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
  uint param_9;
  uint param_10;
  uint *param_11;
  uint *param_12;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint *puVar18;
  
  uVar16 = 0x101;
  uVar12 = (param_2 & 0x3f) << 0x10 | param_3 & 0xffff | 0x400000;
  puVar18 = (uint *)(param_1 + 0x754);
  uVar13 = 0;
  uVar15 = 0;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    uVar12 = uVar12 | 0x400000;
    uVar16 = 1;
  }
  uVar17 = uVar16 | 0x54;
  if (*param_4 == 0) {
    iVar14 = param_4[3];
    iVar8 = param_4[1];
    iVar2 = param_4[2];
LAB_0006e560:
    uVar12 = uVar12 | 0x400000;
    uVar17 = (uint)(iVar14 != 0) * 0x40 |
             (uint)(iVar2 != 0) * 0x10 |
             (uint)(iVar8 != 0) * 4 | (uint)(*param_4 != 0) | uVar16 & 0xffffff00;
  }
  else {
    iVar8 = param_4[1];
    if (iVar8 == 0) {
      iVar14 = param_4[3];
      iVar2 = param_4[2];
      goto LAB_0006e560;
    }
    iVar2 = param_4[2];
    if (iVar2 == 0) {
      iVar14 = param_4[3];
      goto LAB_0006e560;
    }
    if (param_4[3] == 0) {
      iVar14 = 0;
      goto LAB_0006e560;
    }
  }
  uVar16 = (param_5 & 0x3f) << 0x10 | param_6 & 0xffff;
  if (*param_8 == 0) {
    uVar7 = param_8[1];
    if (uVar7 != 0) {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar6 = param_8[2];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_0006e6b0;
    }
    uVar6 = param_8[2];
    if (uVar6 != 0) {
      uVar5 = param_8[3];
      uVar9 = param_7[3];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_0006e6b0;
    }
    uVar5 = param_8[3];
    if (uVar5 != 0) {
      uVar9 = param_7[3];
      uVar10 = *param_7;
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_0006e6b0;
    }
    uVar10 = *param_7;
    if (uVar10 != 0) {
      uVar9 = param_7[3];
      uVar3 = param_7[1];
      uVar1 = param_7[2];
      goto LAB_0006e6b0;
    }
    uVar3 = param_7[1];
    if (uVar3 != 1) {
      uVar9 = param_7[3];
      uVar1 = param_7[2];
      goto LAB_0006e6b0;
    }
    uVar1 = param_7[2];
    if (uVar1 != 2) {
      uVar9 = param_7[3];
      goto LAB_0006e6b0;
    }
    uVar9 = param_7[3];
    if (uVar9 != 3) goto LAB_0006e6b0;
  }
  else {
    uVar5 = param_8[3];
    uVar9 = param_7[3];
    uVar7 = param_8[1];
    uVar6 = param_8[2];
    uVar10 = *param_7;
    uVar3 = param_7[1];
    uVar1 = param_7[2];
LAB_0006e6b0:
    uVar16 = uVar16 | 0x400000;
    uVar15 = (uVar5 & 1) << 0xf |
             (uVar9 & 7) << 0xc |
             (uVar6 & 1) << 0xb |
             (uVar1 & 7) << 8 |
             (uVar7 & 1) << 7 | (uVar3 & 7) << 4 | (*param_8 & 1) << 3 | uVar10 & 7;
  }
  uVar1 = (param_9 & 0x3f) << 0x10 | param_10 & 0xffff;
  if (*param_12 == 0) {
    uVar10 = param_12[1];
    if (uVar10 == 0) {
      uVar7 = param_12[2];
      if (uVar7 == 0) {
        uVar6 = param_12[3];
        if (uVar6 == 0) {
          uVar11 = *param_11;
          if (uVar11 == 0) {
            uVar5 = param_11[1];
            if (uVar5 == 1) {
              uVar3 = param_11[2];
              if (uVar3 == 2) {
                uVar9 = param_11[3];
                if (uVar9 == 3) goto LAB_0006e804;
              }
              else {
                uVar9 = param_11[3];
              }
            }
            else {
              uVar9 = param_11[3];
              uVar3 = param_11[2];
            }
          }
          else {
            uVar9 = param_11[3];
            uVar5 = param_11[1];
            uVar3 = param_11[2];
          }
        }
        else {
          uVar9 = param_11[3];
          uVar11 = *param_11;
          uVar5 = param_11[1];
          uVar3 = param_11[2];
        }
      }
      else {
        uVar6 = param_12[3];
        uVar9 = param_11[3];
        uVar11 = *param_11;
        uVar5 = param_11[1];
        uVar3 = param_11[2];
      }
    }
    else {
      uVar6 = param_12[3];
      uVar9 = param_11[3];
      uVar7 = param_12[2];
      uVar11 = *param_11;
      uVar5 = param_11[1];
      uVar3 = param_11[2];
    }
  }
  else {
    uVar6 = param_12[3];
    uVar9 = param_11[3];
    uVar10 = param_12[1];
    uVar7 = param_12[2];
    uVar11 = *param_11;
    uVar5 = param_11[1];
    uVar3 = param_11[2];
  }
  uVar1 = uVar1 | 0x400000;
  uVar13 = (uVar6 & 1) << 0xf |
           (uVar9 & 7) << 0xc |
           (uVar7 & 1) << 0xb |
           (uVar3 & 7) << 8 |
           (uVar10 & 1) << 7 | (uVar5 & 7) << 4 | (*param_12 & 1) << 3 | uVar11 & 7;
LAB_0006e804:
  uVar3 = *puVar18;
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = 0x4e;
  uVar3 = *puVar18 + 1;
  *puVar18 = uVar3;
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar12;
  uVar3 = *puVar18 + 1;
  *puVar18 = uVar3;
  if ((uVar12 & 0x400000) != 0) {
    iVar14 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar3) {
      uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar3 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar17;
    uVar3 = *puVar18 + 1;
    *puVar18 = uVar3;
  }
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar16;
  uVar12 = *puVar18 + 1;
  *puVar18 = uVar12;
  if ((uVar16 & 0x400000) != 0) {
    iVar14 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar12) {
      uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar12 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar12 * 4 + *(int *)(param_1 + 0x75c)) = uVar15;
    uVar12 = *puVar18 + 1;
    *puVar18 = uVar12;
  }
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar12) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar12 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar12 * 4 + *(int *)(param_1 + 0x75c)) = uVar1;
  uVar16 = *puVar18 + 1;
  *puVar18 = uVar16;
  if ((uVar1 & 0x400000) != 0) {
    iVar14 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar16) {
      uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar16 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar16 * 4 + *(int *)(param_1 + 0x75c)) = uVar13;
    *puVar18 = *puVar18 + 1;
  }
  return;
}

/* FUN_0006ec10 @ 0x6ec10 (4312 bytes) */
int FUN_0006ec10(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15, param_16)
  int param_1;
  uint param_2;
  uint param_3;
  int *param_4;
  uint param_5;
  uint param_6;
  uint *param_7;
  uint *param_8;
  uint param_9;
  uint param_10;
  uint *param_11;
  uint *param_12;
  uint param_13;
  uint param_14;
  uint *param_15;
  uint *param_16;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  uint *puVar17;
  undefined1 auStack_88 [4];
  uint uStack_84;
  
  uVar16 = 0;
  (**(code **)(param_1 + 0x748))(param_1,0,auStack_88);
  puVar17 = (uint *)(param_1 + 0x754);
  uVar10 = uStack_84 & 0xffff;
  uVar14 = (param_9 & 0x3f) << 0x10 | param_10 & 0xffff;
  if (*param_12 == 0) {
    uVar9 = param_12[1];
    if (uVar9 != 0) {
      uVar5 = param_12[3];
      uVar7 = param_11[3];
      uVar6 = param_12[2];
      uVar11 = *param_11;
      uVar2 = param_11[1];
      uVar1 = param_11[2];
      goto LAB_0006edc0;
    }
    uVar6 = param_12[2];
    if (uVar6 != 0) {
      uVar5 = param_12[3];
      uVar7 = param_11[3];
      uVar11 = *param_11;
      uVar2 = param_11[1];
      uVar1 = param_11[2];
      goto LAB_0006edc0;
    }
    uVar5 = param_12[3];
    if (uVar5 != 0) {
      uVar7 = param_11[3];
      uVar11 = *param_11;
      uVar2 = param_11[1];
      uVar1 = param_11[2];
      goto LAB_0006edc0;
    }
    uVar11 = *param_11;
    if (uVar11 != 0) {
      uVar7 = param_11[3];
      uVar2 = param_11[1];
      uVar1 = param_11[2];
      goto LAB_0006edc0;
    }
    uVar2 = param_11[1];
    if (uVar2 != 1) {
      uVar7 = param_11[3];
      uVar1 = param_11[2];
      goto LAB_0006edc0;
    }
    uVar1 = param_11[2];
    if (uVar1 != 2) {
      uVar7 = param_11[3];
      goto LAB_0006edc0;
    }
    uVar7 = param_11[3];
    if (uVar7 != 3) goto LAB_0006edc0;
  }
  else {
    uVar5 = param_12[3];
    uVar7 = param_11[3];
    uVar9 = param_12[1];
    uVar6 = param_12[2];
    uVar11 = *param_11;
    uVar2 = param_11[1];
    uVar1 = param_11[2];
LAB_0006edc0:
    uVar14 = uVar14 | 0x400000;
    uVar16 = (uVar5 & 1) << 0xf |
             (uVar7 & 7) << 0xc |
             (uVar6 & 1) << 0xb |
             (uVar1 & 7) << 8 |
             (uVar9 & 1) << 7 | (uVar2 & 7) << 4 | (*param_12 & 1) << 3 | uVar11 & 7;
  }
  uVar1 = *puVar17;
  iVar15 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar1) {
    uVar4 = (**(code **)(iVar15 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar15 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar1 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = 0x47;
  uVar1 = *puVar17 + 1;
  *puVar17 = uVar1;
  iVar15 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar1) {
    uVar4 = (**(code **)(iVar15 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar15 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar1 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar1 * 4 + *(int *)(param_1 + 0x75c)) = uVar10 | 0x440000;
  uVar10 = *puVar17 + 1;
  *puVar17 = uVar10;
  iVar15 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar10) {
    uVar4 = (**(code **)(iVar15 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar15 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar10 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar10 * 4 + *(int *)(param_1 + 0x75c)) = 1;
  uVar10 = *puVar17 + 1;
  *puVar17 = uVar10;
  iVar15 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar10) {
    uVar4 = (**(code **)(iVar15 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar15 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar10 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar10 * 4 + *(int *)(param_1 + 0x75c)) = uVar14;
  uVar10 = *puVar17 + 1;
  *puVar17 = uVar10;
  if ((uVar14 & 0x400000) != 0) {
    iVar15 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar10) {
      uVar4 = (**(code **)(iVar15 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
        (**(code **)(iVar15 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar10 = *puVar17;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar10 * 4 + *(int *)(param_1 + 0x75c)) = uVar16;
    uVar10 = *puVar17 + 1;
    *puVar17 = uVar10;
  }
  uVar1 = 0;
  uVar14 = uStack_84 & 0xffff;
  uVar16 = (param_5 & 0x3f) << 0x10 | param_6 & 0xffff;
  if (*param_8 == 0) {
    uVar9 = param_8[1];
    if (uVar9 != 0) {
      uVar6 = param_8[3];
      uVar11 = param_7[3];
      uVar7 = param_8[2];
      uVar12 = *param_7;
      uVar5 = param_7[1];
      uVar2 = param_7[2];
      goto LAB_0006f1f0;
    }
    uVar7 = param_8[2];
    if (uVar7 != 0) {
      uVar6 = param_8[3];
      uVar11 = param_7[3];
      uVar12 = *param_7;
      uVar5 = param_7[1];
      uVar2 = param_7[2];
      goto LAB_0006f1f0;
    }
    uVar6 = param_8[3];
    if (uVar6 != 0) {
      uVar11 = param_7[3];
      uVar12 = *param_7;
      uVar5 = param_7[1];
      uVar2 = param_7[2];
      goto LAB_0006f1f0;
    }
    uVar12 = *param_7;
    if (uVar12 != 0) {
      uVar11 = param_7[3];
      uVar5 = param_7[1];
      uVar2 = param_7[2];
      goto LAB_0006f1f0;
    }
    uVar5 = param_7[1];
    if (uVar5 != 1) {
      uVar11 = param_7[3];
      uVar2 = param_7[2];
      goto LAB_0006f1f0;
    }
    uVar2 = param_7[2];
    if (uVar2 != 2) {
      uVar11 = param_7[3];
      goto LAB_0006f1f0;
    }
    uVar11 = param_7[3];
    if (uVar11 != 3) goto LAB_0006f1f0;
  }
  else {
    uVar6 = param_8[3];
    uVar11 = param_7[3];
    uVar9 = param_8[1];
    uVar7 = param_8[2];
    uVar12 = *param_7;
    uVar5 = param_7[1];
    uVar2 = param_7[2];
LAB_0006f1f0:
    uVar16 = uVar16 | 0x400000;
    uVar1 = (uVar6 & 1) << 0xf |
            (uVar11 & 7) << 0xc |
            (uVar7 & 1) << 0xb |
            (uVar2 & 7) << 8 |
            (uVar9 & 1) << 7 | (uVar5 & 7) << 4 | (*param_8 & 1) << 3 | uVar12 & 7;
  }
  iVar15 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar10) {
    uVar4 = (**(code **)(iVar15 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar15 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar10 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar10 * 4 + *(int *)(param_1 + 0x75c)) = 0x47;
  uVar10 = *puVar17 + 1;
  *puVar17 = uVar10;
  iVar15 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar10) {
    uVar4 = (**(code **)(iVar15 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar15 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar10 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar10 * 4 + *(int *)(param_1 + 0x75c)) = uVar14 | 0x440000;
  uVar10 = *puVar17 + 1;
  *puVar17 = uVar10;
  iVar15 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar10) {
    uVar4 = (**(code **)(iVar15 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar15 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar10 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar10 * 4 + *(int *)(param_1 + 0x75c)) = 4;
  uVar10 = *puVar17 + 1;
  *puVar17 = uVar10;
  iVar15 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar10) {
    uVar4 = (**(code **)(iVar15 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar15 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar10 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar10 * 4 + *(int *)(param_1 + 0x75c)) = uVar16;
  uVar10 = *puVar17 + 1;
  *puVar17 = uVar10;
  if ((uVar16 & 0x400000) != 0) {
    iVar15 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar10) {
      uVar4 = (**(code **)(iVar15 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
        (**(code **)(iVar15 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar10 = *puVar17;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar10 * 4 + *(int *)(param_1 + 0x75c)) = uVar1;
    uVar10 = *puVar17 + 1;
    *puVar17 = uVar10;
  }
  uVar2 = 0;
  uVar14 = uStack_84 & 0xffff;
  uVar16 = 0x40;
  uVar1 = (param_13 & 0x3f) << 0x10 | param_14 & 0xffff;
  if (*param_16 == 0) {
    uVar11 = param_16[1];
    if (uVar11 != 0) {
      uVar7 = param_16[3];
      uVar12 = param_15[3];
      uVar9 = param_16[2];
      uVar13 = *param_15;
      uVar6 = param_15[1];
      uVar5 = param_15[2];
      goto LAB_0006f620;
    }
    uVar9 = param_16[2];
    if (uVar9 != 0) {
      uVar7 = param_16[3];
      uVar12 = param_15[3];
      uVar13 = *param_15;
      uVar6 = param_15[1];
      uVar5 = param_15[2];
      goto LAB_0006f620;
    }
    uVar7 = param_16[3];
    if (uVar7 != 0) {
      uVar12 = param_15[3];
      uVar13 = *param_15;
      uVar6 = param_15[1];
      uVar5 = param_15[2];
      goto LAB_0006f620;
    }
    uVar13 = *param_15;
    if (uVar13 != 0) {
      uVar12 = param_15[3];
      uVar6 = param_15[1];
      uVar5 = param_15[2];
      goto LAB_0006f620;
    }
    uVar6 = param_15[1];
    if (uVar6 != 1) {
      uVar12 = param_15[3];
      uVar5 = param_15[2];
      goto LAB_0006f620;
    }
    uVar5 = param_15[2];
    if (uVar5 != 2) {
      uVar12 = param_15[3];
      goto LAB_0006f620;
    }
    uVar12 = param_15[3];
    if (uVar12 != 3) goto LAB_0006f620;
  }
  else {
    uVar7 = param_16[3];
    uVar12 = param_15[3];
    uVar11 = param_16[1];
    uVar9 = param_16[2];
    uVar13 = *param_15;
    uVar6 = param_15[1];
    uVar5 = param_15[2];
LAB_0006f620:
    uVar1 = uVar1 | 0x400000;
    uVar2 = (uVar7 & 1) << 0xf |
            (uVar12 & 7) << 0xc |
            (uVar9 & 1) << 0xb |
            (uVar5 & 7) << 8 |
            (uVar11 & 1) << 7 | (uVar6 & 7) << 4 | (*param_16 & 1) << 3 | uVar13 & 7;
  }
  iVar15 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar10) {
    uVar4 = (**(code **)(iVar15 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar15 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar10 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar10 * 4 + *(int *)(param_1 + 0x75c)) = 0x47;
  uVar10 = *puVar17 + 1;
  *puVar17 = uVar10;
  iVar15 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar10) {
    uVar4 = (**(code **)(iVar15 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar15 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar10 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar10 * 4 + *(int *)(param_1 + 0x75c)) = uVar14 | 0x440000;
  uVar10 = *puVar17 + 1;
  *puVar17 = uVar10;
  iVar15 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar10) {
    uVar4 = (**(code **)(iVar15 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar15 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar10 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar10 * 4 + *(int *)(param_1 + 0x75c)) = 0x40;
  uVar10 = *puVar17 + 1;
  *puVar17 = uVar10;
  iVar15 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar10) {
    uVar4 = (**(code **)(iVar15 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar15 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar10 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar10 * 4 + *(int *)(param_1 + 0x75c)) = uVar1;
  uVar10 = *puVar17 + 1;
  *puVar17 = uVar10;
  if ((uVar1 & 0x400000) != 0) {
    iVar15 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar10) {
      uVar4 = (**(code **)(iVar15 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
        (**(code **)(iVar15 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar10 = *puVar17;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar10 * 4 + *(int *)(param_1 + 0x75c)) = uVar2;
    uVar10 = *puVar17 + 1;
    *puVar17 = uVar10;
  }
  uVar14 = (param_2 & 0x3f) << 0x10 | param_3 & 0xffff | 0x400000;
  if ((param_2 == 0x12) || (param_2 == 0x13)) {
    uVar14 = uVar14 | 0x400000;
    uVar16 = 0x55;
  }
  if (*param_4 == 0) {
    iVar15 = param_4[3];
    iVar8 = param_4[1];
    iVar3 = param_4[2];
  }
  else {
    iVar8 = param_4[1];
    if (iVar8 == 0) {
      iVar15 = param_4[3];
      iVar3 = param_4[2];
    }
    else {
      iVar3 = param_4[2];
      if (iVar3 == 0) {
        iVar15 = param_4[3];
      }
      else {
        if (param_4[3] != 0) goto LAB_0006f9f0;
        iVar15 = 0;
      }
    }
  }
  uVar14 = uVar14 | 0x400000;
  uVar16 = (uint)(iVar15 != 0) * 0x40 |
           (uint)(iVar3 != 0) * 0x10 | (uint)(iVar8 != 0) * 4 | (uint)(*param_4 != 0);
LAB_0006f9f0:
  iVar15 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar10) {
    uVar4 = (**(code **)(iVar15 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar15 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar10 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar10 * 4 + *(int *)(param_1 + 0x75c)) = 0x39;
  uVar10 = *puVar17 + 1;
  *puVar17 = uVar10;
  iVar15 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar10) {
    uVar4 = (**(code **)(iVar15 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar15 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar10 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar10 * 4 + *(int *)(param_1 + 0x75c)) = uVar14;
  uVar10 = *puVar17 + 1;
  *puVar17 = uVar10;
  if ((uVar14 & 0x400000) != 0) {
    iVar15 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar10) {
      uVar4 = (**(code **)(iVar15 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
        (**(code **)(iVar15 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar10 = *puVar17;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar10 * 4 + *(int *)(param_1 + 0x75c)) = uVar16;
    uVar10 = *puVar17 + 1;
    *puVar17 = uVar10;
  }
  iVar15 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar10) {
    uVar4 = (**(code **)(iVar15 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar17 << 2);
      (**(code **)(iVar15 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar10 = *puVar17;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar10 * 4 + *(int *)(param_1 + 0x75c)) = uStack_84 & 0xffff | 0x40000;
  *puVar17 = *puVar17 + 1;
  (**(code **)(param_1 + 0x74c))(param_1,auStack_88);
  return;
}

/* FUN_0006fd10 @ 0x6fd10 (180 bytes) */
int FUN_0006fd10(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  undefined4 param_3;
{
  uint uVar1;
  
  uVar1 = *param_2;
  if (param_2[1] <= uVar1) {
    uVar1 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if (param_2[2] != 0) {
      _memcpy(uVar1,param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = uVar1;
    uVar1 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar1 * 4 + param_2[2]) = param_3;
  *param_2 = *param_2 + 1;
  return;
}

/* FUN_0006fdd0 @ 0x6fdd0 (1812 bytes) */
int FUN_0006fdd0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  
  iVar4 = *(int *)(param_4 + 0x28);
  if (iVar4 == 0x87c3) {
    *(int *)(param_2 + 0x60) = *(int *)(param_2 + 0x60) + 1;
    *(int *)(param_3 + 0x118) = *(int *)(param_3 + 0x118) + 1;
    *(undefined1 *)(param_4 + 0x3d) = 1;
    iVar4 = *(int *)(param_4 + 0x24);
    if (iVar4 == 0x87bf) {
      uVar6 = 0;
      uVar7 = 0;
      iVar4 = 0;
      bVar1 = true;
      *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 1;
      while (uVar7 < *(uint *)(param_3 + 0x48)) {
        if (!bVar1) goto LAB_000702bc;
        if (*(char *)(iVar4 + *(int *)(param_3 + 0x44) + 0x10) == '\0') {
          uVar6 = 1;
          bVar1 = false;
        }
        else {
          uVar7 = uVar7 + 1;
          iVar4 = iVar4 + 0x28;
        }
      }
      goto LAB_000702b8;
    }
    if (iVar4 == 0x87c0) {
      uVar7 = 0;
      iVar4 = 0;
      bVar1 = true;
      *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 4;
      while (uVar7 < *(int *)(param_3 + 0x48) - 3U) {
        if (!bVar1) goto LAB_000703cc;
        if (*(char *)(iVar4 + *(int *)(param_3 + 0x44) + 0x10) == '\0') {
          bVar1 = false;
        }
        else {
          uVar7 = uVar7 + 1;
          iVar4 = iVar4 + 0x28;
        }
      }
      if (!bVar1) {
LAB_000703cc:
        iVar8 = uVar7 * 0x28;
        iVar4 = iVar8 + *(int *)(param_3 + 0x44);
        if (((*(char *)(iVar4 + 0x38) == '\0') && (*(char *)(iVar4 + 0x60) == '\0')) &&
           (*(char *)(iVar4 + 0x88) == '\0')) {
          iVar4 = 0;
          iVar10 = 4;
          do {
            iVar2 = uVar7 + iVar4;
            iVar4 = iVar4 + 1;
            *(int *)(param_4 + 0x10) = iVar2;
            param_4 = param_4 + 4;
            iVar2 = *(int *)(param_3 + 0x44) + iVar8;
            iVar8 = iVar8 + 0x28;
            *(undefined1 *)(iVar2 + 0x10) = 1;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
          return 0;
        }
      }
      *(undefined1 *)(param_2 + 0x10) = 0;
      iVar10 = *(int *)(param_3 + 0x48);
      uVar9 = (**(code **)(param_1 + 0x10))(iVar10 + 0x40,0x28);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar9,*(undefined4 *)(param_3 + 0x44),*(int *)(param_3 + 0x48) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x44));
      *(undefined4 *)(param_3 + 0x44) = uVar9;
      iVar4 = iVar10 * 0x28;
      iVar2 = 4;
      iVar8 = 0;
      *(int *)(param_3 + 0x48) = *(int *)(param_3 + 0x48) + 0x40;
      do {
        iVar3 = iVar10 + iVar8;
        iVar8 = iVar8 + 1;
        *(int *)(param_4 + 0x10) = iVar3;
        param_4 = param_4 + 4;
        iVar3 = *(int *)(param_3 + 0x44) + iVar4;
        iVar4 = iVar4 + 0x28;
        *(undefined1 *)(iVar3 + 0x10) = 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      return 0;
    }
    if (iVar4 != 0x87be) {
      return 1;
    }
    uVar9 = 0;
    uVar7 = 0;
    iVar4 = 0;
    bVar1 = true;
    *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 1;
    while (uVar7 < *(uint *)(param_3 + 0x48)) {
      if (!bVar1) goto LAB_000701ac;
      if (*(char *)(iVar4 + *(int *)(param_3 + 0x44) + 0x10) == '\0') {
        uVar9 = 1;
        bVar1 = false;
      }
      else {
        uVar7 = uVar7 + 1;
        iVar4 = iVar4 + 0x28;
      }
    }
  }
  else {
    if (iVar4 == 0x87c4) {
      return 0;
    }
    if (iVar4 != 0x87c2) {
      return 1;
    }
    *(int *)(param_2 + 0x5c) = *(int *)(param_2 + 0x5c) + 1;
    if (*(char *)(param_4 + 0x44) == '\0') {
      *(int *)(param_3 + 0x118) = *(int *)(param_3 + 0x118) + 1;
    }
    else {
      *(int *)(param_3 + 0x120) = *(int *)(param_3 + 0x120) + 1;
    }
    iVar4 = *(int *)(param_4 + 0x24);
    *(undefined1 *)(param_4 + 0x3d) = 1;
    if (iVar4 == 0x87bf) {
      uVar6 = 0;
      uVar7 = 0;
      iVar4 = 0;
      bVar1 = true;
      *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 1;
      while (uVar7 < *(uint *)(param_3 + 0x48)) {
        if (!bVar1) goto LAB_000702bc;
        if (*(char *)(iVar4 + *(int *)(param_3 + 0x44) + 0x10) == '\0') {
          uVar6 = 1;
          bVar1 = false;
        }
        else {
          uVar7 = uVar7 + 1;
          iVar4 = iVar4 + 0x28;
        }
      }
LAB_000702b8:
      if (!bVar1) {
LAB_000702bc:
        *(uint *)(param_4 + 4) = uVar7;
        *(undefined1 *)(uVar7 * 0x28 + *(int *)(param_3 + 0x44) + 0x10) = 1;
        return 0;
      }
      *(undefined1 *)(param_2 + 0x10) = uVar6;
      iVar4 = *(int *)(param_3 + 0x48);
      uVar9 = (**(code **)(param_1 + 0x10))(iVar4 + 0x40,0x28);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar9,*(undefined4 *)(param_3 + 0x44),*(int *)(param_3 + 0x48) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x44));
      *(undefined4 *)(param_3 + 0x44) = uVar9;
      *(int *)(param_3 + 0x48) = *(int *)(param_3 + 0x48) + 0x40;
      goto LAB_00070350;
    }
    if (iVar4 == 0x87c0) {
      uVar7 = 0;
      iVar4 = 0;
      bVar1 = true;
      *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 4;
      while (uVar7 < *(int *)(param_3 + 0x48) - 3U) {
        if (!bVar1) goto LAB_0006ffbc;
        if (*(char *)(iVar4 + *(int *)(param_3 + 0x44) + 0x10) == '\0') {
          bVar1 = false;
        }
        else {
          uVar7 = uVar7 + 1;
          iVar4 = iVar4 + 0x28;
        }
      }
      if (!bVar1) {
LAB_0006ffbc:
        iVar8 = uVar7 * 0x28;
        iVar4 = iVar8 + *(int *)(param_3 + 0x44);
        if (((*(char *)(iVar4 + 0x38) == '\0') && (*(char *)(iVar4 + 0x60) == '\0')) &&
           (*(char *)(iVar4 + 0x88) == '\0')) {
          iVar4 = 0;
          iVar10 = 4;
          do {
            iVar2 = uVar7 + iVar4;
            iVar4 = iVar4 + 1;
            *(int *)(param_4 + 0x10) = iVar2;
            param_4 = param_4 + 4;
            iVar2 = *(int *)(param_3 + 0x44) + iVar8;
            iVar8 = iVar8 + 0x28;
            *(undefined1 *)(iVar2 + 0x10) = 1;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
          return 0;
        }
      }
      *(undefined1 *)(param_2 + 0x10) = 0;
      iVar10 = *(int *)(param_3 + 0x48);
      uVar9 = (**(code **)(param_1 + 0x10))(iVar10 + 0x40,0x28);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar9,*(undefined4 *)(param_3 + 0x44),*(int *)(param_3 + 0x48) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x44));
      *(undefined4 *)(param_3 + 0x44) = uVar9;
      iVar4 = iVar10 * 0x28;
      iVar2 = 4;
      iVar8 = 0;
      *(int *)(param_3 + 0x48) = *(int *)(param_3 + 0x48) + 0x40;
      do {
        iVar3 = iVar10 + iVar8;
        iVar8 = iVar8 + 1;
        *(int *)(param_4 + 0x10) = iVar3;
        param_4 = param_4 + 4;
        iVar3 = iVar4 + *(int *)(param_3 + 0x44);
        iVar4 = iVar4 + 0x28;
        *(undefined1 *)(iVar3 + 0x10) = 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      return 0;
    }
    if (iVar4 != 0x87be) {
      return 1;
    }
    uVar9 = 0;
    uVar7 = 0;
    iVar4 = 0;
    bVar1 = true;
    *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 1;
    while (uVar7 < *(uint *)(param_3 + 0x48)) {
      if (!bVar1) goto LAB_000701ac;
      if (*(char *)(iVar4 + *(int *)(param_3 + 0x44) + 0x10) == '\0') {
        uVar9 = 1;
        bVar1 = false;
      }
      else {
        uVar7 = uVar7 + 1;
        iVar4 = iVar4 + 0x28;
      }
    }
  }
  if (!bVar1) {
LAB_000701ac:
    *(uint *)(param_4 + 4) = uVar7;
    *(undefined4 *)(param_4 + 8) = 0;
    *(undefined1 *)(uVar7 * 0x28 + *(int *)(param_3 + 0x44) + 0x10) = 1;
    return 0;
  }
  *(char *)(param_2 + 0x10) = (char)uVar9;
  iVar4 = *(int *)(param_3 + 0x48);
  uVar5 = (**(code **)(param_1 + 0x10))(iVar4 + 0x40,0x28);
  (**(code **)(((unsigned char *)0x00001344) + param_1))
            (uVar5,*(undefined4 *)(param_3 + 0x44),*(int *)(param_3 + 0x48) * 0x28);
  (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x44));
  *(undefined4 *)(param_3 + 0x44) = uVar5;
  *(int *)(param_3 + 0x48) = *(int *)(param_3 + 0x48) + 0x40;
  *(undefined4 *)(param_4 + 8) = uVar9;
LAB_00070350:
  *(int *)(param_4 + 4) = iVar4;
  *(undefined1 *)(iVar4 * 0x28 + *(int *)(param_3 + 0x44) + 0x10) = 1;
  return 0;
}

/* FUN_00070520 @ 0x70520 (252 bytes) */
int FUN_00070520(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int *param_4;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if (*param_4 == 2) {
    iVar1 = *(int *)(param_2 + 0x20);
    iVar4 = param_4[1] * 0x54;
    iVar2 = iVar4 + iVar1;
    if (*(char *)(iVar2 + 0x3d) == '\0') {
      if (*(int *)(iVar2 + 0x30) == 0) {
        if (*(uint *)(iVar2 + 0x34) < 2) {
          iVar1 = ((int (*)())FUN_0006fdd0)(param_1,param_2,param_3,iVar2);
          if (iVar1 != 1) {
            return 0;
          }
          return 1;
        }
      }
      else {
        iVar4 = FUN_00054da0(param_2 + 0x1c,*(int *)(iVar2 + 0x30));
        iVar1 = *(int *)(param_2 + 0x20);
        iVar4 = iVar4 * 0x54;
      }
      if (*(int *)(iVar4 + iVar1 + 0x34) != 0) {
        uVar3 = 0;
        iVar2 = iVar4;
        do {
          iVar1 = ((int (*)())FUN_0006fdd0)(param_1,param_2,param_3,iVar1 + iVar2);
          if (iVar1 == 1) {
            return 1;
          }
          iVar1 = *(int *)(param_2 + 0x20);
          uVar3 = uVar3 + 1;
          iVar2 = iVar2 + 0x54;
        } while (uVar3 < *(uint *)(iVar1 + iVar4 + 0x34));
      }
    }
  }
  return 0;
}

/* FUN_00070630 @ 0x70630 (1412 bytes) */
int FUN_00070630(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int *param_4;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  if (*param_4 == 2) {
    iVar10 = param_4[1];
    iVar11 = iVar10 * 0x54 + *(int *)(param_2 + 0x20);
    if ((*(int *)(iVar11 + 0x28) == 0x87c4) && (*(char *)(iVar11 + 0x3d) == '\0')) {
      *(undefined1 *)(iVar11 + 0x3d) = 1;
      *(int *)(param_2 + 100) = *(int *)(param_2 + 100) + 1;
      iVar7 = *(int *)(iVar10 * 0x54 + *(int *)(param_2 + 0x20) + 0x24);
      if (iVar7 == 0x87bf) {
        uVar5 = 0;
        uVar6 = 0;
        bVar1 = true;
        while (uVar5 < *(uint *)(param_3 + 0x40)) {
          if (!bVar1) goto LAB_000708f8;
          if (*(char *)(uVar5 * 0x28 + *(int *)(param_3 + 0x3c) + 0x10) == '\0') {
            uVar6 = 1;
            bVar1 = false;
          }
          else {
            uVar5 = uVar5 + 1;
          }
        }
        if (bVar1) {
          *(undefined1 *)(param_2 + 0x10) = uVar6;
          uVar5 = *(uint *)(param_3 + 0x40);
          uVar4 = (**(code **)(param_1 + 0x10))(uVar5 + 0x40,0x28);
          (**(code **)(((unsigned char *)0x00001344) + param_1))
                    (uVar4,*(undefined4 *)(param_3 + 0x3c),*(int *)(param_3 + 0x40) * 0x28);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x3c));
          *(undefined4 *)(param_3 + 0x3c) = uVar4;
          *(int *)(param_3 + 0x40) = *(int *)(param_3 + 0x40) + 0x40;
          *(uint *)(iVar11 + 4) = uVar5;
        }
        else {
LAB_000708f8:
          *(uint *)(iVar11 + 4) = uVar5;
        }
        iVar11 = uVar5 * 0x28;
        *(undefined1 *)(*(int *)(param_3 + 0x3c) + iVar11 + 0x10) = 1;
        *(undefined4 *)(iVar11 + *(int *)(param_3 + 0x3c) + 0x14) = 4;
        *(int *)(iVar11 + *(int *)(param_3 + 0x3c) + 0x18) = iVar10;
        *(int *)(iVar11 + *(int *)(param_3 + 0x3c) + 0x1c) = iVar10;
        *(int *)(iVar11 + *(int *)(param_3 + 0x3c) + 0x20) = iVar10;
        *(int *)(iVar11 + *(int *)(param_3 + 0x3c) + 0x24) = iVar10;
      }
      else if (iVar7 == 0x87c0) {
        uVar5 = 0;
        bVar1 = true;
        while (uVar5 < *(int *)(param_3 + 0x40) - 3U) {
          if (!bVar1) goto LAB_00070a18;
          if (*(char *)(uVar5 * 0x28 + *(int *)(param_3 + 0x3c) + 0x10) == '\0') {
            bVar1 = false;
          }
          else {
            uVar5 = uVar5 + 1;
          }
        }
        if (!bVar1) {
LAB_00070a18:
          iVar8 = uVar5 * 0x28;
          iVar7 = iVar8 + *(int *)(param_3 + 0x3c);
          if (((*(char *)(iVar7 + 0x38) == '\0') && (*(char *)(iVar7 + 0x60) == '\0')) &&
             (*(char *)(iVar7 + 0x88) == '\0')) {
            iVar7 = 0;
            iVar12 = 4;
            do {
              iVar2 = uVar5 + iVar7;
              iVar7 = iVar7 + 1;
              *(int *)(iVar11 + 0x10) = iVar2;
              iVar11 = iVar11 + 4;
              *(undefined1 *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x10) = 1;
              *(undefined4 *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x14) = 4;
              *(int *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x18) = iVar10;
              *(int *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x1c) = iVar10;
              *(int *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x20) = iVar10;
              iVar2 = *(int *)(param_3 + 0x3c) + iVar8;
              iVar8 = iVar8 + 0x28;
              *(int *)(iVar2 + 0x24) = iVar10;
              iVar12 = iVar12 + -1;
            } while (iVar12 != 0);
            return;
          }
        }
        *(undefined1 *)(param_2 + 0x10) = 0;
        iVar12 = *(int *)(param_3 + 0x40);
        uVar4 = (**(code **)(param_1 + 0x10))(iVar12 + 0x40,0x28);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar4,*(undefined4 *)(param_3 + 0x3c),*(int *)(param_3 + 0x40) * 0x28);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x3c));
        *(undefined4 *)(param_3 + 0x3c) = uVar4;
        iVar8 = iVar12 * 0x28;
        iVar2 = 4;
        iVar7 = 0;
        *(int *)(param_3 + 0x40) = *(int *)(param_3 + 0x40) + 0x40;
        do {
          iVar3 = iVar12 + iVar7;
          iVar7 = iVar7 + 1;
          *(int *)(iVar11 + 0x10) = iVar3;
          iVar11 = iVar11 + 4;
          *(undefined1 *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x10) = 1;
          *(undefined4 *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x14) = 4;
          *(int *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x18) = iVar10;
          *(int *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x1c) = iVar10;
          *(int *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x20) = iVar10;
          iVar3 = *(int *)(param_3 + 0x3c) + iVar8;
          iVar8 = iVar8 + 0x28;
          *(int *)(iVar3 + 0x24) = iVar10;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      else if (iVar7 == 0x87be) {
        uVar5 = *(uint *)(param_3 + 0x40);
        uVar9 = 0;
        bVar1 = false;
        iVar7 = 0;
        while (uVar9 < uVar5) {
          if (bVar1) goto LAB_0007075c;
          iVar8 = iVar7 + *(int *)(param_3 + 0x3c);
          if ((*(char *)(iVar8 + 0x10) == '\0') || (bVar1 = true, 3 < *(uint *)(iVar8 + 0x14))) {
            uVar9 = uVar9 + 1;
            iVar7 = iVar7 + 0x28;
            bVar1 = false;
          }
        }
        if (bVar1) {
LAB_0007075c:
          *(uint *)(iVar11 + 4) = uVar9;
          iVar7 = uVar9 * 0x28;
          *(undefined4 *)(iVar11 + 8) = *(undefined4 *)(*(int *)(param_3 + 0x3c) + iVar7 + 0x14);
          iVar11 = iVar7 + *(int *)(param_3 + 0x3c);
          *(int *)(*(int *)(iVar11 + 0x14) * 4 + iVar11 + 0x18) = iVar10;
          iVar7 = iVar7 + *(int *)(param_3 + 0x3c);
          *(int *)(iVar7 + 0x14) = *(int *)(iVar7 + 0x14) + 1;
        }
        else {
          if (uVar5 == 0) {
LAB_000707f4:
            *(undefined1 *)(param_2 + 0x10) = 0;
            uVar9 = *(uint *)(param_3 + 0x40);
            uVar4 = (**(code **)(param_1 + 0x10))(uVar9 + 0x40,0x28);
            (**(code **)(((unsigned char *)0x00001344) + param_1))
                      (uVar4,*(undefined4 *)(param_3 + 0x3c),*(int *)(param_3 + 0x40) * 0x28);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x3c));
            *(undefined4 *)(param_3 + 0x3c) = uVar4;
            *(int *)(param_3 + 0x40) = *(int *)(param_3 + 0x40) + 0x40;
            *(undefined4 *)(iVar11 + 8) = 0;
            *(uint *)(iVar11 + 4) = uVar9;
          }
          else {
            uVar9 = 0;
            do {
              bVar1 = *(char *)(uVar9 * 0x28 + *(int *)(param_3 + 0x3c) + 0x10) != '\0';
              if (bVar1) {
                uVar9 = uVar9 + 1;
              }
              if (uVar5 <= uVar9) {
                if (bVar1) goto LAB_000707f4;
                break;
              }
            } while (bVar1);
            *(uint *)(iVar11 + 4) = uVar9;
            *(undefined4 *)(iVar11 + 8) = 0;
          }
          iVar11 = uVar9 * 0x28;
          *(undefined1 *)(*(int *)(param_3 + 0x3c) + iVar11 + 0x10) = 1;
          *(undefined4 *)(iVar11 + *(int *)(param_3 + 0x3c) + 0x14) = 1;
          *(int *)(iVar11 + *(int *)(param_3 + 0x3c) + 0x18) = iVar10;
        }
      }
    }
  }
  return;
}

/* FUN_00070bf0 @ 0x70bf0 (80 bytes) */
int FUN_00070bf0(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  
  if ((*param_1 == 2) &&
     ((((iVar1 = param_1[1], iVar1 == *(int *)(param_2 + 0x18) ||
        (iVar1 == *(int *)(param_2 + 0x1c))) || (iVar1 == *(int *)(param_2 + 0x20))) ||
      (iVar1 == *(int *)(param_2 + 0x24))))) {
    return 1;
  }
  return 0;
}

/* FUN_00070c50 @ 0x70c50 (4 bytes) */
int FUN_00070c50()
{
  return;
}

/* FUN_00070c60 @ 0x70c60 (4 bytes) */
int FUN_00070c60()
{
  return;
}

/* FUN_00070c70 @ 0x70c70 (84 bytes) */
int FUN_00070c70(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    uVar1 = uVar2;
    if (*(int *)(uVar2 * 4 + param_1 + 0x60) == -1) {
      return uVar2;
    }
    do {
      uVar2 = uVar1 + 1;
      if (0x15 < uVar2) {
        return 0xffffffff;
      }
      uVar1 = uVar2;
    } while (((uVar2 == 1) || (uVar1 = 0x12, uVar2 == 0x12)) || (uVar1 = uVar2, uVar2 == 0x13));
  } while( true );
}

/* FUN_00070cd0 @ 0x70cd0 (144 bytes) */
int FUN_00070cd0(param_1)
  int param_1;
{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  
  iVar3 = *(int *)(param_1 + 0x40);
  if (iVar3 == 0) {
    return -1;
  }
  iVar7 = *(int *)(param_1 + 0x3c);
  if (*(char *)(iVar7 + 0x10) == '\0') {
    iVar4 = 0;
    iVar5 = 0;
    iVar8 = iVar7;
  }
  else {
    pcVar6 = (char *)(iVar7 + 0x38);
    iVar4 = 0;
    iVar2 = 0x28;
    do {
      iVar5 = iVar2;
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + -1;
      if (iVar3 == 0) {
        return -1;
      }
      cVar1 = *pcVar6;
      iVar8 = iVar7 + iVar5;
      pcVar6 = pcVar6 + 0x28;
      iVar2 = iVar5 + 0x28;
    } while (cVar1 != '\0');
  }
  *(undefined1 *)(iVar8 + 0x10) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x3c) + iVar5 + 0x14) = 4;
  return iVar4;
}

/* FUN_00070d80 @ 0x70d80 (3624 bytes) */
int FUN_00070d80(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined *puVar6;
  uint *puVar7;
  
  puVar7 = (uint *)(param_2 + 4);
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (param_4 == 0) {
    if (*(uint *)(param_2 + 8) <= *(uint *)(param_2 + 4)) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(param_2 + 0xc),*(int *)(param_2 + 4) << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar3;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(*puVar7 * 4 + *(int *)(param_2 + 0xc)) = 0x47;
    uVar4 = *puVar7 + 1;
    *puVar7 = uVar4;
    if (*(uint *)(param_2 + 8) <= uVar4) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar3;
      uVar4 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x100000;
    uVar5 = *puVar7 + 1;
    *puVar7 = uVar5;
    uVar4 = *(uint *)(((unsigned char *)0x000013c0) + param_3);
    if (*(uint *)(param_2 + 8) <= uVar5) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar3;
      uVar5 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(uVar5 * 4 + *(int *)(param_2 + 0xc)) = uVar4 & 0xffff | 0x440000;
    puVar6 = (undefined *)0x0;
    uVar4 = *(uint *)(param_2 + 8);
    uVar5 = *puVar7 + 1;
    *puVar7 = uVar5;
    if (uVar4 <= uVar5) {
LAB_00071330:
      uVar3 = (**(code **)(param_1 + 0xc))(uVar4 * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar3;
      uVar5 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
LAB_00071390:
    *(undefined **)(uVar5 * 4 + *(int *)(param_2 + 0xc)) = puVar6;
    *puVar7 = *puVar7 + 1;
  }
  else {
    *(undefined1 *)(param_2 + 3) = 1;
    sVar1 = *(short *)(((unsigned char *)0x00002e04) + iVar2);
    if (sVar1 == 0x801) {
      if (*(uint *)(param_2 + 8) <= *(uint *)(param_2 + 4)) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(int *)(param_2 + 0xc) != 0) {
          _memcpy(uVar3,*(int *)(param_2 + 0xc),*(int *)(param_2 + 4) << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(undefined4 *)(param_2 + 0xc) = uVar3;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(undefined4 *)(*puVar7 * 4 + *(int *)(param_2 + 0xc)) = 0x49;
      uVar5 = *puVar7 + 1;
      *puVar7 = uVar5;
      uVar4 = *(uint *)(((unsigned char *)0x000013c0) + param_3);
      if (*(uint *)(param_2 + 8) <= uVar5) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(int *)(param_2 + 0xc) != 0) {
          _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(undefined4 *)(param_2 + 0xc) = uVar3;
        uVar5 = *puVar7;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(uint *)(uVar5 * 4 + *(int *)(param_2 + 0xc)) = uVar4 & 0xffff | 0x40000;
      uVar4 = *puVar7 + 1;
      *puVar7 = uVar4;
      uVar5 = *(uint *)(((unsigned char *)0x000013c0) + param_3) & 0xffff | 0x40000;
      if (*(uint *)(param_2 + 8) <= uVar4) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(int *)(param_2 + 0xc) != 0) {
          _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(undefined4 *)(param_2 + 0xc) = uVar3;
        uVar4 = *puVar7;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar5;
      uVar4 = *puVar7 + 1;
      *puVar7 = uVar4;
      if (*(uint *)(param_2 + 8) <= uVar4) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(int *)(param_2 + 0xc) != 0) {
          _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(undefined4 *)(param_2 + 0xc) = uVar3;
        uVar4 = *puVar7;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar5;
      uVar4 = *puVar7 + 1;
      *puVar7 = uVar4;
    }
    else {
      if (sVar1 == 0x2601) {
        if (*(uint *)(param_2 + 8) <= *(uint *)(param_2 + 4)) {
          uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(int *)(param_2 + 0xc) != 0) {
            _memcpy(uVar3,*(int *)(param_2 + 0xc),*(int *)(param_2 + 4) << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(undefined4 *)(param_2 + 0xc) = uVar3;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(undefined4 *)(*puVar7 * 4 + *(int *)(param_2 + 0xc)) = 0x23;
        uVar4 = *puVar7 + 1;
        *puVar7 = uVar4;
        if (*(uint *)(param_2 + 8) <= uVar4) {
          uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(int *)(param_2 + 0xc) != 0) {
            _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(undefined4 *)(param_2 + 0xc) = uVar3;
          uVar4 = *puVar7;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x100000;
        uVar5 = *puVar7 + 1;
        *puVar7 = uVar5;
        uVar4 = *(uint *)(((unsigned char *)0x000013c0) + param_3);
        if (*(uint *)(param_2 + 8) <= uVar5) {
          uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(int *)(param_2 + 0xc) != 0) {
            _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(undefined4 *)(param_2 + 0xc) = uVar3;
          uVar5 = *puVar7;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(uint *)(uVar5 * 4 + *(int *)(param_2 + 0xc)) = uVar4 & 0xffff | 0x440000;
        uVar4 = *puVar7 + 1;
        *puVar7 = uVar4;
        if (*(uint *)(param_2 + 8) <= uVar4) {
          uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(int *)(param_2 + 0xc) != 0) {
            _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(undefined4 *)(param_2 + 0xc) = uVar3;
          uVar4 = *puVar7;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(undefined **)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = ((unsigned char *)0x00004054);
        uVar5 = *puVar7 + 1;
        *puVar7 = uVar5;
        uVar4 = *(uint *)(((unsigned char *)0x000013c4) + param_3);
        if (*(uint *)(param_2 + 8) <= uVar5) {
          uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(int *)(param_2 + 0xc) != 0) {
            _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(undefined4 *)(param_2 + 0xc) = uVar3;
          uVar5 = *puVar7;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(uint *)(uVar5 * 4 + *(int *)(param_2 + 0xc)) = uVar4 & 0xffff | 0x410000;
        puVar6 = ((unsigned char *)0x00004214);
        uVar4 = *(uint *)(param_2 + 8);
        uVar5 = *puVar7 + 1;
        *puVar7 = uVar5;
        if (uVar4 <= uVar5) goto LAB_00071330;
        goto LAB_00071390;
      }
      if (sVar1 != 0x800) {
        return;
      }
      uVar4 = *puVar7;
    }
    if (*(uint *)(param_2 + 8) <= uVar4) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar3;
      uVar4 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x49;
    uVar5 = *puVar7 + 1;
    *puVar7 = uVar5;
    uVar4 = *(uint *)(((unsigned char *)0x000013c0) + param_3);
    if (*(uint *)(param_2 + 8) <= uVar5) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar3;
      uVar5 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(uVar5 * 4 + *(int *)(param_2 + 0xc)) = uVar4 & 0xffff | 0x40000;
    uVar5 = *puVar7 + 1;
    *puVar7 = uVar5;
    uVar4 = *(uint *)(((unsigned char *)0x000013c0) + param_3);
    if (*(uint *)(param_2 + 8) <= uVar5) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar3;
      uVar5 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(uVar5 * 4 + *(int *)(param_2 + 0xc)) = uVar4 & 0xffff | 0x40000;
    uVar5 = *puVar7 + 1;
    *puVar7 = uVar5;
    uVar4 = *(uint *)(((unsigned char *)0x000013c4) + param_3);
    if (*(uint *)(param_2 + 8) <= uVar5) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar3;
      uVar5 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(uVar5 * 4 + *(int *)(param_2 + 0xc)) = uVar4 & 0xffff | 0x410000;
    uVar4 = *puVar7 + 1;
    *puVar7 = uVar4;
    if (*(uint *)(param_2 + 8) <= uVar4) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar3;
      uVar4 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x2222;
    uVar4 = *puVar7 + 1;
    *puVar7 = uVar4;
    if (*(uint *)(param_2 + 8) <= uVar4) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar3;
      uVar4 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x2c;
    uVar4 = *puVar7 + 1;
    *puVar7 = uVar4;
    if (*(uint *)(param_2 + 8) <= uVar4) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar3;
      uVar4 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x100000;
    uVar5 = *puVar7 + 1;
    *puVar7 = uVar5;
    uVar4 = *(uint *)(((unsigned char *)0x000013c0) + param_3);
    if (*(uint *)(param_2 + 8) <= uVar5) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar3;
      uVar5 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(uVar5 * 4 + *(int *)(param_2 + 0xc)) = uVar4 & 0xffff | 0x440000;
    uVar4 = *puVar7 + 1;
    *puVar7 = uVar4;
    if (*(uint *)(param_2 + 8) <= uVar4) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar3;
      uVar4 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0;
    *puVar7 = *puVar7 + 1;
  }
  return;
}

/* FUN_00071bc0 @ 0x71bc0 (7188 bytes) */
int FUN_00071bc0(param_1, param_2)
  int param_1;
  int *param_2;
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  int iVar10;
  uint uVar11;
  undefined4 uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  uint uVar24;
  uint uVar25;
  bool bVar26;
  int iVar27;
  uint uStack_58;
  
  iVar22 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar20 = iVar22 + 0x13c;
  *(undefined4 *)(((unsigned char *)0x0000137c) + iVar22) = 0;
  ((unsigned char *)0x000013d0)[iVar22] = 0;
  if ((param_2[6] == 0) || (param_2[5] == 0)) {
    param_2[0x19] = 0;
    param_2[0xc] = 0;
    param_2[0x15] = 0;
    param_2[0x16] = 0;
    param_2[0x17] = 0;
    param_2[0x18] = 0;
    return 1;
  }
  *(undefined1 *)(param_2 + 4) = 1;
  uVar12 = ((int (*)())FUN_00070cd0)(iVar22);
  *(undefined4 *)(((unsigned char *)0x000013c0) + iVar22) = uVar12;
  uVar12 = ((int (*)())FUN_00070cd0)(iVar22);
  *(undefined4 *)(((unsigned char *)0x000013cc) + iVar22) = uVar12;
  iVar27 = 0x16;
  iVar23 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar10 = iVar23;
  do {
    *(undefined4 *)(iVar10 + 0x60) = 0xffffffff;
    *(undefined4 *)(iVar10 + 0xb8) = 0xffffffff;
    iVar10 = iVar10 + 4;
    iVar27 = iVar27 + -1;
  } while (iVar27 != 0);
  iVar10 = 1;
  *(undefined4 *)(((unsigned char *)0x00001398) + iVar23) = 0;
  *(undefined4 *)(iVar23 + 0x110) = 0;
  if (param_2[5] != 0) {
    uVar13 = 0;
    do {
      iVar27 = uVar13 * 0x74;
      iVar19 = param_2[6];
      iVar16 = *(int *)(((unsigned char *)0x0000118c) + param_1);
      iVar17 = *param_2;
      iVar15 = **(int **)(iVar16 * 4 + iVar17);
      if (*(int *)(iVar27 + iVar19 + 0x20) == 2) {
        iVar18 = *(int *)(iVar27 + iVar19 + 0x24) * 0x54;
        iVar14 = iVar18 + param_2[8];
        if ((*(int *)(iVar14 + 0x28) == 0x87c1) && (*(char *)(iVar14 + 0x3d) == '\0')) {
          *(undefined4 *)(iVar18 + param_2[8]) = 0;
          *(undefined1 *)(iVar14 + 0x3d) = 1;
          param_2[0x16] = param_2[0x16] + 1;
          if ((*(char *)(iVar14 + 0x44) == '\0') || (*(int *)(iVar14 + 0x48) == 0x12)) {
            iVar16 = *(int *)(iVar14 + 0x24);
            if (iVar16 == 0x87bf) {
LAB_0007209c:
              iVar17 = iVar10 * 0x28;
              *(int *)(iVar14 + 4) = iVar10;
              iVar10 = iVar10 + 1;
            }
            else if (iVar16 == 0x87c0) {
              *(int *)(iVar14 + 0x1c) = iVar10;
              *(int *)(iVar14 + 0x10) = iVar10;
              *(int *)(iVar14 + 0x14) = iVar10;
              *(int *)(iVar14 + 0x18) = iVar10;
              iVar17 = iVar10 * 0x28;
              iVar10 = iVar10 + 4;
            }
            else {
              iVar17 = 0;
              if (iVar16 == 0x87be) goto LAB_0007209c;
            }
            iVar17 = *(int *)(iVar15 + 0x10) + iVar17;
          }
          else {
            iVar16 = iVar10;
            switch(*(int *)(iVar14 + 0x48)) {
            case 0:
              iVar16 = iVar10 + 1;
              iVar10 = 0;
              iVar17 = 0;
              *(undefined1 *)(iVar15 + 0x18) = 1;
              *(undefined4 *)(iVar15 + 0x60) = 1;
              *(undefined4 *)(iVar15 + 0xb8) = 0;
              break;
            case 1:
              iVar17 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 8;
              *(undefined4 *)(iVar15 + 100) = 1;
              *(int *)(((unsigned char *)0x0000139c) + iVar15) = iVar10;
              *(int *)(iVar15 + 0xbc) = iVar10;
              break;
            case 2:
              iVar19 = *(int *)(iVar14 + 0x4c);
              uVar25 = param_2[0xc];
              iVar17 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              *(undefined1 *)((int)param_2 + iVar19 + 0x34) = 1;
              param_2[0xc] = uVar25 | 4;
              *(int *)(((unsigned char *)0x000013a0) + iVar19 * 4 + iVar15) = iVar10;
              iVar19 = (iVar19 + 10) * 4 + iVar15;
              *(undefined4 *)(iVar19 + 0x60) = 1;
              *(int *)(iVar19 + 0xb8) = iVar10;
              break;
            case 3:
              iVar17 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 1;
              *(undefined4 *)(iVar15 + 0x68) = 1;
              *(int *)(((unsigned char *)0x00001388) + iVar15) = iVar10;
              *(int *)(iVar15 + 0xc0) = iVar10;
              break;
            case 4:
              iVar17 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xc4) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x23) = 1;
              *(undefined4 *)(iVar15 + 0x6c) = 1;
              break;
            case 5:
              iVar17 = iVar10 * 0x28;
              *(int *)(iVar15 + 200) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x24) = 1;
              *(undefined4 *)(iVar15 + 0x70) = 1;
              break;
            case 6:
              iVar17 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xcc) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x25) = 1;
              *(undefined4 *)(iVar15 + 0x74) = 1;
              break;
            case 7:
              iVar17 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xd0) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x22) = 1;
              *(undefined4 *)(iVar15 + 0x78) = 1;
              break;
            case 8:
              iVar17 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xd4) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x27) = 1;
              *(undefined4 *)(iVar15 + 0x7c) = 1;
              break;
            case 9:
              iVar17 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xd8) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x28) = 1;
              *(undefined4 *)(iVar15 + 0x80) = 1;
              break;
            case 10:
              iVar17 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xdc) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x29) = 1;
              *(undefined4 *)(iVar15 + 0x84) = 1;
              break;
            case 0xb:
              iVar17 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xd0) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x26) = 1;
              *(undefined4 *)(iVar15 + 0x78) = 1;
              break;
            case 0xc:
              iVar19 = *(int *)(((unsigned char *)0x00001398) + iVar15);
              if (*(int *)(((unsigned char *)0x00001398) + iVar15) == 0) {
                *(int *)(((unsigned char *)0x00001398) + iVar15) = iVar10;
                iVar16 = iVar10 + 1;
                iVar19 = iVar10;
              }
              iVar17 = iVar19 * 0x28;
              *(undefined4 *)(iVar14 + 8) = 2;
              *(undefined4 *)(iVar15 + 0xa8) = 1;
              *(int *)(iVar15 + 0x100) = iVar19;
              iVar10 = iVar19;
              break;
            case 0xd:
              iVar19 = *(int *)(((unsigned char *)0x00001398) + iVar15);
              if (*(int *)(((unsigned char *)0x00001398) + iVar15) == 0) {
                *(int *)(((unsigned char *)0x00001398) + iVar15) = iVar10;
                iVar16 = iVar10 + 1;
                iVar19 = iVar10;
              }
              iVar17 = iVar19 * 0x28;
              *(undefined4 *)(iVar14 + 8) = 3;
              *(undefined4 *)(iVar15 + 0xa8) = 1;
              *(int *)(iVar15 + 0x100) = iVar19;
              iVar10 = iVar19;
              break;
            case 0xe:
              iVar17 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 2;
              *(undefined4 *)(iVar15 + 0x6c) = 1;
              *(int *)(((unsigned char *)0x0000138c) + iVar15) = iVar10;
              *(int *)(iVar15 + 0xc4) = iVar10;
              break;
            case 0xf:
              iVar17 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 0x40;
              *(int *)((*(unsigned char *)0x00001390) + iVar15) = iVar10;
              *(int *)(iVar15 + 0x100) = iVar10;
              *(undefined4 *)(iVar15 + 0xa8) = 1;
              *(undefined4 *)(iVar14 + 8) = 1;
              break;
            case 0x10:
              iVar17 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 0x80;
              *(undefined4 *)(iVar15 + 0xac) = 1;
              *(int *)(((unsigned char *)0x00001394) + iVar15) = iVar10;
              *(int *)(iVar15 + 0x104) = iVar10;
              break;
            default:
              iVar17 = 0;
              iVar10 = 0;
            }
            *(int *)(iVar14 + 4) = iVar10;
            iVar17 = *(int *)(iVar15 + 0x10) + iVar17;
            iVar10 = iVar16;
          }
          *(undefined1 *)(iVar17 + 0x10) = 1;
          iVar16 = *(int *)(((unsigned char *)0x0000118c) + param_1);
          iVar17 = *param_2;
          iVar19 = param_2[6];
        }
      }
      iVar15 = **(int **)(iVar16 * 4 + iVar17);
      if (*(int *)(iVar27 + iVar19 + 0x3c) == 2) {
        iVar18 = *(int *)(iVar27 + iVar19 + 0x40) * 0x54;
        iVar14 = iVar18 + param_2[8];
        if ((*(int *)(iVar14 + 0x28) == 0x87c1) && (*(char *)(iVar14 + 0x3d) == '\0')) {
          *(undefined4 *)(iVar18 + param_2[8]) = 0;
          *(undefined1 *)(iVar14 + 0x3d) = 1;
          param_2[0x16] = param_2[0x16] + 1;
          if ((*(char *)(iVar14 + 0x44) == '\0') || (*(int *)(iVar14 + 0x48) == 0x12)) {
            iVar16 = *(int *)(iVar14 + 0x24);
            if (iVar16 == 0x87bf) {
LAB_000724bc:
              iVar17 = iVar10 * 0x28;
              *(int *)(iVar14 + 4) = iVar10;
              iVar10 = iVar10 + 1;
            }
            else if (iVar16 == 0x87c0) {
              *(int *)(iVar14 + 0x1c) = iVar10;
              *(int *)(iVar14 + 0x10) = iVar10;
              *(int *)(iVar14 + 0x14) = iVar10;
              *(int *)(iVar14 + 0x18) = iVar10;
              iVar17 = iVar10 * 0x28;
              iVar10 = iVar10 + 4;
            }
            else {
              iVar17 = 0;
              if (iVar16 == 0x87be) goto LAB_000724bc;
            }
            iVar17 = *(int *)(iVar15 + 0x10) + iVar17;
          }
          else {
            iVar16 = iVar10;
            switch(*(int *)(iVar14 + 0x48)) {
            case 0:
              iVar16 = iVar10 + 1;
              iVar10 = 0;
              iVar17 = 0;
              *(undefined1 *)(iVar15 + 0x18) = 1;
              *(undefined4 *)(iVar15 + 0x60) = 1;
              *(undefined4 *)(iVar15 + 0xb8) = 0;
              break;
            case 1:
              iVar17 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 8;
              *(undefined4 *)(iVar15 + 100) = 1;
              *(int *)(((unsigned char *)0x0000139c) + iVar15) = iVar10;
              *(int *)(iVar15 + 0xbc) = iVar10;
              break;
            case 2:
              iVar19 = *(int *)(iVar14 + 0x4c);
              uVar25 = param_2[0xc];
              iVar17 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              *(undefined1 *)((int)param_2 + iVar19 + 0x34) = 1;
              param_2[0xc] = uVar25 | 4;
              *(int *)(((unsigned char *)0x000013a0) + iVar19 * 4 + iVar15) = iVar10;
              iVar19 = (iVar19 + 10) * 4 + iVar15;
              *(undefined4 *)(iVar19 + 0x60) = 1;
              *(int *)(iVar19 + 0xb8) = iVar10;
              break;
            case 3:
              iVar17 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 1;
              *(undefined4 *)(iVar15 + 0x68) = 1;
              *(int *)(((unsigned char *)0x00001388) + iVar15) = iVar10;
              *(int *)(iVar15 + 0xc0) = iVar10;
              break;
            case 4:
              iVar17 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xc4) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x23) = 1;
              *(undefined4 *)(iVar15 + 0x6c) = 1;
              break;
            case 5:
              iVar17 = iVar10 * 0x28;
              *(int *)(iVar15 + 200) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x24) = 1;
              *(undefined4 *)(iVar15 + 0x70) = 1;
              break;
            case 6:
              iVar17 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xcc) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x25) = 1;
              *(undefined4 *)(iVar15 + 0x74) = 1;
              break;
            case 7:
              iVar17 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xd0) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x22) = 1;
              *(undefined4 *)(iVar15 + 0x78) = 1;
              break;
            case 8:
              iVar17 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xd4) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x27) = 1;
              *(undefined4 *)(iVar15 + 0x7c) = 1;
              break;
            case 9:
              iVar17 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xd8) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x28) = 1;
              *(undefined4 *)(iVar15 + 0x80) = 1;
              break;
            case 10:
              iVar17 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xdc) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x29) = 1;
              *(undefined4 *)(iVar15 + 0x84) = 1;
              break;
            case 0xb:
              iVar17 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xd0) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x26) = 1;
              *(undefined4 *)(iVar15 + 0x78) = 1;
              break;
            case 0xc:
              iVar19 = *(int *)(((unsigned char *)0x00001398) + iVar15);
              if (*(int *)(((unsigned char *)0x00001398) + iVar15) == 0) {
                *(int *)(((unsigned char *)0x00001398) + iVar15) = iVar10;
                iVar16 = iVar10 + 1;
                iVar19 = iVar10;
              }
              iVar17 = iVar19 * 0x28;
              *(undefined4 *)(iVar14 + 8) = 2;
              *(undefined4 *)(iVar15 + 0xa8) = 1;
              *(int *)(iVar15 + 0x100) = iVar19;
              iVar10 = iVar19;
              break;
            case 0xd:
              iVar19 = *(int *)(((unsigned char *)0x00001398) + iVar15);
              if (*(int *)(((unsigned char *)0x00001398) + iVar15) == 0) {
                *(int *)(((unsigned char *)0x00001398) + iVar15) = iVar10;
                iVar16 = iVar10 + 1;
                iVar19 = iVar10;
              }
              iVar17 = iVar19 * 0x28;
              *(undefined4 *)(iVar14 + 8) = 3;
              *(undefined4 *)(iVar15 + 0xa8) = 1;
              *(int *)(iVar15 + 0x100) = iVar19;
              iVar10 = iVar19;
              break;
            case 0xe:
              iVar17 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 2;
              *(undefined4 *)(iVar15 + 0x6c) = 1;
              *(int *)(((unsigned char *)0x0000138c) + iVar15) = iVar10;
              *(int *)(iVar15 + 0xc4) = iVar10;
              break;
            case 0xf:
              iVar17 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 0x40;
              *(int *)((*(unsigned char *)0x00001390) + iVar15) = iVar10;
              *(int *)(iVar15 + 0x100) = iVar10;
              *(undefined4 *)(iVar15 + 0xa8) = 1;
              *(undefined4 *)(iVar14 + 8) = 1;
              break;
            case 0x10:
              iVar17 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 0x80;
              *(undefined4 *)(iVar15 + 0xac) = 1;
              *(int *)(((unsigned char *)0x00001394) + iVar15) = iVar10;
              *(int *)(iVar15 + 0x104) = iVar10;
              break;
            default:
              iVar17 = 0;
              iVar10 = 0;
            }
            *(int *)(iVar14 + 4) = iVar10;
            iVar17 = *(int *)(iVar15 + 0x10) + iVar17;
            iVar10 = iVar16;
          }
          *(undefined1 *)(iVar17 + 0x10) = 1;
          iVar16 = *(int *)(((unsigned char *)0x0000118c) + param_1);
          iVar17 = *param_2;
          iVar19 = param_2[6];
        }
      }
      iVar15 = **(int **)(iVar16 * 4 + iVar17);
      if (*(int *)(iVar27 + iVar19 + 0x58) == 2) {
        iVar16 = *(int *)(iVar27 + iVar19 + 0x5c) * 0x54;
        iVar27 = iVar16 + param_2[8];
        if ((*(int *)(iVar27 + 0x28) == 0x87c1) && (*(char *)(iVar27 + 0x3d) == '\0')) {
          *(undefined4 *)(iVar16 + param_2[8]) = 0;
          *(undefined1 *)(iVar27 + 0x3d) = 1;
          param_2[0x16] = param_2[0x16] + 1;
          if ((*(char *)(iVar27 + 0x44) == '\0') || (*(int *)(iVar27 + 0x48) == 0x12)) {
            iVar16 = *(int *)(iVar27 + 0x24);
            if (iVar16 == 0x87bf) {
LAB_000728e4:
              iVar17 = iVar10 * 0x28;
              *(int *)(iVar27 + 4) = iVar10;
              iVar10 = iVar10 + 1;
            }
            else if (iVar16 == 0x87c0) {
              *(int *)(iVar27 + 0x1c) = iVar10;
              *(int *)(iVar27 + 0x10) = iVar10;
              *(int *)(iVar27 + 0x14) = iVar10;
              *(int *)(iVar27 + 0x18) = iVar10;
              iVar17 = iVar10 * 0x28;
              iVar10 = iVar10 + 4;
            }
            else {
              iVar17 = 0;
              if (iVar16 == 0x87be) goto LAB_000728e4;
            }
            *(undefined1 *)(*(int *)(iVar15 + 0x10) + iVar17 + 0x10) = 1;
          }
          else {
            iVar16 = iVar10;
            switch(*(int *)(iVar27 + 0x48)) {
            case 0:
              iVar16 = iVar10 + 1;
              iVar10 = 0;
              iVar17 = 0;
              *(undefined1 *)(iVar15 + 0x18) = 1;
              *(undefined4 *)(iVar15 + 0x60) = 1;
              *(undefined4 *)(iVar15 + 0xb8) = 0;
              break;
            case 1:
              iVar17 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 8;
              *(undefined4 *)(iVar15 + 100) = 1;
              *(int *)(((unsigned char *)0x0000139c) + iVar15) = iVar10;
              *(int *)(iVar15 + 0xbc) = iVar10;
              break;
            case 2:
              iVar19 = *(int *)(iVar27 + 0x4c);
              uVar25 = param_2[0xc];
              iVar17 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              *(undefined1 *)((int)param_2 + iVar19 + 0x34) = 1;
              param_2[0xc] = uVar25 | 4;
              *(int *)(((unsigned char *)0x000013a0) + iVar19 * 4 + iVar15) = iVar10;
              iVar19 = (iVar19 + 10) * 4 + iVar15;
              *(undefined4 *)(iVar19 + 0x60) = 1;
              *(int *)(iVar19 + 0xb8) = iVar10;
              break;
            case 3:
              iVar17 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 1;
              *(undefined4 *)(iVar15 + 0x68) = 1;
              *(int *)(((unsigned char *)0x00001388) + iVar15) = iVar10;
              *(int *)(iVar15 + 0xc0) = iVar10;
              break;
            case 4:
              iVar17 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xc4) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x23) = 1;
              *(undefined4 *)(iVar15 + 0x6c) = 1;
              break;
            case 5:
              iVar17 = iVar10 * 0x28;
              *(int *)(iVar15 + 200) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x24) = 1;
              *(undefined4 *)(iVar15 + 0x70) = 1;
              break;
            case 6:
              iVar17 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xcc) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x25) = 1;
              *(undefined4 *)(iVar15 + 0x74) = 1;
              break;
            case 7:
              iVar17 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xd0) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x22) = 1;
              *(undefined4 *)(iVar15 + 0x78) = 1;
              break;
            case 8:
              iVar17 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xd4) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x27) = 1;
              *(undefined4 *)(iVar15 + 0x7c) = 1;
              break;
            case 9:
              iVar17 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xd8) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x28) = 1;
              *(undefined4 *)(iVar15 + 0x80) = 1;
              break;
            case 10:
              iVar17 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xdc) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x29) = 1;
              *(undefined4 *)(iVar15 + 0x84) = 1;
              break;
            case 0xb:
              iVar17 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xd0) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x26) = 1;
              *(undefined4 *)(iVar15 + 0x78) = 1;
              break;
            case 0xc:
              iVar19 = *(int *)(((unsigned char *)0x00001398) + iVar15);
              if (*(int *)(((unsigned char *)0x00001398) + iVar15) == 0) {
                *(int *)(((unsigned char *)0x00001398) + iVar15) = iVar10;
                iVar16 = iVar10 + 1;
                iVar19 = iVar10;
              }
              iVar17 = iVar19 * 0x28;
              *(undefined4 *)(iVar27 + 8) = 2;
              *(undefined4 *)(iVar15 + 0xa8) = 1;
              *(int *)(iVar15 + 0x100) = iVar19;
              iVar10 = iVar19;
              break;
            case 0xd:
              iVar19 = *(int *)(((unsigned char *)0x00001398) + iVar15);
              if (*(int *)(((unsigned char *)0x00001398) + iVar15) == 0) {
                *(int *)(((unsigned char *)0x00001398) + iVar15) = iVar10;
                iVar16 = iVar10 + 1;
                iVar19 = iVar10;
              }
              iVar17 = iVar19 * 0x28;
              *(undefined4 *)(iVar27 + 8) = 3;
              *(undefined4 *)(iVar15 + 0xa8) = 1;
              *(int *)(iVar15 + 0x100) = iVar19;
              iVar10 = iVar19;
              break;
            case 0xe:
              iVar17 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 2;
              *(undefined4 *)(iVar15 + 0x6c) = 1;
              *(int *)(((unsigned char *)0x0000138c) + iVar15) = iVar10;
              *(int *)(iVar15 + 0xc4) = iVar10;
              break;
            case 0xf:
              iVar17 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 0x40;
              *(int *)((*(unsigned char *)0x00001390) + iVar15) = iVar10;
              *(int *)(iVar15 + 0x100) = iVar10;
              *(undefined4 *)(iVar15 + 0xa8) = 1;
              *(undefined4 *)(iVar27 + 8) = 1;
              break;
            case 0x10:
              iVar17 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 0x80;
              *(undefined4 *)(iVar15 + 0xac) = 1;
              *(int *)(((unsigned char *)0x00001394) + iVar15) = iVar10;
              *(int *)(iVar15 + 0x104) = iVar10;
              break;
            default:
              iVar17 = 0;
              iVar10 = 0;
            }
            *(int *)(iVar27 + 4) = iVar10;
            *(undefined1 *)(*(int *)(iVar15 + 0x10) + iVar17 + 0x10) = 1;
            iVar10 = iVar16;
          }
        }
      }
      uVar13 = uVar13 + 1;
    } while (uVar13 < (uint)param_2[5]);
  }
  *(int *)(iVar23 + 0x130) = iVar10;
  if (param_2[5] != 0) {
    uVar13 = 0;
    iVar10 = 0;
    do {
      iVar17 = param_2[6];
      iVar15 = *(int *)(((unsigned char *)0x0000118c) + param_1);
      iVar16 = *param_2;
      iVar27 = **(int **)(iVar15 * 4 + iVar16);
      if (*(int *)(iVar10 + iVar17 + 0x20) == 2) {
        iVar19 = param_2[8];
        iVar18 = *(int *)(iVar10 + iVar17 + 0x24) * 0x54;
        iVar14 = iVar18 + iVar19;
        if ((*(int *)(iVar14 + 0x28) == 0x87c1) &&
           ((((*(char *)(iVar14 + 0x44) == '\0' || (*(int *)(iVar14 + 0x48) == 0x12)) &&
             (iVar14 != 0)) && (*(int *)(iVar18 + iVar19) == 0)))) {
          *(undefined1 *)(iVar14 + 0x3d) = 1;
          if (*(int *)(iVar14 + 0x24) == 0x87bf) {
            iVar15 = ((int (*)())FUN_00070c70)(iVar27);
            iVar27 = iVar15 * 4 + iVar27;
            *(undefined4 *)(iVar27 + 0xb8) = *(undefined4 *)(iVar14 + 4);
            *(undefined4 *)(iVar27 + 0x60) = 1;
            uVar12 = (**(code **)(((unsigned char *)0x000012a8) + param_1))(param_1,iVar15,4);
            *(undefined4 *)(iVar18 + iVar19) = uVar12;
            iVar15 = *(int *)(((unsigned char *)0x0000118c) + param_1);
            iVar16 = *param_2;
            iVar17 = param_2[6];
          }
          else {
            iVar15 = *(int *)(((unsigned char *)0x0000118c) + param_1);
            iVar16 = *param_2;
            iVar17 = param_2[6];
          }
        }
      }
      iVar27 = **(int **)(iVar15 * 4 + iVar16);
      if (*(int *)(iVar10 + iVar17 + 0x3c) == 2) {
        iVar19 = param_2[8];
        iVar18 = *(int *)(iVar10 + iVar17 + 0x40) * 0x54;
        iVar14 = iVar18 + iVar19;
        if ((((*(int *)(iVar14 + 0x28) == 0x87c1) &&
             ((*(char *)(iVar14 + 0x44) == '\0' || (*(int *)(iVar14 + 0x48) == 0x12)))) &&
            (iVar14 != 0)) && (*(int *)(iVar18 + iVar19) == 0)) {
          *(undefined1 *)(iVar14 + 0x3d) = 1;
          if (*(int *)(iVar14 + 0x24) == 0x87bf) {
            iVar15 = ((int (*)())FUN_00070c70)(iVar27);
            iVar27 = iVar15 * 4 + iVar27;
            *(undefined4 *)(iVar27 + 0xb8) = *(undefined4 *)(iVar14 + 4);
            *(undefined4 *)(iVar27 + 0x60) = 1;
            uVar12 = (**(code **)(((unsigned char *)0x000012a8) + param_1))(param_1,iVar15,4);
            *(undefined4 *)(iVar18 + iVar19) = uVar12;
            iVar15 = *(int *)(((unsigned char *)0x0000118c) + param_1);
            iVar16 = *param_2;
            iVar17 = param_2[6];
          }
          else {
            iVar15 = *(int *)(((unsigned char *)0x0000118c) + param_1);
            iVar16 = *param_2;
            iVar17 = param_2[6];
          }
        }
      }
      iVar27 = **(int **)(iVar15 * 4 + iVar16);
      if (*(int *)(iVar10 + iVar17 + 0x58) == 2) {
        iVar15 = param_2[8];
        iVar17 = *(int *)(iVar10 + iVar17 + 0x5c) * 0x54;
        iVar16 = iVar17 + iVar15;
        if (((*(int *)(iVar16 + 0x28) == 0x87c1) &&
            ((*(char *)(iVar16 + 0x44) == '\0' || (*(int *)(iVar16 + 0x48) == 0x12)))) &&
           ((iVar16 != 0 &&
            ((*(int *)(iVar17 + iVar15) == 0 &&
             (*(undefined1 *)(iVar16 + 0x3d) = 1, *(int *)(iVar16 + 0x24) == 0x87bf)))))) {
          iVar19 = ((int (*)())FUN_00070c70)(iVar27);
          iVar27 = iVar19 * 4 + iVar27;
          *(undefined4 *)(iVar27 + 0xb8) = *(undefined4 *)(iVar16 + 4);
          *(undefined4 *)(iVar27 + 0x60) = 1;
          uVar12 = (**(code **)(((unsigned char *)0x000012a8) + param_1))(param_1,iVar19,4);
          *(undefined4 *)(iVar17 + iVar15) = uVar12;
        }
      }
      uVar13 = uVar13 + 1;
      iVar10 = iVar10 + 0x74;
    } while (uVar13 < (uint)param_2[5]);
  }
  iVar27 = 0x16;
  iVar10 = iVar23;
  do {
    if (*(int *)(iVar10 + 0x60) != -1) {
      *(int *)(iVar23 + 0x110) = *(int *)(iVar23 + 0x110) + 1;
    }
    iVar10 = iVar10 + 4;
    iVar27 = iVar27 + -1;
  } while (iVar27 != 0);
  *(undefined4 *)(iVar22 + 0x118) = 0;
  *(undefined4 *)(iVar22 + 0x120) = 0;
  if (param_2[5] != 0) {
    uVar13 = 0;
    iVar10 = 0;
    do {
      iVar23 = ((int (*)())FUN_00070520)(param_1,param_2,iVar22,iVar10 + param_2[6] + 0x20);
      if (((iVar23 == 1) ||
          (iVar23 = ((int (*)())FUN_00070520)(param_1,param_2,iVar22,iVar10 + param_2[6] + 0x3c), iVar23 == 1))
         || (iVar23 = ((int (*)())FUN_00070520)(param_1,param_2,iVar22,iVar10 + param_2[6] + 0x58), iVar23 == 1))
      {
        param_2[0x19] = 0;
        param_2[0xc] = 0;
        param_2[0x15] = 0;
        param_2[0x16] = 0;
        param_2[0x17] = 0;
        param_2[0x18] = 0;
        return 0;
      }
      uVar13 = uVar13 + 1;
      iVar10 = iVar10 + 0x74;
    } while (uVar13 < (uint)param_2[5]);
  }
  uVar25 = 0;
  iVar10 = iVar22 + 0x140;
  *(undefined4 *)(iVar22 + 4) = 0;
  ((int (*)())FUN_0006fd10)(param_1,iVar10,1);
  ((int (*)())FUN_0006fd10)(param_1,iVar10,0x200);
  uVar13 = 0;
  if (*(int *)(iVar22 + 0x130) != 0) {
    do {
      ((int (*)())FUN_0006fd10)(param_1,iVar10,(uVar25 & 0x3fff) << 0x10 | 0x1a);
      uVar13 = uVar25 & 0xffff;
      uVar25 = uVar25 + 1;
      ((int (*)())FUN_0006fd10)(param_1,iVar10,uVar13 | 0x50000);
      uVar13 = *(uint *)(iVar22 + 0x130);
    } while (uVar25 < uVar13);
  }
  *(uint *)(((unsigned char *)0x00001178) + iVar22) = uVar13;
  uVar13 = param_2[7];
  if (uVar13 != 0) {
    uVar25 = 0;
    iVar23 = 0;
    do {
      iVar27 = iVar23 + param_2[8];
      if ((iVar27 != 0) && (*(int *)(iVar27 + 0x28) == 0x87c3)) {
        iVar15 = *(int *)(iVar27 + 0x24);
        if (iVar15 == 0x87bf) {
          uVar13 = *(uint *)(iVar27 + 4);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,0x1c);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,uVar13 & 0xffff | 0x10000);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,**(undefined4 **)(iVar23 + param_2[8] + 0x38));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(iVar23 + param_2[8] + 0x38) + 4));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(iVar23 + param_2[8] + 0x38) + 8));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(iVar23 + param_2[8] + 0x38) + 0xc));
          uVar13 = param_2[7];
        }
        else if (iVar15 == 0x87c0) {
          uVar13 = *(uint *)(iVar27 + 0x10);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,0x1c);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,uVar13 & 0xffff | 0x10000);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,**(undefined4 **)(param_2[8] + iVar23 + 0x38));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(param_2[8] + iVar23 + 0x38) + 4));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(param_2[8] + iVar23 + 0x38) + 8));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(param_2[8] + iVar23 + 0x38) + 0xc));
          uVar13 = *(uint *)(iVar27 + 0x14);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,0x1c);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,uVar13 & 0xffff | 0x10000);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(param_2[8] + iVar23 + 0x38) + 0x10));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(param_2[8] + iVar23 + 0x38) + 0x14));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(param_2[8] + iVar23 + 0x38) + 0x18));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(param_2[8] + iVar23 + 0x38) + 0x1c));
          uVar13 = *(uint *)(iVar27 + 0x18);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,0x1c);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,uVar13 & 0xffff | 0x10000);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(param_2[8] + iVar23 + 0x38) + 0x20));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(iVar23 + param_2[8] + 0x38) + 0x24));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(iVar23 + param_2[8] + 0x38) + 0x28));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(iVar23 + param_2[8] + 0x38) + 0x2c));
          uVar13 = *(uint *)(iVar27 + 0x1c);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,0x1c);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,uVar13 & 0xffff | 0x10000);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(iVar23 + param_2[8] + 0x38) + 0x30));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(iVar23 + param_2[8] + 0x38) + 0x34));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(iVar23 + param_2[8] + 0x38) + 0x38));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(iVar23 + param_2[8] + 0x38) + 0x3c));
          uVar13 = param_2[7];
        }
        else if (iVar15 == 0x87be) {
          uVar13 = *(uint *)(iVar27 + 4);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,0x1c);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,uVar13 & 0xffff | 0x10000);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,**(undefined4 **)(iVar23 + param_2[8] + 0x38));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,**(undefined4 **)(iVar23 + param_2[8] + 0x38));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,**(undefined4 **)(iVar23 + param_2[8] + 0x38));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,**(undefined4 **)(iVar23 + param_2[8] + 0x38));
          uVar13 = param_2[7];
        }
      }
      uVar25 = uVar25 + 1;
      iVar23 = iVar23 + 0x54;
    } while (uVar25 < uVar13);
  }
  uStack_58 = 0;
  if (param_2[5] != 0) {
    uVar13 = 0;
    iVar23 = 0;
    do {
      if (0x20 < *(int *)(iVar23 + param_2[6]) - 0x8782U) {
        param_2[0x19] = 0;
        param_2[0xc] = 0;
        param_2[0x15] = 0;
        param_2[0x16] = 0;
        param_2[0x17] = 0;
        param_2[0x18] = 0;
        return 0;
      }
      ((int (*)())FUN_00070630)(param_1,param_2,iVar22,iVar23 + param_2[6] + 4);
      ((int (*)())FUN_00070630)(param_1,param_2,iVar22,iVar23 + param_2[6] + 0x20);
      ((int (*)())FUN_00070630)(param_1,param_2,iVar22,iVar23 + param_2[6] + 0x3c);
      ((int (*)())FUN_00070630)(param_1,param_2,iVar22,iVar23 + param_2[6] + 0x58);
      if (uStack_58 < (uint)param_2[0x19]) {
        uStack_58 = param_2[0x19];
      }
      iVar27 = (**(code **)(&DAT_001b9d04 + *(int *)(iVar23 + param_2[6]) * 4))
                         (param_1,iVar20,param_2,iVar23 + param_2[6]);
      if (iVar27 < 0) {
        *(undefined1 *)(param_2 + 4) = 0;
        param_2[0xc] = 0;
        param_2[0x15] = 0;
        param_2[0x16] = 0;
        param_2[0x17] = 0;
        param_2[0x18] = 0;
        param_2[0x19] = 0;
        return 0;
      }
      *(int *)(iVar22 + 4) = iVar27 + *(int *)(iVar22 + 4);
      if (*(char *)((int)param_2 + 0x7b) == '\0') {
        iVar27 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
        uVar25 = *(uint *)(iVar27 + 0x40);
        if (uVar25 != 0) {
          uVar21 = 0;
          iVar15 = 0;
          do {
            iVar16 = iVar15 + *(int *)(iVar27 + 0x3c);
            if (*(char *)(iVar16 + 0x10) != '\0') {
              iVar17 = *(int *)(iVar16 + 0x18);
              if ((((iVar17 == 0) && (*(int *)(iVar16 + 0x1c) == 0)) &&
                  ((*(int *)(iVar16 + 0x20) == 0 && (*(int *)(iVar16 + 0x24) == 0)))) ||
                 (uVar11 = param_2[5], uVar11 <= uVar13 + 1)) {
                bVar1 = true;
              }
              else {
                bVar1 = true;
                iVar19 = iVar23 + 0x74 + param_2[6];
                bVar6 = 0;
                bVar7 = 0;
                bVar8 = 0;
                bVar9 = 0;
                uVar24 = uVar13 + 1;
                do {
                  iVar14 = ((int (*)())FUN_00070bf0)(iVar19 + 0x20,iVar16);
                  if (((iVar14 == 0) && (iVar14 = ((int (*)())FUN_00070bf0)(iVar19 + 0x3c,iVar16), iVar14 == 0))
                     && (iVar14 = ((int (*)())FUN_00070bf0)(iVar19 + 0x58,iVar16), iVar14 == 0)) {
                    iVar14 = ((int (*)())FUN_00070bf0)(iVar19 + 4,iVar16);
                    if (iVar14 != 0) {
                      iVar14 = *(int *)(iVar19 + 8);
                      if (*(int *)(iVar14 * 0x54 + param_2[8] + 0x24) == 0x87be) {
                        bVar2 = iVar17 == iVar14;
                        bVar3 = iVar14 == *(int *)(iVar16 + 0x1c);
                        bVar4 = iVar14 == *(int *)(iVar16 + 0x20);
                        bVar5 = iVar14 == *(int *)(iVar16 + 0x24);
                      }
                      else {
                        bVar2 = *(byte *)(iVar19 + 0xf);
                        bVar3 = *(byte *)(iVar19 + 0x13);
                        bVar4 = *(byte *)(iVar19 + 0x17);
                        bVar5 = *(byte *)(iVar19 + 0x1b);
                      }
                      bVar6 = bVar6 | bVar2;
                      bVar7 = bVar7 | bVar3;
                      bVar8 = bVar8 | bVar4;
                      bVar9 = bVar9 | bVar5;
                      if (((bVar6 != 0) && (bVar7 != 0)) && (bVar8 != 0)) {
                        bVar26 = bVar9 != 0;
                        goto LAB_000734d0;
                      }
                    }
                    bVar26 = false;
                  }
                  else {
                    bVar1 = false;
                    bVar26 = true;
                  }
LAB_000734d0:
                  uVar24 = uVar24 + 1;
                } while ((uVar11 != uVar24) && (iVar19 = iVar19 + 0x74, !bVar26));
              }
              if (uVar21 == *(uint *)(((unsigned char *)0x000013c0) + iVar27)) {
                bVar1 = false;
              }
              if ((uVar21 != *(uint *)(((unsigned char *)0x000013cc) + iVar27)) && (bVar1)) {
                *(undefined1 *)(iVar17 * 0x54 + param_2[8] + 0x3d) = 0;
                *(undefined1 *)
                 (*(int *)(*(int *)(iVar27 + 0x3c) + iVar15 + 0x1c) * 0x54 + param_2[8] + 0x3d) = 0;
                *(undefined1 *)
                 (*(int *)(*(int *)(iVar27 + 0x3c) + iVar15 + 0x20) * 0x54 + param_2[8] + 0x3d) = 0;
                *(undefined1 *)
                 (*(int *)(*(int *)(iVar27 + 0x3c) + iVar15 + 0x24) * 0x54 + param_2[8] + 0x3d) = 0;
                *(undefined1 *)(*(int *)(iVar27 + 0x3c) + iVar15 + 0x10) = 0;
                *(undefined4 *)(*(int *)(iVar27 + 0x3c) + iVar15 + 0x14) = 0;
                *(undefined4 *)(*(int *)(iVar27 + 0x3c) + iVar15 + 0x18) = 0;
                *(undefined4 *)(*(int *)(iVar27 + 0x3c) + iVar15 + 0x1c) = 0;
                *(undefined4 *)(*(int *)(iVar27 + 0x3c) + iVar15 + 0x20) = 0;
                *(undefined4 *)(*(int *)(iVar27 + 0x3c) + iVar15 + 0x24) = 0;
                param_2[0x19] = param_2[0x19] + -1;
                uVar25 = *(uint *)(iVar27 + 0x40);
              }
            }
            uVar21 = uVar21 + 1;
            iVar15 = iVar15 + 0x28;
          } while (uVar21 < uVar25);
        }
      }
      uVar13 = uVar13 + 1;
      iVar23 = iVar23 + 0x74;
    } while (uVar13 < (uint)param_2[5]);
  }
  if (*(char *)((int)param_2 + 0x7a) != '\0') {
    bVar1 = (*(uint *)(param_1 + 0x44) & 0x2800) != 0x2800;
    if (bVar1) {
      ((unsigned char *)0x000013c8)[iVar22] = 1;
    }
    else {
      ((unsigned char *)0x000013c9)[iVar22] = ((unsigned char *)0x000011d1)[param_1];
      *(byte *)((int)param_2 + (byte)((unsigned char *)0x000011d1)[param_1] + 0x71) =
           *(byte *)((int)param_2 + (byte)((unsigned char *)0x000011d1)[param_1] + 0x71) | 1;
      ((unsigned char *)0x000013c8)[iVar22] = 0;
    }
    if ((*(uint *)(param_1 + 0x44) & 0x2000) == 0) {
      uVar12 = 1;
    }
    else {
      uVar12 = 0;
      if (bVar1) goto LAB_000736b0;
    }
    iVar23 = *(int *)(iVar22 + 0x4c);
    *(int *)(((unsigned char *)0x000013c4) + iVar22) = iVar23;
    *(int *)(iVar22 + 0x4c) = iVar23 + 1;
    ((int (*)())FUN_00070d80)(param_1,iVar20,iVar22,uVar12);
  }
LAB_000736b0:
  ((int (*)())FUN_0006fd10)(param_1,iVar10,0x28);
  param_2[0x15] = *(int *)(iVar22 + 4);
  param_2[0x19] = uStack_58;
  if (*(int *)(iVar22 + 0x118) != 0) {
    uVar12 = (**(code **)(param_1 + 0xc))(*(int *)(iVar22 + 0x118) << 2);
    *(undefined4 *)(iVar22 + 0x114) = uVar12;
    uVar13 = param_2[7];
    if (uVar13 != 0) {
      uVar25 = 0;
      iVar10 = 0;
      iVar23 = 0;
      do {
        iVar27 = iVar23 + param_2[8];
        if (*(char *)(iVar27 + 0x3d) != '\0') {
          if (*(int *)(iVar27 + 0x28) == 0x87c2) {
            if (*(char *)(iVar27 + 0x44) == '\0') {
LAB_00073754:
              iVar27 = iVar10 * 4;
              iVar10 = iVar10 + 1;
              *(uint *)(iVar27 + *(int *)(iVar22 + 0x114)) = uVar25;
              uVar13 = param_2[7];
            }
          }
          else if (*(int *)(iVar27 + 0x28) == 0x87c3) goto LAB_00073754;
        }
        uVar25 = uVar25 + 1;
        iVar23 = iVar23 + 0x54;
      } while (uVar25 < uVar13);
    }
  }
  if (*(int *)(iVar22 + 0x4c) != 0) {
    uVar12 = (**(code **)(param_1 + 0xc))(*(int *)(iVar22 + 0x4c) * 0x10 + 0x10);
    *(undefined4 *)(iVar22 + 0x124) = uVar12;
    *(undefined4 *)(((unsigned char *)0x00001174) + iVar22) = *(undefined4 *)(iVar22 + 0x4c);
  }
  *(undefined1 *)(iVar22 + 0x36) = *(undefined1 *)((int)param_2 + 0x79);
  iVar20 = (**(code **)(((unsigned char *)0x0000128c) + param_1))(param_1,iVar20);
  if (iVar20 != 0) {
    *(undefined1 *)(param_2 + 4) = 0;
  }
  (**(code **)(((unsigned char *)0x000012b8) + param_1))(param_1,param_2);
  *(undefined1 *)(param_1 + 0x29) = 1;
  ((int (*)())FUN_00076b80)(param_1,param_2);
  *(undefined1 *)(param_2[1] + *(int *)(((unsigned char *)0x0000118c) + param_1)) = 0;
  if (*(int *)(((unsigned char *)0x000013d8) + iVar22) != 0) {
    (**(code **)(param_1 + 0x18))();
    *(undefined4 *)(((unsigned char *)0x000013d8) + iVar22) = 0;
  }
  return *(undefined1 *)(param_2 + 4);
}

/* FUN_000738c0 @ 0x738c0 (2852 bytes) */
int FUN_000738c0(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint *param_2;
  int param_3;
  int *param_4;
  int param_5;
  uint *param_6;
{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined *puVar8;
  uint uVar9;
  undefined *puVar10;
  
  puVar8 = ((unsigned char *)0x00003210);
  switch(param_4[2]) {
  case 0x87d9:
    puVar8 = ((unsigned char *)0x00003218);
  case 0x87d5:
    break;
  case 0x87da:
    puVar8 = ((unsigned char *)0x00003218);
  case 0x87d6:
    puVar8 = (undefined *)((uint)puVar8 | 1);
    break;
  case 0x87db:
    puVar8 = ((unsigned char *)0x00003218);
  case 0x87d7:
    puVar8 = (undefined *)((uint)puVar8 | 2);
    break;
  case 0x87dc:
    puVar8 = ((unsigned char *)0x00003218);
  case 0x87d8:
    puVar8 = (undefined *)((uint)puVar8 | 3);
    break;
  case 0x87dd:
    puVar8 = ((unsigned char *)0x00003214);
    break;
  case 0x87de:
    puVar8 = ((unsigned char *)0x00003215);
  }
  switch(param_4[3]) {
  case 0x87d9:
    puVar8 = (undefined *)((uint)puVar8 | 0x80);
  case 0x87d5:
    puVar8 = (undefined *)((uint)puVar8 & 0xffffff8f);
    break;
  case 0x87da:
    puVar8 = (undefined *)((uint)puVar8 | 0x80);
  case 0x87d6:
    puVar8 = (undefined *)((uint)puVar8 & 0xffffff8f | 0x10);
    break;
  case 0x87db:
    puVar8 = (undefined *)((uint)puVar8 | 0x80);
  case 0x87d7:
    puVar8 = (undefined *)((uint)puVar8 & 0xffffff8f | 0x20);
    break;
  case 0x87dc:
    puVar8 = (undefined *)((uint)puVar8 | 0x80);
  case 0x87d8:
    puVar8 = (undefined *)((uint)puVar8 & 0xffffff8f | 0x30);
    break;
  case 0x87dd:
    puVar8 = (undefined *)((uint)puVar8 & 0xffffff8f | 0x40);
    break;
  case 0x87de:
    puVar8 = (undefined *)((uint)puVar8 & 0xffffff8f | 0x50);
  }
  switch(param_4[4]) {
  case 0x87d9:
    puVar8 = (undefined *)((uint)puVar8 | 0x800);
  case 0x87d5:
    puVar8 = (undefined *)((uint)puVar8 & 0xfffff8ff);
    break;
  case 0x87da:
    puVar8 = (undefined *)((uint)puVar8 | 0x800);
  case 0x87d6:
    puVar8 = (undefined *)((uint)puVar8 & 0xfffff8ff | 0x100);
    break;
  case 0x87db:
    puVar8 = (undefined *)((uint)puVar8 | 0x800);
  case 0x87d7:
    puVar8 = (undefined *)((uint)puVar8 & 0xfffff8ff | 0x200);
    break;
  case 0x87dc:
    puVar8 = (undefined *)((uint)puVar8 | 0x800);
  case 0x87d8:
    puVar8 = (undefined *)((uint)puVar8 & 0xfffff8ff | 0x300);
    break;
  case 0x87dd:
    puVar8 = (undefined *)((uint)puVar8 & 0xfffff8ff | 0x400);
    break;
  case 0x87de:
    puVar8 = (undefined *)((uint)puVar8 & 0xfffff8ff | 0x500);
  }
  switch(param_4[5]) {
  case 0x87d9:
    puVar8 = (undefined *)((uint)puVar8 | 0x8000);
  case 0x87d5:
    puVar8 = (undefined *)((uint)puVar8 & 0xffff8fff);
    break;
  case 0x87da:
    puVar8 = (undefined *)((uint)puVar8 | 0x8000);
  case 0x87d6:
    puVar8 = (undefined *)((uint)puVar8 & 0xffff8fff | 0x1000);
    break;
  case 0x87db:
    puVar8 = (undefined *)((uint)puVar8 | 0x8000);
  case 0x87d7:
    puVar8 = (undefined *)((uint)puVar8 & 0xffff8fff | 0x2000);
    break;
  case 0x87dc:
    puVar8 = (undefined *)((uint)puVar8 | 0x8000);
  case 0x87d8:
    puVar8 = (undefined *)((uint)puVar8 & 0xffff8fff | 0x3000);
    break;
  case 0x87dd:
    puVar8 = (undefined *)((uint)puVar8 & 0xffff8fff | 0x4000);
    break;
  case 0x87de:
    puVar8 = (undefined *)((uint)puVar8 & 0xffff8fff | 0x5000);
  }
  if (param_6 != (uint *)0x0) {
    uVar9 = *param_6;
    uVar2 = uVar9 & 3;
    if (uVar2 == 2) {
      puVar8 = (undefined *)((uint)puVar8 >> 8 & 7 | (uint)puVar8 & 0xfffffff8);
    }
    else if (uVar2 == 3) {
      puVar8 = (undefined *)((uint)puVar8 >> 0xc & 7 | (uint)puVar8 & 0xfffffff8);
    }
    else if (uVar2 == 1) {
      puVar8 = (undefined *)((uint)puVar8 >> 4 & 7 | (uint)puVar8 & 0xfffffff8);
    }
    uVar6 = param_6[1];
    uVar2 = uVar6 & 3;
    if (uVar2 != 1) {
      if (uVar2 == 0) {
        puVar8 = (undefined *)(((uint)puVar8 & 7) << 4 | (uint)puVar8 & 0xffffff8f);
      }
      else if (uVar2 == 2) {
        puVar8 = (undefined *)((uint)puVar8 >> 4 & 0x70 | (uint)puVar8 & 0xffffff8f);
      }
      else if (uVar2 == 3) {
        puVar8 = (undefined *)((uint)puVar8 >> 8 & 0x70 | (uint)puVar8 & 0xffffff8f);
      }
    }
    uVar1 = param_6[2];
    uVar2 = uVar1 & 3;
    if (uVar2 == 1) {
      puVar8 = (undefined *)(((uint)puVar8 & 0x70) << 4 | (uint)puVar8 & 0xfffff8ff);
    }
    else if (uVar2 == 0) {
      puVar8 = (undefined *)(((uint)puVar8 & 7) << 8 | (uint)puVar8 & 0xfffff8ff);
    }
    else if ((uVar2 != 2) && (uVar2 == 3)) {
      puVar8 = (undefined *)((uint)puVar8 >> 4 & 0x700 | (uint)puVar8 & 0xfffff8ff);
    }
    uVar5 = param_6[3];
    uVar2 = uVar5 & 3;
    if (uVar2 == 1) {
      puVar8 = (undefined *)(((uint)puVar8 & 0x70) << 8 | (uint)puVar8 & 0xffff8fff);
    }
    else if (uVar2 == 0) {
      puVar8 = (undefined *)(((uint)puVar8 & 7) << 0xc | (uint)puVar8 & 0xffff8fff);
    }
    else if (uVar2 == 2) {
      puVar8 = (undefined *)(((uint)puVar8 & 0x700) << 4 | (uint)puVar8 & 0xffff8fff);
    }
    if ((uVar9 & 4) != 0) {
      puVar8 = (undefined *)(((uint)puVar8 ^ 8) & 8 | (uint)puVar8 & 0xfffffff7);
    }
    if ((uVar6 & 4) != 0) {
      puVar8 = (undefined *)(((uint)puVar8 ^ 0x80) & 0x80 | (uint)puVar8 & 0xffffff7f);
    }
    if ((uVar1 & 4) != 0) {
      puVar8 = (undefined *)(((uint)puVar8 ^ 0x800) & 0x800 | (uint)puVar8 & 0xfffff7ff);
    }
    if ((uVar5 & 4) != 0) {
      puVar8 = (undefined *)(((uint)puVar8 ^ 0x8000) & 0x8000 | (uint)puVar8 & 0xffff7fff);
    }
    if ((uVar9 & 8) != 0) {
      puVar8 = (undefined *)((uint)puVar8 & 0xffff7777 | 0x100000);
    }
    if ((uVar6 & 8) != 0) {
      puVar8 = (undefined *)((uint)puVar8 & 0xffff7777 | 0x100000);
    }
    if ((uVar1 & 8) != 0) {
      puVar8 = (undefined *)((uint)puVar8 & 0xffff7777 | 0x100000);
    }
    if ((uVar5 & 8) != 0) {
      puVar8 = (undefined *)((uint)puVar8 & 0xffff7777 | 0x100000);
    }
  }
  puVar10 = puVar8;
  if (*param_4 != 2) {
    if (*param_4 != 0) {
      return 0;
    }
    uVar2 = 0x40000;
    goto LAB_00074014;
  }
  iVar4 = param_4[1] * 0x54 + *(int *)(param_3 + 0x20);
  uVar2 = *(uint *)(iVar4 + 0x28);
  iVar7 = *(int *)(iVar4 + 0x24);
  if (uVar2 < 0x87c4) {
    if (uVar2 < 0x87c2) {
      if (uVar2 != 0x87c1) {
        return 0;
      }
      if (iVar7 == 0x87bf) {
        uVar2 = *(uint *)(iVar4 + 4) & 0xffff | 0x50000;
        if ((*(char *)(iVar4 + 0x44) != '\0') && (*(int *)(iVar4 + 0x48) == 1)) {
          puVar10 = (undefined *)((uint)puVar8 & 0xffff8fff | 0x4000);
        }
      }
      else if (iVar7 == 0x87c0) {
        uVar2 = *(uint *)(iVar4 + 0x10) & 0xffff | 0x50000;
      }
      else {
        if (iVar7 != 0x87be) {
          return 0;
        }
        uVar9 = *(uint *)(iVar4 + 8);
        uVar2 = *(uint *)(iVar4 + 4) & 0xffff | 0x50000;
        puVar10 = (undefined *)
                  ((uVar9 & 7) << 0xc |
                  (uVar9 & 7) << 8 | (uVar9 & 7) << 4 | uVar9 & 7 | (uint)puVar8 & 0xffff8888);
        if ((*(char *)(iVar4 + 0x44) != '\0') && (*(int *)(iVar4 + 0x48) == 0xf)) {
          puVar10 = (undefined *)((uint)puVar8 & 0xffff8888 | 0x5441);
        }
      }
      goto LAB_00074014;
    }
    if (iVar7 == 0x87bf) {
      uVar2 = *(uint *)(iVar4 + 4) & 0xffff | 0x10000;
      goto LAB_00074014;
    }
    if (iVar7 == 0x87c0) {
      uVar2 = *(uint *)(iVar4 + 0x10) & 0xffff | 0x10000;
      goto LAB_00074014;
    }
    if (iVar7 != 0x87be) {
      return 0;
    }
    uVar9 = *(uint *)(iVar4 + 8);
    uVar2 = *(uint *)(iVar4 + 4);
    iVar4 = 1;
  }
  else {
    if (uVar2 != 0x87c4) {
      return 0;
    }
    if (iVar7 == 0x87bf) {
      uVar2 = *(uint *)(iVar4 + 4) & 0xffff | 0x40000;
      goto LAB_00074014;
    }
    if (iVar7 == 0x87c0) {
      uVar2 = *(uint *)(iVar4 + 0x10) & 0xffff | 0x40000;
      goto LAB_00074014;
    }
    if (iVar7 != 0x87be) {
      return 0;
    }
    uVar9 = *(uint *)(iVar4 + 8);
    uVar2 = *(uint *)(iVar4 + 4);
    iVar4 = 4;
  }
  uVar2 = uVar2 & 0xffff | iVar4 << 0x10;
  puVar10 = (undefined *)
            ((uVar9 & 7) << 0xc |
            (uVar9 & 7) << 8 | (uVar9 & 7) << 4 | uVar9 & 7 | (uint)puVar8 & 0xffff8888);
LAB_00074014:
  if ((param_5 == 0) && (puVar10 == ((unsigned char *)0x00003210))) {
    if (*(char *)(param_4 + 6) == '\0') {
      uVar9 = *param_2;
      if (param_2[1] <= uVar9) {
        uVar9 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
        if (param_2[2] != 0) {
          _memcpy(uVar9,param_2[2],*param_2 << 2);
          (**(code **)(param_1 + 0x18))(param_2[2]);
        }
        param_2[2] = uVar9;
        uVar9 = *param_2;
        param_2[1] = param_2[1] + 0x80;
      }
      uVar3 = 1;
      *(uint *)(uVar9 * 4 + param_2[2]) = uVar2;
      *param_2 = *param_2 + 1;
    }
    else {
      uVar9 = *param_2;
      if (param_2[1] <= uVar9) {
        uVar9 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
        if (param_2[2] != 0) {
          _memcpy(uVar9,param_2[2],*param_2 << 2);
          (**(code **)(param_1 + 0x18))(param_2[2]);
        }
        param_2[2] = uVar9;
        uVar9 = *param_2;
        param_2[1] = param_2[1] + 0x80;
      }
      *(uint *)(uVar9 * 4 + param_2[2]) = uVar2 | 0x800000;
      uVar2 = *param_2 + 1;
      *param_2 = uVar2;
      if (param_2[1] <= uVar2) {
        uVar2 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
        if (param_2[2] != 0) {
          _memcpy(uVar2,param_2[2],*param_2 << 2);
          (**(code **)(param_1 + 0x18))(param_2[2]);
        }
        param_2[2] = uVar2;
        uVar2 = *param_2;
        param_2[1] = param_2[1] + 0x80;
      }
      uVar3 = 2;
      *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0;
      *param_2 = *param_2 + 1;
    }
  }
  else if (*(char *)(param_4 + 6) == '\0') {
    uVar9 = *param_2;
    if (param_2[1] <= uVar9) {
      uVar9 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if (param_2[2] != 0) {
        _memcpy(uVar9,param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = uVar9;
      uVar9 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    *(uint *)(uVar9 * 4 + param_2[2]) = uVar2 | 0x400000;
    uVar2 = *param_2 + 1;
    *param_2 = uVar2;
    if (param_2[1] <= uVar2) {
      uVar2 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if (param_2[2] != 0) {
        _memcpy(uVar2,param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = uVar2;
      uVar2 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    uVar3 = 2;
    *(undefined **)(uVar2 * 4 + param_2[2]) = puVar10;
    *param_2 = *param_2 + 1;
  }
  else {
    uVar9 = *param_2;
    if (param_2[1] <= uVar9) {
      uVar9 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if (param_2[2] != 0) {
        _memcpy(uVar9,param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = uVar9;
      uVar9 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    *(uint *)(uVar9 * 4 + param_2[2]) = uVar2 | 0xc00000;
    uVar2 = *param_2 + 1;
    *param_2 = uVar2;
    if (param_2[1] <= uVar2) {
      uVar2 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if (param_2[2] != 0) {
        _memcpy(uVar2,param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = uVar2;
      uVar2 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    *(undefined **)(uVar2 * 4 + param_2[2]) = puVar10;
    uVar2 = *param_2 + 1;
    *param_2 = uVar2;
    if (param_2[1] <= uVar2) {
      uVar2 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if (param_2[2] != 0) {
        _memcpy(uVar2,param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = uVar2;
      uVar2 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    uVar3 = 3;
    *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0;
    *param_2 = *param_2 + 1;
  }
  return uVar3;
}

/* FUN_000744d0 @ 0x744d0 (1412 bytes) */
int FUN_000744d0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint *param_2;
  int *param_3;
  int *param_4;
  int param_5;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = 0x55;
  iVar4 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_3);
  if (param_4[2] == 0) {
    uVar5 = 0x54;
  }
  iVar2 = param_4[3];
  if (iVar2 == 0) {
    uVar5 = uVar5 & 0xfffffff3;
  }
  if (param_4[4] == 0) {
    uVar5 = uVar5 & 0xffffffcf;
  }
  if (param_4[5] == 0) {
    uVar5 = uVar5 & 0xffffff3f;
  }
  if (*param_4 == 1) {
    uVar3 = param_4[1];
    if (uVar3 == 0x879b) {
      uVar5 = uVar5 | 0x100;
      *(undefined1 *)((int)param_3 + 0x6d) = 1;
      uVar6 = 0x120000;
    }
    else if (uVar3 < 0x879c) {
      if (uVar3 == 0x610f) {
        uVar5 = uVar5 | 0x100;
        *(undefined1 *)((int)param_3 + 0x6f) = 1;
        uVar6 = 0x120001;
      }
      else if (uVar3 < 0x6110) {
        if (uVar3 != 0x610e) {
          return 0;
        }
        *(undefined1 *)((int)param_3 + 0x79) = 1;
        uVar6 = 0xd0000;
        uVar5 = uVar5 & 0xffffff03;
      }
      else if (uVar3 == 0x6110) {
        uVar5 = uVar5 | 0x100;
        *(undefined1 *)(param_3 + 0x1c) = 1;
        uVar6 = 0x130001;
      }
      else {
        if (uVar3 != 0x879a) {
          return 0;
        }
        uVar6 = 0xe0000;
      }
    }
    else if (uVar3 < 0x87a5) {
      if (uVar3 < 0x879d) {
        uVar5 = uVar5 | 0x100;
        *(undefined1 *)((int)param_3 + 0x6e) = 1;
        uVar6 = 0x130000;
      }
      else {
        uVar6 = uVar3 + 0x7863 & 0xffff | 0x110000;
        if (param_4[2] == 1) {
          *(byte *)((int)param_3 + (uVar3 - 0x872c)) =
               *(byte *)((int)param_3 + (uVar3 - 0x872c)) | 1;
          iVar2 = param_4[3];
        }
        if (iVar2 == 1) {
          *(byte *)((int)param_3 + param_4[1] + -0x872c) =
               *(byte *)((int)param_3 + param_4[1] + -0x872c) | 2;
        }
        if (param_4[4] == 1) {
          *(byte *)((int)param_3 + param_4[1] + -0x872c) =
               *(byte *)((int)param_3 + param_4[1] + -0x872c) | 4;
        }
        if (param_4[5] == 1) {
          *(byte *)((int)param_3 + param_4[1] + -0x872c) =
               *(byte *)((int)param_3 + param_4[1] + -0x872c) | 8;
        }
      }
    }
    else {
      if (uVar3 != 0x87bd) {
        return 0;
      }
      uVar3 = *(uint *)(((unsigned char *)0x000013c0) + iVar4);
      *(undefined1 *)((int)param_3 + 0x7a) = 1;
      *(undefined1 *)(iVar4 + 0x33) = 1;
      uVar6 = uVar3 & 0xffff | 0x40000;
      uVar5 = uVar5 & 0xffffff03;
    }
  }
  else {
    if (*param_4 != 2) {
      return 0;
    }
    iVar4 = param_4[1] * 0x54 + param_3[8];
    iVar2 = *(int *)(iVar4 + 0x24);
    if (*(int *)(iVar4 + 0x28) == 0x87c4) {
      if (iVar2 == 0x87bf) {
        uVar6 = *(uint *)(iVar4 + 4) & 0xffff | 0x40000;
      }
      else if (iVar2 == 0x87c0) {
        uVar6 = *(uint *)(iVar4 + 0x10) & 0xffff | 0x40000;
      }
      else {
        if (iVar2 != 0x87be) {
          return 0;
        }
        iVar2 = *(int *)(iVar4 + 8);
        uVar6 = *(uint *)(iVar4 + 4) & 0xffff | 0x40000;
        if (iVar2 == 1) {
          uVar5 = uVar5 & 0xffffff0c;
        }
        else if (iVar2 == 0) {
          uVar5 = uVar5 & 0xffffff03;
        }
        else if (iVar2 == 2) {
          uVar5 = uVar5 & 0xffffff30;
        }
        else {
          if (iVar2 != 3) {
            return 0;
          }
          uVar5 = uVar5 & 0xffffffc0;
        }
      }
    }
    else {
      if (*(int *)(iVar4 + 0x28) != -1) {
        return 0;
      }
      uVar6 = 0x30000;
    }
  }
  if ((param_5 == 0) && (uVar5 == 0x55)) {
    uVar5 = *param_2;
    if (param_2[1] <= uVar5) {
      uVar5 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if (param_2[2] != 0) {
        _memcpy(uVar5,param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = uVar5;
      uVar5 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    uVar1 = 1;
    *(uint *)(uVar5 * 4 + param_2[2]) = uVar6;
    *param_2 = *param_2 + 1;
  }
  else {
    uVar3 = *param_2;
    if (param_2[1] <= uVar3) {
      uVar3 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if (param_2[2] != 0) {
        _memcpy(uVar3,param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = uVar3;
      uVar3 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    *(uint *)(uVar3 * 4 + param_2[2]) = uVar6 | 0x400000;
    uVar3 = *param_2 + 1;
    *param_2 = uVar3;
    if (param_2[1] <= uVar3) {
      uVar3 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if (param_2[2] != 0) {
        _memcpy(uVar3,param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = uVar3;
      uVar3 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    uVar1 = 2;
    *(uint *)(uVar3 * 4 + param_2[2]) = uVar5;
    *param_2 = *param_2 + 1;
  }
  return uVar1;
}

/* FUN_00074a70 @ 0x74a70 (192 bytes) */
int FUN_00074a70(param_1, param_2, param_3, param_4)
  int param_1;
  uint *param_2;
  uint param_3;
  uint param_4;
{
  uint uVar1;
  
  uVar1 = *param_2;
  if (param_2[1] <= uVar1) {
    uVar1 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if (param_2[2] != 0) {
      _memcpy(uVar1,param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = uVar1;
    uVar1 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(uVar1 * 4 + param_2[2]) = (param_4 & 0x3fff) << 0x10 | param_3 & 0xffff;
  *param_2 = *param_2 + 1;
  return 1;
}

/* FUN_00074b30 @ 0x74b30 (204 bytes) */
int FUN_00074b30(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x48,0);
  if (iVar1 != 0) {
    local_48 = *(undefined4 *)(param_4 + 4);
    local_44 = *(undefined4 *)(param_4 + 8);
    local_30 = *(undefined4 *)(param_4 + 0x1c);
    local_34 = 0;
    local_3c = 0;
    local_38 = 0;
    local_40 = 1;
    iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,&local_48,1);
    if ((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)
       ) {
      return 1;
    }
  }
  return 0xffffffff;
}

/* FUN_00074c00 @ 0x74c00 (188 bytes) */
int FUN_00074c00(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x3d,0);
  if ((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) {
    uStack_2c = 4;
    uStack_34 = 4;
    uStack_30 = 4;
    uStack_38 = 0xc;
    iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,1,&uStack_38);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0xffffffff;
}

/* FUN_00074cc0 @ 0x74cc0 (156 bytes) */
int FUN_00074cc0(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x2e,0);
  if (((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,1,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00074d60 @ 0x74d60 (204 bytes) */
int FUN_00074d60(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x24,0);
  if ((((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
      (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x3c,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00074e30 @ 0x74e30 (156 bytes) */
int FUN_00074e30(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x39,0);
  if (((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00074ed0 @ 0x74ed0 (392 bytes) */
int FUN_00074ed0(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uStack_58;
  uint uStack_54;
  uint uStack_50;
  uint uStack_4c;
  undefined4 uStack_48;
  int iStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  
  iVar1 = FUN_000550e0(param_3 + 0x1c,param_4 + 4);
  uVar4 = *(uint *)(param_4 + 0x40);
  if (3 < uVar4) {
    return 0xffffffff;
  }
  iVar3 = param_2 + 4;
  iVar2 = ((int (*)())FUN_00074a70)(param_1,iVar3,0x47,0);
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  iVar2 = ((int (*)())FUN_000744d0)(param_1,iVar3,param_3,param_4 + 4,0);
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  uStack_30 = *(undefined4 *)(param_4 + 0x38);
  uStack_48 = *(undefined4 *)(param_4 + 0x20);
  iStack_44 = *(int *)(param_4 + 0x24);
  uStack_3c = *(undefined4 *)(param_4 + 0x2c);
  uStack_38 = *(undefined4 *)(param_4 + 0x30);
  uStack_34 = *(undefined4 *)(param_4 + 0x34);
  uStack_40 = *(undefined4 *)(param_4 + 0x28);
  if (iVar1 != 0x87be) {
    iStack_44 = uVar4 + iStack_44;
    iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar3,param_3,&uStack_48,1,0);
    goto LAB_00075028;
  }
  if (uVar4 == 1) {
LAB_00074fd4:
    uStack_58 = uVar4;
    uStack_54 = uVar4;
    uStack_50 = uVar4;
    uStack_4c = uVar4;
  }
  else if (uVar4 == 0) {
    uStack_4c = 0;
    uStack_58 = 0;
    uStack_54 = 0;
    uStack_50 = 0;
  }
  else if ((uVar4 == 2) || (uVar4 == 3)) goto LAB_00074fd4;
  iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar3,param_3,&uStack_48,1,&uStack_58);
LAB_00075028:
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  return 1;
}

/* FUN_00075060 @ 0x75060 (584 bytes) */
int FUN_00075060(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uStack_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  
  iVar1 = FUN_000550e0(param_3 + 0x1c,param_4 + 4);
  uVar4 = *(uint *)(param_4 + 0x40);
  if (3 < uVar4) {
    return 0xffffffff;
  }
  iVar3 = param_2 + 4;
  iVar2 = ((int (*)())FUN_00074a70)(param_1,iVar3,0x47,0);
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  if (iVar1 == 0x87bf) {
    uStack_48 = *(uint *)(param_4 + 4);
    uStack_44 = *(uint *)(param_4 + 8);
    uStack_40 = *(uint *)(param_4 + 0xc);
    uStack_3c = *(uint *)(param_4 + 0x10);
    uStack_38 = *(undefined4 *)(param_4 + 0x14);
    uStack_34 = *(undefined4 *)(param_4 + 0x18);
    uStack_30 = *(undefined4 *)(param_4 + 0x1c);
    if (uVar4 == 1) {
      uStack_34 = 0;
      uStack_40 = 0;
      uStack_38 = 0;
    }
    else if (uVar4 == 0) {
      uStack_34 = 0;
      uStack_3c = 0;
      uStack_38 = 0;
    }
    else if (uVar4 == 2) {
      uStack_34 = 0;
      uStack_40 = 0;
      uStack_3c = 0;
    }
    else if (uVar4 == 3) {
      uStack_38 = 0;
      uStack_40 = 0;
      uStack_3c = 0;
    }
    iVar2 = ((int (*)())FUN_000744d0)(param_1,iVar3,param_3,&uStack_48,1);
  }
  else {
    uStack_48 = *(uint *)(param_4 + 4);
    uStack_40 = *(uint *)(param_4 + 0xc);
    uStack_3c = *(uint *)(param_4 + 0x10);
    uStack_38 = *(undefined4 *)(param_4 + 0x14);
    uStack_34 = *(undefined4 *)(param_4 + 0x18);
    uStack_30 = *(undefined4 *)(param_4 + 0x1c);
    uStack_44 = uVar4 + *(int *)(param_4 + 8);
    iVar2 = ((int (*)())FUN_000744d0)(param_1,iVar3,param_3,&uStack_48,1);
  }
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  if (iVar1 != 0x87bf) {
    ((int (*)())FUN_000738c0)(param_1,iVar3,param_3,param_4 + 0x20,1,0);
    return 1;
  }
  if (uVar4 != 1) {
    if (uVar4 == 0) {
      uStack_3c = 0;
      uStack_48 = 0;
      uStack_44 = 0;
      uStack_40 = 0;
      goto LAB_00075258;
    }
    if ((uVar4 != 2) && (uVar4 != 3)) goto LAB_00075258;
  }
  uStack_48 = uVar4;
  uStack_44 = uVar4;
  uStack_40 = uVar4;
  uStack_3c = uVar4;
LAB_00075258:
  ((int (*)())FUN_000738c0)(param_1,iVar3,param_3,param_4 + 0x20,1,&uStack_48);
  return 1;
}

/* FUN_000752c0 @ 0x752c0 (156 bytes) */
int FUN_000752c0(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x47,0);
  if (((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,1), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075360 @ 0x75360 (156 bytes) */
int FUN_00075360(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x47,0);
  if (((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075400 @ 0x75400 (156 bytes) */
int FUN_00075400(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x47,0);
  if (((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_000754a0 @ 0x754a0 (204 bytes) */
int FUN_000754a0(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x45,0);
  if ((((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
      (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x3c,0,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075570 @ 0x75570 (204 bytes) */
int FUN_00075570(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x13,0);
  if ((((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
      (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x3c,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075640 @ 0x75640 (204 bytes) */
int FUN_00075640(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x5b,0);
  if ((((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
      (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x3c,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075710 @ 0x75710 (156 bytes) */
int FUN_00075710(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x55,3);
  if (((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_000757b0 @ 0x757b0 (156 bytes) */
int FUN_000757b0(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x51,3);
  if (((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075850 @ 0x75850 (204 bytes) */
int FUN_00075850(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x4e,0);
  if ((((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
      (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x3c,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075920 @ 0x75920 (156 bytes) */
int FUN_00075920(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x3c,0);
  if (((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_000759c0 @ 0x759c0 (156 bytes) */
int FUN_000759c0(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x2d,0);
  if (((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075a60 @ 0x75a60 (156 bytes) */
int FUN_00075a60(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x54,0);
  if (((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075b00 @ 0x75b00 (156 bytes) */
int FUN_00075b00(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x30,0);
  if (((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075ba0 @ 0x75ba0 (236 bytes) */
int FUN_00075ba0(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,10,0);
  if ((((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
      (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) &&
     ((iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x3c,0,0), iVar1 != 0 &&
      (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x58,0,0), iVar1 != 0)))) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075c90 @ 0x75c90 (204 bytes) */
int FUN_00075c90(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x56,5);
  if ((((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
      (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x3c,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075d60 @ 0x75d60 (204 bytes) */
int FUN_00075d60(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x56,2);
  if ((((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
      (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x3c,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075e30 @ 0x75e30 (204 bytes) */
int FUN_00075e30(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x44,0);
  if ((((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
      (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x3c,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075f00 @ 0x75f00 (204 bytes) */
int FUN_00075f00(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x41,0);
  if ((((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
      (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x3c,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075fd0 @ 0x75fd0 (156 bytes) */
int FUN_00075fd0(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x31,0);
  if (((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00076070 @ 0x76070 (236 bytes) */
int FUN_00076070(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x40,0);
  if ((((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
      (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) &&
     ((iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x3c,0,0), iVar1 != 0 &&
      (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x58,0,0), iVar1 != 0)))) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00076160 @ 0x76160 (204 bytes) */
int FUN_00076160(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,3,0);
  if ((((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
      (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x3c,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00076230 @ 0x76230 (204 bytes) */
int FUN_00076230(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x49,0);
  if ((((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
      (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x3c,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00076300 @ 0x76300 (204 bytes) */
int FUN_00076300(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x23,0);
  if ((((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
      (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x3c,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_000763d0 @ 0x763d0 (204 bytes) */
int FUN_000763d0(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x22,0);
  if ((((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
      (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) &&
     (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x3c,0,0), iVar1 != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_000764a0 @ 0x764a0 (188 bytes) */
int FUN_000764a0(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x47,0);
  if ((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) {
    uStack_38 = 4;
    uStack_34 = 5;
    uStack_30 = 6;
    uStack_2c = 7;
    iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,1,&uStack_38);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0xffffffff;
}

/* FUN_00076560 @ 0x76560 (524 bytes) */
int FUN_00076560(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar4 = (uint *)(param_2 + 4);
  iVar1 = ((int (*)())FUN_00074a70)(param_1,puVar4,0x48,0);
  if (iVar1 != 0) {
    if (*(uint *)(param_2 + 8) <= *(uint *)(param_2 + 4)) {
      uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar2,*(int *)(param_2 + 0xc),*(int *)(param_2 + 4) << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar2;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(*puVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x430000;
    uVar3 = *puVar4 + 1;
    *puVar4 = uVar3;
    if (*(uint *)(param_2 + 8) <= uVar3) {
      uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar2,*(int *)(param_2 + 0xc),*puVar4 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar2;
      uVar3 = *puVar4;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = 1;
    *puVar4 = *puVar4 + 1;
    iVar1 = ((int (*)())FUN_000738c0)(param_1,puVar4,param_3,param_4 + 0x20,0,0);
    if (iVar1 != 0) {
      ((int (*)())FUN_00074a70)(param_1,puVar4,0x47,0);
      iVar1 = ((int (*)())FUN_000744d0)(param_1,puVar4,param_3,param_4 + 4,0);
      if (iVar1 != 0) {
        *(undefined1 *)(param_4 + 0x54) = 1;
        iVar1 = ((int (*)())FUN_000738c0)(param_1,puVar4,param_3,param_4 + 0x3c,0,0);
        if (iVar1 != 0) {
          return 1;
        }
      }
    }
  }
  return 0xffffffff;
}

/* FUN_00076770 @ 0x76770 (352 bytes) */
int FUN_00076770(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int *param_3;
{
  short sVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  
  iVar4 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_3);
  if (*(int *)(iVar4 + 0x4c) == 0) {
    return;
  }
  iVar3 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((*(char *)((int)param_3 + 0x7a) != '\0') && (((unsigned char *)0x00002e0a)[iVar3] != '\0')) {
    sVar1 = *(short *)(((unsigned char *)0x00002e04) + iVar3);
    iVar6 = *(int *)(((unsigned char *)0x000013c4) + iVar4);
    if (sVar1 == 0x801) {
      fVar5 = 0.0;
      fVar2 = -(*(float *)(((unsigned char *)0x00002df0) + iVar3) * *(float *)(((unsigned char *)0x00002df0) + iVar3));
    }
    else if (sVar1 == 0x2601) {
      fVar5 = *(float *)(((unsigned char *)0x00002dfc) + iVar3) * *(float *)(((unsigned char *)0x00002df8) + iVar3);
      fVar2 = -*(float *)(((unsigned char *)0x00002dfc) + iVar3);
    }
    else {
      fVar5 = FLOAT_001aa0d4;
      fVar2 = FLOAT_001aa0d4;
      if (sVar1 == 0x800) {
        fVar5 = 0.0;
        fVar2 = -*(float *)(((unsigned char *)0x00002df0) + iVar3);
      }
    }
    iVar3 = iVar6 * 0x10;
    iVar7 = iVar3 + iVar4;
    *(undefined4 *)(*(int *)(iVar4 + 0x124) + iVar3) = 0;
    *(float *)(iVar3 + *(int *)(iVar4 + 0x124) + 4) = fVar5;
    *(float *)(iVar3 + *(int *)(iVar4 + 0x124) + 8) = fVar2;
    *(undefined4 *)(iVar3 + *(int *)(iVar4 + 0x124) + 0xc) = 0;
    *(undefined4 *)(iVar7 + 0x160) = 0;
    *(float *)(iVar7 + 0x158) = fVar5;
    *(float *)(iVar7 + 0x15c) = fVar2;
    *(undefined4 *)(iVar7 + 0x154) = 0;
    if (*(int *)(((unsigned char *)0x0000137c) + iVar4) < iVar6) {
      *(int *)(((unsigned char *)0x0000137c) + iVar4) = iVar6;
    }
  }
                    
                    
  (**(code **)((int)((unsigned char *)0x000012a0) + param_1))(param_1,iVar4 + 0x13c);
  return;
}

/* FUN_000768e0 @ 0x768e0 (384 bytes) */
int FUN_000768e0(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  
  if (*param_2 != 0) {
    iVar9 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    if ((*(char *)(param_2 + 4) != '\0') && ((*(uint *)(param_1 + 0x8c) & 0x40000000) == 0)) {
      iVar8 = iVar9 + 0x13c;
      if (iVar8 == *(int *)(((unsigned char *)0x0000148c) + param_1)) {
        (**(code **)((int)((unsigned char *)0x000012a0) + param_1))(param_1,iVar8);
      }
      else {
        (**(code **)((int)((unsigned char *)0x00001294) + param_1))(param_1,iVar8,*(undefined4 *)(iVar9 + 0x130));
      }
      (**(code **)(((unsigned char *)0x000012b4) + param_1))(param_1);
      if (*(int *)(iVar9 + 0x4c) != 0) {
        iVar4 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
        uVar2 = *(uint *)(iVar4 + 0x118);
        if (uVar2 != 0) {
          uVar3 = 0;
          do {
            iVar6 = *(int *)(((unsigned char *)0x0000137c) + iVar9);
            iVar1 = *(int *)(uVar3 * 4 + *(int *)(iVar4 + 0x114)) * 0x54 + param_2[8];
            puVar7 = *(undefined4 **)(iVar1 + 0x38);
            iVar1 = *(int *)(iVar1 + 4);
            iVar5 = iVar1 * 0x10 + iVar4;
            *(undefined4 *)(iVar5 + 0x154) = *puVar7;
            *(undefined4 *)(iVar5 + 0x158) = puVar7[1];
            *(undefined4 *)(iVar5 + 0x15c) = puVar7[2];
            *(undefined4 *)(iVar5 + 0x160) = puVar7[3];
            if (iVar6 < iVar1) {
              *(int *)(((unsigned char *)0x0000137c) + iVar9) = iVar1;
              uVar2 = *(uint *)(iVar4 + 0x118);
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < uVar2);
        }
        ((int (*)())FUN_00076770)(param_1,iVar8,param_2);
      }
      *(undefined4 *)(((unsigned char *)0x00001354) + param_1) = 0;
      *(undefined4 *)(((unsigned char *)0x0000134c) + param_1) = 0;
      *(code **)(((unsigned char *)0x00001350) + param_1) = FUN_00077430;
    }
  }
  return;
}

/* FUN_00076ac0 @ 0x76ac0 (188 bytes) */
int FUN_00076ac0(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x44);
  uVar1 = (uint)*(byte *)(param_2 + 0x36) & uVar2 >> 7 & 1 |
          ((uint)*(byte *)(param_2 + 0x37) & uVar2 >> 6 & 1) << 1;
  if (*(char *)(param_2 + 0x33) != '\0') {
    if (*(char *)(param_2 + 0x30) != '\0') {
      uVar1 = uVar1 | uVar2 >> 10 & 4;
    }
    if ((uVar2 & 0x800) != 0) {
      uVar1 = (uint)(byte)((unsigned char *)0x000011d1)[param_1] << 7 | uVar1 | 8;
    }
  }
  if (*(char *)(param_2 + 0x2e) == '\0') {
    uVar2 = *(uint *)(param_1 + 0x44);
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x44);
    if ((uVar2 & 0x400) != 0) {
      uVar1 = uVar1 | (uint)(byte)((unsigned char *)0x000011d2)[param_1] << 0x14 | 0x10;
    }
  }
  if ((uVar2 & 0x2000) != 0) {
    uVar1 = uVar1 | 0x20;
  }
  return uVar1 | (uint)(byte)((unsigned char *)0x00002e0a)[*(int *)(*(int *)(param_1 + 4) + 0x10)] << 6;
}

/* FUN_00076b80 @ 0x76b80 (116 bytes) */
int FUN_00076b80(param_1, param_2)
  int param_1;
  int *param_2;
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = *(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar3 = *piVar2;
  uVar1 = ((int (*)())FUN_00076ac0)(param_1,iVar3);
  *(uint *)(iVar3 + 0x38) = uVar1;
  *(int *)(iVar3 + 0x138) = piVar2[(uVar1 & 0x1f) + 1];
  piVar2[(uVar1 & 0x1f) + 1] = iVar3;
  *(undefined1 *)(iVar3 + 0x134) = 1;
  piVar2[0x21] = piVar2[0x21] + 1;
  return;
}

/* FUN_00076c00 @ 0x76c00 (4 bytes) */
int FUN_00076c00()
{
  return;
}

/* FUN_00076c10 @ 0x76c10 (72 bytes) */
int FUN_00076c10(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  
  iVar1 = *(int *)((param_2 & 0x1f) * 4 + param_1 + 4);
  if (iVar1 != 0) {
    if (param_2 == *(uint *)(iVar1 + 0x38)) {
      return iVar1;
    }
    while (iVar1 = *(int *)(iVar1 + 0x138), iVar1 != 0) {
      if (param_2 == *(uint *)(iVar1 + 0x38)) {
        return iVar1;
      }
    }
  }
  return 0;
}

