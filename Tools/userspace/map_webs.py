#!/usr/bin/env python3
"""map_webs.py DIR FUNC_A FUNC_B SPEC_A.tsv - carry web names from FUNC_A to a near-duplicate FUNC_B (code the compiler inlined or copied).

SPEC_A uses the emit_webs.py spec format for FUNC_A. The statements of both functions are aligned (variable names blanked, equal runs >= 4 lines); for every
named web of FUNC_A the variable and web of FUNC_B holding the aligned lines is looked up. Output: `VAR<TAB>WEB<TAB>name<TAB>tier<TAB>evidence<TAB>#from ...`
with how many lines of the B web were covered. Review rows whose B web is larger than the covered part (the web may join other roles) before using them
as an emit_webs.py spec."""
import sys,os,re,difflib,collections
sys.path.insert(0,os.path.dirname(os.path.abspath(__file__)))
import find_webs as F
d=None
PH=re.compile(r'\b(param_[0-9]+|[a-zA-Z]{0,4}Var[0-9]+|local_[0-9a-f]+|[a-z]Stack_?[0-9a-f]+|fparam_[0-9]+|in_[A-Za-z0-9]+)\b')
def skel(l): return PH.sub('V',l.strip())
def main(dd,fa,fb,spec):
    global d
    d=dd
    A,ba=F.load(d,fa); B,bb=F.load(d,fb)
    na,ea=F.build_cfg(A,ba); nb,eb=F.build_cfg(B,bb)
    # webs of A named in spec
    names={}  # (var,web)->(name,tier,ev)
    for l in open(spec):
        if not l.strip() or l.startswith('#'): continue
        var,wl,new,tier,ev=l.rstrip('\n').split('\t')[:5]
        if wl=='*': continue
        for w in wl.split(','):
            m=re.match(r'^(\d+)(?:([<>])(\d+))?$',w); names[(var,int(m.group(1)),m.group(2),m.group(3))]=(new,tier,ev)
    wa={}
    for (var,k,op,n) in names:
        if var not in wa: wa[var]=F.webs(na,ea,var)[0]
    sa=[skel(l) for l in A]; sb=[skel(l) for l in B]
    a0=ba+1; b0=bb+1
    sm=difflib.SequenceMatcher(None,sa[a0:],sb[b0:],autojunk=False)
    line_map={}
    for tag,i1,i2,j1,j2 in sm.get_opcodes():
        if tag=='equal' and i2-i1>=4:
            for i,j in zip(range(i1,i2),range(j1,j2)): line_map[a0+i]=b0+j
    out=[]
    ids=lambda l: PH.findall(l)
    nbrcache={}
    for (var,k,op,n),(new,tier,ev) in names.items():
        lines=wa[var][k]
        if op=='<': lines=[x for x in lines if x<int(n)]
        if op=='>': lines=[x for x in lines if x>=int(n)]
        votes=collections.Counter(); blines=set()
        for x in lines:
            if x not in line_map: continue
            y=line_map[x]; la=ids(A[x]); lb=ids(B[y])
            # position of var occurrences within la
            for pos,v in enumerate(la):
                if v==var and len(la)==len(lb):
                    votes[lb[pos]]+=1; blines.add((lb[pos],y))
        if not votes: continue
        vb,cnt=votes.most_common(1)[0]
        ys=sorted(y for (v,y) in blines if v==vb)
        if vb not in nbrcache:
            try: nbrcache[vb]=F.webs(nb,eb,vb)[0]
            except SystemExit as ex:
                print('#skip',vb,ex); nbrcache[vb]=None
        if nbrcache[vb] is None: continue
        # find web of vb containing the majority of ys
        sc=collections.Counter()
        for y in ys:
            for wi,wl in enumerate(nbrcache[vb]):
                if y in wl: sc[wi]+=1
        if not sc: continue
        wi,c=sc.most_common(1)[0]
        out.append((vb,wi,new,tier,ev,var,k,cnt,len(lines),len(ys),c,len(nbrcache[vb][wi])))
    for o in sorted(out): print('\t'.join(str(x) for x in o[:5])+'\t#from %s w%d votes=%d/%d lines mapped=%d, webB covered %d/%d'%o[5:])
if __name__=='__main__': main(*sys.argv[1:5])
