#!/usr/bin/env python3
"""gen_strparams.py PRISTINE_DIR OUT.tsv - parameter names of the libstdc++ basic_string members, from the mangled signature and the libstdc++ 4.0 declarations."""
import re,sys,glob,os
d,outp=sys.argv[1:3]
sys.path.insert(0,os.path.expanduser('~/wt/D6/Tools/userspace'))
import apply_names as A
rows=A.load_rows(d); named=set((r[2],r[3]) for r in rows)
def parse(sig):
    """parameter type tokens of the mangled argument string"""
    toks=[]; i=0
    while i<len(sig):
        for pat,t in ((r'RKSs','str'),(r'RKSaIcE','alloc'),(r'RSs','strRef'),(r'PKc','s'),(r'Pc','sMut'),(r'N9__gnu_cxx17__normal_iterator\w+?SsE','iter'),(r'St18input_iterator_tag','tag'),(r'S1_','dup'),(r'S2_','dup'),(r'S_','dup'),(r'm','size'),(r'c','char'),(r'v','void'),(r'i','int'),(r'RKSbIcSt11char_traitsIcE14pool_allocatorIcEE','str'),(r'T_','tmpl')):
            m=re.match(pat,sig[i:])
            if m: toks.append(t); i+=m.end(); break
        else: toks.append('?'); i+=1
    return [t for t in toks if t!='void']
out=open(outp,'w'); out.write('# local rows, fork D6: libstdc++ 4.0 basic_string member parameters (names follow the libstdc++ declarations)\n'); n=0
for pf in sorted(glob.glob(os.path.join(d,'part_*.c'))):
    lines,fns=A.split_functions(open(pf).read())
    for fn,s,e in fns:
        m=re.match(r'^__ZN(K?)S(?:s|bIcSt11char_traitsIcE14pool_allocatorIcEE)(\d+)?(\w+?)E(.*)$',fn)
        if not m: continue
        # method name
        mm=re.match(r'^__ZNK?Ss(\d+)([A-Za-z_]+)E(.*)$',fn) or re.match(r'^__ZNK?SbIcSt11char_traitsIcE14pool_allocatorIcEE(\d+)([A-Za-z_]+)E(.*)$',fn)
        if mm:
            meth=mm.group(2)[:int(mm.group(1))]; sig=mm.group(2)[int(mm.group(1)):]+mm.group(3) if False else mm.group(3)
        else:
            mc=re.match(r'^__ZNSs(C[124])E(.*)$',fn)
            if not mc: continue
            meth='ctor'; sig=mc.group(2)
        toks=parse(sig)
        txt='\n'.join(lines[s:e])
        # parameter list of the corpus function in order
        hdr=re.search(r'\((.*)\)$',lines[s+1])
        if not hdr: continue
        params=[p.strip() for p in hdr.group(1).split(',')]
        if not params or params[0] not in ('this','param_1'): continue
        sizes=[]
        names=[]
        szn=iter(['pos','n','n2','n3'] if meth not in ('insert','replace','compare') else ['pos1','n1','pos2','n2'])
        # multi-string forms: first size is pos1
        for t in toks:
            if t=='size': names.append(next(szn,'n'))
            elif t=='str': names.append('str')
            elif t=='s': names.append('s')
            elif t=='sMut': names.append('s')
            elif t=='char': names.append('c')
            elif t=='alloc': names.append('alloc')
            elif t=='iter': names.append('i%d'%(1+sum(1 for x in names if x and x.startswith('i') and x[1:].isdigit())))
            elif t=='int': names.append('n')
            else: names.append(None)
        for k,nm in enumerate(names):
            idx=k+1   # params[idx] after this
            if idx>=len(params): break
            old=params[idx]
            if re.match(r'^param_\d+$',old) and nm and (fn,old) not in named:
                out.write('local\t%s\t%s\t%s\tINFERRED\tlibstdc++ 4.0 basic_string::%s parameter %d (%s) from the mangled signature %s\n'%(fn,old,nm,meth,k+1,nm,sig)); n+=1; named.add((fn,old))
out.close(); print(n,'rows')
