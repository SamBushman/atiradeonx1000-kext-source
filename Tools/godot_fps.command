#!/bin/sh
# godot_fps.command (runs on the G5 inside the Aqua session via `open -a Terminal`): run the Godot game under the opcode recorder for SECS seconds.
# Tag and duration come from $HOME/rung3/gd_tag ("TAG SECS"), because a .command cannot take arguments. Output: $HOME/rung3/gd_<TAG>/game.tsv (recorder log with FLUSH t_us), game.out, shot.png, DONE.
read TAG SECS < $HOME/rung3/gd_tag
O=$HOME/rung3/gd_$TAG; mkdir -p $O; rm -f $O/*
G="/Volumes/Test HD/godot-tiger-test/dist-tiger/Godot.app/Contents/MacOS/Godot"; PROJ="/Volumes/Test HD/squash_the_creeps_start"
R="$HOME/rung3/opcode_recorder.dylib"   # built from Tools/userspace/opcode_recorder.c on the G5 (the 2026-10-03 copy on Test HD predates the FLUSH t_us field)
DYLD_INSERT_LIBRARIES="$R" OPCODE_LOG="$O/game.tsv" "$G" --path "$PROJ" Main.tscn > "$O/game.out" 2>&1 < /dev/null &
pid=$!; i=0
while kill -0 $pid 2>/dev/null && [ $i -lt $SECS ]; do sleep 1; i=`expr $i + 1`; [ $i -eq 20 ] && screencapture -x $O/shot.png; done
kill $pid 2>/dev/null; sleep 3; kill -9 $pid 2>/dev/null
echo "ran ${i}s" > $O/summary.txt; echo DONE >> $O/summary.txt
