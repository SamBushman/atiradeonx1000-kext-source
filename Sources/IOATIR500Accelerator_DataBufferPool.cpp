/*
 * IOATIR500Accelerator_DataBufferPool.cpp
 *
 * RESOLVED: `IOATIR500Accelerator::allocDataBufferBacking`,
 * `find_surface_for_id`, `getVRAMDescriptors`, `allocCommandBuffer` -
 * four real, previously-named-but-undecompiled methods, all with
 * genuinely small/clean real bodies.
 *
 * `allocDataBufferBacking` (real addr 0x30d0): a thin real wrapper -
 * allocates via `IOBufferMemoryDescriptor::inTaskWithOptions(task=0,
 * options=0x10422, capacity=buffer's own +0x50 size field, alignment=
 * _ASICSupportsAGP)` (RESOLVED, this pass, via live kxld-resolved
 * memory read - the same real family as `IOBufferMemoryDescriptor::
 * withOptions` this project already resolved, issue #27), stores the
 * result at `buffer+8` (matches `VendorTextureBuffer::memoryDescriptor`
 * exactly), returns whether it succeeded.
 *
 * `find_surface_for_id` (real addr 0x59e0): a real linear walk of the
 * live-surface circular list (`this+0x5c`, `liveSurfaceListHead`),
 * matching on each surface's own real `+0xa4` ID field (the SAME real
 * "ID slot" field `set_id_mode` already establishes), real "next"
 * pointer at `+0x9c`.
 *
 * `getVRAMDescriptors` (real addr 0x4d20): loops calling a real,
 * previously-unknown per-index local function, `IOATIR500Accelerator::
 * getVRAMDescriptor(unsigned long)` (singular - a genuinely NEW real
 * function this pass found via the live-memory technique, its call site
 * rendered as a "local call thunk" - same real mechanism as
 * `init_swap_buffer_header`'s own caller - real addr `0x290`, own body
 * NOT decompiled this pass), once per index up to `this+0xcc`'s own
 * real count. Real success gate: count nonzero AND `this+0xe4` nonzero
 * afterward.
 *
 * `allocCommandBuffer` (real addr 0x23e0): allocates via
 * `IOBufferMemoryDescriptor::withOptions`, stores the real requested
 * size at `outBuffer+0x18`, gets a real hardware-mappable header via
 * vtable`+0x1cc` into `outBuffer+0x14`, then calls a real, previously-
 * unknown function, `IOATIR500Accelerator::init_command_buffer_header`
 * (own body not decompiled this pass - a real, already-demangled name
 * Ghidra's own symbol table already carried).
 *
 * Confidence: CONFIRMED for control flow and every real offset - four
 * real, complete, standalone decompiles. No C++ compiler was available
 * in the sandboxed environment this was written in (same standing
 * limitation as every other file in this project).
 */

#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/ATIRadeonX1000Types.h"

extern "C" void *FUN_inTaskWithOptions(void *task, UInt32 options, UInt32 capacity, int align) asm("__ZN24IOBufferMemoryDescriptor17inTaskWithOptionsEP4taskmjj");
extern "C" void *FUN_withOptions(UInt32 options, UInt32 capacity, int align) asm("__ZN24IOBufferMemoryDescriptor11withOptionsEmjj");
extern "C" int _ASICSupportsAGP;

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
} // namespace

bool IOATIR500Accelerator::allocDataBufferBacking(VendorTextureBuffer *buffer) {
    void *desc = FUN_inTaskWithOptions(nullptr, 0x10422, buffer->poolSizeClass, _ASICSupportsAGP);
    buffer->memoryDescriptor = desc;
    return desc != nullptr;
}

void *IOATIR500Accelerator::find_surface_for_id(UInt32 surfaceID) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *head = *reinterpret_cast<UInt8 **>(self + 0x5c);
    if (head == nullptr) {
        return nullptr;
    }
    UInt8 *cur = head;
    do {
        if (*reinterpret_cast<UInt32 *>(cur + 0xa4) == surfaceID) {
            return cur;
        }
        cur = *reinterpret_cast<UInt8 **>(cur + 0x9c);
    } while (cur != head);
    return nullptr;
}

bool IOATIR500Accelerator::getVRAMDescriptors(void) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt32 count = U32At(self, 0xcc);
    if (count == 0) {
        return false;
    }
    for (UInt32 i = 0; i < count; i++) {
        getVRAMDescriptor(i); /* real addr 0x290, own body not decompiled this pass */
    }
    return U32At(self, 0xcc) != 0 && U32At(self, 0xe4) != 0;
}

bool IOATIR500Accelerator::allocCommandBuffer(VendorCommandBuffer *outBuffer, UInt32 size) {
    UInt8 *buf = reinterpret_cast<UInt8 *>(outBuffer);
    void *memHandle = FUN_withOptions(*reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(this) + 0x82c) | 0x10022, size, _ASICSupportsAGP);
    *reinterpret_cast<void **>(buf + 8) = memHandle;
    if (memHandle == nullptr) {
        return false;
    }
    U32At(buf, 0x18) = size;
    typedef VendorCommandBufferHeader *(*GetHeaderFn)(void *);
    VendorCommandBufferHeader *header = (*reinterpret_cast<GetHeaderFn *>(*reinterpret_cast<void ***>(memHandle) + (0x1cc / 4)))(memHandle);
    *reinterpret_cast<VendorCommandBufferHeader **>(buf + 0x14) = header;
    init_command_buffer_header(header, size); /* real name, own body not decompiled this pass */
    return true;
}
