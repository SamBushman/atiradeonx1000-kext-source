/*
 * IOATIR500Surface_set_shape_backing_length_ext_Port.cpp
 *
 * IOATIR500Surface::set_shape_backing_length_ext (real addr 0x152d0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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

extern "C" UInt32 GH_IOFreeAligned(...) asm("_IOFreeAligned");
extern "C" UInt32 GH_IOLockLock(...) asm("_IOLockLock");
extern "C" UInt32 GH_IOLockSleep(...) asm("_IOLockSleep");
extern "C" UInt32 GH_IOLockUnlock(...) asm("_IOLockUnlock");
extern "C" UInt32 GH_IOMallocAligned(...) asm("_IOMallocAligned");


/* real addr 0x152d0 */
IOReturn IOATIR500Surface::set_shape_backing_length_ext(eIOAccelSurfaceShapeBits shapeBits, UInt32 id, unsigned int backingAddress, UInt32 backingPitch, IOAccelDeviceRegion *region, UInt32 regionSize, UInt32 backingLength) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    int *regionRaw = reinterpret_cast<int *>(region);

  int *piVar1;
  char cVar2;
  UInt16 uVar3;
  UInt16 uVar4;
  UInt8 IVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  UInt32 uVar14;
  UInt8 *pAVar15;
  UInt8 bVar16;
  UInt8 bVar17;
  UInt8 bVar18;
  UInt32 local_48;
  UInt32 local_44;
  UInt32 local_40;
  UInt32 local_3c;
  
  iVar10 = M<int>(self + 0xd50);
  if (((M<unsigned int>(iVar10 + 0xcc) <= id) || (M<SInt16>(regionRaw + 2) < 0)) ||
     (M<SInt16>((int)regionRaw + 10) < 0)) {
    return 0xe00002bc;
  }
  if (regionSize == 0) {
    regionSize = *regionRaw * 8 + 0xc;
  }
  else if (regionSize != *regionRaw * 8 + 0xcU) {
    return 0xe00002bc;
  }
  if ((M<SInt16>(regionRaw + 2) == 0) || (M<SInt16>((int)regionRaw + 10) == 0)) {
    backingAddress = 0;
    backingPitch = 0;
    M<UInt16>((int)regionRaw + 10) = 1;
    M<UInt16>(regionRaw + 2) = 1;
    iVar10 = M<int>(self + 0xd50);
  }
  GH_IOLockLock(M<UInt32>(iVar10 + 0x840));
  if ((shapeBits & 0x80) != 0) {
    iVar10 = M<int>(self + 0xd50);
    cVar2 = M<char>(iVar10 + 0x80);
    while (cVar2 == '\0') {
      GH_IOLockSleep(M<UInt32>(iVar10 + 0x840),iVar10,0);
      cVar2 = M<char>(iVar10 + 0x80);
    }
  }
  bVar17 = (backingPitch == 0xffffffff) << 1;
  if ((backingPitch != 0xffffffff) && (backingLength != 0)) {
    M<int>(self + 0xd4c) = backingLength;
  }
  if ((M<unsigned int>(self + 0xbd0) & 0xffff0000) != 0) {
    uVar14 = 0xe00002cc;
    goto LAB_000157b4;
  }
  if ((M<unsigned int>(self + 0xbe8) & 0x20) == 0) {
    uVar14 = 0xe00002bc;
    goto LAB_000157b4;
  }
  M<unsigned int>(self + 0xbfc) = shapeBits;
  if ((self[0xbec] == 0x0) || ((shapeBits & 4) == 0)) {
    bVar9 = false;
  }
  else {
    bVar9 = true;
    self[0xbec] = 0x0;
  }
  iVar10 = id * 8;
  M<unsigned int>(self + 0xbf8) = M<unsigned int>(self + 0xbf8) | 0x10000000;
  if ((bVar9) ||
     ((self[0xbec] == 0x0 &&
      (M<int>(M<int>(self + iVar10 + 0xd60) + 8) != regionRaw[2])))) {
    bVar9 = true;
  }
  else {
    bVar9 = false;
  }
  if ((M<unsigned int>(self + iVar10 + 0xd64) < regionSize) ||
     ((regionSize & 0xffffff00) != (M<unsigned int>(self + iVar10 + 0xd64) & 0xffffff00))) {
    iVar13 = GH_IOMallocAligned(regionSize,0x20);
    if (iVar13 == 0) {
      uVar14 = 0xe00002be;
      goto LAB_000157b4;
    }
    iVar6 = M<int>(self + 0xd50);
    if (iVar6 != 0) {
      M<unsigned int>(iVar6 + 0x804) = regionSize + M<int>(iVar6 + 0x804);
    }
    GH_IOFreeAligned(M<UInt32>(self + iVar10 + 0xd60),M<UInt32>(self + iVar10 + 0xd64));
    iVar6 = M<int>(self + 0xd50);
    if (iVar6 != 0) {
      M<int>(iVar6 + 0x804) = M<int>(iVar6 + 0x804) - M<int>(self + iVar10 + 0xd64);
    }
    M<unsigned int>(self + iVar10 + 0xd64) = regionSize;
    M<int>(self + iVar10 + 0xd60) = iVar13;
  }
  iVar13 = regionRaw[1];
  iVar6 = regionRaw[2];
  piVar12 = M<int *>(self + iVar10 + 0xd60);
  *piVar12 = *regionRaw;
  piVar12[1] = iVar13;
  piVar12[2] = iVar6;
  iVar13 = *regionRaw;
  if (iVar13 != 0) {
    iVar8 = 0;
    piVar12 = regionRaw;
    iVar6 = iVar13;
    if (iVar13 == 0) {
      iVar6 = 1;
    }
    do {
      iVar11 = piVar12[3];
      iVar7 = iVar8 * 8;
      iVar8 = iVar8 + 1;
      piVar1 = piVar12 + 4;
      piVar12 = piVar12 + 2;
      iVar7 = iVar7 + M<int>(self + iVar10 + 0xd60);
      M<int>(iVar7 + 0x10) = *piVar1;
      M<int>(iVar7 + 0xc) = iVar11;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  if (((1 << (id & 0x3f) & M<unsigned int>(M<int>(self + 0xd50) + 0xd0)) == 0) ||
     ((iVar13 == 1 && ((M<SInt16>(regionRaw + 4) == 0 || (M<SInt16>((int)regionRaw + 0x12) == 0))))))
  {
    IVar5 = 0x0;
  }
  else {
    IVar5 = 0x1;
  }
  self[id * 0x94 + 0xcac] = IVar5;
  if (self[0xbec] == 0x0) {
    uVar3 = M<UInt16>(regionRaw + 2);
    M<UInt16>(self + 0xbd4) = uVar3;
    uVar4 = M<UInt16>((int)regionRaw + 10);
    M<UInt16>(self + 0xbde) = 0;
    M<UInt16>(self + 0xbe0) = uVar3;
    M<UInt16>(self + 0xbdc) = 0;
    M<UInt16>(self + 0xbe2) = uVar4;
    M<UInt16>(self + 0xbd6) = uVar4;
  }
  bVar16 = (backingAddress == 0) << 1;
  M<UInt16>(self + 0xbe4) = M<UInt16>(regionRaw + 2);
  M<UInt16>(self + 0xbe6) = M<UInt16>((int)regionRaw + 10);
  if ((backingAddress == 0) || (*regionRaw != 1)) {
    M<UInt16>(self + 0xbd8) = M<UInt16>(self + 0xbd4);
    M<UInt16>(self + 0xbda) = M<UInt16>(self + 0xbd6);
  }
  else {
    M<UInt16>(self + 0xbd8) = M<UInt16>(regionRaw + 4);
    M<UInt16>(self + 0xbda) = M<UInt16>((int)regionRaw + 0x12);
  }
  bVar18 = !bVar9 << 1;
  if ((bVar9) || ((M<unsigned int>(self + 0xd70) & 2) != 0)) {
    VCALL(M<int>(self), 0x5c8)(self);
    this->update_contexts();
  }
  iVar10 = VCALL(M<int>(self), 0x5b0)
                     (self,(int)M<SInt16>(self + 0xbd4),(int)M<SInt16>(self + 0xbd6));
  if (iVar10 == 0) {
LAB_00015720:
    uVar14 = 0xe00002be;
    M<unsigned int>(self + 0xbf8) = M<unsigned int>(self + 0xbf8) | 0x20000000;
  }
  else {
    if (!(bool)(bVar18 >> 1 & 1)) {
      local_3c = 0;
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      iVar10 = VCALL(*M<int *>(self + 0xd50), 0x540)
                         (M<int *>(self + 0xd50),&local_48,
                          M<UInt32>(M<int>(self + 0xb70) + 0x10),0x1000);
      if (iVar10 == 0) goto LAB_00015720;
      M<unsigned int>(self + 0xbf8) = M<unsigned int>(self + 0xbf8) & 0xdfffffff;
      VCALL(*M<int *>(self + 0xd50), 0x544)(M<int *>(self + 0xd50),&local_48);
    }
    pAVar15 = M<UInt8 *>(self + 0xb70);
    if ((bool)(bVar17 >> 1 & 1)) {
      backingPitch = 0;
    }
    else if (M<UInt8 *>(pAVar15 + 0x24) != (UInt8 *)0x0) {
      this->delete_buffer_backing((IOTextureBuffer *)(M<UInt8 *>(pAVar15 + 0x24)));
      M<UInt32>(pAVar15 + 0x24) = 0;
    }
    if ((((bool)(bVar16 >> 1 & 1)) || (backingPitch == 0)) ||
       (iVar10 = this->connect_buffer_backing_store((ATIR500SurfaceBuffer *)(pAVar15),backingAddress,backingPitch), iVar10 == 0)) {
      uVar14 = 0;
    }
    else {
      if ((shapeBits & 0x20) == 0) {
        iVar10 = M<int>(self + 0x7c);
      }
      else {
        iVar10 = M<int>(self + 0x7c) + -1;
      }
      uVar14 = 0;
      M<int>(M<int>(pAVar15 + 0x24) + 0x54) = iVar10;
    }
  }
LAB_000157b4:
  self[0xbef] = ((UInt8)(shapeBits >> 3) & 1);
  if ((M<SInt16>(self + 0xbee) != 0) || (IVar5 = 0x0, (shapeBits & 0x10) != 0)) {
    IVar5 = 0x1;
  }
  self[0xbed] = IVar5;
  if ((shapeBits & 1) == 0) {
    piVar12 = M<int *>(self + 0xd50);
    iVar13 = piVar12[0x1f0];
    iVar10 = VCALL(*piVar12, 0x558)(piVar12,M<UInt32>(self + 0x80));
    piVar12[0x1f0] = iVar13 + iVar10;
    self[0xbf2] = 0x0;
  }
  else {
    self[0xbf2] = 0x1;
  }
  GH_IOLockUnlock(M<UInt32>(M<int>(self + 0xd50) + 0x840));
  return uVar14;
}
