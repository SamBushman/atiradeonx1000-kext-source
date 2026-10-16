#!/bin/sh
# perf_2d_compare.sh (dev machine) - back-to-back desktop-compositing + WindowServer-gesture comparison, stock vs rebuilt, in the SAME hot-swap + unstick state. Hot-swap only.
# Protocol: visits alternate stock/rebuilt (A B A B ...); each visit = hot-swap + unstick + killall Dock (clears stale Docks) + SETTLE s + quiesce check +
# one DISCARDED warm-up run + RUNS measured runs, each with a per-tick RAW dump. Per-run files: <tag>_v<visit>_r<run>.txt (METRIC lines), .raw (per tick), .quiesce (ps/load snapshot before the run).
#   sh Tools/perf_2d_compare.sh OUTDIR [RUNS=3] [VISITS=4] [TICKS=200] [SEQ="stock rebuilt"]    env: REBUILT_DIR (kext_build_fix) STOCK_DIR (stockkext) SETTLE (60)
# SEQ lets you run an A/A pilot ("stock stock") or a planted-difference control. Needs ~/rung3/gest2d.sh (Tests/perf_2d_gestures.sh) on the G5.
O=${1:?outdir}; RUNS=${2:-3}; VISITS=${3:-4}; TICKS=${4:-200}; SEQ=${5:-"stock rebuilt"}; RB=${REBUILT_DIR:-kext_build_fix}; ST=${STOCK_DIR:-stockkext}; SETTLE=${SETTLE:-60}
mkdir -p "$O"; echo "start $(date) runs=$RUNS visits=$VISITS ticks=$TICKS seq=$SEQ" >> "$O/driver.log"
visit=1
while [ $visit -le $VISITS ]; do
  for tag in $SEQ; do
    if [ $tag = stock ] || [ $tag = burn ]; then D=$ST; else D=$RB; fi
    if [ $tag = boot ]; then echo "boot: no swap (whatever driver the G5 booted with)" >> "$O/driver.log"; else
    timeout 100 ssh G5 "sh \$HOME/rung3/swap.sh $D 2>&1 | tail -1; sh \$HOME/rung3/srchead/Tools/issue157_unstick_hotswap/unstick_hotswap_vram.sh 2>&1 | tail -1; killall Dock; true" >> "$O/driver.log" 2>&1 || { echo "swap FAILED v$visit $tag" >> "$O/driver.log"; exit 1; }
    fi
    sleep $SETTLE
    # planted-difference control: BURN_TAGS="rebuilt" runs BURN_N CPU burners on the G5 during that side's warm-up and runs (the burner is the known difference)
    case " $BURN_TAGS " in *" $tag "*) timeout 30 ssh G5 "i=0; while [ \$i -lt ${BURN_N:-2} ]; do (nohup yes > /dev/null 2>&1 < /dev/null &); i=\$((i+1)); done; true" >> "$O/driver.log" 2>&1;; esac
    timeout 400 ssh G5 "WARMUP=1 OUTFILE=\$HOME/rung3/warm.txt TICKS=$TICKS sh \$HOME/rung3/gest2d.sh" > /dev/null 2>&1 || echo "warmup v$visit $tag FAILED" >> "$O/driver.log"
    sleep 10
    r=1; while [ $r -le $RUNS ]; do
      b=${tag}_v${visit}_r${r}
      timeout 60 ssh G5 "(uptime; ps -axco pcpu,command | sort -nr | head -6) > \$HOME/rung3/$b.quiesce 2>&1" 
      timeout 600 ssh G5 "RAW=\$HOME/rung3/$b.raw OUTFILE=\$HOME/rung3/$b.txt TICKS=$TICKS sh \$HOME/rung3/gest2d.sh" >/dev/null 2>&1 || echo "run $b FAILED" >> "$O/driver.log"
      for x in txt raw quiesce; do scp -q G5:rung3/$b.$x "$O/$b.$x"; done
      r=$((r+1)); sleep 10
    done
    timeout 30 ssh G5 "killall yes 2>/dev/null; true" > /dev/null 2>&1
  done
  timeout 30 ssh G5 "killall yes 2>/dev/null; true" > /dev/null 2>&1
  visit=$((visit+1))
done
echo "done: $O" | tee -a "$O/driver.log"
