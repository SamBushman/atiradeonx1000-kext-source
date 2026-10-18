# Feature-parity test harness

A plain userspace Tiger program that drives the ATIRadeonX1000 accelerator's external methods through IOKit exactly the way the real clients (the GL,
2D and video userspace bundles) do, so results can be recorded and compared between Apple's stock kext and a kext built from this tree.

It is **not** a kext: it is a normal Mac OS X application built with the system `gcc` and linked against `IOKit.framework` and
`CoreFoundation.framework`.

## Building and running (Mac OS X 10.4.x, PowerPC)

    cd Tests
    make
    ./parity_test_harness                 # the normal suite
    ./parity_test_harness --deep          # the deep-path suite (25 asserted checks, see below)

    sh compare_to_baseline.sh             # build, run against whichever ATIRadeonX1000 is loaded, diff against the recorded stock baseline
    DEEP=1 sh compare_to_baseline.sh      # the same for the deep suite

`compare_to_baseline.sh` exits 0 when the run is identical to the baseline, 1 when it differs (the differences are printed) and 2 when the harness
failed to run. Always run the harness against the **stock** kext first: its calls should behave sanely against a known-good driver before the
harness is used to judge a rebuild.

## Baselines

- `baseline/stock_4.1.9_g5_tiger.txt` - the normal suite against stock `com.apple.ATIRadeonX1000` 4.1.9 on a Power Mac G5 (Mac OS X 10.4.11, ATI Radeon
  X1900); two consecutive runs were byte-identical. 87 live calls: 74 asserted (`[OK]`; a different result prints `[UNEXPECTED]`) and 13 recorded only (`[REC]`).
- `baseline/stock_4.1.9_g5_tiger_deep.txt` - the deep suite against the same kext.
- `baseline/opcode/` - command-stream opcode tallies recorded from real workloads (see "Opcode tools").
- `baseline/README.md` explains how to read the baseline. Values such as VRAM size and device id belong to the machine that produced them; compare like with
  like (same machine, same GPU).

Most results are recorded rather than asserted, and "parity" means a rebuilt kext produces exactly the stock output. Non-success return codes are
meaningful: a DVD call that needs a bound surface returns `kIOReturnError` on a fresh connection, and unlocking with no lock held returns
`kIOReturnCannotLock`. IOKit copies outputs back only on success, so outputs of an error return are not observable from userspace.

`GL get_data_buffer` (selector 18) is not a pure query: it grows a global data-buffer pool, so the baseline pins only its invariants.

## What is covered

All 81 external methods are represented, one test file per context:

| file | context | methods |
|---|---|---|
| `test_gl_context.c` | GL | 21 (selectors 0-20; `Headers/IOATIR500GLContext.h` + `ATIR500GLContext.h`) |
| `test_2d_context.c` | 2D | 19 (selectors 0-18; `IOATIR5002DContext.h` + `ATIR5002DContext.h`) |
| `test_dvd_context.c` | DVD | 22 (selectors 0-21; `IOATIR500DVDContext.h` + `ATIR500DVDContext.h`) |
| `test_surface_context.c` | Surface | 19 (selectors 0-18; `IOATIR500Surface.h` + `ATIR500Surface.h`) |

`test_deep_t1.c` / `test_deep_t2.c` are the deep suite: asserted checks of outputs the normal suite only records (`get_config`, `get_status`,
`get_hw_info`, register reads through `read_regs` such as CONFIG_MEMSIZE and RBBM_STATUS, DVD `check_stamps`, Surface `get_state` / `query_lock`).

Ten methods are not part of either suite because calling them can hang or panic the machine or writes hardware state: GL `set_stereo`, 2D
`set_macrovision`, DVD `write_buffer`, `set_macrovision`, `write_regs` and `doIDCT`, and the Surface `write_lock_options`, `surface_flush`,
`read_lock` and `write_lock` family. They are run one per boot session under the protocol in `destructive/README.md`.

### Wire shapes and confidence

The wire shape of each call (selector, scalar counts, structure sizes) comes from the dispatch tables of the shipped kext: each entry is an
`IOExternalMethod` `{flags, count0, count1}` (flags 0 = scalarI/scalarO, 2 = scalarI/structO, 3 = structI/structO, 4 = scalarI/structI; `0xffffffff` =
variable size). `../Tools/dump_method_tables.py` extracts them into `method_shapes.txt` and `--audit Tests` checks every harness call against them.
Each call's comment records which shipped caller or body it was derived from. Calls whose shape could be confirmed from a vendor userspace call site are
marked CONFIRMED in the test files; the rest use the class header's declared signature and are marked UNVERIFIED.

## Safety

A broad sweep of call shapes against the live stock driver once caused a kernel panic: `ATIR500DVDContext::set_macrovision` dereferences its unbound
surface (`this+0xf8 == NULL`), reachable by one call on a fresh DVD connection. The harness therefore only calls methods whose bodies were traced first
(see the policy at the top of `common.h`). Rules for extending it:

- Do not turn a skipped test into a live one without establishing a real, valid setup sequence (an actually created and bound surface, etc.).
- Trace the full real code path of the target method, including every helper, and list the object state it assumes (allocated records, flag bits,
  non-null pointers). Satisfy each precondition with calls already proven safe, then make a single deliberate call - never a sweep.
- A `kIOReturnBadArgument` result is still information (usually an unverified wire shape rejected by the argument-count check); record it as it is.
- Never scan kernel memory broadly and never fuzz external methods with arbitrary arguments.

## Other tools in this directory

- **Opcode tools:** `Tools/userspace/opcode_recorder.c` tallies the command-stream opcodes a process submits; `Tools/opcode_usage.py` merges the logs and
  compares them with the opcode inventory in `pm4_opcode_inventory.json`. `pm4_opcode_inventory.md` and `pm4_opcode_usage.md` are the generated reports.
- **Performance:** `perf_baseline.c`, `perf_methods.c`, `perf_2d_compositing.c`, `perf_dvd_idct.c`, `perf_collect.sh`, `perf_2d_gestures.sh` and
  `userspace/perf_gl_features.c` time the driver; `Tools/perf_compare.py` and `Tools/perf_2d_report*.py` compare stock against rebuilt runs.
- **Stability:** `soak.sh` repeats the harness and consumer workloads for hours and checks for leaks and failures; `hwup_sampler.c` detects display
  re-handshakes that interrupt long runs.
- **Coverage data:** `function_coverage.md` (method coverage), `body_triage.tsv` (every static-check difference, classified), `deep_paths.json` and
  `deep_paths_notes.tsv` (shipped return codes per method and hand-written notes; `Tools/return_code_audit.py` checks them against the baselines).
  `Tools/parity_report.py` compares stock and rebuilt logs from the destructive tests and lists the known vendor deviations.

# Building every test
`sh Tests/build_all.sh` (on the G5) builds all test programs found under Tests/ (frameworks chosen from each file's includes; `build_exclude.tsv` lists any file deliberately skipped, with a reason) and exits non-zero if one fails. `sh Tools/stage_for_test.sh` (dev machine) builds the rebuilt kext AND all tests on the G5 in one step. Per-file list: `Tests/build_all.out`; compiler output: `Tests/build_all.err`.
