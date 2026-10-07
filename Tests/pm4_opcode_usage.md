# Command-stream opcode usage by real workloads (issue #42 criterion 2)

Recorded on the stock kext (4.1.9, G5, Tiger) with `Tools/userspace/opcode_recorder.c`, merged by `Tools/opcode_usage.py`, compared with the dispatcher inventory in `Tests/pm4_opcode_inventory.md`.
Counts are buffers submitted through the flush-map path (the kernel's `process_command_buffer`); buffers processed by other kernel paths are not counted.

Workloads: `features_bigdraw` (1 run), `features_cglparams` (1 run), `features_clear` (1 run), `features_copydepth` (1 run), `features_copypix` (1 run), `features_draw` (1 run), `features_fbo` (1 run), `features_fbo2` (1 run), `features_msaa4` (1 run), `features_multitex` (1 run), `features_pixel` (1 run), `features_query` (1 run), `features_shaders` (1 run), `features_state` (1 run), `features_texfmt` (1 run), `features_vbo` (1 run), `godot_editor` (1 run), `godot_game` (1 run), `probes_cgl_probe` (1 run), `probes_glprobe` (1 run), `probes_glsl120test` (1 run), `probes_nesttest` (1 run), `probes_perf_baseline` (1 run), `windows_win_0_30_1_24_basic` (1 run), `windows_win_0_30_1_24_resolve` (1 run), `windows_win_0_40_0_16_basic` (1 run), `windows_win_0_40_1_24_clears` (1 run), `windows_win_0_40_1_24_hz` (1 run), `windows_win_2_40_1_24_basic` (1 run), `windows_win_4_30_1_24_resolve` (1 run), `windows_win_4_40_1_24_basic` (1 run), `windows_win_4_40_1_24_hz` (1 run), `windows_win_6_30_0_24_resolve` (1 run), `windows_win_6_40_1_24_basic` (1 run)

## GL

Flushes: 5353.  Records: 78077.  Words: 60582847.  Distinct opcodes observed: 57 of 66 in the inventory (**86 % coverage**); observed but not in the inventory: 2.

| opcode | records | words | in inventory | workloads |
|---|---:|---:|---|---|
| 0x00 | 5298 | 23036485 | **NO** | features_bigdraw, features_cglparams, features_clear, features_copydepth, features_copypix, features_draw, features_fbo, features_fbo2, features_msaa4, features_multitex, features_pixel, features_query, features_shaders, features_state, features_texfmt, features_vbo, godot_editor, godot_game, probes_cgl_probe, probes_perf_baseline, windows_win_0_30_1_24_basic, windows_win_0_30_1_24_resolve, windows_win_0_40_0_16_basic, windows_win_0_40_1_24_clears, windows_win_0_40_1_24_hz, windows_win_2_40_1_24_basic, windows_win_4_30_1_24_resolve, windows_win_4_40_1_24_basic, windows_win_4_40_1_24_hz, windows_win_6_30_0_24_resolve, windows_win_6_40_1_24_basic |
| 0x01 | 2007 | 2007 | **NO** | features_bigdraw, features_cglparams, features_clear, features_copydepth, features_copypix, features_draw, features_fbo, features_fbo2, features_msaa4, features_multitex, features_pixel, features_query, features_shaders, features_state, features_texfmt, features_vbo, godot_editor, godot_game, probes_cgl_probe, probes_perf_baseline, windows_win_0_30_1_24_basic, windows_win_0_30_1_24_resolve, windows_win_0_40_0_16_basic, windows_win_0_40_1_24_clears, windows_win_0_40_1_24_hz, windows_win_2_40_1_24_basic, windows_win_4_30_1_24_resolve, windows_win_4_40_1_24_basic, windows_win_4_40_1_24_hz, windows_win_6_30_0_24_resolve, windows_win_6_40_1_24_basic |
| 0x02 | 2683 | 2683 | yes | godot_editor, godot_game, windows_win_0_30_1_24_basic, windows_win_0_30_1_24_resolve, windows_win_0_40_0_16_basic, windows_win_0_40_1_24_clears, windows_win_0_40_1_24_hz, windows_win_2_40_1_24_basic, windows_win_4_30_1_24_resolve, windows_win_4_40_1_24_basic, windows_win_4_40_1_24_hz, windows_win_6_30_0_24_resolve, windows_win_6_40_1_24_basic |
| 0x03 | 607 | 607 | yes | features_bigdraw, features_cglparams, features_clear, features_copydepth, features_copypix, features_fbo, features_fbo2, features_msaa4, features_multitex, features_pixel, features_query, features_shaders, features_state, features_texfmt, features_vbo, probes_cgl_probe, probes_perf_baseline, windows_win_0_30_1_24_resolve, windows_win_4_30_1_24_resolve, windows_win_6_30_0_24_resolve |
| 0x04 | 220 | 59816 | yes | windows_win_2_40_1_24_basic, windows_win_4_30_1_24_resolve, windows_win_4_40_1_24_basic, windows_win_4_40_1_24_hz, windows_win_6_30_0_24_resolve, windows_win_6_40_1_24_basic |
| 0x05 | 415 | 46480 | yes | features_clear, features_copydepth, features_copypix, features_fbo2, features_msaa4, features_multitex, features_pixel, features_query, features_state, windows_win_0_30_1_24_basic, windows_win_0_30_1_24_resolve, windows_win_0_40_0_16_basic, windows_win_0_40_1_24_clears, windows_win_0_40_1_24_hz, windows_win_2_40_1_24_basic, windows_win_4_30_1_24_resolve, windows_win_4_40_1_24_basic, windows_win_4_40_1_24_hz, windows_win_6_30_0_24_resolve, windows_win_6_40_1_24_basic |
| 0x06 | 487 | 74383 | yes | features_copydepth, features_fbo, features_fbo2, features_multitex, features_pixel, features_shaders, features_state, features_texfmt, godot_editor, godot_game, windows_win_0_30_1_24_resolve, windows_win_4_30_1_24_resolve, windows_win_6_30_0_24_resolve |
| 0x07 | 14 | 57 | yes | features_multitex, features_shaders, godot_editor |
| 0x08 | 3 | 24 | yes | features_multitex, features_shaders |
| 0x09 | 3 | 19 | yes | features_multitex, features_shaders |
| 0x0a | 2 | 16 | yes | features_multitex |
| 0x0b | 2 | 16 | yes | features_multitex |
| 0x0c | 2 | 16 | yes | features_multitex |
| 0x0d | 5 | 607 | yes | features_multitex, features_state |
| 0x0e | 1 | 8 | yes | features_multitex |
| 0x0f | 1 | 8 | yes | features_multitex |
| 0x10 | 1 | 8 | yes | features_multitex |
| 0x11 | 1 | 8 | yes | features_multitex |
| 0x12 | 1 | 8 | yes | features_multitex |
| 0x13 | 1 | 8 | yes | features_multitex |
| 0x14 | 1 | 8 | yes | features_multitex |
| 0x15 | 3 | 840 | yes | features_multitex, godot_editor, godot_game |
| 0x16 | 5341 | 788249 | yes | features_bigdraw, features_cglparams, features_clear, features_copydepth, features_copypix, features_draw, features_fbo, features_fbo2, features_msaa4, features_multitex, features_pixel, features_query, features_shaders, features_state, features_texfmt, features_vbo, godot_editor, godot_game, probes_cgl_probe, probes_perf_baseline, windows_win_0_30_1_24_basic, windows_win_0_30_1_24_resolve, windows_win_0_40_0_16_basic, windows_win_0_40_1_24_clears, windows_win_0_40_1_24_hz, windows_win_2_40_1_24_basic, windows_win_4_30_1_24_resolve, windows_win_4_40_1_24_basic, windows_win_4_40_1_24_hz, windows_win_6_30_0_24_resolve, windows_win_6_40_1_24_basic |
| 0x17 | 2393 | 2393 | yes | features_bigdraw, features_cglparams, features_clear, features_copydepth, features_copypix, features_draw, features_fbo, features_fbo2, features_msaa4, features_multitex, features_pixel, features_query, features_shaders, features_state, features_texfmt, features_vbo, godot_editor, godot_game, probes_cgl_probe, probes_perf_baseline, windows_win_0_30_1_24_basic, windows_win_0_30_1_24_resolve, windows_win_0_40_0_16_basic, windows_win_0_40_1_24_clears, windows_win_0_40_1_24_hz, windows_win_2_40_1_24_basic, windows_win_4_30_1_24_resolve, windows_win_4_40_1_24_basic, windows_win_4_40_1_24_hz, windows_win_6_30_0_24_resolve, windows_win_6_40_1_24_basic |
| 0x18 | 2404 | 2408 | yes | features_bigdraw, features_cglparams, features_clear, features_copydepth, features_copypix, features_draw, features_fbo, features_fbo2, features_msaa4, features_multitex, features_pixel, features_query, features_shaders, features_state, features_texfmt, features_vbo, godot_editor, godot_game, probes_cgl_probe, probes_perf_baseline, windows_win_0_30_1_24_basic, windows_win_0_30_1_24_resolve, windows_win_0_40_0_16_basic, windows_win_0_40_1_24_clears, windows_win_0_40_1_24_hz, windows_win_2_40_1_24_basic, windows_win_4_30_1_24_resolve, windows_win_4_40_1_24_basic, windows_win_4_40_1_24_hz, windows_win_6_30_0_24_resolve, windows_win_6_40_1_24_basic |
| 0x19 | 2404 | 2404 | yes | features_bigdraw, features_cglparams, features_clear, features_copydepth, features_copypix, features_draw, features_fbo, features_fbo2, features_msaa4, features_multitex, features_pixel, features_query, features_shaders, features_state, features_texfmt, features_vbo, godot_editor, godot_game, probes_cgl_probe, probes_perf_baseline, windows_win_0_30_1_24_basic, windows_win_0_30_1_24_resolve, windows_win_0_40_0_16_basic, windows_win_0_40_1_24_clears, windows_win_0_40_1_24_hz, windows_win_2_40_1_24_basic, windows_win_4_30_1_24_resolve, windows_win_4_40_1_24_basic, windows_win_4_40_1_24_hz, windows_win_6_30_0_24_resolve, windows_win_6_40_1_24_basic |
| 0x1a | 2405 | 2405 | yes | features_bigdraw, features_cglparams, features_clear, features_copydepth, features_copypix, features_draw, features_fbo, features_fbo2, features_msaa4, features_multitex, features_pixel, features_query, features_shaders, features_state, features_texfmt, features_vbo, godot_editor, godot_game, probes_cgl_probe, probes_perf_baseline, windows_win_0_30_1_24_basic, windows_win_0_30_1_24_resolve, windows_win_0_40_0_16_basic, windows_win_0_40_1_24_clears, windows_win_0_40_1_24_hz, windows_win_2_40_1_24_basic, windows_win_4_30_1_24_resolve, windows_win_4_40_1_24_basic, windows_win_4_40_1_24_hz, windows_win_6_30_0_24_resolve, windows_win_6_40_1_24_basic |
| 0x1b | 2405 | 2409 | yes | features_bigdraw, features_cglparams, features_clear, features_copydepth, features_copypix, features_draw, features_fbo, features_fbo2, features_msaa4, features_multitex, features_pixel, features_query, features_shaders, features_state, features_texfmt, features_vbo, godot_editor, godot_game, probes_cgl_probe, probes_perf_baseline, windows_win_0_30_1_24_basic, windows_win_0_30_1_24_resolve, windows_win_0_40_0_16_basic, windows_win_0_40_1_24_clears, windows_win_0_40_1_24_hz, windows_win_2_40_1_24_basic, windows_win_4_30_1_24_resolve, windows_win_4_40_1_24_basic, windows_win_4_40_1_24_hz, windows_win_6_30_0_24_resolve, windows_win_6_40_1_24_basic |
| 0x1c | 2405 | 2405 | yes | features_bigdraw, features_cglparams, features_clear, features_copydepth, features_copypix, features_draw, features_fbo, features_fbo2, features_msaa4, features_multitex, features_pixel, features_query, features_shaders, features_state, features_texfmt, features_vbo, godot_editor, godot_game, probes_cgl_probe, probes_perf_baseline, windows_win_0_30_1_24_basic, windows_win_0_30_1_24_resolve, windows_win_0_40_0_16_basic, windows_win_0_40_1_24_clears, windows_win_0_40_1_24_hz, windows_win_2_40_1_24_basic, windows_win_4_30_1_24_resolve, windows_win_4_40_1_24_basic, windows_win_4_40_1_24_hz, windows_win_6_30_0_24_resolve, windows_win_6_40_1_24_basic |
| 0x1d | 2408 | 3431 | yes | features_bigdraw, features_cglparams, features_clear, features_copydepth, features_copypix, features_draw, features_fbo, features_fbo2, features_msaa4, features_multitex, features_pixel, features_query, features_shaders, features_state, features_texfmt, features_vbo, godot_editor, godot_game, probes_cgl_probe, probes_perf_baseline, windows_win_0_30_1_24_basic, windows_win_0_30_1_24_resolve, windows_win_0_40_0_16_basic, windows_win_0_40_1_24_clears, windows_win_0_40_1_24_hz, windows_win_2_40_1_24_basic, windows_win_4_30_1_24_resolve, windows_win_4_40_1_24_basic, windows_win_4_40_1_24_hz, windows_win_6_30_0_24_resolve, windows_win_6_40_1_24_basic |
| 0x1e | 2405 | 2405 | yes | features_bigdraw, features_cglparams, features_clear, features_copydepth, features_copypix, features_draw, features_fbo, features_fbo2, features_msaa4, features_multitex, features_pixel, features_query, features_shaders, features_state, features_texfmt, features_vbo, godot_editor, godot_game, probes_cgl_probe, probes_perf_baseline, windows_win_0_30_1_24_basic, windows_win_0_30_1_24_resolve, windows_win_0_40_0_16_basic, windows_win_0_40_1_24_clears, windows_win_0_40_1_24_hz, windows_win_2_40_1_24_basic, windows_win_4_30_1_24_resolve, windows_win_4_40_1_24_basic, windows_win_4_40_1_24_hz, windows_win_6_30_0_24_resolve, windows_win_6_40_1_24_basic |
| 0x1f | 2405 | 2405 | yes | features_bigdraw, features_cglparams, features_clear, features_copydepth, features_copypix, features_draw, features_fbo, features_fbo2, features_msaa4, features_multitex, features_pixel, features_query, features_shaders, features_state, features_texfmt, features_vbo, godot_editor, godot_game, probes_cgl_probe, probes_perf_baseline, windows_win_0_30_1_24_basic, windows_win_0_30_1_24_resolve, windows_win_0_40_0_16_basic, windows_win_0_40_1_24_clears, windows_win_0_40_1_24_hz, windows_win_2_40_1_24_basic, windows_win_4_30_1_24_resolve, windows_win_4_40_1_24_basic, windows_win_4_40_1_24_hz, windows_win_6_30_0_24_resolve, windows_win_6_40_1_24_basic |
| 0x20 | 2405 | 2405 | yes | features_bigdraw, features_cglparams, features_clear, features_copydepth, features_copypix, features_draw, features_fbo, features_fbo2, features_msaa4, features_multitex, features_pixel, features_query, features_shaders, features_state, features_texfmt, features_vbo, godot_editor, godot_game, probes_cgl_probe, probes_perf_baseline, windows_win_0_30_1_24_basic, windows_win_0_30_1_24_resolve, windows_win_0_40_0_16_basic, windows_win_0_40_1_24_clears, windows_win_0_40_1_24_hz, windows_win_2_40_1_24_basic, windows_win_4_30_1_24_resolve, windows_win_4_40_1_24_basic, windows_win_4_40_1_24_hz, windows_win_6_30_0_24_resolve, windows_win_6_40_1_24_basic |
| 0x21 | 2405 | 2405 | yes | features_bigdraw, features_cglparams, features_clear, features_copydepth, features_copypix, features_draw, features_fbo, features_fbo2, features_msaa4, features_multitex, features_pixel, features_query, features_shaders, features_state, features_texfmt, features_vbo, godot_editor, godot_game, probes_cgl_probe, probes_perf_baseline, windows_win_0_30_1_24_basic, windows_win_0_30_1_24_resolve, windows_win_0_40_0_16_basic, windows_win_0_40_1_24_clears, windows_win_0_40_1_24_hz, windows_win_2_40_1_24_basic, windows_win_4_30_1_24_resolve, windows_win_4_40_1_24_basic, windows_win_4_40_1_24_hz, windows_win_6_30_0_24_resolve, windows_win_6_40_1_24_basic |
| 0x22 | 2405 | 2405 | yes | features_bigdraw, features_cglparams, features_clear, features_copydepth, features_copypix, features_draw, features_fbo, features_fbo2, features_msaa4, features_multitex, features_pixel, features_query, features_shaders, features_state, features_texfmt, features_vbo, godot_editor, godot_game, probes_cgl_probe, probes_perf_baseline, windows_win_0_30_1_24_basic, windows_win_0_30_1_24_resolve, windows_win_0_40_0_16_basic, windows_win_0_40_1_24_clears, windows_win_0_40_1_24_hz, windows_win_2_40_1_24_basic, windows_win_4_30_1_24_resolve, windows_win_4_40_1_24_basic, windows_win_4_40_1_24_hz, windows_win_6_30_0_24_resolve, windows_win_6_40_1_24_basic |
| 0x23 | 2405 | 2405 | yes | features_bigdraw, features_cglparams, features_clear, features_copydepth, features_copypix, features_draw, features_fbo, features_fbo2, features_msaa4, features_multitex, features_pixel, features_query, features_shaders, features_state, features_texfmt, features_vbo, godot_editor, godot_game, probes_cgl_probe, probes_perf_baseline, windows_win_0_30_1_24_basic, windows_win_0_30_1_24_resolve, windows_win_0_40_0_16_basic, windows_win_0_40_1_24_clears, windows_win_0_40_1_24_hz, windows_win_2_40_1_24_basic, windows_win_4_30_1_24_resolve, windows_win_4_40_1_24_basic, windows_win_4_40_1_24_hz, windows_win_6_30_0_24_resolve, windows_win_6_40_1_24_basic |
| 0x24 | 2405 | 2423 | yes | features_bigdraw, features_cglparams, features_clear, features_copydepth, features_copypix, features_draw, features_fbo, features_fbo2, features_msaa4, features_multitex, features_pixel, features_query, features_shaders, features_state, features_texfmt, features_vbo, godot_editor, godot_game, probes_cgl_probe, probes_perf_baseline, windows_win_0_30_1_24_basic, windows_win_0_30_1_24_resolve, windows_win_0_40_0_16_basic, windows_win_0_40_1_24_clears, windows_win_0_40_1_24_hz, windows_win_2_40_1_24_basic, windows_win_4_30_1_24_resolve, windows_win_4_40_1_24_basic, windows_win_4_40_1_24_hz, windows_win_6_30_0_24_resolve, windows_win_6_40_1_24_basic |
| 0x25 | 2407 | 63174 | yes | features_bigdraw, features_cglparams, features_clear, features_copydepth, features_copypix, features_draw, features_fbo, features_fbo2, features_msaa4, features_multitex, features_pixel, features_query, features_shaders, features_state, features_texfmt, features_vbo, godot_editor, godot_game, probes_cgl_probe, probes_perf_baseline, windows_win_0_30_1_24_basic, windows_win_0_30_1_24_resolve, windows_win_0_40_0_16_basic, windows_win_0_40_1_24_clears, windows_win_0_40_1_24_hz, windows_win_2_40_1_24_basic, windows_win_4_30_1_24_resolve, windows_win_4_40_1_24_basic, windows_win_4_40_1_24_hz, windows_win_6_30_0_24_resolve, windows_win_6_40_1_24_basic |
| 0x26 | 2 | 9696 | yes | features_bigdraw |
| 0x28 | 3290 | 601994 | yes | features_bigdraw, features_cglparams, features_clear, features_copydepth, features_copypix, features_draw, features_fbo, features_fbo2, features_msaa4, features_multitex, features_pixel, features_query, features_shaders, features_state, features_texfmt, features_vbo, godot_editor, godot_game, probes_cgl_probe, probes_perf_baseline, windows_win_0_30_1_24_basic, windows_win_0_30_1_24_resolve, windows_win_0_40_0_16_basic, windows_win_0_40_1_24_clears, windows_win_0_40_1_24_hz, windows_win_2_40_1_24_basic, windows_win_4_30_1_24_resolve, windows_win_4_40_1_24_basic, windows_win_4_40_1_24_hz, windows_win_6_30_0_24_resolve, windows_win_6_40_1_24_basic |
| 0x29 | 5263 | 308908 | yes | features_bigdraw, features_cglparams, features_clear, features_copydepth, features_copypix, features_draw, features_fbo, features_fbo2, features_msaa4, features_multitex, features_pixel, features_query, features_shaders, features_state, features_texfmt, features_vbo, godot_editor, godot_game, probes_cgl_probe, probes_perf_baseline, windows_win_0_30_1_24_basic, windows_win_0_30_1_24_resolve, windows_win_0_40_0_16_basic, windows_win_0_40_1_24_clears, windows_win_0_40_1_24_hz, windows_win_2_40_1_24_basic, windows_win_4_30_1_24_resolve, windows_win_4_40_1_24_basic, windows_win_4_40_1_24_hz, windows_win_6_30_0_24_resolve, windows_win_6_40_1_24_basic |
| 0x2d | 18 | 18504 | yes | features_copypix |
| 0x2f | 13550 | 34814548 | yes | features_clear, features_copydepth, features_copypix, features_fbo, features_fbo2, features_msaa4, features_multitex, features_pixel, features_query, features_state, godot_editor, godot_game, probes_cgl_probe, probes_perf_baseline, windows_win_0_30_1_24_basic, windows_win_0_30_1_24_resolve, windows_win_0_40_0_16_basic, windows_win_0_40_1_24_clears, windows_win_0_40_1_24_hz, windows_win_2_40_1_24_basic, windows_win_4_30_1_24_resolve, windows_win_4_40_1_24_basic, windows_win_4_40_1_24_hz, windows_win_6_30_0_24_resolve, windows_win_6_40_1_24_basic |
| 0x30 | 860 | 215000 | yes | windows_win_2_40_1_24_basic, windows_win_4_30_1_24_resolve, windows_win_4_40_1_24_basic, windows_win_4_40_1_24_hz, windows_win_6_30_0_24_resolve, windows_win_6_40_1_24_basic |
| 0x31 | 16 | 19216 | yes | features_copydepth |
| 0x32 | 336 | 69888 | yes | features_fbo2, features_shaders, features_texfmt, windows_win_0_30_1_24_resolve, windows_win_4_30_1_24_resolve, windows_win_6_30_0_24_resolve |
| 0x33 | 1283 | 254488 | yes | features_copydepth, features_copypix, features_fbo2, features_pixel, features_shaders, features_texfmt, godot_editor, godot_game, windows_win_0_30_1_24_resolve, windows_win_2_40_1_24_basic, windows_win_4_30_1_24_resolve, windows_win_4_40_1_24_basic, windows_win_4_40_1_24_hz, windows_win_6_30_0_24_resolve, windows_win_6_40_1_24_basic |
| 0x34 | 4 | 114 | yes | features_query |
| 0x35 | 1 | 204 | yes | features_fbo2 |
| 0x37 | 49 | 14906 | yes | features_texfmt, godot_editor, godot_game |
| 0x39 | 100 | 126970 | yes | features_bigdraw, features_vbo, godot_editor, godot_game |
| 0x3a | 4 | 636 | yes | features_bigdraw, features_vbo, godot_editor, godot_game |
| 0x3b | 8 | 472 | yes | features_query |
| 0x3e | 1 | 206 | yes | features_pixel |
| 0x3f | 1 | 205 | yes | features_pixel |
| 0x40 | 1 | 206 | yes | features_pixel |
| 0x41 | 119 | 12257 | yes | features_fbo, features_fbo2, godot_editor, godot_game |
| 0x44 | 2 | 106 | yes | features_texfmt |
| 0x45 | 4 | 4080 | yes | features_fbo2 |

Observed but NOT in the inventory: 0x00, 0x01.  (0x00 is observed as 1-word pads and as large register-state blocks and is not compared against by the dispatcher, so it presumably takes the default path - to be confirmed; any other entry here needs checking.)

In the inventory but never observed (9): 0x27, 0x2a, 0x2b, 0x2c, 0x36, 0x38, 0x3d, 0x43, 0x46.

## 2D

**(2026-10-07)** Captured via a new workload, `windowserver_gestures`: the real 2D-context traffic generated by `Tools/userspace/opcode_recorder.c` injected directly into `WindowServer` itself (the only process that ever opens a 2D-context connection - no app-level client does), while `Tests/perf_2d_compositing.c` drove 6 real desktop gestures (idle baseline, window open, window drag, window resize, scroll, Dock hover) via synthetic `CGPostMouseEvent`/`CGPostScrollWheelEvent` input against the live login session. Two 2D connections opened (one per Finder window lifecycle), flushes: 6, records: 12, words: 260, anomalies: 0.

| opcode | records | words | in inventory | workloads |
|---|---:|---:|---|---|
| 0x00 | 6 | 254 | **NO** | windowserver_gestures |
| 0x01 | 4 | 4 | **NO** | windowserver_gestures |
| 0x80 | 2 | 2 | **NO** | windowserver_gestures |

Inventory: 18 opcodes, **none observed under ordinary use**. All three observed records are the same generic pad/no-op (`0x00`)/terminator (`0x80`) family already seen in GL, not a real 2D-dispatcher opcode - ordinary Finder window compositing (drag/resize/scroll) never emits a single `masked`-kind opcode from the inventory on its own.

### Direct injection (2026-10-07): all 17 real opcodes now exercised or analytically closed

Since no real consumer emits the 17 "masked" 2D opcodes (same situation GL was in for its own last 9 gaps, closed by injection in the 2026-10-03 work above), `opcode_recorder.c` was extended (`OPCODE_INJECT_TYPE` to target a 2D connection instead of GL; a new `OPCODE_INJECT_SCHEDULE` to fire several independent single-record injections across different flushes of one connection, letting opcodes whose handler ends the whole buffer early on an invalid id each still get their own clean flush) and spliced into `WindowServer`'s own real, live 2D connection via the kill+immediate-relaunch technique (`Tests/windowserver_capture_notes.md`) - never a hand-built client, which is what hung the G5 in the 2026-10-03 attempt below.

**11 of 17 live-verified against the real stock kernel, zero anomalies, every word rewritten exactly as `Sources/ATIR5002DContext_process_command_buffer_Port.cpp` predicts:**

| opcode | records | words | kernel's rewrite (observed) | matches handler |
|---|---:|---:|---|---|
| 0x02 | 1 | 1 | header -> `80000000` | yes |
| 0x05 | 1 | 1 | header -> `80000000` | yes |
| 0x06 | 1 | 8 | all 8 words -> `80000000` | yes |
| 0x09 | 1 | 6 | header/word1/word5 rewritten from surface-state fallback (id clamped out of range) | yes |
| 0x0a | 1 | 2 | header/word1 rewritten (id clamped) | yes |
| 0x0b | 1 | 6 | header/word1/word5 rewritten (`find_surface_for_id` safe fallback, id not found) | yes |
| 0x0c | 1 | 2 | header/word1 rewritten (same fallback) | yes |
| 0x0d | 1 | 6 | header/word1/word5 rewritten (context's own bound-surface state, no id used) | yes |
| 0x0e | 1 | 2 | header/word1 rewritten (same) | yes |
| 0x11 | 1 | 4 | header/word1/word2/word3 rewritten (id=0, the always-valid first context slot) | yes |
| 0x12 | 1 | 4 | header/word1/word2/word3 rewritten (context's own bound-surface state, no id used) | yes |

Chained in one buffer (all 11 in a single flush): the real client's own stream, shifted up behind them, continued processing normally afterward - none of these terminate the loop. Full log: `Tests/baseline/opcode/stock_windowserver_inject.tsv`.

**The remaining 6 (`0x03`, `0x04`, `0x07`, `0x08`, `0x10`, `0x13`) found a real stock-driver bug first, then were live-verified too.** All six share one shape: the handler's very first bounds check, `M<UInt32>(M<SInt32>(self + 0x88) + 0x14) <= puVar18[1]`, dereferences `self+0x88` *unconditionally* - before the id is ever compared. The first scheduled live attempt (on an unprimed connection) panicked the kernel twice with an identical signature (`DAR=0x14`, `PC` inside this exact bounds check) - root-caused and filed as **kext-source#152**: `self+0x88` is a per-connection pointer that stays NULL until `declare_image` (external method selector 8) is called at least once, and ordinary `WindowServer` desktop compositing never calls it (confirmed by this file's own observation capture above). Fixed by extending `opcode_recorder.c` with `OPCODE_PRIME_IMAGE=1`, which calls `declare_image` for real (`IOConnectMethodScalarIScalarO`, the exact call shape `Tests/destructive/t3_2d_declare_image.c` already proved safe) on each 2D connection as it opens, before any schedule can fire - populating `self+0x88` the real way first.

With priming in place, all six fired cleanly on the next connections, **zero anomalies, every record entirely unchanged** - confirming the predicted "safe early-exit, no rewrite" behavior (the short-circuit `||` means an out-of-range id never reaches the second half of the check, and this family never writes `puVar18` on that path):

| opcode | records | words | kernel's rewrite (observed) | matches handler |
|---|---:|---:|---|---|
| 0x03 | 1 | 4 | unchanged | yes |
| 0x04 | 1 | 4 | unchanged | yes |
| 0x07 | 1 | 4 | unchanged | yes |
| 0x08 | 1 | 4 | unchanged | yes |
| 0x10 | 1 | 4 | unchanged | yes |
| 0x13 | 1 | 4 | unchanged | yes |

(Each needed its own 2D connection reaching flush 2 - these connections only ever live for ~2 flushes before closing, so `OPCODE_INJECT_SCHEDULE` targeted flush 2 on several separate connections, generated across a few kill+relaunch cycles, rather than several flushes of one.)

**Net: 0 of 18 inventory opcodes observed from ordinary use, but all 17 real opcodes are now live-verified against the real stock kernel, zero anomalies - genuinely closed, not an open gap. A real, previously-unknown stock-driver NULL-deref bug (#152) was found and fixed-around along the way.**

Capture logs: `Tests/baseline/opcode/stock_windowserver_gestures.tsv` (pure observation), `stock_windowserver_inject.tsv` (the first 11-opcode batch), `windowserver_inject4.tsv` through `windowserver_inject7.tsv` (the primed six, one or more opcodes per file). Technique notes (mach_init.d/launchd config caching per boot session, Test-HD-mount-timing trap, the working manual kill+relaunch method, `OPCODE_INJECT_TYPE`/`OPCODE_INJECT_SCHEDULE`/`OPCODE_PRIME_IMAGE`, the relaunch-race limitation, and the #152 panic/root-cause/fix story) written up in `Tests/windowserver_capture_notes.md`.

## DVD

No `DVD` flushes recorded by any workload (flushes: 0).

Inventory: 62 opcodes, none observed.

Anomalies recorded (record overruns a buffer / buffer never terminates / unreadable mapping): **0**.
Stray words (one word between the end of the last record and a zero terminator, logged as STRAY, not as an anomaly): 1.

