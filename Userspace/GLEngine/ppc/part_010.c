#include "decls.h"

/* _glBindBuffer_Exec @ 0x58520 (240 bytes) */
void _glBindBuffer_Exec(glContext, target, buffer)
  int glContext;
  uint target;
  undefined4 buffer;
{
  undefined4 glErrorCode;
  int sharedStateMutex;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((0x8891 < target) && ((target < 0x8894 || (target - 0x88eb < 2)))) {
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        sharedStateMutex = *(int *)(glContext + 0x5148) + 0x8028;
        _pthread_mutex_lock(sharedStateMutex);
        _gleBindBufferObject(glContext,target,buffer);
        _pthread_mutex_unlock(sharedStateMutex);
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
  bool clientArrayBufferDeleted;
  undefined4 glErrorCode;
  int clientState;
  int newRefCount;
  undefined4 *dstCursor;
  int arrayBufferObject;
  uint bufferBoundBitsWord;
  int boundElementArrayBufferName;
  int boundArrayBufferName;
  int boundPixelUnpackBufferName;
  int boundPixelPackBufferName;
  int bufferName;
  int loopIndex;
  int unitTableCursor;
  int bufferSlotCursor;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (-1 < n) {
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      clientState = *(int *)(glContext + 0x4a60);
      boundArrayBufferName = 0;
      if (*(int *)(clientState + 0x358) != 0) {
        boundArrayBufferName = *(int *)(*(int *)(clientState + 0x358) + 4);
      }
      boundElementArrayBufferName = 0;
      if (*(int *)(clientState + 0x35c) != 0) {
        boundElementArrayBufferName = *(int *)(*(int *)(clientState + 0x35c) + 4);
      }
      boundPixelPackBufferName = 0;
      if (*(int *)(glContext + 0x4a68) != 0) {
        boundPixelPackBufferName = *(int *)(*(int *)(glContext + 0x4a68) + 4);
      }
      boundPixelUnpackBufferName = 0;
      if (*(int *)(glContext + 0x4a6c) != 0) {
        boundPixelUnpackBufferName = *(int *)(*(int *)(glContext + 0x4a6c) + 4);
      }
      clientArrayBufferDeleted = false;
      if (0 < n) {
        do {
          bufferName = *buffers;
          buffers = buffers + 1;
          if (bufferName != 0) {
            loopIndex = 0;
            unitTableCursor = clientState + 0x10;
            bufferSlotCursor = clientState + 0x10;
            do {
              arrayBufferObject = *(int *)(bufferSlotCursor + 0x350);
              if ((arrayBufferObject != 0) && (bufferName == *(int *)(arrayBufferObject + 4))) {
                clientArrayBufferDeleted = true;
                newRefCount = *(int *)(arrayBufferObject + 8) + -1;
                *(int *)(arrayBufferObject + 8) = newRefCount;
                if (newRefCount == 0) {
                  _gleFreeBufferObject(glContext,arrayBufferObject);
                }
                bufferBoundBitsWord = *(uint *)(clientState + 0x33c);
                *(undefined4 *)(bufferSlotCursor + 0x350) = 0;
                *(undefined4 *)(clientState + 0x338) = 0;
                *(uint *)(clientState + 0x33c) = bufferBoundBitsWord & ~(1 << (loopIndex + 0x10U & 0x3f));
                loopIndex2 = 0;
                if (*(char *)(glContext + 0x85a4) != '\0') {
                  dstCursor = (undefined4 *)(unitTableCursor + 0x3d0);
                  do {
                    *dstCursor = 0;
                    loopIndex2 = loopIndex2 + 1;
                    dstCursor = dstCursor + 0x23;
                  } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
                }
              }
              loopIndex = loopIndex + 1;
              unitTableCursor = unitTableCursor + 4;
              bufferSlotCursor = bufferSlotCursor + 4;
            } while (loopIndex < 0x20);
            if (bufferName == boundArrayBufferName) {
              _gleBindBufferObject(glContext,0x8892,0);
            }
            if (bufferName == boundElementArrayBufferName) {
              _gleBindBufferObject(glContext,0x8893,0);
            }
            if (bufferName == boundPixelPackBufferName) {
              _gleBindBufferObject(glContext,0x88eb,0);
            }
            if (bufferName == boundPixelUnpackBufferName) {
              _gleBindBufferObject(glContext,0x88ec,0);
            }
            _gleDeleteHashNameAndObject(glContext,*(int *)(glContext + 0x5148) + 0x701c,bufferName);
          }
          n = n + -1;
        } while (n != 0);
        if (clientArrayBufferDeleted) {
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
  int bufferName;
  int loopIndex;
  int firstBufferName;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (-1 < n) {
      firstBufferName = _gleGenHashNames(*(int *)(glContext + 0x5148) + 0x701c,n);
      if (firstBufferName == 0) {
        return;
      }
      loopIndex = 0;
      if (n < 1) {
        return;
      }
      do {
        bufferName = loopIndex + firstBufferName;
        loopIndex = loopIndex + 1;
        *buffers = bufferName;
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
  int sharedStateThenBufferObject;
  bool isBuffer;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    sharedStateThenBufferObject = *(int *)(glContext + 0x5148);
    if (*(char *)(sharedStateThenBufferObject + 0x8024) != '\0') {
      _pthread_mutex_lock(sharedStateThenBufferObject + 0x8028);
      sharedStateThenBufferObject = *(int *)(glContext + 0x5148);
    }
    sharedStateThenBufferObject = _gleLookupHashObject(sharedStateThenBufferObject + 0x701c,buffer);
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
    isBuffer = sharedStateThenBufferObject != 0;
  }
  else {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    isBuffer = false;
  }
  return isBuffer;
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
  undefined4 uploadSource;
  int clientState;
  uint bufferDirtyBits;
  int bufferObjectThenDirtyWordCursor;
  vm_address_t allocatedAddress [7];
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x8893) {
      bufferObjectThenDirtyWordCursor = *(int *)(*(int *)(glContext + 0x4a60) + 0x35c);
LAB_00058acc:
      if (bufferObjectThenDirtyWordCursor == 0) goto LAB_00058ad4;
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
        _gleOrphanBufferData(glContext,bufferObjectThenDirtyWordCursor + 0x10,bufferSize,usage & 0xffff);
        if (*(int *)(bufferObjectThenDirtyWordCursor + 0x30) != 0) {
          if ((data != 0) && (bufferSize != 0)) {
            _memcpy(*(int *)(bufferObjectThenDirtyWordCursor + 0x30),data,bufferSize);
          }
          if (1 < *(int *)(bufferObjectThenDirtyWordCursor + 8)) {
            if ((data == 0) || (bufferSize == 0)) {
              glContextWord4688 = *(undefined4 *)(glContext + 0x4688);
              glContextByte85a8 = *(byte *)(glContext + 0x85a8);
              uploadSource = 0;
            }
            else {
              glContextWord4688 = *(undefined4 *)(glContext + 0x4688);
              glContextByte85a8 = *(byte *)(glContext + 0x85a8);
              uploadSource = *(undefined4 *)(bufferObjectThenDirtyWordCursor + 0x30);
            }
            (**(code **)(glContext + 0x481c))
                      (glContextWord4688,*(undefined4 *)((uint)glContextByte85a8 * 4 + bufferObjectThenDirtyWordCursor + 0x10),uploadSource,bufferSize);
            if (target - 0x8892 < 2) {
              _gleResetVACachePointers(glContext);
              clientState = *(int *)(glContext + 0x4a60);
              *(undefined4 *)(clientState + 0x350) = *(undefined4 *)(clientState + 0x350);
              *(uint *)(clientState + 0x354) = *(uint *)(clientState + 0x354) | 0x10;
              *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
            }
          }
          *(short *)(bufferObjectThenDirtyWordCursor + 0x3c) = (short)usage;
          *(undefined1 *)(bufferObjectThenDirtyWordCursor + 0x44) = 0;
          *(int *)(bufferObjectThenDirtyWordCursor + 0x38) = bufferSize;
          return;
        }
        size = bufferSize + 0xfffU & 0xfffff000;
        if (bufferSize == 0) {
          bufferDirtyBits = 0;
          allocatedAddress[0] = 0;
code_r0x00058cb0:
          *(undefined1 *)(bufferObjectThenDirtyWordCursor + 0x44) = 0;
          *(int *)(bufferObjectThenDirtyWordCursor + 0x38) = bufferSize;
          *(short *)(bufferObjectThenDirtyWordCursor + 0x3c) = (short)usage;
          *(uint *)(bufferObjectThenDirtyWordCursor + 0x34) = size;
          *(vm_address_t *)(bufferObjectThenDirtyWordCursor + 0x30) = allocatedAddress[0];
          if ((target - 0x8892 < 2) && (1 < *(int *)(bufferObjectThenDirtyWordCursor + 8))) {
            _gleResetVACachePointers(glContext);
            clientState = *(int *)(glContext + 0x4a60);
            *(undefined4 *)(clientState + 0x350) = *(undefined4 *)(clientState + 0x350);
            *(uint *)(clientState + 0x354) = *(uint *)(clientState + 0x354) | 0x10;
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
          }
          if (bufferDirtyBits == 0) {
            return;
          }
          loopIndex = 0;
          if (*(char *)(glContext + 0x85a4) == '\0') {
            return;
          }
          do {
            loopIndex = loopIndex + 1;
            *(uint *)(bufferObjectThenDirtyWordCursor + 0x48) = *(uint *)(bufferObjectThenDirtyWordCursor + 0x48) | bufferDirtyBits;
            bufferObjectThenDirtyWordCursor = bufferObjectThenDirtyWordCursor + 4;
          } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
          return;
        }
        _vm_allocate(*(vm_map_t *)PTR_00112034,allocatedAddress,size,1);
        if (allocatedAddress[0] != 0) {
          bufferDirtyBits = 3;
          if (data != 0) {
            _memcpy(allocatedAddress[0],data,bufferSize);
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
          bufferObjectThenDirtyWordCursor = *(int *)(glContext + 0x4a68);
        }
        else {
          if (target != 0x88ec) goto LAB_00058b40;
          bufferObjectThenDirtyWordCursor = *(int *)(glContext + 0x4a6c);
        }
        goto LAB_00058acc;
      }
      if (target == 0x8892) {
        bufferObjectThenDirtyWordCursor = *(int *)(*(int *)(glContext + 0x4a60) + 0x358);
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
  int *rendererFunctionTablePtr;
  undefined4 *rendererHandlePtr;
  undefined4 glErrorCode;
  int pluginResultThenBufferEntryCursor;
  int clientState;
  int rendererRecordCursor;
  int loopIndex2;
  int bufferObjectThenPluginFlagCursor;
  int clientState2;
  vm_size_t size;
  vm_address_t dataAddress [5];
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x8893) {
      bufferObjectThenPluginFlagCursor = *(int *)(*(int *)(glContext + 0x4a60) + 0x35c);
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
      bufferObjectThenPluginFlagCursor = *(int *)(*(int *)(glContext + 0x4a60) + 0x358);
    }
    else if (target == 0x88eb) {
      bufferObjectThenPluginFlagCursor = *(int *)(glContext + 0x4a68);
    }
    else {
      if (target != 0x88ec) goto LAB_00058e24;
      bufferObjectThenPluginFlagCursor = *(int *)(glContext + 0x4a6c);
    }
    if ((bufferObjectThenPluginFlagCursor != 0) && (*(char *)(bufferObjectThenPluginFlagCursor + 0x44) == '\0')) {
      size = *(vm_size_t *)(bufferObjectThenPluginFlagCursor + 0x34);
      if (size == 0) {
        return;
      }
      dataAddress[0] = *(vm_address_t *)(bufferObjectThenPluginFlagCursor + 0x30);
      if (dataAddress[0] != 0) {
        rendererRecordCursor = glContext + 0x10000;
        pluginResultThenBufferEntryCursor = (**(code **)(glContext + 0x4718))
                          (*(undefined4 *)(glContext + 0x4688),
                           *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + bufferObjectThenPluginFlagCursor + 0x10),
                           offset,bufferSize,data);
        if (pluginResultThenBufferEntryCursor != 0) {
          *(undefined4 *)(bufferObjectThenPluginFlagCursor + 0x40) =
               *(undefined4 *)
                ((uint)*(byte *)(glContext + 0x85a8) * 4 + *(int *)(glContext + 0x5148) + 0x8054);
          return;
        }
        loopIndex2 = 0;
        pluginResultThenBufferEntryCursor = bufferObjectThenPluginFlagCursor;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          do {
            rendererFunctionTablePtr = (int *)(rendererRecordCursor + -0x777c);
            rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
            loopIndex2 = loopIndex2 + 1;
            rendererRecordCursor = rendererRecordCursor + 0x2e0;
            (**(code **)(*rendererFunctionTablePtr + 0x1c4))(*rendererHandlePtr,3,*(undefined4 *)(pluginResultThenBufferEntryCursor + 0x10));
            *(uint *)(pluginResultThenBufferEntryCursor + 0x48) = *(uint *)(pluginResultThenBufferEntryCursor + 0x48) | 2;
            pluginResultThenBufferEntryCursor = pluginResultThenBufferEntryCursor + 4;
          } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
        _memcpy(dataAddress[0] + offset,data,bufferSize);
        if (*(int *)(bufferObjectThenPluginFlagCursor + 8) < 2) {
          return;
        }
        (**(code **)(glContext + 0x481c))
                  (*(undefined4 *)(glContext + 0x4688),
                   *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + bufferObjectThenPluginFlagCursor + 0x10),
                   dataAddress[0] + offset,bufferSize);
        if (*(int *)((uint)*(byte *)(glContext + 0x85a8) * 4 + bufferObjectThenPluginFlagCursor + 0x48) == 0) {
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
      _vm_allocate(*(vm_map_t *)PTR_00112034,dataAddress,size,1);
      if (dataAddress[0] != 0) {
        *(vm_address_t *)(bufferObjectThenPluginFlagCursor + 0x30) = dataAddress[0];
        *(vm_size_t *)(bufferObjectThenPluginFlagCursor + 0x34) = size;
        if ((target - 0x8892 < 2) && (1 < *(int *)(bufferObjectThenPluginFlagCursor + 8))) {
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
            *(uint *)(bufferObjectThenPluginFlagCursor + 0x48) = *(uint *)(bufferObjectThenPluginFlagCursor + 0x48) | 3;
            bufferObjectThenPluginFlagCursor = bufferObjectThenPluginFlagCursor + 4;
          } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
        _memcpy(dataAddress[0] + offset,data,bufferSize);
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
  int boundBufferObject;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x8893) {
      boundBufferObject = *(int *)(*(int *)(glContext + 0x4a60) + 0x35c);
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
      boundBufferObject = *(int *)(*(int *)(glContext + 0x4a60) + 0x358);
    }
    else if (target == 0x88eb) {
      boundBufferObject = *(int *)(glContext + 0x4a68);
    }
    else {
      if (target != 0x88ec) goto LAB_00059160;
      boundBufferObject = *(int *)(glContext + 0x4a6c);
    }
    if ((boundBufferObject != 0) && (*(char *)(boundBufferObject + 0x44) == '\0')) {
      if (*(int *)(boundBufferObject + 0x40) != 0) {
        _gleSynchronizePluginBuffer(glContext,boundBufferObject + 0x10);
      }
      if (*(int *)(boundBufferObject + 0x30) == 0) {
        return;
      }
      _memcpy(data,*(int *)(boundBufferObject + 0x30) + offset,size);
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
  int *rendererFuncTableSlot;
  undefined4 *rendererHandleSlot;
  undefined4 glErrorCode;
  vm_size_t size;
  int rendererSlotCursor;
  int loopIndex2;
  int bufferObjectThenDirtyWordCursor;
  vm_address_t mappedAddress [7];
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target != 0x8893) {
      if (0x8893 < target) {
        if (target == 0x88eb) {
          bufferObjectThenDirtyWordCursor = *(int *)(glContext + 0x4a68);
        }
        else {
          if (target != 0x88ec) goto LAB_000592a8;
          bufferObjectThenDirtyWordCursor = *(int *)(glContext + 0x4a6c);
        }
        goto LAB_00059290;
      }
      if (target == 0x8892) {
        bufferObjectThenDirtyWordCursor = *(int *)(*(int *)(glContext + 0x4a60) + 0x358);
        goto LAB_00059290;
      }
LAB_000592a8:
      if (*(int *)(glContext + 0x7574) != 0) {
        return 0;
      }
      glErrorCode = 0x500;
      goto LAB_0005933c;
    }
    bufferObjectThenDirtyWordCursor = *(int *)(*(int *)(glContext + 0x4a60) + 0x35c);
LAB_00059290:
    if (bufferObjectThenDirtyWordCursor != 0) {
      if (2 < access - 35000U) goto LAB_000592a8;
      if (*(char *)(bufferObjectThenDirtyWordCursor + 0x44) == '\0') {
        mappedAddress[0] = *(vm_address_t *)(bufferObjectThenDirtyWordCursor + 0x30);
        *(undefined1 *)(bufferObjectThenDirtyWordCursor + 0x44) = 1;
        *(short *)(bufferObjectThenDirtyWordCursor + 0x3e) = (short)access;
        size = *(vm_size_t *)(bufferObjectThenDirtyWordCursor + 0x34);
        if ((mappedAddress[0] != 0) || (size == 0)) {
          if (*(int *)(bufferObjectThenDirtyWordCursor + 0x40) != 0) {
            _gleSynchronizePluginBuffer(glContext,bufferObjectThenDirtyWordCursor + 0x10);
          }
          rendererSlotCursor = glContext + 0x10000;
          loopIndex2 = 0;
          if (*(char *)(glContext + 0x85a4) != '\0') {
            do {
              rendererFuncTableSlot = (int *)(rendererSlotCursor + -0x777c);
              rendererHandleSlot = (undefined4 *)(rendererSlotCursor + -0x7a54);
              loopIndex2 = loopIndex2 + 1;
              rendererSlotCursor = rendererSlotCursor + 0x2e0;
              (**(code **)(*rendererFuncTableSlot + 0x1c4))(*rendererHandleSlot,3,*(undefined4 *)(bufferObjectThenDirtyWordCursor + 0x10));
              *(uint *)(bufferObjectThenDirtyWordCursor + 0x48) = *(uint *)(bufferObjectThenDirtyWordCursor + 0x48) | 2;
              bufferObjectThenDirtyWordCursor = bufferObjectThenDirtyWordCursor + 4;
            } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
            return mappedAddress[0];
          }
          return mappedAddress[0];
        }
        _vm_allocate(*(vm_map_t *)PTR_00112034,mappedAddress,size,1);
        if (mappedAddress[0] != 0) {
          *(vm_address_t *)(bufferObjectThenDirtyWordCursor + 0x30) = mappedAddress[0];
          *(vm_size_t *)(bufferObjectThenDirtyWordCursor + 0x34) = size;
          if (1 < *(int *)(bufferObjectThenDirtyWordCursor + 8)) {
            _gleResetVACachePointers(glContext);
          }
          loopIndex = 0;
          if (*(char *)(glContext + 0x85a4) != '\0') {
            do {
              loopIndex = loopIndex + 1;
              *(uint *)(bufferObjectThenDirtyWordCursor + 0x48) = *(uint *)(bufferObjectThenDirtyWordCursor + 0x48) | 3;
              bufferObjectThenDirtyWordCursor = bufferObjectThenDirtyWordCursor + 4;
            } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
            return mappedAddress[0];
          }
          return mappedAddress[0];
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
  int boundBuffer;
  int clientState;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x8893) {
      boundBuffer = *(int *)(*(int *)(glContext + 0x4a60) + 0x35c);
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
      boundBuffer = *(int *)(*(int *)(glContext + 0x4a60) + 0x358);
    }
    else if (target == 0x88eb) {
      boundBuffer = *(int *)(glContext + 0x4a68);
    }
    else {
      if (target != 0x88ec) goto LAB_000594c4;
      boundBuffer = *(int *)(glContext + 0x4a6c);
    }
    if ((boundBuffer != 0) && (*(char *)(boundBuffer + 0x44) != '\0')) {
      *(undefined1 *)(boundBuffer + 0x44) = 0;
      if ((1 < *(int *)(boundBuffer + 8)) &&
         (((**(code **)(glContext + 0x481c))
                     (*(undefined4 *)(glContext + 0x4688),
                      *(undefined4 *)((uint)*(byte *)(glContext + 0x85a8) * 4 + boundBuffer + 0x10),
                      *(undefined4 *)(boundBuffer + 0x30),*(undefined4 *)(boundBuffer + 0x38)),
          *(int *)((uint)*(byte *)(glContext + 0x85a8) * 4 + boundBuffer + 0x48) != 0 &&
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
  uint parameterValue;
  int bufferObject;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x8893) {
      bufferObject = *(int *)(*(int *)(glContext + 0x4a60) + 0x35c);
LAB_0005964c:
      if (bufferObject == 0) goto LAB_00059654;
      if (pname == 0x8765) {
        parameterValue = (uint)*(ushort *)(bufferObject + 0x3c);
        goto LAB_000596c4;
      }
      if (pname < 0x8766) {
        if (pname == 0x8764) {
          parameterValue = *(uint *)(bufferObject + 0x38);
          goto LAB_000596c4;
        }
      }
      else {
        if (pname == 0x88bb) {
          parameterValue = (uint)*(ushort *)(bufferObject + 0x3e);
LAB_000596c4:
          *params = parameterValue;
          return;
        }
        if (pname == 0x88bc) {
          parameterValue = (uint)*(byte *)(bufferObject + 0x44);
          goto LAB_000596c4;
        }
      }
    }
    else {
      if (0x8893 < target) {
        if (target == 0x88eb) {
          bufferObject = *(int *)(glContext + 0x4a68);
        }
        else {
          if (target != 0x88ec) goto LAB_00059634;
          bufferObject = *(int *)(glContext + 0x4a6c);
        }
        goto LAB_0005964c;
      }
      if (target == 0x8892) {
        bufferObject = *(int *)(*(int *)(glContext + 0x4a60) + 0x358);
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
  undefined4 mapPointer;
  int boundBuffer;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x8893) {
      boundBuffer = *(int *)(*(int *)(glContext + 0x4a60) + 0x35c);
LAB_00059778:
      if (boundBuffer == 0) goto LAB_00059780;
      if (pname == 0x88bd) {
        mapPointer = 0;
        if (*(char *)(boundBuffer + 0x44) != '\0') {
          mapPointer = *(undefined4 *)(boundBuffer + 0x30);
        }
        *params = mapPointer;
        return;
      }
    }
    else {
      if (0x8893 < target) {
        if (target == 0x88eb) {
          boundBuffer = *(int *)(glContext + 0x4a68);
        }
        else {
          if (target != 0x88ec) goto LAB_00059760;
          boundBuffer = *(int *)(glContext + 0x4a6c);
        }
        goto LAB_00059778;
      }
      if (target == 0x8892) {
        boundBuffer = *(int *)(*(int *)(glContext + 0x4a60) + 0x358);
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
void _glClear_NoopExec(int glContext,undefined4 mask,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int loopIndex;
  bool rendererInfoByte79Zero;
  bool noStateChangePending;
  char rendererInfoByte79;
  int *srcCursor;
  int dirtyWord;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixChangeBits;
  uint dispatchFlags;
  uint changeWord3;
  int *changeWordCursor;
  double f1AfterCall;
  double f1AfterCall1;
  double f1AfterCall2;
  
  matrixChangeBits = *(int *)(glContext + 0x50ac);
  if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    forwardedFloatArg1 = f1AfterCall;
  }
  if (*(char *)(glContext + 0x4691) != '\0') {
    framebufferObject = *(int *)(glContext + 0x744c);
    changeWordCursor = (int *)(glContext + 0x310);
    rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixChangeBits,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,
                 forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      forwardedFloatArg1 = forwardedFloatArg1;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000598fc:
      changeWord3 = *(uint *)(glContext + 0x31c);
    }
    else {
      loopIndex = 0;
      srcCursor = (int *)(glContext + 0x324);
      do {
        dirtyWord = *srcCursor;
        srcCursor = srcCursor + 1;
        if (dirtyWord != 0) {
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
          break;
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < 9);
      changeWord3 = *(uint *)(glContext + 0x31c);
      if ((changeWord3 & 0x15555) != 0) {
        if (*(char *)(glContext + 0x2e54) != '\0') {
          forwardedFloatArg1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          forwardedFloatArg1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
        }
        goto LAB_000598fc;
      }
    }
    rendererInfoByte79Zero = rendererInfoByte79 == '\0';
    if (rendererInfoByte79Zero) {
      changeWord3 = changeWord3 & 0x17000000;
    }
    else {
      changeWord3 = changeWord3 & 0x17ffffff;
    }
    if (rendererInfoByte79Zero) {
      noStateChangePending = ((*changeWordCursor == 0 && *(int *)(glContext + 0x314) == 0) && changeWord3 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    else {
      noStateChangePending = (((*changeWordCursor == 0 && *(int *)(glContext + 0x314) == 0) &&
               (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && changeWord3 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    if (!noStateChangePending) {
      if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
        dispatchFlags = (**(code **)(glContext + 0x4788))
                          (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,changeWordCursor);
        if ((((dispatchFlags & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
            ((dispatchFlags & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
           (forwardedFloatArg1 = f1AfterCall2, (dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0')))
        {
          if ((dispatchFlags & 4) == 0) {
            dispatchFlags = dispatchFlags & 0xfffffffe;
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
          }
          forwardedFloatArg1 = (double)_gleUpdateDispatchCodeChange(glContext,dispatchFlags);
          if (*(char *)(glContext + 0x759d) == '\0') goto LAB_00059a1c;
        }
      }
      else {
        forwardedFloatArg1 = (double)_gleSwitchToNonRevertRenderer(glContext);
      }
      remaining = 0x13;
      do {
        *changeWordCursor = 0;
        changeWordCursor = changeWordCursor + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
    }
  }
  if (*(char *)(glContext + 0x759d) != '\0') {
    ((void (*)())_glClear_Exec)(glContext,mask,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,
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
  float floatMinusOneAsDouble;
  
  floatMinusOne = FLOAT_00108e58;
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    *(undefined4 *)(glContext + 0x7574) = 0x502;
    return;
  }
  floatMinusOneAsDouble = (double)FLOAT_00108e58;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x40;
  if (red < (double)floatMinusOneAsDouble) {
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
  float indexScale;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    indexScale = (double)FLOAT_00108e5c;
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 8;
    *(float *)(glContext + 0x3110) = (c * indexScale);
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
  byte dirtyBitNumber;
  float planeB;
  float planeA;
  float planeC;
  float planeD;
  undefined4 glErrorCode;
  int dirtyWordAddress324;
  uint clipPlaneIndex;
  int clipPlaneEquation;
  int dirtyWordAddress348;
  int glContextWord5424;
  
  clipPlaneIndex = plane - 0x3000;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (clipPlaneIndex < 6) {
      clipPlaneEquation = glContext + clipPlaneIndex * 0x10;
      *(float *)(clipPlaneEquation + 0x418c) = (float)*equation;
      *(float *)(clipPlaneEquation + 0x4190) = (float)equation[1];
      *(float *)(clipPlaneEquation + 0x4194) = (float)equation[2];
      *(float *)(clipPlaneEquation + 0x4198) = (float)equation[3];
      if ((*(uint *)(glContext + 0x50b0) & 0x10) != 0) {
        ((double (*)())_gleModelMatInvert)(glContext);
      }
      planeB = *(float *)(clipPlaneEquation + 0x4190);
      planeA = *(float *)(clipPlaneEquation + 0x418c);
      planeC = *(float *)(clipPlaneEquation + 0x4194);
      planeD = *(float *)(clipPlaneEquation + 0x4198);
      *(float *)(clipPlaneEquation + 0x418c) =
           planeD * *(float *)(glContext + 0x22f0) +
           (planeC * *(float *)(glContext + 0x22e0) +
           (planeA * *(float *)(glContext + 0x22c0) + planeB * *(float *)(glContext + 0x22d0)));
      *(float *)(clipPlaneEquation + 0x4190) =
           planeD * *(float *)(glContext + 0x22f4) +
           (planeC * *(float *)(glContext + 0x22e4) +
           (planeA * *(float *)(glContext + 0x22c4) + planeB * *(float *)(glContext + 0x22d4)));
      *(float *)(clipPlaneEquation + 0x4194) =
           planeD * *(float *)(glContext + 0x22f8) +
           (planeC * *(float *)(glContext + 0x22e8) +
           (planeA * *(float *)(glContext + 0x22c8) + planeB * *(float *)(glContext + 0x22d8)));
      *(float *)(clipPlaneEquation + 0x4198) =
           planeD * *(float *)(glContext + 0x22fc) +
           (planeC * *(float *)(glContext + 0x22ec) +
           (planeA * *(float *)(glContext + 0x22cc) + planeB * *(float *)(glContext + 0x22dc)));
      if (*(int *)(glContext + 0x5434) == 0) {
        dirtyBitNumber = *(byte *)(clipPlaneIndex + *(int *)(glContext + 0x5420) + 0x31c);
      }
      else {
        dirtyBitNumber = *(byte *)(clipPlaneIndex + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x350);
      }
      dirtyWordAddress324 = (dirtyBitNumber >> 3 & 0x1c) + glContext;
      glContextWord5424 = *(int *)(glContext + 0x5424);
      *(uint *)(dirtyWordAddress324 + 0x324) = *(uint *)(dirtyWordAddress324 + 0x324) | 1 << (dirtyBitNumber & 0x1f);
      dirtyBitNumber = *(byte *)(clipPlaneIndex + glContextWord5424 + 0x31c);
      dirtyWordAddress348 = (dirtyBitNumber >> 3 & 0x1c) + glContext;
      *(uint *)(dirtyWordAddress348 + 0x348) = *(uint *)(dirtyWordAddress348 + 0x348) | 1 << (dirtyBitNumber & 0x1f);
      *(uint *)(glContext + 0x318) = *(uint *)(glContext + 0x318) | 0x1000000 << (clipPlaneIndex & 0x3f);
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
  int clipPlaneRecord;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (plane - 0x3000U < 6) {
      clipPlaneRecord = glContext + (plane - 0x3000U) * 0x10;
      *equation = (double)*(float *)(clipPlaneRecord + 0x418c);
      equation[1] = (double)*(float *)(clipPlaneRecord + 0x4190);
      equation[2] = (double)*(float *)(clipPlaneRecord + 0x4194);
      equation[3] = (double)*(float *)(clipPlaneRecord + 0x4198);
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
  undefined4 blueValue;
  undefined4 greenValue;
  
  blueValue = recordedArgs[2];
  greenValue = recordedArgs[1];
  *(undefined4 *)(glContext + 0x2a0) = *recordedArgs;
  *(undefined4 *)(glContext + 0x2a4) = greenValue;
  *(undefined4 *)(glContext + 0x2a8) = blueValue;
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
  float channelScale;
  float channelBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor3_ListExec_0011005c,0xc);
  channelBias = FLOAT_00108e64;
  channelScale = FLOAT_00108e60;
  intToDoubleMagic = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,red ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e60 + FLOAT_00108e64;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,green ^ 0x80000000) - intToDoubleMagic) * channelScale + channelBias;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,blue ^ 0x80000000) - intToDoubleMagic) * channelScale + channelBias;
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
  float redConverted;
  float channelScale;
  float channelBias;
  double greenAsDouble;
  double blueAsDouble;
  
  channelBias = FLOAT_00108e64;
  channelScale = FLOAT_00108e60;
  blueAsDouble = (double)CONCAT44(0x43300000,blue ^ 0x80000000) - DOUBLE_00108d58;
  greenAsDouble = (double)CONCAT44(0x43300000,green ^ 0x80000000) - DOUBLE_00108d58;
  redConverted = (float)((double)CONCAT44(0x43300000,red ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e60 + FLOAT_00108e64;
  *(undefined4 *)(glContext + 0x2ac) = *(undefined4 *)(glContext + 0x24);
  *(float *)(glContext + 0x2a0) = redConverted;
  *(float *)(glContext + 0x2a8) = (float)blueAsDouble * channelScale + channelBias;
  *(float *)(glContext + 0x2a4) = (float)greenAsDouble * channelScale + channelBias;
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
  float channelScale;
  float channelBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor3_ListExec_0011005c,0xc);
  channelBias = FLOAT_00108e64;
  channelScale = FLOAT_00108e60;
  intToDoubleMagic = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e60 + FLOAT_00108e64;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - intToDoubleMagic) * channelScale +
                channelBias;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - intToDoubleMagic) * channelScale +
                channelBias;
  }
  return listRecord;
}

/* _glColor3bv_Exec @ 0x5a650 (220 bytes) */
double _glColor3bv_Exec(glContext, v)
  int glContext;
  char *v;
{
  float redFloat;
  float channelScale;
  float channelBias;
  double greenDouble;
  double blueDouble;
  
  channelBias = FLOAT_00108e64;
  channelScale = FLOAT_00108e60;
  blueDouble = (double)CONCAT44(0x43300000,(int)v[2] ^ 0x80000000) - DOUBLE_00108d58;
  greenDouble = (double)CONCAT44(0x43300000,(int)v[1] ^ 0x80000000) - DOUBLE_00108d58;
  redFloat = (float)((double)CONCAT44(0x43300000,(int)*v ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e60 + FLOAT_00108e64;
  *(undefined4 *)(glContext + 0x2ac) = *(undefined4 *)(glContext + 0x24);
  *(float *)(glContext + 0x2a0) = redFloat;
  *(float *)(glContext + 0x2a8) = (float)blueDouble * channelScale + channelBias;
  *(float *)(glContext + 0x2a4) = (float)greenDouble * channelScale + channelBias;
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
  double redDouble;
  double greenDouble;
  
  redDouble = *v;
  greenDouble = v[1];
  *(float *)(glContext + 0x2a8) = (float)v[2];
  *(float *)(glContext + 0x2a0) = (float)redDouble;
  *(float *)(glContext + 0x2a4) = (float)greenDouble;
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
  undefined4 greenValue;
  undefined4 blueValue;
  
  greenValue = v[1];
  blueValue = v[2];
  *(undefined4 *)(glContext + 0x2a0) = *v;
  *(undefined4 *)(glContext + 0x2ac) = *(undefined4 *)(glContext + 0x24);
  *(undefined4 *)(glContext + 0x2a4) = greenValue;
  *(undefined4 *)(glContext + 0x2a8) = blueValue;
  return;
}

/* _glColor3fv_ColorMat_Exec @ 0x5ab3c (48 bytes) */
double _glColor3fv_ColorMat_Exec(glContext, v)
  int glContext;
  undefined4 *v;
{
  undefined4 blueBits;
  undefined4 greenBits;
  
  blueBits = v[2];
  greenBits = v[1];
  *(undefined4 *)(glContext + 0x2a0) = *v;
  *(undefined4 *)(glContext + 0x2a4) = greenBits;
  *(undefined4 *)(glContext + 0x2a8) = blueBits;
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
  float channelScale;
  float channelBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor3_ListExec_0011005c,0xc);
  channelBias = FLOAT_00108e6c;
  channelScale = FLOAT_00108e68;
  intToDoubleMagic = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,red ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e68 + FLOAT_00108e6c;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,green ^ 0x80000000) - intToDoubleMagic) * channelScale + channelBias;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,blue ^ 0x80000000) - intToDoubleMagic) * channelScale + channelBias;
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
  float redFloat;
  float blueFloat;
  float channelScale;
  float channelBias;
  double greenDouble;
  
  channelBias = FLOAT_00108e6c;
  channelScale = FLOAT_00108e68;
  greenDouble = (double)CONCAT44(0x43300000,green ^ 0x80000000) - DOUBLE_00108d58;
  redFloat = (float)((double)CONCAT44(0x43300000,red ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  blueFloat = (float)((double)CONCAT44(0x43300000,blue ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  *(undefined4 *)(glContext + 0x2ac) = *(undefined4 *)(glContext + 0x24);
  *(float *)(glContext + 0x2a0) = redFloat;
  *(float *)(glContext + 0x2a8) = blueFloat;
  *(float *)(glContext + 0x2a4) = (float)greenDouble * channelScale + channelBias;
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
  float channelScale;
  float channelBias;
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glColor3_ListExec_0011005c,0xc);
  channelBias = FLOAT_00108e6c;
  channelScale = FLOAT_00108e68;
  intToDoubleMagic = DOUBLE_00108d58;
  if (listRecord != (float *)0x0) {
    *listRecord = (float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58) *
              FLOAT_00108e68 + FLOAT_00108e6c;
    listRecord[1] = (float)((double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - intToDoubleMagic) * channelScale +
                channelBias;
    listRecord[2] = (float)((double)CONCAT44(0x43300000,v[2] ^ 0x80000000) - intToDoubleMagic) * channelScale +
                channelBias;
  }
  return listRecord;
}

/* _glColor3iv_Exec @ 0x5ae74 (208 bytes) */
double _glColor3iv_Exec(glContext, v)
  int glContext;
  uint *v;
{
  float redValue;
  float blueValue;
  float channelScale;
  float channelBias;
  double greenConverted;
  
  channelBias = FLOAT_00108e6c;
  channelScale = FLOAT_00108e68;
  greenConverted = (double)CONCAT44(0x43300000,v[1] ^ 0x80000000) - DOUBLE_00108d58;
  redValue = (float)((double)CONCAT44(0x43300000,*v ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  blueValue = (float)((double)CONCAT44(0x43300000,v[2] ^ 0x80000000) - DOUBLE_00108d58) *
          FLOAT_00108e68 + FLOAT_00108e6c;
  *(undefined4 *)(glContext + 0x2ac) = *(undefined4 *)(glContext + 0x24);
  *(float *)(glContext + 0x2a0) = redValue;
  *(float *)(glContext + 0x2a8) = blueValue;
  *(float *)(glContext + 0x2a4) = (float)greenConverted * channelScale + channelBias;
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

