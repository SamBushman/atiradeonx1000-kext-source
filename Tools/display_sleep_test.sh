#!/bin/sh
# display_sleep_test.sh OUTDIR SIDE [CYCLES=3] (dev machine): DISPLAY sleep/wake only (no system sleep: that hangs the stock stack, #180). SIDE = boot | rebuilt (rebuilt hot-swapped + unstick + settle).
# Per cycle: parity harness + screenshot before; `pmset displaysleep 1` and wait ~80 s for the display to sleep; wake with a synthetic mouse event (Tools/gui_input.c); then kext identity, panic.log, parity harness, screenshot after.
O=${1:?outdir}; SIDE=${2:?boot|rebuilt}; CY=${3:-3}; RB=${REBUILT_DIR:-kext_build_fix}; mkdir -p "$O"
if [ $SIDE = rebuilt ]; then
  timeout 100 ssh G5 "sh \$HOME/rung3/swap.sh $RB 2>&1 | tail -1; sh \$HOME/rung3/srchead/Tools/issue157_unstick_hotswap/unstick_hotswap_vram.sh 2>&1 | tail -1; killall Dock; md5 -r \$HOME/rung3/$RB/ATIRadeonX1000.kext/Contents/MacOS/ATIRadeonX1000" >> "$O/log.txt" 2>&1; sleep 45
fi
c=1
while [ $c -le $CY ]; do
  echo "== cycle $c $(date +%T)" >> "$O/log.txt"
  timeout 200 ssh G5 "cd \$HOME/rung3/srchead/Tests && ./parity_test_harness > \$HOME/rung3/ds_pre.txt 2>&1; echo pre_harness_rc=\$?; screencapture -x \$HOME/rung3/ds_pre.png; sudo pmset displaysleep 1; echo set" >> "$O/log.txt" 2>&1
  sleep 85
  timeout 30 ssh G5 "echo alive_during_display_sleep; ioreg -l -w0 | grep -A4 \"+-o IODisplayWrangler\" | grep \"Power Management protected data\" | grep -o -E \"myCurrentState = [0-9]+\" | head -3" >> "$O/log.txt" 2>&1 || echo "G5 UNREACHABLE during display sleep" >> "$O/log.txt"
  timeout 30 ssh G5 "\$HOME/rung3/gui_input click 960 540; sleep 1; \$HOME/rung3/gui_input click 962 542" >> "$O/log.txt" 2>&1; sleep 6
  timeout 200 ssh G5 "sudo pmset displaysleep 0; screencapture -x \$HOME/rung3/ds_post.png; kextstat | grep ATIRadeonX1000; ls -l /Library/Logs/panic.log; cd \$HOME/rung3/srchead/Tests && ./parity_test_harness > \$HOME/rung3/ds_post.txt 2>&1; echo post_harness_rc=\$?; diff \$HOME/rung3/ds_pre.txt \$HOME/rung3/ds_post.txt | wc -l" >> "$O/log.txt" 2>&1
  scp -q G5:rung3/ds_pre.png "$O/cycle${c}_pre.png"; scp -q G5:rung3/ds_post.png "$O/cycle${c}_post.png"
  c=$((c+1))
done
echo done >> "$O/log.txt"
