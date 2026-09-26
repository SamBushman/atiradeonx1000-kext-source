#!/bin/bash
# regen_b3.sh - Stage B3 (issues #67-#72, 2026-09-24/25): targeted re-decompiles on top of the Stage B2 projects. Each step works on a COPY of the
# B2 project; the address lists are in pipeline/b3/. The functions listed in b3/redump_*.txt are re-decompiled and replace their files in the
# archived dump (n_<x>/0x<entry>.txt); RANGES rows of the seven switch owners are widened to b3/ranges_widened_glprog.tsv (Tools/userspace
# flow_ranges.py). See pipeline/README.md, "Stage B3".
G=~/Documents/ATI-X1900-Decomp/atiradeonx1000-kext-source/Tools/userspace/gs
B=~/Documents/ATI-X1900-Decomp/atiradeonx1000-kext-source/Tools/userspace/pipeline/b3
AH=~/ghidra_12.1.3_PUBLIC/support/analyzeHeadless
OUT=${1:?output dir}
cd ~/Documents/ATI-X1900-Decomp/ghidra-projects
run() { proj=$1; pn=$2; prog=$3; shift 3; $AH $PWD/$proj $pn -process $prog -noanalysis -scriptPath $G "$@"; }
# libGLProgrammability (from glprog-un, the B2 project of the archived dump)
rm -rf glprog-sw && cp -r glprog-un glprog-sw
X="glprog-sw GLProgProject libGLProgrammability.dylib"
run $X -postScript PatchConstSwitch.java $(cat $B/constswitch_glprog.txt)
run $X -postScript SetValueReturn.java $(cat $B/setret_glprog.txt)
run $X -postScript OverrideVariadicCalls.java $(cat $B/variadic_glprog.txt)
run $X -postScript FlattenStructParams.java $(cat $B/flatten_glprog.txt)
run $X -postScript OverrideIndirectCalls.java $OUT/icalls_glprog.tsv ALL
run $X -postScript ExtendParams.java $(cat $B/extend_glprog.txt)
run $X -postScript WidenParams.java $(cat $B/widen_glprog.txt)
mkdir -p $OUT/n_glprog && run $X -readOnly -postScript RedumpContaining.java $OUT/n_glprog $(cat $B/redump_glprog.txt)
# step 8, stack parameters (9th+ argument words at 0x38(r1)), on a further copy; the redumped files replace their earlier versions
rm -rf glprog-stk && cp -r glprog-sw glprog-stk
X="glprog-stk GLProgProject libGLProgrammability.dylib"
run $X -postScript ExtendParams.java $(cat $B/stackparams_glprog.txt)
run $X -readOnly -postScript RedumpContaining.java $OUT/n_glprog $(cat $B/stackredump_glprog.txt)
# step 11: TPPStreamCompiler::error / ::warning take `this` in r3 (Ghidra had the demangled bool there); matched by qualified name + the PIC stub
rm -rf glprog-w2 && cp -r glprog-stk glprog-w2
X="glprog-w2 GLProgProject libGLProgrammability.dylib"
run $X -postScript WidenParams.java 0x97bc9a04:0 0x97bc9b34:0 0x97c21a00:0
run $X -readOnly -postScript RedumpContaining.java $OUT/n_glprog $(cat $B/widen2_redump_glprog.txt)
# GLDriver (from gld-ext) and GA (from r32-ga)
rm -rf gld-ret && cp -r gld-ext gld-ret
run gld-ret GLDProject ATIRadeonX1000GLDriver.bundle.bin -postScript SetValueReturn.java $(cat $B/setret_gld.txt)
run gld-ret GLDProject ATIRadeonX1000GLDriver.bundle.bin -postScript ExtendParams.java $(cat $B/extend_gld.txt)
mkdir -p $OUT/n_gld && run gld-ret GLDProject ATIRadeonX1000GLDriver.bundle.bin -readOnly -postScript RedumpContaining.java $OUT/n_gld $(cat $B/redump_gld.txt)
rm -rf gld-stk && cp -r gld-ret gld-stk
run gld-stk GLDProject ATIRadeonX1000GLDriver.bundle.bin -postScript ExtendParams.java $(cat $B/stackparams_gld.txt)
run gld-stk GLDProject ATIRadeonX1000GLDriver.bundle.bin -readOnly -postScript RedumpContaining.java $OUT/n_gld $(cat $B/stackredump_gld.txt)
# step 9: the two embedded jump tables Ghidra left unresolved ("Jumptable with 0 entries") and glAccum's missing r4 parameter
rm -rf gld-sw && cp -r gld-stk gld-sw
run gld-sw GLDProject ATIRadeonX1000GLDriver.bundle.bin -postScript FixSwitches.java 0xd072c 0xd0aa0
run gld-sw GLDProject ATIRadeonX1000GLDriver.bundle.bin -postScript ExtendParams.java 0x2ae0:2
run gld-sw GLDProject ATIRadeonX1000GLDriver.bundle.bin -readOnly -postScript RedumpContaining.java $OUT/n_gld 0xd0488 0xd0888 0x2ae0
# step 10 (no Ghidra): RANGES rows of every switch owner widened to its case code - b3/ranges_switch_{gld,glprog,va}.tsv from
#   python3 Tools/userspace/switch_ranges.py <stock.dis> $OUT/n_<x>/RANGES.tsv Userspace/<bin>/ppc/unowned_blocks.tsv <slice>   (run on the step-9 RANGES)
# replace those rows in $OUT/n_<x>/RANGES.tsv, then unowned_blocks.py / coverage.py / raw_blocks.py / raw_emit.py / text_complete.py as in Stage A
rm -rf r32-ga-ret && cp -r r32-ga r32-ga-ret
run r32-ga-ret Rest32Project ATIRadeonX1000GA.plugin.bin.ppc -postScript SetValueReturn.java $(cat $B/setret_ga.txt)
run r32-ga-ret Rest32Project ATIRadeonX1000GA.plugin.bin.ppc -postScript ExtendParams.java $(cat $B/extend_ga.txt)
mkdir -p $OUT/n_ga && run r32-ga-ret Rest32Project ATIRadeonX1000GA.plugin.bin.ppc -readOnly -postScript RedumpContaining.java $OUT/n_ga $(cat $B/redump_ga.txt)
rm -rf r32-va-ret && cp -r r32-va r32-va-ret
run r32-va-ret Rest32Project ATIRadeonX1000VADriver.bundle.bin.ppc -postScript SetValueReturn.java $(cat $B/setret_va.txt)
run r32-va-ret Rest32Project ATIRadeonX1000VADriver.bundle.bin.ppc -postScript ExtendParams.java $(cat $B/extend_va.txt)
mkdir -p $OUT/n_va && run r32-va-ret Rest32Project ATIRadeonX1000VADriver.bundle.bin.ppc -readOnly -postScript RedumpContaining.java $OUT/n_va $(cat $B/redump_va.txt)
# step 12: Darwin float-argument storage (_ecvt: ints after a double go in r5.., not r3..), FUN_000cdc3c's undeclared double (f1, set by all 17
# callers), and the libm imports' real prototypes (results in f1) - on further copies; callers re-decompiled
rm -rf gld-dw && cp -r gld-sw gld-dw
run gld-dw GLDProject ATIRadeonX1000GLDriver.bundle.bin -postScript DarwinStorage.java apply
run gld-dw GLDProject ATIRadeonX1000GLDriver.bundle.bin -postScript AddDoubleParams.java 0xcdc3c:1
run gld-dw GLDProject ATIRadeonX1000GLDriver.bundle.bin -postScript SetLibmSignatures.java
run gld-dw GLDProject ATIRadeonX1000GLDriver.bundle.bin -readOnly -postScript RedumpContaining.java $OUT/n_gld $(cat $B/darwin_redump_gld.txt) $(cat $B/libm_redump_gld.txt)
rm -rf glprog-lm && cp -r glprog-w2 glprog-lm
run glprog-lm GLProgProject libGLProgrammability.dylib -postScript SetLibmSignatures.java
run glprog-lm GLProgProject libGLProgrammability.dylib -readOnly -postScript RedumpContaining.java $OUT/n_glprog $(cat $B/libm_redump_glprog.txt)
rm -rf va-lm && cp -r r32-va-ret va-lm
run va-lm Rest32Project ATIRadeonX1000VADriver.bundle.bin.ppc -postScript SetLibmSignatures.java
run va-lm Rest32Project ATIRadeonX1000VADriver.bundle.bin.ppc -readOnly -postScript RedumpContaining.java $OUT/n_va $(cat $B/libm_redump_va.txt)
# step 13: functions re-created at their true entry (gcc scheduled the entry compare / CR save / stmw before mflr; the decompile read an
# uninitialised in_cr7 / unaff_r29), then Tools/userspace/apply_moves.py (INDEX/RANGES/dump files) and Tools/userspace/prune_orphans.py (orphans
# whose code a function now owns)
rm -rf gld-mv && cp -r gld-dw gld-mv
run gld-mv GLDProject ATIRadeonX1000GLDriver.bundle.bin -postScript MoveEntries.java $(cat $B/move_entries_gld.txt)
run gld-mv GLDProject ATIRadeonX1000GLDriver.bundle.bin -readOnly -postScript RedumpContaining.java $OUT/rd_mv_gld $(cut -d: -f2 $B/move_entries_gld.txt)
rm -rf glprog-mv && cp -r glprog-lm glprog-mv
run glprog-mv GLProgProject libGLProgrammability.dylib -postScript MoveEntries.java $(cat $B/move_entries_glprog.txt)
run glprog-mv GLProgProject libGLProgrammability.dylib -readOnly -postScript RedumpContaining.java $OUT/rd_mv_glprog $(cut -d: -f2 $B/move_entries_glprog.txt)
# python3 Tools/userspace/apply_moves.py $OUT/n_gld $B/move_entries_gld.txt $OUT/rd_mv_gld   (and glprog), then prune_orphans.py N O unowned_code orph_*.tsv
# step 14: arguments forwarded to calls through pointers (ForwardArgs.java: FUN_000e1564(ctx, size) & co.), then every import's prototype
# (SetImportSignatures.java: IOKit calls had lost 4 of their 6 arguments), call sites re-decompiled
rm -rf gld-fw && cp -r gld-mv gld-fw
run gld-fw GLDProject ATIRadeonX1000GLDriver.bundle.bin -postScript ForwardArgs.java $(cat $B/forward_args_gld.txt)
run gld-fw GLDProject ATIRadeonX1000GLDriver.bundle.bin -postScript SetImportSignatures.java
run gld-fw GLDProject ATIRadeonX1000GLDriver.bundle.bin -postScript RetypeParams.java $(cat $B/retype_forwarded_gld.txt)   # no-op with the uint ForwardArgs
run gld-fw GLDProject ATIRadeonX1000GLDriver.bundle.bin -readOnly -postScript RedumpContaining.java $OUT/n_gld $(cat $B/forward_redump_gld.txt) $(cat $B/importsig_redump_gld.txt)
rm -rf glprog-is && cp -r glprog-mv glprog-is
run glprog-is GLProgProject libGLProgrammability.dylib -postScript SetImportSignatures.java
run glprog-is GLProgProject libGLProgrammability.dylib -postScript ForwardArgs.java $(cat $B/forward_args_glprog.txt)
run glprog-is GLProgProject libGLProgrammability.dylib -postScript ExtendParams.java $(cat $B/forward_args_glprog.txt)   # the PIC stubs too
run glprog-is GLProgProject libGLProgrammability.dylib -readOnly -postScript RedumpContaining.java $OUT/n_glprog $(cat $B/forward_redump_glprog.txt)
run glprog-is GLProgProject libGLProgrammability.dylib -readOnly -postScript RedumpContaining.java $OUT/n_glprog $(cat $B/importsig_redump_glprog.txt)
rm -rf va-is && cp -r va-lm va-is
run va-is Rest32Project ATIRadeonX1000VADriver.bundle.bin.ppc -postScript SetImportSignatures.java
run va-is Rest32Project ATIRadeonX1000VADriver.bundle.bin.ppc -readOnly -postScript RedumpContaining.java $OUT/n_va $(cat $B/importsig_redump_va.txt)
rm -rf ga-is && cp -r r32-ga-ret ga-is
run ga-is Rest32Project ATIRadeonX1000GA.plugin.bin.ppc -postScript SetImportSignatures.java
run ga-is Rest32Project ATIRadeonX1000GA.plugin.bin.ppc -readOnly -postScript RedumpContaining.java $OUT/n_ga $(cat $B/importsig_redump_ga.txt)
# step 15: values Ghidra typed float that hold integers / pointers. FUN_001043f0 returns an object pointer (SetPointerReturn: its callers had kept
# the objects in float locals); stack locals typed float but holding counts / addresses (RetypeLocals, b3/retype_locals_*.txt from
# Tools/userspace/float_ints.py); the remaining plain int<->float casts become bit reinterpretations in ghidra2c (fix_float_int, needs
# CORPUS_SLICE, which build_corpus.py and verify_corpus.sh set)
rm -rf gld-rl && cp -r gld-fw gld-rl
run gld-rl GLDProject ATIRadeonX1000GLDriver.bundle.bin -postScript SetPointerReturn.java 0x1043f0
run gld-rl GLDProject ATIRadeonX1000GLDriver.bundle.bin -postScript RetypeLocals.java $(cat $B/retype_locals_gld.txt)
run gld-rl GLDProject ATIRadeonX1000GLDriver.bundle.bin -readOnly -postScript RedumpContaining.java $OUT/n_gld 0x180830 $(cut -d: -f1 $B/retype_locals_gld.txt)
rm -rf glprog-rl && cp -r glprog-is glprog-rl
run glprog-rl GLProgProject libGLProgrammability.dylib -postScript RetypeLocals.java $(cat $B/retype_locals_glprog.txt)
run glprog-rl GLProgProject libGLProgrammability.dylib -readOnly -postScript RedumpContaining.java $OUT/n_glprog $(cut -d: -f1 $B/retype_locals_glprog.txt)
rm -rf ga-rl && cp -r ga-is ga-rl
run ga-rl Rest32Project ATIRadeonX1000GA.plugin.bin.ppc -postScript RetypeLocals.java $(cat $B/retype_locals_ga.txt)
run ga-rl Rest32Project ATIRadeonX1000GA.plugin.bin.ppc -readOnly -postScript RedumpContaining.java $OUT/n_ga $(cut -d: -f1 $B/retype_locals_ga.txt)
# step 16: arguments still dropped at call sites, from Tools/userspace/callarg_check.py (a register argument the stock sets - constant, incoming
# parameter or stack address - that the C call does not pass at its position). glprog: the PIC stubs of _InterpreterNoiseGeneratorCalculate4D and
# of the RECT texture fetch took fewer parameters than their definitions read (ExtendParams); _InterpreterEmulateOp's noise output pointer is
# fixed in patches.py. GLDriver: prototypes for its libGLProgrammability / libGLImage imports (SetImportSignatures: glgConvertType printed 3 of
# its 8 arguments) and FUN_00165b7c forwards 7 registers to a call through a pointer.
rm -rf glprog-rc && cp -r glprog-rl glprog-rc
run glprog-rc GLProgProject libGLProgrammability.dylib -postScript ExtendParams.java $(cat $B/extend2_glprog.txt)
run glprog-rc GLProgProject libGLProgrammability.dylib -readOnly -postScript RedumpContaining.java $OUT/n_glprog $(cat $B/extend2_redump_glprog.txt)
rm -rf gld-gl && cp -r gld-rl gld-gl
run gld-gl GLDProject ATIRadeonX1000GLDriver.bundle.bin -postScript SetImportSignatures.java
run gld-gl GLDProject ATIRadeonX1000GLDriver.bundle.bin -postScript ForwardArgs.java 0x165b7c:7
run gld-gl GLDProject ATIRadeonX1000GLDriver.bundle.bin -readOnly -postScript RedumpContaining.java $OUT/n_gld $(cat $B/glfix_redump_gld.txt)
# step 17: indirect calls printed with fewer arguments than the stock passes (OverrideIndirectCalls.java only widened calls printed with none):
# Tools/userspace/indirect_args.py lists every bctrl's argument registers (b3/indirect_args_*.txt), ExtendIndirectCalls.java widens the calls that
# pass fewer (never narrows; calls with float arguments are left alone and listed) and writes the functions it changed (b3/indirect_redump_*.txt)
rm -rf gld-ia && cp -r gld-gl gld-ia
run gld-ia GLDProject ATIRadeonX1000GLDriver.bundle.bin -postScript ExtendIndirectCalls.java $B/indirect_args_gld.txt /dev/null
run gld-ia GLDProject ATIRadeonX1000GLDriver.bundle.bin -readOnly -postScript RedumpContaining.java $OUT/n_gld $(cat $B/indirect_redump_gld.txt)
rm -rf glprog-ia && cp -r glprog-rc glprog-ia
run glprog-ia GLProgProject libGLProgrammability.dylib -postScript ExtendIndirectCalls.java $B/indirect_args_glprog.txt /dev/null
run glprog-ia GLProgProject libGLProgrammability.dylib -readOnly -postScript RedumpContaining.java $OUT/n_glprog $(cat $B/indirect_redump_glprog.txt)
rm -rf ga-ia && cp -r ga-rl ga-ia
run ga-ia Rest32Project ATIRadeonX1000GA.plugin.bin.ppc -postScript ExtendIndirectCalls.java $B/indirect_args_ga.txt /dev/null
run ga-ia Rest32Project ATIRadeonX1000GA.plugin.bin.ppc -readOnly -postScript RedumpContaining.java $OUT/n_ga $(cat $B/indirect_redump_ga.txt)
rm -rf va-ia && cp -r va-is va-ia
run va-ia Rest32Project ATIRadeonX1000VADriver.bundle.bin.ppc -postScript ExtendIndirectCalls.java $B/indirect_args_va.txt /dev/null
run va-ia Rest32Project ATIRadeonX1000VADriver.bundle.bin.ppc -readOnly -postScript RedumpContaining.java $OUT/n_va $(cat $B/indirect_redump_va.txt)
# step 18: printf-family calls whose format is a global pointer variable, and calls that pass more arguments than the format consumes
# (OverrideVariadicCalls.java now resolves the pointer and narrows); the functions are re-dumped
rm -rf glprog-vf && cp -r glprog-ia glprog-vf
run glprog-vf GLProgProject libGLProgrammability.dylib -postScript OverrideVariadicCalls.java $(cat $B/variadic2_glprog.txt)
run glprog-vf GLProgProject libGLProgrammability.dylib -readOnly -postScript RedumpContaining.java $OUT/n_glprog $(cat $B/variadic2_redump_glprog.txt)
# step 19: _glpPPDisassemble returns a pointer (function + its PIC stub); callers of 9+-parameter functions whose stack arguments were dropped (stackarg_calls.py)
rm -rf glprog-pr && cp -r glprog-vf glprog-pr
run glprog-pr GLProgProject libGLProgrammability.dylib -postScript SetPointerReturn.java $(cat $B/ptrret_glprog.txt)
run glprog-pr GLProgProject libGLProgrammability.dylib -readOnly -postScript RedumpContaining.java $OUT/n_glprog $(cat $B/ptrret_redump_glprog.txt) $(cat $B/stackcallers_redump_glprog.txt)
run gld-ia GLDProject ATIRadeonX1000GLDriver.bundle.bin -readOnly -postScript RedumpContaining.java $OUT/n_gld $(cat $B/stackcallers_redump_gld.txt)
