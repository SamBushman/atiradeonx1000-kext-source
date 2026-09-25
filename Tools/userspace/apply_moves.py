#!/usr/bin/env python3
# apply_moves.py DUMPDIR MOVES REDUMPDIR - move INDEX/RANGES rows and dump files of functions re-created at their true entry (gs/MoveEntries.java)
import sys,os,re,shutil
D,M,R=sys.argv[1:4]
moves={int(l.split(':')[0],16):int(l.split(':')[1],16) for l in open(M) if l.strip()}
newname={}
for o,n in moves.items():
    t=open(os.path.join(R,'0x%x.txt'%n)).read()
    newname[n]=re.search(r'// Function: (.*) @',t).group(1)
rows=[]
for l in open(D+'/INDEX.tsv'):
    p=l.rstrip('\n').split('\t')
    if len(p)<3: continue
    a=int(p[0],16)
    if a in moves: n=moves[a]; p=['0x%x'%n,str(int(p[1])+(a-n)),newname[n]]
    rows.append(p)
rows.sort(key=lambda p:int(p[0],16))
open(D+'/INDEX.tsv','w').write(''.join('\t'.join(p)+'\n' for p in rows))
out=[]
for l in open(D+'/RANGES.tsv').read().split('\n'):
    p=l.split('\t')
    if len(p)>3 and p[0].startswith('0x') and p[2]=='fn' and int(p[0],16) in moves:
        o=int(p[0],16); n=moves[o]
        iv=sorted([tuple(int(x,16) for x in r.split('-')) for r in p[3].rstrip(';').split(';') if r]+[(n,o)])
        m=[list(iv[0])]
        for a,b in iv[1:]:
            if a<=m[-1][1]: m[-1][1]=max(m[-1][1],b)
            else: m.append([a,b])
        l='\t'.join(['0x%x'%n,newname[n],'fn',''.join('%x-%x;'%(a,b) for a,b in m)])
        f=os.path.join(D,'0x%x.txt'%o)
        if os.path.exists(f): os.remove(f)
    out.append(l)
open(D+'/RANGES.tsv','w').write('\n'.join(out))
for n in newname: shutil.copy(os.path.join(R,'0x%x.txt'%n), D)
print('moved', {hex(o):(hex(n),newname[n]) for o,n in moves.items()})
