import sys,os,random
os.environ['RBIN']='/tmp/emu/rebuilt_r6.bin'; os.environ['RNM']='/tmp/emu/rebuilt_r6.nm'
sys.path.insert(0,'/tmp/emu')
from drive import *
targets=['FUN_00126984','FUN_00126a10','FUN_00126c40','FUN_001271d8','FUN_00126b28']
s=Runner(Image('/tmp/emu/stock.bin',None)); r=Runner(Image('/tmp/emu/rebuilt_r6.bin',None))
def trace(rn,ents):
    seen=[]
    rn.uc.hook_add(UC_HOOK_CODE,lambda uc,ad,sz,ud: seen.append(ents[ad]) if ad in ents else None)
    return seen
es=int('1275a0',16); er=entries_r['FUN_001275a0']
sm={int(t.split('_')[1],16):t for t in targets}; rm={entries_r[t]:t for t in targets}
diff=0
for seed in range(40):
    rng=random.Random(seed); ctx,heap,a=mkmem(rng,{})
    args=[HEAP+0x4000, 0, HEAP+0x5000, 0]
    out=[]
    for rn,e,ents in ((s,es,sm),(r,er,rm)):
        rn.reset(ctx,heap,a)
        # fresh hooks each run: remove by creating tracer list
        seen=[]
        h=rn.uc.hook_add(UC_HOOK_CODE,lambda uc,ad,sz,ud,seen=seen,ents=ents: seen.append(ents[ad]) if ad in ents else None)
        st,rv=rn.call(e,list(args),limit=100000)
        rn.uc.hook_del(h); out.append((st,seen))
    if out[0][1]!=out[1][1]: diff+=1; print(seed,out[0],out[1])
print('diffs',diff)
