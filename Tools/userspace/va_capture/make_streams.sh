#!/bin/sh
# make_streams.sh - generate small MPEG-2 test streams for the #93 capture (needs ffmpeg on the dev machine). Output: streams/*.mpg (a few MB in total).
# Content is a synthetic test pattern with motion (so the decoder gets real P/B macroblocks: intra-only content would not exercise motion compensation / IDCT residuals) plus silent MPEG audio.
cd "`dirname "$0"`" && mkdir -p streams || exit 1
SRC="testsrc2=size=720x480:rate=30000/1001"
AUD="-f lavfi -i anullsrc=r=48000:cl=stereo"
# 1. NTSC DVD-compliant program stream (720x480, 29.97 fps, GOP 15 with B frames, 4 Mbit/s), 4 seconds
ffmpeg -y -f lavfi -i "$SRC" $AUD -t 4 -c:v mpeg2video -b:v 4000k -maxrate 6000k -bufsize 1835k -g 15 -bf 2 -pix_fmt yuv420p -aspect 4:3 -c:a mp2 -b:a 192k -f mpeg streams/test_ntsc_720x480.mpg
# 2. the same as a DVD-VOB program stream (target ntsc-dvd), 30 seconds (authored into dvd/disc by author_video_ts.sh)
ffmpeg -y -f lavfi -i "$SRC" $AUD -t 30 -target ntsc-dvd -aspect 4:3 streams/test_ntsc_dvd.vob
# 3. smaller 352x240 MPEG-2 for a quick first look (the hardware path may only engage for DVD-size video, so this one is a control)
ffmpeg -y -f lavfi -i "testsrc2=size=352x240:rate=30000/1001" $AUD -t 4 -c:v mpeg2video -b:v 1500k -g 12 -bf 2 -pix_fmt yuv420p -c:a mp2 -b:a 128k -f mpeg streams/test_ntsc_352x240.mpg
ls -l streams
