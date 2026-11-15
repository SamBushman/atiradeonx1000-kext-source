import re,sys,collections
def load(f):
    d=collections.defaultdict(dict)
    for l in open(f,errors='replace'):
        m=re.match(r'(DT|AT) (\S+)\s+trial (\d+) mode (\d+)( RUNINIT)?: stock st=(-?\d+) r3=(\w+)(?: f1=\w+)? dg=(\w+) \| rebuilt st=(-?\d+) r3=(\w+)(?: f1=\w+)? dg=(\w+) \| args (.*)',l)
        if m:
            d[m.group(2)][int(m.group(3))]=(m.group(1),l.strip())
    return d
R=load('diag46_real.full');S=load('diag46_self.full')
for n in R:
    rd={t for t,(k,_) in R[n].items() if k=='DT'}
    sd={t for t,(k,_) in S[n].items() if k=='DT'}
    print(f"{n:50s} real {sorted(rd)} self {sorted(sd)} real-only {sorted(rd-sd)} self-only {sorted(sd-rd)}")
