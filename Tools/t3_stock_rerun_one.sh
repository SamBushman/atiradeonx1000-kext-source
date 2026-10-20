#!/bin/sh
# t3_stock_rerun_one.sh NAME [reboot]   (dev machine) - the same T3 test and protocol as t3_phaseR_one.sh but with the CURRENT test binary on the hot-swapped STOCK kext (kext_dir stockkext, --kext stock), compared with the rebuilt run's normalised result in ~/g5logs/t3_phaseR/NAME.rebuilt.norm.
# Why: the recorded Phase S logs date from Oct 2; five T3 sources changed afterwards (Oct 5-13), so a diff against them is not like for like. Output: ~/g5logs/t3_phaseR_stockrerun/NAME.*; exit codes as t3_phaseR_one.sh (0 = same as the rebuilt run).
# Protocol of Tests/destructive/README.md (#87): ONE test per boot. Start from a clean boot with the stock kext loaded; this script hot-swaps the staged rebuilt kext, runs the unstick step
# (#157), builds, acknowledges, preflight -> test -> postflight, and compares the RESULT/NOTE lines with the Phase S log. With "reboot" it reboots the G5 afterwards and waits for ssh.
#   env: SRC (staged tree dir on the G5, default newest ~/rung3/src_*), KEXT (staged kext dir name, default kext_build_<sha of SRC>), H (host, default G5)
# Output: ~/g5logs/t3_phaseR/NAME.{out,diff,mirror}; exit 0 = same as stock, 1 = differs (a DIVERGENCE: file an issue), 3 = G5 stopped answering (HANG: do not touch it; check panic.log after power-cycle).
# NOT yet exercised end to end on the G5 (written Oct 18): run the first test by hand-watching it.
N=${1:?usage: t3_phaseR_one.sh NAME [reboot]}; REBOOT=$2; H=${H:-G5}; OUT=$HOME/g5logs/t3_phaseR_stockrerun; RB=$HOME/g5logs/t3_phaseR; mkdir -p "$OUT"
SRC=${SRC:-$(ssh $H 'ls -dt $HOME/rung3/src_* | grep -v tgz | head -1' | sed 's|.*/||')}; SHA=${SRC#src_}; KEXT=stockkext
D="rung3/$SRC/Tests/destructive"; ME=$(ssh $H 'echo $SSH_CLIENT' | cut -d' ' -f1)
echo "T3 $N: tree $SRC kext $KEXT"
ssh $H 'kextstat | grep -i " com.apple.ATIRadeonX1000 "' | grep -q . || { echo "stock kext is not loaded: reboot first"; exit 2; }
ssh $H "cd $D && ls phaseS/t3_${N}_stock_*.log >/dev/null 2>&1" || { echo "no Phase S log for $N in $D/phaseS (copy rung3/srchead/Tests/destructive/phaseS)"; exit 2; }
ssh $H "sh \$HOME/rung3/swap.sh $KEXT 2>&1 | tail -2; cd \$HOME/rung3/$SRC && sh Tools/issue157_unstick_hotswap/unstick_hotswap_vram.sh 2>&1 | tail -3"
: > "$OUT/$N.mirror"; python3 "$(dirname "$0")/../Tests/destructive/udp_listen.py" "$OUT/$N.mirror" & LP=$!
ssh $H "cd $D && rm -rf results/t3_$N* && mkdir -p results && make destructive-t3_$N 2>&1 | grep -E ' error|Error'; make regsnap >/dev/null 2>&1; touch results/peer_ack" 
ssh $H "cd $D && sh preflight.sh t3_$N 2>&1 | tail -3; ./t3_$N --phase R --kext stock --mirror $ME:9999 --i-understand-this-may-hang-the-machine 2>&1; echo TEST_EXIT=\$?; sh postflight.sh t3_$N 2>&1 | tail -15" > "$OUT/$N.out" 2>&1 &
SP=$!; i=0; down=0
while kill -0 $SP 2>/dev/null; do
    sleep 10; i=$((i+10))
    if [ $((i % 60)) -eq 0 ]; then
        if timeout 25 ssh -o ConnectTimeout=20 $H true >/dev/null 2>&1; then down=0; else down=$((down+60)); fi
        [ $down -ge 300 ] && { echo "G5 UNRESPONSIVE $down s: possible HANG. Last mirrored lines:"; tail -3 "$OUT/$N.mirror"; kill $LP 2>/dev/null; exit 3; }
    fi
    [ $i -ge 3600 ] && { echo "session open > 1 h"; kill $LP 2>/dev/null; exit 5; }
done
kill $LP 2>/dev/null
NEW=$(ssh $H "cd $D && ls -t results/t3_${N}_stock_*.log | head -1"); OLD=$(ssh $H "cd $D && ls -t phaseS/t3_${N}_stock_*.log | tail -1")
norm() { ssh $H "cd $D && cat $1" | sed 's/^[^ ]* \[[^]]*\] //' | grep -E "^(RESULT|NOTE)" | grep -v "^NOTE start:"; }
norm "$NEW" > "$OUT/$N.stockhs.norm"; cp "$RB/$N.rebuilt.norm" "$OUT/$N.rebuilt.norm"
if diff "$OUT/$N.stockhs.norm" "$OUT/$N.rebuilt.norm" > "$OUT/$N.diff"; then echo "T3 $N: SAME AS REBUILT RUN ($(ssh $H "cd $D && tail -1 $NEW | cut -c1-120"))"; rc=0; else echo "T3 $N: DIFFERS from rebuilt run:"; head -20 "$OUT/$N.diff"; rc=1; fi
if [ "$REBOOT" = reboot ]; then
    ssh $H 'sudo shutdown -r now' >/dev/null 2>&1; sleep 60
    until timeout 20 ssh -o ConnectTimeout=15 $H 'ls "/Volumes/Test HD/rung3" >/dev/null' >/dev/null 2>&1; do sleep 15; done; echo "G5 back up after reboot"
fi
exit $rc
