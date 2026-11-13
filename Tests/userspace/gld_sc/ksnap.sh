#!/bin/sh
# ksnap.sh INTERVAL : low-rate kernel-state sampler (#273): every INTERVAL seconds one line with the process count, in-use counts of the kernel zones that grow with fork/exit/timers/mappings, and vm_stat page counts; appended to ksnap.log and sent as one UDP datagram to 192.168.5.213:9998 (survives a panic that the log file may not).
LOG=${KSNAP_LOG:-$HOME/rung3/fnf_237/ksnap.log}
while :; do
  l="KS $(date +%H:%M:%S) procs=$(ps ax | wc -l | tr -d ' ') $(zprint 2>/dev/null | awk '/^(threads|uthreads|tasks|zombie|proc|pmap|mk_timer|alarms|ipc.ports|ipc.spaces|vm.objects|vm.map.entries|vm.map.copies|vm.object.hash.entries) /{printf "%s=%s ",$1,$7}') crashlogKB=$(ls -l $HOME/Library/Logs/CrashReporter/*.crash.log 2>/dev/null | awk '{t+=$5} END{printf "%d",t/1024}') crd=$(ps axo pcpu,command | awk '/[c]rashreporterd|[c]rashdump/{printf "%s%%,",$1}') $(vm_stat | awk '/Pages free|Pages active|Pages wired|Pages zero/{gsub(":","",$0); gsub("\\.","",$0); printf "%s=%s ",$2,$NF}')"
  echo "$l" >> $LOG; echo "$l" | nc -u -w1 192.168.5.213 9998 2>/dev/null
  sleep $1
done
