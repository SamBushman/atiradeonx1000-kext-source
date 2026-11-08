#!/bin/sh
# t3_experiment_one.sh NAME stock|rebuilt [reboot]   (dev machine) - run ONE experiment test (Tests/destructive/NAME.c, not a checklist test: no Phase S log, no pass/fail compare) on the hot-swapped
# STOCK kext (kext dir stockkext) or the staged REBUILT kext, with a full-screen screenshot taken on the G5 right before and right after the test (screencapture -x over ssh captures the framebuffer).
# Same protocol as t3_phaseR_one.sh (#87): ONE test per boot, start from a clean boot with the stock kext loaded. Output: ~/g5logs/t3_experiments/NAME_ARM_<UTC time>/{NAME.out,NAME.mirror,NAME.log,before.png,after.png}.
# Then: python3 Tools/t3_read_buffer_source_analyze.py <that dir>  (for NAME=t3_gl_read_buffer_source). Exit: 0 ran, 2 precondition failed, 3 G5 stopped answering (check it before believing; Tools/t3_phaseR_one.sh rc 3 notes), 5 session > 1 h.
#   env: SRC (staged tree on the G5, default newest ~/rung3/src_*), KEXT (rebuilt kext dir, default kext_build_<sha of SRC>), H (host, default G5)
N=${1:?usage: t3_experiment_one.sh NAME stock|rebuilt [reboot]}; ARM=${2:?stock|rebuilt}; REBOOT=$3; H=${H:-G5}
SRC=${SRC:-$(ssh $H 'ls -dt $HOME/rung3/src_* | grep -v tgz | head -1' | sed 's|.*/||')}; SHA=${SRC#src_}
case $ARM in stock) KEXT=stockkext;; rebuilt) KEXT=${KEXT:-kext_build_$SHA};; *) echo "ARM must be stock or rebuilt"; exit 2;; esac
OUT=$HOME/g5logs/t3_experiments/${N}_${ARM}_$(date -u +%Y%m%dT%H%M%SZ); mkdir -p "$OUT"
D="rung3/$SRC/Tests/destructive"; ME=$(ssh $H 'echo $SSH_CLIENT' | cut -d' ' -f1)
echo "experiment $N arm $ARM: tree $SRC kext $KEXT -> $OUT"
ssh $H 'kextstat | grep -i " com.apple.ATIRadeonX1000 "' | grep -q . || { echo "stock kext is not loaded: reboot first"; exit 2; }
ssh $H "sh \$HOME/rung3/swap.sh $KEXT 2>&1 | tail -2; cd \$HOME/rung3/$SRC && sh Tools/issue157_unstick_hotswap/unstick_hotswap_vram.sh 2>&1 | tail -3"
: > "$OUT/$N.mirror"; python3 "$(dirname "$0")/../Tests/destructive/udp_listen.py" "$OUT/$N.mirror" & LP=$!
ssh $H "cd $D && rm -rf results/${N}* results/t3_${N}* results/shot_*.png && mkdir -p results && make destructive-$N 2>&1 | grep -E ' error|Error'; make regsnap >/dev/null 2>&1; touch results/peer_ack"
ssh $H "cd $D && sh preflight.sh $N 2>&1 | tail -3; screencapture -x results/shot_before.png; ./$N --phase R --kext $ARM --mirror $ME:9999 --i-understand-this-may-hang-the-machine 2>&1; echo TEST_EXIT=\$?; screencapture -x results/shot_after.png; sh postflight.sh $N 2>&1 | tail -15" > "$OUT/$N.out" 2>&1 &
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
LOG=$(ssh $H "cd $D && ls -t results/${N}_${ARM}_*.log results/t3_${N}_${ARM}_*.log 2>/dev/null | head -1")
[ -n "$LOG" ] && ssh $H "cd $D && cat $LOG" > "$OUT/$N.log"
scp -q $H:"$D/results/shot_before.png" "$OUT/before.png"; scp -q $H:"$D/results/shot_after.png" "$OUT/after.png"
echo "experiment $N arm $ARM: done; $(grep -c ' NOTE obs ' "$OUT/$N.log" 2>/dev/null) obs lines, log $LOG"
if [ "$REBOOT" = reboot ]; then
    ssh $H 'sudo shutdown -r now' >/dev/null 2>&1; sleep 60
    until timeout 20 ssh -o ConnectTimeout=15 $H 'ls "/Volumes/Test HD/rung3" >/dev/null' >/dev/null 2>&1; do sleep 15; done; echo "G5 back up after reboot"
fi
exit 0
