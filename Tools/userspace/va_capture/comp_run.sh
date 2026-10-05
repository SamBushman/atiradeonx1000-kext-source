#!/bin/sh
# comp_run.sh NAME PICTURES [extra ava_drive args]  (dev machine) - issue #141 composite run in ONE ssh session (the G5 is slow to accept connections).
# The REAL VA flow with declare_image/delete_image (8, 9), stamps (19, 20), doIDCT (18) and the type-1 command-buffer submit (GUARD_FWD_REMAP=1) forwarded (override the selector list with GFSET=..),
# so the kernel really runs the DVD command buffers; --getframe MODE reads the decoded frame back through DVDDriverGetFrameImpl, --dump-images dumps the declare_image buffers.
# Sources travel as a tar stream on ssh's stdin, results come back as a tar stream on stdout: nothing else touches the network. Output lands in captures/comp/NAME/.
# Needs /tmp/rung3/va and /tmp/rung3/Tests on the G5 (see px_run.sh). Example: sh comp_run.sh g1 11 --getframe 8   (picture 11 = R3i chroma probe)
# Heavy #87 checks (diskutil verifyVolume) are not per run: do them once per boot and after any anomaly.
N=$1; P=$2; shift; shift
D=$(cd "$(dirname "$0")" && pwd); OUT=$D/captures/comp/$N; mkdir -p $OUT
(cd $D && python3 gen_ava_vectors.py . >/dev/null) || exit 1
ARGS="$*"
( cd $D && tar cf - ava_vectors.h ava_drive.c iokit_guard_va.c run_rung3.sh comp_remote.sh ) | \
  ssh -o ConnectTimeout=60 -o ServerAliveInterval=15 G5 "cd /tmp/rung3/va && tar xf - && GFSET='$GFSET' WATCHDOG_S='$WATCHDOG_S' sh ./comp_remote.sh $N $P $ARGS; tar cf - ${N}_* $N.out $N.tsv $N.tsv.mem 2>/dev/null" | \
  tar xf - -C $OUT 2>&1
cat $OUT/${N}_wrapper.log 2>/dev/null
grep -E 'RESULT|EXIT|dump-images|WATCHDOG|GetFrame|rc=' $OUT/$N.out 2>/dev/null | cut -c1-200
cat $OUT/${N}_regdiff.txt 2>/dev/null | head -5
