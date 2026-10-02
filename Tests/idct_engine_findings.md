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
| 0x1f8c | params+0x10 (`dmaByteCount`, dwords) |
| 0x1ffc | params+0x24 |
| 0x1ff8 | params+0x28 (pitch, replicated in both halves) |
| (one more dword pair) | `(transferBufferGartAddr + accel+0x8a4) >> 1 & 0x7ffffff0`, then params+0x14 |
| 0x1fa8 | `accel+0x854` (running submission counter) |
| 0x1fac | params+0x18 |
| 0x1fb4 | 0, written six times |
| MMIO 0x1fa0 (kick) | `wptr << 24 | (wptr & 0x700) << 8` |

Only the plumbing is known. What the `dmaByteCount` words at the transfer buffer contain (the "coefficient/macroblock stream"), what 0x1ffc/0x1fac mean, and what the engine does with a malformed stream are not documented anywhere available. The values in params+0x10..+0x28 are supplied by the VA client (they are not computed by the kext) and point at memory the GPU will read.

## 3. Real-client capture
QuickTime Player and DVD Player (with the passive recorder, `Tools/userspace/va_capture/`) never open a DVD (type 3) connection on this Tiger/X1900 setup; they decode in software. No captured `doIDCT` call exists.

## Conclusion
No documentation and no real-client example gives a valid macroblock stream or valid `sATIDVDIDCTParams` values. A hardware submission would have to use invented addresses and stream content, which the #87 protocol forbids. #93's valid-path phases (A/B) therefore stay unrun; what could change this: (a) a client that actually drives the VA driver (not available here), (b) a captured submission from another OS/driver, (c) AMD documentation of the engine (not in the archive).
