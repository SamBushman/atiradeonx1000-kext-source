# r17: GLDriver transcription flaws (contiguous scalar blocks, store-conditional pseudo-calls)

Scope asked: `_gldGetRendererInfo`, `_gldSetInteger`, `_gldReclaimTexture`. Directive also said to check sibling functions for the same pattern and fix or report. The siblings below were fixed because they have the SAME defect (a block the callee/kernel treats as contiguous, or an inline lwarx/stwcx. loop, transcribed as something that is not that). 40 functions changed in total (not 3); the tables below say exactly which and why.

## Flaw classes (what was wrong)
- **A. lwarx/add/stwcx. loop transcribed as a call to `storeWordConditionalIndexed`** plus an unwritten `reservation` flag, a made-up `crBits` loop and an unused "stored value" local. `storeWordConditionalIndexed` exists nowhere (the object calls an undefined symbol - same family as issue #64 dcbz/dcba) and `reservation` was read uninitialized. Fix: new macro `atomicAddWord(p,d)` in `ghidra_c.h` (inline `lwarx / add / stwcx. / bne-`, yields the OLD word = the lwarx result). 47 sites in 28 functions, all converted.
- **B. input/output scalar block as separate scalars** (`scalarIn0..3`, `scalarOut0..2`, `queryResult0..4`) with `&scalarIn0` passed to `_io_connect_method_scalarI_*` as if contiguous (callee reads N words). Fix: one `uint x [N]`.
- **C. 8-byte kernel output struct {handle, backing} transcribed as `outHandle` (4 bytes) + a separate `newBacking`** (or `outHandleUnused [4]` + `newBacking`) - the kernel writes 8 bytes through the pointer; `newBacking` was never written in C (10 -Wuninitialized warnings). Fix: `int outStruct [2]` (`[0]` handle, `[1]` backing; `structOut [2]` in gld_setQueryAgpRefBacking).
- **D. `_gldAllocVertexBuffer`**: input struct is 0x14 bytes (`structIn0/1` only 8 declared) and output is {chunk, chunkMemory} as two loose locals. Fix: `uint structIn [5]` (words 2..4 are never written in stock either: stack garbage) and `int chunkOut [2]`.
- **E. `_gldGetRendererInfo`**: `scalarOut1/2` read but never written, `scalarOut0[4]` passed with count 3, and `gld_fillMaxPixelFormat(rendererInfo)` lost its 2nd argument (stock loads r4 = `scalarOut[0]`; the callee ignores it, kept for call-argument parity). Fix: `uint scalarOut [3]`, `rendererInfo[0xc]=scalarOut[2]`, `[0xd]=scalarOut[1]`, 2nd arg `scalarOut[0]`.

## Evidence that the new C matches STOCK
Honest limit first: a tier-1 (`split_equiv.py`) or tier-2 (`sem_equiv.py`) comparison against the stock binary is NOT possible - stock is optimized code (bdnz loops, different block graph, stmw/lmw frames) and the corpus is compiled -O0, so the CFG shapes differ for every function; `sem_equiv` would report DIFFERENT/INCONCLUSIVE for any function regardless of correctness. What was done instead, per class, all from the real stock Mach-O (`tiger-hd-pull/ATIRadeonX1000GLDriver.bundle.bin`, machoutil + Capstone, per-word decode):
- **A**: scanned every `lwarx` in stock `__text`: 47, each exactly `lwarx / add / stwcx. / bne <back to lwarx>`, delta +-0x10000 (4 sites use a register delta set earlier; the C passes +0x10000 there). Compiled the new C on the G5 and extracted the same signature: all 28 functions have identical lwarx count and identical delta multiset to stock (script output `functions 28 mismatch 0`). Spot read of `_gldReclaimTexture` stock 0x9338 / 0x938c: old value (lwarx dest) compared with 0x10000 -> `_io_connect_method_scalarI_structureI(conn,0xb,...)`, matches `oldRefCount = atomicAddWord(p,-0x10000); if (oldRefCount == 0x10000)`.
- **B**: for every scalarI_* call in stock the input pointer is `addi r5,r1,0x38` with count N (2 or 4) and the words are stored at consecutive ascending 0x38.. offsets; `_gldGetInteger` out ptr r1+0x3c, count slot r1+0x38, count 3; `gld_initContextHardwareState` out ptr r1+0x50, count 5, stores at 0x50..0x60; `_gldGetRendererInfo` scalarOut at 0x40..0x48 (0x48 -> rendererInfo+0x30, 0x44 -> +0x34, 0x40 -> r4 of gld_fillMaxPixelFormat). Array sizes equal the count each call passes.
- **C/D**: all 12 stock `structureI_structureO` calls (stub 0x1a3780): output ptr `addi r7,r1,0x3c`, size slot r1+0x38 = 8, backing read from r1+0x40, handle from r1+0x3c; `_gldAllocVertexBuffer` input `addi r5,r1,0x44`, stores only 0x44 (=2) and 0x48 (=0x16000), size 0x14.
- **Compiler check**: -Wuninitialized warnings in parts 000-005 fell 25/37/59/71/55/31 -> 14/24/32/65/48/30 (the `scalarOut1/2`, `newBacking`, `reservation` warnings are gone).

## Nothing outside the intended fix changed
- Only the 40 functions below differ in `part_000..005.c` (+ `ghidra_c.h` macro, + stale rows removed). 
- Base-vs-candidate, compiled on the G5 (Tiger): after normalising local label numbers (they shift when earlier functions shrink - the plain gate prints those as CODE lines and cannot be read as pass/fail), tier-1 `split_equiv.py` reports problems ONLY in changed functions (0 unexpected function in all six parts); tier-2 `sem_equiv.py` reports every unchanged function IDENTICAL-CODE (54/53/52/53/55/61 per part) and all DIFFERENT/INCONCLUSIVE ones are changed functions (sem_equiv does not model lwarx/stwcx. and the frame blocks moved, so these cannot be EQUIVALENT by construction). 
- Parts 006+ do not use the new macro (ghidra_c.h is only extended).

## The 40 changed functions
Columns: class(es) / rows removed / Ghidra-style placeholder count before -> after / locals removed and added.

| function | class | rows removed | placeholders | locals |
|---|---|---|---|---|
| _gldSetInteger | B | 4 | 0 -> 0 | removed: scalarIn0, scalarIn1, scalarIn2, scalarIn3; added: scalarIn |
| _gldGetInteger | B | 3 | 0 -> 0 | removed: scalarOut0, scalarOut1, scalarOut2; added: scalarOut |
| _gldDestroyMemoryPluginData | A | 2 | 0 -> 0 | removed: reservation, updatedRefCount |
| _gldReclaimBuffer | A | 3 | 0 -> 0 | removed: crBits, reservation, updatedRefCount |
| gld_setBufferAgpRefBacking | A+C | 12 | 0 -> 0 | removed: cr0Bits, newBacking, newRefCountStored, oldRefCountStored, outHandleUnused, reservation; added: outStruct |
| gld_setBufferNewTextureBacking | A+C | 12 | 0 -> 0 | removed: cr0Bits, newBacking, newRefCountStored, oldRefCountStored, outHandle, reservation; added: outStruct |
| _gldAttachDrawable | B | 4 | 0 -> 0 | removed: scalarIn0, scalarIn1, scalarIn2, scalarIn3; added: scalarIn |
| gld_bindCurrentFramebuffer | A | 4 | 0 -> 0 | removed: casResult, casResult2, crField0, reservation |
| _gldGetRendererInfo | E | 3 | 0 -> 0 | removed: scalarOut0, scalarOut1, scalarOut2; added: scalarOut |
| _gldDeleteTextureLevel | A | 3 | 0 -> 0 | removed: crBits, reservation, updatedRefCount |
| _gldReclaimTexture | A | 7 | 0 -> 0 | removed: crBits, reservation, updatedRefCount |
| gld_releaseQueryMemory | A | 3 | 0 -> 0 | removed: crBits, reservation, updatedRefCount |
| gld_setQueryAgpRefBacking | A+C | 5 | 0 -> 0 | removed: crBits, newMemory, reservation, structOut0, updatedRefCount; added: structOut |
| gld_ensureTextureBackingSized2 | A+C | 11 | 0 -> 0 | removed: newBacking, newRefCountStored, oldRefCountStored, outHandle, reservation; added: outStruct |
| gld_ensureTextureAgpRefBacking | A+C | 11 | 0 -> 0 | removed: newBacking, newRefCountStored, oldRefCountStored, outHandle, reservation; added: outStruct |
| gld_setTextureAgpRefBacking | A+C | 12 | 0 -> 0 | removed: cr0Bits, newBacking, newRefCountStored, oldRefCountStored, outHandleUnused, reservation; added: outStruct |
| gld_setTextureNewTextureBacking | A+C | 12 | 0 -> 0 | removed: cr0Bits, newBacking, newRefCountStored, oldRefCountStored, outHandle, reservation; added: outStruct |
| gld_ensureTextureSurfaceBacking | A+C | 12 | 0 -> 0 | removed: cr0Bits, newBacking, newRefCountStored, oldRefCountStored, outHandleUnused, reservation; added: outStruct |
| gld_ensureTextureGlobalBacking | A+C | 12 | 0 -> 0 | removed: cr0Bits, newBacking, newRefCountStored, oldRefCountStored, outHandleUnused, reservation; added: outStruct |
| _gldModifyVertexArray | A | 2 | 0 -> 0 | removed: reservation, updatedRefCount |
| _gldReclaimVertexArray | A | 3 | 0 -> 0 | removed: crBits, reservation, updatedRefCount |
| gld_setVertexArrayAgpRefBacking | A+C | 12 | 0 -> 0 | removed: cr0Bits, newBacking, newRefCountStored, oldRefCountStored, outHandleUnused, reservation; added: outStruct |
| gld_setVertexArrayNewTextureBacking | A+C | 12 | 0 -> 0 | removed: cr0Bits, newBacking, newRefCountStored, oldRefCountStored, outHandle, reservation; added: outStruct |
| gld_applySampleConfiguration | B | 5 | 0 -> 0 | removed: scalarIn0, scalarIn1, scalarIn2, scalarIn3; added: scalarIn |
| glFlush_impl | B | 2 | 0 -> 0 | removed: scalarIn0, scalarIn1; added: scalarIn |
| glFlush_impl_withSurfaceUpdate | B | 4 | 0 -> 0 | removed: scalarIn0, scalarIn1, scalarIn2, scalarIn3; added: scalarIn |
| glFinish_impl | B | 2 | 0 -> 0 | removed: scalarIn0, scalarIn1; added: scalarIn |
| gld_swapBuffersImpl | B | 2 | 0 -> 0 | removed: scalarIn0, scalarIn1; added: scalarIn |
| _gldAllocVertexBuffer | A+D | 5 | 0 -> 0 | removed: chunk, chunkMemory, reservation, structIn0, structIn1; added: chunkOut, structIn |
| gld_emitFramebufferState | A | 11 | 0 -> 0 | removed: crBits, releaseResult, releaseStatus, reservation |
| _gldPageoffBuffer | B | 2 | 0 -> 0 | removed: scalarIn0, scalarIn1; added: scalarIn |
| gld_drawVertexArray | A | 1 | 0 -> 0 | removed: reservation |
| gld_readPixelsViaBlit | A | 5 | 0 -> 0 | removed: reservation, storeResult |
| gld_drawPixelsFromClientSurface | A | 3 | 0 -> 0 | removed: reservation, storeResult |
| gld_emitQueryBeginPacket | A | 2 | 0 -> 0 | removed: crField0, reservation |
| gld_emitStampFencePacket | A | 3 | 2 -> 2 | removed: crField0, fenceUpdated, reservation |
| gld_validateStreamState | B | 4 | 1 -> 1 | removed: scalarIn0, scalarIn1, scalarIn2, scalarIn3; added: scalarIn |
| gld_initContextHardwareState | B | 5 | 0 -> 0 | removed: queryResult0, queryResult1, queryResult2, queryResult3, queryResult4; added: queryResult |
| gld_emitUnitObjectPacket | A | 3 | 0 -> 0 | removed: fenceUpdated, reservation, storeResult |
| glTexSubImage_impl | A | 2 | 0 -> 0 | removed: reservation |
The five functions that look "extra" (gld_releaseQueryMemory, gld_setQueryAgpRefBacking, gld_drawVertexArray, gld_bindCurrentFramebuffer, gld_emitFramebufferState) are class A (and C for gld_setQueryAgpRefBacking) sites; their older rows are keyed by the pre-rename names FUN_00009cd0, FUN_00009d70, FUN_0001ecd0, FUN_00007d50, FUN_0001bac0 (ledger-resolved).

## Removed rows (225)
Rows only recorded renames of identifiers that no longer exist in the rewritten text (`reservation`, `crBits`, the "stored value" locals, `outHandle`, `newBacking`, `scalarInN`, ...), or anchored on the deleted `storeWordConditionalIndexed(...)` lines. 168 were removed first, 57 more after the second `--check` (cascade); every flagged function was resolved through the ledger and had to be in the rewritten set (the loop stops otherwise; it never stopped). Count outside the 40 rewritten functions: **0**. Full list (file, kind, function, old, new): `removed_rows_r17.tsv` (also inlined below). Names are NOT lost: they are carried in the part files; no placeholder identifier remains in these functions to re-name (before/after column: 3 -> 3, the 3 are `in_LR`-style artifacts in `gld_emitStampFencePacket` (2) and `gld_validateStreamState` (1), unchanged).

```
file	kind	function(now)	old	new
names_R4_misc.tsv	local	_gldAllocVertexBuffer	in_RESERVE	reservation
names_W4.tsv	local	_gldAllocVertexBuffer	local_44	chunk
names_W4.tsv	local	_gldAllocVertexBuffer	local_40	chunkMemory
names_W4.tsv	local	_gldAllocVertexBuffer	local_3c	structIn0
names_W4.tsv	local	_gldAllocVertexBuffer	local_38	structIn1
names_W4.tsv	local	_gldAttachDrawable	local_58	scalarIn0
names_W4.tsv	local	_gldAttachDrawable	local_54	scalarIn1
names_W4.tsv	local	_gldAttachDrawable	local_50	scalarIn2
names_W4.tsv	local	_gldAttachDrawable	local_4c	scalarIn3
names_R4_misc.tsv	local	_gldDeleteTextureLevel	in_RESERVE	reservation
names_W4.tsv	local	_gldDeleteTextureLevel	iVar2	updatedRefCount
names_W4.tsv	local	_gldDeleteTextureLevel	in_cr0	crBits
names_R4_misc.tsv	local	_gldDestroyMemoryPluginData	in_RESERVE	reservation
names_W4.tsv	local	_gldDestroyMemoryPluginData	iVar1	updatedRefCount
names_W4.tsv	local	_gldGetInteger	local_24	scalarOut0
names_W4.tsv	local	_gldGetInteger	local_20	scalarOut1
names_W4.tsv	local	_gldGetInteger	local_1c	scalarOut2
names_W4.tsv	local	_gldGetRendererInfo	local_30	scalarOut0
names_W4.tsv	local	_gldGetRendererInfo	local_2c	scalarOut1
names_W4.tsv	local	_gldGetRendererInfo	local_28	scalarOut2
names_R4_misc.tsv	local	_gldModifyVertexArray	in_RESERVE	reservation
names_W4.tsv	local	_gldModifyVertexArray	iVar2	updatedRefCount
names_W4.tsv	local	_gldPageoffBuffer	local_28	scalarIn0
names_W4.tsv	local	_gldPageoffBuffer	local_24	scalarIn1
names_R4_misc.tsv	local	_gldReclaimBuffer	in_RESERVE	reservation
names_W4.tsv	local	_gldReclaimBuffer	iVar1	updatedRefCount
names_W4.tsv	local	_gldReclaimBuffer	in_cr0	crBits
names_R4_misc.tsv	local	_gldReclaimTexture	in_RESERVE	reservation
names_W4.tsv	local	_gldReclaimTexture	iVar2	updatedRefCount
names_W4.tsv	local	_gldReclaimTexture	in_cr0	crBits
names_r16_splits.tsv	use	_gldReclaimTexture	iVar5	oldRefCount
names_r16_splits.tsv	use	_gldReclaimTexture	iVar5	oldRefCount
names_r16_splits.tsv	use	_gldReclaimTexture	iVar5	oldRefCount
names_r16_splits.tsv	use	_gldReclaimTexture	iVar5	oldRefCount
names_R4_misc.tsv	local	_gldReclaimVertexArray	in_RESERVE	reservation
names_W4.tsv	local	_gldReclaimVertexArray	iVar1	updatedRefCount
names_W4.tsv	local	_gldReclaimVertexArray	in_cr0	crBits
names_W4.tsv	local	_gldSetInteger	local_28	scalarIn0
names_W4.tsv	local	_gldSetInteger	local_24	scalarIn1
names_W4.tsv	local	_gldSetInteger	local_20	scalarIn2
names_W4.tsv	local	_gldSetInteger	local_1c	scalarIn3
names_q01_4.tsv	local	glFinish_impl	uStack_28	scalarIn0
names_q01_4.tsv	local	glFinish_impl	uStack_24	scalarIn1
names_q01_4.tsv	local	glFlush_impl	local_28	scalarIn0
names_q01_4.tsv	local	glFlush_impl	local_24	scalarIn1
names_q01_31.tsv	local	glFlush_impl_withSurfaceUpdate	uStack_24	scalarIn1
names_q01_4.tsv	local	glFlush_impl_withSurfaceUpdate	uStack_28	scalarIn0
names_q01_4.tsv	local	glFlush_impl_withSurfaceUpdate	uStack_20	scalarIn2
names_q01_4.tsv	local	glFlush_impl_withSurfaceUpdate	uStack_1c	scalarIn3
names_R4_misc.tsv	local	glTexSubImage_impl	in_RESERVE	reservation
names_X_f369f0.tsv	use	glTexSubImage_impl	piVar36	surfaceRefPtr
names_q01_4.tsv	local	gld_applySampleConfiguration	local_28	scalarIn0
names_q01_4.tsv	local	gld_applySampleConfiguration	local_20	scalarIn2
names_q01_4.tsv	local	gld_applySampleConfiguration	local_1c	scalarIn3
names_q01_4.tsv	use	gld_applySampleConfiguration	local_24	scalarIn1
names_q01_4.tsv	use	gld_applySampleConfiguration	local_24	newDrawableFlags
names_q01_14.tsv	local	gld_bindCurrentFramebuffer	iVar3	casResult
names_q01_14.tsv	use	gld_bindCurrentFramebuffer	iVar7	casResult2
names_q01_6.tsv	local	gld_bindCurrentFramebuffer	in_RESERVE	reservation
names_q01_6.tsv	local	gld_bindCurrentFramebuffer	in_cr0	crField0
names_R4_misc.tsv	local	gld_drawPixelsFromClientSurface	in_RESERVE	reservation
names_X_f2a3d0.tsv	use	gld_drawPixelsFromClientSurface	iVar22	storeResult
names_X_f2a3d0.tsv	use	gld_drawPixelsFromClientSurface	piVar21	surfaceRefPtr
names_R4_misc.tsv	local	gld_drawVertexArray	in_RESERVE	reservation
names_q01_5.tsv	local	gld_emitFramebufferState	in_RESERVE	reservation
names_q01_5.tsv	local	gld_emitFramebufferState	in_cr0	crBits
names_q01_5.tsv	use	gld_emitFramebufferState	iVar5	releaseResult
names_q01_5.tsv	use	gld_emitFramebufferState	iVar1	releaseStatus
names_q01_5.tsv	use	gld_emitFramebufferState	piVar3	refCountWord
names_q01_5.tsv	use	gld_emitFramebufferState	piVar3	refCountWord
names_q01_5.tsv	use	gld_emitFramebufferState	piVar3	refCountWord
names_q01_5.tsv	use	gld_emitFramebufferState	iVar5	releaseResult
names_q01_5.tsv	use	gld_emitFramebufferState	piVar3	refCountWord
names_q01_5.tsv	use	gld_emitFramebufferState	piVar3	refCountWord
names_q01_5.tsv	use	gld_emitFramebufferState	piVar3	refCountWord
names_q01_6.tsv	local	gld_emitQueryBeginPacket	in_RESERVE	reservation
names_q01_6.tsv	local	gld_emitQueryBeginPacket	in_cr0	crField0
names_q01_31.tsv	local	gld_emitStampFencePacket	iVar1	fenceUpdated
names_q01_6.tsv	local	gld_emitStampFencePacket	in_RESERVE	reservation
names_q01_6.tsv	local	gld_emitStampFencePacket	in_cr0	crField0
names_q01_31.tsv	local	gld_emitUnitObjectPacket	iVar1	storeResult
names_q01_31.tsv	local	gld_emitUnitObjectPacket	bVar3	fenceUpdated
names_q01_6.tsv	local	gld_emitUnitObjectPacket	in_RESERVE	reservation
names_gQ_1.tsv	local	gld_ensureTextureAgpRefBacking	uStack_34	outHandle
names_gQ_1.tsv	local	gld_ensureTextureAgpRefBacking	iStack_30	newBacking
names_gQ_1.tsv	use	gld_ensureTextureAgpRefBacking	iVar9	oldRefCountValue
names_gQ_1.tsv	use	gld_ensureTextureAgpRefBacking	iVar9	oldRefCountValue
names_gQ_1.tsv	use	gld_ensureTextureAgpRefBacking	iVar7	oldRefCountStored
names_gQ_1.tsv	use	gld_ensureTextureAgpRefBacking	iVar10	newRefCountStored
names_gQ_1.tsv	use	gld_ensureTextureAgpRefBacking	piVar5	oldRefCountPtr
names_gQ_1.tsv	use	gld_ensureTextureAgpRefBacking	piVar5	oldRefCountPtr
names_gQ_1.tsv	use	gld_ensureTextureAgpRefBacking	piVar5	newRefCountPtr
names_gQ_1.tsv	use	gld_ensureTextureAgpRefBacking	piVar5	newRefCountPtr
names_q01_6.tsv	local	gld_ensureTextureAgpRefBacking	in_RESERVE	reservation
names_gQ_1.tsv	local	gld_ensureTextureBackingSized2	local_34	outHandle
names_gQ_1.tsv	local	gld_ensureTextureBackingSized2	local_30	newBacking
names_gQ_1.tsv	use	gld_ensureTextureBackingSized2	iVar9	oldRefCountValue
names_gQ_1.tsv	use	gld_ensureTextureBackingSized2	iVar9	oldRefCountValue
names_gQ_1.tsv	use	gld_ensureTextureBackingSized2	iVar7	oldRefCountStored
names_gQ_1.tsv	use	gld_ensureTextureBackingSized2	iVar10	newRefCountStored
names_gQ_1.tsv	use	gld_ensureTextureBackingSized2	piVar5	oldRefCountPtr
names_gQ_1.tsv	use	gld_ensureTextureBackingSized2	piVar5	oldRefCountPtr
names_gQ_1.tsv	use	gld_ensureTextureBackingSized2	piVar5	newRefCountPtr
names_gQ_1.tsv	use	gld_ensureTextureBackingSized2	piVar5	newRefCountPtr
names_q01_6.tsv	local	gld_ensureTextureBackingSized2	in_RESERVE	reservation
names_gQ_1.tsv	local	gld_ensureTextureGlobalBacking	auStack_24	outHandleUnused
names_gQ_1.tsv	local	gld_ensureTextureGlobalBacking	local_20	newBacking
names_gQ_1.tsv	local	gld_ensureTextureGlobalBacking	iVar1	oldRefCountStored
names_gQ_1.tsv	use	gld_ensureTextureGlobalBacking	iVar4	newRefCountStored
names_gQ_1.tsv	use	gld_ensureTextureGlobalBacking	iVar5	oldRefCountValue
names_gQ_1.tsv	use	gld_ensureTextureGlobalBacking	iVar5	oldRefCountValue
names_gQ_1.tsv	use	gld_ensureTextureGlobalBacking	piVar3	oldRefCountPtr
names_gQ_1.tsv	use	gld_ensureTextureGlobalBacking	piVar3	oldRefCountPtr
names_gQ_1.tsv	use	gld_ensureTextureGlobalBacking	piVar3	newRefCountPtr
names_gQ_1.tsv	use	gld_ensureTextureGlobalBacking	piVar3	newRefCountPtr
names_gQ_1.tsv	local	gld_ensureTextureGlobalBacking	in_cr0	cr0Bits
names_q01_6.tsv	local	gld_ensureTextureGlobalBacking	in_RESERVE	reservation
names_gQ_1.tsv	local	gld_ensureTextureSurfaceBacking	auStack_34	outHandleUnused
names_gQ_1.tsv	local	gld_ensureTextureSurfaceBacking	local_30	newBacking
names_gQ_1.tsv	local	gld_ensureTextureSurfaceBacking	iVar1	oldRefCountStored
names_gQ_1.tsv	use	gld_ensureTextureSurfaceBacking	iVar4	newRefCountStored
names_gQ_1.tsv	use	gld_ensureTextureSurfaceBacking	iVar5	oldRefCountValue
names_gQ_1.tsv	use	gld_ensureTextureSurfaceBacking	iVar5	oldRefCountValue
names_gQ_1.tsv	use	gld_ensureTextureSurfaceBacking	piVar3	oldRefCountPtr
names_gQ_1.tsv	use	gld_ensureTextureSurfaceBacking	piVar3	oldRefCountPtr
names_gQ_1.tsv	use	gld_ensureTextureSurfaceBacking	piVar3	newRefCountPtr
names_gQ_1.tsv	use	gld_ensureTextureSurfaceBacking	piVar3	newRefCountPtr
names_gQ_1.tsv	local	gld_ensureTextureSurfaceBacking	in_cr0	cr0Bits
names_q01_6.tsv	local	gld_ensureTextureSurfaceBacking	in_RESERVE	reservation
names_q01_31.tsv	local	gld_initContextHardwareState	local_40	queryResult0
names_q01_31.tsv	local	gld_initContextHardwareState	local_3c	queryResult1
names_q01_31.tsv	local	gld_initContextHardwareState	local_38	queryResult2
names_q01_31.tsv	local	gld_initContextHardwareState	local_34	queryResult3
names_q01_31.tsv	local	gld_initContextHardwareState	local_30	queryResult4
names_R4_misc.tsv	local	gld_readPixelsViaBlit	in_RESERVE	reservation
names_X_f28350.tsv	use	gld_readPixelsViaBlit	iVar24	storeResult
names_X_f28350.tsv	use	gld_readPixelsViaBlit	piVar23	surfaceRefPtr
names_r14_misc2.tsv	use	gld_readPixelsViaBlit	bVar42	loopExitFlagWord
names_r14_misc2.tsv	use	gld_readPixelsViaBlit	bVar42	loopExitFlagWord
names_R4_misc.tsv	local	gld_releaseQueryMemory	in_RESERVE	reservation
names_W4.tsv	local	gld_releaseQueryMemory	iVar1	updatedRefCount
names_W4.tsv	local	gld_releaseQueryMemory	in_cr0	crBits
names_gQ_1.tsv	local	gld_setBufferAgpRefBacking	auStack_34	outHandleUnused
names_gQ_1.tsv	local	gld_setBufferAgpRefBacking	local_30	newBacking
names_gQ_1.tsv	local	gld_setBufferAgpRefBacking	iVar1	oldRefCountStored
names_gQ_1.tsv	use	gld_setBufferAgpRefBacking	iVar3	newRefCountStored
names_gQ_1.tsv	use	gld_setBufferAgpRefBacking	iVar3	oldRefCountValue
names_gQ_1.tsv	use	gld_setBufferAgpRefBacking	iVar3	oldRefCountValue
names_gQ_1.tsv	use	gld_setBufferAgpRefBacking	piVar2	newRefCountPtr
names_gQ_1.tsv	use	gld_setBufferAgpRefBacking	piVar2	newRefCountPtr
names_gQ_1.tsv	use	gld_setBufferAgpRefBacking	piVar2	oldRefCountPtr
names_gQ_1.tsv	use	gld_setBufferAgpRefBacking	piVar2	oldRefCountPtr
names_gQ_1.tsv	local	gld_setBufferAgpRefBacking	in_cr0	cr0Bits
names_q01_6.tsv	local	gld_setBufferAgpRefBacking	in_RESERVE	reservation
names_gQ_1.tsv	local	gld_setBufferNewTextureBacking	local_44	outHandle
names_gQ_1.tsv	local	gld_setBufferNewTextureBacking	local_40	newBacking
names_gQ_1.tsv	local	gld_setBufferNewTextureBacking	iVar1	oldRefCountStored
names_gQ_1.tsv	use	gld_setBufferNewTextureBacking	iVar3	newRefCountStored
names_gQ_1.tsv	use	gld_setBufferNewTextureBacking	iVar3	oldRefCountValue
names_gQ_1.tsv	use	gld_setBufferNewTextureBacking	iVar3	oldRefCountValue
names_gQ_1.tsv	use	gld_setBufferNewTextureBacking	piVar2	newRefCountPtr
names_gQ_1.tsv	use	gld_setBufferNewTextureBacking	piVar2	newRefCountPtr
names_gQ_1.tsv	use	gld_setBufferNewTextureBacking	piVar2	oldRefCountPtr
names_gQ_1.tsv	use	gld_setBufferNewTextureBacking	piVar2	oldRefCountPtr
names_gQ_1.tsv	local	gld_setBufferNewTextureBacking	in_cr0	cr0Bits
names_q01_6.tsv	local	gld_setBufferNewTextureBacking	in_RESERVE	reservation
names_R4_misc.tsv	local	gld_setQueryAgpRefBacking	in_RESERVE	reservation
names_W4.tsv	local	gld_setQueryAgpRefBacking	iVar1	updatedRefCount
names_W4.tsv	local	gld_setQueryAgpRefBacking	in_cr0	crBits
names_W4.tsv	local	gld_setQueryAgpRefBacking	auStack_24	structOut0
names_W4.tsv	local	gld_setQueryAgpRefBacking	local_20	newMemory
names_gQ_1.tsv	local	gld_setTextureAgpRefBacking	auStack_34	outHandleUnused
names_gQ_1.tsv	local	gld_setTextureAgpRefBacking	local_30	newBacking
names_gQ_1.tsv	local	gld_setTextureAgpRefBacking	iVar1	oldRefCountStored
names_gQ_1.tsv	use	gld_setTextureAgpRefBacking	iVar3	newRefCountStored
names_gQ_1.tsv	use	gld_setTextureAgpRefBacking	iVar3	oldRefCountValue
names_gQ_1.tsv	use	gld_setTextureAgpRefBacking	iVar3	oldRefCountValue
names_gQ_1.tsv	use	gld_setTextureAgpRefBacking	piVar2	newRefCountPtr
names_gQ_1.tsv	use	gld_setTextureAgpRefBacking	piVar2	newRefCountPtr
names_gQ_1.tsv	use	gld_setTextureAgpRefBacking	piVar2	oldRefCountPtr
names_gQ_1.tsv	use	gld_setTextureAgpRefBacking	piVar2	oldRefCountPtr
names_gQ_1.tsv	local	gld_setTextureAgpRefBacking	in_cr0	cr0Bits
names_q01_6.tsv	local	gld_setTextureAgpRefBacking	in_RESERVE	reservation
names_gQ_1.tsv	local	gld_setTextureNewTextureBacking	local_34	outHandle
names_gQ_1.tsv	local	gld_setTextureNewTextureBacking	local_30	newBacking
names_gQ_1.tsv	local	gld_setTextureNewTextureBacking	iVar1	oldRefCountStored
names_gQ_1.tsv	use	gld_setTextureNewTextureBacking	iVar3	newRefCountStored
names_gQ_1.tsv	use	gld_setTextureNewTextureBacking	iVar3	oldRefCountValue
names_gQ_1.tsv	use	gld_setTextureNewTextureBacking	iVar3	oldRefCountValue
names_gQ_1.tsv	use	gld_setTextureNewTextureBacking	piVar2	newRefCountPtr
names_gQ_1.tsv	use	gld_setTextureNewTextureBacking	piVar2	newRefCountPtr
names_gQ_1.tsv	use	gld_setTextureNewTextureBacking	piVar2	oldRefCountPtr
names_gQ_1.tsv	use	gld_setTextureNewTextureBacking	piVar2	oldRefCountPtr
names_gQ_1.tsv	local	gld_setTextureNewTextureBacking	in_cr0	cr0Bits
names_q01_6.tsv	local	gld_setTextureNewTextureBacking	in_RESERVE	reservation
names_gQ_1.tsv	local	gld_setVertexArrayAgpRefBacking	auStack_34	outHandleUnused
names_gQ_1.tsv	local	gld_setVertexArrayAgpRefBacking	local_30	newBacking
names_gQ_1.tsv	local	gld_setVertexArrayAgpRefBacking	iVar1	oldRefCountStored
names_gQ_1.tsv	use	gld_setVertexArrayAgpRefBacking	iVar3	newRefCountStored
names_gQ_1.tsv	use	gld_setVertexArrayAgpRefBacking	iVar3	oldRefCountValue
names_gQ_1.tsv	use	gld_setVertexArrayAgpRefBacking	iVar3	oldRefCountValue
names_gQ_1.tsv	use	gld_setVertexArrayAgpRefBacking	piVar2	newRefCountPtr
names_gQ_1.tsv	use	gld_setVertexArrayAgpRefBacking	piVar2	newRefCountPtr
names_gQ_1.tsv	use	gld_setVertexArrayAgpRefBacking	piVar2	oldRefCountPtr
names_gQ_1.tsv	use	gld_setVertexArrayAgpRefBacking	piVar2	oldRefCountPtr
names_gQ_1.tsv	local	gld_setVertexArrayAgpRefBacking	in_cr0	cr0Bits
names_q01_6.tsv	local	gld_setVertexArrayAgpRefBacking	in_RESERVE	reservation
names_gQ_1.tsv	local	gld_setVertexArrayNewTextureBacking	local_34	outHandle
names_gQ_1.tsv	local	gld_setVertexArrayNewTextureBacking	local_30	newBacking
names_gQ_1.tsv	local	gld_setVertexArrayNewTextureBacking	iVar1	oldRefCountStored
names_gQ_1.tsv	use	gld_setVertexArrayNewTextureBacking	iVar3	newRefCountStored
names_gQ_1.tsv	use	gld_setVertexArrayNewTextureBacking	iVar3	oldRefCountValue
names_gQ_1.tsv	use	gld_setVertexArrayNewTextureBacking	iVar3	oldRefCountValue
names_gQ_1.tsv	use	gld_setVertexArrayNewTextureBacking	piVar2	newRefCountPtr
names_gQ_1.tsv	use	gld_setVertexArrayNewTextureBacking	piVar2	newRefCountPtr
names_gQ_1.tsv	use	gld_setVertexArrayNewTextureBacking	piVar2	oldRefCountPtr
names_gQ_1.tsv	use	gld_setVertexArrayNewTextureBacking	piVar2	oldRefCountPtr
names_gQ_1.tsv	local	gld_setVertexArrayNewTextureBacking	in_cr0	cr0Bits
names_q01_6.tsv	local	gld_setVertexArrayNewTextureBacking	in_RESERVE	reservation
names_q01_4.tsv	local	gld_swapBuffersImpl	local_28	scalarIn0
names_q01_4.tsv	local	gld_swapBuffersImpl	local_24	scalarIn1
names_q01_26.tsv	local	gld_validateStreamState	local_48	scalarIn0
names_q01_26.tsv	local	gld_validateStreamState	local_44	scalarIn1
names_q01_26.tsv	local	gld_validateStreamState	local_40	scalarIn2
names_q01_26.tsv	local	gld_validateStreamState	local_3c	scalarIn3
```

## Open / reported, not fixed
- **Same class A defect elsewhere**: `ATIRadeonX1000VADriver` 2 sites (1 file), `libGLProgrammability` 290 sites (20 files) still call `storeWordConditionalIndexed` and read uninitialized `reservation`. `ghidra_c.h` there needs the same macro; per-function stock verification needed. Not touched (other binaries).
- Dead locals now only assigned: `loopExitFlagWord` (gld_readPixelsViaBlit) and `scratchFlag35` (gld_drawPixelsFromClientSurface) held the old loop's CR0 compare; left (removing them changes -O0 code; stock has the cmp for other branches).
- `_gldAllocVertexBuffer` input words 2..4 are uninitialized in stock too; kept uninitialized.
- `glReadPixels_*` pass 0x1c-byte structs through pointers (fake-struct overlays); not audited here.
- The inline asm uses `bne- 1b`; stock's `bne` carries no static hint (no behaviour change).
