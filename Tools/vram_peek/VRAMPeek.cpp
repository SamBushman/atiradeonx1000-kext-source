/*
 * VRAMPeek.cpp - issue #92 follow-up: a small, SEPARATE, read-only diagnostic kext (same class and safety pattern as Tools/ga_probe/GAProbe.cpp,
 * used without incident across #141/#142/#144's investigations) to read back DVD write_buffer's actual blitted pixel content.
 *
 * Pass 1 (BAR discovery, already run and logged): write_buffer's target slot addresses (e.g. 0x08eb0000, observed via lock_all_buffers) do NOT
 * fall inside the accelerator's own VRAM/framebuffer PCI BAR (BAR[0], physAddr=0x98000000, length 128MB) - so they are not raw PCI physical
 * addresses needing BAR-relative mapping at all. They match this project's own already-established convention for the completion-stamp address
 * (GAProbe: `*(UInt8*)(stamp_base + stamp_off)`, a direct kernel-virtual-address dereference, no BAR mapping) - the surface buffer descriptor's
 * own `+8` address field is itself a kernel-authored, directly-dereferencable kernel virtual pointer.
 *
 * Pass 2 (this file): given a target kernel virtual address (TARGET_ADDR, baked in at build time from a FRESH lock_all_buffers/write_buffer run -
 * these addresses are not stable across runs, so this must be rebuilt+reloaded with a just-discovered address while the owning DVD connection/
 * surface is still alive, same "known-good address, not a guess" safety class as every other direct-dereference read this project has done
 * safely so far - never a scan), dumps TARGET_LEN bytes from that address via IOLog as hex.
 */
#include <IOKit/IOLib.h>
#include <IOKit/IOService.h>
#include <libkern/c++/OSIterator.h>

#ifndef TARGET_ADDR
#define TARGET_ADDR 0  /* must be overridden at build time: -DTARGET_ADDR=0x... */
#endif
#ifndef TARGET_LEN
#define TARGET_LEN 0x3000  /* 3 rows at pitch 0xc00, covers the 4x4 write_buffer blit's first 3 of 4 rows */
#endif

extern "C" kern_return_t VRAMPeek_start(kmod_info_t *ki, void *data);
extern "C" kern_return_t VRAMPeek_stop(kmod_info_t *ki, void *data);

extern "C" kern_return_t VRAMPeek_start(kmod_info_t *ki, void *data) {
    IOLog("VRAMPeek: start, TARGET_ADDR=0x%08x TARGET_LEN=0x%x\n", (unsigned)TARGET_ADDR, (unsigned)TARGET_LEN);
    if (TARGET_ADDR == 0) { IOLog("VRAMPeek: TARGET_ADDR not set, nothing to do\n"); return KERN_SUCCESS; }
    volatile UInt8 *p = (volatile UInt8 *)(UInt32)TARGET_ADDR;
    char line[128]; int lo = 0;
    for (unsigned i = 0; i < (unsigned)TARGET_LEN; i++) {
        if (i % 32 == 0) { if (i) { line[lo] = 0; IOLog("VRAMPeek[+0x%04x]: %s\n", i - 32, line); } lo = 0; }
        lo += snprintf(line + lo, sizeof(line) - lo, "%02x ", p[i]);
    }
    if (lo) { line[lo] = 0; IOLog("VRAMPeek[+0x%04x]: %s\n", (unsigned)(TARGET_LEN - (TARGET_LEN % 32 ? TARGET_LEN % 32 : 32)), line); }
    IOLog("VRAMPeek: dump done\n");
    return KERN_SUCCESS;
}

extern "C" kern_return_t VRAMPeek_stop(kmod_info_t *ki, void *data) {
    IOLog("VRAMPeek: stop\n");
    return KERN_SUCCESS;
}
