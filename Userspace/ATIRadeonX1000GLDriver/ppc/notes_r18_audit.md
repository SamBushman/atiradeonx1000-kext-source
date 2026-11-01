# r18: sem_equiv audit of earlier (tier-1-only) renames/splits

Method: for each of the 5 binaries, compile the pre-naming corpus (git 3ffd0893 for GLDriver/libGL/libGLProg, 0483b189 GA, 5903e0f3 VA) and the current tree on the G5 (verify_names.sh, SPLITS=1, TMPDIR on disk) and run Tools/userspace/sem_equiv.py on every part pair (126 parts, ~7,400 functions). This is cumulative over all rounds, so it audits every split at once. Raw output: sem_audit_r18_raw.txt; per-function layout classes: sem_audit_r18_layout.tsv; scripts: Tools/userspace/audit_layout/.

## Tier 1 (cumulative)
GA, VA, libGL: SPLIT-EQUIVALENT. GLDriver and libGLProgrammability: NOT-EQUIVALENT cumulatively - NOT investigated here (the per-round gates were SPLIT-EQUIVALENT; the cumulative base also predates later non-name content changes such as r09's 0x934f0 rewrite and transcription fixes). Not claimed to be a split problem.

## Tier 2 (sem_equiv, all binaries)
IDENTICAL-CODE 5769, EQUIVALENT 965, UNINIT-PAIRED 224, DIFFERENT 366, INCONCLUSIVE 78.
DIFFERENT by binary: GLDriver 249, libGLProg 103, VA 8, GA 6 (INCONCLUSIVE 53/21/3/1).
- 358 of the 366 DIFFERENT are "rgn" differences only: an offset inside the escaped frame region (everything above the lowest escaped address) moved relative to the region anchor. No other observable event (store, load, call, arg, return, control flow) differs in those functions.
- 2 DIFFERENT (libGLProg __BuildInterferenceSets, __RegistersReInterfere) differ only in the call-target symbol of one stub (_BitSetFirstSetBit vs orph_97c08028 - the r10 fragment rename of the same address); name only, not hand-verified at the instruction level.
- 6 DIFFERENT are runtime-indexed accesses into the escaped region whose constant base moved: _FUN_000c8e50, _FUN_000e3b88 (Block__materializePendingMovs, already known), _FUN_0010fb54, _FUN_0010fc88, _FUN_00129b48, _FUN_001899ac. The indexed arrays are escaped arrays accessed in their own bounds in the two I read (0x10fb54 slotOwnerRegister[51], 0x10fc88 slotOwnerRegister[53]); I did not prove the other four.

## Layout classification of the 358 'rgn' functions (tools: audit_layout/gaps.py, tight.py)
- 270 SHIFT: the sorted escaped-address offsets have identical gaps (pure shift of the region; no change in the relative layout of escaped objects).
- 88 LAYOUT (GLDriver 58, libGLProg 30): the gap between some escaped objects changed because added private scalars land between them.
  - 60 of these: only pairs that already had other frame slots between them in the base changed. Nothing in the base code can rely on such a pair being adjacent.
  - 28 TIGHT: a pair of escaped addresses with no other accessed slot between them in the base changed gap (list below). These are the only candidates for a real layout dependence. Not resolved here: for the ones I read (e.g. 0x131008: a 1-byte out-param at +85 and an int at +100 passed to different callees) the objects are independent out-parameters, but I did not read all 28.
- Placement is not the cause: for dxt5EncodeAlphaBlock (0x1be50) I recompiled with the 4 added scalars at the start, after the scalar block, and at the end of the declarations: identical offsets in all three. The G5 gcc does not allocate by declaration order across classes (array vs scalar); the gap between an int array and a char array is set by the NUMBER of scalars. So re-placing the new declarations (a declreorder tool I wrote and then discarded) cannot restore those gaps; the only way to restore them is to not split (rejoin the scalar) or to add no net scalars.
- Base itself never had the stock adjacency for those cases (e.g. 0x1be50 base gap 100 bytes with scalars between), so the base C cannot be relying on adjacency there either.

## Actions
- No split was reverted: nothing found that I could show harmful; the 28 TIGHT functions and 4 unproven indexed cases remain UNREVIEWED, not cleared.
- No corpus files changed in this fork. Added Tools/userspace/audit_layout/{gaps,tight}.py and the audit data files only.
- _gldGetRendererInfo / _gldSetInteger / _gldReclaimTexture: not touched.

## 28 TIGHT functions (binary part function: base pair -> cand pair)


## Counts
audited: 5 binaries, 126 parts. OK (EQUIVALENT/IDENTICAL/UNINIT, plus SHIFT-only and separated-pair LAYOUT): all except 28 TIGHT + 6 indexed (overlap possible) + 2 name-only + 78 INCONCLUSIVE (not hand-reviewed). Reverted: 0.
