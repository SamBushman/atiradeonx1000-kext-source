/* NOTE 2026-09-19: 2 function bodies formerly in this file have been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * IOATIR500Accelerator_FreeOrphanTexture.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real bodies for
 * `IOATIR500Accelerator::freeOrphanTexture` (real addr 0x3680) and
 * `IOATIR500Shared::free_texvert` (real addr 0x18710, a real STATIC
 * method - see its own header comment in `Headers/IOATIR500Shared.h`).
 *
 * `freeOrphanTexture`: walks the accelerator's own orphan-texture list
 * (`+0x664`/`+0x63c`, the same real self-pointer-as-empty-sentinel
 * shape `freeWaitToAllocGART` already establishes), reading each
 * node's own real "release arg" from its `clientShared` (`+0x14`)
 * field - `+0xc` for kind 3/7, `+8` for kind 4/5 (kinds outside
 * [4,5] and not 3/7 stop the walk entirely, matching the real
 * decompile's own early `return`). In gentle mode (`aggressive==
 * false`), confirms via the already-established `+0x554` slot the
 * node is really free before proceeding, and if not, defers the whole
 * orphan sweep to a real one-shot timer (`+0xb8`'s own vtable `+300`
 * slot, real arg `100` - own exact Apple identity unconfirmed) gated
 * by a real "already scheduled" flag at `+0x82`. In aggressive mode,
 * accumulates a freed-byte stat at `+0x790` via the already-established
 * `waitForTimeStamp` `+0x54c` slot (same real argument-dropped
 * situation this project already documents for
 * `freeTransferToAllocGART`). Between iterations after the first, calls
 * a single-arg external (`FUN_000037dc`, real arg `0`, RESOLVED in
 * issue #58 follow-up as `thread_block(0)` via live kxld read) before tearing the node down via
 * `IOATIR500Shared::free_texvert`.
 *
 * Confidence: CONFIRMED for control flow and every real offset/literal
 * constant - two real, complete, standalone decompiles.
 */

#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/IOATIR500Shared.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8 &U8At(void *base, int offset) { return *reinterpret_cast<UInt8 *>(reinterpret_cast<UInt8 *>(base) + offset); }
typedef SInt32 (*Fn0x554)(void *, UInt32);
typedef UInt32 (*Fn0x5ac)(void *, void *);
typedef UInt32 (*Fn0x574)(void *, void *, UInt32);
typedef bool (*ScheduleFn)(void *, UInt32);
typedef UInt32 (*ReleaseFn)(void *);
} // namespace

/* FUN_000037dc: kxld-patched stub, live target 0x32eec = thread_block
 * (exact nm match); a plain yield between iterations. */
extern "C" void FreeOrphan_thread_block(UInt32 continuation) asm("_thread_block");

/* (re-ported mechanically: see IOATIR500Accelerator_freeOrphanTexture_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Shared_free_texvert_Port.cpp) */

