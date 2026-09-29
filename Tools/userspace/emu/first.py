import sys,random,collections
sys.path.insert(0,'/tmp/emu')
from drive import *
fn=sys.argv[1]; nargs=int(sys.argv[2]); seeds=int(sys.argv[3]); show=int(sys.argv[4]) if len(sys.argv)>4 else 3
s=Runner(Image('/tmp/emu/stock.bin',None)); r=Runner(Image(os.environ.get('RBIN','/tmp/emu/rebuilt.bin'),None)) if False else Runner(Image(__import__('os').environ.get('RBIN','/tmp/emu/rebuilt.bin'),None))
es=int(fn.split('_')[1],16); er=entries_r[fn]
cnt=collections.Counter(); shown=0; nreach=0; nid=0; stat=collections.Counter()
for seed in range(seeds):
    rng=random.Random(seed); ctx,heap,a=mkmem(rng,{})
    args=[CTXA]+[rng.choice([0,1,2,3,4,5,7,9,0xffffffff,HEAP+0x100]) for _ in range(nargs-1)]
    out=[]
    for rn,e,w in ((s,es,'s'),(r,er,'r')):
        rn.reset(ctx,heap,a); st,rv=rn.call(e,list(args)); out.append((st,rv,[normcall(w,c) for c in rn.log]))
    (st1,rv1,l1),(st2,rv2,l2)=out
    stat[(st1[:3],st2[:3])]+=1
    if not (l1 or l2): continue
    nreach+=1
    first=None
    for i in range(min(len(l1),len(l2))):
        if l1[i]!=l2[i]: first=i;break
    if first is None and len(l1)!=len(l2): first=min(len(l1),len(l2))
    if first is None: nid+=1; continue
    key=(l1[first][0] if first<len(l1) else None, first)
    cnt[key]+=1
    if shown<show:
        shown+=1; print('seed',seed,'args',[hex(x) for x in args],'first diff call',first,'stock/rebuilt status',st1,st2,'ncalls',len(l1),len(l2))
        print('  stock  ',l1[first] if first<len(l1) else None); print('  rebuilt',l2[first] if first<len(l2) else None)
print('reached',nreach,'identical',nid,'status',dict(stat)); print(cnt.most_common(8))
