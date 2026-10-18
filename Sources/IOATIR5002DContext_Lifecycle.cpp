/*
 * IOATIR5002DContext_Lifecycle.cpp
 *
 * RESOLVED (ledger pass): the lifecycle members of IOATIR5002DContext (the 2D/QuickDraw user-client base class),
 * transcribed from the shipped kext (real addrs in parentheses):
 *   start (0xc0a0, vtable +0x348)   stop (0xb7f0, +0x34c)   clientClose (0xba30, +0x568)
 *   init_command_buffer_header (0xbab0)   remove_surface (0xbb30)
 *
 * Field offsets (this): +0x78 owning task, +0x7c current stamp, +0x80 next context in the accelerator's 2D list,
 * +0x84/+0x88 shared allocator, +0x8c required-bits word, +0x92/+0x93 flags, +0x94 accelerator, +0x98..+0xb0 the
 * live VendorCommandBuffer (0xa0 = its IOMemoryDescriptor), +0xbc context-buffer descriptor, +0xc8 context-buffer
 * header, +0xcc.. two 0x18-byte transfer-buffer slots, +0xfc current slot, +0x100 bound surface, +0x104/+0x118/+0x11c
 * mapped surface descriptor / its IOMemoryMap / mapped address, +0x108 "started" flag, +0x10c method table,
 * +0x110 fallback framebuffer index, +0x114 last bound texture.
 * Accelerator: +0x64 head of the live 2D-context list, +0x734 open-context count, +0x78 last submitting context,
 * vtable +0x534 setup2D(), +0x53c teardown2D().
 *
 * The qualified base-class calls (`IOUserClient::start/stop`, which the shipped code reaches through the
 * IOUserClient vtable symbol) are written as qualified calls; -fapple-kext compiles those the same way.
 */

#include "../Headers/IOATIR5002DContext.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Surface.h"

extern const VendorExternalMethod kTwoDBaseMethods[16] asm("__ZZN18IOATIR5002DContext5startEP9IOServiceE11methodDescs");

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
typedef UInt32 (*AccelSetupFn)(void *);
typedef void (*AccelTeardownFn)(void *);
} // namespace

bool IOATIR5002DContext::start(IOService *provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    if (!IOUserClient::start(provider)) {
        return false;
    }
    U32At(self, kIOATIR5002DContext_contextBufferHeader) = 0;
    accelerator = reinterpret_cast<ATIRadeonX1000 *>(provider);
    U32At(self, kIOATIR5002DContext_started) = 0;
    U32At(self, kIOATIR5002DContext_lastSubmitStamp) = 0;
    U32At(self, kIOATIR5002DContext_boundSurface) = 0;
    U32At(self, kIOATIR5002DContext_sharedAllocator) = 0;
    U32At(self, kIOATIR5002DContext_nextContext) = 0;
    U32At(self, kIOATIR5002DContext_panelIndex) = 0;
    U16At(self, kIOATIR5002DContext_unknown_0x90) = 0;
    U32At(self, kIOATIR5002DContext_commandBuffer) = 0;
    U32At(self, kIOATIR5002DContext_commandBufferGartOffset) = 0;
    U32At(self, kIOATIR5002DContext_commandBufferDescriptor) = 0;
    U16At(self, kIOATIR5002DContext_commandBufferInFlight) = 0;
    U32At(self, kIOATIR5002DContext_commandBufferStamp) = 0;
    U32At(self, kIOATIR5002DContext_commandBufferHeader) = 0;
    U32At(self, kIOATIR5002DContext_commandBufferSize) = 0;
    U32At(self, kIOATIR5002DContext_contextBufferRingIndex) = 0;
    U32At(self, kIOATIR5002DContext_contextBuffer) = 0;
    U32At(self, kIOATIR5002DContext_contextBufferGartOffset) = 0;
    U32At(self, kIOATIR5002DContext_contextBufferDescriptor) = 0;
    U16At(self, kIOATIR5002DContext_contextBufferInFlight) = 0;
    U16At(self, kIOATIR5002DContext_contextBufferType) = 0;
    U32At(self, kIOATIR5002DContext_contextBufferStamp) = 0;
    U8At(self, kIOATIR5002DContext_unknown_0x93) = 0;
    U16At(self, kIOATIR5002DContext_commandBufferType) = 1;
    U8At(self, kIOATIR5002DContext_surfaceBackingReplaced) = 0;
    for (int i = 0; i < 2; ++i) {
        UInt8 *slot = self + i * 0x18;
        U32At(slot, 0xcc) = 0;
        U32At(slot, 0xd0) = 0;
        U32At(slot, 0xd4) = 0;
        U16At(slot, 0xda) = 0;
        U16At(slot, 0xd8) = 0;
        U32At(slot, 0xdc) = 0;
        U32At(slot, 0xe0) = 0;
    }
    U32At(self, kIOATIR5002DContext_surfaceMapAddress) = 0;
    U32At(self, kIOATIR5002DContext_lastBoundTexture) = 0;
    U32At(self, kIOATIR5002DContext_mappedDescriptor) = 0;
    U32At(self, kIOATIR5002DContext_surfaceMemoryMap) = 0;
    U32At(self, kIOATIR5002DContext_surfaceFlagsBitmask) = 0x20000000;

    UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, kIOATIR5002DContext_accelerator));
    if (U32At(accel, 0x64) == 0) {
        AccelSetupFn setup2D = *reinterpret_cast<AccelSetupFn *>(*reinterpret_cast<UInt8 **>(accel) + 0x534);
        if (setup2D(accel) == 0) {
            IOATIR5002DContext::stop(provider);
            return false;
        }
        accel = reinterpret_cast<UInt8 *>(U32At(self, kIOATIR5002DContext_accelerator));
    }
    U32At(self, kIOATIR5002DContext_nextLiveContext) = U32At(accel, 0x64);
    U32At(accel, 0x64) = reinterpret_cast<UInt32>(this);
    U32At(reinterpret_cast<void *>(U32At(self, kIOATIR5002DContext_accelerator)), 0x734) += 1;
    if (accelerator->getVRAMDescriptors() &&
        accelerator->allocCommandBuffer(reinterpret_cast<VendorCommandBuffer *>(self + kIOATIR5002DContext_commandBuffer), 0x1000) &&
        allocAllContextBuffers(0x1000)) {
        U32At(self, kIOATIR5002DContext_started) = 1;
        U32At(self, kIOATIR5002DContext_baseMethodTable) = reinterpret_cast<UInt32>(kTwoDBaseMethods);
        return true;
    }
    IOATIR5002DContext::stop(provider);
    return false;
}

void IOATIR5002DContext::stop(IOService *provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    U32At(self, kIOATIR5002DContext_started) = 0;
    if (U32At(self, kIOATIR5002DContext_surfaceMemoryMap) != 0) {
        reinterpret_cast<OSObject *>(U32At(self, kIOATIR5002DContext_surfaceMemoryMap))->release();
        U32At(self, kIOATIR5002DContext_surfaceMapAddress) = 0;
        U32At(self, kIOATIR5002DContext_surfaceMemoryMap) = 0;
    }

    /* unlink from the accelerator's singly-linked list of live 2D contexts (head at accelerator+0x64) */
    UInt8 *accel = reinterpret_cast<UInt8 *>(U32At(self, kIOATIR5002DContext_accelerator));
    UInt8 *head = reinterpret_cast<UInt8 *>(U32At(accel, 0x64));
    if (self == head) {
        U32At(accel, 0x64) = U32At(self, kIOATIR5002DContext_nextLiveContext);
        accel = reinterpret_cast<UInt8 *>(U32At(self, kIOATIR5002DContext_accelerator));
        if (U32At(accel, 0x64) == 0) {
            AccelTeardownFn teardown2D = *reinterpret_cast<AccelTeardownFn *>(*reinterpret_cast<UInt8 **>(accel) + 0x53c);
            teardown2D(accel);
            accel = reinterpret_cast<UInt8 *>(U32At(self, kIOATIR5002DContext_accelerator));
        }
    } else {
        UInt8 *prev;
        do {
            prev = head;
            head = reinterpret_cast<UInt8 *>(U32At(prev, 0x80));
            if (head == nullptr) {
                break;
            }
        } while (self != head);
        U32At(prev, 0x80) = U32At(self, kIOATIR5002DContext_nextLiveContext);
    }
    U32At(accel, 0x734) -= 1;

    /* drop every other live 2D context's client mapping of this context's command-buffer descriptor */
    if (U32At(self, kIOATIR5002DContext_commandBufferDescriptor) != 0) {
        UInt8 *ctx = reinterpret_cast<UInt8 *>(U32At(reinterpret_cast<void *>(U32At(self, kIOATIR5002DContext_accelerator)), 0x64));
        if (ctx != nullptr) {
            for (;;) {
                IOMemoryMap *map = reinterpret_cast<IOATIR5002DContext *>(ctx)->removeMappingForDescriptor(
                    reinterpret_cast<IOMemoryDescriptor *>(U32At(self, kIOATIR5002DContext_commandBufferDescriptor)));
                if (map != nullptr) {
                    map->release();
                }
                ctx = reinterpret_cast<UInt8 *>(U32At(ctx, 0x80));
                if (ctx == nullptr) {
                    break;
                }
            }
        }
    }
    if (U32At(self, kIOATIR5002DContext_contextBufferDescriptor) != 0) {
        freeAllContextBuffers();
    }
    if (U32At(self, kIOATIR5002DContext_commandBufferDescriptor) != 0) {
        accelerator->freeCommandBuffer(reinterpret_cast<VendorCommandBuffer *>(self + kIOATIR5002DContext_commandBuffer));
    }
    accel = reinterpret_cast<UInt8 *>(U32At(self, kIOATIR5002DContext_accelerator));
    if (self == reinterpret_cast<UInt8 *>(U32At(accel, 0x78))) {
        U32At(accel, 0x78) = 0;
    }
    if (boundSurface != nullptr) {
        boundSurface->remove_2d_context_from_list(this);
        boundSurface->prune_buffers();
        boundSurface = nullptr;
    }
    if (U32At(self, kIOATIR5002DContext_sharedAllocator) != 0) {
        reinterpret_cast<OSObject *>(U32At(self, kIOATIR5002DContext_sharedAllocator))->release();
        U32At(self, kIOATIR5002DContext_sharedAllocator) = 0;
    }
    IOUserClient::stop(provider);
}

/* Real: only if the started flag is set, stop() then detach() from the accelerator (vtable +0x34c / +0x3a8). */
IOReturn IOATIR5002DContext::clientClose() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    if (U32At(self, kIOATIR5002DContext_started) != 0) {
        IOService *provider = reinterpret_cast<IOService *>(U32At(self, kIOATIR5002DContext_accelerator));
        this->stop(provider);
        this->detach(provider);
    }
    return 0;
}

void IOATIR5002DContext::init_command_buffer_header(VendorCommandBufferHeader *header, UInt32 size, UInt32 flags) {
    UInt8 *h = reinterpret_cast<UInt8 *>(header);
    for (int i = 0; i < 8; ++i) {
        U32At(h, i * 4) = 0;
    }
    U32At(h, 0x14) = flags;
    U32At(h, 0x20) = 0x1000000;
    U32At(h, 0x10) = (size - 0x20) >> 2;
    U32At(h, 0x1c) = 1;
}

void IOATIR5002DContext::remove_surface() {
    U32At(this, kIOATIR5002DContext_boundSurface) = 0;
}
