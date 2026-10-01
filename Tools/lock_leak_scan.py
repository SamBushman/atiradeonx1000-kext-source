#!/usr/bin/env python3
# lock_leak_scan.py OTOOL_TV_DUMP - paths from IOLockLock to a return/tail-jump with no IOLockUnlock (issues #98, #99). Heuristic DFS over `otool -arch ppc -tV` output;
# review every hit by hand: jump-table bctr and lock-held-by-design functions are known false positives (see #98).
import re,sys
def load(p):
    fn={}; cur=None
    for l in open(p,errors='replace'):
        m=re.match(r'^(__Z\S+|_\S+):$',l)
        if m: cur=m.group(1); fn[cur]=[]; continue
        if cur and l[:8].strip() and re.match(r'^[0-9a-f]{8}\t',l):
            f=l.rstrip('\n').split('\t'); a=int(f[0],16); fn[cur].append((a,f[1] if len(f)>1 else '',f[2] if len(f)>2 else ''))
    return fn
fn=load(sys.argv[1]); out=[]
for name,ins in fn.items():
    if not ins: continue
    idx={a:i for i,(a,_,_) in enumerate(ins)}
    lo,hi=ins[0][0],ins[-1][0]
    locks=[i for i,(a,op,arg) in enumerate(ins) if 'jbsr' in op and '_IOLockLock' in arg or (op=='bl' and '_IOLockLock' in arg)]
    if not locks: continue
    def isunlock(op,arg): return ('_IOLockUnlock' in arg) and (op in('jbsr','bl','b','bctr') or 'jbsr' in op)
    leaks=set()
    for s in locks:
        seen=set(); stack=[s+1]
        while stack:
            i=stack.pop()
            while 0<=i<len(ins) and i not in seen:
                seen.add(i); a,op,arg=ins[i]
                if isunlock(op,arg): break
                if op=='blr' or op=='blrr': leaks.add(a); break
                if op in('b','b+','b-'):
                    t=re.match(r'0x([0-9a-f]+)',arg)
                    if t and lo<=int(t.group(1),16)<=hi and int(t.group(1),16) in idx: i=idx[int(t.group(1),16)]; continue
                    leaks.add(a); break   # tail jump out of the function with lock held
                if op=='bctr': leaks.add(a); break
                if re.match(r'^b(eq|ne|lt|gt|le|ge|dnz|dz|so|ns|nl|ng)',op) or (op.startswith('b') and op not in('bl','bctrl','blrl') and re.match(r'0x',arg.split(',')[-1].strip() if arg else '')):
                    t=re.search(r'0x([0-9a-f]+)\s*$',arg)
                    if t and int(t.group(1),16) in idx: stack.append(idx[int(t.group(1),16)])
                i+=1
    if leaks: out.append((name,len(locks),sorted(leaks)))
print(len(out),'functions with a lock->return path without an unlock call')
for n,k,l in out: print(' ',n,'locks=%d'%k,'leak-exit-addrs',[hex(x) for x in l][:4])
