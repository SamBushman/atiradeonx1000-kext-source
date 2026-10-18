# Phase S (stock kext 4.1.9, G5 Tiger) results of the T3 tests - issue #100 / protocol #87

One run per test through `Tests/destructive/run_t3.sh` (preflight -> test -> postflight; kextstat, volumes, displays and registers unchanged in every run; the stock normal and `--deep` baselines
were IDENTICAL after a reboot at the end). Outcome class for every test: **PASS** (return codes as predicted by the static trace), except where noted. Phase R (rebuilt kext) is tracked in #122.

| issue | selector(s) | test | result on stock |
|---|---|---|---|
| #101 | 2D lock_memory (5) | t3_2d_lock_unlock | unbound -> CannotLock; bound -> 0, address 0x3810000, size 0x100 (twice, identical); unlock_memory(0) -> 0 |
| #102 | DVD lock_all_buffers (4), unlock_memory (5) | t3_dvd_lock_buffers | unbound -> CannotLock; after setup_buffers(0,0,16,16,0x7ffc00): 0, 256-byte output, **all 13 {address, pitch} pairs zero** (no buffer memory allocated for this minimal surface); unlock -> 0 |
| #103 | GL read_buffer (7) | t3_gl_read_buffer | run 1 (set_surface mode 0): CannotLock (EXPECTED-REJECT, requirement mask has no front-buffer bit); run 2 (mode 0x800): 0, 16 bytes written (4 rows x 4, first row ff ff ff ff), 0 bytes outside the rectangle |
| #104 | GL new_texture (10) | t3_gl_textures | typeTag 2, size 0x1000 -> 0, out0 0xa000, out1 0xc000, texture id 0 (found by purge probe) |
| #105 | GL become_global_shared (12) | t3_gl_global_shared | release unowned -> CannotLock; claim -> 0; claim again -> CannotLock; release -> 0; release again -> CannotLock |
| #106 | GL page_off_texture (13) | t3_gl_textures | page_off_texture(id, 0) -> 0 (nothing dirty to page); delete -> 0, second delete and purge-after-delete -> BadArgument |
| #107 | GL scale_surface (14) | t3_scaling | unbound -> Unsupported; bound, flags 3, 4x4 identity -> 0 |
| #108 | GL set_surface_volatile_state (16) | t3_volatile_state | bound: 1 -> 0, 0 -> 0 |
| #109 | GL reclaim_resources (17) | t3_gl_reclaim | data-buffer offset out0 0xa000 -> 0x1a000 -> 0x2a000 over three get_data_buffer, back to 0xa000 after reclaim; out1 0x10000 throughout |
| #110 | 2D swap_surface (3) | t3_2d_swap | unbound -> NoResources; bound -> 0, tag 0; screenshots before/after byte-identical |
| #111 | 2D scale_surface (4) | t3_scaling | bound, flags 3, 4x4 -> 0 |
| #112 | 2D unlock_memory (6) | t3_2d_lock_unlock, t3_2d_unlock_swap | lockType 0 -> 0; lockType 0x80000000 (unlock then swap_surface) -> 0, tag 0 |
| #113 | 2D create_transfer (10) | t3_2d_images | (0, 0x1000) -> 0, handle 0xa000, addr 0xc000; freed by delete_image |
| #114 | 2D write_regs (17) | t3_2d_write_regs | CONFIG_MEMSIZE (0xf8) read 0x10000000, byte count 4 -> BadArgument, write {0xf8, 0x10000000} -> 0, read-back 0x10000000 |
| #115 | 2D write_2_regs (18) | t3_2d_write_2_regs | same sequence through the two-register form -> 0, read-back unchanged |
| #116 | Surface surface_read (5) | t3_surface_read | after 2D bind+lock+unlock: 0, 16 bytes written (ff ff ff ff per row), 0 outside the 4x4 rectangle |
| #117 | Surface set_scale (8) | t3_scaling | disabled path 0; enable with the identity IOAccelSurfaceScaling (0x2c bytes, flags 2) -> 0; disable again -> 0 |
| #118 | Surface surface_control (16) / alias (18) | t3_volatile_state | selector 1 (blocking) 1 and 0 -> 0 (it never sleeps); selector 2 -> BadArgument; selector 4 (volatile) 1 and 0 -> 0 through both entries; get_state 0x1 |
| #119 | 2D create_image (9), wait_image (12), delete_image (11), declare_image (8) | t3_2d_images, t3_2d_declare_image | create_image(0x1000, 0) -> 0, id 0; wait/delete -> 0; second delete and wait-after-delete -> BadArgument; wait before any allocator -> NoResources; declare_image(0, user addr, 0x1000) -> 0, user buffer untouched |
| #120 | DVD declare_image (8), delete_image (9) | t3_dvd_images | delete before declare -> NoResources; declare -> 0; delete -> 0; second delete -> BadArgument; user buffer untouched |
| #121 | Surface set_shape_backing (6) | t3_surface_backing | connect (addr, pitch 64) -> 0; disconnect (0, 0) -> 0; user buffer untouched; the sel 17 `param5 < param4*dim` Error was already observed (deep suite) |

Not covered by a T3 run (they are #88-#97 under #87, never run so far): DVD write_regs/write_buffer/set_macrovision/doIDCT, 2D set_macrovision, GL set_stereo, Surface lock variants and flush.

## #88-#97 (the ten destructive-protocol methods), Phase S on stock

| issue | selector | test | result on stock |
|---|---|---|---|
| #88 | GL set_stereo (19) | t3_gl_set_stereo | wire order from the vendor call site (scalar 0 = mode, scalar 1 = panel). mode 0 on panels 0 and 1 -> 0 (no-op). The ENABLE (allocates per-panel VRAM, walks all surfaces, #32 loop) was NOT run |
| #89 | 2D set_macrovision (15) | t3_2d_macrovision | attribute 0x92: Phase A (0) -> 0 (a display accepted it), Phase B (1) -> 0, Phase C (0) restore -> 0; screenshots identical |
| #90 | DVD set_macrovision (16) | t3_dvd_macrovision | vendor pair (0x92, value) from the VA bundle wrapper at 0x5280; bound surface, (0x92, 0) -> 0. No enable phase; the unbound call (the #43 panic) was never made |
| #91 | DVD write_regs (14) | t3_dvd_write_regs | Phase A: CONFIG_MEMSIZE read 0x10000000, write the same value -> 0, read-back identical. Phase B (flip bits of a scratch register) NOT run: no register proven side-effect-free (SCRATCH_REG0-5 at 0x15e0-0x15f4 are the kext's stamp registers) |
| #92 | DVD write_buffer (6) | t3_dvd_write_buffer | bound + setup_buffers: bufferSelect 0 and 1 -> 0 as a no-op (the slot has no backing record, so no DMA path was reached); the user source buffer untouched. Unbound call never made (NULL-deref panic) |
| #93 | DVD doIDCT (18) | (valid path NOT run) t3_dvd_idct_lock_leak for Phase C | the valid IDCT submission programs the GPU with caller-supplied coefficient/destination addresses from a real macroblock stream: no safe evidence-derived stream exists offline, so Phase A/B are not run. Phase C: see the issue |
| #94 | Surface write_lock_options (3) | t3_surface_locks | **lockOptions 0 on the baseline surface PANICKED the stock kernel (#123)**; lockOptions 3 -> 0 (pending tail: data[0]=0, 1920x1080 data in state A); lockOptions 1 -> 0 with data[0] = 0x3018000, data[4] (pitch) 0x1e00 in state A, 0x3812000 / 0x100 for the 4x4 surface (state B); unlock and query_lock clean in every case |
| #95 | Surface read_lock (12) | t3_surface_read_lock | run 2026-10-02 (the static prediction of the #123 panic path was wrong for state A): -> 0, data[0] 0x3018000, pitch 0x1e00 (same as write_lock in state A), unlock sel 1 -> 0, query_lock -> 0; no panic, displays/registers unchanged. PASS |
| #96 | Surface write_lock (14) | t3_surface_locks | -> 0, data[0] 0x3018000, pitch 0x1e00 (state A); 0x3812000 / 0x100 (state B); unlock sel 15 -> 0 |
| #97 | Surface surface_flush (10) | t3_surface_flush | Phase A (a=0) -> 0; Phase B (a=1, b=0, surface with memory, 2D-bound) -> 0; again -> 0; no allocation phase needed |

### Follow-up runs
* **#90 enable/restore** (t3_dvd_macrovision run 2): bound surface, (0x92, 1) -> 0, restore (0x92, 0) -> 0 (same as the 2D version in #89).
* **#91 Phase B** (t3_dvd_write_regs_scratch): SCRATCH_REG5 (0x15f4) with evidence (SCRATCH_UMSK 0x0770 = 0xff, SCRATCH_ADDR 0x0774 = 0x10005000, REG0 = stamp counter, REG1 = GL driver, REG2-5 = 0; kext only zeroes them at init; GL/VA bundles reference only 0x15e4): write 0 -> 0, write 0x5a5a5a5a -> 0, read-back exactly 0x5a5a5a5a, restore 0 -> 0, read-back 0; REG0 kept counting. PASS.
* **#88 enable, #98/#99/#32/#123 live work:** not run (stock-bug / hang-prone paths; skipped on the user's instruction and after repeated safety-check stops).
* **#88 enable** (t3_gl_set_stereo_enable, run on the user's instruction): `set_stereo(mode 1, panel 0)` -> `0xe00002bd` (NoMemory: the traced `setup_stereo` branch where the per-panel stereo record cannot be allocated, `-0x1ffffd43`); restore `set_stereo(0, 0)` -> 0; no hang, no panic, displays and registers unchanged. Outcome class **EXPECTED-REJECT** (the test's own state file says DIVERGENCE because it expected the enable to succeed).
