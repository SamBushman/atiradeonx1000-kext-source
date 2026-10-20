#!/usr/bin/env python3
"""findtriple.py DIS SYMSUB SH MB: print rlwinm sh,mb,31 sites with 6 insns of context"""
import sys,re
dis,sub,sh,mb=sys.argv[1],sys.argv[2],sys.argv[3],sys.argv[4]
lines=[];on=False;base=None
for ln in open(dis,errors='replace'):
    s=ln.rstrip()
    if re.match(r'^_\S+:$',s):
        if on: break
        on=(s[:-1]==sub); base=None; continue
    if on:
        m=re.match(r'^([0-9a-f]{8})\s+(.*)$',s)
        if m:
            a=int(m.group(1),16); base=base or a; lines.append((a-base,m.group(2)))
for i,(o,t) in enumerate(lines):
    if re.search(r'rlwinm\.?\s+r\d+,r\d+,%s,%s,31\b'%(sh,mb),t):
        print('-- %x'%o)
        for (o2,t2) in lines[max(0,i-5):i+3]: print('  %5x %s'%(o2,t2))
