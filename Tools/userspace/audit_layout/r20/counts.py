import re,subprocess,sys,os
sys.argv=[sys.argv[0]]
exec(open('inv.py').read().split("res={}")[0])
PH=re.compile(r'\b(local_[0-9a-f]+|[a-z]{1,3}Var\d+|[a-z]?[a-z]?Stack_[0-9a-f]+|param_\d+|in_\w+|extraout_\w+|FUN_[0-9a-f]+|DAT_[0-9a-f]+|PTR_\w+|LAB_\w+|[a-z]+Var[A-Z]\d+|[a-z]?[a-z]?Var\d+S?\d*)\b')
DECL=re.compile(r'^\s+(?!return\b)[\w ]+?[ *]+([A-Za-z_]\w*)( ?\[\w+\])?;$')
rows=[];tb=ta=nb_=na=0;rd=0
for (p,fn),rs in G.items():
    rel=os.path.relpath(p,R)
    old=subprocess.check_output(['git','show',f'{BASE}:{rel}'],cwd=R).decode(); new=open(p).read()
    ob=fnbody(old,fn); nbk=re.sub(r'(\n#(?:undef|define) [^\n]*)+$','',fnbody(new,fn))
    def cnt(b):
        _,d,post=split(b); names=[DECL.match(l).group(1) for l in d.split('\n') if DECL.match(l)]
        return len(PH.findall(b)), len([n for n in names if not PH.fullmatch(n)]), len(names)
    ph0,nm0,dl0=cnt(ob); ph1,nm1,dl1=cnt(nbk)
    # role names: member names now carried by *_IDX constants
    roles=sum(len(re.findall(r'^#define '+'', '')) for _ in [0])
    mem=sum(len(r['members']) for r in rs if 'members' in r)+sum(len(r['struct']) for r in rs if 'struct' in r)
    rows.append((fn,ph0,ph1,nm0,nm1,mem))
    tb+=ph0;ta+=ph1;nb_+=nm0;na+=nm1
print('function | placeholders before->after | named decls before->after | members folded into arrays/structs')
for r in rows: print('%s | %d -> %d | %d -> %d | %d'%r)
print('TOTAL placeholders %d -> %d ; named decls %d -> %d'%(tb,ta,nb_,na))
