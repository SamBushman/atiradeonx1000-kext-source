#!/bin/sh
# godot_fps_compare.sh OUTDIR [VISITS=3] [SECS=90] [SEQ="stock rebuilt"] (dev machine): interleaved hot-swap A B A B, each visit = swap + unstick + killall Dock + settle + Godot game under the recorder
# (Tools/godot_fps.command inside the Aqua session). env: REBUILT_DIR STOCK_DIR SRC (G5 source tree under ~/rung3, for the unstick script) REBUILT_ENV (shell lines written to ~/rung3/gd_env for the rebuilt side only; stock side gets an empty file). Analyse each game.tsv with Tools/frame_rate_from_log.py. Records the loaded binary's md5 per visit.
O=${1:?outdir}; V=${2:-3}; SECS=${3:-90}; SEQ=${4:-"stock rebuilt"}; RB=${REBUILT_DIR:-kext_build_fix}; ST=${STOCK_DIR:-stockkext}; SRC=${SRC:-srchead}; mkdir -p "$O"
v=1
while [ $v -le $V ]; do
  for tag in $SEQ; do
    if [ $tag = stock ]; then D=$ST; else D=$RB; fi
    timeout 100 ssh G5 "sh \$HOME/rung3/swap.sh $D 2>&1 | tail -1; sh \$HOME/rung3/$SRC/Tools/issue157_unstick_hotswap/unstick_hotswap_vram.sh 2>&1 | tail -1; killall Dock; md5 -r \$HOME/rung3/$D/ATIRadeonX1000.kext/Contents/MacOS/ATIRadeonX1000; ls -l /Library/Logs/panic.log" >> "$O/driver.log" 2>&1 || { echo "swap FAILED v$v $tag" >> "$O/driver.log"; exit 1; }
    sleep 60
    b=${tag}_v$v
    GE=""; [ $tag = rebuilt ] && GE="$REBUILT_ENV"
    printf '%s\n' "$GE" > "$O/gd_env.$tag"; scp -q "$O/gd_env.$tag" G5:rung3/gd_env
    timeout 60 ssh G5 "echo $b $SECS > \$HOME/rung3/gd_tag; rm -rf \$HOME/rung3/gd_$b; open -a Terminal \$HOME/rung3/godot_fps.command"
    n=0; until timeout 20 ssh G5 "grep -q DONE \$HOME/rung3/gd_$b/summary.txt" 2>/dev/null; do sleep 10; n=$((n+1)); [ $n -gt $((SECS/10+30)) ] && { echo "timeout $b" >> "$O/driver.log"; break; }; done
    mkdir -p "$O/$b"; scp -q G5:rung3/gd_$b/* "$O/$b/" 2>> "$O/driver.log"
    timeout 30 ssh G5 "killall Godot 2>/dev/null; true" >/dev/null 2>&1
  done
  v=$((v+1))
done
echo "done: $O" >> "$O/driver.log"
