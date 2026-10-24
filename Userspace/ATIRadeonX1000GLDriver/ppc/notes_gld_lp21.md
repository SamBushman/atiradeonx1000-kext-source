# GLDriver parts 019-026 (fork lp21, tag gU): what was learned

Evidence tiers as in the other notes: CONFIRMED = read from code/data, INFERRED = role clear from use.

## FUN_000fd5c8 = the IL -> IR translator loop (INFERRED name; not renamed, address kept)
Caller (part_024, after building the Entry/Exit blocks) passes `program` (the Program of notes_compiler_ir.md 5.1) and `ilReader`.
* `program` fields used here: +8 Compiler, +0x30 flags (bit0 pixel?, 0x2000, 0x4000, 0x40000 ...), +0x78 table of 0xc-byte per-IL-register records
  ({kind, usage, ...}), +0x7c highest IL register, +0x84 register bitmap, +0x8c/+0x90 vectors, +0x3a0 entry block, +0x3a8 exit block,
  +0x3ac register map (first argument of FUN_00127608(regMap, file, index, 0) -> virtual register), +0x3c4 instruction vector, +0x3d8/+0x3dc and
  +0x3e8/+0x3ec lowest/highest register seen (two files), +0x414 vector.
* Compiler: +0x374 arena A, +0x378 arena B, +0x30c hardware description (+0xc = table of 0x24-byte per-IL-opcode records, record+0x18 = template stream),
  +0x3ac **counts temporaries downwards**: `idx = compiler[0x3ac] - 1; compiler[0x3ac] = idx` allocates a fresh temporary register (`newTempIndex`).
* `ilReader` (the object FUN_000e5e70 fills): +0x8d register byte, +0x8e current opcode (<0xbf, FUN_000e4408 clamps it), +0x7c state, token words from +0x8c
  (`tokenWords`), [0x16] operand-token count, [0x19] destination operand array, [0x1b] source operand array. Case labels of the outer switch are AMD IL
  opcodes (notes_shader_formats.md 5: 0x27 else, 0x29 endif, 0x2a endloop, 0x24 dst ...).
* Operand record (IRInst__getOperandRecord, 0x18 bytes): +8 register index, +0xc register file, +0x10 select word.
* Block-family allocations: 0x130 Block, 0x134 Block__ctor_ea148, 0x138 Break/Continue, 0x15c IfHeader/PostLoopFooter; IRInst allocations are 0x168
  (arena word + object); growable vectors are 0x14 (arena word, capacity, count, data, arena) with a separate 8-byte first data block.
* Stacks (vector header: capacity, count, data pointer): `ifStack` (IfHeader blocks, popped by endif), `conditionStack` (3-word records {temp register,
  counter, 0}), the loop stack (puVar13). IR opcodes made here by number come from compiler_opcodes.tsv (0x31 IrMovFloat, 0x14 IrMulAddFloat,
  0x13 IrMulFloat, 0x12 IrAddFloat, 0x40 IrRecipIEEE, 0x1b IrCube, 0x73/0x72 IrSetGradientsV/H, 0x78 IrFetchTextureMapGradients, 0xbe IrRoundNearestEven).
* The old name `arena` for uVar46 was a misnomer (72 webs: compiler arena A / B, register file, register map, virtual register, vector storage ...):
  split into those roles (names_gU_1.tsv).

## Fixed-function pixel shader emitters (part_019): ffps*
* Caller (part_016 ~8700): per texture unit u (loop to min(ctx[0x13b2], ctx[0x2b])) it calls ffpsEmitTexEnvCombine when the unit mode is GL_COMBINE
  (0x8570) and ffpsEmitTexEnvLegacy otherwise, with `(ctx, ilBuilder, baseFormat = tex->+0x38, texEnvMode = unit record +0x450, unit, textureObject,
  isFirstUnit, previousUnit)`. `ctx[0x13b2]` is `textureUnitCount`; the result temp of unit u is `u + textureUnitCount`; source token 0x120000 =
  colour 0 input, 0x40000|reg = temp. IL builder: count +4, capacity +8, tokens +0xc, grown with the context allocator callbacks ctx+0xc / ctx+0x18.

## Pitfalls met (also in Tools/userspace/lpnames/README.md)
* `arena`-style whole-function names on reused variables hide behind the placeholder counters; check names that cover 20+ webs (`lw2.py`).
* `webspec.py` (new): rule-classified webs -> seg.py specs; chain webs (`x = f(x)`) are split at the chain line with lhs/rhs; weak rules (`~name`) for
  default defs; use rules (`@name`) classify a web by any of its lines (constructor called on it). `uniq_names.py` makes names unique per function (also against
  names already applied). `seg.py` now handles a single line taken on one side only.
