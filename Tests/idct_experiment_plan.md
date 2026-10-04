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

## Rung 2 plan - capture what the real VA driver sends, with nothing executed by the GPU

**Goal.** Obtain, from the real `ATIRadeonX1000VADriver` fed by Apple's real front end, (a) the exact `doIDCT` parameter block and the exact stream bytes in the type 4/5 buffers, (b) the real `set_surface` / `setup_buffers` / `declare_image` arguments and the surface it binds, (c) the real DVD command-buffer contents, **without** the kernel ever running an IDCT submission or a DVD command buffer. It validates, end to end and with real producer output, every claim in findings sections 5-7 (parameter fields, packet header, run/level dwords, bit 0, dequantisation) and fixes the unknown arguments rung 3 needs.

**What the VA driver is, as established statically (2026-10-04).** `_AVACreateRenderer` (0x2100) builds a renderer table (AVA 1.2): +0x10 `FUN_00002570` open (IOServiceOpen type 3, selector 1, maps types 1/4/5/2, selector 0 set_surface), +0x14 close, +0x2c `FUN_00002e50` per-decoder setup (selectors 0x11, 0x15, 0, 4), +0x34 `FUN_00003930` picture decode (descriptor + macroblock array + coefficient array, consumed as in findings section 6). Command buffers are submitted by **re-mapping memory type 1** (the kext swaps ping-pong buffers inside `clientMemoryForType`), not by a selector; selector 18 is called from `FUN_00005fd0` when a stream buffer is flushed. `_AVACreateRendererDVDExt` is a different, display-side table (overlay, subpicture, macrovision) and is not needed here.

**Design: drive the real pipeline through AppleVA with a real bitstream (option A).** The AVA front end that `AppleHDVCodec` uses is exported by AppleVA (and DVD Studio Pro's DVDBase references it): `AVAFLoadAllRenderers`, `AVAFGetGPURenderer(displayID)`, `AVAFCreateRenderer`, `AVAFQTInitDecoder(params)`, `AVAFQTDecodePicture(...)`. Feeding it a tiny MPEG-2 elementary stream makes Apple's own VLD (`AppleVADriverG5 FUN_00054070`, the producer) generate the records and coefficient dwords and hand them to the ATI renderer: real producer, real consumer, nothing of ours in the data path. The stream is generated with ffmpeg (an all-intra picture of one or two macroblocks with a known flat or two-level content, known quantiser) so the expected dwords can be predicted from `Tools/idct_stream.py` and compared. Option B (calling the renderer table slots with synthetic descriptors) is kept as the fallback; it needs the same arguments plus a hand-built 0x260-byte AppleVA picture structure.

**Safety design: default-deny interposer (the key change from the passive recorder).** `iokit_record_va.c` forwards everything. Rung 2 needs a new shim (`iokit_guard_va.c`) that forwards only an explicit allowlist to the kernel and answers everything else itself with a logged synthetic success:
| call | action | basis |
|---|---|---|
| IOServiceOpen type 3, Close | forward | proven live (T3 DVD tests) |
| selectors 1 get_config, 2 get_status, 0 set_surface (bound), 21 setup_buffers (bound), 20 check_stamps, 19 wait_for_stamps, 7 finish | forward | proven live on stock (baseline + T3 phase S); only with the Surface bound as the T3 tests do |
| IOConnectMapMemory type 1 initial map, types 4 and 5 initial maps, type 2 | forward the **first** map of each type only | type 1 proven (`t3_dvd_inject`); **types 4/5 and 2 are first live use** (they allocate the transfer buffers; GART mapping happens only in doIDCT) |
| IOConnectMapMemory type 1 re-map (= command-buffer submit) | **swallow**: return the existing mapping, log the buffer bytes | `process_command_buffer` has never run a real VA stream live; the injected-opcode attempts crashed the G5 four times (#124-#126) |
| IOConnectMapMemory types 4/5 re-map (stream ping-pong) | swallow, same way | kernel side effects not needed |
| selector 18 doIDCT | **swallow**: return 0, log params + the first 4 KB of both stream buffers | the point of the rung |
| selectors 4, 8, 9, 17 (lock_all_buffers, declare_image, delete_image, enable_deint) | forward only if proven in T3 with the same shapes, else swallow | decided in Step 2.0 against `Tests/destructive/t3_dvd_*` |
| 10-12, 14, 15, 16 (overlay, write_regs, subpicture, set_macrovision) and everything unlisted | swallow (write_regs and set_macrovision never forwarded) | register write / display side effects / panic when unbound |
The shim is itself tested first with the already-safe Surface `get_state` call (as `record_selftest.c` does) and with a no-op DVD open/close, before any AVA code runs.

**Steps.**
- 2.0 (static, no G5): resolve AppleVA's `AVAFQTInitDecoder` init-parameter struct (`numReferenceBuffers`, `numOutputBuffers`, NV12 buffer descriptors) and the decode-picture argument layout from `AVAFQTImpl.c`'s decompile; find out how `AVAFGetGPURenderer` chooses the ATI renderer (and whether it has a GPU allow-list of its own - the DVDPlayback list is a separate gate); classify every selector the real flow uses against the allowlist; write the harness `Tools/userspace/va_capture/ava_drive.c`.
- 2.1 (dev machine): build the test stream(s), compute the predicted dwords/params with `idct_stream.py`, write the comparison script.
- 2.2 (G5, at the console - a GUI-session process is needed for CoreGraphics; ssh-started GUI processes deadlock on this machine): preflight/peer-ack per #87, install the shim, run the harness with the allowlist, collect log + `.mem` dumps, postflight. Phase S, stock kext, one run per boot.
- 2.3: compare captured vs predicted; record results in this file; update findings sections 5-7 (anything that differs is a finding).
- Abort criteria: any kernel return not in the allowlist's expected set, a panic/hang (reboot protocol, issue), or AVA choosing the software renderer (then record why and stop - that is itself the answer to "can the stock stack reach this path").

**What this tells rung 3.** The real `set_surface` mode/flag arguments and surface properties, the buffer capacity and alignment as allocated by the kernel, the real `+0x14` flag word and its variation with picture type, and a captured packet to replay byte-for-byte (rung 3 can then use a stream the real producer made, not only our encoder's).

**Open risks.** (1) First live mapping of types 2/4/5 and the transfer-buffer allocation (moderate-low; no hardware engine involved). (2) AppleVA's own threading and async job handling may call selectors in orders the static read did not show (the allowlist makes unexpected calls harmless but may stall the harness - the log shows where). (3) `AVAFGetGPURenderer` may refuse the X1900 (AppleVA is the third place a GPU gate could live). (4) CoreGraphics requirements for the harness process. None involves the doIDCT hardware path or `process_command_buffer`.

**Decisions needed before 2.2 (not before 2.0/2.1):** approve the default-deny allowlist above (in particular forwarding the first maps of types 2/4/5), and approve a console session on the G5 for the capture run.

**Rung 2 - done (2026-10-04, Tools/userspace/va_capture/{iokit_guard_va.c,guard_selftest.c,ava_drive.c,gen_ava_vectors.py,compare_guard.py,install_guard_on_g5.sh,run_in_console.sh}; captures in captures/run_{open2,full}.*).**
2.0 resolved the call path: `AppleVA` exports `DVDDriverOpenDeviceImpl`/`DVDDriverDecodeImpl`; the GPU renderer is chosen by `AVAFGetGPURenderer` from the accelerator's `IODVDBundleName` property with no allow-list in AppleVA (DVDPlayback's flags/list are a separate gate that the harness bypasses by calling AppleVA directly);
the ATI renderer's open needs a real WindowServer window + surface (`CGSBindSurface` callback), so the harness runs in the console session (launched over ssh via `osascript ... Terminal do script`); `DVDDriverDecodeImpl` converts the DVD-driver coefficient layout in place (`FUN_97d83730`) and calls the renderer's `+0x34` (`FUN_00003930`).
2.1 built three pictures and the independent expectations. Shim self-test passed (proven calls only). Runs: `open` (SIGBUS after the first swallowed `declare_image`: zero handle; machine unaffected) -> shim fixed -> `open2` (open-only: clean) -> `full` (3 pictures: clean).
2.3 result: 4/4 doIDCT parameter blocks and 34/34 stream dwords match the predictions (findings section 9b). The only kernel traffic was 18 forwarded calls (open, get_config, map types 1/2/4/5 first maps, set_surface x3, setup_buffers x2, close) plus the 2D display-extension connection; 49 calls were swallowed.
Rung 3 now has: the real set-up recipe, a byte-exact packet the real producer path made, the buffer capacity (0x1fff8 dwords) and alignment as allocated by the kernel.

**Rung 3a - done (2026-10-04; captures/rung3/, Tests/destructive/results on the G5 under /tmp/rung3).** First forwarded `doIDCT` on stock: rc `0xe00002d8` (NotReady), no ring activity, no engine register changed, clean teardown (findings section 9c). Two harness events worth keeping: run `r3a` stayed fail-closed because the guard's swallow branch for selector 18 ran before the forwarding branch (fixed, commit 86aea52); the first window position (0,0)/(300,300) was hidden by the menu bar / the white Terminal (the window is white, so it must be placed on bare desktop, e.g. 800,500).
The Rung 3 questions (bit 0, bias/clipping, alt-scan, flag bits) are therefore still unanswered by hardware: the engine has not yet been given a destination.
Next (rung 3b, proposed, nothing run): (1) static: find what creates the overlay slots (`shape_surface` slot >= 10, `ATIR500Surface::dvd_setup_overlay`, the set_shape region fields, `CGSBindSurface` / WindowServer side); (2) check whether the harness' surface lacks them by reading the surface state through already-proven Surface calls; (3) only if a safe, proven way to give the surface overlay slots exists, repeat 3a. Forcing overlay hardware setup (`dvd_setup_overlay`/`dvd_enable_overlay`) is a display-hardware change beyond what rung 3 was approved for and is not proposed without a separate decision.
