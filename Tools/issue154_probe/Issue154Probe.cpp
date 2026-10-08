/*
 * Issue154Probe.cpp - issue #154 follow-up: read-only, same safety class as Tools/issue147_probe/Issue147Probe.cpp.
 *
 * Reads specific struct offsets off the LIVE, currently-loaded REBUILT ATIRadeonX1000 instance to check
 * why getVRAMDescriptors() fails for every client type (GL/2D/Surface/DVD all now show the identical
 * 0xe00002c9 open failure on this hot-swapped instance). getVRAMDescriptors() fails immediately when
 * self+0xcc (head count) is 0; that count is only ever incremented by foundFramebuffer(), called from
 * findFramebuffers() (IOATIR500Accelerator_Members.cpp), which walks children of self+0x74 (expected to
 * be this driver's own PCI/AGP provider, cached once during IOATIR500Accelerator::start()) looking for an
 * IOFramebuffer sibling. self+0x74 is also the field central to issue #155's stop()-path panic
 * investigation - this probe gets independent, live ground truth on what it actually is right now.
 *
 * Never touches/calls into the live instance beyond read-only struct-offset access and the standard
 * OSObject::getMetaClass()/getClassName() virtual calls (same safety class already used successfully by
 * issue147_probe/issue153_probe this week) - no VCALL into any unverified/driver-specific vtable slot, no
 * writes of any kind.
 */
#include <IOKit/IOLib.h>
#include <IOKit/IOService.h>
#include <IOKit/IODeviceTreeSupport.h>
#include <libkern/c++/OSIterator.h>
#include <libkern/c++/OSDictionary.h>

static UInt8 *g_accel = NULL;

#define R32(off) (*(UInt32 *)(g_accel + (off)))

extern "C" kern_return_t Issue154Probe_start(kmod_info_t *ki, void *data);
extern "C" kern_return_t Issue154Probe_stop(kmod_info_t *ki, void *data);

extern "C" kern_return_t Issue154Probe_start(kmod_info_t *ki, void *data) {
    IOLog("Issue154Probe: start\n");
    OSDictionary *match = IOService::serviceMatching("ATIRadeonX1000");
    if (!match) { IOLog("Issue154Probe: serviceMatching failed\n"); return KERN_SUCCESS; }
    OSIterator *it = IOService::getMatchingServices(match);
    match->release();
    if (!it) { IOLog("Issue154Probe: getMatchingServices returned null\n"); return KERN_SUCCESS; }
    IOService *accel = OSDynamicCast(IOService, it->getNextObject());
    if (accel) accel->retain();
    it->release();
    if (!accel) { IOLog("Issue154Probe: ATIRadeonX1000 service not found\n"); return KERN_SUCCESS; }
    g_accel = (UInt8 *)accel;
    IOLog("Issue154Probe: found object of real class '%s', retainCount=%d\n",
          accel->getMetaClass()->getClassName(), accel->getRetainCount());

    UInt32 f74 = R32(0x74);
    UInt32 fcc = R32(0xcc);
    UInt32 fe4 = R32(0xe4);
    IOLog("Issue154Probe: self+0x74=0x%x self+0xcc(head count)=%u self+0xe4=0x%x\n",
          (unsigned)f74, (unsigned)fcc, (unsigned)fe4);

    if (f74 != 0) {
        OSObject *provider = (OSObject *)(uintptr_t)f74;
        /* Standard, universally-safe OSObject virtual call - same safety class as accel->getMetaClass() above. */
        const OSMetaClass *mc = provider->getMetaClass();
        IOLog("Issue154Probe: self+0x74 real class = '%s'\n", mc ? mc->getClassName() : "(getMetaClass returned null)");

        IOService *realProvider = accel->getProvider();
        IOLog("Issue154Probe: accel->getProvider()=%p (class '%s'), matches self+0x74? %s\n",
              realProvider, realProvider ? realProvider->getMetaClass()->getClassName() : "(null)",
              (realProvider == provider) ? "YES" : "NO");

        /* Standard, safe IORegistryEntry::getChildIterator - real public API, not a raw VCALL. */
        OSIterator *dtKids = realProvider->getChildIterator(gIODTPlane);
        int dtCount = 0, dtFbCount = 0;
        if (dtKids) {
            IORegistryEntry *child;
            while ((child = OSDynamicCast(IORegistryEntry, dtKids->getNextObject())) != NULL) {
                dtCount++;
                IOService *svc = OSDynamicCast(IOService, child);
                bool isFb = svc && svc->metaCast("IOFramebuffer") != NULL;
                if (isFb) dtFbCount++;
                IOLog("Issue154Probe: IODeviceTree child #%d class='%s' isIOFramebuffer=%d\n",
                      dtCount, child->getMetaClass()->getClassName(), isFb);
                /* This is what findFramebuffers() actually does per-child: getClientWithCategory("IOFramebuffer").
                 * Real, declared IOService method - normal virtual dispatch, not a raw VCALL guess. */
                if (svc) {
                    const OSSymbol *cat = OSSymbol::withCString("IOFramebuffer");
                    IOService *client = svc->getClientWithCategory(cat);
                    cat->release();
                    IOLog("Issue154Probe:   child #%d getClientWithCategory(\"IOFramebuffer\") = %p class='%s' isIOFramebuffer=%d\n",
                          dtCount, client, client ? client->getMetaClass()->getClassName() : "(null)",
                          client && client->metaCast("IOFramebuffer") != NULL);
                }
            }
            dtKids->release();
        } else {
            IOLog("Issue154Probe: getChildIterator(gIODTPlane) returned NULL\n");
        }
        IOLog("Issue154Probe: IODeviceTree children total=%d framebuffers=%d\n", dtCount, dtFbCount);
    } else {
        IOLog("Issue154Probe: self+0x74 is NULL\n");
    }

    /* System-wide: does any IOFramebuffer exist at all right now, and who is its provider? */
    OSDictionary *fbMatch = IOService::serviceMatching("IOFramebuffer");
    if (fbMatch) {
        OSIterator *fbIt = IOService::getMatchingServices(fbMatch);
        fbMatch->release();
        if (fbIt) {
            IOService *fb;
            int n = 0;
            while ((fb = OSDynamicCast(IOService, fbIt->getNextObject())) != NULL) {
                n++;
                IOService *fbProvider = fb->getProvider();
                IOLog("Issue154Probe: system IOFramebuffer #%d = %p class='%s' provider=%p provider-class='%s' provider==self+0x74? %s\n",
                      n, fb, fb->getMetaClass()->getClassName(),
                      fbProvider, fbProvider ? fbProvider->getMetaClass()->getClassName() : "(null)",
                      (f74 != 0 && (UInt32)(uintptr_t)fbProvider == f74) ? "YES" : "NO");
            }
            if (n == 0) IOLog("Issue154Probe: system-wide IOFramebuffer search found ZERO instances\n");
            fbIt->release();
        }
    }

    /* Standard, public IOService::requestProbe - real declared API (same safety class as every
     * other call in this probe), not a raw VCALL guess. Our port's override calls findFramebuffers()
     * unconditionally (IOATIR500Accelerator_SmallMethods.cpp). This is the normal mechanism the real
     * graphics subsystem uses to ask an accelerator to re-discover its framebuffer after a display
     * reconfiguration - exercising it here mirrors expected real-world driver behavior, not a novel
     * code path. Testing whether this is what a hot-swapped instance is missing (issue #154). */
    IOLog("Issue154Probe: calling accel->requestProbe(1)...\n");
    IOReturn rp = accel->requestProbe(1);
    IOLog("Issue154Probe: requestProbe returned 0x%x\n", (unsigned)rp);
    IOLog("Issue154Probe: after requestProbe: self+0xcc(head count)=%u self+0xe4=0x%x\n",
          (unsigned)R32(0xcc), (unsigned)R32(0xe4));

    return KERN_SUCCESS;
}

extern "C" kern_return_t Issue154Probe_stop(kmod_info_t *ki, void *data) {
    if (g_accel) { ((IOService *)g_accel)->release(); g_accel = NULL; }
    IOLog("Issue154Probe: stop\n");
    return KERN_SUCCESS;
}
