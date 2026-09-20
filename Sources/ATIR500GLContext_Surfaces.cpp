/* NOTE 2026-09-19: 2 function bodies formerly in this file have been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * ATIR500GLContext_Surfaces.cpp
 *
 * build_surface_from_texture / process_kATIGLStreamFastClearColor -
 * CONFIRMED, fully transcribed from real decompiles (kext offsets
 * 0x28200/0x292a0). The real backing for opcodes 0x45 and 0x46
 * respectively.
 */

#include "../Headers/ATIR500GLContext.h"
#include "../Headers/ATIRadeonX1000Registers.h"

namespace {
inline UInt32 &U32At(void *base, int offset) {
    return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset);
}
} // namespace

/*
 * build_surface_from_texture - CONFIRMED, fully transcribed (real kext
 * offset 0x28200, opcode 0x45's real backing function). Populates a
 * caller-owned ATIR500SurfaceBuffer record in place from a
 * VendorTextureBuffer: zeroes/defaults every field, resolves the real
 * GPU base address (via GetTextureOffset for chained/type-6 textures, or
 * directly for plain ones), copies real format/tiling bytes across, and
 * runs the same real format-table-driven tile-alignment check already
 * seen in write_kernel_context_buffer_regs/build_scissor (the
 * DAT_0004d2dc table).
 */
/* (re-ported mechanically: see ATIR500GLContext_build_surface_from_texture_Port.cpp) */


/*
 * process_kATIGLStreamFastClearColor - CONFIRMED, fully transcribed (real
 * kext offset 0x292a0, opcode 0x46 "fast clear"). Computes real per-mip
 * render-target offset/tiling values for TWO surfaces simultaneously (the
 * bound color surface at `this+0xac`'s unit index, and a second surface
 * at `this+0xae`'s unit index - plausibly a paired depth/stencil or MRT
 * target) and writes a real Type-0-header-shaped burst starting at a
 * caller-supplied dword offset (`record[1]`, confirmed to be read BEFORE
 * being overwritten - the real function uses it purely as an output
 * index, not as data).
 */
/* (re-ported mechanically: see ATIR500GLContext_process_kATIGLStreamFastClearColor_Port.cpp) */

