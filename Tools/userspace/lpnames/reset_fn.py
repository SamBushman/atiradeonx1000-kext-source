#!/usr/bin/env python3
"""reset_fn.py DIR FN... : put FN back to its HEAD state (part file text and every names*.tsv row of FN); rows of FN in names_lpE_y.tsv are dropped"""
import sys,re,subprocess,glob,os
d=sys.argv[1]; fns=sys.argv[2:]
HDR=re.compile(r'^/\* (\S+) @ 0x')
def head(path): return subprocess.run(['git','show','HEAD:'+path],capture_output=True,text=True,errors='surrogateescape').stdout
for f in sorted(glob.glob(os.path.join(d,'part_*.c'))):
    L=open(f,errors='surrogateescape').read().split('\n'); H=head(f).split('\n'); ch=False
    for fn in fns:
        def rng(X):
            s=next((i for i,l in enumerate(X) if HDR.match(l) and HDR.match(l).group(1)==fn),None)
            if s is None: return None
            e=next((i for i in range(s+1,len(X)) if HDR.match(X[i])),len(X)); return s,e
        a=rng(L); b=rng(H)
        if a and b: L[a[0]:a[1]]=H[b[0]:b[1]]; ch=True; print('text reset',fn)
    if ch: open(f,'w',errors='surrogateescape').write('\n'.join(L))
for t in sorted(glob.glob(os.path.join(d,'names*.tsv'))):
    cur=open(t,errors='surrogateescape').read().rstrip('\n').split('\n')
    if t.endswith('names_lpE_y.tsv'):
        keep=[l for l in cur if l.split('\t')[1] not in fns]
        open(t,'w',errors='surrogateescape').write('\n'.join(keep)+'\n'); continue
    h=head(t).rstrip('\n').split('\n') if head(t) else []
    hrows=[l for l in h if len(l.split('\t'))>2 and l.split('\t')[1] in fns]
    crows=[l for l in cur if len(l.split('\t'))>2 and l.split('\t')[1] in fns]
    if sorted(hrows)==sorted(crows): continue
    keep=[l for l in cur if not (len(l.split('\t'))>2 and l.split('\t')[1] in fns)]
    open(t,'w',errors='surrogateescape').write('\n'.join(keep+hrows)+'\n'); print('rows reset in',os.path.basename(t),len(hrows))
