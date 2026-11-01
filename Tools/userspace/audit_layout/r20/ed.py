import re,sys,os
D=os.path.expanduser('~/wt/r20/Userspace/')
def path(b,part): return D+('ATIRadeonX1000GLDriver' if b=='gld' else 'libGLProgrammability')+'/ppc/'+part+'.c'
class Fn:
    def __init__(s,b,part,name):
        s.p=path(b,part); s.t=open(s.p).read()
        m=re.search(r'/\* '+re.escape(name)+r' @[^\n]*\n',s.t); assert m,name
        e=s.t.find('\n/* ',m.end()); s.s=m.start(); s.e=e if e>0 else len(s.t)
        s.name=name
    def body(s): return s.t[s.s:s.e]
    def put(s,b): s.t=s.t[:s.s]+b+s.t[s.e:]; s.e=s.s+len(b)
    def save(s): open(s.p,'w').write(s.t)
def split(b):
    i=b.find('{\n')+2
    j=b.find('\n  \n',i)
    if j<0: raise SystemExit('no blank-line decl terminator')
    return b[:i],b[i:j],b[j:]
import json
LOG=os.path.expanduser('~/g5logs/tmp_r20/edlog.jsonl')
def rec(fn,arr,nwords,members,head=None,ctype='int',keep_decl_for=None):
    json.dump(dict(p=fn.p,fn=fn.name,arr=arr,n=nwords,members=members,head=head,ctype=ctype),open(LOG,'a'));open(LOG,'a').write('\n')
    """members: list of (old, word, kind) kind 'v'(value) | 'p'(pointer to word) ; head: old head array name replaced by arr (same word 0)"""
    b=fn.body();pre,decl,post=split(b)
    L=decl.split('\n');first=None;out=[]
    olds={m[0] for m in members}|({head} if head else set())
    for i,l in enumerate(L):
        mm=re.match(r'\s+[A-Za-z_][A-Za-z0-9_ \*]*?\b([A-Za-z_][A-Za-z0-9_]*)\s*(\[[^\]]*\])?;\s*$',l)
        if mm and mm.group(1) in olds:
            if first is None: first=len(out); out.append('@@'+arr)
            olds.discard(mm.group(1)); continue
        out.append(l)
    assert not olds,('decl not found',olds)
    out[first]=f'  {ctype} {arr} [{nwords}];'
    decl='\n'.join(out)
    def sub(txt):
        for old,w,k in members:
            rep=f'{arr}[{w}]' if k=='v' else (f'(*(undefined1 *)&{arr}[{w}])' if k=='b' else (f'(&{arr}[{w}])' if w else arr))
            txt=re.sub(r'(?<![A-Za-z0-9_])'+re.escape(old)+r'(?![A-Za-z0-9_])',lambda m:rep,txt)
        if head and head!=arr: txt=re.sub(r'(?<![A-Za-z0-9_])'+re.escape(head)+r'(?![A-Za-z0-9_])',arr,txt)
        return txt
    post=sub(post)
    fn.put(pre+decl+post)
def retype_ptr(fn,old,newtype):
    b=fn.body()
    b2=re.sub(r'(\n\s+)undefined1 \*'+re.escape(old)+';',lambda m:m.group(1)+newtype+' *'+old+';',b)
    assert b2!=b,('ptr decl not found',old); fn.put(b2)

def recs(fn,arr,fields,align_note=None):
    """fields: list of (ctype, fname, old, kind) ; kind 'v' value (arr.f), 'p' old was an array used as pointer (&arr.f). One struct local replaces the olds."""
    json.dump(dict(p=fn.p,fn=fn.name,arr=arr,struct=fields),open(LOG,'a'));open(LOG,'a').write('\n')
    b=fn.body();pre,decl,post=split(b)
    L=decl.split('\n');first=None;out=[];olds={f[2] for f in fields}
    for l in L:
        mm=re.match(r'\s+[A-Za-z_][A-Za-z0-9_ \*]*?\b([A-Za-z_][A-Za-z0-9_]*)\s*(\[[^\]]*\])?;\s*$',l)
        if mm and mm.group(1) in olds:
            if first is None: first=len(out); out.append('@@')
            olds.discard(mm.group(1)); continue
        out.append(l)
    assert not olds,('decl not found',olds)
    out[first]='  struct { '+' '.join(f'{t} {n};' for t,n,o,k in fields)+f' }} {arr};'
    post2=post
    for t,n,o,k in fields:
        rep=f'{arr}.{n}' if k=='v' else f'(&{arr}.{n})'
        post2=re.sub(r'(?<![A-Za-z0-9_])'+re.escape(o)+r'(?![A-Za-z0-9_])',lambda m:rep,post2)
    fn.put(pre+'\n'.join(out)+post2)
