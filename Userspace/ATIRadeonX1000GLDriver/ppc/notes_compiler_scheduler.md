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


# Round 5 (fork I1): scheduler block roles and the recovered algorithms

Names: `names_I1_snn.tsv`, `names_I1_snn2.tsv` (selectNextNode), `names_I1_bdg.tsv` (buildDependencyGraph), `names_I1_p044.tsv` / `names_I1_p044b.tsv` / `names_I1_p045.tsv` (the other Scheduler functions),
`names_I1_p049.tsv` / `names_I1_p049b.tsv` (R300 / R300V scheduling models and the presub helpers). The rows are web-based (`Tools/userspace/find_webs.py` with two
fixes kept in the fork's scratch copy: a `while( true )` loop has no exit edge, and a definition after `&&` / `||` does not kill the reaching definitions); the
gate (`verify_names.sh`, SPLITS=1) accepts every row.

## 12. Scheduler object additions (words of the Scheduler object)

| word | meaning | tier |
|---|---|---|
| [0x46] (+0x118) | fetch-batch mode: selects the fetch ready list (+0x34) instead of the ALU ready list (+0x4c) in `selectNextNode` | CONFIRMED |
| [0x44]/[0x45]/[9]/[8]/[10] | max node depth, model target depth (slot 0x5c), "low pressure" flag, thresholds from `computeNodePriorities` | INFERRED |
| [0x47]/[0x48] | maximum node height of the ALU-class / fetch-class ready nodes (`advanceCycle`) | CONFIRMED |
| [0x49] | cycle at which the last fetch batch ended (`updateFetchBatchMode`) | INFERRED |
| [0x3d] (+0xf4) | number of dot-product candidate pairs found by `packDotProductCandidates` | INFERRED |
| [0x60] | a spare address-register load instruction (`tryReuseAddressRegister`) | INFERRED |
| [0x5c]..[0x5f], [0x61] | in-flight address-register (a0) load nodes and their count | CONFIRMED |
| [0x62], [0x63] | in-flight loop-index load nodes | CONFIRMED |
| list at +0x64 | waiting list (`onNodeReady` pushes nodes whose predecessors have not all issued) | CONFIRMED |
| list at +0x7c | "passed over" list: candidates `selectNextNode` looked at and left; `advanceCycle` re-enqueues them as ready nodes | CONFIRMED |
| lists at +0xac, +0xc4, +0xdc | deferred buckets 1..3 of the ResourceModel (slot 15) for `transformDotProduct` | INFERRED |
| list at +0xf8 | special list: nodes held back while their group is built; moved to the ALU list by `advanceCycle` | INFERRED |

ResourceModel base class fields: +0xc / +0x10 / +0x14 count the issued nodes of resource class 1 / class 2 / the "special" (OPT_BALANCE) nodes (`SchedModel__countIssuedNode`,
`uncountNode`); slot 23 (0x5c, target depth) and slot 25 return the rounded average of those counters. ThreadModel: slot 4 (`ThreadModel__vslot4`) is the issue hook (records
the issue cycle of fetch-class nodes in this[2] and marks a thread break, flag 0x1000, when a fetch-fed consumer follows the previous break in this[1]);
slots 0x28 / 0x2c (10 / 11) classify nodes into two chains that `buildDependencyGraph` links with kind-4 edges.

## 13. SchedNode group record (node + 0x60, `buildCoScheduleGroups`)

`+0` lane mask (union of the members' write masks), `+4` hardware register (-1 until assigned), `+8` the first issued member node, `+0xc` four select bytes, `+0x10` member count,
`+0x14` cycle bound (starts at 0x7fffffff), `+0x18..+0x24` the member node of each component. Partial writers feeding the same operand of one consumer are collected through a work stack
(`buildCoScheduleGroups`, and again in the fallback of `selectNextNode`) so they receive one register.

## 14. `Scheduler__selectNextNode` (0x16ff54), algorithm

1. Take the fetch ready list when scheduler[0x46] (fetch-batch mode) is set, else the ALU ready list; walk it in order. In ALU mode stop at the first node whose position (+0x10) is past `cycleLimit`.
2. Address-register loads (`IRInst__isProjectionOfClass26or3a`) and loop-index loads (class 44) are handled by `tryReuseAddressRegister` / `tryReuseLoopIndexLoad`: a non-zero result issues the node,
   otherwise the node is moved to the passed-over list.
3. For any other node: with a co-schedule group whose register is already assigned (group + 4 >= 0) and OPT_SCHEDULER_ALLOC_REG on, the pending consumer counts of every
   component of that register (from the per-component writer arrays scheduler + 0x4d) minus the node's own use are checked; a node that would overwrite a live component is skipped.
   A node whose group leader issued in this very cycle must not overlap its lanes; register kinds (inst + 0x98) of group members are made equal.
4. Without a register (or when OPT_SCHEDULER_ALLOC_REG may allocate one) `Scheduler__findFreeTempRegister(file 1, component mask)` is asked for a temp register (mask 0x1010101 for texture fetches,
   `HwLimits` slot 0x7c = `isNotTextureFetch`); a register past `firstTempReg + 4` makes the node fall back to register kind 0.
5. The thread model must accept the node (`ThreadModel` slot 3); then the resource model: `canAddInstruction` (slot 3) accepts it; if the bundle is empty and the model refuses, `insertOperandCopy` may
   return a copy node to issue; with OPT_BALANCE ("special" nodes, slot 13) the register-state check (slot 11) or a swap with the single occupied bundle slot is tried.
6. A rejected node goes to the passed-over list, or to deferred bucket 1..3 (ResourceModel slot 15) when OPT_ALLOW_SCHED_TRANSFORMS is on and OPT_NO_REASSOC is off (dot-product transform candidates).
7. If the scan ended with address-register or loop-index loads seen, no ordinary node, an empty waiting list and an empty bundle, the in-flight a0 load is "split": every consumer with pending
   component uses gets a copy node (`createCopyNode`), the edges of its unissued consumers are re-pointed to the copy and the copy is enqueued.
8. If nothing was selected and no node was passed over, a fallback builds a group from the head of the list: the head becomes the leader of a new group record, its register-sharing sibling
   producers (other predecessor edges of the same consumer with the same operand indices) are pulled in through a work stack, and producers already issued or flagged get copy nodes
   (vectors vec / vec2 hold the copies and the producers they read); the head is then returned.

## 15. `Scheduler__buildDependencyGraph` (0x16a568), algorithm

Pass 1 (program order): one `SchedNode` per instruction that needs one (not entry/exit, `IRInst__needsNoSchedulerNode`); `addOperandDependencyEdges` for every source (and for the operands of a
presub / mix source), kind-5 ordering edges between the producers of a node reading a loop-index load, and, with OPT_SCHEDULER_REORDER off, kind-1 serial edges chaining each node to the previous
one. Pass 2 (backward, with a register-keyed hash set of the latest writer of every register): kind-1 write-after-write edges to the later writer, kind-2 anti-dependence edges from a
reader to the later writer of the register it reads, kind-4 edges between successive nodes of the two ThreadModel classes (slots 0x28, 0x2c), from fetch nodes to the latest class-0x2c node,
from ALU nodes to the latest class-0x28 node, and from fetch-class nodes to every node of the chain list.

## 16. Other scheduler functions decoded here

`Scheduler__markGlobalValues`: union-find over register ids (copies join their ids), a root is global when any member is live across blocks; `computeBlockRegisterSets`: per block a live-in set
(+0x100) and a live-out set (+0x104) over scheduler[0x51] registers, phi inputs go to the predecessor's live-out set, then a backward fixpoint; `computeNodePriorities`: height / depth /
32-bit descendant masks / per-class descendant counts per node and the height histogram of fetch nodes that fixes scheduler[8..10]; `transformDotProduct`: rewrites DP3 / DP4 (0x1c / 0x1d) to
the reduced forms (0x1e / 0xa3, mul 0x13, mul-add 0x14) around a helper instruction the ResourceModel (slot 0x40) provides and adds the helper -> node edge; `splitAddressRegisterUses`,
`tryReuseAddressRegister` (reuse an in-flight a0 load with the same address and component, else take a free slot), `tryReuseLoopIndexLoad` (a loop-index load covers [start, start + size)),
`allocateRegisterForNode` / `assignFreshVirtualRegister` (register assignment when the last consumer of a result issues), `findFreeTempRegister` / `findFreeHwRegister` (best free register by waste /
slack), `insertOperandCopy`, `releaseOperandsOfIssuedNode`, `commitBundle`, `advanceCycle`, `scheduleCycle`.

R300 models: `R300SchedModel::legalizeInstruction` (kill negation push-up, fetch-source movs, IrDsx/IrDsy, swizzle splitting through slot 26, presub expansion), `vslot28` (block legaliser: undo
unsupported presubs, merge identical presub sources through a hash), `vslot11` (pick a free component of the group's register), `vslot16` (reduced dot product), `vslot19` (resource class),
`vslot26` (swizzle split table), `vslot34` (swizzles natively readable); `R300VSchedModel::vslot27` (vertex legaliser: abs lowered to max(x, -x), IrCndGE lowered to set / add / mul / mul-add, one
register per restricted bank per instruction), `vslot17` (rotate the result component), `vslot3` / `vslot4` (bank bookkeeping of the current word), `vslot19` (class), `vslot28`;
`FUN_00186a88` forms IrPresub* instructions (0x99 BX2Neg, 0x9a Sub, 0x9b Add, 0x9c Invert) from add / mov / mul-add producers and constants +-1.0, +-0.5; `FUN_00187ad8` turns a compare into its
select form (0x24..0x26) and folds multiplies by it into a select of the other factor; `FUN_0018cdd8` records the source pair of one ALU slot.

Note for round 5 (I1): `names_D3_acc.tsv` line 1075 anchor was changed to `(?:iVar30|node)` and `names_R2_params.tsv` line 306 (`FUN_0016c1fc` param_1) now says `scheduler` (the function is `Scheduler__assignBundleRegisters`). One new name maps to one old variable per function.

## 11. Not done

`Scheduler__selectNextNode` (828 placeholders), `buildDependencyGraph` (658), `FUN_00187ad8`, `R300VSchedModel::vslot27`, `FUN_0018cdd8`, `FUN_00186a88`, most `R300SchedModel` slot bodies other than 13/26/27/28: the single-use temporaries are reused across many roles and need a per-block reading.
Two functions (`R300VSchedModel__vslot27`, `R300VMachineAssembler__encodeDestinationWord/DualMathOperands`) were restored to their pre-callee-pass text after the dataflow gate rejected the callee-result rows.
