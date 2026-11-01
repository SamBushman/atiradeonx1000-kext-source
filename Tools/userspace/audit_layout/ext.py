import re,sys,glob,os,collections
# ext.py ppcdir [only-func-substr...] : for each &local / array-local passed to a corpus callee, compare callee's accessed extent through that parameter vs the local's declared size
d=sys.argv[1];only=sys.argv[2:]
tn={'undefined1':1,'undefined2':2,'undefined4':4,'undefined8':8,'char':1,'byte':1,'bool':1,'short':2,'ushort':2,'int':4,'uint':4,'float':4,'dword':4,'double':8,'undefined':1,'long':4,'ulong':4,'longlong':8,'ulonglong':8}
files=sorted(glob.glob(d+'/part_*.c')+glob.glob(d+'/unowned_code/part_*.c'))
F={}  # name -> (params, code, file)
for fp in files:
    t=open(fp,errors='replace').read()
    for m in re.finditer(r'(?:^|\n)/\* (\S+) @ (0x[0-9a-f]+) \((\d+) bytes\) \*/\n',t):
        e=t.find('\n/* ',m.end());b=t[m.end():e if e>0 else None];i=b.find('{')
        if i<0: continue
        hdr=b[:i];code=b[i:]
        pm=re.search(r'\(([^)]*)\)',hdr)
        params=[x.strip() for x in pm.group(1).split(',')] if pm and pm.group(1).strip() else []
        F[m.group(1)]=(params,code,os.path.basename(fp),hdr)
def extent(callee,idx,depth=0):
    if callee not in F: return None
    params,code,_,_=F[callee]
    if idx>=len(params): return None
    p=params[idx].strip()
    mx=0;seen=False
    pat=re.escape(p)
    for m in re.finditer(r'\*\s*\(\s*([A-Za-z_ ]+?)\s*\*\s*\)\s*\(\s*'+pat+r'\s*\+\s*(0x[0-9a-fA-F]+|\d+)\s*\)',code):
        mx=max(mx,int(m.group(2),0)+tn.get(m.group(1).strip(),4));seen=True
    for m in re.finditer(r'(?<![A-Za-z0-9_])'+pat+r'\s*\[\s*(0x[0-9a-fA-F]+|\d+)\s*\]',code):
        mx=max(mx,(int(m.group(1),0)+1)*4);seen=True   # element size unknown; assume int-ish (lower bound)
    for m in re.finditer(r'\*\s*(?:\(\s*[A-Za-z_ ]+\s*\*\s*\)\s*)?'+pat+r'(?![A-Za-z0-9_])',code):
        mx=max(mx,4);seen=True
    # pass-through to deeper callees
    if depth<3:
        for cm in re.finditer(r'([A-Za-z_][A-Za-z0-9_]*)\s*\(([^;]*)\)',code):
            args=split(cm.group(2))
            for k,a in enumerate(args):
                if a.strip()==p:
                    r=extent(cm.group(1),k,depth+1)
                    if r: mx=max(mx,r);seen=True
    return mx if seen else None
def split(s):
    out=[];dep=0;cur=''
    for ch in s:
        if ch in '([': dep+=1
        if ch in ')]': dep-=1
        if ch==',' and dep==0: out.append(cur);cur=''
        else: cur+=ch
    out.append(cur);return out
n=0
for fn,(params,code,fil,hdr) in F.items():
    if only and not any(o in fn for o in only): continue
    decl={}
    for dm in re.finditer(r'^\s*([A-Za-z_][A-Za-z0-9_ ]*?)\s*(\*?)\s*([A-Za-z_][A-Za-z0-9_]*)\s*(?:\[(\d+)\])?\s*;',code,re.M):
        ty,ptr,nm,sz=dm.groups();el=4 if ptr else tn.get(ty.strip(),None)
        if el: decl[nm]=(el*(int(sz) if sz else 1),sz is not None)
    for cm in re.finditer(r'([A-Za-z_][A-Za-z0-9_]*)\s*\(((?:[^;()]|\([^()]*\))*)\)',code):
        callee=cm.group(1)
        for k,a in enumerate(split(cm.group(2))):
            a=a.strip();mm=re.fullmatch(r'&\s*([A-Za-z_][A-Za-z0-9_]*)',a) or (re.fullmatch(r'([A-Za-z_][A-Za-z0-9_]*)',a) if a in decl and decl[a][1] else None)
            if not mm: continue
            nm=mm.group(1)
            if nm not in decl: continue
            ex=extent(callee,k)
            if ex and ex>decl[nm][0]:
                print(f'{fil} {fn}: {callee} arg{k} gets {"&" if a.startswith("&") else ""}{nm} (size {decl[nm][0]}) callee extent >= {ex}');n+=1
print('TOTAL',n)
