#!/bin/sh
# doom3_bench.command (G5, Aqua session): one dhewm3 (Tiger PPC build, installed on Tiger HD in /Applications/Doom 3 so the run never touches the SonnetSATA/Test HD disk) run, results in $HOME/gamefps/doom3/TAG/ (out.txt has the timedemo line). Parameters from $HOME/gamefps/d3_tag: first word TAG, then SECS, then extra dhewm3 args.
read TAG SECS ARGS < $HOME/gamefps/d3_tag
R="${D3ROOT:-/Applications/Doom 3}"; O=$HOME/gamefps/doom3/$TAG; mkdir -p $O "$R/save" "$R/run"; rm -rf $O/*
true  # engine files already in $R/run
rm -f "$R/save"/*.log "$R/save"/*/*.log 2>/dev/null
cd "$R/run"
./dhewm3 +set fs_basepath "$R" +set fs_savepath "$R/save" +set fs_gameDllPath "$R/run" +set logFile 1 +set s_noSound 1 $ARGS > $O/out.txt 2>&1 < /dev/null &
pid=$!; echo $pid > $O/pid; i=0
while kill -0 $pid 2>/dev/null && [ $i -lt $SECS ]; do sleep 1; i=`expr $i + 1`; [ $i -eq 40 ] && screencapture -x $O/shot.png; done
kill $pid 2>/dev/null; sleep 3; kill -9 $pid 2>/dev/null
find "$R/save" -name "*.log" -exec cp {} $O/ \; 2>/dev/null
echo "ran ${i}s $TAG $ARGS" > $O/summary.txt; ps -axo pid,state,command | grep "[d]hewm3" >> $O/summary.txt; echo DONE >> $O/summary.txt
