#!/bin/sh
# wait-only variant of g5reboot.sh: poll until ssh answers AND Finder+Dock exist (25 min cap); issues no reboot
tries=0
while [ $tries -lt 150 ]; do
  out=`ssh -o ConnectTimeout=6 -o ServerAliveInterval=3 G5 'uptime; ps auxww | grep -c "[D]ock.app"; ps auxww | grep -c "[F]inder.app"' 2>/dev/null`
  if [ -n "$out" ]; then
    dock=`echo "$out" | sed -n 2p`; fnd=`echo "$out" | sed -n 3p`
    if [ "$dock" -ge 1 ] 2>/dev/null && [ "$fnd" -ge 1 ] 2>/dev/null; then echo "G5_READY after $tries probes: `echo "$out" | sed -n 1p`"; exit 0; fi
  fi
  tries=`expr $tries + 1`; sleep 10
done
echo "G5_NOT_BACK after 25 min of probes"; exit 1
