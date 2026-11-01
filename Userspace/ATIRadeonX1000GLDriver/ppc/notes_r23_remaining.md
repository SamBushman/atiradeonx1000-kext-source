# r23: open items from r19/r20/r22 (GLDriver + libGLProg dead CR stores)

Stock = Tiger PPC binaries (Capstone via Tools/userspace/audit_layout/sdis.py). Gates: `Tools/userspace/lpnames/gate.sh` on the G5, TMPDIR on disk.
Gate rule: every function that differs from the base is one of the rewritten ones (LENGTH); every other CODE line differs only in label numbers.

## 1. glDrawPixels_impl (0x18a40) -- fixed
Stock: `addi r30,r1,0xc0; li r5,0x274; bl memcpy` copies the 628-byte pixel-processing state to r1+0xc0; the 0x70-byte descriptor at r1+0x50..0xc0 is the 2nd
argument of _glgProcessPixels (0x1a3c00). The C had 29 loose locals plus `procZoomX`, so the 628-byte memcpy ran over whatever gcc put after it.
Now two properly sized locals: `procDesc` (0x70 bytes, fields at the stock offsets) and `procZoom` (628 bytes: zoomX, zoomY, 153 pad words, zoomFlags, 1 pad).
Compiled check: descriptor and zoom object adjacent in the same order as stock (desc+0x70 == zoom).

## 2. Compiler__getOrCreateLoadConst{1,2,3,4,N} / Compiler__getOrCreateConstVector{1,2,3,4,N} + callers -- fixed (transcription flaw, 10 functions)
Stock (0xf5248 and siblings): the operands travel BY VALUE as 6-word records (kind,value,word2..word5): Const1 takes 6 words, Const2 12, Const3 18, Const4 24;
the callee N gets (compiler, count, 24-word aggregate) in r3,r4,r5..r10 + the stack parameter area (0x38..). N copies the 24 words into its frame
(constRecords at r1+0x48, stride 0x18) and reads word 0/1 of record k for k < count.
The C passed/accepted only 7-8 words, and N filled only constRecords[0..1], so records 1..3 were read uninitialised (HashTable__find key + the new
IRLoadConst's operand records). Now: typedef ConstOps1..4 (decls.h), N takes `ConstOps4 ops` and copies it into constRecords, wrappers 1-3 copy their
6/12/18 words into a ConstOps4 (the unused tail is not read by N: loops are guarded by `loopIndex < constCount`), callers in IRInst__setConstantOperand
(8 call sites) build the full record from operandPtrTable[3..6][0..5] and KhanPs__vslot85_findOrEncodeConstantVector passes `*(ConstOps4 *)&constVec[0]`
(its 24-word `constVec` is the stock object at r1+0xe8 filled by ConstRecords__fillFloat4).
Compiled check (cand disassembly of Const4): r5..r10 = struct words 0..5, 72 bytes copied to the outgoing parameter area at r1+56 = stock layout.
The 4 wrappers' copies of r4..r10 into the callee's own home area (`Home` locals) and the N `uStack*` stores to the home area were removed (not observable).

## 3. glReadPixels_entry / glReadPixels_impl (0x29290/0x29294, duplicate bodies) -- fixed
Stock frame 0x130: layoutRowBytes 0x48, layoutPixelBytes 0x4c, skip offset 0x50, reply size 0x54, the 0x1c-byte selector-7 request at 0x58..0x74
(x, y, width, height, surface code/format, address, pitch), then the 0x70-byte _glgProcessPixels descriptor at 0x74..0xe4 (convertOutA/B at 0x8c/0x90,
procEnd byte at 0xe0). The C had `int layoutSkipBytes[3]` followed by loose request words (request = `layoutSkipBytes + 2`, reply = `layoutSkipBytes + 1`,
7 words past the end of the array) and loose descriptor words. Now `layoutState` (11 words, 0x2c bytes) and `procDesc` (0x70 bytes). Offsets checked
against the stock stack objects (_glgConvertType out pointers 0x8c/0x90 and 0x7c/0x80; IOConnect call `addi r5,r1,0x58; li r6,0x1c; addi r8,r1,0x54`).

## 4. Runtime-indexed arrays
- SchedModel__fitsConstantLimit `seenConstants[12]`: PROVEN in bounds. Its limits are the two PackState__countFreeSlots counts (each counted over 3 slots, so 0..3);
  the function returns 0 as soon as `seenCount > inlineLimit + otherLimit`, so the largest stored index is 6.
- R520SchedModel__vslot3_canAddInstruction / vslot4_addInstruction: `freeSlotsA/B` (countFreeSlots writes 2 words via `&freeSlotsA`, stock r1+0x38/0x3c) and
  vslot3's `modelStateWord0..3` (stock r1+0x38..0x44, used as pointers to words 0/2 and 1/3) are now `freeSlots[2]` / `modelState[4]` (same adjacent-locals
  hazard as above).
- Program__assignExportSlotsByKind / assignOutputExportSlots `slotOwnerRegister[assignedSlot]`, SchedModel__assignConstantSelectors `seenConstants[13]`,
  ilAssembleProgram tables (unitTexFormats[32], inputMaskWords[6], dclValueTable[1024], intConstTable[1024], inputKindTable[17]): NOT provable from the C
  (indices are program data: allocator slot numbers, distinct-constant count, hardware limits). The arrays are the stock frame objects (slotOwnerRegister:
  stock array at r1+0x38 in a 0x130 frame, 51/53 words = the room below the saved GPRs); stock performs no check, so none is added (rule: no guards absent from stock).
  Status: open at the stock-invariant level, unchanged from r19.

## 5. Dead CR-bit stores -- removed (42 functions: 2 GLDriver, 40 libGLProg)
Pseudo variables `cr0`/`cr0Flags`/`cr0Reg`/`crBits`/`reservationOk` that Ghidra modelled from `or.`/`cmp`/`stwcx.` and that are only assigned, never read.
Scanner: per function, the variable occurs only in its declaration and in whole-line assignments; every right-hand side is side-effect free (no call, dereference,
subscript, ++/--; checked on all 110 assignments). 110 assignments + 42 declarations removed; none was the body of an unbraced if/else (checked on the diff).
List: notes_r23_cr_removed_assignments.txt. (laneSourceCount in RegKind__laneSourceCount is a false positive of the scanner, a real variable: untouched.)
yyparse (34 KB) had 28 of them. Not a CR use anywhere else: the 22 other comparison-shift variables are read (e.g. chipVariantBit*, srcMode) and were left.

## 6. Block__materializePendingMovs (0xe3b88)
- Frame fix: stock r1+0x38 `writtenLanes` (byte-indexed through `&writtenLanes + lane`), 0x3c..0x48 `pendingInsts[4]` (slot 0x48 doubles as the merge-output slot:
  `SelectWord__mergeWrittenLanes(pendingInsts + 3, ...)`, `addi r3,r1,0x48`), 0x4c `mergedLanes[3]` (`addi r3,r1,0x4c`). The three were separate locals relying on gcc
  keeping them adjacent; now one `pendFrame` struct.
- Split of `pendingCountOrMovInst` (iVar14) into pendingCount / firstPendingKey / newMovInst (7 webs): applied by split_apply.py as its own commit.
  Gate verdicts: tier 1 ADDRESS-TAKEN at slot 56, tier 2 DIFFERENT ('rgn' 0 vs 8). Both come from one artifact already described in names_r14_misc.tsv: slot 56 (the
  index variable, lowest frame slot) is the base of gcc's folded array addressing (`lwz r0,56(r30); slwi; addi r0,r30,56; add; addi r2,r2,128; ...` = &pendingInsts[idx]),
  which the tools read as an address-taken scalar; the 8 extra bytes of scalars move pendFrame from 180 to 188 relative to it.
  Manual determination (cand vs base `gcc -S` output of the whole function, 1,117 lines each): with every `N(r30)` and `addi rX,r30,N` operand masked the two
  listings differ ONLY in `stwu r1,-240(r1)` -> `-256(r1)` and the two array-element offsets `addi r2,r2,128` -> `136`; tier 1 reports no MERGE/DATAFLOW
  line (slot map consistent, every load reached by the same stores). So the instruction stream, the call arguments (registers) and every external store are the
  same; only private slots and the frame position of the escaped object pendFrame (callees get a pointer to its fields; the intra-object offsets are the same) change.
  This is a judgement over the tools' verdict, not a tool pass: revert is the single commit `r23: split pendingCountOrMovInst`.

## Counts
GLDriver `apply_names --check`: see the commit message. Rows retired (stale after the rewrites): 300 (glDrawPixels_impl, LoadConst/ConstVector family, setConstantOperand,
findOrEncodeConstantVector) + 117 (glReadPixels, SchedModel, materializePendingMovs, CR stores), listed in notes_r23_removed_rows.rows (GLDriver) and
libGLProgrammability/ppc/notes_r23_removed_rows.rows.
