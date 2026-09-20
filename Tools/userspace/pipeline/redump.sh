#!/bin/sh
cd ~/Documents/ATI-X1900-Decomp/ghidra-projects
r() { proj=$1; name=$2; prog=$3; dir=$4; rm -rf /tmp/claude-1000/-var-home-sam/2670b33a-ea5f-4e43-81c2-8b3a797b033b/scratchpad/$dir; mkdir -p /tmp/claude-1000/-var-home-sam/2670b33a-ea5f-4e43-81c2-8b3a797b033b/scratchpad/$dir; ~/ghidra_12.1.3_PUBLIC/support/analyzeHeadless $PWD/$proj $name -process $prog -noanalysis -readOnly -scriptPath /tmp/claude-1000/-var-home-sam/2670b33a-ea5f-4e43-81c2-8b3a797b033b/scratchpad/gs -postScript DecompAll.java /tmp/claude-1000/-var-home-sam/2670b33a-ea5f-4e43-81c2-8b3a797b033b/scratchpad/$dir > /tmp/claude-1000/-var-home-sam/2670b33a-ea5f-4e43-81c2-8b3a797b033b/scratchpad/$dir.log 2>&1; ~/ghidra_12.1.3_PUBLIC/support/analyzeHeadless $PWD/$proj $name -process $prog -noanalysis -readOnly -scriptPath /tmp/claude-1000/-var-home-sam/2670b33a-ea5f-4e43-81c2-8b3a797b033b/scratchpad/gs -postScript DumpRanges.java /tmp/claude-1000/-var-home-sam/2670b33a-ea5f-4e43-81c2-8b3a797b033b/scratchpad/$dir/RANGES.tsv >/dev/null 2>&1; echo done $dir >> /tmp/spec/redump.done; }
r rest-proj RestProject ATIRadeonX1000GA.plugin.bin.ppc n_ga
r rest-proj RestProject ATIRadeonX1000VADriver.bundle.bin.ppc n_va
r rest-proj RestProject libGL.dylib n_libgl
r glprog-proj GLProgProject libGLProgrammability.dylib n_glprog
r gld-proj GLDProject ATIRadeonX1000GLDriver.bundle.bin n_gld
