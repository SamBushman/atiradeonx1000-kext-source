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

  bool moreEntries;
  UInt32 rbbmStatus;
  UInt32 cpCsqStat;
  UInt32 pcieReg10;
  UInt32 vapCntlStatus;
  UInt32 cpMeCntl;
  UInt32 reg1724;
  UInt32 pcieReg21;
  UInt32 cpStat;
  UInt32 mcData;
  UInt32 pcieReg104;
  UInt32 cpRbCntl;
  UInt32 regEC;
  UInt32 pcieReg18;
  UInt32 reg790;
  UInt32 regE7C;
  UInt32 reg4c;
  SInt32 mmioBase;
  SInt32 registers;
  UInt32 reg7fc;
  UInt32 reg7b0;
  UInt32 cpCsqCntl;
  UInt32 reg130;
  UInt32 cpCsqAvail;
  UInt32 pcieRegB4;
  UInt32 reg5002Half;
  UInt32 cpCsqStatBefore;
  UInt32 queueAddress;
  UInt32 csqData;
  SInt32 pollCount;
  SInt32 checksum;
  
  this->disable_GPUSensor();
  mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  cpCsqStatBefore = loadWordByteReversed(&M<UInt8>(mmioBase + 0x7f8));
  pollCount = 0;
  do {
    GH_assert_wait_timeout(&gl_assert_wait_timeout_event,0,100,1000);
    GH_thread_block(0);
    registers = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
    if (cpCsqStatBefore != (loadWordByteReversed(&M<UInt8>(registers + 0x7f8)))) {
      this->enable_GPUSensor();
      return;
    }
    pollCount = pollCount + 1;
  } while (pollCount != 0x186a1);
  reg5002Half = loadHalfByteReversed(&M<UInt8>(registers + 0x5002)) | 0x1000000;      /* one lhbrx, as the shipped code */
  GH_IOSleep(10);
  GH_IOLog("** ASIC Hang Log Start **\n");
  GH_IOSleep(10);
  mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  M<UInt32>(mmioBase + 0x30) = 0x21000000;
  enforceInOrderExecutionIO();
  pcieReg21 = loadWordByteReversed(&M<UInt8>(mmioBase + 0x34));
  M<UInt32>(mmioBase + 0x30) = 0x18000000;
  enforceInOrderExecutionIO();
  pcieReg18 = loadWordByteReversed(&M<UInt8>(mmioBase + 0x34));
  reg7fc = loadWordByteReversed(&M<UInt8>(mmioBase + 0x7fc));
  GH_IOLog("0x%08lx %08lx %08lx %08lx\n",reg5002Half,pcieReg21,pcieReg18,reg7fc);
  GH_IOSleep(10);
  mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  cpCsqStat = loadWordByteReversed(&M<UInt8>(mmioBase + 0x7f8));
  cpStat = loadWordByteReversed(&M<UInt8>(mmioBase + 0x7c0));
  reg790 = loadWordByteReversed(&M<UInt8>(mmioBase + 0x790));
  reg7b0 = loadWordByteReversed(&M<UInt8>(mmioBase + 0x7b0));
  GH_IOLog("0x%08lx %08lx %08lx %08lx\n",cpCsqStat,cpStat,reg790,reg7b0);
  GH_IOSleep(10);
  mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  M<UInt32>(mmioBase + 0x30) = 0x10000000;
  enforceInOrderExecutionIO();
  pcieReg10 = loadWordByteReversed(&M<UInt8>(mmioBase + 0x34));
  if ((M<UInt32>(self + kIOATIR500Accelerator_hwCapabilityBits) & 0x400000) == 0) {
    M<UInt32>(mmioBase + 0x70) = 0;
    enforceInOrderExecutionIO();
  }
  else {
    M<UInt32>(mmioBase + 0x70) = 0x8000000;
    enforceInOrderExecutionIO();
  }
  mcData = loadWordByteReversed(&M<UInt8>(mmioBase + 0x74));
  regE7C = loadWordByteReversed(&M<UInt8>(mmioBase + 0xe7c));
  rbbmStatus = loadWordByteReversed(&M<UInt8>(mmioBase + 0xe40));
  GH_IOLog("0x%08lx %08lx %08lx %08lx\n",pcieReg10,mcData,regE7C,rbbmStatus);
  GH_IOSleep(10);
  mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  vapCntlStatus = loadWordByteReversed(&M<UInt8>(mmioBase + 0x2140));
  M<UInt32>(mmioBase + 0x30) = 0x4010000;
  enforceInOrderExecutionIO();
  pcieReg104 = loadWordByteReversed(&M<UInt8>(mmioBase + 0x34));
  reg4c = loadWordByteReversed(&M<UInt8>(mmioBase + 0x4c));
  cpCsqCntl = loadWordByteReversed(&M<UInt8>(mmioBase + 0x740));
  GH_IOLog("0x%08lx %08lx %08lx %08lx\n",vapCntlStatus,pcieReg104,reg4c,cpCsqCntl);
  GH_IOSleep(10);
  mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  cpMeCntl = loadWordByteReversed(&M<UInt8>(mmioBase + 2000));
  cpRbCntl = loadWordByteReversed(&M<UInt8>(mmioBase + 0x704));
  M<UInt32>(mmioBase + 0x30) = 0xb4000000;
  enforceInOrderExecutionIO();
  pcieRegB4 = loadWordByteReversed(&M<UInt8>(mmioBase + 0x34));
  reg130 = loadWordByteReversed(&M<UInt8>(mmioBase + 0x130));
  GH_IOLog("0x%08lx %08lx %08lx %08lx\n",cpMeCntl,cpRbCntl,pcieRegB4,reg130);
  GH_IOSleep(10);
  mmioBase = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
  reg1724 = loadWordByteReversed(&M<UInt8>(mmioBase + 0x1724));
  regEC = loadWordByteReversed(&M<UInt8>(mmioBase + 0xec));
  cpCsqAvail = loadWordByteReversed(&M<UInt8>(mmioBase + 0x7b8));
  checksum = reg5002Half + pcieReg21 + pcieReg18 + reg7fc + cpCsqStat + cpStat + reg790 + reg7b0 + pcieReg10 + mcData +
           regE7C + rbbmStatus + vapCntlStatus + pcieReg104 + reg4c + cpCsqCntl + cpMeCntl + cpRbCntl + pcieRegB4 + reg130 +
           reg1724 + regEC + cpCsqAvail;
  queueAddress = 0;
  GH_IOLog("0x%08lx %08lx %08lx\n",reg1724,regEC,cpCsqAvail);
  GH_IOSleep(10);
  do {
    registers = M<SInt32>(self + kIOATIR500Accelerator_mmioBase);
    M<UInt32>(registers + 0x7f0) =
         queueAddress << 0x18 | (queueAddress & 0xff00) << 8 | queueAddress >> 8 & 0xff00 | queueAddress >> 0x18;
    enforceInOrderExecutionIO();
    csqData = loadWordByteReversed(&M<UInt8>(registers + 0x7f4));
    checksum = checksum + csqData;
    GH_IOLog("%ld:0x%08lx\n",queueAddress >> 2,csqData);
    GH_IOSleep(10);
    moreEntries = queueAddress != 0xffc;
    queueAddress = queueAddress + 4;
  } while (moreEntries);
  GH_IOLog("0x%08lx\n",checksum);
  GH_IOSleep(10);
  GH_IOLog("** ASIC Hang Log End **\n");
  GH_IOSleep(10);
  return;
}
