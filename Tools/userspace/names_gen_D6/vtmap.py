import sys,struct,collections,re,os
sys.path.insert(0,os.path.expanduser('~/wt/D6/Tools/userspace'))
import machoutil
m=machoutil.load(os.path.expanduser('~/Documents/ATI-X1900-Decomp/tiger-hd-pull/libGLProgrammability.dylib'))
byaddr={}
for s in m.syms:
    if s['sect'] and (s['type']&0xe)==0xe: byaddr.setdefault(s['value'],s['name'])
def u32(a): return struct.unpack('>I',m.read(a,4))[0]
def method_of(sym):
    mm=re.match(r'__ZNK?(\d+)',sym)
    if not mm: return None
    n=int(mm.group(1)); k=mm.end(1)+n; r=sym[k:]
    m2=re.match(r'(\d+)(.*)',r)
    if m2:
        l=int(m2.group(1)); return m2.group(2)[:l]
    if r.startswith('D1E') or r.startswith('D0E') or r.startswith('D2E'): return '~'
    return None
VT={}   # class -> {offset: method}
for s in m.syms:
    nm=s['name']
    if nm.startswith('__ZTV') and s['value']:
        c=re.match(r'__ZTV(\d+)',nm)
        if not c: continue
        n=int(c.group(1)); cls=nm[c.end(1):c.end(1)+n]
        a=s['value']+8; d={}
        for i in range(0,60):
            try: v=u32(a+4*i)
            except Exception: break
            if v==0 or v>0x98000000 or v<0x97000000: break
            mn=method_of(byaddr.get(v,''))
            d[4*i]=(mn,byaddr.get(v,'?%x'%v))
        VT[cls]=d
if __name__=='__main__':
    for c in ('TIntermBinary','TIntermAggregate','TType','TIntermTyped'):
        print(c, {hex(k):v[0] for k,v in list(VT.get(c,{}).items())[:30]})
