import sys,collections,re,glob
D=sys.argv[1]; mine=sys.argv[2]
owner=collections.defaultdict(set)   # (fn_root,name)->vars
def rows(f):
    return [l.split('\t') for l in open(f,errors='surrogateescape').read().split('\n')]
funcs={}
for f in glob.glob(D+'/names*.tsv'):
    for c in rows(f):
        if len(c)>=4 and c[0]=='func': funcs[c[2]]=c[1]; funcs.setdefault(c[1],c[1])
root=lambda n: funcs.get(n,n)
for f in glob.glob(D+'/names*.tsv'):
    if f==mine: continue
    for c in rows(f):
        if len(c)>=6 and c[0] in('use','local'): owner[(root(c[1]),c[3])].add(c[2])
L=open(mine,errors='surrogateescape').read().split('\n')
ch=0
for i,l in enumerate(L):
    c=l.split('\t')
    if len(c)>=6 and c[0] in('use','local'):
        k=(root(c[1]),c[3])
        if owner[k] and c[2] not in owner[k]:
            suf=re.sub(r'\D','',c[2]) or c[2]
            nn=c[3]+suf
            while (root(c[1]),nn) in owner and c[2] not in owner[(root(c[1]),nn)]: nn+='x'
            c[3]=nn; L[i]='\t'.join(c); ch+=1; k=(root(c[1]),nn)
        owner[k].add(c[2])
open(mine,'w',errors='surrogateescape').write('\n'.join(L)); print('renamed',ch)
