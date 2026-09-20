#!/bin/bash
SCR=/tmp/claude-1000/-var-home-sam/a954711a-369a-4135-962a-a60a7b937668/scratchpad
G=~/Documents/ATI-X1900-Decomp/atiradeonx1000-kext-source/Tools/userspace/gs
P=~/Documents/ATI-X1900-Decomp/atiradeonx1000-kext-source/Tools/userspace/pipeline
AH=~/ghidra_12.1.3_PUBLIC/support/analyzeHeadless
X="-process libGLProgrammability.dylib -noanalysis"
cd ~/Documents/ATI-X1900-Decomp/ghidra-projects && rm -rf glprog-o glprog-p $SCR/o_gp4 $SCR/p_gp4
for k in o p; do
  cp -r glprog-sigs glprog-$k
  if [ $k = o ]; then EX="$SCR/arch_gp/n_glprog $SCR/arch_gp/o_glprog"; else EX="$SCR/arch_gp/n_glprog $SCR/arch_gp/p_glprog"; fi
  $AH $PWD/glprog-$k GLProgProject $X -scriptPath $G -postScript RemoveExtras.java $EX 2>&1 | grep REMOVEEXTRAS
  for s in UniqueNames ThisToStdcall CopySigToStubs; do $AH $PWD/glprog-$k GLProgProject $X -scriptPath $G -postScript $s.java 2>&1 | grep "UNIQUENAMES\|THISTO\|COPYSIG" | cut -c1-120; done
done
$AH $PWD/glprog-o GLProgProject $X -readOnly -scriptPath $G -postScript CreateOrphans.java $P/orph_glprog.tsv $SCR/o_gp4 2>&1 | grep -i removed
$AH $PWD/glprog-p GLProgProject $X -readOnly -scriptPath $G -postScript CreatePads.java $P/pads_glprog.tsv $SCR/p_gp4 2>&1 | grep -i "removed\|noreturn"
wc -l $SCR/o_gp4/INDEX.tsv $SCR/p_gp4/INDEX.tsv
echo GP_COMP_DONE
