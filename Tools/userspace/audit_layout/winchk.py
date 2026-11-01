import re,sys,os,glob
sys.path.insert(0,os.path.expanduser('~/g5logs/tmp_r19'))
import ovl
R=os.path.expanduser('~/g5logs/tmp_r19')
def dis_funcs(path):
    out={};cur=None
    for l in open(path,errors='replace'):
        s=l.rstrip()
        m=re.match(r'^(_[A-Za-z0-9_$.]*):$',s)
        if m: cur=m.group(1);out[cur]=[];continue
        if cur: out[cur].append(s)
    return out
def slots(lines):
    esc=set();acc=set()
    for s in lines:
        m=re.match(r'\s+addi\s+r\d+,r30,(-?\d+)',s) or re.match(r'\s+la\s+r\d+,(-?\d+)\(r30\)',s)
        if m: esc.add(int(m.group(1)));continue
        m=re.match(r'\s+\w+\s+[rf]\d+,(-?\d+)\(r30\)',s)
        if m: acc.add(int(m.group(1)))
    return sorted(esc),sorted(acc)
def stabs(b,part,cname):
    f=f'{R}/stabs_{b}/p{part.split("_")[1]}.s'
    if not os.path.exists(f): return None
    on=False;loc={}
    for l in open(f,errors='replace'):
        m=re.match(r'\s*\.stabs\s+"([^"]*)",(\d+),\d+,\d+,(.*)',l)
        if not m: continue
        nm,ty,val=m.groups()
        if ty=='36': fn=nm.split(':')[0];on=(fn==cname or fn=='_'+cname or fn.lstrip('_')==cname.lstrip('_'));continue
        if on and ty=='128' and ':' in nm:
            try: loc[nm.split(':')[0]]=int(val)
            except: pass
    return loc
def run(b):
    c=ovl.Corpus(os.path.expanduser(f'~/wt/r19/Userspace/{b}/ppc'))
    T=[x for x in glob.glob(os.path.expanduser('~/g5logs/tmp_r18/vn_*')) if ('_'+b+'_ppc_a18_') in x and 'a18b' not in x][0]
    cache={}
    res=[]
    for fn,(params,code,part,addr) in c.F.items():
        if '/' in part: continue
        ov=c.overlays(fn)
        if not ov: continue
        key=part
        if key not in cache:
            try: cache[key]=(dis_funcs(f'{T}/base.{part}.dis'),dis_funcs(f'{T}/cand.{part}.dis'))
            except Exception as e: cache[key]=None
        if cache[key] is None: res.append((fn,'NODIS',part));continue
        B,C=cache[key]
        lab='_FUN_%08x'%addr if ('_FUN_%08x'%addr) in C else ('_'+fn if ('_'+fn) in C else fn)
        if lab not in C or lab not in B: res.append((fn,'NOLABEL',part));continue
        be,ba=slots(B[lab]);ce,ca=slots(C[lab])
        loc=stabs(b,part,fn)
        if loc is None: res.append((fn,'NOSTABS',part));continue
        for (nm,sz,E,why) in ov:
            if nm not in loc: res.append((fn,'NOLOC '+nm,part));continue
            co=loc[nm]
            if co not in ce and not any(abs(co-x)<sz for x in ce) and why.startswith('subscript') is False:
                pass
            # rank among cand escaped addresses
            if co in ce: k=ce.index(co)
            else:
                res.append((fn,f'NOTESC {nm}@{co} ({why})',part));continue
            if len(ce)!=len(be): res.append((fn,f'ESC-COUNT {len(be)}vs{len(ce)} {nm}',part));continue
            bo=be[k]
            if E is None: lo,hi=-16,0
            else: lo,hi=0,max(E,sz)
            wb=[x-bo for x in sorted(set(ba+be)) if bo+lo<=x<bo+hi]
            wc=[x-co for x in sorted(set(ca+ce)) if co+lo<=x<co+hi]
            res.append((fn,'OK' if wb==wc else 'DIFF',part,nm,sz,E,why,wb,wc))
    return res
if __name__=='__main__':
    b=sys.argv[1]
    r=run(b)
    import collections
    print(collections.Counter(x[1].split()[0] for x in r))
    for x in r:
        if x[1]!='OK': print(x)
