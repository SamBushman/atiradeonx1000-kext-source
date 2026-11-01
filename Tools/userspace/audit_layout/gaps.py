#!/usr/bin/env python3
# gaps.py all.txt : for each sem_equiv 'rgn' DIFFERENT function, compare the escaped-address offset sets (addi/la rX,K(r30)) of base vs cand
import re,sys,glob,os,collections
T=glob.glob(os.path.expanduser('~/g5logs/tmp_r18/vn_*'))
def funcs(path):
    out={};cur=None
    for l in open(path,errors='replace'):
        m=re.match(r'^(_[A-Za-z0-9_$.]*):$',l.rstrip())
        if m: cur=m.group(1);out[cur]=[];continue
        if cur is None: continue
        m=re.match(r'\s+addi\s+r\d+,r30,(-?\d+)',l) or re.match(r'\s+la\s+r\d+,(-?\d+)\(r30\)',l)
        if m: out[cur].append(int(m.group(1)))
    return {k:sorted(set(v)) for k,v in out.items()}
cur=None;res=[]
cache={}
for l in open(sys.argv[1]):
    if l.startswith('###'):
        _,b,p=l.split();cur=(b,p);continue
    m=re.match(r'^DIFFERENT (\S+) - .*\'rgn\'',l)
    if m:
        d=[x for x in T if x.endswith('_a18_'+cur[0]) or ('_'+cur[0]+'_ppc_a18') in x][0]
        key=(d,cur[1])
        if key not in cache: cache[key]=(funcs(d+'/base.'+cur[1]+'.dis'),funcs(d+'/cand.'+cur[1]+'.dis'))
        B,C=cache[key];f=m.group(1)
        bo,co=B.get(f,[]),C.get(f,[])
        gb=[y-x for x,y in zip(bo,bo[1:])];gc=[y-x for x,y in zip(co,co[1:])]
        res.append((cur[0],cur[1],f,'SHIFT' if gb==gc and len(bo)==len(co) else 'LAYOUT',bo,co))
for r in res: print('\t'.join([r[0],r[1],r[2],r[3],str(r[4]),str(r[5])]))
