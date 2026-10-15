#!/bin/sh
# video_consumer_compare.sh OUTDIR (dev machine): automated video-consumer run on BOTH kexts (stock then rebuilt hot-swap, each with swap + unstick + settle): DVD Player playing the generated disc image mounted at /Volumes/TESTDVD,
# QuickTime Player playing an MPEG-2 file, VLC playing the DVD VOB, each under the passive IOKit recorder (Tools/userspace/va_capture). Fetches the screenshot, recorder log, hw-watch log and player output per run.
# Env: SEQ="stock rebuilt" REBUILT_DIR STOCK_DIR SETTLE(45) JOBS (default below). Needs ~/rung3/va_cap installed (install_on_g5.sh) and the disc mounted (hdiutil attach ~/rung3/dvdgen/test.iso).
O=${1:?outdir}; SEQ=${SEQ:-"stock rebuilt"}; RB=${REBUILT_DIR:-kext_build_fix}; ST=${STOCK_DIR:-stockkext}; SETTLE=${SETTLE:-45}; mkdir -p "$O"
JOBS=${JOBS:-"dvdplayer|/Volumes/TESTDVD|40 quicktime|\$HOME/rung3/va_cap/streams/test_ntsc_720x480.mpg|20 vlc|\$HOME/rung3/va_cap/streams/test_ntsc_dvd.vob|30"}
for tag in $SEQ; do
  if [ $tag = stock ]; then D=$ST; else D=$RB; fi
  timeout 100 ssh G5 "sh \$HOME/rung3/swap.sh $D 2>&1 | tail -1; sh \$HOME/rung3/srchead/Tools/issue157_unstick_hotswap/unstick_hotswap_vram.sh 2>&1 | tail -1; killall Dock; md5 -r \$HOME/rung3/$D/ATIRadeonX1000.kext/Contents/MacOS/ATIRadeonX1000; ls /Volumes/TESTDVD | head -1" >> "$O/driver.log" 2>&1 || { echo "swap FAILED $tag" >> "$O/driver.log"; exit 1; }
  sleep $SETTLE
  for j in $JOBS; do
    player=${j%%|*}; rest=${j#*|}; stream=${rest%%|*}; secs=${rest##*|}; b=${tag}_$player
    timeout 60 ssh G5 "rm -f \$HOME/rung3/va_cap/auto_DONE; echo \"$player $stream $secs\" > \$HOME/rung3/va_cap/auto_play.args; open -a Terminal \$HOME/rung3/va_cap/auto_play.command"
    n=0; until timeout 20 ssh G5 "test -f \$HOME/rung3/va_cap/auto_DONE" 2>/dev/null; do sleep 5; n=$((n+1)); [ $n -gt $((secs/5+40)) ] && { echo "timeout $b" >> "$O/driver.log"; break; }; done
    mkdir -p "$O/$b"; timeout 120 ssh G5 "cd \$HOME/rung3/va_cap; cat auto_DONE; ls -t rec_*.tsv | head -1; ls -t hw_watch_*.log | head -1; ls -t auto_*.png | head -1; ls -t auto_*.out | head -1" > "$O/$b/files.txt" 2>> "$O/driver.log"
    for f in `tail -4 "$O/$b/files.txt"`; do scp -q G5:rung3/va_cap/$f "$O/$b/" 2>> "$O/driver.log"; done
    timeout 60 ssh G5 "echo \"$b panic=\$(ls -l /Library/Logs/panic.log | awk '{print \$5}') \$(uptime | sed 's/,.*//') kext=\$(kextstat | grep -c com.apple.ATIRadeonX1000)\"" >> "$O/health.txt" 2>&1
    sleep 5
  done
done
echo "done: $O" >> "$O/driver.log"
