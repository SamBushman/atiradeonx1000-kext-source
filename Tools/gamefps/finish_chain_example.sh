#!/bin/bash
# finish_chain.sh: (1) wait for the rebuilt Doom 3 matrix, (2) restore stock (binary + kernelcache from backup, 2 reboots), (3) baseline check,
# (4) stock Doom 3 matrix from Tiger HD, (5) Desktop comparison file, (6) shut the G5 down. Log: ~/g5logs/gamefps/chain.log
K=$HOME/atiradeonx1000-kext-source; L=$HOME/g5logs/gamefps/chain.log; D3=$HOME/g5logs/gamefps/doom3_run3; UT=$HOME/g5logs/gamefps/ut2004_run3
log() { echo "$(date '+%H:%M:%S') $*" >> $L; }
g5() { ssh -o ConnectTimeout=10 G5 "$@"; }
wait_up() { # seconds
  local t=0; until ssh -o ConnectTimeout=5 G5 uptime >/dev/null 2>&1; do sleep 15; t=$((t+15)); [ $t -gt $1 ] && return 1; done; return 0; }
reboot_to() {
  g5 'sudo reboot' >/dev/null 2>&1; sleep 90; wait_up 1500 || return 1; sleep 45
  g5 'ls /Volumes | grep -q "Test HD"' || { log "Test HD missing after reboot; rebooting again"; g5 'sudo reboot' >/dev/null 2>&1; sleep 90; wait_up 1500 || return 1; sleep 45; }
  return 0; }
log "chain start"
# 1. wait for the rebuilt matrix
until grep -q -E "^done rebuilt|ABORT" $D3/driver.log 2>/dev/null; do sleep 20; done
grep -E "^done rebuilt|ABORT" $D3/driver.log >> $L
if ! wait_up 1500; then
  log "G5 unreachable for 25 min after the rebuilt run (needs a manual power cycle); skipping restore/stock run, writing partial report"; DOWN=1
fi
if [ -z "$DOWN" ]; then
  g5 'uptime; kextstat | grep X1000; ls -l /Library/Logs/panic.log' >> $L 2>&1
  # 2. restore stock, discrete commands
  B='$HOME/rung3/bootinstall_backup_ut'
  g5 "sudo cp $B/ATIRadeonX1000 /tmp/ATIRadeonX1000.stock && sudo chown root:wheel /tmp/ATIRadeonX1000.stock && sudo chmod 644 /tmp/ATIRadeonX1000.stock && md5 -r /tmp/ATIRadeonX1000.stock" >> $L 2>&1
  g5 'sudo mv /tmp/ATIRadeonX1000.stock /System/Library/Extensions/ATIRadeonX1000.kext/Contents/MacOS/ATIRadeonX1000 && md5 -r /System/Library/Extensions/ATIRadeonX1000.kext/Contents/MacOS/ATIRadeonX1000' >> $L 2>&1
  g5 "sudo cp $B/kernelcache.86C01707 /tmp/kernelcache.stock && sudo chown root:wheel /tmp/kernelcache.stock && sudo chmod 644 /tmp/kernelcache.stock && md5 -r /tmp/kernelcache.stock" >> $L 2>&1
  g5 'sudo mv /tmp/kernelcache.stock /System/Library/Caches/com.apple.kernelcaches/kernelcache.86C01707 && md5 -r /System/Library/Caches/com.apple.kernelcaches/kernelcache.86C01707' >> $L 2>&1
  g5 'sudo touch /System/Library/Extensions && echo touched' >> $L 2>&1
  log "restore files done; reboot 1"
  if reboot_to; then
    g5 'kextstat | grep X1000' >> $L 2>&1; log "reboot 2"
    sleep 60
    if reboot_to; then
      g5 'uptime; kextstat | grep X1000; md5 -r /System/Library/Extensions/ATIRadeonX1000.kext/Contents/MacOS/ATIRadeonX1000 /System/Library/Caches/com.apple.kernelcaches/kernelcache.86C01707; ls -l /Library/Logs/panic.log' >> $L 2>&1
      # 3. baseline check
      g5 'cd $HOME/rung3/src_6842a99/Tests && sh compare_to_baseline.sh 2>&1 | tail -1; DEEP=1 sh compare_to_baseline.sh 2>&1 | tail -1' >> $L 2>&1
      # 4. stock matrix from Tiger HD
      log "starting stock Doom 3 matrix"
      $K/Tools/gamefps/doom3_run_side.sh $D3 stock 3 >> $L 2>&1
      grep -E "^done stock|ABORT" $D3/driver.log | tail -2 >> $L
    else log "second reboot failed (G5 not back in 25 min)"; DOWN=1; fi
  else log "first reboot failed (G5 not back in 25 min)"; DOWN=1; fi
fi
# 5. Desktop comparison file
python3 -I $K/Tools/gamefps/make_comparison_report.py $UT $D3 "$HOME/Desktop/G5_game_benchmark_comparison.md" "${DOWN:-0}" >> $L 2>&1
log "report written"
# 6. shut down
if [ -z "$DOWN" ]; then
  g5 'sudo shutdown -h now' >> $L 2>&1; log "shutdown issued"
  sleep 120; if ping -c2 -W2 192.168.5.83 >/dev/null 2>&1; then log "G5 still answers ping after shutdown"; else log "G5 no longer answers ping (shut down)"; fi
fi
{ echo; echo "## Final G5 state"; echo '```'; grep -E "restore|reboot|Test HD missing|IDENTICAL|DIFFER|panic.log|X1000|shutdown|ping|unreachable|ABORT|done " $L | tail -40; echo '```'; } >> "$HOME/Desktop/G5_game_benchmark_comparison.md"
log "chain done"
