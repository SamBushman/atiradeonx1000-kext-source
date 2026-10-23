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

## Round 5, fork I2: peephole pattern decode, IR instruction fields, HwLimits helper slots (tables: names_I2_asm.tsv, names_I2_func.tsv, names_I2_pat.tsv)

**IRInst fields fixed by this round** (all read in several places, tier in the tables):

| offset | meaning | evidence |
|---|---|---|
| +0x11c | predicate kind (0 none, 2 / 3 predicated), set by IRInst vslot 33 (`IRInst__vslot33_setPredicateKind`); the R300V assembler turns 2 / 3 into PRED_ENABLE / PRED_SENSE | `vslot14_assembleInstruction`, R520V visitors |
| +0x120 | **saturate** flag (PVS VE_SAT bit 24 / ME_SAT bit 25) | `encodeDestinationWord`, `encodeDualMathOperands`; set to 1 by `Inst__collapseClampToSaturate` |
| +0x124 | **result scale code**; `FUN_0010aad4` (`IRInst__resultScaleFactor`) maps the code to a float; HwLimits slot 63 (`HwLimits__vslot63_supportsResultScale`) validates it | `Inst__foldConstantMovIntoResultScale`, `Inst__distributeResultScale`, `Inst__collapseAddOfScaledMov` |
| +0x12c | compare condition (compare opcodes 0x8b..0x8d) or the mova round flag; OpcodeInfo slot 6 gives the default for the opcode | `KhanPs__vslot9_createCompareInst`, scheduler address-register reuse |
| +0x160 | counter kept relative to `program+0x478` (`inst+0x160 = base + n`); new instructions get `base + 1` | every rebuild in the collapse patterns |
| operand record n | at `inst + 0x8c + n*0x18`: +4 source, +8 register, +0xc register offset, +0x10 select word, +0x14 flags (bit 0 negate, bit 1 abs) | `IROperand__copyFrom`, `IRInst__applyAbsModifier` / `applyNegateModifier` |
| +0x12c.. | for an interpolant load: four 4-byte lane records (used flag, kind byte, attribute halfword) | `IRLoadInterp__laneUsed/laneKind/laneIndex`, `KhanPs__vslot87_assignInterpolatorBindings` |

IRInst vslot 23 / 24 / 25 are `isPresub` / `isMix` / `isMov` (names of the stubs at 0x1cd758 / 760 / 768). Slot 34 (`setSourceSelect`) stores one lane byte of an operand select word,
slot 35 (`allowsSourceNegate`, default 1) lets `KhanPs__vslot59_tryEncodeSourceConstant` try the negated literal. OpcodeInfo slot 5 (`getValueKeyTransformLevel`) is called by the
ValueKey transform `FUN_0017f7ec`; slot 6 (`getMovaRoundFlag`) is 1 only for IrMovaRound / IrMovaRoundFloat. HwLimits slot 32 (`supportsResultSaturate`: Khan Ps 1, Khan Vs 0, Fudo Vs 1)
gates the clamp fold.

**The OPT_COLLAPSE_ALGEBRAIC patterns decoded** (`Inst__collapseAlgebraic_<addr>` was not a decodable name; every row is `func` in names_I2_pat.tsv):

| address | new name | rewrite |
|---|---|---|
| 0x14acb8 | `Inst__collapseMulSplatByDotOnes` | `s * dot(v, 1.0)` -> `dot(v, s)` |
| 0x14b150 | `Inst__collapseAddIntoMadMulAddend` | `add(mad(a,b,mul(c,d)), y)` -> `mad(a,b,mad(c,d,y))`, the add becomes a mov |
| 0x14b82c | `Inst__collapseAddOfMulToMad` | `add(mul(a,b), c)` -> `mad(a,b,c)` (test half: `Inst__canFuseAddMul`) |
| 0x14bdbc | `Inst__collapseMulOfAddWithUnitConstant` | `(x +- 1) * y` -> `mad(x, y, +-y)` |
| 0x14caec | `Inst__collapseMadOfMulToDot2Add` | `mad(a,b,x*y)` -> `dot2add` with a 0.0 third source |
| 0x14cec8 | `Inst__collapseMadWithDot2AddToDot3` | `mad(a,b,dot2add(c,d,0))` -> `dot3` |
| 0x14d274 | `Inst__collapseDot3VectorTimesScaledVector` | `dot3(V, V*S)` -> `(V.V) * S` reusing the existing V.V |
| 0x14d8f8 | `Inst__collapseThreeComponentSumToDot3` | `(x.a + x.b) + x.c` -> `dot3(x.abc, 1.0)` |
| 0x150d38 | `Inst__collapseAddOfScaledMov` | `add(mov(x) scaled by k, y)` -> `mad(x, k, y)` |
| 0x154dc0 | `Inst__mergeComponentMovsIntoCnd` | two single-component partial movs -> one cnd with a constant mask |
| 0x1595f0 | `Inst__foldCndWithConstantCondition` | cnd with constant condition lanes -> mov of the selected source |
| 0x155a60 / 0x15ceb0 / 0x15c6d4 / 0x162cc0 + helpers | (not decoded) | result-scale / extra-source folds, see tier UNKNOWN names |
| 0x158c3c | `Inst__distributeResultScale` | worklist pushing a result scale code into add / mul / mad sources |
| 0x15bd40 | `Inst__mergeAddAndMadSharedOperands` | add + mad with shared operands and disjoint lanes -> one mad (extra-source layout) |
| 0x15df44 | `Inst__collapseMulOfExps` | `exp(a) * exp(b)` -> `exp(a + b)` |
| 0x15e494 | `Inst__collapseClampToSaturate` | `max(min(x,1),0)` -> saturate flag on the producer |
| 0x163994 | `Inst__mergeMovAndMadByLanes` | mov + mad with disjoint lanes through the extra source -> one mad |
| 0x1882a4 | `Inst__foldConstantMovIntoResultScale` | `mov(k)` with a scale-representable constant -> `mov(1.0)` with a result scale |
| 0x1875a8 | `Inst__r300ReassociateAddPair` | exchange one operand between two adds and retry `FUN_00186a88` |
| 0x163478 | `Inst__hoistScalarMulOutOfDot` | `dot(x, v*s)` -> `dot(x, v) * s` |
| 0x1859bc | `Inst__tryDp3Add` | `dot3(a,b).splat + c.splat` -> `dp3add(a,b,c)` |

Helper functions named: `IRInst__reinitAsBinary/Unary/Trinary/Mov` (in-place re-construction), `IRInst__deleteIfUnused`, `IRInst__cloneInto`, `IRInst__copyOperandFrom`,
`IRInst__sourceLanesAllWritten`, `IRInst__sourceMatchesConstant`, `SelectWord__isSplat`, `SelectWord__compose`, `SelectWord__mergeWrittenLanes`, `SelectWord__fillUnusedLanes`,
`SelectWord__splatComponent`, `IRInst__replaceWithMovOfSource`, `IRInst__cloneIfPresub`, `OpcodeInfo__getResultMode`.

**Not decoded** (tier UNKNOWN, left as placeholders): `Inst__collapseAlgebraic_00155a60`, `_0015ceb0`, `_0015c6d4`, `_00162cc0` (a dispatcher over seven further 1.3-4.7 KB helpers
`FUN_00161748`, `FUN_00151a74`, `FUN_001524b8`, `FUN_00151370`, `FUN_001541f0`, `FUN_00152ea8`, `FUN_001621c8`), `_00158264`, `Inst__foldProducerIntoConsumer`, `Inst__tryMix` is decoded in
its locals only, `Inst__takeOutCommonFactor`.

**Gate pitfalls hit while splitting** (each produced a NOT-EQUIVALENT before the fix): a `do { .. } while (n != 0)` countdown segment must include the `while` line; a line that reads
the old value of a variable and assigns a new role needs `first=lhs` / `last=rhs` halves; a pass-through argument read of a variable after the role changed must stay with the old name;
a use that follows a `goto` label belongs to the definition that reaches it, not to the nearest textual one.
