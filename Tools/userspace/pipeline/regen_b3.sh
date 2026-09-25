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
