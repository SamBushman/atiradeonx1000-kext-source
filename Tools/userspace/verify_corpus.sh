#!/bin/sh
# verify_corpus.sh NAME SLICE_FILE DECOMP_DUMP_DIR [ranges...]  - regenerate the corpus without call casts, one translation unit per
# function, compile -O0 on the G5, disassemble with the stock slice and compare callee sets (callee_compare_c.py).
N=$1; S=$2; D=$3; shift 3
[ $# -eq 0 ] && set -- $(python3 $(dirname $0)/slice_ranges.py $S)
H=$(dirname $0); T=/tmp/verify_$N; rm -rf $T; mkdir -p $T
CORPUS_SLICE=$S CORPUS_SCOPE=$(python3 -c "import sys; sys.path.insert(0, '$H'); import patches; print(patches.scope_of_slice('$S') or '')") NOCAST=1 LOOSE=1 SINGLE=1 python3 $H/ghidra2c.py $D $T/corp 60 "$@" > /dev/null || exit 1
cp $H/ghidra_c.h $T/corp/
[ -n "$EXTRA" ] && cp $EXTRA $T/corp/extra_decls.h && echo '#include "extra_decls.h"' >> $T/corp/decls.h
scp -q $S G5:/tmp/v_stock.bin
tar czf $T/c.tgz -C $T corp; scp -q $T/c.tgz G5:/tmp/v_c.tgz
ssh G5 'rm -rf /tmp/v_c; mkdir /tmp/v_c; cd /tmp/v_c && tar xzf /tmp/v_c.tgz && cd corp/single && for f in *.c; do gcc -arch ppc -w -O0 -mdynamic-no-pic -c $f -o ${f%.c}.o 2>/dev/null || echo FAIL $f; done > /tmp/v_fail.txt; ls *.o | wc -l; for o in *.o; do otool -arch ppc -tV $o; done > /tmp/v_ours.dis; otool -arch ppc -tV /tmp/v_stock.bin > /tmp/v_stock.dis; wc -l /tmp/v_fail.txt'
scp -q G5:/tmp/v_ours.dis G5:/tmp/v_stock.dis G5:/tmp/v_fail.txt $T/
mv $T/v_ours.dis $T/ours.dis; mv $T/v_stock.dis $T/stock.dis
# coalesced C++ text (weak definitions) is a separate section: append it so calls into/out of it are attributed
ssh G5 'otool -arch ppc -s __TEXT __textcoal_nt -V /tmp/v_stock.bin 2>/dev/null' | grep -E '^[0-9a-f]{8}	|^[A-Za-z_$][^ ]*:$' >> $T/stock.dis
python3 $H/callee_compare_c.py $T/stock.dis $T/ours.dis $T/corp/ledger.tsv $D/RANGES.tsv > $T/report.txt
head -3 $T/report.txt | cut -c1-200
