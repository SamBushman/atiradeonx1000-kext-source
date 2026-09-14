/*
 * MapTransferToGART_RemainingContexts.cpp
 *
 * RESOLVED (issue #28): the three remaining `map_transfer_to_GART`
 * bodies - `IOATIR500Surface` (real addr 0x10be0), `IOATIR5002DContext`
 * (real addr 0xbb40), `IOATIR500DVDContext` (real addr 0xe820).
 * Structurally identical to the already-transcribed
 * `IOATIR500GLContext::map_transfer_to_GART`
 * (`Sources/IOATIR500GLContext_TextureStream.cpp`): call
 * `accelerator->addTransferToGART(buffer)`, then unconditionally call
 * `accelerator->freeToAllocGART(...)` excluding this context's own
 * associated 2D/DVD/GL/Surface/Shared objects. The apparent real gate on
 * `addTransferToGART`'s "return value" is the SAME real calling-
 * convention artifact issue #26 already settled for the GL variant (the
 * whole `addTransferToGART`/`addToGART` chain is genuinely void at every
 * level this project can see) - the unconditional call is the correct
 * final transcription for all three, not a placeholder.
 *
 * DVD's own `excludeSurface`/`excludeShared` arguments (`this+0xf8`/
 * `this+0x84`) are transcribed as raw offsets rather than named fields -
 * `this+0xf8` in particular is the SAME real field this project's own
 * `idctInfo` (`Headers/ATIRadeonX1000Types.h`) already flags as
 * ambiguously overloaded between an IDCT-info-struct role and a
 * boundSurface-shaped role; using it here as a `IOATIR500Surface*`
 * argument is consistent with that existing ambiguity note, not a new
 * uncertainty.
 *
 * Confidence: CONFIRMED for control flow and every real offset - three
 * real, complete, standalone decompiles, all structurally identical to
 * the already-verified GL variant. No C++ compiler was available in the
 * sandboxed environment this was written in (same standing limitation as
 * every other file in this project).
 */

#include "../Headers/IOATIR500Surface.h"
#include "../Headers/IOATIR5002DContext.h"
#include "../Headers/ATIR500DVDContext.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Shared.h"

void IOATIR500Surface::map_transfer_to_GART(VendorTransferBuffer *buffer) {
    accelerator->addTransferToGART(buffer);
    accelerator->freeToAllocGART(nullptr, nullptr, nullptr, this, nullptr, buffer);
}

void IOATIR5002DContext::map_transfer_to_GART(VendorTransferBuffer *buffer) {
    accelerator->addTransferToGART(buffer);
    accelerator->freeToAllocGART(this, nullptr, nullptr, boundSurface, sharedAllocator, buffer);
}

void IOATIR500DVDContext::map_transfer_to_GART(VendorTransferBuffer *buffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    IOATIR500Surface *excludeSurface = *reinterpret_cast<IOATIR500Surface **>(self + 0xf8);
    IOATIR500Shared *excludeShared = *reinterpret_cast<IOATIR500Shared **>(self + 0x84);
    accelerator->addTransferToGART(buffer);
    accelerator->freeToAllocGART(nullptr, this, nullptr, excludeSurface, excludeShared, buffer);
}
