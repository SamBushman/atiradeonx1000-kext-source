import sys,random,os,collections,json
sys.path.insert(0,'/tmp/emu')
os.environ['NOSTK']='1'
from drive import *
fn=sys.argv[1]; seeds=int(sys.argv[2])
es=int(fn.split('_')[1],16); er=entries_r.get(fn)
if er is None: print(json.dumps({'fn':fn,'skip':1})); sys.exit()
s=Runner(Image('/tmp/emu/stock.bin',None)); r=Runner(Image(os.environ['RBIN'],None))
def kind(x):
    return x[0] if isinstance(x,tuple) else str(x)
cat=collections.Counter(); reach=ident=0
for seed in range(seeds):
    rng=random.Random(seed); ctx,heap,a=mkmem(rng,{})
    args=[CTXA]+[rng.choice([0,1,2,3,4,5,7,9,0xffffffff,HEAP+0x100]) for _ in range(9)]
    L=[]
    for rn,e,w in ((s,es,'s'),(r,er,'r')):
        rn.reset(ctx,heap,a); rn.call(e,list(args),limit=100000); L.append([normcall(w,c) for c in rn.log])
    l1,l2=L
    if not (l1 or l2): continue
    reach+=1
    k=next((i for i in range(min(len(l1),len(l2))) if l1[i]!=l2[i]),None)
    if k is None:
        if len(l1)==len(l2): ident+=1
        else: cat['COUNT %s'%('rebuilt-short' if len(l2)<len(l1) else 'rebuilt-long')]+=1
        continue
    a1,a2=l1[k],l2[k]
    for p in range(1,len(a1)):
        if a1[p]!=a2[p]:
            cat['%s pos%d %s->%s'%(hex(a1[0]),p,kind(a1[p]),kind(a2[p]))]+=1; break
print(json.dumps({'fn':fn,'reach':reach,'ident':ident,'cat':cat}))
