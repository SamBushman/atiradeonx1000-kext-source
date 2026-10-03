# Command-stream opcode usage by real workloads (issue #42 criterion 2)

Recorded on the stock kext (4.1.9, G5, Tiger) with `Tools/userspace/opcode_recorder.c`, merged by `Tools/opcode_usage.py`, compared with the dispatcher inventory in `Tests/pm4_opcode_inventory.md`.
Counts are buffers submitted through the flush-map path (the kernel's `process_command_buffer`); buffers processed by other kernel paths are not counted.

Workloads: `cgl_probe` (1 run), `glcov_bigdraw` (1 run), `glcov_clear` (1 run), `glcov_draw` (1 run), `glcov_fbo` (1 run), `glcov_msaa4` (1 run), `glcov_multitex` (1 run), `glcov_pixel` (1 run), `glcov_query` (1 run), `glcov_shaders` (1 run), `glcov_state` (1 run), `glcov_texfmt` (1 run), `glcov_vbo` (1 run), `glprobe` (1 run), `glsl120test` (1 run), `glwin_0_30_1_24_basic` (1 run), `glwin_0_30_1_24_resolve` (1 run), `glwin_0_40_0_16_basic` (1 run), `glwin_0_40_1_24_clears` (1 run), `glwin_0_40_1_24_hz` (1 run), `glwin_2_40_1_24_basic` (1 run), `glwin_4_30_1_24_resolve` (1 run), `glwin_4_40_1_24_basic` (1 run), `glwin_4_40_1_24_hz` (1 run), `glwin_6_30_0_24_resolve` (1 run), `glwin_6_40_1_24_basic` (1 run), `godot_editor_ui` (1 run), `godot_squash_game` (1 run), `nesttest` (1 run), `perf_baseline` (1 run)

## GL

Flushes: 5574.  Records: 81429.  Words: 32205343.  Distinct opcodes observed: 51 of 66 in the inventory (**77 % coverage**); observed but not in the inventory: 1.

| opcode | records | words | in inventory | workloads |
|---|---:|---:|---|---|
| 0x00 | 5523 | 18922972 | **NO** | cgl_probe, glcov_bigdraw, glcov_clear, glcov_draw, glcov_fbo, glcov_msaa4, glcov_multitex, glcov_pixel, glcov_query, glcov_shaders, glcov_state, glcov_texfmt, glcov_vbo, glwin_0_30_1_24_basic, glwin_0_30_1_24_resolve, glwin_0_40_0_16_basic, glwin_0_40_1_24_clears, glwin_0_40_1_24_hz, glwin_2_40_1_24_basic, glwin_4_30_1_24_resolve, glwin_4_40_1_24_basic, glwin_4_40_1_24_hz, glwin_6_30_0_24_resolve, glwin_6_40_1_24_basic, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x04 | 220 | 59816 | yes | glwin_2_40_1_24_basic, glwin_4_30_1_24_resolve, glwin_4_40_1_24_basic, glwin_4_40_1_24_hz, glwin_6_30_0_24_resolve, glwin_6_40_1_24_basic |
| 0x05 | 409 | 45808 | yes | glcov_clear, glcov_msaa4, glcov_multitex, glcov_pixel, glcov_query, glcov_state, glwin_0_30_1_24_basic, glwin_0_30_1_24_resolve, glwin_0_40_0_16_basic, glwin_0_40_1_24_clears, glwin_0_40_1_24_hz, glwin_2_40_1_24_basic, glwin_4_30_1_24_resolve, glwin_4_40_1_24_basic, glwin_4_40_1_24_hz, glwin_6_30_0_24_resolve, glwin_6_40_1_24_basic |
| 0x06 | 461 | 70058 | yes | glcov_fbo, glcov_multitex, glcov_pixel, glcov_shaders, glcov_state, glcov_texfmt, glwin_0_30_1_24_resolve, glwin_4_30_1_24_resolve, glwin_6_30_0_24_resolve, godot_editor_ui, godot_squash_game |
| 0x07 | 14 | 57 | yes | glcov_multitex, glcov_shaders, godot_editor_ui |
| 0x08 | 3 | 24 | yes | glcov_multitex, glcov_shaders |
| 0x09 | 3 | 19 | yes | glcov_multitex, glcov_shaders |
| 0x0a | 2 | 16 | yes | glcov_multitex |
| 0x0b | 2 | 16 | yes | glcov_multitex |
| 0x0c | 2 | 16 | yes | glcov_multitex |
| 0x0d | 5 | 607 | yes | glcov_multitex, glcov_state |
| 0x0e | 1 | 8 | yes | glcov_multitex |
| 0x0f | 1 | 8 | yes | glcov_multitex |
| 0x10 | 1 | 8 | yes | glcov_multitex |
| 0x11 | 1 | 8 | yes | glcov_multitex |
| 0x12 | 1 | 8 | yes | glcov_multitex |
| 0x13 | 1 | 8 | yes | glcov_multitex |
| 0x14 | 1 | 8 | yes | glcov_multitex |
| 0x15 | 3 | 840 | yes | glcov_multitex, godot_editor_ui, godot_squash_game |
| 0x16 | 6322 | 960591 | yes | cgl_probe, glcov_bigdraw, glcov_clear, glcov_draw, glcov_fbo, glcov_msaa4, glcov_multitex, glcov_pixel, glcov_query, glcov_shaders, glcov_state, glcov_texfmt, glcov_vbo, glwin_0_30_1_24_basic, glwin_0_30_1_24_resolve, glwin_0_40_0_16_basic, glwin_0_40_1_24_clears, glwin_0_40_1_24_hz, glwin_2_40_1_24_basic, glwin_4_30_1_24_resolve, glwin_4_40_1_24_basic, glwin_4_40_1_24_hz, glwin_6_30_0_24_resolve, glwin_6_40_1_24_basic, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x17 | 2912 | 2912 | yes | cgl_probe, glcov_bigdraw, glcov_clear, glcov_draw, glcov_fbo, glcov_msaa4, glcov_multitex, glcov_pixel, glcov_query, glcov_shaders, glcov_state, glcov_texfmt, glcov_vbo, glwin_0_30_1_24_basic, glwin_0_30_1_24_resolve, glwin_0_40_0_16_basic, glwin_0_40_1_24_clears, glwin_0_40_1_24_hz, glwin_2_40_1_24_basic, glwin_4_30_1_24_resolve, glwin_4_40_1_24_basic, glwin_4_40_1_24_hz, glwin_6_30_0_24_resolve, glwin_6_40_1_24_basic, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x18 | 2923 | 2927 | yes | cgl_probe, glcov_bigdraw, glcov_clear, glcov_draw, glcov_fbo, glcov_msaa4, glcov_multitex, glcov_pixel, glcov_query, glcov_shaders, glcov_state, glcov_texfmt, glcov_vbo, glwin_0_30_1_24_basic, glwin_0_30_1_24_resolve, glwin_0_40_0_16_basic, glwin_0_40_1_24_clears, glwin_0_40_1_24_hz, glwin_2_40_1_24_basic, glwin_4_30_1_24_resolve, glwin_4_40_1_24_basic, glwin_4_40_1_24_hz, glwin_6_30_0_24_resolve, glwin_6_40_1_24_basic, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x19 | 2923 | 2923 | yes | cgl_probe, glcov_bigdraw, glcov_clear, glcov_draw, glcov_fbo, glcov_msaa4, glcov_multitex, glcov_pixel, glcov_query, glcov_shaders, glcov_state, glcov_texfmt, glcov_vbo, glwin_0_30_1_24_basic, glwin_0_30_1_24_resolve, glwin_0_40_0_16_basic, glwin_0_40_1_24_clears, glwin_0_40_1_24_hz, glwin_2_40_1_24_basic, glwin_4_30_1_24_resolve, glwin_4_40_1_24_basic, glwin_4_40_1_24_hz, glwin_6_30_0_24_resolve, glwin_6_40_1_24_basic, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x1a | 2924 | 2924 | yes | cgl_probe, glcov_bigdraw, glcov_clear, glcov_draw, glcov_fbo, glcov_msaa4, glcov_multitex, glcov_pixel, glcov_query, glcov_shaders, glcov_state, glcov_texfmt, glcov_vbo, glwin_0_30_1_24_basic, glwin_0_30_1_24_resolve, glwin_0_40_0_16_basic, glwin_0_40_1_24_clears, glwin_0_40_1_24_hz, glwin_2_40_1_24_basic, glwin_4_30_1_24_resolve, glwin_4_40_1_24_basic, glwin_4_40_1_24_hz, glwin_6_30_0_24_resolve, glwin_6_40_1_24_basic, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x1b | 2924 | 2928 | yes | cgl_probe, glcov_bigdraw, glcov_clear, glcov_draw, glcov_fbo, glcov_msaa4, glcov_multitex, glcov_pixel, glcov_query, glcov_shaders, glcov_state, glcov_texfmt, glcov_vbo, glwin_0_30_1_24_basic, glwin_0_30_1_24_resolve, glwin_0_40_0_16_basic, glwin_0_40_1_24_clears, glwin_0_40_1_24_hz, glwin_2_40_1_24_basic, glwin_4_30_1_24_resolve, glwin_4_40_1_24_basic, glwin_4_40_1_24_hz, glwin_6_30_0_24_resolve, glwin_6_40_1_24_basic, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x1c | 2924 | 2924 | yes | cgl_probe, glcov_bigdraw, glcov_clear, glcov_draw, glcov_fbo, glcov_msaa4, glcov_multitex, glcov_pixel, glcov_query, glcov_shaders, glcov_state, glcov_texfmt, glcov_vbo, glwin_0_30_1_24_basic, glwin_0_30_1_24_resolve, glwin_0_40_0_16_basic, glwin_0_40_1_24_clears, glwin_0_40_1_24_hz, glwin_2_40_1_24_basic, glwin_4_30_1_24_resolve, glwin_4_40_1_24_basic, glwin_4_40_1_24_hz, glwin_6_30_0_24_resolve, glwin_6_40_1_24_basic, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x1d | 2927 | 3950 | yes | cgl_probe, glcov_bigdraw, glcov_clear, glcov_draw, glcov_fbo, glcov_msaa4, glcov_multitex, glcov_pixel, glcov_query, glcov_shaders, glcov_state, glcov_texfmt, glcov_vbo, glwin_0_30_1_24_basic, glwin_0_30_1_24_resolve, glwin_0_40_0_16_basic, glwin_0_40_1_24_clears, glwin_0_40_1_24_hz, glwin_2_40_1_24_basic, glwin_4_30_1_24_resolve, glwin_4_40_1_24_basic, glwin_4_40_1_24_hz, glwin_6_30_0_24_resolve, glwin_6_40_1_24_basic, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x1e | 2924 | 2924 | yes | cgl_probe, glcov_bigdraw, glcov_clear, glcov_draw, glcov_fbo, glcov_msaa4, glcov_multitex, glcov_pixel, glcov_query, glcov_shaders, glcov_state, glcov_texfmt, glcov_vbo, glwin_0_30_1_24_basic, glwin_0_30_1_24_resolve, glwin_0_40_0_16_basic, glwin_0_40_1_24_clears, glwin_0_40_1_24_hz, glwin_2_40_1_24_basic, glwin_4_30_1_24_resolve, glwin_4_40_1_24_basic, glwin_4_40_1_24_hz, glwin_6_30_0_24_resolve, glwin_6_40_1_24_basic, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x1f | 2924 | 2924 | yes | cgl_probe, glcov_bigdraw, glcov_clear, glcov_draw, glcov_fbo, glcov_msaa4, glcov_multitex, glcov_pixel, glcov_query, glcov_shaders, glcov_state, glcov_texfmt, glcov_vbo, glwin_0_30_1_24_basic, glwin_0_30_1_24_resolve, glwin_0_40_0_16_basic, glwin_0_40_1_24_clears, glwin_0_40_1_24_hz, glwin_2_40_1_24_basic, glwin_4_30_1_24_resolve, glwin_4_40_1_24_basic, glwin_4_40_1_24_hz, glwin_6_30_0_24_resolve, glwin_6_40_1_24_basic, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x20 | 2924 | 2924 | yes | cgl_probe, glcov_bigdraw, glcov_clear, glcov_draw, glcov_fbo, glcov_msaa4, glcov_multitex, glcov_pixel, glcov_query, glcov_shaders, glcov_state, glcov_texfmt, glcov_vbo, glwin_0_30_1_24_basic, glwin_0_30_1_24_resolve, glwin_0_40_0_16_basic, glwin_0_40_1_24_clears, glwin_0_40_1_24_hz, glwin_2_40_1_24_basic, glwin_4_30_1_24_resolve, glwin_4_40_1_24_basic, glwin_4_40_1_24_hz, glwin_6_30_0_24_resolve, glwin_6_40_1_24_basic, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x21 | 2924 | 2924 | yes | cgl_probe, glcov_bigdraw, glcov_clear, glcov_draw, glcov_fbo, glcov_msaa4, glcov_multitex, glcov_pixel, glcov_query, glcov_shaders, glcov_state, glcov_texfmt, glcov_vbo, glwin_0_30_1_24_basic, glwin_0_30_1_24_resolve, glwin_0_40_0_16_basic, glwin_0_40_1_24_clears, glwin_0_40_1_24_hz, glwin_2_40_1_24_basic, glwin_4_30_1_24_resolve, glwin_4_40_1_24_basic, glwin_4_40_1_24_hz, glwin_6_30_0_24_resolve, glwin_6_40_1_24_basic, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x22 | 2924 | 2924 | yes | cgl_probe, glcov_bigdraw, glcov_clear, glcov_draw, glcov_fbo, glcov_msaa4, glcov_multitex, glcov_pixel, glcov_query, glcov_shaders, glcov_state, glcov_texfmt, glcov_vbo, glwin_0_30_1_24_basic, glwin_0_30_1_24_resolve, glwin_0_40_0_16_basic, glwin_0_40_1_24_clears, glwin_0_40_1_24_hz, glwin_2_40_1_24_basic, glwin_4_30_1_24_resolve, glwin_4_40_1_24_basic, glwin_4_40_1_24_hz, glwin_6_30_0_24_resolve, glwin_6_40_1_24_basic, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x23 | 2924 | 2924 | yes | cgl_probe, glcov_bigdraw, glcov_clear, glcov_draw, glcov_fbo, glcov_msaa4, glcov_multitex, glcov_pixel, glcov_query, glcov_shaders, glcov_state, glcov_texfmt, glcov_vbo, glwin_0_30_1_24_basic, glwin_0_30_1_24_resolve, glwin_0_40_0_16_basic, glwin_0_40_1_24_clears, glwin_0_40_1_24_hz, glwin_2_40_1_24_basic, glwin_4_30_1_24_resolve, glwin_4_40_1_24_basic, glwin_4_40_1_24_hz, glwin_6_30_0_24_resolve, glwin_6_40_1_24_basic, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x24 | 2924 | 2942 | yes | cgl_probe, glcov_bigdraw, glcov_clear, glcov_draw, glcov_fbo, glcov_msaa4, glcov_multitex, glcov_pixel, glcov_query, glcov_shaders, glcov_state, glcov_texfmt, glcov_vbo, glwin_0_30_1_24_basic, glwin_0_30_1_24_resolve, glwin_0_40_0_16_basic, glwin_0_40_1_24_clears, glwin_0_40_1_24_hz, glwin_2_40_1_24_basic, glwin_4_30_1_24_resolve, glwin_4_40_1_24_basic, glwin_4_40_1_24_hz, glwin_6_30_0_24_resolve, glwin_6_40_1_24_basic, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x25 | 2926 | 63629 | yes | cgl_probe, glcov_bigdraw, glcov_clear, glcov_draw, glcov_fbo, glcov_msaa4, glcov_multitex, glcov_pixel, glcov_query, glcov_shaders, glcov_state, glcov_texfmt, glcov_vbo, glwin_0_30_1_24_basic, glwin_0_30_1_24_resolve, glwin_0_40_0_16_basic, glwin_0_40_1_24_clears, glwin_0_40_1_24_hz, glwin_2_40_1_24_basic, glwin_4_30_1_24_resolve, glwin_4_40_1_24_basic, glwin_4_40_1_24_hz, glwin_6_30_0_24_resolve, glwin_6_40_1_24_basic, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x26 | 2 | 9696 | yes | glcov_bigdraw |
| 0x28 | 3808 | 631203 | yes | cgl_probe, glcov_bigdraw, glcov_clear, glcov_draw, glcov_fbo, glcov_msaa4, glcov_multitex, glcov_pixel, glcov_query, glcov_shaders, glcov_state, glcov_texfmt, glcov_vbo, glwin_0_30_1_24_basic, glwin_0_30_1_24_resolve, glwin_0_40_0_16_basic, glwin_0_40_1_24_clears, glwin_0_40_1_24_hz, glwin_2_40_1_24_basic, glwin_4_30_1_24_resolve, glwin_4_40_1_24_basic, glwin_4_40_1_24_hz, glwin_6_30_0_24_resolve, glwin_6_40_1_24_basic, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x29 | 6260 | 365572 | yes | cgl_probe, glcov_bigdraw, glcov_clear, glcov_draw, glcov_fbo, glcov_msaa4, glcov_multitex, glcov_pixel, glcov_query, glcov_shaders, glcov_state, glcov_texfmt, glcov_vbo, glwin_0_30_1_24_basic, glwin_0_30_1_24_resolve, glwin_0_40_0_16_basic, glwin_0_40_1_24_clears, glwin_0_40_1_24_hz, glwin_2_40_1_24_basic, glwin_4_30_1_24_resolve, glwin_4_40_1_24_basic, glwin_4_40_1_24_hz, glwin_6_30_0_24_resolve, glwin_6_40_1_24_basic, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x2f | 11813 | 10350366 | yes | cgl_probe, glcov_clear, glcov_fbo, glcov_msaa4, glcov_multitex, glcov_pixel, glcov_query, glcov_state, glwin_0_30_1_24_basic, glwin_0_30_1_24_resolve, glwin_0_40_0_16_basic, glwin_0_40_1_24_clears, glwin_0_40_1_24_hz, glwin_2_40_1_24_basic, glwin_4_30_1_24_resolve, glwin_4_40_1_24_basic, glwin_4_40_1_24_hz, glwin_6_30_0_24_resolve, glwin_6_40_1_24_basic, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x30 | 860 | 215000 | yes | glwin_2_40_1_24_basic, glwin_4_30_1_24_resolve, glwin_4_40_1_24_basic, glwin_4_40_1_24_hz, glwin_6_30_0_24_resolve, glwin_6_40_1_24_basic |
| 0x32 | 334 | 69472 | yes | glcov_shaders, glcov_texfmt, glwin_0_30_1_24_resolve, glwin_4_30_1_24_resolve, glwin_6_30_0_24_resolve |
| 0x33 | 1246 | 242487 | yes | glcov_pixel, glcov_shaders, glcov_texfmt, glwin_0_30_1_24_resolve, glwin_2_40_1_24_basic, glwin_4_30_1_24_resolve, glwin_4_40_1_24_basic, glwin_4_40_1_24_hz, glwin_6_30_0_24_resolve, glwin_6_40_1_24_basic, godot_editor_ui, godot_squash_game |
| 0x34 | 4 | 114 | yes | glcov_query |
| 0x37 | 49 | 14906 | yes | glcov_texfmt, godot_editor_ui, godot_squash_game |
| 0x39 | 100 | 126970 | yes | glcov_bigdraw, glcov_vbo, godot_editor_ui, godot_squash_game |
| 0x3a | 4 | 636 | yes | glcov_bigdraw, glcov_vbo, godot_editor_ui, godot_squash_game |
| 0x3b | 8 | 472 | yes | glcov_query |
| 0x3e | 1 | 206 | yes | glcov_pixel |
| 0x3f | 1 | 205 | yes | glcov_pixel |
| 0x40 | 1 | 206 | yes | glcov_pixel |
| 0x41 | 109 | 11227 | yes | glcov_fbo, godot_editor_ui, godot_squash_game |
| 0x44 | 2 | 106 | yes | glcov_texfmt |

Observed but NOT in the inventory: 0x00.  (0x00 is observed as 1-word pads and as large register-state blocks and is not compared against by the dispatcher, so it presumably takes the default path - to be confirmed; any other entry here needs checking.)

In the inventory but never observed (15): 0x02, 0x03, 0x27, 0x2a, 0x2b, 0x2c, 0x2d, 0x31, 0x35, 0x36, 0x38, 0x3d, 0x43, 0x45, 0x46.

## 2D

No `2D` flushes recorded by any workload (flushes: 0).

Inventory: 18 opcodes, none observed.

## DVD

No `DVD` flushes recorded by any workload (flushes: 0).

Inventory: 62 opcodes, none observed.

Anomalies recorded (record overruns a buffer / buffer never terminates / unreadable mapping): **0**.
Stray words (one word between the end of the last record and a zero terminator, logged as STRAY, not as an anomaly): 1.

