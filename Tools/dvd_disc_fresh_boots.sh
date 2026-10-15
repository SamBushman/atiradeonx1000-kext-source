#!/bin/sh
# dvd_disc_fresh_boots.sh OUTROOT [SECS=60]: run Tools/dvd_disc_compare.sh once per side, each from a FRESH BOOT (the stock hot-swap panics in stop() when unloaded after DVD Player use, #179, so never swap after playback).
# Sides: boot (the boot-time stock driver, no swap) then rebuilt (hot-swapped over the clean boot-time stock). Ends with a reboot back to the stock boot state.
O=${1:?outroot}; S=${2:-60}; mkdir -p "$O"
reboot_wait() { ssh G5 'sudo reboot' > /dev/null 2>&1; sleep 90; until ssh -o ConnectTimeout=5 G5 'uptime' > /dev/null 2>&1; do sleep 10; done; sleep 30; }
for side in ${SIDES:-boot rebuilt}; do
  reboot_wait; echo "$side: booted $(date)" >> "$O/sides.log"
  SEQ=$side sh "$(dirname "$0")/dvd_disc_compare.sh" "$O/$side" $S
done
reboot_wait; echo "final reboot done $(date)" >> "$O/sides.log"; echo "done" >> "$O/sides.log"
