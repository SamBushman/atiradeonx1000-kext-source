# Command-stream opcode usage by real workloads (issue #42 criterion 2)

Recorded on the stock kext (4.1.9, G5, Tiger) with `Tools/userspace/opcode_recorder.c`, merged by `Tools/opcode_usage.py`, compared with the dispatcher inventory in `Tests/pm4_opcode_inventory.md`.
Counts are buffers submitted through the flush-map path (the kernel's `process_command_buffer`); buffers processed by other kernel paths are not counted.

Workloads: `cgl_probe` (1 run), `glprobe` (1 run), `glsl120test` (1 run), `godot_editor_ui` (1 run), `godot_squash_game` (1 run), `nesttest` (1 run), `perf_baseline` (1 run)

## GL

Flushes: 3014.  Records: 63508.  Words: 2398211.  Distinct opcodes observed: 27 of 66 in the inventory (**41 % coverage**); observed but not in the inventory: 1.

| opcode | records | words | in inventory | workloads |
|---|---:|---:|---|---|
| 0x00 | 2986 | 21913 | **NO** | cgl_probe, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x06 | 57 | 226 | yes | godot_editor_ui, godot_squash_game |
| 0x07 | 11 | 33 | yes | godot_editor_ui |
| 0x15 | 2 | 80 | yes | godot_editor_ui, godot_squash_game |
| 0x16 | 5807 | 948129 | yes | cgl_probe, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x17 | 2863 | 2863 | yes | cgl_probe, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x18 | 2874 | 2874 | yes | cgl_probe, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x19 | 2874 | 2874 | yes | cgl_probe, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x1a | 2874 | 2874 | yes | cgl_probe, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x1b | 2874 | 2874 | yes | cgl_probe, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x1c | 2874 | 2874 | yes | cgl_probe, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x1d | 2874 | 2874 | yes | cgl_probe, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x1e | 2874 | 2874 | yes | cgl_probe, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x1f | 2874 | 2874 | yes | cgl_probe, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x20 | 2874 | 2874 | yes | cgl_probe, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x21 | 2874 | 2874 | yes | cgl_probe, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x22 | 2874 | 2874 | yes | cgl_probe, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x23 | 2874 | 2874 | yes | cgl_probe, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x24 | 2874 | 2892 | yes | cgl_probe, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x25 | 2876 | 23516 | yes | cgl_probe, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x28 | 2851 | 222549 | yes | cgl_probe, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x29 | 5665 | 323572 | yes | cgl_probe, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x2f | 2832 | 784599 | yes | cgl_probe, godot_editor_ui, godot_squash_game, perf_baseline |
| 0x33 | 45 | 8595 | yes | godot_editor_ui, godot_squash_game |
| 0x37 | 45 | 13618 | yes | godot_editor_ui, godot_squash_game |
| 0x39 | 2 | 44 | yes | godot_editor_ui, godot_squash_game |
| 0x3a | 2 | 588 | yes | godot_editor_ui, godot_squash_game |
| 0x41 | 102 | 10506 | yes | godot_editor_ui, godot_squash_game |

Observed but NOT in the inventory: 0x00.  (0x00 is observed as 1-word pads and as large register-state blocks and is not compared against by the dispatcher, so it presumably takes the default path - to be confirmed; any other entry here needs checking.)

In the inventory but never observed (39): 0x02, 0x03, 0x04, 0x05, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x26, 0x27, 0x2a, 0x2b, 0x2c, 0x2d, 0x30, 0x31, 0x32, 0x34, 0x35, 0x36, 0x38, 0x3b, 0x3d, 0x3e, 0x3f, 0x40, 0x43, 0x44, 0x45, 0x46.

## 2D

No `2D` flushes recorded by any workload (flushes: 0).

Inventory: 18 opcodes, none observed.

## DVD

No `DVD` flushes recorded by any workload (flushes: 0).

Inventory: 62 opcodes, none observed.

Anomalies recorded (record overruns a buffer / buffer never terminates / unreadable mapping): **0**.

