# Classify the PD_RDDIFF "RD" lines of a pipeline_diff.py log: for each one-sided read, require that the overlapping bytes of the other image's reads carry equal values (load-width class). Usage: rd_check.py LOG
import re,sys,ast,collections
rows=collections.defaultdict(lambda:{'stock-only':[], 'rebuilt-only':[]})
for l in open(sys.argv[1]):
    m=re.match(r'\s+RD (\S+) (stock-only|rebuilt-only) \((\d+), (\d+)\) values (\[.*?\]) other image overlapping (\[.*\])$',l.rstrip())
    if not m: continue
    step,side,a,s,v,ov=m.groups(); a=int(a); s=int(s)
    v=ast.literal_eval(v); ov=ast.literal_eval(ov)
    rows[step][side].append((a,s,v,ov))
bad=0;tot=0
def bytesof(val,s,off): return (val>>(8*(s-1-off)))&0xff
for step,d in rows.items():
    for side,other in (('stock-only','rebuilt-only'),('rebuilt-only','stock-only')):
        for a,s,v,ov in d[side]:
            tot+=1
            # byte-wise: for each overlapping other read, compare overlapped bytes, require some value pairing consistent
            ok=True
            for (oa,os_),ovals in ov:
                lo=max(a,oa);hi=min(a+s,oa+os_)
                if lo>=hi: continue
                mine={tuple(bytesof(x,s,i-a) for i in range(lo,hi)) for x in v}
                theirs={tuple(bytesof(x,os_,i-oa) for i in range(lo,hi)) for x in ovals}
                if not (mine & theirs): ok=False;print('MISMATCH',step,side,a,s,v,(oa,os_),ovals)
            if not ok: bad+=1
print('reads checked',tot,'inconsistent',bad)
