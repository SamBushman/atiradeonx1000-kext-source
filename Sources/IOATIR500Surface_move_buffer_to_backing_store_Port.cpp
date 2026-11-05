/*
 * IOATIR500Surface_move_buffer_to_backing_store_Port.cpp
 *
 * IOATIR500Surface::move_buffer_to_backing_store (real addr 0x11420, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
 * Tools/port_fn.py); replaces the earlier hand-written body, which the callee/atomics comparison (Tools/callee_compare.py) showed had
 * dropped or simplified parts of the original.
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/IOATIR5002DContext.h"
#include "../Headers/IOATIR500DVDContext.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/IOATIR500Shared.h"
#include "../Headers/ATIR500Surface.h"
#include "../Headers/ATIR500GLContext.h"
#include "../Headers/ATIR5002DContext.h"
#include "../Headers/ATIR500DVDContext.h"
#include "../Headers/ATIR500Memory.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h"
#include "../Headers/ATIRadeonX1000Registers.h"
#include "../Headers/GhidraExterns.h"
#include "../Headers/GhidraCompat.h"
#include "../Headers/GhidraLiterals.h"



/* real addr 0x11420 */
bool IOATIR500Surface::move_buffer_to_backing_store(ATIR500SurfaceBuffer *buffer) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *bufferBytes = reinterpret_cast<UInt8 *>(buffer);

  UInt32 result;
  
  result = this->copy_buffer_to_backing_store((ATIR500SurfaceBuffer *)(bufferBytes));
/* Root cause (#123): the buffer passed in is not necessarily one of THIS surface's own 23 slots. A panel surface's attachment pointer
   (surface+0xb70, set by set_id_mode) points at the accelerator's scanout record (accel+0x12c+panel*0x78), which has the same record layout
   but is display-owned VRAM (reserved once at HardwareInit), not a surface slot. The slot index recovered below by pointer arithmetic is only
   meaningful for the surface's own buffers: for the scanout record it names a bogus slot (here: the record 4 bytes before the scanout element -
   its +0 is the unrelated word at accel+0x128 = NULL, its +4 the scanout's own next link, its +8 the scanout's prev link), so dealloc_surface
   -> ATIR500Memory::dealloc follows a NULL link (DAR 0xc) and panics. The vendor's own sibling code (IOATIR500DVDContext::write_buffer,
   IOATIR500GLContext::read_buffer) already treats `index >= 0x17` as "not one of the surface's slots"; there is simply no slot (and no pool
   element of this surface) to release for such a buffer - the display keeps its VRAM. */
  if ((UInt32)(((SInt32)bufferBytes - (SInt32)(self + kIOATIR500Surface_buffers) >> 3) * -0x11111111) < 0x17) {
    VCALL(M<SInt32>(self), 0x5cc)(self,((SInt32)bufferBytes - (SInt32)(self + kIOATIR500Surface_buffers) >> 3) * -0x11111111);
  }
  return result;
}
