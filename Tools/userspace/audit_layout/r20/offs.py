import json,re,sys,os,collections
sys.path.insert(0,'.')
import stockobjs as S
exec(open('inv.py').read().split("res={}")[0])   # recs, G, helpers
D={'ATI':'ATIRadeonX1000GLDriver','lib':'libGLProgrammability'}
rowsmap=collections.defaultdict(dict)   # (dir,fn)->{new:old}
for d in D.values():
    for l in open(os.path.expanduser(f'~/wt/r20/Userspace/{d}/ppc/removed_rows_r20.rows')):
        c=l.rstrip('\n').split('\t')
        if len(c)>5 and c[2]=='local': rowsmap[(d,c[3])][c[5]]=c[4]
        # also keep keyed by func-name alias handled below
led={}
for d,b in (('ATIRadeonX1000GLDriver','gld'),('libGLProgrammability','glp')):
    for l in open(os.path.expanduser(f'~/wt/r20/Userspace/{d}/ppc/ledger.tsv')):
        f=l.rstrip('\n').split('\t')
        if len(f)>2 and f[0].startswith('0x'): led[(d,f[2])]=(b,int(f[0],16),int(f[1]))
OVR={'arbParseParamBinding':(0x89864,3780),'Block__flattenAndRebuildAddMulTree':(0x181f00,6000)}
def stock(b,addr,size):
    m=S.load(b);I=S.dis(m,addr,size);fs=None;esc=set()
    for i in I:
        if i.mnemonic=='stwu' and fs is None and 'r1' in i.op_str: fs=int(re.search(r'-(0x[0-9a-f]+|\d+)\(',i.op_str).group(1),0)
        mm=re.match(r'(r\d+), r1, (-?(?:0x)?[0-9a-f]+)$',i.op_str)
        if i.mnemonic=='addi' and mm: esc.add(int(mm.group(2),0))
    return fs,esc
def rawof(mp,name):
    seen=0
    while name in mp and seen<20: name=mp[name]; seen+=1
    return name
tot=collections.Counter()
for (p,fn),rs in G.items():
    rel=os.path.relpath(p,R); d=rel.split('/')[1]; b='gld' if d.startswith('ATI') else 'glp'
    if fn in OVR: addr,size=OVR[fn]
    elif (d,fn) in led: _,addr,size=led[(d,fn)]
    else: print('NOLEDGER',fn); continue
    fs,esc=stock(b,addr,size)
    # function-name aliases in rows: try fn and any key of rowsmap with same d
    mp=None
    for (dd,nm),m in rowsmap.items():
        if dd==d and (nm==fn or nm==('FUN_%08x'%addr) or nm==('FUN_%06x'%addr)): mp={**(mp or {}),**m}
    mp=mp or {}
    out=[]
    for r in rs:
        if 'members' not in r: continue
        Bs=collections.Counter(); unk=[]
        for old,w,k in r['members']:
            raw=rawof(mp,old)
            m=re.match(r'(?:local|uStack|Stack|auStack|fStack|dStack)_?([0-9a-f]+)$',raw) or re.match(r'(?:local_|uStack_|auStack_|fStack_)([0-9a-f]+)',raw)
            if not m: unk.append((old,raw)); continue
            off=fs-int(m.group(1),16)
            Bs[off-(1 if r.get('ctype')=='byte' else 4)*w]+=1
        B=Bs.most_common(1)[0][0] if Bs else None
        ok = B is not None and len(Bs)==1 and (B in esc)
        out.append((r['arr'],B,dict(Bs),B in esc if B is not None else None,unk[:3]))
        tot['arr']+=1; tot['ok']+= ok; tot['inconsistent']+= len(Bs)>1; tot['noraw']+= (B is None)
        if not ok: print('CHECK',fn,r['arr'],'base',B and hex(B),{hex(k):v for k,v in Bs.items()},'in_esc',B in esc if B is not None else None,'unk',unk[:3])
print(dict(tot))
