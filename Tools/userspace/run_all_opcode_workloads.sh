#!/bin/sh
# run_all_opcode_workloads.sh - issue #42: the whole opcode-coverage battery in one go, ON the G5, safe workloads only (the hazardous glstress / window fastclear modes are NOT included).
#   sh run_all_opcode_workloads.sh OUTDIR        (needs opcode_recorder.dylib, glcov, glwin, the runner scripts in the current directory; Godot paths as on this G5)
# Order: small probes, offscreen features, windows (plain / multisample / depth / clear / resolve), then the Godot game and editor for 40 s each. Each runner stops at its own first crash or hang;
# this script continues with the next group regardless and writes OUTDIR/groups.txt.
O=${1:?usage: sh run_all_opcode_workloads.sh OUTDIR}; mkdir -p "$O"; P="`pwd`"; G="/Volumes/Test HD/godot-tiger-test/dist-tiger/Godot.app/Contents/MacOS/Godot"; PROJ="/Volumes/Test HD/squash_the_creeps_start"; : > "$O/groups.txt"
sh run_opcode_workloads.sh "$O/probes" > "$O/probes.log" 2>&1; echo "probes: done" >> "$O/groups.txt"
sh run_gl_features.sh "$O/features" multitex texfmt fbo fbo2 query clear state draw shaders pixel vbo bigdraw copypix copydepth cglparams msaa4 > "$O/features.log" 2>&1; echo "features: done" >> "$O/groups.txt"
sh run_gl_features.sh "$O/windows" win:0,30,1,24,basic win:4,40,1,24,basic win:2,40,1,24,basic win:6,40,1,24,basic win:0,40,0,16,basic win:0,40,1,24,clears win:0,40,1,24,hz win:4,40,1,24,hz win:4,30,1,24,resolve win:0,30,1,24,resolve win:6,30,0,24,resolve > "$O/windows.log" 2>&1; echo "windows: done" >> "$O/groups.txt"
mkdir -p "$O/godot"
for m in game editor; do
  if [ $m = game ]; then A="--path $PROJ Main.tscn"; else A="-e --path $PROJ"; fi
  DYLD_INSERT_LIBRARIES="$P/opcode_recorder.dylib" OPCODE_LOG="$O/godot/$m.tsv" "$G" $A > "$O/godot/$m.out" 2>&1 < /dev/null &
  pid=$!; i=0; while kill -0 $pid 2>/dev/null && [ $i -lt 40 ]; do sleep 1; i=`expr $i + 1`; done
  kill $pid 2>/dev/null; j=0; while kill -0 $pid 2>/dev/null && [ $j -lt 60 ]; do sleep 1; j=`expr $j + 1`; done
  echo "godot $m: ran ${i}s, exit wait ${j}s" >> "$O/groups.txt"
done
echo "ALL DONE" >> "$O/groups.txt"
