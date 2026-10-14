#!/bin/sh
# perf_2d_compare.sh (dev machine) - back-to-back desktop-compositing + WindowServer-gesture comparison, stock vs rebuilt, in the SAME hot-swap + unstick state (see Tests/performance_plan.md section 8:
# swap state alone moves 2D numbers ~1.6x, so the kexts are interleaved A B A B and each is run RUNS times per visit). Hot-swap only. No other GUI consumer may be running.
#   sh Tools/perf_2d_compare.sh OUTDIR [RUNS=2] [REBUILT_DIR=kext_build_fix] [STOCK_DIR=stockkext]      (dirs are under ~/rung3 on the G5)
O=${1:?outdir}; RUNS=${2:-2}; RB=${3:-kext_build_fix}; ST=${4:-stockkext}; mkdir -p "$O"
for visit in 1 2; do
  for tag in stock rebuilt; do
    if [ $tag = stock ]; then D=$ST; else D=$RB; fi
    timeout 100 ssh G5 "sh \$HOME/rung3/swap.sh $D 2>&1 | tail -1; sh \$HOME/rung3/srchead/Tools/issue157_unstick_hotswap/unstick_hotswap_vram.sh 2>&1 | tail -1" || exit 1
    sleep 20      # WindowServer / Dock settle after the forced mode set
    r=1; while [ $r -le $RUNS ]; do
      f=${tag}_v${visit}_r${r}.txt
      timeout 600 ssh G5 "OUTFILE=\$HOME/rung3/$f sh \$HOME/rung3/gest2d.sh" >/dev/null 2>&1 || echo "run $f FAILED"
      scp -q G5:rung3/$f "$O/$f"; r=$((r+1)); sleep 10
    done
  done
done
echo "done: $O"
