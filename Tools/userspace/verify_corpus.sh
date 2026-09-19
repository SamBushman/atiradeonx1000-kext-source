#!/bin/sh
# verify_corpus.sh NAME SLICE_FILE DECOMP_DUMP_DIR [ranges...]  - regenerate the corpus without call casts, one translation unit per
# function, compile -O0 on the G5, disassemble with the stock slice and compare callee sets (callee_compare_c.py).
N=$1; S=$2; D=$3; shift 3
H=$(dirname $0); T=/tmp/verify_$N; rm -rf $T; mkdir -p $T
NOCAST=1 SINGLE=1 python3 $H/ghidra2c.py $D $T/corp 60 "$@" > /dev/null || exit 1
cp $H/ghidra_c.h $T/corp/
[ -f /tmp/spec/extra_$N.h ] && cp /tmp/spec/extra_$N.h $T/corp/extra_decls.h
scp -q $S G5:/tmp/v_stock.bin
tar czf $T/c.tgz -C $T corp; scp -q $T/c.tgz G5:/tmp/v_c.tgz
ssh G5 'rm -rf /tmp/v_c; mkdir /tmp/v_c; cd /tmp/v_c && tar xzf /tmp/v_c.tgz && cd corp/single && for f in *.c; do gcc -arch ppc -w -O0 -mdynamic-no-pic -c $f -o ${f%.c}.o 2>/dev/null || echo FAIL $f; done > /tmp/v_fail.txt; ls *.o | wc -l; for o in *.o; do otool -arch ppc -tV $o; done > /tmp/v_ours.dis; otool -arch ppc -tV /tmp/v_stock.bin > /tmp/v_stock.dis; wc -l /tmp/v_fail.txt'
scp -q G5:/tmp/v_ours.dis G5:/tmp/v_stock.dis G5:/tmp/v_fail.txt $T/
mv $T/v_ours.dis $T/ours.dis; mv $T/v_stock.dis $T/stock.dis
python3 $H/callee_compare_c.py $T/stock.dis $T/ours.dis $T/corp/ledger.tsv $D/RANGES.tsv > $T/report.txt
head -3 $T/report.txt | cut -c1-200
