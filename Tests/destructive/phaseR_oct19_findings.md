# T3 Phase R full run, Oct 19 2026 (tip 06f8492, rebuilt vs stock, one test per boot)

27 of 27 tests ran. No hang, no panic (`/Library/Logs/panic.log` unchanged at 223340 bytes throughout). `t3_phaseR_one.sh` compared each result with the recorded Phase S log: 20 identical, 7 flagged.

The recorded Phase S logs date from Oct 2. Sources of `dvd_images`, `dvd_lock_buffers`, `dvd_write_regs_scratch` (Oct 5), `gl_set_stereo_enable` (Oct 6) and `gl_read_buffer` (Oct 13) changed afterwards, so those diffs were not like for like. Each flagged test was therefore re-run with the CURRENT binary on hot-swapped stock (`Tools/t3_stock_rerun_one.sh`, same procedure, fresh boot) and compared with the rebuilt run:

| Test | Phase S diff | Re-run on stock with current test | Verdict |
|---|---|---|---|
| dvd_images | extra NOTE lines (newer test) | identical to rebuilt | no divergence |
| dvd_lock_buffers | different call shapes (newer test) | identical | no divergence |
| gl_set_stereo_enable | newer test (liveness checks, EXPECTED-REJECT) | identical | no divergence |
| surface_locks | returned address 0x3812000 vs 0x3810000 | identical | no divergence (allocation placement) |
| surface_read | first row bytes | stock varies run to run (ff ff ff / 83 41 24 / 81 40 24 / 83 41 24), rebuilt 80 3f 23 / a5 6c 3f, same range; extent identical (16 changed, 0 outside) | no divergence: test never writes the surface, content is live |
| gl_read_buffer | first row bytes | stock itself changed (ff ff ff Phase S, 4a 4d 41 re-run), rebuilt b8 53 22; extent identical | no divergence, same reasoning as #158's byte caveat |
| dvd_write_regs_scratch | different test (Phase C writes) | both sides fail the test's own "0 registers differ" check: stock 14/15/16/16 registers, rebuilt 15, all from the same volatile set (0x34, 0xa8, 0xac, 0x340, 0x3b8/0x3d8, 0x594, 0x7d4, 0x7e0, 0x1fc0-0x1fdc); rebuilt set is within stock's union | no divergence; the test's criterion is too strict for volatile registers (stock fails it too) |

Evidence: `~/g5logs/final_eval/t3/` (t3_phaseR = rebuilt runs, t3_phaseR_stockrerun = stock re-runs, summaries, diffs). Caveat: the harness' save step overwrote most per-repeat rebuilt files (only the last repeat survives per test), so rebuilt repeats are thinner than the stock ones.

Harness lessons: after a reboot the SonnetSATA card sometimes fails its OOB sequence and Test HD never mounts (a round of six runs failed instantly on Oct 19 19:00); both T3 scripts now wait for Test HD, and the Phase 6 driver should recheck it.
