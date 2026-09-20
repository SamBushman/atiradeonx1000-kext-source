#!/bin/bash
SCR=/tmp/claude-1000/-var-home-sam/a954711a-369a-4135-962a-a60a7b937668/scratchpad
G=~/Documents/ATI-X1900-Decomp/atiradeonx1000-kext-source/Tools/userspace/gs
P=~/Documents/ATI-X1900-Decomp/atiradeonx1000-kext-source/Tools/userspace/pipeline
AH=~/ghidra_12.1.3_PUBLIC/support/analyzeHeadless
cd ~/Documents/ATI-X1900-Decomp/ghidra-projects && rm -rf gld-o gld-p gld-base && cp -r gld-proj gld-base
X="-process ATIRadeonX1000GLDriver.bundle.bin -noanalysis"
$AH $PWD/gld-base GLDProject $X -scriptPath $G -postScript NopMillicode.java 1a322c 1a3277 2>&1 | grep NOPMILLI
$AH $PWD/gld-base GLDProject $X -scriptPath $G -postScript CommitLiveSigs.java EXTEND 2>&1 | grep COMMITLIVE
cp -r gld-base gld-o; cp -r gld-base gld-p
$AH $PWD/gld-o GLDProject $X -scriptPath $G -postScript RemoveExtras.java $SCR/arch_gld/n_gld $SCR/arch_gld/o_gld 2>&1 | grep REMOVEEXTRAS
$AH $PWD/gld-p GLDProject $X -scriptPath $G -postScript RemoveExtras.java $SCR/arch_gld/n_gld $SCR/arch_gld/p_gld 2>&1 | grep REMOVEEXTRAS
rm -rf $SCR/o_gld4 $SCR/p_gld4
$AH $PWD/gld-o GLDProject $X -readOnly -scriptPath $G -postScript CreateOrphans.java $P/orph_gld.tsv $SCR/o_gld4 2>&1 | grep -i "removed"
$AH $PWD/gld-p GLDProject $X -readOnly -scriptPath $G -postScript CreatePads.java $P/pads_gld.tsv $SCR/p_gld4 2>&1 | grep -i "removed\|noreturn"
wc -l $SCR/o_gld4/INDEX.tsv $SCR/p_gld4/INDEX.tsv
echo GLD_COMP_DONE
