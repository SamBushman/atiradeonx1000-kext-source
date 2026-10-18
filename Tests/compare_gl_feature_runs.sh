#!/bin/sh
# Tests/compare_gl_feature_runs.sh STOCK_DIR REBUILT_DIR : compare two run_gl_feature_suite.sh outputs. Exit 0 = every program has the same exit code and FAIL-line count AND identical output
# (timestamps/addresses are not printed by these programs); 1 = differences (listed).
S=${1:?}; R=${2:?}; bad=0
for f in "$S"/*.out; do
    n=`basename $f`
    [ -f "$R/$n" ] || { echo "MISSING in rebuilt: $n"; bad=1; continue; }
    cmp -s "$f" "$R/$n" || { echo "OUTPUT DIFFERS: $n"; bad=1; }
done
cut -f1-3 "$S/summary.tsv" > $R/.gfs_s.$$ ; cut -f1-3 "$R/summary.tsv" > $R/.gfs_r.$$
diff $R/.gfs_s.$$ $R/.gfs_r.$$ > $R/.gfs_d.$$ || { echo "SUMMARY DIFFERS (name, exit code, FAIL lines):"; cat $R/.gfs_d.$$; bad=1; }
rm -f $R/.gfs_s.$$ $R/.gfs_r.$$ $R/.gfs_d.$$
[ $bad = 0 ] && echo "IDENTICAL: stock and rebuilt give the same result for every GL feature program"
exit $bad
