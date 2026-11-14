import re,sys
s=open(sys.argv[1]).read().split('\n')
T={};cur=None;F={}
for l in s:
    m=re.match(r'type (\S+) (\S+)( share)?',l)
    if m: cur=m.group(1); T[cur]=[int(m.group(2),0),bool(m.group(3)),[]]; continue
    m=re.match(r'func (\S+)',l)
    if m: cur=None; fn=m.group(1); F[fn]=[]; continue
    m=re.match(r'  ptr (\S+) (\S+)',l)
    if m and cur: T[cur][2].append(m.group(2)); continue
    m=re.match(r'  arg \d+ ptr (\S+)',l)
    if m and not cur: F[fn].append(m.group(1))
def total(fn):
    seen=set(); tot=0
    def walk(t):
        nonlocal tot
        if t not in T: return
        sz,sh,ch=T[t]
        if sh and t in seen: return
        seen.add(t); tot+=(sz+15)&~15
        for c in ch: walk(c)
    for a in F[fn]: walk(a)
    return tot
for fn in sys.argv[2:]: print(fn, hex(total(fn)))
