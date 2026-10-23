#!/usr/bin/env python3
"""dupdecl.py FILE... : report functions whose leading declaration block declares an identifier twice; --fix removes the later duplicate"""
import sys,re,collections
fix='--fix' in sys.argv
for f in [a for a in sys.argv[1:] if a!='--fix']:
    L=open(f,errors='surrogateescape').read().split('\n'); out=[]; i=0; bad=0
    H=re.compile(r'^/\* (\S+) @ 0x')
    cur=None; inblock=False; seen=set()
    for l in L:
        m=H.match(l)
        if m: cur=m.group(1); inblock=False; seen=set()
        if l=='{' and cur: inblock=True; seen=set(); out.append(l); continue
        if inblock:
            if not l.strip(): out.append(l); continue
            if '(' in l or '=' in l or l.lstrip().startswith(('return','goto','break','if','for','while','do')) : inblock=False; out.append(l); continue
            mm=re.search(r'([A-Za-z_]\w*)(?: ?\[\w+\])?;$',l)
            if mm:
                if mm.group(1) in seen:
                    print('%s: %s: duplicate decl %s'%(f,cur,mm.group(1))); bad+=1
                    if fix: continue
                seen.add(mm.group(1))
        out.append(l)
    if fix and bad: open(f,'w',errors='surrogateescape').write('\n'.join(out))
