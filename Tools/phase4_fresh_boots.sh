#!/bin/sh
# phase4_fresh_boots.sh OUTROOT (dev machine): runbook Phase 4 in one go, each side from a FRESH BOOT: sides boot (boot-time stock kext + stock userspace), K (rebuilt kext hot-swapped + unstick, stock userspace), KU (K + the rebuilt userspace:
# WindowServer relaunched by hand with the rebuilt GA / GLDriver / VADriver redirect (Tools/userspace/ws_relaunch_ku.sh), every consumer started with the same environment through $HOME/rung3/side_env).
# Per boot, in this order: installed-application sweep, video (QuickTime, VLC), display sleep, DVD Player on the generated disc LAST (one side per boot, #190). Ends with a reboot to the stock boot state.
# env: SHA IMG (G5 tree src_<SHA>, images us_<IMG>/gld_<IMG>) REBUILT_DIR (kext_build_<sha>) SIDES (default "boot K KU") SECS_DVD (60). Evidence: OUTROOT/<side>/{sweep,video,dsleep,dvd,proof}.
O=${1:?outroot}; SHA=${SHA:?SHA}; IMG=${IMG:-$SHA}; RB=${REBUILT_DIR:?REBUILT_DIR}; SECS_DVD=${SECS_DVD:-60}; T=$(cd "$(dirname "$0")" && pwd); mkdir -p "$O"
. "$T/reboot_wait.sh"
R=\$HOME/rung3
for side in ${SIDES:-boot K KU}; do
  D="$O/$side"; mkdir -p "$D/proof"
  reboot_wait; echo "$side: booted $(date)" >> "$O/sides.log"
  scp -q "$T/app_sweep.command" "$T/side_launch.command" "$T/userspace/ws_relaunch_ku.sh" G5:rung3/
  scp -q "$T"/userspace/va_capture/play_with_recorder_*.command "$T/userspace/va_capture/auto_play.command" G5:rung3/va_cap/
  ssh G5 "chmod +x $R/side_launch.command $R/app_sweep.command; : > $R/side_env; rm -f $R/side_launch_app $R/side_launch_done; kextstat | grep ATIRadeonX1000" > "$D/proof/boot_kext.txt" 2>&1
  SIDE_LAUNCH=0
  if [ $side != boot ]; then
    timeout 100 ssh G5 "sh $R/swap.sh $RB 2>&1 | tail -1; sh $R/src_$SHA/Tools/issue157_unstick_hotswap/unstick_hotswap_vram.sh 2>&1 | tail -1; killall Dock; md5 -r $R/$RB/ATIRadeonX1000.kext/Contents/MacOS/ATIRadeonX1000; kextstat | grep ATIRadeonX1000" > "$D/proof/swap.txt" 2>&1 || { echo "$side: swap FAILED $(date)" >> "$O/sides.log"; exit 1; }
    sleep 30
  fi
  if [ $side = KU ]; then
    SIDE_LAUNCH=1
    timeout 120 ssh G5 "sh $R/ws_relaunch_ku.sh $IMG $SHA" > "$D/proof/ws_relaunch.txt" 2>&1 < /dev/null
    grep -q "ATIRadeonX1000GA.*redirected to" "$D/proof/ws_relaunch.txt" || { echo "KU: WindowServer did not map the rebuilt GA $(date)" >> "$O/sides.log"; exit 1; }
    cat > "$D/proof/side_env.local" <<EOE
export GLD_REDIRECT_MAP=ATIRadeonX1000GLDriver=\$HOME/rung3/gld_$IMG/gld_link/ATIRadeonX1000GLDriver_renamed,ATIRadeonX1000GA=\$HOME/rung3/us_$IMG/ga/ATIRadeonX1000GA,ATIRadeonX1000VADriver=\$HOME/rung3/us_$IMG/va/ATIRadeonX1000VADriver
export DYLD_LIBRARY_PATH=\$HOME/rung3/final_eval/dyld_dir_$IMG
SIDE_INSERT=\$HOME/rung3/src_$SHA/Tools/userspace/gld_redirect.dylib
EOE
    scp -q "$D/proof/side_env.local" G5:rung3/side_env
    ssh G5 "screencapture -x $R/ku_after_ws.png" >> "$D/proof/ws_relaunch.txt" 2>&1 < /dev/null
    sleep 30
  fi
  scp -q G5:rung3/side_env "$D/proof/side_env.txt" 2>/dev/null; scp -q G5:rung3/ku_after_ws.png "$D/proof/" 2>/dev/null
  APPS=${APPS:-"30|/Applications/Srb2mac.app 30|/Applications/Half-Life_10.4_Tiger-SDL2.app 40|/Applications/Unreal Tournament 2004.app 30|/Applications/Aquaria.app 30|/Applications/VVVVVV.app 30|/Applications/Marathon.app 40|/Applications/Motion.app 30|/Developer/Applications/Graphics Tools/Quartz Composer.app 30|/Applications/Godot.app"}
  echo "$APPS" | sed 's/ \([0-9][0-9]*|\/\)/\n\1/g' | { set --; while IFS= read -r l; do set -- "$@" "$l"; done; SEQ=boot sh "$T/app_sweep.sh" "$D/sweep" "$@"; }
  SEQ=boot JOBS="quicktime|\$HOME/rung3/va_cap/streams/test_ntsc_720x480.mpg|20 vlc|\$HOME/rung3/va_cap/streams/test_ntsc_dvd.vob|30" sh "$T/video_consumer_compare.sh" "$D/video"
  sh "$T/display_sleep_test.sh" "$D/dsleep" boot 3
  SEQ=boot SIDE_LAUNCH=$SIDE_LAUNCH sh "$T/dvd_disc_compare.sh" "$D/dvd" $SECS_DVD
  for f in side_launch_redirect.log side_launch_dyld.txt; do scp -q G5:rung3/$f "$D/proof/" 2>/dev/null; done
  ssh G5 "cp /Users/Shared/ws_ku_redirect.log $R/final_eval/ws_ku_redirect_$side.log 2>/dev/null; true" >/dev/null 2>&1; scp -q G5:/Users/Shared/ws_ku_redirect.log "$D/proof/ws_redirect_after.log" 2>/dev/null
  echo "$side: done $(date)" >> "$O/sides.log"
done
reboot_wait; echo "final reboot done $(date)" >> "$O/sides.log"; echo "done" >> "$O/sides.log"
