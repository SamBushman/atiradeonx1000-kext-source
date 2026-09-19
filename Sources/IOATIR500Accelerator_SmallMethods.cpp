/*
 * IOATIR500Accelerator_SmallMethods.cpp
 *
 * RESOLVED (ledger pass): the small IOATIR500Accelerator members that had no body in the rebuild, transcribed from the
 * shipped kext (real addrs in parentheses):
 *   ASICSupportsAGP (0x0; a second copy of the identical body sits at 0x19ad0, the inherited vtable entry of
 *   ATIRadeonX1000): returns true            is_idle (0x5410)  pageoff_dirty_texture (0x34a0): empty
 *   setup2D (0x25d0)  teardown2D (0x2310)     makeGARTEntry (0x3670): returns its argument
 *   synchronizeGART (0x53e0): empty           flush_memory_for_in/out(IOMemoryDescriptor*, ...) (0x5400/0x53f0): empty
 *   set_stereo (0x5450): kIOReturnUnsupported getAccelCapsBits (0x5a10): 0
 *   system_will_sleep (0x6540) / system_did_wake (0x5960): flip the "asleep" byte (this+0x83) under the command lock
 *   requestProbe (0x6320): with bit 0 set rescans the framebuffers under the command lock
 *   commitAGPMemory (0x5160) / releaseAGPMemory (0x5190): tail calls into the AGP provider's vtable +0x5ec / +0x5f0
 *   reserveInGART (0x51c0) / clearInGART (0x5200): claim / release a GART page slot (this+0x83c table)
 *   flush_memory_for_in/out(const void*, unsigned long) (0x6270/0x62c0): cache flush of a range by cache-line size
 *   timers/collectors (0x4a50 0x4ce0 0x63b0 0x6440): the two software-only "garbage collector" event sources
 * Field offsets: this+0x50 current stamp, +0x74 provider, +0x80 hardware up, +0x83 asleep, +0x84 cache-line size,
 * +0x88/+0x89 collector state, +0x8c/+0x90/+0x94 collector interval/timeout, +0x98 flags, +0xa0/+0xa4 wired bytes /
 * cache size, +0xb4 workloop, +0xb8/+0xbc garbage collector timer/source, +0xc0/+0xc4 GART collector timer/source,
 * +0xc8 open-notification count, +0x83c GART page table, +0x844 empty entry, +0x848 reserved entry, +0x840 command lock.
 */

#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h"
#include "../Headers/GhidraExterns.h"

extern "C" void SmallM_lock(void *) asm("_IOLockLock");
extern "C" void SmallM_unlock(void *) asm("_IOLockUnlock");

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
typedef IOReturn (*AGPFn)(void *, void *, UInt32, UInt32);
}

bool IOATIR500Accelerator::ASICSupportsAGP() {
    return true;
}

bool IOATIR500Accelerator::is_idle() {
    return checkForTimeStamp(U32At(this, 0x50) - 1);
}

void IOATIR500Accelerator::pageoff_dirty_texture(VendorTextureBuffer *, SInt32, SInt32) {
}

UInt32 IOATIR500Accelerator::setup2D(void) {
    return allocMoreCommandBuffers(1, 0x1000);
}

void IOATIR500Accelerator::teardown2D(void) {
    freeAllCommandBuffers(1);
}

UInt32 IOATIR500Accelerator::makeGARTEntry(UInt32 physicalAddress) {
    return physicalAddress;
}

void IOATIR500Accelerator::synchronizeGART(UInt32, UInt32) {
}

void IOATIR500Accelerator::flush_memory_for_out(IOMemoryDescriptor *, UInt32, UInt32) {
}

void IOATIR500Accelerator::flush_memory_for_in(IOMemoryDescriptor *, UInt32, UInt32) {
}

IOReturn IOATIR500Accelerator::set_stereo(UInt32, UInt32) {
    return 0xe00002c7;
}

UInt32 IOATIR500Accelerator::getAccelCapsBits() {
    return 0;
}

void IOATIR500Accelerator::system_will_sleep() {
    SmallM_lock(reinterpret_cast<void *>(U32At(this, 0x840)));
    if (U8At(this, 0x83) == 0) {
        U8At(this, 0x83) = 1;
    }
    SmallM_unlock(reinterpret_cast<void *>(U32At(this, 0x840)));
}

void IOATIR500Accelerator::system_did_wake() {
    SmallM_lock(reinterpret_cast<void *>(U32At(this, 0x840)));
    if (U8At(this, 0x83) != 0) {
        U8At(this, 0x83) = 0;
    }
    SmallM_unlock(reinterpret_cast<void *>(U32At(this, 0x840)));
}

IOReturn IOATIR500Accelerator::requestProbe(UInt32 options) {
    if ((options & 1) == 0) {
        return 0xe00002c7;
    }
    SmallM_lock(reinterpret_cast<void *>(U32At(this, 0x840)));
    findFramebuffers();
    SmallM_unlock(reinterpret_cast<void *>(U32At(this, 0x840)));
    return 0;
}

/* Real: tail calls into the AGP provider (this+0x74) vtable +0x5ec / +0x5f0 with the caller's own arguments. */
IOReturn IOATIR500Accelerator::commitAGPMemory(IOMemoryDescriptor *memory, UInt32 agpOffset, UInt32 options) {
    void *provider = reinterpret_cast<void *>(U32At(this, 0x74));
    return (*reinterpret_cast<AGPFn *>(*reinterpret_cast<UInt8 **>(provider) + 0x5ec))(provider, memory, agpOffset, options);
}

IOReturn IOATIR500Accelerator::releaseAGPMemory(IOMemoryDescriptor *memory, UInt32 agpOffset, UInt32 options) {
    void *provider = reinterpret_cast<void *>(U32At(this, 0x74));
    return (*reinterpret_cast<AGPFn *>(*reinterpret_cast<UInt8 **>(provider) + 0x5f0))(provider, memory, agpOffset, options);
}

/* GART page slot (this+0x83c): 0x844 marks a free slot; reserving stores the "reserved" entry from 0x848 */
bool IOATIR500Accelerator::reserveInGART(UInt32 gartOffset) {
    UInt32 *table = reinterpret_cast<UInt32 *>(U32At(this, 0x83c));
    UInt32 index = gartOffset >> (GH_page_shift & 0x3f);
    bool wasFree = table[index] == U32At(this, 0x844);
    if (wasFree) {
        table[index] = U32At(this, 0x848);
    }
    return wasFree;
}

void IOATIR500Accelerator::clearInGART(UInt32 gartOffset) {
    reinterpret_cast<UInt32 *>(U32At(this, 0x83c))[gartOffset >> (GH_page_shift & 0x3f)] = U32At(this, 0x844);
}

/* Real: flush the cache lines covering [address, address+length): dcbf every line but the last, then the last line */
void IOATIR500Accelerator::flush_memory_for_in(const void *address, UInt32 length) {
    UInt32 line = U8At(this, 0x84);
    UInt32 base = reinterpret_cast<UInt32>(address);
    SInt32 offset = 0;
    SInt32 limit = static_cast<SInt32>(((base & (line - 1)) + length) - line);
    if (0 < limit) {
        do {
            dataCacheBlockFlush((-line & base) + offset);
            offset += line;
        } while (offset < limit);
    }
    dataCacheBlockFlush((-line & base) + offset);
    __asm__ __volatile__("sync" : : : "memory");
    instructionSynchronize();
}

void IOATIR500Accelerator::flush_memory_for_out(const void *address, UInt32 length) {
    UInt32 line = U8At(this, 0x84);
    UInt32 base = reinterpret_cast<UInt32>(address);
    SInt32 offset = 0;
    SInt32 limit = static_cast<SInt32>(((base & (line - 1)) + length) - line);
    if (0 < limit) {
        do {
            dataCacheBlockStore((-line & base) + offset);
            offset += line;
        } while (offset < limit);
    }
    __asm__ __volatile__("sync" : : : "memory");
    instructionSynchronize();
    dataCacheBlockFlush((-line & base) + offset);
    __asm__ __volatile__("sync" : : : "memory");
    instructionSynchronize();
    instructionSynchronize();
}

/* The event-source callbacks: owner is the accelerator. The timers just re-fire their event source's interrupt
 * (IOEventSource-level vtable +0x130); the collectors run the deferred reclamation under the command lock. */
void IOATIR500Accelerator::garbage_collector_timer(OSObject *owner, IOTimerEventSource *) {
    void *source = reinterpret_cast<void *>(U32At(owner, 0xbc));
    typedef void (*TriggerFn)(void *, UInt32, UInt32, UInt32);
    (*reinterpret_cast<TriggerFn *>(*reinterpret_cast<UInt8 **>(source) + 0x130))(source, 0, 0, 0);
}

void IOATIR500Accelerator::gart_collector_timer(OSObject *owner, IOTimerEventSource *) {
    void *source = reinterpret_cast<void *>(U32At(owner, 0xc4));
    typedef void (*TriggerFn)(void *, UInt32, UInt32, UInt32);
    (*reinterpret_cast<TriggerFn *>(*reinterpret_cast<UInt8 **>(source) + 0x130))(source, 0, 0, 0);
}

void IOATIR500Accelerator::garbage_collector(OSObject *owner, IOInterruptEventSource *, int) {
    IOATIR500Accelerator *accelerator = reinterpret_cast<IOATIR500Accelerator *>(owner);
    SmallM_lock(reinterpret_cast<void *>(U32At(owner, 0x840)));
    U8At(owner, 0x82) = 0;
    accelerator->freeOrphanTexture(false);
    SmallM_unlock(reinterpret_cast<void *>(U32At(owner, 0x840)));
}

void IOATIR500Accelerator::gart_collector(OSObject *owner, IOInterruptEventSource *, int) {
    IOATIR500Accelerator *accelerator = reinterpret_cast<IOATIR500Accelerator *>(owner);
    if (U32At(owner, 200) == 0) {
        SmallM_lock(reinterpret_cast<void *>(U32At(owner, 0x840)));
        if (U32At(owner, 0xa4) < U32At(owner, 0xa0)) {
            accelerator->free_gart_wirings();
        }
        U8At(owner, 0x88) = 0;
        if (U8At(owner, 0x89) != 0) {
            void *timer = reinterpret_cast<void *>(U32At(owner, 0xc0));
            typedef void (*ScheduleFn)(void *, UInt32);
            (*reinterpret_cast<ScheduleFn *>(*reinterpret_cast<UInt8 **>(timer) + 300))(timer, U32At(owner, 0x8c));
            U8At(owner, 0x89) = 0;
            U8At(owner, 0x88) = 1;
        }
        SmallM_unlock(reinterpret_cast<void *>(U32At(owner, 0x840)));
    } else {
        U8At(owner, 0x89) = 0;
        U8At(owner, 0x88) = 0;
    }
}
