# Godot game + editor, rebuilt vs stock, launched inside the Aqua session (2026-10-13)

Method: `Tools/userspace/godot_gui.command` started with `open -a Terminal` (see tiger-ssh skill). 40 s per app under
`opcode_recorder.dylib`, screenshot at 25 s. Fixes the old SSH launch failure (`bootstrap_register 1100`) and the old
`run_all_opcode_workloads.sh` quoting flaw (unquoted `--path /Volumes/Test HD/...` word-splits; Godot silently opened
its Project Manager, so the earlier 2026-10-02 "game" capture was probably the Project Manager, not Main.tscn).

| set (same hot-swap + unstick state) | game flushes/40 s | rec/flush | words/flush | editor flushes | anomalies |
|---|--:|--:|--:|--:|--:|
| stock hot-swap #1 | 4625 | 23.00 | 807.4 | 120 | 0 |
| stock hot-swap #2 | 4743 | 23.00 | 807.4 | 120 | 0 |
| rebuilt issue172c (2nd attempt) | 4727 | 23.00 | 807.4 | 120 | 0 |
| stock, boot-time driver (different state) | 2192 | - | - | 120 | 0 |

Opcode terminators: game 0x02 x ~4700 + 0x01 x4, editor 0x01 x119 + 0x02 x1, identical on all. => parity.

Not matching expectations on BOTH drivers: the game window shows only the grey clear colour (no 3D scene) - same on
stock, so not a rebuilt-driver regression; cause undetermined (not investigated).

One rebuilt run (1st attempt, game, ~25 s in, at the moment of the screenshot) ended in a hard hang/crash of the whole
machine with NO panic text written (`panic.log` gained only a stale re-dump of the 16:45 entry). Not reproduced in the
2nd rebuilt run; stock 0 of 3. Filed as a separate issue.
