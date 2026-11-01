# r19: resolving r18's open layout-audit results

Scope (from notes_r18_audit.md): 28 TIGHT functions, 6 runtime-indexed DIFFERENT, 2 libGLProg call-target DIFFERENT, 78 INCONCLUSIVE.
Tools are in Tools/userspace/audit_layout/ (they read the r18 base/cand .dis trees and per-part `gcc -gstabs -S` output; paths inside are
~/g5logs/tmp_r18 and ~/g5logs/tmp_r19, see the script heads).

## Key finding (changes how the r18 argument must be read)
r18 argued that a layout change between two escaped objects is harmless when "nothing in the base code can rely on the pair being adjacent".
That does not hold for **fake-struct overlays**: Ghidra splits one stock stack object into several C locals, and the C then passes `&firstMember`
to a callee that fills the whole object (`WriteMask__fromSelectWord(&x)` writes 16 bytes, `_memcpy(&procZoomX, ..., 0x274)`, `Vector__elementRefGrow(&workStackCapacity)`,
`_memcpy(&limitInfo, ..., 40)` ...). Those functions are correct only if gcc lays the member locals out contiguously in the stock order. The
accessed slots between two escaped objects are the *members*, so "separated pairs" are exactly where such a struct is hiding.

So the right per-function question is: for every access that leaves its declared object (callee extent > local size, memcpy/memset length > size, subscript
outside the array), is the window of frame slots it covers the same in base and cand? `Tools/userspace/audit_layout/winchk.py` answers that
(`ovl.py` finds the accesses: callee-extent through the corpus callee's parameter, memcpy/memset lengths, negative subscripts; `winchk.py` compares the
accessed/escaped slots inside [x, x+E) base vs cand, matching objects by rank among the escaped addresses).

Result (data: overlay_window_audit_r19.txt next to this file, and in libGLProgrammability/ppc/):
- GLDriver: 109 functions / 299 overlay sites; windows identical base vs cand: 222 sites, different: 71 sites (3 not locatable).
- libGLProg: 38 functions / 103 sites; identical 92, different 9, 1 part (part_001) does not compile with -gstabs (no map).
- GA, VA, libGL: no overlay sites.
A DIFFERENT window is NOT proof of a behaviour change by itself (base itself is not stock-faithful in many of these: base has odd-offset 1-byte locals inside the
window that the cand aligns), but it is the complete list of places where the corpus depends on frame adjacency and the adjacency changed. Resolving each
needs the struct written as one object from the stock offsets (the r17 method: `uint x[N]` / `outStruct`), a transcription job of its own. **Still open (listed in the data file).**

## Fixed (real defects, found by this audit)
Five functions read a neighbouring local through a negative subscript of the local the Ghidra frame put next to it (`arr[i - 4]`), so the C read whatever gcc put 4 bytes
below the array. The right object is the 4-byte local that precedes the array in the stock frame (Ghidra stack offset arithmetic, evidence below):

| function | old text | new text | stock evidence |
|---|---|---|---|
| RegAlloc__laneDependsOnChain (0x131008) | `laneDefOut[laneIndex + -4] != 0` | `((char *)&laneMaskWord)[laneIndex] != 0` | stock `addi r23,r1,0x38; ...; lbzx r0,r30,r23` (lane byte i of the word at sp+0x38, the word stored from readMask's output); laneDefOut is sp+0x3c |
| Program__forwardMovIntoConsumers (0xf07a8) | `consumerDestMaskView[sel - 4]` | `((char *)&consumerDestMask)[sel]` | view at stack -0x78, consumerDestMask at -0x7c (names rows) |
| IRInst__setConstantOperand (0xf6d14) | `uniqueRank[laneByte - 4] = 0` | `((char *)&existingSelect)[laneByte] = 0` | stock `addi r30,r1,0x88 ... stbx r27,r30,r0` (r27 = 0); existingSelect at -0x288 = sp+0x88, uniqueRank at -0x284 |
| Inst__foldMovIntoProducer (0x15b4a4) | `laneRemapBytes[i - 4]` (2 sites) | `((byte *)&operandSelect)[i]` | array at -0x44, operandSelect at -0x48 |
| Inst__collapseAlgebraic_0015c6d4 | `uniformConstOut[operandIndex + -4]` | `((char *)&operandSelectC)[operandIndex]` | array at -0x78, operandSelectC (old local_7c) at -0x7c |

Gate (base = main 79d701e7, G5 Tiger): tier 1 reports a problem in exactly these 5 functions (LENGTH: the code changed, as intended) and nothing else
(parts 024/026/040/044: 153/175/168/188 functions compared). No quota/No space/compared 0 lines. The laneDependsOnChain cand now loads the lane byte from
the 4-byte laneMaskWord slot (`addi r2,r30,96 ... lbzx`), matching the stock shape.
Stale rows: 3 rows anchored on the replaced lines (2 for laneDependsOnChain, 1 for collapseAlgebraic_0015c6d4) were removed (Tools/userspace/audit_layout/removed_rows_r19.txt);
the names they applied stay in the C. (Do not put a file with the old bare Ghidra names into the ppc/ directory: apply_names reads every file there and
reports "new function name ... already occurs".)

## The 2 libGLProg call-target DIFFERENT: name only, verified
`__BuildInterferenceSets` / `__RegistersReInterfere` call `_BitSetFirstSetBit` (cand) vs `orph_97c08028` (base). Base ledger: `0x97c08028 8 orph_97c08028`; cand ledger:
`0x97c08028 8 _BitSetFirstSetBit` (unowned_code/ledger.tsv, r10 rename of the same fragment); `data/DATA___la_symbol_ptr.c` word `0x97c08028 -> _BitSetFirstSetBit`; r10's
datacheck showed the link tree (labels, data.s, exports, symbol_map) identical. Same address, same 8-byte body, so the calls land on the same code. RESOLVED (name only).

## The 28 TIGHT functions
In every one the cand has the array immediately followed by the next object (gap == size) where the base had alignment padding after it. That matters only when something
accesses the first object beyond its size. Using the overlay scanner on the pair's two objects (cand names from the stabs map; Tools/userspace/audit_layout/tight_names.py):
- laneDependsOnChain: FIXED above (the adjacency-dependent read is gone).
- 22 functions have no out-of-object access involving the pair (no callee extent, memcpy length or subscript beyond the objects): the gap change cannot be observed by the C.
  This rests on the scanner (callee extents only for callees defined in the corpus; imports with counts such as io_connect calls are not modelled), so it is evidence, not proof:
  glDrawPixels_impl pair (layoutOut/srcSkipBytes) [its 628-byte memcpy is on procZoomX, window below], gld_readbackTextureLevel, recordPickNextToEmit,
  recordProgramAllocateAndEmit, vsdisPrintOutputMapping, Program__hoistInstructions, pass_flatten_ifs, PostPack__remapRootUsers_0014375c, the 8 libGLProg parser/compileNode/
  BindingTable/TParseContext functions, TPPStreamCompiler__constructFromOperand, ___frame_state_for, and the rest of the list.
- 5 have overlays touching the pair (propagateMovThroughUses, selectNextNode, flattenAndRebuildAddMulTree, _FlattenIf, _DetectConstantLoopsSimple): the window check gives
  identical windows base vs cand for propagateMovThroughUses, selectNextNode, flattenAndRebuildAddMulTree and _FlattenIf; `_DetectConstantLoopsSimple` has DIFFERENT windows
  (counterInfo/initInfo/limitInfo, each a 12-byte array that a 40-byte `_memcpy` overwrites; in the window a 1-byte local sits at +37 in base, +36 in cand). **Open** with the 71+9 above.
- glDrawPixels_impl: the 628-byte memcpy over `procZoomX` has a DIFFERENT window (open, a real fake-struct: the 0x274-byte pixel-processing state).

## The 6 runtime-indexed DIFFERENT
All six index a properly sized local array with a positive subscript; base/cand differ only in where the array sits relative to the region anchor.
- Program__assignExportSlotsByKind / Program__assignOutputExportSlots: `slotOwnerRegister[assignedSlot]` (arrays of 51/53 words; re-read here: the index is `firstSlot + bindingKind` / the allocator's next slot / `outputBase + *(exportInst + 0x140)`, program data, not bounded in the C; the array is the stock object (51/53 export slots). In bounds only by the hardware slot limit: OPEN at the stock-invariant level, same class as the two below.)
- KhanVs__vslot71_canCombineSources: `seenRegs[slotIndex]` / `[slotIndex + 3]`, int[10]; slotIndex is 0..2 (the loop stops when `slotIndex == 2`): max index 5. In bounds, PROVEN.
- SchedModel__assignConstantSelectors: `seenConstants[loopIndex2]`, int*[13]; loopIndex2 grows once per distinct constant and is not capped in the C (only `loopIndex < inlineLimit` caps its use). In bounds only if at most 13 distinct constants occur (a stock invariant). Not provable from the C: OPEN (evidence level: stock invariant).
- ilAssembleProgram (0xc8e50): unitTexFormats[32], inputMaskWords[6], dclValueTable[1024], intConstTable[1024], inputKindTable[17], all with runtime subscripts bounded by hardware limits (tex units, registers, kinds); not provable from the C: OPEN (stock invariant).
- Block__materializePendingMovs: no array subscript; the indexed access is the known address-taken fake-struct at slot 56 (r14/r16 hybrid, kept joined).

## INCONCLUSIVE (78 in r18)
sem_equiv improvements (Tools/userspace/sem_equiv.py): `bne cr7,$+8` (pc-relative branches), `dcbt`/`dcbtst`/`dcba` hints (no architectural effect),
`dcbz` (32-byte zero store). Rerun over all 126 parts (sem_audit_r19_raw.txt): EQUIVALENT 969 (was 965), UNINIT-PAIRED 228 (224), DIFFERENT 369 (366: 3 of the former
INCONCLUSIVE turned out to be the usual region-offset difference), INCONCLUSIVE 67 (78) before the `dcba` fix (2 more are fixed by it, not rerun).
The 67 left: 43 `partial overlap of frame accesses` (a word stored and read back by bytes, float/int punning, packing), 16 `no consistent slot correspondence` (block-correspondence),
1 each: outgoing area address taken (x2), indexed frame access, `trap`, no convergence, address-taken slots on one side only.
None of the 59 partial-overlap/block functions is in the overlay list (no out-of-object access found by the scanners), so the partial overlaps are punning inside a single local
(layout independent) -- evidence, not a sem_equiv proof. A byte-granular frame model for sem_equiv would turn those into EQUIVALENT/DIFFERENT; not done here.

## Counts
Resolved with evidence: 2 name-only, 5 transcription fixes (laneDependsOnChain is also one of the 28 TIGHT), 22 TIGHT (no out-of-object access found), 4 TIGHT with identical windows, 1 of 6 indexed proven in bounds (KhanVs__vslot71_canCombineSources).
Open: 71+9 overlay windows with a changed adjacency (needs stock-faithful struct transcription, e.g. glDrawPixels_impl, ffvp* temp-register records, _DetectConstantLoopsSimple),
4 indexed arrays (slotOwnerRegister x2, seenConstants, the ilAssembleProgram tables) that are in bounds only by stock/hardware invariants, Block__materializePendingMovs (kept joined), 1 TIGHT (_DetectConstantLoopsSimple), 67 INCONCLUSIVE.
