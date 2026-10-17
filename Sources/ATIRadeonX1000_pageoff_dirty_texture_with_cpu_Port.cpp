/*
 * ATIRadeonX1000_pageoff_dirty_texture_with_cpu_Port.cpp
 *
 * ATIRadeonX1000::pageoff_dirty_texture_with_cpu (real addr 0x1e500, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern "C" UInt32 global_dummy_read_back_a_register;   /* ATIRadeonX1000_DataTables.cpp */

extern "C" UInt32 GH_memcpy(...) asm("_memcpy");


/* real addr 0x1e500 */
void ATIRadeonX1000::pageoff_dirty_texture_with_cpu(VendorTextureBuffer *texture, ATITextureBufferHeader *hwInfo) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *textureBytes = reinterpret_cast<UInt8 *>(texture);
    UInt8 *hwInfoBytes = reinterpret_cast<UInt8 *>(hwInfo);

  UInt8 faceCount;
  UInt8 *pbVar2;
  UInt32 saved0;
  UInt32 saved1;
  UInt32 saved2;
  SInt32 surfaceInfoOffset;
  SInt32 surfaceLowerOffset;
  bool bVar17;
  UInt8 bVar18;
  UInt32 uVar19;
  SInt32 iVar20;
  UInt32 lastLevel;
  UInt32 uVar22;
  UInt8 *destination;
  SInt32 vramSource;
  UInt8 AVar25;
  SInt32 iVar26;
  SInt32 iVar27;
  SInt32 iVar28;
  SInt32 iVar29;
  UInt32 baseLevel;
  SInt32 iVar31;
  UInt32 uVar32;
  SInt32 iVar33;
  UInt32 level;
  UInt32 uVar35;
  SInt32 repeat;
  UInt32 uVar37;
  SInt32 rowCount;
  UInt8 *tileRecord;
  UInt32 uVar40;
  UInt32 face;
  SInt32 bytesCopied;
  SInt32 local_7c;
  SInt32 *innerMapping;
  
  iVar26 = M<SInt32>(textureBytes + 0x14);
  baseLevel = (UInt32)M<UInt8>(iVar26 + 0x17);
  lastLevel = (baseLevel + M<UInt8>(iVar26 + 0x35)) - 1;
  faceCount = M<UInt8>(iVar26 + 0x34);
  VCALL(M<SInt32>(self), 0x558)(self,M<SInt32>(self + 0x50) + -1);
  uVar19 = (UInt32)(UInt8)self[0x990];
  if ((uVar19 == 0) || ((M<UInt32>(self + 0x890) & 1) == 0)) {
LAB_0001e594:
    iVar26 = 0;
  }
  else {
    uVar35 = 0;
    do {
      uVar35 = uVar35 + 1;
      uVar19 = uVar19 - 1;
      if (uVar19 == 0) goto LAB_0001e594;
    } while ((M<UInt32>(self + 0x890) & 1 << (uVar35 & 0x3f)) != 0);
    iVar26 = uVar35 * 4;
  }
  iVar31 = M<SInt32>(self + 0x860);
  surfaceInfoOffset = (iVar26 + 0x2c3) * 4;
  /* the three registers are read as words (lwbrx) and written back later (stwbrx), exactly as the shipped code does: four single-byte reads would be a different access on the bus */
  saved0 = loadWordByteReversed(reinterpret_cast<UInt8 *>(iVar31 + surfaceInfoOffset));
  surfaceLowerOffset = (iVar26 + 0x2c1) * 4;
  saved1 = loadWordByteReversed(reinterpret_cast<UInt8 *>(iVar31 + surfaceLowerOffset));
  iVar26 = (iVar26 + 0x2c2) * 4;
  saved2 = loadWordByteReversed(reinterpret_cast<UInt8 *>(iVar31 + iVar26));
  bVar18 = M<UInt8>(M<SInt32>(textureBytes + 0x14) + 0x15) >> 3;
  iVar20 = -(bVar18 & 3);
  if ((bVar18 & 2) == 0) {
    if (-1 < iVar20) {
      bVar17 = false;
      goto LAB_0001e61c;
    }
    AVar25 = hwInfoBytes[0x1a];
    bVar17 = AVar25 == 0x0;
LAB_0001e624:
    if ((UInt8)AVar25 < 4) {
      if (bVar17) {
        iVar20 = 2;
        iVar33 = 3;
        local_7c = 2;
      }
      else {
        iVar20 = 1;
        iVar33 = 4;
        local_7c = 1;
      }
      goto LAB_0001e668;
    }
  }
  else {
    bVar17 = true;
LAB_0001e61c:
    if (iVar20 < 0) {
      AVar25 = hwInfoBytes[0x1a];
      goto LAB_0001e624;
    }
  }
  iVar20 = 0;
  iVar33 = 5;
  local_7c = 0;
LAB_0001e668:
  if (faceCount == 0) {
    innerMapping = (SInt32 *)0x0;
    bytesCopied = 0;
  }
  else {
    face = 0;
    innerMapping = (SInt32 *)0x0;
    bytesCopied = 0;
    do {
      uVar37 = (UInt32)M<UInt16>(hwInfoBytes + 0x14);
      uVar35 = (UInt32)M<UInt16>(hwInfoBytes + 0x16);
      uVar19 = (UInt32)M<UInt16>(hwInfoBytes + 0x18);
      uVar40 = M<UInt32>(hwInfoBytes + 0xc);
      iVar31 = M<SInt32>(hwInfoBytes + 0x10);
      if (baseLevel <= lastLevel) {
        tileRecord = hwInfoBytes + (face * 0xd + baseLevel) * 0x20 + 0x42;
        level = baseLevel;
        do {
          uVar22 = (UInt32)M<UInt16>(tileRecord);
          if ((uVar22 != 0) && (rowCount = (SInt32)(uVar35 * uVar19) / (SInt32)uVar22, uVar22 != 0)) {
            repeat = 0;
            do {
              if (textureBytes[0x20] == 0x7) {
                innerMapping = (SInt32 *)VCALL(*M<SInt32 *>(M<SInt32>(textureBytes + 0x58) + 8), 0x14c)
                                            (M<SInt32 *>(M<SInt32>(textureBytes + 0x58) + 8),
                                             GH_kernel_task,0,1,0,0);
                if (innerMapping == (SInt32 *)0x0) {
                  return;
                }
                destination = (UInt8 *)VCALL(*innerMapping, 0xd0)(innerMapping);
              }
              else {
                destination = hwInfoBytes + M<SInt32>(tileRecord + 2);
              }
              destination = destination + repeat * M<SInt32>(tileRecord + 10);
              vramSource = M<SInt32>(self + 0xe4) + M<SInt32>(textureBytes + 0x48) + M<SInt32>(tileRecord + 6) +
                       repeat * M<SInt32>(tileRecord + 0xe);
              if ((((SInt32)uVar40 < 1 << iVar33 + 3) || ((SInt32)uVar35 < 1 << local_7c + 3)) ||
                 ((M<UInt8>(M<SInt32>(textureBytes + 0x14) + 0x15) & 4) == 0)) {
                bVar17 = false;
                uVar22 = 0;
              }
              else {
                bVar17 = true;
                uVar22 = 1;
              }
              switch(local_7c << 1 | uVar22) {
              default:
                uVar22 = 0;
                break;
              case 1:
                uVar22 = 0x10000;
                break;
              case 2:
                uVar22 = 0x20000;
                break;
              case 3:
                uVar22 = 0x30000;
                break;
              case 4:
                uVar22 = 0x60000;
                break;
              case 5:
                uVar22 = 0x70000;
              }
              iVar28 = 8;
              if (!bVar17) {
                iVar28 = 1;
              }
              iVar28 = iVar28 * (1 << iVar20);
              uVar32 = vramSource - M<SInt32>(self + 0xe4);
              iVar27 = M<SInt32>(self + 0x860);
              M<UInt32>(iVar27 + surfaceInfoOffset) =
                   (uVar40 >> 3) << 0x18 | (uVar40 >> 3 & 0x1f00) << 8 |
                   (uVar22 | ((UInt8)hwInfoBytes[0x1b] & 3) << 0x14 | ((UInt8)hwInfoBytes[0x1b] & 3) << 0x16)
                   >> 8;
              enforceInOrderExecutionIO();
              M<UInt32>(iVar27 + surfaceLowerOffset) =
                   uVar32 * 0x1000000 | (uVar32 & 0xff00) << 8 | uVar32 >> 8 & 0xff00 |
                   uVar32 >> 0x18;
              enforceInOrderExecutionIO();
              uVar22 = (uVar32 + iVar28 * uVar40 * ((rowCount + iVar28 + -1) / iVar28)) - 1;
              M<UInt32>(iVar27 + iVar26) =
                   uVar22 * 0x1000000 | (uVar22 & 0xff00) << 8 | uVar22 >> 8 & 0xff00 |
                   uVar22 >> 0x18;
              enforceInOrderExecutionIO();
              pbVar2 = (UInt8 *)(iVar27 + iVar26);
              global_dummy_read_back_a_register =
                   loadWordByteReversed(pbVar2);
              if (rowCount < 1) {
                uVar22 = (UInt32)(UInt8)hwInfoBytes[0x1a];
              }
              else {
                uVar22 = (UInt32)(UInt8)hwInfoBytes[0x1a];
                iVar28 = 0;
                do {
                  GH_memcpy(destination,vramSource,uVar37 << (uVar22 & 0x3f));
                  if ((M<UInt32>(self + 0x98) & 0x80) == 0) {
                    AVar25 = hwInfoBytes[0x1a];
                  }
                  else {
                    uVar22 = (UInt32)(UInt8)self[0x84];
                    AVar25 = hwInfoBytes[0x1a];
                    iVar27 = 0;
                    iVar29 = ((uVar37 << ((UInt8)AVar25 & 0x3f)) + ((UInt32)destination & uVar22 - 1)) -
                             uVar22;
                    if (0 < iVar29) {
                      iVar27 = 0;
                      do {
                        dataCacheBlockStore((-uVar22 & (UInt32)destination) + iVar27);
                        iVar27 = iVar27 + uVar22;
                      } while (iVar27 < iVar29);
                    }
                    ppcSync();
                    instructionSynchronize();
                    dataCacheBlockFlush((-uVar22 & (UInt32)destination) + iVar27);
                    ppcSync();
                    instructionSynchronize();
                    instructionSynchronize();
                  }
                  uVar22 = (UInt32)(UInt8)AVar25;
                  iVar28 = iVar28 + 1;
                  destination = destination + iVar31;
                  vramSource = vramSource + uVar40;
                } while (rowCount != iVar28);
              }
              repeat = repeat + 1;
              bytesCopied = bytesCopied + rowCount * (uVar37 << (uVar22 & 0x3f));
            } while (repeat < (SInt32)(UInt32)M<UInt16>(tileRecord));
          }
          if (((1 >= uVar37) && (uVar35 < 2)) && (uVar19 < 2)) break;
          if (0x20 < iVar31) {
            iVar31 = iVar31 >> 1;
          }
          if (1 << iVar33 < (SInt32)uVar40) {
            uVar40 = (SInt32)uVar40 >> 1;
          }
          if (1 < uVar37) {
            uVar37 = (SInt32)uVar37 >> 1;
          }
          if (1 < uVar35) {
            uVar35 = (SInt32)uVar35 >> 1;
          }
          if (1 < uVar19) {
            uVar19 = (SInt32)uVar19 >> 1;
          }
          level = level + 1;
          tileRecord = tileRecord + 0x20;
        } while (level <= lastLevel);
      }
      face = face + 1;
    } while (face < faceCount);
    iVar31 = M<SInt32>(self + 0x860);
  }
  M<SInt32>(self + 0x720) = bytesCopied + M<SInt32>(self + 0x720);
  storeWordByteReversed(reinterpret_cast<UInt8 *>(iVar31 + surfaceInfoOffset), saved0);
  enforceInOrderExecutionIO();
  storeWordByteReversed(reinterpret_cast<UInt8 *>(iVar31 + surfaceLowerOffset), saved1);
  enforceInOrderExecutionIO();
  storeWordByteReversed(reinterpret_cast<UInt8 *>(iVar31 + iVar26), saved2);
  enforceInOrderExecutionIO();
  if (innerMapping != (SInt32 *)0x0) {
    VCALL(*innerMapping, 0x18)(innerMapping);
  }
  return;
}
