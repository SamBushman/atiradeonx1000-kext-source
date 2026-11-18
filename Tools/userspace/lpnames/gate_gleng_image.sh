#!/bin/sh
# gate_agent.sh WORKTREE TAG : build the GLEngine image of WORKTREE on the G5 (tag nma_TAG), compare with the base image
# (HEAD 071b6bfe, G5 ~/rung3/gleng_nmc_p1) : function instruction sequences, data section, symbol table.
# Prints a final line  VERDICT: IDENTICAL  (0 instruction diffs, data identical, nm identical) or the problems.
export BUILD_JOBS=${BUILD_JOBS:-4}; WT=$1; TAG=$2; V=$HOME/g5logs/fnf_237/vn; OUT=$V/agent_$TAG; mkdir -p $OUT
cd $WT || exit 2
IMG_TAG=nma_$TAG timeout 1200 sh Tools/userspace/build_gleng_image.sh G5 $OUT/ev > $OUT/build.log 2>&1 || { echo "VERDICT: BUILD-FAILED (see $OUT/build.log)"; tail -5 $OUT/build.log; exit 1; }
ssh G5 "cd ~/rung3 && mkdir -p vn_cmp_a_$TAG && d=gleng_nma_$TAG/gleng_link/GLEngine_rebuilt && otool -tV \$d | tail -n +2 > vn_cmp_a_$TAG/t.txt && otool -dV \$d | tail -n +2 > vn_cmp_a_$TAG/d.txt && nm -n \$d > vn_cmp_a_$TAG/n.txt && cmp vn_cmp_a_$TAG/d.txt vn_cmp_p1/dc.txt && echo DATA-IDENTICAL; cmp vn_cmp_a_$TAG/n.txt vn_cmp_p1/nc.txt && echo NM-IDENTICAL" > $OUT/g5cmp.txt 2>&1
ssh G5 "cat ~/rung3/vn_cmp_a_$TAG/t.txt" > $OUT/t.dis
cd $HOME/atiradeonx1000-kext-source && python3 Tools/userspace/image_function_diff.py $V/cmp/p1_tc.dis $OUT/t.dis > $OUT/fdiff.txt 2>&1
head -1 $OUT/fdiff.txt; cat $OUT/g5cmp.txt
if grep -q 'only in old 0, only in new 0, instruction sequence differs in 0' $OUT/fdiff.txt && grep -q DATA-IDENTICAL $OUT/g5cmp.txt && grep -q NM-IDENTICAL $OUT/g5cmp.txt; then echo "VERDICT: IDENTICAL"; else echo "VERDICT: DIFFERENT (see $OUT/fdiff.txt $OUT/g5cmp.txt)"; fi
ssh G5 "rm -rf ~/rung3/gleng_nma_$TAG ~/rung3/gleng_nma_$TAG.tgz ~/rung3/vn_cmp_a_$TAG"
