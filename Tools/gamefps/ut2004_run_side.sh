#!/bin/sh
# ut2004_run_side.sh OUTDIR SIDE [VISITS=3] [SECS=60] [MAPS="DM-Antalus ONS-Torlan"] [PRESETS="high low"]  (dev machine)
# Runs the UT2004 built-in benchmark on the CURRENT boot of the G5: no kext swapping. SIDE is a label (stock | rebuilt) for the driver that was
# booted; record which is loaded (kextstat + installed-binary md5) into OUTDIR/SIDE.driver. One discarded warm-up pass, then VISITS rounds of
# MAP x PRESET passes (fixed RNG seed) through Tools/gamefps/ut2004_bench.command inside the Aqua session.
# Results: OUTDIR/<SIDE>_v<round>/<map>_<preset>/ ; run Tools/game_fps_report.py OUTDIR after both sides exist.
O=${1:?outdir}; SIDE=${2:?side}; V=${3:-3}; SECS=${4:-60}; MAPS=${5:-"DM-Antalus ONS-Torlan"}; PRESETS=${6:-"high low"}; SEED=${SEED:-453418555}; mkdir -p "$O"
runpass() { # tag map preset secs
  timeout 60 ssh G5 "echo $1 $2 $3 $4 $SEED 0 > \$HOME/rung3/ut_tag; rm -rf \$HOME/rung3/gamefps/ut2004/$1; open -a Terminal \$HOME/rung3/gamefps/ut2004_bench.command"
  n=0; until timeout 20 ssh G5 "grep -q DONE \$HOME/rung3/gamefps/ut2004/$1/summary.txt" 2>/dev/null; do sleep 10; n=$((n+1)); [ $n -gt $(($4/10+30)) ] && { echo "timeout $1" >> "$O/driver.log"; return 1; }; done
}
timeout 60 ssh G5 "uptime; kextstat | grep -i ATIRadeonX1000; md5 -r /System/Library/Extensions/ATIRadeonX1000.kext/Contents/MacOS/ATIRadeonX1000; ls -l /Library/Logs/panic.log" > "$O/$SIDE.driver" 2>&1
sleep 30
runpass warm_$SIDE DM-Antalus low 30   # discarded
timeout 30 ssh G5 "killall ut2004-bin 2>/dev/null; true" >/dev/null 2>&1
v=1
while [ $v -le $V ]; do
  for m in $MAPS; do for p in $PRESETS; do
    b=${SIDE}_v$v/${m}_$p; t=${SIDE}_v${v}_${m}_$p
    runpass $t $m $p $SECS || true
    mkdir -p "$O/$b"; scp -q G5:rung3/gamefps/ut2004/$t/* "$O/$b/" 2>> "$O/driver.log"
    timeout 30 ssh G5 "killall ut2004-bin 2>/dev/null; true" >/dev/null 2>&1
    echo "$b: $(tail -2 "$O/$b/avgfps.log" 2>/dev/null | tr '\n' ' ')" >> "$O/driver.log"
  done; done
  v=$((v+1))
done
timeout 30 ssh G5 "ls -l /Library/Logs/panic.log; kextstat | grep X1000" >> "$O/$SIDE.driver" 2>&1
echo "done $SIDE: $O" >> "$O/driver.log"
