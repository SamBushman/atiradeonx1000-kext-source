#!/bin/sh
# (1) self-control: the same 9 rows (8 deleting_dtor + gld_updateSampleCoverage), stock vs a byte copy of the stock (the RUNINIT second run is of the copy), 3000 trials: do the one-off st 14 flags also appear with no rebuilt code involved?
# (2) gld_updateSampleCoverage with gld_misc_spec.txt (valid state object), stock vs rebuilt cc4e, 3000 trials.
cd $HOME/rung3/fnf_237 || exit 1
FZ=$HOME/rung3/gleng_fz/fnfuzz_gs85; ST=/Library/ATIRadeonX1000-Rebuilt/stock/gld_ATIRadeonX1000GLDriver; RB=$HOME/rung3/gld_cc4e5e7b/gld_link/ATIRadeonX1000GLDriver_renamed
export FNFUZZ_STACKFILL=0 FNFUZZ_STACKFILL2=5a5a5a5a FNFUZZ_RUNINIT=1 FNFUZZ_NANCANON=1 FNFUZZ_ARENA_KB=512 FNFUZZ_LAZYSTOCK2=1 FNFUZZ_LISTDIFFS=1 FNFUZZ_FLOATARGS=0
$FZ flaky9_self_ledger.tsv $ST gld_stockcopy 3000 > flaky2_self.full 2>&1 < /dev/null
echo "self9: `tail -1 flaky2_self.full`" >> flaky2.log
FNFUZZ_GRAPHSPEC=gld_misc_spec.txt $FZ flaky9_ledger.tsv $ST $RB 3000 gld_updateSampleCoverage > flaky2_usc.full 2>&1 < /dev/null
echo "usc_spec: `tail -1 flaky2_usc.full`" >> flaky2.log
echo done >> flaky2.log
