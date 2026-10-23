#!/usr/bin/env python3
"""orig.py DIR FUNC [from to] - print FUNC with every table rename taken back (Ghidra text) plus current-file line numbers"""
import sys,re,glob,os
d,fn=sys.argv[1],sys.argv[2]
HDR=re.compile(r'^/\* (\S+) @ 0x')
back={}
for t in sorted(glob.glob(os.path.join(d,'names*.tsv'))):
    for l in open(t,errors='replace'):
        c=l.rstrip('\n').split('\t')
        if len(c)>=6 and c[0] in('local','use') and c[1]==fn: back[c[3]]=c[2]
rx=re.compile('|'.join(r'\b%s\b'%re.escape(k) for k in sorted(back,key=len,reverse=True))) if back else None
for f in sorted(glob.glob(os.path.join(d,'part_*.c'))):
    L=open(f,errors='replace').read().split('\n'); s=None
    for i,l in enumerate(L):
        m=HDR.match(l)
        if m:
            if s is not None: e=i;break
            if m.group(1)==fn: s=i
    else: e=len(L)
    if s is None: continue
    a=int(sys.argv[3]) if len(sys.argv)>3 else s+1
    b=int(sys.argv[4]) if len(sys.argv)>4 else e
    for i in range(max(s,a-1),min(e,b)):
        t=L[i]
        if rx: t=rx.sub(lambda m:back[m.group(0)],t)
        print('%d:%s'%(i+1,t))
    break
