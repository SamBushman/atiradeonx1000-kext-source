#!/bin/sh
# perf_gl_userspace_compare.sh OUTDIR [VISITS=3] (dev machine): interleaved hot-swap A B A B, each visit = swap + unstick + killall Dock + settle + the five Tests/userspace/perf_gl_* programs.
# Output: OUTDIR/{stock,rebuilt}/run<k>_methods.txt (METRIC lines of all five), readable with Tools/perf_compare.py OUTDIR/stock OUTDIR/rebuilt. env: REBUILT_DIR STOCK_DIR SRC (G5 source tree under ~/rung3)
O=${1:?outdir}; V=${2:-3}; RB=${REBUILT_DIR:-kext_build_fix}; ST=${STOCK_DIR:-stockkext}; SRC=${SRC:-srchead}
mkdir -p "$O/stock" "$O/rebuilt"; v=1
while [ $v -le $V ]; do
  for tag in stock rebuilt; do
    if [ $tag = stock ]; then D=$ST; else D=$RB; fi
    timeout 100 ssh G5 "sh \$HOME/rung3/swap.sh $D 2>&1 | tail -1; sh \$HOME/rung3/$SRC/Tools/issue157_unstick_hotswap/unstick_hotswap_vram.sh 2>&1 | tail -1; killall Dock; true" >> "$O/driver.log" 2>&1 || { echo "swap FAILED v$v $tag" >> "$O/driver.log"; exit 1; }
    sleep 60
    for p in features pipeline scale statechange upload; do
      timeout 900 ssh G5 "cd \$HOME/rung3/$SRC/Tests/userspace && ./perf_gl_$p" >> "$O/$tag/run${v}_methods.txt" 2>> "$O/driver.log" || echo "perf_gl_$p $tag v$v rc=$?" >> "$O/driver.log"
    done
    : > "$O/$tag/run${v}_gl.txt"
  done
  v=$((v+1))
done
echo "done: $O" >> "$O/driver.log"
