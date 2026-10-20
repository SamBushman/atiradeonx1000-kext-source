#!/usr/bin/env python3
"""shiftsites.py DIS SYMSUB: list rlwinm ..,20,29,31 (>>12 &7) sites in a function with 12 insns of context before"""
import sys,re
dis,sub=sys.argv[1],sys.argv[2]
lines=[];on=False;base=None
for ln in open(dis,errors='replace'):
    s=ln.strip()
    if re.match(r'^_\S+:$',s):
        if on: break
        on = sub in s; base=None; continue
    if on:
        m=re.match(r'^([0-9a-f]{8})\s+(.*)$',ln.rstrip())
        if m:
            a=int(m.group(1),16); base=base or a; lines.append((a-base,m.group(2)))
for i,(o,t) in enumerate(lines):
    if re.search(r'rlwinm\s+r\d+,r\d+,20,29,31',t) or re.search(r'rlwinm\s+r\d+,r\d+,20,0x1d,0x1f',t) or re.search(r',20,29,31',t):
        print('== site %x'%o)
        for (o2,t2) in lines[max(0,i-10):i+3]: print('  %5x %s'%(o2,t2))
