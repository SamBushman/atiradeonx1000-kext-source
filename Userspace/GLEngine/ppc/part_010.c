#include "decls.h"

/* _glBindBuffer_Exec @ 0x58520 (240 bytes) */
void _glBindBuffer_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  int iVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((0x8891 < param_2) && ((param_2 < 0x8894 || (param_2 - 0x88eb < 2)))) {
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        iVar2 = *(int *)(param_1 + 0x5148) + 0x8028;
        _pthread_mutex_lock(iVar2);
        _gleBindBufferObject(param_1,param_2,param_3);
        _pthread_mutex_unlock(iVar2);
        return;
      }
      _gleBindBufferObject(param_1,param_2,param_3);
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glDeleteBuffers_Exec @ 0x58610 (696 bytes) */
void _glDeleteBuffers_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (-1 < param_2) {
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_lock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
      iVar3 = *(int *)(param_1 + 0x4a60);
      iVar9 = 0;
      if (*(int *)(iVar3 + 0x358) != 0) {
        iVar9 = *(int *)(*(int *)(iVar3 + 0x358) + 4);
      }
      iVar8 = 0;
      if (*(int *)(iVar3 + 0x35c) != 0) {
        iVar8 = *(int *)(*(int *)(iVar3 + 0x35c) + 4);
      }
      iVar11 = 0;
      if (*(int *)(param_1 + 0x4a68) != 0) {
        iVar11 = *(int *)(*(int *)(param_1 + 0x4a68) + 4);
      }
      iVar10 = 0;
      if (*(int *)(param_1 + 0x4a6c) != 0) {
        iVar10 = *(int *)(*(int *)(param_1 + 0x4a6c) + 4);
      }
      bVar1 = false;
      if (0 < param_2) {
        do {
          iVar12 = *param_3;
          param_3 = param_3 + 1;
          if (iVar12 != 0) {
            iVar13 = 0;
            iVar14 = iVar3 + 0x10;
            iVar15 = iVar3 + 0x10;
            do {
              iVar6 = *(int *)(iVar15 + 0x350);
              if ((iVar6 != 0) && (iVar12 == *(int *)(iVar6 + 4))) {
                bVar1 = true;
                iVar4 = *(int *)(iVar6 + 8) + -1;
                *(int *)(iVar6 + 8) = iVar4;
                if (iVar4 == 0) {
                  _gleFreeBufferObject(param_1,iVar6);
                }
                uVar7 = *(uint *)(iVar3 + 0x33c);
                *(undefined4 *)(iVar15 + 0x350) = 0;
                *(undefined4 *)(iVar3 + 0x338) = 0;
                *(uint *)(iVar3 + 0x33c) = uVar7 & ~(1 << (iVar13 + 0x10U & 0x3f));
                iVar6 = 0;
                if (*(char *)(param_1 + 0x85a4) != '\0') {
                  puVar5 = (undefined4 *)(iVar14 + 0x3d0);
                  do {
                    *puVar5 = 0;
                    iVar6 = iVar6 + 1;
                    puVar5 = puVar5 + 0x23;
                  } while (iVar6 < (int)(uint)*(byte *)(param_1 + 0x85a4));
                }
              }
              iVar13 = iVar13 + 1;
              iVar14 = iVar14 + 4;
              iVar15 = iVar15 + 4;
            } while (iVar13 < 0x20);
            if (iVar12 == iVar9) {
              _gleBindBufferObject(param_1,0x8892,0);
            }
            if (iVar12 == iVar8) {
              _gleBindBufferObject(param_1,0x8893,0);
            }
            if (iVar12 == iVar11) {
              _gleBindBufferObject(param_1,0x88eb,0);
            }
            if (iVar12 == iVar10) {
              _gleBindBufferObject(param_1,0x88ec,0);
            }
            _gleDeleteHashNameAndObject(param_1,*(int *)(param_1 + 0x5148) + 0x701c,iVar12);
          }
          param_2 = param_2 + -1;
        } while (param_2 != 0);
        if (bVar1) {
          _gleResetVACachePointers(param_1);
          *(undefined4 *)(iVar3 + 0x350) = *(undefined4 *)(iVar3 + 0x350);
          *(uint *)(iVar3 + 0x354) = *(uint *)(iVar3 + 0x354) | 0x10;
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
        }
      }
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
        return;
      }
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glGenBuffers_Exec @ 0x588c8 (168 bytes) */
void _glGenBuffers_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (-1 < param_2) {
      iVar4 = _gleGenHashNames(*(int *)(param_1 + 0x5148) + 0x701c,param_2);
      if (iVar4 == 0) {
        return;
      }
      iVar3 = 0;
      if (param_2 < 1) {
        return;
      }
      do {
        iVar2 = iVar3 + iVar4;
        iVar3 = iVar3 + 1;
        *param_3 = iVar2;
        param_3 = param_3 + 1;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glIsBuffer_Exec @ 0x58970 (168 bytes) */
int _glIsBuffer_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  bool bVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar1 = *(int *)(param_1 + 0x5148);
    if (*(char *)(iVar1 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar1 + 0x8028);
      iVar1 = *(int *)(param_1 + 0x5148);
    }
    iVar1 = _gleLookupHashObject(iVar1 + 0x701c,param_2);
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
    bVar2 = iVar1 != 0;
  }
  else {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
    bVar2 = false;
  }
  return bVar2;
}

/* FUN_00058a1c @ 0x58a1c (304 bytes) */
void FUN_00058a1c(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  int param_3;
  int param_4;
  uint param_5;
{
  byte bVar1;
  uint size;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  vm_address_t avStack_40 [7];
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x8893) {
      iVar6 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x35c);
LAB_00058acc:
      if (iVar6 == 0) goto LAB_00058ad4;
      switch(param_5) {
      case 0x88e0:
      case 0x88e1:
      case 0x88e2:
      case 0x88e4:
      case 0x88e5:
      case 0x88e6:
      case 0x88e8:
      case 0x88e9:
      case 0x88ea:
        _gleOrphanBufferData(param_1,iVar6 + 0x10,param_3,param_5 & 0xffff);
        if (*(int *)(iVar6 + 0x30) != 0) {
          if ((param_4 != 0) && (param_3 != 0)) {
            _memcpy(*(int *)(iVar6 + 0x30),param_4,param_3);
          }
          if (1 < *(int *)(iVar6 + 8)) {
            if ((param_4 == 0) || (param_3 == 0)) {
              uVar2 = *(undefined4 *)(param_1 + 0x4688);
              bVar1 = *(byte *)(param_1 + 0x85a8);
              uVar3 = 0;
            }
            else {
              uVar2 = *(undefined4 *)(param_1 + 0x4688);
              bVar1 = *(byte *)(param_1 + 0x85a8);
              uVar3 = *(undefined4 *)(iVar6 + 0x30);
            }
            (**(code **)(param_1 + 0x481c))
                      (uVar2,*(undefined4 *)((uint)bVar1 * 4 + iVar6 + 0x10),uVar3,param_3);
            if (param_2 - 0x8892 < 2) {
              _gleResetVACachePointers(param_1);
              iVar4 = *(int *)(param_1 + 0x4a60);
              *(undefined4 *)(iVar4 + 0x350) = *(undefined4 *)(iVar4 + 0x350);
              *(uint *)(iVar4 + 0x354) = *(uint *)(iVar4 + 0x354) | 0x10;
              *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
            }
          }
          *(short *)(iVar6 + 0x3c) = (short)param_5;
          *(undefined1 *)(iVar6 + 0x44) = 0;
          *(int *)(iVar6 + 0x38) = param_3;
          return;
        }
        size = param_3 + 0xfffU & 0xfffff000;
        if (param_3 == 0) {
          uVar5 = 0;
          avStack_40[0] = 0;
code_r0x00058cb0:
          *(undefined1 *)(iVar6 + 0x44) = 0;
          *(int *)(iVar6 + 0x38) = param_3;
          *(short *)(iVar6 + 0x3c) = (short)param_5;
          *(uint *)(iVar6 + 0x34) = size;
          *(vm_address_t *)(iVar6 + 0x30) = avStack_40[0];
          if ((param_2 - 0x8892 < 2) && (1 < *(int *)(iVar6 + 8))) {
            _gleResetVACachePointers(param_1);
            iVar4 = *(int *)(param_1 + 0x4a60);
            *(undefined4 *)(iVar4 + 0x350) = *(undefined4 *)(iVar4 + 0x350);
            *(uint *)(iVar4 + 0x354) = *(uint *)(iVar4 + 0x354) | 0x10;
            *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
          }
          if (uVar5 == 0) {
            return;
          }
          iVar4 = 0;
          if (*(char *)(param_1 + 0x85a4) == '\0') {
            return;
          }
          do {
            iVar4 = iVar4 + 1;
            *(uint *)(iVar6 + 0x48) = *(uint *)(iVar6 + 0x48) | uVar5;
            iVar6 = iVar6 + 4;
          } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x85a4));
          return;
        }
        _vm_allocate(*(vm_map_t *)PTR_00112034,avStack_40,size,1);
        if (avStack_40[0] != 0) {
          uVar5 = 3;
          if (param_4 != 0) {
            _memcpy(avStack_40[0],param_4,param_3);
          }
          goto code_r0x00058cb0;
        }
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar2 = 0x505;
        goto LAB_00058c84;
      }
    }
    else {
      if (0x8893 < param_2) {
        if (param_2 == 0x88eb) {
          iVar6 = *(int *)(param_1 + 0x4a68);
        }
        else {
          if (param_2 != 0x88ec) goto LAB_00058b40;
          iVar6 = *(int *)(param_1 + 0x4a6c);
        }
        goto LAB_00058acc;
      }
      if (param_2 == 0x8892) {
        iVar6 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x358);
        goto LAB_00058acc;
      }
    }
LAB_00058b40:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x500;
  }
  else {
LAB_00058ad4:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
  }
LAB_00058c84:
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glBufferSubData_Exec @ 0x58d74 (844 bytes) */
void _glBufferSubData_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  vm_size_t size;
  vm_address_t local_40 [5];
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x8893) {
      iVar7 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x35c);
    }
    else if (param_2 < 0x8894) {
      if (param_2 != 0x8892) {
LAB_00058e24:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar3 = 0x500;
        goto LAB_00058eb4;
      }
      iVar7 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x358);
    }
    else if (param_2 == 0x88eb) {
      iVar7 = *(int *)(param_1 + 0x4a68);
    }
    else {
      if (param_2 != 0x88ec) goto LAB_00058e24;
      iVar7 = *(int *)(param_1 + 0x4a6c);
    }
    if ((iVar7 != 0) && (*(char *)(iVar7 + 0x44) == '\0')) {
      size = *(vm_size_t *)(iVar7 + 0x34);
      if (size == 0) {
        return;
      }
      local_40[0] = *(vm_address_t *)(iVar7 + 0x30);
      if (local_40[0] != 0) {
        iVar5 = param_1 + 0x10000;
        iVar4 = (**(code **)(param_1 + 0x4718))
                          (*(undefined4 *)(param_1 + 0x4688),
                           *(undefined4 *)((uint)*(byte *)(param_1 + 0x85a8) * 4 + iVar7 + 0x10),
                           param_3,param_4,param_5);
        if (iVar4 != 0) {
          *(undefined4 *)(iVar7 + 0x40) =
               *(undefined4 *)
                ((uint)*(byte *)(param_1 + 0x85a8) * 4 + *(int *)(param_1 + 0x5148) + 0x8054);
          return;
        }
        iVar6 = 0;
        iVar4 = iVar7;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          do {
            piVar1 = (int *)(iVar5 + -0x777c);
            puVar2 = (undefined4 *)(iVar5 + -0x7a54);
            iVar6 = iVar6 + 1;
            iVar5 = iVar5 + 0x2e0;
            (**(code **)(*piVar1 + 0x1c4))(*puVar2,3,*(undefined4 *)(iVar4 + 0x10));
            *(uint *)(iVar4 + 0x48) = *(uint *)(iVar4 + 0x48) | 2;
            iVar4 = iVar4 + 4;
          } while (iVar6 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
        _memcpy(local_40[0] + param_3,param_5,param_4);
        if (*(int *)(iVar7 + 8) < 2) {
          return;
        }
        (**(code **)(param_1 + 0x481c))
                  (*(undefined4 *)(param_1 + 0x4688),
                   *(undefined4 *)((uint)*(byte *)(param_1 + 0x85a8) * 4 + iVar7 + 0x10),
                   local_40[0] + param_3,param_4);
        if (*(int *)((uint)*(byte *)(param_1 + 0x85a8) * 4 + iVar7 + 0x48) == 0) {
          return;
        }
        if (1 < param_2 - 0x8892) {
          return;
        }
        iVar7 = *(int *)(param_1 + 0x4a60);
        *(undefined4 *)(iVar7 + 0x350) = *(undefined4 *)(iVar7 + 0x350);
        *(uint *)(iVar7 + 0x354) = *(uint *)(iVar7 + 0x354) | 0x10;
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
        return;
      }
      _vm_allocate(*(vm_map_t *)PTR_00112034,local_40,size,1);
      if (local_40[0] != 0) {
        *(vm_address_t *)(iVar7 + 0x30) = local_40[0];
        *(vm_size_t *)(iVar7 + 0x34) = size;
        if ((param_2 - 0x8892 < 2) && (1 < *(int *)(iVar7 + 8))) {
          _gleResetVACachePointers(param_1);
          iVar4 = *(int *)(param_1 + 0x4a60);
          *(undefined4 *)(iVar4 + 0x350) = *(undefined4 *)(iVar4 + 0x350);
          *(uint *)(iVar4 + 0x354) = *(uint *)(iVar4 + 0x354) | 0x10;
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
        }
        iVar4 = 0;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          do {
            iVar4 = iVar4 + 1;
            *(uint *)(iVar7 + 0x48) = *(uint *)(iVar7 + 0x48) | 3;
            iVar7 = iVar7 + 4;
          } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
        _memcpy(local_40[0] + param_3,param_5,param_4);
        return;
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar3 = 0x505;
      goto LAB_00058eb4;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x502;
LAB_00058eb4:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glGetBufferSubData_Exec @ 0x590c0 (308 bytes) */
void _glGetBufferSubData_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined4 uVar1;
  int iVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x8893) {
      iVar2 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x35c);
    }
    else if (param_2 < 0x8894) {
      if (param_2 != 0x8892) {
LAB_00059160:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar1 = 0x500;
        goto LAB_00059198;
      }
      iVar2 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x358);
    }
    else if (param_2 == 0x88eb) {
      iVar2 = *(int *)(param_1 + 0x4a68);
    }
    else {
      if (param_2 != 0x88ec) goto LAB_00059160;
      iVar2 = *(int *)(param_1 + 0x4a6c);
    }
    if ((iVar2 != 0) && (*(char *)(iVar2 + 0x44) == '\0')) {
      if (*(int *)(iVar2 + 0x40) != 0) {
        _gleSynchronizePluginBuffer(param_1,iVar2 + 0x10);
      }
      if (*(int *)(iVar2 + 0x30) == 0) {
        return;
      }
      _memcpy(param_5,*(int *)(iVar2 + 0x30) + param_3,param_4);
      return;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x502;
LAB_00059198:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glMapBuffer_Exec @ 0x591f4 (564 bytes) */
int _glMapBuffer_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  vm_size_t size;
  int iVar4;
  int iVar5;
  int iVar6;
  vm_address_t local_30 [7];
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 != 0x8893) {
      if (0x8893 < param_2) {
        if (param_2 == 0x88eb) {
          iVar6 = *(int *)(param_1 + 0x4a68);
        }
        else {
          if (param_2 != 0x88ec) goto LAB_000592a8;
          iVar6 = *(int *)(param_1 + 0x4a6c);
        }
        goto LAB_00059290;
      }
      if (param_2 == 0x8892) {
        iVar6 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x358);
        goto LAB_00059290;
      }
LAB_000592a8:
      if (*(int *)(param_1 + 0x7574) != 0) {
        return 0;
      }
      uVar3 = 0x500;
      goto LAB_0005933c;
    }
    iVar6 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x35c);
LAB_00059290:
    if (iVar6 != 0) {
      if (2 < param_3 - 35000U) goto LAB_000592a8;
      if (*(char *)(iVar6 + 0x44) == '\0') {
        local_30[0] = *(vm_address_t *)(iVar6 + 0x30);
        *(undefined1 *)(iVar6 + 0x44) = 1;
        *(short *)(iVar6 + 0x3e) = (short)param_3;
        size = *(vm_size_t *)(iVar6 + 0x34);
        if ((local_30[0] != 0) || (size == 0)) {
          if (*(int *)(iVar6 + 0x40) != 0) {
            _gleSynchronizePluginBuffer(param_1,iVar6 + 0x10);
          }
          iVar4 = param_1 + 0x10000;
          iVar5 = 0;
          if (*(char *)(param_1 + 0x85a4) != '\0') {
            do {
              piVar1 = (int *)(iVar4 + -0x777c);
              puVar2 = (undefined4 *)(iVar4 + -0x7a54);
              iVar5 = iVar5 + 1;
              iVar4 = iVar4 + 0x2e0;
              (**(code **)(*piVar1 + 0x1c4))(*puVar2,3,*(undefined4 *)(iVar6 + 0x10));
              *(uint *)(iVar6 + 0x48) = *(uint *)(iVar6 + 0x48) | 2;
              iVar6 = iVar6 + 4;
            } while (iVar5 < (int)(uint)*(byte *)(param_1 + 0x85a4));
            return local_30[0];
          }
          return local_30[0];
        }
        _vm_allocate(*(vm_map_t *)PTR_00112034,local_30,size,1);
        if (local_30[0] != 0) {
          *(vm_address_t *)(iVar6 + 0x30) = local_30[0];
          *(vm_size_t *)(iVar6 + 0x34) = size;
          if (1 < *(int *)(iVar6 + 8)) {
            _gleResetVACachePointers(param_1);
          }
          iVar4 = 0;
          if (*(char *)(param_1 + 0x85a4) != '\0') {
            do {
              iVar4 = iVar4 + 1;
              *(uint *)(iVar6 + 0x48) = *(uint *)(iVar6 + 0x48) | 3;
              iVar6 = iVar6 + 4;
            } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x85a4));
            return local_30[0];
          }
          return local_30[0];
        }
        if (*(int *)(param_1 + 0x7574) != 0) {
          return 0;
        }
        uVar3 = 0x505;
        goto LAB_0005933c;
      }
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return 0;
  }
  uVar3 = 0x502;
LAB_0005933c:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return 0;
}

/* _glUnmapBuffer_Exec @ 0x59428 (392 bytes) */
int _glUnmapBuffer_Exec(param_1, param_2)
  int param_1;
  uint param_2;
{
  undefined4 uVar1;
  int iVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x8893) {
      iVar2 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x35c);
    }
    else if (param_2 < 0x8894) {
      if (param_2 != 0x8892) {
LAB_000594c4:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return 0;
        }
        uVar1 = 0x500;
        goto LAB_000594fc;
      }
      iVar2 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x358);
    }
    else if (param_2 == 0x88eb) {
      iVar2 = *(int *)(param_1 + 0x4a68);
    }
    else {
      if (param_2 != 0x88ec) goto LAB_000594c4;
      iVar2 = *(int *)(param_1 + 0x4a6c);
    }
    if ((iVar2 != 0) && (*(char *)(iVar2 + 0x44) != '\0')) {
      *(undefined1 *)(iVar2 + 0x44) = 0;
      if ((1 < *(int *)(iVar2 + 8)) &&
         (((**(code **)(param_1 + 0x481c))
                     (*(undefined4 *)(param_1 + 0x4688),
                      *(undefined4 *)((uint)*(byte *)(param_1 + 0x85a8) * 4 + iVar2 + 0x10),
                      *(undefined4 *)(iVar2 + 0x30),*(undefined4 *)(iVar2 + 0x38)),
          *(int *)((uint)*(byte *)(param_1 + 0x85a8) * 4 + iVar2 + 0x48) != 0 &&
          (param_2 - 0x8892 < 2)))) {
        iVar2 = *(int *)(param_1 + 0x4a60);
        *(undefined4 *)(iVar2 + 0x350) = *(undefined4 *)(iVar2 + 0x350);
        *(uint *)(iVar2 + 0x354) = *(uint *)(iVar2 + 0x354) | 0x10;
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
      }
      return 1;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return 0;
  }
  uVar1 = 0x502;
LAB_000594fc:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return 0;
}

/* _glGetBufferParameteriv_Exec @ 0x595b0 (300 bytes) */
void _glGetBufferParameteriv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint *param_4;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x8893) {
      iVar3 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x35c);
LAB_0005964c:
      if (iVar3 == 0) goto LAB_00059654;
      if (param_3 == 0x8765) {
        uVar2 = (uint)*(ushort *)(iVar3 + 0x3c);
        goto LAB_000596c4;
      }
      if (param_3 < 0x8766) {
        if (param_3 == 0x8764) {
          uVar2 = *(uint *)(iVar3 + 0x38);
          goto LAB_000596c4;
        }
      }
      else {
        if (param_3 == 0x88bb) {
          uVar2 = (uint)*(ushort *)(iVar3 + 0x3e);
LAB_000596c4:
          *param_4 = uVar2;
          return;
        }
        if (param_3 == 0x88bc) {
          uVar2 = (uint)*(byte *)(iVar3 + 0x44);
          goto LAB_000596c4;
        }
      }
    }
    else {
      if (0x8893 < param_2) {
        if (param_2 == 0x88eb) {
          iVar3 = *(int *)(param_1 + 0x4a68);
        }
        else {
          if (param_2 != 0x88ec) goto LAB_00059634;
          iVar3 = *(int *)(param_1 + 0x4a6c);
        }
        goto LAB_0005964c;
      }
      if (param_2 == 0x8892) {
        iVar3 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x358);
        goto LAB_0005964c;
      }
    }
LAB_00059634:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
  }
  else {
LAB_00059654:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glGetBufferPointerv_Exec @ 0x596dc (224 bytes) */
void _glGetBufferPointerv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  int param_3;
  undefined4 *param_4;
{
  undefined4 uVar1;
  int iVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x8893) {
      iVar2 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x35c);
LAB_00059778:
      if (iVar2 == 0) goto LAB_00059780;
      if (param_3 == 0x88bd) {
        uVar1 = 0;
        if (*(char *)(iVar2 + 0x44) != '\0') {
          uVar1 = *(undefined4 *)(iVar2 + 0x30);
        }
        *param_4 = uVar1;
        return;
      }
    }
    else {
      if (0x8893 < param_2) {
        if (param_2 == 0x88eb) {
          iVar2 = *(int *)(param_1 + 0x4a68);
        }
        else {
          if (param_2 != 0x88ec) goto LAB_00059760;
          iVar2 = *(int *)(param_1 + 0x4a6c);
        }
        goto LAB_00059778;
      }
      if (param_2 == 0x8892) {
        iVar2 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x358);
        goto LAB_00059778;
      }
    }
LAB_00059760:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
  }
  else {
LAB_00059780:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glClear_ListExec @ 0x597bc (40 bytes) */
undefined4 _glClear_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  ((void (*)())_glClear_Exec)(param_1,*param_2,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,
                fparam_8);
  return 4;
}

/* _glClear_NoopExec @ 0x597e4 (640 bytes) */
void _glClear_NoopExec(int param_1,undefined4 param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar5;
  uint uVar6;
  int *piVar7;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  iVar5 = *(int *)(param_1 + 0x50ac);
  if (iVar5 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) != '\0') {
    iVar4 = *(int *)(param_1 + 0x744c);
    piVar7 = (int *)(param_1 + 0x310);
    cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
    if ((iVar4 != 0) && (*(int *)(iVar4 + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar4 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar5,fparam_1,fparam_2,fparam_3,
                 fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000598fc:
      uVar6 = *(uint *)(param_1 + 0x31c);
    }
    else {
      iVar5 = 0;
      piVar3 = (int *)(param_1 + 0x324);
      do {
        iVar4 = *piVar3;
        piVar3 = piVar3 + 1;
        if (iVar4 != 0) {
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
          break;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 9);
      uVar6 = *(uint *)(param_1 + 0x31c);
      if ((uVar6 & 0x15555) != 0) {
        if (*(char *)(param_1 + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
        }
        if (*(char *)(param_1 + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
        }
        goto LAB_000598fc;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      uVar6 = uVar6 & 0x17000000;
    }
    else {
      uVar6 = uVar6 & 0x17ffffff;
    }
    if (bVar1) {
      bVar1 = ((*piVar7 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar6 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    else {
      bVar1 = (((*piVar7 == 0 && *(int *)(param_1 + 0x314) == 0) &&
               (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar6 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    if (!bVar1) {
      if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
        uVar6 = (**(code **)(param_1 + 0x4788))
                          (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar7);
        if ((((uVar6 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
            ((uVar6 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
           (fparam_1 = extraout_f1_01, (uVar6 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0')))
        {
          if ((uVar6 & 4) == 0) {
            uVar6 = uVar6 & 0xfffffffe;
            *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
          }
          fparam_1 = (double)_gleUpdateDispatchCodeChange(param_1,uVar6);
          if (*(char *)(param_1 + 0x759d) == '\0') goto LAB_00059a1c;
        }
      }
      else {
        fparam_1 = (double)_gleSwitchToNonRevertRenderer(param_1);
      }
      iVar5 = 0x13;
      do {
        *piVar7 = 0;
        piVar7 = piVar7 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
  }
  if (*(char *)(param_1 + 0x759d) != '\0') {
    ((void (*)())_glClear_Exec)(param_1,param_2,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,
                  fparam_8);
    return;
  }
LAB_00059a1c:
  if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x506;
  }
  return;
}

/* _glClearAccum_ListExec @ 0x59a64 (52 bytes) */
int _glClearAccum_ListExec(param_1, param_2)
  undefined4 param_1;
  float *param_2;
{
  ((void (*)())_glClearAccum_Exec)(param_1,(double)*param_2,(double)param_2[1],(double)param_2[2],
                     (double)param_2[3]);
  return 0x10;
}

/* _glClearAccum_Comp @ 0x59a98 (92 bytes) */
void _glClearAccum_Comp(undefined4 param_1,float fparam_1,float fparam_2,float fparam_3,float fparam_4)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glClearAccum_ListExec_0011004c,0x10);
  if (pfVar1 != (float *)0x0) {
    pfVar1[3] = (float)fparam_4;
    *pfVar1 = (float)fparam_1;
    pfVar1[1] = (float)fparam_2;
    pfVar1[2] = (float)fparam_3;
  }
  return;
}

/* _glClearAccum_Exec @ 0x59af4 (280 bytes) */
void _glClearAccum_Exec(int param_1,float fparam_1,float fparam_2,float fparam_3,float fparam_4)
{
  float fVar1;
  float dVar2;
  
  fVar1 = FLOAT_00108e58;
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
    return;
  }
  dVar2 = (double)FLOAT_00108e58;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x40;
  if ((double)dVar2 <= fparam_1) {
    if (fparam_1 <= 1.0) {
      *(float *)(param_1 + 0x30f0) = (float)fparam_1;
    }
    else {
      *(undefined4 *)(param_1 + 0x30f0) = 0x3f800000;
    }
  }
  else {
    *(float *)(param_1 + 0x30f0) = fVar1;
  }
  if ((double)FLOAT_00108e58 <= fparam_2) {
    if (fparam_2 <= 1.0) {
      *(float *)(param_1 + 0x30f4) = (float)fparam_2;
    }
    else {
      *(undefined4 *)(param_1 + 0x30f4) = 0x3f800000;
    }
  }
  else {
    *(float *)(param_1 + 0x30f4) = FLOAT_00108e58;
  }
  if ((double)FLOAT_00108e58 <= fparam_3) {
    if (fparam_3 <= 1.0) {
      *(float *)(param_1 + 0x30f8) = (float)fparam_3;
    }
    else {
      *(undefined4 *)(param_1 + 0x30f8) = 0x3f800000;
    }
  }
  else {
    *(float *)(param_1 + 0x30f8) = FLOAT_00108e58;
  }
  if (fparam_4 < (double)FLOAT_00108e58) {
    *(float *)(param_1 + 0x30fc) = FLOAT_00108e58;
    return;
  }
  if (1.0 < fparam_4) {
    *(undefined4 *)(param_1 + 0x30fc) = 0x3f800000;
    return;
  }
  *(float *)(param_1 + 0x30fc) = (float)fparam_4;
  return;
}

/* _glClearAccum_CompExec @ 0x59c0c (96 bytes) */
void _glClearAccum_CompExec(undefined4 param_1,float fparam_1,float fparam_2,float fparam_3,float fparam_4)
{
  ((void (*)())_glClearAccum_Comp)(param_1,fparam_1,fparam_2,fparam_3,fparam_4);
  ((void (*)())_glClearAccum_Exec)(param_1,fparam_1,fparam_2,fparam_3,fparam_4);
  return;
}

/* _glClearColor_ListExec @ 0x59c6c (52 bytes) */
int _glClearColor_ListExec(param_1, param_2)
  undefined4 param_1;
  float *param_2;
{
  ((void (*)())_glClearColor_Exec)(param_1,(double)*param_2,(double)param_2[1],(double)param_2[2],
                     (double)param_2[3]);
  return 0x10;
}

/* _glClearColor_Comp @ 0x59ca0 (92 bytes) */
void _glClearColor_Comp(undefined4 param_1,float fparam_1,float fparam_2,float fparam_3,float fparam_4)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glClearColor_ListExec_00110048,0x10);
  if (pfVar1 != (float *)0x0) {
    pfVar1[3] = (float)fparam_4;
    *pfVar1 = (float)fparam_1;
    pfVar1[1] = (float)fparam_2;
    pfVar1[2] = (float)fparam_3;
  }
  return;
}

/* _glClearColor_CompExec @ 0x59cfc (96 bytes) */
void _glClearColor_CompExec(undefined4 param_1,float fparam_1,float fparam_2,float fparam_3,float fparam_4)
{
  ((void (*)())_glClearColor_Exec)(param_1,fparam_1,fparam_2,fparam_3,fparam_4);
  ((void (*)())_glClearColor_Comp)(param_1,fparam_1,fparam_2,fparam_3,fparam_4);
  return;
}

/* _glClearDepth_ListExec @ 0x59d5c (40 bytes) */
int _glClearDepth_ListExec(param_1, param_2)
  undefined4 param_1;
  double *param_2;
{
  ((void (*)())_glClearDepth_Exec)(param_1,*param_2);
  return 8;
}

/* _glClearDepth_Comp @ 0x59d84 (84 bytes) */
double * _glClearDepth_Comp(undefined4 param_1,double fparam_1)
{
  double *pdVar1;
  
  pdVar1 = (double *)_gleAddListItem(param_1,PTR__glClearDepth_ListExec_00110044,8);
  if (pdVar1 != (double *)0x0) {
    *pdVar1 = fparam_1;
  }
  return pdVar1;
}

/* _glClearDepth_CompExec @ 0x59dd8 (64 bytes) */
void _glClearDepth_CompExec(undefined4 param_1,double fparam_1)
{
  ((double * (*)())_glClearDepth_Comp)(param_1,fparam_1);
  ((void (*)())_glClearDepth_Exec)(param_1,fparam_1);
  return;
}

/* _glClearIndex_ListExec @ 0x59e18 (40 bytes) */
int _glClearIndex_ListExec(param_1, param_2)
  undefined4 param_1;
  float *param_2;
{
  ((void (*)())_glClearIndex_Exec)(param_1,(double)*param_2);
  return 4;
}

/* _glClearIndex_Comp @ 0x59e40 (84 bytes) */
float * _glClearIndex_Comp(undefined4 param_1,float fparam_1)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glClearIndex_ListExec_00110040,4);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)fparam_1;
  }
  return pfVar1;
}

/* _glClearIndex_Exec @ 0x59e94 (84 bytes) */
void _glClearIndex_Exec(int param_1,float fparam_1)
{
  float dVar1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    dVar1 = (double)FLOAT_00108e5c;
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 8;
    *(float *)(param_1 + 0x3110) = (fparam_1 * dVar1);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glClearIndex_CompExec @ 0x59ee8 (64 bytes) */
void _glClearIndex_CompExec(undefined4 param_1,float fparam_1)
{
  ((float * (*)())_glClearIndex_Comp)(param_1,fparam_1);
  ((void (*)())_glClearIndex_Exec)(param_1,fparam_1);
  return;
}

/* _glClearStencil_ListExec @ 0x59f28 (40 bytes) */
int _glClearStencil_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glClearStencil_Exec)(param_1,*param_2);
  return 4;
}

/* _glClearStencil_Comp @ 0x59f50 (76 bytes) */
int _glClearStencil_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glClearStencil_ListExec_0011003c,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glClearStencil_Exec @ 0x59f9c (60 bytes) */
void _glClearStencil_Exec(param_1, param_2)
  int param_1;
  uint param_2;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    *(uint *)(param_1 + 0x3114) = param_2 & 0xff;
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x20;
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glClearStencil_CompExec @ 0x59fd8 (56 bytes) */
void _glClearStencil_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glClearStencil_Comp)(param_1,param_2);
  ((void (*)())_glClearStencil_Exec)(param_1,param_2);
  return;
}

/* _glClipPlane_ListExec @ 0x5a010 (44 bytes) */
int _glClipPlane_ListExec(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  ((void (*)())_glClipPlane_Exec)(param_1,*(undefined4 *)(param_2 + 0x20),param_2);
  return 0x28;
}

/* _glClipPlane_Comp @ 0x5a03c (112 bytes) */
int _glClipPlane_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined8 *param_3;
{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)_gleAddListItem(param_1,PTR__glClipPlane_ListExec_00110050,0x28);
  if (puVar1 != (undefined8 *)0x0) {
    *(undefined4 *)(puVar1 + 4) = param_2;
    *puVar1 = *param_3;
    puVar1[1] = param_3[1];
    puVar1[2] = param_3[2];
    puVar1[3] = param_3[3];
  }
  return puVar1;
}

/* _glClipPlane_Exec @ 0x5a0ac (480 bytes) */
void _glClipPlane_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  double *param_3;
{
  byte bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  
  uVar8 = param_2 - 0x3000;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (uVar8 < 6) {
      iVar9 = param_1 + uVar8 * 0x10;
      *(float *)(iVar9 + 0x418c) = (float)*param_3;
      *(float *)(iVar9 + 0x4190) = (float)param_3[1];
      *(float *)(iVar9 + 0x4194) = (float)param_3[2];
      *(float *)(iVar9 + 0x4198) = (float)param_3[3];
      if ((*(uint *)(param_1 + 0x50b0) & 0x10) != 0) {
        ((double (*)())_gleModelMatInvert)(param_1);
      }
      fVar2 = *(float *)(iVar9 + 0x4190);
      fVar3 = *(float *)(iVar9 + 0x418c);
      fVar4 = *(float *)(iVar9 + 0x4194);
      fVar5 = *(float *)(iVar9 + 0x4198);
      *(float *)(iVar9 + 0x418c) =
           fVar5 * *(float *)(param_1 + 0x22f0) +
           (fVar4 * *(float *)(param_1 + 0x22e0) +
           (fVar3 * *(float *)(param_1 + 0x22c0) + fVar2 * *(float *)(param_1 + 0x22d0)));
      *(float *)(iVar9 + 0x4190) =
           fVar5 * *(float *)(param_1 + 0x22f4) +
           (fVar4 * *(float *)(param_1 + 0x22e4) +
           (fVar3 * *(float *)(param_1 + 0x22c4) + fVar2 * *(float *)(param_1 + 0x22d4)));
      *(float *)(iVar9 + 0x4194) =
           fVar5 * *(float *)(param_1 + 0x22f8) +
           (fVar4 * *(float *)(param_1 + 0x22e8) +
           (fVar3 * *(float *)(param_1 + 0x22c8) + fVar2 * *(float *)(param_1 + 0x22d8)));
      *(float *)(iVar9 + 0x4198) =
           fVar5 * *(float *)(param_1 + 0x22fc) +
           (fVar4 * *(float *)(param_1 + 0x22ec) +
           (fVar3 * *(float *)(param_1 + 0x22cc) + fVar2 * *(float *)(param_1 + 0x22dc)));
      if (*(int *)(param_1 + 0x5434) == 0) {
        bVar1 = *(byte *)(uVar8 + *(int *)(param_1 + 0x5420) + 0x31c);
      }
      else {
        bVar1 = *(byte *)(uVar8 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x350);
      }
      iVar7 = (bVar1 >> 3 & 0x1c) + param_1;
      iVar9 = *(int *)(param_1 + 0x5424);
      *(uint *)(iVar7 + 0x324) = *(uint *)(iVar7 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(uVar8 + iVar9 + 0x31c);
      iVar9 = (bVar1 >> 3 & 0x1c) + param_1;
      *(uint *)(iVar9 + 0x348) = *(uint *)(iVar9 + 0x348) | 1 << (bVar1 & 0x1f);
      *(uint *)(param_1 + 0x318) = *(uint *)(param_1 + 0x318) | 0x1000000 << (uVar8 & 0x3f);
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar6 = 0x500;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar6 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar6;
  return;
}

/* _glClipPlane_CompExec @ 0x5a28c (64 bytes) */
void _glClipPlane_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glClipPlane_Comp)(param_1,param_2,param_3);
  ((void (*)())_glClipPlane_Exec)(param_1,param_2,param_3);
  return;
}

/* _glGetClipPlane_Exec @ 0x5a2cc (116 bytes) */
void _glGetClipPlane_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  double *param_3;
{
  undefined4 uVar1;
  int iVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 - 0x3000U < 6) {
      iVar2 = param_1 + (param_2 - 0x3000U) * 0x10;
      *param_3 = (double)*(float *)(iVar2 + 0x418c);
      param_3[1] = (double)*(float *)(iVar2 + 0x4190);
      param_3[2] = (double)*(float *)(iVar2 + 0x4194);
      param_3[3] = (double)*(float *)(iVar2 + 0x4198);
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glColor3_ListExec @ 0x5a340 (92 bytes) */
int _glColor3_ListExec(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = param_2[2];
  uVar2 = param_2[1];
  *(undefined4 *)(param_1 + 0x2a0) = *param_2;
  *(undefined4 *)(param_1 + 0x2a4) = uVar2;
  *(undefined4 *)(param_1 + 0x2a8) = uVar1;
  *(undefined4 *)(param_1 + 0x2ac) = *(undefined4 *)(param_1 + 0x24);
  if (*(char *)(param_1 + 0x4df8) != '\0') {
    (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  }
  return 0xc;
}

/* _glColor3b_Comp @ 0x5a39c (204 bytes) */
int _glColor3b_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  double dVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  
  pfVar4 = (float *)_gleAddListItem(param_1,PTR__glColor3_ListExec_0011005c,0xc);
  fVar3 = FLOAT_00108e64;
  fVar2 = FLOAT_00108e60;
  dVar1 = DOUBLE_00108d58;
  if (pfVar4 != (float *)0x0) {
    *pfVar4 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e60 + FLOAT_00108e64;
    pfVar4[1] = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - dVar1) * fVar2 + fVar3;
    pfVar4[2] = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar1) * fVar2 + fVar3;
  }
  return pfVar4;
}

/* _glColor3b_Exec @ 0x5a468 (196 bytes) */
void _glColor3b_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  float fVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  double dVar5;
  
  fVar3 = FLOAT_00108e64;
  fVar2 = FLOAT_00108e60;
  dVar5 = (double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58;
  dVar4 = (double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58;
  fVar1 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e60 + FLOAT_00108e64;
  *(undefined4 *)(param_1 + 0x2ac) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(param_1 + 0x2a0) = fVar1;
  *(float *)(param_1 + 0x2a8) = (float)dVar5 * fVar2 + fVar3;
  *(float *)(param_1 + 0x2a4) = (float)dVar4 * fVar2 + fVar3;
  if (*(char *)(param_1 + 0x4df8) != '\0') {
    (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  }
  return;
}

/* _glColor3b_CompExec @ 0x5a52c (72 bytes) */
void _glColor3b_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glColor3b_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glColor3b_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glColor3bv_Comp @ 0x5a574 (220 bytes) */
int _glColor3bv_Comp(param_1, param_2)
  undefined4 param_1;
  char *param_2;
{
  double dVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  
  pfVar4 = (float *)_gleAddListItem(param_1,PTR__glColor3_ListExec_0011005c,0xc);
  fVar3 = FLOAT_00108e64;
  fVar2 = FLOAT_00108e60;
  dVar1 = DOUBLE_00108d58;
  if (pfVar4 != (float *)0x0) {
    *pfVar4 = (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e60 + FLOAT_00108e64;
    pfVar4[1] = (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1) * fVar2 +
                fVar3;
    pfVar4[2] = (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - dVar1) * fVar2 +
                fVar3;
  }
  return pfVar4;
}

/* _glColor3bv_Exec @ 0x5a650 (220 bytes) */
double _glColor3bv_Exec(param_1, param_2)
  int param_1;
  char *param_2;
{
  float fVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  double dVar5;
  
  fVar3 = FLOAT_00108e64;
  fVar2 = FLOAT_00108e60;
  dVar5 = (double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - DOUBLE_00108d58;
  dVar4 = (double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - DOUBLE_00108d58;
  fVar1 = (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e60 + FLOAT_00108e64;
  *(undefined4 *)(param_1 + 0x2ac) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(param_1 + 0x2a0) = fVar1;
  *(float *)(param_1 + 0x2a8) = (float)dVar5 * fVar2 + fVar3;
  *(float *)(param_1 + 0x2a4) = (float)dVar4 * fVar2 + fVar3;
  if (*(char *)(param_1 + 0x4df8) != '\0') {
    (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  }
  return;
}

/* _glColor3bv_CompExec @ 0x5a72c (56 bytes) */
void _glColor3bv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glColor3bv_Comp)(param_1,param_2);
  ((double (*)())_glColor3bv_Exec)(param_1,param_2);
  return;
}

/* _glColor3d_Comp @ 0x5a764 (128 bytes) */
float * _glColor3d_Comp(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glColor3_ListExec_0011005c,0xc);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)fparam_1;
    pfVar1[1] = (float)fparam_2;
    pfVar1[2] = (float)fparam_3;
  }
  return pfVar1;
}

/* _glColor3d_CompExec @ 0x5a820 (156 bytes) */
void _glColor3d_CompExec(int param_1,double fparam_1,double fparam_2,double fparam_3)
{
  ((float * (*)())_glColor3d_Comp)(param_1,fparam_1,fparam_2,fparam_3);
  *(float *)(param_1 + 0x2a0) = (float)fparam_1;
  *(float *)(param_1 + 0x2a4) = (float)fparam_2;
  *(float *)(param_1 + 0x2a8) = (float)fparam_3;
  *(undefined4 *)(param_1 + 0x2ac) = *(undefined4 *)(param_1 + 0x24);
  if (*(char *)(param_1 + 0x4df8) == '\0') {
    return;
  }
                    
                    
  (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  return;
}

/* _glColor3dv_Comp @ 0x5a880 (108 bytes) */
int _glColor3dv_Comp(param_1, param_2)
  undefined4 param_1;
  double *param_2;
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glColor3_ListExec_0011005c,0xc);
  if (pfVar1 != (float *)0x0) {
    *pfVar1 = (float)*param_2;
    pfVar1[1] = (float)param_2[1];
    pfVar1[2] = (float)param_2[2];
  }
  return pfVar1;
}

/* _glColor3dv_Exec @ 0x5a8ec (72 bytes) */
double _glColor3dv_Exec(param_1, param_2)
  int param_1;
  double *param_2;
{
  double dVar1;
  double dVar2;
  
  dVar1 = *param_2;
  dVar2 = param_2[1];
  *(float *)(param_1 + 0x2a8) = (float)param_2[2];
  *(float *)(param_1 + 0x2a0) = (float)dVar1;
  *(float *)(param_1 + 0x2a4) = (float)dVar2;
  *(undefined4 *)(param_1 + 0x2ac) = *(undefined4 *)(param_1 + 0x24);
  if (*(char *)(param_1 + 0x4df8) == '\0') {
    return;
  }
                    
                    
  (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  return;
}

/* _glColor3dv_CompExec @ 0x5a934 (56 bytes) */
void _glColor3dv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glColor3dv_Comp)(param_1,param_2);
  ((double (*)())_glColor3dv_Exec)(param_1,param_2);
  return;
}

/* _glColor3f_Comp @ 0x5a96c (116 bytes) */
float * _glColor3f_Comp(undefined4 param_1,float fparam_1,float fparam_2,float fparam_3)
{
  float *pfVar1;
  
  pfVar1 = (float *)_gleAddListItem(param_1,PTR__glColor3_ListExec_0011005c,0xc);
  if (pfVar1 != (float *)0x0) {
    pfVar1[2] = (float)fparam_3;
    *pfVar1 = (float)fparam_1;
    pfVar1[1] = (float)fparam_2;
  }
  return pfVar1;
}

/* _glColor3f_CompExec @ 0x5aa1c (216 bytes) */
void _glColor3f_CompExec(int param_1,float fparam_1,float fparam_2,float fparam_3)
{
  ((float * (*)())_glColor3f_Comp)(param_1,fparam_1,fparam_2,fparam_3);
  if (*(char *)(param_1 + 0x4df8) != '\0') {
    *(float *)(param_1 + 0x2a0) = (float)fparam_1;
    *(float *)(param_1 + 0x2a4) = (float)fparam_2;
    *(float *)(param_1 + 0x2a8) = (float)fparam_3;
    *(undefined4 *)(param_1 + 0x2ac) = *(undefined4 *)(param_1 + 0x24);
                    
                    
    (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
    return;
  }
  *(float *)(param_1 + 0x2a0) = (float)fparam_1;
  *(undefined4 *)(param_1 + 0x2ac) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(param_1 + 0x2a4) = (float)fparam_2;
  *(float *)(param_1 + 0x2a8) = (float)fparam_3;
  return;
}

/* _glColor3fv_Comp @ 0x5aab8 (96 bytes) */
int _glColor3fv_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glColor3_ListExec_0011005c,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_2;
    puVar1[1] = param_2[1];
    puVar1[2] = param_2[2];
  }
  return puVar1;
}

/* _glColor3fv_NoColorMat_Exec @ 0x5ab18 (36 bytes) */
double _glColor3fv_NoColorMat_Exec(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = param_2[1];
  uVar2 = param_2[2];
  *(undefined4 *)(param_1 + 0x2a0) = *param_2;
  *(undefined4 *)(param_1 + 0x2ac) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(param_1 + 0x2a4) = uVar1;
  *(undefined4 *)(param_1 + 0x2a8) = uVar2;
  return;
}

/* _glColor3fv_ColorMat_Exec @ 0x5ab3c (48 bytes) */
double _glColor3fv_ColorMat_Exec(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = param_2[2];
  uVar2 = param_2[1];
  *(undefined4 *)(param_1 + 0x2a0) = *param_2;
  *(undefined4 *)(param_1 + 0x2a4) = uVar2;
  *(undefined4 *)(param_1 + 0x2a8) = uVar1;
  *(undefined4 *)(param_1 + 0x2ac) = *(undefined4 *)(param_1 + 0x24);
                    
                    
  (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  return;
}

/* _glColor3fv_CompExec @ 0x5ab6c (96 bytes) */
void _glColor3fv_CompExec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  ((int (*)())_glColor3fv_Comp)(param_1,param_2);
  if (*(char *)(param_1 + 0x4df8) != '\0') {
    ((double (*)())_glColor3fv_ColorMat_Exec)(param_1,param_2);
    return;
  }
  ((double (*)())_glColor3fv_NoColorMat_Exec)(param_1,param_2);
  return;
}

/* _glColor3i_Comp @ 0x5abcc (204 bytes) */
int _glColor3i_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  double dVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  
  pfVar4 = (float *)_gleAddListItem(param_1,PTR__glColor3_ListExec_0011005c,0xc);
  fVar3 = FLOAT_00108e6c;
  fVar2 = FLOAT_00108e68;
  dVar1 = DOUBLE_00108d58;
  if (pfVar4 != (float *)0x0) {
    *pfVar4 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e68 + FLOAT_00108e6c;
    pfVar4[1] = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - dVar1) * fVar2 + fVar3;
    pfVar4[2] = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar1) * fVar2 + fVar3;
  }
  return pfVar4;
}

/* _glColor3i_Exec @ 0x5ac98 (196 bytes) */
void _glColor3i_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  
  fVar4 = FLOAT_00108e6c;
  fVar3 = FLOAT_00108e68;
  dVar5 = (double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58;
  fVar1 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  fVar2 = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  *(undefined4 *)(param_1 + 0x2ac) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(param_1 + 0x2a0) = fVar1;
  *(float *)(param_1 + 0x2a8) = fVar2;
  *(float *)(param_1 + 0x2a4) = (float)dVar5 * fVar3 + fVar4;
  if (*(char *)(param_1 + 0x4df8) != '\0') {
    (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  }
  return;
}

/* _glColor3i_CompExec @ 0x5ad5c (72 bytes) */
void _glColor3i_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glColor3i_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glColor3i_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glColor3iv_Comp @ 0x5ada4 (208 bytes) */
int _glColor3iv_Comp(param_1, param_2)
  undefined4 param_1;
  uint *param_2;
{
  double dVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  
  pfVar4 = (float *)_gleAddListItem(param_1,PTR__glColor3_ListExec_0011005c,0xc);
  fVar3 = FLOAT_00108e6c;
  fVar2 = FLOAT_00108e68;
  dVar1 = DOUBLE_00108d58;
  if (pfVar4 != (float *)0x0) {
    *pfVar4 = (float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e68 + FLOAT_00108e6c;
    pfVar4[1] = (float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - dVar1) * fVar2 +
                fVar3;
    pfVar4[2] = (float)((double)CONCAT44(0x43300000,param_2[2] ^ 0x80000000) - dVar1) * fVar2 +
                fVar3;
  }
  return pfVar4;
}

/* _glColor3iv_Exec @ 0x5ae74 (208 bytes) */
double _glColor3iv_Exec(param_1, param_2)
  int param_1;
  uint *param_2;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  
  fVar4 = FLOAT_00108e6c;
  fVar3 = FLOAT_00108e68;
  dVar5 = (double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - DOUBLE_00108d58;
  fVar1 = (float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  fVar2 = (float)((double)CONCAT44(0x43300000,param_2[2] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  *(undefined4 *)(param_1 + 0x2ac) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(param_1 + 0x2a0) = fVar1;
  *(float *)(param_1 + 0x2a8) = fVar2;
  *(float *)(param_1 + 0x2a4) = (float)dVar5 * fVar3 + fVar4;
  if (*(char *)(param_1 + 0x4df8) != '\0') {
    (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  }
  return;
}

/* _glColor3iv_CompExec @ 0x5af44 (56 bytes) */
void _glColor3iv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glColor3iv_Comp)(param_1,param_2);
  ((double (*)())_glColor3iv_Exec)(param_1,param_2);
  return;
}

