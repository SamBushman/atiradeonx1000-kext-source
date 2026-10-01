#!/bin/sh
# Tests/destructive/capture.sh PREFIX  - the state capture shared by preflight.sh ("pre") and postflight.sh ("post") (issue #87, criterion 3).
# Writes PREFIX.kextstat, .ioreg, .displays, .vm_stat, .syslog_tail, .regs (if ./regsnap exists), .png, .volumes. Never writes to the machine except under PREFIX.*
# Exit status: number of capture items that failed. Read-only on the system.
P=${1:?usage: capture.sh PREFIX}
FAIL=0
step() { # step NAME COMMAND...   (output to PREFIX.NAME)
    N=$1; shift
    if "$@" > "$P.$N" 2>&1; then :; else echo "capture: $N FAILED ($*)"; FAIL=$((FAIL+1)); fi
}
step kextstat  sh -c 'kextstat | grep -i ati'
step ioreg     /usr/sbin/ioreg -l -w0
step displays  /usr/sbin/system_profiler SPDisplaysDataType
step vm_stat   /usr/bin/vm_stat
step syslog_tail sh -c 'tail -n 80 /var/log/system.log'
if [ -x ./regsnap ]; then step regs ./regsnap; fi
/usr/sbin/screencapture -x "$P.png" 2>/dev/null || { echo "capture: screencapture FAILED"; FAIL=$((FAIL+1)); }
# every mounted volume must verify clean (a hard reset once corrupted files on the Tiger working volume, godot-ports #9)
: > "$P.volumes"
# default: the two volumes of the issue (boot volume + the Tiger working volume "Test HD"); override with DTEST_VOLUMES (newline-separated). Other
# volumes (Sorbet HD = Leopard's boot disk, off-limits, ThinkTanks, ...) are deliberately not touched.
VOLS=${DTEST_VOLUMES:-"/
/Volumes/Test HD"}
echo "$VOLS" | while IFS= read -r V; do
    [ -d "$V" ] || continue
    OUT=`/usr/sbin/diskutil verifyVolume "$V" 2>&1`; RC=$?
    echo "== $V rc=$RC" >> "$P.volumes"; echo "$OUT" >> "$P.volumes"
    case "$OUT" in
        *"appears to be OK"*|*"appears to be ok"*) ;;
        *"not supported"*|*"Cannot verify"*|*"cannot be verified"*|*"in use"*) echo "capture: volume $V could not be verified live (recorded, not counted)";;
        *) echo "capture: volume $V did NOT verify clean"; echo x >> "$P.volfail";;
    esac
done
[ -f "$P.volfail" ] && { FAIL=$((FAIL+`wc -l < "$P.volfail"`)); rm -f "$P.volfail"; }
exit $FAIL
