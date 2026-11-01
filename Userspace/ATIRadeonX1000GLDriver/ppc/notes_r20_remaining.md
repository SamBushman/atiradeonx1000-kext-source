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
