#!/bin/sh
# (1) 18 non-_Comp plain27 rows with a valid (zeroed list) context FNFUZZ_LISTCTX=1, 200 trials; (2) gleng_p18_spec.txt on the 6 context rows, 1000 trials; gs85, LISTDIFFS=1
cd $HOME/rung3/fnf_237 || exit 1
FZ=$HOME/rung3/gleng_fz/fnfuzz_gs85; ST=/System/Library/Frameworks/OpenGL.framework/Resources/GLEngine.bundle/GLEngine; RB=$HOME/rung3/gleng_1ec1b836/gleng_link/GLEngine_rebuilt
export FNFUZZ_STACKFILL=0 FNFUZZ_STACKFILL2=5a5a5a5a FNFUZZ_RUNINIT=1 FNFUZZ_NANCANON=1 FNFUZZ_ARENA_KB=512 FNFUZZ_LAZYSTOCK2=1 FNFUZZ_LISTDIFFS=1 FNFUZZ_DATA=$HOME/rung3/gleng_fz/data_addrs_1ec1.tsv
FNFUZZ_LISTCTX=1 FNFUZZ_FLOATARGS=1 $FZ p27_other18.tsv $ST $RB 200 > p18_listctx.full 2>&1 < /dev/null
echo "listctx: `tail -1 p18_listctx.full`" >> p18.log
FNFUZZ_GRAPHSPEC=gleng_p18_spec.txt FNFUZZ_FLOATARGS=0 $FZ p27_other18.tsv $ST $RB 1000 > p18_spec.full 2>&1 < /dev/null
echo "spec: `tail -1 p18_spec.full`" >> p18.log
echo done >> p18.log
