# PP shader optimizer data layouts recovered while naming part_018 / part_019 (libGLProgrammability, Tiger PPC)

Source of every entry: the functions named in `names_lpG_ds*.tsv` (part_018.c register allocator and containers, part_019.c loop passes, constant folder, PP assembler parser).
Tiers: CONFIRMED = the code shows it; INFERRED = role clear from use.

## Containers (part_018.c)

* `BitSet` (0xc bytes): `+0 sizeInBits, +4 byteSize, +8 words*` (`_BitSetNew`, `_BitSetSetSizeEquals`).
* `HashSet` (0x10): `+0 bucketCount, +4 buckets*, +8 hashFunction, +0xc equalsFunction`; bucket = 8 bytes `{entryCount, entries*}`; the callbacks are called with extra stale register arguments (`unusedArg5..8`, Ghidra shows them as parameters). `HashTable` = 4-byte wrapper around a HashSet whose entries are pointers to 8-byte `{key, value}` pairs. HashSet iterator = `{hashSet, bucketIndex, entryIndex}`.
* Default callbacks: `DAT_a7b7bf70` -> `_defaultHashFunction`, `DAT_a7b7bf6c` -> `_defaultEqualsFunction`; `DAT_a7b7bf7c/80` = `_regEqualsFunction`/`_regHashFunction`, `DAT_a7b7bf74/78` = instruction-index equals/hash (see `link/symbol_map.tsv`).

## Register allocator program (part_018.c)

`Program` (0x44 bytes, `_ProgramNew`): `+0 stream, +4 blockCount, +8 blocks (0x2c-byte records), +0xc registerCount, +0x10 registers (0x2c-byte records), +0x14 labelCount, +0x18 blockByLabel[], +0x1c..+0x2c first record index per bank, +0x30..+0x40 end record index per bank`. Banks: 0 attrib bindings (stream +0x18), 1 temp usages (+4), 2 param bindings (+0x10), 3 output bindings (+0x1c), 4 address usages (+0xc). Four component records per register (`_RegisterAdd`), record index = bankFirst + registerIndex*4 + component (`_GetRegister`).

`Register` record (0x2c): `+0 index, +4 stream register number, +8 interference BitSet*, +0xc component, +0x10 type bits, +0x14 bank, +0x18 excluded flag, +0x1c/+0x20 fixed flags, +0x24 use count, +0x28 stream usage chunk`.

`Block` record (0x2c): `+0 instructionCount, +4 instructions* (0x1c-byte records), +8 predecessorCount, +0xc predecessors*, +0x10 successorCount, +0x14 successors*, +0x18 liveOut BitSet, +0x24 gen BitSet, +0x28 kill BitSet` (+0x1c, +0x20 allocated BitSets not named).

`Instruction` record (0x1c): `+0 sourceCount, +4 sources (Register*[]), +8 destCount, +0xc dests, +0x10 required flag, +0x14 removed flag, +0x18 stream operation chunk`.

## Stream usage lists (PPStream, from `_PPStreamCreate` and the `_PPStreamAdd*` functions)

`+4 tempUsages, +8 tempUsageArrays, +0xc addressUsages, +0x10 paramBindings, +0x14 paramBindingArrays, +0x18 attribBindings, +0x1c outputBindings, +0x20 operations, +0x24 labels, +0x28 rasterOps, +0x2c constants, +0x30 options`. Usage chunk word `+0xc`: precision bits 31..29, type 28..26, size 25..24 (`_glpWriteSizeTypePrecision`); register number is the ushort at +0x12 (array chunks: first/last at +0xe/+0x12).

## Operation / operand words (stream operations, 14-word record)

Word `+0xc`: opcode bits 25..18, source count bits 31..29. Source operand = 8 bytes at `+0x1c + 8*i`: bit 31 indirect, bits 25..23 bank, bit 14 / bits 13..12 array access, register number ushort at +0x22. Destination words `+0x14` (bank bits 19..17, write mask bits 16..13, extent bits 11..10) and `+0x18` (register number low half, bit 31 indirect). Branch target / label in `+0x10` bits 17..0; operations are linked list nodes (`+4` prev, `+8` next).

## RegInfo (10 words, 0x28 bytes; `_GetRegisterTypeInfo`, `_GetOpRegs`)

`[0] register number, [1] bank (500 = unused), [2] precision, [3] type (1 float, 3 int), [4] size, [5] isConstant, [6..9] constant xyzw`. `_GetOpRegs(stream, op, sourceInfos[4], destInfo)`.

## Loop passes (part_019.c)

* `_DetectConstantLoopsSimple`: `MOV counter,init; WHILE; SLT/SLE/SGT/SGE cond,counter,limit; NOT; IF ... ENDIF; ... ADD/SUB counter,counter,step; ENDWHILE` with constant integer init/limit/step becomes `REP count`; the count is computed by nine inserted operations (opcodes at `DAT_97c3aa40`: 0x6c x3 (MTC), 0x20 SUB, 0x3a DIV, 0x03 CEI, 0x22 MUL, 0x31 SEQ, 0x1f ADD; source counts at `DAT_97c3aa64`: 1 1 1 2 2 1 2 2 2).
* `_UnrollConstantLoopsSimple` / `_RepifyConstantLoopSimple` / `_UnrollConstantLoopSimple`: REP with known count is repified or unrolled; unknown count gets SLE, IF, BRK, ENDIF, SUB around the body (tables `DAT_97c3aa88..ac`).
* `_FlattenIfs` / `_FlattenIf`: IF/ELSE/ENDIF become straight-line code: condition temps (MOV and NOT of the IF condition), per-branch register renaming to temps (HashTable original -> temp), KIL ANDed with the condition, temps initialised from the originals, merged back after ENDIF with CMP.
* `_ConstantPropagateFold` / `_EmulateOp`: known-constant RegInfo set; indirect addresses with constant address registers are folded; operations are evaluated at compile time.

## Naming rules learned

* Stack scalars that Ghidra splits out of one address-taken struct or array (`local_1a0..local_190` as the RegInfo key / iterator / operation record, `local_90..local_5c` as the op record) must not be split with `use` rows: new declarations move them and break the contiguous layout (the gate reports LENGTH / UNINIT). They get one honest hybrid name instead.
* A new name must not be a C keyword (`register`) nor collide with decls.h (`operation`, `size`).
* Do not chain a `local`/`use` row on a name another row already produced: the anchors of the old rows are normalised through the new name and stop matching; retarget the old row (edit its `new` field) and rename the text instead.
