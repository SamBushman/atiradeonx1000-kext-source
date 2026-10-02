#!/bin/sh
# Tests/soak.sh - issue #43: the sustained-usage workload of the stability regimen. Runs ON the G5 from this directory (Tests/) against whichever
# com.apple.ATIRadeonX1000 is loaded (stock now, the rebuilt kext in #45), for DURATION seconds, and writes one timestamped line per step to LOG.
#   sh soak.sh [DURATION_SECONDS=3600]        env: LOG=/tmp/soak.log  GLN=50 (GL create/draw/readback/destroy cycles per perf_baseline step)
# Each round: perf_baseline $GLN  (GL context + pbuffer churn: the userspace GL path and the kext's GL/Surface contexts)
#             parity_test_harness          (every external method of the four contexts, 87 calls: connection open/close churn)
#             parity_test_harness --deep   (the T1 deep paths: real register reads, surface bind/unbind)
# It only uses calls already proven safe on stock (no destructive-protocol tests: those are one-per-boot by #87 and never belong in a soak).
# Stability is judged by SELF-CONSISTENCY, not by the recorded stock baseline: the first harness outputs of the soak are saved as the reference and every later round must reproduce them
# exactly. (The recorded baseline depends on display state: e.g. Surface set_id_mode(1,0x0) only succeeds while display record 1 is unconfigured, and a display mode set on wake
# makes it return Error - see #42. Comparing to the baseline would flag the machine's state, not the driver.) The number of "unexpected" results in the reference is logged as a NOTE.
# A step that exits non-zero, or whose output differs from its reference, stops the soak with exit 1 (the log has the output). The watchdog (Tools/stability_watch.sh, on the dev machine)
# is what notices a hang or panic, since a hung G5 cannot report its own hang. Needs perf_baseline and parity_test_harness built
# (gcc -arch ppc -std=gnu99 perf_baseline.c -framework OpenGL -framework ApplicationServices; make).
D=${1:-3600}; LOG=${LOG:-/tmp/soak.log}; GLN=${GLN:-50}
start=`date +%s`; round=0; : > "$LOG"
note() { echo "`date '+%Y-%m-%dT%H:%M:%S'` $*" >> "$LOG"; }
note "SOAK START duration=${D}s gln=$GLN kext=`kextstat 2>/dev/null | grep ' com.apple.ATIRadeonX1000 ' | awk '{print $3, $6}'`"
note "fingerprint: `sh ./machine_fingerprint.sh 2>&1 | tr '\n' '|'`"
step() { # step NAME REF COMMAND...   REF = "" (no reference check) or a reference file: created by the first run, compared on later ones
  n=$1; ref=$2; shift; shift; o=/tmp/soak_step.$$; "$@" > $o 2>&1; rc=$?
  # no reference: the exit status is the verdict. With a reference: the harness exits 1 when it reports unexpected results (a standing machine state, see above), so the verdict is
  # "it ran to its summary line" (a crash/hang would not print it) plus an exact match with the reference.
  if [ -z "$ref" ] && [ $rc -ne 0 ]; then note "STEP-FAIL $n rc=$rc"; tail -20 $o >> "$LOG"; rm -f $o; note "SOAK STOPPED round=$round"; exit 1; fi
  if [ -n "$ref" ] && ! grep -q "calls made" $o; then note "STEP-FAIL $n rc=$rc (no summary line: crashed or cut short)"; tail -20 $o >> "$LOG"; rm -f $o; note "SOAK STOPPED round=$round"; exit 1; fi
  if [ -n "$ref" ]; then
    if [ ! -f "$ref" ]; then cp $o "$ref"; note "reference saved $ref: `grep -E 'calls made' $o`"
    elif ! cmp -s $o "$ref"; then note "STEP-DIFF $n differs from $ref"; diff "$ref" $o | head -20 >> "$LOG"; rm -f $o; note "SOAK STOPPED round=$round"; exit 1; fi
  fi
  note "ok $n"; rm -f $o
}
while [ `expr \`date +%s\` - $start` -lt "$D" ]; do
  round=`expr $round + 1`
  step "r$round perf_baseline" "" ./perf_baseline $GLN   # its timings differ run to run; a crash or a failed CGL call is its failure (exit status)
  step "r$round parity" /tmp/soak_ref_parity.$$ ./parity_test_harness
  step "r$round deep" /tmp/soak_ref_deep.$$ ./parity_test_harness --deep
done
rm -f /tmp/soak_ref_parity.$$ /tmp/soak_ref_deep.$$
note "SOAK DONE rounds=$round elapsed=`expr \`date +%s\` - $start`s"
echo "SOAK DONE rounds=$round"
