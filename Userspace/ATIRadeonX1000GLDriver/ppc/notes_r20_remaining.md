# r20: fake-struct overlay windows (r19 audit: 71 GLDriver + 9 libGLProg)

Each flagged object was re-declared as ONE properly sized local (array/struct) at the stock size, taken from the stock binary's
frame (address-taken sp objects, record strides, callee fill sizes), with the old loose members mapped to element indices.
Verified per part on the G5 (`gcc -arch ppc -gstabs -S`): no foreign local falls inside any rewritten object's window; tier-1
(`split_equiv`) differs from the base only for the rewritten functions (LENGTH) plus pure label/LC renumbering downstream.
Rows naming the replaced locals were removed (listed in removed_rows_r20.rows in each binary dir); `#L` row anchors in rewritten
functions were shifted by the number of declaration lines removed. `apply_names --check`: see commit message for the final count.

## Fixed
GLDriver: part_006 fragmentTranslate{Rfl,Dsl,Sel,All,Any} (ilInstA/B/C[9]); part_009 extvsEmitMmul (operandA/B[7]),
extvsPrepareHardwareProgram (tempInstr[29]); part_013 arbParseParamBinding (constVec[4], plus transcription fix: missing W stores
per stock 0x89864); part_014 ffvpEmit{ClipPosition,FogDistance,TexCoordGen,BlendedEyeNormal,FogLinear,BlendedClipPosition}
(40-byte records); part_039/042/043/044/048/050 splat/uniform/operand-copy/scale records (Inst__*, IRInst__*, KhanVs/KhanPs/FudoPs
vslot85, Block__flattenAndRebuildAddMulTree chainList[6]).
libGLProg: TGenericLinker__FixOutputReads (opRecord[14]); _DetectConstantLoopsSimple (stepInfo/counterInfo/initInfo/limitInfo and
loopTempA..G as 12-word records, opRecord[14]); TIntermUnary__compileNode (op1Record/op2Record[14], operandDesc[2], constValue[1]);
_InterpreterEmulateOp (texel[4]); _PPCRuntimeCompilerBackupRegister (transferSel[4]).

## Not changed (scanner false positives)
Inst__collapseAlgebraic_00158264, Inst__foldProducerIntoConsumer, Inst__mergeSplatSourceInsts_001621c8, Scheduler__markGlobalValues:
the callee (WriteMask__fromSelectWord) writes only 4 bytes, so the scanner's 16-byte extent is wrong.

## Deferred / open
- glDrawPixels_impl (part_002, 628-byte memcpy over procZoomX) and gld_readbackTextureLevel: r17's zone (parts 000-005).
- KhanPs__vslot85_findOrEncodeConstantVector: stock passes a 24-word struct by value to Compiler__getOrCreateLoadConst4; the C
  (and the callee, 0xf5248) still pass/accept only 7 words. Needs a transcription fix of both.
- Ledger boundary errors: arbParseParamBinding (ledger 0x8aa40) is really stock 0x89864; Block__flattenAndRebuildAddMulTree ledger
  size 220 is wrong (big function); FUN_000934f0 header size vs body mismatch (noted earlier).
- Runtime-indexed arrays from r19 (slotOwnerRegister x2, seenConstants, ilAssembleProgram tables): bounds proofs not attempted.
- TIntermUnary__compileNode / _InterpreterEmulateOp: generated code was already identical, frame gaps between records (stock
  8-byte pads) are not reproduced; behaviour unaffected.

## Follow-up evidence (coordinator's three points)

### (1) ffvpEmitTexCoordGen (FUN_00096600) CODE difference
Full normalised .dis diff (stack offsets of r30/r1 and L/LC labels normalised) shows exactly two kinds of difference:
(a) 4 `addi rN,r30,K` where K is the address of a rewritten local (&texTempA/&texTempB; expected: the objects moved),
(b) 4 sites `lwz r0,0(r2); stw r0,X(r30)` -> `lwz r2,0(r2); stw r2,X(r30)`: same load address, same stack store, only the
scratch register differs (r2 is dead afterwards; the next instruction is the branch, gcc -O0 keeps every value on the stack).
Same stores, calls, arguments and returns; the register pick is gcc allocator noise from the changed local layout.

### (2) naming: placeholders / named decls per rewritten function -> counts_result.txt
Placeholders 148 -> 148 (unchanged; the 148 were already there, e.g. extvsPrepareHardwareProgram 85, _InterpreterEmulateOp 41).
Named decls 1609 -> 1376 because 233 loose member names became array/struct elements. Their roles are kept: every folded
member is a function-scoped `#define <oldName>_IDX <word>` before the function (and `#undef` after it), and the array is indexed
`arr[<oldName>_IDX]` (256 constants in 28 functions; struct rewrites keep field names). Generated code is unchanged by this
(tier-1 vs the previous commit: 0 problems in all 15 touched parts).

### (3) mechanical per-function evidence (Tools/userspace/audit_layout/r20/)
- `inv.py`: reverse-substitutes every logged rewrite (and expands the `_IDX` constants) in the NEW body and compares it with
  the OLD body (pre-r20 main, aaec42e4): 31/32 identical; arbParseParamBinding differs only by the intended new W stores.
  (Documented one-off manual edits are folded in as explicit reverse rules: BlendedClipPosition blendTemp3Reg, FixOutputReads
  opHeader pointer use, _DetectConstantLoopsSimple opSrc0BHigh.)
- `offs.py`: maps each old member back to its Ghidra local (via the removed local rows), converts to the stock sp offset
  (frame - NN) and checks base + 4*word is the same base for all members and that base is a stock address-taken object:
  60/62 arrays pass; the other two (Block__flattenAndRebuildAddMulTree chainList, TIntermUnary__compileNode constValue) have no
  renamed members and were checked by hand against the stock object (6-word DListNode, single word at sp+0xd8).
- arbParseParamBinding W stores vs stock 0x89864: splat path stores the same float to sp+0x44,0x38,0x3c,0x40; default path
  stores 1.0 to 0x44 and 0.0 to 0x40,0x3c; a 4th parsed component stores to 0x44. The C matches (store order on the stack
  frame differs from stock only in the splat path: W first in stock, X first here; not externally observable).
