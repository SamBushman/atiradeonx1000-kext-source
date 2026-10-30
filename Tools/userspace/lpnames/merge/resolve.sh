#!/bin/bash
# resolve.sh BRANCH LO HI : resolve a conflicted merge of BRANCH (parts LO..HI are its own range)
cd ~/atiradeonx1000-kext-source
P=Userspace/ATIRadeonX1000GLDriver/ppc
B=$(git merge-base HEAD $1)
python3 ~/g5logs/mkmaps.py $B $1 ~/g5logs/maps_$1.json || exit 1
for f in $(git status --short | grep -E '^(UU|AA)' | awk '{print $2}'); do
  case $f in
    $P/part_*.c) n=$(basename $f .c); n=${n#part_}; n=$((10#$n))
       if [ $n -ge $2 ] && [ $n -le $3 ]; then git checkout --theirs $f; else git checkout --ours $f; fi ;;
    *) echo "NON-PART CONFLICT $f";;
  esac
done
python3 - $1 <<'PY'
import json,re,glob,sys
m=json.load(open('/home/sam/g5logs/maps_%s.json'%sys.argv[1]));u={**m['ours'],**m['theirs']}
R=re.compile(r'\b('+'|'.join(map(re.escape,sorted(u,key=len,reverse=True)))+r')\b')
n=0
for f in sorted(glob.glob('Userspace/ATIRadeonX1000GLDriver/ppc/part_*.c')):
    t=open(f,encoding='latin-1').read()
    s=R.sub(lambda x:u[x.group(1)],t)
    if s!=t: open(f,'w',encoding='latin-1').write(s);n+=1
print('files changed',n)
PY
