#!/bin/sh
# Tests/destructive/run_t3.sh NAME [reboot]   (dev machine; issue #87 protocol driver for the T3 tests of #100)
# Copies Tests/ to the G5, builds NAME, writes the peer acknowledgement, mirrors the write-ahead log to a local UDP listener, runs preflight -> the test
# (phase S, stock kext) -> postflight over ssh, then (optional) reboots the G5 and waits for ssh to come back. Output: /tmp/t3_NAME.{mirror,out}.
# A hung G5 shows up as the ssh session never returning: this script then prints the last mirrored line (the call in flight) and exits 3 WITHOUT touching the machine.
N=${1:?usage: run_t3.sh NAME [reboot]}; REBOOT=$2
H=G5; D="/Volumes/Test HD/ati-parity/Tests/destructive"; ME=`ssh $H 'echo $SSH_CLIENT' | cut -d' ' -f1`
S=${SCRATCH:-/tmp}; OUT=$S/t3_$N.out; MIR=$S/t3_$N.mirror; : > $MIR
tar czf $S/t3_tests.tgz Tests && scp -q $S/t3_tests.tgz $H:/tmp/t3_tests.tgz || exit 1
ssh $H "cd '/Volumes/Test HD/ati-parity' && tar xzf /tmp/t3_tests.tgz && cd Tests/destructive && make destructive-$N 2>&1 | grep -E ' error|Error' ; make regsnap >/dev/null 2>&1; ls $N >/dev/null" || { echo "build failed"; exit 1; }
sh Tests/destructive/peer_ack.sh $H "$D" || exit 1
python3 Tests/destructive/udp_listen.py $MIR &
LP=$!
ssh $H "cd '$D' && rm -rf results/$N; sh preflight.sh $N 2>&1 && screencapture -x /tmp/t3_$N.before.png; ./$N --phase S --kext stock --mirror $ME:9999 --i-understand-this-may-hang-the-machine 2>&1; echo TEST_EXIT=\$?; screencapture -x /tmp/t3_$N.after.png; sh postflight.sh $N 2>&1" > $OUT 2>&1 &
SP=$!
# wait up to 240 s for the ssh session to finish
i=0; while kill -0 $SP 2>/dev/null && [ $i -lt 240 ]; do sleep 2; i=$((i+2)); done
if kill -0 $SP 2>/dev/null; then echo "NO RESPONSE after 240 s: possible HANG. Last mirrored lines:"; tail -3 $MIR; kill $LP 2>/dev/null; exit 3; fi
kill $LP 2>/dev/null
cat $OUT | tail -30
echo "--- mirror tail"; tail -5 $MIR
if [ "$REBOOT" = reboot ]; then
    echo "rebooting G5"; ssh $H 'sudo shutdown -r now' >/dev/null 2>&1
    sleep 60; i=0; until ssh -o ConnectTimeout=5 $H 'uptime' >/dev/null 2>&1; do sleep 10; i=$((i+10)); [ $i -gt 600 ] && { echo "G5 did not come back in 10 min"; exit 4; }; done
    echo "G5 back: `ssh $H uptime`"
fi
