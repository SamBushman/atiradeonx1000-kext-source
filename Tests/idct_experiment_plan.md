# DVD IDCT engine: live experiment ladder (issue #140 follow-up, feeds #93)

Goal: settle what static analysis cannot (`Tests/idct_engine_findings.md` section 10). All rungs use the STOCK kext and the #87 protocol (`Tests/destructive`: write-ahead log, preflight/postflight, peer ack,
one test per boot, reboot afterwards). Rungs 0-2 touch no hardware engine.

Open questions: (1) does the engine use bit 0 as block terminator and what happens without it; (2) output bias/clipping (stream 0), residual sign/offset (stream 1), level saturation;
(3) the other bits of `engineFlagWord` and `planeModeWord` 0x8000; (4) alt-scan and the field flags in hardware; (5) whether `dimensionsHeightWidth` limits the engine.

| rung | what | hardware? | answers |
|---|---|---|---|
| 0 | `kemu.py` dry run of stock `doIDCT` + `submit_idct_buffer_consumed` on a synthetic one-macroblock state | no | predicted ring words / registers; no wild access |
| 1 | software oracle: Python stream encoder -> Apple's software AVA renderer (`AppleVADriverG5`) on the G5 | userspace only | expected pixels for every later rung; validates the encoder against the real consumer |
| 2 | drive the real `ATIRadeonX1000VADriver` via the AVA API with the rung-1 picture, recorder shim swallowing selector 18 | no engine execution (opens DVD ctx, maps types 4/5 - first live use, #126 neighbourhood) | real params + buffer bytes; real `set_surface`/`setup_buffers` args |
| 3 | Phase A: one stream-0 macroblock, Y0 only, DC-only, bit 0 set, 16x16 owned destination, real `dmaDwordCount` | yes | completion stamp (5 s watchdog), ring advance, pixels == oracle |
| 4 | arms, one per boot, increasing risk: (a) run>0 and alt-scan on/off; (b) CBP Cb/Cr block order; (c) stream 1 with `planeModeWord` 0x8000; (d) macroblock at column 1 of a 32x16 picture; (e) bit 0 clear on the last dword (most likely to stall - last) | yes | questions 1-5 |

Not probed: undefined flag bits blindly, out-of-bounds macroblock addresses, out-of-range `planeSelector` (leaks the command lock).
Prerequisites to confirm: output read-back from a surface the DVD context writes (reuse `probe_shape_backing.c`), real `set_surface` modeBits/flagCount (rung 2 captures them).

## Results so far

**Rung 0 - done (`Tools/userspace/emu/idct_dryrun.py`, 2026-10-04).** The stock kext's machine code for `doIDCT` + `submit_idct_buffer_consumed` was run in unicorn against a hand-built context/accelerator/ring/MMIO/surface and compared with an
independent model of the derived behaviour (including a negative control: a corrupted model is detected). All five stream/field scenarios MATCH: 32 ring dwords (ten register/address pairs + six `0x1fb4` trigger pairs), MMIO kick `0x1fa0 = 0x20000000`,
kext-computed parameter fields +0x1c..+0x30, completion tag/stamp bookkeeping (`this+0x150/0x154`, transfer buffer +0x10), three external calls per call (waitForTimeStamp, IOLockLock, IOLockUnlock). `planeSelector` 2 returns `0xe00002c2` with the
unlock call missing (lock leak reproduced). An oversize `dmaDwordCount` (0x40000 over a 0x1000-byte buffer) is accepted: returns 0, writes the count to 0x1f8c and the cache-flush loop walks ~1 MB past the buffer - the kext does not bound-check it.
Side finding: the DMA-address dword is `((GART + 0x20 + accel[0x8a4]) >> 1) & 0x7ffffff0`, i.e. the low four bits of the halved address are dropped, so the stream must start on a 32-byte boundary (the transfer buffer's GART base + 0x8a4 offset + the 0x20 header).
Not modelled: `map_transfer_to_GART`, the cache-maintenance branch with real memory, the hardware.

**Rung 1 - done as a spec oracle (`Tools/idct_stream.py`).** Encoder, parser (block ends found from the last bit, as the hardware must), reference IDCT oracle, and seven test vectors (`idct_stream.py vectors`) for rungs 3-4; 17 self-tests pass (pack/unpack, scan tables,
DC-only values, zigzag-vs-alternate ramp orientation, packet round trips, MB boundaries, block placement and field-DCT line interleave). The oracle's numeric conventions were cross-checked against Apple's software output stage (`AppleVADriverG5` `FUN_0000b7e0` intra / `FUN_0000b6c0` non-intra):
intra output = IDCT result, signed max with 0, unsigned-saturating pack (clip 0..255, **no +128 bias**); non-intra = IDCT residual + prediction, same clip. Both standard MPEG-2 scan tables are present in the binaries (plus transposed copies for Apple's AltiVec IDCT, an internal detail).
**What rung 1 did NOT do:** run Apple's real decoder on the vectors. That needs the AVA renderer set-up chain (surface allocation, the 0x260-byte per-picture structure owned by AppleVA) and was judged not worth its cost: it would re-validate my encoder against the same code I already read line by line.
For stream 1 the hardware behaviour (does the engine write signed residuals, with what offset, and what does 0x8000 in `planeModeWord` do) is exactly what vector V5 is for.
