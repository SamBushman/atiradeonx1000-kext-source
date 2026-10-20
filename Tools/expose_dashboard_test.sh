#!/bin/sh
# expose_dashboard_test.sh OUTDIR TAG   (dev machine) - Phase 8 automation: drive Expose (F9 all windows, F10 app windows, F11 show desktop) and Dashboard (F12) with synthetic key events
# (gui_input key; virtual codes F9=101 F10=109 F11=103 F12=111) and take a screenshot before/during/after each, on the CURRENT driver. TAG: boot (no swap) or rebuilt (hot-swap + unstick first; REBUILT_DIR).
# Run each TAG from its own fresh boot. Evidence: OUTDIR/<tag>_*.png, <tag>.txt (kextstat, panic.log size, display mode, WindowServer alive). Screenshots are compared by eye / md5 (live desktop content varies).
O=${1:?outdir}; TAG=${2:?tag}; RB=${REBUILT_DIR:-kext_build_fix}; mkdir -p "$O"; L="$O/$TAG.txt"; : > "$L"
if [ $TAG = rebuilt ]; then
  timeout 100 ssh G5 "sh \$HOME/rung3/swap.sh $RB 2>&1 | tail -1; sh \$HOME/rung3/srchead/Tools/issue157_unstick_hotswap/unstick_hotswap_vram.sh 2>&1 | tail -1; killall Dock" >> "$L" 2>&1 || { echo "swap FAILED" >> "$L"; exit 1; }
  sleep 45
fi
G="timeout 40 ssh G5"
shot() { $G "screencapture -x \$HOME/rung3/final_eval/ed_${TAG}_$1.png" ; scp -q "G5:rung3/final_eval/ed_${TAG}_$1.png" "$O/${TAG}_$1.png"; }
key() { $G "\$HOME/rung3/gui_input key $1"; }
$G 'mkdir -p $HOME/rung3/final_eval; osascript -e "tell application \"Finder\" to make new Finder window to (POSIX file \"/usr/bin\" as alias)" -e "tell application \"Finder\" to make new Finder window to (POSIX file \"/Applications\" as alias)"' >> "$L" 2>&1; sleep 4
shot 0_before
key 101; sleep 3; shot 1_expose_all; key 101; sleep 3; shot 2_after_expose_all
key 109; sleep 3; shot 3_expose_app; key 109; sleep 3; shot 4_after_expose_app
key 103; sleep 3; shot 5_show_desktop; key 103; sleep 3; shot 6_after_show_desktop
key 111; sleep 5; shot 7_dashboard; key 111; sleep 4; shot 8_after_dashboard
for i in 1 2 3; do key 101; sleep 1; key 101; sleep 1; key 111; sleep 2; key 111; sleep 2; done
shot 9_after_cycles
$G 'osascript -e "tell application \"Finder\" to close every window" >/dev/null 2>&1; kextstat | grep " com.apple.ATIRadeonX1000 "; ls -l /Library/Logs/panic.log; ps ax | grep -c "[W]indowServer"; system_profiler SPDisplaysDataType | grep -i resolution' >> "$L" 2>&1
cat "$L"
