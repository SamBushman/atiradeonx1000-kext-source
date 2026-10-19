# Real-game FPS test plan (stock vs rebuilt ATIRadeonX1000)

Status: PLAN, nothing here has been run. Written Oct 18 while Phase 4 of `full_evaluation_runbook.md` was running.

## Goal
Compare real-game frame rates between the stock driver and the rebuilt driver on the G5 (Tiger 10.4.11, 4 CPUs, 16 GB, Radeon X1900, 1920x1080), using each game's own benchmark where one exists and an external counter where it does not. Pass criterion = the same as `perf_compare.py`: no metric slower than stock by more than max(5 %, 3x stock run-to-run noise).

## Method common to every title
1. **Same-boot interleaving, A B A B** like `Tools/godot_fps_compare.sh`: hot-swap stock / rebuilt, run `unstick_hotswap_vram.sh`, `killall Dock`, settle 60 s, run one benchmark pass, repeat. Minimum 3 passes per side, plus 1 discarded warm-up per visit.
2. **Fresh boot per side for any title that crashes or wedges the hot-swapped driver** (rule from #179: never hot-swap back to stock after client activity). Use the `sweep_fresh_boots.sh` pattern.
3. **Two independent measurements per run**, so a game's own counter can be cross-checked:
   - the game's internal benchmark / FPS readout (parsed from its log or console output), and
   - the passive recorder (`Tools/godot_fps.command` style interposer, `Tools/frame_rate_from_log.py`): counts buffer flushes, so it works for every game even with no built-in benchmark, and it also gives the frame-time distribution (p10 / median / p90 / max stalls).
4. **Fixed settings per title**: one low and one high quality preset, fixed resolution (1920x1080 and 1024x768), vsync off wherever the game allows (otherwise state it; vsync-locked numbers hide differences). Settings files are copied from a committed snapshot before each run so both sides run identical configs.
5. **Metrics recorded**: average FPS, min FPS, p10/p90 frame time, max stall, panic.log size before/after, kextstat line, `stability_watch.sh` running on the dev machine for the whole session.
6. **Output**: `~/g5logs/<session>/gamefps/<title>/<side>_v<visit>/`; on the G5 under `~/rung3` (Test HD), never `/tmp`. Report via a new `Tools/game_fps_report.py` that reads the per-title result lines and prints a table in the `perf_compare.py` format (OK / REGRESSION / NOISY).
7. **Visual check**: each benchmark also saves one screenshot at a fixed frame; compare stock vs rebuilt for rendering differences (a fast but wrong frame is not a pass).
8. **Hazards**: never run alongside a soak. Do not run glstress or fast-clear modes. Record any hang/crash as a new `rebuilt-kext-defect` issue (never reopen an old one) and pull `panic.log`.

## Titles

| # | Title | State on G5 | Built-in benchmark | Effort |
|---|---|---|---|---|
| 1 | Unreal Tournament 2004 | Installed, `/Applications/Unreal Tournament 2004.app`, build 3369.2 | Yes: `Benchmark` / flyby, and `botmatch` timed runs, results in `Benchmark/*.csv` and `Logs/` | Low |
| 2 | Age of Empires III | Installed (`/Applications/Age of Empires III.app`, v1.0) | **No timedemo found.** The binary has a `showFPS` toggle ("overlays the game screen with an FPS counter") and nothing named benchmark/timedemo | Medium |
| 3 | Doom 3 | Not installed | Yes: `timedemo demo1` / `demo2`, prints "N frames, X seconds, Y fps" | High |
| 4 | Halo: Combat Evolved | Not installed; install media on the FTP | Yes on PC (`-timedemo` with recorded demos); Mac port support is **unverified** | Medium |
| 5 | Half-Life 2 (PPC Source port) | Not installed | Yes: `timedemo` / `-timedemo`, `bench`, and the Video Stress Test map `vst`; Steam-installed game | High |

### 1. Unreal Tournament 2004 (do first; also validates the harness)
- Use the stock UT2004 benchmark: `ut2004 "DM-Antalus?spectatingonly=true?numbots=8" -benchmark -seconds=60 -nosound` style launch for botmatch and `-flyby` for flybys (confirm exact syntax against build 3369.2 on the G5 before scripting; the Mac build may differ from PC).
- Parse the "Avg FPS / Min / Max" lines the engine writes to the log; cross-check with the recorder.
- Maps: DM-Antalus (flyby), CTF-FaceClassic or similar (botmatch), one outdoor map (ONS-Torlan). Presets: lowest and highest detail in `UT2004.ini`.
- Sources of variance to control: bot RNG (fixed seed via `-seed` if accepted, else flybys only for the pass/fail decision), audio off.

### 2. Age of Empires III
- Open question you raised: **does it have a benchmark?** On this G5 build: no timedemo or benchmark switch in the executable's strings; it has `showFPS`. Plan:
  1. Look inside `Contents/Resources/GameData` for `.xmb` / `.age3Yrec` and the in-game console/cheat list for a `benchmark` command. (The PC Windows build has no formal benchmark either; community "benchmarks" are replays and the `-benchmark` developer option, which may not exist on the Mac port.)
  2. Fallback that does not need a built-in benchmark: play a **recorded game replay** (`.age3Yrec`) at 1x speed on a fixed late-game, many-unit scenario, with `showFPS` on, and measure with the recorder. Replays are deterministic, so both sides see the same frames. Alternative: load one saved skirmish and run the camera along a scripted path with `CGPostMouseEvent` (proven to work over SSH, per `project_g5_ui_automation_oct6`).
  3. If neither is stable, mark as "FPS measured by recorder only, not benchmark-grade".
- Needs: confirm game version (1.0 is old; the Mac patch history should be checked) and that the game launches from an SSH-driven Terminal session (`open -a Terminal x.command` method).

### 3. Doom 3 (build from source)
- Source: `id-Software/DOOM-3` (GPL release). Notes from its README: no game data included; **needs the retail data patched to 1.3.1**; Mac Xcode 3.2 project under `neo/sys/osx/`; **the GPL release omits the stencil-shadow "depth fail" path**, so shadows are wrong and cheaper than retail. That makes frame rates not comparable with published numbers, but they are still valid for stock vs rebuilt as long as both sides use the identical binary. If we want correct shadows, base on a community fork (dhewm3 or the original-Mac-compatible forks) and say so in the report.
- Work items: (a) get a toolchain that builds the engine for ppc on Tiger (gcc 4.0.1 / Xcode on the G5, or the gcc-7 setup if the code needs C++11; the old Xcode project predates both); (b) fix big-endian issues in the PPC build (Doom 3 has endian-swap macros for the Mac, verify); (c) SDL or native Cocoa window; (d) ARB2 render path (needs ARB_fragment_program; X1900 on Tiger exposes it, verify with `glcov`).
- Game data: copy `base/pak000-pak004.pk4` etc. from the PC CD-ROMs (4 discs, PC install) plus the 1.3.1 patch's pk4s. Mac and PC data are the same .pk4 format. Check CD key not needed for single-player.
- Benchmark: `+set com_showFPS 1 +timedemo demo1` style (`timedemo demo1`, `demo2`; PC retail ships `demo1.demo`, `demo2.demo` in `base/demos`) with `+set r_mode`/`r_customWidth` fixed, vsync off (`r_swapInterval 0`), `s_noSound 1`. Output line: "`N frames rendered in X seconds = Y fps`". Run each demo 3 times per visit.
- Risk: highest effort in the plan; do it in a worktree with its own issue so it does not block the other titles.

### 4. Halo: Combat Evolved
- Retrieve media from the FTP (host/path needed from you), checksum the images, mount with hdiutil, install into `/Applications` on Tiger HD (or onto Test HD to save the 91 %-full primary drive; confirm free space: primary has 17 GB free, Test HD 645 GB).
- Apply the Mac patches in order (1.0.x updates) before testing.
- Benchmark: PC Halo accepts `-timedemo` with `-vidmode WxH,hz`; and demos recorded in-game. **Unverified for the Mac port**; first task is to check whether `Halo.app` honours command-line args and a `-timedemo` switch. Fallback: the recorder on the first scripted-camera segment of a named level (e.g. start of "The Pillar of Autumn") using the in-game demo (the attract-mode demo reel is deterministic) measured with the recorder.
- Hazard: game uses its own display mode switching; display reconfig could hit the display-sleep issues, so run it from a fresh boot per side.

### 5. Half-Life 2 (PPC Source port)
- Tool: `doctashay/source-engine-configurator` (README read Oct 18). It patches an existing Windows/Mac/Linux install folder (or Steam download via `libsteamdepot`) into a PPC `.app`. HL2, HL2:EP1/EP2, HL2:DM, CS:S, TF2, Portal etc. are supported. The engine is a private fork of `nillerusr/source-engine`.
- **Blocker to resolve first: its stated requirement is Mac OS X 10.5.0 or newer; the G5's Tiger HD runs 10.4.11.** Leopard (Sorbet HD) is off-limits per the standing rules. Options: (a) test whether the generated app actually runs on Tiger (many PPC ports do, but unverified); (b) ask the tool's author whether a 10.4 runtime exists; (c) get your explicit decision on whether a Leopard boot may be used for this one title (a hot-swap comparison would need the same kext on Leopard, which is a different driver build, so this likely means not a valid stock-vs-rebuilt test). Recommended: try (a) first.
- Game data: needs a legitimate install folder. Steam download via the tool (Ethernet, Steam login) or copy from a PC.
- Benchmark: Source engine's built-in `timedemo` (record a demo with `record`, play with `timedemo demo_name`), or `+map d1_canals_01 +timedemo`; and `vst` (Video Stress Test, Steam only). Output: console line "`N frames (X.XX seconds): Y fps`" written to `console.log` when `-condebug` is passed. Use `-novid -sw -w 1920 -h 1080 +mat_vsync 0`.
- Use the same demo file on both sides (committed to `Tests/gamefps/hl2/`; demo files are small).

## Order and schedule (rough)
1. UT2004 (hours): validates scripts, report generator, recorder cross-check.
2. AoE3 (half a day): decide benchmark method from the in-game investigation.
3. HL2 (half a day, plus blocker resolution).
4. Halo (half a day: install + patch + arg investigation).
5. Doom 3 (days): engine build + data + patch.
Each title ends with: scripts in `Tools/gamefps/<title>_compare.sh`, results in `~/g5logs/<session>/gamefps/`, a report table, and any divergence filed as a new `rebuilt-kext-defect` issue.

## What I need from you
- FTP host/path/credentials-free access method for the Halo media; confirm installation location (Test HD recommended).
- Doom 3: which discs (Doom 3 only, or also Resurrection of Evil?), and whether to fork-base on a community engine for correct shadows.
- HL2: how you want the Tiger/10.5 requirement handled (try on Tiger first is my recommendation), and Steam login/ownership details for the download path (I will not enter credentials without your OK).
- AoE3: which version/patches you have on disc, in case the installed 1.0 is not what you want benchmarked.
- Whether benchmarking is allowed to run while the 4-hour soak is NOT running (it must not overlap) and whether to schedule it after Phase 9.
