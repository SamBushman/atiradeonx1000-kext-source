# #214 repro tooling (Doom 3 r_useVertexBuffers=1 CP wedge, stock driver)

* `../dhewm3-trace-214.patch` – dhewm3 patch: `neo/renderer/gllog214.cpp` wraps qgl* (env `D3GLLOG=<path>`), draw filters
  `D3GL_KEEPSET="a,b-c"` / `D3GL_DRAW_FROM` / `D3GL_DRAW_TO` / `D3GL_FINISH_AT`, per-draw `DRAWX` line (array buffers, strides, index range+hash),
  and `D3GL_STATE_AT="a,b"` (full GL state + raw index array → `<log>.state<N>.txt` / `.idx<N>.bin`).
* `d3run.sh TAG ENV...` – launch a Doom run on the G5 with the filters; `d3check.sh` on the G5 decides NORMAL/WEDGED (gllog line count stalled 20 s).
* `g5reboot.sh` / `g5wait.sh` – reboot (`sync; reboot -q`) + poll-until-ready (ssh+Finder+Dock, 25 min cap).
* `runp.sh TAG` + `rbis.sh TAG RANGES [ENV]` – run `Tests/userspace/gl_doom_replay_probe` (REPLAY=<gllog> REPLAY_REAL=1329,1382,1383
  REPLAY_REALDIR=<state/idx dumps> REPLAY_LINES=<log line ranges>) with the IOKit recorder and auto-reboot after a wedge.
* `../../pm4_walk.py` – walk a recorded command-buffer dump.

Result so far: Doom wedges with only draws {1329,1382,1383} issued; the standalone probe wedges when replaying log lines 1-30000 + 122452-130660 with those three real draws.
