#!/bin/sh
# ut2004_bench.command (runs on the G5 inside the Aqua session via `open -a Terminal`): one UT2004 built-in benchmark pass.
# Parameters come from $HOME/rung3/ut_tag ("TAG MAP PRESET SECS SEED REC", REC=1 runs under the opcode recorder), because a .command cannot take arguments.
# PRESET = name of an ini snapshot in $HOME/rung3/gamefps/ut2004/ini/<PRESET>.ini (copied over the user UT2004.ini before every run, so both sides get identical settings).
# Output: $HOME/rung3/gamefps/ut2004/<TAG>/ {avgfps.log, stats.csv, UT2004.log, game.tsv (recorder), shot.png, summary.txt (ends with DONE)}.
read TAG MAP PRESET SECS SEED REC < $HOME/rung3/ut_tag
R3=$HOME/rung3/gamefps/ut2004; O=$R3/$TAG; mkdir -p $O; rm -rf $O/*
AS="$HOME/Library/Application Support/Unreal Tournament 2004"; A="/Applications/Unreal Tournament 2004.app"
cp "$R3/ini/$PRESET.ini" "$AS/System/UT2004.ini"
rm -f "$AS"/Benchmark/Results/avgfps-*.log "$AS"/Benchmark/CSVs/stats-*.csv "$AS"/Benchmark/Logs/ut2004-*.log
cd "$A/System"
case $MAP in
  ONS-Torlan) URL="ONS-Torlan?spectatingonly=true?numbots=8?quickstart=true?attractcam=true";;
  *) URL="$MAP?spectatingonly=true?numbots=8?quickstart=true?attractcam=true";;
esac
if [ "$REC" = 1 ]; then
  DYLD_INSERT_LIBRARIES=$HOME/rung3/opcode_recorder.dylib OPCODE_LOG="$O/game.tsv" ./ut2004-bin "$URL" -benchmark -seconds=$SECS -seed=$SEED -nosound > $O/out.txt 2>&1 < /dev/null &
else
  ./ut2004-bin "$URL" -benchmark -seconds=$SECS -seed=$SEED -nosound > $O/out.txt 2>&1 < /dev/null &
fi
pid=$!; i=0; LIM=`expr $SECS + 120`
while kill -0 $pid 2>/dev/null && [ $i -lt $LIM ]; do sleep 1; i=`expr $i + 1`; [ $i -eq `expr $SECS / 2 + 30` ] && screencapture -x $O/shot.png; done
kill $pid 2>/dev/null; sleep 3; kill -9 $pid 2>/dev/null
cp "$AS"/Benchmark/Results/avgfps-*.log $O/avgfps.log 2>/dev/null; cp "$AS"/Benchmark/CSVs/stats-*.csv $O/stats.csv 2>/dev/null
cp "$AS/System/UT2004.log" $O/UT2004.log
echo "ran ${i}s $TAG $MAP $PRESET seed=$SEED rec=$REC" > $O/summary.txt; echo DONE >> $O/summary.txt
