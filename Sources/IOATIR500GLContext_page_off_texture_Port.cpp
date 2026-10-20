/*
 * IOATIR500GLContext_page_off_texture_Port.cpp
 *
 * IOATIR500GLContext::page_off_texture (real addr 0x9740, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOLockLock(...) asm("_IOLockLock");
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");


/* real addr 0x9740 */
IOReturn IOATIR500GLContext::page_off_texture(UInt32 textureID, UInt32 mipAndFace, unsigned int structPtr, unsigned int structSize) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 *accel;
  UInt32 result;
  SInt32 textureLookup;
  SInt32 faceBits;
  SInt32 texture;   /* #169: the texture-buffer pointer, live in r4 at the vcall in stock (0x9790 lwzx r4) */
  
  GH_IOLockLock(M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_accelerator) + 0x840));
  accel = M<SInt32 *>(self + kIOATIR500GLContext_accelerator);
  if (M<char>(accel + 0x20) == '\0') {
unlockAndSucceed:
    GH_IOLockUnlock(accel[0x210]);
    result = 0;
  }
  else {
    if (textureID < M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x14)) {
      textureLookup = M<SInt32>(textureID * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x10));
      texture = textureLookup;
      if (textureLookup != 0) {
        faceBits = (mipAndFace >> 0x10) * 2 + M<SInt32>(textureLookup + 0x14);
        if ((((UInt32)M<UInt16>(faceBits + 0x28) & ~(UInt32)M<UInt16>(faceBits + 0x1c)) >>
             (mipAndFace & 0x3f) & 1) != 0) {
          /* #169: stock 0x97e4 calls vtable+0x52c (ATIRadeonX1000::pageoff_dirty_texture) with r3=accel, r4=texture,
           * r5=mipAndFace>>16, r6=mipAndFace&0xffff - all still live in registers from the check above. The earlier port
           * dropped the three arguments (implicit-argument forwarding), so the callee read a NULL texture. */
          VCALL(*accel, 0x52c)(accel, texture, mipAndFace >> 0x10, mipAndFace & 0xffff);
          accel = M<SInt32 *>(self + kIOATIR500GLContext_accelerator);
        }
        goto unlockAndSucceed;
      }
    }
    GH_IOLockUnlock(accel[0x210]);
    result = 0xe00002c2;
  }
  return result;
}
