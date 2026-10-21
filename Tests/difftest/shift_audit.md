# Format-table shift audit (`entry >> 12 & 7`, `entry >> 8 & 3`) and int->double signedness scan

Why: the hand-world push found Ghidra variable-merge defects in `ATIR500GLContext::process_command_buffer` where the format-table shift read a stale variable
(f53dd93). This audit checks every other site of the same pattern against the stock disassembly and proves that a case would notice a wrong shift.

Result: **no further defect**. 9 functions, 24 `>> 12 & 7` sites, all correct; every function is pinned by an existing case that FAILS when the shift is perturbed.

## 1. Completeness (is every site on this list?)

`rlwinm rX,rY,20,29,31` (`>> 12 & 7`) occurs in exactly 9 functions of the stock kext, and the rebuilt kext has the same count in each function
(`Tools/difftest/audit/shiftsites.py STOCK.dis SYMBOL` lists the sites with context). `rlwinm ...,24,30,31` (`>> 8 & 3`, the sub-sample shift next to it) has the
same counts in stock and rebuilt (pcl_CopyPix 2, write_3dtexquad 2, build_swap 2, 2D pcb 1, GL pcb 4, build_surface_from_texture 2). No site outside these functions exists.

## 2. Per-site verdicts

Stock evidence: in the 2-arm sites the shipped code loads the table entry (`lwz r,0xc(entry)`) on both arms of the macro-tile test, then uses that one register for
`>> 8 & 3` (sub-sample, negated) and `>> 12 & 7`. The source must read the variable assigned on BOTH arms (the defect H1 found was a read of another variable).

| function | source line(s) | stock offset(s) | stock evidence | verdict |
|---|---|---|---|---|
| ATIR500GLContext::process_command_buffer | 596 (texture-size handler), 2434 (0x31), 2626 (0x32), 3456 (0x2d) | 0x3e4, 0x25c4, 0x3b68, 0x4048 | entry loaded on both arms, same register feeds both shifts | correct after f53dd93 (formatFieldDC / maxY assigned on both arms) |
| ATIR5002DContext::process_command_buffer | 261 | 0x5a4 | both arms load the entry (`lwz 0xc(r2)`), `>>8&3` and `>>12&7` from it | correct (formatEntry set on both arms) |
| ATIR500Surface::build_swap | 842, 1071 (tile units), 729 (split-strip texture offset) | 0xf34, 0x15dc, 0x1ba8 | tile sites as above; 0x1ba8 reloads the entry from the format byte at 0x67(r1) | correct: fmtDC set on both arms; srcFormatIndex is assigned once (line 480), so the cached fmtDC at 729 equals stock's fresh load |
| ATIRadeonX1000::pcl_CopyPix | 533 (loop), 576 | 0x3a4, 0x139c | as above | correct (formatInfo/formatInfoB set on both arms; index byte params+0x2f is the same value in both sites) |
| write_3dtexquad_cmds_for_copy_buffer_using_DMA | 712 (loop), 756 | 0x7e0, 0x179c | as above | correct (formatIndexSaved assigned once, line 383) |
| ATIR500Surface::copy_buffer_using_DMA | 214, 237, 246, 267, 299, 301 | 0x390, 0x440, 0x4a8, 0x534, 0x67c, 0x680 | each shift is a direct table read of the saved offset | correct: every site calls the lookup with shiftOffsetSrc/Dst, no cached variable |
| ATIR500Surface::shape_surface | 193, 315, 641 | 0x19c, 0x4c0, 0xc7c | direct reads of the entry | correct |
| ATIR500GLContext::build_surface_from_texture | 107 | 0x19c | entry re-read after the size test, same offset | correct |
| ATIR500GLContext::build_scissor | 65 | 0xa4 | direct table read of the colour-buffer format | correct (but 2x stock cost, see the perf fork) |

## 3. Sensitivity (does a case notice a wrong shift?)

Mutant 1: every `>> 0xc & 7` of the nine functions changed to `>> 0xb & 7` (build, then `run_all.sh -f` on each function). Mutant 2: every `>> 8 & 3` changed
to `>> 9 & 3`. A function is **pinned** if at least one case FAILS on the mutant.

| function | mutant 1 | mutant 2 | cases that fail |
|---|---|---|---|
| GL process_command_buffer | FAIL | FAIL | "texture bind, format-table size shift", opcodes 0x31/0x32 (+H1 big surfaces 0x2d/0x31/0x32), H1 high-bit 0x08/09/0b/0c/11 |
| 2D process_command_buffer | FAIL | FAIL | "(hand world)" 379/400 |
| build_swap | FAIL | FAIL | ATIR500Surface::build_swap 283/400 |
| pcl_CopyPix | FAIL | FAIL | generic + [hand H2] |
| write_3dtexquad | FAIL | FAIL | generic + [hand H2] |
| copy_buffer_using_DMA | FAIL | (no `>>8&3` site) | 45/81 |
| shape_surface | FAIL | (no `>>8&3` site) | "modes H3" 189/692 |
| build_surface_from_texture | FAIL | FAIL | 12/40 |
| build_scissor | FAIL | (no `>>8&3` site) | "(hand world)" 72/200 |

So all sites are reached (see the coverage lists in `DIFFTEST_UNCOVERED=1` runs) and every one is observable; no extra pin case was needed. The 2D process_command_buffer
generic one-run case and the shape_surface generic 9-run case do not notice the mutant; the hand worlds do.

## 4. Other defect classes scanned (same shapes)

* **Signed vs unsigned int->double** (the `real_to_hex` defect, H3). Source uses the `SD()`/`UD()` helpers only in `ATIR500Surface_OverlayScaler.cpp`; mutant 2 swaps
  their signedness: `real_to_hex` and `calc_h_scaler_blank` FAIL (pinned); `calc_h_inc_step_by`'s sites convert table bytes/halfwords (cannot have the high bit).
  Disassembly of `calc_h_scaler_blank` matches stock site by site (U: `p3>>3` via srwi, S: `lineWidth - U32At(info,0x14)` via xoris, U: `lineWidth` stored raw).
  Everywhere else the source keeps Ghidra's explicit `CONCAT44d(0x43300000, x [^ 0x80000000])` form, which is bit-exact by construction; the remaining C casts
  `(float)x` sit in functions whose hand worlds use operands >= 2^31 (H1 high-bit worlds, H3 overlay worlds with negative/0x7fffffff sizes) and pass.
  `Tools/difftest/audit/cvtseq.py STOCK.dis REBUILT.dis` prints the ordered S/U conversion sequences; the rebuilt compiler emits extra (CSE-less) conversions and
  `addis 0x8000` for the sign flip, so the sequences differ in length without a behavioural difference.
* **Shift/mask constants** (`Tools/difftest/audit/rlwscan.py`, right-shift extractions `rlwinm sh,mb,31` compared per function): 12 functions differ between stock and rebuilt.
  Each was classified from the disassembly and then tested by a mutant (one mask/shift in the source altered, image rebuilt, `run_all.sh -f <function>`; a function is
  *pinned* when a case FAILS on the mutant). Result: **0 source defects, 12 compiler artifacts, all 12 pinned** (one needed a new world, one a new failure-injection world).

| function | difference (stock vs rebuilt) | class | pinned by (mutant -> result) |
|---|---|---|---|
| HZMEM_InitMemResource | rebuilt materialises the CR bit `hzMode==1` with `mfcr; rlwinm 31,31,31` / `srwi. 1`; stock branches on the CR bit (source variable `modeIsOne`) | CR pseudo-register | `kind1MapBytes` 0xa000->0xa010: generic + new case FAIL. Coverage was 72%: added `HZMEM_InitMemResource (failure injection R3)` (every mode, n-th IOMallocPageable fails): 240/240, 93%/100% |
| ATIR500Surface::copy_from_buffer | stock saves/restores CR fields through `mtocrf`+`rlwinm 4/28`; rebuilt keeps `kernelPathBits>>1&1` in a GPR | CR pseudo-register | `if (!(kernelPathBits>>1&1))` inverted: "mapped H3" FAIL |
| ATIR500Surface::copy_buffer_using_DMA | same CR save/restore sandwiches (5 in stock) and CR-bit tests | CR pseudo-register | shift mutants 1/2 (45/81 FAIL); case 96%/99% |
| ATIRadeonX1000::startupPCIeGART | stock stores the GART pitch word with `stwbrx`; source builds the byte-swapped word explicitly (`(p>>3)<<24 \| (p>>3 & 0xff00)<<8`) | byte-reversed store | `& 0xff00` -> `& 0xfb00`: [hand H2] FAIL. (The first mutant `& 0x7f00` was unobservable: the pitch is `tableWidth<<2` <= 0x2000, so `p>>3` <= 0x400.) |
| ATIRadeonX1000::set_display_mode_and_vram | byte-reversal done by `rlwinm 24,*,*` composition where stock uses lwbrx/stwbrx | byte-reversed store | display base words `& 0xff00` -> `& 0xfb00`: FAIL |
| ATIRadeonX1000::pageoff_dirty_texture_with_cpu | stock `stwbrx` of `(srcPitch>>3)&0x1fff` \| fields; source composes the swapped word | byte-reversed store | `& 0x1f00` -> `& 0x0f00`: the old world PASSED (pitch < 0x800). Added `pageoff_dirty_texture_with_cpu (wide pitches R3)` (pitches up to 0x1fff8): mutant FAIL 62/80, baseline 80/80 |
| IOATIR500Shared::alloc_handles | stock `(n<<1)>>3`, rebuilt `n>>2`; algebraically equal: `rlwinm 1,0,30` then `rlwinm 29,3,31` = `(n & 0x7fffffff)>>2` = rebuilt `rlwinm 30,3,31` | strength reduction | `bitmapBytes >> 2` -> `>> 3`: FAIL |
| IOATIR500Shared::alloc_buf_handle | stock reuses the loaded capacity word, rebuilt reloads it (volatile `M<T>`) before each `>>5` | CSE vs reload | `handleHint >> 5` -> `>> 4`: FAIL |
| ATIR500GLContext::load_texture | rebuilt duplicates the mip-halving `>>1` into two arms (tail duplication) | code layout | `halfWidth = curWidth>>1` -> `>>2`: "load_texture (hand world)" FAIL |
| ATIR500GLContext::process_kATIGLStreamFastClearColor | stock `(x>>1)&0x1fff` then `<<1`; source writes `(pitch & 0x3ffe)` (same value) | merged shift+mask | `& 0x3ffe` -> `& 0x3ffc`: FAIL |
| ATIR500GLContext::process_command_buffer | rebuilt reads packed halfwords/bytes with `lhz`/`lbz` where stock loads the word and extracts (`rlwinm 16,16,31` x11 vs x7, `24,24`); `27,10` is a merged `>>5 & 0x3fffff` | load width / merged shift+mask | mutated `>>0x10` (opcode 0x37 x2, 0x2c x2) and `>>5 & 0x3fffff` (ops 0x08-0x15): H1 cases for 0x37, 0x2c, 0x0b/0e/12/13/14 FAIL |
| ATIR500DVDContext::process_command_buffer | the five stock `(a+b+c)>>5` (`rlwinm 27,5,31`) are merged with the following mask/shift in the rebuilt code; `31,30`/`31,31` are CR-bit extractions | merged shift+mask / CR bit | `surfaceInfo+0x830 >> 5` -> `>> 4`: 4 DVD cases FAIL |

Mutation builds used a throw-away worktree; none of the mutations is committed.

## 5. Reproduce

    python3 Tools/difftest/audit/shiftsites.py ~/g5logs/difftest/stock.dis '<stock symbol>'
    # mutant: sed -i -E 's/>> *0xc *& *7/>> 0xb \& 7/g' on the nine files, WORK=rung3/R3m_build REBUILT_KEXT=build/difftest/mutant.bin sh Tools/difftest/build_rebuilt.sh
    # then REBUILT_KEXT=build/difftest/mutant.bin sh Tests/difftest/run_all.sh -f '<function>'   (expect FAIL)
