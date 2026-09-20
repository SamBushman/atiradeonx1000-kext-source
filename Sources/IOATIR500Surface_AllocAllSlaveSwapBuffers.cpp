/* NOTE 2026-09-19: 1 function body formerly in this file has been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * IOATIR500Surface_AllocAllSlaveSwapBuffers.cpp
 *
 * RESOLVED (issue #28), failure-path infinite loop CONFIRMED as a real
 * driver bug (follow-up investigation): `IOATIR500Surface::
 * allocAllSlaveSwapBuffers`'s real body, real addr 0x11e50. By far the
 * densest of issue #28's targets - transcribed as literally as possible
 * (preserving the real decompile's own `goto`s rather than
 * force-restructuring it).
 *
 * Real per-panel-side (`param_1`) slave-swap-buffer allocation: for each
 * of up to 4 buffers, allocates a real `IOBufferMemoryDescriptor` (via
 * `FUN_00012034`, RESOLVED issue #27:
 * `IOBufferMemoryDescriptor::withOptions`) sized `param_2`, stores it
 * into a per-slot pointer array (`this+param_1*0x94+0xc44`, stride
 * `0x1c`), gets its real hardware-mappable header via its own vtable
 * `+0x1cc` (an Apple `IOBufferMemoryDescriptor`-family method this
 * project does not reverse-engineer further) into a second parallel
 * array (`this+param_1*0x94+0xc50`), and initializes it via
 * `init_swap_buffer_header` (a real, previously-undeclared name this
 * pass surfaced - own body not independently decompiled). Real loop
 * bound: `*(uint*)(this+0xd50's own +0x114)` (an accelerator-owned real
 * count, role UNKNOWN beyond this use).
 *
 * On an allocation failure partway through (`FUN_00012034` returns
 * null): if fewer than 4 buffers were successfully allocated THIS PASS,
 * jumps into a real cleanup block that walks a THIRD per-slot array
 * (`this+param_1*0x94+0xc30`/`+0xc40`, stride `0x1c`) releasing
 * (`vtable+0x18` - `OSObject::release()`, RESOLVED issue #20) and
 * zeroing every populated entry - real per-record fields at
 * `record-0x20`/`record-0x10`/`record` (three dwords) and a matching
 * second-array triple, plus two `UInt16` fields at `+0x18`/`+0x16`
 * (real values `2`/`0`, role UNKNOWN) - counting up to the SAME real
 * `+0x114` bound. If 4 or more buffers had already succeeded before the
 * failure, returns `1` immediately instead (a real "good enough, treat
 * as success" tolerance this project has not seen an explanation for
 * beyond the literal decompile).
 *
 * FOLLOW-UP INVESTIGATION, CONFIRMED: the apparent infinite loop at the
 * end of the cleanup block is real, not a transcription error. Traced
 * the complete raw PPC instruction sequence from function entry through
 * every register (`r27`=`boundBase` and `r11`=`accel`, the two operands
 * of the re-tested `+0x114` condition, are EACH set exactly once - `r27`
 * at function entry, `r11` from `this+0xd50` - and NOTHING in this
 * function's own code, including the entire cleanup block, ever writes
 * to memory at `accel+boundBase+0x114`). The decrement-and-jump-back at
 * the end of the cleanup block (`goto retest_condition` below) has NO
 * conditional guard at all in the real disassembly - a bare unconditional
 * branch. Since the re-tested condition is provably invariant within a
 * single call, this is a genuine infinite loop in Apple's own compiled
 * driver whenever this exact failure path is reached (`FUN_00012034`/
 * `IOBufferMemoryDescriptor::withOptions` returning null) - almost
 * certainly a real, latent bug that goes untriggered in practice because
 * this specific allocation call essentially never fails for real
 * callers (kernel buffer-descriptor allocation failure paths are a
 * well-known under-tested corner in shipped drivers generally). This
 * project transcribes the real compiled behavior faithfully rather than
 * "fixing" a bug that was never ours to fix - if this function is ever
 * exercised on real hardware with a forced allocation failure, expect a
 * real hang, matching the vendor driver's own real behavior.
 *
 * Confidence: CONFIRMED for the ENTIRE function, including the
 * failure/cleanup path's own real (non-)termination - cross-checked
 * against raw PPC disassembly instruction-by-instruction, not just
 * Ghidra's own C decompile, given this function's density and the
 * seriousness of the anomaly. No C++ compiler was available in the
 * sandboxed environment this was written in (same standing limitation as
 * every other file in this project).
 */

#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"

extern "C" void *FUN_00012034(UInt32 options, UInt32 capacity, int task) asm("__ZN24IOBufferMemoryDescriptor11withOptionsEmjj");
extern "C" int kernelPageSize asm("_page_size"); /* kernel page_size (0x1000). Ghidra labels every zero-immediate data relocation in this kext "_ASICSupportsAGP"; the real target of each site comes from the Mach-O relocation table (issue #58 follow-up) */

namespace {
inline UInt8 *ByteAt(void *base, int offset) { return reinterpret_cast<UInt8 *>(base) + offset; }
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

/* (re-ported mechanically: see IOATIR500Surface_allocAllSlaveSwapBuffers_Port.cpp) */

