#!/bin/sh
# app_sweep.command (runs on the G5 inside the Aqua session via `open -a Terminal`): launch one installed application for SECS seconds, screenshot it, record kernel-side evidence, quit it.
# Input $HOME/rung3/sweep_tag = "TAG SECS APPPATH" (APPPATH may contain spaces: it is the rest of the line). Output dir $HOME/rung3/sw_<TAG>/: shot1.png (mid-run), shot2.png (end), ps.txt (is the app alive at the end),
# ioreg_before/after.txt (IOKitDiagnostics class counts), crash.txt (new CrashReporter logs), summary.txt, DONE.
read TAG SECS APP < $HOME/rung3/sweep_tag
O=$HOME/rung3/sw_$TAG; mkdir -p $O; rm -f $O/*
ioreg -l -w0 | grep -E '"(ATIR500|IOATIR500)' | head -20 > $O/ioreg_before.txt
ls -t $HOME/Library/Logs/CrashReporter 2>/dev/null | head -3 > $O/crash_before.txt
open -a "$APP"
# optional scripted clicks: $HOME/rung3/sweep_clicks, lines "SECONDS_AFTER_LAUNCH X Y" (global coordinates), e.g. to dismiss a first-run dialog
if [ -f $HOME/rung3/sweep_clicks ]; then prev=0; while read t x y; do [ -z "$t" ] && continue; sleep `expr $t - $prev`; $HOME/rung3/gui_input click $x $y; prev=$t; done < $HOME/rung3/sweep_clicks; SECS=`expr $SECS - $prev`; fi
i=0; while [ $i -lt $SECS ]; do sleep 1; i=`expr $i + 1`; [ $i -eq `expr $SECS / 2` ] && screencapture -x $O/shot1.png; done
screencapture -x $O/shot2.png
ps auxww | grep -i "`basename "$APP" .app`" | grep -v grep | head -3 > $O/ps.txt
ioreg -l -w0 | grep -E '"(ATIR500|IOATIR500)' | head -20 > $O/ioreg_after.txt
ls -t $HOME/Library/Logs/CrashReporter 2>/dev/null | head -3 > $O/crash_after.txt
EXE=`defaults read "$APP/Contents/Info" CFBundleExecutable 2>/dev/null`
osascript -e "tell application \"`basename "$APP" .app`\" to quit" > /dev/null 2>&1; sleep 4
killall "`basename "$APP" .app`" 2>/dev/null; [ -n "$EXE" ] && killall "$EXE" 2>/dev/null; sleep 2
ps auxww | grep -i "`basename "$APP" .app`" | grep -v grep | head -3 > $O/ps_after_quit.txt
echo "ran ${SECS}s app=$APP" > $O/summary.txt; echo DONE >> $O/summary.txt
