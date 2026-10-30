# rowfix.py BRANCH : for conflicting functions replace merged TSV rows by the chosen side's rows (HEAD = ours, BRANCH = theirs)
import json,sys,subprocess,glob,os
br=sys.argv[1]; D='Userspace/ATIRadeonX1000GLDriver/ppc/'
conf=json.load(open('/home/sam/g5logs/conf_%s.json'%br))
def show(rev,p): return subprocess.run(['git','show',f'{rev}:{p}'],capture_output=True,text=True,errors='surrogateescape').stdout.split('\n')
side={}
for cur,sd,b,o,t,fn in conf:
    for n in (cur,b,o,t,fn):
        if n: side[n]=sd
rev=lambda sd:'HEAD' if sd=='ours' else br
isrow=lambda l:(l.split('\t')+['',''])[1] in side and l.split('\t')[0] in ('local','use')
tot=0
for f in sorted(glob.glob(D+'names*.tsv')):
    merged=open(f,encoding='utf-8',errors='surrogateescape').read().split('\n')
    if not any(isrow(l) for l in merged) : 
        # maybe chosen side has rows that merge dropped
        pass
    keep={}
    for sd in ('ours','theirs'):
        keep[sd]=[l for l in show(rev(sd),f) if isrow(l) and side[l.split('\t')[1]]==sd]
    out=[];changed=False;done=False
    add=keep['ours']+keep['theirs']
    for l in merged:
        if isrow(l):
            changed=True
            if not done: out+=add; done=True
            continue
        out.append(l)
    if add and not done:
        if out and out[-1]=='': out=out[:-1]+add+['']
        else: out+=add
        changed=True
    if changed:
        open(f,'w',encoding='utf-8',errors='surrogateescape').write('\n'.join(out)); tot+=len(add)
print('rows reinserted',tot)
