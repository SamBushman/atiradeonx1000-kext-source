cd $HOME/rung3/fnf_237 || exit 1
FZ=$HOME/rung3/gleng_fz/fnfuzz_gs85; ST=/System/Library/Frameworks/OpenGL.framework/Resources/GLEngine.bundle/GLEngine; RB=$HOME/rung3/gleng_1ec1b836/gleng_link/GLEngine_rebuilt
export FNFUZZ_STACKFILL=0 FNFUZZ_STACKFILL2=5a5a5a5a FNFUZZ_RUNINIT=1 FNFUZZ_NANCANON=1 FNFUZZ_ARENA_KB=512 FNFUZZ_LAZYSTOCK2=1 FNFUZZ_LISTDIFFS=1 FNFUZZ_FLOATARGS=0 FNFUZZ_DATA=$HOME/rung3/gleng_fz/data_addrs_1ec1.tsv
FNFUZZ_GRAPHSPEC=gleng_pmap_spec.txt $FZ p27_other18.tsv $ST $RB 1000 _glGetPixelMap > pmap.full 2>&1 < /dev/null
echo "pmap: `tail -1 pmap.full`" > pmap.log; echo done >> pmap.log
