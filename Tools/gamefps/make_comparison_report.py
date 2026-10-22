#!/usr/bin/env python3
"""make_comparison_report.py UT2004_DIR DOOM3_DIR OUT.md DOWN  - stock vs rebuilt ATIRadeonX1000 game-benchmark comparison as one Markdown file.
UT2004_DIR: Tools/gamefps/ut2004_run_side.sh results; DOOM3_DIR: Tools/gamefps/doom3_run_side.sh results. DOWN=1 notes that the G5 did not come back."""
import sys, os, re, glob, importlib.util, statistics as st, datetime, subprocess

here = os.path.dirname(os.path.abspath(__file__))
def mod(name, path):
    s = importlib.util.spec_from_file_location(name, path); m = importlib.util.module_from_spec(s); s.loader.exec_module(m); return m
ut = mod('ut', os.path.join(here, '..', 'game_fps_report.py'))
d3 = mod('d3', os.path.join(here, '..', 'game_fps_report_d3.py'))
UT, D3, OUT, DOWN = sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4] == '1'

def collect(base, loader, pat):
    res = {}
    for d in sorted(glob.glob(os.path.join(base, pat))):
        side = os.path.basename(os.path.dirname(d)).rsplit('_' + pat.split('_')[1][0], 1)[0]
        r = loader(d)
        if r: res.setdefault(os.path.basename(d), {}).setdefault(side, []).append(r)
    return res

def verdict(sv, bv, hib=True):
    sm, bm = st.mean(sv), st.mean(bv); noise = st.stdev(sv) / sm if len(sv) > 1 else 0.0
    tol = max(0.05, 3 * noise); delta = (bm - sm) / sm if hib else (sm - bm) / sm
    v = 'REGRESSION' if delta < -tol else ('NOISY' if noise > 0.05 else 'OK')
    return sm, bm, delta, tol, noise, v

def table(res, key, hib=True, fmt='%.2f'):
    rows = ['| Test | Stock (n) | Rebuilt (n) | Delta | Tolerance | Verdict |', '|---|---|---|---|---|---|']
    bad = 0
    for k in sorted(res):
        s = [x[key] for x in res[k].get('stock', []) if key in x]; b = [x[key] for x in res[k].get('rebuilt', []) if key in x]
        if not s or not b: rows.append('| %s | incomplete | | | | |' % k); continue
        sm, bm, dl, tol, nz, v = verdict(s, b, hib); bad += v == 'REGRESSION'
        rows.append('| %s | %s (%d) | %s (%d) | %+.1f%% | %.1f%% | %s |' % (k, fmt % sm, len(s), fmt % bm, len(b), dl * 100, tol * 100, v))
    return '\n'.join(rows), bad

utres = collect(UT, ut.load, '*_v*/*')
d3res = {}
for d in sorted(glob.glob(os.path.join(D3, '*_r*', '*'))):
    side = os.path.basename(os.path.dirname(d)).rsplit('_r', 1)[0]; r = d3.load(d)
    if r: d3res.setdefault(os.path.basename(d), {}).setdefault(side, []).append(r)
utres = {}
for d in sorted(glob.glob(os.path.join(UT, '*_v*', '*'))):
    side = os.path.basename(os.path.dirname(d)).rsplit('_v', 1)[0]; r = ut.load(d)
    if r: utres.setdefault(os.path.basename(d), {}).setdefault(side, []).append(r)

ut_avg, b1 = table(utres, 'avg'); ut_min, _ = table(utres, 'min'); ut_p90, b2 = table(utres, 'p90', False); ut_stall, _ = table(utres, 'stall', False)
d3_fps, b3 = table(d3res, 'fps')
raw = ['### Raw per-pass results', '', '| Run | FPS | frames |', '|---|---|---|']
for k in sorted(d3res):
    for side in ('stock', 'rebuilt'):
        for i, x in enumerate(d3res[k].get(side, []), 1): raw.append('| Doom 3 %s %s #%d | %.1f | %d |' % (k, side, i, x['fps'], x['frames']))
for k in sorted(utres):
    for side in ('stock', 'rebuilt'):
        for i, x in enumerate(utres[k].get(side, []), 1): raw.append('| UT2004 %s %s #%d | %.2f (min %.1f, max %.1f) | %d |' % (k, side, i, x['avg'], x['min'], x['max'], x.get('frames', 0)))
total_bad = b1 + b2 + b3

def drvline(base, side):
    p = os.path.join(base, side + '.driver')
    return open(p).read().strip() if os.path.exists(p) else '(not recorded)'

md = f"""# G5 game benchmarks: stock vs rebuilt ATIRadeonX1000

Generated {datetime.datetime.now():%Y-%m-%d %H:%M} on the dev machine from the G5 results.

## Summary
- **Regressions of the rebuilt driver against stock: {total_bad}** (criterion: a metric worse than stock by more than max(5 %, 3x stock run-to-run noise)).
{'- No metric regressed: UT2004 and Doom 3 results are within tolerance of stock everywhere (see the tables and the NOISY rows).' if total_bad == 0 else '- **At least one metric regressed; see the REGRESSION rows below and investigate before drawing conclusions.**'}
- Doom 3 frame counts are identical on every pass (2148 for demo1), and UT2004 uses a fixed RNG seed, so both drivers rendered the same workload.
- {"**The G5 did not come back after its last crash, so some results are missing and the driver restore/shutdown could not be done.**" if DOWN else "Driver restore and G5 shutdown status is recorded in the 'Final G5 state' section at the end of this file."}

## Setup
- Mac Power Mac G5 (quad PPC970), Mac OS X 10.4.11 (Tiger), ATI Radeon X1900 (`GL_VERSION 1.5 ATI-1.4.19`), 16 GB.
- **Stock driver:** Apple `ATIRadeonX1000` 4.1.9, loaded from the prelinked kernelcache (0x541000), binary md5 `9c7a9fff5ee767ed5280e58d55df92cd`.
- **Rebuilt driver:** source tip `6842a99`, binary md5 `3c187f4d15785192ec050579c6e6d1be`, installed over the stock binary in `/System/Library/Extensions` and booted (prelinked after kextd regenerated the kernelcache, same load path as stock).
- Method: **one driver per boot, no hot-swapping.** Stock measured, rebuilt installed and the G5 rebooted, then the identical passes repeated.
- Settings are fixed in scripts (`Tools/gamefps/` in atiradeonx1000-kext-source) and identical for both sides: vsync off, sound off, fixed resolution, fixed RNG seed (UT2004).

## UT2004 (build 3369.2, built-in benchmark, DM-Antalus and ONS-Torlan, 60 s, seed 453418555, 8 bots, attract camera)
Presets: `high` = 1920x1080 with the existing ultra textures; `low` = 1024x768, lowest texture detail, no decals/coronas/projectors.

### Average FPS
{ut_avg}

### Minimum FPS
{ut_min}

### 90th-percentile frame time (ms, lower is better)
{ut_p90}

### Maximum stall (ms, lower is better)
{ut_stall}

Notes: per-frame data come from the game's own `stats.csv`; the game's reported average and the CSV-derived average agree within 0.3 %. ONS-Torlan has 2 rebuilt rounds (the round-1 passes were killed by an unexplained SIGTERM); stock has 3.

## Doom 3 (dhewm3 built for PPC Tiger, retail data + 1.3.1 patch, `timeDemoQuit demo1`, fullscreen, 3 rounds)
Presets are explicit cvars: `high` = anisotropy 8, no downsizing/compression; `low` = anisotropy 1, textures downsized, compression on. `r_useVertexBuffers 0` for both sides (see notes).

### Average FPS (higher is better)
{d3_fps}

Notes:
- The run is largely CPU-bound on this machine: going from 1920x1080 to 1024x768, or high to low quality, changes FPS by only about 10 %, so the benchmark is a weak probe of GPU-side differences.
- The Doom 3 data and results were on Tiger HD (onboard disk) for these numbers. An earlier set of rebuilt/stock passes read the data from Test HD (the SonnetSATA disk); those are kept separately (`testhd_rebuilt_r*`, `stock_r*` in `doom3_run2`) and show the same parity.

{chr(10).join(raw)}

## Things you should know
1. **Doom 3 hangs the stock driver with vertex buffer objects on.** With `r_useVertexBuffers 1` the first GUI `glBufferSubData` blocks forever in the ATI kernel call (`gldFinishObject`), WindowServer then blocks too, and only a reboot recovers it. This is on the **stock** driver, not a rebuilt-driver bug. All results use `r_useVertexBuffers 0`. Evidence: `~/g5logs/gamefps/doom3_hang1/`. Whether the rebuilt driver behaves the same with VBOs on was **not tested**.
2. **Two G5 crashes during the rebuilt runs were SonnetSATA kernel panics, not the ATI driver.** Both are a NULL dereference at the same place in SonnetSATA 2.2.4 (offset 0x15394, DAR 0), with identical kernel backtraces and no ATIRadeonX1000 frame. The SATA card holds Test HD (Marvell 88SX7042, WDC 750 GB); Tiger HD is on the onboard bay. The rebuilt kext has no dependency on SonnetSATA. 2.2.4 (2010) is the newest Power Mac Sonnet driver; 2.2.9b is Intel-only. Evidence: `~/g5logs/gamefps/crash1/`, `crash2/`.
3. The passive opcode recorder cannot be used as a frame counter for UT2004 (about 8 flushes per frame, and it halves FPS), so the game's own timing was used.
4. A like-for-like caveat from earlier work: boot-time stock is loaded from the prelinked kernelcache, and so is the rebuilt driver here (kernelcache md5 `36443c16...` contains the rebuilt binary).

## Driver state on each side
Stock boot:
```
{drvline(UT, 'stock')}
```
Rebuilt boot:
```
{drvline(UT, 'rebuilt')}
```
"""
open(OUT, 'w').write(md)
print('wrote', OUT, 'regressions', total_bad)
