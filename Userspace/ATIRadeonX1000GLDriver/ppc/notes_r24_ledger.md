# r24 part A: ledger boundary audit (all five binaries, vs stock)

Method: true function starts = bl targets + ledger starts + `mflr r0` prologues after terminators; extent = start to next true start; compared with each ledger.tsv size. Raw per-entry results were produced by a scratch script (ledger2.py); classes below.

| Binary | In-text entries | Exact | Short (ledger < extent) | Long (ledger > extent) | Unledgered true starts |
|---|---|---|---|---|---|
| GLDriver | 3,270 | 2,066 | 960 (486 by >32 B, 474 by <=32 B) | 12 | 20 (+5 non-text entries) |
| GA | 80 | 51 | rest short | 1 (`_radeonSolidScanlines` 3660 vs 3596) | 0 |
| VA | 120 | 79 | rest short | 0 | 0 |
| libGL | 897 | 893 | 4 | 0 | 0 |
| libGLProg | 1,612 | - | 186 (121 by >32 B, 65 by <=32 B) | 1 (`___register_frame_table`) | 2 (4-byte thunks `_AddAtom`, `___deregister_frame_info`) |

## Causes (all benign, none is a wrong label)
1. Ledger size = Ghidra function body size. It excludes the trailing epilogue/blr tail (<=32 B) and **jump-table case blocks** (e.g. `glAccum_impl`: 88 B then `bctr`, ~11 KB of cases follow). Code beyond ledger size: GLDriver ~205 KB, libGLProg ~68 KB. `link_corpus.py` already uses "extent runs to the next ledger entry" so this does not affect linking.
2. Ghidra bodies are non-contiguous (`RANGES.tsv`). A ledger entry whose size is the sum of several ranges is *longer than its first contiguous extent* (the 12 GLDriver "long" entries, GA 1, libGLProg 1). Examples: `arbParseParamBinding` (3,780 = 0x89860-89a14 + 0x89d40-... + 0x8aa40-8acd8).
3. The 20 GLDriver "unledgered true starts" are real stock functions that Ghidra merged into another body or thunk (owner from RANGES.tsv):
   0x20da0->FUN_00018120; 0x52e50->thunk_FUN_00054a90; 0x53db0->thunk_FUN_00053b60; 0x89860,0x89d40->FUN_0008aa40; 0x8af50,0x8b0e0->FUN_0008b160; 0x8e390->FUN_0008ebb0; 0xa1030->thunk_FUN_000a2330; 0xed3a4->FUN_000eec50; 0x1308dc->thunk_FUN_001307f8; 0x134ef0->thunk_FUN_00134de8; 0x16efac,0x16f484->FUN_0016ff54; 0x1764dc->thunk_FUN_001268a4; 0x1774a8,0x17ff24,0x18003c->FUN_00180154; 0x19175c->FUN_001920e0; 0x1a323c->FUN_001a322c.
   The C functions `glCopyPixels_impl`, `extvsValidateProgramState`, `arbParseParamBinding`, `arbParseSourceRegister`, `arbfpFetchParameterValue`, `Program__emitDepthExportScale`, `Scheduler__selectNextNode`, `ValueKey__createLaneRecordsByOpcode`, `FudoPs__ctor_1920e0`, `R520VMachineAssembler__vslot12_visitNode`, `_savef14` therefore each contain the code of 2-4 real stock functions.
4. 268 GLDriver / 480 libGLProg "start-not-prologue": leaf functions and tail-call stubs with no `mflr`; starts are bl targets, correct.
5. Non-text entries (GLDriver 5, libGLProg 5): C++ dtors/ctors in `__textcoal` sections; addresses outside `__text`, not comparable by this method.

## Correction
Earlier notes (r20) said `arbParseParamBinding` is "stock 0x89864". The merged function includes real function starts at **0x89860**, 0x89d40 and 0x8aa40.

## Decision
No ledger.tsv/header edits: every recorded size equals the Ghidra body (the corpus's definition) and linking is already extent-based. Splitting the merged C functions into one C function per stock function is a transcription job (changes function boundaries, gate must be re-established per function); left open and listed in the report.
Stale handoff item "FUN_000934f0 header says 20 bytes but duplicates ffvpEmitSphereMapCoord": checked, already `ffvpEmitSphereMapCoordChecked`, a 20-byte wrapper (Ghidra body 934f0-934fc;93500-93508), correct.
