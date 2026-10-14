#!/bin/sh
# usage (run from inside the Aqua session, e.g. via `open -a Terminal`): godot_gui.command TAG
# Runs the Godot game, then the editor, 40 s each under the opcode recorder, screenshotting at 25 s.
R=$HOME/rung3; T=${1:-run}; O=$R/gd_$T; rm -rf $O; mkdir -p $O
for m in game editor; do
  if [ $m = game ]; then set -- --path $R/squash Main.tscn; else set -- -e --path $R/squash; fi
  DYLD_INSERT_LIBRARIES=$R/rec.dylib OPCODE_LOG=$O/$m.tsv $R/godot_bin "$@" > $O/$m.out 2>&1 < /dev/null &
  pid=$!; i=0
  while kill -0 $pid 2>/dev/null && [ $i -lt 40 ]; do sleep 1; i=`expr $i + 1`; [ $i = 25 ] && screencapture -x $O/$m.png; done
  alive=no; kill -0 $pid 2>/dev/null && alive=yes
  kill $pid 2>/dev/null; sleep 3; kill -9 $pid 2>/dev/null
  echo "$m ran ${i}s alive_at_end=$alive" >> $O/summary.txt
done
echo DONE >> $O/summary.txt
