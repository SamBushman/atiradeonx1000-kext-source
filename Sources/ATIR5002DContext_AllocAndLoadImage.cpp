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

void ATIR5002DContext::alloc_and_load_image(VendorTextureBuffer *texture) {
    UInt8 *tex = reinterpret_cast<UInt8 *>(texture);
    UInt8 kind = U8At(tex, 0x20);

    if (kind == 3 || kind == 4) {
        bool mapped = (U32At(tex, 4) != 0);
        if (!mapped) {
            map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(texture));
            mapped = (U32At(tex, 4) != 0);
        }
        if (mapped) {
            AllocAndLoadImage_IOGetTime(tex + 0x2c);

            UInt8 *oldPrev = reinterpret_cast<UInt8 *>(U32At(tex, 0x34));
            UInt8 *oldNext = reinterpret_cast<UInt8 *>(U32At(tex, 0x38));
            U32At(oldPrev, 0x38) = reinterpret_cast<UInt32>(oldNext);
            U32At(oldNext, 0x34) = reinterpret_cast<UInt32>(oldPrev);

            UInt8 *accel = reinterpret_cast<UInt8 *>(accelerator);
            U32At(tex, 0x34) = U32At(accel, 0x6d0);
            U32At(tex, 0x38) = reinterpret_cast<UInt32>(accel + 0x69c);
            U32At(accel, 0x6d0) = reinterpret_cast<UInt32>(tex);
            U32At(reinterpret_cast<void *>(U32At(tex, 0x34)), 0x38) = reinterpret_cast<UInt32>(tex);
        }

        if (kind == 3) {
            if (U32At(tex, 0x48) == 0 &&
                accelerator->allocate_texture(texture) == 0 &&
                accelerator->freeToAllocTextureVRAM(boundSurface, &lastBoundTexture, 1, texture) == 0) {
                return;
            }
        }
    } else {
        return;
    }

    U8At(reinterpret_cast<void *>(U32At(tex, 0x14)), 0x14) = 0;
}
