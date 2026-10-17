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
extern const VendorExternalMethod kSurfaceMethods[19] asm("__ZZN16IOATIR500Surface5startEP9IOServiceE11methodDescs");   /* ATIR500Surface_ExternalMethods.cpp */

extern "C" UInt32 GH_IOLockAlloc(...) asm("_IOLockAlloc");
extern "C" UInt32 GH_IOMallocAligned(...) asm("_IOMallocAligned");

/* a swap-buffer entry as IOATIR500Surface::start leaves it: every field zero except the 16-bit state at +0x0c, which is 2 */
static inline void ClearSwapBufferEntry(SwapBufferEntry *e) {
    e->unknown_0x00 = 0;
    e->gartOffset = 0;
    e->memory = 0;
    e->unknown_0x0e = 0;
    e->unknown_0x0c = 2;
    e->stamp = 0;
    e->header = 0;
    e->rectWordIndex = 0;
}

/* real addr 0x119f0 */
bool IOATIR500Surface::start(IOService *provider) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *providerBytes = reinterpret_cast<UInt8 *>(provider);

  bool success;
  UInt8 *pIVar2;
  SInt32 iVar3;
  UInt32 lock;
  UInt8 *accelerator;
  UInt8 *formatSlot;
  UInt8 *surfaceBuffer;
  UInt8 *tilingCursor;
  UInt32 panelIndex;
  SInt32 iVar9;
  PanelRecord *panel;
  
  iVar3 = IOUserClient::start(provider);
  if (iVar3 == 0) {
    return false;
  }
  M<UInt8 *>(self + 0xd50) = providerBytes;
  M<UInt32>(self + 0xd58) = 0;
  iVar3 = M<SInt32>(providerBytes + 0x50);
  M<UInt32>(self + 0xa4) = 0xffffffe0;
  M<UInt32>(self + 0x80) = 0;
  M<UInt32>(self + 0x84) = 0;
  M<SInt32>(self + 0x7c) = iVar3 + -0x3fffffff;
  lock = GH_IOLockAlloc();
  M<UInt32>(self + 0xd4c) = 0;
  M<UInt32>(self + 0x88) = 0;
  M<UInt32>(self + 0xc04) = lock;
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
  surfaceBuffer = self + 0xa8;
  tilingCursor = self + 0xd0;
  pIVar2 = self;
  formatSlot = self;
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
    M<UInt32>(tilingCursor + 0x14) = M<UInt32>(tilingCursor + 0x14) & 0xff0007ff | 0x111000;
    M<UInt32>(pIVar2 + 0xe8) = 0;
    tilingCursor = tilingCursor + 0x78;
    M<UInt32>(pIVar2 + 0xec) = 0;
    M<UInt8 *>(formatSlot + 0xb70) = surfaceBuffer;
    pIVar2 = pIVar2 + 0x78;
    surfaceBuffer = surfaceBuffer + 0x78;
    formatSlot = formatSlot + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  panel = PANEL_RECORD(self, 0);
  for (iVar3 = 0; iVar3 < 2; iVar3++, panel++) {
    M<UInt32>(self + iVar3 * 8 + 0xd60) = 0;                 /* the per-id region record pointer and size */
    M<UInt32>(self + iVar3 * 8 + 0xd64) = 0;
    panel->active = 0x0;
    panel->swapMode = 0x0;
    panel->slotIndex = 0;
    panel->swapBufferSize = 0;
    ClearSwapBufferEntry(&panel->entries[0]);
    for (iVar9 = 1; iVar9 < 5; iVar9++) {
      ClearSwapBufferEntry(&panel->entries[iVar9]);
    }
  }
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
  accelerator = M<UInt8 *>(self + 0xd50);
  M<UInt32>(self + 0xbf8) = 0x307fffff;
  M<UInt32>(self + 0xc14) = 0xffff;
  if (M<SInt32>(accelerator + 0xcc) == 0) {
LAB_00011d4c:
    iVar3 = ((IOATIR500Accelerator *)(accelerator))->getVRAMDescriptors();
    if (iVar3 != 0) {
      accelerator = M<UInt8 *>(self + 0xd50);
      success = true;
      goto LAB_00011d6c;
    }
    accelerator = M<UInt8 *>(self + 0xd50);
  }
  else {
    panelIndex = 0;
    pIVar2 = self;
    do {
      iVar3 = GH_IOMallocAligned(0xc,0x20);
      M<SInt32>(pIVar2 + 0xd60) = iVar3;
      if (iVar3 == 0) {
LAB_00011d38:
        accelerator = M<UInt8 *>(self + 0xd50);
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
      iVar3 = this->allocMasterSwapBuffer(panelIndex,0x9000);
      if (iVar3 == 0) goto LAB_00011d38;
      accelerator = M<UInt8 *>(self + 0xd50);
      panelIndex = panelIndex + 1;
      pIVar2 = pIVar2 + 8;
    } while (panelIndex < M<UInt32>(accelerator + 0xcc));
    if (M<UInt32>(accelerator + 0xcc) == panelIndex) goto LAB_00011d4c;
  }
  success = false;
LAB_00011d6c:
  M<UInt8 **>(self + 0xd5c) = (UInt8 **)kSurfaceMethods; /* IOATIR500Surface::start(IOService*)::methodDescs */
  iVar3 = M<SInt32>(accelerator + 0x5c);
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
  M<UInt8 *>(accelerator + 0x5c) = self;
  M<SInt32>(M<SInt32>(self + 0xd50) + 0x730) = M<SInt32>(M<SInt32>(self + 0xd50) + 0x730) + 1;
  if (success) {
    M<UInt32>(self + 0xd58) = 1;
  }
  else {
    IOATIR500Surface::stop(provider);
  }
  return success;
}
