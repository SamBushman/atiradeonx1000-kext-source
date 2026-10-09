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

    /* #155 follow-up (2026-10-08): the removeEventSource argument fix (passing the real event source
     * instead of a missing/garbage one, matching stock) didn't change the crash at all. Checking here,
     * non-destructively, on a kext that's been loaded and idle (NOT right after load, NOT via the
     * crash-triggering unload path) whether self+0xb4 (our private workloop) and the four event
     * sources still have valid, non-null vtables - to see if corruption happens during ordinary
     * operation (before stop() ever runs) rather than during stop()'s own cleanup sequence. */
    static const struct { int off; const char *label; } fields[] = {
        {0xb4, "workloop"}, {0xbc, "eventSource(0xbc)"}, {0xb8, "eventSource(0xb8)"},
        {0xc0, "eventSource(0xc0)"}, {0xc4, "eventSource(0xc4)"},
    };
    for (unsigned i = 0; i < sizeof(fields)/sizeof(fields[0]); i++) {
        UInt32 val = R32(fields[i].off);
        /* Raw memory read only - deliberately NOT calling any virtual method (even getMetaClass())
         * here, since if the vtable word itself is 0/garbage, a virtual dispatch would crash exactly
         * like the bug under investigation. Report the raw vtable word only; resolve to a class name
         * in a SEPARATE pass below, only for fields whose vtable word looks plausibly valid. */
        UInt32 vt = val ? *(UInt32 *)(uintptr_t)val : 0;
        IOLog("Issue155Probe: self+0x%x %s = 0x%x vtable=0x%x\n",
              fields[i].off, fields[i].label, (unsigned)val, (unsigned)vt);
    }
    for (unsigned i = 0; i < sizeof(fields)/sizeof(fields[0]); i++) {
        UInt32 val = R32(fields[i].off);
        UInt32 vt = val ? *(UInt32 *)(uintptr_t)val : 0;
        /* Only now, having confirmed the vtable word is a plausible kernel-text address (not 0, not
         * some tiny/obviously-bogus value), is it safe to attempt the real virtual call. */
        if (vt > 0x1000 && vt < 0x10000000) {
            OSObject *obj = (OSObject *)(uintptr_t)val;
            const OSMetaClass *mc = obj->getMetaClass();
            IOLog("Issue155Probe: self+0x%x %s class='%s'\n",
                  fields[i].off, fields[i].label, mc ? mc->getClassName() : "(getMetaClass null)");
        } else if (val != 0) {
            IOLog("Issue155Probe: self+0x%x %s vtable=0x%x looks NOT SAFE to dispatch through - skipping getMetaClass\n",
                  fields[i].off, fields[i].label, (unsigned)vt);
        }
    }

    return KERN_SUCCESS;
}

extern "C" kern_return_t Issue155Probe_stop(kmod_info_t *ki, void *data) {
    if (g_accel) { ((IOService *)g_accel)->release(); g_accel = NULL; }
    IOLog("Issue155Probe: stop\n");
    return KERN_SUCCESS;
}
