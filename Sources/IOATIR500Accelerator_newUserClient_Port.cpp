/*
 * IOATIR500Accelerator_newUserClient_Port.cpp
 *
 * IOATIR500Accelerator::newUserClient (real addr 0x2070, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
#include <libkern/c++/OSBoolean.h>


/* #153 ROOT CAUSE (found 2026-10-08, live-verified): this file used to declare its own
 * `extern "C" void *g_kOSBooleanTrue asm("_kOSBooleanTrue");` alias instead of including the real
 * header - a pattern inherited from the original hand-written body (Sources/IOATIR500Accelerator_
 * NewUserClient.cpp, now dead/historical) that the mechanical port kept without question. That
 * alias does NOT resolve to the real OSBoolean TRUE singleton's address - a live comparison
 * against Apple's own properly-typed `kOSBooleanTrue` global (from this header), logged from the
 * same call site at the same moment, showed the hand-rolled version is one dereference short:
 * it gives the ADDRESS OF THE POINTER VARIABLE (0x3d7960, stable across every boot) instead of
 * the ADDRESS OF THE ACTUAL OBJECT that variable points to (0x1038fd30 in that boot, matching
 * exactly what the real `kOSBooleanTrue` global reads directly and what *(UInt32*)g_kOSBooleanTrue
 * gave when dereferenced once by hand).
 *
 * This explains the Surface-client-open crash completely: passing 0x3d7960 as the real
 * `OSDictionary::setObject`'s `anObject` argument, stock setObject correctly calls
 * `anObject->vtable[0x28]` (OSBoolean::taggedRetain) on it - reading *(UInt32*)0x3d7960 as "the
 * vtable" (actually 0x1038fd30, the real object's address, not a vtable at all), then reading
 * *(UInt32*)(0x1038fd30 + 0x28) as a function pointer and jumping there - a wild branch to
 * whatever garbage happens to live at that offset into an unrelated object. Confirmed
 * independently via raw kernel disassembly (issue #153's own GitHub thread) that stock's
 * `taggedRetain` is a trivial no-op `blr`, and via `nm`/relocation-table reads of /mach_kernel
 * that the real `__ZTV9OSBoolean` vtable (0x35e330) was never actually reached.
 *
 * Fix: use the real, properly-typed `kOSBooleanTrue` global (this header) directly instead of the
 * broken hand-rolled alias - same methodology as `issue153_probe`'s working comparison kext. */

extern "C" UInt32 GH_ZN12OSDictionary12withCapacityEj(...) asm("__ZN12OSDictionary12withCapacityEj");


/* real addr 0x2070 */
IOReturn IOATIR500Accelerator::newUserClient(task *owningTask, void*securityID, UInt32 type, IOUserClient**handler) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *owningTaskBytes = reinterpret_cast<UInt8 *>(owningTask);

  code *factory;
  UInt8 *client;
  SInt32 clientStatus;
  SInt32 *properties;
  UInt8 noProperties;

  *handler = (IOUserClient *)0x0;
  if (type == 1) {
    factory = M<code *>(M<SInt32>(self) + 0x5e0);
  }
  else {
    if (type == 0) {
      properties = (SInt32 *)GH_ZN12OSDictionary12withCapacityEj(1);
      noProperties = (properties == (SInt32 *)0x0) << 1;
      if (properties == (SInt32 *)0x0) {
        return 0xe00002be;
      }
      VCALL(*properties, 300)(properties,"IOUserClientCrossEndianCompatible",
                          (UInt32)const_cast<void *>(static_cast<const void *>(kOSBooleanTrue)));
      client = (UInt8 *)VCALL(M<SInt32>(self), 0x5d4)(self);
      if (client == (UInt8 *)0x0) {
        VCALL(*properties, 0x18)(properties);
        return 0xe00002be;
      }
      M<task *>(client + 0x78) = owningTask;
      goto attachClient;
    }
    if (type != 2) {
      if (type != 3) {
        return 0xe00002c2;
      }
      client = (UInt8 *)VCALL(M<SInt32>(self), 0x5dc)(self);
      if (client == (UInt8 *)0x0) {
        return 0xe00002be;
      }
      M<task *>(client + 0x78) = owningTask;
      properties = (SInt32 *)0x0;
      noProperties = 2;
      goto attachClient;
    }
    factory = M<code *>(M<SInt32>(self) + 0x5d8);
  }
  /* #153 root cause: real disassembly (addr 0x2070; GL/2D branches at 0x2160/0x2170) confirms this
   * call explicitly loads only r2 (the vtable, to fetch the function pointer) - r3 (self/"this")
   * is never clobbered since function entry, so it is still self's value when the real compiled
   * code's bctrl executes. The naive 0-argument transcription dropped that implicit first
   * argument entirely; our own compiler has no reason to leave self in r3 for a call that
   * references no arguments at all in the C++ source. This is the actual cause of #153's
   * deterministic, build-independent crash: newUserClient is the very first thing called when
   * opening a GL (type==1) or 2D (type==2) user client, which is why the crash recurred
   * identically regardless of any GART/texture-buffer fix tried earlier. */
  client = (UInt8 *)(*factory)(self);
  if (client == (UInt8 *)0x0) {
    return 0xe00002be;
  }
  properties = (SInt32 *)0x0;
  M<task *>(client + 0x78) = owningTask;
  noProperties = 2;
attachClient:
  clientStatus = VCALL(M<SInt32>(client), 0x150)(client,properties);
  if (clientStatus != 0) {
    clientStatus = VCALL(M<SInt32>(client), 0x3a4)(client,self);
  }
  if (clientStatus != 0) {
    clientStatus = VCALL(M<SInt32>(client), 0x348)(client,self);
    if (clientStatus != 0) {
      *handler = (IOUserClient *)client;
      if (!(bool)(noProperties >> 1 & 1)) {
        VCALL(*properties, 0x18)(properties);
      }
      return 0;
    }
    VCALL(M<SInt32>(client), 0x3a8)(client,self);
  }
  VCALL(M<SInt32>(client), 0x18)(client);
  if (!(bool)(noProperties >> 1 & 1)) {
    VCALL(*properties, 0x18)(properties);
  }
  return 0xe00002c9;
}
