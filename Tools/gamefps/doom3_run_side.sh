#!/bin/sh
# doom3_run_side.sh OUTDIR SIDE [ROUNDS=3] [RESOLUTIONS="1920x1080 1024x768"] [PRESETS="high low"] [DEMOS="demo1"]  (dev machine)
# Runs the Doom 3 timedemo benchmark (dhewm3 built for PPC Tiger on the G5, see Tests/gamefps/doom3/) on the CURRENT boot; SIDE labels the driver that is booted.
# No kext swapping (same one-side-per-boot method as ut2004_run_side.sh). Always r_useVertexBuffers 0: with VBOs on, the first glBufferSubData wedges the stock driver.
# Only demo1 exists in the retail data (pak000 demos/demo1.demo); timeDemoQuit with a missing demo drops to the main menu.
# Pass = `timeDemoQuit DEMO` at a fixed resolution (fullscreen), vsync off, sound off; presets are explicit cvars so both sides get identical settings.
# Results: OUTDIR/SIDE_r<round>/<res>_<preset>_<demo>/out.txt ; report with Tools/game_fps_report_d3.py OUTDIR.
O=${1:?outdir}; SIDE=${2:?side}; V=${3:-3}; RES=${4:-"1920x1080 1024x768"}; PRESETS=${5:-"high low"}; DEMOS=${6:-"demo1"}; mkdir -p "$O"
common="+set r_fullscreen 1 +set r_mode -1 +set r_swapInterval 0 +set r_useVertexBuffers 0 +set com_showFPS 0"
high="+set image_anisotropy 8 +set image_downSize 0 +set image_useCompression 0"
low="+set image_anisotropy 1 +set image_downSize 1 +set image_downSizeLimit 128 +set image_downSizeBump 1 +set image_downSizeSpecular 1 +set image_useCompression 1"
runpass() { # tag secs args
  timeout 60 ssh G5 "echo $1 $2 $3 > \$HOME/gamefps/d3_tag; rm -rf \$HOME/gamefps/doom3/$1; open -a Terminal \$HOME/gamefps/doom3_bench.command"
  n=0; until timeout 20 ssh G5 "grep -q DONE \$HOME/gamefps/doom3/$1/summary.txt" 2>/dev/null; do sleep 10; n=$((n+1)); [ $n -gt $(($2/10+12)) ] && { echo "timeout $1" >> "$O/driver.log"; return 1; }; done
  return 0
}
timeout 60 ssh G5 "uptime; kextstat | grep -i ATIRadeonX1000; md5 -r /System/Library/Extensions/ATIRadeonX1000.kext/Contents/MacOS/ATIRadeonX1000; ls -l /Library/Logs/panic.log" > "$O/$SIDE.driver" 2>&1
sleep 20
r=1
while [ $r -le $V ]; do
  for res in $RES; do w=${res%x*}; h=${res#*x}; for p in $PRESETS; do for d in $DEMOS; do
    if [ $p = high ]; then pa="$high"; else pa="$low"; fi
    t=${SIDE}_r${r}_${res}_${p}_${d}; b=${SIDE}_r$r/${res}_${p}_${d}
    runpass $t 420 "$common +set r_customWidth $w +set r_customHeight $h $pa +timeDemoQuit $d" || { echo "ABORT: pass $t did not finish (possible GPU wedge); not continuing" >> "$O/driver.log"; exit 1; }
    mkdir -p "$O/$b"; scp -q G5:gamefps/doom3/$t/* "$O/$b/" 2>> "$O/driver.log"
    echo "$b: $(grep -a 'frames rendered' "$O/$b/out.txt" | tail -1)" >> "$O/driver.log"
  done; done; done
  r=$((r+1))
done
timeout 30 ssh G5 "ls -l /Library/Logs/panic.log; kextstat | grep X1000" >> "$O/$SIDE.driver" 2>&1
echo "done $SIDE: $O" >> "$O/driver.log"
