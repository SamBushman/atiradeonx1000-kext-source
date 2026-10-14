#!/bin/sh
# consumer load loop (dev machine) against the G5 during a soak: cycles automated QuickTime, DVD Player, and the 2D-compositing + WindowServer-gesture scenarios; stops when consumers.STOP exists.
L=/home/sam/g5logs/oct14-phaseR; K=/Users/bushmas/rung3/va_cap; M=192.168.5.213:9168
n=0
while [ ! -f $L/consumers.STOP ]; do
  n=$((n+1)); k=$((n%3))
  if [ $k = 0 ]; then
    r=$(timeout 400 ssh -o ConnectTimeout=10 G5 'sh $HOME/rung3/gest2d.sh' 2>&1 | tail -1)
    echo "$(date +%T) run $n gestures2d -> $r" >> $L/consumers.log
  else
    if [ $k = 1 ]; then P="quicktime $K/streams/test_ntsc_720x480.mpg 20 $M"; else P="dvdplayer $K 25 $M"; fi
    timeout 20 ssh G5 "echo '$P' > $K/auto_play.args; rm -f $K/auto_DONE"
    timeout 25 ssh G5 "open -a Terminal $K/auto_play.command"
    for i in $(seq 1 30); do timeout 15 ssh -o ConnectTimeout=8 G5 "test -f $K/auto_DONE" 2>/dev/null && break; sleep 5; done
    echo "$(date +%T) run $n ($P) done=$(timeout 15 ssh -o ConnectTimeout=8 G5 "test -f $K/auto_DONE && echo yes || echo NO" 2>&1)" >> $L/consumers.log
  fi
  sleep 60
done
