# Why the flagged T3 tests are judged as they are (evidence, Nov 7 2026)

Written for the next investigator. Every statement below is backed by a stored file or a git commit. Anything not proven is labelled **not established**. Where a conclusion only says "no evidence of a kext-dependent difference", that is all it says.

## How T3 compares (what "differs" means)

`Tools/t3_phaseR_one.sh` normalises a log with `sed 's/^[^ ]* \[[^]]*\] //' | grep -E '^(RESULT|NOTE)' | grep -v '^NOTE start:'` and `diff`s the rebuilt run against a stock reference. Each log line is prefixed `timestamp [method/kext/phase]`; the sed strips it. `NOTE start:` is dropped because `dtest.c:127` prints `phase`, `kext` and the mirror IP in it, which differ between any two runs by construction. Everything else is compared: every `RESULT` line and every `NOTE` line, including NOTE values that are data (a register value, a returned address, pixel bytes).

The stock references are of two kinds. Do not mix them up:

| File name | What it is | Date |
|---|---|---|
| `<test>.stock.norm` in a run directory | the Phase S log (`Tests/destructive/phaseS/t3_<test>_stock_*.log`), the same Oct 2 data re-normalised every time | Oct 2 |
| `<test>.stockhs.norm` (and `.stock1`, `.stock_rep1`, `.stock_rep2`) | the CURRENT test binary run on hot-swapped stock (`Tools/t3_stock_rerun_one.sh`), one test per fresh boot | Oct 19, Oct 21, Nov 3 |

`phaseS_rerun/*.norm` in this directory are from the **Nov 3** re-run (`~/g5logs/t3_phaseR_stockrerun`), except `surface_read.stock_rep1/2`, `dvd_write_regs_scratch.stock1/stock_rep1/stock_rep2` which are byte-identical to the Oct 19 files. `~/g5logs/final_eval_oct21/t3_stockrerun/` contains files with the same md5 as Oct 19 for several tests (for example all three `surface_read` stock files and `.diff`); those are copies, not new runs, and are counted once below.

## dvd_images, dvd_lock_buffers, gl_set_stereo_enable: older Phase S log, test changed afterwards

* Test sources changed after the Oct 2 Phase S logs: `dvd_images` and `dvd_lock_buffers` on Oct 5 (9cfc8934, 2122612e: leak checks, real allocation setup), `gl_set_stereo_enable` on Oct 6 (227cd8a2: GPU-liveness checks, EXPECTED-REJECT classification). So the diff against Phase S contains lines the old test never printed.
* Proven: for each of the three tests, `stockhs.norm` and `rebuilt.norm` are byte-identical (`cmp`) in `final_eval/t3/t3_phaseR_stockrerun` (Oct 19), `final_eval_oct21/t3_stockrerun` and `t3_phaseR_stockrerun` (Nov 3), and the `.diff` there is 0 bytes. The Nov 7 rebuilt norm of `dvd_images` and `dvd_lock_buffers` is byte-identical to the Nov 3 `stockhs.norm`. (`gl_set_stereo_enable` had not yet run in the Nov 7 pass when this was written.)
* Not established: nothing open for these three.

## gl_read_buffer and surface_read: the "first row" bytes

What the tests check: PASS needs the call to return 0 (or the predicted CannotLock) and **no byte changed outside rows 0..3** of the pre-filled 0xAA user buffer. The NOTE line also prints `first row: b0..b7` (the first eight bytes the call wrote). That NOTE is data, not a criterion.

Source changes: `t3_surface_read.c` unchanged since Oct 1 (862861ca), before the Phase S run. `t3_gl_read_buffer.c`: the 0x800 binding change was Oct 1 21:28 PDT (672b3a50), before the Oct 2 04:48Z (= Oct 1 21:48 PDT) Phase S run 2; the Oct 13 change (1b9f91f4) is comment-only in this file. So the test code that produced the Phase S bytes and the code now are the same.

The test never writes the surface: in `t3_surface_read.c` the value `addr` returned by 2D `lock_memory(0)` is stored and never dereferenced; the only writes are `memset(buf, 0xAA, ...)` into the destination. For `read_buffer`, the #158 follow-up (comment in `t3_gl_read_buffer.c` and `IOATIR500GLContext_read_buffer_Port.cpp`, Oct 13) records that the +0x5e8 path renders a textured quad on the GPU (`write_3dtexquad_cmds_for_copy_buffer_using_DMA`), returns without waiting for completion, and that a CPU write to the same buffer record had no observable effect on the returned bytes.

Every stored first-row value (first four of eight bytes shown; the last four of the eight are in the files; the fourth byte is `ff` in every non-0xAA case):

| Session | Arm | gl_read_buffer | surface_read |
|---|---|---|---|
| Oct 2 (Phase S) | stock | run 1 (mode 0): CannotLock, nothing changed; run 2: `ff ff ff ff` | `ff ff ff ff` |
| Oct 19 | stock (hot-swapped, current test) | `4a 4d 41 ff` | `83 41 24 ff`; reps `81 40 24 ff`, `83 41 24 ff` |
| Oct 19 | rebuilt | `b8 53 22 ff` | `80 3f 23 ff` |
| Oct 21 | stock | `ff ff ff ff` | (file is a copy of Oct 19) |
| Oct 21 | rebuilt | `ac 84 74 ff` | `ff ff ff ff` |
| Nov 3 | stock | `b4 88 76 ff` | `86 a9 cf ff` |
| Nov 3 | rebuilt | `b4 88 76 ff` | `86 a9 cf ff` |
| Nov 7 | rebuilt | `4a 4d 41 ff` | not yet run |

Proven by that table:
1. The value changes from session to session **on stock itself** (`gl_read_buffer`: three different values in four stock sessions; `surface_read`: at least four).
2. Stock and rebuilt gave the **same** bytes within the Nov 3 session for both tests, and **different** bytes within the Oct 19 session (both tests) and the Oct 21 `gl_read_buffer` session. So "identical under matched conditions" is NOT a proven statement; the table does not support it.
3. Two rebuilt values also occur on stock at another time (`4a 4d 41`: Oct 19 stock, Nov 7 rebuilt; `b4 88 76`: Nov 3 both). `ff ff ff ff` occurs on stock (Oct 2, Oct 21) and, for `surface_read`, on rebuilt (Oct 21). Two rebuilt values (`b8 53 22`, `ac 84 74`) were not seen on stock; the sample is too small to say whether stock can produce them.
4. The extent is identical in all 13 stored runs of both tests on both arms (Phase S, Oct 19, Oct 21, Nov 3, Nov 7): `bytes changed inside rows 0..3: 16, outside: 0`. Why 16 and not the whole 4x4 rectangle is not established.

**Not established:** where the written bytes come from (what the GPU quad samples). Earlier text called it "desktop content", "leftover memory" or "live"; none of that was shown. Only that the values are session-dependent on stock and that the extent is stable is shown. Because of this the comparison cannot prove the rebuilt kext writes the same pixels as stock, only that no extent difference and no stock-exceeding value spread was seen.

**Gap and the queued experiment (written Nov 7, NOT YET RUN).** The two existing tests sample only the first 8 bytes, once, at the moment the call returns, and the #158 comment says the call does not wait for the GPU copy, so even "16 bytes changed" may be a partial copy at that instant. `Tests/destructive/t3_gl_read_buffer_source.c` (experiment, not one of the 27) answers five questions in one session per boot on the same surface: (1) does the content change after the call returns (samples at 0/50/500/2000 ms); (2) is it repeatable inside a session (read_buffer three times, two different prefills); (3) do `read_buffer` and `surface_read` return the same bytes; (4) are the bytes pixels of the screen (before/after screenshots taken on the G5, searched in four channel orders); (5) does any of this depend on the kext (stock and rebuilt, 2 boots each). Run with `sh Tools/t3_experiment_one.sh t3_gl_read_buffer_source stock reboot` (twice), then `... rebuilt reboot` (twice); read with `python3 Tools/t3_read_buffer_source_analyze.py ~/g5logs/t3_experiments/<dirs>`. The test has only been written, not compiled or run: build it first on the G5 (`make destructive-t3_gl_read_buffer_source`) and fix any compile error before the first run. Results go into the table below and into the comment blocks of `t3_gl_read_buffer.c` / `t3_surface_read.c`; until then every byte-source statement stays "not established".

**Experiment results:** none yet.

Remaining gaps that this experiment does NOT close (also not established): the content of the surface memory as the CPU sees it (the address returned by 2D `lock_memory` is not shown to be a dereferenceable user pointer, so the test does not read it), and why only 16 bytes change.

## surface_locks: returned address

`t3_surface_locks.c` code is unchanged since the Phase S run (last code change eb19cb42, Oct 1 22:30 PDT; Phase S log is `...20261002T053315Z` = Oct 1 22:33 PDT; the later e96e0279 changed only a comment).

The three `[B]` battery NOTEs that print `data[0]` (sel3 `write_lock_options(1)`, sel14 `write_lock`, sel0 `read_lock_options(1)`): Phase S (Oct 2) stock `0x3812000` on all three. Hot-swapped stock re-runs (Oct 19, Oct 21, Nov 3) and rebuilt runs (Oct 19, Oct 21, Nov 3, Nov 7) all `0x3810000`. Every other line is identical (the Nov 7 rebuilt diff against the Phase S log is exactly those three lines; the Nov 7 rebuilt norm is byte-identical to the Oct 19, Oct 21 and Nov 3 stock re-runs).

Proven: the same test code produced two different values on stock (Oct 2 vs the re-runs); the three re-runs match the four rebuilt runs. **Not established:** why the Oct 2 run placed the buffer 0x2000 higher (the Oct 2 boot/load procedure versus the hot-swapped re-runs is the obvious difference, but it was not tested), and what decides the placement. The Oct 19 findings text "allocation placement" is a description of the symptom, not a diagnosis.

## dvd_write_regs_scratch: volatile registers

The test's own check, "full-range diff: N register(s) differ (expected 0)", fails on stock and rebuilt alike. Registers listed (`FULL-RANGE DIFF at ...`), file md5-distinct runs only:

| Run | Count | Registers |
|---|---|---|
| Oct 19 stock `stock1` / `stock_rep1` / `stock_rep2` / `stockhs` | 15 / 14 / 16 / 16 | subsets of {0x34 0xa8 0xac 0x340 0x3b8 0x3d8 0x594 0x7d4 0x7e0 0x1fc0..0x1fdc (8)} |
| Oct 21 stock `stockhs` | 15 | 0x34 0xa8 0xac 0x340 0x3b8 0x7d4 0x7e0 + 0x1fc0..0x1fdc |
| Nov 3 stock `stockhs` | 14 | 0x34 0xa8 0xac 0x340 0x7d4 0x7e0 + 0x1fc0..0x1fdc |
| Oct 19 rebuilt | 15 | + 0x3b8 |
| Oct 21 rebuilt | 15 | + 0x594 |
| Nov 3 rebuilt | 14 | the Nov 3 stock set |
| **Nov 7 rebuilt** | **17** | **0x000c** + 0x34 0xa8 0xac 0x340 0x3b8 0x594 0x7d4 0x7e0 + 0x1fc0..0x1fdc |

Proven: the stock set varies between 14 and 16 registers and contains 0x34 0xa8 0xac 0x340 0x7d4 0x7e0 0x1fc0..0x1fdc in every run on both arms, plus 0x3b8 0x3d8 0x594 intermittently. 0x000c (pre `0x10bfac8f`, post `0x103fac8f`, bit 0x00800000 differs) appears in **no** recorded stock or rebuilt run except Nov 7 rebuilt, and the Nov 7 rebuilt set is the only one with a register outside the union of the six recorded stock runs (that union has 17 registers; the Nov 7 set has 17 too but lacks 0x3d8 and adds 0x000c).

**Not established:** whether 0x000c is a volatile stock register that was simply never sampled (the test samples one run per boot, so six stock runs is a small sample of an intermittent register), or something the rebuilt kext touches. Do not call it clean and do not call it a defect from this run. Open: re-run on stock 2-3 times and on rebuilt 2 times after the main T3 run, one test per boot; if 0x000c appears on stock, record it here; if it appears on rebuilt only in several runs, trace what touches register 0x0c in the rebuilt kext against stock.

## Open check: does any real workload use selector 7? (queued, not run)

`read_buffer` (GL selector 7) is exercised by no test except `t3_gl_read_buffer`. Whether any real application calls it with data is not established. Planned: record IOConnect calls (the passive recorder from `Tools/userspace/`) while the Phase 6/9 workloads and games run and count selector-7 calls. If the count is zero, the byte-level content of `read_buffer` has no consumer in the evaluated workloads and the extent check is proportionate; if non-zero, the byte content needs a real check.
