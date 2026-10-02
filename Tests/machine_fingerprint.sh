#!/bin/sh
# Tests/machine_fingerprint.sh - issue #42/#43/#44: print the machine state that the recorded baselines depend on, on ONE line per fact, so a run can be compared only with like.
# Runs ON the G5 from Tests/. Makes the 24 already-reviewed validation calls of probe_set_id_mode (set_id_mode id 0-3 x 6 mode kinds; closed enumeration, no writes beyond the surface id bookkeeping).
# Finding (2026-10-02): Surface set_id_mode(1, 0x0) only succeeds while display record 1's pixel-format class (accel+0x142+id*0x78) is 0; it was 4 after the G5 had been up ~10 h, which made
# parity_test_harness report 3 unexpected results (--deep: 7) against baselines recorded in the other state. "idkind" below is that fact: for each id, the mode kinds that were accepted.
# Output lines:  uptime / kext / displays / idkind id0=... id1=... / fingerprint <short checksum of the idkind + display lines>
cd "`dirname "$0"`" || exit 1
[ -x /tmp/probe_set_id_mode ] && [ /tmp/probe_set_id_mode -nt probe_set_id_mode.c ] || gcc -arch ppc -w -o /tmp/probe_set_id_mode probe_set_id_mode.c -framework IOKit -framework CoreFoundation 2>/dev/null || { echo "idkind: probe did not build"; exit 1; }
echo "uptime: `uptime | sed 's/^ *//'`"
echo "kext: `kextstat 2>/dev/null | grep ' com.apple.ATIRadeonX1000 ' | awk '{print $3, $6, $7}'`"
D=`system_profiler SPDisplaysDataType 2>/dev/null | egrep -i "Resolution|Mirror|Online" | sed 's/^ *//' | tr '\n' ';'`; echo "displays: $D"
K=`/tmp/probe_set_id_mode 2>&1 | awk '/SUCCESS/ { split($1,a,"="); split($2,b,"="); acc[a[2]] = acc[a[2]] " " b[2] } END { for (i = 0; i < 4; i++) printf "id%d=[%s ] ", i, acc[i] }'`
echo "idkind: $K"
echo "fingerprint: `echo "$K $D" | cksum | awk '{print $1}'`"
