#!/bin/bash
# mergeall.sh TAG : merge every wt-q0N branch that is ahead of main (function-level), check, gate vs pre-merge HEAD, push if clean
cd ~/wt/int || exit 1; git merge -q --ff-only main 2>/dev/null
B0=$(git rev-parse HEAD); n=0
for b in wt-q01 wt-q02 wt-q03 wt-q04 wt-q05 wt-q06 wt-q07 wt-q08; do
  case " $EXCL " in *" $b "*) continue;; esac
  [ $(git rev-list --count HEAD..$b) -eq 0 ] && continue
  git merge --no-commit --no-ff $b >/dev/null 2>&1
  git status --short | grep -E '^(UU|AA|DU|UD)' | grep -v part_
  python3 ~/g5logs/fnmerge.py $b --apply | head -1
  python3 ~/g5logs/rowfix.py $b >/dev/null
  git add -A
  r=$(python3 Tools/userspace/apply_names.py Userspace/ATIRadeonX1000GLDriver/ppc 2>&1 | tail -1); echo "$b: $r"
  git commit -q -m "Merge branch '$b'"; n=$((n+1))
done
[ $n -eq 0 ] && { echo nothing to merge; exit 0; }
for f in Tools/userspace/lpnames/*.py; do python3 -m py_compile $f 2>&1|head -1; done
python3 Tools/userspace/apply_names.py --check Userspace/ATIRadeonX1000GLDriver/ppc 2>&1 | tail -1
BIN=ATIRadeonX1000GLDriver sh Tools/userspace/lpnames/gate.sh $1 $B0 > ~/g5logs/$1.out 2>&1
head -1 ~/g5logs/$1.out; grep -v ', 0 problems' ~/g5logs/$1.out | grep -v '^VERDICT' | head -5
if head -1 ~/g5logs/$1.out | grep -q 'EQUIVALENT$\|IDENTICAL' && ! head -1 ~/g5logs/$1.out | grep -q NOT; then git push -q origin integ:main 2>&1 | tail -1; (cd ~/atiradeonx1000-kext-source && git merge -q --ff-only integ); echo pushed $(git rev-parse --short HEAD); else echo "NOT PUSHED (gate) base=$B0"; fi
