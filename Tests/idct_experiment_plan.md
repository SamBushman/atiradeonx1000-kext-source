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
