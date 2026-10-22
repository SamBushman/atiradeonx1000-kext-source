#!/usr/bin/env python3
"""typeprop.py PRISTINE_DIR - class typing of placeholder parameters by call arguments: a param passed as argument 1 of a method `X__m` (or whose function is a method) is an X."""
import re,glob,collections,sys,os
d=sys.argv[1]
CLS=re.compile(r'^([A-Z][A-Za-z0-9]*)__[A-Za-z_]')
PAR=re.compile(r'\b(param_\d+)\b')
fns={}
for pf in sorted(glob.glob(d+'/part_*.c')):
    L=open(pf).read().split('\n'); i=0
    while i<len(L):
        m=re.match(r'^/\* (\S+) @',L[i])
        if m:
            name=m.group(1); j=i+1
            while j<len(L) and L[j]!='{': j+=1
            k=j
            while k<len(L) and not L[k].startswith('/* '): k+=1
            fns[name]=(pf,i,j,k,L[i:k]); i=k; continue
        i+=1
# method classes: class of callee when called with arg0
def cls_of(callee):
    m=CLS.match(callee)
    if m: return m.group(1)
    m=re.match(r'^__ZN(\d+)([A-Za-z0-9_]+)',callee)
    if m:
        n=int(m.group(1)); return m.group(2)[:n]
    return None
res=collections.defaultdict(lambda: collections.defaultdict(collections.Counter))   # fn -> param -> class -> n
for name,(pf,i,j,k,F) in fns.items():
    hdr=F[1:j-i]; params=[p for p in re.findall(r'\b(param_\d+);',' '.join(hdr))]
    own=cls_of(name)
    body=[l for l in F[j-i:] if not re.match(r'\s*(/\*|\*|//)',l)]
    text='\n'.join(body)
    for m in re.finditer(r'\b([A-Za-z_][A-Za-z0-9_]*)\(\s*(?:\([a-z ]+\*\))?\s*(param_\d+)\b',text):
        c=cls_of(m.group(1))
        if c: res[name][m.group(2)][c]+=1
    if 'param_1' in params and own: res[name]['param_1'][own]+=5
tot=0; occ=0
out=[]
for name,(pf,i,j,k,F) in fns.items():
    for p,c in res.get(name,{}).items():
        if p not in ' '.join(F[1:j-i]): continue
        cl,n=c.most_common(1)[0]
        n_occ=len(re.findall(r'\b%s\b'%p,'\n'.join(l for l in F[j-i:] if not re.match(r'\s*(/\*|\*|//)',l))))
        out.append((name,p,cl,len(c),n_occ))
print(len(out),sum(o[4] for o in out),'occurrences;',sum(1 for o in out if o[3]>1),'with conflicting classes')
if len(sys.argv)>2:
    for o in out[:40]: print(o)
