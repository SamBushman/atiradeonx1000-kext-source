/*
 * VRAMPeek.cpp - issue #92 follow-up: a small, SEPARATE, read-only diagnostic kext (same class and safety pattern as Tools/ga_probe/GAProbe.cpp,
 * used without incident across #141/#142/#144's investigations) to read back DVD write_buffer's actual blitted pixel content.
 *
 * Pass 1 (BAR discovery, already run and logged): write_buffer's target slot addresses (e.g. 0x08eb0000, observed via lock_all_buffers) do NOT
 * fall inside the accelerator's own VRAM/framebuffer PCI BAR (BAR[0], physAddr=0x98000000, length 128MB) - so they are not raw PCI physical
 * addresses needing BAR-relative mapping at all.
 *
 * Pass 2 (superseded): dereferencing the raw `+8` "address" field directly, baked in at build time from a fresh lock_all_buffers/write_buffer
 * run, landed on a real but wrong 44-byte repeating record - not pixel data. Root cause, found by reading the real decompiled bodies of
 * ATIR500Surface::copy_to_buffer/copy_from_buffer (Sources/ATIR500Surface_copy_to_buffer_Port.cpp, copy_from_buffer_Port.cpp): the buffer
 * record's `+8` field is relative to the OWNING SURFACE OBJECT's own `+0xc10` field (the kernel-virtual base of the surface's mapped VRAM
 * aperture, set by IOATIR500Surface::reset_access - Sources/IOATIR500Surface_reset_access_Port.cpp:48-52), not an absolute pointer by itself:
 * real address = *(bufferRecord + 8) + *(surface + 0xc10).
 *
 * Pass 3 (this file): walks the whole chain live and read-only, no hardcoded addresses needed -
 *   accel = the live ATIRadeonX1000 instance (IOService::getMatchingServices, same as GAProbe)
 *   dvdCtx = *(accel + 0x68)                      - head of the accelerator's live DVD-context list (Sources/IOATIR500DVDContext_Lifecycle.cpp)
 *   surface = *(dvdCtx + 0xf8)                    - the DVD context's bound surface
 *   apertureBase = *(surface + 0xc10)             - the surface's mapped-VRAM-aperture kernel-virtual base
 *   bufPtr = *(surface + TARGET_SLOT*4 + 0xb70)   - the per-slot buffer record pointer (array of pointers on the surface object)
 *   realAddr = *(bufPtr + 8) + apertureBase
 * then dumps TARGET_LEN bytes from realAddr via IOLog as hex. Every step is a plain struct-offset read, same safety class as GAProbe's own
 * already-safe *(accel+0x864) stamp read and VRAMPeek's own earlier passes - no lock/mutex manipulation anywhere in this file.
 */
#include <IOKit/IOLib.h>
#include <IOKit/IOService.h>
#include <libkern/c++/OSIterator.h>

#ifndef TARGET_SLOT
#define TARGET_SLOT 16   /* matches the --write-buffer 1 case (bufferSelect != 0) in IOATIR500DVDContext::write_buffer */
#endif
#ifndef TARGET_LEN
#define TARGET_LEN 0x100  /* kept small deliberately: a first full-size (0x3000) dump showed only its LAST ~20 lines survived in system.log - the
                            * kernel's own IOLog message buffer drops earlier lines under a burst this large. */
#endif

extern "C" kern_return_t VRAMPeek_start(kmod_info_t *ki, void *data);
extern "C" kern_return_t VRAMPeek_stop(kmod_info_t *ki, void *data);

static void dump_at(UInt32 addr, unsigned len) {
    volatile UInt8 *p = (volatile UInt8 *)addr;
    char line[128]; int lo = 0;
    for (unsigned i = 0; i < len; i++) {
        if (i % 32 == 0) { if (i) { line[lo] = 0; IOLog("VRAMPeek[+0x%04x]: %s\n", i - 32, line); } lo = 0; }
        lo += snprintf(line + lo, sizeof(line) - lo, "%02x ", p[i]);
    }
    if (lo) { line[lo] = 0; IOLog("VRAMPeek[+0x%04x]: %s\n", len - (len % 32 ? len % 32 : 32), line); }
}

extern "C" kern_return_t VRAMPeek_start(kmod_info_t *ki, void *data) {
    IOLog("VRAMPeek: start, TARGET_SLOT=%d TARGET_LEN=0x%x\n", (int)TARGET_SLOT, (unsigned)TARGET_LEN);

    OSDictionary *match = IOService::serviceMatching("ATIRadeonX1000");
    if (!match) { IOLog("VRAMPeek: serviceMatching failed\n"); return KERN_SUCCESS; }
    OSIterator *it = IOService::getMatchingServices(match);
    match->release();
    if (!it) { IOLog("VRAMPeek: getMatchingServices returned null\n"); return KERN_SUCCESS; }
    IOService *accelSvc = OSDynamicCast(IOService, it->getNextObject());
    if (accelSvc) accelSvc->retain();
    it->release();
    if (!accelSvc) { IOLog("VRAMPeek: ATIRadeonX1000 service not found\n"); return KERN_SUCCESS; }
    UInt8 *accel = (UInt8 *)accelSvc;

    UInt32 dvdCtx = *(UInt32 *)(accel + 0x68);
    IOLog("VRAMPeek: accel=0x%08x dvdCtx(accel+0x68)=0x%08x\n", (unsigned)(UInt32)accel, (unsigned)dvdCtx);
    if (dvdCtx == 0) { IOLog("VRAMPeek: no active DVD context\n"); accelSvc->release(); return KERN_SUCCESS; }

    UInt32 surface = *(UInt32 *)(dvdCtx + 0xf8);
    IOLog("VRAMPeek: surface(dvdCtx+0xf8)=0x%08x\n", (unsigned)surface);
    if (surface == 0) { IOLog("VRAMPeek: no bound surface\n"); accelSvc->release(); return KERN_SUCCESS; }

    UInt32 apertureBase = *(UInt32 *)(surface + 0xc10);
    IOLog("VRAMPeek: apertureBase(surface+0xc10)=0x%08x\n", (unsigned)apertureBase);

    UInt32 bufPtr = *(UInt32 *)(surface + TARGET_SLOT * 4 + 0xb70);
    IOLog("VRAMPeek: bufPtr(surface+slot*4+0xb70)=0x%08x\n", (unsigned)bufPtr);
    if (bufPtr == 0) { IOLog("VRAMPeek: slot %d buffer record not allocated\n", (int)TARGET_SLOT); accelSvc->release(); return KERN_SUCCESS; }

    UInt32 raw8 = *(UInt32 *)(bufPtr + 8);
    UInt16 pitch = *(UInt16 *)(bufPtr + 0x14);
    UInt16 bpp   = *(UInt16 *)(bufPtr + 0x16);
    UInt16 width = *(UInt16 *)(bufPtr + 0x1c);
    UInt16 height = *(UInt16 *)(bufPtr + 0x1e);
    UInt32 realAddr = raw8 + apertureBase;
    IOLog("VRAMPeek: raw8(bufPtr+8)=0x%08x pitch=0x%x bpp=0x%x w=%u h=%u\n",
          (unsigned)raw8, (unsigned)pitch, (unsigned)bpp, (unsigned)width, (unsigned)height);
    IOLog("VRAMPeek: realAddr = raw8 + apertureBase = 0x%08x\n", (unsigned)realAddr);

    dump_at(realAddr, (unsigned)TARGET_LEN);
    IOLog("VRAMPeek: dump done\n");

    accelSvc->release();
    return KERN_SUCCESS;
}

extern "C" kern_return_t VRAMPeek_stop(kmod_info_t *ki, void *data) {
    IOLog("VRAMPeek: stop\n");
    return KERN_SUCCESS;
}
