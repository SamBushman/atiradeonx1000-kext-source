#!/usr/bin/env python3
# hidden_params.py DIS DUMPDIR - argument registers live at a function's entry (read or forwarded, stock liveness) beyond its declared
# parameters, which some stock caller sets before the call: an argument the decompile does not show (e.g. forwarded to an indirect call)
import sys,re,runpy,os,glob
dis,D=sys.argv[1:3]
sys.argv=['x',dis,D+'/RANGES.tsv','/nonexistent']
g=runpy.run_path(os.path.expanduser('~/Documents/ATI-X1900-Decomp/atiradeonx1000-kext-source/Tools/userspace/inreg_liveness.py'))
G=g['classify'].__globals__; ins=G['ins']; rows=G['rows']
calls={}
label=G['label']   # an unstripped image prints `bl _name`
for a,(op,arg) in ins.items():
    if op!='bl': continue
    m=re.match(r'0x([0-9a-f]+)',arg)
    t=int(m.group(1),16) if m else label.get(arg.split()[0]) if arg else None
    if t is not None: calls.setdefault(t,[]).append(a)
def setters(ent,r):
    n=0; sites=calls.get(ent,[])
    for a in sites:
        b=a-4
        readafter=False
        while b in ins and a-b<200:
            op,arg=ins[b]
            if op.startswith('b'): break
            p=[x.strip() for x in arg.split(';')[0].split(',')]
            if p and p[0]=='r%d'%r and not op.startswith(('st','cmp')):
                if not readafter: n+=1   # written, and nothing reads it before the call: an argument
                break
            if re.search(r'\br%d\b'%r, arg.split(';')[0]): readafter=True   # read (a temporary) - not passed
            b-=4
    return n,len(sites)
out=0
for ent in sorted(rows):
    f=os.path.join(D,'0x%x.txt'%ent)
    if not os.path.exists(f): continue
    sig=open(f).readline(); sig=open(f).read(600)
    m=re.search(r'// Signature: .*?\((.*)\)',sig)
    if not m: continue
    ps=[p for p in m.group(1).split(',') if p.strip() and p.strip()!='void' and '...' not in p]
    nint=len([p for p in ps if not re.search(r'\b(double|float)\b',p)])
    if '...' in m.group(1): continue
    lr,lt,la,info,succ=g['classify'](ent)
    for r in sorted(x for x in la if isinstance(x,int) and 3+nint<=x<=10):
        n,tot=setters(ent,r)
        if n: out+=1; print('%x\t%s\tparams=%d\tr%d live at entry (%s), set by %d/%d callers'%(ent,os.path.basename(f),nint,r,'read' if r in lr else 'forwarded',n,tot))
print('hidden arguments:',out)
