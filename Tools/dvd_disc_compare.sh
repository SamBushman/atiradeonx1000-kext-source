#!/bin/sh
# dvd_disc_compare.sh OUTDIR [SECS=60] (dev machine): play the GENERATED DVD (~/rung3/dvdgen/test.iso, built by Tools/userspace/va_capture/author_video_ts.sh + hdiutil makehybrid) on stock then rebuilt (hot-swap, swap + unstick + settle each).
# Mounting the image makes DVD Player auto-launch and play it (the unstick step unmounts it, so it is attached AFTER each swap). Evidence: 3 screenshots, max DVD contexts seen (watch_hw_path.sh), panic.log/kextstat health, DVD Player exit status.
O=${1:?outdir}; SECS=${2:-60}; SEQ=${SEQ:-"stock rebuilt"}; RB=${REBUILT_DIR:-kext_build_fix}; ST=${STOCK_DIR:-stockkext}; SETTLE=${SETTLE:-45}; mkdir -p "$O"
for tag in $SEQ; do
  if [ $tag = stock ]; then D=$ST; else D=$RB; fi
  if [ $tag = boot ]; then   # no hot-swap at all: whatever driver the G5 booted with (SEQ=boot)
    echo "boot: no swap" >> "$O/driver.log"
  else
  timeout 100 ssh G5 "killall 'DVD Player' 2>/dev/null; hdiutil detach /Volumes/TESTDVD 2>/dev/null; sh \$HOME/rung3/swap.sh $D 2>&1 | tail -1; sh \$HOME/rung3/srchead/Tools/issue157_unstick_hotswap/unstick_hotswap_vram.sh 2>&1 | tail -1; killall Dock; md5 -r \$HOME/rung3/$D/ATIRadeonX1000.kext/Contents/MacOS/ATIRadeonX1000" >> "$O/driver.log" 2>&1 || { echo "swap FAILED $tag" >> "$O/driver.log"; exit 1; }
  fi
  sleep $SETTLE
  mkdir -p "$O/$tag"
  timeout 60 ssh G5 "hdiutil attach \$HOME/rung3/dvdgen/test.iso | tail -1; open -a \"DVD Player\"; sh \$HOME/rung3/va_cap/watch_hw_path.sh $SECS \$HOME/rung3/dvd_$tag.watch > /dev/null 2>&1 &" >> "$O/driver.log" 2>&1
  sleep ${PRECLICK:-12}; timeout 30 ssh G5 "screencapture -x \$HOME/rung3/dvd_${tag}_0.png; \$HOME/rung3/gui_input click 759 148; sleep 1; \$HOME/rung3/gui_input click 759 102"   # answer the "previously viewed disc" dialog: click Beginning of Disc (a Return key event does not reach it)
  sleep 5; timeout 30 ssh G5 "screencapture -x \$HOME/rung3/dvd_${tag}_1.png"
  sleep $((SECS/2-20)); timeout 30 ssh G5 "screencapture -x \$HOME/rung3/dvd_${tag}_2.png"
  sleep $((SECS/2+5)); timeout 30 ssh G5 "screencapture -x \$HOME/rung3/dvd_${tag}_3.png; ps auxww | grep -c '[D]VD Player' ; osascript -e 'tell application \"DVD Player\" to quit'; sleep 4; killall 'DVD Player' 2>/dev/null; sleep 2; hdiutil detach /Volumes/TESTDVD > /dev/null 2>&1; echo \"$tag panic=\$(ls -l /Library/Logs/panic.log | awk '{print \$5}') \$(uptime | sed 's/,.*//') kext=\$(kextstat | grep -c com.apple.ATIRadeonX1000)\"" >> "$O/health.txt" 2>&1
  for f in dvd_${tag}_0.png dvd_${tag}_1.png dvd_${tag}_2.png dvd_${tag}_3.png dvd_$tag.watch; do scp -q G5:rung3/$f "$O/$tag/" 2>> "$O/driver.log"; done
done
echo "done: $O" >> "$O/driver.log"
