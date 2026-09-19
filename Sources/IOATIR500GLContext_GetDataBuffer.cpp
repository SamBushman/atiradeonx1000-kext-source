/*
 * IOATIR500GLContext_GetDataBuffer.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real body for
 * `IOATIR500GLContext::get_data_buffer` - real addr 0x9a30, the real
 * "hand the client a fresh/recycled scratch data buffer" external
 * method (external method 18).
 *
 * Real body: grows this context's own requested-size hint
 * (`this+0xb4`, capped at 0x80000) if the previous buffer turned out
 * too small for the current command-buffer's own needs, ratchets the
 * accelerator's own shared `cachedBufferSizeThresholdB` (`+0x5d8`) up
 * to match, then either reuses the accelerator's single cached free
 * data buffer (`+0x5cc`) if it's confirmed idle (via the already-
 * established `+0x554` slot) or allocates a fresh one via
 * `allocOneDataBuffer` - falling back to accumulating a real freed-
 * byte stat (`+0x1de`-th field, via `waitForTimeStamp`) when reuse
 * fails and a fresh allocation also fails. If the fetched buffer no
 * longer matches the accelerator's own cache slot, unlinks it from a
 * real secondary list (`+0x3c` singly-linked) and does real per-kind
 * teardown (GART unmap, `deallocate_texture`, GART-mapping release) to
 * reset it to a plain, unmapped, correctly-sized buffer. Then - gated
 * on whether the device is active - either backs it with plain memory
 * via `allocDataBufferBacking` (freeing and failing on error) or tries
 * the accelerator's own `allocate_texture` first, falling back to
 * `allocDataBufferBacking` if that vtable call reports no support.
 * Every path funnels into a shared tail that marks the buffer resident
 * (`+0x54`=1), appends it to this context's own pending-buffer list
 * (`+0xec`/`+0xe8`/`+0xf0`), stamps it with this context's own
 * generation counter (`+0x5c`), records it as the current command-
 * buffer target (`this+0x108`'s own `+8`), lazily creates its real
 * userspace mapping via the already-established `+0x14c` map call if
 * missing, and returns its virtual address (`+0xd0`) plus its own
 * `+0x50` field to the caller.
 *
 * Confidence: CONFIRMED for control flow and every real offset/literal
 * constant - a real, complete, standalone decompile. Several vtable
 * slots (`+0xdc`/`+0xf0`) have no established real name/role beyond
 * what's directly inferable from this one call site - flagged
 * accordingly rather than guessed.
 */

#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/ATIRadeonX1000.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8 &U8At(void *base, int offset) { return *reinterpret_cast<UInt8 *>(reinterpret_cast<UInt8 *>(base) + offset); }
typedef SInt32 (*Fn0x554)(void *, UInt32);
typedef UInt32 (*Fn0x54c)(void *, UInt32);
typedef void (*Fn0x5ac)(void *, void *);
typedef void (*Fn0x524)(void *, void *);
typedef IOReturn (*Fn0x528)(void *, void *);
typedef void (*ReleaseFn)(void *);
typedef UInt32 (*Fn0xdc)(void *);
typedef void (*Fn0xf0)(void *, UInt32, UInt32, UInt32);
typedef void *(*MapFn)(void *, void *, int, UInt32, UInt32, UInt32);
typedef UInt32 (*Fn0xd0)(void *);
} // namespace

extern "C" void GetDataBuffer_mutex_lock(void *lockPtr) asm("_IOLockLock");
extern "C" void GetDataBuffer_mutex_unlock(void *lockPtr) asm("_IOLockUnlock");
extern "C" int kernelPageSize asm("_page_size"); /* kernel page_size (0x1000). Ghidra labels every zero-immediate data relocation in this kext "_ASICSupportsAGP"; the real target of each site comes from the Mach-O relocation table (issue #58 follow-up) */

/* (re-ported mechanically: see IOATIR500GLContext_get_data_buffer_Port.cpp) */

