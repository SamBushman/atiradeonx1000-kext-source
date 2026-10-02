# Stability regimen (issue #43) - methodology, tooling, stock result

Scope (per the 2026-10-02 scope decision on #41-#45): this file **defines** how stability is judged and what tooling does it, and records the **stock** driver's result. Applying it to the rebuilt kext is #45.
Everything here uses only calls already proven safe on the stock kext. The destructive-protocol tests (#87, one per boot, user at the machine) are deliberately NOT part of a soak.

## 1. The regimen (criterion 1)

| category | what runs | where | tool |
|---|---|---|---|
| sustained mixed usage | `Tests/soak.sh DURATION`: rounds of `perf_baseline` (GL context + pbuffer create/draw/readback/destroy x50: GL/Surface context churn), `parity_test_harness` (all external methods of the 4 contexts: connection open/close churn), `parity_test_harness --deep` (T1 deep paths: real register reads, surface bind/unbind) | on the G5 | `Tests/soak.sh` |
| rapid create/destroy | the `perf_baseline` step above (50 contexts per round; ~35 k contexts in 4 h) | G5 | `Tests/perf_baseline.c`, `GLN=` to scale |
| adversarial inputs | the tiered, reasoned destructive tests (hardware writes with evidence, lockOptions variants, unbound-surface calls are NEVER made): one per boot-session, recorded outcome class PASS / EXPECTED-REJECT / HANG / PANIC | G5, user at the machine | `Tests/destructive/run_t3.sh` (protocol #87); results in `Tests/destructive/phaseS/` |
| resource exhaustion / allocation-failure injection | **not run on any machine we care about**: the known failure paths are real vendor bugs (#32 infinite loop, #99 lock leak, see `Tests/known_vendor_deviations.md` V1/V2) found by static trace. Define-only: on the rebuilt kext these paths are compared by disassembly, not triggered. A future injected-failure test needs a sacrificial setup (a second boot volume and a recoverable machine) and the user's explicit go-ahead | - | `Tools/callee_compare.py`, `Tools/lock_leak_scan.py` |
| real consumers under load | GL application, desktop, video as defined in `Tests/consumer_scenarios.md`, run for the same wall-clock as the soak | G5 console | `Tools/userspace/iokit_record.c` recorder |

Judging rule for the soak (self-consistency): the first `parity` and `deep` outputs of a soak become its reference; every later round must reproduce them byte for byte, `perf_baseline` must exit 0 each time. The recorded
stock baselines are **not** used as the soak oracle because they depend on display state (see section 5).

## 2. Detection (criterion 2)

`Tools/stability_watch.sh` (dev machine, read-only on the G5, one ssh per interval) writes a TSV of uptime, kext load address, crashdump count and panic.log size, and stops with a named verdict:

| verdict | exit | meaning |
|---|---|---|
| HANG | 3 | G5 unanswered for N consecutive probes (default 5 x 30 s) |
| REBOOT | 4 | uptime went backwards (panic with auto-restart, or power cycle) |
| PANIC | 5 | `/Library/Logs/panic.log` grew |
| KEXT | 6 | the ATIRadeonX1000 kext vanished or moved |
| CRASHDUMP | 7 | a `crashdump` process appeared (crashreporterd saw a crash/hang; they pin a core each) |
| OK | 0 | duration elapsed, none of the above |

All five failure verdicts were exercised (HANG against an unreachable host, the others with a stand-in `ssh` returning crafted samples); OK was exercised against the real G5. The soak itself also stops on a crashed step or a
reference mismatch (`STEP-FAIL` / `STEP-DIFF` in its log). A hung G5 cannot report its own hang, hence the dev-machine watcher; `run_t3.sh` keeps its own 5-minute-silence HANG rule for the destructive tests.

## 3. Diagnosis (criterion 3)

1. Get `/Library/Logs/panic.log` off the G5 (the log accumulates; the entry of interest is the newest naming `com.apple.ATIRadeonX1000`). Archive it in `Tests/destructive/phaseS/panics/`.
2. `python3 Tools/panic_symbolicate.py LOG --find-pad` (use `--kext` with the exact binary that was loaded: the stock `tiger-hd-pull/ATIRadeonX1000.kext.bin` today, the rebuilt kext's binary in Phase R). It maps PC, LR and the
   backtrace to function+offset, demangled, and prints the instructions at PC/LR. `--find-pad` derives the load pad from the log (return addresses must follow call instructions); **always check** that the faulting
   instruction is a load/store whose offset equals DAR. A wrong pad produces a confident but absurd call chain (the first #123 analysis, corrected on 2026-10-02: pad is 0x1000, not the header size 0xce0).
3. Root-cause in this project's own source: open the function in `Sources/` (`Ledger/` and `Tools/callee_compare.py` give the stock/rebuilt comparison), decide whether the stock kext does the same (a vendor bug: add a row to `Tests/known_vendor_deviations.md`)
   or the transcription differs (a defect: file an issue per `github-issue-filing`, one per offending function, as the project convention requires).
4. Validation of the method on real data: the 2026-09-18 panic resolves to `ATIR500Surface::getFramebufferIndex()+0x8` (`lwz r0,0xd64(r3)`, DAR 0xd64 = the documented DVD set_macrovision NULL-surface cause); the 2026-10-01 panic (#123) resolves to
   `ATIR500Memory::dealloc(GLKMemoryElement*)+0x60` via `dealloc_surface` <- `move_buffer_to_backing_store` <- `surface_lock_options` <- `surface_write_lock_options`.

## 4. Unbootable / hung machine (criterion 4)

Covered by `Tests/first_load_plan.md` Stage 3 (recovery ladder) and the protocol of #87 (write-ahead log mirrored over UDP, preflight/postflight, one test per boot). Practical rules from the incidents so far:
a hung G5 needs a physical power-cycle (no ssh path); after any panic collect `panic.log` before doing anything else; stray `crashdump` processes (root) must be cleared (`sudo killall crashdump`) or a reboot, before the next run.
The backup of the stock driver bundles with checksums is `backups/stock-driver-2026-09-19/` on the G5's Test HD (verified intact 2026-10-02).

## 5. Findings made while building this (stock)

* **The recorded parity baselines are display-state dependent.** `Surface set_id_mode(1, 0x0)` succeeds only while display record 1's pixel-format-class field (`accel+0x142+id*0x78`, written by `set_display_mode_and_vram`) is 0 (unconfigured); it equals the mode table
  entry for the requested mode bits, 4 = 32-bit colour. On 2026-10-02 (after the G5 had been up ~10 h) `probe_set_id_mode` shows both ids 0 and 1 match kind 4, so `parity_test_harness` reports 3 unexpected results and `--deep` 7, all in
  the set_id_mode(1,...) preconditions, with identical outputs run to run. The T3 runs of the previous evening passed with the same single 1920x1080 display, so the field changed with no change of attached displays (likely a display mode set on display sleep/wake).
  Consequence: before comparing any run (stock or rebuilt) with the recorded baseline, record the machine's id/kind fingerprint (`probe_set_id_mode`, 24 validated calls) next to it, or compare only against a same-session reference as the soak does.
  **Confirmed 2026-10-02:** after a reboot `probe_set_id_mode` shows id0=[0x4] id1=[0x0] again and both recorded baselines (normal and `--deep`) are IDENTICAL on stock (`Tests/baseline/FINGERPRINT.txt`); the baselines were never wrong, they are valid in the fresh-boot state.
* The soak step for the harness therefore uses a self-consistency reference, and `Tests/soak.sh` records the reference's "unexpected" count in its log.
* `/Library/Logs/panic.log` contains older, unrelated panics (a 2026-08-21 AppleGPIO/AppleSMU mutex panic); the symbolicator selects entries that name the ATI kext.

## 6. Stability gate (criterion 5)

**Bar: 4 hours of `Tests/soak.sh` with `Tools/stability_watch.sh` running throughout, zero verdicts other than OK, zero STEP-FAIL/STEP-DIFF, on a machine booted fresh for the run, kext load address unchanged - with ONE amendment (2026-10-02, per the user, after the first stock run): the transient retry rule.** A step whose only differences from its reference are NotReady (0xe00002d8) results on DVD-context lines (the accelerator's "hardware up" flag briefly down during a display reconfiguration, V11 in `Tests/known_vendor_deviations.md`) is rerun after 2 s, up to 3 times; it counts as a pass only if a rerun matches the reference exactly, every retry and recovery is logged and the number of recovered transients is reported at the end (`transients_recovered=N`). Any other difference, or a NotReady that persists through the retries, is still a STEP-DIFF failure. An optional budget (`TRANSIENT_MAX_PER_HOUR=N`, off by default) fails the run if recovered transients exceed N x (elapsed hours + 1). The rule is proven by `Tests/soak_retry_selftest.sh` (10 scenarios with a fake harness, passing on both a modern shell and the G5's sh) and classifies the real 2026-10-02 13:00:58 event as retryable. `Tests/hwup_sampler.c` runs alongside and logs the exact hardware-not-up windows. The same bar applies to stock and rebuilt.
Rationale: the soak's GL churn is ~35 k contexts in 4 h, an order of magnitude beyond anything run so far; a leak or slow corruption in a context/surface path shows up as a diverging round or a panic well inside that window.
The bar is a proposal for the user to adjust; the tooling takes the duration as an argument.

Stock result against the bar: see the "Stock soak results" section appended below as runs complete.

## Stock soak results

**Run 1, 2026-10-02 (stock 4.1.9, fresh boot at 09:14, soak started 09:17:24): the bar was NOT met as defined.** Log and watchdog traces: `Tests/baseline/soak/`.

* **703 complete rounds plus the first two steps of round 704, 3 h 43 min (09:17:24 - 13:00:58), then `STEP-DIFF r704 deep`** and the soak stopped itself. That is ~35 200 GL context create/draw/readback/destroy cycles (`perf_baseline` x50 per round) and ~1 400 full harness passes, every one identical to its round-1 reference until round 704.
* The reference was clean (parity: 87 calls, 0 unexpected; deep: 136 calls, 0 unexpected).
* **The difference, in one round only:** 6 calls of the DVD guarded wrappers returned `0xe00002d8` (kIOReturnNotReady): `dvd_setup_overlay` and `dvd_enable_deint` unbound (expected `Error`, 0xe00002bc), and `dvd_setup_overlay`, `dvd_enable_deint` x2, `setup_buffers` bound (expected success). Everything else in the round matched.
* **It did not persist:** a deep and a normal harness pass run ~90 s later were both clean (0 unexpected), the `machine_fingerprint.sh` fingerprint was unchanged (id0=[0x4] id1=[0x0], 2221852201), the kext was still at 0x588000, no panic (`panic.log` still 6718 bytes), no crashdump.
* **Watchdog (`Tools/stability_watch.sh`): no verdict other than OK for the whole run.** It was killed at the 2 h background cap and restarted with a 16 s gap (uptime and panic.log size continuous across it); part 2 ends ~13:13. The final minutes were checked by hand.
* **Likely cause (inferred from the source, not observed):** the wrappers return NotReady when `accelerator+0x80 == 0`, the "hardware up" flag that `stop_promo4_engine()` clears and `start_promo4_engine()` sets; the display-mode-change path (`ATIRadeonX1000_DisplayMode.cpp:146`) runs between them. A display reconfiguration at ~13:00 (display/screen-saver/mode event; `pmset` has display sleep and sleep both set to never) would open exactly such a window. Nothing on the machine identifies the trigger.
* **What this means for the bar:** the stock driver ran 3 h 43 min under load with no crash, hang, leak symptom or drift, but the criterion "zero STEP-DIFF in 4 h" is literally unmet, and the cause of the one difference is not proven to be external. Next step (needs a decision): rerun on a fresh boot with the console left alone; if the same kind of NotReady transient recurs, the soak should treat a *transient* NotReady on the DVD wrappers as retryable (retry the step once after ~2 s; fail only if it persists) and log each retry, which would be an explicit, recorded change to the bar.

Earlier: 150 s validation soak (8 rounds, 153 s): all rounds identical to their references, 0 failures.
