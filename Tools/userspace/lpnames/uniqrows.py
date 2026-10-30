#!/usr/bin/env python3
"""uniqrows.py ROWS.tsv OUT.tsv [--exclude TABLE] : make the new names of local/use rows unique per function against names other tables already give to OTHER variables, and across my own variables"""
import sys,glob,os,re,collections
D='Userspace/ATIRadeonX1000GLDriver/ppc'
rows=[l.rstrip('\n').split('\t') for l in open(sys.argv[1]) if l.strip()]
mine=os.path.abspath(sys.argv[1])
ex=collections.defaultdict(lambda: collections.defaultdict(set))   # fn -> name -> vars
for t in glob.glob(D+'/names*.tsv'):
    if os.path.abspath(t)==mine: continue
    for l in open(t,errors='surrogateescape'):
        c=l.rstrip('\n').split('\t')
        if len(c)>3 and c[0] in('local','use'): ex[c[1]][c[3]].add(c[2])
# identifiers in text per function (cheap): all words
H=re.compile(r'^/\* (\S+) @ 0x')
ids=collections.defaultdict(set)
fnmap={}
for t in glob.glob(D+'/names*.tsv'):
    for l in open(t,errors='surrogateescape'):
        c=l.rstrip('\n').split('\t')
        if len(c)>3 and c[0]=='func': fnmap[c[1]]=c[2]
want=set(r[1] for r in rows if len(r)>3 and r[0] in('local','use'))
curname={g:fnmap.get(g,g) for g in want}
rev={v:k for k,v in curname.items()}
for p in glob.glob(D+'/part_*.c'):
    cur=None
    for l in open(p,errors='replace'):
        m=H.match(l)
        if m: cur=rev.get(m.group(1)); continue
        if cur: ids[cur].update(re.findall(r'[A-Za-z_]\w*',l))
assign={}   # (fn,var,new)->final
used=collections.defaultdict(lambda: collections.defaultdict(set))  # fn->final->vars
out=[]
for c in rows:
    if len(c)>3 and c[0] in('local','use'):
        fn,var,new=c[1],c[2],c[3]
        k=(fn,var,new)
        if k not in assign:
            cand=new;i=0
            def bad(n):
                if used[fn][n]-{var}: return True
                if ex[fn].get(n) and ex[fn][n]-{var}: return True
                if n in ids[fn] and not (ex[fn].get(n) and var in ex[fn][n]) and not re.match(r'^(param|[a-z]*Var)',n): 
                    return not (var in used[fn][n])
                return False
            while bad(cand):
                i+=1; cand=new+('B','C','D','E','F','G','H')[i-1] if i<=7 else new+str(i)
            assign[k]=cand; used[fn][cand].add(var)
        c[3]=assign[k]
    out.append('\t'.join(c))
open(sys.argv[2],'w').write('\n'.join(out)+'\n')
print(sum(1 for k,v in assign.items() if k[2]!=v),'renamed of',len(assign))
