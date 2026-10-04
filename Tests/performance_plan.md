# Performance measurement plan and stock baseline (issue #44)

Scope (per the 2026-10-02 scope decision on #41-#45): this file **defines** the benchmarks, the "no worse than" rule, the profiling method and the noise handling, and records the **stock** driver's baseline.
Running the same tooling against the rebuilt kext and iterating on regressions is #45. Nothing here loads the rebuilt kext.

## 1. What is measured (criterion 1)

| domain | metric family | tool | covers |
|---|---|---|---|
| kext external methods, all four contexts | `gl.*`, `2d.*`, `dvd.*`, `surface.*`: latency of one proven-safe call (user -> IOConnectMethod* -> method body -> back), p10 of 50 000 calls | `Tests/perf_methods.c` | per-selector cost, so a regression localises to a context and selector; includes two real MMIO register reads (`read_regs`, ~+0.7 us over a pure query) |
| connection lifecycle | `open_close.surface/gl/2d/dvd`: open + close one user client | `Tests/perf_methods.c` | allocation/teardown of each context object and its state |
| GL rendering path | `glcycle.*`: one create-context / pbuffer / clear / 100-triangle draw / readback / destroy cycle, per-phase median over 100 cycles | `Tests/perf_baseline.c` | the userspace GL driver + the kext's GL/Surface contexts together |
| 2D / compositing responsiveness (real desktop) | window move/resize/scroll frame times | **manual, not automated**: needs a person at the console (SSH-launched GUI apps deadlock); the 2D *context* is covered by `2d.*` above | see `Tests/consumer_scenarios.md` |
| DVD / video decode (IDCT throughput, dropped frames) | **not measurable on stock today**: QuickTime and DVD Player both decode in software on this machine (no DVD context is ever opened, `Tools/userspace/va_capture/`), and `doIDCT` has no safe valid call (#93). The DVD context is covered by `dvd.*` latency only | - | revisit when a client really uses the hardware IDCT path |

All calls are the ones `Tests/test_deep_t1.c` already asserts on stock: no surface binding, locking, flipping, submission or register writes.

## 2. Baseline numbers (criterion 2)

**Baseline of record: `Tests/baseline/perf/stock_4.1.9_g5_tiger_20261002_freshboot/`** - stock `com.apple.ATIRadeonX1000` 4.1.9, G5 2.5 GHz x4, Mac OS X 10.4.11, ATI X1900 (R580), one 1920x1080 display, collected minutes after a reboot
(login window / fresh session), 5 fresh-process repetitions 5 s apart (`env.txt`, `fingerprint.txt`, `run<k>_methods.txt`, `run<k>_gl.txt`; collected with `sh Tests/perf_collect.sh OUTDIR` on the G5).
Each number is the median over the 5 runs of the run's p10 (`perf_methods`) or median (`perf_baseline`); "noise" is (max - min) of the 5 run values / the median; "margin" is the regression threshold of section 3.

| metric | stock | noise | margin |
|---|---|---:|---:|
| `2d.get_config.sel1` | 3.51 us | 6.0 % | 18 % |
| `2d.get_surface_info.sel2` | 3.69 us | 5.7 % | 17 % |
| `2d.read_regs_1.sel16` | 4.32 us | 4.2 % | 12 % |
| `2d.read_regs_2.sel16` | 4.74 us | 1.3 % | 5 % |
| `dvd.check_stamps.sel20` | 3.51 us | 3.4 % | 10 % |
| `dvd.get_config.sel1` | 3.48 us | 5.2 % | 16 % |
| `dvd.get_status.sel2` | 3.48 us | 4.3 % | 13 % |
| `dvd.read_regs.sel13` | 4.32 us | 1.4 % | 5 % |
| `gl.get_config.sel3` | 3.75 us | 1.6 % | 5 % |
| `gl.get_hw_info.sel20` | 3.66 us | 4.1 % | 12 % |
| `gl.get_status.sel4` | 3.72 us | 4.0 % | 12 % |
| `glcycle.ChoosePixelFormat` | 33.00 us (1% of a 6.6 ms cycle) | 0.0 % | 5 % |
| `glcycle.Clear+Flush` | 192.00 us (3% of a 6.6 ms cycle) | 1.0 % | 5 % |
| `glcycle.CreateContext` | 1.95 ms (30% of a 6.6 ms cycle) | 1.0 % | 5 % |
| `glcycle.Draw100Tri+Flush` | 117.00 us (2% of a 6.6 ms cycle) | 0.9 % | 5 % |
| `glcycle.ReadPixels` | 1.51 ms (23% of a 6.6 ms cycle) | 1.3 % | 5 % |
| `glcycle.SetPBuffer` | 1.89 ms (29% of a 6.6 ms cycle) | 1.3 % | 5 % |
| `glcycle.Teardown` | 908.00 us (14% of a 6.6 ms cycle) | 2.6 % | 8 % |
| `open_close.2d` | 87.70 us | 0.7 % | 5 % |
| `open_close.dvd` | 149.59 us | 0.8 % | 5 % |
| `open_close.gl` | 279.83 us | 1.0 % | 5 % |
| `open_close.surface` | 61.83 us | 0.7 % | 5 % |
| `surface.get_state.sel2` | 3.54 us | 3.4 % | 10 % |
| `surface.query_lock.sel11` | 3.63 us | 0.8 % | 5 % |

GL cycle phases (where the time goes, criterion 4), share of a 6.6 ms cycle: CreateContext 30 %, SetPBuffer 29 %, ReadPixels 23 %, Teardown 14 %, Clear+Flush 3 %, Draw100Tri+Flush 2 %, ChoosePixelFormat 1 %.

### The baseline depends on machine state (found by comparing across a reboot)

An earlier set (`..._20261002/`, collected after ~10 h of uptime with the desktop session in use) compared against this fresh-boot set with `perf_compare.py`: the kext **method latencies are identical within 2.5 %**
(every `gl/2d/dvd/surface` per-call metric is OK), but several GL-cycle and lifecycle metrics moved: `Draw100Tri+Flush` 230 -> 117 us (**2.0x faster after the reboot**), `Teardown` -16 %,
`ReadPixels` -15 %, `open_close.gl` -8 %, `open_close.dvd` -5 %. Whatever accumulates over hours of uptime or in a used session (VRAM/GART fragmentation, window-server state, the display "kind" state of
`Tests/stability_regimen.md` section 5) slows the GL path while leaving the kext's method bodies unchanged. Consequences: (1) compare a candidate only with a baseline taken in the same state - a fresh boot is the
reference state; (2) the per-selector `perf_methods` metrics are the robust regression gate, the `glcycle.*` metrics are state-sensitive and need the same boot/session discipline; (3) the cross-boot spread of
`glcycle.*` (up to 2x) is far above the 5 % margin, so a rebuilt-kext run must be preceded by a fresh-boot stock run under the same session conditions, never compared with an old baseline.

## 3. "No worse than" (criterion 3) and noise (criterion 5)

`python3 Tools/perf_compare.py STOCKDIR CANDDIR` (>= 3 repetitions each; fewer is marked INDICATIVE). Per metric, with S = median over the stock runs and C = median over the candidate runs of the per-run value:

* noise = (max - min) of the stock run values / S, margin = **max(5 %, 3 x noise)**
* **REGRESSION** if C > S x (1 + margin) **and** C - S > floor (0.15 us for `perf_methods` metrics, 50 us for `glcycle.*`: the timer/IOKit resolution); **IMPROVED** if the mirror holds; otherwise **OK**
* a metric with margin > 25 % is **NOISY**: no conclusion, rerun on a quiet machine
* exit status 1 if any REGRESSION. `--self-test STOCKDIR` checks the rule on real data: stock vs other stock runs gives 0 regressions, a synthetic +20 % is REGRESSION, +4 % is OK.

Why 5 % at minimum: the stock metrics repeat within 1-6 %, so a 5 % floor with 3x the measured noise keeps false alarms rare while still catching the 10-20 % slowdowns a missing fast path or an extra lock would cause.
Comparisons are only valid like-with-like: same machine, same boot (a fresh boot is cleanest), same display state, nothing else running (`env.txt` records load and busy processes).

### The G5 dynamic-power-step trap (found while building this)

The first stock baseline (kept as `stock_4.1.9_g5_tiger_20261002_unwarmed_first_attempt/`) used 2000-call samples and showed an apparent **2x bimodality**: the same call measured 3.5 us in one run and 7.3 us in the next
(52-100 % "spread", which made the self-test report a false regression). A 50 000-call sample was uniformly fast, so it is a start-up transient of tens of ms after an idle gap. The cause is most likely the G5's dynamic power stepping (a ~2x clock step that ramps up under load); that is an inference from the
size and timing of the effect, not something measured directly (the clock was not read). Fix, now built in: `perf_methods` burns ~0.7 s of CPU before each group, takes 50 000 calls per metric and reports p10 as the headline (the fast-mode floor). After this every
metric's run-to-run spread is <= 6 %. Any new benchmark on this machine needs a warm-up and a long sample, or it measures the power governor.

## 4. Localising a regression (criterion 4)

1. Run `perf_compare.py`; the REGRESSION rows name the context and selector (`2d.read_regs_1.sel16`) or GL phase (`glcycle.SetPBuffer`).
2. A selector row -> the method body is the suspect: compare it with the stock body (`Tools/callee_compare.py`, `size_compare.py`, `imm_compare.py`, `Tests/body_triage.tsv`) - a missing fast path or an extra call/lock shows there. The per-call IOKit overhead
   (~3.5 us) is identical for stock and rebuilt, so differences are method time; `read_regs` vs `get_config` shows how an MMIO access scales.
3. A `glcycle.*` phase row -> phase share first (the table above; apply the `component-cost-profiling` method: optimise/inspect the largest share), then `open_close.gl` / `2d.*` / `surface.*` to see whether the kext side moved or the userspace GL driver did.
4. Function-level timing inside the rebuilt kext needs kernel instrumentation (timestamps around suspect calls via `mach_absolute_time` in a debug build) and is part of #45's iterate loop, not set up here.

## 5. Not covered yet (and why)

* Heavier method bodies (surface bind, lock, swap, scaling, texture allocation) are not timed: they are the destructive/T3 calls, one per boot by protocol #87, and cannot be looped safely. A timing for those would be a single-shot number per boot, too noisy to gate on.
* Real GL application frame times and desktop compositing: manual runs at the console (section 1).
* 2D and DVD hardware throughput: no safe workload exists (section 1).

## 6. Feature-level GL cost (added after issue #128's 62-test correctness sweep)

The domains above time one GENERIC rendering path (a plain 100-triangle draw). They say nothing about whether any of the SPECIFIC GL features #128 correctness-tested (blend modes, texture combine chains, shadow sampling, texture compression, texgen, lighting, GLSL/ARB compile, FBO switching, display lists, VBO vs client arrays) costs more than a plain draw - a feature can be correct and pathologically slow and #128's tests would never catch it. `Tests/userspace/perf_gl_features.c` and `Tests/userspace/perf_gl_pipeline.c` close that gap, same methodology (mach_absolute_time, warmup, N timed repetitions, p10 headline, same `METRIC` line format).

**Baseline of record** (stock 4.1.9, same G5/display/session conditions as section 2; 3 repetitions, `Tests/baseline/perf/gl_features_pipeline_20261004/`). Each number is the median over 3 runs of that run's p10; noise is (max-min)/median across the 3 runs - every metric below came in under 1% noise, well inside the existing 5%-floor margin rule in section 3, so no change to that rule was needed.

Per-draw feature cost, `perf_gl_features.c`, 64x64 pbuffer, single quad, p10 median over 3000-draw samples:

| metric | stock | noise | notes |
|---|---:|---:|---|
| `gl.baseline.flatcolor` | 122.05 us | 0.3 % | reference: every other row below is read relative to this |
| `gl.blend.srcalpha` | 122.14 us | 0.2 % | +0.1 us over baseline - free at this scale |
| `gl.blend.equation_func_separate` | 122.14 us | 0.2 % | separate func+equation costs the same as plain blend |
| `gl.fog.linear` | 124.12 us | 0.4 % | +2.1 us over baseline - the one fixed-function-only metric with a real, measurable cost |
| `gl.stencil.funcop` | 122.02 us | 0.4 % | free |
| `gl.alphatest` | 122.11 us | 0.4 % | free |
| `gl.tex2d.modulate` | 124.24 us | 0.4 % | +2.2 us - baseline texture-sampling cost, every other `gl.tex.*`/`gl.texgen.*` row below is close to this, not stacking further |
| `gl.tex2d.dot3combine` | 124.27 us | 0.4 % | same as plain modulate - combine mode doesn't change the cost |
| `gl.tex.multiunit2.modulate_add` | 124.36 us | 0.5 % | a second texture unit adds nothing measurable beyond the first |
| `gl.tex.cubemap` | 124.15 us | 0.6 % | same as 2D texturing |
| `gl.tex.3d` | 124.06 us | 0.6 % | same as 2D texturing |
| `gl.tex.s3tc_dxt1` | 124.06 us | 0.5 % | compressed sampling costs the same as uncompressed at this texture size |
| `gl.tex.shadow_compare` | 124.36 us | 0.6 % | the depth-compare path costs the same as a normal texture sample |
| `gl.texgen.objectlinear` | 121.96 us | 0.5 % | free - no measurable cost over the non-textured baseline |
| `gl.lighting.onelight` | 124.18 us | 0.5 % | +2.1 us, same order as the texturing/fog cost |

Reading this table: on this hardware at this scale, essentially all of the real per-draw cost comes from just THREE things being active at all - texturing (any kind), fog, or lighting (each ~+2 us flat) - and none of the specific MODE within those categories (which blend equation, which combine mode, which texture target, compressed vs not, shadow-compare vs not) costs anything extra once that category is paid for. No feature found here is disproportionately expensive relative to its own category.

One-shot/setup-phase costs, `perf_gl_pipeline.c`, p10 median over 3 runs:

| metric | stock | noise | notes |
|---|---:|---:|---|
| `gl.glsl.compile_link` | 582.67 us | 0.6 % | n=200/run (capped - compiling is far more expensive than a draw) |
| `gl.arbfp.parse` | 56.79 us | 0.3 % | **ARB assembly program parsing is ~10x cheaper than GLSL compile+link** for a comparable single-texture-sample shader - a real, substantial difference worth knowing before choosing a shading path for anything compiled at load time or runtime on this hardware |
| `gl.fbo.bind_unbind_roundtrip` | 125.08 us | 0.2 % | bind+unbind+finish, no draw - about the same cost as one textured quad draw |
| `gl.displaylist.compile_100tri` | 47.19 us | 0.5 % | compiling the list is cheaper than either replaying it or drawing it immediately |
| `gl.displaylist.replay_100tri` | 146.71 us | 0.3 % | |
| `gl.immediate.draw_100tri` | 147.73 us | 0.4 % | display-list replay is only about 0.7% faster than immediate mode for this workload - a negligible, not a real, advantage on this driver at this geometry size |
| `gl.client_array.draw_100tri` | 123.34 us | 0.4 % | |
| `gl.vbo.draw_100tri` | 122.32 us | 0.2 % | VBO is about 0.8% faster than a client array for the identical draw - real but small at this geometry size; correctness of this exact comparison was separately confirmed identical in `gl_feature_vbo_correctness_test.c` (#128) |

Not covered here either (same reasons as section 5): any of this at a GEOMETRY SIZE large enough to be GPU-bound rather than dominated by the fixed per-draw/per-call overhead visible above - all these numbers are measuring a tiny (64x64, ~100-triangle) workload on purpose, matching this project's existing `glcycle.*` convention, not a real scene's throughput. Section 7 covers that scaling question directly, plus the rest of the gaps section 6 left behind.

## 7. Upload/pixel-transfer cost, state-change cost, batching, and scale (closes the remaining #44 gaps from section 6)

Three more benchmark programs, same methodology, baseline of record `Tests/baseline/perf/gl_upload_statechange_scale_20261004/` (3 repetitions each, noise <1% on every metric except `tricount.20000` at ~2.9%, still well inside the 25% noisy-metric threshold from section 3).

**`Tests/userspace/perf_gl_upload.c`** - texture upload and pixel-transfer-op cost, never measured before (p10 median over 300 iterations, 64x64 pbuffer unless noted):

| metric | stock | noise | notes |
|---|---:|---:|---|
| `gl.teximage2d.16x16` | 25.29 us | 0.0 % | |
| `gl.teximage2d.64x64` | 419.37 us | 0.2 % | 16x more texels than 16x16, ~16.6x slower - upload cost scales essentially linearly with pixel count |
| `gl.teximage2d.256x256` | 6570.46 us | 0.2 % | 16x more texels than 64x64, ~15.7x slower - same linear scaling holds |
| `gl.teximage2d.64x64.plain` | 419.16 us | 0.1 % | re-measured alongside the PBO comparison below |
| `gl.teximage2d.64x64.pbo` | 416.04 us | 0.0 % | **PBO-backed upload is about 0.7% faster than plain client-memory upload** - small but consistent across all 3 runs, a real if modest win |
| `gl.teximage2d.64x64.automipmap` | 477.64 us | 0.3 % | **+58.5 us (+14%) over plain upload** to auto-generate the full mip chain - a real, worth-knowing cost; correctness of the generated chain was confirmed in #128's `gl_feature_automipmap_test.c` |
| `gl.drawpixels.16x16` | 211.25 us | 0.6 % | |
| `gl.copypixels.16x16` | 279.11 us | 0.1 % | +32% over DrawPixels at the same size |
| `gl.readpixels.16x16` | 126.37 us | 0.1 % | cheapest of the three at this size |
| `gl.drawpixels.64x64` | 215.42 us | 0.5 % | barely more than the 16x16 case - DrawPixels is not size-bound at this scale |
| `gl.copypixels.64x64` | 700.70 us | 0.5 % | **+2.5x over the 16x16 CopyPixels case** for only a 16x pixel-count increase - CopyPixels is clearly bandwidth-bound here in a way DrawPixels/ReadPixels are not; it is also the single most expensive of the three pixel-transfer paths at every size tested |
| `gl.readpixels.64x64` | 132.46 us | 0.1 % | barely more than the 16x16 case, same pattern as DrawPixels |

**`Tests/userspace/perf_gl_statechange.c`** - state-change cost, batching benefit, context-switch cost, query/fence overhead (each "x10" metric is 10 real draws plus `glFinish()`, p10 median over 300 iterations):

| metric | stock | noise | notes |
|---|---:|---:|---|
| `gl.statechange.tex_bind.same_x10` | 126.88 us | 0.2 % | baseline: 10 draws, texture bound once |
| `gl.statechange.tex_bind.alternate_x10` | 143.35 us | 0.3 % | +16.5 us for 10 switches = **~1.6 us per texture bind** |
| `gl.statechange.program.same_x10` | 125.23 us | 0.5 % | baseline: 10 draws, one GLSL program bound once |
| `gl.statechange.program.alternate_x10` | 177.25 us | 0.2 % | +52.0 us for 10 switches = **~5.2 us per `glUseProgram` switch - the most expensive state change measured, more than 3x the cost of a texture bind** |
| `gl.statechange.blendfunc.same_x10` | 125.02 us | 0.5 % | baseline: 10 draws, blend func set once |
| `gl.statechange.blendfunc.alternate_x10` | 134.02 us | 0.5 % | +9.0 us for 10 switches = **~0.9 us per `glBlendFunc` call - the cheapest state change measured** |
| `gl.batching.loop_drawarrays_x10` | 123.97 us | 0.4 % | 10 separate `glDrawArrays` calls |
| `gl.batching.multidrawarrays_x10` | 123.85 us | 0.4 % | one `glMultiDrawArraysEXT` covering the same 10 sub-ranges - **no measurable benefit over the naive loop** (the two are within each other's noise) |
| `gl.context_switch.roundtrip` | 0.12 us | 0.0 % | `CGLSetCurrentContext` between two live contexts - **essentially free**, a pure CPU-side pointer update with no GPU synchronization |
| `gl.occlusionquery.roundtrip` | 228.86 us | 0.3 % | begin query + one draw + end query + fetch result |
| `gl.fence.set_finish_roundtrip` | 122.05 us | 0.2 % | set + finish after an already-submitted draw - cheaper than the occlusion-query round trip, which also includes its own draw |

**`Tests/userspace/perf_gl_scale.c`** - does any of this scale differently once the GPU is doing real work? (p10 median over 100 iterations; each group isolates one axis, holding the others fixed)

| metric | stock | noise | notes |
|---|---:|---:|---|
| `gl.scale.fullscreenquad.64x64` | 122.05 us | 0.4 % | flat-color quad filling the whole viewport |
| `gl.scale.fullscreenquad.256x256` | 122.05 us | 0.4 % | identical to 64x64 - **fill rate is not the bottleneck up to this size** |
| `gl.scale.fullscreenquad.512x512` | 122.32 us | 0.8 % | still identical |
| `gl.scale.fullscreenquad.1024x1024` | 225.83 us | 0.3 % | **cost roughly doubles crossing the 512->1024 boundary** - the first size tested where fill rate (or some other viewport-size-dependent cost) actually shows up |
| `gl.scale.texsample.16x16` | 124.21 us | 0.5 % | textured quad, fixed 256x256 viewport, increasing SOURCE texture size |
| `gl.scale.texsample.64x64` | 124.21 us | 0.3 % | identical |
| `gl.scale.texsample.256x256` | 124.27 us | 0.4 % | identical |
| `gl.scale.texsample.512x512` | 124.36 us | 0.4 % | **completely flat from 16x16 to 512x512 - texture cache/bandwidth is not a bottleneck at this draw scale, source texture size essentially does not matter** |
| `gl.scale.tricount.100` | 129.46 us | 0.3 % | fixed 256x256 viewport, increasing triangle count in one draw call |
| `gl.scale.tricount.1000` | 299.87 us | 0.2 % | 10x the triangles, only 2.3x the time - sub-linear, per-triangle submission cost dominates at low counts |
| `gl.scale.tricount.5000` | 1049.93 us | 0.3 % | 5x the triangles (from 1000), 3.5x the time |
| `gl.scale.tricount.20000` | 2896.35 us | 2.9 % | 4x the triangles (from 5000), 2.76x the time - **triangle count is the one axis tested here that scales clearly and substantially, unlike viewport fill or texture size**; this is also the noisiest metric found in any perf_gl_*.c file so far, still well under the 25% noisy-metric threshold |

**What this settles from section 6's gap list:** texture upload cost, PBO-vs-plain upload, auto-mipmap generation cost, pixel-transfer-op cost at more than one size, state-change cost (texture/program/blend), multi-draw-arrays batching benefit, context-switch cost, occlusion-query and fence overhead, and GPU-bound-at-scale behavior across three independent axes (viewport fill, texture size, triangle count) are now all measured with a recorded stock baseline.

**Still not covered, for the same structural reasons as section 5:** heavier kext method bodies (T3 destructive calls, one-shot per boot, cannot be safely looped into a stable number), 2D/DVD hardware throughput (no safe workload - the DVD context is never opened by any real consumer on this machine), and real desktop compositing/app frame times (needs a human at the console, SSH-launched GUI apps deadlock per the `tiger-ssh` skill).
