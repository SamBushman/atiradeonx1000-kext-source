#!/bin/sh
# Tests/destructive/postflight.sh METHOD  (issue #87, criterion 3): repeat the capture into post.* and diff it against pre.*.
# The kextstat and volume-verify captures must be identical; the ioreg / vm_stat / register / syslog diffs are printed for the
# issue (they legitimately differ), and a changed kextstat or an unclean volume is CORRUPTION-class and exits 1.
M=${1:?usage: postflight.sh METHOD}
R=results/$M
[ -f $R/pre.kextstat ] || { echo "no pre capture for $M (run preflight.sh first)"; exit 2; }
sh ./capture.sh $R/post; CAP=$?
RC=0
[ $CAP -eq 0 ] || { echo "POSTFLIGHT: capture reported $CAP failure(s) "; RC=1; }
diff $R/pre.kextstat $R/post.kextstat > $R/diff.kextstat || { echo "POSTFLIGHT: kextstat CHANGED (see $R/diff.kextstat)"; RC=1; }
diff $R/pre.volumes $R/post.volumes > $R/diff.volumes || { echo "POSTFLIGHT: volume verify output CHANGED (CORRUPTION-class, see $R/diff.volumes)"; RC=1; }
for X in displays ioreg vm_stat regs; do
    [ -f $R/pre.$X ] && [ -f $R/post.$X ] && { diff $R/pre.$X $R/post.$X > $R/diff.$X; echo "diff $X: `grep -c '^[<>]' $R/diff.$X` line(s) (see $R/diff.$X)"; }
done
echo "POSTFLIGHT done for $M (rc=$RC); record the outcome class in the issue"
exit $RC
