#!/bin/sh
# per-trial diagnostics for the 46 stage-1 DIFF rows (gld rz, same env as rerun_v2 stage 1) with fnfuzz_gs85 FNFUZZ_LISTDIFFS=2:
#   real   : stock vs rebuilt gld_cc4e5e7b (the stage-1 image)
#   self   : stock vs a byte-identical copy of the stock (same function on both sides) = layout/load-address control
#   real2  : real again (is the set of differing trials repeatable? timing-dependent flags would move)
cd $HOME/rung3/fnf_237 || exit 1
FZ=$HOME/rung3/gleng_fz/fnfuzz_gs85; ST=/Library/ATIRadeonX1000-Rebuilt/stock/gld_ATIRadeonX1000GLDriver; RB=$HOME/rung3/gld_cc4e5e7b/gld_link/ATIRadeonX1000GLDriver_renamed
[ -f gld_stockcopy ] || cp $ST gld_stockcopy
export FNFUZZ_STACKFILL=0 FNFUZZ_STACKFILL2=5a5a5a5a FNFUZZ_RUNINIT=1 FNFUZZ_NANCANON=1 FNFUZZ_ARENA_KB=512 FNFUZZ_FLOATARGS=0 FNFUZZ_LAZYSTOCK2=1 FNFUZZ_LISTDIFFS=2
for m in real self real2; do
  case $m in self) L=diff46_self_ledger.tsv; R=gld_stockcopy;; *) L=diff46_ledger.tsv; R=$RB;; esac
  $FZ $L $ST $R 60 > diag46_$m.full 2>&1 < /dev/null
  echo "$m: `tail -1 diag46_$m.full`" >> diag46.log
done
echo done >> diag46.log
