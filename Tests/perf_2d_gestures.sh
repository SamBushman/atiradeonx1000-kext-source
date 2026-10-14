#!/bin/sh
# perf_2d_gestures.sh (G5, run via FOREGROUND ssh; installed as ~/rung3/gest2d.sh): open a disposable Finder window on /usr/bin in list view (hundreds of rows, so the synthetic scroll has content),
# run the compositing + WindowServer-gesture scenarios, close it. Env: TICKS (default 200), OUTFILE (METRIC lines), RAW (per-tick dump, see perf_2d_compositing.c), WARMUP=1 (run once and discard).
O=${OUTFILE:-$HOME/rung3/gest2d_`date +%H%M%S`.txt}
osascript -e 'tell application "Finder" to make new Finder window to (POSIX file "/usr/bin" as alias)' -e 'tell application "Finder" to set current view of front window to list view' -e 'tell application "Finder" to set bounds of front window to {100,100,700,500}' >/dev/null 2>&1
sleep 3
if [ "$WARMUP" = 1 ]; then RAW= $HOME/rung3/srchead/Tests/perf_2d_compositing ${TICKS:-200} 16000 > /dev/null 2>&1; echo "warmup done" > $O; else
$HOME/rung3/srchead/Tests/perf_2d_compositing ${TICKS:-200} 16000 > $O 2>&1; fi
osascript -e 'tell application "Finder" to close every window' >/dev/null 2>&1
echo $O
