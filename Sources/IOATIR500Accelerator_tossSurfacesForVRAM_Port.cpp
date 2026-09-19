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
UInt32 IOATIR500Accelerator::tossSurfacesForVRAM(IOATIR500Surface *real_param_1, VendorTextureBuffer**param_2, SInt32 param_3, VendorTextureBuffer *real_param_4, bool param_5) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);
    UInt8 *param_4 = reinterpret_cast<UInt8 *>(real_param_4);

  bool bVar1;
  UInt8 *pVVar2;
  UInt32 uVar3;
  UInt32 in_register_00000020;
  UInt8 **ppVVar4;
  UInt8 *pIVar5;
  UInt32 uVar6;
  UInt8 *pAVar7;
  UInt8 *this_00;
  UInt8 bVar8;
  long lVar9;
  
  pIVar5 = M<UInt8 *>(self + 0x5c);
  if (pIVar5 != (UInt8 *)0x0) {
    bVar8 = (0 < param_3) << 2 | (param_3 == 0) << 1;
    this_00 = pIVar5;
    do {
      this_00 = M<UInt8 *>(this_00 + 0xa0);
      if ((this_00 != param_1) &&
         ((((UInt32)param_5) == 0 || (M<SInt32>(this_00 + 0xd48) != 0)))) {
        ppVVar4 = (UInt8 **)param_2;
        lVar9 = param_3;
        if ((bool)(bVar8 >> 2 & 1)) {
          do {
            pVVar2 = *ppVVar4;
            ppVVar4 = ppVVar4 + 1;
            if (((pVVar2 != (UInt8 *)0x0) &&
                (pVVar2[0x20] == 0x0)) &&
               (this_00 == M<UInt8 *>(pVVar2 + 0x50))) goto LAB_00003f10;
            lVar9 = lVar9 + -1;
          } while (lVar9 != 0);
        }
        else if (!(bool)(bVar8 >> 1 & 1)) goto LAB_00003f10;
        uVar6 = 0;
        pAVar7 = (UInt8 *)(this_00 + 0xa8);
        do {
          if ((((M<SInt32>(this_00 + 0xc14) == 0xffff) || ((1 < uVar6 && (1 < uVar6 - 4)))) &&
              (M<SInt32>(pAVar7 + 8) != 0)) &&
             (((M<UInt32>(this_00 + 0xbd0) & 0xffff0000) == 0 ||
              (pAVar7 != M<UInt8 *>(this_00 + 0xb70))))) {
            if (M<SInt32>(this_00 + 0xd48) == 0) {
              ((IOATIR500Surface *)(this_00))->move_buffer_to_backing_store((ATIR500SurfaceBuffer *)(pAVar7));
LAB_00003ec0:
              VCALL(M<SInt32>(self), 0x528)(self,param_4);
            }
            else if (M<SInt32>(this_00 + 0xbcc) == 0) {
              VCALL(M<SInt32>(this_00), 0x5cc)(this_00,uVar6);
              goto LAB_00003ec0;
            }
            if (M<SInt32>(param_4 + 0x48) != 0) goto LAB_00003f28;
          }
          bVar1 = uVar6 != 0x16;
          pAVar7 = pAVar7 + 0x78;
          uVar6 = uVar6 + 1;
        } while (bVar1);
        if (M<SInt32>(param_4 + 0x48) != 0) goto LAB_00003f28;
        pIVar5 = M<UInt8 *>(self + 0x5c);
      }
LAB_00003f10: ;
    } while (this_00 != pIVar5);
  }
  uVar3 = 0;
  if (M<SInt32>(param_4 + 0x48) != 0) {
LAB_00003f28:
    uVar3 = 1;
  }
  return uVar3;
}
