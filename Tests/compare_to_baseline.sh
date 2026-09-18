#!/bin/sh
# compare_to_baseline.sh - build the harness, run it against whichever
# com.apple.ATIRadeonX1000 is currently loaded, and diff against the recorded stock baseline.
# Run on the Tiger G5 from this directory:   sh compare_to_baseline.sh
# Exit 0 = identical to the baseline; 1 = differences (printed); 2 = harness failed to run.
set -e
BASE=${BASE:-baseline/stock_4.1.9_g5_tiger.txt}
make -s >/dev/null
OUT=${OUT:-/tmp/parity_run.txt}
./parity_test_harness > "$OUT" 2>&1 || true
grep -q "calls made" "$OUT" || { echo "harness did not complete; see $OUT"; exit 2; }
if diff "$BASE" "$OUT" > /tmp/parity_diff.txt; then
    echo "IDENTICAL to baseline ($BASE)"
else
    echo "DIFFERS from baseline:"; cat /tmp/parity_diff.txt; exit 1
fi
