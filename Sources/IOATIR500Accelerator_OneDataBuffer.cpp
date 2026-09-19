/*
 * IOATIR500Accelerator_OneDataBuffer.cpp
 *
 * RESOLVED: `IOATIR500Accelerator::allocOneDataBuffer`/`freeOneDataBuffer`'s
 * real bodies (real addrs 0x6960/0x32d0), including the real identity of
 * every vtable call each makes - `allocVendorTextureBuffer`/
 * `releaseVendorTextureBuffer`/`removeTransferFromGART`/
 * `alloc_surface_buffer` (`+0x570`/`+0x574`/`+0x5ac`/`+0x56c`), all
 * confirmed via direct `nm` cross-check on both the base and concrete
 * subclass vtables - see `Headers/IOATIR500Accelerator.h`'s own
 * declaration comment for the full account (an earlier pass this same
 * session reported a real anomaly here that turned out to be this
 * project's own by-hand arithmetic slip, now corrected).
 *
 * `allocOneDataBuffer`: allocates a real `0xc0`-byte `VendorTextureBuffer`-
 * shaped object via `allocVendorTextureBuffer`, stamps its own `poolSizeClass` (`+0x50`)
 * and `mip` pointer (`+0x14`, pointed at the object's own embedded
 * `+0x80` record) and `typeTag` (`+0x20` = `8`, a real data-buffer type
 * this project hasn't seen elsewhere). If `forWrite` is false, or a real
 * `allocate_texture` call (`+0x528`, RESOLVED elsewhere) fails, falls
 * back to `allocDataBufferBacking`; on failure there too, releases via
 * `releaseVendorTextureBuffer` and returns null. If `forWrite` succeeded,
 * splices the buffer into a real per-accelerator list (`this+0x600`,
 * sentinel `this+0x5dc`) when its own `transferBufferFlag` (`+0x48`) is
 * set, then calls a real `waitForTimeStamp`-shaped method (`+0x54c`,
 * RESOLVED elsewhere) with `this+0x50 - 1`. Either way, increments a
 * real per-accelerator counter (`+0x750`).
 *
 * `freeOneDataBuffer`: the real inverse - unsplices from the same list
 * (via `deallocate_texture`, `+0x524`, called here with NO visible
 * arguments in the raw decompile - the same real "calling-convention
 * artifact" this project documents elsewhere) when `transferBufferFlag`
 * is set, releases a real GART-mapping handle (`+0x10`, vtable `+0x18` -
 * `OSObject::release()`) if present, and - if the buffer has a real
 * `memoryDescriptor` (`+8`) - calls `waitForTimeStamp` (`+0x54c`) on its
 * own `+0x5c` field then `removeTransferFromGART` on the buffer itself
 * (real signature takes a `VendorTransferBuffer*` - this project's own
 * established note that `VendorTransferBuffer`/`VendorTextureBuffer`
 * overlap in shape applies here) before releasing the descriptor
 * (vtable `+0x18` again). Finally releases the whole object via
 * `releaseVendorTextureBuffer` and decrements the same `+0x750` counter.
 *
 * Confidence: CONFIRMED for control flow and every real offset,
 * including every vtable call's real identity. No C++ compiler was
 * available in the sandboxed environment this was written in (same
 * standing limitation as every other file in this project).
 */

#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/ATIRadeonX1000Types.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

/* (re-ported mechanically: see IOATIR500Accelerator_allocOneDataBuffer_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Accelerator_freeOneDataBuffer_Port.cpp) */

