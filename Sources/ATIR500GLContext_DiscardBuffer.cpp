/*
 * ATIR500GLContext_DiscardBuffer.cpp
 *
 * ATIR500GLContext::discard_command_buffer (real addr 0x27580, 2228 bytes): walks the not-yet-submitted command
 * buffer's embedded-opcode stream and drops every texture / vertex-buffer / query reference it had bound (an atomic
 * lwarx/stwcx. decrement of the record's outstanding count at texture->+0x14->+0x10; at 1 -> 0 it calls
 * IOATIR500Shared::delete_texture), takes the references the discarded stream would have taken, and rebuilds the
 * vertex-format state for opcode 0x29.
 *
 * Mechanically re-ported from the Ghidra decompile (Tools/port_fn.py, atomics via Tools/ghidra2cpp.py's lwarx idiom
 * rewrite) - replaces the earlier interpretive transcription, which used non-atomic stand-ins for the refcount ops and
 * left the delete_texture / set_volatile_state calls as comments. Verified with Tools/callee_compare.py.
 */

#include "../Headers/ATIR500GLContext.h"
#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/IOATIR500Shared.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000PPCIntrinsics.h"
#include "../Headers/GhidraExterns.h"
#include "../Headers/GhidraCompat.h"



/* real addr 0x27580 */
void ATIR500GLContext::discard_command_buffer() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);

  bool bVar1;
  SInt32 iVar2;
  SInt32 *useCount;
  UInt32 opcode;
  UInt32 newTexture;
  UInt32 mode;
  SInt32 *piVar5;
  UInt8 *shared;
  UInt8 *boundTexture;
  SInt32 texture;
  SInt32 previousTexture;
  SInt32 wordOffset;
  SInt32 oldCount;
  SInt32 slotTableOffset;
  UInt32 handle;
  SInt32 iVar11;
  UInt32 packetWords;
  UInt32 uVar13;
  SInt32 slotOffset;
  UInt32 header;
  UInt32 *packet;
  UInt8 *slotCursor;
  char in_RESERVE;
  UInt8 in_cr0;
  UInt8 bVar18;
  SInt32 textures [22];
  SInt32 slot;
  
  packet = (UInt32 *)(M<SInt32>(self + kIOATIR500GLContext_commandBufferHeader) + 0x1c);
  do {
    header = *packet;
    opcode = header & 0xff000000;
    if (opcode == 0x19000000) {
LAB_00027ab0:
      packetWords = header & 0xffffff;
      opcode = opcode + 0xea000000 >> 0x16;
      boundTexture = M<UInt8 *>(self + opcode + 0x2a4);
      if (boundTexture != (UInt8 *)0x0) {
        useCount = (SInt32 *)(M<SInt32>(boundTexture + 0x14) + 0x10);
        oldCount = atomicAddReturningOld((SInt32 *)useCount, -1);
        if (oldCount == 1) {
          ((IOATIR500Shared *)(M<UInt8 *>(self + kIOATIR500GLContext_clientHandle)))->delete_texture((VendorTextureBuffer *)boundTexture);
        }
        packetWords = header & 0xffffff;
        M<UInt32>(self + opcode + 0x2a4) = 0;
      }
    }
    else {
      if (0x19000000 < opcode) {
        if (opcode != 0x23000000) {
          if (opcode < 0x23000001) {
            if (opcode != 0x1e000000) {
              if (opcode < 0x1e000001) {
                if (opcode != 0x1b000000) {
                  if (opcode < 0x1b000001) {
                    if (opcode == 0x1a000000) goto LAB_00027ab0;
                  }
                  else if ((opcode == 0x1c000000) || (opcode == 0x1d000000)) goto LAB_00027ab0;
                  goto LAB_00027e70;
                }
              }
              else if (opcode != 0x20000000) {
                if (opcode < 0x20000001) {
                  if (opcode == 0x1f000000) goto LAB_00027ab0;
                }
                else if ((opcode == 0x21000000) || (opcode == 0x22000000)) goto LAB_00027ab0;
                goto LAB_00027e70;
              }
            }
          }
          else {
            if (opcode == 0x29000000) {
              wordOffset = 0;
              slotOffset = 4;
              M<UInt32>(self + kATIR500GLContext_renderToTexture) = 0;
              slotCursor = self;
              do {
                switch(M<UInt32>((SInt32)packet + wordOffset + 4)) {
                default:
                  M<UInt16>(slotCursor + 0x3aa) = 1;
                  break;
                case 1:
                  M<UInt16>(slotCursor + 0x3aa) = 0;
                  break;
                case 2:
                  M<UInt16>(slotCursor + 0x3aa) = 4;
                  break;
                case 3:
                  M<UInt16>(slotCursor + 0x3aa) = 5;
                  break;
                case 7:
                  M<UInt16>(slotCursor + 0x3aa) = 2;
                  break;
                case 8:
                  M<UInt16>(slotCursor + 0x3aa) = 3;
                  break;
                case 0x10:
                  M<UInt16>(slotCursor + 0x3aa) = 9;
                  break;
                case 0x11:
                  M<UInt16>(slotCursor + 0x3aa) = 0x17;
                }
                slotOffset = slotOffset + -1;
                wordOffset = wordOffset + 4;
                slotCursor = slotCursor + 2;
              } while (slotOffset != 0);
              M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex) = M<UInt16>(self + kATIR500GLContext_attachmentBufferIds);
              M<UInt32>(self + kATIR500GLContext_renderBufferIndex) = (UInt32)M<UInt16>(self + kATIR500GLContext_attachmentBufferIds);
              if (packet[5] == 0x10) {
                M<UInt16>(self + kATIR500GLContext_attachmentBufferIds) = 9;
                M<UInt16>(self + kIOATIR500GLContext_colorBufferIndex) = 9;
              }
              packetWords = header & 0xffffff;
              bVar1 = (M<UInt32>(self + kIOATIR500GLContext_surfaceFlagsBitmask) & 0x80) == 0;
              in_cr0 = bVar1 << 1;
              if (!bVar1) {
                mode = packet[1];
                if ((mode == 7) || (mode == 8)) {
                  packetWords = header & 0xffffff;
                  M<SInt16>(self + kIOATIR500GLContext_depthBufferIndex) = (SInt16)mode;
                }
                else {
                  M<UInt16>(self + kIOATIR500GLContext_depthBufferIndex) = 6;
                }
              }
              goto LAB_00027e90;
            }
            if (0x29000000 < opcode) {
              if (opcode == 0x3a000000) {
                bVar18 = (packet[1] == 0) << 1;
                slotCursor = self;
                do {
                  boundTexture = M<UInt8 *>(slotCursor + 0x2e4);
                  if (boundTexture != (UInt8 *)0x0) {
                    useCount = (SInt32 *)(M<SInt32>(boundTexture + 0x14) + 0x10);
                    oldCount = atomicAddReturningOld((SInt32 *)useCount, -1);
                    if (oldCount == 1) {
                      ((IOATIR500Shared *)(M<UInt8 *>(self + kIOATIR500GLContext_clientHandle)))->delete_texture((VendorTextureBuffer *)boundTexture);
                    }
                    M<UInt32>(slotCursor + 0x2e4) = 0;
                  }
                } while ((!(bool)(bVar18 >> 1 & 1)) &&
                        (slotCursor = slotCursor + 4, slotCursor != self + 0x44));
              }
              else if (opcode < 0x3a000001) {
                if (opcode == 0x36000000) {
                  previousTexture = M<SInt32>(self + kATIR500GLContext_pinnedTexture);
                  newTexture = packet[1];
                  if ((previousTexture != 0) && (M<SInt32>(previousTexture + 0x48) == 0)) {
                    M<SInt16>(previousTexture + 0xe) = M<SInt16>(previousTexture + 0xe) + -1;
                  }
                  if (M<SInt32>(newTexture + 0x48) == 0) {
                    M<SInt16>(newTexture + 0xe) = M<SInt16>(newTexture + 0xe) + 1;
                  }
                  packetWords = header & 0xffffff;
                  M<UInt32>(self + kATIR500GLContext_pinnedTexture) = newTexture;
                  goto LAB_00027e90;
                }
                if (opcode == 0x39000000) {
                  opcode = packet[1];
                  uVar13 = packet[4];
                  if (packet[2] == 0) {
                    opcode = 1;
                  }
                  bVar18 = (packet[3] == 0) << 1;
                  if (packet[3] != 0) {
                    opcode = opcode + 1;
                  }
                  packetWords = header & 0xffffff;
                  if (opcode == 0) goto LAB_00027e90;
                  packetWords = 0;
                  slot = 0x10;
                  slotOffset = 0;
                  useCount = textures;
                  do {
                    if ((!(bool)(bVar18 >> 1 & 1)) && (packetWords == opcode - 1)) {
                      slot = 0x20;
                    }
                    shared = M<UInt8 *>(self + kIOATIR500GLContext_clientHandle);
                    handle = M<UInt32>((SInt32)packet + slotOffset + 0x20);
                    if ((M<UInt32>(shared + 0x14) <= handle) ||
                       (slotTableOffset = M<SInt32>(handle * 4 + M<SInt32>(shared + 0x10)), slotTableOffset == 0))
                    goto LAB_00027e80;
                    *useCount = slotTableOffset;
                    slotTableOffset = slot * 4;
                    boundTexture = M<UInt8 *>(self + slotTableOffset + 0x2a4);
                    if (boundTexture != (UInt8 *)0x0) {
                      piVar5 = (SInt32 *)(M<SInt32>(boundTexture + 0x14) + 0x10);
                      iVar11 = atomicAddReturningOld((SInt32 *)piVar5, -1);
                      if (iVar11 == 1) {
                        ((IOATIR500Shared *)(shared))->delete_texture((VendorTextureBuffer *)boundTexture);
                      }
                      M<UInt32>(self + slotTableOffset + 0x2a4) = 0;
                    }
                    if (((slot == 0x20) &&
                        (iVar11 = M<SInt32>(slotOffset + (SInt32)(unsigned long)textures), M<char>(iVar11 + 0x20) == '\a'
                        )) && (uVar13 != M<UInt32>(iVar11 + 100))) {
                      M<UInt32>(iVar11 + 100) = uVar13;
                      M<UInt8>(M<SInt32>(M<SInt32>(slotOffset + (SInt32)(unsigned long)textures) + 0x14) + 0x14) = 1;
                    }
                    iVar11 = M<SInt32>(slotOffset + (SInt32)(unsigned long)textures);
                    piVar5 = (SInt32 *)(M<SInt32>(iVar11 + 0x14) + 0x10);
                    atomicAddReturningOld((SInt32 *)piVar5, -0xffff);
                    packetWords = packetWords + 1;
                    useCount = useCount + 1;
                    slot = slot + 1;
                    M<SInt32>(self + slotTableOffset + 0x2a4) = iVar11;
                    slotOffset = slotOffset + 4;
                  } while (opcode != packetWords);
                }
              }
              else if (opcode == 0x3b000000) {
                shared = M<UInt8 *>(self + kIOATIR500GLContext_clientHandle);
                opcode = packet[3];
                if ((M<UInt32>(shared + 0x14) <= packet[1]) ||
                   (texture = M<SInt32>(packet[1] * 4 + M<SInt32>(shared + 0x10)), texture == 0))
                goto LAB_00027e80;
                boundTexture = M<UInt8 *>(self + kATIR500GLContext_streamedTexture);
                if (boundTexture != (UInt8 *)0x0) {
                  useCount = (SInt32 *)(M<SInt32>(boundTexture + 0x14) + 0x10);
                  slotOffset = atomicAddReturningOld((SInt32 *)useCount, -1);
                  if (slotOffset == 1) {
                    ((IOATIR500Shared *)(shared))->delete_texture((VendorTextureBuffer *)boundTexture);
                  }
                }
                useCount = (SInt32 *)(M<SInt32>(texture + 0x14) + 0x10);
                atomicAddReturningOld((SInt32 *)useCount, -0xffff);
                M<SInt32>(self + kATIR500GLContext_streamedTexture) = texture;
                useCount = (SInt32 *)0x0;
                if (M<SInt32>(texture + 0x54) != 0) {
                  useCount = M<SInt32 *>(M<SInt32>(texture + 0x54) + 8);
                  useCount = (SInt32 *)VCALL(*useCount, 0x14c)(useCount,GH_kernel_task,0,1,0,0);
                  in_cr0 = (useCount == (SInt32 *)0x0) << 1;
                  if (useCount != (SInt32 *)0x0) {
                    texture = VCALL(*useCount, 0xd0)(useCount);
                    texture = opcode * 0x20 + texture;
                    M<UInt32>(texture + 0x21c) = 0;
                    M<UInt32>(texture + 0x210) = 0;
                    M<UInt32>(texture + 0x220) = 0;
                    M<UInt32>(texture + 0x218) = 0;
                  }
                }
                VCALL(*useCount, 0x18)(useCount);
              }
              else if (opcode == 0x3d000000) {
                packetWords = header & 0xffffff;
                if (packet[1] == 0x132) {
                  if (M<UInt8 *>(self + kIOATIR500GLContext_boundSurface) != (UInt8 *)0x0) {
                    ((IOATIR500Surface *)(M<UInt8 *>(self + kIOATIR500GLContext_boundSurface)))->set_volatile_state((eSurfaceVolatileState)packet[2]);
                    goto LAB_00027e70;
                  }
                }
                goto LAB_00027e90;
              }
              goto LAB_00027e70;
            }
            if (opcode != 0x25000000) {
              if (0x25000000 < opcode) {
                if (opcode == 0x26000000) {
                  if ((M<UInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x14) <= packet[1]) ||
                     (texture = M<SInt32>(packet[1] * 4 + M<SInt32>(M<SInt32>(self + kIOATIR500GLContext_clientHandle) + 0x10)),
                     texture == 0)) goto LAB_00027e80;
                  packetWords = header & 0xffffff;
                  M<SInt32>(self + kATIR500GLContext_transferBufferSlot) = texture;
                }
                else {
                  if (opcode != 0x27000000) goto LAB_00027e70;
                  packetWords = header & 0xffffff;
                  M<UInt32>(self + kATIR500GLContext_transferBufferSlot) = 0;
                }
                goto LAB_00027e90;
              }
              if (opcode != 0x24000000) goto LAB_00027e70;
            }
          }
        }
        goto LAB_00027ab0;
      }
      if (opcode != 0xf000000) {
        if (opcode < 0xf000001) {
          if (opcode != 0xa000000) {
            if (opcode < 0xa000001) {
              if (opcode != 0x7000000) {
                if (opcode < 0x7000001) {
                  if (opcode != 0x6000000) {
LAB_00027e70:
                    packetWords = header & 0xffffff;
                    goto LAB_00027e90;
                  }
                }
                else if ((opcode != 0x8000000) && (opcode != 0x9000000)) goto LAB_00027e70;
              }
            }
            else if (opcode != 0xc000000) {
              if (opcode < 0xc000001) {
                if (opcode != 0xb000000) goto LAB_00027e70;
              }
              else if ((opcode != 0xd000000) && (opcode != 0xe000000)) goto LAB_00027e70;
            }
          }
        }
        else if (opcode != 0x14000000) {
          if (0x14000000 < opcode) {
            if (opcode == 0x16000000) goto LAB_00027ab0;
            if (opcode < 0x16000001) {
              if (opcode == 0x15000000) goto LAB_00027a00;
            }
            else if ((opcode == 0x17000000) || (opcode == 0x18000000)) goto LAB_00027ab0;
            goto LAB_00027e70;
          }
          if (opcode != 0x11000000) {
            if (opcode < 0x11000001) {
              if (opcode != 0x10000000) goto LAB_00027e70;
            }
            else if ((opcode != 0x12000000) && (opcode != 0x13000000)) goto LAB_00027e70;
          }
        }
      }
LAB_00027a00:
      shared = M<UInt8 *>(self + kIOATIR500GLContext_clientHandle);
      if ((packet[1] < M<UInt32>(shared + 0x14)) &&
         (texture = M<SInt32>(packet[1] * 4 + M<SInt32>(shared + 0x10)), texture != 0)) {
        slotOffset = (opcode + 0xfa000000 >> 0x18) * 4;
        boundTexture = M<UInt8 *>(self + slotOffset + 0x2a4);
        if (boundTexture != (UInt8 *)0x0) {
          useCount = (SInt32 *)(M<SInt32>(boundTexture + 0x14) + 0x10);
          slotTableOffset = atomicAddReturningOld((SInt32 *)useCount, -1);
          if (slotTableOffset == 1) {
            ((IOATIR500Shared *)(shared))->delete_texture((VendorTextureBuffer *)boundTexture);
          }
        }
        useCount = (SInt32 *)(M<SInt32>(texture + 0x14) + 0x10);
        atomicAddReturningOld((SInt32 *)useCount, -0xffff);
        packetWords = header & 0xffffff;
        M<SInt32>(self + slotOffset + 0x2a4) = texture;
      }
      else {
LAB_00027e80:
        packetWords = 0;
      }
    }
LAB_00027e90:
    packet = packet + packetWords;
    if (packetWords == 0) {
      return;
    }
  } while( true );
}
