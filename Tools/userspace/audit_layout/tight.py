import re,sys,glob,os,collections
T=glob.glob(os.path.expanduser('~/g5logs/tmp_r18/vn_*'))
def funcs(path):
    out={};cur=None
    for l in open(path,errors='replace'):
        m=re.match(r'^(_[A-Za-z0-9_$.]*):$',l.rstrip())
        if m: cur=m.group(1);out[cur]=([],[]);continue
        if cur is None: continue
        m=re.match(r'\s+addi\s+r\d+,r30,(-?\d+)',l) or re.match(r'\s+la\s+r\d+,(-?\d+)\(r30\)',l)
        if m: out[cur][0].append(int(m.group(1)));continue
        m=re.match(r'\s+\w+\s+[rf]\d+,(-?\d+)\(r30\)',l)
        if m: out[cur][1].append(int(m.group(1)))
    return {k:(sorted(set(v[0])),sorted(set(v[1]))) for k,v in out.items()}
res=collections.Counter();det=[]
cache={}
for l in open('gaps.tsv'):
    b,p,f,v,_,_=l.rstrip('\n').split('\t')
    if v!='LAYOUT': continue
    d=[x for x in T if ('_'+b+'_ppc_a18_') in x and 'a18b' not in x][0]
    if (d,p) not in cache: cache[(d,p)]=(funcs(d+'/base.'+p+'.dis'),funcs(d+'/cand.'+p+'.dis'))
    B,C=cache[(d,p)]
    be,ba=B[f];ce,ca=C[f]
    if len(be)!=len(ce): res['esc-count-differs']+=1;det.append((b,p,f,'COUNT',be,ce));continue
    bad=[]
    for i in range(len(be)-1):
        k1,k2=be[i],be[i+1]
        between=[o for o in ba if k1<o<k2]
        if not between and (ce[i+1]-ce[i])!=(k2-k1): bad.append((k1,k2,ce[i],ce[i+1]))
    if bad: res['TIGHT-PAIR-CHANGED']+=1;det.append((b,p,f,'TIGHT',bad))
    else: res['only-separated-pairs-changed']+=1
print(res)
for d in det: print(d)
