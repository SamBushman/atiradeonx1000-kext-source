#!/usr/bin/env python3
"""jumptable_triage.py DUMP_DIR STOCK_DIS - classify every unresolved-jump-table warning of a dump: TABLE = an embedded jump table (lwzx/add/mtctr/bctr
 followed by .long offsets: gs/FixSwitches.java), ? = inside a stub section, OTHER = a tail call through a pointer (equivalent as call + return)."""
import sys,re,glob,bisect
d,dis=sys.argv[1],sys.argv[2]
rows=[]
for l in open(dis):
    m=re.match(r'([0-9a-f]{8})\t(\S+)\t?(.*)',l)
    if m: rows.append((int(m.group(1),16),m.group(2),m.group(3)))
addrs=[r[0] for r in rows]
res={}
for f in glob.glob(d+'/*.txt'):
    t=open(f).read()
    fn=re.search(r'// Function: (.*) @',t).group(1)
    for w in re.findall(r'(?:Jumptable with 0 entries|Could not recover jumptable) at 0x([0-9a-f]+)',t):
        a=int(w,16); i=bisect.bisect_left(addrs,a)
        if i>=len(rows) or rows[i][0]!=a: res[(fn,a)]='?'; continue
        prev=[r[1] for r in rows[max(0,i-8):i]]
        nxt=rows[i+1][1] if i+1<len(rows) else ''
        table = ('lwzx' in prev or 'lwz' in prev) and 'add' in prev and nxt=='.long'
        res[(fn,a)]='TABLE' if table else ('lwzx' in prev and 'add' in prev) and 'TABLE?' or 'OTHER'
from collections import Counter
print(Counter(res.values()))
for (fn,a),k in sorted(res.items(),key=lambda x:x[0][1]):
    if k!='OTHER': print('%s\t%x\t%s'%(k,a,fn))
