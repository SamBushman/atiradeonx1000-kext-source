/*
 * IOATIR500GLContext_start_Port.cpp
 *
 * IOATIR500GLContext::start (real addr 0x7690, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern const VendorExternalMethod kGLRegularMethods[20] asm("__ZZN18IOATIR500GLContext5startEP9IOServiceE11methodDescs");   /* IOATIR500GLContext_ExternalMethods.cpp */

extern "C" UInt32 GH_ZN8OSObjectnwEm(...) asm("__ZN8OSObjectnwEm");


/* real addr 0x7690 */
bool IOATIR500GLContext::start(IOService *real_param_1) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  bool bVar1;
  UInt8 *pIVar2;
  SInt32 iVar3;
  UInt8 *this_00;
  SInt32 *piVar4;
  UInt8 bVar5;
  
  iVar3 = IOUserClient::start(real_param_1);
  if (iVar3 == 0) {
    return 0;
  }
  M<UInt8 *>(self + 200) = param_1;
  M<UInt32>(self + 0x108) = 0;
  M<UInt32>(self + 0x294) = 0;
  M<UInt32>(self + 0x7c) = 0;
  M<UInt16>(self + 0xd8) = 1;
  M<UInt16>(self + 0xac) = 1;
  M<UInt32>(self + 0x290) = 0;
  M<UInt32>(self + 0x298) = 0;
  M<UInt32>(self + 0x29c) = 0;
  M<UInt32>(self + 0x88) = 0;
  M<UInt32>(self + 0x84) = 0;
  M<UInt32>(self + 0xcc) = 0;
  M<UInt32>(self + 0xd0) = 0;
  M<UInt32>(self + 0xd4) = 0;
  M<UInt16>(self + 0xda) = 0;
  M<UInt32>(self + 0xdc) = 0;
  M<UInt32>(self + 0xe0) = 0;
  M<UInt32>(self + 0xe4) = 0;
  M<UInt32>(self + 0xe8) = 0;
  M<UInt32>(self + 0xec) = 0;
  M<UInt32>(self + 0xf0) = 0;
  M<UInt32>(self + 0x28c) = 0;
  M<UInt32>(self + 0xf4) = 0;
  M<UInt32>(self + 0xf8) = 0;
  M<UInt32>(self + 0xfc) = 0;
  M<UInt16>(self + 0x102) = 0;
  M<UInt16>(self + 0x100) = 0;
  M<UInt32>(self + 0x104) = 0;
  M<UInt16>(self + 0xae) = 6;
  iVar3 = 0x10;
  M<UInt32>(self + 0xb0) = 0x20000;
  M<UInt32>(self + 0xb4) = 0x10000;
  pIVar2 = self;
  do {
    M<UInt32>(pIVar2 + 0x10c) = 0;
    M<UInt32>(pIVar2 + 0x110) = 0;
    M<UInt32>(pIVar2 + 0x114) = 0;
    M<UInt16>(pIVar2 + 0x11a) = 0;
    M<UInt16>(pIVar2 + 0x118) = 0;
    M<UInt32>(pIVar2 + 0x11c) = 0;
    M<UInt32>(pIVar2 + 0x120) = 0;
    pIVar2 = pIVar2 + 0x18;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  M<UInt16>(self + 0x98) = 0;
  M<UInt16>(self + 0x90) = 0;
  M<UInt16>(self + 0x92) = 0;
  M<UInt16>(self + 0x94) = 0;
  M<UInt16>(self + 0x9a) = 1;
  M<UInt16>(self + 0x96) = 0;
  iVar3 = 0;
  pIVar2 = self;
  do {
    bVar1 = iVar3 != 2;
    M<UInt32>(pIVar2 + 0x9c) = 0;
    iVar3 = iVar3 + 1;
    pIVar2 = pIVar2 + 4;
  } while (bVar1);
  M<UInt32>(self + 0xc4) = 0;
  iVar3 = 0x2a;
  M<UInt32>(self + 0x8c) = 0x20000000;
  pIVar2 = self;
  do {
    M<UInt32>(pIVar2 + 0x2a4) = 0;
    pIVar2 = pIVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  this_00 = (UInt8 *)new IOATIR500Shared();   /* real: OSObject::operator new(0x28) + the IOATIR500Shared constructor */
  bVar5 = (this_00 == (UInt8 *)0x0) << 1;
  M<UInt8 *>(self + 0x88) = this_00;
  if (!(bool)(bVar5 >> 1 & 1)) {
    iVar3 = VCALL(M<SInt32>(this_00), 0x48)(this_00);
    if (iVar3 == 0) {
      VCALL(*M<SInt32 *>(self + 0x88), 0x18)(M<SInt32 *>(self + 0x88));
      M<UInt32>(self + 0x88) = 0;
    }
    else {
      M<UInt32>(M<SInt32>(self + 0x88) + 0xc) = M<UInt32>(self + 200);
      M<UInt32>(M<SInt32>(self + 0x88) + 8) = M<UInt32>(self + 0x78);
      piVar4 = M<SInt32 *>(self + 200);
      if ((piVar4[0x18] == 0) && (piVar4[0x1a] == 0)) {
        iVar3 = VCALL(*piVar4, 0x530)(piVar4);
        if (iVar3 == 0) goto LAB_0000790c;
        piVar4 = M<SInt32 *>(self + 200);
      }
      M<SInt32>(self + 0x80) = piVar4[0x18];
      piVar4[0x18] = (SInt32)self;
      M<SInt32>(M<SInt32>(self + 200) + 0x738) = M<SInt32>(M<SInt32>(self + 200) + 0x738) + 1;
      iVar3 = ((IOATIR500Accelerator *)(M<UInt8 *>(self + 200)))->getVRAMDescriptors();
      if (((iVar3 != 0) &&
          (iVar3 = ((IOATIR500Accelerator *)(M<UInt8 *>(self + 200)))->allocCommandBuffer((VendorCommandBuffer *)((UInt8 *)(self + 0xcc)),0x20000), iVar3 != 0)) &&
         (iVar3 = this->allocAllContextBuffers(0x8000), iVar3 != 0)) {
        M<UInt32>(self + 0x294) = 1;
        M<UInt8 **>(self + 0x2a0) = (UInt8 **)kGLRegularMethods; /* IOATIR500GLContext::start(IOService*)::methodDescs */
        return 1;
      }
    }
  }
LAB_0000790c:
  IOATIR500GLContext::stop(real_param_1);
  return 0;
}
