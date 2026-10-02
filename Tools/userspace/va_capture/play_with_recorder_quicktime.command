#!/bin/sh
# play_with_recorder_quicktime.command - DOUBLE-CLICK this at the G5 console (an app started from ssh deadlocks Cocoa on this machine). It plays a test stream in "QuickTime Player" with the passive
# IOKit recorder loaded (iokit_record_va.dylib: logs every call the player makes to the kext, changes nothing) and runs watch_hw_path.sh in the background.
# Usage: double-click for the default stream, or run  sh play_with_recorder_quicktime.command /path/to/file.mpg  from Terminal.
D=/tmp/va_cap; cd "$D" || { echo "copy the va_capture folder to /tmp/va_cap first"; exit 1; }
F=${1:-$D/streams/test_ntsc_720x480.mpg}
ts=`date +%H%M%S`
sh $D/watch_hw_path.sh 90 $D/hw_watch_$ts.log > /dev/null 2>&1 &
echo "recording to $D/rec_$ts.tsv  (.mem = mapped-buffer dumps); play the file, then quit the player"
IOKIT_RECORD_LOG=$D/rec_$ts.tsv VA_DUMP_MAX=64 VA_DUMP_BYTES=4096 DYLD_INSERT_LIBRARIES=$D/iokit_record_va.dylib "/Applications/QuickTime Player.app/Contents/MacOS/QuickTime Player" "$F"
echo "player exited; logs:"; ls -l $D/rec_$ts.* $D/hw_watch_$ts.log 2>/dev/null
