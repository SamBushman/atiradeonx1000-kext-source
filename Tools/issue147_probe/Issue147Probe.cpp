/*
 * Issue147Probe.cpp - issue #147 follow-up: read-only, same safety class as Tools/ga_probe/GAProbe.cpp.
 *
 * Reads specific struct offsets directly off the LIVE, currently-loaded STOCK ATIRadeonX1000 instance
 * (com.apple.ATIRadeonX1000, already running and driving the real display) to get ground truth for
 * what ATIRadeonX1000::start()'s chip-ID classification logic actually sees on THIS real hardware when
 * it runs successfully (self+0x74, self+0x860's mapped BAR2 virtual address, and the raw bytes at
 * self+0x860+8..0xf that the chip-ID classifier reads). Compared against the same offsets' live values
 * already observed in the REBUILT kext (self+0x860=0x6ff56000, raw bytes "8b 00 00 00 8f ac bf 10",
 * chip-id=0xac8f - not matching any real AMD/ATI device-ID range) to determine whether the rebuilt
 * kext's BAR2 mapping/chip-ID read genuinely diverges from stock's, or whether stock sees equally
 * "wrong-looking" bytes there too (meaning the chip-ID classifier reads something other than what was
 * assumed, and the real divergence is elsewhere).
 *
 * Never touches/calls into the stock instance beyond read-only struct-offset access - no VCALL, no
 * lock manipulation, no writes of any kind to the stock instance or to hardware.
 */
#include <IOKit/IOLib.h>
#include <IOKit/IOService.h>
#include <libkern/c++/OSIterator.h>

static UInt8 *g_accel = NULL;

#define R32(off) (*(UInt32 *)(g_accel + (off)))

extern "C" kern_return_t Issue147Probe_start(kmod_info_t *ki, void *data);
extern "C" kern_return_t Issue147Probe_stop(kmod_info_t *ki, void *data);

extern "C" kern_return_t Issue147Probe_start(kmod_info_t *ki, void *data) {
    IOLog("Issue147Probe: start\n");
    OSDictionary *match = IOService::serviceMatching("ATIRadeonX1000");
    if (!match) { IOLog("Issue147Probe: serviceMatching failed\n"); return KERN_SUCCESS; }
    OSIterator *it = IOService::getMatchingServices(match);
    match->release();
    if (!it) { IOLog("Issue147Probe: getMatchingServices returned null\n"); return KERN_SUCCESS; }
    IOService *accel = OSDynamicCast(IOService, it->getNextObject());
    if (accel) accel->retain();
    it->release();
    if (!accel) { IOLog("Issue147Probe: ATIRadeonX1000 service not found\n"); return KERN_SUCCESS; }
    g_accel = (UInt8 *)accel;
    IOLog("Issue147Probe: found object of real class '%s', retainCount=%d\n",
          accel->getMetaClass()->getClassName(), accel->getRetainCount());

    UInt32 f98 = R32(0x98);
    UInt32 f830 = R32(0x830);
    UInt32 f3000 = R32(3000);
    UInt32 fc4c = R32(0xc4c);
    UInt32 f860 = R32(0x860);
    UInt32 fc50 = R32(0xc50);
    UInt32 fc54 = R32(0xc54);
    IOLog("Issue147Probe: self+0x98=0x%x self+0x830=%u self+3000=%u self+0xc4c=0x%x self+0x860=0x%x self+0xc50(saved puVar3)=0x%x self+0xc54=0x%x\n",
          (unsigned)f98, (unsigned)f830, (unsigned)f3000, (unsigned)fc4c, (unsigned)f860, (unsigned)fc50, (unsigned)fc54);

    if (f860 != 0) {
        UInt8 *p = (UInt8 *)f860;
        IOLog("Issue147Probe: raw bytes at self+0x860 [8..0xf]: %02x %02x %02x %02x %02x %02x %02x %02x\n",
              p[8], p[9], p[10], p[0xb], p[0xc], p[0xd], p[0xe], p[0xf]);
        IOLog("Issue147Probe: chipid(CONCAT11 d:c)=0x%04x\n", (unsigned)((p[0xd] << 8) | p[0xc]));
    } else {
        IOLog("Issue147Probe: self+0x860 is NULL, cannot read chip-id bytes\n");
    }

    return KERN_SUCCESS;
}

extern "C" kern_return_t Issue147Probe_stop(kmod_info_t *ki, void *data) {
    if (g_accel) { ((IOService *)g_accel)->release(); g_accel = NULL; }
    IOLog("Issue147Probe: stop\n");
    return KERN_SUCCESS;
}
