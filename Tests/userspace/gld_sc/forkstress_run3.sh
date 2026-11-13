#!/bin/sh
# forkstress_run3.sh SECS : #273 experiment 1 (Nov 13): SEGV-with-handler children (flags 2) with the GLDriver dlopen'ed in the parent (flag 4), crashreporterd RUNNING, one child at a time like the fuzz harness. Telemetry fsynced + UDP (9999); ksnap (9998) samples crash-log size and crashreporterd CPU.
cd ~/rung3/fnf_237/fs || exit 1
SECS=${1:-300}; export FS_PAR=1; LOG=run3.log
say() { echo "$(date +%H:%M:%S) $*" >> $LOG; sync; echo "$(date +%H:%M:%S) $*" | nc -u -w1 192.168.5.213 9999 2>/dev/null; }
say "RUN3 START secs=$SECS crashreporterd=$(ps auxww | grep -c '[c]rashreporterd') uptime=$(uptime | sed 's/,.*//')"
sh ../ksnap.sh 2 > /dev/null 2>&1 &
KP=$!
say "EXP1 flags=6 BEGIN"
./forkstress exp1_segv_crashrep 6 $SECS 0 fs3.log
say "EXP1 flags=6 END (survived)"
kill $KP 2>/dev/null
say "RUN3 FINISHED"
