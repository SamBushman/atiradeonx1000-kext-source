#!/bin/sh
# ap.sh FUNCTION SPEC [TABLE] - espec rows for FUNCTION appended to the table (default names_lpF_2.tsv in the libGLProgrammability corpus).
# Rows whose segment no longer contains the variable ("neither X nor Y in the segment": the line was renamed by an earlier row) are dropped; any other check error undoes the append.
D=Userspace/libGLProgrammability/ppc; T=${3:-$D/names_lpF_2.tsv}
[ -f $T ] || : > $T; N=$(wc -l < $T)
python3 Tools/userspace/espec.py $D "$1" "$2" >> $T || { head -n $N $T > $T.tmp && mv $T.tmp $T; exit 1; }
for i in 1 2 3 4 5 6; do
  python3 Tools/userspace/apply_names.py --check $D > $T.chk 2>&1
  python3 - $T $T.chk $N <<'P'
import sys,re
t,chk,n=sys.argv[1],sys.argv[2],int(sys.argv[3])
errs=[l for l in open(chk) if re.match(r'.*: .*:',l) or 'errors' in l]
drop=set()
for l in open(chk):
    m=re.match(r'.*%s:(\d+): .*neither .* in the segment'%re.escape(t.split('/')[-1]),l)
    if m and int(m.group(1))>n: drop.add(int(m.group(1)))
if drop:
    L=open(t).read().split('\n')
    open(t,'w').write('\n'.join(x for i,x in enumerate(L,1) if i not in drop))
    print('dropped %d rows with renamed lines'%len(drop))
P
  grep -q 'in the segment' $T.chk && continue; break
done
tail -3 $T.chk
case "$(tail -1 $T.chk)" in *" 0 errors"*) ;; *) head -n $N $T > $T.tmp && mv $T.tmp $T; echo UNDONE;; esac
rm -f $T.chk
