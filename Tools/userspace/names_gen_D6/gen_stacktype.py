#!/usr/bin/env python3
"""gen_stacktype.py PRISTINE_DIR OUT.tsv - name the words of stack-allocated TType objects: a local `L = &PTR___ZN5TTypeD1Ev...` is the vtable word of a TType on the
stack; the following ten words (locals at -4 each) are its fields (layout recovered from TType::setType/getTypeName/getFieldName/setStructSize/getBasicType...)."""
import re,sys,glob,os,collections
d,outp=sys.argv[1:3]
sys.path.insert(0,os.path.expanduser('~/wt/D6/Tools/userspace'))
import apply_names as A
rows=A.load_rows(d)
named=set((r[2],r[3]) for r in rows)   # (function, old)
SD=os.path.expanduser('~/g5logs/D6/spec/')
for l in open(SD+'index.tsv'):
    sf,fn_=l.rstrip('\n').split('\t')
    for q in open(SD+sf):
        named.add((fn_,q.split('\t')[0]))
FIELDS=['','ArraySize','Structure','FieldName','TypeName','Word14','StructureSize','Word1c','Word20','Bits']
EVID=['TType vtable store (&PTR___ZN5TTypeD1Ev)','TType +4 (setType: the last argument, array size)','TType +8 structure (TTypeList*), copied from userDef+8','TType +0xc fieldName (TString*)','TType +0x10 typeName (TString*, TType__getTypeName)','TType +0x14 (copied to TVariable+0x20; no accessor seen)','TType +0x18 structureSize (TType__setStructSize)','TType +0x1c (no accessor seen)','TType +0x20 (no accessor seen)','TType +0x24 bit-field word (qualifier 31..25, basic type 24..19, size 18..11, matrix 10, array 9)']
out=open(outp,'w'); out.write('# local rows, fork D6: words of stack TType objects (vtable store at the first word)\n'); n=0; nf=0
for pf in sorted(glob.glob(os.path.join(d,'part_*.c'))):
    text=open(pf).read(); lines,fns=A.split_functions(text)
    for fn,s,e in fns:
        body=lines[s:e]
        bases=[]
        for l in body:
            m=re.match(r'\s*(local_[0-9a-f]+) = &PTR___ZN5TTypeD1Ev',l)
            if m and m.group(1) not in bases: bases.append(m.group(1))
        if not bases: continue
        decl=set()
        for l in body:
            m=re.match(r'\s+(?!return\b)[\w ]+?[ *]+(local_[0-9a-f]+);$',l)
            if m: decl.add(m.group(1))
        roles={}   # local -> [(tag, field index)]
        tags=['stackType'] + ['stackType'+chr(ord('B')+k) for k in range(len(bases))]
        bs=sorted(bases,key=lambda x:-int(x[6:],16))
        if len(bs)==1: tags=['stackType']
        for idx,b in enumerate(bs):
            base=int(b[6:],16)
            for k in range(10):
                v='local_%x'%(base-4*k)
                if v in decl and (fn,v) not in named:
                    roles.setdefault(v,[]).append((tags[idx],k))
        nm={}
        for v,rs in roles.items():
            nm[v]=('Or'.join((t+FIELDS[k])[0].upper()+(t+FIELDS[k])[1:] if i else t+FIELDS[k] for i,(t,k) in enumerate(rs)), '; also '.join(EVID[k] for t,k in rs))
        for v,(new,ev) in nm.items():
            out.write('local\t%s\t%s\t%s\tINFERRED\t%s; layout from TType accessors; the slot is also reused as a TString by TType__getCompleteString\n'%(fn,v,new,ev)); n+=1
        nf+=1
out.close(); print(nf,'functions',n,'rows')
