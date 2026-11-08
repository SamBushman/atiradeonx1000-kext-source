#!/bin/sh
# t3_compare_by_hand.sh NAME [OUT=$HOME/g5logs/t3_phaseR]      (dev machine)
# The comparison step of Tools/t3_phaseR_one.sh, standalone: normalise the newest rebuilt result log of T3 test NAME on the G5 and its recorded Phase S (stock) log, write NAME.{rebuilt,stock}.norm and NAME.diff, print the diff
# size. Use it when the runner stopped before its own compare (a false HANG verdict, see the T3 phase in Tests/full_evaluation_runbook.md). rc 0 = identical, 1 = differs.
N=${1:?test name}; OUT=${2:-$HOME/g5logs/t3_phaseR}; H=${H:-G5}; SRC=${SRC:-src_$(ssh $H 'ls -dt $HOME/rung3/src_* | grep -v tgz | head -1' | sed 's|.*src_||')}; D=rung3/$SRC/Tests/destructive
NEW=$(ssh $H "cd $D && ls -t results/t3_${N}_rebuilt_*.log | head -1"); OLD=$(ssh $H "cd $D && ls -t phaseS/t3_${N}_stock_*.log | tail -1"); echo "$NEW | $OLD"
norm() { ssh $H "cd $D && cat $1" | sed 's/^[^ ]* \[[^]]*\] //' | grep -E "^(RESULT|NOTE)" | grep -v "^NOTE start:"; }
norm "$NEW" > "$OUT/$N.rebuilt.norm"; norm "$OLD" > "$OUT/$N.stock.norm"
diff "$OUT/$N.stock.norm" "$OUT/$N.rebuilt.norm" > "$OUT/$N.diff"; rc=$?; echo "$N: diff rc=$rc, $(wc -l < "$OUT/$N.diff") line(s)"; exit $rc
