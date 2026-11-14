#!/usr/bin/env python3
"""frame_mem_fit_audit.py LINK_TREE... - in a LINKED tree (after rewrites.mirror_frame) every memcpy/memset/memmove with a constant size whose target is `ghidra_frame + OFF` must fit in the frame array: OFF + size <= 8 * N. Prints OVER lines; "total 0" = all fit (Nov 14: 83 sites over the gld cc4e5e7b, gleng 5e958370, glprog, ga, va, libgl trees, 0 over). Companion of frame_adjacency_audit.py (#282): its MEM hits are covered when the function is mirrored and the site fits."""
import re, glob, sys
call=re.compile(r'\b(_memcpy|_memset|_memmove|_bcopy)\s*\(([^;]*?)\)\s*;')
fr=re.compile(r'unsigned long long ghidra_frame\[(\d+)\]')
ref=re.compile(r'\(\(?(?:unsigned char|char) \*\)\s*ghidra_frame\s*\+\s*(\d+)\)')
bad=0; chk=[0]
for d in sys.argv[1:]:
  for f in sorted(glob.glob(d+'/part_*.c')):
    L=open(f,errors='replace').read().split('\n'); cur=None; N=None
    for i,l in enumerate(L):
        m=re.match(r'^[A-Za-z_][\w \*]*?\b([A-Za-z_]\w*)\(.*\)$',l)
        if m and not l.startswith(' '): cur=m.group(1); N=None
        m=fr.search(l)
        if m: N=int(m.group(1))*8
        for c in call.finditer(l):
            args=[a.strip() for a in re.split(r',(?![^()]*\))',c.group(2))]
            if len(args)<3: continue
            try: n=int(args[2],0)
            except: continue
            tg=[args[0]] if 'memset' in c.group(1) else args[:2]
            for t in tg:
                r=ref.search(t)
                if r: chk[0]+=1
                if r and N is not None and int(r.group(1))+n>N:
                    print('OVER',f.split('/')[-1],i+1,cur,'off',r.group(1),'size',n,'frame',N); bad+=1
print("total",bad,"checked",chk[0])
