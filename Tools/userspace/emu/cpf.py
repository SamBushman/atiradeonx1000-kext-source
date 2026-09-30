import sys,os,random,struct
os.environ['RBIN']='/tmp/emu/rebuilt_r6.bin'; os.environ['RNM']='/tmp/emu/rebuilt_r6.nm'
sys.path.insert(0,'/tmp/emu')
from drive import *
helpers=['FUN_00007ec0','FUN_00007fc0','FUN_00008030']
s=Runner(Image('/tmp/emu/stock.bin',None)); r=Runner(Image('/tmp/emu/rebuilt_r6.bin',None))
es=0x80b0; er=entries_r.get('_gldChoosePixelFormat') or [a for n,a in rsyms.items() if n=='gldChoosePixelFormat'][0]
sm={int(h.split('_')[1],16):h for h in helpers}; rm={entries_r[h]:h for h in helpers}
diff=0
for seed in range(30):
    rng=random.Random(seed); ctx,heap,a=mkmem(rng,{})
    # attribute list: (attr, value)* 0  from the CGL/GLD vocabulary
    words=[rng.choice([0x2,0x3,0x5,0x6,0x8,0x9,0xa,0xc,0x18,0x20,0x22,0x30,0x50,0x58,0x60,0x7e]) for _ in range(rng.randrange(0,12))]
    lst=struct.pack('>%dI'%(len(words)+4),*(words+[0,0,0,0]))
    out=[]
    for rn,e,ents in ((s,es,sm),(r,er,rm)):
        rn.reset(ctx,heap,a); rn.uc.mem_write(HEAP+0x6000,lst)
        seen=[]
        h=rn.uc.hook_add(UC_HOOK_CODE,lambda uc,ad,sz,ud,seen=seen,ents=ents: seen.append(ents[ad]) if ad in ents else None)
        st,rv=rn.call(e,[HEAP+0x5000,HEAP+0x6000],limit=200000)
        rn.uc.hook_del(h); out.append((st,rv&0xffffffff,len(seen), struct.unpack('>I',bytes(rn.uc.mem_read(HEAP+0x5000,4)))[0]))
    if out[0]!=out[1]: diff+=1; print(seed,words,out)
print('diffs',diff)
