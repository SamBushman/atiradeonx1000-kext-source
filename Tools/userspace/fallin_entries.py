#!/usr/bin/env python3
"""fallin_entries.py STOCK_DIS RANGES_TSV - function entries that the preceding instructions fall into (not a blr / b / bctr / nop / table word before
them): gcc scheduled a compare, `mfcr`, `stmw` or register copy before `mflr` and auto-analysis started the function at the `mflr`. Rows: entry,
name, the first instruction of the run, the run, and how many code references reach the run. A decompile that reads a register the run sets
(`in_cr7`, `unaff_r29`) is fixed with gs/MoveEntries.java (Stage B3 step 13)."""
import re,sys
dis,rng=sys.argv[1:3]
ins={};order=[]
for l in open(dis):
    m=re.match(r'([0-9a-f]{8})\t(\S+)\s*(.*)',l.rstrip())
    if m: a=int(m.group(1),16); ins[a]=(m.group(2),m.group(3)); order.append(a)
idx={a:i for i,a in enumerate(order)}
ents={}
for l in open(rng):
    p=l.split('\t')
    if len(p)>3 and p[0].startswith('0x') and p[2]=='fn': ents[int(p[0],16)]=p[1]
calls={}
for a,(op,arg) in ins.items():
    m=re.match(r'0x([0-9a-f]+)',arg)
    if op in ('bl','b') and m: calls.setdefault(int(m.group(1),16),[]).append(a)
TERM=('b','blr','bctr','.long','nop','attn','bctrl')
for e,n in sorted(ents.items()):
    if e not in idx: continue
    i=idx[e]
    if i==0: continue
    p=order[i-1]; op=ins[p][0]
    if op in TERM or op.startswith('b') and op not in ('bl','bcl'): continue
    # walk back to the start of the fall-in run
    j=i-1
    while j>0 and ins[order[j-1]][0] not in TERM and not (ins[order[j-1]][0].startswith('b') and ins[order[j-1]][0] not in ('bl','bcl')) and order[j] not in ents: j-=1
    start=order[j]
    run=[ins[order[k]][0] for k in range(j,i)]
    c=sorted(set(a for x in range(start,e,4) for a in calls.get(x,[])))
    print('%x\t%s\tfalls from %x (%d instr: %s)\tcalled at start-run: %d'%(e,n,start,len(run),' '.join(run[:6]),len(c)))
