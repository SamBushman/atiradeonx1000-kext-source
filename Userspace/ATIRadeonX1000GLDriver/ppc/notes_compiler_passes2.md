# GLDriver shader compiler: pass bodies, part 2 (value numbering / SSA renaming, rewrite pipeline, options)

Fork D3 (round 3), continuing `notes_compiler_passes.md` (C2) and `notes_compiler_opcodes.md` (C1). Tiers as before: **CONFIRMED** (the corpus text, a table or a string shows it),
**INFERRED** (role clear from use), **UNKNOWN**. Per-name evidence is in the rows (`names_D3_*.tsv`).

## 1. The compiler option table (CONFIRMED, new)

`Compiler__isOptionEnabled(compiler, id)` tests bit `id` of the byte array at `compiler+0x59c`. The ids are indexes into the table of 80 `OPT_*` name strings at `0x1dc444`
(pointers to C strings); `FUN_000e0ee8` (renamed `Compiler__setOption(compiler, name, value)`) matches a name against that table (`strncmp`) and sets the bit; when the name is not in
the table it falls through to a chain of `strncmp`s against the tunable limits and stores the value at the compiler offset in the second column of section 1.1. So every
`Compiler__isOptionEnabled(x, N)` call in the corpus has a real name:

| id | option |
|---|---|
| 0 (0x0) | `OPT_IGNORE_DEFINED_CONSTANTS` |
| 1 (0x1) | `OPT_PREPROCESS_CONSTANT_IFS` |
| 2 (0x2) | `OPT_UNROLL_LOOPS` |
| 3 (0x3) | `OPT_REMOVE_LOOPS` |
| 4 (0x4) | `OPT_DECOMPOSE_DP3` |
| 5 (0x5) | `OPT_COPY_FOLD` |
| 6 (0x6) | `OPT_CONST_PROP` |
| 7 (0x7) | `OPT_VALUE_NUMBER` |
| 8 (0x8) | `OPT_VALUE_NUMBER_SHUFFLE` |
| 9 (0x9) | `OPT_VALUE_TRANSFORMS` |
| 10 (0xa) | `OPT_CONST_FOLD_ADDR` |
| 11 (0xb) | `OPT_CONST_FOLD_LITERALS` |
| 12 (0xc) | `OPT_CONST_FOLD_SHIFTS` |
| 13 (0xd) | `OPT_CSE_IF_SIMPLIFY` |
| 14 (0xe) | `OPT_HOIST_INSTRUCTIONS` |
| 15 (0xf) | `OPT_REDUCE_DEP` |
| 16 (0x10) | `OPT_DELETE_COMPUTATIONS_THAT_COULD_BE_VS` |
| 17 (0x11) | `OPT_DEAD_CODE` |
| 18 (0x12) | `OPT_PACK_INSTS` |
| 19 (0x13) | `OPT_USEVECTOR` |
| 20 (0x14) | `OPT_MOV_AND_SHIFT_USEVECTOR` |
| 21 (0x15) | `OPT_REASSOCIATE` |
| 22 (0x16) | `OPT_TAKEOUT_COMMON_FACTOR` |
| 23 (0x17) | `OPT_FOLD_USELESS_PHI` |
| 24 (0x18) | `OPT_MOVE_FETCH_INST` |
| 25 (0x19) | `OPT_CONVERT_INNER_IF_TO_CMOV` |
| 26 (0x1a) | `OPT_PEEPHOLE` |
| 27 (0x1b) | `OPT_COPY_PROP` |
| 28 (0x1c) | `OPT_COLLAPSE_ALGEBRAIC` |
| 29 (0x1d) | `OPT_COLLAPSE_SIMILAR` |
| 30 (0x1e) | `OPT_POW_OF_CONST` |
| 31 (0x1f) | `OPT_WHILE_TO_FOR` |
| 32 (0x20) | `OPT_REMOVE_EMPTY_GRAPH` |
| 33 (0x21) | `OPT_REMOVE_EMPTY_THEN` |
| 34 (0x22) | `OPT_MARK_IGNORE_UNCOVERED` |
| 35 (0x23) | `OPT_ALLOC_PLACEMENT` |
| 36 (0x24) | `OPT_SCHEDULER_REORDER` |
| 37 (0x25) | `OPT_SCHEDULER_ALLOC_REG` |
| 38 (0x26) | `OPT_SCHEDULER_REORDER_PW` |
| 39 (0x27) | `OPT_ALLOW_SCHED_TRANSFORMS` |
| 40 (0x28) | `OPT_BALANCE` |
| 41 (0x29) | `OPT_RECYCLE_MEM` |
| 42 (0x2a) | `OPT_NO_DIST` |
| 43 (0x2b) | `OPT_NO_REASSOC` |
| 44 (0x2c) | `OPT_ALLOW_TOO_BIG` |
| 45 (0x2d) | `LAST_GENERIC_OPT_FLAG` |
| 46 (0x2e) | `OPT_USE_VERTEX_CACHE` |
| 47 (0x2f) | `OPT_CONST_FOLD_43_INLINE` |
| 48 (0x30) | `OPT_SPLIT_RGB_ALPHA` |
| 49 (0x31) | `OPT_SPLIT_RGB_ALPHA_EXPORTS` |
| 50 (0x32) | `OPT_SPLIT_INTO_SCALAR` |
| 51 (0x33) | `OPT_SPLIT_INTO_SCALAR_EXPORTS` |
| 52 (0x34) | `OPT_MAP_CHANNELS` |
| 53 (0x35) | `OPT_PAIR_INSTRUCTIONS` |
| 54 (0x36) | `OPT_SPLIT_AND_MERGE` |
| 55 (0x37) | `OPT_PACK_PS_INPUT` |
| 56 (0x38) | `OPT_SWIZZLE_TFETCH_OUTPUT` |
| 57 (0x39) | `OPT_R300_PEEPHOLE` |
| 58 (0x3a) | `OPT_MIX` |
| 59 (0x3b) | `OPT_DP3ADD` |
| 60 (0x3c) | `OPT_DP3_COMMUTATIVITY_PUSHOFF` |
| 61 (0x3d) | `OPT_TEXKILL_SPECIAL` |
| 62 (0x3e) | `OPT_PRESERVE_VERTEX_INPUTS` |
| 63 (0x3f) | `OPT_EXPORT_PACKING` |
| 64 (0x40) | `OPT_TEXKILL_NO_NEG_ZERO` |
| 65 (0x41) | `OPT_R300_USE_RS_SWIZZLE` |
| 66 (0x42) | `OPT_HEIGHT_REDUCTION` |
| 67 (0x43) | `OPT_MIN_REG_SORT` |
| 68 (0x44) | `OPT_R600_DONT_USE_BREAKLOOP_STK` |
| 69 (0x45) | `OPT_R600_USE_CONST_CACHE` |
| 70 (0x46) | `OPT_R600_PRESERVE_PVPS` |
| 71 (0x47) | `OPT_SCHEDULER_PAIR_EXPORTS` |
| 72 (0x48) | `OPT_SPILL_REGISTERS` |
| 73 (0x49) | `OPT_PACK_CONSTANTS` |
| 74 (0x4a) | `OPT_CONVERT_INNER_IF_TO_PRED` |
| 75 (0x4b) | `OPT_MERGE_ENDIF` |
| 76 (0x4c) | `OPT_R600_MINIMIZE_CF_INSTS` |
| 77 (0x4d) | `OPT_COMPRESS` |
| 78 (0x4e) | `OPT_SOFTIL_GEN_POS_SHDR` |
| 79 (0x4f) | `OPT_SOFTIL_GEN_ATTRIB_SHDR` |

The earlier passes' option gates are now readable: `pass_loop_trans` is gated by `OPT_WHILE_TO_FOR` (0x1f), `pass_minreg_order` by `OPT_MIN_REG_SORT` (0x43), `pass_remove_empty_graphs`
by `OPT_REMOVE_EMPTY_GRAPH` (0x20) / `OPT_REMOVE_EMPTY_THEN` (0x21), `pass_rewrite` by `OPT_USEVECTOR` (0x13), `OPT_FOLD_USELESS_PHI` (0x17), `OPT_MOVE_FETCH_INST` (0x18),
`OPT_CONVERT_INNER_IF_TO_CMOV` (0x19) and `OPT_PACK_PS_INPUT` (0x37); `pass_ssa_build` by `OPT_VALUE_NUMBER` (7), `OPT_VALUE_TRANSFORMS` (9), `OPT_CSE_IF_SIMPLIFY` (0xd).
`names_D3_opt.tsv` names every variable that holds the result of such a call `<option>Enabled`.

### 1.1 Tunable limits stored by `Compiler__setOption` (CONFIRMED: the strings and the stores are in the same function)

`compiler+0x64c` `opt_flatten_if_state`, `+0x650` `max_copy_folds`, `+0x654` `max_vn_kills`, `+0x658` `max_vn_transforms`, `+0x65c` `max_copy_merges`, `+0x660` `max_copy_props`, `+0x664` `max_mix_insts`,
`+0x668` `max_presubs`, `+0x66c` `max_useless_phis`, `+0x670` `max_mov_and_shift`, `+0x674` `max_balance_conversions`, `+0x678` `max_coalesce_loops`, `+0x67c` `max_spill_loops`,
`+0x680` `max_inst_hoists`, `+0x684` `max_mad_mul_to_d2a`, `+0x688` `max_mad_d2a_to_dp3`, `+0x68c` `max_add_add_to_dp3`, `+0x690` `max_add_mul_to_mad`, `+0x694` `max_add_mad_mul_to_mov_mad_mad`,
`+0x698` `max_reassociate`, `+0x69c` `max_reconst_alu`, `+0x6a0` `max_remove_cnd_input` (the rest up to `+0x6a8` are `max_r600_minimize_cf_attempts`, `max_flatten_if`, as the function continues).
Each limit has a matching running counter in the **Program** (`program+0xa0` copy folds against `+0x650`; `+0x14c` value-number kills against `+0x654`; `*(compiler+0x6c4)+0xa8` value
transforms against `+0x658`; `+0x22c` useless phis folded against `+0x66c`), which is how the passes below stop after a configured number of rewrites.

## 2. `pass_ssa_build` is a dominator-tree renaming walk with value numbering

(CONFIRMED structure; INFERRED names.) The function name is misleading: besides turning the program into SSA (phi nodes already exist as opcode 0x8e instructions, `IRInst` virtual slot 31 returns the
phi), it renames every source to its **current definition** and performs scoped **value numbering** (`OPT_VALUE_NUMBER`), copy folding, constant propagation and the elimination of `if` regions whose
condition value numbering proves constant (`OPT_CSE_IF_SIMPLIFY`).

* The work list `blockStack` (vector header in the three contiguous locals `local_5c/58/54`) starts with the entry block (`program+0x3a0`). Blocks are popped; the vector at `block+0xf4` holds the
  blocks the popped block immediately dominates (idom link at `+0xf0`, depth at `+0xbc`), which are pushed.
* **Renaming stacks.** Every virtual register (`vreg`) has a definition stack, a growable vector at `vreg+0x2c`, and `vreg+0x28` is the id of the block that pushed the top.
  `VReg__currentDefinition` returns the top (creating the initial definition through virtual slot 2 when the stack is empty), `VReg__pushDefinition` pushes (replacing the top when the same block
  already defined it), `VReg__popDefinition` undoes it. `Block__recordDefinition` adds the vreg to the block's defined-vreg vector (`block+0xc4`) so `Block__popDefinitions` can pop every definition when the
  walk leaves the block's subtree. After the instruction walk of a block, the pass visits each successor, finds this block's predecessor index (`Block__phiOperandIndexForPredecessor`, the phi
  source operand to fill) and sets the source of every phi of the successor to the current definition of the phi's vreg.
* **Scopes.** With `OPT_VALUE_NUMBER` on, entering a block opens a scope: three hash tables are created per scope (`exprTable`, `laneMatchTable`, `swizzleTable`) and a `perBlockSlotTable`
  (0x20c bytes, 0x80 slots) at `block+0x128`. The scope stacks are the vectors at `program+0x404`, `+0x408`, `+0x40c` (one table per open scope) and `+0x410` (the block that opened
  it); `scopeDepth` indexes them and is decremented when `Block__popDefinitions` closes the scope. The tables are the generic `HashTable` (`{bucketCount, count, buckets, eq, hash, arena}`, bucket count a
  power of two up to 0x400/0x100, `HashTable__find` / `HashTable__insert` with the equality function returning 0 for equal):
  * `exprTable`: hash `ScopedExprTable__hashKey` (product of the per-lane value numbers of the sources + opcode, mod 101), equality `ScopedExprTable__eqKeys` (`memcmp` of the 0x15c-byte signature at key+0xb4).
  * `laneMatchTable`: single bucket (`LaneMatchTable__hashZero`), equality `LaneMatchTable__eqKeys` (lane value numbers equal or either is the wildcard 3).
  * `swizzleTable`: hash `SwizzleTable__hashKey` (max |lane value|), equality `SwizzleTable__eqKeys` (identity swizzle between the two keys).
* **Global tables** hang off the compiler (`+0x3e0` records by value number, `+0x3e4` by expression handle, `+0x3e8` a pointer set, `+0x3ec` (key, lane) entries by opcode). `Compiler__nextValueNumber`
  hands out ids from 4 up and `Compiler__nextNegativeValueNumber` from -2 down; `Compiler__valueNumberForExpr` creates a 0x2c-byte `ExprRecord {handle, valueNumber, ...}` for an expression and
  registers it in `+0x3e4`, `+0x3e0` and the creation list `+0x3d8`. Negative lane values in a key are resolved to their record with `Compiler__exprRecordForValueNumber`.
* **The key (`ValueKey`, 0x240 bytes).** One per instruction, `ValueKey__init(key, inst, compiler)`, filled by `ValueKey__fill`:

| offset | meaning |
|---|---|
| +0x00..0x30 | four-lane word sets (`+0x20` the value numbers of the result lanes; `ValueKey__initResultLaneValues`, `ValueKey__propagateLaneValues` move them between sets) |
| +0x2c words (`key[0x2c]`) | the table stores the instruction pointer at `+0xb0` (`key[0x2c]`) and the compiler at `+0x238` (`key[0x8e]`) |
| +0xb0 | the instruction |
| +0xb4 | **opcode number** (`inst->opcodeInfo->+8`); from here 0x15c bytes (to +0x210) are the comparable signature |
| +0xb8/+0xbc | destination register pair (`inst[0x25]`/`inst[0x26]`) or zero |
| +0xc0/+0xc4 | `inst+0x120`/`+0x124` |
| +0xc8 + 0x20*i + 4*lane | modifier bits (negate, abs) of source `i`, lane |
| +0x168 + 0x10*i + 4*lane | value number of lane `lane` of source `i` (the defining key's lane numbers at `defKey+0x20`, or a negative number resolved through the expression record) |
| +0x1bc + 4*i | operand kind (`FUN_00105c5c`) |
| +0x1cc..0x1ec | copy of `inst+0x12c..0x14c` (compare condition, extra words) |
| +0x210 + 4*i | for source `i`, the defining instruction found by `VReg__currentDefinition` (`ValueKey__loadSourceDefinitions`) |
| +0x228 + 4*i | per-source lane-usage record (`FUN_000f3c30`, `ValueKey__fillSourceLaneUsage`) |

* **Per instruction** (`Program__valueNumberInst`, `FUN_00175dac`): fill the key, canonicalise commutative operands (`ValueKey__canonicalizeCommutativeOperands`: opcode trait bit 0 and a swap of sources
  1 and 2 by lane-set order), try to fold (`ValueKey__foldMovSources`, `Program__tryEliminateRedundantCopy`: `OPT_CONST_PROP` and `OPT_COPY_FOLD`, counted in `program+0xa4` / `+0xa0`), look the key up in
  the scope tables, replace the instruction by the earlier equivalent definition when found (`FUN_00173b98`: removes the instruction, `program+0x14c`/`0x150` count kills), otherwise insert the key into
  the current scope's tables.
* `Program__foldConstantIfRegion` (`FUN_0012df90`) removes the dead arm of an `if` whose header carries a known condition value (`header+0x14c`: 1 selects the then arm +0x134, otherwise the else arm
  +0x138): it detaches every block of the dead arm (visit stamp `program+0x474`), removes the branch, rewires the surviving arm between the header's predecessor and the footer's successor and detaches
  header and footer.

## 3. The `pass_rewrite` pipeline (CONFIRMED gating, INFERRED bodies)

`Program__foldUselessPhis` (`FUN_0011fb94`, `OPT_FOLD_USELESS_PHI`): marks every phi (`+0x134 = 1`), worklist; `IRPhi__getUniqueSource` (`FUN_0011e6f4`) returns the single distinct source of a phi (ignoring
itself) or 0; the uses of such a phi are rewritten to that source (a user that is itself a phi is re-queued), the phi is deleted and `program+0x22c` counted against `max_useless_phis`.
`Program__packPsInputs` (`FUN_001121b4`, `OPT_PACK_PS_INPUT`): groups interpolant loads with the same register/stream words (+0x13c..0x148) that write different lanes into one 4-lane load
(`FUN_000f3a30` counts the lanes), replacing the others by moves. `Program__moveInterpFetchesOutOfIfs` (`FUN_001394b0`) and `Program__hoistFetchInsts` (`FUN_0013b3f0`) implement
`OPT_MOVE_FETCH_INST`: fetches whose address source is an interpolant load are moved out of if regions to a new `AnyBlock` after the entry block. `Block__convertInnerIfToCmov`
(`FUN_0013caf4`, `OPT_CONVERT_INNER_IF_TO_CMOV`) turns an if whose arms hold only phis and cheap instructions into a conditional move.

## 4. `pass_post_pack_insts` (`FUN_00145670`)

A greedy instruction packer (pairing instructions for dual issue): for every pair of eligible instructions (opcode record bit 1, `FUN_0011379c`) it builds a 0x2c-byte candidate record
(`FUN_001436b4`), keeps at most 0x400, scores each with `FUN_00143e40`, applies the best (`FUN_0014532c`) and repeats until `param_1[2]` reaches 0x17. The candidate vector is an inlined growable array with
growth factor 1.6 (`(cap << 4) / 10`), which is why the function body is mostly element-access boilerplate.

## 5. Not decoded

`FUN_00180830`, `FUN_0017b12c`, `FUN_00180250` (the rest of the value-numbering transformations behind `OPT_VALUE_TRANSFORMS`, option 9), the algorithm inside `FUN_00141930` / `FUN_0014375c` /
`FUN_001440e4` (pair legality and scoring of `post_pack_insts`), `FUN_0013c60c` and `FUN_00139f84` (the use-vector peepholes of `pass_rewrite`).
