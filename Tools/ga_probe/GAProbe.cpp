/*
 * GAProbe.cpp - issue #141, user-authorized raw-MMIO probe, kernel-mode helper (Pass 1: READ-ONLY).
 *
 * The stock kext's read_regs/write_regs (sel 16/17 etc.) mask every offset to & 0x1ffc, so GA_IDLE (0x425c) and
 * GA_SOFT_RESET (0x429c) - the two registers AMD's own documented hang-recovery procedure (R5xx_Acceleration_v1.5.pdf
 * 10.1.9) needs beyond what RBBM_SOFTRESET (0x00f0, already reachable and already tried, see idct_engine_findings.md
 * 9s) covers - are unreachable through any existing kernel path. /dev/mem is blocked by kern.securelevel=1 (confirmed).
 *
 * This kext does NOT register any IOKitPersonalities (it never matches/competes for the GPU) - it is loaded manually,
 * finds the ALREADY-RUNNING ATIRadeonX1000 instance by name, gets its IOPCIDevice provider, locates the one memory
 * range whose length is exactly 0x10000 (the register BAR; confirmed via ioreg's assigned-addresses decode: phys
 * 0x90000000, len 0x10000 - distinct from the 128MB VRAM BAR and the 128KB ROM BAR), maps it, reads three registers
 * ONCE, logs them, unmaps, and does nothing else. No writes in this pass. No persistent kernel state (no sysctl, no
 * retained objects) - load it, read the log, unload it.
 */
#include <IOKit/IOLib.h>
#include <IOKit/IOService.h>
#include <IOKit/pci/IOPCIDevice.h>
#include <libkern/c++/OSIterator.h>
#include <libkern/OSByteOrder.h>

/* The register aperture is little-endian (the stock kext's own write_regs/read_regs byte-swap - see
 * Sources/ATIR5002DContext_write_regs_Port.cpp); this PPC kernel reads big-endian, so every raw load needs OSSwapInt32. */
#define RD32(base, off) OSSwapInt32((base)[(off) / 4])

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

    IOPCIDevice *pci = OSDynamicCast(IOPCIDevice, accel->getProvider());
    if (!pci) { IOLog("GAProbe: provider is not an IOPCIDevice\n"); accel->release(); return KERN_SUCCESS; }

    IOMemoryMap *map = NULL;
    for (int i = 0; i < 6 && !map; i++) {
        IODeviceMemory *dm = pci->getDeviceMemoryWithIndex(i);
        if (!dm) continue;
        IOLog("GAProbe: range[%d] length=0x%lx\n", i, (unsigned long)dm->getLength());
        if (dm->getLength() == 0x10000) {
            map = pci->mapDeviceMemoryWithIndex(i);
        }
    }
    if (!map) { IOLog("GAProbe: no 0x10000-length memory range found (register BAR not identified) - stopping, no access attempted\n"); accel->release(); return KERN_SUCCESS; }

    volatile UInt32 *bar1 = (volatile UInt32 *)map->getVirtualAddress();
    UInt32 rbbm_status = RD32(bar1, 0x0e40);
    UInt32 rbbm_softreset = RD32(bar1, 0x00f0);
    UInt32 ga_idle = RD32(bar1, 0x425c);
    UInt32 ga_softreset = RD32(bar1, 0x429c);
    IOLog("GAProbe: RBBM_STATUS=0x%08x RBBM_SOFTRESET=0x%08x GA_IDLE=0x%08x GA_SOFT_RESET=0x%08x\n",
          (unsigned)rbbm_status, (unsigned)rbbm_softreset, (unsigned)ga_idle, (unsigned)ga_softreset);

    map->release();
    accel->release();
    IOLog("GAProbe: done (read-only, no writes)\n");
    return KERN_SUCCESS;
}

extern "C" kern_return_t GAProbe_stop(kmod_info_t *ki, void *data) {
    IOLog("GAProbe: stop\n");
    return KERN_SUCCESS;
}
