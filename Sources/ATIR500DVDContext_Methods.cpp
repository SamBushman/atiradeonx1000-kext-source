/*
 * ATIR500DVDContext_Methods.cpp
 *
 * RESOLVED (ledger pass): the members of ATIR500DVDContext (the concrete DVD context) that had no body in the
 * rebuild, transcribed from the shipped kext (real addrs in parentheses):
 *   start (0x34860, vtable +0x348)   stop (0x34ac0, +0x34c)   clientMemoryForType (0x352a0, +0x580)
 *   getTargetAndMethodForIndex (0x33bf0, +0x594)   invalidate (0x34100, +0x5a4)   update_surface (0x34060, +0x5a8)
 *   submit_context_buffer (0x34440, +0x5b0)   discard_command_buffer (0x33c30, +0x5b8)
 *   build_scissor (0x34020)   finish (0x340a0)
 *
 * Extra field offsets (this): +0x14c..+0x15c IDCT/scissor state (+0x150 last IDCT tag, +0x158/+0x15c scissor),
 * +0x160 the IONDRVFramebuffer for display 0, +0x164/+0x168.. luma command-buffer ping-pong (flag, buffer A at
 * +0x168, buffer B at +0x184), +0x1a0/+0x1a4.. chroma ping-pong (flag, buffer A +0x1a4, buffer B +0x1c0),
 * +0x1dc the 12-entry method table (selectors 10-21).
 */

#include "../Headers/ATIR500DVDContext.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/IOATIR500Shared.h"
#include "../Headers/ATIR500Surface.h"

extern const VendorExternalMethod kDVDSubMethods[12] asm("__ZZN17ATIR500DVDContext5startEP9IOServiceE11methodDescs");

extern "C" void DVDSubM_lock(void *) asm("_IOLockLock");
extern "C" void DVDSubM_unlock(void *) asm("_IOLockUnlock");
extern "C" SInt32 DVDSubM_OSDecrementAtomic(volatile SInt32 *address) asm("_OSDecrementAtomic");
extern "C" SInt32 DVDSubM_OSAddAtomic(SInt32 amount, volatile SInt32 *address) asm("_OSAddAtomic");
extern "C" void DVDSubM_IOGetTime(void *clock) asm("_IOGetTime");
extern "C" void *DVDSubM_safeMetaCast(void *obj, void *metaClass) asm("__ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass");
/* Site 0x348c4/0x348dc is a `lis/lwz` VALUE load of IONDRVFramebuffer::metaClass (Ghidra mislabels it `_ASICSupportsAGP`). */
extern "C" void *DVDSubM_IONDRVFramebuffer_metaClass asm("__ZN17IONDRVFramebuffer9metaClassE");

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
typedef SInt32 (*StampFn)(void *, UInt32);
} // namespace

bool ATIR500DVDContext::start(IOService *provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    void *lock = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(provider) + 0x840);
    DVDSubM_lock(lock);
    if (!IOATIR500DVDContext::start(provider)) {
        DVDSubM_unlock(lock);
        return false;
    }
    U32At(self, 0x14c) = 0;
    U32At(self, 0x150) = 0;
    U32At(self, 0x154) = 0;
    U32At(self, 0x158) = 0;
    U32At(self, 0x15c) = 0;
    U32At(self, 0x160) = reinterpret_cast<UInt32>(DVDSubM_safeMetaCast(
        reinterpret_cast<void *>(U32At(provider, 0xd4)), DVDSubM_IONDRVFramebuffer_metaClass));
    reinterpret_cast<ATIRadeonX1000 *>(provider)->start_xdct_engine();
    U32At(reinterpret_cast<void *>(U32At(self, 0xa4)), 0x1c) = 9;
    U32At(reinterpret_cast<void *>(U32At(self, 0xa4)), 0x40) = 0x1000000;
    U16At(self, 0x174) = 1;
    U16At(self, 400) = 1;
    U16At(self, 0x1b0) = 1;
    U32At(self, 0x164) = 0;
    U32At(self, 0x1a0) = 0;
    U32At(self, 0x168) = 0;
    U32At(self, 0x16c) = 0;
    U32At(self, 0x170) = 0;
    U16At(self, 0x176) = 0;
    U32At(self, 0x178) = 0;
    U32At(self, 0x17c) = 0;
    U32At(self, 0x180) = 0;
    U32At(self, 0x184) = 0;
    U32At(self, 0x188) = 0;
    U32At(self, 0x18c) = 0;
    U16At(self, 0x192) = 0;
    U32At(self, 0x194) = 0;
    U32At(self, 0x198) = 0;
    U32At(self, 0x19c) = 0;
    U32At(self, 0x1a4) = 0;
    U32At(self, 0x1a8) = 0;
    U32At(self, 0x1ac) = 0;
    U16At(self, 0x1b2) = 0;
    U32At(self, 0x1b4) = 0;
    U32At(self, 0x1b8) = 0;
    U32At(self, 0x1bc) = 0;
    U32At(self, 0x1c0) = 0;
    U32At(self, 0x1c4) = 0;
    U32At(self, 0x1c8) = 0;
    U16At(self, 0x1ce) = 0;
    U16At(self, 0x1cc) = 1;
    U32At(self, 0x1d8) = 0;
    U32At(self, 0x1d0) = 0;
    U32At(self, 0x1d4) = 0;
    if (accelerator->allocCommandBuffer(reinterpret_cast<VendorCommandBuffer *>(self + 0x168), 0x80000) &&
        accelerator->allocCommandBuffer(reinterpret_cast<VendorCommandBuffer *>(self + 0x184), 0x80000) &&
        accelerator->allocCommandBuffer(reinterpret_cast<VendorCommandBuffer *>(self + 0x1a4), 0x80000) &&
        accelerator->allocCommandBuffer(reinterpret_cast<VendorCommandBuffer *>(self + 0x1c0), 0x80000)) {
        U32At(self, 0x1dc) = reinterpret_cast<UInt32>(kDVDSubMethods);
        DVDSubM_unlock(lock);
        return true;
    }
    DVDSubM_unlock(lock);
    this->stop(provider);
    return false;
}

void ATIR500DVDContext::stop(IOService *provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    void *lock = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(provider) + 0x840);
    DVDSubM_lock(lock);
    IOATIR500DVDContext::stop(provider);
    if (U32At(self, 0x170) != 0) {
        accelerator->freeCommandBuffer(reinterpret_cast<VendorCommandBuffer *>(self + 0x168));
    }
    if (U32At(self, 0x18c) != 0) {
        accelerator->freeCommandBuffer(reinterpret_cast<VendorCommandBuffer *>(self + 0x184));
    }
    if (U32At(self, 0x1ac) != 0) {
        accelerator->freeCommandBuffer(reinterpret_cast<VendorCommandBuffer *>(self + 0x1a4));
    }
    if (U32At(self, 0x1c8) != 0) {
        accelerator->freeCommandBuffer(reinterpret_cast<VendorCommandBuffer *>(self + 0x1c0));
    }
    reinterpret_cast<ATIRadeonX1000 *>(provider)->stop_xdct_engine();
    DVDSubM_unlock(lock);
}

/* Real: types 0-3 go to IOATIR500DVDContext::clientMemoryForType; 4 and 5 hand out the luma / chroma IDCT
 * command buffers, alternating between the two buffers of each pair on every call. */
IOReturn ATIR500DVDContext::clientMemoryForType(UInt32 type, UInt32 *options, IOMemoryDescriptor **memory) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    if (type < 4) {
        return IOATIR500DVDContext::clientMemoryForType(type, options, memory);
    }
    void *lock = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accelerator) + 0x840);
    if (type == 4) {
        DVDSubM_lock(lock);
        if (U32At(self, 0x164) == 0) {
            accelerator->waitForConsumedIDCTTimeStamp(U32At(self, 0x194));
            reinterpret_cast<OSObject *>(U32At(self, 0x18c))->retain();
            *options = 0;
            *memory = reinterpret_cast<IOMemoryDescriptor *>(U32At(self, 0x18c));
            init_command_buffer_header(reinterpret_cast<VendorCommandBufferHeader *>(U32At(self, 0x198)), U32At(self, 0x19c), 0);
            U32At(reinterpret_cast<void *>(U32At(self, 0x198)), 0x18) = U32At(self, 0x150);
            U32At(self, 0x164) = 1;
        } else {
            accelerator->waitForConsumedIDCTTimeStamp(U32At(self, 0x178));
            reinterpret_cast<OSObject *>(U32At(self, 0x170))->retain();
            *options = 0;
            *memory = reinterpret_cast<IOMemoryDescriptor *>(U32At(self, 0x170));
            init_command_buffer_header(reinterpret_cast<VendorCommandBufferHeader *>(U32At(self, 0x17c)), U32At(self, 0x180), 0);
            U32At(reinterpret_cast<void *>(U32At(self, 0x17c)), 0x18) = U32At(self, 0x150);
            U32At(self, 0x164) = 0;
        }
    } else {
        if (type != 5) {
            return 0xe00002c2;
        }
        DVDSubM_lock(lock);
        if (U32At(self, 0x1a0) == 0) {
            accelerator->waitForConsumedIDCTTimeStamp(U32At(self, 0x1d0));
            reinterpret_cast<OSObject *>(U32At(self, 0x1c8))->retain();
            *options = 0;
            *memory = reinterpret_cast<IOMemoryDescriptor *>(U32At(self, 0x1c8));
            init_command_buffer_header(reinterpret_cast<VendorCommandBufferHeader *>(U32At(self, 0x1d4)), U32At(self, 0x1d8), 0);
            U32At(reinterpret_cast<void *>(U32At(self, 0x1d4)), 0x18) = U32At(self, 0x150);
            U32At(self, 0x1a0) = 1;
        } else {
            accelerator->waitForConsumedIDCTTimeStamp(U32At(self, 0x1b4));
            reinterpret_cast<OSObject *>(U32At(self, 0x1ac))->retain();
            *options = 0;
            *memory = reinterpret_cast<IOMemoryDescriptor *>(U32At(self, 0x1ac));
            init_command_buffer_header(reinterpret_cast<VendorCommandBufferHeader *>(U32At(self, 0x1b8)), U32At(self, 0x1bc), 0);
            U32At(reinterpret_cast<void *>(U32At(self, 0x1b8)), 0x18) = U32At(self, 0x150);
            U32At(self, 0x1a0) = 0;
        }
    }
    DVDSubM_unlock(lock);
    return 0;
}

/* selectors 0-9 index the 10-entry base table (this+0x100), 10-21 the 12-entry table at this+0x1dc */
IOExternalMethod *ATIR500DVDContext::getTargetAndMethodForIndex(IOService **target, UInt32 selector) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    *target = this;
    if (selector < 10) {
        return reinterpret_cast<IOExternalMethod *>(selector * 0x18 + U32At(self, 0x100));
    }
    if (selector > 0x15) {
        return nullptr;
    }
    return reinterpret_cast<IOExternalMethod *>(selector * 0x18 + U32At(self, 0x1dc) - 0xf0);
}

void ATIR500DVDContext::invalidate() {
    U32At(reinterpret_cast<void *>(U32At(this, 0xc0)), 0x1c) |= 1;
}

void ATIR500DVDContext::build_scissor() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    U32At(reinterpret_cast<void *>(U32At(self, 0xc0)), 0x1c) |= 1;
    UInt16 bottom = U16At(reinterpret_cast<void *>(U32At(self, 0xf8)), 0x576);
    UInt16 right = U16At(reinterpret_cast<void *>(U32At(self, 0xf8)), 0x574);
    U32At(self, 0x158) = 0;
    U32At(self, 0x15c) = (right & 0x3fff) | (static_cast<UInt32>(bottom & 0x3fff) << 16);
}

void ATIR500DVDContext::update_surface() {
    if (U32At(this, 0xf8) != 0) {
        build_scissor();
    }
}

/* Real: waits (accelerator vtable +0x558) for this context's last stamp; always returns 0. */
IOReturn ATIR500DVDContext::finish() {
    UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(this, 0x8c));
    UInt32 waited = U32At(accel, 0x7ac);
    SInt32 delta = (*reinterpret_cast<StampFn *>(*reinterpret_cast<UInt8 **>(accel) + 0x558))(accel, U32At(this, 0x7c));
    U32At(accel, 0x7ac) = waited + delta;
    return 0;
}

/*
 * discard_command_buffer: walk the client's record stream (this+0xa4, first record at +0x1c) and undo the texture
 * bookkeeping of every bind/unbind record without executing anything. Records are (opcode<<24 | wordCount); a
 * zero word count ends the walk.
 *   opcodes 0x19..0x2a: texture bind - resolve record[1] in the shared allocator's table, drop the reference on
 *     the texture previously held in slot (opcode-0x19), take one on the new texture, store it in the slot.
 *   opcodes 0x2b..0x3c: texture unbind - drop the slot's (opcode-0x2b) reference (deleting the texture when it
 *     was the last) and clear the slot.
 * References are OSDecrementAtomic/OSAddAtomic on the packed count at texture+0x14 -> +0x10; a bind adds
 * 0xffff0001 (one reference in the low half, minus 0xffff in the high half - same packing the stream helpers use).
 */
/* (re-ported mechanically: see ATIR500DVDContext_discard_command_buffer_Port.cpp) */


/* Real: mirror of the 2D version; see ATIR5002DContext::submit_context_buffer. The DVD variant first pulls every
 * bound texture (18 slots at +0x104) through GART mapping / the accelerator's texture lists, then appends a fixed
 * ten-word PM4 packet {0x1393,10,0xd0b,5,0x13c6,3,0x5c8,0x70000,0x1006,(accel[0xb74] & ~0x10000) | 0x10000},
 * pads a word count that is not a multiple of eight with one 0x80000000 NOP, and submits. */
/* (re-ported mechanically: see ATIR500DVDContext_submit_context_buffer_Port.cpp) */

