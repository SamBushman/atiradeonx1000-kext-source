#!/bin/sh
# valid-list-context check of the 177 stage-3 _Comp/_CompExec DIFF rows (plain27 rerun3, image gleng_1ec1b836): FNFUZZ_LISTCTX=1 (parameter 0 = a valid list context) + FLOATARGS=1,
# RUNINIT, 200 trials, per-trial lines (LISTDIFFS=1); fnfuzz_par.sh (manifest, chunks)
cd $HOME/rung3/gleng_fz || exit 1
FZ=$HOME/rung3/gleng_fz/fnfuzz_gs85
export FNFUZZ_STACKFILL=0 FNFUZZ_STACKFILL2=5a5a5a5a FNFUZZ_RUNINIT=1 FNFUZZ_NANCANON=1 FNFUZZ_ARENA_KB=512 FNFUZZ_LAZYSTOCK2=1 FNFUZZ_LISTCTX=1 FNFUZZ_FLOATARGS=1 FNFUZZ_LISTDIFFS=1
FNFUZZ_DATA=$HOME/rung3/gleng_fz/data_addrs_1ec1.tsv sh $HOME/rung3/fnf_237/fnfuzz_par.sh $FZ $HOME/rung3/fnf_237/p27_comp177.tsv /System/Library/Frameworks/OpenGL.framework/Resources/GLEngine.bundle/GLEngine $HOME/rung3/gleng_1ec1b836/gleng_link/GLEngine_rebuilt 200 4 2 $HOME/rung3/fnf_237/p27comp_valid
echo done > $HOME/rung3/fnf_237/p27comp_valid.script.done
