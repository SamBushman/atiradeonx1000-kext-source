#!/bin/sh
# video_fresh_boots.sh OUTROOT: QuickTime Player and VLC under the passive IOKit recorder (Tools/video_consumer_compare.sh), each side from a FRESH BOOT (boot-time stock, then rebuilt hot-swapped); ends with a reboot to stock.
O=${1:?outroot}; mkdir -p "$O"
reboot_wait() { ssh G5 'sudo reboot' > /dev/null 2>&1; sleep 90; until ssh -o ConnectTimeout=5 G5 'uptime' > /dev/null 2>&1; do sleep 10; done; sleep 30; }
for side in ${SIDES:-boot rebuilt}; do
  reboot_wait; echo "$side: booted $(date)" >> "$O/sides.log"
  scp -q "$(dirname "$0")/userspace/va_capture/auto_play.command" G5:rung3/va_cap/auto_play.command
  SEQ=$side JOBS=${JOBS:-"quicktime|\$HOME/rung3/va_cap/streams/test_ntsc_720x480.mpg|20 vlc|\$HOME/rung3/va_cap/streams/test_ntsc_dvd.vob|30"} sh "$(dirname "$0")/video_consumer_compare.sh" "$O/$side"
done
reboot_wait; echo "final reboot done $(date)" >> "$O/sides.log"; echo "done" >> "$O/sides.log"
