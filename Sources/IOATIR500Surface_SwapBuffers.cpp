/*
 * IOATIR500Surface_SwapBuffers.cpp
 *
 * RESOLVED (issue #31): `IOATIR500Surface::freeAllSwapBuffers` (real
 * addr 0x10860) and `IOATIR500Surface::allocMasterSwapBuffer` (real addr
 * 0x118e0) - the real counterpart/sibling to the already-RESOLVED
 * `allocAllSlaveSwapBuffers` (issue #28,
 * `Sources/IOATIR500Surface_AllocAllSlaveSwapBuffers.cpp`), all three
 * called together from `setup_stereo`'s own live-surface notification
 * loop (`Sources/IOATIR500Accelerator_SetupStereo.cpp`).
 *
 * `allocMasterSwapBuffer`: allocates a real per-panel (`param1`) "master"
 * swap buffer array (real per-index `IOBufferMemoryDescriptor`, real
 * per-slot record at `this+param1*0x94+0xc28`, stride `0x1c` - pointer
 * at `+0`, real hardware-mappable header at `+0xc`), looping up to the
 * SAME real accelerator-owned bound `allocAllSlaveSwapBuffers` already
 * uses (`accel+param1*4+0x114`). Zeroes a real "current size" field
 * (`this+param1*0x94+0xcb0`) at entry and stores the real requested size
 * there on success - the SAME real field `freeAllSwapBuffers` clears at
 * its own end, a nice cross-confirmation of both functions' real roles.
 *
 * `freeAllSwapBuffers`: the real inverse. First, for every already-
 * allocated slot up to the real bound, calls `waitForTimeStamp` on a
 * real per-slot stamp field (`this+idx*0x1c+param1*0x94+0xc4c`, `idx`
 * itself read from a real per-panel `+0xcae` UInt16 field plus a running
 * counter) and accumulates the real per-accelerator delta into a real,
 * previously-undocumented accelerator field (`accel+0x788`). Then walks
 * THREE real parallel per-slot arrays (`this+param1*0x94+0xc20`/`+0xc30`/
 * `+0xc40`, stride `0x1c`) - releasing GART mappings (`removeTransferFromGART`,
 * already RESOLVED) and real objects (vtable`+0x18` - `OSObject::
 * release()`) at each populated real sub-slot (a real fixed inner loop
 * of 4 - matches `allocAllSlaveSwapBuffers`'s own 4-buffer real cap),
 * zeroing every real field it touches. Clears `+0xcb0` at the very end
 * regardless of whether any real cleanup happened.
 *
 * Confidence: CONFIRMED for control flow and every real offset AS GIVEN
 * BY Ghidra's own C decompile (trustworthy per this project's established
 * "class-typed pointer already byte-scaled" convention, and independently
 * cross-confirmed against `allocAllSlaveSwapBuffers`'s own already-
 * disassembly-verified field layout at several shared offsets) but NOT
 * independently re-traced against raw disassembly instruction-by-
 * instruction given their density - the real per-slot `+0xcae`/`+0xc4c`
 * stamp-accumulator fields have no established role beyond this call
 * site. No C++ compiler was available in the sandboxed environment this
 * was written in (same standing limitation as every other file in this
 * project).
 */

#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"

extern "C" void *FUN_000119e0(UInt32 options, UInt32 capacity, int align) asm("__ZN24IOBufferMemoryDescriptor11withOptionsEmjj"); /* real: same external target as the project's already-RESOLVED FUN_withOptions family, issue #27 */
extern "C" int kernelPageSize asm("_page_size"); /* kernel page_size (0x1000). Ghidra labels every zero-immediate data relocation in this kext "_ASICSupportsAGP"; the real target of each site comes from the Mach-O relocation table (issue #58 follow-up) */

namespace {
inline UInt8  &B(void *p, int o)  { return *(reinterpret_cast<UInt8 *>(p) + o); }
inline UInt16 &H(void *p, int o)  { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(p) + o); }
inline UInt32 &W(void *p, int o)  { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(p) + o); }
} // namespace

/* (re-ported mechanically: see IOATIR500Surface_freeAllSwapBuffers_Port.cpp) */


/* (re-ported mechanically: see IOATIR500Surface_allocMasterSwapBuffer_Port.cpp) */

