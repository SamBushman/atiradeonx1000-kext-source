/*
 * ATIR500GLContext_WriteZDecompressAddOnPacket.cpp
 *
 * RESOLVED (issue #1, get-it-linking pass): real body for
 * `ATIR500GLContext::write_r500_zdecompress_restore_add_on_packet` -
 * real addr 0x28780. See the method's own header comment in
 * `Headers/ATIR500GLContext.h` and `r500_zdecompress_restore_add_on_
 * packet_struct`'s own header comment in `Headers/ATIRadeonX1000Types.h`
 * (a real struct-size bug fixed alongside this transcription).
 *
 * Confidence: CONFIRMED for control flow and every real offset/literal
 * constant - a real, complete, standalone decompile.
 */

#include "../Headers/ATIR500GLContext.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Registers.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

/* (re-ported mechanically: see ATIR500GLContext_write_r500_zdecompress_restore_add_on_packet_Port.cpp) */

