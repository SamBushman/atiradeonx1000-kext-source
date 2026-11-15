#!/bin/sh
# per-trial diagnostics for the 18 non-_Comp plain27 DIFF rows (stage 3, GLEngine image gleng_1ec1b836): real / self-control (stock vs byte copy of stock) / real again; gs85 LISTDIFFS=2, stage-3 env
cd $HOME/rung3/fnf_237 || exit 1
FZ=$HOME/rung3/gleng_fz/fnfuzz_gs85; ST=/System/Library/Frameworks/OpenGL.framework/Resources/GLEngine.bundle/GLEngine; RB=$HOME/rung3/gleng_1ec1b836/gleng_link/GLEngine_rebuilt
[ -f gleng_stockcopy ] || cp $ST gleng_stockcopy
export FNFUZZ_STACKFILL=0 FNFUZZ_STACKFILL2=5a5a5a5a FNFUZZ_RUNINIT=1 FNFUZZ_NANCANON=1 FNFUZZ_ARENA_KB=512 FNFUZZ_LAZYSTOCK2=1 FNFUZZ_LISTDIFFS=2
export FNFUZZ_STACKREC=glgProcessPixels:1:13 FNFUZZ_ADDRDEP=_gleOptimizeDisplayListCreateHashTable FNFUZZ_DATA=$HOME/rung3/gleng_fz/data_addrs_1ec1.tsv FNFUZZ_LISTUNINF=1
for m in real self real2; do
  case $m in self) R=gleng_stockcopy;; *) R=$RB;; esac
  L=p27_other18.tsv; [ $m = self ] && L=p27_other18_self.tsv; $FZ $L $ST $R 100 > diag18_$m.full 2>&1 < /dev/null
  echo "$m: `tail -1 diag18_$m.full`" >> diag18.log
done
echo done >> diag18.log
