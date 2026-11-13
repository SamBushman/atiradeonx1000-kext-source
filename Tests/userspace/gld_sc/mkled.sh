#!/bin/sh
# mkled.sh NAMESFILE PREFIX [VOIDFILE]: PREFIX_4966.tsv / PREFIX_b62d.tsv ledgers for the rows named in NAMESFILE (+ Compiler__initStaticLocals as row 9999 for the precall)
F=$HOME/g5logs/fnf_237; T=${TMPDIR:-/tmp}/mkled.$$
{ grep '^#anchor' $F/all17_gld.tsv; awk -F'\t' 'FNR==NR{n[$1]=1;next} ($2 in n){print}' $1 $F/all17_gld.tsv; printf '9999\tCompiler__initStaticLocals\t115fa0\t0\t34636\t-\ti\n'; } > $T
for k in 4966 b62d; do
  python3 ~/atiradeonx1000-kext-source/Tools/userspace/gleng_ledger_retarget.py $T $F/nm_$k.txt 2>/dev/null | awk -F'\t' -v V="${3:-/dev/null}" 'BEGIN{OFS="\t"; while((getline l < V)>0) v[l]=1} /^#/{print;next} {$7=($2 in v)?"v":"i"; print}' > $2_$k.tsv
  echo "$2_$k.tsv: $(grep -vc '^#' $2_$k.tsv) rows"
done
rm -f $T
