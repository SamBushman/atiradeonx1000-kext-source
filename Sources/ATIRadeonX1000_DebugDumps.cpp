/*
 * ATIRadeonX1000_DebugDumps.cpp
 *
 * RESOLVED (ledger pass): the two debug-dump helpers that had no body in the rebuild (real addrs in parentheses):
 * dump_registers (0x1b8a0) - prints the RBBM/CP/VAP status registers through IOLog with IOSleep gaps, then steps the
 * CP microengine control register (CP_ME_CNTL, +0x7d0) through the values 0x13, 0x17, 0x18, 0x19, 0x1a, 0x1b in the
 * bits 16-23 field (printing it each time) - and DumpPCIeGART (0x1b470) - prints a range of PCIe GART entries
 * through kprintf.
 *
 * Transcribed mechanically from the decompile (Tools/ghidra2cpp.py, Headers/GhidraCompat.h); registers is the mapped
 * register aperture (accelerator+0x860).
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h"
#include "../Headers/GhidraCompat.h"

extern "C" void IOLog(const char *format, ...);
extern "C" void kprintf(const char *format, ...);
extern "C" void IOSleep(unsigned int milliseconds);

void DumpPCIeGART(UInt32 *gartTable, UInt32 firstEntry, UInt32 entryCount) {

  UInt8 *entryByte2;
  UInt8 *entryByte1;
  UInt8 entryByte0;
  UInt32 entryWord;
  SInt32 entryIndex;
  UInt32 printed;
  UInt32 *entryCursor;
  
  if ((gartTable != (UInt32 *)0x0) && (entryCount != 0)) {
    printed = 0;
    entryCursor = gartTable + firstEntry;
    do {
      entryWord = *entryCursor;
      entryByte2 = (UInt8 *)((SInt32)entryCursor + 2);
      entryByte1 = (UInt8 *)((SInt32)entryCursor + 1);
      entryByte0 = M<UInt8>(entryCursor);
      entryIndex = printed + firstEntry;
      printed = printed + 1;
      entryCursor = entryCursor + 1;
      kprintf("ATI_PCIe:DumpPCIeGART() GART(0x%08lx)[%d] = 0x%08lx\n",gartTable,entryIndex,
                   (UInt32)(UInt8)entryWord << 0x18 | (UInt32)*entryByte2 << 0x10 | (UInt32)*entryByte1 << 8 |
                   (UInt32)entryByte0);
      IOSleep(100);
    } while (entryCount != printed);
  }
  return;
}

void dump_registers(ATIRadeonX1000 *accelerator) {
    UInt8 *acceleratorBytes = reinterpret_cast<UInt8 *>(accelerator);

  UInt32 value;
  SInt32 registers;
  
  registers = M<SInt32>(acceleratorBytes + 0x860);
  IOSleep(1000);
  value = loadWordByteReversed(&M<UInt8>(registers + 0xe40));
  IOLog("REG> RBBM_STATUS = 0x%08lX (%lu)\n",value,value);
  IOSleep(0);
  value = loadWordByteReversed(&M<UInt8>(registers + 0x7c0));
  IOLog("REG> CP_STAT = 0x%08lX (%lu)\n",value,value);
  IOSleep(0);
  value = loadWordByteReversed(&M<UInt8>(registers + 0x700));
  IOLog("REG> CP_RB_BASE = 0x%08lX (%lu)\n",value,value);
  IOSleep(0);
  value = loadWordByteReversed(&M<UInt8>(registers + 0x704));
  IOLog("REG> CP_RB_CNTL = 0x%08lX (%lu)\n",value,value);
  IOSleep(0);
  value = loadWordByteReversed(&M<UInt8>(registers + 0x710));
  IOLog("REG> CP_RB_RPTR = 0x%08lX (%lu)\n",value,value);
  IOSleep(0);
  value = loadWordByteReversed(&M<UInt8>(registers + 0x714));
  IOLog("REG> CP_RB_WPTR = 0x%08lX (%lu)\n",value,value);
  IOSleep(0);
  value = loadWordByteReversed(&M<UInt8>(registers + 0x730));
  IOLog("REG> CP_IB2_BASE = 0x%08lX (%lu)\n",value,value);
  IOSleep(0);
  value = loadWordByteReversed(&M<UInt8>(registers + 0x734));
  IOLog("REG> CP_IB2_BUFSZ = 0x%08lX (%lu)\n",value,value);
  IOSleep(0);
  value = loadWordByteReversed(&M<UInt8>(registers + 0x738));
  IOLog("REG> CP_IB_BASE = 0x%08lX (%lu)\n",value,value);
  IOSleep(0);
  value = loadWordByteReversed(&M<UInt8>(registers + 0x73c));
  IOLog("REG> CP_IB_BUFSZ = 0x%08lX (%lu)\n",value,value);
  IOSleep(0);
  value = loadWordByteReversed(&M<UInt8>(registers + 0x740));
  IOLog("REG> CP_CSQ_CNTL = 0x%08lX (%lu)\n",value,value);
  IOSleep(0);
  value = loadWordByteReversed(&M<UInt8>(registers + 0x744));
  IOLog("REG> CP_CSQ_MODE = 0x%08lX (%lu)\n",value,value);
  IOSleep(0);
  value = loadWordByteReversed(&M<UInt8>(registers + 0x7b8));
  IOLog("REG> CP_CSQ_AVAIL = 0x%08lX (%lu)\n",value,value);
  IOSleep(0);
  value = loadWordByteReversed(&M<UInt8>(registers + 2000));
  IOLog("REG> CP_ME_CNTL = 0x%08lX (%lu)\n",value,value);
  IOSleep(0);
  value = loadWordByteReversed(&M<UInt8>(registers + 0x7ec));
  IOLog("REG> CP_DEBUG = 0x%08lX (%lu)\n",value,value);
  IOSleep(0);
  value = loadWordByteReversed(&M<UInt8>(registers + 0x7f8));
  IOLog("REG> CP_CSQ_STAT = 0x%08lX (%lu)\n",value,value);
  IOSleep(0);
  value = loadWordByteReversed(&M<UInt8>(registers + 0x2080));
  IOLog("REG> VAP_CNTL = 0x%08lX (%lu)\n",value,value);
  IOSleep(0);
  value = loadWordByteReversed(&M<UInt8>(registers + 0x2084));
  IOLog("REG> VAP_VF_CNTL = 0x%08lX (%lu)\n",value,value);
  IOSleep(0);
  value = loadWordByteReversed(&M<UInt8>(registers + 0x2140));
  IOLog("REG> VAP_CNTL_STATUS = 0x%08lX (%lu)\n",value,value);
  IOSleep(0);
  value = loadWordByteReversed(&M<UInt8>(registers + 0x221c));
  IOLog("REG> VAP_CLIP_CNTL = 0x%08lX (%lu)\n",value,value);
  IOSleep(0);
  storeWordByteReversed(&M<UInt8>(registers + 2000), loadWordByteReversed(&M<UInt8>(registers + 2000)) & 0xffe0ffff | 0x130000);
  enforceInOrderExecutionIO();
  value = loadWordByteReversed(&M<UInt8>(registers + 2000));
  IOLog("REG> CP_ME_CNTL = 0x%08lX (%lu)\n",value,value);
  IOSleep(0);
  storeWordByteReversed(&M<UInt8>(registers + 2000), loadWordByteReversed(&M<UInt8>(registers + 2000)) & 0xffe0ffff | 0x170000);
  enforceInOrderExecutionIO();
  value = loadWordByteReversed(&M<UInt8>(registers + 2000));
  IOLog("REG> CP_ME_CNTL = 0x%08lX (%lu)\n",value,value);
  IOSleep(0);
  storeWordByteReversed(&M<UInt8>(registers + 2000), loadWordByteReversed(&M<UInt8>(registers + 2000)) & 0xffe0ffff | 0x180000);
  enforceInOrderExecutionIO();
  value = loadWordByteReversed(&M<UInt8>(registers + 2000));
  IOLog("REG> CP_ME_CNTL = 0x%08lX (%lu)\n",value,value);
  IOSleep(0);
  storeWordByteReversed(&M<UInt8>(registers + 2000), loadWordByteReversed(&M<UInt8>(registers + 2000)) & 0xffe0ffff | 0x190000);
  enforceInOrderExecutionIO();
  value = loadWordByteReversed(&M<UInt8>(registers + 2000));
  IOLog("REG> CP_ME_CNTL = 0x%08lX (%lu)\n",value,value);
  IOSleep(0);
  storeWordByteReversed(&M<UInt8>(registers + 2000), loadWordByteReversed(&M<UInt8>(registers + 2000)) & 0xffe0ffff | 0x1a0000);
  enforceInOrderExecutionIO();
  value = loadWordByteReversed(&M<UInt8>(registers + 2000));
  IOLog("REG> CP_ME_CNTL = 0x%08lX (%lu)\n",value,value);
  IOSleep(0);
  storeWordByteReversed(&M<UInt8>(registers + 2000), loadWordByteReversed(&M<UInt8>(registers + 2000)) & 0xffe0ffff | 0x1b0000);
  enforceInOrderExecutionIO();
  value = loadWordByteReversed(&M<UInt8>(registers + 2000));
  IOLog("REG> CP_ME_CNTL = 0x%08lX (%lu)\n",value,value);
  IOSleep(0);
  return;
}
