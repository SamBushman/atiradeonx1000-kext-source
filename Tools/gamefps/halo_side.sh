#!/bin/sh
# halo_side.sh SIDE [IMG]   (dev machine) - ONLY the Halo section of final_eval_side.sh: 800x600 high and 640x480 low, 3 runs each, on the CURRENT boot of the G5.
# Used to re-run Halo with a fixed userspace set without repeating UT2004 / Doom 3 (issue #235). SIDE = result label (e.g. Ufix), IMG = userspace image set (~/rung3/ut_env_IMG), empty = stock userspace.
# Results: ~/g5logs/final_eval/gamefps/halo_<SIDE>/, log side_<SIDE>.log ("ALL DONE SIDE=<SIDE>" at the end). If a run reports `NO Timedemo.txt`, check ~/Library/Logs/CrashReporter/Halo.crash.log on the G5.
SIDE=${1:?SIDE}; IMG=${2:-}; R=$HOME/g5logs/final_eval/gamefps; L=$R/side_$SIDE.log
mkdir -p $R/halo_$SIDE
echo "$(date +%H:%M) start SIDE=$SIDE IMG=$IMG (Halo only)" >> "$L"
for cfg in "800x600 high" "640x480 low"; do set -- $cfg
  timeout 3000 ssh G5 "cd \$HOME/rung3/gamefps && HALO_ENV=$IMG GI=\$HOME/rung3/gui_input sh halo_run_side.sh ${SIDE}_$2 $1 $2 3" >> "$L" 2>&1
done
scp -q -r "G5:rung3/gamefps/halo/${SIDE}_*" $R/halo_$SIDE/ >> "$L" 2>&1
ssh G5 "uptime; kextstat | grep -i ATIRadeonX1000; ls -l /Library/Logs/panic.log; ls -l ~/Library/Logs/CrashReporter/Halo.crash.log" > $R/halo_$SIDE/driver.txt 2>&1
echo "$(date +%H:%M) halo done; ALL DONE SIDE=$SIDE" >> "$L"
