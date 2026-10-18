/*
 * IOATIR500Accelerator_tossSurfacesForVRAM_Port.cpp
 *
 * IOATIR500Accelerator::tossSurfacesForVRAM (real addr 0x3d60, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



/* real addr 0x3d60 */
UInt32 IOATIR500Accelerator::tossSurfacesForVRAM(IOATIR500Surface *excludeSurface, VendorTextureBuffer**excludeList, SInt32 excludeCount, VendorTextureBuffer *needed, bool skipExcludeCheck) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *excludeSurfaceBytes = reinterpret_cast<UInt8 *>(excludeSurface);
    UInt8 *neededBytes = reinterpret_cast<UInt8 *>(needed);

  bool notLastBuffer;
  UInt8 *excludedTexture;
  UInt32 result;
  UInt32 in_register_00000020;
  UInt8 **excludeCursor;
  UInt8 *surfaceListHead;
  UInt32 bufferIndex;
  UInt8 *surfaceBuffer;
  UInt8 *surface;
  UInt8 excludeFlags;
  long excludeLeft;
  
  surfaceListHead = M<UInt8 *>(self + kIOATIR500Accelerator_liveSurfaceListHead);
  if (surfaceListHead != (UInt8 *)0x0) {
    excludeFlags = (0 < excludeCount) << 2 | (excludeCount == 0) << 1;
    surface = surfaceListHead;
    do {
      surface = M<UInt8 *>(surface + 0xa0);
      if ((surface != excludeSurfaceBytes) &&
         ((((UInt32)skipExcludeCheck) == 0 || (M<SInt32>(surface + 0xd48) != 0)))) {
        excludeCursor = (UInt8 **)excludeList;
        excludeLeft = excludeCount;
        if ((bool)(excludeFlags >> 2 & 1)) {
          do {
            excludedTexture = *excludeCursor;
            excludeCursor = excludeCursor + 1;
            if (((excludedTexture != (UInt8 *)0x0) &&
                (excludedTexture[0x20] == 0x0)) &&
               (surface == M<UInt8 *>(excludedTexture + 0x50))) goto LAB_00003f10;
            excludeLeft = excludeLeft + -1;
          } while (excludeLeft != 0);
        }
        else if (!(bool)(excludeFlags >> 1 & 1)) goto LAB_00003f10;
        bufferIndex = 0;
        surfaceBuffer = (UInt8 *)(surface + 0xa8);
        do {
          if ((((M<SInt32>(surface + 0xc14) == 0xffff) || ((1 < bufferIndex && (1 < bufferIndex - 4)))) &&
              (M<SInt32>(surfaceBuffer + 8) != 0)) &&
             (((M<UInt32>(surface + 0xbd0) & 0xffff0000) == 0 ||
              (surfaceBuffer != M<UInt8 *>(surface + 0xb70))))) {
            if (M<SInt32>(surface + 0xd48) == 0) {
              ((IOATIR500Surface *)(surface))->move_buffer_to_backing_store((ATIR500SurfaceBuffer *)(surfaceBuffer));
LAB_00003ec0:
              VCALL(M<SInt32>(self), 0x528)(self,neededBytes);
            }
            else if (M<SInt32>(surface + 0xbcc) == 0) {
              VCALL(M<SInt32>(surface), 0x5cc)(surface,bufferIndex);
              goto LAB_00003ec0;
            }
            if (M<SInt32>(neededBytes + 0x48) != 0) goto LAB_00003f28;
          }
          notLastBuffer = bufferIndex != 0x16;
          surfaceBuffer = surfaceBuffer + 0x78;
          bufferIndex = bufferIndex + 1;
        } while (notLastBuffer);
        if (M<SInt32>(neededBytes + 0x48) != 0) goto LAB_00003f28;
        surfaceListHead = M<UInt8 *>(self + kIOATIR500Accelerator_liveSurfaceListHead);
      }
LAB_00003f10: ;
    } while (surface != surfaceListHead);
  }
  result = 0;
  if (M<SInt32>(neededBytes + 0x48) != 0) {
LAB_00003f28:
    result = 1;
  }
  return result;
}
