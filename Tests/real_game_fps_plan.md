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
Findings from inspecting the G5 install (Oct 18, read-only):
- **No replays exist on the machine.** `~/Documents/Age of Empires III/Savegame` is empty (created Mar 2023); `GameData/CAMERATRACKS` holds only a 0-byte `stub.txt`; no `.age3rec`/`.age3sav`/benchmark files anywhere in the app or Documents.
- **The game has no benchmark switch.** The executable's strings contain `.age3rec` / `.age3sav` / `.age3scn` handling and an `ACameraTrackGadget` (editor camera tracks) but nothing named benchmark/timedemo; `Startup/game.cfg` has `syncRecord` / `noPregameRecording` and no FPS options; the only FPS feature is the `showFPS` overlay.
- Installed version is the 1.0 Mac build (`com.macsoft.age3`, base game, so recordings are `.age3rec`; the expansions use `.age3xrec` / `.age3yrec`). A web search found no public benchmark replay set; recorded games from other versions will not play on 1.0.
- Plan (needs your input / a short manual step): **record our own benchmark replay once** on the G5 (a fixed skirmish vs AI, played to a many-unit state, saved with the in-game recorded-game feature), then play that `.age3rec` back on each side, measuring with the passive recorder plus the `showFPS` overlay. Replays are deterministic for one build, so both sides render the same frames. Alternative that needs no replay: a saved late-game skirmish loaded from the save menu with a scripted `CGPostMouseEvent` camera pan.
- **Candidate replays found (Oct 18):** the AoE3 Heaven recorded-games archive (`aoe3.heavengames.com/downloads/lister.php?category=rec`, 1,511 files, newest first) goes back to Nov 2005. Sorted oldest first, files #35 to #126 are Nov 2005 games, the closest to the Mac 1.0 build. Downloaded to `~/g5logs/aoe3rec/dl/rec` on the dev machine (not committed; third-party files): `German_amazonia`, `German_Merc`, `Germans v2` (1v2), `forumparty1`, `2v3MokonViewpoint` / `2v3TGEViewpoint` (6-player Carolina), `Bobbers` (about 30 min vs 2 AI), and three Nov 26 forum-party games (Pampas 6-player, Carolina, Texas). Download recipe: `getfile.php?id=<id>&dd=1&s=<token from the page>` with a cookie jar; the files are zips containing `.age3rec`.
- **Open risk:** the `.age3rec` header is `l33t` followed by a compressed stream, so the game version cannot be read statically. A replay only plays on the exact build that recorded it. The installed Mac build is 1.0 (MacSoft conversion); the PC game was patched repeatedly in Nov 2005, so only the earliest files (Nov 3 to 6) are likely 1.0-compatible. Next step is empirical: copy 3 or 4 to `~/Documents/Age of Empires III/Savegame` on the G5 and try Help and Tools, Recorded Games, once the runbook is not using the GPU.
- Pick the benchmark replay by unit count: the 2v3 and 6-player games should stress rendering most; `Bobbers` has the longest single game.
- The Windows disc may carry a different build than the installed 1.0: tell me which patch level you have before recording.

### 3. Doom 3 (build from source)
- Source: `id-Software/DOOM-3` (GPL release). Notes from its README: no game data included; **needs the retail data patched to 1.3.1**; Mac Xcode 3.2 project under `neo/sys/osx/`; **the GPL release omits the stencil-shadow "depth fail" path**. Per your note, `dhewm/dhewm3` (GPL-3.0, updated Jun 2026) carries the full renderer (`neo/renderer/tr_stencilshadow.cpp`, `tr_shadowbounds.cpp`) and has a CMake build plus a `neo/sys/osx` tree and `dist/macosx`. Plan: base the work on dhewm3 (correct shadows, SDL2, maintained), not the id release, and port-check it for big-endian PPC (the original engine has endian macros; dhewm3 has dropped some PPC testing, so expect fixes). Frame rates then reflect the real stencil-shadow workload.
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
Findings from inspecting `Source.Engine.Configurator-0.0.8.dmg` (release v0.0.8, 665 MB, sha256 ddfba438...; unpacked on the dev machine under `~/g5logs/hl2_feas`, nothing run on the G5 yet):
- **There is nothing to build.** The `doctashay/source-engine-configurator` repo contains only the README, release notes, `version.txt` and screenshots; the app ships as a binary DMG (the bundle carries a GPL-3.0 licence file, so the author could be asked for the source). The engine runtime is a private fork of `nillerusr/source-engine`, and `libsteamdepot` (C++, LGPL) is separate.
- **The bundle is Leopard-targeted.** `LSMinimumSystemVersion` 10.5.0; binaries are built against the 10.5 SDK (about 33 `$UNIX2003` and 4 `$INODE64` libSystem symbols that Tiger lacks) with MacPorts `legacy-support` bundled. It includes separate `g4` and `g5` engine builds (`EngineVariants/g5`).
- **Static symbol check against Tiger 10.4.11's exports** (148,542 symbols from every Tiger system dylib/framework on the G5; first 25 per library listed, so these counts are lower bounds): 42 of 53 binaries import at least one symbol Tiger does not export, 108 distinct. Kinds: `$UNIX2003` / `$INODE64` variants (open/read/close/fstat/opendir...), **AudioQueue\* (15, Leopard-only; used by the engine and SDL2)**, IOHIDDevice\* (SDL2 joystick, Leopard-only), CFNetwork proxy calls, `glBlitFramebufferEXT` / `glRenderbufferStorageMultisampleEXT`, `getcontext` / `makecontext`, `_Unwind_GetIPInfo`, and in the GUI app `NSGradient`, `NSPathControl`, several `NSImageName*` constants (Leopard-only AppKit; the GUI would fail to load on Tiger).
- **Positive signs:** the shipped ToGL layer has an "OpenGL 1.5 compatibility / DX8 profile" path and Apple extension paths (`GL_APPLE_*`, `GL_EXT_framebuffer_object`), and it already contains R500 (X1000-series) workarounds, so the renderer is aimed at the same GPU family.
- **Work estimate**, in order, with confidence:
  1. Feasibility spike on the G5 (2-4 h, high confidence): copy the payload to Test HD, run `hl2_launcher` with `DYLD_BIND_AT_LAUNCH=1 DYLD_PRINT_LIBRARIES=1` to get the exact unresolved list.
  2. Compatibility layer (about 1-2 days, medium): script that rewrites the string table / library ordinal of the `$UNIX2003` imports to the plain Tiger symbols; a small shim dylib for `$INODE64` (stat/dirent struct conversion), stubs or a CoreAudio-backed implementation of AudioQueue (stub = no sound, fine for a benchmark), stubs for IOHIDDevice / CFNetwork / GL blit / getcontext. Not trivial, but mechanical.
  3. Assemble the game app by hand because the GUI cannot run on Tiger (0.5-1 day, medium): reverse the layout from `EnginePayload` and `Games/` and copy a game folder in. **Game data source:** the downloader lives inside the GUI, so game files must come from a Steam install on a PC/Intel Mac that you copy over (HL2 is a few GB).
  4. Make it actually render on Tiger's GL 2.0 stack and our X1900 driver (1-3 days, low confidence): ToGL translation paths, Tiger GLSL 1.10 quirks (see the X1900 driver quirk catalogue), SDL2 on 10.4 window/display code.
  - **Total: about 3-6 working days of focused work, with a real chance it ends at "reaches the menu but renders incorrectly".** Recommended: do step 1 first (half a day) and decide then; also ask the author for the source or a 10.4 build, which would remove most of steps 2-3.
- Benchmark once running: Source `timedemo` (record a demo with `record`, play with `timedemo`), console output via `-condebug` in `console.log`; launch args `-novid -sw -w 1920 -h 1080 +mat_vsync 0`. Same demo on both sides (commit it to `Tests/gamefps/hl2/`).

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
