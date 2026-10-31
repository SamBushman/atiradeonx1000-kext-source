# r14 (GLDriver variable webs) - what was done and what is left (Oct 31)

Approach: no splitting of anything the gate rejects (split_equiv.py untouched). Each *web* (def-use component found by find_webs) of the big
Ghidra scratch variables got its own name via `use` rows (names_r14_translate.tsv, names_r14_misc2.tsv); variables that are one single joined
web or sit in the folded-address slot got ONE joined name (names_r14_misc.tsv). Joined names say so in the name and evidence.

* `Program__translateILInstruction` (was FUN_000fb3d4, 526 placeholders): 48 PLAIN webs named (pdVar17/18/25/26/27/28/29/30/31/32, puVar5/21,
  pvVar15, iVar6/iVar20, uVar1/12/19/35/39, bVar2/bVar3, dVar4). Many pdVar names are honest hybrids (`scratchInstOrOperandIndex`,
  `scratchSourcePtrOrZero`, `extensionWordOrCompiler`, `tokenIndexOrConstant`): gcc reused one register for unrelated roles and gotos join them.
  Left as Ghidra names on purpose: `local_94` (`dword local_94[3]`, address-taken fake array: renaming it as a scalar broke the compile),
  `local_80`, `local_98`, `local_88`, `local_84` (address-taken scratch words), `param_5` (stack-pointer parameter later reused as scratch), and the
  `extraout_r4*` residual-register artifacts.
* `ILReader__nextInstruction` iVar4 -> `readerStateOrScratch` (one 81-use web).
* `Block__materializePendingMovs` iVar14 -> `pendingCountOrMovInst` (whole variable; splitting it gives ADDRESS-TAKEN slot 56).
* names_r14_misc2.tsv: ~40 single-role webs in 27 functions (ild*, ffps*, Compiler__*, DominatorTree__free, IRInst__*, ...).
* `IRInst__operandSelectIsNotDefault` bVar2: NOT named. Its two defs (one per branch) join at the `return`; the rows' anchors were broken by an
  earlier rename of iVar1 and a partial application gave DATAFLOW/UNINIT; the function is left exactly as before.

Still placeholders (all gate- or artifact-bound): Ghidra stale-register artifacts (`in_r5..in_r10`, `extraout_r4*`, `unaff_r*`), `in_stack_*`,
fake-struct locals and `#define` overlays (`Program__translateILStream` local_14c/164 ..., `psnAnalyzeProgram`, `Scheduler__*`), names that appear
only in comments, and the `FUN_` callee refs owned by other ranges.
