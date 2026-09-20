/* NOTE 2026-09-19: 9 function bodies formerly in this file have been replaced by mechanical ports from the shipped kext's decompile (Sources/*_Port.cpp; marked
   "(re-ported mechanically: ...)" below). The analysis prose in this file describes the earlier hand-written bodies and is kept as history; see README.md,
   "How the code was produced". */
/*
 * IOATIR500DVDContext_ExternalMethods.cpp
 *
 * RESOLVED (issue #59 / #42): real bodies for the DVD context's base external-method table members
 * that only need already-reconstructed pieces (real addrs in parentheses):
 *   get_config (0xe980)  get_status (0xe9b0)  get_surface_size (0xe9e0)  finish (0xea30)
 *   unlock_memory (0xff20)  write_buffer (0xffe0)  declare_image (0x103e0)  delete_image (0x104f0)
 *   create_shared (0xee60)
 * Still on #59 for this class: lock_all_buffers (needs IOATIR500Surface::alloc_surfaces) and the
 * start/stop/clientClose/remove_surface/setCompatibleSurfaceMode family.
 *
 * Field offsets: this+0x78 task, +0x7c stamp tag, +0x84 shared allocator, +0x88 surface-flags bitmask,
 * +0x8c accelerator, +0xf8 bound surface (NULL until set_surface binds one). accelerator+0x80 =
 * hardware up, +0x840 = command lock.
 *
 * REAL VENDOR BUG, reproduced faithfully: write_buffer reads `boundSurface + 0xb70 + ...` BEFORE it
 * checks boundSurface for NULL. On a fresh DVD connection (no set_surface yet) that is a kernel NULL
 * dereference: it panics the stock driver exactly like set_macrovision does (issue #43). The load is
 * done through a volatile pointer so the compiler cannot delete the later null check on the grounds
 * that the earlier dereference already proved non-null.
 *
 * Confidence: CONFIRMED for control flow and offsets - complete decompiles.
 */

#include "../Headers/IOATIR500DVDContext.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/IOATIR500Shared.h"

extern "C" void DVDBase_lock(void *) asm("_IOLockLock");
extern "C" void DVDBase_unlock(void *) asm("_IOLockUnlock");
extern "C" void DVDBase_IOSleep(UInt32) asm("_IOSleep");
extern "C" void *DVDBase_withAddress(UInt32 address, UInt32 length, UInt32 direction, void *task) asm("__ZN18IOMemoryDescriptor11withAddressEjm11IODirectionP4task");
extern "C" int kernelPageSize asm("_page_size"); /* kernel page_size (0x1000); see ATIRadeonX1000Types.h notes on the "_ASICSupportsAGP" label */

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }
typedef void (*BlitTileFn)(void *, UInt32, UInt32, UInt32, UInt32, UInt32, UInt32, void *, UInt32, UInt32, UInt32, UInt32, UInt32);
typedef SInt32 (*Fn0x55c)(void *, UInt32);
typedef void (*Fn0x5ac)(void *, void *);
typedef void (*ReleaseFn)(void *);
struct DVDWriteXfer { UInt32 word0; UInt32 needsRelease; void *memDesc; UInt16 kind; UInt16 pad; };
} // namespace

/* (re-ported mechanically: see IOATIR500DVDContext_get_config_Port.cpp) */


/* (re-ported mechanically: see IOATIR500DVDContext_get_status_Port.cpp) */


/* (re-ported mechanically: see IOATIR500DVDContext_get_surface_size_Port.cpp) */


/* (re-ported mechanically: see IOATIR500DVDContext_finish_Port.cpp) */


/* (re-ported mechanically: see IOATIR500DVDContext_unlock_memory_Port.cpp) */


/* create_shared: see IOATIR5002DContext::create_shared - same body, this class's own offsets (+0x84, +0x8c) */
/* (re-ported mechanically: see IOATIR500DVDContext_create_shared_Port.cpp) */


/* (re-ported mechanically: see IOATIR500DVDContext_declare_image_Port.cpp) */


/* (re-ported mechanically: see IOATIR500DVDContext_delete_image_Port.cpp) */


/* write_buffer(data, byteCount): the DVD context's clipped framebuffer WRITE-back into a caller-supplied
 * userspace range - the same shape as GL read_buffer / Surface surface_read, keyed off bound-surface
 * buffer index 0xf or 0x10. data layout: {x,y,w,h, kindFlag, destBase, stride}. */
/* (re-ported mechanically: see IOATIR500DVDContext_write_buffer_Port.cpp) */

