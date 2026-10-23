#!/usr/bin/env python3
"""fixspec.py DIR FN SPEC > SPEC2 : expand spec rows so that one new name never spans webs that the HEAD text keeps as different variables (would be a MERGE for the gate).
HEAD group of a web = the identifier among {V} + {HEAD new names of V's rows} found on the web's HEAD lines (first one found per line); webs with different groups get a suffix."""
import sys,os,re,glob,subprocess
sys.path.insert(0,os.path.join(os.path.dirname(os.path.abspath(__file__)),'..'))
import find_webs as F
from collections import Counter
d,fn,spec=sys.argv[1:4]
body,brace=F.load(d,fn); nodes,entry=F.build_cfg(body,brace)
HDR=re.compile(r'^/\* (\S+) @ 0x')
part=next(pf for pf in sorted(glob.glob(os.path.join(d,'part_*.c'))) if any(HDR.match(l) and HDR.match(l).group(1)==fn for l in open(pf,errors='replace')))
head=subprocess.run(['git','show','HEAD:'+part],capture_output=True,text=True,errors='replace').stdout.split('\n')
s=next(i for i,l in enumerate(head) if HDR.match(l) and HDR.match(l).group(1)==fn)
e=next((i for i in range(s+1,len(head)) if HDR.match(head[i])),len(head)); hb=head[s:e]
DECL=re.compile(r'^  [\w ]+?[ *]+[A-Za-z_]\w*( ?\[\w+\])?;$')
hbrace=next(i for i,l in enumerate(hb) if l=='{')
hs=[i for i,l in enumerate(hb) if i>hbrace and not DECL.match(l)]; cs=[i for i,l in enumerate(body) if i>brace and not DECL.match(l)]
pos=dict(zip(cs,hs))
# HEAD names per var
hn={}
tabs=subprocess.run(['git','ls-tree','--name-only','HEAD',d.rstrip('/')+'/'],capture_output=True,text=True).stdout.split()
for n in tabs:
    if os.path.basename(n).startswith('names') and n.endswith('.tsv'):
        for l in subprocess.run(['git','show','HEAD:'+n],capture_output=True,text=True,errors='replace').stdout.split('\n'):
            c=l.split('\t')
            if len(c)>=6 and c[0] in('local','use') and c[1]==fn: hn.setdefault(c[2],set()).add(c[3])
cache={}
def group_of(var,w,idx=0):
    ids=[var]+sorted(hn.get(var,()))
    cnt=Counter()
    for l in sorted(w):
        h=pos.get(l)
        if h is None: continue
        for t in ids:
            if re.search(r'\b%s\b'%re.escape(t),hb[h]): cnt[t]+=1; break
    return cnt.most_common(1)[0][0] if cnt else '?w%d'%idx
for line in open(spec):
    if not line.strip() or line.startswith('#'): print(line,end=''); continue
    r=line.rstrip('\n').split('\t'); var,wl,new=r[0],r[1],r[2]
    if var not in cache: cache[var]=F.webs(nodes,entry,var)[0]
    ws=cache[var]
    idx=list(range(len(ws))) if wl=='*' else [int(re.match(r'\d+',w).group(0)) for w in wl.split(',')]
    if wl!='*' and any(not re.fullmatch(r'\d+',w) for w in wl.split(',')): print(line,end=''); continue
    if wl=='*' and len(ws)==1: print(line,end=''); continue
    groups={}
    for i in idx: groups.setdefault(group_of(var,ws[i],i),[]).append(i)
    if len(groups)==1 and wl!='*': print(line,end=''); continue
    if len(groups)==1: print(line,end=''); continue
    letters='ABCDEFGH'
    for k,(g,l) in enumerate(sorted(groups.items(),key=lambda kv:kv[1][0])):
        nm=new if k==0 else new+letters[k]
        print('\t'.join([var,','.join(map(str,l)),nm]+r[3:]))
