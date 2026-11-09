#!/usr/bin/env python3
"""stkscan.py STOCK_DIS  - per function (label block of the otool -tV listing): frame size from `stwu r1,-N(r1)`, then every load/addi from off(r1) with
off >= N+0x38 (the caller's 9th+ argument words) that no earlier instruction of the function stored to. Prints name, entry, frame, offsets."""
import re,sys
cur=None; funcs={}; order=[]
for l in open(sys.argv[1]):
    if l.endswith(':\n') and not l[0].isdigit() and not l.startswith('/'):
        cur=l[:-2]; funcs[cur]={'ins':[]}; order.append(cur); continue
    m=re.match(r'([0-9a-f]{8})\t(\S+)\t?(.*)',l.rstrip('\n'))
    if m and cur is not None: funcs[cur]['ins'].append((int(m.group(1),16),m.group(2),m.group(3)))
for n in order:
    ins=funcs[n]['ins']
    if not ins: continue
    fr=None
    for a,op,args in ins:
        m=re.match(r'r1,(0x[0-9a-f]+|-?\d+)\(r1\)',args)
        if op=='stwu' and m:
            v=int(m.group(1),0)
            if v>=0x80000000 or v>0x7fff and v>=0xffff0000: pass
            fr=(-v if v<0 else (0x10000-v if v>=0x8000 else -v)) if False else None
            # otool prints negative displacements as 0xffXX (16-bit two's complement)
            if v>=0x8000: v-=0x10000
            fr=-v; break
    if fr is None: fr=0
    if fr<0: continue
    stored=set(); hits={}
    for a,op,args in ins:
        m=re.search(r'(0x[0-9a-f]+|-?\d+)\(r1\)',args)
        if m and op not in ('stwu',):
            off=int(m.group(1),0)
            if off>=0x8000: off-=0x10000
            if off>=fr+0x38 and off<fr+0x38+0x40:
                if op.startswith('st'):
                    stored.add(off)
                elif off not in stored and (op.startswith('l')):
                    hits.setdefault(off-fr,a)
        m2=re.match(r'r\d+,r1,(0x[0-9a-f]+|-?\d+)$',args)
        if op=='addi' and m2:
            off=int(m2.group(1),0)
            if off>=0x8000: off-=0x10000
            if off>=fr+0x38 and off<fr+0x78 and off not in stored: hits.setdefault(off-fr,a)
    if hits: print("%s\t%x\tframe=%x\toffs=%s"%(n,ins[0][0],fr,','.join('%x'%o for o in sorted(hits))))
