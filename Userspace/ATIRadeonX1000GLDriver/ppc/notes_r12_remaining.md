# r12 (GLDriver): resolving the r09/r11 leftovers

Rows: `names_r12_data.tsv` (40), `names_r12_pools.tsv` (~124, TEXT __const pool words), `names_r12_tables.tsv` (82), `names_r12_misc.tsv` (9).
Tooling change: `Tools/userspace/link_corpus.py` now defines a `gld.json` `data_anchors` entry under its renamed label when a `data` row renamed the Ghidra name (the anchors are keyed by the Ghidra name).

## Resolved
- **PIC-base anchors** (`constPoolAnchor_<addr>`: 001ab134, 001acec0, 001ad5d8, 001ada48, 001b2eb8, 001b40f0, 001b81b8, 001e3520, 001e3a54, 001f3a54, 001db440, 001f8514) are not objects: they are gcc `addis`/`addi` bases (sign-extended low halves, e.g. 0x9f3c is negative) from which constants hang at fixed offsets. `extvsOpEmitFuncTableBase_001b9d04` = 0x1dbb0c - 4*0x8782, the biased base of `extvsOpEmitFuncTable_001dbb0c` (index = GL op token - 0x8782). CONFIRMED by the offset arithmetic against the disassembly (`gld_full.dis`) and the existing `data_anchors` bases.
- **Class/range tables** 001e6134..001e61e8 (ValueKey fold/canonicalize): sign/compare codes 1 <0, 2 <=0, 3 =0, 4 >=0, 5 >0; range classes 1={1}, 2={0}, 3={-1}, 4=[0,1], 5=[-1,0]; instruction +0x120 is the clamp flag, flag bit0 negate, bit1 abs. `compareFoldResultTable_001e61e8` is 6x8x6 (0 unknown / 1 false / 2 true).
- **Vtable slots**: 001e9100 = ThreadModel, 001e9108 = HwLimits, 001e9144 = KhanPs, 001e9148 = R520SchedModel (slot target + 8 equals the named `ptrTo_X__dtor_` label; FudoPs : KhanPs : HwLimits). 001e9104/001e9114 are the KhanPs/KhanVs HwLimits `this[1]` tables (INFERRED from the lookupTableEntry users).
- vertex-type tables 001d9b70..001d9dac, EXT swizzle tokens, FFVP tables, psn control-flow table, `vsHardwareTable_field*` (fields patched by Khan/FudoVs `vslot96_installHardwareTables`), the nl_symbol_ptr template/table slots, `interpolatorBucketTable_001fc1f0`, the TEXT constant-pool words (`laneWord*`, `floatWord*`, `constWord*`).
- Verification: 0 remaining `(DAT|UNK|PTR|LAB|switchD)_<addr>` placeholders in part_*.c, decls.h, extra_decls.h, data/*.c, symbol_map.tsv; datacheck DATA-IDENTICAL (92 link files, 1677 symbols); `apply_names --check` 0 errors.

## Oddities (kept, documented)
- `rangeClassAfterClampTable_001e6158` maps class 3 (-1) to 1, not the 2 a [0,1] clamp would give. Name states the use, content is as the binary has it.
- `compareClassAbsTable_001e61a0`, as used under the clamp flag, has the same content as the abs table 001e61d0; the name reflects content, not the call site.

## Still unnamed (reason)
- Targets of the `ptrTo_*` template/vtable slots are anonymous `LD_<addr>` objects: link_corpus has no address-keyed naming, so only the slots carry names (r09 finding unchanged).
- `unowned_code/part_000.c` labels `LAB_00040524..` (8) and ~192 `FUN_` cross-range references: out of scope of this directive (code labels / callee refs, not data).
- Tier: names derived by offset/vtable arithmetic are CONFIRMED; names derived from user-code role only (HwLimits tables, template-case slots, lane/float word groupings) are INFERRED, as stated per row.
