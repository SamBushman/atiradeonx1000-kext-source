import re,glob,os
tn={'undefined1':1,'undefined2':2,'undefined4':4,'undefined8':8,'char':1,'byte':1,'bool':1,'short':2,'ushort':2,'int':4,'uint':4,'float':4,'dword':4,'double':8,'undefined':1,'long':4,'ulong':4,'longlong':8,'ulonglong':8}
def calls(code):
    for m in re.finditer(r'([A-Za-z_][A-Za-z0-9_]*)\s*\(',code):
        i=m.end();dep=1
        while i<len(code) and dep:
            if code[i]=='(': dep+=1
            elif code[i]==')': dep-=1
            i+=1
        yield m.group(1),code[m.end():i-1]
def split(s):
    out=[];dep=0;cur=''
    for ch in s:
        if ch in '([': dep+=1
        if ch in ')]': dep-=1
        if ch==',' and dep==0: out.append(cur);cur=''
        else: cur+=ch
    out.append(cur);return out
class Corpus:
    def __init__(s,d):
        s.F={};s.d=d
        for fp in sorted(glob.glob(d+'/part_*.c')+glob.glob(d+'/unowned_code/part_*.c')):
            t=open(fp,errors='replace').read()
            for m in re.finditer(r'(?:^|\n)/\* (\S+) @ (0x[0-9a-f]+) \((\d+) bytes\) \*/\n',t):
                e=t.find('\n/* ',m.end());b=t[m.end():e if e>0 else None];i=b.find('{')
                if i<0: continue
                hdr=b[:i];code=b[i:]
                pm=re.search(r'\(([^)]*)\)',hdr)
                params=[x.strip() for x in pm.group(1).split(',')] if pm and pm.group(1).strip() else []
                s.F[m.group(1)]=(params,code,os.path.basename(fp)[:-2],int(m.group(2),16))
        s.cache={}
    def decls(s,fn):
        code=s.F[fn][1];decl={}
        for dm in re.finditer(r'^\s*([A-Za-z_][A-Za-z0-9_ ]*?)\s*(\*?)\s*([A-Za-z_][A-Za-z0-9_]*)\s*(?:\[(\d+)\])?\s*;',code,re.M):
            ty,ptr,nm,sz=dm.groups();el=4 if ptr else tn.get(ty.strip(),None)
            if el: decl[nm]=(el*(int(sz) if sz else 1),sz is not None)
        return decl
    def extent(s,callee,idx,depth=0):
        key=(callee,idx)
        if key in s.cache: return s.cache[key]
        s.cache[key]=None
        r=s._ext(callee,idx,depth);s.cache[key]=r;return r
    def _ext(s,callee,idx,depth):
        if callee not in s.F: return None
        params,code,_,_=s.F[callee]
        if idx>=len(params): return None
        p=params[idx].strip().split()[-1].lstrip('*')
        mx=0;seen=False;pat=re.escape(p)
        for m in re.finditer(r'\*\s*\(\s*([A-Za-z_ ]+?)\s*\*\s*\)\s*\(\s*'+pat+r'\s*\+\s*(0x[0-9a-fA-F]+|\d+)\s*\)',code):
            mx=max(mx,int(m.group(2),0)+tn.get(m.group(1).strip(),4));seen=True
        for m in re.finditer(r'(?<![A-Za-z0-9_])'+pat+r'\s*\[\s*(0x[0-9a-fA-F]+|\d+)\s*\]',code):
            mx=max(mx,(int(m.group(1),0)+1)*4);seen=True
        for m in re.finditer(r'\*\s*(?:\(\s*[A-Za-z_ ]+\s*\*\s*\)\s*)?'+pat+r'(?![A-Za-z0-9_])',code):
            mx=max(mx,4);seen=True
        if depth<3:
            for cn_,ar_ in calls(code):
                for k,a in enumerate(split(ar_)):
                    if a.strip()==p:
                        r=s.extent(cn_,k,depth+1)
                        if r: mx=max(mx,r);seen=True
        return mx if seen else None
    def overlays(s,fn):
        """list of (name,size,E,why)"""
        params,code,part,addr=s.F[fn];decl=s.decls(fn);out=[]
        for callee,argtxt in calls(code):
            args=split(argtxt)
            for k,a in enumerate(args):
                a=a.strip()
                mm=re.fullmatch(r'&\s*([A-Za-z_][A-Za-z0-9_]*)',a)
                if not mm and a in decl and decl[a][1]: mm=re.fullmatch(r'([A-Za-z_][A-Za-z0-9_]*)',a)
                if not mm or mm.group(1) not in decl: continue
                nm=mm.group(1)
                if re.fullmatch(r'_?(?:memcpy|memset|bzero|memmove)',callee) and k==0:
                    try: n=int(args[2].strip(),0) if callee.lstrip('_') in('memcpy','memmove','memset') else int(args[1].strip(),0)
                    except: n=None
                    if n and n>decl[nm][0]: out.append((nm,decl[nm][0],n,callee))
                    continue
                m2=re.match(r'_?io_connect_method_(\w+)',callee)
                if m2: continue
                ex=s.extent(callee,k)
                if ex and ex>decl[nm][0]: out.append((nm,decl[nm][0],ex,f'{callee}.arg{k}'))
        # negative / oob array subscripts
        for nm,(sz,isarr) in decl.items():
            if not isarr: continue
            for sm in re.finditer(r'(?<![A-Za-z0-9_.>])'+re.escape(nm)+r'\s*\[([^\]]*)\]',code):
                ctx=code[max(0,sm.start()-25):sm.start()]
                if re.search(r'(undefined\d?|char|uint|int|float|byte|dword|bool|short|ushort)\s*\**\s*$',ctx): continue
                ix=sm.group(1).strip()
                if re.search(r'-\s*\d|\+\s*-',ix): out.append((nm,sz,None,f'subscript[{ix}]'))
        return out
