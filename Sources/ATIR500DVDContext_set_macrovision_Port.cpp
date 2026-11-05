/*
 * ATIR500DVDContext_set_macrovision_Port.cpp
 *
 * ATIR500DVDContext::set_macrovision (real addr 0x35010, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern "C" UInt32 GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(...) asm("__ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass");


/* real addr 0x35010 */
IOReturn ATIR500DVDContext::set_macrovision(UInt32 attribute, UInt32 value) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  SInt32 *framebuffer;
  UInt32 result;
  SInt32 framebufferIndex;
  SInt32 accelAddr;
  /* the shipped code spills its 3rd register argument (value, `value`) to the stack and passes the slot's address on */
  
  GH_IOLockLock(M<UInt32>(M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0x840));
  accelAddr = M<SInt32>(self + kIOATIR500DVDContext_accelerator);
  if (M<char>(accelAddr + kIOATIR500Accelerator_active) == '\0') {
    result = 0xe00002d8;
  }
  /* Root cause (#146): boundSurface is legitimately NULL until set_surface binds one, and again after remove_surface (vtable slot 0x5a4, called by
   * IOATIR500Surface::invalidate_contexts) unbinds it - so a well-behaved client can reach this state. The vendor code never tests for it before calling
   * getFramebufferIndex() on the NULL surface (DAR=0xD64 panic). All nine sibling methods that read boundSurface (get_surface_size, dvd_enable_overlay,
   * dvd_setup_subpicture, ...) test it first and return 0xe00002bc; this method lacked the same precondition. */
  else if (M<UInt8 *>(self + kIOATIR500DVDContext_boundSurface) == (UInt8 *)0x0) {
    result = 0xe00002bc;
  }
  else {
    framebufferIndex = ((ATIR500Surface *)(M<UInt8 *>(self + kIOATIR500DVDContext_boundSurface)))->getFramebufferIndex();
    framebuffer = (SInt32 *)GH_ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass(M<UInt32>(framebufferIndex * 0x20 + M<SInt32>(self + kIOATIR500DVDContext_accelerator) + 0xd4),
                                 GH_IONDRVFramebuffer_metaClass);
    M<SInt32 *>(self + kATIR500DVDContext_macrovisionFramebuffer) = framebuffer;
    if (framebuffer == (SInt32 *)0x0) {
      accelAddr = M<SInt32>(self + kIOATIR500DVDContext_accelerator);
      result = 0xe00002c0;
    }
    else {
      result = VCALL(*framebuffer, 0x70c)(framebuffer,attribute,&value);
      accelAddr = M<SInt32>(self + kIOATIR500DVDContext_accelerator);
    }
  }
  GH_IOLockUnlock(M<UInt32>(accelAddr + kIOATIR500Accelerator_commandLock));
  return result;
}
