/*
 * ATIRadeonX1000_DebugDumps.cpp
 *
 * RESOLVED (ledger pass): the two debug-dump helpers that had no body in the rebuild (real addrs in parentheses):
 * dump_registers (0x1b8a0) - prints the RBBM/CP/VAP status registers through IOLog with IOSleep gaps, then steps the
 * CP microengine control register (CP_ME_CNTL, +0x7d0) through the values 0x13, 0x17, 0x18, 0x19, 0x1a, 0x1b in the
 * bits 16-23 field (printing it each time) - and DumpPCIeGART (0x1b470) - prints a range of PCIe GART entries
 * through kprintf.
 *
 * Transcribed mechanically from the decompile (Tools/ghidra2cpp.py, Headers/GhidraCompat.h); iVar2 is the mapped
 * register aperture (accelerator+0x860).
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h"
#include "../Headers/GhidraCompat.h"

extern "C" void IOLog(const char *format, ...);
extern "C" void kprintf(const char *format, ...);
extern "C" void IOSleep(unsigned int milliseconds);

void DumpPCIeGART(UInt32 *param_1, UInt32 param_2, UInt32 param_3) {

  UInt8 *pbVar1;
  UInt8 *pbVar2;
  UInt8 bVar3;
  UInt32 uVar4;
  SInt32 iVar5;
  UInt32 uVar6;
  UInt32 *puVar7;
  
  if ((param_1 != (UInt32 *)0x0) && (param_3 != 0)) {
    uVar6 = 0;
    puVar7 = param_1 + param_2;
    do {
      uVar4 = *puVar7;
      pbVar1 = (UInt8 *)((SInt32)puVar7 + 2);
      pbVar2 = (UInt8 *)((SInt32)puVar7 + 1);
      bVar3 = M<UInt8>(puVar7);
      iVar5 = uVar6 + param_2;
      uVar6 = uVar6 + 1;
      puVar7 = puVar7 + 1;
      kprintf("ATI_PCIe:DumpPCIeGART() GART(0x%08lx)[%d] = 0x%08lx\n",param_1,iVar5,
                   (UInt32)(UInt8)uVar4 << 0x18 | (UInt32)*pbVar1 << 0x10 | (UInt32)*pbVar2 << 8 |
                   (UInt32)bVar3);
      IOSleep(100);
    } while (param_3 != uVar6);
  }
  return;
}

void dump_registers(ATIRadeonX1000 *accelerator) {
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(accelerator);

  UInt32 uVar1;
  SInt32 iVar2;
  
  iVar2 = M<SInt32>(param_1 + 0x860);
  IOSleep(1000);
  uVar1 = (UInt32)M<UInt8>(iVar2 + 0xe43) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0xe42) << 0x10 |
          (UInt32)M<UInt8>(iVar2 + 0xe41) << 8 | (UInt32)M<UInt8>(iVar2 + 0xe40);
  IOLog("REG> RBBM_STATUS = 0x%08lX (%lu)\n",uVar1,uVar1);
  IOSleep(0);
  uVar1 = (UInt32)M<UInt8>(iVar2 + 0x7c3) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x7c2) << 0x10 |
          (UInt32)M<UInt8>(iVar2 + 0x7c1) << 8 | (UInt32)M<UInt8>(iVar2 + 0x7c0);
  IOLog("REG> CP_STAT = 0x%08lX (%lu)\n",uVar1,uVar1);
  IOSleep(0);
  uVar1 = (UInt32)M<UInt8>(iVar2 + 0x703) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x702) << 0x10 |
          (UInt32)M<UInt8>(iVar2 + 0x701) << 8 | (UInt32)M<UInt8>(iVar2 + 0x700);
  IOLog("REG> CP_RB_BASE = 0x%08lX (%lu)\n",uVar1,uVar1);
  IOSleep(0);
  uVar1 = (UInt32)M<UInt8>(iVar2 + 0x707) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x706) << 0x10 |
          (UInt32)M<UInt8>(iVar2 + 0x705) << 8 | (UInt32)M<UInt8>(iVar2 + 0x704);
  IOLog("REG> CP_RB_CNTL = 0x%08lX (%lu)\n",uVar1,uVar1);
  IOSleep(0);
  uVar1 = (UInt32)M<UInt8>(iVar2 + 0x713) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x712) << 0x10 |
          (UInt32)M<UInt8>(iVar2 + 0x711) << 8 | (UInt32)M<UInt8>(iVar2 + 0x710);
  IOLog("REG> CP_RB_RPTR = 0x%08lX (%lu)\n",uVar1,uVar1);
  IOSleep(0);
  uVar1 = (UInt32)M<UInt8>(iVar2 + 0x717) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x716) << 0x10 |
          (UInt32)M<UInt8>(iVar2 + 0x715) << 8 | (UInt32)M<UInt8>(iVar2 + 0x714);
  IOLog("REG> CP_RB_WPTR = 0x%08lX (%lu)\n",uVar1,uVar1);
  IOSleep(0);
  uVar1 = (UInt32)M<UInt8>(iVar2 + 0x733) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x732) << 0x10 |
          (UInt32)M<UInt8>(iVar2 + 0x731) << 8 | (UInt32)M<UInt8>(iVar2 + 0x730);
  IOLog("REG> CP_IB2_BASE = 0x%08lX (%lu)\n",uVar1,uVar1);
  IOSleep(0);
  uVar1 = (UInt32)M<UInt8>(iVar2 + 0x737) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x736) << 0x10 |
          (UInt32)M<UInt8>(iVar2 + 0x735) << 8 | (UInt32)M<UInt8>(iVar2 + 0x734);
  IOLog("REG> CP_IB2_BUFSZ = 0x%08lX (%lu)\n",uVar1,uVar1);
  IOSleep(0);
  uVar1 = (UInt32)M<UInt8>(iVar2 + 0x73b) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x73a) << 0x10 |
          (UInt32)M<UInt8>(iVar2 + 0x739) << 8 | (UInt32)M<UInt8>(iVar2 + 0x738);
  IOLog("REG> CP_IB_BASE = 0x%08lX (%lu)\n",uVar1,uVar1);
  IOSleep(0);
  uVar1 = (UInt32)M<UInt8>(iVar2 + 0x73f) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x73e) << 0x10 |
          (UInt32)M<UInt8>(iVar2 + 0x73d) << 8 | (UInt32)M<UInt8>(iVar2 + 0x73c);
  IOLog("REG> CP_IB_BUFSZ = 0x%08lX (%lu)\n",uVar1,uVar1);
  IOSleep(0);
  uVar1 = (UInt32)M<UInt8>(iVar2 + 0x743) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x742) << 0x10 |
          (UInt32)M<UInt8>(iVar2 + 0x741) << 8 | (UInt32)M<UInt8>(iVar2 + 0x740);
  IOLog("REG> CP_CSQ_CNTL = 0x%08lX (%lu)\n",uVar1,uVar1);
  IOSleep(0);
  uVar1 = (UInt32)M<UInt8>(iVar2 + 0x747) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x746) << 0x10 |
          (UInt32)M<UInt8>(iVar2 + 0x745) << 8 | (UInt32)M<UInt8>(iVar2 + 0x744);
  IOLog("REG> CP_CSQ_MODE = 0x%08lX (%lu)\n",uVar1,uVar1);
  IOSleep(0);
  uVar1 = (UInt32)M<UInt8>(iVar2 + 0x7bb) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x7ba) << 0x10 |
          (UInt32)M<UInt8>(iVar2 + 0x7b9) << 8 | (UInt32)M<UInt8>(iVar2 + 0x7b8);
  IOLog("REG> CP_CSQ_AVAIL = 0x%08lX (%lu)\n",uVar1,uVar1);
  IOSleep(0);
  uVar1 = (UInt32)M<UInt8>(iVar2 + 0x7d3) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x7d2) << 0x10 |
          (UInt32)M<UInt8>(iVar2 + 0x7d1) << 8 | (UInt32)M<UInt8>(iVar2 + 2000);
  IOLog("REG> CP_ME_CNTL = 0x%08lX (%lu)\n",uVar1,uVar1);
  IOSleep(0);
  uVar1 = (UInt32)M<UInt8>(iVar2 + 0x7ef) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x7ee) << 0x10 |
          (UInt32)M<UInt8>(iVar2 + 0x7ed) << 8 | (UInt32)M<UInt8>(iVar2 + 0x7ec);
  IOLog("REG> CP_DEBUG = 0x%08lX (%lu)\n",uVar1,uVar1);
  IOSleep(0);
  uVar1 = (UInt32)M<UInt8>(iVar2 + 0x7fb) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x7fa) << 0x10 |
          (UInt32)M<UInt8>(iVar2 + 0x7f9) << 8 | (UInt32)M<UInt8>(iVar2 + 0x7f8);
  IOLog("REG> CP_CSQ_STAT = 0x%08lX (%lu)\n",uVar1,uVar1);
  IOSleep(0);
  uVar1 = (UInt32)M<UInt8>(iVar2 + 0x2083) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x2082) << 0x10 |
          (UInt32)M<UInt8>(iVar2 + 0x2081) << 8 | (UInt32)M<UInt8>(iVar2 + 0x2080);
  IOLog("REG> VAP_CNTL = 0x%08lX (%lu)\n",uVar1,uVar1);
  IOSleep(0);
  uVar1 = (UInt32)M<UInt8>(iVar2 + 0x2087) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x2086) << 0x10 |
          (UInt32)M<UInt8>(iVar2 + 0x2085) << 8 | (UInt32)M<UInt8>(iVar2 + 0x2084);
  IOLog("REG> VAP_VF_CNTL = 0x%08lX (%lu)\n",uVar1,uVar1);
  IOSleep(0);
  uVar1 = (UInt32)M<UInt8>(iVar2 + 0x2143) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x2142) << 0x10 |
          (UInt32)M<UInt8>(iVar2 + 0x2141) << 8 | (UInt32)M<UInt8>(iVar2 + 0x2140);
  IOLog("REG> VAP_CNTL_STATUS = 0x%08lX (%lu)\n",uVar1,uVar1);
  IOSleep(0);
  uVar1 = (UInt32)M<UInt8>(iVar2 + 0x221f) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x221e) << 0x10 |
          (UInt32)M<UInt8>(iVar2 + 0x221d) << 8 | (UInt32)M<UInt8>(iVar2 + 0x221c);
  IOLog("REG> VAP_CLIP_CNTL = 0x%08lX (%lu)\n",uVar1,uVar1);
  IOSleep(0);
  M<UInt32>(iVar2 + 2000) =
       (UInt32)M<UInt8>(iVar2 + 2000) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x7d1) << 0x10 |
       ((M<UInt8>(iVar2 + 0x7d2) & 0xe0) << 0x10 | 0x130000) >> 8 | (UInt32)M<UInt8>(iVar2 + 0x7d3);
  enforceInOrderExecutionIO();
  uVar1 = (UInt32)M<UInt8>(iVar2 + 0x7d3) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x7d2) << 0x10 |
          (UInt32)M<UInt8>(iVar2 + 0x7d1) << 8 | (UInt32)M<UInt8>(iVar2 + 2000);
  IOLog("REG> CP_ME_CNTL = 0x%08lX (%lu)\n",uVar1,uVar1);
  IOSleep(0);
  M<UInt32>(iVar2 + 2000) =
       (UInt32)M<UInt8>(iVar2 + 2000) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x7d1) << 0x10 |
       ((M<UInt8>(iVar2 + 0x7d2) & 0xe0) << 0x10 | 0x170000) >> 8 | (UInt32)M<UInt8>(iVar2 + 0x7d3);
  enforceInOrderExecutionIO();
  uVar1 = (UInt32)M<UInt8>(iVar2 + 0x7d3) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x7d2) << 0x10 |
          (UInt32)M<UInt8>(iVar2 + 0x7d1) << 8 | (UInt32)M<UInt8>(iVar2 + 2000);
  IOLog("REG> CP_ME_CNTL = 0x%08lX (%lu)\n",uVar1,uVar1);
  IOSleep(0);
  M<UInt32>(iVar2 + 2000) =
       (UInt32)M<UInt8>(iVar2 + 2000) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x7d1) << 0x10 |
       ((M<UInt8>(iVar2 + 0x7d2) & 0xe0) << 0x10 | 0x180000) >> 8 | (UInt32)M<UInt8>(iVar2 + 0x7d3);
  enforceInOrderExecutionIO();
  uVar1 = (UInt32)M<UInt8>(iVar2 + 0x7d3) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x7d2) << 0x10 |
          (UInt32)M<UInt8>(iVar2 + 0x7d1) << 8 | (UInt32)M<UInt8>(iVar2 + 2000);
  IOLog("REG> CP_ME_CNTL = 0x%08lX (%lu)\n",uVar1,uVar1);
  IOSleep(0);
  M<UInt32>(iVar2 + 2000) =
       (UInt32)M<UInt8>(iVar2 + 2000) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x7d1) << 0x10 |
       ((M<UInt8>(iVar2 + 0x7d2) & 0xe0) << 0x10 | 0x190000) >> 8 | (UInt32)M<UInt8>(iVar2 + 0x7d3);
  enforceInOrderExecutionIO();
  uVar1 = (UInt32)M<UInt8>(iVar2 + 0x7d3) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x7d2) << 0x10 |
          (UInt32)M<UInt8>(iVar2 + 0x7d1) << 8 | (UInt32)M<UInt8>(iVar2 + 2000);
  IOLog("REG> CP_ME_CNTL = 0x%08lX (%lu)\n",uVar1,uVar1);
  IOSleep(0);
  M<UInt32>(iVar2 + 2000) =
       (UInt32)M<UInt8>(iVar2 + 2000) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x7d1) << 0x10 |
       ((M<UInt8>(iVar2 + 0x7d2) & 0xe0) << 0x10 | 0x1a0000) >> 8 | (UInt32)M<UInt8>(iVar2 + 0x7d3);
  enforceInOrderExecutionIO();
  uVar1 = (UInt32)M<UInt8>(iVar2 + 0x7d3) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x7d2) << 0x10 |
          (UInt32)M<UInt8>(iVar2 + 0x7d1) << 8 | (UInt32)M<UInt8>(iVar2 + 2000);
  IOLog("REG> CP_ME_CNTL = 0x%08lX (%lu)\n",uVar1,uVar1);
  IOSleep(0);
  M<UInt32>(iVar2 + 2000) =
       (UInt32)M<UInt8>(iVar2 + 2000) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x7d1) << 0x10 |
       ((M<UInt8>(iVar2 + 0x7d2) & 0xe0) << 0x10 | 0x1b0000) >> 8 | (UInt32)M<UInt8>(iVar2 + 0x7d3);
  enforceInOrderExecutionIO();
  uVar1 = (UInt32)M<UInt8>(iVar2 + 0x7d3) << 0x18 | (UInt32)M<UInt8>(iVar2 + 0x7d2) << 0x10 |
          (UInt32)M<UInt8>(iVar2 + 0x7d1) << 8 | (UInt32)M<UInt8>(iVar2 + 2000);
  IOLog("REG> CP_ME_CNTL = 0x%08lX (%lu)\n",uVar1,uVar1);
  IOSleep(0);
  return;
}
