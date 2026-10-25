#!/bin/bash
# bulk_generic.sh LO HI RULES OUTROWS : run a rules module over all functions of parts LO..HI, emit rows (uniqued)
cd ~/wt/q05; P=Userspace/ATIRadeonX1000GLDriver/ppc; Q=~/g5logs/q05
LO=$1; HI=$2; R=$3; OUT=$4; : > $OUT
for fn in $(python3 - $LO $HI <<'PY'
import re,sys
lo,hi=int(sys.argv[1]),int(sys.argv[2])
P='Userspace/ATIRadeonX1000GLDriver/ppc/'
H=re.compile(r'^/\* (\S+) @ 0x')
PH=re.compile(r'\b(?:[A-Za-z]{0,4}Var\d+|p+_?[A-Za-z]*Var\d+)\b')
for i in range(lo,hi+1):
    cur=None;c=0
    for l in open(f'{P}part_{i:03d}.c',errors='replace'):
        m=H.match(l)
        if m:
            if cur and c: print(cur)
            cur=m.group(1);c=0;continue
        c+=len(PH.findall(l))
    if cur and c: print(cur)
PY
); do
  [ "$fn" = FUN_000e3b88 ] && continue
  S=$Q/bg_spec.tsv; rm -f $S
  python3 Tools/userspace/lpnames/autoweb.py $P $fn $R $S >/dev/null 2>&1 || continue
  [ -s $S ] || continue
  python3 Tools/userspace/lpnames/uniq_names.py $S $P >/dev/null 2>&1
  python3 Tools/userspace/emit_webs.py $P $fn $S >> $OUT 2>/dev/null || echo "emit failed $fn"
done
wc -l $OUT
