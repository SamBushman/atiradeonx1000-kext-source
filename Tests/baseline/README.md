# Stock-driver baseline

`stock_4.1.9_g5_tiger.txt` is the harness's own output (`./parity_test_harness`) against
Apple's **stock** `com.apple.ATIRadeonX1000` 4.1.9 on the G5 (Mac OS X 10.4.11, xnu-792.24.17,
ATI Radeon X1900), recorded 2026-09-18 from a fresh build. Two consecutive runs were
byte-identical, so the output is deterministic on this machine/state.

It is the **oracle** for parity: most calls are recorded (`[REC]`) rather than asserted, and
"parity" means the rebuilt kext produces exactly this output. Any diff is either a regression
in the rebuild or a deliberately preserved/changed vendor behaviour that needs an explanation.

Read it with these caveats (details in ../README.md):
- 12 of the 25 non-precondition live calls return `kIOReturnBadArgument`: the kernel's own
  argument-count check rejected the wire shape, so those calls did NOT execute their method
  bodies. They only prove the kernel still rejects that shape.
- Only ~13 live calls reach a real body (10 `Success`, plus `CannotLock`/`Error` results).
- Values such as `get_config`'s VRAM sizes and `get_hw_info`'s device id are properties of this
  specific machine; compare like with like (same G5, same GPU).

Compare a new run against it with `../compare_to_baseline.sh`.
