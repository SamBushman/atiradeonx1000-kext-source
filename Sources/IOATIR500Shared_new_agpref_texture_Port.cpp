/*
 * IOATIR500Shared_new_agpref_texture_Port.cpp
 *
 * IOATIR500Shared::new_agpref_texture (real addr 0x17df0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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


/* real addr 0x17df0 */
VendorTextureBuffer *IOATIR500Shared::new_agpref_texture(unsigned int refAddress, unsigned int agpAddress, UInt32 agpLength, unsigned int*param_4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 iVar1;
  UInt8 *agpTexture;
  void *texture;
  SInt32 iVar4;
  UInt32 agpUserAddr;
  UInt32 handle;
  sIOClientShared *clientShared;
  UInt32 clientUserAddr [6];
  
  agpTexture = (UInt8 *)this->new_agp_texture(agpAddress,agpLength,(unsigned int *)(&agpUserAddr));
  if (agpTexture != (UInt8 *)0x0) {
    texture = (void *)VCALL(*M<SInt32 *>(self + 0xc), 0x570)(M<SInt32 *>(self + 0xc),0x80);
    if (texture != (void *)0x0) {
      iVar4 = this->alloc_buf_handle(texture,(UInt32 *)(&handle));
      if (iVar4 != 0) {
        iVar4 = this->alloc_client_shared(handle,(sIOClientShared **)(&clientShared),(unsigned int *)(clientUserAddr));
        if (iVar4 != 0) {
          iVar4 = 0;
          M<sIOClientShared *>((SInt32)texture + 0x14) = clientShared;
          M<UInt32>((SInt32)texture + 0x18) = clientUserAddr[0];
          M<UInt32>(clientShared) = handle;
          M<UInt32>(M<SInt32>((SInt32)texture + 0x14) + 8) =
               M<UInt32>(M<SInt32>(self + 0xc) + 0x54);
          M<UInt32>(M<SInt32>((SInt32)texture + 0x14) + 0xc) =
               M<UInt32>(M<SInt32>(self + 0xc) + 0x54);
          M<UInt8>(M<SInt32>((SInt32)texture + 0x14) + 0x16) = 6;
          M<UInt8>((SInt32)texture + 0x20) = 6;
          M<UInt8 *>((SInt32)texture + 0x1c) = self;
          if (refAddress != 0) {
            iVar4 = refAddress - M<SInt32>(agpTexture + 0x58);
          }
          M<SInt32>((SInt32)texture + 0x50) = iVar4;
          M<UInt8 *>((SInt32)texture + 0x54) = agpTexture;
          GH_OSIncrementAtomic(M<SInt32>(agpTexture + 0x14) + 0x10);
          M<UInt32>((SInt32)texture + 0x3c) = M<UInt32>(self + 0x24);
          M<void *>(self + 0x24) = texture;
          *param_4 = clientUserAddr[0];
          M<SInt32>(M<SInt32>(self + 0xc) + 0x72c) = M<SInt32>(M<SInt32>(self + 0xc) + 0x72c) + 1;
          iVar4 = M<SInt32>(self + 0xc);
          if (self != M<UInt8 *>(iVar4 + 0x6c)) {
            return (VendorTextureBuffer *)(texture);
          }
          iVar1 = M<SInt32>(iVar4 + 0x70);
          M<SInt32>(M<SInt32>((SInt32)texture + 0x14) + 4) = iVar1;
          M<SInt32>(iVar4 + 0x70) = iVar1 + 1;
          return (VendorTextureBuffer *)(texture);
        }
        this->free_buf_handle(texture,handle);
      }
      if (M<SInt32>(M<SInt32>(agpTexture + 0x14) + 0x10) == 0) {
        this->delete_texture((VendorTextureBuffer *)(agpTexture));
      }
      VCALL(*M<SInt32 *>(self + 0xc), 0x574)(M<SInt32 *>(self + 0xc),texture,0x80);
      return (VendorTextureBuffer *)((void *)0x0);
    }
    if (M<SInt32>(M<SInt32>(agpTexture + 0x14) + 0x10) == 0) {
      this->delete_texture((VendorTextureBuffer *)(agpTexture));
      return (VendorTextureBuffer *)((void *)0x0);
    }
  }
  return (VendorTextureBuffer *)((void *)0x0);
}
