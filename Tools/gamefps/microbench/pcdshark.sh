#!/bin/sh
# pcdshark.sh TAG ENV(none|n2) TESTNAME
cd ~/rung3
if [ $2 = none ]; then unset GLD_REDIRECT_FROM GLD_REDIRECT_TO DYLD_INSERT_LIBRARIES; else . ./ut_env_$2; fi
PCD_ONLY="$3" PCD_REPS=12 PCD_MUL=400 ./pcd > final_eval/nov2/pcd_$1.txt 2>&1 &
sleep 6
pid=`ps -axco pid,command | grep " pcd" | awk '{print $1}' | tail -1`
cd final_eval/nov2/shark
sudo shark -q -i -1 -a $pid -T 8s -o pcd_$1 -d . > /dev/null 2>&1
sudo shark -g pcd_$1_001.mshark > /dev/null 2>&1
wait
