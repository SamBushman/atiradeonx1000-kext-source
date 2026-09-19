/*
 * ATIR500GLContext_TextureOffsets.cpp
 *
 * GetTextureOffset / WriteTextureOffset / GetVertexArrayOffset /
 * WriteVertexArrayOffset / GetQueryOffset - CONFIRMED, fully transcribed
 * from real decompiles (kext offsets 0x280c0/0x28420/0x26ed0/0x27470/
 * 0x26f60). These resolve a VendorTextureBuffer's real GPU-visible
 * address, patch that address into a pre-reserved command-stream slot
 * (the same "deferred patch" convention already fully mapped for opcodes
 * 0x37/0x38/0x39), and give vertex-attribute-buffer and occlusion-query
 * variants of the same mechanism.
 */

#include "../Headers/ATIR500GLContext.h"
#include "../Headers/IOATIR500Surface.h"

namespace {
inline UInt32 &U32At(void *base, int offset) {
    return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset);
}
} // namespace

/*
 * GetTextureOffset - CONFIRMED. Real per-type-discriminant (see
 * IOATIR500GLContext_TextureStream.cpp's note on VendorTextureBuffer+0x20)
 * address resolution:
 *   type 3 or 7 (plain/AGP-ref texture): real base + optional write-offset
 *   type 6 (chained sub-buffer): real base via the sub-buffer, only if it
 *     has a real backing (`+4 != 0`), else falls through
 *   type 0 (surface-backed): real per-mip offset via
 *     IOATIR500Surface::surface_buffer_idx_mask + the confirmed
 *     ATIR500SurfaceBuffer::mipOffsets[]/pitch fields
 *   anything else: 0
 */
/* (re-ported mechanically: see ATIR500GLContext_GetTextureOffset_Port.cpp) */


/*
 * WriteTextureOffset - CONFIRMED. Walks past any real type-1 (alias)
 * chain links first, then resolves the real base offset via
 * GetTextureOffset and patches it into TWO pre-reserved command-stream
 * slots using the same real `+0x1150`/`+0x1158` header-relative
 * convention this project has seen throughout the opcode 0x37/0x39
 * family, gated on a real per-texture format-flags dword at `+0x68`.
 */
/* (re-ported mechanically: see ATIR500GLContext_WriteTextureOffset_Port.cpp) */


/*
 * GetVertexArrayOffset - CONFIRMED. The vertex-attribute-buffer analog of
 * GetTextureOffset, confirmed to route through the SAME texture-fetch-
 * unit hardware (this project's confirmed R5xx architectural fact: vertex
 * attributes and fragment textures share fetch hardware). Real special-
 * case: `param2 == 0xffffffff` means "no offset," treated as 0.
 */
UInt32 ATIR500GLContext::GetVertexArrayOffset(VendorTextureBuffer *buffer, UInt32 param2) {
    if (buffer == nullptr) return 0;
    if (param2 == 0xffffffffu) param2 = 0;

    UInt32 kind = U32At(buffer, 0x20);
    if (kind == 7) {
        UInt32 base = U32At(buffer, 0x48);
        return base == 0 ? 0 : base + param2;
    }
    if (kind == 6) {
        void *sub = reinterpret_cast<void *>(U32At(buffer, 0x54));
        UInt32 base = U32At(sub, 4);
        if (base == 0) return 0;
        return base + param2 + U32At(buffer, 0x50) + U32At(accelerator, 0x8a4);
    }
    return 0;
}

/*
 * GetQueryOffset - CONFIRMED (GL_ARB_occlusion_query support). Real,
 * simple fixed-stride (0x20 bytes) offset computation into a query
 * result buffer, with a real base-offset choice (0x210 vs 0x10)
 * depending on `param3`.
 */
UInt32 ATIR500GLContext::GetQueryOffset(VendorTextureBuffer *buffer, UInt32 param2, UInt32 param3) {
    UInt32 base = (param3 == 0) ? (param2 * 0x20 + 0x210) : (param2 * 0x20 + 0x10);
    void *sub = reinterpret_cast<void *>(U32At(buffer, 0x54));
    return U32At(buffer, 0x50) + U32At(sub, 4) + base + U32At(accelerator, 0x8a4);
}

/*
 * WriteVertexArrayOffset - CONFIRMED, fully transcribed. Real, dense loop
 * writing 8 pairs of patched vertex-attribute offsets (2 per iteration, 4
 * iterations) into the command stream, reading two parallel per-unit
 * arrays advancing by 8 dwords each iteration - real structure preserved,
 * though the exact real meaning of the two parallel base pointers
 * (`this+4`-relative and `this`-relative, both stepping by 8 dwords) and
 * the `this+0x364`/`this+0x368` fields they reference was not
 * independently re-derived this pass (see GAPS.md).
 */
/* (re-ported mechanically: see ATIR500GLContext_WriteVertexArrayOffset_Port.cpp) */

