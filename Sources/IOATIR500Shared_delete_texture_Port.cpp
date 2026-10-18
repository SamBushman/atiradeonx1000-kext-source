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
  UInt8 *pVVar2;
  int iVar3;
  UInt8 *pVVar4;
  int *accel;
  UInt32 stamp;
  int iVar7;
  unsigned int faceIndex;
  UInt8 *surface;
  
  pVVar2 = M<UInt8 *>(self + kIOATIR500Shared_textureListHead);
  if (pVVar2 == textureBytes) {
    M<UInt32>(self + kIOATIR500Shared_textureListHead) = M<UInt32>(textureBytes + 0x3c);
  }
  else {
    if (pVVar2 == (UInt8 *)0x0) {
      return 0xe00002bc;
    }
    for (pVVar4 = M<UInt8 *>(pVVar2 + 0x3c); textureBytes != pVVar4;
        pVVar4 = M<UInt8 *>(pVVar4 + 0x3c)) {
      if (pVVar4 == (UInt8 *)0x0) {
        return 0xe00002bc;
      }
      pVVar2 = pVVar4;
    }
    M<UInt32>(pVVar2 + 0x3c) = M<UInt32>(textureBytes + 0x3c);
  }
  iVar7 = M<int>(textureBytes + 0x24);
  bufferType = textureBytes[0x20];
  M<UInt32>(iVar7 + 0x28) = M<UInt32>(textureBytes + 0x28);
  iVar3 = M<int>(textureBytes + 0x28);
  M<UInt8 *>(textureBytes + 0x28) = textureBytes;
  M<int>(iVar3 + 0x24) = iVar7;
  M<UInt8 *>(textureBytes + 0x24) = textureBytes;
  if ((((UInt8)((char)bufferType - 2U) < 2) || (bufferType == 0x6)) ||
     (bufferType == 0x7)) {
    if ((bufferType == 0x3) || (bufferType == 0x7)) {
      iVar3 = M<int>(textureBytes + 0x14);
      faceIndex = 0;
      if (M<char>(iVar3 + 0x34) != '\0') {
        do {
          iVar7 = faceIndex * 2;
          faceIndex = faceIndex + 1;
          M<UInt16>(iVar7 + iVar3 + 0x28) = 0;
          iVar3 = M<int>(textureBytes + 0x14);
        } while (faceIndex < M<UInt8>(iVar3 + 0x34));
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
      pVVar2 = M<UInt8 *>(textureBytes + 0x58);
      M<UInt32>(textureBytes + 0x58) = 0;
LAB_00017ac4:
      iVar3 = GH_OSDecrementAtomic(M<int>(pVVar2 + 0x14) + 0x10);
      if (iVar3 == 1) {
        this->delete_texture((VendorTextureBuffer *)(pVVar2));
      }
    }
    else if (textureBytes[0x20] == 0x6) {
      pVVar2 = M<UInt8 *>(textureBytes + 0x54);
      M<UInt32>(textureBytes + 0x54) = 0;
      goto LAB_00017ac4;
    }
    if (M<int>(textureBytes + 4) != 0) {
      accel = M<int *>(self + kIOATIR500Shared_accelerator);
      iVar3 = *accel;
      stamp = M<UInt32>(M<int>(textureBytes + 0x14) + 0xc);
LAB_00017b60:
      iVar3 = VCALL(iVar3, 0x554)(accel,stamp);
      if (iVar3 == 0) {
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
        iVar3 = *accel;
        stamp = M<UInt32>(M<int>(textureBytes + 0x14) + 8);
        goto LAB_00017b60;
      }
      goto LAB_00017ba0;
    }
    if (bufferType == 0x0) {
      surface = M<UInt8 *>(textureBytes + 0x50);
      if (surface != (UInt8 *)0x0) {
        pVVar2 = M<UInt8 *>(surface + 0xbcc);
        if (textureBytes == M<UInt8 *>(surface + 0xbcc)) {
          M<UInt32>(surface + 0xbcc) = M<UInt32>(textureBytes + 0x54);
        }
        else {
          do {
            pVVar4 = pVVar2;
            if (pVVar4 == (UInt8 *)0x0) break;
            pVVar2 = M<UInt8 *>(pVVar4 + 0x54);
          } while (textureBytes != M<UInt8 *>(pVVar4 + 0x54));
          M<UInt32>(pVVar4 + 0x54) = M<UInt32>(textureBytes + 0x54);
        }
        ((IOATIR500Surface *)(surface))->reset_req_bits();
        ((IOATIR500Surface *)(surface))->prune_buffers();
      }
    }
    else {
      if (bufferType != 0x1) goto LAB_00017cf0;
      pVVar2 = M<UInt8 *>(textureBytes + 0x50);
      if (pVVar2 != (UInt8 *)0x0) {
        iVar3 = GH_OSDecrementAtomic(M<int>(pVVar2 + 0x14) + 0x10);
        if (iVar3 == 1) {
          ((IOATIR500Shared *)(M<UInt8 *>(M<int>(self + kIOATIR500Shared_accelerator) + 0x6c)))->delete_texture((VendorTextureBuffer *)pVVar2);
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
