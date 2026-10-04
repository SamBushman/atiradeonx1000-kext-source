#!/bin/sh
# px_run.sh NAME PICTURE_INDEX [extra ava_drive args]  (dev machine) - one rung-3 pixel experiment under the #87 gates: peer ack, preflight, forwarded doIDCT into slot 0 (--dst -10), GL read-back,
# fetch the dumps, decode with decode_px.py. Needs the ava_drive/guard build on the G5 (/tmp/rung3/va) and the Tests tree (/tmp/rung3/Tests).
N=$1; P=$2; shift; shift
D=$(cd "$(dirname "$0")" && pwd); R=$(cd "$D/../../.." && pwd); OUT=$D/captures/rung3/rb; mkdir -p $OUT
(cd $R && sh Tests/destructive/peer_ack.sh G5 /tmp/rung3/Tests/destructive 2>&1 | head -1)
scp -q $D/ava_vectors.h G5:/tmp/rung3/va/ && ssh G5 'cd /tmp/rung3/va && gcc -o ava_drive ava_drive.c -F/System/Library/PrivateFrameworks -framework AppleVA -framework ApplicationServices -framework IOKit 2>&1 | grep -v warning'
ssh G5 "cd /tmp/rung3/Tests/destructive && sh preflight.sh px_$N 2>&1 | tail -1"
ssh G5 "osascript -e \"tell application \\\"Terminal\\\" to do script \\\"GF=18 $PX_ENV WIN_X=800 WIN_Y=500 sh /tmp/rung3/va/run_rung3.sh $N --pictures $P --dst -10 --readback --hold-after 2 $*\\\"\" >/dev/null 2>&1"
for i in `seq 1 90`; do ssh -o ConnectTimeout=10 G5 "grep -q 'EXIT=' /tmp/rung3/va/$N.out 2>/dev/null" && break; sleep 1; done
ssh G5 "grep -E 'RESULT|EXIT' /tmp/rung3/va/$N.out /tmp/rung3/va/$N.tsv | cut -c1-170"
for f in before_s1 after_s1; do scp -q "G5:/tmp/rung3/va/${N}_$f.bin" $OUT/; done; for f in $(ssh G5 "ls /tmp/rung3/va/${N}_*_s*.bin 2>/dev/null" | xargs -n1 basename); do scp -q "G5:/tmp/rung3/va/$f" $OUT/ 2>/dev/null; done; cp $OUT/${N}_before_s1.bin $OUT/${N}_before.bin 2>/dev/null; cp $OUT/${N}_after_s1.bin $OUT/${N}_after.bin 2>/dev/null; scp -q G5:/tmp/rung3/va/$N.out G5:/tmp/rung3/va/$N.tsv $D/captures/rung3/ 2>/dev/null
ssh G5 "cd /tmp/rung3/Tests/destructive && ./regsnap | diff results/px_$N/pre.regs - | grep '^>' | tr '\n' ' '; echo; sh postflight.sh px_$N 2>&1 | tail -2"
python3 $D/decode_px.py $OUT/${N}_before.bin $OUT/${N}_after.bin $P
