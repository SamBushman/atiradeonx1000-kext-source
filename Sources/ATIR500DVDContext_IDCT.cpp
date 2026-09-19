/*
 * ATIR500DVDContext_IDCT.cpp
 *
 * doIDCT - THE real external entry point for this GPU's independent
 * hardware IDCT engine (real kext offset 0x35540), directly relevant to
 * this project's H.264 GPU-decode goal. CONFIRMED, fully decoded this
 * session (stage5-iouserclient-external-method-api-complete.md).
 *
 * This is transcribed close to the real decompiled control flow (raw
 * offset arithmetic, matching field names where this project's struct
 * reconstruction is confident - see Headers/ATIRadeonX1000Types.h's
 * sATIDVDIDCTInfo/sATIDVDIDCTParams - and raw UInt8* arithmetic with
 * inline comments where a couple of VendorTransferBuffer fields this
 * function touches (a real "resident size" field at +0x10) were not
 * independently added to that struct's confirmed field list this pass).
 *
 * Confidence: CONFIRMED for control flow and every register/field this
 * project already named; the two fields called out above are a real,
 * narrow, honestly-marked gap.
 */

#include "../Headers/ATIR500DVDContext.h"
#include "../Headers/ATIRadeonX1000.h"

extern "C" void IDCT_lock(void *) asm("_IOLockLock");
extern "C" void IDCT_unlock(void *) asm("_IOLockUnlock");

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

/*
 * CORRECTED (ledger pass): the shipped signature is doIDCT(sATIDVDIDCTInfo *info, unsigned long size) - a real
 * member function. The stock decompile shows `this` typed as the first parameter, and the earlier transcription of
 * this file therefore treated `info` (the caller's parameter block, layout sATIDVDIDCTParams here) as the context
 * object and the object's own fields as a parameter block. Rewritten with `this` as the context and `info` as the
 * caller's block. Also restored: the initial waitForTimeStamp(this+0x7c), the accelerator command lock around the
 * body, and the shipped code's own lock LEAK: a planeSelector other than 0/1 returns kIOReturnBadArgument with the
 * command lock still held (faithful; the next locker of that accelerator will block).
 */
/* (re-ported mechanically: see ATIR500DVDContext_doIDCT_Port.cpp) */

