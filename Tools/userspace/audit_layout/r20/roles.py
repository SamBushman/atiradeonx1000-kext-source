import json,re,sys,os,subprocess,collections
sys.path.insert(0,'.')
DRY='--dry' in sys.argv; sys.argv=[sys.argv[0]]
exec(open('inv.py').read().split("res={}")[0])
dry=DRY
stats=collections.Counter(); files={}
def span_of(od,old):
    m=re.search(r'\b'+re.escape(old)+r' \[(\d+)\];',od); return int(m.group(1)) if m else 1
for (p,fn),rs in G.items():
    rel=os.path.relpath(p,R)
    old=subprocess.check_output(['git','show',f'{BASE}:{rel}'],cwd=R).decode()
    _,od,_=split(fnbody(old,fn))
    t=files.setdefault(p,open(p).read())
    m=re.search(r'/\* '+re.escape(fn)+r' @[^\n]*\n',t); e=t.find('\n/* ',m.end()); e=len(t) if e<0 else e
    blk=t[m.start():e]; pre,decl,post=split(blk)
    defs=[]
    for r in rs:
        if 'members' not in r: continue          # struct recs keep field names already
        a=r['arr']; w2m={}
        for o,w,k in r['members']:
            if k=='b' or o in (r.get('head') or ''): pass
            n=1 if k in('v','b') else span_of(od,o)
            if k=='p' and w==0: continue          # the array itself
            for kk in range(n): w2m[w+kk]=(o,kk)
            defs.append((o+'_IDX',w))
        def rep(mm):
            w=int(mm.group(1))
            if w in w2m:
                o,kk=w2m[w]; return f'{a}[{o}_IDX'+(f' + {kk}' if kk else '')+']'
            return mm.group(0)
        post=re.sub(r'(?<![\w])'+re.escape(a)+r'\[(\d+)\]',rep,post)
    if not defs: continue
    seen=set(); dl=[]
    for n_,w in defs:
        if n_ in seen: continue
        seen.add(n_); dl.append(f'#define {n_} {w}')
    ul=[f'#undef {n_}' for n_,_ in [(d.split()[1],0) for d in dl]]
    nb='\n'.join(dl)+'\n'+pre+decl+post+'\n'+'\n'.join(ul)
    # keep trailing structure: blk had no trailing newline before next comment
    files[p]=t[:m.start()]+nb+t[e:]
    stats['fn']+=1; stats['defs']+=len(dl)
print(dict(stats))
if not dry:
    for p,t in files.items(): open(p,'w').write(t)
