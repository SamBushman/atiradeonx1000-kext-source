# #174 bisect summary (2026-10-13, G5 Tiger, Godot stub scene `~/rung3/squash`, 40 s/run, hot-swap + unstick, opcode recorder)

| build | register reads | opt | screenshot | runs | result |
|---|---|---|---|--:|---|
| stock 4.1.9 | stock | - | yes | 10 (+12 earlier) | 0 hangs |
| rebuilt issue172c | 133 single lwbrx | -Os | yes | 5 of 10 | hang in run 5 (25 s) ; earlier 1 more hang + 1 clean |
| rebuilt issue172c | " | -Os | no | 1 | hang in run 1 (~22 s) |
| rebuilt, autopilot scene (`squash_play`) | " | -Os | 5 of 10 | 10 | 0 hangs (also stock 10: 0) |
| issue171 | 4 byte loads (pre-#172), DIAG logs | -O0 | no | 10 | 0 hangs |
| HEAD built -O0 | single lwbrx, no DIAG | -O0 | no | 6 | 5 clean, hang in run 6 (REAL PANIC captured, see below) |
| issue172lw | single lwbrx, DIAG logs | -Os | no | 1 | hang in run 1 |
| issue175 (+ alignment fix) | single lwbrx | -Os | no | not started/lost | machine died within ~30 s of start (run dir lost) |
| issue176run (run-path files reverted to 4-byte reads: PCIeGART, TimeStamps, submit_buffer, SubmitBufferRetired, pageoff_dirty_with_cpu; 99 lwbrx remain) | mixed | -Os | no | 1 | machine died within ~30 s of start (run dir lost) |

Notes: "hang" = whole machine dead (no ping/ssh), power-cycle needed, no panic text (panic.log only re-dumps an old entry with a new
timestamp - always diff the BODY). Runs where the machine died within ~30 s of starting lose their progress file (HFS+ journal), so
the exact run number is unknown for the last two rows; the machine was healthy up to the test launch each time.
The one real panic (HEAD -O0 build, `panic_o0head_display_change_20261013_2208.log`): data access fault DAR=0x21b054 in
`IOATIR500Surface::copy_buffer_to_backing_store+0x818` (store through `buf->+0x24 + 0x54`, backing-store pointer 0x21b000 = garbage),
via display_change_handler -> display_mode_will_change -> disp_mode_will_change -> move_buffer_to_backing_store; then
mapping_remove: hw_rem_map failed (secondary).
Static comparison with stock: see the #174 comment. Per-file switch for further bisecting: `LWBRX_OFF_FILES="..." Tools/build_kext.sh`.
