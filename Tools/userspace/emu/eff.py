import sys,random,os,collections,struct,re
sys.path.insert(0,'/tmp/emu')
os.environ['NOSTK']='1'
from drive import *
fn=sys.argv[1]; nargs=int(sys.argv[2]); seeds=int(sys.argv[3])
es=int(fn.split('_')[1],16); er=entries_r[fn]
VOID=bool(re.search(r'extern void %s\('%fn,open('/tmp/lk_r6/decls.h').read()))
s=Runner(Image('/tmp/emu/stock.bin',None)); r=Runner(Image(os.environ['RBIN'],None))
BUF=STACK+0x8000
def snap(rn,w):
    out={}
    for base,size,tag in ((CTXA,CTX_SIZE,'c'),(AA,A_SIZE,'a'),(HEAP,0x8000,'h'),(BUF,0x100,'b')):
        d=bytes(rn.uc.mem_read(base,size))
        for i in range(0,size,4):
            out[(tag,i)]=norm(w,struct.unpack('>I',d[i:i+4])[0])
    return out
bad=collections.Counter(); ex={}
tot=same=0
for seed in range(seeds):
    rng=random.Random(seed); ctx,heap,a=mkmem(rng,{})
    args=[CTXA]+[rng.choice([0,1,2,3,4,5,7,9,0xffffffff,HEAP+0x100,BUF]) for _ in range(nargs-1)]
    res=[]
    for rn,e,w in ((s,es,'s'),(r,er,'r')):
        rn.reset(ctx,heap,a); rn.uc.mem_write(BUF,bytes(0x100))
        st,rv=rn.call(e,list(args),limit=100000)
        res.append((st,norm(w,rv),snap(rn,w),[normcall(w,c) for c in rn.log],rn.bad_read))
    if res[0][0]!='RET' or res[1][0]!='RET' or res[0][4] or res[1][4]: continue
    tot+=1
    d=[k for k in res[0][2] if res[0][2][k]!=res[1][2][k]]
    retdiff=(res[0][1]!=res[1][1]) and not VOID
    if not retdiff and not d and res[0][3]==res[1][3]: same+=1; continue
    key=('ret' if retdiff else '')+(' mem:'+d[0][0] if d else '')+(' calls' if res[0][3]!=res[1][3] else '')
    bad[key]+=1; ex.setdefault(key,(seed,[hex(x) for x in args],res[0][1],res[1][1],[(k,res[0][2][k],res[1][2][k]) for k in d[:3]]))
print(fn,'compared',tot,'same',same)

for k,v in bad.most_common(5): print(v,k,ex[k])
