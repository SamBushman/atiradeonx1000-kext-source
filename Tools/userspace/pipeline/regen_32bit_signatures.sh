#!/bin/bash
SCR=/tmp/claude-1000/-var-home-sam/a954711a-369a-4135-962a-a60a7b937668/scratchpad
G=~/Documents/ATI-X1900-Decomp/atiradeonx1000-kext-source/Tools/userspace/gs
AH=~/ghidra_12.1.3_PUBLIC/support/analyzeHeadless
cd ~/Documents/ATI-X1900-Decomp/ghidra-projects
run() { key=$1; prog=$2; lo=$3; hi=$4
  rm -rf r32-$key $SCR/n32x_$key; cp -r rest32-proj r32-$key
  $AH $PWD/r32-$key Rest32Project -process $prog -noanalysis -scriptPath $G -postScript NopMillicode.java $lo $hi 2>&1 | grep NOPMILLI
  $AH $PWD/r32-$key Rest32Project -process $prog -noanalysis -scriptPath $G -postScript CommitLiveSigs.java EXTEND 2>&1 | grep COMMITLIVE
  $AH $PWD/r32-$key Rest32Project -process $prog -noanalysis -scriptPath $G -postScript CopySigToStubs.java 2>&1 | grep COPYSIG
  $AH $PWD/r32-$key Rest32Project -process $prog -noanalysis -readOnly -scriptPath $G -postScript DecompAll.java $SCR/n32x_$key 2>&1 | grep DECOMPALL
  $AH $PWD/r32-$key Rest32Project -process $prog -noanalysis -readOnly -scriptPath $G -postScript DumpRanges.java $SCR/n32x_$key/RANGES.tsv > /dev/null 2>&1
}
run libgl libGL.dylib 92f27f90 92f27fdb
echo R32_DONE
