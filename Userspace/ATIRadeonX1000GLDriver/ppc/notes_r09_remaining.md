# r09 (GLDriver): flaw fixes, pointer-slot naming, what is left

## Flaws fixed
- `0x934f0` (was `FUN_000934f0`, ledger 20 bytes): disassembly (`gld_full.dis`) is `cmpwi r3,0; beq -> li r3,1; blr; else b 0x92570` - a null-check wrapper that tail-calls `ffvpEmitSphereMapCoord`. The part_014 body was a mis-attributed full copy of 0x92570. Body rewritten (`if (allocState == 0) return 1; return ffvpEmitSphereMapCoord(allocState);`), renamed `ffvpEmitSphereMapCoordChecked`, the 29 stale local/use rows for it removed. This is the ONE intended behavioural change of the branch: the compile gate shows a difference in this function only.
- `IrMul__opcodeInfo_atexit_dtor_001fc120` destroys the record `IrMul__opcodeInfo_001fc10c` (opcode 182), not `DAT_001fc120` (a different address): renamed `IrMul__opcodeInfo_001fc10c_atexit_dtor` (name only).

## Done: `names_r09_vtable_ptr.tsv` (317 rows), `names_r09_table_ptr.tsv` (24 rows)
The 409 `PTR_` slots whose target is an anonymous `LD_<addr>` are NOT bss globals (the r07 note was wrong): 322 point at vtables in `__DATA,__const` / `__const_coal`, ~90 at tables/templates/strings. Targets still carry no name (link_corpus only names addresses that have a Ghidra symbol; there is no address-keyed row kind), so only the slots were renamed, `ptrTo_<Class>__vtable_<slotaddr>`.
Method for vtables: functions `Class__ctor*/dtor*/deleting_dtor*` that load the slot vote for their class; a class whose ctor uses exactly one slot owns it; remaining classes own their only not-yet-owned slot (base-class slots are shared by many derived dtors, e.g. 001e8f28 = OpcodeInfo, 257 voters). 316 slots + IfFooter (001e9130, `*ifFooter = slot + 8`) + R300VSchedModel (001e9110).
24 table/template slots named by the role the using code states (ilTypeToInterpSlotTable, compareCondition*Table, hwContextStateTemplate, textureFormatTable, swizzleWords* slots, ...).

## Left (with reason)
- Vtable slots 001e9108 (shared Ps/Vs base vtable, stored after the derived dtor body) and 001e9144 (FudoPs base): base class not identified. 001e9100 (12-byte "pack model" object) and 001e9148 (FudoPs sched model): class name not in the corpus.
- 001e9104 / 001e9114 (KhanPs/KhanVs `this[1]` data tables, __TEXT const) and ~45 `translateILStream` tables (001e8b74-001e8bd8 etc., targets at 0x1ac1fc-0x1aed6c): each is its own IL opcode table; role needs per-table reading.
- 001e8b8c/001eb254 (target `DAT_001aa818`), 001e9778/84/90 (`DAT_001fa5e8`), 001e8b70, 001e8c78/84 (HwLimits defaults), 001e8c60, 001e910c, 001dbdd4/3c/84, 001dc75c-78c, 001e1c34... (KhanVs/FudoVs install tables), cstring slots: roles not stated.
- The 4 vertex-type bitfield tables (0x1d92a8/9358/9408/94b8) and the remaining ~199 `DAT_`: untouched this round.
- 14 labels in ffvpEmitDirectionalLight/ffvpEmitLight/ffvpEmitSceneColor: NOT resolved. Finding so far: these calls go through `*(allocState+0x3d4) + 0x12ec/0x12f0/0x12f4` (ctx offsets in the DISASSEMBLY frame). Disassembly of gld_initContextDispatch (0xa7050) fills ctx+0x12b0..0x1324 from nl_symbol_ptr loads (`stw 0x12e4(r30)` at 0xa75c4 etc.), but the part_015 transcription writes the arb table at 0x1500-0x156c and has no 0x12xx stores - the offsets in C (+0x240?) and the disassembly do not line up yet, so the 0x12e4-0x131c slot -> function mapping is unconfirmed. Resolve that mapping first (it may also reveal a transcription gap in gld_initContextDispatch: ledger covers 0xa7050..0xa7964 but the C has no store of 0x12d4-0x1324).

## Gates (vs d252e0af)
- apply_names --check: 0 errors. datacheck.sh (base e0e55860): DATA-IDENTICAL, 92 link files, 1677 symbols. No `quota|No space|compared 0` in the logs.
- compile gate: NOT-EQUIVALENT, by design and only in part_014: `FUN_000934f0` LENGTH (the rewritten 20-byte wrapper) plus PIC/branch local-label renumbering in the functions after it (gate prints at most 12 lines per part; the 11 shown are all label-number-only). Every other part: 0 problems.
