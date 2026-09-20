/* NOTE 2026-09-19: 2 function bodies formerly in this file have been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * ATIRadeonX1000_TextureVRAM.cpp
 *
 * RESOLVED (issue #23): `ATIRadeonX1000::allocate_texture`/
 * `deallocate_texture`'s real bodies (real vtable slots `+0x528`/`+0x524`,
 * names/addresses RESOLVED issue #19). Both dispatch on a texture's own
 * real type-discriminant byte (`texture+0x20`, the same real discriminant
 * this project has already partially catalogued - see
 * `Sources/IOATIR500GLContext_TextureStream.cpp`'s own header comment).
 *
 * `allocate_texture` - real "try preferred VRAM placement strategy, fall
 * back to another" pattern for real discriminant values 3/7 (and, for
 * every OTHER value except 8, falls into the SAME real allocation path
 * with a zero requested size - transcribed exactly as found, an
 * apparent real "always attempt a (possibly zero-size) allocation
 * unless this is a type-8 texture" design). Real strategy selection:
 * checks a real "is AGP available" signal by calling through the SAME
 * real object issues #20/#24 tracked (`texture+8`, i.e. `memoryDescriptor`,
 * `ATIRadeonX1000Types.h` - RESOLVED, a real Apple `IOMemoryDescriptor`),
 * real `+0x14c`/`+0xd0`/`+0x18` call chain, `_ASICSupportsAGP` - the same
 * real global TextureLoad.cpp/DiscardBuffer.cpp already reference) - if
 * AGP is unavailable or the
 * accelerator's own VRAM budget (`this+0x84c`) already equals its cap
 * (`this+0x9c`), allocates from a real "overflow" region instead
 * (`this+0xd0`-gated choice of two different real `ATIR500Memory::alloc`
 * range arguments). Delegates the real allocation itself to the SAME
 * `ATIR500Memory` class this project found in issue #23's own earlier
 * pass (`Headers/ATIR500Memory.h`), via the accelerator's own "main" GART
 * pool (`this+0x7c`).
 *
 * `deallocate_texture` - real per-discriminant cleanup (type 3/7: a real
 * mip-array dirty-bit scan this project hasn't fully named every field
 * of, then a real vtable call at `+0x52c` on `this` with a
 * "release/evict everything" shaped `(param_1, -1, -1)` argument
 * pattern, own target not investigated; type 8: either a direct real
 * release call on a per-texture handle object at `texture+0x10`
 * (`+0x18` slot - the same real ABI-fixed-looking release pattern this
 * project has seen on several DIFFERENT real classes, not claimed to be
 * the same object as issue #20/#24's own now-resolved `IOMemoryDescriptor`
 * object), or delegates
 * to the already-known `IOATIR500Accelerator::pageOffDataBuffer`),
 * followed by a real shared tail every discriminant value reaches: two
 * `HZMEM_Free` calls (already-known function) gated on real per-texture
 * HyperZ-block-assignment fields, then unconditionally releases the
 * real backing VRAM via `ATIR500Memory::dealloc` on the same "main" GART
 * pool.
 *
 * Confidence: CONFIRMED for control flow and every field offset/literal
 * constant touched - two real, complete decompiles, not summarized.
 * Several field roles (the mip-array scan's own exact semantics,
 * `texture+0x50`/`+0x6c`/`+0x70`/`+0x72`/`+0x74`/`+0x78`/`+0x7a`) are
 * transcribed as raw offsets rather than promoted to named struct
 * fields, since neither this pass nor any earlier one has independently
 * corroborated their real roles beyond what's visible in these two
 * functions alone - consistent with this project's established practice
 * elsewhere. No C++ compiler was available in the sandboxed environment
 * this was written in (same standing limitation as every other file in
 * this project) - checked by careful, repeated manual re-reading against
 * each raw decompile instead.
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIR500Memory.h"
#include "../Headers/ATIRadeonX1000Registers.h"

extern "C" int kernelTaskRef asm("_kernel_task"); /* kernel_task pointer value; the Ghidra label "_ASICSupportsAGP" hid this real relocation target (issue #58 follow-up) */

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

/* (re-ported mechanically: see ATIRadeonX1000_allocate_texture_Port.cpp) */


/* (re-ported mechanically: see ATIRadeonX1000_deallocate_texture_Port.cpp) */

