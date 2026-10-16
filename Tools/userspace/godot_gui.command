#!/bin/sh
# usage (run from inside the Aqua session, e.g. via `open -a Terminal`): godot_gui.command TAG
# PROJ defaults to the autopilot copy ~/rung3/squash_play: the real game kills an idle player in ~1 s.
# Runs the Godot game, then the editor, 40 s (game) / 100 s (editor, slow to load) under the opcode recorder, screenshotting at 25 s.
R=$HOME/rung3; PROJ=${PROJ:-$HOME/rung3/squash_play}; T=${1:-run}; O=$R/gd_$T; rm -rf $O; mkdir -p $O
for m in game editor; do
  if [ $m = game ]; then set -- --path "$PROJ" Main.tscn; else set -- -e --path "$PROJ"; fi
  DYLD_INSERT_LIBRARIES=$R/rec.dylib OPCODE_LOG=$O/$m.tsv $R/godot_bin "$@" > $O/$m.out 2>&1 < /dev/null &
  pid=$!; i=0; L=40; [ $m = editor ] && L=100
  while kill -0 $pid 2>/dev/null && [ $i -lt $L ]; do sleep 1; i=`expr $i + 1`; [ $i = 12 ] && screencapture -x $O/${m}_12.png; [ $i = 28 ] && screencapture -x $O/${m}_28.png; [ $i = 60 ] && screencapture -x $O/${m}_60.png; [ $i = 95 ] && screencapture -x $O/${m}_95.png; done
  alive=no; kill -0 $pid 2>/dev/null && alive=yes
  kill $pid 2>/dev/null; sleep 3; kill -9 $pid 2>/dev/null
  echo "$m ran ${i}s alive_at_end=$alive" >> $O/summary.txt
done
echo DONE >> $O/summary.txt
