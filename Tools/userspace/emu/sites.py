import sys,random,collections,os
sys.path.insert(0,'/tmp/emu')
os.environ['NOSTK']='1'
from drive import *
TARGETS={
 'FUN_00093000':(7,{0x930fc:'930f8 12ec'}),
 'FUN_0009b430':(2,{0x9b740:'9b73c 12ec'}),
 'FUN_00099e50':(3,{0x9a4bc:'9a4b8 12fc',0x9a534:'9a530 12fc'}),
 'FUN_00096d80':(1,{0x97380:'9737c 12f4',0x972e8:'972e4 12f0'}),
 'FUN_00097440':(7,{0x9774c:'97748 12f0',0x97bc8:'97bc4 132c',0x98380:'9837c 12f4',0x981e0:'981dc 12f4',0x97fe4:'97fe0 12ec',0x98048:'98044 12f4'}),
 'FUN_00098500':(10,{0x990ac:'990a8 12f4',0x994d0:'994cc 132c',0x9992c:'99928 12ec',0x98f8c:'98f88 12f0'}),
}
def go(fn,seeds):
    nargs,T=TARGETS[fn]
    s=Runner(Image('/tmp/emu/stock.bin',None)); r=Runner(Image(os.environ.get('RBIN','/tmp/emu/rebuilt.bin'),None))
    es=int(fn.split('_')[1],16); er=entries_r[fn]
    res=collections.defaultdict(collections.Counter); ex={}
    for seed in range(seeds):
        rng=random.Random(seed); ctx,heap,a=mkmem(rng,{})
        args=[CTXA]+[rng.choice([0,1,2,3,4,5,7,9,0xffffffff,HEAP+0x100]) for _ in range(nargs-1)]
        logs=[]
        for rn,e,w in ((s,es,'s'),(r,er,'r')):
            rn.reset(ctx,heap,a); rn.call(e,list(args)); logs.append(([normcall(w,c) for c in rn.log],[c[4] for c in rn.log]))
        (l1,lr1),(l2,lr2)=logs
        for i,lr in enumerate(lr1):
            if lr in T:
                name=T[lr]
                if i>=len(l2): res[name]['rebuilt-missing']+=1; continue
                if l1[:i+1]==l2[:i+1]: res[name]['aligned-equal']+=1
                elif l1[i]==l2[i]: res[name]['call-equal(prefix differs)']+=1
                else:
                    res[name]['CALL-DIFFERS']+=1; ex.setdefault(name,(seed,i,l1[i],l2[i]))
    return res,ex
if __name__=='__main__':
    fn=sys.argv[1]; res,ex=go(fn,int(sys.argv[2]))
    for k,v in res.items(): print(fn,k,dict(v))
    for k,v in ex.items(): print('EXAMPLE',k,v)
