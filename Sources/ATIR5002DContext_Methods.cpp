/* NOTE 2026-09-19: 1 function body formerly in this file has been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * ATIR5002DContext_Methods.cpp
 *
 * RESOLVED (ledger pass): the members of ATIR5002DContext (the concrete 2D context) that had no body in the rebuild,
 * transcribed from the shipped kext (real addrs in parentheses):
 *   start (0x33510, vtable +0x348)   stop (0x335e0, +0x34c)   getTargetAndMethodForIndex (0x31990, +0x594)
 *   get_buffer_info (0x319d0, +0x5b4)   set_destination (0x31b10, +0x5b0)   load_image (0x31b60): empty
 *   invalidate (0x31d10, +0x5a4)   submit_context_buffer (0x31e90, +0x5a8)
 *
 * Both start and stop take the accelerator's command lock around the (qualified) IOATIR5002DContext::start/stop
 * call. start additionally initialises the context-buffer header (this+0xac) and points this+0x120 at the
 * three-entry read_regs/write_regs/write_2_regs table (selectors 16-18).
 *
 * submit_context_buffer flushes the "last bound texture" onto the accelerator's list, switches to the other
 * half of the two-slot command-buffer pair when the pending-write batch (this+200) is dirty, copies that batch
 * into the slot's header buffer, appends the fixed 40-word PM4 packet that programs the destination surface from
 * the bound surface's buffer record (surface+0xa8, or accelerator+panel*0x78+300 when no surface is bound),
 * pads to an even word count with a 0x80000000 NOP, and submits it through ATIRadeonX1000::submit_buffer.
 * The odd-count pad word is stored at the index of the next free word (the stock decompile shows it against a
 * reused variable; the disassembly confirms this).
 */

#include "../Headers/ATIR5002DContext.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Surface.h"

extern "C" void TwoDC_lock(void *) asm("_IOLockLock");
extern "C" void TwoDC_unlock(void *) asm("_IOLockUnlock");

extern const VendorExternalMethod kTwoDRegisterMethods[3] asm("__ZZN16ATIR5002DContext5startEP9IOServiceE11methodDescs");

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
typedef SInt32 (*StampFn)(void *, UInt32);
} // namespace

bool ATIR5002DContext::start(IOService *provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    void *lock = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(provider) + 0x840);
    TwoDC_lock(lock);
    bool started = IOATIR5002DContext::start(provider);
    if (started) {
        U32At(self, 0x128) = 0;
        U32At(self, 0x124) = 0;
        U32At(reinterpret_cast<void *>(U32At(self, 0xac)), 0x1c) = 9;
        U32At(reinterpret_cast<void *>(U32At(self, 0xac)), 0x40) = 0x1000000;
        U32At(self, 0x120) = reinterpret_cast<UInt32>(kTwoDRegisterMethods);
    }
    TwoDC_unlock(lock);
    return started;
}

void ATIR5002DContext::stop(IOService *provider) {
    void *lock = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(provider) + 0x840);
    TwoDC_lock(lock);
    IOATIR5002DContext::stop(provider);
    TwoDC_unlock(lock);
}

/* selectors 0-15 index the 16-entry base table (this+0x10c), 16-18 the three-entry table at this+0x120 */
IOExternalMethod *ATIR5002DContext::getTargetAndMethodForIndex(IOService **target, UInt32 selector) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    *target = this;
    if (selector < 0x10) {
        return reinterpret_cast<IOExternalMethod *>(selector * 0x18 + U32At(self, 0x10c));
    }
    if (selector > 0x12) {
        return nullptr;
    }
    return reinterpret_cast<IOExternalMethod *>(selector * 0x18 + U32At(self, 0x120) - 0x180);
}

IOReturn ATIR5002DContext::get_buffer_info(IOATIR500Surface *surface, UInt32 index, void *info, UInt32 *infoSize) {
    UInt8 *out = reinterpret_cast<UInt8 *>(info);
    if (*infoSize != 0x30) {
        return 0xe00002c2;
    }
    UInt8 *record;
    if (surface == nullptr) {
        UInt8 *entry = reinterpret_cast<UInt8 *>(accelerator) + index * 0x78;
        record = entry + 300;
        U32At(out, 8) = U16At(entry, 0x148);
        U32At(out, 0xc) = U16At(entry, 0x14a);
        UInt32 divisor = U16At(entry, 0x144);
        SInt32 quotient2 = 0;
        UInt32 quotient = 0;
        if (divisor != 0) {
            UInt32 value = U32At(entry, 0x134) & 0x3ff;
            quotient = value / divisor;
            if (U16At(entry, 0x142) != 0) {
                quotient2 = static_cast<SInt32>(value - divisor * quotient) / static_cast<SInt32>(U16At(entry, 0x142));
            }
        }
        U32At(out, 0x14) = quotient2;
        U32At(out, 0x18) = quotient;
    } else {
        record = reinterpret_cast<UInt8 *>(U32At(surface, 0xb70));
        U32At(out, 8) = static_cast<SInt32>(static_cast<SInt16>(U16At(surface, 0xbe4)));
        SInt16 height = static_cast<SInt16>(U16At(surface, 0xbe6));
        U32At(out, 0x18) = 0;
        U32At(out, 0x14) = 0;
        U32At(out, 0xc) = static_cast<SInt32>(height);
    }
    U16At(out, 2) = 0;
    U16At(out, 0) = 0;
    U16At(out, 4) = U16At(record, 0x1c);
    U16At(out, 6) = U16At(record, 0x1e);
    U32At(out, 0x10) = U16At(record, 0x14);
    UInt16 rows = U16At(record, 0x16);
    U32At(out, 0x1c) = rows;
    U32At(out, 0x24) = U8At(record, 0x3b);
    U32At(out, 0x28) = U8At(record, 0x39);
    U32At(out, 0x2c) = U8At(record, 0x3a);
    if (rows > 1) {
        U32At(out, 0x20) = rows >> 1;
        return 0;
    }
    U32At(out, 0x20) = 1;
    return 0;
}

/* Real: a tail call into vtable +0x5b4 (get_buffer_info) with the bound surface and fallback index. */
IOReturn ATIR5002DContext::set_destination(void *info, UInt32 *infoSize) {
    return get_buffer_info(boundSurface, U32At(this, 0x110), info, infoSize);
}

void ATIR5002DContext::load_image(VendorTextureBuffer *texture) {
    (void)texture;
}

void ATIR5002DContext::invalidate() {
    U32At(reinterpret_cast<void *>(U32At(this, 200)), 0x1c) |= 1;
}

/* (re-ported mechanically: see ATIR5002DContext_submit_context_buffer_Port.cpp) */

