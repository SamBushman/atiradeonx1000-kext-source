/*
 * ATIRadeonX1000_Xdct.cpp
 *
 * RESOLVED (ledger pass): start_xdct_engine / stop_xdct_engine.
 * Mechanically ported from the Ghidra decompile of the shipped kext (Tools/port_fn.py); real addresses in the markers.
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIR500Memory.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h"
#include "../Headers/GhidraExterns.h"
#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"

extern "C" UInt32 gl_assert_wait_timeout_event;
extern "C" UInt32 global_dummy_read_back_a_register;
extern "C" UInt32 GH_IODelay(...) asm("_IODelay");
extern "C" UInt32 GH_IOLockLock(...) asm("_IOLockLock");
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");
extern "C" UInt32 GH_IOSleep(...) asm("_IOSleep");
extern "C" UInt32 GH_OSDecrementAtomic(...) asm("_OSDecrementAtomic");
extern "C" UInt32 GH_OSIncrementAtomic(...) asm("_OSIncrementAtomic");
extern "C" UInt32 GH_absolutetime_to_nanoseconds(...) asm("_absolutetime_to_nanoseconds");
extern "C" UInt32 GH_assert_wait_timeout(...) asm("_assert_wait_timeout");
extern "C" UInt32 GH_clock_get_uptime(...) asm("_clock_get_uptime");
extern "C" UInt32 GH_thread_block(...) asm("_thread_block");


/* real addr 0x25c60 */
bool ATIRadeonX1000::start_xdct_engine() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool pollLimitReached;
  UInt32 ringBaseAddress;
  SInt32 vramBase;
  SInt32 mmioBase;
  UInt32 ringControl;
  UInt32 ringCursor;
  UInt32 rptrWritebackAddress;
  SInt32 pollCount;
  UInt32 idctStamp;
  
  mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  M<UInt32>(mmioBase + 0x1f80) = 0;
  enforceInOrderExecutionIO();
  enforceInOrderExecutionIO();
  ringControl = loadWordByteReversed(&M<UInt8>(mmioBase + 0x1f94)) | 0x88000000;      /* one byte-reversed read, kept: reused below, as in the shipped code */
  storeWordByteReversed(&M<UInt8>(mmioBase + 0x1f94), ringControl);
  enforceInOrderExecutionIO();
  ringCursor = M<UInt32>(self + kIOATIR500Accelerator_idctRingCursor);
  M<UInt32>(mmioBase + 0x1f9c) =
       ringCursor << 0x18 | (ringCursor & 0xff00) << 8 | ringCursor >> 8 & 0xff00 | ringCursor >> 0x18;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x1fa0) =
       ringCursor << 0x18 | (ringCursor & 0xff00) << 8 | ringCursor >> 8 & 0xff00 | ringCursor >> 0x18;
  enforceInOrderExecutionIO();
  vramBase = M<SInt32>(self + kIOATIR500Accelerator_vramSizeProgrammed);
  rptrWritebackAddress = vramBase + M<SInt32>(self + kIOATIR500Accelerator_scratchBufferGartOffset) + (M<SInt32>(self + kIOATIR500Accelerator_idctPointerBase) - M<SInt32>(self + kIOATIR500Accelerator_scratchHeader));
  M<UInt32>(mmioBase + 0x1f98) =
       (rptrWritebackAddress & 0xfffffffc) << 0x18 | (rptrWritebackAddress & 0xff00) << 8 | rptrWritebackAddress >> 8 & 0xff00 | rptrWritebackAddress >> 0x18;
  enforceInOrderExecutionIO();
  ringBaseAddress = vramBase + M<SInt32>(self + kIOATIR500Accelerator_idctRingGartOffset);
  M<UInt32>(mmioBase + 0x1f90) =
       ringBaseAddress * 0x1000000 | (ringBaseAddress & 0xff00) << 8 | ringBaseAddress >> 8 & 0xff00 | ringBaseAddress >> 0x18;
  enforceInOrderExecutionIO();
  ringControl = ringControl & 0x67fcc0ff | 0x2002030a;
  storeWordByteReversed(&M<UInt8>(mmioBase + 0x1f94), ringControl);
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x1f80) = 0x40;
  enforceInOrderExecutionIO();
  idctStamp = M<SInt32>(self + kIOATIR500Accelerator_idctSubmitBaseCounter) - 1;
  M<UInt32>(mmioBase + 0x1fa8) =
       idctStamp * 0x1000000 | (idctStamp & 0xff00) << 8 | idctStamp >> 8 & 0xff00 | idctStamp >> 0x18;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x1f80) = 0xa000580;
  enforceInOrderExecutionIO();
  if ((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1f9c))) <
      (loadWordByteReversed(&M<UInt8>(mmioBase + 0x1fa0)))) {
    pollCount = 0;
    do {
      GH_assert_wait_timeout(&gl_assert_wait_timeout_event,0,100,1000);
      GH_thread_block(0);
      mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
      pollLimitReached = pollCount == 10000;
      pollCount = pollCount + 1;
      if (pollLimitReached) break;
    } while ((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1f9c))) <
             (loadWordByteReversed(&M<UInt8>(mmioBase + 0x1fa0))));
  }
  M<UInt32>(self + kIOATIR500Accelerator_xdctEngineRunning) = 1;
  return 1;
}

/* real addr 0x25df0 */
bool ATIRadeonX1000::stop_xdct_engine() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool pollLimitReached;
  SInt32 mmioBase;
  SInt32 pollCount;
  
  mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  if ((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1f9c))) <
      (loadWordByteReversed(&M<UInt8>(mmioBase + 0x1fa0)))) {
    pollCount = 0;
    do {
      GH_assert_wait_timeout(&gl_assert_wait_timeout_event,0,100,1000);
      GH_thread_block(0);
      mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
      pollLimitReached = pollCount == 10000;
      pollCount = pollCount + 1;
      if (pollLimitReached) break;
    } while ((loadWordByteReversed(&M<UInt8>(mmioBase + 0x1f9c))) <
             (loadWordByteReversed(&M<UInt8>(mmioBase + 0x1fa0))));
  }
  enforceInOrderExecutionIO();
  storeWordByteReversed(&M<UInt8>(mmioBase + 0x1f94), loadWordByteReversed(&M<UInt8>(mmioBase + 0x1f94)) | 0x88000000);
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x1f80) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x1f9c) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(mmioBase + 0x1fa0) = 0;
  enforceInOrderExecutionIO();
  M<UInt32>(self + kIOATIR500Accelerator_xdctEngineRunning) = 0;
  return 1;
}

