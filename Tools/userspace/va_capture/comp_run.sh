#!/bin/sh
# comp_run.sh NAME PICTURES [extra ava_drive args]  (dev machine) - issue #141 composite run in ONE ssh session (the G5 is slow to accept connections).
# The REAL VA flow with declare_image/delete_image (8, 9), stamps (19, 20), doIDCT (18) and the type-1 command-buffer submit (GUARD_FWD_REMAP=1) forwarded (override the selector list with GFSET=..),
# so the kernel really runs the DVD command buffers; --getframe MODE reads the decoded frame back through DVDDriverGetFrameImpl, --dump-images dumps the declare_image buffers.
# Sources travel as a tar stream on ssh's stdin, results come back as a tar stream on stdout: nothing else touches the network. Output lands in captures/comp/NAME/.
# Stages into ~/rung3/{va,Tests} on the G5 (persistent: /tmp is wiped by a reboot). FWDREMAP=0 disables the type-1 submit forward (command buffers are logged, not executed). Example: sh comp_run.sh g1 11 --getframe 8   (picture 11 = R3i chroma probe)
# Heavy #87 checks (diskutil verifyVolume) are not per run: do them once per boot and after any anomaly.
N=$1; P=$2; shift; shift
D=$(cd "$(dirname "$0")" && pwd); OUT=$D/captures/comp/$N; mkdir -p $OUT
(cd $D && python3 gen_ava_vectors.py . >/dev/null) || exit 1
ARGS="$*"
STG=$(mktemp -d); mkdir -p $STG/va $STG/Tests/destructive; cp $D/ava_vectors.h $D/ava_drive.c $D/iokit_guard_va.c $D/run_rung3.sh $D/comp_remote.sh $STG/va/; R=$(cd "$D/../../.." && pwd)
cp $R/Tests/common.h $STG/Tests/; cp $R/Tests/destructive/regsnap.c $R/Tests/destructive/dtest.h $STG/Tests/destructive/ 2>/dev/null
( cd $STG && tar cf - va Tests ) | \
  ssh -o ConnectTimeout=60 -o ServerAliveInterval=15 G5 "mkdir -p \$HOME/rung3 && cd \$HOME/rung3 && tar xf - && cd va && GFSET='$GFSET' FWDREMAP='${FWDREMAP:-1}' DELAYMS='$DELAYMS' GENV='$GENV' WATCHDOG_S='$WATCHDOG_S' sh ./comp_remote.sh $N $P $ARGS; tar cf - ${N}_* $N.out $N.tsv $N.tsv.mem 2>/dev/null" | \
  tar xf - -C $OUT 2>&1
cat $OUT/${N}_wrapper.log 2>/dev/null
grep -E 'RESULT|EXIT|dump-images|WATCHDOG|GetFrame|rc=' $OUT/$N.out 2>/dev/null | cut -c1-200
cat $OUT/${N}_regdiff.txt 2>/dev/null | head -5
