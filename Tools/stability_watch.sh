#!/bin/sh
# stability_watch.sh - issue #43 criterion 2: automatic crash / hang / reboot detection for a soak or stress run on the G5. Runs on the DEV machine, read-only on the G5.
#   Tools/stability_watch.sh [-i SECONDS] [-d TOTAL_SECONDS] [-m MISSES] [-l LOGFILE] [HOST]
# Every interval it makes ONE short ssh and records: uptime-in-seconds, whether the ATIRadeonX1000 kext is loaded (and its load address), the number of crashdump processes,
# and the size of /Library/Logs/panic.log. Verdicts (first one wins; the script stops and prints it):
#   HANG     the G5 failed to answer ssh MISSES times in a row (default 5) - a hung kernel or a dead network; the run's last good sample is printed
#   REBOOT   uptime went backwards (the machine restarted: a panic recovered by auto-restart, or a manual power-cycle)
#   PANIC    panic.log grew since the first sample (read it with Tools/panic_symbolicate.py once the G5 is back)
#   KEXT     the ATIRadeonX1000 kext disappeared or moved to a different load address
#   CRASHDUMP  a crashdump process appeared that was not there at the start (crashreporterd saw a crash/hang; they pin a core and compound - see the tiger-ssh skill)
#   OK       the requested duration elapsed with none of the above
# Exit status: 0 OK, 3 HANG, 4 REBOOT, 5 PANIC, 6 KEXT, 7 CRASHDUMP. The TSV log (one line per sample) is the evidence; ssh banner timeouts during a busy G5 are normal, hence MISSES.
# Never changes anything on the G5. Pair it with a workload (Tests/soak_stock.sh) started separately.
INT=30; DUR=3600; MISS=5; LOG=/tmp/stability_watch.tsv; H=G5
while getopts i:d:m:l: o; do case $o in i) INT=$OPTARG;; d) DUR=$OPTARG;; m) MISS=$OPTARG;; l) LOG=$OPTARG;; *) exit 2;; esac; done
shift $((OPTIND-1)); [ -n "$1" ] && H=$1
probe() { # prints: UPTIME_S KEXT_ADDR CRASHDUMPS PANICLOG_BYTES   (one ssh, capped)
  timeout 40 ssh -o ConnectTimeout=20 -o BatchMode=yes "$H" '
    B=`sysctl -n kern.boottime 2>/dev/null | sed "s/.*sec = \([0-9]*\).*/\1/"`; N=`date +%s`
    K=`kextstat 2>/dev/null | grep " com.apple.ATIRadeonX1000 " | awk "{print \\$3}"`
    C=`ps auxww | grep "[c]rashdump" | grep -v " Z " | wc -l | tr -d " "`
    P=`stat -f %z /Library/Logs/panic.log 2>/dev/null || echo 0`
    echo "$((N-B)) ${K:-none} $C $P"' 2>/dev/null
}
start=`date +%s`; miss=0; first=; : > "$LOG"; printf 'time\tuptime_s\tkext\tcrashdumps\tpaniclog_bytes\tstatus\n' >> "$LOG"
while :; do
  now=`date +%s`; r=`probe`
  if [ -z "$r" ]; then
    miss=$((miss+1)); printf '%s\t-\t-\t-\t-\tmiss%d\n' "`date -u +%FT%TZ`" $miss >> "$LOG"
    [ $miss -ge $MISS ] && { echo "HANG: no answer from $H for $miss consecutive probes (~$((miss*INT)) s). Last good sample: `grep -v miss "$LOG" | tail -1`"; exit 3; }
  else
    miss=0; set -- $r; up=$1; kx=$2; cd=$3; pb=$4
    printf '%s\t%s\t%s\t%s\t%s\tok\n' "`date -u +%FT%TZ`" "$up" "$kx" "$cd" "$pb" >> "$LOG"
    if [ -z "$first" ]; then first=1; f_kx=$kx; f_cd=$cd; f_pb=$pb; last_up=$up
    else
      [ "$up" -lt "$last_up" ] && { echo "REBOOT: uptime went from $last_up s to $up s"; exit 4; }
      [ "$pb" -gt "$f_pb" ] && { echo "PANIC: /Library/Logs/panic.log grew from $f_pb to $pb bytes"; exit 5; }
      { [ "$kx" = none ] || [ "$kx" != "$f_kx" ]; } && { echo "KEXT: ATIRadeonX1000 load address was $f_kx, now $kx"; exit 6; }
      [ "$cd" -gt "$f_cd" ] && { echo "CRASHDUMP: $cd crashdump process(es), $f_cd at start"; exit 7; }
      last_up=$up
    fi
  fi
  [ $((now-start)) -ge $DUR ] && { echo "OK: $((now-start)) s, no hang/reboot/panic/kext change (log $LOG)"; exit 0; }
  sleep $INT
done
