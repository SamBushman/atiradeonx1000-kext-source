import re,collections,statistics,sys
d=collections.defaultdict(list)
for l in open(sys.argv[1]):
    m=re.match(r'(\S+) (\d+) (clear\+flush|draw100\+flush) #(\d) median (\d+)',l)
    if m: d[(m.group(3)+'#'+m.group(4),m.group(1))].append(int(m.group(5)))
vs=sys.argv[2:]
for k in sorted({k[0] for k in d}):
    s=statistics.median(d[(k,'stock')])
    print('%-18s'%k,' '.join('%s %.0f (%+.1f%%, n=%d, sd %.1f)'%(v,statistics.median(d[(k,v)]),100*(statistics.median(d[(k,v)])/s-1),len(d[(k,v)]),statistics.pstdev(d[(k,v)])) for v in vs))
