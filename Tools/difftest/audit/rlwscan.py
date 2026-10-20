#!/usr/bin/env python3
"""rlwscan.py STOCK.dis REBUILT.dis [MINDIFF]: per function present in both images, compare the multiset of rlwinm (sh,mb,me) shift/mask constants; list functions where a triple occurs a different number of times"""
import sys,re,collections
def scan(path):
    out={};cur=None
    for ln in open(path,errors='replace'):
        s=ln.rstrip()
        m=re.match(r'^(_\S+):$',s)
        if m: cur=m.group(1); out[cur]=collections.Counter(); continue
        if cur is None: continue
        m=re.search(r'\brlwinm\.?\s+r\d+,r\d+,(\d+),(\d+),(\d+)',s)
        if m: out[cur][tuple(map(int,m.groups()))]+=1
    return out
a,b=scan(sys.argv[1]),scan(sys.argv[2])
n=0
for k in sorted(set(a)&set(b)):
    d={t:(a[k][t],b[k][t]) for t in set(a[k])|set(b[k]) if a[k][t]!=b[k][t]}
    if d:
        n+=1
        print(k[:90], ' '.join('%s:%d/%d'%(','.join(map(str,t)),x,y) for t,(x,y) in sorted(d.items())[:8]))
print(n,'functions with differing rlwinm triples')
