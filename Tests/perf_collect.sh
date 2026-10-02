#!/bin/sh
# Tests/perf_collect.sh - issue #44 criteria 2 and 5: collect a repeatable performance baseline. Runs ON the G5 from Tests/ against the loaded kext.
#   sh perf_collect.sh OUTDIR [REPS=5] [CALLS=50000] [GLN=100]
# For each repetition (a fresh process each time, 5 s apart): perf_methods CALLS 200 and perf_baseline GLN, output saved as OUTDIR/run<k>_methods.txt / run<k>_gl.txt.
# OUTDIR/env.txt records what the numbers depend on: date, uptime/load, kext + load address, CPU/memory, the display configuration, and any other GL/GUI processes. Repetitions are what let
# Tools/perf_compare.py tell noise from regression (criterion 5): compare like with like (same machine, same boot, same display state, nothing else running).
O=${1:?usage: sh perf_collect.sh OUTDIR [REPS] [CALLS] [GLN]}; R=${2:-5}; C=${3:-50000}; G=${4:-100}
mkdir -p "$O" || exit 1
{ echo "date: `date`"; echo "uptime: `uptime`"; echo "kext: `kextstat 2>/dev/null | grep ' com.apple.ATIRadeonX1000 '`"; echo "uname: `uname -a`"
  echo "hw.cpufrequency: `sysctl -n hw.cpufrequency 2>/dev/null`  hw.ncpu: `sysctl -n hw.ncpu 2>/dev/null`  hw.memsize: `sysctl -n hw.memsize 2>/dev/null`"
  echo "displays:"; system_profiler SPDisplaysDataType 2>/dev/null | egrep -i "Chipset|VRAM|Resolution|Main Display|Mirror|Online"
  echo "busy processes (cpu >= 5%):"; ps auxww | awk '$3 >= 5.0 {print}' | cut -c1-120; } > "$O/env.txt" 2>&1
k=1
while [ $k -le $R ]; do
  ./perf_methods $C 200 > "$O/run${k}_methods.txt" 2>&1 || echo "perf_methods run $k failed" >> "$O/env.txt"
  ./perf_baseline $G > "$O/run${k}_gl.txt" 2>&1 || echo "perf_baseline run $k failed" >> "$O/env.txt"
  k=`expr $k + 1`; sleep 5
done
echo "collected $R repetitions into $O"
