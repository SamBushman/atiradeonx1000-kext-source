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

## Update: making the Godot test render something useful (stock driver, same day)

Why it was grey: (1) `/Volumes/Test HD/squash_the_creeps_start` is a stub (empty Main) - nothing to draw; (2) the real game
(`~/Godot/squash_the_creeps_start_1.1.0`) kills an idle player in ~1 s and then a full-screen 51%-grey "Press Enter To Retry"
overlay covers the lit white ground (frames `game_*` above are that state); (3) the editor needs ~60-90 s to load, so
40 s runs captured only splash/blank (the old "120 flushes" editor baseline is the editor still loading).

Fix: `Tools/userspace/squash_play/` (autopilot copy: circle walk + jump, invulnerable, fixed seed) + `godot_gui.command`
now defaults to it and gives the editor 100 s. Result on the stock driver (hot-swapped): `game_playable_stock.png` (orange
player + blue creeps animating, no overlay) and `editor_loaded_stock.png` (full editor, 3D viewport with player, cylinder,
shadow). Flush counts with this method: game 11 506 / 11 594 per 40 s, editor 705 per 100 s. These REPLACE the table above
as the Godot baseline; the rebuilt kext still needs a run with the new scene (and the #174 hang repeats).
