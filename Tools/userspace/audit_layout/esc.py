import re,sys,os,glob
# esc.py binary part func : escaped frame addresses (addi rX,r30,N / la) with the next call and arg position, base vs cand
b,p,f=sys.argv[1:4]
d=[x for x in glob.glob(os.path.expanduser('~/g5logs/tmp_r18/vn_*')) if ('_'+b+'_ppc_a18_') in x and 'a18b' not in x][0]
def get(w):
    on=False;out=[];lines=[]
    for l in open(f'{d}/{w}.{p}.dis',errors='replace'):
        s=l.rstrip()
        if s==f+':': on=True;continue
        if on and re.match(r'^_[A-Za-z0-9_$.]*:$',s): break
        if on: lines.append(s)
    # track reg -> offset
    res=[]
    reg={}
    for i,s in enumerate(lines):
        m=re.match(r'\s+addi\s+r(\d+),r30,(-?\d+)',s) or re.match(r'\s+la\s+r(\d+),(-?\d+)\(r30\)',s)
        if m: reg[int(m.group(1))]=int(m.group(2));continue
        m=re.match(r'\s+mr\s+r(\d+),r(\d+)',s)
        if m and int(m.group(2)) in reg:
            reg[int(m.group(1))]=reg[int(m.group(2))]
            if int(m.group(1)) not in (0,2,12) : res.append((reg[int(m.group(2))],'arg r'+m.group(1)))
            continue
        m=re.match(r'\s+(?:bl|bctrl|b)\s*(\S*)',s)
        if m and (s.strip().startswith('bl') ):
            res.append((None,'CALL '+m.group(1)))
            for r in list(reg):
                if r in (3,4,5,6,7,8,9,10): pass
        m=re.match(r'\s+(?:lwz|lbz|lhz|stw|stb|sth|lfs|stfs|lfd)\s+r\d+,(-?\d+)\(r(\d+)\)',s)
    return res
for w in ('base','cand'):
    print(w,[(o,a) for o,a in get(w) if o is not None or a.startswith('CALL')][:80])
