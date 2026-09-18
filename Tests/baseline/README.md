# Stock-driver baseline

`stock_4.1.9_g5_tiger.txt` is the harness's own output (`./parity_test_harness`) against
Apple's **stock** `com.apple.ATIRadeonX1000` 4.1.9 on the G5 (Mac OS X 10.4.11, xnu-792.24.17,
ATI Radeon X1900), recorded 2026-09-18 from a fresh build, AFTER the 14 call shapes that the kernel had been rejecting
were corrected to their dispatch-table shapes (see ../README.md). Two consecutive runs were
byte-identical, so the output is deterministic on this machine/state.

It is the **oracle** for parity: most calls are recorded (`[REC]`) rather than asserted, and
"parity" means the rebuilt kext produces exactly this output. Any diff is either a regression
in the rebuild or a deliberately preserved/changed vendor behaviour that needs an explanation.

Read it with these caveats (details in ../README.md):
- 87 live calls, 74 asserted against results predicted by tracing the stock bodies (`[OK]`; a different code
  would print `[UNEXPECTED]`) and 13 recorded only (`[REC]`). Some `BadArgument`/`CannotLock`/`Error`/`NoResources`
  results are the METHOD's own validation results (the wire shape matches the dispatch table); each test says which.
- Expected non-success results are meaningful, not failures: DVD calls that need a bound surface
  return `kIOReturnError` on a fresh connection (the stock body checks for it), and reading unlock
  with no lock held returns `kIOReturnCannotLock`.
- Values such as `get_config`'s VRAM sizes and `get_hw_info`'s device id are properties of this
  specific machine; compare like with like (same G5, same GPU).

Compare a new run against it with `../compare_to_baseline.sh`.
