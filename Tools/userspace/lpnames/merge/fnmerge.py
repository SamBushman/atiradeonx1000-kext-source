# fnmerge.py BRANCH [--apply]: function-level 3-way merge of GLDriver parts. Normalizes func renames (union map) first.
import re,subprocess,sys,json,collections
D='Userspace/ATIRadeonX1000GLDriver/ppc/'
br=sys.argv[1]; apply='--apply' in sys.argv
B=subprocess.run(['git','merge-base','HEAD',br],capture_output=True,text=True).stdout.strip()
H=re.compile(r'^/\* (\S+) @ (0x[0-9a-f]+) \(',re.M)
def show(rev,p): return subprocess.run(['git','show',f'{rev}:{p}'],capture_output=True,text=True,errors='surrogateescape').stdout
def split(t):
    ms=list(H.finditer(t)); out=collections.OrderedDict(); pre=t[:ms[0].start()] if ms else t
    for i,m in enumerate(ms):
        e=ms[i+1].start() if i+1<len(ms) else len(t)
        out[m.group(2)]=(m.group(1),t[m.start():e])
    return pre,out
# union rename map
amap={}
def names(rev):
    r={}
    for i in range(68):
        for n,a in H.findall(show(rev,f'{D}part_{i:03d}.c')): r[a]=n
    return r
nb,no,nt=names(B),names('HEAD'),names(br)
u={}
for a in nb:
    if a in no and no[a]!=nb[a]: u[nb[a]]=no[a]
    if a in nt and nt[a]!=nb[a]: u[nb[a]]=nt[a]
R=re.compile(r'\b('+'|'.join(map(re.escape,sorted(u,key=len,reverse=True)))+r')\b') if u else None
norm=lambda t: R.sub(lambda x:u[x.group(1)],t) if R else t
conf=[];result={}
for i in range(68):
    p=f'{D}part_{i:03d}.c'
    tb,to,tt=[norm(show(r,p)) for r in (B,'HEAD',br)]
    if to==tt: result[p]=to; continue
    if tb==to: result[p]=tt; continue
    if tb==tt: result[p]=to; continue
    pb,fb=split(tb);po,fo=split(to);pt,ft=split(tt)
    assert list(fo)==list(ft)==list(fb),p
    out=[po if po!=pb else pt]
    for a in fo:
        b,o,t=fb[a][1],fo[a][1],ft[a][1]
        if o==t or t==b: out.append(o)
        elif o==b: out.append(t)
        else:
            PH=re.compile(r'\b(?:extraout_\w+|\w*Stack_[0-9a-f]+|fparam_\w+|in_stack_\w+|[A-Za-z]{0,4}Var\d+|p+_?[A-Za-z]*Var\d+|local_[0-9a-f]+|param_\d+|in_[a-z]+\d*)\b')
            co,ct=len(PH.findall(o)),len(PH.findall(t))
            side='theirs' if ct<co else 'ours'
            conf.append((p,a,fo[a][0],side,co,ct)); out.append(t if side=='theirs' else o)
    result[p]=''.join(out)
print('conflicting functions:',len(conf)); 
for c in conf: print(c)
json.dump([[c[2],c[3],nb.get(c[1]),no.get(c[1]),nt.get(c[1]),'FUN_%08x'%int(c[1],16)] for c in conf],open('/home/sam/g5logs/conf_%s.json'%br,'w'))
if apply:
    for p,t in result.items(): open(p,'w',encoding='utf-8',errors='surrogateescape').write(t)
