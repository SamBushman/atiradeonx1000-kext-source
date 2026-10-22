#!/bin/sh
# verify_names.sh Userspace/<Binary>/<arch> [BASE_REV]  - the gate for a userspace rename batch: compile every part_*.c of BASE_REV (default HEAD) and of the
# working tree on the G5 (gcc -arch ppc -w, as build_corpus.py does) and demand byte-identical object files. Local names are not in the object (no -g), so a pure
# rename must be IDENTICAL; a changed object means the batch changed a declaration, a type or a split and has to be looked at.
D=$1; REV=${2:-HEAD}; N=$(echo $D | tr '/' '_'); T=${TMPDIR:-/tmp}/vn_$N; rm -rf $T; mkdir -p $T/base $T/cand
git archive $REV $D | tar -x -C $T/base; mkdir -p $T/cand/$(dirname $D); cp -R $D $T/cand/$(dirname $D)/
tar czf $T/v.tgz -C $T base cand
R=rung3/vn_$N
ssh G5 "rm -rf $R; mkdir -p $R" && scp -q $T/v.tgz G5:$R/v.tgz || exit 2
ssh G5 "cd $R && tar xzf v.tgz && for s in base cand; do (cd \$s/$D && for f in part_*.c; do gcc -arch ppc -w -c \$f -o \${f%.c}.o 2> \${f%.c}.err || echo FAIL \$s \$f; done); done; n=0; bad=0; for f in base/$D/part_*.o; do b=\$(basename \$f); n=\$((n+1)); cmp -s \$f cand/$D/\$b || { bad=\$((bad+1)); echo DIFFERENT \$b; }; done; echo \$n objects, \$bad different" | tee $T/result.txt
tail -1 $T/result.txt | grep -q ' 0 different$' && echo IDENTICAL || { echo NOT-IDENTICAL; exit 1; }
