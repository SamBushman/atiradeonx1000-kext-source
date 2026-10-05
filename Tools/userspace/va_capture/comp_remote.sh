#!/bin/sh
# comp_remote.sh NAME PICTURES [ava_drive args...]   (runs ON THE G5, started by comp_run.sh through ONE ssh session)
# Rebuilds the guard / ava_drive only when their sources changed, takes a light pre/post snapshot (uptime, kextstat, vm_stat, DVD/2D registers, system.log tail),
# launches the run in the console (Terminal) session, waits for EXIT= locally (no network), screenshots, and leaves everything as NAME_* files in /tmp/rung3/va for comp_run.sh to stream back.
# The heavy checks (diskutil verifyVolume on both volumes) are NOT run per run: run them once per boot and after any anomaly (#87 reset procedure).
N=$1; P=$2; shift; shift
V=/tmp/rung3/va; T=/tmp/rung3/Tests/destructive; cd $V || exit 1
rm -f ${N}_* $N.out $N.tsv $N.tsv.mem
L=${N}_wrapper.log; exec > $L 2>&1
echo "== $N start `date`"; uptime
# rebuild only when the source is newer than the binary
[ iokit_guard_va.dylib -nt iokit_guard_va.c ] || gcc -dynamiclib -o iokit_guard_va.dylib iokit_guard_va.c -framework IOKit -framework CoreFoundation 2>&1 | grep -v warning
{ [ ava_drive -nt ava_drive.c ] && [ ava_drive -nt ava_vectors.h ]; } || gcc -o ava_drive ava_drive.c -F/System/Library/PrivateFrameworks -framework AppleVA -framework ApplicationServices -framework IOKit 2>&1 | grep -v warning
[ -x ava_drive ] && [ -f iokit_guard_va.dylib ] || { echo "BUILD FAILED"; echo "EXIT=build" > $N.out; exit 1; }
# light preflight
kextstat | grep -i ati > ${N}_pre.kextstat; vm_stat > ${N}_pre.vm; (cd $T && ./regsnap > $V/${N}_pre.regs 2>&1); wc -l /var/log/system.log | awk '{print $1}' > ${N}_pre.syslog_lines
ps auxww | egrep "[c]rashdump|[a]va_drive|[g]odot" > ${N}_pre.ps
echo "preflight done; stale processes: `wc -l < ${N}_pre.ps`"
osascript -e "tell application \"Terminal\" to do script \"GF=${GFSET:-8,9,18,19,20} GUARD_FWD_REMAP=1 WIN_X=800 WIN_Y=500 WATCHDOG_S=${WATCHDOG_S:-60} sh $V/run_rung3.sh $N --pictures $P --hold-after 2 $*\"" > /dev/null 2>&1
i=0; while [ $i -lt 150 ]; do grep -q 'EXIT=' $N.out 2>/dev/null && break; sleep 1; i=`expr $i + 1`; done
echo "waited ${i}s; `tail -1 $N.out 2>/dev/null`"
screencapture -x ${N}_screen.png 2>/dev/null
# light postflight
(cd $T && ./regsnap > $V/${N}_post.regs 2>&1); diff ${N}_pre.regs ${N}_post.regs | grep '^>' > ${N}_regdiff.txt; kextstat | grep -i ati > ${N}_post.kextstat; vm_stat > ${N}_post.vm
tail -n +`expr \`cat ${N}_pre.syslog_lines\` + 1` /var/log/system.log > ${N}_syslog_new.txt 2>/dev/null
ps auxww | egrep "[c]rashdump|[a]va_drive" > ${N}_post.ps
echo "postflight done; stale processes: `wc -l < ${N}_post.ps`; kext unchanged: `cmp -s ${N}_pre.kextstat ${N}_post.kextstat && echo yes || echo NO`; new system.log lines: `wc -l < ${N}_syslog_new.txt`"
echo "== $N end `date`"
