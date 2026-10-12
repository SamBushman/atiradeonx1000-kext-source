/*
 * Issue157Probe.cpp - issue #157, read-only, same safety class as Tools/issue147_probe/Issue147Probe.cpp.
 *
 * Reads accel+0xa8 / accel+0xaa (the max-supported-surface-width/height fields
 * IOATIR500Surface::is_surface_size_supported compares against, per Surface::set_shape ->
 * set_shape_backing_length_ext -> vtable+0x5b0, Sources/IOATIR500Surface_set_shape_backing_length_ext_Port.cpp)
 * directly off the LIVE, currently-loaded ATIRadeonX1000 instance (whichever bundle id is loaded -
 * stock or the rebuilt hot-swap), to determine whether start()'s unconditional "= 0x1000" writes
 * (Sources/IOATIR500Accelerator_Start.cpp:78,81 and Sources/ATIRadeonX1000_Start.cpp:136-143) actually
 * hold at the moment a hot-swapped set_shape call fails with NoResources, or whether something else
 * has changed/cleared them by then. Also reads self+0x8c0 (the ATIEnableWideBlitSupport property-read
 * result) and self+0xcc/self+0xd0 (nearby capability bits, for context, same offsets Issue147Probe
 * already established are meaningful on this exact class).
 *
 * Never touches/calls into the live instance beyond read-only struct-offset access - no VCALL, no
 * lock manipulation, no writes of any kind to the live instance or to hardware.
 */
#include <IOKit/IOLib.h>
#include <IOKit/IOService.h>
#include <libkern/c++/OSIterator.h>

static UInt8 *g_accel = NULL;

#define R32(off) (*(UInt32 *)(g_accel + (off)))
#define R16(off) (*(UInt16 *)(g_accel + (off)))

extern "C" kern_return_t Issue157Probe_start(kmod_info_t *ki, void *data);
extern "C" kern_return_t Issue157Probe_stop(kmod_info_t *ki, void *data);

extern "C" kern_return_t Issue157Probe_start(kmod_info_t *ki, void *data) {
    IOLog("Issue157Probe: start\n");
    OSDictionary *match = IOService::serviceMatching("ATIRadeonX1000");
    if (!match) { IOLog("Issue157Probe: serviceMatching failed\n"); return KERN_SUCCESS; }
    OSIterator *it = IOService::getMatchingServices(match);
    match->release();
    if (!it) { IOLog("Issue157Probe: getMatchingServices returned null\n"); return KERN_SUCCESS; }
    IOService *accel = OSDynamicCast(IOService, it->getNextObject());
    if (accel) accel->retain();
    it->release();
    if (!accel) { IOLog("Issue157Probe: ATIRadeonX1000 service not found\n"); return KERN_SUCCESS; }
    g_accel = (UInt8 *)accel;
    IOLog("Issue157Probe: found object of real class '%s', retainCount=%d, bundle=%s\n",
          accel->getMetaClass()->getClassName(), accel->getRetainCount(),
          accel->getProperty("CFBundleIdentifier") ? "has-prop" : "no-bundle-prop");

    UInt16 fa8 = R16(0xa8);
    UInt16 faa = R16(0xaa);
    UInt32 f8c0 = R32(0x8c0);
    UInt32 f8c4 = R32(0x8c4);
    UInt32 fcc = R32(0xcc);
    UInt32 fd0 = R32(0xd0);
    UInt32 f98 = R32(0x98);
    IOLog("Issue157Probe: self+0xa8(maxW)=0x%x self+0xaa(maxH)=0x%x self+0x8c0(WideBlit)=0x%x self+0x8c4=0x%x self+0xcc=0x%x self+0xd0=0x%x self+0x98(AccelCaps-ish)=0x%x\n",
          (unsigned)fa8, (unsigned)faa, (unsigned)f8c0, (unsigned)f8c4, (unsigned)fcc, (unsigned)fd0, (unsigned)f98);

    OSObject *prop = accel->getProperty("ATIEnableWideBlitSupport");
    IOLog("Issue157Probe: live getProperty(ATIEnableWideBlitSupport)=%p\n", prop);

    /* #157 follow-up: does STOCK, hot-swapped, show the same zero-capacity VRAM pool as the
     * rebuilt kext? self+0x9c/self+0x84c are only ever written by set_display_mode_and_vram()
     * (called from initialize_hardware(), called from display_mode_did_change() - a real
     * display-mode-change callback that a hot-swap never receives, per this issue's own tracing).
     * Reading these on whichever kext is currently loaded answers whether this is a genuine
     * hot-swap-only limitation (same on stock) or specific to the rebuilt kext's own code. */
    UInt32 f9c = R32(0x9c);
    UInt32 f84c = R32(0x84c);
    void *pool93c = *(void **)(g_accel + 0x93c);
    void *pool7c = *(void **)(g_accel + 0x7c);
    UInt32 fe4 = R32(0xe4);
    IOLog("Issue157Probe: self+0x9c(vramsize)=0x%x self+0x84c=0x%x self+0x93c(tmppool)=%p self+0x7c(gartpool)=%p self+0xe4=0x%x\n",
          (unsigned)f9c, (unsigned)f84c, pool93c, pool7c, (unsigned)fe4);

    return KERN_SUCCESS;
}

extern "C" kern_return_t Issue157Probe_stop(kmod_info_t *ki, void *data) {
    if (g_accel) { ((IOService *)g_accel)->release(); g_accel = NULL; }
    IOLog("Issue157Probe: stop\n");
    return KERN_SUCCESS;
}
