/*
 * ATIRadeonX1000_DumpASICHangState_Port.cpp
 *
 * ATIRadeonX1000::DumpASICHangState (real addr 0x1d480, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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
extern "C" UInt32 gl_assert_wait_timeout_event;   /* ATIRadeonX1000_DataTables.cpp */

extern "C" UInt32 GH_IOLog(...) asm("_IOLog");
extern "C" UInt32 GH_IOSleep(...) asm("_IOSleep");
extern "C" UInt32 GH_assert_wait_timeout(...) asm("_assert_wait_timeout");
extern "C" UInt32 GH_thread_block(...) asm("_thread_block");


/* real addr 0x1d480 */
void ATIRadeonX1000::DumpASICHangState() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  UInt8 uVar2;
  UInt8 uVar3;
  UInt8 bVar4;
  UInt8 bVar5;
  UInt8 bVar6;
  UInt8 bVar7;
  UInt32 uVar8;
  UInt32 uVar9;
  UInt32 uVar10;
  UInt32 uVar11;
  UInt32 uVar12;
  UInt32 uVar13;
  UInt32 uVar14;
  UInt32 uVar15;
  UInt32 uVar16;
  UInt32 uVar17;
  UInt32 uVar18;
  UInt32 uVar19;
  UInt32 uVar20;
  UInt32 uVar21;
  UInt32 uVar22;
  UInt32 uVar23;
  SInt32 iVar24;
  SInt32 iVar25;
  UInt32 uVar26;
  UInt32 uVar27;
  UInt32 uVar28;
  UInt32 uVar29;
  UInt32 uVar30;
  UInt32 uVar31;
  UInt32 uVar32;
  
  this->disable_GPUSensor();
  iVar24 = M<SInt32>(self + 0x860);
  bVar4 = M<UInt8>(iVar24 + 0x7fb);
  bVar5 = M<UInt8>(iVar24 + 0x7fa);
  bVar6 = M<UInt8>(iVar24 + 0x7f9);
  bVar7 = M<UInt8>(iVar24 + 0x7f8);
  iVar24 = 0;
  do {
    GH_assert_wait_timeout(&gl_assert_wait_timeout_event,0,100,1000);
    GH_thread_block(0);
    iVar25 = M<SInt32>(self + 0x860);
    if (((UInt32)bVar4 << 0x18 | (UInt32)bVar5 << 0x10 | (UInt32)bVar6 << 8 | (UInt32)bVar7) !=
        ((UInt32)M<UInt8>(iVar25 + 0x7fb) << 0x18 | (UInt32)M<UInt8>(iVar25 + 0x7fa) << 0x10 |
         (UInt32)M<UInt8>(iVar25 + 0x7f9) << 8 | (UInt32)M<UInt8>(iVar25 + 0x7f8))) {
      this->enable_GPUSensor();
      return;
    }
    iVar24 = iVar24 + 1;
  } while (iVar24 != 0x186a1);
  uVar2 = M<UInt8>(iVar25 + 0x5003);
  uVar3 = M<UInt8>(iVar25 + 0x5002);
  GH_IOSleep(10);
  uVar32 = CONCAT11(uVar2,uVar3) | 0x1000000;
  GH_IOLog("** ASIC Hang Log Start **\n");
  GH_IOSleep(10);
  iVar24 = M<SInt32>(self + 0x860);
  M<UInt32>(iVar24 + 0x30) = 0x21000000;
  enforceInOrderExecutionIO();
  uVar14 = (UInt32)M<UInt8>(iVar24 + 0x37) << 0x18 | (UInt32)M<UInt8>(iVar24 + 0x36) << 0x10 |
           (UInt32)M<UInt8>(iVar24 + 0x35) << 8 | (UInt32)M<UInt8>(iVar24 + 0x34);
  M<UInt32>(iVar24 + 0x30) = 0x18000000;
  enforceInOrderExecutionIO();
  uVar20 = (UInt32)M<UInt8>(iVar24 + 0x37) << 0x18 | (UInt32)M<UInt8>(iVar24 + 0x36) << 0x10 |
           (UInt32)M<UInt8>(iVar24 + 0x35) << 8 | (UInt32)M<UInt8>(iVar24 + 0x34);
  uVar26 = (UInt32)M<UInt8>(iVar24 + 0x7ff) << 0x18 | (UInt32)M<UInt8>(iVar24 + 0x7fe) << 0x10 |
           (UInt32)M<UInt8>(iVar24 + 0x7fd) << 8 | (UInt32)M<UInt8>(iVar24 + 0x7fc);
  GH_IOLog("0x%08lx %08lx %08lx %08lx\n",uVar32,uVar14,uVar20,uVar26);
  GH_IOSleep(10);
  iVar24 = M<SInt32>(self + 0x860);
  uVar9 = (UInt32)M<UInt8>(iVar24 + 0x7fb) << 0x18 | (UInt32)M<UInt8>(iVar24 + 0x7fa) << 0x10 |
          (UInt32)M<UInt8>(iVar24 + 0x7f9) << 8 | (UInt32)M<UInt8>(iVar24 + 0x7f8);
  uVar15 = (UInt32)M<UInt8>(iVar24 + 0x7c3) << 0x18 | (UInt32)M<UInt8>(iVar24 + 0x7c2) << 0x10 |
           (UInt32)M<UInt8>(iVar24 + 0x7c1) << 8 | (UInt32)M<UInt8>(iVar24 + 0x7c0);
  uVar21 = (UInt32)M<UInt8>(iVar24 + 0x793) << 0x18 | (UInt32)M<UInt8>(iVar24 + 0x792) << 0x10 |
           (UInt32)M<UInt8>(iVar24 + 0x791) << 8 | (UInt32)M<UInt8>(iVar24 + 0x790);
  uVar27 = (UInt32)M<UInt8>(iVar24 + 0x7b3) << 0x18 | (UInt32)M<UInt8>(iVar24 + 0x7b2) << 0x10 |
           (UInt32)M<UInt8>(iVar24 + 0x7b1) << 8 | (UInt32)M<UInt8>(iVar24 + 0x7b0);
  GH_IOLog("0x%08lx %08lx %08lx %08lx\n",uVar9,uVar15,uVar21,uVar27);
  GH_IOSleep(10);
  iVar24 = M<SInt32>(self + 0x860);
  M<UInt32>(iVar24 + 0x30) = 0x10000000;
  enforceInOrderExecutionIO();
  uVar10 = (UInt32)M<UInt8>(iVar24 + 0x37) << 0x18 | (UInt32)M<UInt8>(iVar24 + 0x36) << 0x10 |
           (UInt32)M<UInt8>(iVar24 + 0x35) << 8 | (UInt32)M<UInt8>(iVar24 + 0x34);
  if ((M<UInt32>(self + 0x98) & 0x400000) == 0) {
    M<UInt32>(iVar24 + 0x70) = 0;
    enforceInOrderExecutionIO();
  }
  else {
    M<UInt32>(iVar24 + 0x70) = 0x8000000;
    enforceInOrderExecutionIO();
  }
  uVar16 = (UInt32)M<UInt8>(iVar24 + 0x77) << 0x18 | (UInt32)M<UInt8>(iVar24 + 0x76) << 0x10 |
           (UInt32)M<UInt8>(iVar24 + 0x75) << 8 | (UInt32)M<UInt8>(iVar24 + 0x74);
  uVar22 = (UInt32)M<UInt8>(iVar24 + 0xe7f) << 0x18 | (UInt32)M<UInt8>(iVar24 + 0xe7e) << 0x10 |
           (UInt32)M<UInt8>(iVar24 + 0xe7d) << 8 | (UInt32)M<UInt8>(iVar24 + 0xe7c);
  uVar8 = (UInt32)M<UInt8>(iVar24 + 0xe43) << 0x18 | (UInt32)M<UInt8>(iVar24 + 0xe42) << 0x10 |
          (UInt32)M<UInt8>(iVar24 + 0xe41) << 8 | (UInt32)M<UInt8>(iVar24 + 0xe40);
  GH_IOLog("0x%08lx %08lx %08lx %08lx\n",uVar10,uVar16,uVar22,uVar8);
  GH_IOSleep(10);
  iVar24 = M<SInt32>(self + 0x860);
  uVar11 = (UInt32)M<UInt8>(iVar24 + 0x2143) << 0x18 | (UInt32)M<UInt8>(iVar24 + 0x2142) << 0x10 |
           (UInt32)M<UInt8>(iVar24 + 0x2141) << 8 | (UInt32)M<UInt8>(iVar24 + 0x2140);
  M<UInt32>(iVar24 + 0x30) = 0x4010000;
  enforceInOrderExecutionIO();
  uVar17 = (UInt32)M<UInt8>(iVar24 + 0x37) << 0x18 | (UInt32)M<UInt8>(iVar24 + 0x36) << 0x10 |
           (UInt32)M<UInt8>(iVar24 + 0x35) << 8 | (UInt32)M<UInt8>(iVar24 + 0x34);
  uVar23 = (UInt32)M<UInt8>(iVar24 + 0x4f) << 0x18 | (UInt32)M<UInt8>(iVar24 + 0x4e) << 0x10 |
           (UInt32)M<UInt8>(iVar24 + 0x4d) << 8 | (UInt32)M<UInt8>(iVar24 + 0x4c);
  uVar28 = (UInt32)M<UInt8>(iVar24 + 0x743) << 0x18 | (UInt32)M<UInt8>(iVar24 + 0x742) << 0x10 |
           (UInt32)M<UInt8>(iVar24 + 0x741) << 8 | (UInt32)M<UInt8>(iVar24 + 0x740);
  GH_IOLog("0x%08lx %08lx %08lx %08lx\n",uVar11,uVar17,uVar23,uVar28);
  GH_IOSleep(10);
  iVar24 = M<SInt32>(self + 0x860);
  uVar12 = (UInt32)M<UInt8>(iVar24 + 0x7d3) << 0x18 | (UInt32)M<UInt8>(iVar24 + 0x7d2) << 0x10 |
           (UInt32)M<UInt8>(iVar24 + 0x7d1) << 8 | (UInt32)M<UInt8>(iVar24 + 2000);
  uVar18 = (UInt32)M<UInt8>(iVar24 + 0x707) << 0x18 | (UInt32)M<UInt8>(iVar24 + 0x706) << 0x10 |
           (UInt32)M<UInt8>(iVar24 + 0x705) << 8 | (UInt32)M<UInt8>(iVar24 + 0x704);
  M<UInt32>(iVar24 + 0x30) = 0xb4000000;
  enforceInOrderExecutionIO();
  uVar31 = (UInt32)M<UInt8>(iVar24 + 0x37) << 0x18 | (UInt32)M<UInt8>(iVar24 + 0x36) << 0x10 |
           (UInt32)M<UInt8>(iVar24 + 0x35) << 8 | (UInt32)M<UInt8>(iVar24 + 0x34);
  uVar29 = (UInt32)M<UInt8>(iVar24 + 0x133) << 0x18 | (UInt32)M<UInt8>(iVar24 + 0x132) << 0x10 |
           (UInt32)M<UInt8>(iVar24 + 0x131) << 8 | (UInt32)M<UInt8>(iVar24 + 0x130);
  GH_IOLog("0x%08lx %08lx %08lx %08lx\n",uVar12,uVar18,uVar31,uVar29);
  GH_IOSleep(10);
  iVar24 = M<SInt32>(self + 0x860);
  uVar13 = (UInt32)M<UInt8>(iVar24 + 0x1727) << 0x18 | (UInt32)M<UInt8>(iVar24 + 0x1726) << 0x10 |
           (UInt32)M<UInt8>(iVar24 + 0x1725) << 8 | (UInt32)M<UInt8>(iVar24 + 0x1724);
  uVar19 = (UInt32)M<UInt8>(iVar24 + 0xef) << 0x18 | (UInt32)M<UInt8>(iVar24 + 0xee) << 0x10 |
           (UInt32)M<UInt8>(iVar24 + 0xed) << 8 | (UInt32)M<UInt8>(iVar24 + 0xec);
  uVar30 = (UInt32)M<UInt8>(iVar24 + 0x7bb) << 0x18 | (UInt32)M<UInt8>(iVar24 + 0x7ba) << 0x10 |
           (UInt32)M<UInt8>(iVar24 + 0x7b9) << 8 | (UInt32)M<UInt8>(iVar24 + 0x7b8);
  iVar24 = uVar32 + uVar14 + uVar20 + uVar26 + uVar9 + uVar15 + uVar21 + uVar27 + uVar10 + uVar16 +
           uVar22 + uVar8 + uVar11 + uVar17 + uVar23 + uVar28 + uVar12 + uVar18 + uVar31 + uVar29 +
           uVar13 + uVar19 + uVar30;
  uVar9 = 0;
  GH_IOLog("0x%08lx %08lx %08lx\n",uVar13,uVar19,uVar30);
  GH_IOSleep(10);
  do {
    iVar25 = M<SInt32>(self + 0x860);
    M<UInt32>(iVar25 + 0x7f0) =
         uVar9 << 0x18 | (uVar9 & 0xff00) << 8 | uVar9 >> 8 & 0xff00 | uVar9 >> 0x18;
    enforceInOrderExecutionIO();
    uVar10 = (UInt32)M<UInt8>(iVar25 + 0x7f7) << 0x18 | (UInt32)M<UInt8>(iVar25 + 0x7f6) << 0x10 |
             (UInt32)M<UInt8>(iVar25 + 0x7f5) << 8 | (UInt32)M<UInt8>(iVar25 + 0x7f4);
    iVar24 = iVar24 + uVar10;
    GH_IOLog("%ld:0x%08lx\n",uVar9 >> 2,uVar10);
    GH_IOSleep(10);
    bVar1 = uVar9 != 0xffc;
    uVar9 = uVar9 + 4;
  } while (bVar1);
  GH_IOLog("0x%08lx\n",iVar24);
  GH_IOSleep(10);
  GH_IOLog("** ASIC Hang Log End **\n");
  GH_IOSleep(10);
  return;
}
