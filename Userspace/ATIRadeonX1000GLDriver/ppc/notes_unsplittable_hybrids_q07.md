# q07 (parts 042-046): placeholders that the gate rejects splitting, and why

Method: every attempted split was gated (SPLIT-EQUIVALENT required, TMPDIR on disk, full log read). The items below were tried and rolled back; they keep their Ghidra placeholder name.

* `pass_post_pack_insts`: iVar2 / iVar5 / iVar6 / iVar8 are the block/inst link cursors of the candidate scan (lines 8299-8394) and are also read after the loops; a range split gives `MERGE ... candidate slot 184 stands for 148 and 188` (and UNINIT). uVar15/uVar16/uVar20 vector-size copies: same MERGE. Left as placeholders.
* `FUN_001494dc`: iVar2 (chain dest select copy / predicate results), iVar3 (dest select), piVar6 (the zero used to initialise the last-operand buffer and the byte cursor): each split gave DATAFLOW + UNINIT (the register is reused across the two rewrite paths).
* `Use__sourceIsPlainSingleUse`: uVar5 (vector element count) - UNINIT when split.
* `FUN_00162dfc`: iVar11 (countdown / source def) - ADDRESS-TAKEN split at slot 56 (neighbours a `local_6c[6]` identity array addressed as `r30+56+disp`).
* Variables assigned inside one `&&`/`||` condition chain (FUN_001524b8 iVar12-15, FUN_00149de4 stale argument register iVar4) must carry one name for all their webs; the stale 5th-argument register of FUN_00149de4 is `staleArg5`.
* Joined names kept on purpose (same register, two roles): `instOpcodeOrResult`, `opcodeKind` (Inst__collapseAlgebraic_00158264), `outputScaleA` (FUN_001621c8), `blockCursorOrNewBlock` (Program__hoistFetchInsts), `operandScanIdxOrTrackUses` (Inst__collapseAlgebraic_0015c6d4), `firstInstOrOperandRecord` was split again after gating (see names_q07_32.tsv).
* `IfHeader__convertInnerIfToCmov`: iVar11 (branch inst, then the compare source via `iVar11 = IRInst__getOperandSource(iVar11,1)`; rows branchInstC/compareSource) and iVar5 (loop index vs predicate chain results) - each split gave DATAFLOW + UNINIT; uVar9 (compiler / then block stale argument) also left; Ghidra artifacts in_r6..in_r9 / uVar18 (64-bit pair) are not variables.
* `Inst__foldProducerIntoConsumer`: local_5c / local_54 keep joined names `maskOrSelectA` / `readMaskOrSelectB` (the slots hold a write mask and later an operand select word).
