cd ~/rung3/fnf_237
FZ=$HOME/rung3/gleng_fz/fnfuzz_gs85; ST=/Library/ATIRadeonX1000-Rebuilt/stock/gld_ATIRadeonX1000GLDriver; RB=$HOME/rung3/gld_cc4e5e7b/gld_link/ATIRadeonX1000GLDriver_renamed
export FNFUZZ_STACKFILL=0 FNFUZZ_STACKFILL2=5a5a5a5a FNFUZZ_RUNINIT=1 FNFUZZ_NANCANON=1 FNFUZZ_ARENA_KB=512 FNFUZZ_FLOATARGS=0 FNFUZZ_LAZYSTOCK2=1 FNFUZZ_LISTDIFFS=1
: > tab2.out
for sp in gld_tables2_spec.txt gld_tables_spec.txt; do
  for n in `grep '^func ' $sp | awk '{print $2}'`; do
    echo "== $sp $n" >> tab2.out
    FNFUZZ_GRAPHSPEC=$sp $FZ diff46_ledger.tsv $ST $RB 1000 $n < /dev/null 2>&1 | egrep -a "^(DIFF|DT|REBUILT|RESULT|NOTE|UNINF)" | cut -c1-260 >> tab2.out
  done
done
echo TABDONE >> tab2.out
