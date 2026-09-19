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

extern const VendorExternalMethod kTwoDRegisterMethods[3];

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

void ATIR5002DContext::submit_context_buffer() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, 0x94));

    /* flush the last bound texture onto the accelerator's texture list (+0x5dc/+0x600) */
    UInt8 *texture = reinterpret_cast<UInt8 *>(U32At(self, 0x114));
    if (texture != nullptr) {
        if (U8At(reinterpret_cast<void *>(U32At(texture, 0x14)), 0x14) != 0) {
            alloc_and_load_image(reinterpret_cast<VendorTextureBuffer *>(texture));
            texture = reinterpret_cast<UInt8 *>(U32At(self, 0x114));
        }
        if (U32At(texture, 0x48) != 0) {
            U32At(reinterpret_cast<void *>(U32At(texture, 0x24)), 0x28) = U32At(texture, 0x28);
            U32At(reinterpret_cast<void *>(U32At(reinterpret_cast<void *>(U32At(self, 0x114)), 0x28)), 0x24) = U32At(reinterpret_cast<void *>(U32At(self, 0x114)), 0x24);
            U32At(reinterpret_cast<void *>(U32At(self, 0x114)), 0x24) = U32At(accel, 0x600);
            U32At(reinterpret_cast<void *>(U32At(self, 0x114)), 0x28) = reinterpret_cast<UInt32>(accel + 0x5dc);
            U32At(accel, 0x600) = U32At(self, 0x114);
            U32At(reinterpret_cast<void *>(U32At(reinterpret_cast<void *>(U32At(self, 0x114)), 0x24)), 0x28) = U32At(self, 0x114);
        }
    }

    UInt8 *pending = reinterpret_cast<UInt8 *>(U32At(self, 200));
    UInt8 *slot;
    if ((U32At(pending, 0x1c) & 1) == 0) {
        slot = self + U32At(self, 0xfc) * 0x18;
    } else {
        UInt32 next = (U32At(self, 0xfc) + 1) & 1;
        U32At(self, 0xfc) = next;
        slot = self + next * 0x18;

        /* wait for the slot's previous submission to retire */
        UInt32 waited = U32At(accel, 0x77c);
        SInt32 delta = (*reinterpret_cast<StampFn *>(*reinterpret_cast<UInt8 **>(accel) + 0x54c))(accel, U32At(slot, 0xdc));
        U32At(accel, 0x77c) = waited + delta;

        /* copy the pending batch's 32-byte header, then its `count` payload words, into the slot's buffer */
        UInt8 *dst = reinterpret_cast<UInt8 *>(U32At(slot, 0xe0));
        pending = reinterpret_cast<UInt8 *>(U32At(self, 200));
        for (int i = 0; i < 8; ++i) {
            U32At(dst, i * 4) = U32At(pending, i * 4);
        }
        UInt32 count = U32At(pending, 0x14);
        UInt8 *words = dst + 0x20;
        for (UInt32 i = 0; i < count; ++i) {
            U32At(words, i * 4) = U32At(pending, 0x20 + i * 4);
        }

        /* destination surface record */
        UInt8 *record;
        if (U32At(self, 0x100) == 0) {
            record = reinterpret_cast<UInt8 *>(U32At(self, 0x110) * 0x78 + U32At(self, 0x94) + 300);
        } else {
            record = reinterpret_cast<UInt8 *>(U32At(self, 0x100) + 0xa8);
        }
        UInt8 flagsByte = U8At(record, 0x38);
        UInt32 base = U32At(record, 8);
        UInt32 packet[0x28];
        packet[0] = 0x1393;   packet[1] = 10;
        packet[2] = 0xd0b;    packet[3] = 5;
        packet[4] = 0x13c6;   packet[5] = 3;
        packet[6] = 0x5c8;    packet[7] = 0x70000;
        packet[8] = 0x1006;   packet[9] = U32At(accel, 0xb74);
        packet[10] = 0x1008;  packet[11] = 0;
        packet[12] = 0x1380;  packet[13] = 0;
        packet[14] = 0x13c7;  packet[15] = 0;
        packet[16] = 0x10e9;  packet[17] = 0;
        packet[18] = 0x13de;  packet[19] = 0;
        packet[20] = 0x13ad;  packet[21] = 0;
        packet[22] = 0x105bb; packet[23] = 0;
        packet[24] = (static_cast<UInt32>(U16At(record, 0x1e)) << 16) | U16At(record, 0x1c);
        packet[25] = 0x11004;
        packet[26] = 0x66666666;
        packet[27] = 0x6666666;
        packet[28] = 0x5b8;
        packet[29] = (flagsByte < 2 ? 0 : 0x80000000u) | (base >> 10) |
                     ((static_cast<UInt32>(U16At(record, 0x18)) & 0x3fc0) << 16) |
                     (static_cast<UInt32>(flagsByte & 1) << 0x1e);
        packet[30] = 0x138a;
        packet[31] = base & 0xffffffe0;
        packet[32] = 0x138e;
        packet[33] = (U16At(record, 0x14) & 0x3ffe) | (static_cast<UInt32>(flagsByte & 1) << 0x10) |
                     (static_cast<UInt32>(flagsByte & 6) << 0x10) |
                     (static_cast<UInt32>(U8At(record, 0x39) & 3) << 0x13) |
                     (static_cast<UInt32>(U8At(record, 0x3b) & 0xf) << 0x15);
        packet[34] = 0xd0a;   packet[35] = 0x100;
        packet[36] = 0x1383;  packet[37] = 0xf;
        packet[38] = 0x1386;  packet[39] = 0;
        for (int i = 0; i < 0x28; ++i) {
            U32At(dst + 0x20, (count + i) * 4) = packet[i];
        }
        UInt32 total = count + 0x28;
        if ((total & 1) != 0) {
            U32At(dst + 0x20, total * 4) = 0x80000000;
            total += 1;
        }
        U32At(dst, 0x14) = total;
        U32At(reinterpret_cast<void *>(U32At(self, 200)), 0x1c) &= 0xfffffffe;
    }

    if (U32At(slot, 0xd0) == 0) {
        map_transfer_to_GART(reinterpret_cast<VendorTransferBuffer *>(slot + 0xcc));
    }
    UInt8 *buffer = reinterpret_cast<UInt8 *>(U32At(slot, 0xe0));
    U32At(reinterpret_cast<void *>(U32At(self, 0x94)), 0x700) += U32At(buffer, 0x14) * 4;
    UInt32 stamp = reinterpret_cast<ATIRadeonX1000 *>(U32At(self, 0x94))->submit_buffer(
        reinterpret_cast<UInt32 *>(buffer + 0x20), U32At(slot, 0xd0) + 0x20, U32At(buffer, 0x14));
    U32At(slot, 0xdc) = stamp;
    U32At(self, 0x7c) = stamp;
}
