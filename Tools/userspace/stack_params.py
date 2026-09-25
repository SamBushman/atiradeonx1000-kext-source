#!/usr/bin/env python3
"""stack_params.py INSTACK_TSV STOCK_DIS OUTPREFIX  - from an instack_table.py table, write OUTPREFIX_extend.txt (entry:count for
gs/ExtendParams.java: parameters up to the highest stack word read, 8 + (off-0x38)/4 + 1) and OUTPREFIX_redump.txt (those entries plus every stock
`bl` site that calls them, directly or through a PIC stub, for RedumpContaining.java). Functions with no committed parameters are clipped fragments
reading their parent's frame and are skipped (check the list: FUN_00029290 had a `(void)` signature and needed a manual entry); the unwinder is
skipped. Rerun on the redumped files until the list is empty: a function that forwards its own stack arguments shows up only after its callee
is extended."""
import sys,re
tsv,dis,outp=sys.argv[1],sys.argv[2],sys.argv[3]
ext={}
for l in open(tsv):
    a,name,p,fp,pos,neg=l.rstrip('\n').split('\t')
    offs=[int(x,16) for x in pos[4:].split(',') if x]
    offs=[o for o in offs if o>=0x38]
    if not offs: continue
    if name.startswith('__Unwind') or name.startswith('eh_'): continue
    np=int(p[7:])
    if np==0: continue            # clipped fragments reading the parent's frame (orphans), not parameters
    want=8+((max(offs)&~3)-0x38)//4+1
    if want>np: ext[int(a,16)]=(name,want)
lab={}; pend=None
for l in open(dis):
    if l.endswith(':\n') and not l[0].isdigit(): pend=l[:-2]; continue
    if pend and l[0] in "0123456789abcdef": lab[pend]=int(l.split()[0],16)
    pend=None
names={n:a for n,a in lab.items() if a in ext}
sites=set()
for l in open(dis):
    m=re.match(r'([0-9a-f]+)\s+bl?\s+(\S+)',l)
    if not m: continue
    t=m.group(2)
    ms=re.search(r'symbol stub for: (\S+)',l)
    if ms: ta=names.get(ms.group(1))
    else:
        try: ta=int(t,16)
        except ValueError: ta=names.get(t)
    if ta in ext: sites.add(int(m.group(1),16))
with open(outp+'_extend.txt','w') as f:
    for a,(n,w) in sorted(ext.items()): f.write('0x%x:%d\n'%(a,w))
with open(outp+'_redump.txt','w') as f:
    for a in sorted(set(ext)|sites): f.write('0x%x\n'%a)
print(len(ext),'functions',len(sites),'call sites')
