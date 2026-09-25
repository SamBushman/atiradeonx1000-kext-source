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
mkdir -p $OUT/n_glprog && run $X -readOnly -postScript RedumpContaining.java $OUT/n_glprog $(cat $B/redump_glprog.txt)
# GLDriver (from gld-ext) and GA (from r32-ga)
rm -rf gld-ret && cp -r gld-ext gld-ret
run gld-ret GLDProject ATIRadeonX1000GLDriver.bundle.bin -postScript SetValueReturn.java $(cat $B/setret_gld.txt)
mkdir -p $OUT/n_gld && run gld-ret GLDProject ATIRadeonX1000GLDriver.bundle.bin -readOnly -postScript RedumpContaining.java $OUT/n_gld $(cat $B/setret_gld.txt)
rm -rf r32-ga-ret && cp -r r32-ga r32-ga-ret
run r32-ga-ret Rest32Project ATIRadeonX1000GA.plugin.bin.ppc -postScript SetValueReturn.java $(cat $B/setret_ga.txt)
mkdir -p $OUT/n_ga && run r32-ga-ret Rest32Project ATIRadeonX1000GA.plugin.bin.ppc -readOnly -postScript RedumpContaining.java $OUT/n_ga $(cat $B/setret_ga.txt)
