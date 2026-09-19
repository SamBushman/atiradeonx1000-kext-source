/*
 * ATIR5002DContext_AllocAndLoadImage.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real body for
 * `ATIR5002DContext::alloc_and_load_image` - real addr 0x31b70, the 2D
 * context's own analog of `ATIR500GLContext::alloc_and_load_texture`.
 *
 * Real body: for kind==3 or kind==4 textures, ensures the texture is
 * GART-mapped (calling `map_transfer_to_GART` only if it doesn't
 * already have a real backing descriptor, `+4`==0), and if it just
 * became mapped (or already was), stamps the current time via the
 * already-established `IOGetTime` helper into the texture's own
 * `+0x2c` field and unlink-then-reinserts it at the head of the
 * accelerator's own dirty-texture list (`accelerator+0x6d0`/`+0x69c` -
 * the SAME list `add_texture_to_stream`/`get_data_buffer`/
 * `purge_texture` already use, per this project's own established
 * cross-references). For kind==3 specifically, additionally tries the
 * accelerator's own `allocate_texture` then `freeToAllocTextureVRAM`
 * (both already established, real vtable `+0x528` and issue #31's own
 * body) against this context's own `boundSurface`/`lastBoundTexture`
 * fields, returning immediately (skipping the tail below) if both
 * succeed. Any other kind returns immediately, doing nothing. The
 * shared tail (kind 3-fallthrough or kind 4 always) clears a real byte
 * flag at the texture's own `clientShared+0x14`.
 *
 * Confidence: CONFIRMED for control flow and every real offset/literal
 * constant - a real, complete, standalone decompile.
 */

#include "../Headers/ATIR5002DContext.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Surface.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8 &U8At(void *base, int offset) { return *reinterpret_cast<UInt8 *>(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

/* real, CONFIRMED via live kxld-resolved memory read elsewhere in this
 * project (see ATIR500GLContext_TextureLoad.cpp/ATIR5002DContext_
 * ProcessCommandBuffer.cpp) - stamps the current time into the pointed
 * field. */
extern "C" void AllocAndLoadImage_IOGetTime(void *timestampField) asm("_IOGetTime");

/* (re-ported mechanically: see ATIR5002DContext_alloc_and_load_image_Port.cpp) */

