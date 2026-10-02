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
# A step that exits non-zero, or whose output differs from its reference, stops the soak with exit 1 (the log has the output), with ONE exception - the TRANSIENT RETRY RULE (#43, 2026-10-02):
# if every difference from the reference is a DVD-context line whose new result is NotReady (0xe00002d8), the accelerator's "hardware up" flag was briefly down (a display reconfiguration;
# see V11 in Tests/known_vendor_deviations.md and Tests/hwup_sampler.c). The step is then rerun after RETRY_WAIT seconds (default 2), up to RETRIES times (default 3); the soak continues only if
# a rerun matches the reference exactly. Each retry and each recovery is logged (TRANSIENT / TRANSIENT-RECOVERED), a difference that persists is still a STEP-DIFF failure, and ANY other kind of
# difference (a different code, a different value, a non-DVD line) fails at once. Optional budget: TRANSIENT_MAX_PER_HOUR=N (default 0 = off) fails the soak if recovered transients exceed
# N x (elapsed hours + 1), so the rule cannot hide an instability that recurs. The watchdog (Tools/stability_watch.sh, on the dev machine)
# is what notices a hang or panic, since a hung G5 cannot report its own hang. Needs perf_baseline and parity_test_harness built
# (gcc -arch ppc -std=gnu99 perf_baseline.c -framework OpenGL -framework ApplicationServices; make).
D=${1:-3600}; LOG=${LOG:-/tmp/soak.log}; GLN=${GLN:-50}; RETRIES=${RETRIES:-3}; RETRY_WAIT=${RETRY_WAIT:-2}; TRANSIENT_MAX_PER_HOUR=${TRANSIENT_MAX_PER_HOUR:-0}
PERF_CMD=${PERF_CMD:-./perf_baseline}; PARITY_CMD=${PARITY_CMD:-./parity_test_harness}   # overridable so the retry rule can be tested with a fake harness
transients=0
start=`date +%s`; round=0; : > "$LOG"
note() { echo "`date '+%Y-%m-%dT%H:%M:%S'` $*" >> "$LOG"; }
note "SOAK START duration=${D}s gln=$GLN kext=`kextstat 2>/dev/null | grep ' com.apple.ATIRadeonX1000 ' | awk '{print $3, $6}'`"
note "fingerprint: `sh ./machine_fingerprint.sh 2>&1 | tr '\n' '|'`"
# diagnostic only (changes no verdict): log every window in which the accelerator reports "hardware not up" (NotReady on the guarded DVD wrappers), see Tests/hwup_sampler.c and #43
if [ -x ./hwup_sampler ]; then ./hwup_sampler 50 300 > "$LOG.hwup" 2>&1 & HWUP=$!; trap 'kill $HWUP 2>/dev/null' 0; note "hwup_sampler started pid $HWUP -> $LOG.hwup"; fi
# 0 only if EVERY differing line (the "calls made" summary excluded, it carries the unexpected count) is a DVD line, and every new line's result is NotReady (0xe00002d8)
only_notready_dvd() { # $1 = reference, $2 = new output
  diff "$1" "$2" | grep '^[<>]' | grep -v 'calls made' > /tmp/soak_dl.$$
  [ -s /tmp/soak_dl.$$ ] || { rm -f /tmp/soak_dl.$$; return 1; }
  bad=0
  grep '^[<>]' /tmp/soak_dl.$$ | grep -v 'DVD' | grep -q . && bad=1
  grep '^>' /tmp/soak_dl.$$ | grep -v '0xe00002d8' | grep -q . && bad=1
  rm -f /tmp/soak_dl.$$; return $bad
}
step() { # step NAME REF COMMAND...   REF = "" (no reference check) or a reference file: created by the first run, compared on later ones
  n=$1; ref=$2; shift; shift; o=/tmp/soak_step.$$; "$@" > $o 2>&1; rc=$?
  # no reference: the exit status is the verdict. With a reference: the harness exits 1 when it reports unexpected results (a standing machine state, see above), so the verdict is
  # "it ran to its summary line" (a crash/hang would not print it) plus an exact match with the reference.
  if [ -z "$ref" ] && [ $rc -ne 0 ]; then note "STEP-FAIL $n rc=$rc"; tail -20 $o >> "$LOG"; rm -f $o; note "SOAK STOPPED round=$round"; exit 1; fi
  if [ -n "$ref" ] && ! grep -q "calls made" $o; then note "STEP-FAIL $n rc=$rc (no summary line: crashed or cut short)"; tail -20 $o >> "$LOG"; rm -f $o; note "SOAK STOPPED round=$round"; exit 1; fi
  if [ -n "$ref" ]; then
    if [ ! -f "$ref" ]; then cp $o "$ref"; note "reference saved $ref: `grep -E 'calls made' $o`"
    else
      tries=0
      while ! cmp -s $o "$ref"; do
        if only_notready_dvd "$ref" $o && [ $tries -lt $RETRIES ]; then
          tries=`expr $tries + 1`; note "TRANSIENT $n: only NotReady on DVD lines differs from the reference (hardware-up flag down); retry $tries/$RETRIES in ${RETRY_WAIT}s"; diff "$ref" $o | head -12 >> "$LOG"
          sleep $RETRY_WAIT; "$@" > $o 2>&1; rc=$?
          if ! grep -q "calls made" $o; then note "STEP-FAIL $n rc=$rc (no summary line on retry: crashed or cut short)"; tail -20 $o >> "$LOG"; rm -f $o; note "SOAK STOPPED round=$round"; exit 1; fi
        else
          note "STEP-DIFF $n differs from $ref (retries used: $tries)"; diff "$ref" $o | head -20 >> "$LOG"; rm -f $o; note "SOAK STOPPED round=$round"; exit 1
        fi
      done
      if [ $tries -gt 0 ]; then
        transients=`expr $transients + 1`; note "TRANSIENT-RECOVERED $n after $tries retr(y/ies); transients so far: $transients"
        if [ "$TRANSIENT_MAX_PER_HOUR" -gt 0 ]; then
          allowed=`expr $TRANSIENT_MAX_PER_HOUR \* \( \( \`date +%s\` - $start \) / 3600 + 1 \)`
          if [ $transients -gt $allowed ]; then note "TRANSIENT-BUDGET exceeded: $transients > $allowed allowed at this point"; rm -f $o; note "SOAK STOPPED round=$round"; exit 1; fi
        fi
      fi
    fi
  fi
  note "ok $n"; rm -f $o
}
while [ `expr \`date +%s\` - $start` -lt "$D" ]; do
  round=`expr $round + 1`
  step "r$round perf_baseline" "" $PERF_CMD $GLN   # its timings differ run to run; a crash or a failed CGL call is its failure (exit status)
  step "r$round parity" /tmp/soak_ref_parity.$$ $PARITY_CMD
  step "r$round deep" /tmp/soak_ref_deep.$$ $PARITY_CMD --deep
done
rm -f /tmp/soak_ref_parity.$$ /tmp/soak_ref_deep.$$
note "SOAK DONE rounds=$round elapsed=`expr \`date +%s\` - $start`s transients_recovered=$transients"
echo "SOAK DONE rounds=$round"
