#!/bin/sh
# t3_watch_loop.sh OUTDIR     (dev machine, start with `setsid nohup sh Tools/t3_watch_loop.sh OUTDIR > /dev/null 2>&1 < /dev/null &`)
# Restart-loop watchdog for the reboot-heavy T3 phase: stability_watch.sh exits when the G5 reboots, so run one segment per boot (watch_t3_<n>.tsv/.out in OUTDIR). Stop with `touch OUTDIR/WATCH_STOP`.
# Always pass -d to stability_watch.sh: its default duration is 3600 s and it then exits with OK (Nov 7: a 4 h soak went unwatched for an hour that way).
O=${1:?outdir}; cd "$(dirname "$0")/.." || exit 2; mkdir -p "$O"; n=0
while [ ! -f "$O/WATCH_STOP" ]; do n=$((n+1)); sh Tools/stability_watch.sh -i 20 -d 3000 -l "$O/watch_t3_$n.tsv" G5 > "$O/watch_t3_$n.out" 2>&1; sleep 15; done
