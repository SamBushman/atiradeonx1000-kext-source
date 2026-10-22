# GLDriver shader compiler: pass bodies and shared infrastructure

Fork C2 (continuation of `notes_compiler_ir.md`, which recovered the RTTI class tree, the IR layouts and the pass registry).
This file records what reading the *bodies* of the pass entry points and of the helpers they share established.
Tiers as before: **CONFIRMED** (the corpus text shows it: a store/load pair, a literal, a string, a vtable slot),
**INFERRED** (the role is clear from use, nothing names it), **UNKNOWN**. Every name in `names_C2.tsv` / `names_C2_func.tsv` carries the tier and
the evidence in its row; this file explains the picture behind them.

Method: a call graph over `part_*.c` (`~/g5logs/C2/cg.py`, scratch) gave, per pass entry, the functions only reachable through it
(10 passes, 428 functions, 33.5k placeholders); the helpers with the most callers across the compiler (the top ~70) were read first,
because naming them improves every function that calls them; then each small pass entry was read whole.

## 1. Shared primitives (all CONFIRMED unless noted)

| function (new name) | what it is |
|---|---|
| `Arena__alloc(arena, size)` | bump allocator: size rounded to 4, cursor `+8`, limit `+0x10`, last allocation `+0x14` |
| `Arena__free(arena, p)` | only rewinds when `p` is the last allocation (zeroes `[p, cursor)`) |
| `Vector__elementRefGrow(vec, i)` | growable array `{capacity, count, data, arena}`; doubles until `i` fits, copies, returns `&data[i]`. The inline `if (i < capacity) { if (count <= i) { memset; count = i+1 } p = &data[i] } else grow` pattern is the C++ `operator[]`/`ElementRef` |
| `Vector__removeAt(vec, i)` / `Vector__removeValue(vec, v)` | shift the tail down; the second finds the first equal element, returns 1 when found |
| `DList__insertBefore / insertAfter / pushBack / pushFront / unlink / count` | intrusive doubly linked list: `node+4` prev, `node+8` next; the list head is a sentinel at `list+0xc` (`DList__count` walks `list+8` to `list+0xc`) |
| `Compiler__fail(compiler, code)` | stores the code at `compiler+0x314` and `longjmp`s to the jmp_buf at `compiler+4`: the compiler's only error exit (`pass_color_graph` calls it when a node cannot be coloured) |
| `Compiler__isOptionEnabled(compiler, id)` | bit `id` of the byte array at `compiler+0x59c` **and** the target description accepts it (INFERRED name) |
| `Compiler__logf(compiler, fmt, ...)` | the body is a bare `return`: the verbose log of the scheduler (`"Scheduler : Total cycles %d\n"`, `"Scheduler : Total dot-product transformed %d\n"`) is compiled out of this build |

### 1.1 IR instruction accessors

An `IRInst` has up to five inline operand records of 0x18 bytes at `+0x8c` and further records in the vector at `+0x118`.
Operand 0 is the destination, 1.. are sources; `inst+0x84` is the source count; `inst+0x88` is the opcode info (`Opcode__getInfo`), whose `+8` is the opcode number.

Operand record (INFERRED from `IRInst__setOperandRef`, `IRInst__setOperandSourceRaw`, flatten_ifs and `FUN_0010b498`):

| offset | meaning |
|---|---|
| +0x00 | reference object (a `VRegInfo`-family object with a vtable; for operand 0 `ref->vfn[9]()` is cached at `inst+0x128`) |
| +0x04 | **source**: the value/instruction that feeds the operand (`IRInst__getOperandSource`) |
| +0x08 / +0x0c | `ref[2]` / `ref[1]` copied by `IRInst__setOperandRef` (the `+0xc` word is the register kind: `FUN_00105dbc` indexes a kind table with it) |
| +0x10 | swizzle / write-mask word, four bytes (one per lane; for the destination byte `1` means the lane is not written: `FUN_0010b498`, `FUN_0012c7c0`, `FUN_0013bd68`) |
| +0x14 | modifier flags: bit 0 negate, bit 1 absolute value (`IROperand__setModifierBits`; flatten_ifs copies them from the compare to the new selects) |

Def-use bookkeeping (CONFIRMED by `IRInst__setOperandSource` / `IRInst__addToUseLists`): when the program keeps def-use lists (program flag `+0x30 & 0x80`),
the **source** object has a vector of its users at `+0x10` and a use count at `+0x160`. The count is stored with an epoch: the stored word is
`program+0x478 + count` and a stored value below the epoch reads as 0 (`IRInst__useCount`, `IRInst__hasSingleUse`). The epoch moves forward by `compiler+0x324 * 4`
every time `FUN_0013bd68` runs, which is how a whole recount is "reset" without touching every object. `inst+0x150` is a visit stamp compared with `program+0x474`
(also bumped by each traversal; `FUN_0012fe8c` uses `block+0x118` the same way).

`IRInst__create(opcode, compiler)` is the factory (class index from the target description, constructor table `0x1ea4fc`);
`IRInst__clone` copies 0x164 bytes into a fresh arena block (arena pointer in the word before the object) and assigns a new id (`compiler+0x324`++).
`Program__addInst / removeInst` maintain the vector of all instructions at `program+0x3c4`.

### 1.2 Block / CFG accessors

`Block` (R2b section 4) has successors in the vector at `+0xd0` and predecessors in the vector at `+0xd4` (CONFIRMED by flatten_ifs: the footer's two
predecessors are the ends of the then and else arms). Instruction list: head object at `+0x98`, entry/exit pseudo instructions at `+0xc8` / `+0xcc`; the block's
embedded instruction `DList` is at `+0x90` (`DList__count(block+0x90)` is the instruction count tests like `< 3` use). `Block__insertInstAfter/Before`,
`Block__appendInst` (before the exit pseudo), `Block__prependInst` (after the entry pseudo) set `inst+0x158 = block`.
`Block__isSimple` is `strcmp(getName(), "SIMPLE") == 0` (virtual slot 19). `Block__successorCount`, `predecessorCount`, `hasMultipleSuccessors`.
`Block__connect(a, b)` adds the edge if absent; `Block__bypass(block, pred, succ)` makes `pred -> succ` replace `pred -> block -> succ`; `Block__detach` frees the block's id bit
(`+0xb4` in the bit set at `owner+0x3bc`) and unlinks it.
`Block__getBranchInst` (INFERRED name) runs a cleanup walk and returns `block+0x130`, the compare/branch instruction of an if header.

`IfHeader` fields (CONFIRMED in `IfHeader__swapArms`, `IfHeader__canFlatten`): `+0x134` then arm, `+0x138` else arm, `+0x13c` the matching footer/join block;
an `IfFooter` points back at its header at `+0x12c`. `IfHeader__swapArms` swaps the arms, re-links the moved arm before the footer and inverts the compare condition via the table at
`0x1e912c` (`IRInst__getCompareCondition` / `setCompareCondition`: condition code in `inst+0x12c` for the compare opcodes 0x8b..0x8d).

## 2. The passes

### 2.1 `pass_color_graph` (`FUN_00135fb0`): graph-colouring register allocation (INFERRED structure, many CONFIRMED details)

Parameter `colorGraph` is a **ColorGraph** object (the object, not the Program):

| offset | meaning |
|---|---|
| +4 | growable vector of node records, indexed by node id |
| +8 | `firstVirtual`: nodes below it are precoloured (hardware registers), from it up to +0xc are virtual |
| +0xc | node count |
| +0x10 | per-class base index (added to a colour at the end to give the final register number) |
| +0x14 | per-class colour budget `K` (clamped to >= 1) |
| +0x20 | alias / representative array (`alias[i] == i` means the node is its own representative) |
| +0x24 | bit set of nodes that could not be coloured / were marked (set when an uncolourable node has no spill flag) |
| +0x28 | the Program (`+0x458` colour per virtual register, `+0x45c` register class per virtual register, `+0x43c`/`+0x448` per-class `[first, last)` hardware register ranges, `+0x470` register count, `+0x25c` / `+0x260` statistics counters) |
| +0x2c | the Compiler (`+0x378` work arena, `+0x30c` target description whose `+0x14` is the number of register classes) |

Node record: `+4` neighbour count, `+8` neighbour list (chunks of 7 ids, next chunk at `+0x1c`), `+0xc` current degree, `+0x10` vector of coalesced partners
(each a pointer to a word holding a virtual register index; used as colour hints), `+0x18` a spill-candidate flag.

Algorithm as read (per register class `c`, arrays allocated from the compiler arena: `colorLimit[c]`, `maxColorUsed[c]`, `hwRegsPerClass[c]` filled by the target's virtual slot `0x130`, `lowDegreeWorklists[c]`, `simplifiedStacks[c]`, `usedColorBits[c]`, `classNodeCount[c]`):
1. Precoloured nodes get their colour made class-relative (`color -= classBase`).
2. Every representative virtual node gets its degree = number of same-class neighbours (`ColorGraph__countSameClassNeighbors`); degree 0 goes straight on the simplified stack, degree < `colorLimit` on the low-degree worklist.
3. Simplify: pop the worklist, push the node on the simplified stack and decrement its neighbours (`ColorGraph__removeNodeUpdateDegrees`: a neighbour reaching `colorLimit - 1` joins the worklist). When the worklist is empty but nodes remain, `colorLimit[c]` is **raised by one** and the nodes with degree `colorLimit - 1` are queued again (an optimistic scheme that grows the register budget instead of choosing spills; `program+0x25c` counts these rounds).
4. Select: pop the simplified stack; the colours already used by coloured neighbours, and by registers the target does not allow (`Program__isHwRegAllowed`), are marked in `usedColorBits`; a coalesced partner's colour is tried first (`program+0x260` counts hint hits); otherwise the first free colour is taken; `Program__markHwRegUsed` records it. With no free colour the pass fails through `Compiler__fail(compiler, 4)` unless the target description flag `0x8000` (`+8`) and option `0x48` are both on, in which case the node is counted (`uncolorableCount`) and, if it has no spill flag, marked in the `+0x24` bit set.
5. Representatives' colours are copied to their aliases, class base offsets are added, the pass marker `"color_graph"` is written and the temporary arrays freed. The function returns whether any node was uncolourable (the caller reruns after spilling).

### 2.2 `pass_flatten_ifs` (`FUN_0012d2f0`): if-conversion (INFERRED, CFG edits CONFIRMED)

Walks the Program's block list (`program+0x384`). For an `IfFooter` that is not static (virtual slots `0x28`, `0x40`) it fetches the matching header (`footer+0x12c`), checks the option limit (`program+0x8 ->+0x6a8` against the options' `+0x15c`), asks the target whether the region is worth flattening (target virtual slot `0x114`) and `IfHeader__canFlatten` (both arms have fewer than three instructions, a single successor, the else arm leads to the join block, no break/continue). Then it rewires the CFG so that `blockBeforeIf -> thenArm -> elseArm -> blockAfterIf` are in sequence, finds the compare instruction (`Block__getBranchInst`), builds or reuses the condition source (a new opcode-`0x12` instruction when the compare cannot be reused; negate/abs modifier bits come from the compare) and turns every phi (`opcode 0x8e`) of the footer into a three-source select (`IRInst` re-initialised with opcode `0x25`, sources: condition, then value, else value, with swizzles copied from the phi). The compare is removed (`Program__removeInst`), the header and footer blocks are detached, and on any change the work arrays are freed (`Program__freeWorkArrays`), the pass marker is written and `Program__eliminateDeadInstsAndRecountUses` runs.

### 2.3 `pass_remove_empty_graphs` (`FUN_001300b0`) (INFERRED, CFG edits CONFIRMED)

Repeats until nothing changes: (a) a "simple" block with fewer than three instructions, one predecessor and one successor, whose neighbours are simple/loop blocks, is bypassed (`Block__bypassAndDetach`); (b) an if header whose arms are trivial (`Program__isRegionTrivial`: every block up to the join is tiny and not break/continue) is collapsed: the compare is removed, the predecessor is connected straight to the join's first real successor; otherwise, with option `0x21`, an if whose then arm is tiny and else arm is large has its arms swapped (`IfHeader__swapArms`). Ends by freeing the work arrays, optionally (option `0x11`) running the dead-code/recount pass, and writing the marker.

### 2.4 `pass_loop_trans` (`FUN_0012ccc0`): counted loops to hardware loops (INFERRED; the `1.0` step test is CONFIRMED)

For each loop header it builds a `LoopInfo` (a 0x44-byte record: `+0` counter-has-other-uses flag, `+4` init kind, `+8/+0xc` init source/lane, `+0x10/+0x14` bound source/lane, `+0x18/+0x1c` constant bound and its flag, `+0x20` loop-control mask (0xff or 0xffff), `+0x24` break target, `+0x28` if header, `+0x2c` loop header, `+0x30` counter initial value, `+0x34` counter phi, `+0x38` counter lane, `+0x3c` the opcode-`0x81` loop-start instruction, `+0x40` program). In the C source the record is a run of contiguous locals (`local_84[12]`, `local_54`, `local_44`) and the corpus keeps it that way. The recognisers: `LoopInfo__init` (header with two predecessors, loop-start instruction whose source 1 is a type-3 constant 0xff/0xffff), `LoopInfo__setCounterPhi`, `LoopInfo__matchCounterInit` (constant 0.0 or a register), `LoopInfo__matchCounterStep` (opcode `0x12` adding the constant `1.0`: CONFIRMED by `GH_U2F(...) == 1.0`), `LoopInfo__matchExit` (compare `0x8b` condition 3 or `0x8c`, bound source or constant). `LoopInfo__convertToHardwareLoop` allocates an `IRLoadConst` loop-control constant (type 5 with init/bound/step words, or type 3 with only the count), makes it source 1 of the loop-start instruction, bypasses the counter/compare/break blocks and detaches them. Afterwards the work arrays are freed and the dead-code/recount pass runs.

### 2.5 `pass_rewrite` (`FUN_0013d160`) and the clean-up `FUN_0013bd68`

`pass_rewrite` is a pipeline gated by options `0x13`, `0x17`, `0x18`, `0x19`, `0x37`, `0x1f` (the last one finally calls `pass_loop_trans`); it calls other passes' helpers (`FUN_0011fb94`, `FUN_0013c60c`, `FUN_00139f84` per if header with a new visit stamp, `FUN_001394b0`, `FUN_0013b3f0`, `FUN_0013caf4`, `FUN_001121b4`, `FUN_0013c210`) that were not read. `Program__eliminateDeadInstsAndRecountUses` (`FUN_0013bd68`, INFERRED name): mark-and-sweep over `program+0x3c4`: roots are instructions whose destination write mask is not the empty constant `DAT_001b0014`; the marks use the epoch stamp, the use counts are recomputed relative to the moved epoch, unmarked instructions without the keep flags (`inst+0x14` bits `8`/`0x10`) are erased through virtual slot 4 (counted in the program statistics); with `verifyCounts` the old counts are saved first and compared (returns 0 on mismatch).

### 2.6 `pass_optimize_control_flow` (`FUN_0012ab80`)

Calls virtual slot `0x74` of the target description (`compiler+0x30c`) with the program and writes the marker: the control-flow optimisation is a per-chip method (CONFIRMED, 88 bytes).

### 2.7 `pass_sched_preprocess_and_schedule_inst` (`FUN_00171714`) and `pass_minreg_order` (`FUN_00184ab4`)

R2b's typing called the first parameter `compiler`: it is the **Scheduler** object: `[0]` compiler, `[1]` program, `[2]`/`[3]` the target description's `+0x60`/`+0x64` objects (`Compiler__getResourceModel` / `getThreadModel`, INFERRED names from the RTTI classes `ResourceModel`/`ThreadModel`), `[5]`/`[6]` growable vectors, `[0xc]` a 0x30-byte record with a `DListNode`, `[0x4c]` a bit set over `[0x51] = target slot 0x138 + target slot 0x140` registers, `[0x4d..0x50]`, `[0x54..0x57]`, `[0x58..0x5b]` per-class arrays, `[100]` (+0x190) the running cycle count and `[0x6a]` (+0x1a8) the dot-product-transform count (the two strings above). Preprocessing moves instructions out of the entry block's single successor and into the predecessor of the exit block, writes `"sched_preprocess"`, optionally (option `0x43`) runs `pass_minreg_order` (walks every block's instruction list and reorders candidates through `FUN_0018413c`), runs the two big scheduling helpers `FUN_00169e30` and `FUN_00165014`, then for every block with more than two instructions runs `FUN_00170e6c` (the per-block list scheduler, 2.1 kB), adds its cycle estimate (`scheduler[0xb]`) to `[100]`, marks the hardware registers the schedule used (`Program__markHwRegUsed` over the three register ranges `[0x66]`, `[0x67]`, `[0x69]`), writes `"schedule_inst"`, and frees everything. The per-block scheduler itself (`FUN_00170e6c` and its ~90 callees, 62 kB) was **not** decoded.

### 2.8 `pass_ssa_build` (`FUN_001214fc`)

Only the set-up was read: a work vector seeded with the entry block, the visit epoch (`program+0x474`, `+0x478`) bumped, and, when option `7` is on, the construction of four hash tables at `compiler+0x3e0`, `+0x3e4`, `+0x3e8`, `+0x3ec` (each `{capacity <= 0x400, count, bucket array, hash function, equality function, arena}`; the function pointers are `PTR_FUN_001e90a0..bc`) plus two vectors at `+0x3d8`/`+0x3dc` and two records at `+0x3f0`/`+0x3f4`: this is the value-numbering state behind the options `max_vn_kills` / `max_vn_transforms` (R2b section 6). The renaming/phi insertion (6 kB of code, 213 reachable functions) was not decoded.

## 3. Leads and corrections for other work

* R2b's `class_methods.tsv` misses constructors that store the vtable through a local (`puVar1 = PTR_DAT_xxx; ... *this = puVar1 + 8`). A scan of the corpus for that pattern, mapping the non-lazy-pointer entry to the vtable address of the class tree, finds about 159 further functions (e.g. `FUN_00106ffc` and `FUN_0010704c` -> `IRFetch`, `FUN_0010709c`/`FUN_001070f8` -> `IRPseudo`, `FUN_00107154`/`FUN_001071a8` -> `IRAlu`, `FUN_001071fc` -> `IRMemStore`, `FUN_001074e0` -> `IRTextureFetch`): not renamed here (fork C1 owns class methods).
* `FUN_00108e40` is a constructor of an `IRPseudo` subclass that sets `inst+0x80 = 1` (`this[0x20]`), `FUN_00108174` / `FUN_00108304` set `+0x84 = 2` / `3` (source counts): leaf-class constructors of the IR hierarchy.
* The `compiler` typing of the first parameter of the scheduler functions in `names_R2_params.tsv` was wrong (it is the Scheduler); `pass_minreg_order`'s first parameter has been corrected the same way.

## 4. Not established

The opcode-number to class mapping, the `IRInst` flag bits at `+0x14` beyond `0x1` (visited), `0x8`/`0x10` (keep) and `0x200` (extra trailing operand), the meaning of the `+0x118`/`+0x150` stamps on blocks, the algorithms inside `FUN_00169e30`, `FUN_00165014`, `FUN_00170e6c`, `FUN_0016a568`, `FUN_0016ff54` (the scheduler), `pass_ssa_build`'s renaming, `pass_post_pack_insts` (`FUN_00145670`) and the `rewrite` sub-steps.
