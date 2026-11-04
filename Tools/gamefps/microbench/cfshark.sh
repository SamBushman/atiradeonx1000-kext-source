#!/bin/sh
# cfshark.sh TAG [N=4000] : runs on the G5. Shark-samples Tests/perf_baseline (the glcycle benchmark: Clear+Flush / Draw100Tri+Flush per fresh context)
# for 8 s and writes the text report to OUTDIR/cf_TAG_001-report.txt (issue #212).  Swap the installed GLDriver BEFORE calling (per-process load).
T=${1:?tag}; N=${2:-4000}
D="/Volumes/Test HD/atiradeonx1000-kext-source-current/Tests"; O=$HOME/rung3/final_eval/nov3/shark; mkdir -p "$O"
cd "$D" || exit 1
./perf_baseline $N > "$O/cf_$T.txt" 2>&1 &
sleep 5
pid=`ps -axco pid,command | grep " perf_baseline" | awk '{print $1}' | tail -1`
cd "$O"
sudo shark -q -i -1 -a $pid -T 8s -o cf_$T -d . > /dev/null 2>&1
sudo shark -g cf_${T}_001.mshark > /dev/null 2>&1
wait
tail -4 "$O/cf_$T.txt"
