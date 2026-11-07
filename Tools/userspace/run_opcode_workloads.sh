#!/bin/sh
# run_opcode_workloads.sh - issue #42: run the available GL workloads under Tools/userspace/opcode_recorder.dylib, one log per run. Runs ON the G5.
#   SRC=~/rung3/src_<sha> sh run_opcode_workloads.sh OUTDIR     (needs opcode_recorder.dylib in the current directory; cgl_probe and perf_baseline come from the staged tree SRC; glprobe / glsl120test / nesttest are the old Aug probes on Test HD, outside the repo)
# Each workload is killed after 60 s (Tiger has no timeout(1)); its exit status and the first line of output are recorded in OUTDIR/summary.txt.
O=${1:?usage: sh run_opcode_workloads.sh OUTDIR}; mkdir -p "$O"; : > "$O/summary.txt"; H="/Volumes/Test HD"; P="`pwd`"; SRC=${SRC:?set SRC to the staged tree, e.g. SRC=$HOME/rung3/src_<sha> (cgl_probe and perf_baseline of the HEAD under test)}
run() { # name command...
  n=$1; shift
  DYLD_INSERT_LIBRARIES="$P/opcode_recorder.dylib${DYLD_INSERT_LIBRARIES:+:$DYLD_INSERT_LIBRARIES}" OPCODE_LOG="$O/$n.tsv" "$@" > "$O/$n.out" 2>&1 &
  pid=$!; i=0
  while kill -0 $pid 2>/dev/null && [ $i -lt 60 ]; do sleep 1; i=`expr $i + 1`; done
  if kill -0 $pid 2>/dev/null; then kill $pid; sleep 1; kill -9 $pid 2>/dev/null; echo "$n: KILLED after 60 s" >> "$O/summary.txt"
  else wait $pid; echo "$n: exit $? ; `tail -1 "$O/$n.out" | cut -c1-80`" >> "$O/summary.txt"; fi
}
run cgl_probe       "$SRC/Tests/userspace/cgl_probe"
run perf_baseline   "$SRC/Tests/perf_baseline" 20
run glprobe         "$H/glprobe"
run glsl120test     "$H/glsl120test"
run nesttest        "$H/nesttest"
cat "$O/summary.txt"
