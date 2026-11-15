#!/bin/sh
# Closing run (Nov 15, 3c4e11b1): the _gleEvalDomain* evaluators with gleng_eval_spec.txt (order 1..8, valid buffers), 1000 trials, same env as closing_checks_3c4e.sh
cd $HOME/rung3/fnf_237 || exit 1
FZ=$HOME/rung3/gleng_fz/fnfuzz_gs85; ST=/System/Library/Frameworks/OpenGL.framework/Resources/GLEngine.bundle/GLEngine; RB=$HOME/rung3/gleng_3c4e11b1/gleng_link/GLEngine_rebuilt
export FNFUZZ_STACKFILL=0 FNFUZZ_STACKFILL2=5a5a5a5a FNFUZZ_RUNINIT=1 FNFUZZ_NANCANON=1 FNFUZZ_ARENA_KB=512 FNFUZZ_LAZYSTOCK2=1 FNFUZZ_LISTDIFFS=1 FNFUZZ_DATA=$HOME/rung3/gleng_fz/data_addrs_3c4e.tsv
FNFUZZ_GRAPHSPEC=gleng_eval_spec.txt FNFUZZ_FLOATARGS=0 $FZ p27_eval.tsv $ST $RB 1000 _gleEvalDomain > c3c4e_eval.full 2>&1 < /dev/null
echo done > c3c4e_eval.done
