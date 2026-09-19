/*
 * IOATIR5002DContext_ExternalMethods.cpp
 *
 * RESOLVED (issue #59 / #42): real bodies for the self-contained members of the 2D context's
 * external-method table (real addrs in parentheses), transcribed from the shipped kext's own
 * decompile:
 *   get_config (0xbd90)  finish (0xbdc0)  scale_surface (0xcb90)  declare_image (0xd020)
 *   create_image (0xd130)  delete_image (0xd450)  wait_image (0xd5c0)  create_shared (0xbc90)
 *   set_surface_paging_options (0xc2c0)  set_surface_vsync_options (0xc2d0)
 *
 * The remaining members of the table (set_surface, get_surface_info, swap_surface, lock_memory, unlock_memory,
 * create_transfer, set_macrovision) are in IOATIR5002DContext_Surface.cpp; the table itself is in
 * IOATIR5002DContext_MethodTables.cpp.
 *
 * Field offsets used: this+0x7c (current stamp tag), +0x88 (shared allocator), +0x94 (accelerator),
 * +0x100 (bound surface), +0x114 (last bound texture); accelerator+0x80 (hardware up), +0x840
 * (command lock), +0x98/+0x9c (config words), +0x75c/+0x7a0/+0x7a4 (wait-time accumulators).
 * The lock is IOLockLock/IOLockUnlock (kxld binds them to mutex_lock/mutex_unlock_rwcmb).
 *
 * Confidence: CONFIRMED for control flow and every offset - short, complete decompiles.
 */

#include "../Headers/IOATIR5002DContext.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/IOATIR500Shared.h"

extern "C" void Ctx2D_lock(void *) asm("_IOLockLock");
extern "C" void Ctx2D_unlock(void *) asm("_IOLockUnlock");

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
typedef SInt32 (*WaitFn)(void *, UInt32);
inline SInt32 CallAccelWait(void *accel, int slotOffset, UInt32 tag) {
    void **vtable = *reinterpret_cast<void ***>(accel);
    return (*reinterpret_cast<WaitFn *>(vtable + (slotOffset / 4)))(accel, tag);
}
} // namespace

IOReturn IOATIR5002DContext::get_config(UInt32 *out0, UInt32 *out1) {
    *out0 = U32At(accelerator, 0x98);
    *out1 = U32At(accelerator, 0x9c);
    return 0;
}

/* finish(mode): 0 = wait on this context's own stamp (same slot GL finish uses, +0x55c); 1 / 2 = wait on
 * the accelerator's own pending stamp (-1) via slot +0x55c / +0x558; anything else = BadArgument. */
/* (re-ported mechanically: see IOATIR5002DContext_finish_Port.cpp) */


/* (re-ported mechanically: see IOATIR5002DContext_scale_surface_Port.cpp) */


/* create_shared: allocate and init this context's IOATIR500Shared, and wire it to the accelerator (+0xc)
 * and the owning task (+8). Real: `init()` is the vtable +0x48 call (IOATIR500Shared::init). */
/* (re-ported mechanically: see IOATIR5002DContext_create_shared_Port.cpp) */


/* (re-ported mechanically: see IOATIR5002DContext_declare_image_Port.cpp) */


/* (re-ported mechanically: see IOATIR5002DContext_create_image_Port.cpp) */


/* (re-ported mechanically: see IOATIR5002DContext_delete_image_Port.cpp) */


/* (re-ported mechanically: see IOATIR5002DContext_wait_image_Port.cpp) */


/* set_surface_paging_options / set_surface_vsync_options: deliberate stubs in the shipped driver */
IOReturn IOATIR5002DContext::set_surface_paging_options(IOSurfacePagingControlInfoStruct *inStruct, IOSurfacePagingControlInfoStruct *outStruct, UInt32 structSize, UInt32 *outTag) {
    (void)inStruct; (void)outStruct; (void)structSize; (void)outTag;
    return 0xe00002c7; /* kIOReturnUnsupported */
}

IOReturn IOATIR5002DContext::set_surface_vsync_options(IOSurfaceVsyncControlInfoStruct *inStruct, IOSurfaceVsyncControlInfoStruct *outStruct, UInt32 structSize, UInt32 *outTag) {
    (void)inStruct; (void)outStruct; (void)structSize; (void)outTag;
    return 0xe00002c7; /* kIOReturnUnsupported */
}
