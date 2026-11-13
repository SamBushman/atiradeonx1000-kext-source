# GLDriver shader-compiler graph specs (fnfuzz `FNFUZZ_PROFILE=graph`)

Per-family object-graph specs for the rows the generic profiles never made informative (every trial faulted in both images).

* `common.txt` - the shared types: `COMPILER` (share: one per function), `ARENA` (share, the compiler's +0x374 arena), `ARENAB` (+0x378), `PROGRAM` (share), `TARGET`/`TVT`/`OPFLAGS`/`BITSET`, `BLOCK`/`LEAF` with real successor/predecessor vectors (`VECA` = header word at -4, capacity, count, data, arena).
* `gen.py FAMILY_REGEX OUT COMMON` - writes `OUT` = common types + one `func` block per row of `~/g5logs/.../uninf_obj.txt` matching the regex (arg named `compiler` -> COMPILER, other args -> BLOCK; per-function overrides in `OVR`).
* `blk1_spec.txt`, `blk1_<image>.tsv` - the Block family spec and its ledgers. `voidrows.txt`: rows compared as void (C++ destructors and one void function whose r3 is a dead leftover; see EVIDENCE_fnfuzz.md).
* `blk_run.sh PREFIX TRIALS`: runs the spec on the new and the control image with `FNFUZZ_PRECALL=Compiler__initStaticLocals` (fills `opcodeInfoTable`; must run before the interposer stubs are installed). `nf.sh` / `nfh.sh` / `faults.sh`: first fault of a row (gdb; `nfh.sh` interrupts a spinning row).
* fnfuzz.c spec additions used here: `type NAME SIZE share`, `self DST DELTA`, `ptr OFF TYPE PCT DELTA`, `objfill`.
