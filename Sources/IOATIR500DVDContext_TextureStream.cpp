/*
 * IOATIR500DVDContext_TextureStream.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real bodies for
 * `IOATIR500DVDContext::add_texture_to_stream`/`remove_texture_from_
 * stream` - real addrs 0xe770/0xe750, two genuinely tiny functions.
 *
 * `add_texture_to_stream`: increments a real `short` "stream reference
 * count" field at `VendorTextureBuffer+0xe` (own name not otherwise
 * established elsewhere in this project).
 *
 * `remove_texture_from_stream`: stamps the texture's own `clientShared`
 * (`+0x14`, established throughout `IOATIR500Shared_TextureAlloc.cpp`)
 * `+8` field with `*(this+0x8c)+0x50` (a real, previously-uncatalogued
 * field on `IOATIR500DVDContext` itself - own identity/role not
 * independently investigated this pass, transcribed by raw offset),
 * then decrements the same `+0xe` stream-refcount field.
 *
 * Confidence: CONFIRMED for control flow and every real offset - two
 * real, complete, standalone decompiles.
 */

#include "../Headers/IOATIR500DVDContext.h"
#include "../Headers/ATIRadeonX1000Types.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline SInt16 &S16At(void *base, int offset) { return *reinterpret_cast<SInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

void IOATIR500DVDContext::add_texture_to_stream(VendorTextureBuffer *texture) {
    UInt8 *tex = reinterpret_cast<UInt8 *>(texture);
    S16At(tex, 0xe) += 1;
}

void IOATIR500DVDContext::remove_texture_from_stream(VendorTextureBuffer *texture) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *tex = reinterpret_cast<UInt8 *>(texture);
    UInt8 *clientShared = reinterpret_cast<UInt8 *>(U32At(tex, 0x14));
    UInt8 *dvdField = reinterpret_cast<UInt8 *>(U32At(self, 0x8c));
    U32At(clientShared, 8) = U32At(dvdField, 0x50);
    S16At(tex, 0xe) -= 1;
}
