#!/bin/sh
cd ~/Documents/ATI-X1900-Decomp/atiradeonx1000-kext-source
SCR=/tmp/claude-1000/-var-home-sam/2670b33a-ea5f-4e43-81c2-8b3a797b033b/scratchpad
TG=~/Documents/ATI-X1900-Decomp/tiger-hd-pull
pads() { # name slice userdir loose short
  n=$1; sl=$2; ud=$3; lo=$4; sh=$5
  echo "== $n"; python3 Tools/userspace/build_corpus.py $sl ppc $SCR/o_$sh Userspace/$ud/ppc/unowned_code 2>&1 | grep -E "functions,|failing|^\('"
  cp $SCR/n_$sh/RANGES.tsv /tmp/ranges_${sh}_ocomb.tsv
  awk -F'\t' '{printf "0x%s\torph_%s\tfn\t%s-%s;\n",$1,$1,$1,$2}' /tmp/spec/orph_$sh.tsv >> /tmp/ranges_${sh}_ocomb.tsv
  LOOSE_NAMES=$lo EXTRA=Userspace/$ud/ppc/unowned_code/extra_decls.h sh Tools/userspace/verify_corpus.sh ${n}orph $sl $SCR/o_$sh > /tmp/verify_${n}orph.log 2>&1
  cat Userspace/$ud/ppc/ledger.tsv /tmp/verify_${n}orph/corp/ledger.tsv > /tmp/${n}_all_ledger.tsv
  LOOSE_NAMES=$lo LOWN=50 GAPN=0 python3 Tools/userspace/callee_compare_c.py /tmp/verify_${n}orph/stock.dis /tmp/verify_${n}orph/ours.dis /tmp/${n}_all_ledger.tsv /tmp/ranges_${sh}_ocomb.tsv > Userspace/$ud/ppc/unowned_code/verify_callees.txt
  cp /tmp/spec/orph_$sh.tsv Userspace/$ud/ppc/unowned_code/code_extents.tsv
  cp $SCR/o_$sh/PADOWNERS.tsv Userspace/$ud/ppc/unowned_code/code_owners.tsv
  grep "functions compared\|LOWCOUNT" Userspace/$ud/ppc/unowned_code/verify_callees.txt | cut -c1-200
}
pads gld /tmp/spec/slices/ATIRadeonX1000GLDriver.bundle.bin.ppc ATIRadeonX1000GLDriver 0 gld
pads glprog $TG/libGLProgrammability.dylib libGLProgrammability 1 glprog
echo DONE
