#!/bin/sh
# sleep_wake_test.sh OUTDIR SIDE [CYCLES=3] [SLEEPSECS=25] (dev machine): system sleep + Wake-on-LAN cycles on the G5 (womp=1; the magic packet is sent from this machine).
# SIDE = boot (the boot-time driver as booted, control) | rebuilt (kext_build_fix hot-swapped + unstick + settle). Per cycle: parity_test_harness before, `pmset sleepnow`, wait until the G5 stops answering ping, SLEEPSECS asleep, WoL, wait for ssh, kext identity + panic.log + parity harness after,
# screenshot. The G5's MAC is read from the live machine (en0). Evidence in OUTDIR/cycleN_*.
O=${1:?outdir}; SIDE=${2:?boot|rebuilt}; CY=${3:-3}; SS=${4:-25}; RB=${REBUILT_DIR:-kext_build_fix}; mkdir -p "$O"; IP=192.168.5.83
MAC=`ssh G5 "ifconfig en0 | awk '/ether/{print \\$2}'"`; echo "mac=$MAC side=$SIDE" >> "$O/log.txt"
wol() { python3 - "$MAC" <<'PY'
import socket,sys
m=bytes.fromhex(sys.argv[1].replace(':','')); p=b'\xff'*6+m*16
s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM); s.setsockopt(socket.SOL_SOCKET,socket.SO_BROADCAST,1)
for a in ('192.168.5.255','255.255.255.255'):
    for port in (9,7): s.sendto(p,(a,port))
PY
}
if [ $SIDE = rebuilt ]; then
  timeout 100 ssh G5 "sh \$HOME/rung3/swap.sh $RB 2>&1 | tail -1; sh \$HOME/rung3/srchead/Tools/issue157_unstick_hotswap/unstick_hotswap_vram.sh 2>&1 | tail -1; killall Dock" >> "$O/log.txt" 2>&1; sleep 45
fi
c=1
while [ $c -le $CY ]; do
  P="$O/cycle${c}"; echo "== cycle $c $(date +%T)" >> "$O/log.txt"
  timeout 200 ssh G5 "cd \$HOME/rung3/srchead/Tests && ./parity_test_harness > \$HOME/rung3/sw_pre.txt 2>&1; echo harness_rc=\$?; kextstat | grep ATIRadeonX1000; ls -l /Library/Logs/panic.log; screencapture -x \$HOME/rung3/sw_pre.png" > ${P}_pre.log 2>&1
  timeout 20 ssh G5 "osascript -e 'tell application \"Finder\" to sleep'" > /dev/null 2>&1
  n=0; while ping -c1 -W1 $IP > /dev/null 2>&1; do sleep 2; n=$((n+1)); [ $n -gt 30 ] && { echo "did not go to sleep" >> "$O/log.txt"; break; }; done
  echo "asleep after ~$((n*2))s" >> "$O/log.txt"; sleep $SS
  wol; t0=$(date +%s); n=0
  until timeout 8 ssh -o ConnectTimeout=5 G5 uptime > /dev/null 2>&1; do sleep 5; n=$((n+1)); [ $((n%6)) -eq 0 ] && wol; [ $n -gt 48 ] && { echo "NO WAKE after 4 min" >> "$O/log.txt"; exit 1; }; done
  echo "woke after $(( $(date +%s) - t0 ))s" >> "$O/log.txt"; sleep 20
  timeout 200 ssh G5 "cd \$HOME/rung3/srchead/Tests && ./parity_test_harness > \$HOME/rung3/sw_post.txt 2>&1; echo harness_rc=\$?; kextstat | grep ATIRadeonX1000; ls -l /Library/Logs/panic.log; uptime; screencapture -x \$HOME/rung3/sw_post.png; diff \$HOME/rung3/sw_pre.txt \$HOME/rung3/sw_post.txt > \$HOME/rung3/sw_diff.txt; echo diff_rc=\$?; wc -l \$HOME/rung3/sw_diff.txt" > ${P}_post.log 2>&1
  scp -q G5:rung3/sw_pre.png G5:rung3/sw_post.png G5:rung3/sw_diff.txt G5:rung3/sw_post.txt "$O/" 2>/dev/null; for f in sw_pre.png sw_post.png sw_diff.txt sw_post.txt; do mv "$O/$f" "$O/cycle${c}_$f" 2>/dev/null; done
  c=$((c+1))
done
echo done >> "$O/log.txt"
