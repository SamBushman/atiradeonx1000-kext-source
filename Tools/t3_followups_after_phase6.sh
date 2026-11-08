#!/bin/sh
# t3_followups_after_phase6.sh EVDIR   (dev machine) - the open follow-ups recorded in Tests/destructive/phaseS_rerun/EVIDENCE.md, one test per boot, each ending with a reboot:
#   1. t3_gl_read_buffer_source experiment on stock x2 then rebuilt x2 (Tools/t3_experiment_one.sh; output ~/g5logs/t3_experiments/)
#   2. dvd_write_regs_scratch on stock x3 (Tools/t3_stock_rerun_one.sh) then rebuilt x2 (Tools/t3_phaseR_one.sh); output EVDIR/dvd_write_regs_scratch/{stock1..3,rebuilt1..2}/ (the OUT / RB overrides keep the Nov 3 and Nov 7 reference files untouched)
# Stops at the first rc 2 / 3 / 5 (precondition, possible hang, session > 1 h): check the G5 before restarting. Env: SRC_EXP (tree holding the experiment, default src_exp053687b0), SRC (tree of the evaluated tests, default src_9904dde8), KEXT (default kext_build_9904dde8).
EV=${1:?usage: t3_followups_after_phase6.sh EVDIR}; SRC_EXP=${SRC_EXP:-src_exp053687b0}; SRC=${SRC:-src_9904dde8}; KEXT=${KEXT:-kext_build_9904dde8}; T=$(dirname "$0")
mkdir -p "$EV"; echo "start $(date)" >> "$EV/followups.log"
run() { echo "$(date +%H:%M) $*" >> "$EV/followups.log"; "$@" >> "$EV/followups.log" 2>&1; rc=$?; echo "$(date +%H:%M) rc=$rc" >> "$EV/followups.log"; case $rc in 2|3|5) echo "STOP rc=$rc" >> "$EV/followups.log"; exit $rc;; esac; }
for i in 1 2; do run env SRC=$SRC_EXP sh $T/t3_experiment_one.sh t3_gl_read_buffer_source stock reboot; done
for i in 1 2; do run env SRC=$SRC_EXP KEXT=$KEXT sh $T/t3_experiment_one.sh t3_gl_read_buffer_source rebuilt reboot; done
for i in 1 2 3; do run env SRC=$SRC OUT=$EV/dvd_write_regs_scratch/stock$i sh $T/t3_stock_rerun_one.sh dvd_write_regs_scratch reboot; done
for i in 1 2; do run env SRC=$SRC KEXT=$KEXT OUT=$EV/dvd_write_regs_scratch/rebuilt$i sh $T/t3_phaseR_one.sh dvd_write_regs_scratch reboot; done
echo "ALL DONE $(date)" >> "$EV/followups.log"
