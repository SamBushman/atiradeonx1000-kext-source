#!/bin/sh
# Closing-run (Nov 15, images 3c4e11b1) re-checks of the stage-3 plain27 DIFF rows with the same valid-context / valid-graph methods as comp_check.sh, run_p18.sh, run_hist.sh, run_pmap.sh (those name the 1ec1b836 image), gs85, LISTDIFFS=1:
#  (1) the 244 _Comp/_CompExec DIFF rows with FNFUZZ_LISTCTX=1 FLOATARGS=1, 200 trials (fnfuzz_par.sh: manifest, chunks); (2) the 20 other DIFF rows with LISTCTX 200 trials; (3) gleng_p18_spec.txt (1000 trials);
#  (4) gleng_hist_spec.txt, (5) gleng_pmap_spec.txt, (6) gleng_hilo_spec.txt (1000 trials each)
cd $HOME/rung3/fnf_237 || exit 1
D=$PWD; FZ=$HOME/rung3/gleng_fz/fnfuzz_gs85; ST=/System/Library/Frameworks/OpenGL.framework/Resources/GLEngine.bundle/GLEngine; RB=$HOME/rung3/gleng_3c4e11b1/gleng_link/GLEngine_rebuilt
export FNFUZZ_STACKFILL=0 FNFUZZ_STACKFILL2=5a5a5a5a FNFUZZ_RUNINIT=1 FNFUZZ_NANCANON=1 FNFUZZ_ARENA_KB=512 FNFUZZ_LAZYSTOCK2=1 FNFUZZ_LISTDIFFS=1 FNFUZZ_DATA=$HOME/rung3/gleng_fz/data_addrs_3c4e.tsv
FNFUZZ_LISTCTX=1 FNFUZZ_FLOATARGS=1 sh $D/fnfuzz_par.sh $FZ $D/p27_comp244.tsv $ST $RB 200 4 2 $D/c3c4e_comp244
FNFUZZ_LISTCTX=1 FNFUZZ_FLOATARGS=1 $FZ p27_other20.tsv $ST $RB 200 > c3c4e_other20_listctx.full 2>&1 < /dev/null
FNFUZZ_GRAPHSPEC=gleng_p18_spec.txt FNFUZZ_FLOATARGS=0 $FZ p27_other20.tsv $ST $RB 1000 > c3c4e_p18_spec.full 2>&1 < /dev/null
FNFUZZ_GRAPHSPEC=gleng_hist_spec.txt FNFUZZ_FLOATARGS=0 $FZ p27_other20.tsv $ST $RB 1000 Parameterfv_Exec > c3c4e_hist.full 2>&1 < /dev/null
FNFUZZ_GRAPHSPEC=gleng_pmap_spec.txt FNFUZZ_FLOATARGS=0 $FZ p27_other20.tsv $ST $RB 1000 _glGetPixelMap > c3c4e_pmap.full 2>&1 < /dev/null
echo done > $D/closing_checks_3c4e.done
