/*
 * ATIR500Surface_ShapeSurface.cpp
 *
 * RESOLVED (issue #22): `ATIR500Surface::shape_surface`'s real body -
 * subclass-only, real addr `0x3c130`. The single largest function this
 * project has ever decompiled (~650 lines of raw decompile) - the last
 * remaining item from this issue's own original 12-slot enumeration.
 *
 * Real purpose: recomputes and (re)allocates the per-format-code
 * `ATIR500SurfaceBuffer` records this surface owns, whenever the
 * surface's own top-level format/mode bits (`this+0xbe8`) or dimensions
 * (`this+0xbd4`/`this+0xbd6`) change - the real "surface was reshaped,
 * make every dependent buffer record agree with the new shape" pass.
 * Every one of this class's own per-slot buffer records lives at
 * `this + slotIndex*0x78 + 0xa8`, cast as `ATIR500SurfaceBuffer*`
 * (matching `alloc_surface_buffer`'s own already-established addressing
 * - issue #22 - and `dealloc_surface`'s own per-index teardown,
 * `ATIR500Surface_VRAM.cpp`) - EXCEPT slot 9, which lives at the fixed
 * offset `this+0x4e0` instead of following the `*0x78` stride (this
 * function special-cases index 9 accordingly throughout).
 *
 * Real structure, four consecutive passes over different slot groups:
 *
 *   1. HyperZ depth/stencil slots (6/7/8) - gated on `this+0xc18`'s own
 *      `0x1c0` bits. Picks a real depth/stencil format-table index
 *      (`0x29` or `0x10`, `DAT_0004d2dc`-driven) and per-slot compression
 *      sample-count multipliers, computes each slot's real byte size,
 *      and reshapes (tears down + calls the real `dealloc_surface(idx)`
 *      teardown, `+0x5cc` on this class's own vtable - CONFIRMED here to
 *      be `dealloc_surface`, resolving the "unidentified `+0x5cc` slot"
 *      an earlier pass on this same issue flagged as unknown) whichever
 *      slots actually changed size.
 *   2. Slot 9 (the fixed color/depth buffer at `this+0x4e0`) - gated on
 *      `this+0xc18 & 0x200`. Same real reshape pattern, using the MAIN
 *      window format (`window_mode_to_ati_format`) instead of the
 *      depth/stencil-specific lookup above.
 *   3. The general color-format slots (a real, mode-dependent index set:
 *      `{0,1,5,4,2,3}` in the normal case, or just `{0,1}` when a real
 *      custom-window-rect mode is active, `this+0x90 != 0`) - computes a
 *      real mip-pyramid byte-size accumulator (14 real per-level partial
 *      sums, `local_90`) via either a trivial swap-buffer-record copy, a
 *      simple pitch*height product, or (the real tiled/`0x70000000` bit
 *      set case) an actual per-mip-level tile-alignment loop - and
 *      reshapes each slot the same way as passes 1/2.
 *   4. Real deinterlace/subpicture-plane slots (10-22, `this+0xc18`'s
 *      own `0x7ffc00` bits, only reached when `this+0x90 != 0`) -
 *      geometry driven by the real custom window rect
 *      (`this+0x94`/`0x96`/`0x98`/`0x9a`) rather than the surface's own
 *      width/height, with three real per-plane-type special config
 *      writes (indices `0x10`/`0x11`/`0x12`) whose own semantics are
 *      UNKNOWN beyond "written when that specific plane is reshaped".
 *
 * Finally, a real overlay-handle allocate-once-if-needed
 * (`alloc_overlay`) and a real per-framebuffer content-sanity check
 * (`getFramebufferIndex`, `this+0xd60`-based array) gate a real
 * `setup_overlay()` call.
 *
 * Two real, previously-undocumented `ATIR500SurfaceBuffer` fields found
 * and named this pass (now in `Headers/ATIRadeonX1000Types.h`):
 * `backingStoreHandle` (+0x24, the real "does this slot already have an
 * allocated backing" gate every reshape site checks before calling
 * `free_buffer_backing_store`) and `formatSubShift` (+0x3b, a real
 * per-format sub-field written alongside `formatTableIndex`, never read
 * back anywhere this project has decompiled so far). The real vtable
 * slot `+0x5cc` is now CONFIRMED `dealloc_surface` (already declared,
 * `Headers/IOATIR500Surface.h`) rather than a separate unidentified
 * "notify resize" method, as an earlier progress pass on this issue had
 * it - resolved by simply cross-checking the slot number against this
 * project's own already-committed vtable-slot table instead of treating
 * it as new.
 *
 * Real gaps left explicitly flagged, not resolved this pass (per this
 * project's own confidence tiers - narrowed as far as static analysis
 * from THIS function alone allows, not guessed):
 *   - `window_mode_to_ati_format`, `getFramebufferIndex`, `alloc_overlay`,
 *     `setup_overlay`, `copy_buffer_to_backing_store` - real names
 *     (Ghidra's own resolved symbols, not `FUN_` addresses), but none of
 *     their own bodies were decompiled this pass; declared with their
 *     real call-site signatures only.
 *   - `setup_overlay()` is real-called with NO arguments at all in the
 *     raw decompile - transcribed literally; this may be a genuine
 *     zero-argument real function, or a decompiler artifact hiding an
 *     implicit argument this project can't recover without decompiling
 *     the function itself.
 *   - The real per-framebuffer array at `this+0xd60` (`this+0xd50`'s
 *     accelerator field sits immediately before it) and the real record
 *     it points to (`+0x0`/`+0x4`/`+0x12` sanity-checked before
 *     `setup_overlay()`) - real shape/roles UNKNOWN, transcribed as
 *     literal raw offsets.
 *   - The real compiled-in constant table `C_146` (copied via a real,
 *     not-independently-decompiled `0x38`-byte memcpy-style helper,
 *     `FUN_0003cf24` - same opaque-helper category as this project's
 *     existing `FUN_000314c4`/`FUN_00044868` blit-template-copy family,
 *     issue #15's own catalog, at a different real address) - real
 *     content/field meaning UNKNOWN, used opaquely as "the default
 *     14-entry mip-offset table" per its own real call-site role.
 *   - The apparent real field-reuse tension between this function's own
 *     `this+0x94`/`0x96`/`0x98`/`0x9a` reads (used here as if they were
 *     two opposite rect corners, `w-x`/`y-h`) and
 *     `ATIR500Surface::dvd_setup_overlay`'s own real writes to the SAME
 *     four offsets (`ATIR500Surface_Overlay.cpp`, x/h/y/w individually)
 *     - both are real, independently decompiled, but this project did
 *     NOT reconcile whether they're genuinely the same logical rect
 *     under two different real access patterns or two coincidentally
 *     co-located records; transcribed literally, flagged rather than
 *     guessed.
 *
 * Confidence: CONFIRMED for control flow and every field offset/literal
 * constant that maps onto an already-established real field
 * (`accelerator`, `gateBits`/`this+0xc18`, `formatBits`/`this+0xbe8`,
 * `this+0xc14`, `this+0xbd4`/`0xbd6`, `this+0xdac`, `ATIR500SurfaceBuffer`'s
 * own named fields, `FormatTableLookup_0x0004d2dc`) - all independently
 * cross-checked against their own already-committed real usage
 * elsewhere in this project before being reused here, per this
 * project's own "cross-check a fresh decompile against committed code"
 * discipline. Real per-mip tile-alignment arithmetic (pass 3's tiled
 * branch) and the three real per-plane-type special config writes
 * (pass 4) are transcribed as literal raw arithmetic/offsets - real
 * behavior, INFERRED-level confidence on exact semantic naming. No C++
 * compiler was available in the sandboxed environment this was written
 * in (same standing limitation as every other file in this project) -
 * checked by careful, repeated manual re-reading against the raw
 * decompile instead.
 *
 * Real, previously-unnoted finding confirmed via that re-reading: pass
 * 3's own `swizzleMode` selector is the SAME Ghidra-tracked
 * variable/register as the earlier per-panel `overlayFormatSel` pick -
 * the real swizzle-mode-computing code sits ONLY inside pass 3's own
 * tiled branch (confirmed from this function's own brace structure),
 * so the two untiled branches genuinely reshape their slots using
 * whatever `overlayFormatSel` value the earlier, logically-unrelated
 * panel-format selection happened to leave behind - a real cross-
 * purpose field reuse, not a transcription simplification.
 *
 * Several real self-caught bugs were found and fixed during this
 * function's own line-by-line re-verification before commit (this
 * project's own standard discipline, not a one-off): every one of this
 * class's per-slot records is addressed as `this+slotIndex*0x78+0xa8`
 * throughout passes 1-3, but pass 4 walks a SEPARATE real pointer
 * (`pAVar15`, starting at `this` itself, not `this+10*0x78+0xa8`) -
 * an initial draft of pass 4 wrongly reused pass 1-3's own `+0xNN`
 * literal offsets verbatim against pass 4's differently-based record
 * pointer, corrupting every single field pass 4 touches; corrected by
 * re-deriving each real offset via `pAVar15 = rec - 0x558`. A second,
 * separate round of the same mistake affected several of pass 1/3's OWN
 * secondary fields (`+0xb8`/`+0xc0`/`+0xe4`/`+0xca`/`200`/`+0xe8`) that
 * were transcribed as literal `rec+<raw literal>` without first
 * subtracting the record's own `+0xa8` base, double-counting it.
 */

#include "../Headers/ATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIRadeonX1000Registers.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline SInt16 &S16At(void *base, int offset) { return *reinterpret_cast<SInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8  &U8At(void *base, int offset)  { return *(reinterpret_cast<UInt8 *>(base) + offset); }

/* Real per-mip/per-plane pitch rounding this function applies repeatedly:
 * round `value` up to the next multiple of `align` (align is always a
 * real power of two, 0x20 or 0x100, in every real call site). */
inline UInt32 RoundUpPitch(UInt32 value, UInt32 align) {
    if ((value & (align - 1)) != 0) {
        value = (value & ~(align - 1)) + align;
    }
    return value;
}

/* Real per-mip height rounding, always to a 0x20 boundary, but real
 * arithmetic on a SIGNED short in the raw decompile (matters for the
 * rare real negative-height case) - transcribed with the exact same
 * signed rounding-toward-zero shift the raw decompile performs, not
 * simplified to unsigned rounding. Real base value is SIGN-extended
 * (`(uint)*(short*)...` in the raw decompile sign-extends short->int
 * before the uint reinterpret - NOT a zero-extend of the 16-bit
 * pattern), which only matters for this same real negative-height
 * edge case. */
inline UInt32 RoundUpHeight32(SInt16 heightVal) {
    UInt32 h = static_cast<UInt32>(static_cast<SInt32>(heightVal));
    if ((h & 0x1f) != 0) {
        SInt32 hSigned = static_cast<SInt32>(h);
        SInt16 shiftSum = static_cast<SInt16>((hSigned >> 5) + ((hSigned < 0) ? 1 : 0));
        SInt16 adjusted = static_cast<SInt16>(heightVal + static_cast<SInt16>(shiftSum * -0x20));
        h = (h - static_cast<UInt32>(static_cast<SInt32>(adjusted))) + 0x20;
    }
    return h;
}
} // namespace

/* real name/role UNKNOWN beyond call-site usage - own body not decompiled this pass */
extern "C" UInt32 window_mode_to_ati_format(UInt32 windowModeBits);
extern "C" UInt32 getFramebufferIndex(IOATIR500Surface *surface);
extern "C" UInt32 alloc_overlay(IOATIR500Surface *surface);
extern "C" void   setup_overlay();
/* real, not independently decompiled - same opaque-helper category as issue #15's own FUN_000314c4/FUN_00044868 blit-template-copy family, at a different real address */
extern "C" void   FUN_0003cf24(void *dest, const void *constTable, UInt32 byteCount);
extern const UInt32 kShapeSurfaceDefaultMipTable[14]; /* real: shape_surface()::C_146, real content not extracted this pass */

void ATIR500Surface::shape_surface() {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *accel = reinterpret_cast<UInt8 *>(accelerator);

    U32At(accel, 0xb94) = 1; /* real "swap chain active" flag, ATIR500Surface_VRAM.cpp's own established field */

    UInt32 formatBits = U32At(self, 0xbe8);
    UInt32 gateBits;
    if ((formatBits & 0x70000000) == 0) {
        gateBits = U32At(self, 0xc18);
    } else {
        formatBits &= 0xff83ffffu;
        U32At(self, 0xbe8) = formatBits;
        gateBits = U32At(self, 0xc18) & 0xfffffdffu;
        U32At(self, 0xc18) = gateBits;
    }

    /* Real compressed-texture sample-count multipliers, chosen from
     * formatBits' own compression-family bits (0x7c0000). */
    SInt32 sampleCountX, sampleCountY;
    {
        if ((formatBits & 0x7c0000) == 0) {
            sampleCountX = 1;
            sampleCountY = 1;
        } else {
            UInt32 fam = formatBits & 0x700000;
            if (fam == 0) {
                UInt32 sub = formatBits & 0xc0000;
                if (sub == 0) {
                    sampleCountX = 1;
                    sampleCountY = 1;
                } else if (sub == 0x40000) {
                    sampleCountX = 1;
                    sampleCountY = 2;
                } else if (sub == 0x80000) {
                    sampleCountX = 2;
                    sampleCountY = 2;
                } else {
                    sampleCountX = 1;
                    sampleCountY = 1;
                }
                if (sub != 0) {
                    if (0x1000 < static_cast<UInt32>(sampleCountX * S16At(self, 0xbd4))) sampleCountX = 1;
                    if (0x1000 < static_cast<UInt32>(sampleCountY * S16At(self, 0xbd6))) sampleCountY = 1;
                }
            } else if (fam == 0x200000) {
                sampleCountX = 4;
                sampleCountY = 1;
            } else if (fam == 0x400000) {
                sampleCountX = 6;
                sampleCountY = 1;
            } else if (fam == 0x100000) {
                sampleCountX = 2;
                sampleCountY = 1;
            } else {
                sampleCountX = 1;
                sampleCountY = 1;
            }
        }
    }

    /* ===== Pass 1: HyperZ depth/stencil slots 6/7/8 ===== */
    if ((gateBits & 0x1c0) != 0) {
        UInt32 dsFormatIndex, dsBlockClass;
        if (((formatBits & 0x30000) == 0x20000) || ((formatBits & 0x30000) == 0x30000)) {
            dsFormatIndex = 0x29;
            dsBlockClass = 3;
        } else {
            dsFormatIndex = 0x10;
            dsBlockClass = 5;
        }
        UInt32 dsFormatEntry = FormatTableLookup_0x0004d2dc(dsFormatIndex * 0x1c);
        UInt32 dsBlockShift = 1u << ((dsFormatEntry >> 0xc) & 7);
        if (S16At(self, 0xbd6) < 0x20) {
            dsBlockClass = (dsBlockClass == 5) ? 4 : 2;
        }

        static const UInt8 kHyperZSlots[3] = {6, 7, 8};
        for (int i = 0; i < 3; ++i) {
            UInt32 slot = kHyperZSlots[i];
            if (((gateBits >> (slot & 0x3f)) & 1) == 0) continue;

            UInt32 sy = (slot == 6) ? sampleCountY : 1;
            UInt32 sx = (slot == 6) ? sampleCountX : 1;
            SInt32 baseW = S16At(self, 0xbd4);
            SInt32 wForPitch = baseW;
            if ((formatBits & 0x700000) != 0 && slot == 6) {
                wForPitch = baseW + 0x18;
            }
            UInt32 rowBytes = RoundUpPitch(static_cast<UInt32>(wForPitch) * dsBlockShift, 0x100);
            rowBytes = sx * rowBytes;
            UInt32 rowsAligned = RoundUpHeight32(S16At(self, 0xbd6));
            UInt32 totalBytes = sy * rowsAligned * rowBytes;

            UInt8 *rec = self + slot * 0x78 + 0xa8;
            ATIR500SurfaceBuffer *buf = reinterpret_cast<ATIR500SurfaceBuffer *>(rec);
            if (buf->bytesPerRow != dsBlockShift ||
                buf->heightOrRows != sx * static_cast<UInt16>(baseW) ||
                buf->extra1e != sy * static_cast<UInt16>(*reinterpret_cast<SInt16 *>(self + 0xbd6))) {
                if (buf->backingStoreHandle != 0) {
                    free_buffer_backing_store(buf);
                }
                if (static_cast<SInt32>(totalBytes) != *reinterpret_cast<SInt32 *>(rec + 0x10)) {
                    dealloc_surface(slot);
                    *reinterpret_cast<SInt32 *>(rec + 0x10) = static_cast<SInt32>(totalBytes);
                }
                buf->width = (dsBlockShift == 0) ? 0 : static_cast<UInt16>(rowBytes / dsBlockShift);
                *reinterpret_cast<UInt16 *>(rec + 0x18) = static_cast<UInt16>(rowBytes);
                buf->bytesPerRow = static_cast<UInt16>(dsBlockShift);
                buf->heightOrRows = static_cast<UInt16>(sx * baseW);
                buf->extra1e = static_cast<UInt16>(sy * S16At(self, 0xbd6));
            }
            buf->formatTableIndex = static_cast<UInt8>(dsFormatIndex);
            buf->tilingConfigByte1 = static_cast<UInt8>((dsFormatEntry >> 10) & 3);
            buf->formatSubShift = static_cast<UInt8>((dsFormatEntry >> 3) & 0x1f);
            buf->tilingConfigByte0 = static_cast<UInt8>(dsBlockClass);

            /* real: this+iVar27+0xe4 -> rec+0x3c, i.e. this class's own already-named
             * `tilingDegreeBits` field - this pass ORs in bits (0x800, and others below
             * 0x100000) outside the `0xf00000`/`(>>0x14)&0xf` sub-range this project's
             * struct comment currently documents for that field, extending (not
             * contradicting) its real known usage. */
            UInt32 &packedCfg = buf->tilingDegreeBits;
            if ((U32At(self, 0xbe8) & 0x700000) == 0) {
                if ((U32At(self, 0xbe8) & 0xc0000) == 0) {
                    packedCfg = (packedCfg & 0xff000fffu) | 0x111000u;
                } else {
                    packedCfg = ((sx & 0xfu) << 0xc) | (sy << 0x10) | (packedCfg & 0xff000fffu) | 0x100000u;
                }
            } else {
                packedCfg = (sy << 0x14) | (packedCfg & 0xff000fffu) | 0x11000u;
            }
            packedCfg |= 0x800u;

            formatBits = U32At(self, 0xbe8);
            gateBits = U32At(self, 0xc18);
        }
    }

    /* ===== Real overlay-format-slot selection for this+0xc14's panel, if applicable ===== */
    UInt8 overlayFormatSel;
    if ((formatBits & 0xf) < 0xe) {
        UInt32 bit = 1u << (formatBits & 0xf);
        if ((bit & 0x1c18) == 0) {
            if ((bit & 0x2000) == 0) {
                overlayFormatSel = 0;
                goto haveOverlayFormatSel;
            }
            if (S16At(self, 0xbd6) < 0x10) {
                overlayFormatSel = 1;
                goto haveOverlayFormatSel;
            }
            overlayFormatSel = 0;
        } else {
            overlayFormatSel = static_cast<UInt8>((0xf < S16At(self, 0xbd6)) + 2);
        }
    } else {
        overlayFormatSel = 0;
    }
haveOverlayFormatSel:
    if (*reinterpret_cast<SInt32 *>(self + 0xc14) != 0xffff && (gateBits & 2) != 0) {
        *reinterpret_cast<UInt8 *>(*reinterpret_cast<SInt32 *>(self + 0xc14) * 0x78 + *reinterpret_cast<SInt32 *>(self + 0xd50) + 0x164) = overlayFormatSel;
        gateBits = U32At(self, 0xc18);
    }

    /* ===== Real "does anything actually need reshaping" gate ===== */
    UInt32 reshapeGate = (*reinterpret_cast<SInt32 *>(self + 0x90) == 0) ? (gateBits & 0x23fu) : (gateBits & 0x7ffc03u);
    if (reshapeGate == 0) {
        return;
    }

    UInt32 mainFormatIdx = window_mode_to_ati_format(U32At(self, 0xbe8) & 0xf);
    UInt32 mainFormatEntry = FormatTableLookup_0x0004d2dc(mainFormatIdx * 0x1c);
    UInt8 mainTileClass = static_cast<UInt8>((mainFormatEntry >> 10) & 3);
    UInt8 mainSubShift = static_cast<UInt8>((mainFormatEntry >> 3) & 0x1f);
    UInt32 mainBlockShift = 1u << ((mainFormatEntry >> 0xc) & 7);

    /* ===== Pass 2: fixed slot 9 (this+0x4e0) ===== */
    if ((gateBits & 0x200) != 0) {
        UInt8 *rec9 = self + 0x4e0;
        ATIR500SurfaceBuffer *buf9 = reinterpret_cast<ATIR500SurfaceBuffer *>(rec9);
        if (buf9->bytesPerRow != mainBlockShift ||
            buf9->heightOrRows != static_cast<UInt16>(sampleCountX * S16At(self, 0xbd4)) ||
            buf9->extra1e != static_cast<UInt16>(sampleCountY * S16At(self, 0xbd6))) {
            if (buf9->backingStoreHandle != 0) {
                free_buffer_backing_store(buf9);
            }
            SInt32 wBase = S16At(self, 0xbd4);
            SInt32 wForPitch = wBase;
            if ((U32At(self, 0xbe8) & 0x700000) != 0) {
                wForPitch = wBase + 0x18;
            }
            UInt32 rowBytes9 = RoundUpPitch(static_cast<UInt32>(wForPitch) * mainBlockShift, 0x100);
            rowBytes9 = static_cast<UInt32>(sampleCountX) * rowBytes9;
            UInt32 rows9 = RoundUpHeight32(S16At(self, 0xbd6));
            SInt32 total9 = static_cast<SInt32>(rowBytes9 * static_cast<UInt32>(sampleCountY) * rows9);
            if (total9 != *reinterpret_cast<SInt32 *>(rec9 + 0x10)) {
                dealloc_surface(9);
                *reinterpret_cast<SInt32 *>(rec9 + 0x10) = total9;
            }
            buf9->width = (mainBlockShift == 0) ? 0 : static_cast<UInt16>(rowBytes9 / mainBlockShift);
            *reinterpret_cast<UInt16 *>(rec9 + 0x18) = static_cast<UInt16>(rowBytes9);
            buf9->bytesPerRow = static_cast<UInt16>(mainBlockShift);
            buf9->heightOrRows = static_cast<UInt16>(sampleCountX * S16At(self, 0xbd4));
            buf9->extra1e = static_cast<UInt16>(sampleCountY * S16At(self, 0xbd6));
        }
        this[0x518] = static_cast<ATIR500Surface>(overlayFormatSel);
        this[0x519] = static_cast<ATIR500Surface>(mainTileClass);
        this[0x51b] = static_cast<ATIR500Surface>(mainSubShift);
        this[0x51a] = static_cast<ATIR500Surface>(static_cast<UInt8>(mainFormatIdx));
        UInt32 &packedCfg9 = buf9->tilingDegreeBits; /* real: this+0x51c == rec9+0x3c */
        if ((U32At(self, 0xbe8) & 0x700000) == 0) {
            if ((U32At(self, 0xbe8) & 0xc0000) == 0) {
                packedCfg9 = (packedCfg9 & 0xff000fffu) | 0x111000u;
            } else {
                packedCfg9 = ((static_cast<UInt32>(sampleCountY) & 0xfu) << 0xc) |
                             (static_cast<UInt32>(sampleCountX) << 0x10) | (packedCfg9 & 0xff000fffu) | 0x100000u;
            }
        } else {
            packedCfg9 = (static_cast<UInt32>(sampleCountX) << 0x14) | (packedCfg9 & 0xff000fffu) | 0x11000u;
        }
    }

    /* Real default mip-offset table copy - real signature/target
     * INFERRED (`FUN_0003cf24(local_90, &C_146, 0x38)` in the raw
     * decompile passes the STACK ARRAY `local_90` directly, not a
     * pointer variable - modeled here as a plain array-fill call). */
    SInt32 localMipOffsets[14];
    FUN_0003cf24(localMipOffsets, kShapeSurfaceDefaultMipTable, 0x38);

    /* ===== Pass 3 setup: real mip-pyramid total size + swizzle-mode pick =====
     * Real note: `swizzleMode` starts as `overlayFormatSel` (the SAME
     * Ghidra-tracked variable/register the earlier overlay-format-slot
     * selection above computed) and is only ever REASSIGNED inside the
     * real tiled branch below - branches 1/2 genuinely reuse whatever
     * `overlayFormatSel` already held, a real, previously-unnoted
     * cross-purpose field reuse confirmed by this function's own brace
     * structure (the swizzle-pick block sits ONLY inside the tiled
     * branch's own closing brace, not shared by all three). */
    UInt32 mipLevelCount = 0; /* real: uVar26 */
    UInt32 totalBytes3;       /* real: iVar9 at the end of this block */
    UInt32 depthSlices3 = 1;  /* real: uVar8 at the end */
    UInt32 sliceMul = 1;      /* real: uVar7 at the end */
    UInt32 rowByteBase;       /* real: uVar24 - the row-byte value later divided by mainBlockShift for the slot's own `width` field */
    UInt8 swizzleMode = overlayFormatSel;

    UInt32 shapeBits = U32At(self, 0xbe8);
    if ((shapeBits & 0x20) == 0) {
        /* Real "reuse an existing per-panel swap-buffer record's own
         * size" branch - accelerator-owned per-panel record,
         * `accel + panelId*0x78`, matching `resetFullScreen`'s own
         * established per-panel array (`ATIR500Surface_ResetFullScreen.cpp`,
         * without that function's own `+300` offset). */
        UInt8 *panelRec = accel + *reinterpret_cast<SInt32 *>(self + 0xc14) * 0x78;
        totalBytes3 = U32At(panelRec, 0x13c);
        rowByteBase = U16At(panelRec, 0x144);
    } else if ((shapeBits & 0x70000000) == 0) {
        /* Real trivial single-level pitch*height product. */
        rowByteBase = RoundUpPitch(mainBlockShift * static_cast<UInt32>(S16At(self, 0xbd4)), 0x100);
        UInt32 rows = RoundUpHeight32(S16At(self, 0xbd6));
        totalBytes3 = rowByteBase * rows;
    } else {
        /* Real per-mip-level tile-alignment accumulation loop. */
        UInt32 w = static_cast<UInt32>(S16At(self, 0xbd4));
        rowByteBase = mainBlockShift * w; /* real: set once here (uVar24 = uVar8's initial value), never reassigned again in this branch */
        UInt32 rowBytes = rowByteBase;
        UInt32 h = static_cast<UInt32>(S16At(self, 0xbd6));
        SInt16 heightSigned = S16At(self, 0xbd6);
        mipLevelCount = (shapeBits >> 0x18) & 0xf;
        SInt32 accum = 0;
        UInt32 lvl = 0;
        UInt32 hCur = h;
        while (true) {
            bool notFirst = (lvl != 0);
            localMipOffsets[lvl] = accum;
            UInt32 align = notFirst ? 0x20 : 0x100;
            rowBytes = RoundUpPitch(rowBytes, align);
            UInt32 hAligned = hCur;
            if (!notFirst && (hCur & 0x1f) != 0) {
                hAligned = (hCur & ~0x1fu) + 0x20;
            }
            accum += static_cast<SInt32>(rowBytes * hAligned);
            if (1 < w) w >>= 1;
            if (1 < hCur) hCur >>= 1;
            lvl += 1;
            if (mipLevelCount < lvl) break;
            rowBytes = mainBlockShift * w;
        }
        localMipOffsets[lvl] = accum;
        depthSlices3 = mipLevelCount + 1;
        sliceMul = ((shapeBits & 0x70000000) == 0x30000000) ? 6u : 1u;
        totalBytes3 = static_cast<UInt32>(accum) * sliceMul;

        /* Real swizzle-mode pick - transcribed with literal `goto`s
         * matching the raw decompile's own shared-tail labels
         * (`LAB_0003c9c4`/`LAB_0003c9d0`) exactly, rather than
         * restructured, since the two shared tails are reached from
         * multiple real, non-nested real conditions and this project's
         * own methodology prefers a literal transcription over a
         * restructuring that risks silently changing which real path a
         * given input takes. */
        if (mainBlockShift == 0x10) {
            if (depthSlices3 == 1) {
                if (sliceMul == 1) {
                    if (static_cast<SInt32>(heightSigned) < 0x10) {
                        swizzleMode = 0;
                        sliceMul = 1;
                    } else {
                        swizzleMode = 1;
                        sliceMul = 1;
                        depthSlices3 = 1;
                    }
                } else {
                    goto shapeSurface_labC9c4;
                }
            } else {
                goto shapeSurface_labC9d0;
            }
        } else {
            if (depthSlices3 != 1) goto shapeSurface_labC9d0;
            if (sliceMul != 1) goto shapeSurface_labC9c4;
            if (static_cast<SInt32>(heightSigned) < 0x10) {
                swizzleMode = 2;
                sliceMul = 1;
            } else {
                swizzleMode = 3;
                sliceMul = 1;
            }
        }
        goto shapeSurface_swizzleDone;
    shapeSurface_labC9c4:
        swizzleMode = 0;
        depthSlices3 = 1;
        goto shapeSurface_swizzleDone;
    shapeSurface_labC9d0:
        swizzleMode = 0;
    shapeSurface_swizzleDone:;
    }

    /* ===== Pass 3: general color-format slots ===== */
    UInt8 slotList[6];
    UInt32 slotCount;
    slotList[0] = 0;
    slotList[1] = 1;
    if (*reinterpret_cast<SInt32 *>(self + 0x90) == 0) {
        slotCount = 6;
        slotList[2] = 5; slotList[3] = 4; slotList[4] = 2; slotList[5] = 3;
    } else {
        /* Real custom-window-rect mode: reshape only slots 0/1, sized
         * from the real custom rect (`this+0x94`/`0x96`/`0x98`/`0x9a`)
         * rather than the surface's own width/height - which this
         * branch also OVERWRITES (`this+0xbd4`/`0xbd6`) for every
         * later real reader to pick up. */
        SInt32 rectW = static_cast<SInt32>(S16At(self, 0x98)) - static_cast<SInt32>(S16At(self, 0x96));
        SInt32 rectH = static_cast<SInt32>(S16At(self, 0x9a)) - static_cast<SInt32>(S16At(self, 0x94));
        UInt16 customW, customH;
        if (rectW == 0) {
            rectW = 0x300;
            customW = 0x300;
        } else {
            customW = static_cast<UInt16>(rectW);
        }
        UInt32 rectHRounded;
        if (rectH == 0) {
            rectHRounded = 0x240;
            customH = 0x240;
        } else {
            rectHRounded = static_cast<UInt32>(rectH);
            if ((rectHRounded & 0xf) != 0) {
                rectHRounded = (rectHRounded & ~0xfu) + 0x10;
            }
            customH = static_cast<UInt16>(rectH);
        }
        rowByteBase = RoundUpPitch(static_cast<UInt32>(rectW) * mainBlockShift, 0x100);
        totalBytes3 = rowByteBase * rectHRounded;
        U16At(self, 0xbe0) = customW;
        U16At(self, 0xbe2) = customH;
        self[0xbec] = static_cast<ATIR500Surface>(1);
        U16At(self, 0xbd4) = customW;
        U16At(self, 0xbd6) = customH;
        slotCount = 2;
    }

    UInt32 slotGateBits = U32At(self, 0xc18);
    for (UInt32 si = 0; si < slotCount; ++si) {
        UInt32 slot = slotList[si];
        if (((slotGateBits >> (slot & 0x3f)) & 1) == 0) continue;

        UInt8 *rec = self + slot * 0x78 + 0xa8;
        ATIR500SurfaceBuffer *buf = reinterpret_cast<ATIR500SurfaceBuffer *>(rec);
        /* real: this+iVar23+200(0xc8) -> rec+0x20 == basePitch; this+iVar23+0xca -> rec+0x22
         * (no established name - a real per-record "depth slice count" companion to
         * basePitch's own "slice multiplier" role in this specific function). */
        if (buf->bytesPerRow != mainBlockShift ||
            buf->heightOrRows != static_cast<UInt16>(S16At(self, 0xbd4)) ||
            buf->extra1e != static_cast<UInt16>(S16At(self, 0xbd6)) ||
            buf->basePitch != static_cast<UInt16>(sliceMul) ||
            *reinterpret_cast<UInt16 *>(rec + 0x22) != static_cast<UInt16>(depthSlices3)) {
            if (buf->backingStoreHandle != 0) {
                free_buffer_backing_store(buf);
            }
            if (static_cast<SInt32>(totalBytes3) != *reinterpret_cast<SInt32 *>(rec + 0x10)) {
                dealloc_surface(slot);
                *reinterpret_cast<SInt32 *>(rec + 0x10) = static_cast<SInt32>(totalBytes3);
            }
            buf->width = (mainBlockShift == 0) ? 0 : static_cast<UInt16>(rowByteBase / mainBlockShift);
            *reinterpret_cast<UInt16 *>(rec + 0x18) = static_cast<UInt16>(rowByteBase);
            buf->bytesPerRow = static_cast<UInt16>(mainBlockShift);
            /* real: rec+0x1c/heightOrRows and rec+0x1e/extra1e get the surface's own raw
             * width/height copied VERBATIM here (no sample-count multiply, unlike passes 1/2) */
            buf->heightOrRows = static_cast<UInt16>(S16At(self, 0xbd4));
            buf->extra1e = static_cast<UInt16>(S16At(self, 0xbd6));
            *reinterpret_cast<UInt16 *>(rec + 0x22) = static_cast<UInt16>(depthSlices3);
            buf->basePitch = static_cast<UInt16>(sliceMul);
            SInt32 *dst = reinterpret_cast<SInt32 *>(buf->mipOffsets);
            UInt32 copied = 0;
            do {
                copied += 1;
                *dst = localMipOffsets[copied - 1];
                dst += 1;
            } while (copied <= mipLevelCount + 1);
        }
        buf->formatTableIndex = static_cast<UInt8>(mainFormatIdx);
        buf->tilingConfigByte0 = swizzleMode;
        buf->tilingConfigByte1 = mainTileClass;
        buf->formatSubShift = mainSubShift;
        slotGateBits = U32At(self, 0xc18);
    }

    if ((slotGateBits & 0x7ffc00) == 0) return;
    if (*reinterpret_cast<SInt32 *>(self + 0x90) == 0) return;

    /* ===== Pass 4: deinterlace/subpicture-plane slots 10-22 =====
     * Real geometry source: the SAME `this+0x96`/`0x98`/`0x94`/`0x9a`
     * rect fields pass 3's custom-window branch reads, here combined
     * differently (`top-bottom` for height, `right-left`, tripled, for
     * a real chroma-plane-sized alternate height) - see this file's own
     * header comment for the real field-reuse tension against
     * `dvd_setup_overlay`'s own writes to these same four offsets. */
    SInt16 rectTop = S16At(self, 0x98);
    SInt16 rectBottom = S16At(self, 0x96);
    SInt32 rectSpan4 = static_cast<SInt32>(S16At(self, 0x9a)) - static_cast<SInt32>(S16At(self, 0x94));
    UInt16 rectSpanTimes3 = static_cast<UInt16>(rectSpan4 * 3);
    UInt16 rectSpanTimes3Half = static_cast<UInt16>((rectSpan4 * 3) >> 1);

    /*
     * Real per-record offsets below (`pAVar15+X` in the raw decompile)
     * were re-derived carefully via `pAVar15 = rec - 0x558` (real:
     * `pAVar15` itself walks from `this` in 0x78 steps starting at real
     * slot 10, i.e. it is NOT the same base as `rec` = `this+slot*0x78+0xa8`
     * used everywhere else in this function - `pAVar15` is offset
     * `0x558` EARLIER for slot 10, and stays a constant `0x558` behind
     * `rec` for every subsequent slot since both advance by the same
     * real `0x78` per iteration). Every real `pAVar15+X` offset this
     * loop touches lands exactly on an already-established
     * `ATIR500SurfaceBuffer` field once corrected this way - a real,
     * previously-unverified confirmation that pass 4 uses the SAME
     * per-slot record layout as passes 1-3, not a distinct one. */
    for (UInt32 slot = 10; slot <= 0x16; ++slot) {
        if ((slotGateBits & (1u << (slot & 0x3f))) != 0) {
            UInt8 *rec = self + slot * 0x78 + 0xa8;
            ATIR500SurfaceBuffer *buf = reinterpret_cast<ATIR500SurfaceBuffer *>(rec);
            if (buf->backingStoreHandle != 0) {
                free_buffer_backing_store(buf);
            }
            buf->heightOrRows = static_cast<UInt16>(rectTop - rectBottom); /* real: pAVar15+0x574 -> rec+0x1c */
            UInt16 chosenHeight = rectSpanTimes3Half;
            /* Real: this+0xdac (real deinterlace-mode field, `enable_deint`) gates a real
             * copy-forward of the PREVIOUS backing store's own content before the slot's
             * geometry changes, only for slots 10-14, when the slot already has a real GPU
             * address (`gpuBaseAddress`) AND its own real chroma-plane size (`extra1e`)
             * doesn't already match the newly-tripled span. */
            if (U32At(self, 0xdac) != 0 && slot > 9 && slot < 0xf) {
                chosenHeight = rectSpanTimes3;
                if (buf->gpuBaseAddress != 0 && buf->extra1e != rectSpanTimes3) {
                    copy_buffer_to_backing_store(buf);
                }
            }
            buf->extra1e = chosenHeight; /* real: pAVar15+0x576 -> rec+0x1e */

            if (slot == 0x11) {
                this[0x8da] = static_cast<ATIR500Surface>(0x2e);
            } else if (slot == 0x10) {
                U16At(self, 0x844) = 0x2d0;
                U16At(self, 0x846) = (rectSpan4 == 0x240 || rectSpan4 == 0x120) ? 0x240 : 0x1e0;
                this[0x862] = static_cast<ATIR500Surface>(0xb);
            } else if (slot == 0x12) {
                S16At(self, 0x936) = static_cast<SInt16>(rectSpan4);
                this[0x952] = static_cast<ATIR500Surface>(0xb);
            } else {
                buf->formatTableIndex = 0x2d; /* real: pAVar15[0x592] -> rec+0x3a */
            }

            UInt16 rHeight = buf->heightOrRows;
            UInt32 fmtIdx2 = buf->formatTableIndex;
            UInt32 fmtEntry2 = FormatTableLookup_0x0004d2dc(fmtIdx2 * 0x1c);
            buf->formatSubShift = static_cast<UInt8>((fmtEntry2 >> 3) & 0x1f); /* real: pAVar15[0x593] -> rec+0x3b */
            UInt32 blockShift2 = 1u << ((fmtEntry2 >> 0xc) & 7);
            buf->bytesPerRow = static_cast<UInt16>(blockShift2); /* real: pAVar15+0x56e -> rec+0x16 */
            buf->tilingConfigByte1 = static_cast<UInt8>((fmtEntry2 >> 10) & 3); /* real: pAVar15[0x591] -> rec+0x39 */
            UInt32 rowBytes2 = RoundUpPitch(rHeight, 0x100);
            UInt32 blockShift2Masked = blockShift2 & 0xffffu;
            *reinterpret_cast<UInt16 *>(rec + 0x18) = static_cast<UInt16>(rowBytes2 * blockShift2Masked); /* real: pAVar15+0x570 -> rec+0x18 */
            if (blockShift2Masked == 0) {
                buf->width = static_cast<UInt16>(blockShift2); /* real: pAVar15+0x56c -> rec+0x14 */
            } else {
                buf->width = static_cast<UInt16>((rowBytes2 * blockShift2Masked & 0xffffu) / blockShift2Masked);
            }

            if (slot == 0x12) {
                this[0x950] = static_cast<ATIR500Surface>(swizzleMode);
            } else {
                buf->tilingConfigByte0 = 0; /* real: pAVar15[0x590] -> rec+0x38 */
            }

            UInt16 sizeW = *reinterpret_cast<UInt16 *>(rec + 0x18);
            UInt16 sizeH = buf->extra1e;
            if (static_cast<UInt32>(sizeW) * static_cast<UInt32>(sizeH) != *reinterpret_cast<UInt32 *>(rec + 0x10)) {
                dealloc_surface(slot);
                *reinterpret_cast<UInt32 *>(rec + 0x10) = static_cast<UInt32>(sizeW) * static_cast<UInt32>(sizeH);
            }
        }
        slotGateBits = U32At(self, 0xc18);
    }

    if (U32At(self, 0xda4) != 0) {
        if (this[0xbf0] == static_cast<ATIR500Surface>(0)) {
            this[0xbf0] = static_cast<ATIR500Surface>(alloc_overlay(this));
        }
    }
    if (this[0xbf0] == static_cast<ATIR500Surface>(0)) {
        return;
    }
    UInt32 fbIndex = getFramebufferIndex(this);
    SInt32 *fbRec = *reinterpret_cast<SInt32 **>(self + fbIndex * 8 + 0xd60);
    if (fbRec[0] != 0 && *reinterpret_cast<SInt16 *>(fbRec + 4) != 0 &&
        *reinterpret_cast<SInt16 *>(reinterpret_cast<UInt8 *>(fbRec) + 0x12) != 0) {
        setup_overlay();
    }
}
