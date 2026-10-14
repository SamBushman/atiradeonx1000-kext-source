import re,sys,glob,collections,os
R=os.path.expanduser('~/atiradeonx1000-kext-source')
def params(sig):
    i=sig.index('('); depth=0; j=None
    for k in range(i,len(sig)):
        if sig[k]=='(': depth+=1
        elif sig[k]==')':
            depth-=1
            if depth==0: j=k;break
    inner=sig[i+1:j].strip()
    if inner in ('','void'): return 0
    d=0;n=1
    for c in inner:
        if c in '(<': d+=1
        elif c in ')>': d-=1
        elif c==',' and d==0: n+=1
    return n
vt=collections.defaultdict(list); cls=None
for l in open(R+'/Ledger/kext_ppc_vtables.txt'):
    l=l.rstrip('\n')
    if l.startswith('#'):
        m=re.match(r'# (\S+) vtable',l); cls=m.group(1) if m else None; continue
    m=re.match(r'0x([0-9a-f]+) (.*)',l)
    if m and cls and '(' in m.group(2):
        off=int(m.group(1),16); sig=m.group(2)
        if sig.startswith('___cxa'): continue
        vt[off].append((cls,sig,params(sig)+1))
def split_args(s):
    out=[];d=0;cur=''
    for c in s:
        if c in '([{': d+=1
        elif c in ')]}': d-=1
        if c==',' and d==0: out.append(cur);cur=''
        else: cur+=c
    if cur.strip(): out.append(cur)
    return out
def match(s,i):  # s[i]=='(' -> index of matching ')'
    d=0
    for k in range(i,len(s)):
        if s[k]=='(': d+=1
        elif s[k]==')':
            d-=1
            if d==0: return k
    return -1
sites=[]
for f in sorted(glob.glob(R+'/Sources/*.cpp')):
    s=open(f).read()
    for m in re.finditer(r'VCALL\(',s):
        a=m.end()-1; b=match(s,a)
        if b<0: continue
        inner=split_args(s[a+1:b])
        if len(inner)!=2: continue
        offs=inner[1].strip()
        try: off=int(offs,0)
        except: continue
        # next must be ')(' args ')'
        k=b+1
        while s[k] in ' \n\t': k+=1
        if s[k]!='(': continue
        e=match(s,k)
        args=split_args(s[k+1:e])
        line=s.count('\n',0,m.start())+1
        sites.append((os.path.basename(f),line,off,len(args),inner[0].strip()[:40]))
short=[];unk=[]
for f,line,off,n,recv in sites:
    c=vt.get(off)
    if not c: unk.append((f,line,off,n,recv)); continue
    need=[x for x in c if x[2]>n]
    if need: short.append((f,line,off,n,recv,c,need))
print("sites",len(sites),"offset-known",len(sites)-len(unk),"unknown-offset",len(unk),"flagged-short",len(short))
import json
json.dump({'short':[(f,l,o,n,r,[(c,s,p) for c,s,p in need],len(c)) for f,l,o,n,r,c,need in short],'unk':unk},open('/tmp/vcall_sweep_out.json','w'))
byoff=collections.Counter((o) for f,l,o,n,r,c,need in short)
print(sorted(byoff.items(), key=lambda x:-x[1])[:25])
