# r16: hybrid-variable splits with a two-tier gate

## Tiers
- Tier 1 `Tools/userspace/split_equiv.py` (unchanged): same instruction stream modulo frame offsets, reaching-store equality, address-taken check, -O1 uninit count.
- Tier 2 `Tools/userspace/sem_equiv.py` (new): per-basic-block symbolic execution of the two `gcc -S` outputs. The function's own frame slots are private; external accesses (non-frame loads/stores, calls with r3..r10/f1..f13/outgoing args, return values and callee-saved regs) are compared as ordered events. A cand-slot -> base-slot simulation relation is inferred and checked on every CFG edge. Frame addresses that escape (`addi rX,r30,K`) form a region compared by layout.
- Rule used for a split row: tier 1 passes AND tier 2 is not DIFFERENT. Validation: `Tools/userspace/sem_equiv_selftest.py` (results in `sem_equiv_validation_selftest.txt`): positives (label rename, commutation, frame growth) give 0 DIFFERENT; mutants (const, swapped/dropped store, dropped call, call arg, inverted branch, argument register) are rejected, except hand-judged true no-ops (a `mr` whose value was already in the register, dead stores to private slots).
- Tools: `split_trial.py`, `fastgate.py` (about 10 s per part), `split_apply.py`.

## Applied (tier 1 and tier 2 both passed)
ValueKey__foldCompareLiterals uVar4; ValueKey__markRegisterLiveInBlock iVar2; IRInst__setExtraOperandSource uVar2; ColorGraph__removeNodeUpdateDegrees uVar5 (whole rename vectorSize); LoopInfo__init iVar2; R300MachineAssembler__rgbSelectForSourceSwizzle uVar2; arbDeclareVariable iVar1; _gldGetRendererInfo uVar2, iVar6; IRInst__operandSelectIsNotDefault bVar2 (single web, renamed selectIsDefault); arbParseSwizzleSuffix iVar2; _gldReclaimTexture iVar5; gld_buildVertexStreamCache uVar8. Rows: `names_r16_splits.tsv` (+ edits to the older tables where a variable's old rows were replaced).

## Not split
- Tier 1 passes, tier 2 DIFFERENT (escaped-region layout changes): _gldSetInteger iVar2/uVar3, _gldChoosePixelFormat iVar10, _gldCreateContext puVar2, ValueKey__foldMinOfConstants/foldMaxOfConstants iVar8. A new scalar shifts objects whose address is passed to a callee relative to the other escaped objects. Tier 1 alone would have accepted these.
- Block__materializePendingMovs iVar14: tier 1 ADDRESS-TAKEN, tier 2 region offsets differ. Escaped objects at frame offsets 180/184/200 become 204/208/224 relative to the lowest anchor at 56, because the split scalars land inside the region. The index into the adjacent `pendingInsts[4]`/`mergedLanes[3]` arrays is not proven in bounds, so harmlessness is not shown. Kept as `pendingCountOrMovInst`.
- Inst__collapseWithChainedSource iVar11, Inst__foldProducerIntoConsumer local_5c/local_54, vsdisFormatFloat local_98, gldValidatePointSize iVar4: ADDRESS-TAKEN / DIFFERENT / INCONCLUSIVE; remain joined.
- Single webs (cannot be split): ILReader__nextInstruction readerStateOrScratch (81 uses), Program__translateILInstruction pdVar17/pdVar18 web 0 and puVar21/pdVar32 (Ghidra stale argument-register artifacts). Their web-1 splits were tried and rolled back (already named).

## Transcription flaws found (not changed; they change content, not names)
- _gldGetRendererInfo: scalarOut1/scalarOut2 read but never written; scalarOut0[4] is passed with outCount 3. Should be one `uint scalarOut[3]`.
- _gldSetInteger: scalarIn0..3 are separate scalars but `&scalarIn0` is passed with count 1-2; they are not contiguous in the build. Should be `uint scalarIn[4]`.
- _gldReclaimTexture: `reservation`/`crBits` pseudo-variables are uninitialised (lwarx/stwcx modelling).
- Several functions read uninitialised slots in both base and cand (sem verdict UNINIT-PAIRED).

## Limits of sem_equiv
- The lowest `addi rX,r30,K` anchor is not always an escaped object, so a new lowest local shifts region offsets (false DIFFERENT; hand review).
- Identical CFG shape required; loops are handled via the fixpoint on the relation, INCONCLUSIVE when no relation is found.
- Libraries/`bl` targets are compared by symbol only; indirect calls by symbolic target.

## Not done
- Further splittable candidates from the survey (pass_color_graph variables, arbfpFetchParameterValue iVar9, pass_remove_empty_graphs piVar8, ildisPrintDestinationOperand uVar7/uVar8) need role naming.
- Audit of earlier tier-1-only splits with sem_equiv.
