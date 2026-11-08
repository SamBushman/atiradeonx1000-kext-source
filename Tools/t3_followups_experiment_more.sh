#!/bin/sh
# t3_followups_experiment_more.sh EVDIR N   (dev machine) - waits for "ALL DONE" in EVDIR/followups.log (Tools/t3_followups_after_phase6.sh), then N more t3_gl_read_buffer_source boots on stock and N on rebuilt (one per boot, each ends with a reboot). Why: the first four runs (Nov 8) had a palindromic top-to-bottom content on both stock boots (ff,f6,f6,ff), which cannot show a vertical flip, while both rebuilt boots showed read_buffer reversed relative to surface_read; stock orientation needs a non-palindromic stock sample (EVIDENCE.md).
EV=${1:?EVDIR}; N=${2:-3}; SRC_EXP=${SRC_EXP:-src_exp053687b0}; KEXT=${KEXT:-kext_build_9904dde8}; T=$(dirname "$0")
until grep -q 'ALL DONE' "$EV/followups.log" 2>/dev/null; do sleep 60; done
i=0; while [ $i -lt $N ]; do i=$((i+1))
  for arm in stock rebuilt; do
    echo "$(date +%H:%M) more: $arm $i" >> "$EV/followups_more.log"
    env SRC=$SRC_EXP KEXT=$KEXT sh $T/t3_experiment_one.sh t3_gl_read_buffer_source $arm reboot >> "$EV/followups_more.log" 2>&1; rc=$?
    echo "$(date +%H:%M) rc=$rc" >> "$EV/followups_more.log"
    case $rc in 2|3|5) echo "STOP rc=$rc" >> "$EV/followups_more.log"; exit $rc;; esac
  done
done
echo "ALL DONE $(date)" >> "$EV/followups_more.log"
