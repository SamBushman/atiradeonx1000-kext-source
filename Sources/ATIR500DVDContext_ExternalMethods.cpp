/*
 * ATIR500DVDContext_ExternalMethods.cpp
 *
 * RESOLVED (issue #59 / #42): real bodies for the DVD subclass's simple external methods (real addrs):
 *   show_buffer (0x34bd0)  dvd_setup_overlay (0x34d50)  dvd_enable_overlay (0x34f30)
 *   dvd_setup_subpicture (0x34e50)  dvd_enable_deint (0x34c90)  setup_buffers (0x34260)
 *   read_regs (0x35120)  write_regs (0x35200)  wait_for_stamps (0x34120)  check_stamps (0x341a0)
 * (doIDCT and set_macrovision are in their own files.)
 *
 * The overlay/subpicture/deinterlace wrappers all share one shape: take the accelerator's command
 * lock, return kIOReturnNotReady (0xe00002d8) if the hardware is not up (accelerator+0x80 == 0),
 * kIOReturnError (0xe00002bc) if no surface is bound (this+0xf8 == NULL), otherwise forward to the
 * bound ATIR500Surface. Because of that NULL check they are SAFE on a fresh connection, unlike
 * set_macrovision / write_buffer, which lack it (issue #43).
 *
 * read_regs / write_regs touch real hardware registers through the accelerator's MMIO window
 * (accelerator+0x860, register offset masked with 0x1ffc), under the command lock.
 *
 * Confidence: CONFIRMED for control flow and offsets - short, complete decompiles.
 */

#include "../Headers/ATIR500DVDContext.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIR500Surface.h"

extern "C" void DVDSub_lock(void *) asm("_IOLockLock");
extern "C" void DVDSub_unlock(void *) asm("_IOLockUnlock");

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt32 SwapLE32(UInt32 v) {
    return ((v & 0x000000ffu) << 24) | ((v & 0x0000ff00u) << 8) | ((v & 0x00ff0000u) >> 8) | ((v & 0xff000000u) >> 24);
}
typedef SInt32 (*Fn2)(void *, UInt32);
inline SInt32 CallAccel(void *accel, int slot, UInt32 arg) {
    void **vtable = *reinterpret_cast<void ***>(accel);
    return (*reinterpret_cast<Fn2 *>(vtable + (slot / 4)))(accel, arg);
}
/* Shared shape of the guarded wrappers: returns 0 when the surface forward should run. */
inline IOReturn GuardCheck(void *accel, void *surface) {
    if (U8At(accel, 0x80) == 0) {
        return 0xe00002d8;
    }
    if (surface == nullptr) {
        return 0xe00002bc;
    }
    return 0;
}
} // namespace

IOReturn ATIR500DVDContext::show_buffer(int bufferIndex, int param2) {
    void *lock = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accelerator) + 0x840);
    DVDSub_lock(lock);
    IOReturn result = GuardCheck(accelerator, boundSurface);
    if (result == 0) {
        boundSurface->showbuffer(bufferIndex, param2);
    }
    DVDSub_unlock(lock);
    return result;
}

IOReturn ATIR500DVDContext::dvd_setup_overlay(int x, int y, int w, int h, int param5) {
    void *lock = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accelerator) + 0x840);
    DVDSub_lock(lock);
    IOReturn result = GuardCheck(accelerator, boundSurface);
    if (result == 0) {
        UInt8 *surface = reinterpret_cast<UInt8 *>(boundSurface);
        U32At(surface, 0xda4) = param5;
        if (param5 == 0) {
            U8At(surface, 0xbed) = 1;
            U8At(surface, 0xbee) = 1;
        }
        boundSurface->dvd_setup_overlay(x, y, w, h);
    }
    DVDSub_unlock(lock);
    return result;
}

IOReturn ATIR500DVDContext::dvd_enable_overlay(int enable) {
    void *lock = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accelerator) + 0x840);
    DVDSub_lock(lock);
    IOReturn result = GuardCheck(accelerator, boundSurface);
    if (result == 0) {
        if (enable == 0) {
            boundSurface->disable_overlay();
        } else {
            boundSurface->enable_overlay();
        }
    }
    DVDSub_unlock(lock);
    return result;
}

IOReturn ATIR500DVDContext::dvd_setup_subpicture(int param1, int param2, int param3, int param4) {
    void *lock = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accelerator) + 0x840);
    DVDSub_lock(lock);
    IOReturn result = GuardCheck(accelerator, boundSurface);
    if (result == 0) {
        boundSurface->dvd_setup_subpicture(param1, param2, param3, param4);
    }
    DVDSub_unlock(lock);
    return result;
}

IOReturn ATIR500DVDContext::dvd_enable_deint(int mode) {
    void *lock = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accelerator) + 0x840);
    DVDSub_lock(lock);
    IOReturn result = GuardCheck(accelerator, boundSurface);
    if (result == 0) {
        boundSurface->enable_deint(mode);
    }
    DVDSub_unlock(lock);
    return result;
}

/* setup_buffers: NOT under the lock in the shipped driver. */
IOReturn ATIR500DVDContext::setup_buffers(UInt32 topHeight, UInt32 leftWidth, UInt32 bottomHeight, UInt32 rightWidth, UInt32 controlFlags) {
    if (boundSurface != nullptr && U8At(accelerator, 0x80) != 0) {
        UInt8 *surface = reinterpret_cast<UInt8 *>(boundSurface);
        U8At(surface, 0xbed) = 1;
        U8At(surface, 0xbee) = 1;
        U16At(surface, 0x94) = static_cast<UInt16>(topHeight);
        U16At(surface, 0x9a) = static_cast<UInt16>(bottomHeight);
        U16At(surface, 0x96) = static_cast<UInt16>(rightWidth);
        U16At(surface, 0x98) = static_cast<UInt16>(leftWidth);
        U32At(this, 0x88) = (controlFlags & 0xfffffc00u) | 0x20000002u;
        return 0;
    }
    return 0xe00002d8;
}

IOReturn ATIR500DVDContext::read_regs(UInt32 *offsets, UInt32 *outValues, UInt32 requestedByteCount, UInt32 *actualByteCount) {
    UInt32 count = *actualByteCount;
    UInt8 *mmio = *reinterpret_cast<UInt8 **>(reinterpret_cast<UInt8 *>(accelerator) + 0x860);
    if (count != requestedByteCount || (count & 3) != 0) {
        return 0xe00002c2;
    }
    void *lock = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accelerator) + 0x840);
    DVDSub_lock(lock);
    IOReturn result;
    if (U8At(accelerator, 0x80) == 0) {
        result = 0xe00002d8;
    } else {
        for (UInt32 i = 0; i < (count >> 2); i++) {
            outValues[i] = SwapLE32(*reinterpret_cast<UInt32 *>(mmio + (offsets[i] & 0x1ffcu)));
        }
        result = 0;
    }
    DVDSub_unlock(lock);
    return result;
}

/* write_regs(offset, value): one register write, byte-swapped to little-endian, under the command lock. */
IOReturn ATIR500DVDContext::write_regs(UInt32 offset, UInt32 value) {
    UInt8 *mmio = *reinterpret_cast<UInt8 **>(reinterpret_cast<UInt8 *>(accelerator) + 0x860);
    void *lock = *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(accelerator) + 0x840);
    DVDSub_lock(lock);
    IOReturn result;
    if (U8At(accelerator, 0x80) == 0) {
        result = 0xe00002d8;
    } else {
        *reinterpret_cast<UInt32 *>(mmio + (offset & 0x1ffcu)) = SwapLE32(value);
        result = 0;
    }
    DVDSub_unlock(lock);
    return result;
}

/* wait_for_stamps / check_stamps: accelerator slots +0x5fc / +0x5f4 take (accel, waitMain) - the decompile
 * shows them with the argument register untouched, i.e. this function's own first parameter passes
 * straight through; +0x558 / +0x554 take the explicit second parameter. Zero = skip that wait/check. */
IOReturn ATIR500DVDContext::wait_for_stamps(UInt32 waitMain, UInt32 waitIDCT) {
    if (waitMain != 0) {
        CallAccel(accelerator, 0x5fc, waitMain);
    }
    if (waitIDCT != 0) {
        CallAccel(accelerator, 0x558, waitIDCT);
    }
    return 0;
}

IOReturn ATIR500DVDContext::check_stamps(UInt32 checkMain, UInt32 checkIDCT, UInt32 *outBothDone) {
    SInt32 mainDone = 1;
    if (checkMain != 0) {
        mainDone = CallAccel(accelerator, 0x5f4, checkMain);
    }
    SInt32 idctDone = 1;
    if (checkIDCT != 0) {
        idctDone = CallAccel(accelerator, 0x554, checkIDCT);
    }
    *outBothDone = (mainDone == 0 || idctDone == 0) ? 0 : 1;
    return 0;
}
