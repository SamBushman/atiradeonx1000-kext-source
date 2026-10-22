#!/bin/sh
# verify_names.sh Userspace/<Binary>/<arch> [BASE_REV]  - the gate for a userspace rename batch: compile every part_*.c of BASE_REV (default HEAD) and of the
# working tree on the G5 (gcc -arch ppc -w, as build_corpus.py does) and demand byte-identical object files. Local names are not in the object (no -g), so a pure
# rename must be IDENTICAL; a changed object means the batch changed a declaration, a type or a split and has to be looked at.
D=$1; REV=${2:-HEAD}; N=$(echo $D | tr "/" "_")${TAG:+_$TAG}; T=${TMPDIR:-/tmp}/vn_$N; rm -rf $T; mkdir -p $T/base $T/cand
git archive $REV $D | tar -x -C $T/base; mkdir -p $T/cand/$(dirname $D); cp -R $D $T/cand/$(dirname $D)/
tar czf $T/v.tgz -C $T base cand
R=rung3/vn_$N
ssh G5 "rm -rf $R; mkdir -p $R" && scp -q $T/v.tgz G5:$R/v.tgz || exit 2
ssh G5 "cd $R && tar xzf v.tgz && for s in base cand; do (cd \$s/$D && for f in part_*.c; do gcc -arch ppc -w -c \$f -o \${f%.c}.o 2> \${f%.c}.err || echo FAIL \$s \$f; done); done; n=0; bad=0; for f in base/$D/part_*.o; do b=\$(basename \$f); n=\$((n+1)); cmp -s \$f cand/$D/\$b || { bad=\$((bad+1)); echo DIFFERENT \$b; }; done; echo \$n objects, \$bad different" | tee $T/result.txt
if tail -1 $T/result.txt | grep -q ' 0 different$'; then echo IDENTICAL; exit 0; fi
H=$(dirname $0)
# `func` rows rename symbols: the objects differ in their symbol tables, so a map (candidate name -> Ghidra name) is applied to the assembler text and the
# warnings of both sides before comparing (Tools/userspace/funcmap.py, unmap_names.py)
python3 $H/funcmap.py $D > $T/namemap.tsv; [ -s $T/namemap.tsv ] && SPLITS=1
[ -n "$SPLITS" ] || { echo NOT-IDENTICAL; exit 1; }
# SPLITS=1: per-use splits move gcc -O0 stack slots, so objects may differ; accept when Tools/userspace/split_equiv.py proves the same code, a
# many-to-one slot map and no new -Wuninitialized warning (compiled -O1) for every differing part
rc=0
for part in $(grep '^DIFFERENT' $T/result.txt | awk '{print $2}' | sed 's/\.o$//'); do
  ssh G5 "cd $R && for s in base cand; do (cd \$s/$D && gcc -arch ppc -w -S $part.c -o $part.dis; gcc -arch ppc -O1 -Wuninitialized -c $part.c -o /dev/null 2> $part.warn); done"
  for s in base cand; do scp -q G5:$R/$s/$D/$part.dis $T/$s.$part.dis; scp -q G5:$R/$s/$D/$part.warn $T/$s.$part.warn; done
  [ -s $T/namemap.tsv ] && python3 $H/unmap_names.py $T/namemap.tsv $T/base.$part.dis $T/cand.$part.dis $T/base.$part.warn $T/cand.$part.warn
  python3 $H/split_equiv.py $T/base.$part.dis $T/cand.$part.dis $T/base.$part.warn $T/cand.$part.warn | tail -8 || rc=1
  python3 $H/split_equiv.py $T/base.$part.dis $T/cand.$part.dis $T/base.$part.warn $T/cand.$part.warn > /dev/null || rc=1
done
[ $rc = 0 ] && echo SPLIT-EQUIVALENT || { echo NOT-EQUIVALENT; exit 1; }
