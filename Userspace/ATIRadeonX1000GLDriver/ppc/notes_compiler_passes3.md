# GLDriver shader compiler, round 4 (fork E3): constant folding, value transforms, use-vector scans, loops, field scopes

Continues `notes_compiler_passes.md`, `notes_compiler_passes2.md`, `notes_compiler_ir.md`, `notes_compiler_opcodes.md`. Tiers: CONFIRMED = the code or a string shows it, INFERRED = our reading, UNKNOWN = not decoded.
Tables: `names_E3_fold.tsv`, `names_E3_misc.tsv`, `names_E3_loops.tsv`, `fields_compiler.tsv`, scopes `prog_scope.txt` / `comp_scope.txt`.

## 1. Per-opcode constant folding (`OpcodeInfo` slots `fold` and `foldVector`) — CONFIRMED

`fold(this, result, operands, compiler)`: `operands` is a float array whose elements 1..3 (`operands+4/+8/+0xc`) are the constant source lanes, `result[0]` receives the folded lane, return 1. `compiler` (4th argument,
used by Cos and Sin only) gives access to the target description `*(compiler+0x30c)` whose slot `0xe0` converts the R5xx angle unit to radians. `foldVector(this, result, srcA, srcB[, addend])` folds the dot products on whole
four-lane arrays. The constants in the literal pool were read from the binary: `FLOAT_001aa0d4` = 0.0, `FLOAT_001aa0e8` = 1.0, `DOUBLE_001aa200` = 1.0, `DOUBLE_001aa2a0` = 2.0.

| class | what it folds (as decoded) |
|---|---|
| `IrCos__fold`, `IrSin__fold` | x = 0 gives 1/0 (cos/sin); x = 1.0 gives 0/1.0 (the R5xx angle unit is a quarter turn: sin(1.0) = 1); otherwise `cos`/`sin` of the converted angle |
| `IrLogInternal__fold` | log2(|x|) as `logf(|x|) * (1.0 / ln 2)`; x = 1.0 gives 0.0; x = 0 leaves the result unchanged |
| `IrRecipSqrtInternal__fold` | 1.0 for x = 1.0, `1.0 / sqrt(x)` for x > 0, no result for x <= 0 |
| `IrRecipInternal__fold` | `1.0 / x`, no result for x = 0 |
| `IrSqrt__fold` | x for x = 0 and x = 1.0, `sqrt(x)` for x > 0, no result for negative x |
| `IrExp__fold` | `pow(2.0, x)`, 1.0 for x = 0 |
| `IrMulFloat__fold`, `IrMulAddFloat__fold` | multiply with the hardware rule 0 * anything = 0 (`FUN_00113554`), plus operand 3 for the mad |
| `IrFloorFloat__fold`, `IrFractFloat__fold` | `floor(x)`, `x - floor(x)` |
| `IrInt2F__fold`, `IrUInt2F__fold` | the usual magic-double conversion (0x43300000 high word minus 2^52 + 2^31 / 2^52) |
| `IrCndEFloat`, `IrCndGEFloat`, `IrCndGTFloat` | select operand 2 or 3 by `x == 0`, `x >= 0`, `x > 0` of operand 1 |
| `IrSetGTFloat__fold` | 1.0 when operand 1 > operand 2, else 0.0 |
| `IrDot3/Dot4/Dot2Add__foldVector` | sum of the lane products (each product with the 0 * x = 0 rule); Dot2Add adds the third source |

## 2. Value-numbering transforms behind `OPT_VALUE_TRANSFORMS` (9) — INFERRED names, CONFIRMED structure

All three take the `ValueKey` (notes_compiler_passes2.md section 2: `+0xb0` instruction, `+0x238` compiler, `+0x168 + 0x10*i + 4*lane` lane value numbers, negative value numbers are constants resolved with
`Compiler__exprRecordForValueNumber`) and return 1 when they changed the instruction. Their first parameter was called `ctx` by the mechanical rules and is now `key`.

* `FUN_00180250` = `ValueKey__canonicalizeConstantSources`. For the texture-kill instruction (`IrFetchTextureMapKill`, opcode 0x77: kills when any coordinate is < 0) it reads the constant lanes of source 1: lanes that can never
  kill are neutralised, and when a lane is a negative constant (the instruction always kills) all but one such lane are neutralised. The rest is a canonicalisation of constant sources to values the target accepts
  (HwLimits slot `0x104`, compiler constant table `PTR_DAT_001e8b8c`).
* `FUN_0017b12c` = `ValueKey__mixLiteralSources`. Needs `OPT_CONST_FOLD_LITERALS` (0xb) and `OPT_MIX` (0x3a) and `max_mix_insts` (compiler+0x664) not reached (counter `*(compiler+0x6c4)+0x228`). For each non-constant-file
  source with literal lanes that HwLimits slot `0xf0` rejects it builds a new instruction (`FUN_00179138`) that materialises the literal, rewires the source to it and value-numbers it (`ValueKey__fill`,
  `ValueKey__propagateLaneValues`). Up to five new instructions (one per source) are collected in the local array.
* `FUN_00180830` = `ValueKey__simplifyModifiersAndAddressing`. Counted against `max_vn_transforms` (compiler+0x658). Part 1 cancels source modifier pairs through the defining instruction
  (negate of a negate, abs of an abs: `FUN_00176518` / `FUN_001764fc`, `IROperand__setModifierBits`). Part 2 (`OPT_CONST_FOLD_ADDR`, 10) turns a relative-addressed source (`FUN_00105dbc` = 2) whose address
  register has a constant value into a direct register: `floor(value [+0.5 when inst+0x12c != 0]) + base register`, reset to 0 above the HwLimits register limit (`+0x2c`).

## 3. Use-vector scans (`pass_rewrite`, `OPT_USEVECTOR` 0x13) — INFERRED

* `FUN_0013c60c` = `Program__scanUsevectorChains`. Bumps the visit stamp `program+0x474`; for every linked instruction of `program+0x3c4` it walks the chain of source-1 definitions with two explicit
  stacks (instruction stack, source-index stack), marks each instruction with the stamp (`inst+0x150`), optionally looks through movs and shifts (`OPT_MOV_AND_SHIFT_USEVECTOR`, 0x14: `FUN_00147f54`), and at the end
  of a chain calls `FUN_00138fb4` (= `Program__finishUsevectorChain`: HwLimits slot `0x6c` and `FUN_0014846c`).
* `FUN_00139f84` = `Block__scanBranchConeForFetchAndInterp`. Floods backwards from the block's branch instruction through the source instructions, noting whether the cone contains a fetch (IRInst slot 10) and an
  interpolant load (slot 19); the block flag word gets `0x400` or `0x800` accordingly.

## 4. Loops and region folding

* `pass_loop_trans` (gated by `OPT_WHILE_TO_FOR`, 0x1f): the `LoopInfo` record is the contiguous locals `loopInfo[12]` + two more words (layout in notes_compiler_passes.md 2.5); for every loop header the recognisers
  (`LoopInfo__init`, `setCounterPhi`, `matchCounterInit`, `matchCounterStep`, `matchExit`) fill it, `LoopInfo__convertToHardwareLoop` replaces the counter, compare and break blocks by an `IRLoadConst` loop-control
  constant and rewires the CFG (`boundOnRight` says on which side of the compare the bound is).
* `pass_remove_empty_graphs`: bypasses trivial blocks (one predecessor, one successor, fewer than three instructions), folds if regions whose arms are empty (`Program__isRegionTrivial`), swaps arms when the then arm
  is the trivial one (`IfHeader__swapArms`, `OPT_REMOVE_EMPTY_THEN` 0x21) and after a change zeroes the three work arrays `program+0x394/0x398/0x39c` (freed by `Program__freeWorkArrays`).
* `Program__foldConstantIfRegion`: drops the dead arm of an `if` with a known condition (worklist of dead blocks stamped with `program+0x474`), removes the branch instruction, connects the header's predecessor to the
  surviving arm and the arm's exit to the footer's successor, returning the surviving entry/exit through `param_4`/`param_5`.

## 5. Field scopes `PROG_` and `COMP_`

`fields_compiler.tsv` names 19 Program offsets (`PROG_`) and 37 Compiler offsets (`COMP_`: arenas, id counters, target description, the expression tables, the `max_*` limits stored by
`Compiler__setOption`, `currentProgram` at `+0x6c4`) with evidence. Scopes: `prog_scope.txt` (functions whose variable `program` is the Program) and `comp_scope.txt` (`compiler`); the file format
`NAME var` names the variable, which `Tools/userspace/apply_fields.py` now supports (it was hard-wired to `ctx`). For Program functions the nested spelling `*(T *)(program + PROG_compiler) + 0x374` is rewritten with the
`COMP_` table. The rewrite is an `enum` constant: the generated code is identical (gate output IDENTICAL for the field commit).
`compiler+0x6c4` is the Program being compiled, not an options object as earlier notes said: its `+0x30` flag word and the `+0xa8` / `+0x228` counters are the Program's.

## 6. Not done

`pass_minreg_order` (its body is only the block/instruction walk calling `FUN_00181928` / `FUN_0018413c`), the algorithms of `FUN_00147f54` and `FUN_0014846c`, `ValueKey__canonicalizeConstantSources` second half in detail,
the unwind of the `Or` names in `FUN_0017b12c` (stack arrays `local_138` ... are one 0x6c-byte record of created instructions), field scopes for `Block` and `IRInst`, and the `compiler`-typed parameters whose object is not a Compiler.
