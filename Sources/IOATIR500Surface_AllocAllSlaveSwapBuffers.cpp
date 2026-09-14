/*
 * IOATIR500Surface_AllocAllSlaveSwapBuffers.cpp
 *
 * RESOLVED (issue #28): `IOATIR500Surface::allocAllSlaveSwapBuffers`'s
 * real body, real addr 0x11e50. By far the densest of issue #28's
 * targets - transcribed as literally as possible (preserving the real
 * decompile's own `goto`s rather than force-restructuring it) because
 * this project could NOT fully verify one part of its own control flow
 * with confidence - see the honest flag below.
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
 * HONEST FLAG, not resolved this pass: after the cleanup block's own
 * inner loop finishes, the real disassembly shows the ARRAY POINTERS
 * being decremented by `0x1c` and control jumping BACK to re-test the
 * exact same `+0x114` condition that gated entry to this whole cleanup
 * block in the first place - a real address this project has no
 * evidence changes between iterations (transcribed as reached via
 * `goto retest_condition` below). Read completely literally, this looks
 * like it could re-enter indefinitely; this project could not fully
 * confirm from static analysis alone whether some real per-call state
 * this transcription hasn't identified actually bounds it, or whether
 * this is a genuine real quirk of the compiled code. Transcribed exactly
 * as decompiled rather than "corrected" into a guessed-safe shape -
 * worth a targeted live-hardware trace before relying on this function's
 * exact failure-path behavior.
 *
 * Confidence: CONFIRMED for the real success-path control flow and every
 * real field offset/array stride (cross-checked against raw PPC
 * disassembly, not just Ghidra's own C decompile, given this function's
 * density). The failure/cleanup path's own eventual termination is
 * UNKNOWN - see the honest flag above. No C++ compiler was available in
 * the sandboxed environment this was written in (same standing
 * limitation as every other file in this project).
 */

#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"

extern "C" void *FUN_00012034(UInt32 options, UInt32 capacity, int task) asm("__ZN24IOBufferMemoryDescriptor11withOptionsEmjj");
extern "C" int _ASICSupportsAGP;

namespace {
inline UInt8 *ByteAt(void *base, int offset) { return reinterpret_cast<UInt8 *>(base) + offset; }
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

UInt32 IOATIR500Surface::allocAllSlaveSwapBuffers(UInt32 param1, UInt32 param2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    void *memHandle = nullptr;
    UInt32 successCount = 0;
    UInt32 boundBase = param1 * 4;
    UInt32 recordBase = 0;
    UInt8 *accel = *reinterpret_cast<UInt8 **>(self + 0xd50);

    for (;;) {
        if (U32At(accel + boundBase, 0x114) == 0) {
            if (memHandle == nullptr) {
                goto cleanup;
            }
        } else {
            UInt32 slotBase = recordBase + param1 * 0x94;
            UInt32 allocCount = 0;
            UInt8 *ptrSlot = self + slotBase + 0xc44;
            UInt8 *hdrSlot = self + slotBase + 0xc50;
            do {
                memHandle = FUN_00012034(U32At(accel, 0x82c) | 0x10023, param2, _ASICSupportsAGP);
                U32At(ptrSlot, 0) = reinterpret_cast<UInt32>(memHandle);
                if (memHandle == nullptr) {
                    if (successCount > 3) {
                        return 1;
                    }
                    accel = *reinterpret_cast<UInt8 **>(self + 0xd50);
                    goto cleanup;
                }
                ptrSlot = ByteAt(ptrSlot, 0x1c);
                allocCount++;

                typedef VendorSwapBufferHeader *(*GetHeaderFn)(void *);
                VendorSwapBufferHeader *header = (*reinterpret_cast<GetHeaderFn *>(*reinterpret_cast<void ***>(memHandle) + (0x1cc / 4)))(memHandle);
                U32At(hdrSlot, 0) = reinterpret_cast<UInt32>(header);
                hdrSlot = ByteAt(hdrSlot, 0x1c);
                init_swap_buffer_header(header, param2);
                accel = *reinterpret_cast<UInt8 **>(self + 0xd50);
            } while (allocCount < U32At(accel + boundBase, 0x114));
        }

        if (successCount == 3) {
            return 1;
        }
        recordBase += 0x1c;
        successCount++;
        continue;

    cleanup:
        {
            UInt32 cleanupBase = (successCount - 1) * 0x1c + param1 * 0x94;
            UInt8 *pIVar11 = self + cleanupBase + 0xc30;
            UInt8 *pIVar12 = self + cleanupBase + 0xc40;
        retest_condition:
            if (U32At(accel + boundBase, 0x114) != 0) {
                UInt8 *pIVar13 = ByteAt(pIVar11, 0x14);
                UInt8 *pIVar10 = ByteAt(pIVar12, 0xc);
                UInt32 n = 0;
                do {
                    void *obj = *reinterpret_cast<void **>(pIVar13);
                    if (obj != nullptr) {
                        typedef void (*ReleaseFn)(void *);
                        (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(obj) + (0x18 / 4)))(obj);
                    }
                    U16At(pIVar13, 6) = 0;
                    U16At(pIVar13, 4) = 2;
                    n++;
                    U32At(pIVar13, -8) = 0;
                    U32At(pIVar13, -4) = 0;
                    U32At(pIVar13, 0) = 0;
                    U32At(pIVar10, 0) = 0;
                    U32At(pIVar10, 4) = 0;
                    U32At(pIVar10, 8) = 0;
                    pIVar13 = ByteAt(pIVar13, 0x1c);
                    pIVar10 = ByteAt(pIVar10, 0x1c);
                    accel = *reinterpret_cast<UInt8 **>(self + 0xd50);
                } while (n < U32At(accel + boundBase, 0x114));
            }
            pIVar11 = ByteAt(pIVar11, -0x1c);
            pIVar12 = ByteAt(pIVar12, -0x1c);
            goto retest_condition; /* see this file's own "HONEST FLAG" header note */
        }
    }
}
