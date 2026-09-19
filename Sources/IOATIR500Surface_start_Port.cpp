/*
 * IOATIR500Surface_start_Port.cpp
 *
 * IOATIR500Surface::start (real addr 0x119f0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern const VendorExternalMethod kSurfaceMethods[19];   /* ATIR500Surface_ExternalMethods.cpp */

extern "C" UInt32 GH_IOLockAlloc(...) asm("_IOLockAlloc");
extern "C" UInt32 GH_IOMallocAligned(...) asm("_IOMallocAligned");


/* real addr 0x119f0 */
bool IOATIR500Surface::start(IOService *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  bool bVar1;
  UInt8 *pIVar2;
  SInt32 iVar3;
  UInt32 uVar4;
  UInt8 *this_00;
  UInt8 *pIVar5;
  UInt8 *pIVar6;
  UInt8 *pIVar7;
  UInt32 uVar8;
  SInt32 iVar9;
  
  iVar3 = IOUserClient::start(real_param_1);
  if (iVar3 == 0) {
    return false;
  }
  M<UInt8 *>(self + 0xd50) = param_1;
  M<UInt32>(self + 0xd58) = 0;
  iVar3 = M<SInt32>(param_1 + 0x50);
  M<UInt32>(self + 0xa4) = 0xffffffe0;
  M<UInt32>(self + 0x80) = 0;
  M<UInt32>(self + 0x84) = 0;
  M<SInt32>(self + 0x7c) = iVar3 + -0x3fffffff;
  uVar4 = GH_IOLockAlloc();
  M<UInt32>(self + 0xd4c) = 0;
  M<UInt32>(self + 0x88) = 0;
  M<UInt32>(self + 0xc04) = uVar4;
  M<UInt32>(self + 0x8c) = 0;
  M<UInt32>(self + 0x90) = 0;
  M<UInt32>(self + 0xd54) = 0;
  M<UInt32>(self + 0xbe8) = 0;
  M<UInt32>(self + 0xbfc) = 0;
  M<UInt16>(self + 0xbd4) = 0;
  M<UInt16>(self + 0xbd6) = 0;
  M<UInt16>(self + 0xbd8) = 0;
  M<UInt16>(self + 0xbda) = 0;
  M<UInt32>(self + 0xc18) = 0x20000000;
  M<UInt32>(self + 0xc1c) = 0x20000000;
  self[0xc09] = 0x0;
  self[0xbf7] = 0x0;
  iVar3 = 0x17;
  pIVar6 = self + 0xa8;
  pIVar7 = self + 0xd0;
  pIVar2 = self;
  pIVar5 = self;
  do {
    M<UInt16>(pIVar2 + 0xbc) = 0;
    M<UInt16>(pIVar2 + 0xbe) = 0;
    M<UInt16>(pIVar2 + 0xc0) = 0;
    M<UInt16>(pIVar2 + 0xc4) = 0;
    M<UInt16>(pIVar2 + 0xc6) = 0;
    M<UInt16>(pIVar2 + 200) = 1;
    M<UInt16>(pIVar2 + 0xca) = 1;
    pIVar2[0xdc] = 0x0;
    pIVar2[0xdd] = 0x0;
    pIVar2[0xde] = 0x0;
    pIVar2[0xdf] = 0xff;
    pIVar2[0xe0] = 0x0;
    pIVar2[0xe1] = 0x0;
    pIVar2[0xe3] = 0x6;
    pIVar2[0xe4] = 0x0;
    M<UInt32>(pIVar2 + 0xa8) = 0;
    M<UInt32>(pIVar2 + 0xac) = 0;
    M<UInt32>(pIVar2 + 0xb0) = 0;
    M<UInt32>(pIVar2 + 0xb4) = 0;
    M<UInt32>(pIVar2 + 0xb8) = 0;
    M<UInt32>(pIVar2 + 0xcc) = 0;
    M<UInt32>(pIVar2 + 0xd0) = 0xffffffff;
    M<UInt32>(pIVar2 + 0xd4) = 0;
    M<UInt32>(pIVar2 + 0xd8) = 0;
    M<UInt32>(pIVar7 + 0x14) = M<UInt32>(pIVar7 + 0x14) & 0xff0007ff | 0x111000;
    M<UInt32>(pIVar2 + 0xe8) = 0;
    pIVar7 = pIVar7 + 0x78;
    M<UInt32>(pIVar2 + 0xec) = 0;
    M<UInt8 *>(pIVar5 + 0xb70) = pIVar6;
    pIVar2 = pIVar2 + 0x78;
    pIVar6 = pIVar6 + 0x78;
    pIVar5 = pIVar5 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = 0;
  pIVar6 = self + 0xc30;
  pIVar2 = self;
  pIVar5 = self;
  do {
    M<UInt32>(pIVar2 + 0xd60) = 0;
    M<UInt32>(pIVar2 + 0xd64) = 0;
    pIVar7 = pIVar6 + 0xc;
    pIVar5[0xcac] = 0x0;
    pIVar5[0xcad] = 0x0;
    iVar9 = 4;
    M<UInt16>(pIVar5 + 0xcae) = 0;
    M<UInt32>(pIVar5 + 0xcb0) = 0;
    M<UInt32>(pIVar5 + 0xc20) = 0;
    M<UInt32>(pIVar5 + 0xc24) = 0;
    M<UInt32>(pIVar5 + 0xc28) = 0;
    M<UInt16>(pIVar5 + 0xc2e) = 0;
    M<UInt16>(pIVar5 + 0xc2c) = 2;
    M<UInt32>(pIVar5 + 0xc30) = 0;
    M<UInt32>(pIVar5 + 0xc34) = 0;
    M<UInt32>(pIVar5 + 0xc38) = 0;
    do {
      M<UInt32>(pIVar7) = 0;
      M<UInt32>(pIVar7 + 4) = 0;
      M<UInt32>(pIVar7 + 8) = 0;
      M<UInt16>(pIVar7 + 0xe) = 0;
      M<UInt16>(pIVar7 + 0xc) = 2;
      M<UInt32>(pIVar7 + 0x10) = 0;
      M<UInt32>(pIVar7 + 0x14) = 0;
      M<UInt32>(pIVar7 + 0x18) = 0;
      pIVar7 = pIVar7 + 0x1c;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    bVar1 = iVar3 != 1;
    pIVar6 = pIVar6 + 0x94;
    pIVar2 = pIVar2 + 8;
    pIVar5 = pIVar5 + 0x94;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  self[0xbd1] = 0x0;
  M<UInt16>(self + 0xbd2) = 0;
  self[0xc08] = 0x0;
  self[0xbec] = 0x0;
  self[0xbd0] = 0x0;
  self[0xbf4] = 0x1;
  self[0xbed] = 0x0;
  self[0xbf0] = 0x0;
  self[0xbf1] = 0x0;
  self[0xbf2] = 0x0;
  self[0xbf3] = 0x0;
  self[0xbef] = 0x0;
  M<UInt32>(self + 0xd48) = 0;
  M<UInt32>(self + 0xbcc) = 0;
  M<UInt32>(self + 0xc00) = 0;
  M<UInt32>(self + 0xd84) = 0;
  M<UInt32>(self + 0xc0c) = 0;
  M<UInt32>(self + 0xd88) = 0;
  M<UInt32>(self + 0xc10) = 0;
  M<UInt32>(self + 0xd8c) = 0;
  M<UInt32>(self + 0xd70) = 0;
  this_00 = M<UInt8 *>(self + 0xd50);
  M<UInt32>(self + 0xbf8) = 0x307fffff;
  M<UInt32>(self + 0xc14) = 0xffff;
  if (M<SInt32>(this_00 + 0xcc) == 0) {
LAB_00011d4c:
    iVar3 = ((IOATIR500Accelerator *)(this_00))->getVRAMDescriptors();
    if (iVar3 != 0) {
      this_00 = M<UInt8 *>(self + 0xd50);
      bVar1 = true;
      goto LAB_00011d6c;
    }
    this_00 = M<UInt8 *>(self + 0xd50);
  }
  else {
    uVar8 = 0;
    pIVar2 = self;
    do {
      iVar3 = GH_IOMallocAligned(0xc,0x20);
      M<SInt32>(pIVar2 + 0xd60) = iVar3;
      if (iVar3 == 0) {
LAB_00011d38:
        this_00 = M<UInt8 *>(self + 0xd50);
        break;
      }
      iVar3 = M<SInt32>(self + 0xd50);
      if (iVar3 != 0) {
        M<SInt32>(iVar3 + 0x804) = M<SInt32>(iVar3 + 0x804) + 0xc;
      }
      M<UInt32>(pIVar2 + 0xd64) = 0xc;
      *M<UInt32 *>(pIVar2 + 0xd60) = 0;
      M<UInt16>(M<SInt32>(pIVar2 + 0xd60) + 4) = 0;
      M<UInt16>(M<SInt32>(pIVar2 + 0xd60) + 6) = 0;
      M<UInt16>(M<SInt32>(pIVar2 + 0xd60) + 8) = 0;
      M<UInt16>(M<SInt32>(pIVar2 + 0xd60) + 10) = 0;
      iVar3 = this->allocMasterSwapBuffer(uVar8,0x9000);
      if (iVar3 == 0) goto LAB_00011d38;
      this_00 = M<UInt8 *>(self + 0xd50);
      uVar8 = uVar8 + 1;
      pIVar2 = pIVar2 + 8;
    } while (uVar8 < M<UInt32>(this_00 + 0xcc));
    if (M<UInt32>(this_00 + 0xcc) == uVar8) goto LAB_00011d4c;
  }
  bVar1 = false;
LAB_00011d6c:
  M<UInt8 **>(self + 0xd5c) = (UInt8 **)kSurfaceMethods; /* IOATIR500Surface::start(IOService*)::methodDescs */
  iVar3 = M<SInt32>(this_00 + 0x5c);
  if (iVar3 == 0) {
    M<UInt8 *>(self + 0x9c) = self;
    M<UInt8 *>(self + 0xa0) = self;
  }
  else {
    iVar9 = M<SInt32>(iVar3 + 0xa0);
    M<SInt32>(self + 0x9c) = iVar3;
    M<SInt32>(self + 0xa0) = iVar9;
    M<UInt8 *>(iVar9 + 0x9c) = self;
    M<UInt8 *>(iVar3 + 0xa0) = self;
  }
  M<UInt8 *>(this_00 + 0x5c) = self;
  M<SInt32>(M<SInt32>(self + 0xd50) + 0x730) = M<SInt32>(M<SInt32>(self + 0xd50) + 0x730) + 1;
  if (bVar1) {
    M<UInt32>(self + 0xd58) = 1;
  }
  else {
    IOATIR500Surface::stop(real_param_1);
  }
  return bVar1;
}
