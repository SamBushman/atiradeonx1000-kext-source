import json, collections
T=json.load(open('tables.json'))
tr=T['_yytranslate']; r1=T['_yyr1']; r2=T['_yyr2']; dfa=T['_yydefact']; dgo=T['_yydefgoto']; pact=T['_yypact']; pgo=T['_yypgoto']; tab=T['_yytable']; chk=T['_yycheck'][:len(tab)]
NINF=-0x8000
YYLAST=len(tab)-1
NT0=min(r1[1:])           # YYNTOKENS
ntok=NT0
nstates=len(dfa)
def action(s,t):
    n=pact[s]
    if n==NINF: return ('r',dfa[s])
    i=n+t
    if 0<=i<=YYLAST and chk[i]==t:
        a=tab[i]
        if a>0: return ('s',a)
        if a<0: return ('r',-a)
        return ('e',0)
    return ('r',dfa[s])
def goto(s,A):
    i=pgo[A-NT0]+s
    if 0<=i<=YYLAST and chk[i]==s: return tab[i]
    return dgo[A-NT0]
edges={}  # (s,sym)->s2 ; symbols: tokens <NT0 internal symbol numbers, NT >=NT0
acc={}
redu=collections.defaultdict(set)
for s in range(nstates):
    for t in range(NT0):
        a=action(s,t)
        if a[0]=='s': edges[(s,t)]=a[1]; acc[a[1]]=t
        elif a[0]=='r' and a[1]>0: redu[a[1]].add(s)
    # reductions via default only for those states that have any; fine
for A in range(NT0, NT0+len(dgo)):
    for s in range(nstates):
        s2=goto(s,A)
        i=pgo[A-NT0]+s
        explicit=(0<=i<=YYLAST and chk[i]==s)
        if explicit or True:
            pass
# goto edges only valid where A is expected: restrict to states that actually have closure with A: approximate by explicit entries + default used by states whose accessing path... keep explicit ones plus default marked
gedges={}
for A in range(NT0, NT0+len(dgo)):
    for s in range(nstates):
        i=pgo[A-NT0]+s
        if 0<=i<=YYLAST and chk[i]==s:
            gedges[(s,A)]=tab[i]
            acc.setdefault(tab[i],A)
        # default goto target: used when no explicit entry
    acc.setdefault(dgo[A-NT0],A)
json.dump({'NT0':NT0,'nstates':nstates,'last':YYLAST},open('meta.json','w'))
print('NTOKENS',NT0,'NNTS',len(dgo),'RULES',len(r1),'STATES',nstates)
print('acc conflicts?')
# accessing symbol consistency
accs=collections.defaultdict(set)
for (s,t),s2 in edges.items(): accs[s2].add(t)
for (s,A),s2 in gedges.items(): accs[s2].add(A)
for A in range(NT0,NT0+len(dgo)): accs[dgo[A-NT0]].add(A)
bad=[(s,v) for s,v in accs.items() if len(v)>1]
print('states with >1 accessing symbol',len(bad), bad[:5])

# reverse edges
rev=collections.defaultdict(list)   # s2 -> [(s,sym)]
for (s,t),s2 in edges.items(): rev[s2].append((s,t))
for (s,A),s2 in gedges.items(): rev[s2].append((s,A))
# default gotos: any state s that has no explicit goto on A and ... skip (their accessing sym known) -> add edges from every state lacking explicit entry? too many; use acc only for last step
def has_goto(s,A):
    return (s,A) in gedges or True
def rhs_paths(r):
    n=r2[r]; A=r1[r]
    res=collections.Counter()
    for sred in redu[r]:
        def back(s,k,seq):
            if k==0:
                yield seq,s; return
            # incoming edges
            for (p,sym) in rev.get(s,[]):
                yield from back(p,k-1,[sym]+seq)
            # default gotos into s
            if acc.get(s,0)>=NT0 and s in [dgo[a-NT0] for a in range(NT0,NT0+len(dgo))]:
                pass
        if n==0: res[()]+=1; continue
        for seq,org in back(sred,n,[]):
            res[tuple(seq)]+=1
    return res
rules={}
for r in range(1,len(r1)):
    c=rhs_paths(r)
    rules[r]=c
amb=[r for r,c in rules.items() if len(c)!=1]
print('rules with a unique RHS',len(rules)-len(amb),'of',len(rules),'ambiguous',amb[:20])
import pickle; pickle.dump({'rules':{r:dict(c) for r,c in rules.items()},'NT0':NT0,'r1':r1,'r2':r2,'acc':acc,'edges':edges,'gedges':gedges},open('g.pkl','wb'))
