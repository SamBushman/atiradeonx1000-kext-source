#!/bin/sh
# pull_evidence.sh NAME  (dev machine) - after a crash/reboot of the G5: ONE ssh session that waits for the machine, then streams back the persistent ~/rung3/va/NAME* logs, the panic log and a short state report
# (uptime, kextstat, stale processes) as a tar into captures/comp/NAME/. Text is written to a file first so nothing but tar goes down the pipe. No volume verification here (slow, starves sshd): do it once, separately.
N=$1; D=$(cd "$(dirname "$0")" && pwd); OUT=$D/captures/comp/$N; mkdir -p $OUT
until ping -c1 -W2 192.168.5.82 >/dev/null 2>&1; do sleep 10; done
for t in 1 2 3 4 5 6 7 8; do
  if timeout 120 ssh -n -o ConnectTimeout=60 G5 "E=/tmp/ev_$N; rm -rf \$E; mkdir -p \$E; { uptime; kextstat | grep -i ati; ps auxww | egrep '[c]rashdump|[a]va_drive'; ls -la \$HOME/rung3/va/${N}*; } > \$E/report.txt 2>&1; cp /Library/Logs/panic.log \$E/panic.log 2>/dev/null; cp \$HOME/rung3/va/${N}* \$E/ 2>/dev/null; cd \$E && tar cf - ." | tar xf - -C $OUT 2>/dev/null && [ -s $OUT/report.txt ]; then echo "evidence pulled on try $t"; break; fi
  sleep 30
done
cat $OUT/report.txt 2>/dev/null; ls $OUT
