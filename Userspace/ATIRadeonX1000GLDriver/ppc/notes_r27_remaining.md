# r27: part_009/011/013 placeholder sweep (GLDriver)

Scope: all 23 functions `ph.py` reported as still carrying Ghidra placeholders in part_009.c/part_011.c/part_013.c, as of main 5e688020. All 23 are now named (113 renames total, 2 gated batches, both IDENTICAL).

## Method
Most placeholders in this range are one of two idioms already seen elsewhere in the corpus:
- `in_rN` / `extraout_r4(_NN)`: never assigned, forwarded unchanged into a callback/vtable/commit call that for this call site doesn't read the trailing word -> `staleArgRN`, or (when it's the "leftover r4 right after a call, immediately copied into an existing named local") `calleeStaleR4(_NN)`.
- `fparam_N` / `in_fN` / `in_stack_fffffXX` float args forwarded unread to a deeper callee -> `unusedFloatArgN` (matches sibling `ffvpValidateProgram`'s existing convention) or, when the function already has its own `fprFN` formal-parameter sequence, `fprFN` extended (renamed `fprF9Stack` etc. to avoid colliding with the real parameter of the same number - see "accepted hybrids" below).

## Accepted hybrids (one joined name, not split)
- `arbValidateProgram` `in_r7`/`in_r8` -> `scratchR7`/`scratchR8`. Three disjoint roles on one register pair: (1) ~L1728/1759 a typeTagTable-derived pointer argument to `arbfpInternParameter` (CONFIRMED), (2) ~L1823-2103 low/high half of a 64-bit "read register usage" bitmask accumulator, structurally parallel to the already-named `writtenLo`/`writtenHi` pair tracking writes (INFERRED from that parallel), (3) ~L2176 unread varargs padding to a `printf_LDBLStub`-style error stub whose format string only consumes 2 args. Not split: all three regions are reachable from a shared `goto storeX00001124` error path, and the tooling's `from`/`to` anchors would have to thread that goto graph exactly; given 70 total occurrences across a 1200-line function, accepted as one name per the project's register-reuse precedent.
- `ffvpSelectLitProgramVariant` `in_r5`/`in_r6`/`in_r7`/`in_r8` -> `scratchR5..R8`. `in_r5` has two distinct real definitions (the `ffvpBuildProgram(...)` result forwarded into `fpVariantCacheInsert`, and later a field of `variant` forwarded into a vtable call); `in_r7`/`in_r8` are only actually read at the `fpVariantCacheInsert` call (the second call site re-passes `variantKeyHeader`/`variantKeyWords[0]` directly instead of these copies, so the copies are stale there, not meaningfully reused).
- `ffvpSelectPassThroughVariant` `in_r9` -> `scratchR9`. Assigned and consumed twice in disjoint branches (a `variantKeyFlags` bit contribution, later a register-offset term).
- `extvsPrepareHardwareProgram` `in_r7`/`in_r8` -> `slotFlag`/`slotScanCursor` (from batch 1). Reused across ~5 structurally similar slot-allocation branches; `in_r8` briefly holds a byte-offset snapshot that's dead before being overwritten into a loop counter in the same branch.

None of these four are provable splits without deep goto-graph-aware `use`-row anchors; a future pass with more time budget could attempt `arbValidateProgram` first since its three roles are the most clearly textually separated.

## Gate results
- Batch 1 (6 functions, commit 80fbfb25): VERDICT IDENTICAL.
- Batch 2 (17 functions, this commit): VERDICT IDENTICAL.
Both are pure whole-variable renames (no `use`-row splits), so byte-identity was expected and held.
