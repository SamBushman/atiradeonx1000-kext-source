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
if [ -x ./regsnap ]; then step regs ./regsnap; else echo "capture: note - ./regsnap not built (make regsnap): no register snapshot"; fi
/usr/sbin/screencapture -x "$P.png" 2>/dev/null || { echo "capture: screencapture FAILED"; FAIL=$((FAIL+1)); }
# Volumes: `diskutil verifyVolume` on Tiger cannot unmount the mounted Test HD ("Could not unmount disk for verification") and reports a live
# "Volume Bit Map needs minor repair" on the in-use boot volume, so an absolute clean/unclean verdict is not available while mounted. The check is
# therefore RELATIVE: the output is recorded here and postflight.sh flags any CHANGE between pre and post (new damage, or a volume that stops
# verifying) as CORRUPTION-class. After a hard reset compare against the last pre.volumes of any earlier run.
VOLS=${DTEST_VOLUMES:-"/
/Volumes/Test HD"}
: > "$P.volumes"
echo "$VOLS" | while IFS= read -r V; do
    [ -d "$V" ] || continue
    echo "== $V" >> "$P.volumes"
    /usr/sbin/diskutil verifyVolume "$V" 2>&1 | sed 's/\x1b\[[0-9;]*m//g' | grep -iE 'Checking|needs|error|invalid|incorrect|corrupt|damaged|overlapped|missing' | grep -v 'needs to be repaired' >> "$P.volumes"
done
exit $FAIL
