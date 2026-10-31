#!/bin/sh
# datacheck.sh Userspace/<Binary>/<arch> STOCK_BINARY GHIDRA_DATA.tsv LINK_CONFIG.json [BASE_REV] - data-side gate for `data` rows: link the corpus of BASE_REV (default HEAD)
# and the working tree with link_corpus.py (no G5 needed), map every renamed label of the candidate back to its Ghidra name (funcmap.py/unmap_names.py), and demand that
# the whole link tree (symbol_map.tsv, data.s, code.s, decls.h, the part files, ...) is IDENTICAL: same symbols at the same stock addresses, same sections, sizes, values and
# pointer words. Prints DATA-IDENTICAL or DATA-DIFFERENT with the first differences.
D=$1; STOCK=$2; GD=$3; CFG=$4; REV=${5:-HEAD}
H=$(cd $(dirname $0) && pwd); ROOT=$(git rev-parse --show-toplevel); cd $ROOT
T=${TMPDIR:-/tmp}/dc_$(echo $D | tr / _); rm -rf $T; mkdir -p $T/base
git archive $REV $D | tar -x -C $T/base
python3 $H/link_corpus.py $T/base/$D $STOCK $GD $T/lk_base --config $CFG > $T/base.log 2>&1 || { echo "link of base failed"; tail -3 $T/base.log; exit 2; }
python3 $H/link_corpus.py $D $STOCK $GD $T/lk_cand --config $CFG > $T/cand.log 2>&1 || { echo "link of candidate failed"; tail -3 $T/cand.log; exit 2; }
python3 $H/funcmap.py $D > $T/map.tsv; python3 $H/funcmap.py $T/base/$D > $T/map.base.tsv
[ -s $T/map.base.tsv ] && python3 $H/unmap_names.py $T/map.base.tsv $T/lk_base/*
[ -s $T/map.tsv ] && python3 $H/unmap_names.py $T/map.tsv $T/lk_cand/*
for f in base cand; do grep -h "data labels emitted\|typed data decls" $T/$f.log | sed 's/^[^:]*: //'; done
if diff -r -q $T/lk_base $T/lk_cand > $T/diff.txt; then echo "DATA-IDENTICAL ($(ls $T/lk_cand | wc -l) link files, $(wc -l < $T/lk_cand/symbol_map.tsv) symbols)"
else echo DATA-DIFFERENT; head -20 $T/diff.txt; exit 1; fi
