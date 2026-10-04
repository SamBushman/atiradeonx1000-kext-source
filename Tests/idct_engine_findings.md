# DVD IDCT engine: what the available evidence says (issue #93)

Question: can the valid path of DVD `doIDCT` (selector 18) be derived from documentation, so a hardware submission can be run under the #87 protocol with evidence-derived parameters?

## 1. AMD document archive (`~/Documents/AMD Docs`, 40+ PDFs converted with pdftotext)
* `R5xx_Acceleration_v1.1-1.5.pdf`, `R3xx_3D_Registers.pdf`: no IDCT or motion-compensation engine section. MPEG appears only as texture formats (`TX_FMT_16_MPEG`), a DAC/colour table row (`C_16_MPEG`) and `MPEG_INDEX` (a packet-index register).
* `RRG-216M56-03oOEM.pdf` (M56 Register Reference Guide, R5xx family) and the RV630/M76/RS690 guides: "IDCT" occurs only as a memory-controller **client name** (`3=idct` in the MC client-select fields, and `MC_WCMB_TIMEOUT` "for these clients only: CP, IDCT, VIP, MCIF"). No register block, no field list, no stream format.
* A search for the registers the kext programs (offsets 0x1f8c, 0x1fa0, 0x1fa8, 0x1fac, 0x1fb4, 0x1fe0, 0x1fe4, 0x1fec, 0x1ff0, 0x1ff8, 0x1ffc) finds none of them in any R3xx/R5xx document. (The Evergreen/Cayman/SI/RDNA/Vega documents are newer architectures with different register maps.)
=> The IDCT engine is **undocumented** in the archive.

## 2. What the shipped kext itself emits (`ATIRadeonX1000::submit_idct_buffer_consumed`, 0x1eb30; `Sources/ATIRadeonX1000_submit_idct_buffer_consumed_Port.cpp`)
Per submission it appends type-0 register-write packets (`0x8000<reg>`, value) to the accelerator ring (`accel+0x91c`, 0x800 dwords, write pointer `accel+0x930`) and then kicks it with an MMIO write to `0x1fa0`:

| register | value (sATIDVDIDCTParams / state) |
|---|---|
| 0x1fe0 | params+0x2c (destination plane start, from the surface plane record) |
| 0x1fe4 | params+0x30 (destination end) |
| 0x1fec | params+0x1c (plane size - 1) |
| 0x1ff0 | params+0x20 (half-height size - 1) |
| 0x1f8c | params+0x10 (`dmaDwordCount`, dwords) |
| 0x1ffc | params+0x24 |
| 0x1ff8 | params+0x28 (pitch, replicated in both halves) |
| (one more dword pair) | `(transferBufferGartAddr + accel+0x8a4) >> 1 & 0x7ffffff0`, then params+0x14 |
| 0x1fa8 | `accel+0x854` (running submission counter) |
| 0x1fac | params+0x18 |
| 0x1fb4 | 0, written six times |
| MMIO 0x1fa0 (kick) | `wptr << 24 | (wptr & 0x700) << 8` |

Only the plumbing is known. What the `dmaDwordCount` words at the transfer buffer contain (the "coefficient/macroblock stream"), what 0x1ffc/0x1fac mean, and what the engine does with a malformed stream are not documented anywhere available. The values in params+0x10..+0x28 are supplied by the VA client (they are not computed by the kext) and point at memory the GPU will read.

## 3. Real-client capture
QuickTime Player and DVD Player (with the passive recorder, `Tools/userspace/va_capture/`) never open a DVD (type 3) connection on this Tiger/X1900 setup; they decode in software. No captured `doIDCT` call exists.

## Conclusion
No documentation and no real-client example gives a valid macroblock stream or valid `sATIDVDIDCTParams` values. A hardware submission would have to use invented addresses and stream content, which the #87 protocol forbids. #93's valid-path phases (A/B) therefore stay unrun; what could change this: (a) a client that actually drives the VA driver (not available here), (b) a captured submission from another OS/driver, (c) AMD documentation of the engine (not in the archive).


---
# Issue #140 - the engine and its stream, derived (2026-10-04)

(Struct fields were renamed after this analysis: `dmaByteCount` -> `dmaDwordCount`, `chromaFlag` -> `fieldPictureFlag`, `fieldFlag` -> `bottomFieldFlag`, `idctCoeffAddr14/18/24` -> `engineFlagWord` / `planeModeWord` / `dimensionsHeightWidth`; `sATIDVDIDCTInfo` luma/chroma buffers -> stream0/stream1. Section 2's older text still says luma/chroma and byte count - superseded by sections 5-6.)

**Correction to sections 2-3 above.** (a) The doIDCT call site in the VA driver *is* findable: `ATIRadeonX1000VADriver` `FUN_00005fd0` (0x5fd0) calls
`_io_connect_method_structureI_structureO(conn, 0x12, &in, 0x38, 0, &out)`; the selector reaches the wrapper through a register copy that the old
`va_callsites.txt` scan (constant `li r4,N` only) missed. (b) Only part of `sATIDVDIDCTParams` is "supplied by the VA client": `doIDCT` itself computes
+0x1c, +0x20, +0x28, +0x2c, +0x30 (see `ATIR500DVDContext_doIDCT_Port.cpp`). So no live capture was needed: the client *and* a software consumer of the same
data are both present in the stock binaries, and both were read.

Confidence labels below: **EXACT** = read directly from stock code on both sides; **INFERRED** = follows from structure, not stated by any code; **UNKNOWN**.

## 4. What the engine is (external evidence)
* The block is ATI's legacy MPEG-2 hardware decoder at MMIO 0x1F80-0x1FFF. Linux `radeon_reg.h` (also xf86-video-ati, MPlayer vidix `radeon.h`) names
  `IDCT_RUNS` 0x1F80, `IDCT_LEVELS` 0x1F84, `IDCT_AUTH_CONTROL` 0x1F88, `IDCT_AUTH` 0x1F8C, `IDCT_CONTROL` 0x1FBC. vidix's comment describes it as "MPEG-2 hardware
  decoder which incorporates run-level decode, de-zigzag and IDCT into an IDCT engine to complement the motion compensation engine" (`SE_MC_SRC1_CNTL.IDCT_EN`,
  bit 28, is documented as a bare bit in the Rage 128 Pro Register Reference Guide). The ATI Imageon W100 header (`hackndev/linux-hnd`, `drivers/video/imageon/w100/idct.h`)
  gives bitfields for the same family: RUNS = four 8-bit runs per dword, LEVELS = two 16-bit levels per dword, CONTROL = luma/chroma read format, scan pattern,
  intra, flush, passthru, sw_reset, constreq, scramble, alt_scan.
* The Rage 128 Pro RRG (bitsavers `RRG-G04500-C`) lists "iDCT registers" in its chapter overview but contains no register definitions for them; the AMD archive
  (R3xx/R5xx/RV630/M76/RS690/M56) mentions IDCT only as an MC client and a clock-gate bit. **No document defines the 0x1fe0-0x1ffc front end the R5xx kext uses.**
* Consequence (INFERRED): the kext's 11 registers are a DMA front end added in front of the legacy block. Only 0x1f8c overlaps a name in Linux's list (`IDCT_AUTH`),
  and the kext writes `dmaDwordCount` there, so Linux's names are not reliable for the R5xx variant. 0x1fa0/0x1fa8/0x1fac/0x1fb4/0x1fe0..0x1ffc are in no public header.
* Motion compensation is **not** done by this engine on this hardware: the VA driver builds it from 3D-engine quads (`FUN_0000bf20`, command buffer = mapped
  type 1) from the motion-vector lists written by `FUN_00008820`. The engine only reconstructs the residual / intra pixels.

## 5. The doIDCT parameter block (0x38 bytes) - EXACT (client `FUN_00005fd0` + kext)
| off | who | value |
|---|---|---|
| +0x00 | client | 0 for a frame picture (picture_structure == 3), 1 for a field picture. Kext: nonzero doubles the pitch (field access) |
| +0x04 | client | 1 for the bottom field (picture_structure == 2) else 0. Kext: nonzero offsets the destination start by one line |
| +0x08 | client | destination surface index (selects the 0x78-byte plane record) - plane 0 only |
| +0x0c | client | stream/plane selector, 0 or 1; anything else returns 0xe00002c2 **with the accelerator command lock still held** (shipped bug, reproduced) |
| +0x10 | client | stream length in dwords = (write pointer - base) >> 2. **The kext never checks it against the buffer's capacity**; it sizes the CPU cache flush with it and writes it to 0x1f8c |
| +0x14 | client | `0x10080 \| (alternate_scan << 3) \| (plane0 ? 0x20 : 0)`; written as the dword that follows the DMA-address dword in the ring (the `(GART+0x20 >> 1) & 0x7ffffff0` pair, which has no register name in the packet) |
| +0x18 | client | `plane1 ? 0x8000 : 0`; written to 0x1fac |
| +0x1c,+0x20,+0x28 | kext | plane size-1, half-height size-1, pitch replicated in both halves of a dword |
| +0x24 | client | `(height << 16) \| width` in pixels; height is halved unless picture_structure == 3; written to 0x1ffc |
| +0x2c,+0x30 | kext | destination plane start/end |
So 0x1ffc = picture dimensions and 0x1fac = a plane-1 mode bit (0x8000). Meanings of the individual bits of +0x14 beyond alt-scan (bit 3) and "plane 0" (bit 5) are UNKNOWN
(0x10080 is passed unchanged for every call the client makes).

## 6. The two streams - EXACT for layout, INFERRED for semantics
The client maps two kext buffers (`IOConnectMapMemory` types 4 and 5). Each is: 0x20-byte header (`+0x10` = capacity in dwords, `+0x18` = a tag the client stores), data from +0x20.
The kext DMAs from `GART + 0x20`. **Stream 0** carries intra macroblocks (all MBs of an I picture, and the intra MBs of P/B pictures: flag 0x20 above); **stream 1** carries the
macroblocks that have motion (their residual, written to a separate residual surface, `surfaceInfo + 0x8a0`, then combined with the prediction by the 3D engine). That role split is
consistent between the client's routing (`FUN_00003930`: no motion flag -> stream 0, motion flag -> stream 1 + motion lists), the kext's surface choice, and the 0x20 / 0x8000 flags,
but no code states it in words (INFERRED).

Per macroblock that has at least one non-zero block (MBs with six zero counts emit nothing), `FUN_00008510` appends:
* dword 0: `bit31 = field_dct | alt_scan << 25 | CBP << 6`, CBP = six bits (set when that block's count is non-zero), Y0 = bit 11, Y1 = bit 10, Y2 = bit 9, Y3 = bit 8, Cb = bit 7, Cr = bit 6.
* dword 1: `(mb_address / mb_width) << 20 | (mb_address % mb_width) << 4`, address counted within the field for field pictures.
* then the coded blocks' coefficient dwords, verbatim, in block order Y0 Y1 Y2 Y3 Cb Cr, N = sum of the six counts of the host record.
No padding or terminator between macroblocks. (The 0xffff1000 / 0x80000000 / 0xc0001000 pad words seen in `FUN_00007de0` belong to the type-1 command buffer, not to these streams.)

## 7. The coefficient dword - EXACT for Apple's AVA software consumer (`AppleVADriverG5` `FUN_0000aac0`, first loop); see section 10 item 1 for the second, older reader that disagrees
```
dword  = level << 16 | run << 1 | b0          level: signed 16 bit, run: 15 bits, b0: ignored by the software consumer
idx    = prev + run;  prev = idx + 1;  block[scan[idx]] = level      (prev restarts at 0 for every block)
scan   = one of two tables (zigzag, alternate) selected by the picture's alternate_scan byte
```
This is the "run-level decode + de-zigzag" half of the engine, which the vidix text and the W100 RUNS/LEVELS registers independently describe.
Levels are **already inverse-quantised**: no quantiser matrix or scale appears anywhere in the VA interface (the picture descriptor is 3 byte-pairs, 3 surface indices
and two pointers, all of whose uses were read in both `FUN_00003930` and Apple's `FUN_000050e0`), nor in the kext's register list; the dense software decoders
(`FUN_00010510` etc.) do the dequantisation in the VLD. (INFERRED from absence; the producer was not found, see section 10.)

The host macroblock record the client reads is 0x1c bytes: +0x00..0x0f four (x,y) short pairs = forward MV, backward MV, second forward MV, second backward MV; +0x10..0x13 reference-field
selects; +0x14 motion flags (1 fwd, 2 bwd, 4 second vector; 0 = intra); +0x15 field_dct; +0x16..0x1b six per-block dword counts. Motion vectors are converted to half-pel
(`v - (v>>31) >> 1` plus fraction) for the 3D path, and are never part of the IDCT stream.

## 8. Resolution of the issue's questions
1. Stream format: **derived** (sections 5-7), good enough to build a stream and a parameter block without inventing anything but the pixel content.
2. Fields: 0x1ffc = (height<<16 | width); 0x1fac = plane-1 mode 0x8000; 0x1f8c = stream length in dwords; the (GART>>1 & 0x7ffffff0, +0x14) pair = DMA address and the
   flag word. UNKNOWN: the individual bits of the flag word beyond alt-scan/intra, and the meaning of b0.
3. Why the old capture failed (see section 9): DVD Player's framework decides per display whether to use the accelerator's own VA driver or its built-in AltiVec software
   driver, and on this machine it never picks the former. The software renderers consume the same macroblock records and coefficient dwords, which is why they are the best
   available specification of the stream.

## 9. Why no player ever opens a DVD context on this machine (and what that means for a capture)
* The accelerator does publish the hook: `ioreg` on the G5 shows `IODVDBundleName = "ATIRadeonX1000VADriver"` (and `IOGLBundleName = "ATIRadeonX1000GLDriver"`).
* `DVDPlayback.framework` (`FUN_98250298` and three near-copies) enumerates the displays, reads that property, and loads the named bundle - but it substitutes the literal
  string `AppleAltiVecDVDDriver` whenever a local flag is set: `(DAT_a8178510 || DAT_a8178511 || !hw_check_passed) && display_uses_OpenGL_acceleration`. `FUN_9824f580` is the
  setter for the two flags; the hardware check is a function pointer loaded from a separate bundle that was not identified. The binary contains a short GPU name list
  (`NVIDIA GeForce FX 5200`, `NVIDIA NV34MAP`, `ATI Radeon 9600`, `ATI Radeon 9600 XT`); the Radeon X1900 is not on it. I did not prove that this list is the gate - only that
  it exists next to the gate and that the observed behaviour (software on the X1900) fits it. (INFERRED)
* Consequence: a capture of a stock player on this GPU will not be obtained by playing more content. Either the gate has to be satisfied (not attempted), or a purpose-built client has to call
  the VA driver, which the derived format now makes possible without guessing the stream.

## 10. Open items, stated plainly
1. **Coefficient dword layout has two software readers that disagree.** `AppleVADriverG5` `FUN_0000aac0` (AVA API v1.1, the same API family the ATI driver exports, v1.2) reads
   `level = dword >> 16`, `run = (dword >> 1) & 0x7fff`. The older `AppleAltiVecDVDDriver` back end (`mp2decvbin1`, `_VEO_idct_cbp`, pre-AVA `_DVDDriver*` API) reads `run = byte 0`
   and `level = halfword at +2`. The ATI client copies the dwords verbatim, so the hardware takes whatever the front end for the AVA path emits; the AVA layout (first form) is the
   best-supported reading, but **no code was found that produces the dwords** (the VLD front end that writes them was not located in `DVDPlayback`, `AppleVA`, `QuickTimeMPEG2` or
   `AppleAltiVecDVDDriver`; the dense `Decode_MPEG2_*_Block` routines in `AppleVADriverG5` are the host renderer's own and do not emit this form). Confidence: INFERRED.
2. **Bit 0 of the dword** is ignored by both software readers. The ATI packet carries no per-block counts (only the six CBP bits), so the hardware has to find block ends in the
   data; bit 0 is the obvious end-of-block candidate. UNKNOWN - this is the first thing a live Phase A must test, with a one-block, one-coefficient packet.
3. **Dequantisation** is not in the stream interface (INFERRED from absence, section 7). A DC-only block is the safest first test content.
4. The individual bits of the +0x14 flag word other than alt-scan (bit 3) and "stream 0" (bit 5), and what 0x8000 in +0x18 selects in the engine: UNKNOWN.
5. Linux's names for 0x1f80-0x1f8c do not match the R5xx front end's use of 0x1f8c (the kext writes the stream length there).

## 11. Verdict for issue #140 / what #93 can now do
Success criterion 1 asks for a derived stream format "with enough confidence to justify attempting #93's Phase A". The parameter block, the buffer layout, the macroblock header, and the
run/level structure are derived from stock code on both sides and the hardware lineage is documented externally; the stream is therefore no longer invented. What remains open (items 1-2)
is a one-bit/one-layout question that only a hardware test, under the #87 protocol, can decide. The test vector is already determined: one stream-0 macroblock, CBP = Y0 only,
one dword with `level = L` and `run = 0` (and, as the alternative, the same with bit 0 set), a destination surface the test owns, `dmaDwordCount` = real dword count <= buffer capacity.
