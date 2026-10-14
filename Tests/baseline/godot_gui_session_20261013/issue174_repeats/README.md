# #174 repeats (2026-10-13). Godot game, 40 s/run under the opcode recorder, launched via godot_gui.command-style Terminal script.
`screencapture -x` at 25 s (new-scene sets: odd runs only; stub-scene sets: every run). All on hot-swap+unstick state.

| set | scene | driver | runs | hangs |
|---|---|---|--:|--:|
| reb | autopilot squash_play | rebuilt issue172c | 10 (5 with shot) | 0 |
| stock | autopilot squash_play | stock | 10 (5 with shot) | 0 |
| reb_stub | stub `~/rung3/squash` (grey scene) | rebuilt | 4 clean then HANG in run 5 at 25 s (= screencapture moment) | 1 |
| stock_stub | stub scene | stock | 10 (all with shot) | 0 |
Earlier: rebuilt+stub+shot: 1 hang (first run), 1 clean. So rebuilt+stub+25s-screenshot: 2 hangs / 7 runs; stock: 0 / 12.
Both hangs: whole machine dead, system.log last lines `PowerMac11_2_SlewCtrlLoop ... slew request timed out`, no new panic text
(panic.log gets only a re-dump of the 16:45 entry with a new timestamp - diff the bodies). Run 5's recorder log lost (stdio buffer).
