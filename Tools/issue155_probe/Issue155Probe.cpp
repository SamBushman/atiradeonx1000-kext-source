/*
 * Issue155Probe.cpp - issue #155 follow-up: read-only, same safety class as issue147_probe/issue154_probe.
 *
 * Dumps the accelerator's own private IOWorkLoop (self+0xb4, IOATIR500Accelerator_Start.cpp's own
 * `IOWorkLoop::workLoop()` call) and the event sources attached to it (self+0xbc garbage_collector
 * interrupt event source, self+0xb8, self+0xc0 gart_collector timer event source, self+0xc4), plus
 * self+0x74 (the real PCI provider) and self+0xcc (head count) for context - comparing these live,
 * non-destructively, between a stock instance and a rebuilt instance is the plan to narrow #155
 * without costing another crash/reboot per data point.
 *
 * Never touches/calls into the live instance beyond read-only struct-offset access and the standard
 * OSObject::getMetaClass()/getClassName()/getRetainCount() virtual calls - no writes, no VCALL into
 * any unverified/driver-specific vtable slot.
 */
#include <IOKit/IOLib.h>
#include <IOKit/IOService.h>
#include <IOKit/IOWorkLoop.h>
#include <libkern/c++/OSIterator.h>

static UInt8 *g_accel = NULL;

#define R32(off) (*(UInt32 *)(g_accel + (off)))

extern "C" kern_return_t Issue155Probe_start(kmod_info_t *ki, void *data);
extern "C" kern_return_t Issue155Probe_stop(kmod_info_t *ki, void *data);

static void dumpField(const char *label, UInt32 val) {
    if (val == 0) { IOLog("Issue155Probe: %s = NULL\n", label); return; }
    OSObject *obj = (OSObject *)(uintptr_t)val;
    const OSMetaClass *mc = obj->getMetaClass();
    IOLog("Issue155Probe: %s = %p class='%s' retainCount=%d\n",
          label, obj, mc ? mc->getClassName() : "(null)", obj->getRetainCount());
}

extern "C" kern_return_t Issue155Probe_start(kmod_info_t *ki, void *data) {
    IOLog("Issue155Probe: start\n");
    OSDictionary *match = IOService::serviceMatching("ATIRadeonX1000");
    if (!match) { IOLog("Issue155Probe: serviceMatching failed\n"); return KERN_SUCCESS; }
    OSIterator *it = IOService::getMatchingServices(match);
    match->release();
    if (!it) { IOLog("Issue155Probe: getMatchingServices returned null\n"); return KERN_SUCCESS; }
    IOService *accel = OSDynamicCast(IOService, it->getNextObject());
    if (accel) accel->retain();
    it->release();
    if (!accel) { IOLog("Issue155Probe: ATIRadeonX1000 service not found\n"); return KERN_SUCCESS; }
    g_accel = (UInt8 *)accel;
    IOLog("Issue155Probe: found object of real class '%s', retainCount=%d\n",
          accel->getMetaClass()->getClassName(), accel->getRetainCount());

    /* Wide, unbiased raw dump of the object's low-offset region (0x0-0x300) - this is base-class
     * (OSObject/IORegistryEntry/IOService/IOAccelerator) territory our own ported code is NOT
     * supposed to write into at all. The point isn't to interpret these values (most are real Apple
     * kernel bookkeeping this project has no documentation for) - it's to get a byte-for-byte
     * comparison against the identical dump from a stock instance, to catch a struct-offset/layout
     * bug in our own code that corrupts memory outside what our own fields are supposed to occupy. */
    IOLog("Issue155Probe: raw dump self+0x0..0x300:\n");
    for (UInt32 off = 0; off < 0x300; off += 0x20) {
        IOLog("Issue155Probe: +%03x: %08x %08x %08x %08x %08x %08x %08x %08x\n", (unsigned)off,
              (unsigned)R32(off), (unsigned)R32(off+4), (unsigned)R32(off+8), (unsigned)R32(off+0xc),
              (unsigned)R32(off+0x10), (unsigned)R32(off+0x14), (unsigned)R32(off+0x18), (unsigned)R32(off+0x1c));
    }

    return KERN_SUCCESS;
}

extern "C" kern_return_t Issue155Probe_stop(kmod_info_t *ki, void *data) {
    if (g_accel) { ((IOService *)g_accel)->release(); g_accel = NULL; }
    IOLog("Issue155Probe: stop\n");
    return KERN_SUCCESS;
}
