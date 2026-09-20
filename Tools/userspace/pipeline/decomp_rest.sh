#!/bin/sh
cd ~/Documents/ATI-X1900-Decomp/ghidra-projects
for f in ATIRadeonX1000GA.plugin.bin.ppc ATIRadeonX1000GA.plugin.bin.i386 ATIRadeonX1000VADriver.bundle.bin.ppc ATIRadeonX1000VADriver.bundle.bin.i386 libGL.dylib ATIRadeonX1000GLDriver.bundle.bin.i386; do
  mkdir -p /tmp/claude-1000/-var-home-sam/2670b33a-ea5f-4e43-81c2-8b3a797b033b/scratchpad/all_$f
  ~/ghidra_12.1.3_PUBLIC/support/analyzeHeadless $PWD/rest-proj RestProject -process $f -noanalysis -readOnly -scriptPath /tmp/claude-1000/-var-home-sam/2670b33a-ea5f-4e43-81c2-8b3a797b033b/scratchpad/gs -postScript DecompAll.java /tmp/claude-1000/-var-home-sam/2670b33a-ea5f-4e43-81c2-8b3a797b033b/scratchpad/all_$f > /tmp/claude-1000/-var-home-sam/2670b33a-ea5f-4e43-81c2-8b3a797b033b/scratchpad/all_$f.log 2>&1
  echo "done $f" >> /tmp/spec/decomp_rest.done
done
