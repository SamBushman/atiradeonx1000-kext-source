#!/bin/sh
# utshark2.sh TAG ENV(none|name) SECS DELAY WIN : Shark UT2004 DM-Antalus high steady state: sample WIN seconds starting DELAY seconds after process start (after map load)
cd ~/rung3
TAG=$1; ENV=$2; SECS=${3:-60}; DELAY=${4:-35}; WIN=${5:-20}
for p in `ps auxww | grep "[u]t2004-bin" | awk '{print $2}'`; do kill $p; done; sleep 3
echo "$TAG DM-Antalus high $SECS 453418555 0" > ~/rung3/ut_tag
if [ $ENV = none ]; then rm -f ~/rung3/ut_env; else cp ~/rung3/ut_env_$ENV ~/rung3/ut_env; fi
rm -rf ~/rung3/gamefps/ut2004/$TAG
open -a Terminal ~/rung3/gamefps/ut2004_bench_r.command
i=0; pid=; while [ -z "$pid" ] && [ $i -lt 120 ]; do pid=`ps -axco pid,command | grep "ut2004-bin" | awk '{print $1}' | head -1`; sleep 1; i=`expr $i + 1`; done
echo "pid=$pid after ${i}s"
mkdir -p ~/rung3/final_eval/nov2/shark; cd ~/rung3/final_eval/nov2/shark
sleep $DELAY; sudo shark -q -i -1 -a $pid -T ${WIN}s -o ut_$TAG -d . > /dev/null 2>&1
sudo shark -g ut_${TAG}_001.mshark > /dev/null 2>&1
i=0; until grep -q DONE ~/rung3/gamefps/ut2004/$TAG/summary.txt 2>/dev/null || [ $i -gt 60 ]; do sleep 5; i=`expr $i + 1`; done
ls ut_${TAG}_001-report.txt
