# GLDriver shader compiler: the instruction scheduler (fork D2, round 3)

Scope: `pass_sched_preprocess_and_schedule_inst` (`0x171714`) and the ~60 functions reachable from it in `0x1648ac`-`0x172204`, plus the resource-model helpers
(`PackState`, `SchedModel` packing checks) around `0x189560`-`0x18c768`. Names are in `names_D2.tsv` (variables), `names_D2_func.tsv` (functions). Tier
words are those of the rows: CONFIRMED = a string, a counter that is logged, or a body that plainly does what the name says; INFERRED = the role is the
simplest reading of the code. The compile gate shows only that the code is unchanged.

Evidence strings in this pass (compiled-out logging, but the format strings and counters remain): `"sched_preprocess"`, `"schedule_inst"`,
`"Scheduler : Total cycles %d"` (scheduler[100]), `"Scheduler : Total dot-product transformed %d"` (scheduler[0x6a]),
`"Scheduler : %d out of %d instructions are marked global"` (in `Scheduler__markGlobalValues`).

## 1. The Scheduler object (int index = word, byte offset = 4 * index)

`Scheduler__run` (`FUN_00171e68`) builds it on the stack (0x1d8 bytes, DList sentinels at +0x34, +0x4c, +0x64, +0x7c, +0x94, +0xac/+0xc4, +0xf8) and calls the pass.

| word | meaning | tier |
|---|---|---|
| [0] | the compiler (arenas at +0x374/+0x378, target description at +0x30c, option test `Compiler__isOptionEnabled`) | CONFIRMED |
| [1] | the program (block list head at +900) | CONFIRMED |
| [2], [3] | `ResourceModel` and `ThreadModel` (`Compiler__getResourceModel/getThreadModel`) | CONFIRMED |
| [4] | the block being scheduled | CONFIRMED |
| [5] | vector of "external" nodes (producers outside the block) | CONFIRMED |
| [6] | vector of all nodes of the block, indexed by `inst+0x150` | CONFIRMED |
| [8] / [9] / [10] | threshold / "low pressure" flag (`maxDepth <= modelDepth`) / second threshold computed by `computeNodePriorities` | INFERRED |
| [0xb] | the current cycle | CONFIRMED (stored into node+0x2c/+0x30 by `issueNode`) |
| [0xc] | the issue bundle record: five node slots plus a DList (`ResourceModel__vslot29` fills them) | CONFIRMED |
| [0x13]..[0x18], [0x19].. | the ready lists (list nodes at +0x34, +0x4c, +0x64, +0x7c, +0x94, +0xf8; see section 5) | INFERRED |
| [0x44], [0x45] | maximum node depth (+0x14) and the model's target depth (resource model slot 0x5c) | CONFIRMED |
| [0x46]..[0x4b] | fetch-batch state: mode flag, maxima of node height for ALU-class and fetch-class nodes, a counter | INFERRED |
| [0x4c] | live-out register bit set (one bit per hardware register) | INFERRED |
| [0x4d]..[0x50] | per component: array indexed by hardware register of the node that last wrote it | CONFIRMED (`buildDependencyGraph`, `releaseOperands`) |
| [0x51] | number of hardware registers (target slot 0x138 + slot 0x140) | CONFIRMED |
| [0x54]..[0x57], [0x58]..[0x5b] | per component: last-use cycle arrays of the two register files | INFERRED |
| [0x5c]..[0x5f] | up to four address-register (a0) load nodes in flight (count in [0x61]) | INFERRED |
| [0x62], [0x63] | two loop-index load nodes | INFERRED |
| [0x66], [0x67], [0x68], [0x69] | register high-water marks, marked used at the end of the pass (`Program__markHwRegUsed`) | CONFIRMED |
| [100] | total cycles (logged) | CONFIRMED |
| [0x6a] | dot-product transforms (logged) | CONFIRMED |

## 2. SchedNode (0x74-byte allocation, vtable `0x1f6520`; the node is allocation+1)

| offset | meaning | tier |
|---|---|---|
| +0 | vtable (`SchedNode`, slot 1 deleting dtor) | CONFIRMED |
| +4 / +8 | DList prev / next | CONFIRMED |
| +0x0c | height: longest path to a sink (propagated from consumers to producers) | INFERRED |
| +0x10 | position index (reverse walk) | INFERRED |
| +0x14 | depth: latency-weighted longest path from the roots | INFERRED |
| +0x18 | tie-break priority | UNKNOWN |
| +0x1c | on a fetch path | INFERRED |
| +0x20, +0x24, +0x28 | counts of descendants by resource class (via the 32-bit descendant mask) | INFERRED |
| +0x2c | the cycle the node issued in (-1 until scheduled) | CONFIRMED |
| +0x30 | earliest cycle (ready cycle) | CONFIRMED |
| +0x34 | remaining unscheduled predecessors | CONFIRMED |
| +0x38 | the instruction | CONFIRMED |
| +0x3c | node index in scheduler[6] (also stored at `inst+0x150`) | CONFIRMED |
| +0x40 | vector of successor edges (this node is the edge `from`) | CONFIRMED |
| +0x44 | vector of predecessor edges (this node is the edge `to`) | CONFIRMED |
| +0x48..+0x54 | per component: number of unissued consumers of the value in that component | CONFIRMED |
| +0x58 | resource class (resource model slot 0x4c: 1, 2, 3) | CONFIRMED |
| +0x5c | non-zero when the node is "special" for the model (option 0x28 and model slot 0x34) | INFERRED |
| +0x60 | group record (`Scheduler__buildCoScheduleGroups`) | INFERRED |
| +0x68 | marked by `packDotProductCandidates` | INFERRED |
| +0x6c | next consumer sharing this address-register load | INFERRED |

## 3. DepEdge (0x24-byte allocation; edge pointer = allocation+1)

`+0` from node, `+4` to node, `+8` kind, `+0xc` latency (`Scheduler__getDependencyLatency`), `+0x10`/`+0x14` operand indices, `+0x18` four per-component bytes
(mask of the components carried), `+0x1c` flag from `ThreadModel` slot 0x20 (the producer is a fetch). Kinds seen: 0 data (latency from the resource model), 1 serial
order (latency 1), 2/3/4/5 ordering edges with latency 0 (3 between partial writers of the same register, 4 between successive fetch/export instructions,
5 around the opcode-0x44 instruction); the kind is the only thing that differs.

## 4. Per-block flow (all INFERRED names except where marked)

1. `pass_sched_preprocess_and_schedule_inst`: allocates the vectors and bit sets, moves instructions into the entry/exit blocks, runs `markGlobalValues` (CONFIRMED by its log string),
   `computeBlockRegisterSets` (live-in/out bit sets by backward fixpoint), then `scheduleBlock` for every block with more than two instructions.
2. `Scheduler__scheduleBlock` (`0x170e6c`): `buildDependencyGraph`, `buildCoScheduleGroups`, `computeNodePriorities`, clear the register-state arrays, seed the lists, then repeat
   `scheduleCycle` / `advanceCycle` until nothing is left.
3. `Scheduler__scheduleCycle`: `selectNextNode` until the model says the bundle is full; `transformDotProduct` for candidates; `commitBundle`.
4. `Scheduler__issueNode` / `issueDeadNode`: sets the cycle, calls the models, `releaseOperandsOfIssuedNode`, `updateSuccessorsAfterIssue` (readyCycle = issue cycle + edge latency).

## 5. Lists

The pending/ready lists of `Scheduler__enqueueReadyNode` are kept sorted with `Scheduler__compareNodes`; which list a node goes to depends on `ThreadModel` slots 0x20/0x24 (fetch-class)
and on `node+0x68`. The exact role of each of the six lists is not decoded.

## 6. R5xx ALU packing (R520SchedModel)

`R520SchedModel+4` holds the state of the current ALU word (0 nothing, 1 vector part used, 2 scalar part used, 3 both, 4 non-ALU); `+0x18..+0x24` are slot usage counters and
`+0x28` is a `PackState` (0x34 bytes: six counters and three 3-element arrays). `canAddInstruction` copies the state (`PackState__copy`), tries
the vector/scalar slot fit, the constant-operand fit (`SchedModel__fitsConstantLimit`, `SchedModel__assignConstantSelectors`) and the
swizzle-pair check, and `addInstruction` commits it.

## 7. Not decoded

`FUN_0016629c` (rewrites list-0x94 nodes into an add), `FUN_00164a74` (fetch-batch state update), `FUN_00166a0c`, `FUN_00164fc0`, `FUN_00164df4`, the bodies of ResourceModel slots
0x34..0x4c and the thread model, the six lists' exact roles, and the contents of the R300SchedModel slot bodies other than `vslot26` (swizzle legalisation) and `vslot28` (a block legaliser that
replaces certain mov/mad forms and collapses duplicate sources). `R300SchedModel__vslot28` is called by the pass as `resourceModel slot 0x70(program)`.

# Round 4 (fork E1): small scheduler functions, model slot map, leaf helpers

Names: `names_E1_func.tsv` (functions), `names_E1.tsv` (variables), `names_E1_callee.tsv` / `names_E1_models.tsv` (webs defined by calls to a named function / to a model slot).
Tiers as in the rows; the compile gate shows only that the code is unchanged.

## 8. Functions identified

| function | name | what it does |
|---|---|---|
| `FUN_0016629c` | `Scheduler__expandPresubToAdd` | walks the deferred list (scheduler word 0x27 = list at +0x94); for a node whose instruction has more than one source and at least one component with pending consumers builds an `IrAddFloat` (opcode 0x12) from the node's sources 1 and 2 (negate bit on source 1 set when the original opcode is 0x9a `IrPresubSub`), asks resource-model slot 3 (`canAddInstruction`) and, if accepted, swaps the node's instruction, updates its resource class (slot 0x4c) and the "special" flag (slot 0x34 with option 0x28), re-routes the data edges to the consumers (consumers already scheduled kill the instruction) and returns the node for issue |
| `FUN_00164a74` | `Scheduler__updateFetchBatchMode` | end-of-cycle update of the fetch-batch mode word `scheduler[0x46]` from the two ready lists (+0x34 fetch, +0x4c ALU), the cycle counters and the arguments (count of fetch nodes at the top height, maximum fetch depth) |
| `FUN_00165014` | `Scheduler__computeBlockRegisterSets` | allocates per block two bit sets of `scheduler[0x51]` bits (+0x100 uses, +0x104 live-out) and fills them from the registers read by every instruction; phi inputs are added to the predecessor block's +0x104 set |
| `FUN_00166a0c` | `Scheduler__hasOtherFlaggedProducer` | a data-edge consumer of the node has another predecessor edge with the same operand indices whose producer instruction carries flag 0x40 |
| `FUN_00164df4` | `IRInst__needsNoSchedulerNode` | phi, pseudo instruction without sources (flag 0x8000, category != 1) or opcode 164 (`IrLoad`): no `SchedNode` is created |
| `FUN_00164fc0` | `IRInst__writesTrackedRegister` | has a destination and (category 1, flag 0x40, or class +0x98 in 0x20..0x22) |
| `R300SchedModel::vslot13` | `tryRewriteConsumerSelects` | speculative rewrite of the select bytes of every consumer operand in `[selectLow, selectHigh]` to a replacement select, with an undo log of three vectors (instruction, operand index, old select word); 0 and full rollback if a consumer cannot take it |
| `R300SchedModel::vslot27` | `legalizeInstruction` | see the func row: negation push-up for kills (option 0x40), `IrMovFloat` copies for sources whose abs/neg modifiers or swizzle the hardware word cannot hold, `IrDsx/IrDsy` operand copies |

## 9. Resource and thread model slots as the scheduler uses them (index = offset/4; INFERRED from call sites and default bodies)

ResourceModel (`scheduler[2]`): 2 reset (zeroes the state word at +4); 3 `canAddInstruction`; 4 `addInstruction`; 5 end-of-word (default calls slot 2); 6 default 0; 7 void; 8 bundle-full test (default 0, used as a loop guard
in `scheduleCycle`); 9 bundle-empty (`state == 0`); 10 `inst+0x98 == 6`; 11 register-state fit check (called with the writer arrays `scheduler+0x4d`); 13 consumer-select rewrite (the override above), result stored
in `node+0x5c`; 15 deferred-list bucket 1..3; 19 resource class 1/2/3 (default 3); 28 block legaliser (called by the pass entry); 29 fills the issue bundle record.
ThreadModel (`scheduler[3]`): 2 reset (`+8 = 0, +4 = 1`); 3 issuable-now test; 7 per-block flag test (`scheduleBlock` marks the successor blocks at +0xdc); 8 fetch-class test; 9 second thread-boundary test.

## 10. Leaf helpers (select words are 4 bytes, one per component; 4 means "unused", 1 in a destination select means "component not written")

`SelectWord__areCompatible`, `readMask`, `clearReadComponents`, `isIdentity`, `maskUnused`, `selectWhereMasked`, `firstWrittenComponent`, `firstUnwrittenComponent`, `matchesDefaultPattern`, `matchesAnyKnownPattern`;
`IRInst__getOperandSourceOrDefault` (70 uses), `getUniformSourceConstant`, `sourceIsSplatConstant`, `countWrittenComponents`, `clearSourceSelectsOfUnwrittenComponents`, `copyBodyFrom`, `getOrCreateOperandRecord`,
`setHardwareRegisterAndAdd`, `isProjectionOfClass26or3a/44`; `IROperand__copyFrom`; `BitSet__setBit`; `Vector__insertAt`; `DList__isEmpty`, `initSentinel`; `SchedModel__countIssuedNode`, `uncountNode`, `resetCounters`.

## 11. Not done

`Scheduler__selectNextNode` (828 placeholders), `buildDependencyGraph` (658), `FUN_00187ad8`, `R300VSchedModel::vslot27`, `FUN_0018cdd8`, `FUN_00186a88`, most `R300SchedModel` slot bodies other than 13/26/27/28: the single-use temporaries are reused across many roles and need a per-block reading.
Two functions (`R300VSchedModel__vslot27`, `R300VMachineAssembler__encodeDestinationWord/DualMathOperands`) were restored to their pre-callee-pass text after the dataflow gate rejected the callee-result rows.
