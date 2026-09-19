#include "decls.h"

/* FUN_000d4e08 @ 0xd4e08 (92 bytes) */
int FUN_000d4e08(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  DAT_001fa61c = *param_1;
  DAT_001fa618 = param_1[1];
  FUN_000d183c(param_2 + 0x64c,"SC Generated Shader",0);
  return 1;
}

/* FUN_000d4e64 @ 0xd4e64 (40 bytes) */
int FUN_000d4e64()
{
  undefined1 auStack_28 [40];
  
  FUN_000d4df8(auStack_28);
  return 0;
}

/* FUN_000d4e8c @ 0xd4e8c (84 bytes) */
int FUN_000d4e8c(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 local_38;
  undefined4 local_34;
  
  FUN_000d4df8(&local_38);
  local_38 = param_4;
  local_34 = param_1;
  ((int (*)())FUN_000d4e08)(&local_38,param_2);
  return 0;
}

/* FUN_000d4ef0 @ 0xd4ef0 (628 bytes) */
int FUN_000d4ef0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined *param_2;
  uint param_3;
  uint *param_4;
  uint *param_5;
  undefined *param_6;
  undefined4 param_7;
  int param_8;
{
  undefined *puVar1;
  short in_stack_0000003a;
  
  puVar1 = param_2 + -0x84c0;
  if ((undefined *)0xf < puVar1) {
    if (param_2 < (undefined *)0x2) {
      if (param_2 == (undefined *)0x0) {
        *param_4 = *param_4 & 0xffc0ffff | 0x120000;
        *(undefined2 *)((int)param_4 + 2) = 0;
        *param_4 = *param_4 | 0x400000;
        if (param_3 != 0x301) {
          if (param_3 < 0x302) {
            if (param_3 != 0x300) {
              return;
            }
          }
          else if (param_3 != 0x302) {
            if (param_3 != 0x303) {
              return;
            }
            goto LAB_000d5160;
          }
LAB_000d517c:
          *param_5 = *param_5 & 0xfffff888 | 0x444;
          return;
        }
      }
      else {
        if (param_2 != (undefined *)0x1) {
          return;
        }
        *param_4 = *param_4 & 0xffc0ffff | 0x120000;
        *(undefined2 *)((int)param_4 + 2) = 0;
        *param_4 = *param_4 | 0x400000;
        if (param_3 == 0x301) goto LAB_000d517c;
        if (param_3 < 0x302) {
          if (param_3 != 0x300) {
            return;
          }
        }
        else if (param_3 != 0x302) {
          if (param_3 != 0x303) {
            return;
          }
          goto LAB_000d517c;
        }
      }
LAB_000d5160:
      *param_5 = *param_5 & 0xfffff888 | 0x555;
      return;
    }
    if (param_2 == (undefined *)0x8576) {
      *param_4 = *param_4 & 0xffc0ffff | 0x10000;
      *(short *)((int)param_4 + 2) = (short)param_6;
      goto LAB_000d4fe0;
    }
    if ((undefined *)0x8576 < param_2) {
      if (param_2 != (undefined *)0x8577) {
        if (param_2 != (undefined *)0x8578) goto LAB_000d4fe0;
        if (param_8 == 0) {
          *param_4 = *param_4 & 0xffc0ffff | 0x40000;
          *(ushort *)((int)param_4 + 2) = in_stack_0000003a + (ushort)(byte)((unsigned char *)0x000013b2)[param_1]
          ;
          goto LAB_000d4fe0;
        }
      }
      *param_4 = *param_4 & 0xffc0ffff | 0x120000;
      goto LAB_000d4fe0;
    }
    puVar1 = param_6;
    if (param_2 != ((unsigned char *)0x00001702)) goto LAB_000d4fe0;
  }
  *param_4 = *param_4 & 0xffc0ffff | 0x40000;
  *(short *)((int)param_4 + 2) = (short)puVar1;
LAB_000d4fe0:
  if (param_3 == 0x302) {
    *param_4 = *param_4 | 0x400000;
    *param_5 = *param_5 & 0xfffff888 | 0x333;
    return;
  }
  if (param_3 == 0x303) {
    *param_4 = *param_4 | 0x400000;
    *param_5 = *param_5 & 0xfffff888 | 0x10333;
    return;
  }
  if (param_3 == 0x301) {
    *param_4 = *param_4 | 0x400000;
    *param_5 = *param_5 & 0xfffff888 | 0x10210;
    return;
  }
  return;
}

/* FUN_000d51a0 @ 0xd51a0 (460 bytes) */
int FUN_000d51a0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined *param_2;
  int param_3;
  uint *param_4;
  uint *param_5;
  undefined *param_6;
  undefined4 param_7;
  int param_8;
{
  undefined *puVar1;
  short in_stack_0000003a;
  
  puVar1 = param_2 + -0x84c0;
  if ((undefined *)0xf < puVar1) {
    if (param_2 < (undefined *)0x2) {
      if (param_2 == (undefined *)0x0) {
        *param_4 = *param_4 & 0xffc0ffff | 0x120000;
        *(undefined2 *)((int)param_4 + 2) = 0;
        *param_4 = *param_4 | 0x400000;
        if (param_3 != 0x302) {
          if (param_3 != 0x303) {
            return;
          }
          goto LAB_000d535c;
        }
      }
      else {
        if (param_2 != (undefined *)0x1) {
          return;
        }
        *param_4 = *param_4 & 0xffc0ffff | 0x120000;
        *(undefined2 *)((int)param_4 + 2) = 0;
        *param_4 = *param_4 | 0x400000;
        if (param_3 == 0x302) {
LAB_000d535c:
          *param_5 = *param_5 & 0xffff8fff | 0x5000;
          return;
        }
        if (param_3 != 0x303) {
          return;
        }
      }
      *param_5 = *param_5 & 0xffff8fff | 0x4000;
      return;
    }
    if (param_2 == (undefined *)0x8576) {
      *param_4 = *param_4 & 0xffc0ffff | 0x10000;
      *(short *)((int)param_4 + 2) = (short)param_6;
      goto LAB_000d52a0;
    }
    if ((undefined *)0x8576 < param_2) {
      if (param_2 != (undefined *)0x8577) {
        if (param_2 != (undefined *)0x8578) goto LAB_000d52a0;
        if (param_8 == 0) {
          *param_4 = *param_4 & 0xffc0ffff | 0x40000;
          *(ushort *)((int)param_4 + 2) = in_stack_0000003a + (ushort)(byte)((unsigned char *)0x000013b2)[param_1]
          ;
          goto LAB_000d52a0;
        }
      }
      *param_4 = *param_4 & 0xffc0ffff | 0x120000;
      *(undefined2 *)((int)param_4 + 2) = 0;
      goto LAB_000d52a0;
    }
    puVar1 = param_6;
    if (param_2 != ((unsigned char *)0x00001702)) goto LAB_000d52a0;
  }
  *param_4 = *param_4 & 0xffc0ffff | 0x40000;
  *(short *)((int)param_4 + 2) = (short)puVar1;
LAB_000d52a0:
  if (param_3 == 0x303) {
    *param_4 = *param_4 | 0x400000;
    *param_5 = *param_5 & 0xffff8fff | 0x13000;
    return;
  }
  return;
}

/* FUN_000d5390 @ 0xd5390 (548 bytes) */
int FUN_000d5390(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint *param_2;
  int param_3;
  int param_4;
  uint param_5;
{
  bool bVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = 0x170000;
  if (param_3 == 0) {
    uVar5 = param_4 + (uint)(byte)((unsigned char *)0x000013b2)[param_1] & 0xffff | 0x40000;
  }
  else {
    uVar5 = 0x120000;
  }
  uVar6 = 0;
  do {
    if ((1 << (uVar6 & 0x3f) & param_5) != 0) {
      uVar3 = *param_2;
      uVar4 = uVar6 & 0xffff | uVar4 & 0xffff0000;
      if (param_2[1] <= uVar3) {
        pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
        if ((void *)param_2[2] != (void *)0x0) {
          _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
          (**(code **)(param_1 + 0x18))(param_2[2]);
        }
        param_2[2] = (uint)pvVar2;
        uVar3 = *param_2;
        param_2[1] = param_2[1] + 0x80;
      }
      *(undefined4 *)(uVar3 * 4 + param_2[2]) = 0xe;
      uVar3 = *param_2 + 1;
      *param_2 = uVar3;
      if (param_2[1] <= uVar3) {
        pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
        if ((void *)param_2[2] != (void *)0x0) {
          _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
          (**(code **)(param_1 + 0x18))(param_2[2]);
        }
        param_2[2] = (uint)pvVar2;
        uVar3 = *param_2;
        param_2[1] = param_2[1] + 0x80;
      }
      *(uint *)(uVar3 * 4 + param_2[2]) = uVar4;
      uVar3 = *param_2 + 1;
      *param_2 = uVar3;
      if (param_2[1] <= uVar3) {
        pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
        if ((void *)param_2[2] != (void *)0x0) {
          _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
          (**(code **)(param_1 + 0x18))(param_2[2]);
        }
        param_2[2] = (uint)pvVar2;
        uVar3 = *param_2;
        param_2[1] = param_2[1] + 0x80;
      }
      *(uint *)(uVar3 * 4 + param_2[2]) = uVar5;
      *param_2 = *param_2 + 1;
    }
    bVar1 = uVar6 != 3;
    uVar6 = uVar6 + 1;
  } while (bVar1);
  return;
}

/* FUN_000d55c0 @ 0xd55c0 (832 bytes) */
int FUN_000d55c0(param_1, param_2, param_3, param_4)
  int param_1;
  uint *param_2;
  int param_3;
  int param_4;
{
  byte bVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *param_2;
  if (param_2[1] <= uVar3) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar2;
    uVar3 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar3 * 4 + param_2[2]) = 3;
  uVar3 = *param_2 + 1;
  *param_2 = uVar3;
  bVar1 = ((unsigned char *)0x000013b2)[param_1];
  if (param_2[1] <= uVar3) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar2;
    uVar3 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(uVar3 * 4 + param_2[2]) = (int)param_4 + (uint)bVar1 & 0xffff | 0x40000;
  uVar3 = *param_2 + 1;
  *param_2 = uVar3;
  if (param_3 == 0) {
    uVar4 = (int)param_4 + (uint)(byte)((unsigned char *)0x000013b2)[param_1] & 0xffff | 0x40000;
  }
  else {
    uVar4 = 0x120000;
  }
  if (param_2[1] <= uVar3) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar2;
    uVar3 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(uVar3 * 4 + param_2[2]) = uVar4;
  uVar3 = *param_2 + 1;
  *param_2 = uVar3;
  if (param_2[1] <= uVar3) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar2;
    uVar3 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar3 * 4 + param_2[2]) = 0x530000;
  uVar3 = *param_2 + 1;
  *param_2 = uVar3;
  if (param_2[1] <= uVar3) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if ((void *)param_2[2] != (void *)0x0) {
      _memcpy(pvVar2,(void *)param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = (uint)pvVar2;
    uVar3 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined **)(uVar3 * 4 + param_2[2]) = ((unsigned char *)0x00004210);
  *param_2 = *param_2 + 1;
  return;
}

/* FUN_000d5900 @ 0xd5900 (2612 bytes) */
int FUN_000d5900(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  
  puVar8 = (uint *)(param_2 + 4);
  iVar6 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (*(uint *)(param_2 + 8) <= *(uint *)(param_2 + 4)) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar2,*(void **)(param_2 + 0xc),*(int *)(param_2 + 4) << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar2;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
  }
  *(undefined4 *)(*puVar8 * 4 + *(int *)(param_2 + 0xc)) = 0x1ff0016;
  uVar3 = *puVar8 + 1;
  *puVar8 = uVar3;
  if (*(uint *)(param_2 + 8) <= uVar3) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar2;
    uVar3 = *puVar8;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
  }
  *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = 0x120000;
  uVar3 = *puVar8 + 1;
  *puVar8 = uVar3;
  if (((*(uint *)(param_1 + 0x44) & 0xa00000) != 0) ||
     (((int)*(uint *)(param_1 + 0x44) < 0 && (*(short *)("}J3x})+x|B;x}k" + iVar6) == -0x7e06)))) {
    if (*(uint *)(param_2 + 8) <= uVar3) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar3 = *puVar8;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = 0x1ff0016;
    uVar3 = *puVar8 + 1;
    *puVar8 = uVar3;
    if (*(uint *)(param_2 + 8) <= uVar3) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar3 = *puVar8;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = 0x130000;
    uVar3 = *puVar8 + 1;
    *puVar8 = uVar3;
  }
  uVar4 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
  bVar1 = false;
  if (uVar4 != 0) {
    uVar7 = 0;
    uVar5 = 0x80000;
    iVar6 = param_1;
    do {
      if (((*(uint *)(param_1 + 0x44) & 0x100000) != 0) &&
         (*(char *)(uVar7 + *(int *)(((unsigned char *)0x00001168) + param_1) + 0x71) == '\0')) {
        bVar1 = true;
      }
      if (*(int *)(((unsigned char *)0x000013f8) + iVar6) != 0) {
        if (*(uint *)(param_2 + 8) <= uVar3) {
          pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar2;
          uVar3 = *puVar8;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = 0x1ff0016;
        uVar3 = *puVar8 + 1;
        *puVar8 = uVar3;
        if (*(uint *)(param_2 + 8) <= uVar3) {
          pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar2;
          uVar3 = *puVar8;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(uint *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = uVar7 & 0xffff | 0x110000;
        uVar3 = *puVar8 + 1;
        *puVar8 = uVar3;
        if (*(uint *)(param_2 + 8) <= uVar3) {
          pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar2;
          uVar3 = *puVar8;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(uint *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = uVar7 << 0x10 | 0x19;
        uVar3 = *puVar8 + 1;
        *puVar8 = uVar3;
        if (((int)(uint)*(byte *)(param_1 + 0x20) >> (uVar7 & 0x3f) & 1U) == 0) {
          uVar4 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
        }
        else {
          if (*(uint *)(param_2 + 8) <= uVar3) {
            pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar2;
            uVar3 = *puVar8;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = uVar5 | 0x19;
          uVar3 = *puVar8 + 1;
          *puVar8 = uVar3;
          uVar4 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
        }
      }
      uVar7 = uVar7 + 1;
      uVar5 = uVar5 + 0x10000;
      iVar6 = iVar6 + 4;
    } while ((int)uVar7 < (int)uVar4);
  }
  if (*(char *)(param_1 + 0x121) != '\0') {
    if (*(uint *)(param_2 + 8) <= uVar3) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar3 = *puVar8;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = 0x1ff0016;
    uVar3 = *puVar8 + 1;
    *puVar8 = uVar3;
    if (*(uint *)(param_2 + 8) <= uVar3) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar3 = *puVar8;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = 0x100000;
    uVar3 = *puVar8 + 1;
    *puVar8 = uVar3;
  }
  if (bVar1) {
    if (*(uint *)(param_2 + 8) <= uVar3) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar3 = *puVar8;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = 0x1c;
    uVar3 = *puVar8 + 1;
    *puVar8 = uVar3;
    if (*(uint *)(param_2 + 8) <= uVar3) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar3 = *puVar8;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = 0x10011;
    uVar3 = *puVar8 + 1;
    *puVar8 = uVar3;
    if (*(uint *)(param_2 + 8) <= uVar3) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar3 = *puVar8;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = 0;
    uVar3 = *puVar8 + 1;
    *puVar8 = uVar3;
    if (*(uint *)(param_2 + 8) <= uVar3) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar3 = *puVar8;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = 0;
    uVar3 = *puVar8 + 1;
    *puVar8 = uVar3;
    if (*(uint *)(param_2 + 8) <= uVar3) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar3 = *puVar8;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = 0;
    uVar3 = *puVar8 + 1;
    *puVar8 = uVar3;
    if (*(uint *)(param_2 + 8) <= uVar3) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar8 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar3 = *puVar8;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = 0x3f800000;
    *puVar8 = *puVar8 + 1;
  }
  return;
}

/* FUN_000d6340 @ 0xd6340 (4540 bytes) */
int FUN_000d6340(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  undefined4 param_3;
  uint param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  bool bVar1;
  byte bVar2;
  float fVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  int *piVar12;
  undefined4 uVar13;
  uint uVar14;
  uint *puVar15;
  uint local_98 [2];
  undefined1 auStack_90 [4];
  uint local_8c [2];
  undefined1 auStack_84 [4];
  uint local_80 [2];
  undefined1 auStack_78 [4];
  uint local_74;
  uint local_70;
  undefined1 auStack_6c [4];
  int local_68 [4];
  uint *local_58;
  
  iVar6 = 0;
  local_58 = &local_74;
  do {
    *(undefined4 *)(iVar6 + (int)local_98) = 0;
    *(undefined4 *)(iVar6 + (int)local_8c) = 0;
    bVar1 = iVar6 != 8;
    *(undefined4 *)(iVar6 + (int)local_80) = 0;
    *(undefined4 *)(iVar6 + (int)local_58) = 0;
    iVar6 = iVar6 + 4;
  } while (bVar1);
  iVar6 = param_4 * 0xcc + param_1;
  puVar15 = (uint *)(param_2 + 4);
  uVar11 = 0;
  ((int (*)())FUN_000d4ef0)(param_1,*(undefined2 *)(iVar6 + 0x456),*(undefined2 *)(iVar6 + 0x462),local_98,
               local_8c,param_4,param_3,param_6);
  ((int (*)())FUN_000d4ef0)(param_1,*(undefined2 *)(iVar6 + 0x458),*(undefined2 *)(iVar6 + 0x464),local_98 + 1,
               local_8c + 1,param_4,param_3,param_6);
  ((int (*)())FUN_000d4ef0)(param_1,*(undefined2 *)(iVar6 + 0x45a),*(undefined2 *)(iVar6 + 0x466),auStack_90,
               auStack_84,param_4,param_3,param_6);
  uVar8 = (uint)*(ushort *)(iVar6 + 0x454);
  fVar3 = *(float *)(iVar6 + 0x474);
  if (uVar8 < 0x86b0) {
    if (uVar8 < 0x86ae) {
      if (uVar8 == 0x2100) {
        uVar11 = 0x49;
LAB_000d6560:
        iVar10 = 2;
        local_68[0] = 0;
        iVar9 = uVar8 - 0x10000;
        local_68[1] = 1;
      }
      else if (uVar8 < 0x2101) {
        if (uVar8 == 0x104) {
          uVar11 = 3;
          goto LAB_000d6560;
        }
        if (uVar8 != 0x1e01) goto LAB_000d6534;
        iVar10 = 1;
        local_68[0] = 0;
        iVar9 = -0xe1ff;
        uVar11 = 0x47;
      }
      else if (uVar8 == 0x8574) {
        local_68[0] = 0;
        uVar11 = 3;
        local_68[1] = 1;
        if ((local_98[1] & 0x400000) == 0) {
          local_98[1] = local_98[1] | 0x400000;
          local_8c[1] = local_8c[1] & 0xfffff888 | 0x210;
        }
        iVar10 = 2;
        iVar9 = -0x7a8c;
        local_8c[1] = local_8c[1] | 0x20000;
      }
      else if (uVar8 == 0x8575) {
        local_68[1] = 0;
        iVar10 = 3;
        uVar11 = 0x3f;
        iVar9 = -0x7a8b;
        local_68[2] = 1;
        local_68[0] = 2;
      }
      else {
        if (uVar8 != 0x84e7) goto LAB_000d6534;
        iVar10 = 2;
        local_68[0] = 0;
        iVar9 = -0x7b19;
        uVar11 = 0x5b;
        local_68[1] = 1;
      }
    }
    else {
LAB_000d64e8:
      iVar9 = uVar8 - 0x10000;
      local_68[0] = 0;
      uVar11 = 0x22;
      local_68[1] = 1;
      if ((local_98[0] & 0x400000) == 0) {
        local_98[0] = local_98[0] | 0x400000;
        local_8c[0] = local_8c[0] & 0xfffff888 | 0x210;
      }
      if ((local_98[1] & 0x400000) == 0) {
        local_98[1] = local_98[1] | 0x400000;
        local_8c[1] = local_8c[1] & 0xfffff888 | 0x210;
      }
      iVar10 = 2;
      local_8c[0] = local_8c[0] | 0x20000;
      local_8c[1] = local_8c[1] | 0x20000;
    }
  }
  else if (uVar8 == 0x8744) {
    local_68[0] = 0;
    iVar10 = 3;
    uVar11 = 0x40;
    iVar9 = -0x78bc;
    local_68[2] = 1;
    local_68[1] = 2;
  }
  else if (uVar8 < 0x8745) {
    if (uVar8 - 0x8740 < 2) goto LAB_000d64e8;
LAB_000d6534:
    iVar9 = uVar8 - 0x10000;
    iVar10 = 0;
  }
  else if (uVar8 == 0x8745) {
    local_68[0] = 0;
    local_68[1] = 2;
    local_68[2] = 1;
    uVar11 = 0x40;
    if ((local_98[1] & 0x400000) == 0) {
      local_98[1] = local_98[1] | 0x400000;
      local_8c[1] = local_8c[1] & 0xfffff888 | 0x210;
    }
    iVar10 = 3;
    iVar9 = -0x78bb;
    local_8c[1] = local_8c[1] | 0x20000;
  }
  else {
    if (uVar8 != 0x8746) goto LAB_000d6534;
    local_68[0] = 0;
    local_68[1] = 2;
    local_68[2] = 1;
    uVar11 = 0x40;
    if ((local_98[1] & 0x400000) == 0) {
      local_98[1] = local_98[1] | 0x400000;
      local_8c[1] = local_8c[1] & 0xfffff888 | 0x210;
    }
    iVar10 = 3;
    iVar9 = -0x78ba;
    local_8c[1] = local_8c[1] | 0x888;
  }
  bVar2 = ((unsigned char *)0x000013b2)[param_1];
  uVar13 = 0x115;
  if (iVar9 + 0x7952U < 2) {
    if (fVar3 == FLOAT_001aa0e8) {
LAB_000d6840:
      uVar13 = 0x515;
    }
    else if (fVar3 == FLOAT_001aa108) {
      uVar13 = 0x715;
    }
    else {
      uVar13 = 0x715;
      local_8c[0] = local_8c[0] | 0x40000;
    }
  }
  else {
    if (((fVar3 == FLOAT_001aa104) || (uVar8 == 0x8740)) || (uVar8 == 0x8741)) goto LAB_000d6840;
    if (fVar3 == FLOAT_001aa108) {
      uVar13 = 0x315;
    }
  }
  uVar8 = *puVar15;
  if (*(uint *)(param_2 + 8) <= uVar8) {
    pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar15 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar7;
    uVar8 = *puVar15;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
  }
  *(undefined4 *)(uVar8 * 4 + *(int *)(param_2 + 0xc)) = uVar11;
  uVar8 = *puVar15 + 1;
  *puVar15 = uVar8;
  if (*(uint *)(param_2 + 8) <= uVar8) {
    pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar15 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar7;
    uVar8 = *puVar15;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
  }
  *(uint *)(uVar8 * 4 + *(int *)(param_2 + 0xc)) =
       (int)(short)param_4 + (uint)bVar2 & 0xffff | 0x440000;
  uVar8 = *puVar15 + 1;
  *puVar15 = uVar8;
  if (*(uint *)(param_2 + 8) <= uVar8) {
    pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar15 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar7;
    uVar8 = *puVar15;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
  }
  *(undefined4 *)(uVar8 * 4 + *(int *)(param_2 + 0xc)) = uVar13;
  uVar8 = *puVar15 + 1;
  *puVar15 = uVar8;
  if (iVar10 != 0) {
    iVar9 = 0;
    piVar12 = local_68;
    do {
      iVar5 = *piVar12;
      piVar12 = piVar12 + 1;
      uVar14 = local_98[iVar5];
      if (*(uint *)(param_2 + 8) <= uVar8) {
        pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(void **)(param_2 + 0xc) != (void *)0x0) {
          _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar15 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(void **)(param_2 + 0xc) = pvVar7;
        uVar8 = *puVar15;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(uint *)(uVar8 * 4 + *(int *)(param_2 + 0xc)) = uVar14;
      uVar8 = *puVar15 + 1;
      *puVar15 = uVar8;
      if ((local_98[iVar5] & 0x400000) != 0) {
        uVar14 = local_8c[iVar5];
        if (*(uint *)(param_2 + 8) <= uVar8) {
          pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar15 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar7;
          uVar8 = *puVar15;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(uint *)(uVar8 * 4 + *(int *)(param_2 + 0xc)) = uVar14;
        uVar8 = *puVar15 + 1;
        *puVar15 = uVar8;
      }
      iVar9 = iVar9 + 1;
    } while (iVar10 != iVar9);
  }
  if ((*(short *)(iVar6 + 0x454) == -0x78bf) || (*(short *)(iVar6 + 0x454) == -0x7951)) {
    if (*(uint *)(param_2 + 8) <= uVar8) {
      pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar15 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar7;
      uVar8 = *puVar15;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar8 * 4 + *(int *)(param_2 + 0xc)) = 0x47;
    uVar8 = *puVar15 + 1;
    *puVar15 = uVar8;
    bVar2 = ((unsigned char *)0x000013b2)[param_1];
    if (*(uint *)(param_2 + 8) <= uVar8) {
      pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar15 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar7;
      uVar8 = *puVar15;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(uVar8 * 4 + *(int *)(param_2 + 0xc)) =
         (param_4 & 0xffff) + (uint)bVar2 & 0xffff | 0x440000;
    uVar8 = *puVar15 + 1;
    *puVar15 = uVar8;
    if (*(uint *)(param_2 + 8) <= uVar8) {
      pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar15 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar7;
      uVar8 = *puVar15;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar8 * 4 + *(int *)(param_2 + 0xc)) = 0x40;
    uVar8 = *puVar15 + 1;
    *puVar15 = uVar8;
    bVar2 = ((unsigned char *)0x000013b2)[param_1];
    if (*(uint *)(param_2 + 8) <= uVar8) {
      pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar15 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar7;
      uVar8 = *puVar15;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(uVar8 * 4 + *(int *)(param_2 + 0xc)) =
         (param_4 & 0xffff) + (uint)bVar2 & 0xffff | 0x440000;
    uVar8 = *puVar15 + 1;
    *puVar15 = uVar8;
    if (*(uint *)(param_2 + 8) <= uVar8) {
      pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar15 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar7;
      uVar8 = *puVar15;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar8 * 4 + *(int *)(param_2 + 0xc)) = 0;
    *puVar15 = *puVar15 + 1;
    return;
  }
  uVar11 = 0;
  ((int (*)())FUN_000d51a0)(param_1,*(undefined2 *)(iVar6 + 0x45c),*(undefined2 *)(iVar6 + 0x468),local_80,
               local_58,param_4,param_3,param_6);
  ((int (*)())FUN_000d51a0)(param_1,*(undefined2 *)(iVar6 + 0x45e),*(undefined2 *)(iVar6 + 0x46a),local_80 + 1,
               &local_70,param_4,param_3,param_6);
  ((int (*)())FUN_000d51a0)(param_1,*(undefined2 *)(iVar6 + 0x460),*(undefined2 *)(iVar6 + 0x46c),auStack_78,
               auStack_6c,param_4,param_3,param_6);
  uVar4 = *(ushort *)(iVar6 + 0x452);
  fVar3 = *(float *)(iVar6 + 0x478);
  if (uVar4 == 0x8574) {
    local_68[0] = 0;
    uVar11 = 3;
    local_68[1] = 1;
    if ((local_80[1] & 0x400000) == 0) {
      local_80[1] = local_80[1] | 0x400000;
      local_70 = local_70 & 0xffff8fff | 0x3000;
    }
    iVar6 = 2;
    local_70 = local_70 | 0x20000;
  }
  else if (uVar4 < 0x8575) {
    if (uVar4 == 0x1e01) {
      iVar6 = 1;
      local_68[0] = 0;
      uVar11 = 0x47;
    }
    else {
      if (uVar4 < 0x1e02) {
        if (uVar4 != 0x104) {
LAB_000d6fbc:
          iVar6 = 0;
          goto LAB_000d7144;
        }
        uVar11 = 3;
      }
      else if (uVar4 == 0x2100) {
        uVar11 = 0x49;
      }
      else {
        if (uVar4 != 0x84e7) goto LAB_000d6fbc;
        uVar11 = 0x5b;
      }
      iVar6 = 2;
      local_68[0] = 0;
      local_68[1] = 1;
    }
  }
  else if (uVar4 == 0x8744) {
    local_68[0] = 0;
    iVar6 = 3;
    uVar11 = 0x40;
    local_68[2] = 1;
    local_68[1] = 2;
  }
  else if (uVar4 < 0x8745) {
    if (uVar4 != 0x8575) goto LAB_000d6fbc;
    local_68[1] = 0;
    iVar6 = 3;
    uVar11 = 0x3f;
    local_68[2] = 1;
    local_68[0] = 2;
  }
  else if (uVar4 == 0x8745) {
    local_68[0] = 0;
    uVar11 = 0x40;
    local_68[2] = 1;
    local_68[1] = 2;
    if ((local_80[1] & 0x400000) == 0) {
      local_80[1] = local_80[1] | 0x400000;
      local_70 = local_70 & 0xffff8fff | 0x3000;
    }
    iVar6 = 3;
    local_70 = local_70 | 0x20000;
  }
  else {
    if (uVar4 != 0x8746) goto LAB_000d6fbc;
    local_68[0] = 0;
    local_68[1] = 2;
    uVar11 = 0x40;
    local_68[2] = 1;
    if ((local_80[1] & 0x400000) == 0) {
      local_80[1] = local_80[1] | 0x400000;
      local_70 = local_70 & 0xffff8fff | 0x3000;
    }
    iVar6 = 3;
    local_70 = local_70 | 0x8000;
  }
LAB_000d7144:
  bVar2 = ((unsigned char *)0x000013b2)[param_1];
  uVar13 = 0x140;
  if (uVar4 == 0x86af) {
    if (fVar3 != FLOAT_001aa0e8) {
      if (fVar3 == FLOAT_001aa108) {
        uVar13 = 0x740;
      }
      else {
        uVar13 = 0x740;
        local_74 = local_74 | 0x40000;
      }
      goto LAB_000d7214;
    }
  }
  else if ((fVar3 != FLOAT_001aa104) && (uVar4 != 0x8741)) {
    if (fVar3 == FLOAT_001aa108) {
      uVar13 = 0x340;
    }
    goto LAB_000d7214;
  }
  uVar13 = 0x540;
LAB_000d7214:
  uVar8 = *puVar15;
  if (*(uint *)(param_2 + 8) <= uVar8) {
    pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar15 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar7;
    uVar8 = *puVar15;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
  }
  *(undefined4 *)(uVar8 * 4 + *(int *)(param_2 + 0xc)) = uVar11;
  uVar8 = *puVar15 + 1;
  *puVar15 = uVar8;
  if (*(uint *)(param_2 + 8) <= uVar8) {
    pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar15 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar7;
    uVar8 = *puVar15;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
  }
  *(uint *)(uVar8 * 4 + *(int *)(param_2 + 0xc)) =
       (int)(short)param_4 + (uint)bVar2 & 0xffff | 0x440000;
  uVar8 = *puVar15 + 1;
  *puVar15 = uVar8;
  if (*(uint *)(param_2 + 8) <= uVar8) {
    pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar15 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar7;
    uVar8 = *puVar15;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
  }
  *(undefined4 *)(uVar8 * 4 + *(int *)(param_2 + 0xc)) = uVar13;
  uVar8 = *puVar15 + 1;
  *puVar15 = uVar8;
  if (iVar6 != 0) {
    iVar9 = 0;
    piVar12 = local_68;
    do {
      iVar10 = *piVar12;
      piVar12 = piVar12 + 1;
      uVar14 = local_80[iVar10];
      if (*(uint *)(param_2 + 8) <= uVar8) {
        pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(void **)(param_2 + 0xc) != (void *)0x0) {
          _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar15 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(void **)(param_2 + 0xc) = pvVar7;
        uVar8 = *puVar15;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(uint *)(uVar8 * 4 + *(int *)(param_2 + 0xc)) = uVar14;
      uVar8 = *puVar15 + 1;
      *puVar15 = uVar8;
      if ((local_80[iVar10] & 0x400000) != 0) {
        uVar14 = local_58[iVar10];
        if (*(uint *)(param_2 + 8) <= uVar8) {
          pvVar7 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar7,*(void **)(param_2 + 0xc),*puVar15 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar7;
          uVar8 = *puVar15;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(uint *)(uVar8 * 4 + *(int *)(param_2 + 0xc)) = uVar14;
        uVar8 = *puVar15 + 1;
        *puVar15 = uVar8;
      }
      iVar9 = iVar9 + 1;
    } while (iVar6 != iVar9);
  }
  return;
}

/* FUN_000d7520 @ 0xd7520 (3832 bytes) */
int FUN_000d7520(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  int param_6;
  int param_7;
  int param_8;
{
  uint uVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined *puVar7;
  undefined *puVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint *puVar15;
  
  puVar15 = (uint *)(param_2 + 4);
  uVar13 = 0;
  uVar12 = 0;
  uVar9 = 0;
  puVar8 = (undefined *)0x0;
  puVar7 = (undefined *)0x0;
  uVar5 = 0;
  uVar6 = 0;
  if ((((param_3 == 0x1902) || (param_3 == 0x81a5)) || (param_3 == 0x81a7)) || (param_3 == 0x81a6))
  {
    param_3 = (uint)*(ushort *)(param_6 + 0x58);
  }
  uVar1 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
  param_5 = param_5 & 0xffff;
  uVar10 = 0;
  uVar4 = param_5 + uVar1 & 0xffff;
  uVar11 = uVar4 | 0x40000;
  if (param_4 == 0x1e01) {
    if (param_3 != 0x1908) {
      if (param_3 < 0x1909) {
        if (param_3 == 0x1906) {
          uVar10 = 3;
          if (param_7 == 0) {
            uVar13 = uVar1 + param_8 & 0xffff | 0x40000;
          }
          else {
            uVar13 = 0x120000;
          }
          uVar3 = *puVar15;
          uVar13 = uVar13 | 0x400000;
          uVar14 = 2;
          uVar12 = param_5 | 0x440000;
          puVar7 = ((unsigned char *)0x00003444);
          puVar8 = ((unsigned char *)0x00004210);
          goto LAB_000d75e8;
        }
        if (param_3 != 0x1907) goto LAB_000d75e0;
LAB_000d7d84:
        uVar10 = 3;
        if (param_7 == 0) {
          uVar13 = uVar1 + param_8 & 0xffff | 0x40000;
        }
        else {
          uVar13 = 0x120000;
        }
        uVar3 = *puVar15;
        uVar13 = uVar13 | 0x400000;
        uVar14 = 2;
        uVar12 = param_5 | 0x440000;
        puVar8 = ((unsigned char *)0x00003444);
        puVar7 = ((unsigned char *)0x00004210);
        goto LAB_000d75e8;
      }
      if (param_3 != 0x190a) {
        if (param_3 < 0x190a) goto LAB_000d7d84;
        if (param_3 != 0x8049) goto LAB_000d75e0;
      }
    }
    uVar3 = *puVar15;
    uVar14 = 1;
    uVar10 = 0x47;
    uVar13 = param_5 | 0x40000;
    goto LAB_000d75e8;
  }
  if (param_4 < 0x1e02) {
    if (param_4 == 0x104) {
      uVar10 = 0x40;
      if (param_7 == 0) {
        uVar13 = uVar1 + param_8 & 0xffff | 0x40000;
      }
      else {
        uVar13 = 0x120000;
      }
      uVar12 = param_5 | 0x440000;
      uVar9 = param_5 | 0x440000;
      if (param_3 < 0x190b) {
        if (0x1906 < param_3) {
LAB_000d7ee4:
          puVar7 = (undefined *)0x555;
          uVar5 = 0x210;
          goto LAB_000d7f0c;
        }
        if (param_3 != 0x1906) goto LAB_000d7f0c;
        uVar5 = 0x444;
        puVar7 = (undefined *)0x555;
      }
      else {
        if (param_3 == 0x8049) goto LAB_000d7ee4;
LAB_000d7f0c:
        if (param_3 == 0x8049) {
          uVar3 = *puVar15;
          uVar14 = 3;
          puVar7 = (undefined *)((uint)puVar7 | 0x5000);
          uVar5 = uVar5 | 0x3000;
          goto LAB_000d75e8;
        }
      }
      uVar3 = *puVar15;
      uVar14 = 3;
      puVar7 = (undefined *)((uint)puVar7 | 0x3000);
      uVar5 = uVar5 | 0x4000;
      goto LAB_000d75e8;
    }
    if ((param_4 == 0xbe2) && (0x1905 < param_3)) {
      if (param_3 < 0x190b) {
        if (param_7 == 0) {
          uVar9 = uVar1 + param_8 & 0xffff | 0x40000;
        }
        else {
          uVar9 = 0x120000;
        }
        uVar13 = *puVar15;
        if (*(uint *)(param_2 + 8) <= uVar13) {
          pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar2;
          uVar13 = *puVar15;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(undefined4 *)(uVar13 * 4 + *(int *)(param_2 + 0xc)) = 0x3f;
        uVar13 = *puVar15 + 1;
        *puVar15 = uVar13;
        if (*(uint *)(param_2 + 8) <= uVar13) {
          pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar2;
          uVar13 = *puVar15;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(uint *)(uVar13 * 4 + *(int *)(param_2 + 0xc)) = uVar4 | 0x440000;
        uVar13 = *puVar15 + 1;
        *puVar15 = uVar13;
        if (*(uint *)(param_2 + 8) <= uVar13) {
          pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar2;
          uVar13 = *puVar15;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(undefined4 *)(uVar13 * 4 + *(int *)(param_2 + 0xc)) = 0x15;
        uVar13 = *puVar15 + 1;
        *puVar15 = uVar13;
        if (*(uint *)(param_2 + 8) <= uVar13) {
          pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar2;
          uVar13 = *puVar15;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(uint *)(uVar13 * 4 + *(int *)(param_2 + 0xc)) = param_5 | 0x40000;
        uVar13 = *puVar15 + 1;
        *puVar15 = uVar13;
        if (*(uint *)(param_2 + 8) <= uVar13) {
          pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar2;
          uVar13 = *puVar15;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(uint *)(uVar13 * 4 + *(int *)(param_2 + 0xc)) = param_5 | 0x10000;
        uVar13 = *puVar15 + 1;
        *puVar15 = uVar13;
        if (*(uint *)(param_2 + 8) <= uVar13) {
          pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(void **)(param_2 + 0xc) != (void *)0x0) {
            _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(void **)(param_2 + 0xc) = pvVar2;
          uVar13 = *puVar15;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        uVar10 = 0x49;
        *(uint *)(uVar13 * 4 + *(int *)(param_2 + 0xc)) = uVar9;
        uVar13 = param_5 | 0x40000;
        uVar3 = *puVar15 + 1;
        *puVar15 = uVar3;
        if (param_7 == 0) {
          uVar12 = param_8 + (uint)(byte)((unsigned char *)0x000013b2)[param_1] & 0xffff | 0x40000;
        }
        else {
          uVar12 = 0x120000;
        }
        uVar14 = 2;
        uVar11 = uVar4 | 0x440000;
        uVar6 = 0x40;
        goto LAB_000d75e8;
      }
      if (param_3 == 0x8049) {
        uVar10 = 0x3f;
        uVar13 = param_5 | 0x40000;
        uVar12 = param_5 | 0x10000;
        if (param_7 == 0) {
          uVar3 = *puVar15;
          uVar14 = 0;
          uVar9 = uVar1 + param_8 & 0xffff | 0x40000;
        }
        else {
          uVar3 = *puVar15;
          uVar14 = 0;
          uVar9 = 0x120000;
        }
        goto LAB_000d75e8;
      }
    }
  }
  else {
    if (param_4 == 0x2100) {
      if (param_3 == 0x1906) {
        uVar10 = 0x49;
        if (param_7 == 0) {
          uVar12 = uVar1 + param_8 & 0xffff | 0x40000;
        }
        else {
          uVar12 = 0x120000;
        }
        uVar3 = *puVar15;
        uVar13 = param_5 | 0x440000;
        uVar14 = 2;
        puVar8 = ((unsigned char *)0x00003555);
      }
      else if (param_3 == 0x1907) {
        uVar10 = 0x49;
        if (param_7 == 0) {
          uVar12 = uVar1 + param_8 & 0xffff | 0x40000;
        }
        else {
          uVar12 = 0x120000;
        }
        uVar3 = *puVar15;
        uVar13 = param_5 | 0x440000;
        uVar14 = 2;
        puVar8 = ((unsigned char *)0x00005210);
      }
      else {
        uVar10 = 0x49;
        uVar13 = param_5 | 0x40000;
        if (param_7 == 0) {
          uVar3 = *puVar15;
          uVar14 = 2;
          uVar12 = uVar1 + param_8 & 0xffff | 0x40000;
        }
        else {
          uVar3 = *puVar15;
          uVar14 = 2;
          uVar12 = 0x120000;
        }
      }
      goto LAB_000d75e8;
    }
    if (param_4 == 0x2101) {
      if (param_3 == 0x1907) {
        uVar10 = 3;
        if (param_7 == 0) {
          uVar12 = uVar1 + param_8 & 0xffff | 0x40000;
        }
        else {
          uVar12 = 0x120000;
        }
        uVar3 = *puVar15;
        uVar13 = param_5 | 0x440000;
        uVar12 = uVar12 | 0x400000;
        uVar14 = 2;
        puVar8 = ((unsigned char *)0x00004210);
        puVar7 = ((unsigned char *)0x00003444);
        goto LAB_000d75e8;
      }
      if (param_3 == 0x1908) {
        uVar10 = 0x3f;
        if (param_7 == 0) {
          uVar9 = uVar1 + param_8 & 0xffff | 0x40000;
        }
        else {
          uVar9 = 0x120000;
        }
        uVar3 = *puVar15;
        uVar13 = param_5 | 0x440000;
        uVar12 = param_5 | 0x440000;
        uVar14 = 3;
        puVar8 = ((unsigned char *)0x00004333);
        puVar7 = ((unsigned char *)0x00004210);
        goto LAB_000d75e8;
      }
    }
  }
LAB_000d75e0:
  uVar3 = *puVar15;
  uVar14 = 0;
LAB_000d75e8:
  if (*(uint *)(param_2 + 8) <= uVar3) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar2;
    uVar3 = *puVar15;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
  }
  *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = uVar10;
  uVar4 = *puVar15 + 1;
  *puVar15 = uVar4;
  if (*(uint *)(param_2 + 8) <= uVar4) {
    pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
    }
    *(void **)(param_2 + 0xc) = pvVar2;
    uVar4 = *puVar15;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
  }
  *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar11;
  uVar4 = *puVar15 + 1;
  *puVar15 = uVar4;
  if ((uVar11 & 0x400000) != 0) {
    if (*(uint *)(param_2 + 8) <= uVar4) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar4 = *puVar15;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar6;
    uVar4 = *puVar15 + 1;
    *puVar15 = uVar4;
  }
  if (uVar14 != 0) {
    if (*(uint *)(param_2 + 8) <= uVar4) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar4 = *puVar15;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar13;
    uVar4 = *puVar15 + 1;
    *puVar15 = uVar4;
    if ((uVar13 & 0x400000) != 0) {
      if (*(uint *)(param_2 + 8) <= uVar4) {
        pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(void **)(param_2 + 0xc) != (void *)0x0) {
          _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(void **)(param_2 + 0xc) = pvVar2;
        uVar4 = *puVar15;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(undefined **)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = puVar8;
      uVar4 = *puVar15 + 1;
      *puVar15 = uVar4;
    }
  }
  if (1 < uVar14) {
    if (*(uint *)(param_2 + 8) <= uVar4) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar4 = *puVar15;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar12;
    uVar4 = *puVar15 + 1;
    *puVar15 = uVar4;
    if ((uVar12 & 0x400000) != 0) {
      if (*(uint *)(param_2 + 8) <= uVar4) {
        pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(void **)(param_2 + 0xc) != (void *)0x0) {
          _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(void **)(param_2 + 0xc) = pvVar2;
        uVar4 = *puVar15;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(undefined **)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = puVar7;
      uVar4 = *puVar15 + 1;
      *puVar15 = uVar4;
    }
  }
  if (2 < uVar14) {
    if (*(uint *)(param_2 + 8) <= uVar4) {
      pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(void **)(param_2 + 0xc) != (void *)0x0) {
        _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(void **)(param_2 + 0xc) = pvVar2;
      uVar4 = *puVar15;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar9;
    uVar13 = *puVar15 + 1;
    *puVar15 = uVar13;
    if ((uVar9 & 0x400000) != 0) {
      if (*(uint *)(param_2 + 8) <= uVar13) {
        pvVar2 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(void **)(param_2 + 0xc) != (void *)0x0) {
          _memcpy(pvVar2,*(void **)(param_2 + 0xc),*puVar15 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(void **)(param_2 + 0xc) = pvVar2;
        uVar13 = *puVar15;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(uint *)(uVar13 * 4 + *(int *)(param_2 + 0xc)) = uVar5;
      *puVar15 = *puVar15 + 1;
    }
  }
  return;
}

/* FUN_000d8450 @ 0xd8450 (5856 bytes) */
int FUN_000d8450(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  uint uVar2;
  void *pvVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined *puVar13;
  uint *puVar14;
  int iStack00000020;
  char acStack_68 [28];
  
  puVar14 = (uint *)(param_2 + 4);
  uVar4 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
  if (uVar4 != 0) {
    uVar10 = 0;
    iVar5 = param_1 + 0x450;
    iVar6 = param_1;
    iVar7 = param_1;
    iVar8 = param_1;
    iStack00000020 = param_3;
    do {
      if (*(int *)(((unsigned char *)0x000013f8) + iVar7) != 0) {
        bVar1 = false;
        if ((*(uint *)(param_1 + 0x44) & 0x100000) != 0) {
          bVar1 = *(char *)(uVar10 + *(int *)(((unsigned char *)0x00001168) + param_1) + 0x71) == '\0';
        }
        if (((int)(uint)*(byte *)(param_1 + 0x20) >> (uVar10 & 0x3f) & 1U) == 0) {
          if ((*(short *)(iVar8 + 0x450) != -0x7a90) || (*(short *)(iVar5 + 4) != -0x7885)) {
            uVar4 = *puVar14;
            if (*(uint *)(param_2 + 8) <= uVar4) {
              pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
              if (*(void **)(param_2 + 0xc) != (void *)0x0) {
                _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
                (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
              }
              *(void **)(param_2 + 0xc) = pvVar3;
              uVar4 = *puVar14;
              *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
            }
            *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = (uVar10 & 0xff) << 0x10 | 0x800005d;
            uVar4 = *puVar14 + 1;
            *puVar14 = uVar4;
            if (*(uint *)(param_2 + 8) <= uVar4) {
              pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
              if (*(void **)(param_2 + 0xc) != (void *)0x0) {
                _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
                (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
              }
              *(void **)(param_2 + 0xc) = pvVar3;
              uVar4 = *puVar14;
              *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
            }
            *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar10 & 0xffff | 0x40000;
            uVar4 = *puVar14 + 1;
            *puVar14 = uVar4;
            if ((iStack00000020 == 0) || (acStack_68[uVar10] == '\0')) {
              if ((bVar1) &&
                 (((*(uint *)(param_1 + 0x44) & 0x20000000) == 0 ||
                  ((1 << (uVar10 & 0x3f) & *(uint *)(param_1 + 0xec)) == 0)))) {
                uVar11 = 0x10011;
              }
              else {
                uVar11 = uVar10 & 0xffff | 0x110000;
              }
            }
            else {
              uVar11 = uVar10 + (uint)(byte)((unsigned char *)0x000013b2)[param_1] * 2 & 0xffff | 0x40000;
            }
            if (*(uint *)(param_2 + 8) <= uVar4) {
              pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
              if (*(void **)(param_2 + 0xc) != (void *)0x0) {
                _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
                (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
              }
              *(void **)(param_2 + 0xc) = pvVar3;
              uVar4 = *puVar14;
              *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
            }
            *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar11 | 0x400000;
            uVar4 = *puVar14 + 1;
            *puVar14 = uVar4;
            if (*(uint *)(param_2 + 8) <= uVar4) {
              pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
              if (*(void **)(param_2 + 0xc) != (void *)0x0) {
                _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
                (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
              }
              *(void **)(param_2 + 0xc) = pvVar3;
              uVar4 = *puVar14;
              *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
            }
            *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x603210;
            *puVar14 = *puVar14 + 1;
            uVar4 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
          }
        }
        else {
          uVar4 = *puVar14;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x49;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          uVar11 = uVar10 & 0xffff;
          *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x40020;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          uVar2 = uVar11 + 0x14 & 0xffff;
          *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar11 | 0x110000;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          pcVar9 = (char *)(iVar6 + 0x21);
          *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar2 | 0x410000;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(char *)(iVar6 + 0x21) == '\x01') {
            uVar12 = 0x50;
          }
          else {
            uVar12 = 5;
          }
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar12 | 0x5500;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = (uVar10 & 0xff) << 0x10 | 0x800005d;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x40020;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x440020;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x603210;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x40;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x40021;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar11 | 0x110000;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar2 | 0x410000;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*pcVar9 == '\x01') {
            uVar12 = 0x51;
          }
          else {
            uVar12 = 0x15;
          }
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar12 | 0x5500;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar2 | 0x410000;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*pcVar9 == '\x01') {
            uVar12 = 0x42;
          }
          else {
            uVar12 = 0x24;
          }
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar12 | 0x4400;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) =
               ((uVar10 & 0xff) + 8) * 0x10000 & 0xff0000 | 0x800005d;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x40021;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x440021;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x603210;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x5b;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x40022;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar11 | 0x510000;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*pcVar9 == '\x01') {
            puVar13 = (undefined *)0x0;
          }
          else {
            puVar13 = ((unsigned char *)0x00001111);
          }
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined **)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = puVar13;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar2 | 0x410000;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined **)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = ((unsigned char *)0x00003333);
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x3000d;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar11 | 0x40000;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x40022;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x40021;
          uVar4 = *puVar14 + 1;
          *puVar14 = uVar4;
          if (*(uint *)(param_2 + 8) <= uVar4) {
            pvVar3 = (void *)(**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
            if (*(void **)(param_2 + 0xc) != (void *)0x0) {
              _memcpy(pvVar3,*(void **)(param_2 + 0xc),*puVar14 << 2);
              (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
            }
            *(void **)(param_2 + 0xc) = pvVar3;
            uVar4 = *puVar14;
            *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
          }
          *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x40020;
          *puVar14 = *puVar14 + 1;
          uVar4 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
        }
      }
      uVar10 = uVar10 + 1;
      iVar5 = iVar5 + 0xcc;
      iVar7 = iVar7 + 4;
      iVar8 = iVar8 + 0xcc;
      iVar6 = iVar6 + 1;
    } while ((int)uVar10 < (int)uVar4);
  }
  return;
}

/* FUN_000d9b58 @ 0xd9b58 (84 bytes) */
int FUN_000d9b58(param_1, param_2, param_3)
  undefined4 param_1;
  uint *param_2;
  int param_3;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  do {
    uVar2 = *param_2;
    if (uVar2 != 0) {
      iVar4 = 0;
      do {
        if ((uVar2 & 1) != 0) {
          if (param_3 == 0) {
            return iVar4 + iVar3;
          }
          param_3 = param_3 + -1;
        }
        uVar2 = uVar2 >> 1;
        iVar4 = iVar4 + 1;
      } while (uVar2 != 0);
    }
    bVar1 = iVar3 != 0xe0;
    param_2 = param_2 + 1;
    iVar3 = iVar3 + 0x20;
  } while (bVar1);
  return -1;
}

/* FUN_000d9bac @ 0xd9bac (228 bytes) */
undefined4
FUN_000d9bac(double param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
            int param_6,int param_7)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  
  if (param_7 == 0) {
    piVar4 = *(int **)(param_6 + 0x84);
    if (piVar4 != (int *)0x0) {
      uVar2 = *(uint *)(param_6 + 0x78);
      if (uVar2 == 0) {
LAB_000d9c0c:
        if (*(uint *)(param_6 + 0x6c) <= uVar2) {
          return 0;
        }
        iVar3 = uVar2 * 0x14;
        *(uint *)(param_6 + 0x78) = uVar2 + 1;
      }
      else if (*piVar4 == param_3) {
        iVar3 = 0;
      }
      else {
        iVar1 = 0x14;
        uVar6 = uVar2;
        piVar5 = piVar4;
        do {
          iVar3 = iVar1;
          piVar5 = piVar5 + 5;
          uVar6 = uVar6 - 1;
          if (uVar6 == 0) goto LAB_000d9c0c;
          iVar1 = iVar3 + 0x14;
        } while (*piVar5 != param_3);
      }
      *(int *)(iVar3 + (int)piVar4) = param_3;
      *(float *)((int)piVar4 + param_5 * 4 + iVar3 + 4) = (float)param_1;
      return 1;
    }
  }
  else {
    uVar2 = *(uint *)(param_6 + 0x54);
    if (uVar2 < *(uint *)(param_6 + 0x48)) {
      *(uint *)(param_6 + 0x54) = uVar2 + 1;
      iVar3 = uVar2 * 0x24 + *(int *)(param_6 + 0x60);
      *(int *)(uVar2 * 0x24 + *(int *)(param_6 + 0x60)) = param_3;
      *(float *)(iVar3 + 0x14) = (float)param_1;
      *(int *)(iVar3 + 4) = param_5;
      *(undefined4 *)(iVar3 + 8) = 1;
      return 1;
    }
  }
  return 0;
}

/* FUN_000d9c90 @ 0xd9c90 (228 bytes) */
int FUN_000d9c90(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
  int param_6;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  
  if (param_6 == 0) {
    piVar4 = *(int **)(param_5 + 0x88);
    if (piVar4 != (int *)0x0) {
      uVar2 = *(uint *)(param_5 + 0x7c);
      if (uVar2 == 0) {
LAB_000d9cf0:
        if (*(uint *)(param_5 + 0x70) <= uVar2) {
          return 0;
        }
        iVar3 = uVar2 * 0x14;
        *(uint *)(param_5 + 0x7c) = uVar2 + 1;
      }
      else if (*piVar4 == param_2) {
        iVar3 = 0;
      }
      else {
        iVar1 = 0x14;
        uVar6 = uVar2;
        piVar5 = piVar4;
        do {
          iVar3 = iVar1;
          piVar5 = piVar5 + 5;
          uVar6 = uVar6 - 1;
          if (uVar6 == 0) goto LAB_000d9cf0;
          iVar1 = iVar3 + 0x14;
        } while (*piVar5 != param_2);
      }
      *(int *)(iVar3 + (int)piVar4) = param_2;
      *(undefined4 *)((int)piVar4 + param_4 * 4 + iVar3 + 4) = param_3;
      return 1;
    }
  }
  else {
    uVar2 = *(uint *)(param_5 + 0x58);
    if (uVar2 < *(uint *)(param_5 + 0x4c)) {
      *(uint *)(param_5 + 0x58) = uVar2 + 1;
      iVar3 = uVar2 * 0x24 + *(int *)(param_5 + 100);
      *(int *)(uVar2 * 0x24 + *(int *)(param_5 + 100)) = param_2;
      *(undefined4 *)(iVar3 + 0x14) = param_3;
      *(int *)(iVar3 + 4) = param_4;
      *(undefined4 *)(iVar3 + 8) = 0;
      return 1;
    }
  }
  return 0;
}

/* FUN_000d9d74 @ 0xd9d74 (228 bytes) */
int FUN_000d9d74(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
  int param_6;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  
  if (param_6 == 0) {
    piVar4 = *(int **)(param_5 + 0x8c);
    if (piVar4 != (int *)0x0) {
      uVar2 = *(uint *)(param_5 + 0x80);
      if (uVar2 == 0) {
LAB_000d9dd4:
        if (*(uint *)(param_5 + 0x74) <= uVar2) {
          return 0;
        }
        iVar3 = uVar2 * 0x14;
        *(uint *)(param_5 + 0x80) = uVar2 + 1;
      }
      else if (*piVar4 == param_2) {
        iVar3 = 0;
      }
      else {
        iVar1 = 0x14;
        uVar6 = uVar2;
        piVar5 = piVar4;
        do {
          iVar3 = iVar1;
          piVar5 = piVar5 + 5;
          uVar6 = uVar6 - 1;
          if (uVar6 == 0) goto LAB_000d9dd4;
          iVar1 = iVar3 + 0x14;
        } while (*piVar5 != param_2);
      }
      *(int *)(iVar3 + (int)piVar4) = param_2;
      *(undefined4 *)((int)piVar4 + param_4 * 4 + iVar3 + 4) = param_3;
      return 1;
    }
  }
  else {
    uVar2 = *(uint *)(param_5 + 0x5c);
    if (uVar2 < *(uint *)(param_5 + 0x50)) {
      *(uint *)(param_5 + 0x5c) = uVar2 + 1;
      iVar3 = uVar2 * 0x24 + *(int *)(param_5 + 0x68);
      *(int *)(uVar2 * 0x24 + *(int *)(param_5 + 0x68)) = param_2;
      *(undefined4 *)(iVar3 + 0x14) = param_3;
      *(int *)(iVar3 + 4) = param_4;
      *(undefined4 *)(iVar3 + 8) = 2;
      return 1;
    }
  }
  return 0;
}

/* FUN_000d9e58 @ 0xd9e58 (64 bytes) */
int FUN_000d9e58(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(param_6 + 0x54);
  if (*(uint *)(param_6 + 0x48) <= uVar1) {
    return 0;
  }
  iVar2 = uVar1 * 0x24 + *(int *)(param_6 + 0x60);
  *(uint *)(param_6 + 0x54) = uVar1 + 1;
  *(undefined4 *)(uVar1 * 0x24 + *(int *)(param_6 + 0x60)) = param_2;
  *(undefined4 *)(iVar2 + 0x10) = param_4;
  *(undefined4 *)(iVar2 + 4) = param_5;
  *(undefined4 *)(iVar2 + 8) = param_3;
  return 1;
}

/* FUN_000d9e98 @ 0xd9e98 (156 bytes) */
int FUN_000d9e98(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
  int param_8;
{
  uint uVar1;
  int iVar2;
  undefined4 in_stack_00000038;
  int in_stack_0000003c;
  
  uVar1 = *(uint *)(in_stack_0000003c + 0x58);
  if (*(uint *)(in_stack_0000003c + 0x4c) <= uVar1) {
    return 0;
  }
  *(uint *)(in_stack_0000003c + 0x58) = uVar1 + 1;
  iVar2 = uVar1 * 0x24 + *(int *)(in_stack_0000003c + 100);
  *(undefined4 *)(uVar1 * 0x24 + *(int *)(in_stack_0000003c + 100)) = param_2;
  *(undefined4 *)(iVar2 + 4) = 0;
  if (param_8 == -1) {
    if (param_7 == 0xff) {
      *(undefined4 *)(iVar2 + 8) = 0x15;
    }
    else {
      *(undefined4 *)(iVar2 + 8) = 0x16;
    }
  }
  else if (param_7 == 0xff) {
    *(undefined4 *)(iVar2 + 8) = 0x17;
  }
  else {
    *(undefined4 *)(iVar2 + 8) = 0x18;
  }
  *(int *)(iVar2 + 0x1c) = param_8;
  *(undefined4 *)(iVar2 + 0x10) = param_5;
  *(undefined4 *)(iVar2 + 0xc) = param_6;
  *(undefined4 *)(iVar2 + 0x20) = in_stack_00000038;
  return 1;
}

/* FUN_000d9f3c @ 0xd9f3c (60 bytes) */
int FUN_000d9f3c(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  
  if (param_2 == 0) {
    iVar2 = *(int *)(param_1 + 0x2c);
  }
  else {
    iVar2 = *(int *)(param_1 + 0x30);
  }
  bVar1 = true;
  if (*(uint **)(iVar2 + 0x48) != (uint *)0x0) {
    bVar1 = (**(uint **)(iVar2 + 0x48) & 0x200000) == 0;
  }
  return bVar1;
}

/* FUN_000d9f80 @ 0xd9f80 (32 bytes) */
int FUN_000d9f80(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x3c);
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x40);
}

/* FUN_000d9fa0 @ 0xd9fa0 (32 bytes) */
int FUN_000d9fa0(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xc);
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x10);
}

/* FUN_000d9fc0 @ 0xd9fc0 (32 bytes) */
int FUN_000d9fc0(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x24);
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x28);
}

/* FUN_000d9fe0 @ 0xd9fe0 (72 bytes) */
int FUN_000d9fe0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 *param_5;
{
  int iVar1;
  int iVar2;
  
  if (param_2 == 0) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x2c) + 0x34);
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 0x30) + 0x30);
  }
  iVar1 = iVar2 + param_3 * 0x10;
  *param_5 = *(undefined4 *)(iVar2 + param_3 * 0x10);
  param_5[1] = *(undefined4 *)(iVar1 + 4);
  param_5[2] = *(undefined4 *)(iVar1 + 8);
  param_5[3] = *(undefined4 *)(iVar1 + 0xc);
  return;
}

/* FUN_000da028 @ 0xda028 (72 bytes) */
int FUN_000da028(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 *param_5;
{
  int iVar1;
  int iVar2;
  
  if (param_2 == 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x2c) + 4);
  }
  else {
    iVar1 = **(int **)(param_1 + 0x30);
  }
  iVar2 = iVar1 + param_3 * 0x10;
  *param_5 = *(undefined4 *)(iVar1 + param_3 * 0x10);
  param_5[1] = *(undefined4 *)(iVar2 + 4);
  param_5[2] = *(undefined4 *)(iVar2 + 8);
  param_5[3] = *(undefined4 *)(iVar2 + 0xc);
  return;
}

/* FUN_000da070 @ 0xda070 (44 bytes) */
int FUN_000da070(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 *param_5;
{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x2c) + 0x1c);
  }
  else {
    iVar1 = *(int *)(*(int *)(param_1 + 0x30) + 0x18);
  }
  *param_5 = *(undefined4 *)(iVar1 + param_3 * 4);
  return;
}

/* FUN_000da09c @ 0xda09c (36 bytes) */
int FUN_000da09c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = *(int *)(param_1 + 0x38);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x3c);
  }
  *(int *)(iVar1 + 0x100) = *(int *)(iVar1 + 0x100) + 1;
  return;
}

/* FUN_000da0c0 @ 0xda0c0 (720 bytes) */
int FUN_000da0c0(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puStack00000018;
  undefined4 *puStack0000001c;
  
  puStack00000018 = param_1;
  puStack0000001c = param_2;
  iVar1 = (*(code *)param_2[0xc])(param_2[0xb],0x6c8);
  uVar3 = puStack0000001c[0xd];
  *puStack00000018 = uVar3;
  uVar2 = puStack0000001c[0xb];
  puStack00000018[1] = uVar2;
  puStack00000018[3] = *puStack0000001c;
  puStack00000018[5] = puStack0000001c[1];
  puStack00000018[4] = puStack0000001c[0x14];
  if (iVar1 == 0) {
    puStack00000018[2] = 0;
    return;
  }
  FUN_000e1a48(iVar1,uVar2,puStack0000001c[0xc],uVar3,0,0,puStack0000001c[0xf],puStack0000001c[0x10]
              );
  puStack00000018[2] = iVar1;
  if (*(int *)(iVar1 + 0x314) != 0) {
    return;
  }
  iVar1 = _setjmp(*(int **)(iVar1 + 4));
  if (iVar1 != 0) {
    return;
  }
  if (puStack00000018[3] == -1) {
    puStack00000018[10] = puStack0000001c[2];
  }
  else {
    uVar2 = FUN_000cd290();
    puStack00000018[10] = uVar2;
  }
  iVar1 = puStack00000018[10];
  iVar4 = puStack0000001c[3];
  iVar5 = puStack0000001c[4];
  if (iVar1 == 2) {
    FUN_000e1b70(puStack00000018[2],2);
    if (iVar5 - 1U < 0x20c) {
      *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = iVar5;
    }
    else {
      *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = 0x20c;
    }
    if (iVar4 - 1U < 0x100) goto LAB_000da340;
  }
  else {
    if (iVar1 == 3) {
      FUN_000e1b70(puStack00000018[2],4);
      if (iVar5 - 1U < 0x200) {
        *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = iVar5;
      }
      else {
        *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = 0x200;
      }
      if (0x3ff < iVar4 - 1U) {
        *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 4) + 0x40) = 0x400;
        return;
      }
LAB_000da340:
      *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 4) + 0x40) = iVar4;
      return;
    }
    if (iVar1 != 1) {
      *(undefined4 *)(puStack00000018[2] + 0x314) = 0xe;
      FUN_000e1b70(puStack00000018[2],1);
      return;
    }
    FUN_000e1b70(puStack00000018[2],1);
    if (iVar5 - 1U < 0x60) {
      *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = iVar5;
    }
    else {
      *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = 0x60;
    }
    if (iVar4 - 1U < 0x100) {
      *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 4) + 0x40) = iVar5;
      return;
    }
  }
  *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 4) + 0x40) = 0x100;
  return;
}

/* FUN_000da394 @ 0xda394 (68 bytes) */
int FUN_000da394(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x38) = param_3;
  *(undefined4 *)(param_1 + 0x3c) = param_3;
  *(undefined4 *)(param_1 + 0x40) = param_3;
  *(int *)(param_1 + 0x2c) = param_2;
  *(int *)(param_1 + 0x30) = param_2;
  *(int *)(param_1 + 0x34) = param_2;
  if (*(int *)(param_1 + 8) != 0) {
    uVar1 = FUN_000e2524(*(int *)(param_1 + 8),param_3,*(undefined4 *)(param_2 + 0x4c),
                         *(undefined4 *)(param_2 + 0x54));
    return uVar1;
  }
  return 2;
}

/* FUN_000da420 @ 0xda420 (24 bytes) */
int FUN_000da420(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 8) == 0) {
    return 2;
  }
  return *(undefined4 *)(*(int *)(param_1 + 8) + 0x314);
}

/* FUN_000da438 @ 0xda438 (32 bytes) */
int FUN_000da438(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = param_2[2];
  uVar1 = param_2[1];
  *(undefined4 *)(param_1 + 0x18) = *param_2;
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  return;
}

/* FUN_000da458 @ 0xda458 (96 bytes) */
int FUN_000da458(param_1)
  undefined4 *param_1;
{
  if (param_1[2] != 0) {
    FUN_000e1fe4();
                    
                    
    (*(code *)*param_1)(param_1[1],param_1[2]);
    return;
  }
  return;
}

/* FUN_000da4b8 @ 0xda4b8 (720 bytes) */
int FUN_000da4b8(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puStack00000018;
  undefined4 *puStack0000001c;
  
  puStack00000018 = param_1;
  puStack0000001c = param_2;
  iVar1 = (*(code *)param_2[0xc])(param_2[0xb],0x6c8);
  uVar3 = puStack0000001c[0xd];
  *puStack00000018 = uVar3;
  uVar2 = puStack0000001c[0xb];
  puStack00000018[1] = uVar2;
  puStack00000018[3] = *puStack0000001c;
  puStack00000018[5] = puStack0000001c[1];
  puStack00000018[4] = puStack0000001c[0x14];
  if (iVar1 == 0) {
    puStack00000018[2] = 0;
    return;
  }
  FUN_000e1a48(iVar1,uVar2,puStack0000001c[0xc],uVar3,0,0,puStack0000001c[0xf],puStack0000001c[0x10]
              );
  puStack00000018[2] = iVar1;
  if (*(int *)(iVar1 + 0x314) != 0) {
    return;
  }
  iVar1 = _setjmp(*(int **)(iVar1 + 4));
  if (iVar1 != 0) {
    return;
  }
  if (puStack00000018[3] == -1) {
    puStack00000018[10] = puStack0000001c[2];
  }
  else {
    uVar2 = FUN_000cd290();
    puStack00000018[10] = uVar2;
  }
  iVar1 = puStack00000018[10];
  iVar4 = puStack0000001c[3];
  iVar5 = puStack0000001c[4];
  if (iVar1 == 2) {
    FUN_000e1b70(puStack00000018[2],2);
    if (iVar5 - 1U < 0x20c) {
      *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = iVar5;
    }
    else {
      *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = 0x20c;
    }
    if (iVar4 - 1U < 0x100) goto LAB_000da738;
  }
  else {
    if (iVar1 == 3) {
      FUN_000e1b70(puStack00000018[2],4);
      if (iVar5 - 1U < 0x200) {
        *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = iVar5;
      }
      else {
        *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = 0x200;
      }
      if (0x3ff < iVar4 - 1U) {
        *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 4) + 0x40) = 0x400;
        return;
      }
LAB_000da738:
      *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 4) + 0x40) = iVar4;
      return;
    }
    if (iVar1 != 1) {
      *(undefined4 *)(puStack00000018[2] + 0x314) = 0xe;
      FUN_000e1b70(puStack00000018[2],1);
      return;
    }
    FUN_000e1b70(puStack00000018[2],1);
    if (iVar5 - 1U < 0x60) {
      *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = iVar5;
    }
    else {
      *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = 0x60;
    }
    if (iVar4 - 1U < 0x100) {
      *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 4) + 0x40) = iVar5;
      return;
    }
  }
  *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 4) + 0x40) = 0x100;
  return;
}

/* FUN_000da78c @ 0xda78c (244 bytes) */
double FUN_000da78c(uint param_1)

{
  uint uVar1;
  uint uVar2;
  double dVar3;
  double dVar4;
  
  dVar3 = DOUBLE_001aa250;
  uVar1 = param_1 & 7;
  uVar2 = param_1 >> 3 & 0xf;
  if (uVar2 == 0) {
    if (uVar1 == 0) {
      dVar3 = (double)FLOAT_001aa1c0;
    }
    else {
      dVar3 = (double)((float)((double)CONCAT44(0x43300000,uVar1) - DOUBLE_001aa250) *
                       FLOAT_001aa170 * FLOAT_001aa1c4);
    }
  }
  else {
    dVar4 = (double)_pow(DOUBLE_001aa2a0,
                         (double)(float)((double)CONCAT44(0x43300000,uVar2) - DOUBLE_001aa250) -
                         DOUBLE_001aa2a8[0]);
    dVar3 = (double)((float)((double)CONCAT44(0x43300000,uVar1) - dVar3) * FLOAT_001aa170 *
                     (float)dVar4 + (float)dVar4);
  }
  return dVar3;
}

/* FUN_000da8a8 @ 0xda8a8 (40 bytes) */
int FUN_000da8a8(param_1)
  undefined4 *param_1;
{
  param_1[0x87] = 0;
  *param_1 = 0;
  param_1[0x84] = 0;
  param_1[0x85] = 0;
  param_1[0x86] = 0;
  _memset(param_1 + 4,0,0x200);
  return;
}

/* FUN_000da8d0 @ 0xda8d0 (16 bytes) */
int FUN_000da8d0(param_1)
  int param_1;
{
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 4;
  return;
}

/* FUN_000da8e0 @ 0xda8e0 (20 bytes) */
int FUN_000da8e0(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 < 0) {
    param_2 = 0;
  }
  *(int *)(param_1 + 0x21c) = param_2;
  return;
}

/* FUN_000da8f4 @ 0xda8f4 (8 bytes) */
int FUN_000da8f4()
{
  return 0;
}

/* FUN_000da8fc @ 0xda8fc (8 bytes) */
int FUN_000da8fc()
{
  return 0;
}

/* FUN_000da904 @ 0xda904 (128 bytes) */
int FUN_000da904(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  size_t sVar1;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  char acStack_224 [536];
  
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  FUN_001a3428(acStack_224,0x200,param_2,&STACKARG(0x20));
  sVar1 = _strlen((char *)(param_1 + 0x10));
  if (sVar1 <= 0x1ff - sVar1) {
    _strcat((char *)(param_1 + 0x10),acStack_224);
  }
  return;
}

/* FUN_000da984 @ 0xda984 (120 bytes) */
int FUN_000da984(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x210) != 0) {
    ((int (*)())FUN_000da904)(param_1,"\r\n");
    (*(code *)**(undefined4 **)(param_1 + 0x210))
              (*(undefined4 *)(param_1 + 0x214),"",param_1 + 0x10,0);
  }
  *(undefined1 *)(param_1 + 0x10) = 0;
  return;
}

/* FUN_000da9fc @ 0xda9fc (180 bytes) */
int FUN_000da9fc(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  size_t sVar1;
  int iVar2;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  char acStack_234 [540];
  
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  if (0 < param_2) {
    iVar2 = 0;
    do {
      iVar2 = iVar2 + 1;
      ((int (*)())FUN_000da904)(param_1,"    ");
    } while (param_2 != iVar2);
  }
  FUN_001a3428(acStack_234,0x200,param_3,&STACKARG(0x24));
  sVar1 = _strlen((char *)(param_1 + 0x10));
  if (sVar1 <= 0x1ff - sVar1) {
    _strcat((char *)(param_1 + 0x10),acStack_234);
  }
  return;
}

/* FUN_000daab0 @ 0xdaab0 (412 bytes) */
int FUN_000daab0(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  int param_3;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  
  bVar1 = (param_2 >> 3 & 1) != 0;
  uVar3 = param_2 >> 7 & 1;
  uVar2 = param_2 >> 0xb & 1;
  uVar4 = param_2 >> 0xf & 1;
  if ((((!bVar1) && (uVar3 == 0)) && (uVar2 == 0)) && (uVar4 == 0)) {
    return;
  }
  ((int (*)())FUN_000da904)(param_1,"_neg(");
  if (bVar1) {
    if (param_3 == 0) {
      pcVar5 = "x";
    }
    else {
      pcVar5 = "r";
    }
    ((int (*)())FUN_000da904)(param_1,pcVar5);
  }
  if (uVar3 != 0) {
    if (param_3 == 0) {
      pcVar5 = "y";
    }
    else {
      pcVar5 = "g";
    }
    ((int (*)())FUN_000da904)(param_1,pcVar5);
  }
  if (uVar2 != 0) {
    if (param_3 == 0) {
      pcVar5 = "z";
    }
    else {
      pcVar5 = "b";
    }
    ((int (*)())FUN_000da904)(param_1,pcVar5);
  }
  if (uVar4 != 0) {
    if (param_3 == 0) {
      pcVar5 = "w";
    }
    else {
      pcVar5 = "a";
    }
    ((int (*)())FUN_000da904)(param_1,pcVar5);
  }
  ((int (*)())FUN_000da904)(param_1,")");
  return;
}

/* FUN_000dac4c @ 0xdac4c (204 bytes) */
int FUN_000dac4c(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 uVar1;
  
  switch(param_2) {
  case 0:
    uVar1 = 0x78;
    if (param_3 != 0) {
      uVar1 = 0x72;
    }
    break;
  case 1:
    uVar1 = 0x79;
    if (param_3 != 0) {
      uVar1 = 0x67;
    }
    break;
  case 2:
    uVar1 = 0x7a;
    if (param_3 != 0) {
      uVar1 = 0x62;
    }
    break;
  case 3:
    uVar1 = 0x77;
    if (param_3 != 0) {
      uVar1 = 0x61;
    }
    break;
  case 4:
    uVar1 = 0x30;
    break;
  case 5:
    uVar1 = 0x31;
    break;
  default:
    *param_1 = *param_1 + 1;
    ((int (*)())FUN_000da904)(param_1,"!!!invalidCompSel!!!");
    uVar1 = 0;
  }
  return uVar1;
}

/* FUN_000dad30 @ 0xdad30 (300 bytes) */
int FUN_000dad30(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  char local_28;
  char local_27;
  char local_26;
  undefined1 local_25;
  undefined1 local_24;
  
  local_28 = ((int (*)())FUN_000dac4c)(param_1,param_2 & 7);
  local_27 = ((int (*)())FUN_000dac4c)(param_1,param_2 >> 4 & 7,param_3);
  local_26 = ((int (*)())FUN_000dac4c)(param_1,param_2 >> 8 & 7,param_3);
  iVar1 = ((int (*)())FUN_000dac4c)(param_1,param_2 >> 0xc & 7,param_3);
  local_25 = (undefined1)iVar1;
  local_24 = 0;
  iVar2 = _strcmp(&local_28,"rgba");
  if ((iVar2 != 0) && (iVar2 = _strcmp(&local_28,"xyzw"), iVar2 != 0)) {
    if ((((int)local_27 == (int)local_28) &&
        (((int)local_26 == (int)local_27 && (iVar1 == local_26)))) &&
       (((iVar1 - 0x61U & 0xff) < 0x1a || ((iVar1 - 0x41U & 0xff) < 0x1a)))) {
      local_27 = '\0';
    }
    ((int (*)())FUN_000da904)(param_1,".");
    ((int (*)())FUN_000da904)(param_1,&local_28);
  }
  return;
}

/* FUN_000dae5c @ 0xdae5c (260 bytes) */
int FUN_000dae5c(param_1, param_2)
  int *param_1;
  uint param_2;
{
  char *pcVar1;
  
  if ((param_2 & 0x100) != 0) {
    ((int (*)())FUN_000da904)(param_1,"_sat");
  }
  if ((param_2 & 0x1e00) != 0) {
    switch(param_2 >> 9 & 0xf) {
    default:
      pcVar1 = "!!!invalidShift!!!";
      *param_1 = *param_1 + 1;
      break;
    case 1:
      pcVar1 = "_x2";
      break;
    case 2:
      pcVar1 = "_x4";
      break;
    case 3:
      pcVar1 = "_x8";
      break;
    case 4:
      pcVar1 = "_d2";
      break;
    case 5:
      pcVar1 = "_d4";
      break;
    case 6:
      pcVar1 = "_d8";
    }
    ((int (*)())FUN_000da904)(param_1,pcVar1);
    return;
  }
  return;
}

/* FUN_000daf7c @ 0xdaf7c (172 bytes) */
int FUN_000daf7c(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  switch(param_2) {
  case 0:
    ((int (*)())FUN_000da904)(param_1,"unknown");
    return;
  case 1:
    ((int (*)())FUN_000da904)(param_1,"snorm");
    return;
  case 2:
    ((int (*)())FUN_000da904)(param_1,"unorm");
    return;
  case 3:
    ((int (*)())FUN_000da904)(param_1,"sint");
    return;
  case 4:
    ((int (*)())FUN_000da904)(param_1,"uint");
    return;
  case 5:
    ((int (*)())FUN_000da904)(param_1,"float");
    return;
  case 6:
    ((int (*)())FUN_000da904)(param_1,"srgb");
    return;
  case 7:
    ((int (*)())FUN_000da904)(param_1,"mixed");
    return;
  default:
    *param_1 = *param_1 + 1;
    ((int (*)())FUN_000da904)(param_1,"!!!invalidElemFormat!!!");
    return;
  }
}

/* FUN_000db048 @ 0xdb048 (224 bytes) */
int FUN_000db048(param_1)
  int param_1;
{
  uint uVar1;
  
  uVar1 = **(uint **)(param_1 + 8);
  *(uint **)(param_1 + 8) = *(uint **)(param_1 + 8) + 1;
  ((int (*)())FUN_000da904)(param_1,"_fmtx(");
  ((int (*)())FUN_000daf7c)(param_1,uVar1 >> 0x14 & 7);
  ((int (*)())FUN_000da904)(param_1,")");
  ((int (*)())FUN_000da904)(param_1,"_fmty(");
  ((int (*)())FUN_000daf7c)(param_1,uVar1 >> 0x17 & 7);
  ((int (*)())FUN_000da904)(param_1,")");
  ((int (*)())FUN_000da904)(param_1,"_fmtz(");
  ((int (*)())FUN_000daf7c)(param_1,uVar1 >> 0x1a & 7);
  ((int (*)())FUN_000da904)(param_1,")");
  ((int (*)())FUN_000da904)(param_1,"_fmtw(");
  ((int (*)())FUN_000daf7c)(param_1,uVar1 >> 0x1d);
  ((int (*)())FUN_000da904)(param_1,")");
  return;
}

/* FUN_000db128 @ 0xdb128 (156 bytes) */
int FUN_000db128(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  char *param_3;
{
  int iVar1;
  
  iVar1 = 0;
  if (param_3 != (char *)0x0) {
    if (param_2 == 1) {
      iVar1 = (int)*param_3;
    }
    else {
      if (param_2 < 2) {
        if (param_2 == 0) {
          return 0x5f;
        }
      }
      else {
        if (param_2 == 2) {
          return 0x30;
        }
        if (param_2 == 3) {
          return 0x31;
        }
      }
      *param_1 = *param_1 + 1;
      ((int (*)())FUN_000da904)(param_1,"!!!invalidModComp!!!");
      iVar1 = 0x20;
    }
  }
  return iVar1;
}

/* FUN_000db1c4 @ 0xdb1c4 (304 bytes) */
int FUN_000db1c4(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  int param_3;
{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  char local_38 [36];
  
  if ((param_2 & 0xff) != 0x55) {
    bVar1 = param_3 != 0;
    if (bVar1) {
      pcVar2 = "r";
    }
    else {
      pcVar2 = "x";
    }
    local_38[0] = ((int (*)())FUN_000db128)(param_1,param_2 & 3,pcVar2);
    if (bVar1) {
      pcVar2 = "g";
    }
    else {
      pcVar2 = "y";
    }
    local_38[1] = ((int (*)())FUN_000db128)(param_1,param_2 >> 2 & 3,pcVar2);
    if (bVar1) {
      pcVar2 = "b";
    }
    else {
      pcVar2 = "z";
    }
    local_38[2] = ((int (*)())FUN_000db128)(param_1,param_2 >> 4 & 3,pcVar2);
    if (bVar1) {
      pcVar2 = "a";
    }
    else {
      pcVar2 = "w";
    }
    local_38[3] = ((int (*)())FUN_000db128)(param_1,param_2 >> 6 & 3,pcVar2);
    ((int (*)())FUN_000da904)(param_1,".");
    iVar3 = 0;
    do {
      ((int (*)())FUN_000da904)(param_1,"%c",(int)local_38[iVar3]);
      bVar1 = iVar3 != 3;
      iVar3 = iVar3 + 1;
    } while (bVar1);
  }
  return;
}

/* FUN_000db2f4 @ 0xdb2f4 (92 bytes) */
int FUN_000db2f4(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined1 auStack_58 [76];
  
  uVar1 = **(undefined4 **)(param_1 + 8);
  *(undefined4 **)(param_1 + 8) = *(undefined4 **)(param_1 + 8) + 1;
  FUN_001a32d0(auStack_58,"%lu",uVar1);
  ((int (*)())FUN_000da904)(param_1,auStack_58);
  return;
}

/* FUN_000db350 @ 0xdb350 (244 bytes) */
int FUN_000db350(param_1, param_2)
  int *param_1;
  uint param_2;
{
  ((int (*)())FUN_000da904)(param_1,"_cmpval(");
  switch(param_2 >> 0x16 & 7) {
  case 0:
    ((int (*)())FUN_000da904)(param_1,"0.0");
    break;
  case 1:
    ((int (*)())FUN_000da904)(param_1,"0.5");
    break;
  case 2:
    ((int (*)())FUN_000da904)(param_1,"1.0");
    break;
  case 3:
    ((int (*)())FUN_000da904)(param_1,"-0.5");
    break;
  case 4:
    ((int (*)())FUN_000da904)(param_1,"-1.0");
    break;
  default:
    *param_1 = *param_1 + 1;
    ((int (*)())FUN_000da904)(param_1,"!!!invalidCmpVal!!!");
  }
  ((int (*)())FUN_000da904)(param_1,")");
  return;
}

/* FUN_000db458 @ 0xdb458 (260 bytes) */
int FUN_000db458(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_000da904)(param_1,"_usage(");
  switch(param_2) {
  case 0:
    ((int (*)())FUN_000da904)(param_1,"pos");
    break;
  case 1:
    ((int (*)())FUN_000da904)(param_1,"pointsize");
    break;
  case 2:
    ((int (*)())FUN_000da904)(param_1,"color");
    break;
  case 3:
    ((int (*)())FUN_000da904)(param_1,"backcolor");
    break;
  case 4:
    ((int (*)())FUN_000da904)(param_1,"fog");
    break;
  case 5:
    ((int (*)())FUN_000da904)(param_1,"generic");
    break;
  default:
    *param_1 = *param_1 + 1;
    ((int (*)())FUN_000da904)(param_1,"!!!invalid!!!");
  }
  ((int (*)())FUN_000da904)(param_1,")");
  return;
}

/* FUN_000db574 @ 0xdb574 (352 bytes) */
int FUN_000db574(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  float fVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_128 [256];
  undefined4 local_28;
  int iStack_24;
  undefined4 local_20;
  uint uStack_1c;
  undefined4 local_18;
  uint uStack_14;
  
  iStack_24 = 1 << (param_4 & 0x3f);
  local_28 = 0x43300000;
  uStack_1c = 0;
  if (1 < param_3) {
    iVar3 = param_3 - 1;
    uStack_1c = 0;
    if (iVar3 != 0) {
      uVar4 = 0;
      uStack_1c = 0;
      do {
        uVar2 = uVar4 & 0x3f;
        uVar4 = uVar4 + 1;
        uStack_1c = uStack_1c | 1 << uVar2;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      uStack_1c = uStack_1c << (param_4 & 0x3f);
    }
    uStack_1c = param_2 & uStack_1c;
  }
  local_20 = 0x43300000;
  uStack_1c = uStack_1c >> (param_4 & 0x3f);
  fVar1 = (float)((double)CONCAT44(0x43300000,uStack_1c) - DOUBLE_001aa250);
  if ((param_2 & 1 << ((param_4 + param_3) - 1 & 0x3f)) != 0) {
    fVar1 = FLOAT_001aa114 - fVar1;
  }
  uStack_14 = 0;
  if (param_4 != 0) {
    uVar4 = 0;
    uStack_14 = 0;
    do {
      uVar2 = uVar4 & 0x3f;
      uVar4 = uVar4 + 1;
      uStack_14 = uStack_14 | 1 << uVar2;
      param_4 = param_4 - 1;
    } while (param_4 != 0);
    uStack_14 = uStack_14 & param_2;
  }
  local_18 = 0x43300000;
  ((char * (*)())FUN_000cdc3c)((double)((float)(DOUBLE_001aa200 /
                               ((double)CONCAT44(0x43300000,iStack_24) - DOUBLE_001aa250)) *
                        (float)((double)CONCAT44(0x43300000,uStack_14) - DOUBLE_001aa250) + fVar1),
               param_1,10,auStack_128);
  ((int (*)())FUN_000da904)(param_1,auStack_128);
  return;
}

/* FUN_000db6d4 @ 0xdb6d4 (196 bytes) */
int FUN_000db6d4(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  ((int (*)())FUN_000da904)(param_1,"_xoffset(");
  ((int (*)())FUN_000db574)(param_1,param_2 & 0xff,7,1);
  ((int (*)())FUN_000da904)(param_1,")");
  ((int (*)())FUN_000da904)(param_1,"_yoffset(");
  ((int (*)())FUN_000db574)(param_1,param_2 >> 8 & 0xff,7,1);
  ((int (*)())FUN_000da904)(param_1,")");
  ((int (*)())FUN_000da904)(param_1,"_zoffset(");
  ((int (*)())FUN_000db574)(param_1,param_2 >> 0x10 & 0xff,7,1);
  ((int (*)())FUN_000da904)(param_1,")");
  return;
}

/* FUN_000db798 @ 0xdb798 (132 bytes) */
int FUN_000db798(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  uint param_3;
{
  uint uVar1;
  undefined1 auStack_118 [268];
  
  uVar1 = (1 << (param_3 & 0x3f)) - 1;
  param_2 = uVar1 & param_2;
  if ((param_2 & 1 << (param_3 - 1 & 0x3f)) != 0) {
    param_2 = (uVar1 & ~param_2) + 1;
    ((int (*)())FUN_000da904)(param_1,"-");
  }
  FUN_001a32d0(auStack_118,"%lu",param_2);
  ((int (*)())FUN_000da904)(param_1,auStack_118);
  return;
}

/* FUN_000db81c @ 0xdb81c (196 bytes) */
int FUN_000db81c(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  
  if ((param_2 & 0x20000000) != 0) {
    ((int (*)())FUN_000da904)(param_1,"_aoffimmi(");
    uVar1 = **(uint **)(param_1 + 8);
    *(uint **)(param_1 + 8) = *(uint **)(param_1 + 8) + 1;
    ((int (*)())FUN_000db798)(param_1,uVar1 & 0xf,4);
    ((int (*)())FUN_000da904)(param_1,",");
    ((int (*)())FUN_000db798)(param_1,uVar1 >> 4 & 0xf,4);
    ((int (*)())FUN_000da904)(param_1,",");
    ((int (*)())FUN_000db798)(param_1,uVar1 >> 8 & 0xf,4);
    ((int (*)())FUN_000da904)(param_1,")");
    return;
  }
  return;
}

/* FUN_000db8e0 @ 0xdb8e0 (88 bytes) */
int FUN_000db8e0(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  undefined1 auStack_118 [268];
  
  FUN_001a32d0(auStack_118,"_resource(%d)_sampler(%d)",param_2 >> 0x10 & 0xff,param_2 >> 0x18 & 0x1f
              );
  ((int (*)())FUN_000da904)(param_1,auStack_118);
  return;
}

/* FUN_000db938 @ 0xdb938 (280 bytes) */
int FUN_000db938(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  ((int (*)())FUN_000da904)(param_1,"_aniso(");
  switch(param_2) {
  case 0:
    ((int (*)())FUN_000da904)(param_1,"unknown");
    break;
  case 1:
    ((int (*)())FUN_000da904)(param_1,"disabled");
    break;
  case 2:
    ((int (*)())FUN_000da904)(param_1,"1");
    break;
  case 3:
    ((int (*)())FUN_000da904)(param_1,"2");
    break;
  case 4:
    ((int (*)())FUN_000da904)(param_1,"4");
    break;
  case 5:
    ((int (*)())FUN_000da904)(param_1,"8");
    break;
  case 6:
    ((int (*)())FUN_000da904)(param_1,"16");
    break;
  default:
    *param_1 = *param_1 + 1;
    ((int (*)())FUN_000da904)(param_1,"!!invalid!!");
  }
  ((int (*)())FUN_000da904)(param_1,")");
  return;
}

/* FUN_000dba6c @ 0xdba6c (216 bytes) */
int FUN_000dba6c(param_1, param_2)
  int *param_1;
  int param_2;
{
  ((int (*)())FUN_000da904)(param_1,"_mip(");
  if (param_2 == 1) {
    ((int (*)())FUN_000da904)(param_1,"point");
  }
  else if (param_2 == 0) {
    ((int (*)())FUN_000da904)(param_1,"unknown");
  }
  else if (param_2 == 2) {
    ((int (*)())FUN_000da904)(param_1,"linear");
  }
  else if (param_2 == 3) {
    ((int (*)())FUN_000da904)(param_1,"base");
  }
  else {
    *param_1 = *param_1 + 1;
    ((int (*)())FUN_000da904)(param_1,"!!invalid!!");
  }
  ((int (*)())FUN_000da904)(param_1,")");
  return;
}

/* FUN_000dbb44 @ 0xdbb44 (124 bytes) */
int FUN_000dbb44(param_1, param_2)
  int *param_1;
  int param_2;
{
  if (param_2 == 1) {
    ((int (*)())FUN_000da904)(param_1,"point");
    return;
  }
  if (param_2 == 0) {
    ((int (*)())FUN_000da904)(param_1,"unknown");
    return;
  }
  if (param_2 == 2) {
    ((int (*)())FUN_000da904)(param_1,"linear");
    return;
  }
  if (param_2 == 3) {
    ((int (*)())FUN_000da904)(param_1,"aniso");
    return;
  }
  *param_1 = *param_1 + 1;
  ((int (*)())FUN_000da904)(param_1,"!!invalid!!");
  return;
}

/* FUN_000dbbc0 @ 0xdbbc0 (284 bytes) */
int FUN_000dbbc0(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  ((int (*)())FUN_000da904)(param_1,"_mag(");
  ((int (*)())FUN_000dbb44)(param_1,param_2 & 7);
  ((int (*)())FUN_000da904)(param_1,")");
  ((int (*)())FUN_000da904)(param_1,"_min(");
  ((int (*)())FUN_000dbb44)(param_1,param_2 >> 3 & 7);
  ((int (*)())FUN_000da904)(param_1,")");
  ((int (*)())FUN_000da904)(param_1,"_volmag(");
  ((int (*)())FUN_000dbb44)(param_1,param_2 >> 6 & 7);
  ((int (*)())FUN_000da904)(param_1,")");
  ((int (*)())FUN_000da904)(param_1,"_volmin(");
  ((int (*)())FUN_000dbb44)(param_1,param_2 >> 9 & 7);
  ((int (*)())FUN_000da904)(param_1,")");
  ((int (*)())FUN_000dba6c)(param_1,param_2 >> 0xc & 7);
  ((int (*)())FUN_000db938)(param_1,param_2 >> 0xf & 7);
  ((int (*)())FUN_000da904)(param_1,"_lodbias(");
  ((int (*)())FUN_000db574)(param_1,param_2 >> 0x12 & 0x7f,3,4);
  ((int (*)())FUN_000da904)(param_1,")");
  return;
}

