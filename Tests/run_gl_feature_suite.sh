#!/bin/sh
# Tests/run_gl_feature_suite.sh OUTDIR [TIMEOUT=120]   (ON the G5, from Tests/, after build_all.sh; against whichever ATIRadeonX1000 is loaded)
# Runs every self-checking GL program (userspace/gl_feature_*_test, plus userspace/cgl_probe) one at a time, each with a TIMEOUT-second limit (SIGTERM; never SIGKILL a live GL client: see glstress.h
# hazard note). Per program: OUTDIR/<name>.out (stdout+stderr) and one line in OUTDIR/summary.tsv:  name <TAB> exit-code <TAB> fail-lines (MISMATCH / RESULT: FAIL / leading FAIL / TIMEOUT, +1 if the output is empty) <TAB> seconds <TAB> output bytes.
# Compare two runs (stock vs rebuilt) with:  diff stock/summary.tsv rebuilt/summary.tsv   (the seconds column is ignored by sh compare_gl_feature_runs.sh)
O=${1:?usage: sh run_gl_feature_suite.sh OUTDIR [TIMEOUT]}; T=${2:-120}; mkdir -p "$O"; : > "$O/summary.tsv"
cd "$(dirname "$0")" || exit 2
for p in userspace/gl_feature_*_test userspace/cgl_probe; do
    [ -x "$p" ] || { echo "missing binary $p (run build_all.sh)"; continue; }
    n=`basename $p`; s=`date +%s`
    "$p" > "$O/$n.out" 2>&1 < /dev/null &
    pid=$!; i=0
    while kill -0 $pid 2>/dev/null && [ $i -lt $T ]; do sleep 1; i=`expr $i + 1`; done
    if kill -0 $pid 2>/dev/null; then kill $pid 2>/dev/null; sleep 5; echo "TIMEOUT after ${T}s" >> "$O/$n.out"; rc=124; else wait $pid; rc=$?; fi
    f=`grep -cE "MISMATCH|RESULT: FAIL|^FAIL|TIMEOUT after" "$O/$n.out"`
    b=`wc -c < "$O/$n.out" | tr -d ' '`   # an EMPTY output is never a pass (a silent _exit(0) in the driver's shader compiler looked like one)
    [ "$b" = 0 ] && f=`expr $f + 1`
    printf '%s\t%s\t%s\t%s\t%s\n' "$n" "$rc" "$f" "`expr \`date +%s\` - $s`" "$b" >> "$O/summary.tsv"
    echo "$n rc=$rc fail-lines=$f bytes=$b"
done
echo "done: `wc -l < $O/summary.tsv` programs, `awk -F'\t' '$2 != 0' $O/summary.tsv | wc -l` with non-zero exit (see $O/summary.tsv)"
