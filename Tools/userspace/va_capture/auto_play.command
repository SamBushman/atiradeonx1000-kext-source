#!/bin/sh
# auto_play.command - fully automated replacement for the "double-click the launcher, play, quit" steps of the VA capture procedure (README).
# Run INSIDE the Aqua session with no person present:  ssh G5 'open -a Terminal /tmp/va_cap/auto_play.command'   (a .command cannot take arguments, so the job is
# read from /tmp/va_cap/auto_play.args, one line:  PLAYER STREAM SECONDS [ip:port]   e.g.  quicktime /tmp/va_cap/streams/test_ntsc_720x480.mpg 20
# PLAYER = quicktime | dvdplayer | vlc.) It starts the existing play_with_recorder_<player>.command (recorder + watch_hw_path.sh), drives the player with AppleScript,
# takes a mid-play screenshot, quits the player, and writes /tmp/va_cap/auto_DONE (last line = the recorder log name) for the dev machine to poll.
D=/tmp/va_cap; cd "$D" || exit 1
rm -f $D/auto_DONE
read PLAYER STREAM SECS MIRROR < $D/auto_play.args   # MIRROR (optional) = ip:port of Tools/udp_log_receiver.py: every recorder line incl. the PRE line before each call is also sent as UDP
[ -n "$MIRROR" ] && export IOKIT_RECORD_MIRROR=$MIRROR
ts=`date +%H%M%S`; OUT=$D/auto_$ts.out
case $PLAYER in
  quicktime) APP="QuickTime Player"; PLAY='tell application "QuickTime Player" to play front document';;
  dvdplayer) APP="DVD Player";       PLAY='tell application "DVD Player" to play';;
  vlc)       APP="VLC";              PLAY='tell application "VLC" to play';;
  *) echo "bad player $PLAYER" > $D/auto_DONE; exit 1;;
esac
echo "auto_play: $PLAYER $STREAM ${SECS}s" > $OUT
sh $D/play_with_recorder_$PLAYER.command "$STREAM" >> $OUT 2>&1 &
sleep 12                                              # app launch + document open
osascript -e "$PLAY" >> $OUT 2>&1
sleep 3; screencapture -x $D/auto_$ts.png
sleep $SECS
osascript -e "tell application \"$APP\" to quit" >> $OUT 2>&1
wait
echo "auto_play: finished `date`" >> $OUT
echo "rec_* from this run: `ls -t $D/rec_*.tsv | head -1`  out=$OUT  max-dvd: `grep -h 'max DVD' $D/hw_watch_*.log | tail -1`" > $D/auto_DONE
