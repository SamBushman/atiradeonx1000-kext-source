#!/bin/sh
# sweep_fresh_boots.sh OUTROOT: installed-application sweep (Tools/app_sweep.sh) with each side from a FRESH BOOT (never swap after client use: #179). Sides: boot (boot-time stock, no swap), rebuilt (hot-swapped over the clean boot). Ends with a reboot to the stock boot state.
O=${1:?outroot}; mkdir -p "$O"
APPS=${APPS:-"30|/Applications/Srb2mac.app 30|/Applications/Half-Life_10.4_Tiger-SDL2.app 40|/Applications/Unreal Tournament 2004.app 30|/Applications/Aquaria.app 30|/Applications/VVVVVV.app 30|/Applications/Marathon.app 40|/Applications/Motion.app 30|/Developer/Applications/Graphics Tools/Quartz Composer.app 30|/Applications/Godot.app"}
. "$(dirname "$0")/reboot_wait.sh"
n=0
for side in ${SIDES:-boot rebuilt}; do
  n=$((n+1))
  reboot_wait; echo "$side: booted $(date)" >> "$O/sides.log"
  # APPS is split on the pattern "N|/path" with spaces inside paths, so feed the specs one per line
  echo "$APPS" | sed 's/ \([0-9][0-9]*|\/\)/\n\1/g' | { set --; while IFS= read -r l; do set -- "$@" "$l"; done; SEQ=$side sh "$(dirname "$0")/app_sweep.sh" "$O/$side" "$@"; }
  [ "${SIDES_NUMBERED:-0}" = 1 ] && mv "$O/$side" "$O/${n}_$side"
done
reboot_wait; echo "final reboot done $(date)" >> "$O/sides.log"; echo "done" >> "$O/sides.log"
