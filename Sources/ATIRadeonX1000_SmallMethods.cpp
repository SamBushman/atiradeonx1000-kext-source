/*
 * ATIRadeonX1000_SmallMethods.cpp
 *
 * RESOLVED (ledger pass): the small ATIRadeonX1000 members that had no body in the rebuild (real addrs in parentheses):
 *   free (0x19fa0), callPlatformFunction (0x1a040), getPeriodValue (0x19ea0), writePerformanceStats (0x1a300)
 *   configureAGP / teardownAGP / commitAGPMemory / releaseAGPMemory / mapVendorTransferBuffer /
 *   unmapVendorTransferBuffer (0x1a3c0 ... 0x1a5f0): tail calls into the same-named IOATIR500Accelerator member
 *   makeGARTEntry (0x1a4b0)  getAccelCapsBits (0x1b300)  tmpTotalVRAM (0x1ab60)  SWDSIsRequired (0x1a9d0)
 *   SWDSEnableCLUT (0x1aa00)  pageOffPCIeGART (0x1a9c0): empty  removeFromGART (0x1b6a0) / addToMinMaxGART (0x1dfd0):
 *   forward to the PCIe-GART versions   noop_buffer (0x1e000)  checkFor{Retired,ConsumedIDCT,}TimeStamp (0x1e060/0x1e030/0x1e090)
 *   initialize_GUI (0x1e0c0)  submit_commands (0x20ce0)
 * Field offsets: this+0x54/+0x858/+0x85c cached stamps (checked / retired / consumed-IDCT), +0x864 stamp page base,
 * +0x868/+0x86c retired / checked stamp offsets, +0x860 mapped register aperture, +0x7c / +0x93c GART / temporary VRAM
 * pools, +0x99c/+0x9a0 GPU-sensor busy / sample counters, +0x9a4 sensor provider, +0x9ac sensor function symbol,
 * +0xb2c+i*4 per-display SWDS flags, +0xbc0 GART entry base.
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIR500Memory.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h"
#include "../Headers/GhidraExterns.h"

extern "C" void SmallX_IOSleep(UInt32 ms) asm("_IOSleep");
extern "C" void *SmallX_safeMetaCast(void *obj, UInt32 metaClass) asm("__ZN15OSMetaClassBase12safeMetaCastEPKS_PK11OSMetaClass");

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
/* the shipped code reads a little-endian 32-bit word byte by byte */
inline UInt32 ReadLE32(const UInt8 *p) { return (static_cast<UInt32>(p[3]) << 24) | (static_cast<UInt32>(p[2]) << 16) | (static_cast<UInt32>(p[1]) << 8) | p[0]; }
typedef void *(*Fn0)(void *);
typedef void *(*FnProp)(void *, char *);
typedef IOReturn (*SetAttrFn)(void *, UInt32, UInt32 *);
}

void ATIRadeonX1000::free() {
    IOService::free();
}

/* Real: property `name` of the sensor provider (this+0x9a4) as OSData; returns its bytes (a big-endian period pair). */
void *ATIRadeonX1000::getPeriodValue(char *name) {
    void *provider = reinterpret_cast<void *>(U32At(this, 0x9a4));
    if (provider != nullptr) {
        void *property = (*reinterpret_cast<FnProp *>(*reinterpret_cast<UInt8 **>(provider) + 0x188))(provider, name);
        void *data = SmallX_safeMetaCast(property, GH_OSData_metaClass);
        if (data != nullptr) {
            return (*reinterpret_cast<Fn0 *>(*reinterpret_cast<UInt8 **>(data) + 0x100))(data);
        }
    }
    return nullptr;
}

/* Real: answers the GPU-sensor platform function (this+0x9ac) itself: writes into *param2 the busy percentage in 16.16
 * fixed point (0x640000 = 100.0 while the device is down); anything else goes to the base implementation. */
IOReturn ATIRadeonX1000::callPlatformFunction(const OSSymbol *function, bool waitForFunction, void *param1, void *param2,
                                              void *param3, void *param4) {
    if (U32At(this, 0x9ac) == reinterpret_cast<UInt32>(function) && U32At(this, 0x9a4) != 0) {
        if (U8At(this, 0x80) == 0) {
            *reinterpret_cast<UInt32 *>(param2) = 0x640000;
            return 0;
        }
        UInt32 samples = U32At(this, 0x9a0);
        UInt32 fixed = 0;
        if (samples != 0) {
            disable_GPUSensor();
            UInt32 busy = U32At(this, 0x99c);
            enable_GPUSensor();
            fixed = ((busy * 100) / samples) << 16;
        }
        *reinterpret_cast<UInt32 *>(param2) = fixed;
        return 0;
    }
    return IOATIR500Accelerator::callPlatformFunction(function, waitForFunction, param1, param2, param3, param4);
}

void ATIRadeonX1000::writePerformanceStats(OSDictionary *dictionary) {
    IOATIR500Accelerator::writePerformanceStats(dictionary);
    UInt32 freeBytes = reinterpret_cast<ATIR500Memory *>(U32At(this, 0x7c))->total_free();
    OSNumber *number = OSNumber::withNumber(static_cast<unsigned long long>(freeBytes), 0x20);
    if (number != nullptr) {
        dictionary->setObject("vramFreeBytes", number);
        number->release();
    }
}

bool ATIRadeonX1000::configureAGP(IOService *provider) {
    return IOATIR500Accelerator::configureAGP(provider);
}

void ATIRadeonX1000::teardownAGP(IOService *provider) {
    IOATIR500Accelerator::teardownAGP(provider);
}

IOReturn ATIRadeonX1000::commitAGPMemory(IOMemoryDescriptor *memory, UInt32 agpOffset, UInt32 options) {
    return IOATIR500Accelerator::commitAGPMemory(memory, agpOffset, options);
}

IOReturn ATIRadeonX1000::releaseAGPMemory(IOMemoryDescriptor *memory, UInt32 agpOffset, UInt32 options) {
    return IOATIR500Accelerator::releaseAGPMemory(memory, agpOffset, options);
}

bool ATIRadeonX1000::mapVendorTransferBuffer(VendorTransferBuffer *buffer) {
    return IOATIR500Accelerator::mapVendorTransferBuffer(buffer);
}

void ATIRadeonX1000::unmapVendorTransferBuffer(VendorTransferBuffer *buffer) {
    IOATIR500Accelerator::unmapVendorTransferBuffer(buffer);
}

UInt32 ATIRadeonX1000::makeGARTEntry(UInt32 physicalAddress) {
    return (physicalAddress >> 8) | U32At(this, 0xbc0) | 0xc;
}

UInt32 ATIRadeonX1000::getAccelCapsBits() {
    return 3;
}

UInt32 ATIRadeonX1000::tmpTotalVRAM() {
    return reinterpret_cast<ATIR500Memory *>(U32At(this, 0x93c))->total_free();
}

bool ATIRadeonX1000::SWDSIsRequired() {
    return !(U32At(this, 0xb2c) == 0 && U32At(this, 0xb30) == 0);
}

/* Real: if display `index` has its SWDS "CLUT pending" bit (bit 1 of this+0xb2c+index*4) set and is an IONDRVFramebuffer,
 * waits 20 ms and sends it attribute 0xbf; on success clears the bit. */
bool ATIRadeonX1000::SWDSEnableCLUT(UInt32 index) {
    UInt32 value = 0;
    if ((U32At(this, index * 4 + 0xb2c) >> 1) != 0) {
        void *framebuffer = SmallX_safeMetaCast(reinterpret_cast<void *>(U32At(this, index * 0x20 + 0xd4)), GH_IONDRVFramebuffer_metaClass);
        if (framebuffer != nullptr) {
            SmallX_IOSleep(0x14);
            SetAttrFn setAttribute = *reinterpret_cast<SetAttrFn *>(*reinterpret_cast<UInt8 **>(framebuffer) + 0x70c);
            if (setAttribute(framebuffer, 0xbf, &value) == 0) {
                U32At(this, index * 4 + 0xb2c) &= 0xfffffffd;
                return true;
            }
        }
    }
    return false;
}

void ATIRadeonX1000::pageOffPCIeGART() {
}

void ATIRadeonX1000::removeFromGART(IOMemoryDescriptor *descriptor, UInt32 gartOffset) {
    removeFromPCIeGART(descriptor, gartOffset);
}

IOReturn ATIRadeonX1000::addToMinMaxGART(IOMemoryDescriptor *memory, UInt32 *outOffset, UInt32 minOffset, UInt32 maxOffset) {
    return addToPCIeGART(memory, outOffset, minOffset, maxOffset);
}

UInt32 ATIRadeonX1000::noop_buffer(UInt32 *buffer) {
    for (int i = 0; i < 8; ++i) {
        buffer[i] = 0x80000000;
    }
    return 8;
}

/* stamp checks: true when `tag` has passed. The cached value is refreshed from the hardware/stamp page only when the
 * cache says the tag is still ahead. */
bool ATIRadeonX1000::checkForConsumedIDCTTimeStamp(UInt32 tag) {
    if (0 < static_cast<SInt32>(tag - U32At(this, 0x85c))) {
        UInt8 *mmio = reinterpret_cast<UInt8 *>(U32At(this, 0x860));
        UInt32 value = ReadLE32(mmio + 0x1fa8);
        U32At(this, 0x85c) = value;
        if (0 < static_cast<SInt32>(tag - value)) {
            return false;
        }
    }
    return true;
}

bool ATIRadeonX1000::checkForRetiredTimeStamp(UInt32 tag) {
    if (0 < static_cast<SInt32>(tag - U32At(this, 0x858))) {
        UInt8 *p = reinterpret_cast<UInt8 *>(U32At(this, 0x864) + U32At(this, 0x868));
        UInt32 value = ReadLE32(p);
        U32At(this, 0x858) = value;
        if (0 < static_cast<SInt32>(tag - value)) {
            return false;
        }
    }
    return true;
}

bool ATIRadeonX1000::checkForTimeStamp(UInt32 tag) {
    if (0 < static_cast<SInt32>(tag - U32At(this, 0x54))) {
        UInt8 *p = reinterpret_cast<UInt8 *>(U32At(this, 0x864) + U32At(this, 0x86c));
        UInt32 value = ReadLE32(p);
        U32At(this, 0x54) = value;
        if (0 < static_cast<SInt32>(tag - value)) {
            return false;
        }
    }
    return true;
}

void ATIRadeonX1000::initialize_GUI() {
    UInt8 *mmio = reinterpret_cast<UInt8 *>(U32At(this, 0x860));
    *reinterpret_cast<UInt32 *>(mmio + 0x4c) = (static_cast<UInt32>(mmio[0x4c] & 0xffffffdfu) << 0x18) |
                                               (static_cast<UInt32>(mmio[0x4d]) << 0x10) |
                                               (static_cast<UInt32>(mmio[0x4e]) << 8) | mmio[0x4f];
    enforceInOrderExecutionIO();
    *reinterpret_cast<UInt32 *>(mmio + 0x208c) = 0;
    enforceInOrderExecutionIO();
    __asm__ __volatile__("sync" : : : "memory");
    instructionSynchronize();
}

UInt32 ATIRadeonX1000::submit_commands(VendorCommandDescriptor *descriptor) {
    UInt8 *d = reinterpret_cast<UInt8 *>(descriptor);
    return submit_buffer(reinterpret_cast<UInt32 *>(U32At(d, 0)), U32At(d, 4), U32At(d, 8));
}
