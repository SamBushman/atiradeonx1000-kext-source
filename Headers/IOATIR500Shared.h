/*
 * IOATIR500Shared.h
 *
 * A real class this project has not reconstructed - found this pass only
 * as IOATIR500GLContext::start's real allocation site (`new`'d as a
 * 0x28-byte object, default-constructed, then a real vtable call at
 * +0x48 that must succeed or the object is released via another real
 * vtable call at +0x18). Forward-declared and referenced elsewhere in
 * this project (e.g. IOATIR500Accelerator.h) as the concrete type behind
 * every context class's `clientHandle` field, but its own real method
 * set, field layout, and base class are all UNKNOWN. Left as a minimal
 * shell rather than inventing an interface this project hasn't actually
 * decompiled - see GAPS.md.
 */

#ifndef IOATIR500SHARED_H
#define IOATIR500SHARED_H

#include <libkern/c++/OSObject.h>
#include "ATIRadeonX1000Types.h"

class IOATIR500Accelerator;
class IOTextureBuffer;

/*
 * sIOClientShared - a real, previously-unnamed 0x40-byte per-handle
 * record shape `alloc_client_shared` (below) carves out of its own
 * 0x2000-byte mapped chunks. Own field layout genuinely UNKNOWN beyond
 * the handful of byte offsets `alloc_client_shared`'s own real body
 * zeroes/initializes (see Sources/IOATIR500Shared_TextureAlloc.cpp) -
 * left forward-declared-only (never defined), matching this project's
 * established convention of not inventing an interface it hasn't
 * actually decompiled. Every real user only ever holds a raw pointer to
 * one.
 */
class sIOClientShared;

/*
 * CORRECTED (issue #58 follow-up): this class IS an OSObject subclass in the
 * real kext (real symbols `IOATIR500Shared::MetaClass`, `gMetaClass`,
 * `getMetaClass`, `MetaClass::alloc`, `init` at vtable slot +0x48 = the
 * OSObject::init() override slot), but was modelled as a plain class with no
 * vptr: the object's first word was never a vtable, so the `+0x18`
 * (`OSObject::release() const`) call the driver makes through it would have
 * jumped through garbage, and the OSObject::init() the real `init()` calls
 * first (`IOATIR500Shared_super_init`) had no definition. Now generated via
 * OSDeclareDefaultStructors/OSDefineMetaClassAndStructors
 * (Sources/MetaClassRegistration.cpp). Real size 0x28 = sizeof(OSObject) (8) + pad.
 */
class IOATIR500Shared : public OSObject {
    OSDeclareDefaultStructors(IOATIR500Shared)
public:
    /*
     * Real size CONFIRMED (0x28 bytes, from its allocation site). FIXED
     * (issue #1): this class declares zero real C++ data members (every
     * real field is accessed by raw offset elsewhere, not by name - see
     * Sources/IOATIR500Shared_Init.cpp/_AllocHandles.cpp), which without
     * this trailing pad would make `sizeof(IOATIR500Shared)` far smaller
     * than the real 0x28-byte object - a real heap-corruption risk the
     * moment `init()`'s own raw writes up to `self+0x24` ran against an
     * undersized `new`allocation. Matches this project's own established
     * "confirmed size, unconfirmed field breakdown" pad convention
     * (e.g. ATIRadeonX1000Types.h's `_trailer_unconfirmed`). Now 0x20 because
     * the OSObject base supplies the first 8 bytes (vptr + retainCount).
     */
    UInt8 _pad_confirmed_size[0x20];

    /*
     * init - RESOLVED, issue #20/#24. Real vtable slot `+0x48`, real
     * addr `0x16aa0` - found by reading this class's own vtable
     * (`__ZTV15IOATIR500Shared`, `0x48f28`) directly, the same technique
     * that resolved issues #6/#18/#19. Real body (issue #24): calls a
     * `OSObject::init()`
     * first (RESOLVED, issue #58 follow-up: a qualified base call compiled as
     * an indirect call through the OSObject vtable symbol; slot +0x48 of the
     * real kernel's OSObject vtable is `OSObject::init()`), then zeroes six real
     * fields and calls `alloc_handles()` - see
     * `Sources/IOATIR500Shared_Init.cpp` for the full transcription.
     *
     * The paired real `+0x18` (release-like) vtable call this class's
     * own real constructor-site failure path also makes is RESOLVED,
     * issue #20: a live kxld-resolved memory read on real G5/Tiger
     * hardware (the exact kext loaded and running, `kextstat` giving the
     * real load address, the loaded image's own live Mach-O load
     * commands giving the real per-segment slide) showed the real,
     * kxld-patched runtime pointer value at this slot - an EXACT
     * (offset-0) match, in `nm /mach_kernel`'s own symbol table, to
     * `OSObject::release() const` (`__ZNK8OSObject7releaseEv`). This
     * class inherits `release()` unoverridden from `OSObject`, exactly
     * as expected for a lightweight IOKit-derived allocator with no
     * special teardown of its own. No custom kext code was written or
     * loaded to obtain this - a plain, read-only userspace `/dev/kmem`
     * reader, validated against the already-CONFIRMED `init()` slot
     * before being trusted on this one.
     */
    virtual bool init();

    /*
     * free / free_handles - RESOLVED (issue #58 follow-up), real addrs
     * 0x184d0 / 0x16b30. `free` (OSObject::free override, vtable slot +0x4c)
     * deletes every live texture on the shared list, unhooks itself from its
     * owning accelerator, frees the accelerator's orphan textures, releases and
     * frees the client-shared chunk list, calls `free_handles`, then
     * `OSObject::free()`. See Sources/IOATIR500Shared_Free.cpp.
     */
    virtual void free();
    void free_handles();

    /*
     * alloc_handles - RESOLVED, issue #28. Real mangled symbol
     * __ZN15IOATIR500Shared13alloc_handlesEv, kext offset 0x16910,
     * called unconditionally from `init()` above (return value discarded
     * there). Real body: grows a combined handle-array+bitmap allocation,
     * doubling capacity each call - see
     * `Sources/IOATIR500Shared_AllocHandles.cpp` for the full
     * transcription. REAL RETURN TYPE CORRECTED to `bool` (was declared
     * `void`) - the real decompiled body returns a real success/failure
     * boolean, simply never checked at its one known call site.
     */
    bool alloc_handles();

    /*
     * delete_texture - CONFIRMED real name/signature (real mangled
     * symbol __ZN15IOATIR500Shared14delete_textureEP19VendorTextureBuffer,
     * kext offset 0x17950), found this pass (issue #7) as a real call
     * site in ATIR500DVDContext::process_command_buffer's texture-
     * unbind family. Real gating pattern at every call site: only
     * invoked after a real refcount-style helper (this project's
     * FUN_0003911c) returns exactly 1, i.e. "this was the last
     * reference". Own body NOT independently decompiled this pass. Also
     * declared (not yet reconstructed) elsewhere in this project's
     * comments: new_agp_texture/new_texture - the same real allocator
     * GL/2D's declare_image/create_image call through.
     */
    IOReturn delete_texture(VendorTextureBuffer *texture); /* RETURN TYPE CORRECTED (issue #1, get-it-linking pass): was declared void, but the real confirmed call site (IOATIR500GLContext::delete_texture) assigns and returns its result - a real, checked IOReturn value, not void. */

    /*
     * new_surface_texture / new_global_texture / new_texture /
     * new_agpref_texture - CONFIRMED to exist (real call sites in
     * IOATIR500GLContext::new_texture, issue #1 get-it-linking pass -
     * this class's own real allocator family, anticipated but not
     * previously declared - see delete_texture's own comment above).
     * Real signatures INFERRED from their call sites' own argument
     * shapes (own bodies NOT independently decompiled this pass -
     * genuine gap, tracked for follow-up, not guessed at beyond what
     * the call sites themselves establish). All four return what the
     * real call sites treat as a `VendorTextureBuffer*`-shaped handle
     * (non-null on success, passed straight into further vtable calls
     * taking that exact type elsewhere in this project).
     */
    VendorTextureBuffer *new_surface_texture(UInt32 param2, UInt32 param3, UInt32 param4, UInt32 *outParam);
    VendorTextureBuffer *new_global_texture(UInt32 param2, UInt32 *outParam);
    VendorTextureBuffer *new_texture(UInt32 param2, UInt32 param3, UInt32 param4, UInt32 param5, UInt32 *out1, UInt32 *out2);
    VendorTextureBuffer *new_agpref_texture(UInt32 param2, UInt32 param3, UInt32 param4, UInt32 *outParam);

    /*
     * freeToAllocGART - RESOLVED (issue #1, get-it-linking pass), real
     * addr 0x17060. Walks this shared allocator's own texture list
     * (`this+0x24`, same list `delete_texture` above already
     * establishes), and for every kind-4 (own AGP-mapped buffer, marks
     * a real "pending release" flag at `clientShared+0x14`) or kind-3/7
     * (per-format cleanup kinds) entry, tries
     * `IOATIR500Accelerator::freeTransferToAllocGART` with the
     * clientShared's own `+8`/`+0xc` field as the per-candidate arg -
     * stopping at the first success.
     */
    bool freeToAllocGART(VendorTransferBuffer *needed, bool aggressive);

    /*
     * new_agp_texture / alloc_buf_handle / free_buf_handle /
     * alloc_client_shared - RESOLVED (issue #1 gap-fill pass), real
     * previously-undeclared helpers found decompiling the texture-alloc
     * family above. All four bodies transcribed in
     * `Sources/IOATIR500Shared_TextureAlloc.cpp` - see that file's own
     * header comment for full detail (real addrs 0x17150/0x16bb0/0x16cf0/
     * 0x16d50).
     *
     * `new_agp_texture` real addr 0x17150: the shared AGP-texture
     * allocator `new_texture`/`new_agpref_texture` both call through -
     * real signature INFERRED from those two real call sites.
     *
     * `alloc_buf_handle`/`free_buf_handle` real addrs 0x16bb0/0x16cf0: a
     * real growable bitmap-based handle table living in the SAME
     * `this+0x10`/`+0x14`/`+0x18` fields `alloc_handles()` (issue #28)
     * already established - `alloc_buf_handle` finds/marks a free bit
     * (growing via `alloc_handles()` if none free) and stores `record` at
     * that index; `free_buf_handle` clears the bit if `record` still
     * matches what's stored there.
     *
     * `alloc_client_shared` real addr 0x16d50: a real growable linked
     * list of 0x2000-byte "shared chunk" nodes (`this+0x20`), each
     * subdivided into 0x80 client-visible 0x40-byte `sIOClientShared`
     * slots, mapped once into the owning client task and once into the
     * kernel task (real `IOBufferMemoryDescriptor::inTaskWithOptions` +
     * `IOMemoryDescriptor::map` pair) - grows by allocating another
     * 0x2000-byte chunk/mapping pair when every existing chunk's 0x80
     * slots are already assigned.
     */
    VendorTextureBuffer *new_agp_texture(UInt32 param1, UInt32 param2, UInt32 *outParam);
    bool alloc_buf_handle(void *record, UInt32 *outHandle);
    void free_buf_handle(void *record, UInt32 handle);
    bool alloc_client_shared(UInt32 index, sIOClientShared **outKernelPtr, UInt32 *outUserAddr);

    /*
     * free_texvert - RESOLVED (issue #1, get-it-linking pass), real
     * addr 0x18710. A real STATIC method (the real decompile calls it
     * as `IOATIR500Shared::free_texvert(accel, texture)` with an
     * explicit accelerator argument, never through an instance) - the
     * accelerator's own orphan-texture teardown leaf, called from
     * `IOATIR500Accelerator::freeOrphanTexture`. Unlinks `texture` from
     * its own doubly-linked list (`+0x24`/`+0x28`, the same shape
     * `delete_texture` already establishes), releases its GART mapping
     * via the accelerator's own `removeTransferFromGART` if it has a
     * real backing descriptor (`+4`!=0), frees its handle via its own
     * owner's `free_buf_handle` if it has one (`+0x1c`), releases its
     * `memoryDescriptor` (`+8`) for kind values 3-7 inclusive, then
     * returns it to the accelerator's own pool via
     * `releaseVendorTextureBuffer` - real size argument `0xc0` for
     * kind==5, `0x80` otherwise (the first place this project has found
     * a texture-family record sized larger than the usual 0x80).
     */
    static void free_texvert(IOATIR500Accelerator *accel, IOTextureBuffer *texture);
};

#endif /* IOATIR500SHARED_H */
