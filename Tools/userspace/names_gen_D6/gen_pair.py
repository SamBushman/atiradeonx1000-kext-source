#!/usr/bin/env python3
"""gen_pair.py PRISTINE_DIR OUT.tsv - 2-word operand descriptor outputs (struct return by hidden pointer): `&local_X` as the first argument of TPPStreamCompiler__getOperandAsDestVar/SourceVar/getConstantAsSourceVar."""
import re,sys,glob,os
d,outp=sys.argv[1:3]
sys.path.insert(0,os.path.expanduser('~/wt/D6/Tools/userspace'))
import apply_names as A
rows=A.load_rows(d); named=set((r[2],r[3]) for r in rows)
SD=os.path.expanduser('~/g5logs/D6/spec/')
for l in open(SD+'index.tsv'):
    sf,fn_=l.rstrip('\n').split('\t')
    for q in open(SD+sf): named.add((fn_,q.split('\t')[0]))
for tf in [f for f in glob.glob(os.path.expanduser('~/g5logs/D6/out_*.tsv')) if not f.endswith('out_pair.tsv')]:
    for l in open(tf):
        c=l.split('\t')
        if c[0]=='local': named.add((c[1],c[2]))
CALLS=r'(?:TPPStreamCompiler__getOperandAsDestVar|TPPStreamCompiler__getOperandAsSourceVar|TPPStreamCompiler__getConstantAsSourceVar|ParseOperand__GetAsDestVar|ParseOperand__GetAsSourceVar|TPPStreamCompiler__getNewConstantSourceVar)'
out=open(outp,'w'); out.write('# local rows, fork D6: 2-word operand descriptors returned through a hidden pointer\n'); n=0
for pf in sorted(glob.glob(os.path.join(d,'part_*.c'))):
    text=open(pf).read(); lines,fns=A.split_functions(text)
    for fn,s,e in fns:
        txt='\n'.join(lines[s:e])
        bases=[]
        for m in re.finditer(CALLS+r'\s*\(\s*(?:\(unsigned char \*\))?\s*&(local_[0-9a-f]+)\b',txt):
            if m.group(1) not in bases: bases.append(m.group(1))
        if not bases: continue
        decl=set(re.findall(r'^\s+(?!return\b)[\w ]+?[ *]+(local_[0-9a-f]+);$',txt,re.M))
        for b in bases:
            base=int(b[6:],16)
            sp=bool(re.search(r'_sprintf\(\(char \*\)&%s\b'%b,txt))
            for k,(nm0) in enumerate(['operandDesc','operandDescB']):
                v='local_%x'%(base-4*k)
                if v in decl and (fn,v) not in named:
                    nm=nm0+('OrSprintfBuffer' if sp and k==0 else '')
                    out.write('local\t%s\t%s\t%s\tINFERRED\t%s of the two-word operand descriptor (ParseOperand packed by getOperandAs{Dest,Source}Var / getConstantAsSourceVar through a hidden result pointer)%s\n'%(fn,v,nm,'first word' if k==0 else 'second word','; the same stack area is also the _sprintf scratch buffer' if sp and k==0 else '')); n+=1; named.add((fn,v))
out.close(); print(n,'rows')
