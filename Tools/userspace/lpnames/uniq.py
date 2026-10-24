#!/usr/bin/env python3
"""uniq.py SPEC : make web-spec names unique per original variable (same name on different Ghidra variables gets suffix B, C, ...)"""
import sys
f=sys.argv[1]; rows=[l.rstrip('\n').split('\t') for l in open(f) if l.strip() and not l.startswith('#')]
owner={}; out=[]
for r in rows:
    var,webs,name=r[0],r[1],r[2]
    base=name; k=0
    while name in owner and owner[name]!=var:
        k+=1; name=base+chr(ord('A')+k)   # B, C, ...
    owner[name]=var
    r[2]=name; out.append('\t'.join(r))
open(f,'w').write('\n'.join(out)+'\n')
