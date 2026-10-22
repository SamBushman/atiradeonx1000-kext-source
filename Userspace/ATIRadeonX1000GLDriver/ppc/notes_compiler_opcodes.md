# GLDriver shader compiler: opcodes, OpcodeInfo, vtable slots (fork C1, continues notes_compiler_ir.md)

Same conventions as `notes_compiler_ir.md`: **CONFIRMED** = the binary shows it (data tables, a function body, a string), **INFERRED** = the role is clear from use and the
name is ours, **UNKNOWN** = left as `vslotN`. Tables generated here: `compiler_opcodes.tsv` (the opcode table), `names_F1x_C1_func.tsv` (vtable-slot function names),
`names_F1x_C1_helpers.tsv` (shared helpers), `names_C1_params.tsv` (parameters of the virtual methods). Generators: `Tools/userspace/gen_slot_func_rows.py` (vtables and
RTTI parsed from `data/*.c`, slot meanings in its `SLOTS` table).

## 1. The opcode table (CONFIRMED)

`FUN_00112f54(opcode)` returns `*(&DAT_001fc2b0 + opcode*4)`; the table is filled by the static initialiser `FUN_00115fa0` (part_036.c). For each opcode it
constructs one static descriptor object (0x14 bytes, `DAT_001fc1c0` and downwards in steps of 0x14) and stores its address in the table slot. 253 opcodes, 15..267,
every index in that range is used exactly once (0..14 are not set by this initialiser); the 253 descriptors have 253 distinct classes: `Ir<Name>`, each a subclass of
`OpcodeInfo`. `compiler_opcodes.tsv` lists opcode number, class, the descriptor fields, and what the class's virtual slots do (columns below).

OpcodeInfo object (CONFIRMED layout, 0x14 bytes):

| offset | field | evidence |
|---|---|---|
| +0x00 | vtable of the `Ir<Name>` class | static initialiser stores `PTR_DAT_xxx + 8` (a non-lazy pointer to the class vtable); the class is found from the RTTI |
| +0x04 | category (0 until `init` runs; see 1.2) | written by the `init` slot (`*(param_1+4) = N`) |
| +0x08 | the opcode number (equals the table index) | initialiser; every `inst->opcodeInfo->+8` compare in the compiler (`== 0x81`, `0x8e` ...) |
| +0x0c | `resourceClass`: scheduling resource class (0 = default, 4/5 dot products, 9 = texture fetch family, 15 = control flow, 16 = derivatives ...) | INFERRED: `FUN_001134bc` returns it (with 0 mapped through the traits bit, 0x10 handled specially) |
| +0x10 | name string, set for only two opcodes (`"SCATTER"`, `"MEM_INIT"`) | initialiser |

### 1.1 `OpcodeInfo` vtable (8 slots)

| slot | name | meaning |
|---|---|---|
| 0 | `init(info, inst, compiler)` | CONFIRMED: called by the factory path after an instruction is constructed; default empty. Overrides set `inst+0x84` (source count), `inst+0x80` (destination count), OR bits into `inst+0x14` and store the category into `info+4`. about two dozen classes override it (Ret/Dyamic*, Kill*, Mova*, Alloc*, LoopIndex, Cmp1D, WhileStart, Scatter) |
| 1 | `fold(info, result, operands)` | INFERRED: constant folder for one scalar op; writes the value to `*result`, returns 1 when folded. Add: `out = in[1] + in[2]`; Recip: `1/in[1]` unless 0; Sin, Cos, Exp, Sqrt, Log, Mul, Min/Max, F2Int ... (45 distinct implementations) |
| 2 | `foldVector(info, result, srcA, srcB)` | INFERRED: folder for the dot-product ops (Dot3, Dot4, Dot2Add and the IEEE variants) |
| 3 / 4 | `dtor` / `deleting_dtor` | GCC 4 layout |
| 5, 6, 7 | `vslot5` / `vslot6` | UNKNOWN. Slot 5 default returns 2 (Add overrides it with a 288-byte heuristic that returns 0, 1 or 2 from operand and register-count tests); slot 6 default returns 0, MovaRound(Float) return 1 |

### 1.2 Opcode categories (`info+4`, set by `init`) (CONFIRMED by the init bodies; the names are ours)

| category | `init` | opcodes |
|---|---|---|
| 0 (never set) | default | 231 opcodes (every plain ALU, fetch, predicate and conversion op) |
| 1 | numSources 0, numDests 1, flags `|= 0x18000` | 147 AllocPos, 148 AllocMem, 149 AllocColor, 150 AllocInterp |
| 2 | numSources 0, numDests 0, flags `|= 0x18000` | 15 Ret, 248 DyamicReturn, 262 DyamicReturnSwitch |
| 3 | numSources 1, numDests 1, flags `|= 0x18000` | 130 LoopIndex |
| 5 | numSources 1, numDests 1, flags `|= 0x18018`, `FUN_000ee9ac(options, inst)` | 253 WhileStart |
| 6 | numSources 1, numDests 1 | 43 MovaRoundFloat, 99 MovaRound, 100 MovaFloor, 166 MovaFlr, 192 MovaFloorGprInt, 193 MovaFloorInt |
| 7 | numSources 1, numDests 1, flags `|= 0x18`, `FUN_000ee9ac` | 78 KillE, 79 KillGT, 80 KillGE, 81 KillNE, 82 KillOne |
| 8 | numSources 1, numDests 0, flags `|= 0x18`, `FUN_000ee9ac` | 140 Cmp1D |
| 9 | numSources 3, numDests 1 | 180 Scatter |

`IRInst::isAlu` (slot 9) is true by default for categories 6, 7, 8; `IRInst::accept` (slot 7) dispatches category 7 to visitor slot `visitKill`, 6 to `visitMova`, 9 to
`visitAlu`. `IRInst+0x80` is therefore the destination count and `IRInst+0x84` the source count (`IRInst::getNumDests` / `getNumSources` return them).

## 2. Per-opcode traits records (the second table)

`*(compiler+0x30c)` is the hardware description (`HwLimits` family: `KhanPs`, `KhanVs`, `FudoPs`, `FudoVs`; chosen per shader kind by `FUN_0019ee74` from `*(compiler+0x310)[1..3]`).
Its virtual slot 91 (`+0x16c`, `getOpcodeTraits`) returns a table of 0x38-byte records indexed by opcode (`&DAT_001dca64` for the pixel kinds `KhanPs`/`FudoPs`, `&DAT_001df1fc` for the vertex kinds `KhanVs`/`FudoVs`). The accessors `FUN_00112f78 ... FUN_00113420` read one field or flag bit of the record of an opcode: word +0 bits 0, 2, 3, 6, 7, 8, 9, 10, 12, 13
(`OpcodeTraits__flagBitN`), +4, +0xc, +0x34 (fields), +0x30 (**the instruction class index**: `FUN_001043f0` passes it to the constructor table `DAT_001ea4fc`).
Bits and fields keep their numeric names: the call sites do not show a single meaning for them (for example bit 2 gates `FUN_000ecb90`'s decision together with bits 8 and 9).
The constructor table `DAT_001ea4fc` has 20 entries `{constructor, index}` (class indexes 1..20: `FUN_00107ad0` ... `FUN_00109d50`).

## 3. `IRInst` vtable (40 slots, CONFIRMED structure) and the names given to them

The vtable is 40 slots long (earlier notes counted only the slots that are overridden). Almost all predicate slots are a default `return 0` stub in the coalesced
text (`orph_1cd6xx`, 8 bytes) with exactly one subclass overriding it with `return 1`: this is how they are named. Names are INFERRED; the table is `SLOTS['IRInst']`.

| slot | name | slot | name |
|---|---|---|---|
| 0, 1 | dtor, deleting_dtor | 20 | isUndefined |
| 2 | validate (loops with dropped results = assertions compiled out; returns 1) | 21 | isProjection |
| 3 / 4 | removeFromListEx / removeFromList | 22 | isMerge |
| 5 | getNumSources (default returns +0x84) | 23 | isPresub |
| 6 | getNumDests (default returns +0x80) | 24 | isMix |
| 7 | accept (visitor dispatch) | 25 | isMov |
| 8 | acceptCallPseudo (only Start/End CallRoutine, Start/End MakeCall) | 26 | isExport |
| 9 | isAlu | 27 | isGeomExport |
| 10 | isFetch | 28 | vslot28 (default: `options&0x4000 && inst+0x98 == 0x24`) |
| 11 | isVertexFetch | 29 / 30 | isMemLoad / isMemStore |
| 12 | isTextureFetch | 31 | isPhi (IRPhiNode only; a bare `blr` returns `this`) |
| 13 | isEntry | 32, 33, 34, 35, 37 | vslot (unnamed) |
| 14 | isExit | 36 | appendSource (increments +0x84, stores the new operand) |
| 15 | isLoopStart | 38 | getKindName ("alu", "fetch", "export", "pseudo", "unknown") CONFIRMED |
| 16 | isLoad | 39 | (null) |
| 17 / 18 / 19 | isLoadTemp / isLoadConst / isLoadInterp | | |

Flag word `inst+0x14` (what the corpus shows, the rest stays unnamed): bit 0 = instruction is linked in a block (set by the constructor, cleared by
`removeFromList`; `Block::verify` loops over instructions that have it), bit 2 is cleared on the successor when the instruction is removed (`removeFromList`),
bit 9 (`0x200`) = more than five source operands (`FUN_00105e9c` grows the operand vector), `0x18000` is ORed in by the `IRPseudo` constructor and by the category-1/2/3 `init`s.
`FUN_00105594(inst, n)` returns the **instruction that defines source operand n** (field +4 of the operand record; callers read its `+0x88` opcode info and call its
methods), not a virtual-register object as the earlier notes guessed: named `IRInst__getOperandDef`.

## 4. `Block` slots 3 and 18; the visitor (`MachineAssembler`) slots

* `Block` slot 3 (`insertInstruction`): empty in `Block`, `EntryBlock` links the instruction at the head of its list (`+0x12c`) and sets `inst+0x158`.
  Slot 4 is `isFuncEnd` (FuncEndBlock only). Slot 18 (`verify`): walks the predecessor/successor vectors (`+0xd0`/`+0xd4`, the comparisons inside are empty loops: assertions
  compiled out) and the instruction list, calling `IRInst::validate`; this is the hook `Program__beginPass` (`FUN_000ed7e4`) invokes per block.
* Both `Block::accept` (slot 17) and `IRInst::accept` (slot 7) call a method of the `MachineAssembler` family (the visitor), which is how its 88 slots were named:
  `visitMemLoad` 10, `visitMemStore` 11, `visitBlock` 13 (Block default), `visitAlu` 14, `visitExport` 15, `visitExportColorAndFog` 16, `visitGeomExport` 17, `visitMov` 18,
  `visitMova` 19, `visitKill` 20, `visitKill2` 21, `visitVertexFetch` 22, `visitTextureFetch` 23, `visitLoopHeader` 24, `visitIfHeader` 25, `visitIfHeaderStatic` 26,
  `visitIfFooter` 28, `visitIfFooterStatic` 29, `visitLoopFooter` 30, `visitPostLoopFooter` 31, `visitBreak` 32, `visitContinue` 33, `visitStartCallRoutine` 43,
  `visitEndCallRoutine` 44, `visitStartMakeCall` 45, `visitEndMakeCall` 46 (slot 27 is the one visitor slot no accept method calls). `R300MachineAssembler` / `R520MachineAssembler`
  (pixel) and `R300VMachineAssembler` / `R520VMachineAssembler` (vertex) implement them: `R300MachineAssembler__visitAlu` (`FUN_001981ac`) is the ALU instruction encoder.
* `VRegInfo` slot 2 is a `clone` (allocate from the arena, copy-construct), 3..8 are the type predicates (`isInterpolator`, `isExportValue`, `isFixedValueOrVertexRegister`,
  `isTempValue`, `isLoopIndexedSet`, `isResource`).

## 5. Not established

* The meaning of the opcode traits flag bits and of `OpcodeInfo` slots 5-6; `IRInst` slots 28 and 32-37; the 93 unnamed `HwLimits` slots (only `flattenIfs` 68 and
  `getOpcodeTraits` 91 are named; the Khan/Fudo overrides of the others are real compiler passes and need to be read one by one); `ResourceModel`/`R300SchedModel`/
  `R520SchedModel` and `ThreadModel` slots (the scheduler's resource model); `MachineAssembler` slots 0-9, 12 and 34-42 and 47.
* Opcodes 0-14 and 268+ (not filled by `FUN_00115fa0`); the IL opcode numbers printed by `FUN_000ddbcc` are a different numbering (the IL token stream).
