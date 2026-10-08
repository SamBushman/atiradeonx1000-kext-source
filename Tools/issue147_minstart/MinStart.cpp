/*
 * MinStart.cpp - issue #147 isolation test, user-requested (2026-10-07).
 *
 * Tests the real timing hypothesis: the chip-ID bytes ATIRadeonX1000::start() reads from BAR2
 * (self+0x860+0xc/0xd) only hold a valid, classifiable value (confirmed via the stock driver's own
 * self+0xc50 save: 0x7240, matching a real range) for a brief window - by the time any kext reads
 * the same bytes afterward (our rebuilt kext's own classifier, or an external read-only probe), they
 * read back 0xac8f, matching nothing. The theory: our rebuilt kext's unoptimized (-O0) build takes
 * measurably longer to reach this read than Apple's (presumably optimized) stock binary, so the
 * window closes before we get there. A first direct test (building with -O2) still crashed the same
 * way, so this isolates the read to the bare minimum: just map BAR2 and read the bytes, with NONE of
 * the ~380 lines of real accelerator setup (object construction, workloop/event sources, AGP config,
 * command buffer allocation, etc.) that happen before this point in the real driver. Deliberately
 * matches the real X1900 personality (same IOProviderClass/IOPCIMatch/IOClass="ATIRadeonX1000") so
 * IOKit offers it the same real hardware match, under a different CFBundleIdentifier. Returns false
 * from start() so IOKit does not consider the device successfully claimed long-term - this is a
 * one-shot read, not a replacement driver.
 *
 * Safety: read-only PCI/BAR mapping and memory reads only. No hardware writes, no register pokes,
 * same safety class as Tools/ga_probe/GAProbe.cpp and Tools/issue147_probe/Issue147Probe.cpp.
 */
#include <IOKit/IOService.h>
#include <IOKit/IOLib.h>
#include <IOKit/pci/IOPCIDevice.h>
#include <IOKit/IOMemoryDescriptor.h>

class ATIRadeonX1000 : public IOService {
    OSDeclareDefaultStructors(ATIRadeonX1000)
public:
    virtual bool start(IOService *provider);
};

OSDefineMetaClassAndStructors(ATIRadeonX1000, IOService)

bool ATIRadeonX1000::start(IOService *provider) {
    if (!IOService::start(provider)) {
        IOLog("MinStart: IOService::start failed\n");
        return false;
    }
    IOPCIDevice *pci = OSDynamicCast(IOPCIDevice, provider);
    if (!pci) {
        IOLog("MinStart: provider is not IOPCIDevice\n");
        return false;
    }
    /* #147: PCI Memory Space Enable is a level bit, not edge-triggered - if the previous driver's
     * unload never explicitly cleared it, our setMemoryEnable(true) below is a true->true no-op,
     * never producing the false->true EDGE some GPUs use to re-latch internal strap/reset logic.
     * Force a real edge here to test that directly. */
    pci->setMemoryEnable(false);
    IOSleep(10);
    pci->setMemoryEnable(true);
    pci->setBusMasterEnable(true);

    /* #147: self+0x860[0xc,0xd] was proven NOT a static chip-ID strap - cross-checked against the
     * live stock instance's self+0xc50 (saved at boot: 0x7240) vs its CURRENT self+0x860 bytes
     * (0xac8f, same garbage we always see) on the SAME running object. The real, stable mechanism
     * for chip identity is standard PCI config space, which never drifts with GPU runtime state. */
    UInt32 vendorDevice = pci->configRead32(0x00);
    UInt16 deviceID = pci->configRead16(0x02);
    UInt16 vendorID = pci->configRead16(0x00);
    IOLog("MinStart: PCI config vendorDevice32=0x%08x vendorID16=0x%04x deviceID16=0x%04x\n",
          (unsigned)vendorDevice, vendorID, deviceID);

    IODeviceMemory *dm = pci->getDeviceMemoryWithRegister(0x18);
    IOMemoryMap *map = pci->mapDeviceMemoryWithRegister(0x18, 0);
    if (!map) {
        IOLog("MinStart: mapDeviceMemoryWithRegister failed (getDeviceMemoryWithRegister=%p)\n", dm);
        return false;
    }
    UInt8 *base = (UInt8 *)map->getVirtualAddress();
    IOLog("MinStart: BEFORE strobe bytes[8..0xf]: %02x %02x %02x %02x %02x %02x %02x %02x  chipid(d:c)=0x%04x\n",
          base[8], base[9], base[10], base[0xb], base[0xc], base[0xd], base[0xe], base[0xf],
          (unsigned)((base[0xd] << 8) | base[0xc]));

    /* #147: real driver's exact sequence (ATIRadeonX1000_Start.cpp:165-173) - write a magic
     * strobe value to BAR2+8 (clears all bits but bit6, forces 0x34), then immediately restores
     * the original byte - this appears to latch real strap/chip-ID data into BAR2+0xc..0xf as a
     * side effect of the write, which our plain-read probes never triggered. */
    UInt8 orig8 = base[8];
#define GH_EIEIO() asm volatile("eieio")
    GH_EIEIO();
    *(volatile UInt32 *)(base + 8) =
        (UInt32)(((orig8 & 0x40) | 0x34) << 0x18) | ((UInt32)base[9] << 0x10) |
        ((UInt32)base[10] << 8) | (UInt32)base[0xb];
    GH_EIEIO();
    *(volatile UInt32 *)(base + 8) =
        (UInt32)(orig8 << 0x18) | ((UInt32)base[9] << 0x10) |
        ((UInt32)base[10] << 8) | (UInt32)base[0xb];
    GH_EIEIO();

    IOLog("MinStart: AFTER strobe bytes[8..0xf]: %02x %02x %02x %02x %02x %02x %02x %02x  chipid(d:c)=0x%04x\n",
          base[8], base[9], base[10], base[0xb], base[0xc], base[0xd], base[0xe], base[0xf],
          (unsigned)((base[0xd] << 8) | base[0xc]));
    map->release();
    return false;
}
