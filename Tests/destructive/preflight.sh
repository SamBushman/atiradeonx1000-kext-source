#!/bin/sh
# Tests/destructive/preflight.sh METHOD  (issue #87, criterion 3). Run on the G5 from Tests/destructive/. On success writes results/preflight.ok,
# which dtest_main() requires (max age 15 min). Aborts (exit 1) if any item fails.
M=${1:?usage: preflight.sh METHOD}
R=results; mkdir -p $R/$M
rm -f $R/preflight.ok
FAIL=0
bad() { echo "PREFLIGHT FAIL: $*"; FAIL=$((FAIL+1)); }
# 1. nothing unpushed on this machine: applies when this directory is inside a git working tree (remote_build.sh copies sources without .git)
if git rev-parse --show-toplevel >/dev/null 2>&1; then
    [ -z "`git status --porcelain`" ] || bad "git working tree is not clean"
    [ -z "`git log @{u}.. 2>/dev/null`" ] || bad "unpushed commits on this machine"
else
    echo "note: no git working tree here (sources are copied by Tools/remote_build.sh); the clean+pushed check is made on the dev machine by peer_ack.sh"
fi
# 2. the same capture postflight repeats
kextstat | grep -qi ATIRadeonX1000 || bad "no ATIRadeonX1000 kext loaded (kextstat)"
sh ./capture.sh $R/$M/pre || bad "state capture reported failures (see above)"
# 3. a second machine is watching
if [ -f $R/peer_ack ] && [ -z "`find $R/peer_ack -mmin +15 2>/dev/null`" ]; then :; else bad "no peer acknowledgement in the last 15 minutes (run peer_ack.sh from a second machine)"; fi
# 4. no GL / DVD client right now (dtest_main re-checks)
for C in ATIR500GLContext ATIR500DVDContext; do
    N=`/usr/sbin/ioreg -w0 -c $C 2>/dev/null | grep -c "<class $C"`
    [ "$N" = "0" ] || bad "$N live $C instance(s): quit the GL application / DVD Player"
done
if [ $FAIL -eq 0 ]; then touch $R/preflight.ok; echo "PREFLIGHT OK for $M (capture in $R/$M/pre.*)"; exit 0; fi
echo "PREFLIGHT FAILED ($FAIL item(s)) - not running"; exit 1
