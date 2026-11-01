import sys,re
# scanc.py ppcdir addr... : scan function C for local-array subscripts / &local uses that could depend on frame adjacency
d=sys.argv[1]
led={}
for l in open(d+'/ledger.tsv'):
    f=l.rstrip('\n').split('\t')
    if len(f)>3: led[f[0].lower().replace('0x','').lstrip('0')]=(f[2],f[3])
cache={}
def body(name,part):
    if part not in cache: cache[part]=open(f'{d}/{part}.c',errors='replace').read()
    t=cache[part]
    m=re.search(r'/\* '+re.escape(name)+r' @ 0x[0-9a-f]+ \(\d+ bytes\) \*/\n',t)
    e=t.find('\n/* ',m.end())
    return t[m.end():e if e>0 else None]
tn={'undefined1':1,'undefined2':2,'undefined4':4,'undefined8':8,'char':1,'byte':1,'bool':1,'short':2,'ushort':2,'int':4,'uint':4,'float':4,'long':4,'ulong':4,'double':8,'undefined':1,'ulonglong':8,'longlong':8}
for a in sys.argv[2:]:
    nm,part=led.get(a.lower().lstrip('0x').lstrip('0'),(None,None))
    if not nm: print('##',a,'NOT IN LEDGER');continue
    b=body(nm,part)
    i=b.find('{')
    hdr,code=b[:i],b[i:]
    decl={}
    for m in re.finditer(r'^\s*([A-Za-z_][A-Za-z0-9_ ]*?)\s*(\*?)\s*([A-Za-z_][A-Za-z0-9_]*)\s*(?:\[(\d+)\])?\s*;',code,re.M):
        ty,ptr,n,sz=m.groups()
        ty=ty.strip()
        if ptr: s=4
        else: s=tn.get(ty,None)
        decl[n]=(ty+('*' if ptr else ''),int(sz) if sz else None,s)
    arrs={n:v for n,v in decl.items() if v[1] is not None}
    print('##',a,nm,part,'arrays:',{n:(v[0],v[1]) for n,v in arrs.items()})
    # references
    for n,v in decl.items():
        for m in re.finditer(r'(?<![A-Za-z0-9_])'+re.escape(n)+r'\s*\[([^\]]*)\]',code):
            ix=m.group(1).strip()
            if v[1] is None: continue
            if code[max(0,m.start()-30):m.start()].rstrip().endswith(tuple(tn)) and re.fullmatch(r'\d+',ix) and int(ix)==v[1]: continue
            if v[1] is not None and re.fullmatch(r'-?\d+',ix) and 0<=int(ix)<v[1]: continue
            print('   IDX',n,v[0],v[1],'[',ix,']')
        for m in re.finditer(r'&\s*'+re.escape(n)+r'(?![A-Za-z0-9_])',code):
            s=code[max(0,m.start()-60):m.end()+30].replace('\n',' ')
            print('   ADDR',n,v[0],v[1],'|',s)
