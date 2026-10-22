#!/usr/bin/env python3
"""gen_symblock.py PRISTINE_DIR OUT.tsv - the stack frame of an inlined `symbolTable.insert(TVariable)` block (IdentifyBuiltIns, executeInitializer, arrayErrorCheck...) relative to the stack TType base B:
B+0x10 pool allocator arg[4], B-0x30 insert result copy, B-0x34 flag copy, B-0x40 insert result iterator, B-0x44 insert flag, B-0x50 name copy TString, B-0x54 its chars, B-0x58 the TVariable, B-0x60 destroy allocator arg[4]."""
import re,sys,glob,os
d,outp=sys.argv[1:3]
sys.path.insert(0,os.path.expanduser('~/wt/D6/Tools/userspace'))
import apply_names as A
rows=A.load_rows(d); named=set((r[2],r[3]) for r in rows)
SD=os.path.expanduser('~/g5logs/D6/spec/')
for l in open(SD+'index.tsv'):
    sf,fn_=l.rstrip('\n').split('\t')
    for q in open(SD+sf): named.add((fn_,q.split('\t')[0]))
for tf in [f for f in glob.glob(os.path.expanduser('~/g5logs/D6/out_*.tsv')) if not f.endswith('out_symblock.tsv')]:
    for l in open(tf):
        c=l.split('\t')
        if c[0]=='local': named.add((c[1],c[2]))
R=[(0x10,'poolAllocatorArg','one-word array holding GetGlobalPoolAllocator(), the allocator argument of the TString constructor'),
   (-0x30,'insertResultCopy','copy of the iterator half of the symbol table level map insert result'),
   (-0x34,'insertResultFlagCopy','copy of the inserted flag half of the insert result'),
   (-0x40,'insertResult','iterator half of the std::map insert result (hidden pair return)'),
   (-0x44,'insertResultFlag','inserted flag half of the std::map insert result'),
   (-0x50,'nameCopy','temporary TString copy of the variable name (key of the map insert)'),
   (-0x54,'nameCopyChars','character pointer of nameCopy (its refcount word is at -4)'),
   (-0x58,'variableForInsert','the new TVariable stored as the map value'),
   (-0x60,'destroyAllocator','allocator argument array of the _Rep::_M_destroy call that releases nameCopy')]
out=open(outp,'w'); out.write('# local rows, fork D6: stack frame of the inlined symbol-table insert of a TVariable\n'); n=0
for pf in sorted(glob.glob(os.path.join(d,'part_*.c'))):
    text=open(pf).read(); lines,fns=A.split_functions(text)
    for fn,s,e in fns:
        body=lines[s:e]; txt='\n'.join(body)
        bases=[]
        for l in body:
            m=re.match(r'\s*(local_[0-9a-f]+) = &PTR___ZN5TTypeD1Ev',l)
            if m and m.group(1) not in bases: bases.append(m.group(1))
        if len(bases)<1: continue
        decl={}
        for m in re.finditer(r'^\s+(?!return\b)([\w ]+?[ *]+)(local_[0-9a-f]+)( ?\[\d+\])?;$',txt,re.M): decl[m.group(2)]=(m.group(1),m.group(3))
        bs=sorted(bases,key=lambda x:-int(x[6:],16)); tags=['']+[chr(ord('B')+k) for k in range(len(bs))]
        if len(bs)==1: tags=['']
        for idx,b in enumerate(bs):
            B=int(b[6:],16)
            v58='local_%x'%(B-0x58); v60='local_%x'%(B-0x60); v10='local_%x'%(B+0x10)
            if not (v58 in decl and v60 in decl and v10 in decl and '[' in (decl[v60][1] or '') and '[' in (decl[v10][1] or '') and '*' in decl[v58][0]): continue
            for off,nm,ev in R:
                v='local_%x'%(B+off)
                if v in decl and (fn,v) not in named:
                    out.write('local\t%s\t%s\t%s%s\tINFERRED\t%s; frame slot at stack TType base %s%+#x\n'%(fn,v,nm,tags[idx],ev,b,off)); n+=1; named.add((fn,v))
out.close(); print(n,'rows')
