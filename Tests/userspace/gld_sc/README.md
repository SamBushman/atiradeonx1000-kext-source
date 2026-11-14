# GLDriver shader-compiler graph specs (fnfuzz `FNFUZZ_PROFILE=graph`)

Per-family object-graph specs for the rows the generic profiles never made informative (every trial faulted in both images).

* `common.txt` - the shared types: `COMPILER` (share: one per function), `ARENA` (share, the compiler's +0x374 arena), `ARENAB` (+0x378), `PROGRAM` (share), `TARGET`/`TVT`/`OPFLAGS`/`BITSET`, `BLOCK`/`LEAF` with real successor/predecessor vectors (`VECA` = header word at -4, capacity, count, data, arena).
* `gen.py FAMILY_REGEX OUT COMMON` - writes `OUT` = common types + one `func` block per row of `~/g5logs/.../uninf_obj.txt` matching the regex (arg named `compiler` -> COMPILER, other args -> BLOCK; per-function overrides in `OVR`).
* `blk1_spec.txt`, `blk1_<image>.tsv` - the Block family spec and its ledgers. `voidrows.txt`: rows compared as void (C++ destructors and one void function whose r3 is a dead leftover; see EVIDENCE_fnfuzz.md).
* `blk_run.sh PREFIX TRIALS`: runs the spec on the new and the control image with `FNFUZZ_PRECALL=Compiler__initStaticLocals` (fills `opcodeInfoTable`; must run before the interposer stubs are installed). `nf.sh` / `nfh.sh` / `faults.sh`: first fault of a row (gdb; `nfh.sh` interrupts a spinning row).
* fnfuzz.c spec additions used here: `type NAME SIZE share`, `self DST DELTA`, `ptr OFF TYPE PCT DELTA`, `objfill`.

## sra spec series (Program / RegAlloc / Scheduler rows, #273 follow-up, Nov 13)
* `sra4_spec.txt` = common types + one `func` block per row; types added on top of `common.txt`: `IRINST` (real IRInst vtable via `dval ptrTo_IRInst__vtable_001e8b4c 8`, operand counts / register-file kinds bounded to the `regKindInfoTable` range 0..48), `VPOOL`/`HTAB`/`HBUCKETS`/`VKEY` (the program's VReg pool: hash table with `fnq` hash/equality callbacks, `*pool` = the COMPILER), `DNODE` (block list sentinel at BLOCK+0xcc). Ledgers (`sra4_<image>.tsv`) are per image; `Program__insertEntryInst` is class `v` (void: its r3 is a dead leftover).
* `fault_summary.py LOG`: where each row's stock trials end (faulting function / caller / wild branch target) - tells which structure the next spec step must add. Needs the fault backtrace breadcrumbs (`W fault ... bt`, harness gs68+).
* Run with the guard on (default); `lrun.sh sra4 40 [ROWFILTER]` writes `sra4_gs68.log`. Rows that fault/branch wild on every trial print `UNINF`.
