/*
 * IOATIR500Surface_ConvertSurfaceBits.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real body for
 * `IOATIR500Surface::convert_surface_bits` - real addr 0x12320, newly
 * exercised (and so newly required to link) by this pass's own
 * `IOATIR500GLContext::clientMemoryForType` transcription.
 *
 * Real body: converts a bitmask of buffer-TYPE-selector bits (`1 <<
 * selector`) into a bitmask of buffer-SLOT-INDEX bits, using the EXACT
 * SAME selector-to-index mapping this project's own `IOATIR500GLContext::
 * read_buffer` switch statement already establishes (cross-validated:
 * every selector value this function's own real decompile handles -
 * 0/1/2/3/4/7/8/10/11 - maps to the identical index `read_buffer`'s
 * switch produces for the same selector, plus one more, selector 16 ->
 * index 9, not otherwise seen in this project). For each set selector
 * bit, resolves the real per-format buffer-pointer-table entry
 * (`this+idx*4+0xb70`, the SAME table `write_r500_3d_blit_state_packet`/
 * `read_buffer` already establish) and converts that pointer back into
 * its own slot index within the `this+0xa8` stride-0x78 array, setting
 * the corresponding bit in the result.
 *
 * Confidence: CONFIRMED for control flow and every real offset/literal
 * constant - a real, complete, standalone decompile.
 */

#include "../Headers/IOATIR500Surface.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

UInt32 IOATIR500Surface::convert_surface_bits(UInt32 selectorBits) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt32 result = 0;
    if (selectorBits == 0) {
        return result;
    }

    UInt32 bit = 1;
    do {
        if ((bit & selectorBits) != 0) {
            int idx = -1;
            switch (bit) {
                case 0x1: idx = 1; break;
                case 0x2: idx = 0; break;
                case 0x4: idx = 4; break;
                case 0x8: idx = 5; break;
                case 0x10: idx = 6; break;
                case 0x80: idx = 2; break;
                case 0x100: idx = 3; break;
                case 0x400: idx = 7; break;
                case 0x800: idx = 8; break;
                case 0x10000: idx = 9; break;
                default: break;
            }
            if (idx >= 0) {
                UInt32 bufPtr = U32At(self, idx * 4 + 0xb70);
                UInt32 slotIndex = (bufPtr - reinterpret_cast<UInt32>(self + 0xa8)) / 0x78;
                result |= 1u << (slotIndex & 0x3f);
            }
        }
        bit <<= 1;
        if (selectorBits < bit) {
            return result;
        }
    } while (true);
}
