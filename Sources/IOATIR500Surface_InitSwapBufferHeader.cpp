/* NOTE 2026-09-19: 1 function body formerly in this file has been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * IOATIR500Surface_InitSwapBufferHeader.cpp
 *
 * RESOLVED (issue #37): `IOATIR500Surface::init_swap_buffer_header`'s
 * real body, real addr 0x10b40.
 *
 * Real body: zeroes the first real 0x20 bytes of `header` (8 dwords,
 * `header+0x00` through `header+0x1c`), then sets `header+0x1c` to `1`
 * (a real "initialized"/valid flag, overwriting one of the just-zeroed
 * dwords - transcribed exactly as decompiled, not simplified to "zero 7
 * dwords then set the 8th"), and `header+0x10` to a real dword count,
 * `(size - 0x20) / 4` (the buffer's own usable size, excluding this
 * 0x20-byte header itself, expressed in dwords rather than bytes -
 * matches this project's established convention of storing PM4-relevant
 * sizes as dword counts elsewhere, e.g.
 * `restore_state_destroyed_by_pageoff`).
 *
 * `VendorSwapBufferHeader`'s own real layout remains otherwise
 * unreconstructed (opaque, per `Headers/IOATIR500Surface.h`) - only the
 * two real fields this function itself touches (`+0x10`, `+0x1c`) are
 * confirmed here.
 *
 * Confidence: CONFIRMED for control flow and every real offset - simple,
 * unambiguous byte-offset arithmetic on an intentionally opaque struct
 * pointer (Ghidra's own C decompile has no sizeof to get wrong here,
 * same as this project's other opaque-struct functions). No C++
 * compiler was available in the sandboxed environment this was written
 * in (same standing limitation as every other file in this project).
 */

#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000Types.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

/* (re-ported mechanically: see IOATIR500Surface_init_swap_buffer_header_Port.cpp) */

