#!/bin/sh
# q.sh PART  : quick gate of the working tree's PART (e.g. part_011) against base dis of the lpH2 snapshot (base=b8c3503)
P=${1:-part_011}; cd ~/wt/lp8; D=Userspace/libGLProgrammability/ppc; B=/tmp/vn_Userspace_libGLProgrammability_ppc_lpH2
R=rung3/q_$P
ssh G5 "mkdir -p $R" && scp -q $D/$P.c $D/decls.h $D/ghidra_c.h $D/extra_decls.h G5:$R/ 2>/dev/null
# the part includes headers relative to its dir: copy the whole dir headers if needed
ssh G5 "cd $R && gcc -arch ppc -w -S $P.c -o cand.dis 2> /dev/null; gcc -arch ppc -O1 -Wuninitialized -c $P.c -o /dev/null 2> cand.warn" 
scp -q G5:$R/cand.dis /tmp/q.cand.$P.dis; scp -q G5:$R/cand.warn /tmp/q.cand.$P.warn
python3 Tools/userspace/unmap_names.py $B/namemap.tsv /tmp/q.cand.$P.dis /tmp/q.cand.$P.warn 2>/dev/null
python3 Tools/userspace/split_equiv.py $B/base.$P.dis /tmp/q.cand.$P.dis $B/base.$P.warn /tmp/q.cand.$P.warn 2>&1 | cut -c1-200 | tail -${2:-8}
