/*
 * store_reg_Port.cpp
 *
 * store_reg (real addr 0x1abe0, 0 bytes) - mechanically ported from the Ghidra decompile of the shipped kext (Tools/replace_fn.py /
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



struct tracked_register_set;   /* opaque, see ATIRadeonX1000_StoreReg.cpp */
extern "C" void store_reg(tracked_register_set *state, UInt32 regIndex, UInt32 value) asm("__Z9store_regP20tracked_register_setmm");   /* local symbol in the stock kext */

/* real addr 0x1abe0 */
extern "C" void store_reg(tracked_register_set *real_param_1, UInt32 param_2, UInt32 param_3) {
    UInt8 *param_1 = reinterpret_cast<UInt8 *>(real_param_1);

  UInt32 uVar1;
  UInt32 uVar2;
  SInt32 iVar3;
  
  if (param_2 == 0x10ea) {
    M<UInt32>(param_1) = param_3;
    return;
  }
  if (0x10ea < param_2) {
    if (param_2 == 0x118e) {
      M<UInt32>(param_1 + 0x98) = param_3;
      return;
    }
    if (0x118e < param_2) {
      if (param_2 == 0x1381) {
        M<UInt32>(param_1 + 100) = param_3;
        return;
      }
      if (0x1381 < param_2) {
        if (param_2 == 0x138e) {
          M<UInt32>(param_1 + 0xb4) = param_3;
          return;
        }
        if (param_2 < 0x138f) {
          if (param_2 == 0x1386) {
            M<UInt32>(param_1 + 0xdc) = param_3;
            return;
          }
          if (param_2 != 0x138a) {
            if (param_2 != 0x1383) {
              return;
            }
            M<UInt32>(param_1 + 0xd8) = param_3;
            return;
          }
          M<UInt32>(param_1 + 0xb0) = param_3;
          return;
        }
        if (param_2 == 0x13c0) {
          M<UInt32>(param_1 + 0x54) = param_3;
          return;
        }
        if (param_2 < 0x13c1) {
          if (param_2 != 0x1394) {
            return;
          }
          M<UInt32>(param_1 + 0x34) = param_3;
          return;
        }
        if (param_2 == 0x13c1) {
          M<UInt32>(param_1 + 0x20) = param_3;
          return;
        }
        if (param_2 != 0x13c7) {
          return;
        }
        M<UInt32>(param_1 + 0x1c) = param_3;
        return;
      }
      if (param_2 == 0x11ac) {
        M<UInt32>(param_1 + 0x84) = param_3;
        return;
      }
      if (0x11ac < param_2) {
        if (param_2 == 0x12f5) {
          M<UInt32>(param_1 + 0x5c) = param_3;
          return;
        }
        if (param_2 != 0x1380) {
          if (param_2 != 0x12f0) {
            return;
          }
          M<UInt32>(param_1 + 0x58) = param_3;
          return;
        }
        M<UInt32>(param_1 + 0x38) = param_3;
        return;
      }
      if (param_2 == 0x11aa) {
        M<UInt32>(param_1 + 0x7c) = param_3;
        return;
      }
      if (param_2 < 0x11ab) {
        if (param_2 != 0x11a9) {
          return;
        }
        M<UInt32>(param_1 + 0x78) = param_3;
        return;
      }
      M<UInt32>(param_1 + 0x80) = param_3;
      return;
    }
    if (param_2 == 0x1130) {
      M<UInt32>(param_1 + 0xcc) = param_3;
      return;
    }
    if (0x1130 < param_2) {
      if (param_2 == 0x1181) {
        M<UInt32>(param_1 + 0x90) = param_3;
        return;
      }
      if (0x1181 < param_2) {
        if (param_2 == 0x118c) {
          M<UInt32>(param_1 + 0x9c) = param_3;
          return;
        }
        if (param_2 < 0x118d) {
          if (param_2 != 0x1189) {
            return;
          }
          M<UInt32>(param_1 + 0x8c) = param_3;
          return;
        }
        M<UInt32>(param_1 + 0x94) = param_3;
        return;
      }
      if (param_2 == 0x1150) {
        M<UInt32>(param_1 + 0xbc) = param_3;
        return;
      }
      if (param_2 != 0x1180) {
        if (param_2 != 0x1140) {
          return;
        }
        M<UInt32>(param_1 + 0xd0) = param_3;
        return;
      }
      M<UInt32>(param_1 + 0x88) = param_3;
      return;
    }
    if (param_2 == 0x10fa) {
      M<UInt32>(param_1 + 4) = param_3;
      return;
    }
    if (0x10fa < param_2) {
      if (param_2 == 0x1110) {
        M<UInt32>(param_1 + 0xc4) = param_3;
        return;
      }
      if (param_2 != 0x1120) {
        if (param_2 != 0x1100) {
          return;
        }
        M<UInt32>(param_1 + 0xc0) = param_3;
        return;
      }
      M<UInt32>(param_1 + 200) = param_3;
      return;
    }
    if (param_2 == 0x10f8) {
      M<UInt32>(param_1 + 0xe0) = param_3;
      return;
    }
    if (param_2 < 0x10f9) {
      if (param_2 != 0x10f4) {
        return;
      }
      M<UInt32>(param_1 + 0xd4) = param_3;
      return;
    }
    M<UInt32>(param_1 + 0xe4) = param_3;
    return;
  }
  if (param_2 == 0x1041) {
    M<UInt32>(param_1 + 0x70) = param_3;
    return;
  }
  if (0x1041 < param_2) {
    if (param_2 == 0x1095) {
      uVar2 = M<UInt32>(param_1 + 0xfc);
      if ((uVar2 & 0x10000) != 0) {
        return;
      }
      uVar1 = uVar2 & 0x1ff;
      if (uVar1 < 2) {
        iVar3 = M<SInt32>(param_1 + 0x100);
        M<UInt32>(param_1 + (uVar1 * 6 + iVar3) * 4 + 0x104) = param_3;
      }
      else {
        iVar3 = M<SInt32>(param_1 + 0x100);
      }
      M<UInt32>(param_1 + 0x100) = iVar3 + 1U;
      if (iVar3 + 1U < 6) {
        return;
      }
      M<UInt32>(param_1 + 0x100) = 0;
      M<UInt32>(param_1 + 0xfc) = uVar2 & 0xfffffe00 | uVar1 + 1 & 0x1ff;
      return;
    }
    if (0x1095 < param_2) {
      if (param_2 == 0x10ae) {
        M<UInt32>(param_1 + 0x30) = param_3;
        return;
      }
      if (param_2 < 0x10af) {
        if (param_2 == 0x109e) {
          M<UInt32>(param_1 + 0x68) = param_3;
          return;
        }
        if (param_2 != 0x10a2) {
          if (param_2 != 0x1096) {
            return;
          }
          M<UInt32>(param_1 + 0x6c) = param_3;
          return;
        }
        M<UInt32>(param_1 + 0x60) = param_3;
        return;
      }
      if (param_2 == 0x10c1) {
        M<UInt32>(param_1 + 0xa4) = param_3;
        return;
      }
      if (param_2 < 0x10c2) {
        if (param_2 != 0x10c0) {
          return;
        }
        M<UInt32>(param_1 + 0xa0) = param_3;
        return;
      }
      if (param_2 == 0x10c8) {
        M<UInt32>(param_1 + 0xa8) = param_3;
        return;
      }
      if (param_2 != 0x10e9) {
        return;
      }
      M<UInt32>(param_1 + 0x18) = param_3;
      return;
    }
    if (param_2 == 0x1082) {
      M<UInt32>(param_1 + 0xf4) = param_3;
      return;
    }
    if (0x1082 < param_2) {
      if (param_2 == 0x1087) {
        M<UInt32>(param_1 + 0xe8) = param_3;
        return;
      }
      if (param_2 != 0x1094) {
        if (param_2 != 0x1083) {
          return;
        }
        M<UInt32>(param_1 + 0xf8) = param_3;
        return;
      }
      M<UInt32>(param_1 + 0xfc) = param_3;
      M<UInt32>(param_1 + 0x100) = 0;
      return;
    }
    if (param_2 == 0x1080) {
      M<UInt32>(param_1 + 0xec) = param_3;
      return;
    }
    if (param_2 < 0x1081) {
      if (param_2 != 0x1046) {
        return;
      }
      M<UInt32>(param_1 + 0x74) = param_3;
      return;
    }
    M<UInt32>(param_1 + 0xf0) = param_3;
    return;
  }
  if (param_2 == 0x887) {
    M<UInt32>(param_1 + 0x28) = param_3;
    return;
  }
  if (0x887 < param_2) {
    if (param_2 == 0x1006) {
      M<UInt32>(param_1 + 8) = param_3;
      return;
    }
    if (0x1006 < param_2) {
      if (param_2 == 0x101d) {
        M<UInt32>(param_1 + 0xac) = param_3;
        return;
      }
      if (param_2 != 0x1040) {
        if (param_2 != 0x1008) {
          return;
        }
        M<UInt32>(param_1 + 0x14) = param_3;
        return;
      }
      M<UInt32>(param_1 + 0xb8) = param_3;
      return;
    }
    if (param_2 == 0x1004) {
      M<UInt32>(param_1 + 0xc) = param_3;
      return;
    }
    if (param_2 < 0x1005) {
      if (param_2 != 0x1002) {
        return;
      }
      M<UInt32>(param_1 + 0x3c) = param_3;
      return;
    }
    M<UInt32>(param_1 + 0x10) = param_3;
    return;
  }
  if (param_2 == 0x82d) {
    M<UInt32>(param_1 + 0x48) = param_3;
    return;
  }
  if (0x82d < param_2) {
    if (param_2 == 0x854) {
      M<UInt32>(param_1 + 0x4c) = param_3;
      return;
    }
    if (param_2 != 0x878) {
      if (param_2 != 0x850) {
        return;
      }
      M<UInt32>(param_1 + 0x24) = param_3;
      return;
    }
    M<UInt32>(param_1 + 0x50) = param_3;
    return;
  }
  if (param_2 == 0x825) {
    M<UInt32>(param_1 + 0x44) = param_3;
    return;
  }
  if (param_2 != 0x82c) {
    if (param_2 != 0x824) {
      return;
    }
    M<UInt32>(param_1 + 0x40) = param_3;
    return;
  }
  M<UInt32>(param_1 + 0x2c) = param_3;
  return;
}
