#!/bin/sh
cd ~/Documents/ATI-X1900-Decomp/atiradeonx1000-kext-source
SCR=/tmp/claude-1000/-var-home-sam/2670b33a-ea5f-4e43-81c2-8b3a797b033b/scratchpad
TG=~/Documents/ATI-X1900-Decomp/tiger-hd-pull
run() {  # NAME SLICE DUMPDIR USERDIR [LOOSE]
  n=$1; sl=$2; dd=$3; ud=$4
  echo "== $n build"; python3 Tools/userspace/build_corpus.py $sl ppc $SCR/$dd Userspace/$ud/ppc 2>&1 | grep -E "functions,|failing|^\('"
  echo "== $n verify"; LOOSE_NAMES=$5 EXTRA=Userspace/$ud/ppc/extra_decls.h sh Tools/userspace/verify_corpus.sh $n $sl $SCR/$dd > /tmp/verify_$n.log 2>&1
  cp /tmp/verify_$n/report.txt Userspace/$ud/ppc/verify_callees.txt
  head -4 /tmp/verify_$n/report.txt | cut -c1-200
  python3 Tools/userspace/unowned_blocks.py /tmp/verify_$n/stock.dis $SCR/$dd/RANGES.tsv Userspace/$ud/ppc/ledger.tsv Userspace/$ud/ppc/unowned_blocks.tsv
  python3 Tools/userspace/coverage.py $sl $SCR/$dd/RANGES.tsv 5 > Userspace/$ud/ppc/coverage.txt 2>&1
}
run ga /tmp/spec/slices/ATIRadeonX1000GA.plugin.bin.ppc n_ga ATIRadeonX1000GA
run va /tmp/spec/slices/ATIRadeonX1000VADriver.bundle.bin.ppc n_va ATIRadeonX1000VADriver
run libgl /tmp/spec/slices/libGL.dylib n_libgl libGL
run glprog $TG/libGLProgrammability.dylib n_glprog libGLProgrammability 1
run gld /tmp/spec/slices/ATIRadeonX1000GLDriver.bundle.bin.ppc n_gld ATIRadeonX1000GLDriver
echo DONE
