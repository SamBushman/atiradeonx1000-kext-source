/*
 * IOATIR500Accelerator_VRAMReclaim.cpp
 *
 * RESOLVED (issue #31): `IOATIR500Accelerator::freeToAllocTextureVRAM`
 * (real addr 0x3f60), `IOATIR500Accelerator::freeToAllocSurfaceVRAM`
 * (real addr 0x45a0), and `IOATIR500Accelerator::tossSurfacesForVRAM`
 * (real addr 0x3d60) - by far the densest three of this issue's real
 * functions (`freeToAllocTextureVRAM` in particular is comparable in
 * size/density to `allocAllSlaveSwapBuffers`, issue #28's own densest
 * target), grouped in one file since all three cooperate on the same
 * real VRAM-reclamation problem and share real field/list conventions.
 *
 * `freeToAllocTextureVRAM` is transcribed AS LITERALLY AS POSSIBLE,
 * preserving the real decompile's own Ghidra-assigned label names
 * (`LAB_00004040` etc.) and variable names as real C++ `goto` labels/
 * locals verbatim, rather than force-restructuring them into "clean"
 * control flow - the same discipline `IOATIR500Surface_
 * AllocAllSlaveSwapBuffers.cpp` already established for a function this
 * dense, and doubly important here: an earlier draft of this exact
 * function that DID try to restructure/rename the goto-diamond into
 * cleaner code introduced at least one fabricated function name and
 * several unverifiable label-correspondence guesses before being
 * discarded in favor of this literal version. Keeping Ghidra's own
 * label/variable names makes every line mechanically auditable against
 * the original decompile.
 *
 * Real shared structure across all three: a real doubly-linked circular
 * list of `VendorTextureBuffer`-shaped nodes (own `+0x24`/`+0x28`
 * prev/next fields - matching this project's already-established
 * `surfaceOrFormatInfo`/`listNext` fields exactly; Ghidra's own
 * `-noanalysis` decompile mistypes these list nodes as
 * `IOATIR500Accelerator*` due to poor type propagation from the two
 * list-head fields' own declared type - transcribed here as raw `UInt8*`
 * instead), rooted at two real accelerator fields: `this+0x5dc`
 * (sentinel)/`this+0x604` ("active" list head) and `this+0x600`
 * ("deferred"/secondary list head) - real roles beyond "two related
 * eviction-candidate rings" not independently confirmed.
 * `freeToAllocTextureVRAM` surfaced an entire real, previously
 * undocumented family of accelerator-owned STATISTICS COUNTERS
 * (`this+0x7cc` through `this+0x7f4`, plus a literal `this+2000`
 * (`0x7d0`) - each simply incremented at a real decision point in the
 * eviction search) - real per-counter MEANING inferred only from its own
 * increment site, not independently confirmed against any debug/
 * telemetry interface.
 *
 * `tossSurfacesForVRAM`/`freeToAllocSurfaceVRAM` additionally walk the
 * real live-surface list via a `+0xa0` "next" pointer - NOTE this is a
 * DIFFERENT real offset than `+0x9c`, this project's own already-
 * established `nextLiveSurface` field (`IOATIR500Accelerator_
 * SetupStereo.cpp`) - transcribed exactly as decompiled rather than
 * assumed to be the same field; real relationship between the two
 * (a second distinct list vs. a real transcription slip in either this
 * or the earlier function) not investigated this pass.
 *
 * Confidence: CONFIRMED for control flow and every real offset AS GIVEN
 * BY Ghidra's own C decompile (trustworthy per this project's long-
 * standing "class-typed pointer already byte-scaled" convention - these
 * three functions are unusually clean in that respect, with almost no
 * genuinely ambiguous pointer arithmetic despite their size) but NOT
 * independently re-traced against raw disassembly instruction-by-
 * instruction given their sheer size - several field roles (the
 * statistics counters, the `+0xa0` list, a handful of vtable slots with
 * no established name: `+0x554`, `+0x56c`/`+0x5d0`'s exact real target)
 * remain UNKNOWN beyond what's directly inferable from their own call
 * site. No C++ compiler was available in the sandboxed environment this
 * was written in (same standing limitation as every other file in this
 * project).
 */

#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIRadeonX1000Types.h"

namespace {
inline UInt8  &B(void *p, int o)  { return *(reinterpret_cast<UInt8 *>(p) + o); }
inline UInt16 &H(void *p, int o)  { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(p) + o); }
inline SInt32 &SW(void *p, int o) { return *reinterpret_cast<SInt32 *>(reinterpret_cast<UInt8 *>(p) + o); }
inline UInt32 &W(void *p, int o)  { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(p) + o); }

/* real vtable +0x554 on IOATIR500Accelerator - no established name/role;
   called here with a real per-node stamp value (mip[0xc]), same real
   argument shape as the already-named waitForTimeStamp (+0x54c) one
   slot over - plausibly a sibling fence-wait variant, not confirmed. */
typedef UInt32 (*Fn0x554)(void *, UInt32);
inline UInt32 CallVtable0x554(void *accel, UInt32 arg) {
    void **vtable = *reinterpret_cast<void ***>(accel);
    return reinterpret_cast<Fn0x554>(vtable[0x554 / 4])(accel, arg);
}
} // namespace

UInt32 IOATIR500Accelerator::freeToAllocTextureVRAM(IOATIR500Surface *surface, VendorTextureBuffer **param_2,
                                                     SInt32 param_3, VendorTextureBuffer *param_4) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *pIVar6, *pIVar10, *pIVar11;
    SInt32 iVar5, iVar9;
    UInt32 uVar7, uVar8, uVar15;
    bool bVar3, bVar4, bVar12, bVar13;
    SInt32 lVar14;

    if (!((W(self, 0x21c) == 0) ||
          ((iVar5 = allocate_texture(param_4)), iVar5 != 0) ||
          ((iVar5 = tossSurfacesForVRAM(surface, param_2, param_3, param_4, true)), iVar5 == 0))) {
        return 1;
    }
    bVar4 = false;

LAB_00004450:
    iVar5 = allocate_texture(param_4);
    if (iVar5 == 0) {
        W(self, 0x7cc) += 1;
        if (surface == nullptr) {
            pIVar6 = *reinterpret_cast<UInt8 **>(self + 0x604);
        } else {
            pIVar6 = *reinterpret_cast<UInt8 **>(self + 0x604);
            pIVar10 = self + 0x5dc;
            if (pIVar6 == pIVar10 ||
                SW(reinterpret_cast<UInt8 *>(surface), 0x84) - SW(*reinterpret_cast<UInt8 **>(pIVar6 + 0x14), 8) < 1) {
                pIVar11 = *reinterpret_cast<UInt8 **>(self + 0x600);
                bVar12 = !bVar4;
                pIVar6 = nullptr;
                bVar3 = (pIVar11 == pIVar10);
                goto LAB_00004294;
            }
        }

        pIVar11 = self + 0x5dc;
        bVar12 = !bVar4;
        pIVar10 = nullptr;
    LAB_00004040:
        do {
            if (pIVar6 == pIVar11 || ((bVar13 = (pIVar10 == pIVar6)), pIVar10 == pIVar6)) {
                goto LAB_00004448;
            }
            W(self, 2000) += 1;
            if (param_3 < 1) {
                if (param_3 == 0) {
                LAB_000040b8:
                    if (bVar12) {
                        iVar5 = SW(pIVar6, 0x14);
                        if (iVar5 == 0 || ((uVar7 = B(reinterpret_cast<void *>(iVar5), 0x34)), uVar7 == 0)) {
                            goto LAB_00004124;
                        }
                        if ((H(reinterpret_cast<void *>(iVar5), 0x28) & ~H(reinterpret_cast<void *>(iVar5), 0x1c)) == 0) {
                            uVar15 = 0;
                            iVar9 = iVar5;
                            uVar8 = uVar7;
                            if (uVar7 == 0) {
                                uVar8 = 1;
                            }
                            do {
                                uVar15 = uVar15 + 1;
                                uVar8 = uVar8 - 1;
                                if (uVar8 == 0) {
                                    if (uVar7 == uVar15) goto LAB_00004124;
                                    goto LAB_00004040;
                                }
                                UInt16 *puVar1 = reinterpret_cast<UInt16 *>(iVar9 + 0x1e);
                                UInt16 *puVar2 = reinterpret_cast<UInt16 *>(iVar9 + 0x2a);
                                iVar9 = iVar9 + 2;
                                if ((*puVar2 & ~*puVar1) != 0) break;
                            } while (true);
                        }
                        W(self, 0x7d8) += 1;
                    } else {
                        iVar5 = SW(pIVar6, 0x14);
                    LAB_00004124:
                        iVar5 = CallVtable0x554(self, *reinterpret_cast<UInt32 *>(iVar5 + 0xc));
                        if (iVar5 != 0) {
                            if (W(pIVar6, 0x48) != 0) {
                                deallocate_texture(reinterpret_cast<VendorTextureBuffer *>(pIVar6));
                                SInt32 mip = SW(pIVar6, 0x14);
                                B(reinterpret_cast<void *>(mip), 0x14) = 1;
                                H(reinterpret_cast<void *>(mip), 0x28) = 0;
                                H(reinterpret_cast<void *>(mip), 0x2a) = 0;
                                H(reinterpret_cast<void *>(mip), 0x2c) = 0;
                                H(reinterpret_cast<void *>(mip), 0x2e) = 0;
                                H(reinterpret_cast<void *>(mip), 0x30) = 0;
                                H(reinterpret_cast<void *>(mip), 0x32) = 0;
                            }
                            iVar9 = SW(pIVar6, 0x24);
                            W(reinterpret_cast<void *>(iVar9), 0x28) = W(pIVar6, 0x28);
                            iVar5 = SW(pIVar6, 0x28);
                            W(pIVar6, 0x28) = reinterpret_cast<UInt32>(pIVar6);
                            SW(reinterpret_cast<void *>(iVar5), 0x24) = iVar9;
                            W(pIVar6, 0x24) = reinterpret_cast<UInt32>(pIVar6);
                            W(self, 0x7e0) += 1;
                            if (pIVar11 != pIVar6) goto LAB_00004430;
                            goto LAB_00004448;
                        }
                        W(self, 0x7dc) += 1;
                    }
                    if (pIVar10 == nullptr) {
                        pIVar10 = pIVar6;
                    }
                    if (W(pIVar6, 0x48) != 0) {
                        iVar9 = SW(pIVar6, 0x24);
                        W(reinterpret_cast<void *>(iVar9), 0x28) = W(pIVar6, 0x28);
                        iVar5 = SW(pIVar6, 0x28);
                        W(pIVar6, 0x28) = reinterpret_cast<UInt32>(pIVar11);
                        SW(reinterpret_cast<void *>(iVar5), 0x24) = iVar9;
                        W(pIVar6, 0x24) = W(self, 0x600);
                        W(self, 0x600) = reinterpret_cast<UInt32>(pIVar6);
                        W(*reinterpret_cast<UInt8 **>(pIVar6 + 0x24), 0x28) = reinterpret_cast<UInt32>(pIVar6);
                    }
                    pIVar6 = *reinterpret_cast<UInt8 **>(pIVar6 + 0x28);
                }
                goto LAB_00004040;
            }
            if (reinterpret_cast<UInt8 *>(*param_2) != pIVar6) {
                iVar5 = 0;
                lVar14 = param_3;
                do {
                    iVar5 = iVar5 + 1;
                    lVar14 = lVar14 - 1;
                    if (lVar14 == 0) goto LAB_000040b8;
                } while (reinterpret_cast<UInt8 *>(param_2[iVar5]) != pIVar6);
            }
            W(self, 0x7d4) += 1;
            pIVar6 = *reinterpret_cast<UInt8 **>(pIVar6 + 0x28);
        } while (true);
    }
    goto LAB_00004474;

LAB_00004294:
    if (!bVar3 && ((bVar13 = (pIVar11 == pIVar6)), pIVar11 != pIVar6)) {
        W(self, 0x7e4) += 1;
        if (param_3 < 1) goto code_r0x00004264;
        if (pIVar11 != reinterpret_cast<UInt8 *>(*param_2)) {
            iVar5 = 0;
            lVar14 = param_3;
            do {
                iVar5 = iVar5 + 1;
                lVar14 = lVar14 - 1;
                if (lVar14 == 0) goto LAB_000042b8;
            } while (reinterpret_cast<UInt8 *>(param_2[iVar5]) != pIVar11);
        }
        W(self, 0x7e8) += 1;
        goto LAB_0000428c;
    }
    goto LAB_00004448;

code_r0x00004264:
    if (param_3 != 0) goto LAB_00004294;
LAB_000042b8:
    if (bVar12) {
        iVar5 = SW(pIVar11, 0x14);
        if (iVar5 != 0) {
            uVar7 = B(reinterpret_cast<void *>(iVar5), 0x34);
            uVar8 = 0;
            if (uVar7 != 0) {
                if ((H(reinterpret_cast<void *>(iVar5), 0x28) & ~H(reinterpret_cast<void *>(iVar5), 0x1c)) == 0) {
                    uVar8 = 0;
                    iVar9 = iVar5;
                    uVar15 = uVar7;
                    if (uVar7 == 0) {
                        uVar15 = 1;
                    }
                    do {
                        uVar8 = uVar8 + 1;
                        uVar15 = uVar15 - 1;
                        if (uVar15 == 0) goto LAB_00004314;
                        UInt16 *puVar1 = reinterpret_cast<UInt16 *>(iVar9 + 0x1e);
                        UInt16 *puVar2 = reinterpret_cast<UInt16 *>(iVar9 + 0x2a);
                        iVar9 = iVar9 + 2;
                        if ((*puVar2 & ~*puVar1) != 0) break;
                    } while (true);
                }
                W(self, 0x7ec) += 1;
                goto joined_r0x00004360;
            }
        LAB_00004314:
            if (uVar8 != uVar7) goto LAB_00004294;
        }
        iVar5 = CallVtable0x554(self, *reinterpret_cast<UInt32 *>(iVar5 + 0xc));
        if (iVar5 == 0) {
            W(self, 0x7f0) += 1;
        joined_r0x00004360:
            if (pIVar6 == nullptr) {
                pIVar6 = pIVar11;
            }
            if (W(pIVar11, 0x48) != 0) {
                iVar9 = SW(pIVar11, 0x24);
                W(reinterpret_cast<void *>(iVar9), 0x28) = W(pIVar11, 0x28);
                iVar5 = SW(pIVar11, 0x28);
                W(pIVar11, 0x28) = W(self, 0x604);
                W(self, 0x604) = reinterpret_cast<UInt32>(pIVar11);
                SW(reinterpret_cast<void *>(iVar5), 0x24) = iVar9;
                W(pIVar11, 0x24) = reinterpret_cast<UInt32>(pIVar10);
                W(*reinterpret_cast<UInt8 **>(pIVar11 + 0x28), 0x24) = reinterpret_cast<UInt32>(pIVar11);
            }
        LAB_0000428c:
            pIVar11 = *reinterpret_cast<UInt8 **>(pIVar11 + 0x24);
            bVar3 = (pIVar11 == pIVar10);
            goto LAB_00004294;
        }
    }
    if (W(pIVar11, 0x48) != 0) {
        deallocate_texture(reinterpret_cast<VendorTextureBuffer *>(pIVar11));
        SInt32 mip = SW(pIVar11, 0x14);
        B(reinterpret_cast<void *>(mip), 0x14) = 1;
        H(reinterpret_cast<void *>(mip), 0x28) = 0;
        H(reinterpret_cast<void *>(mip), 0x2a) = 0;
        H(reinterpret_cast<void *>(mip), 0x2c) = 0;
        H(reinterpret_cast<void *>(mip), 0x2e) = 0;
        H(reinterpret_cast<void *>(mip), 0x30) = 0;
        H(reinterpret_cast<void *>(mip), 0x32) = 0;
    }
    iVar9 = SW(pIVar11, 0x24);
    W(reinterpret_cast<void *>(iVar9), 0x28) = W(pIVar11, 0x28);
    iVar5 = SW(pIVar11, 0x28);
    W(pIVar11, 0x28) = reinterpret_cast<UInt32>(pIVar11);
    SW(reinterpret_cast<void *>(iVar5), 0x24) = iVar9;
    W(pIVar11, 0x24) = reinterpret_cast<UInt32>(pIVar11);
    W(self, 0x7f4) += 1;
    if (pIVar10 != pIVar11) goto LAB_00004430;
    goto LAB_00004448;

LAB_00004430:
    if (bVar13) {
    LAB_00004448:
        if (!bVar12) goto LAB_00004474;
        bVar4 = true;
    }
    goto LAB_00004450;

LAB_00004474:
    if (W(param_4, 0x48) == 0 && tossSurfacesForVRAM(surface, param_2, param_3, param_4, false) == 0) {
        return 0;
    }
    return 1;
}

UInt32 IOATIR500Accelerator::freeToAllocSurfaceVRAM(IOATIR500Surface *excludeA, IOATIR500Surface *excludeB,
                                                     VendorTextureBuffer **param_3, SInt32 param_4,
                                                     ATIR500SurfaceBuffer *needed) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    bool useAccelPath = (excludeA == nullptr);
    UInt8 *pIVar12, *this_00;
    SInt32 iVar5, iVar6, lVar15;
    UInt32 uVar8, uVar10, uVar16;
    bool bVar3 = false;

    for (;;) {
        for (;;) {
            if (useAccelPath) {
                iVar5 = alloc_surface_buffer(needed);
            } else {
                iVar5 = excludeA->alloc_surface_buffer(needed);
            }
            if (iVar5 == 1) break;

            pIVar12 = *reinterpret_cast<UInt8 **>(self + 0x604);
            for (;;) {
                for (;;) {
                    for (;;) {
                        if (self + 0x5dc == pIVar12) goto LAB_00004794;
                        if (param_4 < 1) break;
                        if (pIVar12 != reinterpret_cast<UInt8 *>(*param_3)) {
                            iVar5 = 0;
                            lVar15 = param_4;
                            do {
                                iVar5++;
                                lVar15--;
                                if (lVar15 == 0) goto LAB_00004654;
                            } while (pIVar12 != reinterpret_cast<UInt8 *>(param_3[iVar5]));
                        }
                    LAB_000046a0:
                        pIVar12 = *reinterpret_cast<UInt8 **>(pIVar12 + 0x28);
                    }
                    if (param_4 == 0) break;
                }
            LAB_00004654:
                if (bVar3 || ((iVar5 = SW(pIVar12, 0x14)), iVar5 == 0)) break;
                uVar10 = B(reinterpret_cast<void *>(iVar5), 0x34);
                uVar8 = 0;
                if (uVar10 != 0) {
                    if ((H(reinterpret_cast<void *>(iVar5), 0x28) & ~H(reinterpret_cast<void *>(iVar5), 0x1c)) == 0) {
                        uVar8 = 0;
                        uVar16 = uVar10;
                        if (uVar10 == 0) uVar16 = 1;
                        SInt32 scan = iVar5;
                        do {
                            uVar8++;
                            uVar16--;
                            if (uVar16 == 0) goto LAB_000046b8;
                            UInt16 *puVar1 = reinterpret_cast<UInt16 *>(scan + 0x1e);
                            UInt16 *puVar2 = reinterpret_cast<UInt16 *>(scan + 0x2a);
                            scan += 2;
                            if ((*puVar2 & ~*puVar1) != 0) break;
                        } while (true);
                    }
                    goto LAB_000046a0;
                }
            LAB_000046b8:
                if (uVar8 == uVar10) break;
            }

            if (W(pIVar12, 0x48) != 0) {
                deallocate_texture(reinterpret_cast<VendorTextureBuffer *>(pIVar12));
                SInt32 mip = SW(pIVar12, 0x14);
                B(reinterpret_cast<void *>(mip), 0x14) = 1;
                H(reinterpret_cast<void *>(mip), 0x28) = 0;
                H(reinterpret_cast<void *>(mip), 0x2a) = 0;
                H(reinterpret_cast<void *>(mip), 0x2c) = 0;
                H(reinterpret_cast<void *>(mip), 0x2e) = 0;
                H(reinterpret_cast<void *>(mip), 0x30) = 0;
                H(reinterpret_cast<void *>(mip), 0x32) = 0;
            }
            iVar5 = SW(pIVar12, 0x24);
            W(reinterpret_cast<void *>(iVar5), 0x28) = W(pIVar12, 0x28);
            iVar6 = SW(pIVar12, 0x28);
            W(pIVar12, 0x28) = reinterpret_cast<UInt32>(pIVar12);
            SW(reinterpret_cast<void *>(iVar6), 0x24) = iVar5;
            W(pIVar12, 0x24) = reinterpret_cast<UInt32>(pIVar12);
        }

    LAB_00004794:
        if (W(needed, 8) != 0) {
            return 1;
        }
        if (bVar3) {
            return 0;
        }
        UInt8 *pIVar9 = *reinterpret_cast<UInt8 **>(self + 0x5c);
        if (pIVar9 != nullptr) {
            this_00 = pIVar9;
            do {
                this_00 = *reinterpret_cast<UInt8 **>(this_00 + 0xa0);
                if (reinterpret_cast<UInt8 *>(excludeA) != this_00 && this_00 != reinterpret_cast<UInt8 *>(excludeB)) {
                    bool excluded = false;
                    if (param_4 > 0) {
                        VendorTextureBuffer **p = param_3;
                        SInt32 remaining = param_4;
                        do {
                            VendorTextureBuffer *tex = *p++;
                            if (tex != nullptr && B(tex, 0x20) == 0 &&
                                this_00 == *reinterpret_cast<UInt8 **>(reinterpret_cast<UInt8 *>(tex) + 0x50)) {
                                excluded = true;
                                break;
                            }
                            remaining--;
                        } while (remaining != 0);
                    } else if (param_4 == 0) {
                        goto LAB_0000492c;
                    }
                    if (!excluded) {
                        UInt32 slot = 0;
                        UInt8 *rec = this_00 + 0xa8;
                        do {
                            if ((SW(this_00, 0xc14) == 0xffff || (slot > 1 && (slot - 4) > 1)) &&
                                W(rec, 8) != 0 &&
                                ((W(this_00, 0xbd0) & 0xffff0000) == 0 ||
                                 rec != *reinterpret_cast<UInt8 **>(this_00 + 0xb70))) {
                                if (W(this_00, 0xd48) == 0) {
                                    reinterpret_cast<IOATIR500Surface *>(this_00)->move_buffer_to_backing_store(
                                        reinterpret_cast<ATIR500SurfaceBuffer *>(rec));
                                } else {
                                    typedef SInt32 (*Fn0x5cc)(void *, UInt32);
                                    void **vt = *reinterpret_cast<void ***>(this_00);
                                    reinterpret_cast<Fn0x5cc>(vt[0x5cc / 4])(this_00, slot);
                                }
                                if (useAccelPath) {
                                    alloc_surface_buffer(needed);
                                } else {
                                    excludeA->alloc_surface_buffer(needed);
                                }
                                if (W(needed, 8) != 0) {
                                    return 1;
                                }
                            }
                            bVar3 = (slot != 0x16);
                            rec += 0x78;
                            slot++;
                        } while (bVar3);
                        pIVar9 = *reinterpret_cast<UInt8 **>(self + 0x5c);
                    }
                }
            LAB_0000492c:
                ;
            } while (this_00 != pIVar9);
        }
        bVar3 = true;
    }
}

UInt32 IOATIR500Accelerator::tossSurfacesForVRAM(IOATIR500Surface *excludeSurface, VendorTextureBuffer **excludeList,
                                                  SInt32 excludeCount, VendorTextureBuffer *needed, bool skipExcludeCheck) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *head = *reinterpret_cast<UInt8 **>(self + 0x5c);

    if (head != nullptr) {
        UInt8 *surf = head;
        do {
            surf = *reinterpret_cast<UInt8 **>(surf + 0xa0);
            if (surf != reinterpret_cast<UInt8 *>(excludeSurface) &&
                (!skipExcludeCheck || W(surf, 0xd48) != 0)) {
                bool excluded = false;
                if (excludeCount > 0) {
                    VendorTextureBuffer **p = excludeList;
                    SInt32 remaining = excludeCount;
                    do {
                        VendorTextureBuffer *tex = *p++;
                        if (tex != nullptr && B(tex, 0x20) == 0 &&
                            surf == *reinterpret_cast<UInt8 **>(reinterpret_cast<UInt8 *>(tex) + 0x50)) {
                            excluded = true;
                            break;
                        }
                        remaining--;
                    } while (remaining != 0);
                } else if (excludeCount < 0) {
                    goto nextSurf;
                }
                if (!excluded) {
                    UInt32 slot = 0;
                    UInt8 *rec = surf + 0xa8;
                    bool more;
                    do {
                        if ((SW(surf, 0xc14) == 0xffff || (slot > 1 && (slot - 4) > 1)) &&
                            W(rec, 8) != 0 &&
                            ((W(surf, 0xbd0) & 0xffff0000) == 0 ||
                             rec != *reinterpret_cast<UInt8 **>(surf + 0xb70))) {
                            if (W(surf, 0xd48) == 0) {
                                reinterpret_cast<IOATIR500Surface *>(surf)->move_buffer_to_backing_store(
                                    reinterpret_cast<ATIR500SurfaceBuffer *>(rec));
                                allocate_texture(needed);
                            } else if (W(surf, 0xbcc) == 0) {
                                typedef SInt32 (*Fn0x5cc)(void *, UInt32);
                                void **vtable = *reinterpret_cast<void ***>(surf);
                                reinterpret_cast<Fn0x5cc>(vtable[0x5cc / 4])(surf, slot);
                                allocate_texture(needed);
                            }
                            if (W(needed, 0x48) != 0) {
                                return 1;
                            }
                        }
                        more = (slot != 0x16);
                        rec += 0x78;
                        slot++;
                    } while (more);
                    if (W(needed, 0x48) != 0) {
                        return 1;
                    }
                    head = *reinterpret_cast<UInt8 **>(self + 0x5c);
                }
            }
        nextSurf:
            ;
        } while (surf != head);
    }

    return W(needed, 0x48) != 0 ? 1 : 0;
}
