# q08 (GLDriver parts 047-067): what is left, and why

State after the last q08 gate: 4317 -> 150 placeholders (81 of them in_rN) (wide regex over non-comment lines); every remaining item is one of:

1. `in_r5..in_r8` (81 occurrences): Ghidra register-argument artifacts of indirect calls (`(**(code **)(*this + 0x15c))(this,a,in_r6,in_r7,in_r8,...)`). They are not variables of the original program; deliberately not named.
2. `FUN_xxxxxxxx` calls to functions DEFINED in other forks' ranges (renaming them from q08 would collide with that fork's own `func` rows):
   - part 021: FUN_000e2bf4; part 025: FUN_000f370c, FUN_000f32cc; part 042: FUN_00146788; part 043: FUN_0015546c, FUN_00155654, FUN_00148d8c; part 044: FUN_00165604, FUN_00162dfc, FUN_00160eb0, FUN_0015f44c, FUN_00159b58; part 045: FUN_00172204;
   - part 046 (the 0x1764xx..0x175b40 helper block): FUN_00174ce0 (lane record allocator, 9 refs), FUN_00174e0c (2764 bytes, ValueKey constructor chain, 6 refs), FUN_00175b40, FUN_00176534/564/574/5a4 (small predicates), FUN_0017629c, FUN_0017662c, FUN_00176?? lane-relation helpers (d6c, e20, ec0, 954, 9f4, a94, c40, 6bc, 7d8, 8d4, 72c, 4e0). q07 owns those; q08 only references them.
3. Hybrid/stack-overlay cases already named whole-variable (documented in the rows' evidence): fake frames `laneInputs`, `fillVec4`, `packState`, `destRecordCopy*`, `immediateHigh/Low` ...
