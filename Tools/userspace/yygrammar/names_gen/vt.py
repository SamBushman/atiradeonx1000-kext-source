import sys,struct,collections,re
sys.path.insert(0,'/home/sam/wt/R1b/Tools/userspace')
import machoutil
m=machoutil.load('/home/sam/Documents/ATI-X1900-Decomp/tiger-hd-pull/libGLProgrammability.dylib')
byaddr={}
for s in m.syms:
    if s['sect'] and (s['type']&0xe)==0xe: byaddr.setdefault(s['value'],s['name'])
def u32(a): return struct.unpack('>I',m.read(a,4))[0]
def cls_of(sym):
    mm=re.match(r'__ZN?K?(\d+)',sym)
    if not mm: return None
    n=int(mm.group(1)); k=mm.start(1)+len(mm.group(1)); return sym[k:k+n]
def slots(a,n=40):
    out=[]
    for i in range(2,n):
        v=u32(a+4*i)
        if v==0 or v>0x98000000 or v<0x97000000: break
        out.append((i-2,byaddr.get(v,'?%x'%v)))
    return out
def guess(a):
    sl=slots(a); c=collections.Counter(cls_of(n) for _,n in sl if cls_of(n) and not n.startswith('___cxa'))
    # most-derived: the class that owns the most slots excluding pure virtual
    return c.most_common(4), sl[:6]
if __name__=='__main__':
    import sys
    for a in map(lambda x:int(x,16),sys.argv[1:]):
        print(hex(a), guess(a))
