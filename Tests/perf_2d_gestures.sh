#!/bin/sh
# gest2d.sh (G5, run via foreground ssh): open a disposable Finder window, run the compositing + WindowServer-gesture scenarios, close it. Output -> ~/rung3/gest2d_<time>.txt
O=${OUTFILE:-$HOME/rung3/gest2d_`date +%H%M%S`.txt}
osascript -e 'tell application "Finder" to make new Finder window to (POSIX file "/usr/bin" as alias)' -e 'tell application "Finder" to set current view of front window to list view' -e 'tell application "Finder" to set bounds of front window to {100,100,700,500}' >/dev/null 2>&1   # /usr/bin in list view: hundreds of rows, so the synthetic scroll has something to scroll
sleep 3
$HOME/rung3/srchead/Tests/perf_2d_compositing ${TICKS:-200} 16000 > $O 2>&1
osascript -e 'tell application "Finder" to close every window' >/dev/null 2>&1
echo $O
