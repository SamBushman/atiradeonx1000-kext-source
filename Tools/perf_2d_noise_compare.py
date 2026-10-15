import re,glob,sys,os,statistics as st,random
d=sys.argv[1]; rep=sys.argv[2]
names=[l.split('|')[1].strip() for l in open(rep) if '| INCONCLUSIVE |' in l]
M=re.compile(r'METRIC (\S+) .*median=([-0-9.e+]+)')
def runs(tag):
    out={}
    for f in glob.glob(os.path.join(d,tag+'_v*_r*.txt')):
        m={}
        for l in open(f):
            r=M.match(l)
            if r:m[r.group(1)]=float(r.group(2))
        raw=f[:-4]+'.raw'
        if os.path.exists(raw):
            ser={}
            for l in open(raw):
                p=l.split()
                if len(p)==6: ser.setdefault(p[0],[]).append([float(x) for x in p[2:]])
            idle=ser.get('idle')
            for sc,rows in ser.items():
                for k,n in enumerate('abcd'):
                    col=[r[k] for r in rows]
                    m[f'{sc}.{n}.sum']=sum(col);m[f'{sc}.{n}.peak']=max(col);m[f'{sc}.{n}.tail']=st.median(col[len(col)//2:])
                    if idle:
                        thr=st.median([r[k] for r in idle[len(idle)//2:]])*1.5
                        if thr>0:m[f'{sc}.{n}.active']=float(sum(1 for x in col if x>thr))
        if m:out[f]=m
    return list(out.values())
S,R=runs('stock'),runs('rebuilt')
def spread(xs):
    xs=sorted(xs);n=len(xs);c=st.median(xs)
    q=lambda p:xs[min(n-1,int(p*(n-1)+.5))]
    return (q(.75)-q(.25))/abs(c) if c else float('nan'), st.pstdev(xs)/abs(c) if c else float('nan')
rng=random.Random(1)
print('| metric | n stock/rebuilt | stock IQR/med | rebuilt IQR/med | stock CV | rebuilt CV | rebuilt/stock CV (90% CI) |');print('|---|---|---:|---:|---:|---:|---|')
ratios=[]
for n in names:
    a=[m[n] for m in S if n in m];b=[m[n] for m in R if n in m]
    if len(a)<5 or len(b)<5: print(f'| {n} | {len(a)}/{len(b)} | - | - | - | - | - |');continue
    ia,ca=spread(a);ib,cb=spread(b)
    bs=[]
    for _ in range(2000):
        x=[rng.choice(a) for _ in a];y=[rng.choice(b) for _ in b]
        mx,my=st.mean(x),st.mean(y)
        if mx and my and st.pstdev(x)>0: bs.append((st.pstdev(y)/abs(my))/(st.pstdev(x)/abs(mx)))
    bs.sort()
    ci=f'[{bs[int(.05*len(bs))]:.2f}, {bs[int(.95*len(bs))]:.2f}]' if bs else '-'
    r=cb/ca if ca else float('nan'); ratios.append(r)
    print(f'| {n} | {len(a)}/{len(b)} | {ia:.3f} | {ib:.3f} | {ca:.3f} | {cb:.3f} | {r:.2f} {ci} |')
ratios=[r for r in ratios if r==r]
print('\nmedian CV ratio rebuilt/stock over %d metrics: %.2f ; metrics with rebuilt noisier: %d, stock noisier: %d'%(len(ratios),st.median(ratios),sum(r>1 for r in ratios),sum(r<1 for r in ratios)))
