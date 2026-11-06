#!/bin/sh
# usage: rbis.sh TAG RANGES [EXTRA_ENV]  -> runs probe interleaved-real-draws replay with REPLAY_LINES=RANGES; prints TAG RANGES => WEDGED|NORMAL; reboots G5 if wedged
TAG=$1; R=$2; X=$3
ssh G5 "cd ~/rung3; echo 'export REPLAY=\$HOME/rung3/gllog_d3t53.txt REPLAY_REAL=1329,1382,1383 REPLAY_REALDIR=\$HOME/rung3/real214 REPLAY_LINES=$R $X' > runp_env_$TAG; sh runp.sh $TAG; grep -c 'real replay complete' ~/g5logs/probe214d/$TAG.txt" > /tmp/claude-1000/-var-home-sam/f94d1fb2-d533-4cdc-a57f-ab19ccbcad40/scratchpad/rbis_$TAG.out 2>&1
n=`tail -1 rbis_$TAG.out`
if [ "$n" = "1" ]; then echo "$TAG $R => NORMAL"; else echo "$TAG $R => WEDGED"; ./g5reboot.sh > /dev/null 2>&1; fi
