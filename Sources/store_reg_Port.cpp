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
extern "C" void store_reg(tracked_register_set *state, UInt32 regIndex, UInt32 value) {
    UInt8 *stateBytes = reinterpret_cast<UInt8 *>(state);

  UInt32 slot;
  UInt32 controlWord;
  SInt32 writeCount;
  
  if (regIndex == 0x10ea) {
    M<UInt32>(stateBytes) = value;
    return;
  }
  if (0x10ea < regIndex) {
    if (regIndex == 0x118e) {
      M<UInt32>(stateBytes + 0x98) = value;
      return;
    }
    if (0x118e < regIndex) {
      if (regIndex == 0x1381) {
        M<UInt32>(stateBytes + 100) = value;
        return;
      }
      if (0x1381 < regIndex) {
        if (regIndex == 0x138e) {
          M<UInt32>(stateBytes + 0xb4) = value;
          return;
        }
        if (regIndex < 0x138f) {
          if (regIndex == 0x1386) {
            M<UInt32>(stateBytes + 0xdc) = value;
            return;
          }
          if (regIndex != 0x138a) {
            if (regIndex != 0x1383) {
              return;
            }
            M<UInt32>(stateBytes + 0xd8) = value;
            return;
          }
          M<UInt32>(stateBytes + 0xb0) = value;
          return;
        }
        if (regIndex == 0x13c0) {
          M<UInt32>(stateBytes + 0x54) = value;
          return;
        }
        if (regIndex < 0x13c1) {
          if (regIndex != 0x1394) {
            return;
          }
          M<UInt32>(stateBytes + 0x34) = value;
          return;
        }
        if (regIndex == 0x13c1) {
          M<UInt32>(stateBytes + 0x20) = value;
          return;
        }
        if (regIndex != 0x13c7) {
          return;
        }
        M<UInt32>(stateBytes + 0x1c) = value;
        return;
      }
      if (regIndex == 0x11ac) {
        M<UInt32>(stateBytes + 0x84) = value;
        return;
      }
      if (0x11ac < regIndex) {
        if (regIndex == 0x12f5) {
          M<UInt32>(stateBytes + 0x5c) = value;
          return;
        }
        if (regIndex != 0x1380) {
          if (regIndex != 0x12f0) {
            return;
          }
          M<UInt32>(stateBytes + 0x58) = value;
          return;
        }
        M<UInt32>(stateBytes + 0x38) = value;
        return;
      }
      if (regIndex == 0x11aa) {
        M<UInt32>(stateBytes + 0x7c) = value;
        return;
      }
      if (regIndex < 0x11ab) {
        if (regIndex != 0x11a9) {
          return;
        }
        M<UInt32>(stateBytes + 0x78) = value;
        return;
      }
      M<UInt32>(stateBytes + 0x80) = value;
      return;
    }
    if (regIndex == 0x1130) {
      M<UInt32>(stateBytes + 0xcc) = value;
      return;
    }
    if (0x1130 < regIndex) {
      if (regIndex == 0x1181) {
        M<UInt32>(stateBytes + 0x90) = value;
        return;
      }
      if (0x1181 < regIndex) {
        if (regIndex == 0x118c) {
          M<UInt32>(stateBytes + 0x9c) = value;
          return;
        }
        if (regIndex < 0x118d) {
          if (regIndex != 0x1189) {
            return;
          }
          M<UInt32>(stateBytes + 0x8c) = value;
          return;
        }
        M<UInt32>(stateBytes + 0x94) = value;
        return;
      }
      if (regIndex == 0x1150) {
        M<UInt32>(stateBytes + 0xbc) = value;
        return;
      }
      if (regIndex != 0x1180) {
        if (regIndex != 0x1140) {
          return;
        }
        M<UInt32>(stateBytes + 0xd0) = value;
        return;
      }
      M<UInt32>(stateBytes + 0x88) = value;
      return;
    }
    if (regIndex == 0x10fa) {
      M<UInt32>(stateBytes + 4) = value;
      return;
    }
    if (0x10fa < regIndex) {
      if (regIndex == 0x1110) {
        M<UInt32>(stateBytes + 0xc4) = value;
        return;
      }
      if (regIndex != 0x1120) {
        if (regIndex != 0x1100) {
          return;
        }
        M<UInt32>(stateBytes + 0xc0) = value;
        return;
      }
      M<UInt32>(stateBytes + 200) = value;
      return;
    }
    if (regIndex == 0x10f8) {
      M<UInt32>(stateBytes + 0xe0) = value;
      return;
    }
    if (regIndex < 0x10f9) {
      if (regIndex != 0x10f4) {
        return;
      }
      M<UInt32>(stateBytes + 0xd4) = value;
      return;
    }
    M<UInt32>(stateBytes + 0xe4) = value;
    return;
  }
  if (regIndex == 0x1041) {
    M<UInt32>(stateBytes + 0x70) = value;
    return;
  }
  if (0x1041 < regIndex) {
    if (regIndex == 0x1095) {
      controlWord = M<UInt32>(stateBytes + 0xfc);
      if ((controlWord & 0x10000) != 0) {
        return;
      }
      slot = controlWord & 0x1ff;
      if (slot < 2) {
        writeCount = M<SInt32>(stateBytes + 0x100);
        M<UInt32>(stateBytes + (slot * 6 + writeCount) * 4 + 0x104) = value;
      }
      else {
        writeCount = M<SInt32>(stateBytes + 0x100);
      }
      M<UInt32>(stateBytes + 0x100) = writeCount + 1U;
      if (writeCount + 1U < 6) {
        return;
      }
      M<UInt32>(stateBytes + 0x100) = 0;
      M<UInt32>(stateBytes + 0xfc) = controlWord & 0xfffffe00 | slot + 1 & 0x1ff;
      return;
    }
    if (0x1095 < regIndex) {
      if (regIndex == 0x10ae) {
        M<UInt32>(stateBytes + 0x30) = value;
        return;
      }
      if (regIndex < 0x10af) {
        if (regIndex == 0x109e) {
          M<UInt32>(stateBytes + 0x68) = value;
          return;
        }
        if (regIndex != 0x10a2) {
          if (regIndex != 0x1096) {
            return;
          }
          M<UInt32>(stateBytes + 0x6c) = value;
          return;
        }
        M<UInt32>(stateBytes + 0x60) = value;
        return;
      }
      if (regIndex == 0x10c1) {
        M<UInt32>(stateBytes + 0xa4) = value;
        return;
      }
      if (regIndex < 0x10c2) {
        if (regIndex != 0x10c0) {
          return;
        }
        M<UInt32>(stateBytes + 0xa0) = value;
        return;
      }
      if (regIndex == 0x10c8) {
        M<UInt32>(stateBytes + 0xa8) = value;
        return;
      }
      if (regIndex != 0x10e9) {
        return;
      }
      M<UInt32>(stateBytes + 0x18) = value;
      return;
    }
    if (regIndex == 0x1082) {
      M<UInt32>(stateBytes + 0xf4) = value;
      return;
    }
    if (0x1082 < regIndex) {
      if (regIndex == 0x1087) {
        M<UInt32>(stateBytes + 0xe8) = value;
        return;
      }
      if (regIndex != 0x1094) {
        if (regIndex != 0x1083) {
          return;
        }
        M<UInt32>(stateBytes + 0xf8) = value;
        return;
      }
      M<UInt32>(stateBytes + 0xfc) = value;
      M<UInt32>(stateBytes + 0x100) = 0;
      return;
    }
    if (regIndex == 0x1080) {
      M<UInt32>(stateBytes + 0xec) = value;
      return;
    }
    if (regIndex < 0x1081) {
      if (regIndex != 0x1046) {
        return;
      }
      M<UInt32>(stateBytes + 0x74) = value;
      return;
    }
    M<UInt32>(stateBytes + 0xf0) = value;
    return;
  }
  if (regIndex == 0x887) {
    M<UInt32>(stateBytes + 0x28) = value;
    return;
  }
  if (0x887 < regIndex) {
    if (regIndex == 0x1006) {
      M<UInt32>(stateBytes + 8) = value;
      return;
    }
    if (0x1006 < regIndex) {
      if (regIndex == 0x101d) {
        M<UInt32>(stateBytes + 0xac) = value;
        return;
      }
      if (regIndex != 0x1040) {
        if (regIndex != 0x1008) {
          return;
        }
        M<UInt32>(stateBytes + 0x14) = value;
        return;
      }
      M<UInt32>(stateBytes + 0xb8) = value;
      return;
    }
    if (regIndex == 0x1004) {
      M<UInt32>(stateBytes + 0xc) = value;
      return;
    }
    if (regIndex < 0x1005) {
      if (regIndex != 0x1002) {
        return;
      }
      M<UInt32>(stateBytes + 0x3c) = value;
      return;
    }
    M<UInt32>(stateBytes + 0x10) = value;
    return;
  }
  if (regIndex == 0x82d) {
    M<UInt32>(stateBytes + 0x48) = value;
    return;
  }
  if (0x82d < regIndex) {
    if (regIndex == 0x854) {
      M<UInt32>(stateBytes + 0x4c) = value;
      return;
    }
    if (regIndex != 0x878) {
      if (regIndex != 0x850) {
        return;
      }
      M<UInt32>(stateBytes + 0x24) = value;
      return;
    }
    M<UInt32>(stateBytes + 0x50) = value;
    return;
  }
  if (regIndex == 0x825) {
    M<UInt32>(stateBytes + 0x44) = value;
    return;
  }
  if (regIndex != 0x82c) {
    if (regIndex != 0x824) {
      return;
    }
    M<UInt32>(stateBytes + 0x40) = value;
    return;
  }
  M<UInt32>(stateBytes + 0x2c) = value;
  return;
}
