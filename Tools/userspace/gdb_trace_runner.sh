#!/bin/sh
# gdb_trace_runner.sh - issue #42: run each generated gdb script (Tools/userspace/gdb_emitter_trace.py) against its program under gdb-696 on the G5.
#   sh gdb_trace_runner.sh SCRIPTDIR OUTDIR PROGRAMDIR     (SCRIPTDIR/<name>.gdb, each does its own `run ARGS`; PROGRAMDIR holds ./glcov)
# Each script gets 240 s; if gdb is still alive after that it is killed (this kills the program too - a last resort, see the glstress hazard notes), and the run is reported.
S=${1:?}; O=${2:?}; P=${3:?}; mkdir -p "$O"; : > "$O/summary.txt"; cd "$P" || exit 1
for g in "$S"/*.gdb; do
  n=`basename $g .gdb`
  gdb -batch -x $g ./glcov > "$O/$n.log" 2>&1 &
  pid=$!; i=0
  while kill -0 $pid 2>/dev/null && [ $i -lt 240 ]; do sleep 1; i=`expr $i + 1`; done
  if kill -0 $pid 2>/dev/null; then kill $pid; sleep 2; kill -9 $pid 2>/dev/null; echo "$n: KILLED after 240 s" >> "$O/summary.txt"; cat "$O/summary.txt"; exit 3; fi
  echo "$n: `grep -c 'TRACE .* hit' "$O/$n.log"` traced hits, `grep -a 'TOTAL' "$O/$n.log" | grep -v ' hits 0$' | wc -l` emitters hit, `grep -a -c 'glcov done' "$O/$n.log"` completed" >> "$O/summary.txt"
done
cat "$O/summary.txt"
