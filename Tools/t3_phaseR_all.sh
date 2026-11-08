#!/bin/sh
# t3_phaseR_all.sh  (dev machine) - the whole T3 checklist (#122 criterion 3) against the rebuilt kext, strict protocol: ONE test per boot, reboot after each.
# Runs Tools/t3_phaseR_one.sh NAME reboot for every name in Tests/destructive/t3_list.txt and stops at the first HANG (exit 3); DIVERGENCEs are collected and the run continues.
# t3_dvd_idct_lock_leak is Phase C (#93) and is not in the list. Summary: ~/g5logs/t3_phaseR/summary.tsv. After ANY hang: pull /Library/Logs/panic.log, diskutil verifyVolume (README.md reset procedure).
# Resume: FROM=NAME skips every test before NAME and keeps the existing summary.tsv (use after a false HANG: the G5 answers again, the earlier tests stand).
cd "$(dirname "$0")/.." || exit 2; mkdir -p $HOME/g5logs/t3_phaseR; S=$HOME/g5logs/t3_phaseR/summary.tsv; [ -n "$FROM" ] || : > $S
started=; [ -n "$FROM" ] || started=1
for n in $(grep -v '^#' Tests/destructive/t3_list.txt); do
    [ -n "$started" ] || { [ "$n" = "$FROM" ] && started=1; }; [ -n "$started" ] || continue
    sh Tools/t3_phaseR_one.sh $n reboot; rc=$?
    printf '%s\t%s\t%s\n' "$n" "$rc" "$(date +%H:%M)" >> $S
    [ $rc = 3 ] && { echo "HANG in $n: stopping (needs power-cycle)"; exit 3; }
done
cat $S
