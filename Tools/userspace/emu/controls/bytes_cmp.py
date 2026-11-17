import sys,re,ast
# compare per-byte final memory writes of the two event streams printed by evall_gl_i301.py
lines=open(sys.argv[1]).read().split('\n')
secs=[];cur=None
for l in lines:
    if re.match(r'^(stock|rebuilt)\b',l) and ('events' in l or 'rc' in l and False): pass
    m=re.match(r'^\s+\d+ \(\'(W)\', (\d+), (\d+), (\d+)\)',l)
    if re.match(r'^[SR] (RET|FAULT|TIMEOUT|EMUERR)',l): secs.append({});continue
    if m and secs:
        a,sz,v=int(m.group(2)),int(m.group(3)),int(m.group(4))
        for i in range(sz): secs[-1][a+i]=(v>>(8*(sz-1-i)))&255
print(len(secs),[len(s) for s in secs])
if len(secs)>=2:
    S,R=secs[0],secs[1]
    diff=[a for a in set(S)|set(R) if S.get(a)!=R.get(a)]
    print('bytes differing (written by one side only or different value):',len(diff),sorted(diff)[:10])
