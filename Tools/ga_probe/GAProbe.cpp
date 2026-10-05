/*
 * GAProbe.cpp - issue #141, user-authorized raw-MMIO probe, Pass 4: the actual completion-stamp value.
 *
 * g21's capture showed the kernel repeatedly waiting on stamp 0xf33 (ATIRadeonX1000::waitForTimeStamp family,
 * Sources/ATIRadeonX1000_TimeStamps.cpp) and never completing, while GA/VAP/CP all read idle (Pass 3). That function
 * reads the live completed-stamp value from *(accel+0x864) + *(accel+0x86c) - ordinary GART/DMA-coherent memory the
 * GPU writes to, NOT an MMIO register - and caches it at accel+0x54. This pass reads that exact chain using the
 * already-retained `accel` object pointer (the live ATIRadeonX1000 instance itself; these are the project's own
 * long-validated struct offsets, used throughout Sources/, not a guess) to see directly whether the real stamp value
 * ever reaches what the kernel is waiting for, or is frozen below it - the single most direct test of "did the GPU
 * really never finish" vs. "the kernel's wait logic has its own bug".
 *
 * accel+0x864/accel+0x86c are themselves ordinary (big-endian PPC) struct fields, read directly, no swap. The target
 * memory they point at is GPU-authored and little-endian (confirmed by the decompile's byte-order reconstruction),
 * so that one read needs OSSwapInt32. Still strictly read-only throughout.
 */
#include <IOKit/IOLib.h>
#include <IOKit/IOService.h>
#include <IOKit/IOWorkLoop.h>
#include <IOKit/IOTimerEventSource.h>
#include <IOKit/pci/IOPCIDevice.h>
#include <libkern/c++/OSIterator.h>
#include <libkern/OSByteOrder.h>

#define RD32(base, off) OSSwapInt32((base)[(off) / 4])
#define TICK_MS 250
#define MAX_TICKS 600  /* 150 s */

static IOMemoryMap *g_map = NULL;
static volatile UInt32 *g_bar1 = NULL;
static IOWorkLoop *g_wl = NULL;
static IOTimerEventSource *g_timer = NULL;
static UInt8 *g_accel = NULL;   /* the live ATIRadeonX1000 instance, retained - read-only struct-offset access */
static int g_tick = 0;
static UInt32 g_last_status = 0xffffffff;

static void dump_regs(const char *why) {
    if (!g_bar1) return;
    UInt32 rbbm_status = RD32(g_bar1, 0x0e40);
    bool force = !why[0];
    if (!force && rbbm_status == g_last_status) return;
    g_last_status = rbbm_status;
    UInt32 rbbm_softreset = RD32(g_bar1, 0x00f0);
    UInt32 ga_idle = RD32(g_bar1, 0x425c);
    UInt32 vap_status = RD32(g_bar1, 0x2140);
    UInt32 cp_rptr = RD32(g_bar1, 0x0710);
    UInt32 cp_wptr = RD32(g_bar1, 0x0714);

    UInt32 stamp_base = 0, stamp_off = 0, stamp_val = 0xdeadbeef, cached54 = 0;
    if (g_accel) {
        stamp_base = *(UInt32 *)(g_accel + 0x864);
        stamp_off  = *(UInt32 *)(g_accel + 0x86c);
        cached54   = *(UInt32 *)(g_accel + 0x54);
        if (stamp_base) {
            volatile UInt8 *p = (volatile UInt8 *)(stamp_base + stamp_off);
            /* little-endian 32-bit read, matching waitForTimeStamp's own byte reconstruction exactly */
            stamp_val = (UInt32)p[3] << 24 | (UInt32)p[2] << 16 | (UInt32)p[1] << 8 | (UInt32)p[0];
        }
    }
    IOLog("GAProbe[%s t=%d]: RBBM_STATUS=0x%08x RBBM_SOFTRESET=0x%08x GA_IDLE=0x%08x "
          "VAP_CNTL_STATUS=0x%08x CP_RB_RPTR=0x%08x CP_RB_WPTR=0x%08x "
          "STAMP_BASE=0x%08x STAMP_OFF=0x%08x LIVE_STAMP=0x%08x CACHED_0x54=0x%08x\n",
          why, g_tick, (unsigned)rbbm_status, (unsigned)rbbm_softreset, (unsigned)ga_idle,
          (unsigned)vap_status, (unsigned)cp_rptr, (unsigned)cp_wptr,
          (unsigned)stamp_base, (unsigned)stamp_off, (unsigned)stamp_val, (unsigned)cached54);
}

static void timer_fired(OSObject *owner, IOTimerEventSource *sender) {
    g_tick++;
    dump_regs("tick");
    if (g_tick < MAX_TICKS) sender->setTimeoutMS(TICK_MS);
    else IOLog("GAProbe: window elapsed, timer stopping (kextunload to clean up)\n");
}

extern "C" kern_return_t GAProbe_start(kmod_info_t *ki, void *data);
extern "C" kern_return_t GAProbe_stop(kmod_info_t *ki, void *data);

extern "C" kern_return_t GAProbe_start(kmod_info_t *ki, void *data) {
    IOLog("GAProbe: start\n");
    OSDictionary *match = IOService::serviceMatching("ATIRadeonX1000");
    if (!match) { IOLog("GAProbe: serviceMatching failed\n"); return KERN_SUCCESS; }
    OSIterator *it = IOService::getMatchingServices(match);
    match->release();
    if (!it) { IOLog("GAProbe: getMatchingServices returned null\n"); return KERN_SUCCESS; }
    IOService *accel = OSDynamicCast(IOService, it->getNextObject());
    if (accel) accel->retain();
    it->release();
    if (!accel) { IOLog("GAProbe: ATIRadeonX1000 service not found\n"); return KERN_SUCCESS; }
    g_accel = (UInt8 *)accel;   /* keep the reference for the lifetime of the kext - struct-offset reads only, never released early */

    IOPCIDevice *pci = OSDynamicCast(IOPCIDevice, accel->getProvider());
    if (!pci) { IOLog("GAProbe: provider is not an IOPCIDevice\n"); return KERN_SUCCESS; }

    for (int i = 0; i < 6 && !g_map; i++) {
        IODeviceMemory *dm = pci->getDeviceMemoryWithIndex(i);
        if (dm && dm->getLength() == 0x10000) g_map = pci->mapDeviceMemoryWithIndex(i);
    }
    if (!g_map) { IOLog("GAProbe: register BAR not found - stopping, no MMIO access attempted\n"); return KERN_SUCCESS; }
    g_bar1 = (volatile UInt32 *)g_map->getVirtualAddress();

    dump_regs("");

    g_wl = IOWorkLoop::workLoop();
    if (!g_wl) { IOLog("GAProbe: IOWorkLoop::workLoop() failed - one-shot dump only\n"); return KERN_SUCCESS; }
    g_timer = IOTimerEventSource::timerEventSource(g_wl, &timer_fired);
    if (!g_timer || g_wl->addEventSource(g_timer) != kIOReturnSuccess) {
        IOLog("GAProbe: timer setup failed - one-shot dump only\n");
        return KERN_SUCCESS;
    }
    g_timer->enable();
    g_timer->setTimeoutMS(TICK_MS);
    IOLog("GAProbe: periodic logging armed, %dms ticks for up to %ds (logs only on change)\n", TICK_MS, MAX_TICKS * TICK_MS / 1000);
    return KERN_SUCCESS;
}

extern "C" kern_return_t GAProbe_stop(kmod_info_t *ki, void *data) {
    if (g_timer) { g_timer->disable(); g_timer->cancelTimeout(); }
    if (g_wl && g_timer) g_wl->removeEventSource(g_timer);
    if (g_timer) { g_timer->release(); g_timer = NULL; }
    if (g_wl) { g_wl->release(); g_wl = NULL; }
    if (g_map) { g_map->release(); g_map = NULL; g_bar1 = NULL; }
    if (g_accel) { ((IOService *)g_accel)->release(); g_accel = NULL; }
    IOLog("GAProbe: stop\n");
    return KERN_SUCCESS;
}
