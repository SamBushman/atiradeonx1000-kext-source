#include "decls.h"

/* _glBindBuffer_Exec @ 0x58520 (240 bytes) */
void _glBindBuffer_Exec(glContext, target, buffer)
  int glContext;
  uint target;
  undefined4 buffer;
{
  undefined4 glErrorCode;
  int iVar2;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((0x8891 < target) && ((target < 0x8894 || (target - 0x88eb < 2)))) {
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        iVar2 = *(int *)(glContext + 0x5148) + 0x8028;
        _pthread_mutex_lock(iVar2);
        _gleBindBufferObject(glContext,target,buffer);
        _pthread_mutex_unlock(iVar2);
        return;
      }
      _gleBindBufferObject(glContext,target,buffer);
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glDeleteBuffers_Exec @ 0x58610 (696 bytes) */
void _glDeleteBuffers_Exec(glContext, n, buffers)
  int glContext;
  int n;
  int *buffers;
{
  int loopIndex2;
  bool bVar1;
  undefined4 glErrorCode;
  int clientState;
  int iVar4;
  undefined4 *dstCursor;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int loopIndex;
  int iVar14;
  int iVar15;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (-1 < n) {
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      clientState = *(int *)(glContext + 0x4a60);
      iVar9 = 0;
      if (*(int *)(clientState + 0x358) != 0) {
        iVar9 = *(int *)(*(int *)(clientState + 0x358) + 4);
      }
      iVar8 = 0;
      if (*(int *)(clientState + 0x35c) != 0) {
        iVar8 = *(int *)(*(int *)(clientState + 0x35c) + 4);
      }
      iVar11 = 0;
      if (*(int *)(glContext + 0x4a68) != 0) {
        iVar11 = *(int *)(*(int *)(glContext + 0x4a68) + 4);
      }
      iVar10 = 0;
      if (*(int *)(glContext + 0x4a6c) != 0) {
        iVar10 = *(int *)(*(int *)(glContext + 0x4a6c) + 4);
      }
      bVar1 = false;
      if (0 < n) {
        do {
          iVar12 = *buffers;
          buffers = buffers + 1;
          if (iVar12 != 0) {
            loopIndex = 0;
            iVar14 = clientState + 0x10;
            iVar15 = clientState + 0x10;
            do {
              iVar6 = *(int *)(iVar15 + 0x350);
              if ((iVar6 != 0) && (iVar12 == *(int *)(iVar6 + 4))) {
                bVar1 = true;
                iVar4 = *(int *)(iVar6 + 8) + -1;
                *(int *)(iVar6 + 8) = iVar4;
                if (iVar4 == 0) {
                  _gleFreeBufferObject(glContext,iVar6);
                }
                uVar7 = *(uint *)(clientState + 0x33c);
                *(undefined4 *)(iVar15 + 0x350) = 0;
                *(undefined4 *)(clientState + 0x338) = 0;
                *(uint *)(clientState + 0x33c) = uVar7 & ~(1 << (loopIndex + 0x10U & 0x3f));
                loopIndex2 = 0;
                if (*(char *)(glContext + 0x85a4) != '\0') {
                  dstCursor = (undefined4 *)(iVar14 + 0x3d0);
                  do {
                    *dstCursor = 0;
                    loopIndex2 = loopIndex2 + 1;
                    dstCursor = dstCursor + 0x23;
                  } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
                }
              }
              loopIndex = loopIndex + 1;
              iVar14 = iVar14 + 4;
              iVar15 = iVar15 + 4;
            } while (loopIndex < 0x20);
            if (iVar12 == iVar9) {
              _gleBindBufferObject(glContext,0x8892,0);
            }
            if (iVar12 == iVar8) {
              _gleBindBufferObject(glContext,0x8893,0);
            }
            if (iVar12 == iVar11) {
              _gleBindBufferObject(glContext,0x88eb,0);
            }
            if (iVar12 == iVar10) {
              _gleBindBufferObject(glContext,0x88ec,0);
            }
            _gleDeleteHashNameAndObject(glContext,*(int *)(glContext + 0x5148) + 0x701c,iVar12);
          }
          n = n + -1;
        } while (n != 0);
        if (bVar1) {
          _gleResetVACachePointers(glContext);
          *(undefined4 *)(clientState + 0x350) = *(undefined4 *)(clientState + 0x350);
          *(uint *)(clientState + 0x354) = *(uint *)(clientState + 0x354) | 0x10;
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
        }
      }
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
        return;
      }
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGenBuffers_Exec @ 0x588c8 (168 bytes) */
void _glGenBuffers_Exec(glContext, n, buffers)
  int glContext;
  int n;
  int *buffers;
{
  undefined4 glErrorCode;
  int iVar2;
  int loopIndex;
  int iVar4;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (-1 < n) {
      iVar4 = _gleGenHashNames(*(int *)(glContext + 0x5148) + 0x701c,n);
      if (iVar4 == 0) {
        return;
      }
      loopIndex = 0;
      if (n < 1) {
        return;
      }
      do {
        iVar2 = loopIndex + iVar4;
        loopIndex = loopIndex + 1;
        *buffers = iVar2;
        buffers = buffers + 1;
        n = n + -1;
      } while (n != 0);
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glIsBuffer_Exec @ 0x58970 (168 bytes) */
int _glIsBuffer_Exec(glContext, buffer)
  int glContext;
  undefined4 buffer;
{
  int iVar1;
  bool bVar2;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar1 = *(int *)(glContext + 0x5148);
    if (*(char *)(iVar1 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar1 + 0x8028);
      iVar1 = *(int *)(glContext + 0x5148);
    }
    iVar1 = _gleLookupHashObject(iVar1 + 0x701c,buffer);
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
    bVar2 = iVar1 != 0;
  }
  else {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    bVar2 = false;
  }
  return bVar2;
}

/* _glBufferData_Exec_body @ 0x58a1c (304 bytes) */
void _glBufferData_Exec_body(glContext, target, bufferSize, data, usage)
  int glContext;
  uint target;
  int bufferSize;
  int data;
  uint usage;
{
  int loopIndex;
  undefined4 glErrorCode;
  byte glContextByte85a8;
  uint size;
  undefined4 glContextWord4688;
  undefined4 uVar3;
  int clientState;
  uint uVar5;
  int iVar6;
  vm_address_t avStack_40 [7];
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x8893) {
      iVar6 = *(int *)(*(int *)(glContext + 0x4a60) + 0x35c);
LAB_00058acc:
      if (iVar6 == 0) goto LAB_00058ad4;
      switch(usage) {
      case 0x88e0:
      case 0x88e1:
      case 0x88e2:
      case 0x88e4:
      case 0x88e5:
      case 0x88e6:
      case 0x88e8:
      case 0x88e9:
      case 0x88ea:
        _gleOrphanBufferData(glContext,iVar6 + 0x10,bufferSize,usage & 0xffff);
        if (*(int *)(iVar6 + 0x30) != 0) {
          if ((data != 0) && (bufferSize != 0)) {
            _memcpy(*(int *)(iVar6 + 0x30),data,bufferSize);
          }
          if (1 < *(int *)(iVar6 + 8)) {
            if ((data == 0) || (bufferSize == 0)) {
              glContextWord4688 = *(undefined4 *)(glContext + 0x4688);
              glContextByte85a8 = *(byte *)(glContext + 0x85a8);
              uVar3 = 0;
            }
            else {
              glContextWord4688 = *(undefined4 *)(glContext + 0x4688);
              glContextByte85a8 = *(byte *)(glContext + 0x85a8);
              uVar3 = *(undefined4 *)(iVar6 + 0x30);
            }
            (**(code **)(glContext + 0x481c))
                      (glContextWord4688,*(undefined4 *)((uint)glContextByte85a8 * 4 + iVar6 + 0x10),uVar3,bufferSize);
            if (target - 0x8892 < 2) {
              _gleResetVACachePointers(glContext);
              clientState = *(int *)(glContext + 0x4a60);
              *(undefined4 *)(clientState + 0x350) = *(undefined4 *)(clientState + 0x350);
              *(uint *)(clientState + 0x354) = *(uint *)(clientState + 0x354) | 0x10;
              *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
            }
          }
          *(short *)(iVar6 + 0x3c) = (short)usage;
          *(undefined1 *)(iVar6 + 0x44) = 0;
          *(int *)(iVar6 + 0x38) = bufferSize;
          return;
        }
        size = bufferSize + 0xfffU & 0xfffff000;
        if (bufferSize == 0) {
          uVar5 = 0;
          avStack_40[0] = 0;
code_r0x00058cb0:
          *(undefined1 *)(iVar6 + 0x44) = 0;
          *(int *)(iVar6 + 0x38) = bufferSize;
          *(short *)(iVar6 + 0x3c) = (short)usage;
          *(uint *)(iVar6 + 0x34) = size;
          *(vm_address_t *)(iVar6 + 0x30) = avStack_40[0];
          if ((target - 0x8892 < 2) && (1 < *(int *)(iVar6 + 8))) {
            _gleResetVACachePointers(glContext);
            clientState = *(int *)(glContext + 0x4a60);
            *(undefined4 *)(clientState + 0x350) = *(undefined4 *)(clientState + 0x350);
            *(uint *)(clientState + 0x354) = *(uint *)(clientState + 0x354) | 0x10;
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
          }
          if (uVar5 == 0) {
            return;
          }
          loopIndex = 0;
          if (*(char *)(glContext + 0x85a4) == '\0') {
            return;
          }
          do {
            loopIndex = loopIndex + 1;
            *(uint *)(iVar6 + 0x48) = *(uint *)(iVar6 + 0x48) | uVar5;
            iVar6 = iVar6 + 4;
          } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
          return;
        }
        _vm_allocate(*(vm_map_t *)PTR_00112034,avStack_40,size,1);
        if (avStack_40[0] != 0) {
          uVar5 = 3;
          if (data != 0) {
            _memcpy(avStack_40[0],data,bufferSize);
          }
          goto code_r0x00058cb0;
        }
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x505;
        goto LAB_00058c84;
      }
    }
    else {
      if (0x8893 < target) {
        if (target == 0x88eb) {
          iVar6 = *(int *)(glContext + 0x4a68);
        }
        else {
          if (target != 0x88ec) goto LAB_00058b40;
          iVar6 = *(int *)(glContext + 0x4a6c);
        }
        goto LAB_00058acc;
      }
      if (target == 0x8892) {
        iVar6 = *(int *)(*(int *)(glContext + 0x4a60) + 0x358);
        goto LAB_00058acc;
      }
    }
LAB_00058b40:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
  }
  else {
LAB_00058ad4:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
LAB_00058c84:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glBufferSubData_Exec @ 0x58d74 (844 bytes) */
void _glBufferSubData_Exec(glContext, target, offset, bufferSize, data)
  int glContext;
  uint target;
  int offset;
  undefined4 bufferSize;
  undefined4 data;
{
  int loopIndex;
  int *piVar1;
  undefined4 *puVar2;
  undefined4 glErrorCode;
  int iVar4;
  int clientState;
  int iVar5;
  int loopIndex2;
  int iVar7;
  int clientState2;
  vm_size_t size;
  vm_address_t local_40 [5];
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x8893) {
      iVar7 = *(int *)(*(int *)(glContext + 0x4a60) + 0x35c);
    }
    else if (target < 0x8894) {
      if (target != 0x8892) {
LAB_00058e24:
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x500;
        goto LAB_00058eb4;
      }
      iVar7 = *(int *)(*(int *)(glContext + 0x4a60) + 0x358);
    }
    else if (target == 0x88eb) {
      iVar7 = *(int *)(glContext + 0x4a68);
    }
    else {
      if (target != 0x88ec) goto LAB_00058e24;
      iVar7 = *(int *)(glContext + 0x4a6c);
    }
    if ((iVar7 != 0) && (*(char *)(iVar7 + 0x44) == '\0')) {
      size = *(vm_size_t *)(iVar7 + 0x34);
      if (size == 0) {
        return;
      }
      local_40[0] = *(vm_address_t *)(iVar7 + 0x30);
      if (local_40[0] != 0) {
        iVar5 = glContext + 0x10000;
        iVar4 = (**(code **)(glContext + 0x4718))
                          (*(undefined4 *)(glContext + 0x4688),
                           *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + iVar7 + 0x10),
                           offset,bufferSize,data);
        if (iVar4 != 0) {
          *(undefined4 *)(iVar7 + 0x40) =
               *(undefined4 *)
                ((uint)*(byte *)(glContext + 0x85a8) * 4 + *(int *)(glContext + 0x5148) + 0x8054);
          return;
        }
        loopIndex2 = 0;
        iVar4 = iVar7;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          do {
            piVar1 = (int *)(iVar5 + -0x777c);
            puVar2 = (undefined4 *)(iVar5 + -0x7a54);
            loopIndex2 = loopIndex2 + 1;
            iVar5 = iVar5 + 0x2e0;
            (**(code **)(*piVar1 + 0x1c4))(*puVar2,3,*(undefined4 *)(iVar4 + 0x10));
            *(uint *)(iVar4 + 0x48) = *(uint *)(iVar4 + 0x48) | 2;
            iVar4 = iVar4 + 4;
          } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
        _memcpy(local_40[0] + offset,data,bufferSize);
        if (*(int *)(iVar7 + 8) < 2) {
          return;
        }
        (**(code **)(glContext + 0x481c))
                  (*(undefined4 *)(glContext + 0x4688),
                   *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + iVar7 + 0x10),
                   local_40[0] + offset,bufferSize);
        if (*(int *)((uint)*(byte *)(glContext + 0x85a8) * 4 + iVar7 + 0x48) == 0) {
          return;
        }
        if (1 < target - 0x8892) {
          return;
        }
        clientState2 = *(int *)(glContext + 0x4a60);
        *(undefined4 *)(clientState2 + 0x350) = *(undefined4 *)(clientState2 + 0x350);
        *(uint *)(clientState2 + 0x354) = *(uint *)(clientState2 + 0x354) | 0x10;
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
        return;
      }
      _vm_allocate(*(vm_map_t *)PTR_00112034,local_40,size,1);
      if (local_40[0] != 0) {
        *(vm_address_t *)(iVar7 + 0x30) = local_40[0];
        *(vm_size_t *)(iVar7 + 0x34) = size;
        if ((target - 0x8892 < 2) && (1 < *(int *)(iVar7 + 8))) {
          _gleResetVACachePointers(glContext);
          clientState = *(int *)(glContext + 0x4a60);
          *(undefined4 *)(clientState + 0x350) = *(undefined4 *)(clientState + 0x350);
          *(uint *)(clientState + 0x354) = *(uint *)(clientState + 0x354) | 0x10;
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
        }
        loopIndex = 0;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          do {
            loopIndex = loopIndex + 1;
            *(uint *)(iVar7 + 0x48) = *(uint *)(iVar7 + 0x48) | 3;
            iVar7 = iVar7 + 4;
          } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
        _memcpy(local_40[0] + offset,data,bufferSize);
        return;
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x505;
      goto LAB_00058eb4;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_00058eb4:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetBufferSubData_Exec @ 0x590c0 (308 bytes) */
void _glGetBufferSubData_Exec(glContext, target, offset, size, data)
  int glContext;
  uint target;
  int offset;
  undefined4 size;
  undefined4 data;
{
  undefined4 glErrorCode;
  int iVar2;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x8893) {
      iVar2 = *(int *)(*(int *)(glContext + 0x4a60) + 0x35c);
    }
    else if (target < 0x8894) {
      if (target != 0x8892) {
LAB_00059160:
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x500;
        goto LAB_00059198;
      }
      iVar2 = *(int *)(*(int *)(glContext + 0x4a60) + 0x358);
    }
    else if (target == 0x88eb) {
      iVar2 = *(int *)(glContext + 0x4a68);
    }
    else {
      if (target != 0x88ec) goto LAB_00059160;
      iVar2 = *(int *)(glContext + 0x4a6c);
    }
    if ((iVar2 != 0) && (*(char *)(iVar2 + 0x44) == '\0')) {
      if (*(int *)(iVar2 + 0x40) != 0) {
        _gleSynchronizePluginBuffer(glContext,iVar2 + 0x10);
      }
      if (*(int *)(iVar2 + 0x30) == 0) {
        return;
      }
      _memcpy(data,*(int *)(iVar2 + 0x30) + offset,size);
      return;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_00059198:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glMapBuffer_Exec @ 0x591f4 (564 bytes) */
int _glMapBuffer_Exec(glContext, target, access)
  int glContext;
  uint target;
  int access;
{
  int loopIndex;
  int *piVar1;
  undefined4 *puVar2;
  undefined4 glErrorCode;
  vm_size_t size;
  int iVar4;
  int loopIndex2;
  int iVar6;
  vm_address_t local_30 [7];
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target != 0x8893) {
      if (0x8893 < target) {
        if (target == 0x88eb) {
          iVar6 = *(int *)(glContext + 0x4a68);
        }
        else {
          if (target != 0x88ec) goto LAB_000592a8;
          iVar6 = *(int *)(glContext + 0x4a6c);
        }
        goto LAB_00059290;
      }
      if (target == 0x8892) {
        iVar6 = *(int *)(*(int *)(glContext + 0x4a60) + 0x358);
        goto LAB_00059290;
      }
LAB_000592a8:
      if (*(int *)(glContext + 0x7574) != 0) {
        return 0;
      }
      glErrorCode = 0x500;
      goto LAB_0005933c;
    }
    iVar6 = *(int *)(*(int *)(glContext + 0x4a60) + 0x35c);
LAB_00059290:
    if (iVar6 != 0) {
      if (2 < access - 35000U) goto LAB_000592a8;
      if (*(char *)(iVar6 + 0x44) == '\0') {
        local_30[0] = *(vm_address_t *)(iVar6 + 0x30);
        *(undefined1 *)(iVar6 + 0x44) = 1;
        *(short *)(iVar6 + 0x3e) = (short)access;
        size = *(vm_size_t *)(iVar6 + 0x34);
        if ((local_30[0] != 0) || (size == 0)) {
          if (*(int *)(iVar6 + 0x40) != 0) {
            _gleSynchronizePluginBuffer(glContext,iVar6 + 0x10);
          }
          iVar4 = glContext + 0x10000;
          loopIndex2 = 0;
          if (*(char *)(glContext + 0x85a4) != '\0') {
            do {
              piVar1 = (int *)(iVar4 + -0x777c);
              puVar2 = (undefined4 *)(iVar4 + -0x7a54);
              loopIndex2 = loopIndex2 + 1;
              iVar4 = iVar4 + 0x2e0;
              (**(code **)(*piVar1 + 0x1c4))(*puVar2,3,*(undefined4 *)(iVar6 + 0x10));
              *(uint *)(iVar6 + 0x48) = *(uint *)(iVar6 + 0x48) | 2;
              iVar6 = iVar6 + 4;
            } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
            return local_30[0];
          }
          return local_30[0];
        }
        _vm_allocate(*(vm_map_t *)PTR_00112034,local_30,size,1);
        if (local_30[0] != 0) {
          *(vm_address_t *)(iVar6 + 0x30) = local_30[0];
          *(vm_size_t *)(iVar6 + 0x34) = size;
          if (1 < *(int *)(iVar6 + 8)) {
            _gleResetVACachePointers(glContext);
          }
          loopIndex = 0;
          if (*(char *)(glContext + 0x85a4) != '\0') {
            do {
              loopIndex = loopIndex + 1;
              *(uint *)(iVar6 + 0x48) = *(uint *)(iVar6 + 0x48) | 3;
              iVar6 = iVar6 + 4;
            } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
            return local_30[0];
          }
          return local_30[0];
        }
        if (*(int *)(glContext + 0x7574) != 0) {
          return 0;
        }
        glErrorCode = 0x505;
        goto LAB_0005933c;
      }
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return 0;
  }
  glErrorCode = 0x502;
LAB_0005933c:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return 0;
}

/* _glUnmapBuffer_Exec @ 0x59428 (392 bytes) */
int _glUnmapBuffer_Exec(glContext, target)
  int glContext;
  uint target;
{
  undefined4 glErrorCode;
  int iVar2;
  int clientState;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x8893) {
      iVar2 = *(int *)(*(int *)(glContext + 0x4a60) + 0x35c);
    }
    else if (target < 0x8894) {
      if (target != 0x8892) {
LAB_000594c4:
        if (*(int *)(glContext + 0x7574) != 0) {
          return 0;
        }
        glErrorCode = 0x500;
        goto LAB_000594fc;
      }
      iVar2 = *(int *)(*(int *)(glContext + 0x4a60) + 0x358);
    }
    else if (target == 0x88eb) {
      iVar2 = *(int *)(glContext + 0x4a68);
    }
    else {
      if (target != 0x88ec) goto LAB_000594c4;
      iVar2 = *(int *)(glContext + 0x4a6c);
    }
    if ((iVar2 != 0) && (*(char *)(iVar2 + 0x44) != '\0')) {
      *(undefined1 *)(iVar2 + 0x44) = 0;
      if ((1 < *(int *)(iVar2 + 8)) &&
         (((**(code **)(glContext + 0x481c))
                     (*(undefined4 *)(glContext + 0x4688),
                      *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + iVar2 + 0x10),
                      *(undefined4 *)(iVar2 + 0x30),*(undefined4 *)(iVar2 + 0x38)),
          *(int *)((uint)*(byte *)(glContext + 0x85a8) * 4 + iVar2 + 0x48) != 0 &&
          (target - 0x8892 < 2)))) {
        clientState = *(int *)(glContext + 0x4a60);
        *(undefined4 *)(clientState + 0x350) = *(undefined4 *)(clientState + 0x350);
        *(uint *)(clientState + 0x354) = *(uint *)(clientState + 0x354) | 0x10;
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
      }
      return 1;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return 0;
  }
  glErrorCode = 0x502;
LAB_000594fc:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return 0;
}

/* _glGetBufferParameteriv_Exec @ 0x595b0 (300 bytes) */
void _glGetBufferParameteriv_Exec(glContext, target, pname, params)
  int glContext;
  uint target;
  uint pname;
  uint *params;
{
  undefined4 glErrorCode;
  uint uVar2;
  int iVar3;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x8893) {
      iVar3 = *(int *)(*(int *)(glContext + 0x4a60) + 0x35c);
LAB_0005964c:
      if (iVar3 == 0) goto LAB_00059654;
      if (pname == 0x8765) {
        uVar2 = (uint)*(ushort *)(iVar3 + 0x3c);
        goto LAB_000596c4;
      }
      if (pname < 0x8766) {
        if (pname == 0x8764) {
          uVar2 = *(uint *)(iVar3 + 0x38);
          goto LAB_000596c4;
        }
      }
      else {
        if (pname == 0x88bb) {
          uVar2 = (uint)*(ushort *)(iVar3 + 0x3e);
LAB_000596c4:
          *params = uVar2;
          return;
        }
        if (pname == 0x88bc) {
          uVar2 = (uint)*(byte *)(iVar3 + 0x44);
          goto LAB_000596c4;
        }
      }
    }
    else {
      if (0x8893 < target) {
        if (target == 0x88eb) {
          iVar3 = *(int *)(glContext + 0x4a68);
        }
        else {
          if (target != 0x88ec) goto LAB_00059634;
          iVar3 = *(int *)(glContext + 0x4a6c);
        }
        goto LAB_0005964c;
      }
      if (target == 0x8892) {
        iVar3 = *(int *)(*(int *)(glContext + 0x4a60) + 0x358);
        goto LAB_0005964c;
      }
    }
LAB_00059634:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
  }
  else {
LAB_00059654:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetBufferPointerv_Exec @ 0x596dc (224 bytes) */
void _glGetBufferPointerv_Exec(glContext, target, pname, params)
  int glContext;
  uint target;
  int pname;
  undefined4 *params;
{
  undefined4 glErrorCode;
  undefined4 uVar1;
  int iVar2;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x8893) {
      iVar2 = *(int *)(*(int *)(glContext + 0x4a60) + 0x35c);
LAB_00059778:
      if (iVar2 == 0) goto LAB_00059780;
      if (pname == 0x88bd) {
        uVar1 = 0;
        if (*(char *)(iVar2 + 0x44) != '\0') {
          uVar1 = *(undefined4 *)(iVar2 + 0x30);
        }
        *params = uVar1;
        return;
      }
    }
    else {
      if (0x8893 < target) {
        if (target == 0x88eb) {
          iVar2 = *(int *)(glContext + 0x4a68);
        }
        else {
          if (target != 0x88ec) goto LAB_00059760;
          iVar2 = *(int *)(glContext + 0x4a6c);
        }
        goto LAB_00059778;
      }
      if (target == 0x8892) {
        iVar2 = *(int *)(*(int *)(glContext + 0x4a60) + 0x358);
        goto LAB_00059778;
      }
    }
LAB_00059760:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
  }
  else {
LAB_00059780:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glClear_ListExec @ 0x597bc (40 bytes) */
undefined4 _glClear_ListExec(undefined4 glContext,undefined4 *recordedArgs,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  ((void (*)())_glClear_Exec)(glContext,*recordedArgs,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,
                forwardedFloatArg8);
  return 4;
}

/* _glClear_NoopExec @ 0x597e4 (640 bytes) */
void _glClear_NoopExec(int glContext,undefined4 mask,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int loopIndex;
  bool bVar1;
  char cVar2;
  int *srcCursor;
  int iVar4;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int glContextWord50ac;
  uint uVar6;
  int *piVar7;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  glContextWord50ac = *(int *)(glContext + 0x50ac);
  if (glContextWord50ac != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) != '\0') {
    framebufferObject = *(int *)(glContext + 0x744c);
    piVar7 = (int *)(glContext + 0x310);
    cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,glContextWord50ac,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000598fc:
      uVar6 = *(uint *)(glContext + 0x31c);
    }
    else {
      loopIndex = 0;
      srcCursor = (int *)(glContext + 0x324);
      do {
        iVar4 = *srcCursor;
        srcCursor = srcCursor + 1;
        if (iVar4 != 0) {
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
          break;
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < 9);
      uVar6 = *(uint *)(glContext + 0x31c);
      if ((uVar6 & 0x15555) != 0) {
        if (*(char *)(glContext + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
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
      bVar1 = ((*piVar7 == 0 && *(int *)(glContext + 0x314) == 0) && uVar6 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    else {
      bVar1 = (((*piVar7 == 0 && *(int *)(glContext + 0x314) == 0) &&
               (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && uVar6 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    if (!bVar1) {
      if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
        uVar6 = (**(code **)(glContext + 0x4788))
                          (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,piVar7);
        if ((((uVar6 & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
            ((uVar6 & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
           (fparam_1 = extraout_f1_01, (uVar6 & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0')))
        {
          if ((uVar6 & 4) == 0) {
            uVar6 = uVar6 & 0xfffffffe;
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
          }
          fparam_1 = (double)_gleUpdateDispatchCodeChange(glContext,uVar6);
          if (*(char *)(glContext + 0x759d) == '\0') goto LAB_00059a1c;
        }
      }
      else {
        fparam_1 = (double)_gleSwitchToNonRevertRenderer(glContext);
      }
      remaining = 0x13;
      do {
        *piVar7 = 0;
        piVar7 = piVar7 + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
    }
  }
  if (*(char *)(glContext + 0x759d) != '\0') {
    ((void (*)())_glClear_Exec)(glContext,mask,fparam_1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,
                  forwardedFloatArg8);
    return;
  }
LAB_00059a1c:
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x506;
  }
  return;
}

/* _glClearAccum_ListExec @ 0x59a64 (52 bytes) */
int _glClearAccum_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  float *recordedArgs;
{
  ((void (*)())_glClearAccum_Exec)(glContext,(double)*recordedArgs,(double)recordedArgs[1],(double)recordedArgs[2],
                     (double)recordedArgs[3]);
  return 0x10;
}

/* _glClearAccum_Comp @ 0x59a98 (92 bytes) */
void _glClearAccum_Comp(undefined4 glContext,float red,float green,float blue,float alpha)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glClearAccum_ListExec_0011004c,0x10);
  if (listRecord != (float *)0x0) {
    listRecord[3] = (float)alpha;
    *listRecord = (float)red;
    listRecord[1] = (float)green;
    listRecord[2] = (float)blue;
  }
  return;
}

/* _glClearAccum_Exec @ 0x59af4 (280 bytes) */
void _glClearAccum_Exec(int glContext,float red,float green,float blue,float alpha)
{
  float floatMinusOne;
  float dVar2;
  
  floatMinusOne = FLOAT_00108e58;
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    *(undefined4 *)(glContext + 0x7574) = 0x502;
    return;
  }
  dVar2 = (double)FLOAT_00108e58;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x40;
  if (red < (double)dVar2) {
    *(float *)(glContext + 0x30f0) = floatMinusOne;
  }
  else if (1.0 < red) {
    *(undefined4 *)(glContext + 0x30f0) = 0x3f800000;
  }
  else {
    *(float *)(glContext + 0x30f0) = (float)red;
  }
  if (green < (double)FLOAT_00108e58) {
    *(float *)(glContext + 0x30f4) = FLOAT_00108e58;
  }
  else if (1.0 < green) {
    *(undefined4 *)(glContext + 0x30f4) = 0x3f800000;
  }
  else {
    *(float *)(glContext + 0x30f4) = (float)green;
  }
  if (blue < (double)FLOAT_00108e58) {
    *(float *)(glContext + 0x30f8) = FLOAT_00108e58;
  }
  else if (1.0 < blue) {
    *(undefined4 *)(glContext + 0x30f8) = 0x3f800000;
  }
  else {
    *(float *)(glContext + 0x30f8) = (float)blue;
  }
  if (alpha < (double)FLOAT_00108e58) {
    *(float *)(glContext + 0x30fc) = FLOAT_00108e58;
    return;
  }
  if (1.0 < alpha) {
    *(undefined4 *)(glContext + 0x30fc) = 0x3f800000;
    return;
  }
  *(float *)(glContext + 0x30fc) = (float)alpha;
  return;
}

/* _glClearAccum_CompExec @ 0x59c0c (96 bytes) */
void _glClearAccum_CompExec(undefined4 glContext,float red,float green,float blue,float alpha)
{
  ((void (*)())_glClearAccum_Comp)(glContext,red,green,blue,alpha);
  ((void (*)())_glClearAccum_Exec)(glContext,red,green,blue,alpha);
  return;
}

/* _glClearColor_ListExec @ 0x59c6c (52 bytes) */
int _glClearColor_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  float *recordedArgs;
{
  ((void (*)())_glClearColor_Exec)(glContext,(double)*recordedArgs,(double)recordedArgs[1],(double)recordedArgs[2],
                     (double)recordedArgs[3]);
  return 0x10;
}

/* _glClearColor_Comp @ 0x59ca0 (92 bytes) */
void _glClearColor_Comp(undefined4 glContext,float red,float green,float blue,float alpha)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glClearColor_ListExec_00110048,0x10);
  if (listRecord != (float *)0x0) {
    listRecord[3] = (float)alpha;
    *listRecord = (float)red;
    listRecord[1] = (float)green;
    listRecord[2] = (float)blue;
  }
  return;
}

/* _glClearColor_CompExec @ 0x59cfc (96 bytes) */
void _glClearColor_CompExec(undefined4 glContext,float red,float green,float blue,float alpha)
{
  ((void (*)())_glClearColor_Exec)(glContext,red,green,blue,alpha);
  ((void (*)())_glClearColor_Comp)(glContext,red,green,blue,alpha);
  return;
}

/* _glClearDepth_ListExec @ 0x59d5c (40 bytes) */
int _glClearDepth_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  double *recordedArgs;
{
  ((void (*)())_glClearDepth_Exec)(glContext,*recordedArgs);
  return 8;
}

/* _glClearDepth_Comp @ 0x59d84 (84 bytes) */
double * _glClearDepth_Comp(undefined4 glContext,double depth)
{
  double *listRecord;
  
  listRecord = (double *)_gleAddListItem(glContext,PTR__glClearDepth_ListExec_00110044,8);
  if (listRecord != (double *)0x0) {
    *listRecord = depth;
  }
  return listRecord;
}

/* _glClearDepth_CompExec @ 0x59dd8 (64 bytes) */
void _glClearDepth_CompExec(undefined4 glContext,double depth)
{
  ((double * (*)())_glClearDepth_Comp)(glContext,depth);
  ((void (*)())_glClearDepth_Exec)(glContext,depth);
  return;
}

/* _glClearIndex_ListExec @ 0x59e18 (40 bytes) */
int _glClearIndex_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  float *recordedArgs;
{
  ((void (*)())_glClearIndex_Exec)(glContext,(double)*recordedArgs);
  return 4;
}

/* _glClearIndex_Comp @ 0x59e40 (84 bytes) */
float * _glClearIndex_Comp(undefined4 glContext,float c)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glClearIndex_ListExec_00110040,4);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)c;
  }
  return listRecord;
}

/* _glClearIndex_Exec @ 0x59e94 (84 bytes) */
void _glClearIndex_Exec(int glContext,float c)
{
  float dVar1;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    dVar1 = (double)FLOAT_00108e5c;
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 8;
    *(float *)(glContext + 0x3110) = (c * dVar1);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glClearIndex_CompExec @ 0x59ee8 (64 bytes) */
void _glClearIndex_CompExec(undefined4 glContext,float c)
{
  ((float * (*)())_glClearIndex_Comp)(glContext,c);
  ((void (*)())_glClearIndex_Exec)(glContext,c);
  return;
}

/* _glClearStencil_ListExec @ 0x59f28 (40 bytes) */
int _glClearStencil_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  ((void (*)())_glClearStencil_Exec)(glContext,*recordedArgs);
  return 4;
}

/* _glClearStencil_Comp @ 0x59f50 (76 bytes) */
int _glClearStencil_Comp(glContext, stencilValue)
  undefined4 glContext;
  undefined4 stencilValue;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glClearStencil_ListExec_0011003c,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = stencilValue;
  }
  return listRecord;
}

/* _glClearStencil_Exec @ 0x59f9c (60 bytes) */
void _glClearStencil_Exec(glContext, stencilValue)
  int glContext;
  uint stencilValue;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    *(uint *)(glContext + 0x3114) = stencilValue & 0xff;
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x20;
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glClearStencil_CompExec @ 0x59fd8 (56 bytes) */
void _glClearStencil_CompExec(glContext, stencilValue)
  undefined4 glContext;
  undefined4 stencilValue;
{
  ((int (*)())_glClearStencil_Comp)(glContext,stencilValue);
  ((void (*)())_glClearStencil_Exec)(glContext,stencilValue);
  return;
}

/* _glClipPlane_ListExec @ 0x5a010 (44 bytes) */
int _glClipPlane_ListExec(glContext, equation)
  undefined4 glContext;
  int equation;
{
  ((void (*)())_glClipPlane_Exec)(glContext,*(undefined4 *)(equation + 0x20),equation);
  return 0x28;
}

/* _glClipPlane_Comp @ 0x5a03c (112 bytes) */
int _glClipPlane_Comp(glContext, plane, equation)
  undefined4 glContext;
  undefined4 plane;
  undefined8 *equation;
{
  undefined8 *listRecord;
  
  listRecord = (undefined8 *)_gleAddListItem(glContext,PTR__glClipPlane_ListExec_00110050,0x28);
  if (listRecord != (undefined8 *)0x0) {
    *(undefined4 *)(listRecord + 4) = plane;
    *listRecord = *equation;
    listRecord[1] = equation[1];
    listRecord[2] = equation[2];
    listRecord[3] = equation[3];
  }
  return listRecord;
}

/* _glClipPlane_Exec @ 0x5a0ac (480 bytes) */
void _glClipPlane_Exec(glContext, plane, equation)
  int glContext;
  int plane;
  double *equation;
{
  byte bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined4 glErrorCode;
  int iVar7;
  uint uVar8;
  int iVar9;
  int glContextWord5424;
  
  uVar8 = plane - 0x3000;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (uVar8 < 6) {
      iVar9 = glContext + uVar8 * 0x10;
      *(float *)(iVar9 + 0x418c) = (float)*equation;
      *(float *)(iVar9 + 0x4190) = (float)equation[1];
      *(float *)(iVar9 + 0x4194) = (float)equation[2];
      *(float *)(iVar9 + 0x4198) = (float)equation[3];
      if ((*(uint *)(glContext + 0x50b0) & 0x10) != 0) {
        ((double (*)())_gleModelMatInvert)(glContext);
      }
      fVar2 = *(float *)(iVar9 + 0x4190);
      fVar3 = *(float *)(iVar9 + 0x418c);
      fVar4 = *(float *)(iVar9 + 0x4194);
      fVar5 = *(float *)(iVar9 + 0x4198);
      *(float *)(iVar9 + 0x418c) =
           fVar5 * *(float *)(glContext + 0x22f0) +
           (fVar4 * *(float *)(glContext + 0x22e0) +
           (fVar3 * *(float *)(glContext + 0x22c0) + fVar2 * *(float *)(glContext + 0x22d0)));
      *(float *)(iVar9 + 0x4190) =
           fVar5 * *(float *)(glContext + 0x22f4) +
           (fVar4 * *(float *)(glContext + 0x22e4) +
           (fVar3 * *(float *)(glContext + 0x22c4) + fVar2 * *(float *)(glContext + 0x22d4)));
      *(float *)(iVar9 + 0x4194) =
           fVar5 * *(float *)(glContext + 0x22f8) +
           (fVar4 * *(float *)(glContext + 0x22e8) +
           (fVar3 * *(float *)(glContext + 0x22c8) + fVar2 * *(float *)(glContext + 0x22d8)));
      *(float *)(iVar9 + 0x4198) =
           fVar5 * *(float *)(glContext + 0x22fc) +
           (fVar4 * *(float *)(glContext + 0x22ec) +
           (fVar3 * *(float *)(glContext + 0x22cc) + fVar2 * *(float *)(glContext + 0x22dc)));
      if (*(int *)(glContext + 0x5434) == 0) {
        bVar1 = *(byte *)(uVar8 + *(int *)(glContext + 0x5420) + 0x31c);
      }
      else {
        bVar1 = *(byte *)(uVar8 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x350);
      }
      iVar7 = (bVar1 >> 3 & 0x1c) + glContext;
      glContextWord5424 = *(int *)(glContext + 0x5424);
      *(uint *)(iVar7 + 0x324) = *(uint *)(iVar7 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(uVar8 + glContextWord5424 + 0x31c);
      iVar9 = (bVar1 >> 3 & 0x1c) + glContext;
      *(uint *)(iVar9 + 0x348) = *(uint *)(iVar9 + 0x348) | 1 << (bVar1 & 0x1f);
      *(uint *)(glContext + 0x318) = *(uint *)(glContext + 0x318) | 0x1000000 << (uVar8 & 0x3f);
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glClipPlane_CompExec @ 0x5a28c (64 bytes) */
void _glClipPlane_CompExec(glContext, plane, equation)
  undefined4 glContext;
  undefined4 plane;
  undefined4 equation;
{
  ((int (*)())_glClipPlane_Comp)(glContext,plane,equation);
  ((void (*)())_glClipPlane_Exec)(glContext,plane,equation);
  return;
}

/* _glGetClipPlane_Exec @ 0x5a2cc (116 bytes) */
void _glGetClipPlane_Exec(glContext, plane, equation)
  int glContext;
  int plane;
  double *equation;
{
  undefined4 glErrorCode;
  int iVar2;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (plane - 0x3000U < 6) {
      iVar2 = glContext + (plane - 0x3000U) * 0x10;
      *equation = (double)*(float *)(iVar2 + 0x418c);
      equation[1] = (double)*(float *)(iVar2 + 0x4190);
      equation[2] = (double)*(float *)(iVar2 + 0x4194);
      equation[3] = (double)*(float *)(iVar2 + 0x4198);
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glColor3_ListExec @ 0x5a340 (92 bytes) */
int _glColor3_ListExec(glContext, recordedArgs)
  int glContext;
  undefined4 *recordedArgs;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = recordedArgs[2];
  uVar2 = recordedArgs[1];
  *(undefined4 *)(glContext + 0x2a0) = *recordedArgs;
  *(undefined4 *)(glContext + 0x2a4) = uVar2;
  *(undefined4 *)(glContext + 0x2a8) = uVar1;
  *(undefined4 *)(glContext + 0x2ac) = *(undefined4 *)(glContext + 0x24);
  if (*(char *)(glContext + 0x4df8) != '\0') {
    (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  }
  return 0xc;
}

/* _glColor3b_Comp @ 0x5a39c (204 bytes) */
int _glColor3b_Comp(glContext, red, green, blue)
  undefined4 glContext;
  uint red;
  uint green;
  uint blue;
{
  double intToDoubleMagic;
  float fVar2;
  float fVar3;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor3_ListExec_0011005c,0xc);
  fVar3 = FLOAT_00108e64;
  fVar2 = FLOAT_00108e60;
  intToDoubleMagic = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,red ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e60 + FLOAT_00108e64;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,green ^ 0x80000000) - intToDoubleMagic) * fVar2 + fVar3;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,blue ^ 0x80000000) - intToDoubleMagic) * fVar2 + fVar3;
  }
  return listRecord;
}

/* _glColor3b_Exec @ 0x5a468 (196 bytes) */
void _glColor3b_Exec(glContext, red, green, blue)
  int glContext;
  uint red;
  uint green;
  uint blue;
{
  float fVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  double dVar5;
  
  fVar3 = FLOAT_00108e64;
  fVar2 = FLOAT_00108e60;
  dVar5 = (double)CONCAT44(0x43300000,blue ^ 0x80000000) - DOUBLE_00108d58;
  dVar4 = (double)CONCAT44(0x43300000,green ^ 0x80000000) - DOUBLE_00108d58;
  fVar1 = (float)((double)CONCAT44(0x43300000,red ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e60 + FLOAT_00108e64;
  *(undefined4 *)(glContext + 0x2ac) = *(undefined4 *)(glContext + 0x24);
  *(float *)(glContext + 0x2a0) = fVar1;
  *(float *)(glContext + 0x2a8) = (float)dVar5 * fVar2 + fVar3;
  *(float *)(glContext + 0x2a4) = (float)dVar4 * fVar2 + fVar3;
  if (*(char *)(glContext + 0x4df8) != '\0') {
    (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  }
  return;
}

/* _glColor3b_CompExec @ 0x5a52c (72 bytes) */
void _glColor3b_CompExec(glContext, red, green, blue)
  undefined4 glContext;
  undefined4 red;
  undefined4 green;
  undefined4 blue;
{
  ((int (*)())_glColor3b_Comp)(glContext,red,green,blue);
  ((void (*)())_glColor3b_Exec)(glContext,red,green,blue);
  return;
}

/* _glColor3bv_Comp @ 0x5a574 (220 bytes) */
int _glColor3bv_Comp(glContext, v)
  undefined4 glContext;
  char *v;
{
  double intToDoubleMagic;
  float fVar2;
  float fVar3;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor3_ListExec_0011005c,0xc);
  fVar3 = FLOAT_00108e64;
  fVar2 = FLOAT_00108e60;
  intToDoubleMagic = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e60 + FLOAT_00108e64;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - intToDoubleMagic) * fVar2 +
                fVar3;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - intToDoubleMagic) * fVar2 +
                fVar3;
  }
  return listRecord;
}

/* _glColor3bv_Exec @ 0x5a650 (220 bytes) */
double _glColor3bv_Exec(glContext, v)
  int glContext;
  char *v;
{
  float fVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  double dVar5;
  
  fVar3 = FLOAT_00108e64;
  fVar2 = FLOAT_00108e60;
  dVar5 = (double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - DOUBLE_00108d58;
  dVar4 = (double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - DOUBLE_00108d58;
  fVar1 = (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e60 + FLOAT_00108e64;
  *(undefined4 *)(glContext + 0x2ac) = *(undefined4 *)(glContext + 0x24);
  *(float *)(glContext + 0x2a0) = fVar1;
  *(float *)(glContext + 0x2a8) = (float)dVar5 * fVar2 + fVar3;
  *(float *)(glContext + 0x2a4) = (float)dVar4 * fVar2 + fVar3;
  if (*(char *)(glContext + 0x4df8) != '\0') {
    (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  }
  return;
}

/* _glColor3bv_CompExec @ 0x5a72c (56 bytes) */
void _glColor3bv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glColor3bv_Comp)(glContext,v);
  ((double (*)())_glColor3bv_Exec)(glContext,v);
  return;
}

/* _glColor3d_Comp @ 0x5a764 (128 bytes) */
float * _glColor3d_Comp(undefined4 glContext,double red,double green,double blue)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor3_ListExec_0011005c,0xc);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)red;
    listRecord[1] = (float)green;
    listRecord[2] = (float)blue;
  }
  return listRecord;
}

/* _glColor3d_CompExec @ 0x5a820 (156 bytes) */
void _glColor3d_CompExec(int glContext,double red,double green,double blue)
{
  ((float * (*)())_glColor3d_Comp)(glContext,red,green,blue);
  *(float *)(glContext + 0x2a0) = (float)red;
  *(float *)(glContext + 0x2a4) = (float)green;
  *(float *)(glContext + 0x2a8) = (float)blue;
  *(undefined4 *)(glContext + 0x2ac) = *(undefined4 *)(glContext + 0x24);
  if (*(char *)(glContext + 0x4df8) == '\0') {
    return;
  }
                    
                    
  (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  return;
}

/* _glColor3dv_Comp @ 0x5a880 (108 bytes) */
int _glColor3dv_Comp(glContext, v)
  undefined4 glContext;
  double *v;
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor3_ListExec_0011005c,0xc);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)*v;
    listRecord[1] = (float)v[1];
    listRecord[2] = (float)v[2];
  }
  return listRecord;
}

/* _glColor3dv_Exec @ 0x5a8ec (72 bytes) */
double _glColor3dv_Exec(glContext, v)
  int glContext;
  double *v;
{
  double dVar1;
  double dVar2;
  
  dVar1 = *v;
  dVar2 = v[1];
  *(float *)(glContext + 0x2a8) = (float)v[2];
  *(float *)(glContext + 0x2a0) = (float)dVar1;
  *(float *)(glContext + 0x2a4) = (float)dVar2;
  *(undefined4 *)(glContext + 0x2ac) = *(undefined4 *)(glContext + 0x24);
  if (*(char *)(glContext + 0x4df8) == '\0') {
    return;
  }
                    
                    
  (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  return;
}

/* _glColor3dv_CompExec @ 0x5a934 (56 bytes) */
void _glColor3dv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glColor3dv_Comp)(glContext,v);
  ((double (*)())_glColor3dv_Exec)(glContext,v);
  return;
}

/* _glColor3f_Comp @ 0x5a96c (116 bytes) */
float * _glColor3f_Comp(undefined4 glContext,float red,float green,float blue)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor3_ListExec_0011005c,0xc);
  if (listRecord != (float *)0x0) {
    listRecord[2] = (float)blue;
    *listRecord = (float)red;
    listRecord[1] = (float)green;
  }
  return listRecord;
}

/* _glColor3f_CompExec @ 0x5aa1c (216 bytes) */
void _glColor3f_CompExec(int glContext,float red,float green,float blue)
{
  ((float * (*)())_glColor3f_Comp)(glContext,red,green,blue);
  if (*(char *)(glContext + 0x4df8) != '\0') {
    *(float *)(glContext + 0x2a0) = (float)red;
    *(float *)(glContext + 0x2a4) = (float)green;
    *(float *)(glContext + 0x2a8) = (float)blue;
    *(undefined4 *)(glContext + 0x2ac) = *(undefined4 *)(glContext + 0x24);
                    
                    
    (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
    return;
  }
  *(float *)(glContext + 0x2a0) = (float)red;
  *(undefined4 *)(glContext + 0x2ac) = *(undefined4 *)(glContext + 0x24);
  *(float *)(glContext + 0x2a4) = (float)green;
  *(float *)(glContext + 0x2a8) = (float)blue;
  return;
}

/* _glColor3fv_Comp @ 0x5aab8 (96 bytes) */
int _glColor3fv_Comp(glContext, v)
  undefined4 glContext;
  undefined4 *v;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glColor3_ListExec_0011005c,0xc);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = *v;
    listRecord[1] = v[1];
    listRecord[2] = v[2];
  }
  return listRecord;
}

/* _glColor3fv_NoColorMat_Exec @ 0x5ab18 (36 bytes) */
double _glColor3fv_NoColorMat_Exec(glContext, v)
  int glContext;
  undefined4 *v;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = v[1];
  uVar2 = v[2];
  *(undefined4 *)(glContext + 0x2a0) = *v;
  *(undefined4 *)(glContext + 0x2ac) = *(undefined4 *)(glContext + 0x24);
  *(undefined4 *)(glContext + 0x2a4) = uVar1;
  *(undefined4 *)(glContext + 0x2a8) = uVar2;
  return;
}

/* _glColor3fv_ColorMat_Exec @ 0x5ab3c (48 bytes) */
double _glColor3fv_ColorMat_Exec(glContext, v)
  int glContext;
  undefined4 *v;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = v[2];
  uVar2 = v[1];
  *(undefined4 *)(glContext + 0x2a0) = *v;
  *(undefined4 *)(glContext + 0x2a4) = uVar2;
  *(undefined4 *)(glContext + 0x2a8) = uVar1;
  *(undefined4 *)(glContext + 0x2ac) = *(undefined4 *)(glContext + 0x24);
                    
                    
  (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  return;
}

/* _glColor3fv_CompExec @ 0x5ab6c (96 bytes) */
void _glColor3fv_CompExec(glContext, v)
  int glContext;
  undefined4 v;
{
  ((int (*)())_glColor3fv_Comp)(glContext,v);
  if (*(char *)(glContext + 0x4df8) != '\0') {
    ((double (*)())_glColor3fv_ColorMat_Exec)(glContext,v);
    return;
  }
  ((double (*)())_glColor3fv_NoColorMat_Exec)(glContext,v);
  return;
}

/* _glColor3i_Comp @ 0x5abcc (204 bytes) */
int _glColor3i_Comp(glContext, red, green, blue)
  undefined4 glContext;
  uint red;
  uint green;
  uint blue;
{
  double intToDoubleMagic;
  float fVar2;
  float fVar3;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor3_ListExec_0011005c,0xc);
  fVar3 = FLOAT_00108e6c;
  fVar2 = FLOAT_00108e68;
  intToDoubleMagic = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,red ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e68 + FLOAT_00108e6c;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,green ^ 0x80000000) - intToDoubleMagic) * fVar2 + fVar3;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,blue ^ 0x80000000) - intToDoubleMagic) * fVar2 + fVar3;
  }
  return listRecord;
}

/* _glColor3i_Exec @ 0x5ac98 (196 bytes) */
void _glColor3i_Exec(glContext, red, green, blue)
  int glContext;
  uint red;
  uint green;
  uint blue;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  
  fVar4 = FLOAT_00108e6c;
  fVar3 = FLOAT_00108e68;
  dVar5 = (double)CONCAT44(0x43300000,green ^ 0x80000000) - DOUBLE_00108d58;
  fVar1 = (float)((double)CONCAT44(0x43300000,red ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  fVar2 = (float)((double)CONCAT44(0x43300000,blue ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  *(undefined4 *)(glContext + 0x2ac) = *(undefined4 *)(glContext + 0x24);
  *(float *)(glContext + 0x2a0) = fVar1;
  *(float *)(glContext + 0x2a8) = fVar2;
  *(float *)(glContext + 0x2a4) = (float)dVar5 * fVar3 + fVar4;
  if (*(char *)(glContext + 0x4df8) != '\0') {
    (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  }
  return;
}

/* _glColor3i_CompExec @ 0x5ad5c (72 bytes) */
void _glColor3i_CompExec(glContext, red, green, blue)
  undefined4 glContext;
  undefined4 red;
  undefined4 green;
  undefined4 blue;
{
  ((int (*)())_glColor3i_Comp)(glContext,red,green,blue);
  ((void (*)())_glColor3i_Exec)(glContext,red,green,blue);
  return;
}

/* _glColor3iv_Comp @ 0x5ada4 (208 bytes) */
int _glColor3iv_Comp(glContext, v)
  undefined4 glContext;
  uint *v;
{
  double intToDoubleMagic;
  float fVar2;
  float fVar3;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor3_ListExec_0011005c,0xc);
  fVar3 = FLOAT_00108e6c;
  fVar2 = FLOAT_00108e68;
  intToDoubleMagic = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e68 + FLOAT_00108e6c;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - intToDoubleMagic) * fVar2 +
                fVar3;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,v[2] ^ 0x80000000) - intToDoubleMagic) * fVar2 +
                fVar3;
  }
  return listRecord;
}

/* _glColor3iv_Exec @ 0x5ae74 (208 bytes) */
double _glColor3iv_Exec(glContext, v)
  int glContext;
  uint *v;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  
  fVar4 = FLOAT_00108e6c;
  fVar3 = FLOAT_00108e68;
  dVar5 = (double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - DOUBLE_00108d58;
  fVar1 = (float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  fVar2 = (float)((double)CONCAT44(0x43300000,v[2] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  *(undefined4 *)(glContext + 0x2ac) = *(undefined4 *)(glContext + 0x24);
  *(float *)(glContext + 0x2a0) = fVar1;
  *(float *)(glContext + 0x2a8) = fVar2;
  *(float *)(glContext + 0x2a4) = (float)dVar5 * fVar3 + fVar4;
  if (*(char *)(glContext + 0x4df8) != '\0') {
    (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  }
  return;
}

/* _glColor3iv_CompExec @ 0x5af44 (56 bytes) */
void _glColor3iv_CompExec(glContext, v)
  undefined4 glContext;
  undefined4 v;
{
  ((int (*)())_glColor3iv_Comp)(glContext,v);
  ((double (*)())_glColor3iv_Exec)(glContext,v);
  return;
}

