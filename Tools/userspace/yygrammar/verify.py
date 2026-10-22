import pickle,json,collections
exec(open('gl.py').read().replace('print(len(TOK))',''))
exec(open('rules.py').read())
G2=[]
for l,rhs in G:
    for x in rhs:
        if x.startswith('@'): G2.append((x,[]))
    G2.append((l,rhs))
G=G2
T=json.load(open('tables.json')); r1=T['_yyr1']; r2=T['_yyr2']
exec(open('grammar.py').read().split('edges={}')[0].replace("print(","(lambda *a:None)("))
d=pickle.load(open('g.pkl','rb')); acc=d['acc']; edges=d['edges']; gedges=d['gedges']
# nonterminal order = first LHS appearance (bison numbers by first appearance incl. %type; check against yyr1)
nts=[]
for l,_ in G:
    if l not in nts: nts.append(l)
mid=[]  # mid-rule action nonterminals appear in yyr1 as their own numbers
# map names -> numbers using yyr1
nt_num={}
for i,(l,rhs) in enumerate(G,1):
    nt_num.setdefault(l, r1[i])
for i,(l,rhs) in enumerate(G,1):
    for x in rhs:
        if x.startswith('@'): pass
print('rules',len(G),'expected 215')
bad=[i for i,(l,rhs) in enumerate(G,1) if len(rhs)!=r2[i]]
print('len mismatches',bad)
nt_num={}
bad=[]
for i,(l,rhs) in enumerate(G,1):
    if nt_num.setdefault(l,r1[i])!=r1[i]: bad.append(('lhs-inconsistent',i,l))
if len(set(nt_num.values()))!=len(nt_num): bad.append('dup nt numbers')
print('lhs consistency problems',bad)
def sym(x):
    return nt_num[x] if x in nt_num else TOK.index(x)
redu=collections.defaultdict(set)
for s_ in range(nstates):
    for t_ in range(NT0):
        a_=action(s_,t_)
        if a_[0]=='r' and a_[1]>0: redu[a_[1]].add(s_)
# automaton verification
rev=collections.defaultdict(list)
for (s,t),s2 in edges.items(): rev[s2].append((s,t))
for (s,A),s2 in gedges.items(): rev[s2].append((s,A))
ok=part=fail=0; fails=[]
for i,(l,rhs) in enumerate(G,1):
    seq=[sym(x) for x in rhs]
    if not seq: ok+=1; continue
    good=False; deep=False
    for sred in redu[i]:
        if acc.get(sred)!=seq[-1]: continue
        # walk back through explicit predecessors where possible
        def walk(s,k):
            if k<0: return True
            preds=rev.get(s,[])
            if not preds: return None   # default goto: unknown
            for p,sy in preds:
                if sy==seq[k]:
                    r=walk(p,k-1) if k>0 else True
                    if r: return True
                    if r is None: return None
            return False
        r=walk(sred,len(seq)-1)
        if r: good=True; deep=True
        elif r is None: good=True
    if good and deep: ok+=1
    elif good: part+=1
    else: fail+=1; fails.append(i)
print('RHS verified by automaton: full path',ok,'last-symbol only (default goto)',part,'FAIL',fail,fails[:20])
