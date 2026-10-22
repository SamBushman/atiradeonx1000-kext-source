#!/usr/bin/env python3
"""gen_art.py PRISTINE_DIR OUT.tsv - Ghidra register-model artifacts: in_RESERVE (lwarx reservation), in_cr0, and the byte that models CR0 (`(bool)(V >> 1 & 1)`)."""
import re,sys,glob,os
d,outp=sys.argv[1:3]
sys.path.insert(0,os.path.expanduser('~/wt/D6/Tools/userspace'))
import apply_names as A
rows=A.load_rows(d); named=set((r[2],r[3]) for r in rows)
used=set((r[2],r[4]) for r in rows)
SD=os.path.expanduser('~/g5logs/D6/spec/')
for l in open(SD+'index.tsv'):
    sf,fn_=l.rstrip('\n').split('\t')
    for q in open(SD+sf): named.add((fn_,q.split('\t')[0]))
for tf in [f for f in glob.glob(os.path.expanduser('~/g5logs/D6/out_*.tsv')) if not f.endswith('out_art.tsv')]:
    for l in open(tf):
        c=l.split('\t')
        if c[0] in('local','use') and len(c)>3: named.add((c[1],c[2]))
out=open(outp,'w'); out.write('# local rows, fork D6: Ghidra register-model artifacts\n'); n=0
for pf in sorted(glob.glob(os.path.join(d,'part_*.c'))):
    text=open(pf).read(); lines,fns=A.split_functions(text)
    for fn,s,e in fns:
        txt='\n'.join(lines[s:e])
        idents=set(re.findall(r'[A-Za-z_]\w*',txt))
        def emit(old,new,tier,ev):
            global n
            if old in idents and new not in idents and (fn,old) not in named:
                out.write('local\t%s\t%s\t%s\t%s\t%s\n'%(fn,old,new,tier,ev)); named.add((fn,old)); idents.add(new); n+=1
        emit('in_RESERVE','reservation','INFERRED','Ghidra artifact: the lwarx reservation flag tested before the conditional store (stwcx.)')
        emit('in_cr0','cr0Reg','INFERRED','Ghidra artifact: the incoming condition register field CR0')
        for m in re.finditer(r'\(bool\)\((b?[A-Za-z]*Var\d+) >> 1 & 1\)',txt):
            v=m.group(1)
            if re.search(r'\bbyte %s;'%v,txt): emit(v,'cr0Flags','INFERRED','Ghidra models CR0 as a byte: (x == 0) << 1 sets the EQ bit, (V >> 1 & 1) tests it')
out.close(); print(n,'rows')
