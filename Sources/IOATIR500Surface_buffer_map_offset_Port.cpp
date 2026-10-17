/*
 * IOATIR500Surface_buffer_map_offset_Port.cpp
 *
 * IOATIR500Surface::buffer_map_offset (real addr 0x14010, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x14010 */
SInt32 IOATIR500Surface::buffer_map_offset(ATIR500SurfaceBuffer *buffer, UInt32 index, UInt32 level, SInt32*w, SInt32*h, SInt32*bytes) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *bufferBytes = reinterpret_cast<UInt8 *>(buffer);

  UInt16 width;
  UInt16 bytesPerRow;
  UInt16 height;
  
  width = M<UInt16>(bufferBytes + 0x14);
  bytesPerRow = M<UInt16>(bufferBytes + 0x16);
  height = M<UInt16>(bufferBytes + 0x1e);
  if (w != (long *)0x0) {
    *w = (UInt32)M<UInt16>(bufferBytes + 0x1c);
  }
  if (h != (long *)0x0) {
    *h = (UInt32)height;
  }
  if (bytes != (long *)0x0) {
    *bytes = (UInt32)bytesPerRow * (UInt32)width;
  }
  return 0;
}
