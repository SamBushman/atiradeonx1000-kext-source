/*
 * IOATIR500GLContext_Start.cpp
 *
 * IOATIR500GLContext::start - CONFIRMED, fully transcribed from a real
 * decompile (kext offset 0x7690). Previously unlocated - this is a
 * separate, distinct function from ATIR500GLContext::start (0x28540,
 * the 3D subclass's own start(), already transcribed in
 * Sources/ATIR500GLContext_RegisterState.cpp's sibling files), and is
 * the real answer to a long-standing open question (issue #10): it's the
 * function that populates `regularMethodTable` at +0x2a0.
 *
 * Also, on the success path, allocates this context's IOATIR500Shared
 * handle and links the context into the accelerator's live-context list
 * at accelerator+0x60 - independently confirming
 * IOATIR500Accelerator::liveGLContextListHead's offset from the writer
 * side (previously only known from freeWaitToAllocGART's reader side).
 *
 * Confidence: CONFIRMED for control flow and every field offset touched.
 * The large zero-init block (this+0x7c..this+0x2a4ish) is transcribed
 * offset-by-offset from the real decompile, but most of those individual
 * fields' semantic roles are UNKNOWN beyond "zeroed at context start" -
 * named narratively below rather than invented, matching this project's
 * existing convention for ATIR500GLContext::start's own zero-init block.
 * `allocAllContextBuffers`, `getVRAMDescriptors`, and `allocCommandBuffer`
 * are called but not independently decompiled - see their declarations
 * in IOATIR500GLContext.h / IOATIR500Accelerator.h.
 */

#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Shared.h"
#include "../Headers/ATIRadeonX1000Types.h"

/* FIXED (issue #1, first build attempt): was a local (function-scope)
 * `extern "C" ...` declaration. gcc-4.0.1's C++03 grammar does not
 * allow a linkage-specification as a block-declaration at all - a real
 * syntax error, not a portability nit. Hoisted to file scope, same real
 * target. */
extern "C" void IOATIR500Shared_release(IOATIR500Shared *) asm("__ZNK8OSObject7releaseEv");

bool IOATIR500GLContext::start(IOService *provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

    if (!IOUserClient::start(provider)) {
        return false;
    }

    accelerator = reinterpret_cast<ATIRadeonX1000 *>(provider);

    /*
     * Real zero-init block. Every offset below is a real, literal write
     * confirmed from the decompile; field roles beyond "cleared here" are
     * UNKNOWN except where separately named (methodTable slots, the
     * six-entry-ish small arrays at +0x9c/+0x10c). Left as raw offsets
     * rather than invented names, matching ATIR500GLContext::start's own
     * documented convention for its analogous block.
     */
    *reinterpret_cast<UInt32 *>(self + 0x108) = 0;
    *reinterpret_cast<UInt32 *>(self + 0x294) = 0;
    *reinterpret_cast<UInt32 *>(self + 0x7c) = 0;
    *reinterpret_cast<UInt16 *>(self + 0xd8) = 1;
    *reinterpret_cast<UInt16 *>(self + 0xac) = 1;
    *reinterpret_cast<UInt32 *>(self + 0x290) = 0;
    *reinterpret_cast<UInt32 *>(self + 0x298) = 0;
    *reinterpret_cast<UInt32 *>(self + 0x29c) = 0;
    *reinterpret_cast<UInt32 *>(self + 0x88) = 0;   /* clientHandle, re-set below once allocated */
    *reinterpret_cast<UInt32 *>(self + 0x84) = 0;
    *reinterpret_cast<UInt32 *>(self + 0xcc) = 0;
    *reinterpret_cast<UInt32 *>(self + 0xd0) = 0;
    *reinterpret_cast<UInt32 *>(self + 0xd4) = 0;
    *reinterpret_cast<UInt16 *>(self + 0xda) = 0;
    *reinterpret_cast<UInt32 *>(self + 0xdc) = 0;
    *reinterpret_cast<UInt32 *>(self + 0xe0) = 0;
    *reinterpret_cast<UInt32 *>(self + 0xe4) = 0;
    *reinterpret_cast<UInt32 *>(self + 0xe8) = 0;
    *reinterpret_cast<UInt32 *>(self + 0xec) = 0;
    *reinterpret_cast<UInt32 *>(self + 0xf0) = 0;
    *reinterpret_cast<UInt32 *>(self + 0x28c) = 0;
    *reinterpret_cast<UInt32 *>(self + 0xf4) = 0;
    *reinterpret_cast<UInt32 *>(self + 0xf8) = 0;
    *reinterpret_cast<UInt32 *>(self + 0xfc) = 0;
    *reinterpret_cast<UInt16 *>(self + 0x102) = 0;
    *reinterpret_cast<UInt16 *>(self + 0x100) = 0;
    *reinterpret_cast<UInt32 *>(self + 0x104) = 0;
    *reinterpret_cast<UInt16 *>(self + 0xae) = 6;
    *reinterpret_cast<UInt32 *>(self + 0xb0) = 0x20000;
    *reinterpret_cast<UInt32 *>(self + 0xb4) = 0x10000;

    /* Real 16-entry array at this+0x10c, stride 0x18 - role UNKNOWN
     * beyond "per-slot state, zeroed at start", plausibly a resource or
     * buffer-slot table given the stride and count. */
    for (UInt8 *slot = self; slot < self + 0x10 * 0x18; slot += 0x18) {
        *reinterpret_cast<UInt32 *>(slot + 0x10c) = 0;
        *reinterpret_cast<UInt32 *>(slot + 0x110) = 0;
        *reinterpret_cast<UInt32 *>(slot + 0x114) = 0;
        *reinterpret_cast<UInt16 *>(slot + 0x11a) = 0;
        *reinterpret_cast<UInt16 *>(slot + 0x118) = 0;
        *reinterpret_cast<UInt32 *>(slot + 0x11c) = 0;
        *reinterpret_cast<UInt32 *>(slot + 0x120) = 0;
    }

    *reinterpret_cast<UInt16 *>(self + 0x98) = 0;
    *reinterpret_cast<UInt16 *>(self + 0x90) = 0;
    *reinterpret_cast<UInt16 *>(self + 0x92) = 0;
    *reinterpret_cast<UInt16 *>(self + 0x94) = 0;
    *reinterpret_cast<UInt16 *>(self + 0x9a) = 1;
    *reinterpret_cast<UInt16 *>(self + 0x96) = 0;

    /* Real 3-entry array at this+0x9c, stride 4 - role UNKNOWN. */
    for (int i = 0; i < 3; i++) {
        *reinterpret_cast<UInt32 *>(self + 0x9c + i * 4) = 0;
    }

    *reinterpret_cast<UInt32 *>(self + 0xc4) = 0;
    *reinterpret_cast<UInt32 *>(self + 0x8c) = 0x20000000;

    /* Real 0x2a-word (0xa8-byte) block at this+0x2a4 - role UNKNOWN,
     * immediately precedes regularMethodTable at +0x2a0 (this array
     * starts right after it). */
    for (int i = 0; i < 0x2a; i++) {
        *reinterpret_cast<UInt32 *>(self + 0x2a4 + i * 4) = 0;
    }

    /*
     * Real IOATIR500Shared allocation - stored at clientHandle (+0x88).
     * On the real decompile: allocate 0x28 bytes, placement-construct a
     * real IOATIR500Shared, then (if a real vtable init call at +0x48
     * succeeds) wire it to this context's task/accelerator and link into
     * the accelerator's live-context list; on failure, release it via a
     * real vtable call at +0x18 (free/release) and clear the field.
     */
    clientHandle = new IOATIR500Shared();
    if (clientHandle == nullptr) {
        stop(provider);
        return false;
    }

    /* Real vtable call at +0x48 RESOLVED (issue #20): `init()` (see
     * IOATIR500Shared.h). The +0x18 (release) call is likewise RESOLVED,
     * issue #20 (live kxld-resolved memory read on real G5/Tiger
     * hardware - exact match to `OSObject::release() const` in the
     * running kernel's own symbol table) - called directly below via its
     * real mangled symbol rather than a raw vtable-offset cast. Its real
     * decompile showed it called with NO visible argument at all - a
     * decompiler artifact (a real `release()` needs its own `this`),
     * passed here for correctness, same as before. */
    if (clientHandle->init() == 0) {
        IOATIR500Shared_release(clientHandle);
        clientHandle = nullptr;
        stop(provider);
        return false;
    }

    /* CONFIRMED: real writes at clientHandle+0xc (task*, from this+200)
     * and clientHandle+8 (from this+0x78 - role of this+0x78 itself
     * UNKNOWN, not independently traced this pass). */
    *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(clientHandle) + 0xc) =
        *reinterpret_cast<void **>(self + 200);
    *reinterpret_cast<void **>(reinterpret_cast<UInt8 *>(clientHandle) + 8) =
        *reinterpret_cast<void **>(self + 0x78);

    /*
     * ATIRadeonX1000::setup3D - RESOLVED (issue #19; real vtable slot
     * +0x530). Gated on the accelerator having NO live GL context
     * (accel+0x60 == 0, liveGLContextListHead) AND no live DVD context
     * (accel+0x68 == 0, liveDVDContextListHead) - i.e. only runs once,
     * for the first live GL-or-DVD context. INFERRED role beyond the
     * real name: some kind of shared first-open hardware/state setup;
     * own body not independently decompiled this pass. Real return
     * value IS checked (`if (iVar3 == 0) goto failure`) - previously
     * left as a comment-only note, never actually wired into this
     * function's own compiled code path; now wired in via the same
     * failure path as everything else here.
     */
    UInt8 *accel = reinterpret_cast<UInt8 *>(accelerator);
    if (*reinterpret_cast<UInt32 *>(accel + 0x60) == 0 &&
        *reinterpret_cast<UInt32 *>(accel + 0x68) == 0) {
        if (accelerator->setup3D() == 0) {
            stop(provider);
            return false;
        }
    }

    /*
     * CONFIRMED, real singly-linked-list push: this context's own
     * nextLiveContext (+0x80 - a real, previously-undocumented field,
     * NEW finding this pass) is set to the accelerator's current list
     * head, then the accelerator's head (+0x60,
     * liveGLContextListHead - CONFIRMED from this write site, see
     * IOATIR500Accelerator.h) is set to `this`. Classic head-insertion;
     * this+0x80 is the intrusive "next" link every live GL context
     * carries.
     */
    nextLiveContext = *reinterpret_cast<IOATIR500GLContext **>(accel + 0x60);
    *reinterpret_cast<IOATIR500GLContext **>(accel + 0x60) = this;

    /* CONFIRMED: real increment of a counter at accelerator's own
     * provider+0x738 (open-context or similar count; role UNKNOWN). */
    UInt8 *acceleratorsProvider = *reinterpret_cast<UInt8 **>(accel + 200);
    *reinterpret_cast<UInt32 *>(acceleratorsProvider + 0x738) += 1;

    if (accelerator->getVRAMDescriptors() &&
        accelerator->allocCommandBuffer(
            reinterpret_cast<VendorCommandBuffer *>(self + 0xcc), 0x20000) &&
        allocAllContextBuffers(0x8000)) {
        *reinterpret_cast<UInt32 *>(self + 0x294) = 1;

        /*
         * RESOLVED (issue #10): this is the real, previously-unlocated
         * write that populates regularMethodTable, pointing it at the
         * same real static table already transcribed into
         * Sources/IOATIR500GLContext_ExternalMethods.cpp (there named
         * kGLRegularMethods; Ghidra's own name for it, derived from its
         * enclosing function, is `start(IOService*)::methodDescs`).
         */
        extern const VendorExternalMethod kGLRegularMethods[20];
        regularMethodTable = const_cast<VendorExternalMethod *>(kGLRegularMethods);

        return true;
    }

    stop(provider);
    return false;
}
