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

void IOATIR500Surface::freeAllSwapBuffers(UInt32 param1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *accel = *reinterpret_cast<UInt8 **>(self + 0xd50);

    if (W(accel, param1 * 4 + 0x114) != 0) {
        UInt32 recordBase = param1 * 0x94;
        UInt32 idx = 0;
        UInt32 counter = 0;
        do {
            UInt32 accumBefore = W(accel, 0x788);
            idx = H(self, recordBase + 0xcae) + counter;
            counter++;
            UInt32 delta = reinterpret_cast<ATIRadeonX1000 *>(accel)->waitForTimeStamp(
                W(self, idx * 0x1c + recordBase + 0xc4c));
            W(accel, 0x788) = accumBefore + delta;
            accel = *reinterpret_cast<UInt8 **>(self + 0xd50);
        } while (counter < W(accel, param1 * 4 + 0x114));

        if (W(accel, param1 * 4 + 0x114) != 0) {
            UInt8 *base = self + recordBase;
            UInt32 n = 0;
            UInt8 *pIVar7 = self + recordBase + 0xc20;
            UInt8 *pIVar5 = base + 0xc40;
            UInt8 *pIVar6 = base + 0xc30;
            do {
                UInt8 *pIVar10 = pIVar6 + 0x10;
                UInt8 *pIVar12 = pIVar5 + 0xc;
                UInt32 slot = 0;
                UInt8 *pIVar8 = base + 0xc3c;
                bool more;
                do {
                    if (W(pIVar10, 0) != 0) {
                        accel = *reinterpret_cast<UInt8 **>(self + 0xd50);
                        reinterpret_cast<ATIRadeonX1000 *>(accel)->removeTransferFromGART(
                            reinterpret_cast<VendorTransferBuffer *>(pIVar8));
                    }
                    void *obj = *reinterpret_cast<void **>(pIVar10 + 4);
                    if (obj != nullptr) {
                        typedef void (*ReleaseFn)(void *);
                        (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(obj) + (0x18 / 4)))(obj);
                    }
                    more = (slot != 3);
                    pIVar8 += 0x1c;
                    W(pIVar10, -4) = 0;
                    W(pIVar10, 0) = 0;
                    slot++;
                    W(pIVar10, 4) = 0;
                    H(pIVar10, 10) = 0;
                    H(pIVar10, 8) = 2;
                    W(pIVar12, 0) = 0;
                    W(pIVar12, 4) = 0;
                    W(pIVar12, 8) = 0;
                    pIVar10 += 0x1c;
                    pIVar12 += 0x1c;
                } while (more);

                void *obj7 = *reinterpret_cast<void **>(pIVar7 + 8);
                if (obj7 != nullptr) {
                    typedef void (*ReleaseFn)(void *);
                    (*reinterpret_cast<ReleaseFn *>(*reinterpret_cast<void ***>(obj7) + (0x18 / 4)))(obj7);
                }
                H(pIVar7, 0xc) = 2;
                H(pIVar7, 0xe) = 0;
                n++;
                base += 0x1c;
                W(pIVar7, 0x18) = 0;
                W(pIVar7, 0) = 0;
                W(pIVar7, 4) = 0;
                W(pIVar7, 8) = 0;
                W(pIVar7, 0x10) = 0;
                W(pIVar7, 0x14) = 0;
                pIVar6 += 0x1c;
                pIVar5 += 0x1c;
                pIVar7 += 0x1c;
            } while (n < W(*reinterpret_cast<UInt8 **>(self + 0xd50), param1 * 4 + 0x114));
        }
    }

    W(self, param1 * 0x94 + 0xcb0) = 0;
}

bool IOATIR500Surface::allocMasterSwapBuffer(UInt32 param1, UInt32 param2) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt32 recordBase = param1 * 0x94;
    W(self, recordBase + 0xcb0) = 0;

    UInt8 *accel = *reinterpret_cast<UInt8 **>(self + 0xd50);
    if (W(accel, param1 * 4 + 0x114) != 0) {
        UInt32 count = 0;
        UInt8 *slot = self + recordBase + 0xc28;
        do {
            void *memHandle = FUN_000119e0(W(accel, 0x82c) | 0x10023, param2, kernelPageSize);
            *reinterpret_cast<void **>(slot) = memHandle;
            if (memHandle == nullptr) {
                return false;
            }
            count++;
            typedef VendorSwapBufferHeader *(*GetHeaderFn)(void *);
            VendorSwapBufferHeader *header = (*reinterpret_cast<GetHeaderFn *>(
                *reinterpret_cast<void ***>(memHandle) + (0x1cc / 4)))(memHandle);
            *reinterpret_cast<VendorSwapBufferHeader **>(slot + 0xc) = header;
            slot += 0x1c;
            init_swap_buffer_header(header, param2);
            accel = *reinterpret_cast<UInt8 **>(self + 0xd50);
        } while (count < W(accel, param1 * 4 + 0x114));
    }

    W(self, recordBase + 0xcb0) = param2;
    return true;
}
