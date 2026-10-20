/*
 * IOATIR500Shared_delete_texture_Port.cpp
 *
 * IOATIR500Shared::delete_texture (real addr 0x17950, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
 * Tools/port_fn.py); replaces the earlier hand-written body, which the callee/atomics comparison (Tools/callee_compare.py) showed had
 * dropped or simplified parts of the original.
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/IOATIR5002DContext.h"
#include "../Headers/IOATIR500DVDContext.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/IOATIR500Shared.h"
#include "../Headers/ATIR500Surface.h"
#include "../Headers/ATIR500GLContext.h"
#include "../Headers/ATIR5002DContext.h"
#include "../Headers/ATIR500DVDContext.h"
#include "../Headers/ATIR500Memory.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h"
#include "../Headers/ATIRadeonX1000Registers.h"
#include "../Headers/GhidraExterns.h"
#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"

extern "C" UInt32 GH_OSDecrementAtomic(...) asm("_OSDecrementAtomic");


/* real addr 0x17950 */
IOReturn IOATIR500Shared::delete_texture(VendorTextureBuffer *texture) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *textureBytes = reinterpret_cast<UInt8 *>(texture);

  UInt8 bufferType;
  int *accel;
  UInt32 stamp;
  unsigned int faceIndex;
  UInt8 *surface;
  UInt8 *prevInList;
  UInt8 *listCursor;
  UInt8 *refTexture;
  UInt8 *nextTexture;
  UInt8 *prevTexture;
  int prevVramNode;
  int nextVramNode;
  int faceByteOffset;
  int textureRecord;
  int refCount;
  int accelVtable;
  int stampReached;
  
  prevInList = M<UInt8 *>(self + kIOATIR500Shared_textureListHead);
  if (prevInList == textureBytes) {
    M<UInt32>(self + kIOATIR500Shared_textureListHead) = M<UInt32>(textureBytes + 0x3c);
  }
  else {
    if (prevInList == (UInt8 *)0x0) {
      return 0xe00002bc;
    }
    for (listCursor = M<UInt8 *>(prevInList + 0x3c); textureBytes != listCursor;
        listCursor = M<UInt8 *>(listCursor + 0x3c)) {
      if (listCursor == (UInt8 *)0x0) {
        return 0xe00002bc;
      }
      prevInList = listCursor;
    }
    M<UInt32>(prevInList + 0x3c) = M<UInt32>(textureBytes + 0x3c);
  }
  prevVramNode = M<int>(textureBytes + 0x24);
  bufferType = textureBytes[0x20];
  M<UInt32>(prevVramNode + 0x28) = M<UInt32>(textureBytes + 0x28);
  nextVramNode = M<int>(textureBytes + 0x28);
  M<UInt8 *>(textureBytes + 0x28) = textureBytes;
  M<int>(nextVramNode + 0x24) = prevVramNode;
  M<UInt8 *>(textureBytes + 0x24) = textureBytes;
  if ((((UInt8)((char)bufferType - 2U) < 2) || (bufferType == 0x6)) ||
     (bufferType == 0x7)) {
    if ((bufferType == 0x3) || (bufferType == 0x7)) {
      textureRecord = M<int>(textureBytes + 0x14);
      faceIndex = 0;
      if (M<char>(textureRecord + 0x34) != '\0') {
        do {
          faceByteOffset = faceIndex * 2;
          faceIndex = faceIndex + 1;
          M<UInt16>(faceByteOffset + textureRecord + 0x28) = 0;
          textureRecord = M<int>(textureBytes + 0x14);
        } while (faceIndex < M<UInt8>(textureRecord + 0x34));
      }
      if (M<int>(textureBytes + 0x48) != 0) {
        VCALL(*M<int *>(self + kIOATIR500Shared_accelerator), 0x524)(M<int *>(self + kIOATIR500Shared_accelerator),textureBytes);
      }
    }
    if (M<int *>(textureBytes + 0x10) != (int *)0x0) {
      VCALL(*M<int *>(textureBytes + 0x10), 0x18)(M<int *>(textureBytes + 0x10));
      M<UInt32>(textureBytes + 0x10) = 0;
    }
    if (textureBytes[0x20] == 0x7) {
      refTexture = M<UInt8 *>(textureBytes + 0x58);
      M<UInt32>(textureBytes + 0x58) = 0;
LAB_00017ac4:
      refCount = GH_OSDecrementAtomic(M<int>(refTexture + 0x14) + 0x10);
      if (refCount == 1) {
        this->delete_texture((VendorTextureBuffer *)(refTexture));
      }
    }
    else if (textureBytes[0x20] == 0x6) {
      refTexture = M<UInt8 *>(textureBytes + 0x54);
      M<UInt32>(textureBytes + 0x54) = 0;
      goto LAB_00017ac4;
    }
    if (M<int>(textureBytes + 4) != 0) {
      accel = M<int *>(self + kIOATIR500Shared_accelerator);
      accelVtable = *accel;
      stamp = M<UInt32>(M<int>(textureBytes + 0x14) + 0xc);
LAB_00017b60:
      stampReached = VCALL(accelVtable, 0x554)(accel,stamp);
      if (stampReached == 0) {
        ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500Shared_accelerator)))->addOrphanTexture((IOTextureBuffer *)((UInt8 *)textureBytes));
        goto LAB_00017cf0;
      }
      if (M<int>(textureBytes + 4) != 0) {
        VCALL(*M<int *>(self + kIOATIR500Shared_accelerator), 0x5ac)(M<int *>(self + kIOATIR500Shared_accelerator),textureBytes);
      }
    }
LAB_00017ba0:
    this->free_buf_handle(textureBytes,*M<UInt32 *>(textureBytes + 0x14));
    if (M<int *>(textureBytes + 8) != (int *)0x0) {
      VCALL(*M<int *>(textureBytes + 8), 0x18)(M<int *>(textureBytes + 8));
      M<UInt32>(textureBytes + 8) = 0;
    }
  }
  else {
    if (bufferType == 0x4) {
      if (M<int *>(textureBytes + 0x10) != (int *)0x0) {
        VCALL(*M<int *>(textureBytes + 0x10), 0x18)(M<int *>(textureBytes + 0x10));
        M<UInt32>(textureBytes + 0x10) = 0;
      }
      if (M<int>(textureBytes + 4) != 0) {
        accel = M<int *>(self + kIOATIR500Shared_accelerator);
        accelVtable = *accel;
        stamp = M<UInt32>(M<int>(textureBytes + 0x14) + 8);
        goto LAB_00017b60;
      }
      goto LAB_00017ba0;
    }
    if (bufferType == 0x0) {
      surface = M<UInt8 *>(textureBytes + 0x50);
      if (surface != (UInt8 *)0x0) {
        nextTexture = M<UInt8 *>(surface + 0xbcc);
        if (textureBytes == M<UInt8 *>(surface + 0xbcc)) {
          M<UInt32>(surface + 0xbcc) = M<UInt32>(textureBytes + 0x54);
        }
        else {
          do {
            prevTexture = nextTexture;
            if (prevTexture == (UInt8 *)0x0) break;
            nextTexture = M<UInt8 *>(prevTexture + 0x54);
          } while (textureBytes != M<UInt8 *>(prevTexture + 0x54));
          M<UInt32>(prevTexture + 0x54) = M<UInt32>(textureBytes + 0x54);
        }
        ((IOATIR500Surface *)(surface))->reset_req_bits();
        ((IOATIR500Surface *)(surface))->prune_buffers();
      }
    }
    else {
      if (bufferType != 0x1) goto LAB_00017cf0;
      refTexture = M<UInt8 *>(textureBytes + 0x50);
      if (refTexture != (UInt8 *)0x0) {
        refCount = GH_OSDecrementAtomic(M<int>(refTexture + 0x14) + 0x10);
        if (refCount == 1) {
          ((IOATIR500Shared *)(M<UInt8 *>(M<int>(self + kIOATIR500Shared_accelerator) + 0x6c)))->delete_texture((VendorTextureBuffer *)refTexture);
        }
        VCALL(*M<int *>(M<int>(self + kIOATIR500Shared_accelerator) + 0x6c), 0x18)(M<int *>(M<int>(self + kIOATIR500Shared_accelerator) + 0x6c));
        M<UInt32>(textureBytes + 0x50) = 0;
      }
    }
    this->free_buf_handle(textureBytes,*M<UInt32 *>(textureBytes + 0x14));
  }
  VCALL(*M<int *>(self + kIOATIR500Shared_accelerator), 0x574)(M<int *>(self + kIOATIR500Shared_accelerator),textureBytes,0x80);
LAB_00017cf0:
  M<int>(M<int>(self + kIOATIR500Shared_accelerator) + 0x72c) = M<int>(M<int>(self + kIOATIR500Shared_accelerator) + 0x72c) + -1;
  return 0;
}
