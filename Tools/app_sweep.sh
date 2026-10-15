#!/bin/sh
# app_sweep.sh OUTDIR "SECS|/Applications/X.app" ... (dev machine): for each app, on BOTH kexts (stock then rebuilt hot-swap, same swap+unstick state each), run Tools/app_sweep.command and fetch the evidence.
# Kernel-health record per run: panic.log size, kextstat line, hwup via uptime. Env: SEQ="stock rebuilt", REBUILT_DIR, STOCK_DIR, SETTLE (45).
O=${1:?outdir}; shift; SEQ=${SEQ:-"stock rebuilt"}; RB=${REBUILT_DIR:-kext_build_fix}; ST=${STOCK_DIR:-stockkext}; SETTLE=${SETTLE:-45}; mkdir -p "$O"
for tag in $SEQ; do
  if [ $tag = stock ]; then D=$ST; else D=$RB; fi
  timeout 100 ssh G5 "sh \$HOME/rung3/swap.sh $D 2>&1 | tail -1; sh \$HOME/rung3/srchead/Tools/issue157_unstick_hotswap/unstick_hotswap_vram.sh 2>&1 | tail -1; killall Dock; md5 -r \$HOME/rung3/$D/ATIRadeonX1000.kext/Contents/MacOS/ATIRadeonX1000" >> "$O/driver.log" 2>&1 || { echo "swap FAILED $tag" >> "$O/driver.log"; exit 1; }
  sleep $SETTLE
  for spec in "$@"; do
    secs=${spec%%|*}; app=${spec#*|}; name=`basename "$app" .app | tr -c 'A-Za-z0-9\n' _`; b=${tag}_$name
    timeout 60 ssh G5 "echo '$b $secs $app' > \$HOME/rung3/sweep_tag; rm -rf \$HOME/rung3/sw_$b; open -a Terminal \$HOME/rung3/app_sweep.command"
    n=0; until timeout 20 ssh G5 "grep -q DONE \$HOME/rung3/sw_$b/summary.txt" 2>/dev/null; do sleep 5; n=$((n+1)); [ $n -gt $((secs/5+40)) ] && { echo "timeout $b" >> "$O/driver.log"; break; }; done
    mkdir -p "$O/$b"; scp -q G5:rung3/sw_$b/* "$O/$b/" 2>> "$O/driver.log"
    timeout 60 ssh G5 "echo \"$b panic=\$(ls -l /Library/Logs/panic.log | awk '{print \$5}') up=\$(uptime | sed 's/,.*//') \$(kextstat | grep -c com.apple.ATIRadeonX1000)\"" >> "$O/health.txt" 2>&1
    sleep 5
  done
done
echo "done: $O" >> "$O/driver.log"
