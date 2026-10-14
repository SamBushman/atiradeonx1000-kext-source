#!/bin/sh
# gest2d.sh (G5, run via foreground ssh): open a disposable Finder window, run the compositing + WindowServer-gesture scenarios, close it. Output -> ~/rung3/gest2d_<time>.txt
O=$HOME/rung3/gest2d_`date +%H%M%S`.txt
osascript -e 'tell application "Finder" to make new Finder window' -e 'tell application "Finder" to set bounds of front window to {100,100,700,500}' >/dev/null 2>&1
sleep 3
$HOME/rung3/srchead/Tests/perf_2d_compositing 80 16000 > $O 2>&1
osascript -e 'tell application "Finder" to close every window' >/dev/null 2>&1
echo $O
