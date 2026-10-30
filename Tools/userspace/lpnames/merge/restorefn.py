# restorefn.py REV PART ADDRHEX FUNNAME : restore one function's text (in PART) and its local/use rows to REV's state
import sys,subprocess,glob,re
rev,part,addr,fn=sys.argv[1:5]
D='Userspace/ATIRadeonX1000GLDriver/ppc/'
show=lambda p:subprocess.run(['git','show',f'{rev}:{p}'],capture_output=True,text=True,errors='surrogateescape').stdout
H=re.compile(r'^/\* (\S+) @ (0x[0-9a-f]+) \(',re.M)
def span(t):
    ms=list(H.finditer(t))
    for i,m in enumerate(ms):
        if m.group(2)==addr: return m.group(1),m.start(),(ms[i+1].start() if i+1<len(ms) else len(t))
p=D+part; cur=open(p,encoding='utf-8',errors='surrogateescape').read(); old=show(p)
a=span(cur); b=span(old)
open(p,'w',encoding='utf-8',errors='surrogateescape').write(cur[:a[1]]+old[b[1]:b[2]]+cur[a[2]:])
names={fn,a[0],b[0]}
isrow=lambda l:(l.split('\t')+['',''])[1] in names and l.split('\t')[0] in ('local','use')
for f in sorted(glob.glob(D+'names*.tsv')):
    m=open(f,encoding='utf-8',errors='surrogateescape').read().split('\n')
    keep=[l for l in show(f).split('\n') if isrow(l)]
    if not keep and not any(isrow(l) for l in m): continue
    out=[];done=False
    for l in m:
        if isrow(l):
            if not done: out+=keep;done=True
            continue
        out.append(l)
    if keep and not done: out=out[:-1]+keep+[''] if out and out[-1]=='' else out+keep
    open(f,'w',encoding='utf-8',errors='surrogateescape').write('\n'.join(out))
print('restored',fn)
