/*
 * IOATIR500Shared_new_global_texture_Port.cpp
 *
 * IOATIR500Shared::new_global_texture (real addr 0x17740, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_OSIncrementAtomic(...) asm("_OSIncrementAtomic");


/* real addr 0x17740 */
VendorTextureBuffer *IOATIR500Shared::new_global_texture(UInt32 globalId, unsigned int *real_param_2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    unsigned int *param_2 = reinterpret_cast<unsigned int *>(real_param_2);

  UInt8 *globalShared;
  int *accel;
  void *texture;
  int iVar4;
  int sourceTexture;
  UInt32 handle;
  sIOClientShared *clientShared;
  unsigned int clientUserAddr [4];
  
  if (globalId != 0) {
    accel = M<int *>(self + kIOATIR500Shared_accelerator);
    globalShared = (UInt8 *)accel[0x1b];
    if ((globalShared != (UInt8 *)0x0) && (self != globalShared)) {
      for (sourceTexture = M<int>(globalShared + 0x24); sourceTexture != 0; sourceTexture = M<int>(sourceTexture + 0x3c)) {
        if (globalId == M<UInt32>(M<int>(sourceTexture + 0x14) + 4)) {
          texture = (void *)VCALL(*accel, 0x570)(accel,0x80);
          if (texture == (void *)0x0) {
            return (VendorTextureBuffer *)((void *)0x0);
          }
          iVar4 = this->alloc_buf_handle(texture,(UInt32 *)(&handle));
          if (iVar4 != 0) {
            iVar4 = this->alloc_client_shared(handle,(sIOClientShared **)(&clientShared),(unsigned int *)(clientUserAddr));
            if (iVar4 != 0) {
              M<UInt32>((int)texture + 8) = 0;
              M<sIOClientShared *>((int)texture + 0x14) = clientShared;
              M<UInt32>(clientShared) = handle;
              M<UInt32>(M<int>((int)texture + 0x14) + 8) =
                   M<UInt32>(M<int>(self + kIOATIR500Shared_accelerator) + 0x54);
              M<UInt32>(M<int>((int)texture + 0x14) + 0xc) =
                   M<UInt32>(M<int>(self + kIOATIR500Shared_accelerator) + 0x54);
              M<UInt8>(M<int>((int)texture + 0x14) + 0x16) = 1;
              M<UInt8>((int)texture + 0x20) = 1;
              M<UInt32>((int)texture + 0x10) = 0;
              M<UInt8 *>((int)texture + 0x1c) = self;
              M<int>((int)texture + 0x50) = sourceTexture;
              GH_OSIncrementAtomic(M<int>(sourceTexture + 0x14) + 0x10);
              VCALL(*M<int *>(M<int>(self + kIOATIR500Shared_accelerator) + 0x6c), 0x14)(M<int *>(M<int>(self + kIOATIR500Shared_accelerator) + 0x6c));
              M<UInt32>((int)texture + 0x3c) = M<UInt32>(self + kIOATIR500Shared_textureListHead);
              M<void *>(self + kIOATIR500Shared_textureListHead) = texture;
              *param_2 = clientUserAddr[0];
              M<int>(M<int>(self + kIOATIR500Shared_accelerator) + 0x72c) = M<int>(M<int>(self + kIOATIR500Shared_accelerator) + 0x72c) + 1;
              return (VendorTextureBuffer *)(texture);
            }
            this->free_buf_handle(texture,handle);
          }
          VCALL(*M<int *>(self + kIOATIR500Shared_accelerator), 0x574)(M<int *>(self + kIOATIR500Shared_accelerator),texture,0x80);
          return (VendorTextureBuffer *)((void *)0x0);
        }
      }
    }
  }
  return (VendorTextureBuffer *)((void *)0x0);
}
