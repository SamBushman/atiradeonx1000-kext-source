#!/bin/sh
# final_eval_side.sh SIDE [IMG]   (dev machine) - the three real-game benchmarks (UT2004, Doom 3, Halo) on the CURRENT boot of the G5, one SIDE label (stock | U | K | KU), optional userspace image IMG
# (the set whose ~/rung3/ut_env_IMG exists; empty = stock userspace). Results: ~/g5logs/final_eval/gamefps/{ut2004,doom3,halo_<SIDE>}. ONE kext per boot, no kext swapping (user rule Oct 21).
# Pre: ~/rung3/gamefps scripts deployed (Tools/gamefps/*), console logged in at 1920x1080, nothing else running on the G5. For SIDE with a KU/U userspace the compositor stays stock here unless ku_env was set separately.
# Time: UT2004 ~30-40 min, Doom 3 ~20-30 min, Halo ~15-20 min.
SIDE=${1:?SIDE}; IMG=${2:-}; T=$(dirname "$0"); R=$HOME/g5logs/final_eval/gamefps; mkdir -p "$R"; L=$R/side_$SIDE.log
echo "$(date +%H:%M) start SIDE=$SIDE IMG=$IMG" >> "$L"
GAME_ENV=$IMG sh $T/ut2004_run_side.sh $R/ut2004 $SIDE 3 60 >> "$L" 2>&1; echo "$(date +%H:%M) ut2004 done" >> "$L"
GAME_ENV=$IMG sh $T/doom3_run_side.sh $R/doom3 $SIDE 3 >> "$L" 2>&1; echo "$(date +%H:%M) doom3 done" >> "$L"
mkdir -p $R/halo_$SIDE
for cfg in "800x600 high" "640x480 low"; do set -- $cfg
  timeout 3000 ssh G5 "cd \$HOME/rung3/gamefps && HALO_ENV=$IMG GI=\$HOME/rung3/gui_input sh halo_run_side.sh ${SIDE}_$2 $1 $2 3" >> "$L" 2>&1
done
scp -q -r "G5:rung3/gamefps/halo/${SIDE}_*" $R/halo_$SIDE/ >> "$L" 2>&1
ssh G5 "uptime; kextstat | grep -i ATIRadeonX1000; ls -l /Library/Logs/panic.log" > $R/halo_$SIDE/driver.txt 2>&1
echo "$(date +%H:%M) halo done; ALL DONE SIDE=$SIDE" >> "$L"
