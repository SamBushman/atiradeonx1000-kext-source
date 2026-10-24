import re,glob,collections,sys
D='Userspace/ATIRadeonX1000GLDriver/ppc/'
H=re.compile(r'^/\* (\S+) @ 0x([0-9a-f]+)')
SIG=re.compile(r'^(?:[A-Za-z_][\w \*]*?)\b([A-Za-z_]\w*)\(([^)]*)\)\s*$')
funcs={}   # name -> (part, start, end, params list)
texts={}
for f in sorted(glob.glob(D+'part_*.c')):
    L=open(f,errors='replace').read().split('\n'); texts[f]=L
    cur=None
    for i,l in enumerate(L):
        m=H.match(l)
        if m:
            if cur: funcs[cur[0]]=(f,cur[1],i,cur[2])
            nm=m.group(1); sig=L[i+1] if i+1<len(L) else ''
            ps=[]
            ms=re.match(r'^.*?\b%s\((.*)\)\s*$'%re.escape(nm),sig)
            if ms: ps=[p.strip() for p in ms.group(1).split(',') if p.strip()]
            cur=(nm,i,ps)
    if cur: funcs[cur[0]]=(f,cur[1],len(L),cur[2])
PH=re.compile(r'^(param_\d+|in_\w+|extraout_\w+|\w*Var\d+|local_\w+|this_\d+)$')
def callargs(s,pos):
    # parse balanced args from s starting after '(' at pos
    depth=1;args=[];cur='';i=pos
    while i<len(s):
        c=s[i]
        if c in '([': depth+=1; cur+=c
        elif c in ')]':
            depth-=1
            if depth==0: args.append(cur.strip()); return args
            cur+=c
        elif c==',' and depth==1: args.append(cur.strip()); cur=''
        else: cur+=c
        i+=1
    return None
props=collections.defaultdict(collections.Counter)   # (fn,param)->Counter(name)
CALL=re.compile(r'\b([A-Za-z_]\w*)\)?\(')
for fn,(f,s,e,ps) in funcs.items():
    pset=set(p for p in ps if re.match(r'param_\d+$',p))
    if not pset: continue
    for l in texts[f][s+1:e]:
        for m in re.finditer(r'(?:\(\([^)]*\)\s*)?\b([A-Za-z_]\w*)\)?\(',l):
            callee=m.group(1)
            if callee not in funcs or callee==fn: continue
            args=callargs(l,m.end())
            if not args: continue
            cps=funcs[callee][3]
            for k,a in enumerate(args):
                a=re.sub(r'^\((?:[^()]*\*+|[^()]*)\)\s*','',a).strip()
                if a in pset and k<len(cps) and not PH.match(cps[k]) :
                    props[(fn,a)][cps[k]]+=1
out=[]
for (fn,p),c in props.items():
    name,n=c.most_common(1)[0]
    out.append((fn,p,name,n,sum(c.values()),dict(c)))
print(len(out),'proposals;',len(set(o[0] for o in out)),'funcs')
agree=[o for o in out if o[3]==o[4]]
print('unanimous',len(agree))
for o in sorted(out,key=lambda o:-o[3])[:25]: print(o)

owner={}
for fn,(f,st,en,ps) in funcs.items():
    m=re.search(r'part_(\d+)\.c',f)
    owner[fn]=int(m.group(1))
lo,hi=int(sys.argv[2]),int(sys.argv[3])
rows=[]
for fn,p,name,n,tot,c in out:
    if not(lo<=owner[fn]<=hi): continue
    if not re.match(r'^[A-Za-z_]\w*$',name) or name in('int','void','uint','char','undefined4','undefined','float'): continue
    if n!=tot: continue
    rows.append('local\t%s\t%s\t%s\tINFERRED\tevery call of a named callee that receives %s passes it as the parameter that callee names %s (%d call sites)'%(fn,p,name,p,name,n))
open(sys.argv[1],'w').write('\n'.join(rows)+('\n' if rows else ''))
print('rows',len(rows))

