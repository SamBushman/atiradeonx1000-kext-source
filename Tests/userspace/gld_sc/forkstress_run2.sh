#!/bin/sh
# forkstress_run2.sh SECS ALARM_US PAR : #273 repro. Variant V (ITIMER_VIRTUAL control) first, then H (ITIMER_REAL/ualarm). Telemetry fsynced + UDP before each variant.
cd ~/rung3/fnf_237/fs || exit 1
SECS=${1:-60}; export FS_ALARM_US=${2:-3000} FS_PAR=${3:-4}; LOG=run2.log
say() { echo "$(date +%H:%M:%S) $*" >> $LOG; sync; echo "$(date +%H:%M:%S) $*" | nc -u -w1 192.168.5.213 9999 2>/dev/null; }
say "RUN2 START secs=$SECS alarm_us=$FS_ALARM_US par=$FS_PAR uptime=$(uptime | sed 's/,.*//')"
for v in "K_parentkill_spin 80" "H_real_spin 17"; do
  set -- $v; name=$1; flags=$2
  say "VARIANT $name flags=$flags BEGIN"
  ./forkstress $name $flags $SECS 0 fs2.log
  say "VARIANT $name flags=$flags END (survived)"
  sleep 5
done
say "RUN2 FINISHED"
