#!/bin/sh
# repeat the rows whose only DIFF in the sweeps was a one-off watchdog (st 14) / digest flag: _glUniform3fvARB_Comp (valid list ctx) and the 8 *_deleting_dtor + gld_updateSampleCoverage rows; 1000 trials, LISTDIFFS=1
cd $HOME/rung3/fnf_237 || exit 1
FZ=$HOME/rung3/gleng_fz/fnfuzz_gs85
export FNFUZZ_STACKFILL=0 FNFUZZ_STACKFILL2=5a5a5a5a FNFUZZ_RUNINIT=1 FNFUZZ_NANCANON=1 FNFUZZ_ARENA_KB=512 FNFUZZ_LAZYSTOCK2=1 FNFUZZ_LISTDIFFS=1
FNFUZZ_LISTCTX=1 FNFUZZ_FLOATARGS=1 FNFUZZ_DATA=$HOME/rung3/gleng_fz/data_addrs_1ec1.tsv $FZ uni3_ledger.tsv /System/Library/Frameworks/OpenGL.framework/Resources/GLEngine.bundle/GLEngine $HOME/rung3/gleng_1ec1b836/gleng_link/GLEngine_rebuilt 1000 > flaky_uni3.full 2>&1 < /dev/null
echo "uni3: `tail -1 flaky_uni3.full`" >> flaky.log
FNFUZZ_FLOATARGS=0 $FZ flaky9_ledger.tsv /Library/ATIRadeonX1000-Rebuilt/stock/gld_ATIRadeonX1000GLDriver $HOME/rung3/gld_cc4e5e7b/gld_link/ATIRadeonX1000GLDriver_renamed 1000 > flaky_gld9.full 2>&1 < /dev/null
echo "gld9: `tail -1 flaky_gld9.full`" >> flaky.log
echo done >> flaky.log
