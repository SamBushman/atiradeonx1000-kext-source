# r13 (GLDriver): the r12 "still open" items

Rows: `names_r13_targets.tsv` (377 `target` rows), `names_r13_misc.tsv` (4 chained `data` rows). Edit: 8 `LAB_` labels renamed in `unowned_code/part_000.c`.

## New: `target` row kind (address-keyed naming of anonymous link objects)
`target<TAB>LD_<hex address><TAB>NEWNAME<TAB>tier<TAB>evidence` names an object the link layer labels `LD_<address>` (an object only data words reach: a vtable, a template, a table, a zerofill global). `Tools/userspace/link_corpus.py` `ld(addr)` returns the row's name instead of `LD_<addr>` for the label in data.s, the `.zerofill`/`.set` forms, the data_anchors `.set`, and every pointer word / symbol_map "pointer ->" value. `apply_names.py` (`load_targets`) validates the rows (unique old/new, new not already a corpus identifier; counted as applied) and rewrites nothing, since LD_ never occurs in the C corpus. `funcmap.py --link` adds `new -> LD_<addr>` so `datacheck.sh` maps the link output back and must still say DATA-IDENTICAL.
The labels stay non-global (as LD_ was); only the name changed.

Targets named: the 377 anonymous targets of the 623 `ptrTo_*` nl_symbol_ptr slots (317 vtable slots of r09, 24 table slots of r09, r12's template/table slots). Name = the slot's class/role + the TARGET address (`DListNode__vtable_001f1008`: a vtable whose entries start at +8, so the C++ `vtable` pointer stored is target+8; `rendererLibraryState_001fc6e0`). Tier is the slot row's tier (31 CONFIRMED, 346 INFERRED). The other 7 slots point at objects that already carry a name; no vtable/table target is shared by two slots.

## Resolved
- `ptrTo_KhanPsHwLimitsTable_001e9104` / `ptrTo_KhanVsHwLimitsTable_001e9114` -> `...IlTypeToRegisterFileTable...` (CONFIRMED). The slot value is stored to HwLimits `this[1]` by the KhanPs ctors (part_039 712/753) and KhanVs ctors (1743/1786); the reader of `*(compiler+0x30c)->[1]` is `Program__registerFileOfIlType` (part_024 109): `registerFile = tbl[ilType*8 + 4]`, -1 -> `Compiler__fail(0xf)`. Records are (ilType, registerFile) pairs (data: 0,3, 1,2, 2,4, 3,0x25 ...; Ps and Vs differ at ilType 5 and 7).
- `rangeClassAfterClampTable_001e6158` -> `rangeClassAfterSaturateTable_001e6158`, `compareClassAbsTable_001e61a0` -> `compareClassAfterSaturateTable_001e61a0` (CONFIRMED use): the `+0x120` flag they are gated on is the SATURATE flag (notes_compiler_passes3.md: PVS VE_SAT/ME_SAT, set by `Inst__collapseClampToSaturate`), not a generic clamp. Content oddities are the binary's own and are kept: class 3 ({-1}) maps to 1 although saturate(-1)=0 would be class 2, and the compare-class table under saturate equals the abs table.
- `unowned_code/part_000.c` `LAB_` (8): `orph_40a9c` / `orph_40ac0` are copies of the bodies of fragmentTranslateScalarMath(Body) / fragmentTranslateScalarMath2Src, so they take the labels r03 already gave there (checkComponentCount{,2,3}, checkRepeatCount{,2,3}, setTempRegister). `apply_names` does not process `unowned_code/`, so this is a direct edit; the link output differs only in `x_unowned_code_part_000.c`.
- The ~192 `FUN_` references: every one is an `asm(".globl FUN_x"); asm(".set FUN_x, _Name")` alias pair (by design, see apply_names docstring); there is no other `FUN_<addr>` token in any part_*.c / decls.h.

## Left
- Targets of slots whose class/role is only INFERRED stay INFERRED.
- The ~1,370 other `LD_` labels (the targets of non-nl_symbol_ptr data words: jump tables, string-pool interiors, sub-object interiors) are not named; they have no slot row to take a role from.
