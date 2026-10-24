#!/usr/bin/env python3
"""pack_revert.py DIR GHIDRAFN NEWFN : undo the multi-role local rows (oldWordN, srcNFileField, instr) of the emitter so web rows can replace them"""
import sys,re,glob
D,gfn,nfn=sys.argv[1:4]
NAMES=set(sys.argv[4].split(',')) if len(sys.argv)>4 else {'oldWord0','oldWord1','oldWord2','oldWord3','src0FileField','src1FileField','src2FileField','instr'}
rev={}
for t in glob.glob(D+'/names*.tsv'):
    L=open(t,errors='surrogateescape').read().split('\n'); out=[]
    for l in L:
        c=l.split('\t')
        if len(c)>=6 and c[0]=='local' and c[1]==gfn and c[3] in NAMES and not c[2].startswith('param_'):
            rev[c[3]]=c[2]; continue
        out.append(l)
    open(t,'w',errors='surrogateescape').write('\n'.join(out))
H=re.compile(r'^/\* (\S+) @ 0x')
for f in sorted(glob.glob(D+'/part_*.c')):
    L=open(f,errors='surrogateescape').read().split('\n'); cur=None; ch=0
    for i,l in enumerate(L):
        m=H.match(l)
        if m: cur=m.group(1)
        if cur==nfn:
            n=l
            for new,old in rev.items(): n=re.sub(r'\b%s\b'%new,old,n)
            if n!=l: L[i]=n; ch+=1
    if ch: open(f,'w',errors='surrogateescape').write('\n'.join(L)); print(nfn,'reverted',sorted(rev),ch,'lines')
