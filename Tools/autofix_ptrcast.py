#!/usr/bin/env python3
"""Wrap the RHS of `lhs = rhs;` in (UInt32) where gcc reports a pointer->unsigned long conversion on that line."""
import re,sys,collections
errs=collections.defaultdict(set)
for l in open(sys.argv[1]):
    m=re.match(r"(Sources/\S+?):(\d+): error: invalid conversion from '[^']*\*' to 'long unsigned int'",l)
    if m: errs[m.group(1)].add(int(m.group(2)))
for f,lines in errs.items():
    src=open(f).read().split('\n')
    for n in sorted(lines):
        s=src[n-1]
        m=re.match(r"^(\s*)([^=()]+?) = (.+);(.*)$",s)
        if m and '(UInt32)' not in m.group(3)[:9]:
            src[n-1]="%s%s = (UInt32)(%s);%s"%(m.group(1),m.group(2),m.group(3),m.group(4)); print("fixed",f,n)
        else: print("SKIP",f,n,s)
    open(f,'w').write('\n'.join(src))
