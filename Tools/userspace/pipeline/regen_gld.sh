#!/bin/bash
SCR=/tmp/claude-1000/-var-home-sam/a954711a-369a-4135-962a-a60a7b937668/scratchpad
G=~/Documents/ATI-X1900-Decomp/atiradeonx1000-kext-source/Tools/userspace/gs
AH=~/ghidra_12.1.3_PUBLIC/support/analyzeHeadless
cd ~/Documents/ATI-X1900-Decomp/ghidra-projects && rm -rf gld-ext && cp -r gld-proj gld-ext
$AH $PWD/gld-ext GLDProject -process ATIRadeonX1000GLDriver.bundle.bin -noanalysis -scriptPath $G -postScript NopMillicode.java 1a322c 1a3277 2>&1 | grep NOPMILLI
$AH $PWD/gld-ext GLDProject -process ATIRadeonX1000GLDriver.bundle.bin -noanalysis -scriptPath $G -postScript CommitLiveSigs.java EXTEND > $SCR/cl_gld_ext.log 2>&1
grep "COMMITLIVE\|ONLY" $SCR/cl_gld_ext.log
$AH $PWD/gld-ext GLDProject -process ATIRadeonX1000GLDriver.bundle.bin -noanalysis -scriptPath $G -postScript RemoveExtras.java $SCR/arch_gld/n_gld 2>&1 | grep REMOVEEXTRAS
for s in UniqueNames ThisToStdcall CopySigToStubs; do $AH $PWD/gld-ext GLDProject -process ATIRadeonX1000GLDriver.bundle.bin -noanalysis -scriptPath $G -postScript $s.java 2>&1 | grep "UNIQUENAMES\|THISTO\|COPYSIG"; done
rm -rf $SCR/nl_gld_ext; $AH $PWD/gld-ext GLDProject -process ATIRadeonX1000GLDriver.bundle.bin -noanalysis -readOnly -scriptPath $G -postScript DecompAll.java $SCR/nl_gld_ext > $SCR/dgld_ext.log 2>&1
grep DECOMPALL $SCR/dgld_ext.log
echo GLD_EXT_DONE
