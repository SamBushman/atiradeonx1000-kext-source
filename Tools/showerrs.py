#!/usr/bin/env python3
"""showerrs.py LOG - print each gcc error with the offending source line."""
import re,sys
seen=set()
for l in open(sys.argv[1]):
    m=re.match(r"(Sources/\S+?):(\d+): (error|warning): (.*)",l)
    if not m or m.group(3)!='error': continue
    f,n=m.group(1),int(m.group(2))
    if (f,n,m.group(4)) in seen: continue
    seen.add((f,n,m.group(4)))
    try: src=open(f).read().split('\n')[n-1].strip()
    except Exception: src='?'
    print("%s:%d: %s\n      | %s"%(f.replace('Sources/',''),n,m.group(4)[:170],src[:200]))
