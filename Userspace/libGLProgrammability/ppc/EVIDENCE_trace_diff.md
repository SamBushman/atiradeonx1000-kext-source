# Trace differential (unicorn) - stock vs rebuilt libGLProgrammability, Nov 15 2026

Tool, tiers, gate rules: see `Userspace/ATIRadeonX1000GLDriver/ppc/EVIDENCE_trace_diff.md` and `Userspace/GLEngine/ppc/EVIDENCE_trace_diff.md` (same `Tools/userspace/emu/trace_diff.py`, `census_summary.py`).

Inputs: stock `libGLProgrammability.dylib` from `/Library/ATIRadeonX1000-Rebuilt/stock/` (md5 7f9f4e4e29e7ec66dac4748872863b4b; NOT the file under /System, which is the rebuilt copy installed Nov 8),
rebuilt `us_3c4e11b1/sbs/libGLProgrammability.dylib` (md5 40e96ec0c1b00f0cfeea5693d13b63ff), ledger `ledger_3c4e_glprog_rz.tsv` (508 rows), 150 coverage-guided inputs per row (76,200 trials).
Census: `trace_diff_census_fuzz150.tsv` (this directory). Reproduce: `trace_diff.py STOCK REBUILT LEDGER --all 16 --fuzz 150 --procs 30 --out OUT --symmap link/symbol_map.tsv --nm REBUILT.nm --funcs ledger.tsv --nargs NARGS`
(NARGS = the ledger-function table plus the import arities from `Tools/userspace/import_arity.py` run over Tiger libSystem/libmathCommon/libgcc/libstdc++).

## Result
Gate: PASS 507, OUT-OF-CONTRACT 1, FAIL 0, REVIEW 0, NO-INFO 0. Trials: IDENTICAL 58,831; REORDERED 12,587; READ_SET 749; FAULT_SITE/PARTIAL 1,919; FAULT_MISMATCH 0; EFFECTS 0; PTR_VALUE_DEP 0; IMAGE_DATA_DEP 0;
LAYOUT_DEP 1,087 (excluded: input is an address inside the image window); end state UCERR/UCERR 655 (both images raise the same unemulated exception: no comparison); TIMEOUT 309; UNINIT_REBUILT 3 trials (one row, below).
Outcome pairs over all trials: FAULT/FAULT 43,904, RET/RET 31,234, UCERR/UCERR 655, TIMEOUT/TIMEOUT 289, RET/FAULT 98 (all in LAYOUT_DEP trials, i.e. image-window inputs), TIMEOUT/FAULT 12, TIMEOUT/RET 8.

## The one OUT-OF-CONTRACT row
`_PPCRuntimeCompilerGetOffsetInRegister` (UNINIT_REBUILT, 3 trials): both images copy 0x24 bytes of a record to a local and then do `lbz 8(buf + *(record+4))` (stock `lbz r0,8(r28)`, r28 = buf + `lwz r2,4(r29)`; rebuilt 0x6e7bc/0x6e7d0): the
record field is an unchecked index into the local copy. With field > 0x1c the byte read lies beyond the copy; the two images have different frame sizes (stock 0x80, rebuilt 0xc0), so what lies there differs
(rebuilt: uninitialised stack, differs between the two fills; what the stock reads there is not established). Unchecked out-of-range index confirmed in both disassemblies -> out of contract (user decision 3, Nov 15).

## Tool changes needed for this binary (all in `trace_diff.py`, none changes a GLEngine/GLDriver verdict)
The stock is a prebound, split-segment dylib linked at 0x97b7b000: addresses are rebased so the image starts at the common slide; relocation addresses are relative to the first writable segment (MH_SPLIT_SEGS);
undefined symbols of type N_PBUD are imports; ledger, symbol-map and `_name_97c1c44c`-style names carry absolute stock addresses and are rebased; `abort`, `exit` and `__cxa_rethrow` end the run (noreturn: the
rebuilt/stock code after the call is not behaviour); libm callees (exp2, log2, acos, asin, atan, tan, trunc, atan2f, isnanf) take their arguments in FPRs. The first runs had 179 REVIEW and 13 FAIL rows; every one was
traced to one of these loader/arity gaps (stock fetch faults at 0x9000xxxx = prebound libSystem addresses; `_exp2`/`_memchr` call arguments compared in unused registers; vtable pointers canonicalised in the wrong
address space; code after `abort` executed), none to a rebuilt-code difference.

## Not covered
The ledger holds 508 of 1,799 corpus functions (the fnfuzz-eligible ones); the other ~1,290 (C++ methods with `this`/object graphs, varargs, callback-only, tiny) have no argument model in this census.


## Update Nov 15 (night): final image, extended ledger, two defects found
Rebuilt image now `us_ccbfd3b2/glprog/libGLProgrammability.dylib` (commit ccbfd3b2, md5 2b20f5ef1e4e6bbb46a1f67ef1a7f0f4; G5 `~/rung3/us_ccbfd3b2`), stock unchanged. Two censuses, 150 coverage-guided inputs per row:
* `trace_diff_census_fuzz150.tsv` - the 508-row rz ledger (as above): **PASS 507, OUT-OF-CONTRACT 1** (same row), FAIL 0.
* `trace_diff_census_ic_fuzz150.tsv` - 356 further rows (imp/ctx ledger rows not in the rz ledger, `ledger_glprog_ic.tsv`): **PASS 349, OUT-OF-CONTRACT 2, NO-INFO 5, FAIL 0**. Rows by worst trial outcome: IDENTICAL 212, REORDERED 84, FAULT_SITE 46, READ_SET 7, LAYOUT_ALL 5, PTR_VALUE_DEP 1, IMAGE_DATA_DEP 1; EFFECTS 0; 1,647 of 53,400 trials excluded as layout-dependent.
Together 864 of 1,799 corpus functions (48%) are covered; the remaining 935 still have no argument model.

### Defects this found (both fixed, issue + checked patch + image rebuilt + row re-run IDENTICAL)
| issue | function | stock vs corpus | fix |
|---|---|---|---|
| #289 | `_idstr` (0x97b8a330) | `*src - 0x2e < 2` compiled signed (`cmpwi`), stock unsigned range check (`cmplwi`): characters below 0x2e replaced by '_' | `PATCHES['_idstr']`, `(uint)` cast; row: old image EFFECTS (stock `___maskrune` call missing), fixed image IDENTICAL 340 / REORDERED 58 / LAYOUT_DEP 2 |
| #290 | `_uw_init_context_1` (0x97c1b79c) | stored an uninitialised local as the unwind context's return address (`in_LR` lost); stock `lwz r29,8(r2)` = own saved LR | `PATCHES['_uw_init_context_1']`, `__builtin_return_address(0)`; row: 150/150 IDENTICAL after (before: store at context+0x1c0 differed on every input) |

### Comparator rule added (trace_diff.py)
`fprintf` joins `printf/sprintf/snprintf`: only the arguments the format string consumes are behaviour (the other argument registers are caller leftovers, e.g. `TInfoSinkBase::append` `fprintf(f,"%s",s)` differed only in registers 6-8); an unreadable format (callee faults on it) leaves only the fixed arguments. This cleared `__ZN13TInfoSinkBase6appendERKSs`, `...appendEic` and `___eprintf` (all previously EFFECTS, no data difference in consumed arguments; re-run IDENTICAL).

### OUT-OF-CONTRACT / NO-INFO rows of the ic census
| row | gate | evidence |
|---|---|---|
| `_PPCConstantsAndScratchInitialise` | OOC (IMAGE_ADDR_DEP) | only f1 at return differs (stock 2.718281828459045, rebuilt 0.36787945032...): the function is declared `double` but both call sites (`part_000.c:34`, `part_016.c:13`) discard the result; the table it fills is identical (no store differs). Leftover f1, not an observable return. |
| `___cxa_throw` | OOC (PTR_VALUE_DEP) | stock stores its own `terminate` handler address (IMG 650764), the rebuilt the symbol `__ZSt9terminatev` (IMGR): an address of an import/function in each image, emulator mapping gap, not a value difference. |
| `ParseBinary/Unary/Selection/Loop/Branch__errorReportTail` (5) | NO-INFO (LAYOUT_ALL) | tail fragments of larger parse functions; every trial faults in both images and the stock itself differs at a second slide. NOT established: they are only exercised through their parent functions, which are not in a ledger. |

### Sign-compare audit (Tools/userspace/cmp_sign_audit.py)
Counts signed/unsigned ordering compares and `addi+cmpli` range-check pairs per function, stock vs rebuilt (glprog: 1,197 functions compared; sign-neutral compares filtered). Leads read so far:
`_idstr` (defect, fixed); `_InterpreterTextureSamplerSampleTexel1D/2D/3D` (`1 < ushort - 0x2700`, rebuilt signed: benign, enclosed by `(uint)(x - 0x2700) < 4` on the same field); `_byte_scan` digit checks (digit already range-limited by the loop condition: benign); `_glpPPDisassemble` (`--counter > 0`, signed in both). Not yet read: ~30 further range-pair rows. A difference is a lead, not a proof.

Sign-audit extension (Nov 15 night): the same audit run over GLEngine (3,382 functions compared), GLDriver (3,936), GA (40), VA (82), libGL (896) gave no further defect. Leads outside every census row (13 GLEngine, 16 GLDriver) were read at the
disassembly level: the rebuilt signed `addi+cmpwi` pairs there are `--counter > 0` / `x - 1 >= 0` loop and decrement tests (stock uses `addic.`), none is a `x - C < N` range test; in GLEngine/GLDriver/GA/VA/libGL no function
has a stock unsigned range check replaced by a signed one. Functions inside the censuses were not read individually: a signed-for-unsigned flip there is exposed by the random inputs (half of them have the high bit set).
The fprintf consumed-argument rule was added after the GLEngine/GLDriver/GA/VA/libGL censuses; it only drops unused argument registers from the comparison, so it cannot turn a PASS into a FAIL there (those censuses were not re-run).
