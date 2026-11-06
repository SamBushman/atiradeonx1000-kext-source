#!/bin/sh
# usage: g5reboot.sh   -- sync + reboot -q the G5, then wait until it is genuinely back (ssh answers, uptime small, Finder+Dock running).
# Never declares a hang before 25 min of continuous failed probes; prints G5 uptime (the reliable clock), not the container clock.
ssh -o ConnectTimeout=10 G5 'sync; sudo reboot -q' >/dev/null 2>&1
echo "reboot issued"
sleep 45
tries=0; max=150   # 150 x 10 s = 25 min
while [ $tries -lt $max ]; do
  out=`ssh -o ConnectTimeout=6 -o ServerAliveInterval=3 G5 'uptime; ps auxww | grep -c "[D]ock.app"; ps auxww | grep -c "[F]inder.app"' 2>/dev/null`
  if [ -n "$out" ]; then
    up=`echo "$out" | sed -n 1p`; dock=`echo "$out" | sed -n 2p`; fnd=`echo "$out" | sed -n 3p`
    case "$up" in *" mins"*|*" secs"*|*" min,"*|*":"*) ;; esac
    if [ "$dock" -ge 1 ] 2>/dev/null && [ "$fnd" -ge 1 ] 2>/dev/null; then echo "G5_READY after $tries probes: $up"; exit 0; fi
  fi
  tries=`expr $tries + 1`; sleep 10
done
echo "G5_NOT_BACK after 25 min of probes"; exit 1
