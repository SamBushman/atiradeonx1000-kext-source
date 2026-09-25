#!/usr/bin/env python3
# prune_orphans.py N_DIR O_DIR UNOWNED_CODE_DIR PIPELINE_ORPH_TSV - drop the orphans whose code now lies inside a function's RANGES (switch owners
# widened by switch_ranges.py, entries moved by MoveEntries.java): the owner's C transcribes that code, the orphan was a duplicate
import sys,os,shutil
N,O,U,P=sys.argv[1:5]
own=[]
for l in open(N+'/RANGES.tsv'):
    p=l.rstrip('\n').split('\t')
    if len(p)>3 and p[2]=='fn':
        for r in p[3].split(';'):
            if r: a,b=r.split('-'); own.append((int(a,16),int(b,16)))
def inside(a,b): return all(any(x<=w<y for x,y in own) for w in range(a,b,4))
ext={int(l.split('\t')[0],16):int(l.split('\t')[1],16) for l in open(P) if l.strip()}   # the orphan's own code (its decompile flows on further)
drop=set(); keep=[]
for l in open(O+'/INDEX.tsv'):
    p=l.rstrip('\n').split('\t'); a=int(p[0],16)
    if a in ext and inside(a,ext[a]): drop.add(a)
    else: keep.append(l)
open(O+'/INDEX.tsv','w').write(''.join(keep))
for a in drop:
    f=os.path.join(O,'0x%x.txt'%a)
    if os.path.exists(f): os.remove(f)
for fn in (O+'/PADOWNERS.tsv', U+'/code_owners.tsv'):
    if os.path.exists(fn):
        kept = [l for l in open(fn) if int(l.split('\t')[0],16) not in drop]   # read first: open(fn,'w') truncates
        open(fn,'w').write(''.join(kept))
for fn in (U+'/code_extents.tsv', P):
    kept = [l for l in open(fn) if int(l.split('\t')[0],16) not in drop]
    open(fn,'w').write(''.join(kept))
shutil.copy(N+'/RANGES.tsv', O+'/RANGES.tsv')
print(O, 'dropped', len(drop), sorted('%x'%a for a in drop))
