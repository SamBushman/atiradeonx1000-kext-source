/*
 * IOATIR500Shared_new_surface_texture_Port.cpp
 *
 * IOATIR500Shared::new_surface_texture (real addr 0x17520, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x17520 */
VendorTextureBuffer *IOATIR500Shared::new_surface_texture(UInt32 surfaceId, UInt32 unknown_0x58, UInt32 unknown_0x34, unsigned int*param_4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  UInt8 *surface;
  void *texture;
  SInt32 iVar3;
  UInt32 handle;
  sIOClientShared *clientShared;
  UInt32 clientUserAddr [4];
  
  surface = (UInt8 *)
            ((IOATIR500Accelerator *)(M<UInt8 *>(self + kIOATIR500Shared_accelerator)))->find_surface_for_id(surfaceId);
  if ((surface != (UInt8 *)0x0) &&
     (texture = (void *)VCALL(*M<SInt32 *>(self + kIOATIR500Shared_accelerator), 0x570)(M<SInt32 *>(self + kIOATIR500Shared_accelerator),0x80),
     texture != (void *)0x0)) {
    M<UInt32>((SInt32)texture + 8) = 0;
    iVar3 = this->alloc_buf_handle(texture,(UInt32 *)(&handle));
    if (iVar3 != 0) {
      iVar3 = this->alloc_client_shared(handle,(sIOClientShared **)(&clientShared),(unsigned int *)(clientUserAddr));
      if (iVar3 != 0) {
        M<sIOClientShared *>((SInt32)texture + 0x14) = clientShared;
        M<UInt32>(clientShared) = handle;
        M<UInt32>(M<SInt32>((SInt32)texture + 0x14) + 8) =
             M<UInt32>(M<SInt32>(self + kIOATIR500Shared_accelerator) + 0x54);
        M<UInt32>(M<SInt32>((SInt32)texture + 0x14) + 0xc) =
             M<UInt32>(M<SInt32>(self + kIOATIR500Shared_accelerator) + 0x54);
        M<UInt8>(M<SInt32>((SInt32)texture + 0x14) + 0x16) = 0;
        M<char>(M<SInt32>((SInt32)texture + 0x14) + 0x34) = (char)unknown_0x34;
        M<UInt8>((SInt32)texture + 0x20) = 0;
        M<UInt32>((SInt32)texture + 0x10) = 0;
        M<UInt32>((SInt32)texture + 0x58) = unknown_0x58;
        M<UInt32>((SInt32)texture + 0x5c) = surfaceId;
        M<UInt8 *>((SInt32)texture + 0x1c) = self;
        M<UInt8 *>((SInt32)texture + 0x50) = surface;
        M<UInt32>((SInt32)texture + 0x3c) = M<UInt32>(self + kIOATIR500Shared_textureListHead);
        M<void *>(self + kIOATIR500Shared_textureListHead) = texture;
        *param_4 = clientUserAddr[0];
        M<UInt32>((SInt32)texture + 0x54) = M<UInt32>(surface + 0xbcc);
        M<void *>(surface + 0xbcc) = texture;
        ((IOATIR500Surface *)(surface))->reset_req_bits();
        ((IOATIR500Surface *)(surface))->prune_buffers();
        M<SInt32>(M<SInt32>(self + kIOATIR500Shared_accelerator) + 0x72c) = M<SInt32>(M<SInt32>(self + kIOATIR500Shared_accelerator) + 0x72c) + 1;
        iVar3 = M<SInt32>(self + kIOATIR500Shared_accelerator);
        if (self != M<UInt8 *>(iVar3 + 0x6c)) {
          return (VendorTextureBuffer *)(texture);
        }
        iVar1 = M<SInt32>(iVar3 + 0x70);
        M<SInt32>(M<SInt32>((SInt32)texture + 0x14) + 4) = iVar1;
        M<SInt32>(iVar3 + 0x70) = iVar1 + 1;
        return (VendorTextureBuffer *)(texture);
      }
      this->free_buf_handle(texture,handle);
    }
    VCALL(*M<SInt32 *>(self + kIOATIR500Shared_accelerator), 0x574)(M<SInt32 *>(self + kIOATIR500Shared_accelerator),texture,0x80);
    return (VendorTextureBuffer *)((void *)0x0);
  }
  return (VendorTextureBuffer *)((void *)0x0);
}
