import json,re,subprocess,sys,os,collections,difflib
sys.path.insert(0,'.')
from ed import split
R='/home/sam/wt/r20/'
BASE=sys.argv[1] if len(sys.argv)>1 else 'aaec42e4'
recs=[json.loads(l) for l in open('edlog.jsonl') if l.strip()]
last={}
for i,r in enumerate(recs): last[(r['p'],r['fn'],r['arr'])]=i
order=sorted(last.values())
G=collections.OrderedDict()
for i in order: G.setdefault((recs[i]['p'],recs[i]['fn']),[]).append(recs[i])
def fnbody(t,name):
    m=re.search(r'/\* '+re.escape(name)+r' @[^\n]*\n',t); e=t.find('\n/* ',m.end()); return t[m.start():e if e>0 else len(t)]
def norm(t):
    t=re.sub(r'\(&([A-Za-z_]\w*)\[(\d+)\]\)\[(\d+)\]',lambda m:f'{m.group(1)}[{int(m.group(2))+int(m.group(3))}]',t)
    return t
def inv(post,r):
    a=r['arr']
    if 'struct' in r:
        for t,n,o,k in r['struct']:
            rep=f'{a}.{n}' if k=='v' else f'(&{a}.{n})'
            post=post.replace(rep,o)
        return post
    head=r.get('head'); 
    for old,w,k in sorted(r['members'],key=lambda m:-len(m[0])):
        if k=='v': post=post.replace(f'{a}[{w}]',old)
        elif k=='b': post=post.replace(f'(*(undefined1 *)&{a}[{w}])',old)
        else:
            if w: post=post.replace(f'(&{a}[{w}])',old)
            else: post=re.sub(r'(?<![\w\.])'+re.escape(a)+r'(?![\w\[\.])',old,post)
    if head and head!=a: post=re.sub(r'(?<![\w\.])'+re.escape(a)+r'(?![\w\[\.])',head,post)
    return post
EXTRA={'ffvpEmitBlendedClipPosition':{'blendTemp3[1]':'blendTemp3Reg[0]'},
 'TGenericLinker__FixOutputReads':{'opRecord[0] = 0x20000000':'opHeader = 0x20000000',',opHeader,0,0':',&opHeader,0,0'},
 '_DetectConstantLoopsSimple':{'((undefined2 *)&opSrc0B)[1 + sourceIndex * 4]':'(&opSrc0BHigh)[sourceIndex * 4]'}}
INTENDED={'arbParseParamBinding':'W-component stores added per stock 0x89864 (not a rename)'}
res={}
for (p,fn),rs in G.items():
    rel=os.path.relpath(p,R)
    old=subprocess.check_output(['git','show',f'{BASE}:{rel}'],cwd=R).decode()
    new=open(p).read()
    ob=fnbody(old,fn); nb=fnbody(new,fn); nb=re.sub(r'(\n#(?:undef|define) [^\n]*)+$','',nb); ob=re.sub(r'(\n#(?:undef|define) [^\n]*)+$','',ob)
    _,od,opost=split(ob); _,nd,npost=split(nb)
    mm_=re.search(r'/\* '+re.escape(fn)+r' @',new); pre_=new[:mm_.start()].split('\n')
    dm={}
    for l_ in reversed(pre_[:-1]):
        q=re.match(r'#define (\w+_IDX) (\d+)$',l_)
        if not q: break
        dm[q.group(1)]=int(q.group(2))
    npost=re.sub(r'\[(\w+_IDX)(?: \+ (\d+))?\]',lambda m_:'[%d]'%(dm[m_.group(1)]+int(m_.group(2) or 0)),npost)
    x=npost
    for r in reversed(rs): x=inv(x,r)
    for k_,v_ in EXTRA.get(fn,{}).items(): x=x.replace(k_,v_)
    # p-kind members spanning several words: A[w+k] -> old[k]
    for r in rs:
        for old_,w_,k_ in r.get('members',[]):
            if k_=='p' and w_:
                m_=re.search(r'\b'+re.escape(old_)+r' \[(\d+)\];',od)
                if m_:
                    for kk in range(int(m_.group(1))): x=x.replace(f"{r['arr']}[{w_+kk}]",f'{old_}[{kk}]')
    a=norm(opost).split('\n'); b=norm(x).split('\n')
    d=[l for l in difflib.unified_diff(a,b,lineterm='',n=0) if not l.startswith(('---','+++','@@'))]
    res[(rel.split('/')[1][:3],fn)]=(len(rs),d)
ok=0
for k,(n,d) in res.items():
    print(('PASS' if not d else ('INTENDED' if k[1] in INTENDED else 'DIFF')),k,'recs=%d'%n, '' if not d else '(%d diff lines)'%len(d)); ok+=not d
    for l in d[:8]: print('     ',l[:200])
print(ok,'/',len(res))
