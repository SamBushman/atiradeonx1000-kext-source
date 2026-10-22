#!/usr/bin/env python3
"""gen_oprec.py PRISTINE_DIR OUT.tsv - name the 14 words of a _PPStreamOperation record (passed by address to _PPStreamAddOperation / TPPStreamCompiler__AddOperation)."""
import re,sys,glob,os
d,outp=sys.argv[1:3]
sys.path.insert(0,os.path.expanduser('~/wt/D6/Tools/userspace'))
import apply_names as A
rows=A.load_rows(d); named=set((r[2],r[3]) for r in rows)
SD=os.path.expanduser('~/g5logs/D6/spec/')
for l in open(SD+'index.tsv'):
    sf,fn_=l.rstrip('\n').split('\t')
    for q in open(SD+sf): named.add((fn_,q.split('\t')[0]))
F=['Header','Flags','Dest0','Dest1','Src0A','Src0B','Src1A','Src1B','Src2A','Src2B','AuxA','AuxB','Line','Word13']
EV=['word 0: opcode in bits 25..18 ((opcode & 0xff) << 0x12 in _PPParserParseOperation)','word 1: modifier/condition flags ((param_3 & 3) << 0x12 | ... in _PPParserParseOperation)',
 'destination operand descriptor, first word (ParseOperand__GetAsDestVar output, filled by _PPParserParseDestination(parser, &rec+8))','destination operand descriptor, second word',
 'source 0 descriptor, first word (_PPParserParseSourceVar(parser, &rec+0x10))','source 0 descriptor, second word','source 1 descriptor, first word','source 1 descriptor, second word',
 'source 2 descriptor, first word','source 2 descriptor, second word','auxiliary operand (condition/branch) first word, zero-initialised','auxiliary operand second word',
 'source line (parser+0x18 / TIntermNode slot 0 getLine)','word 13: copied from the parser state (local_5c = local_50 in _PPParserParseOperation)']
out=open(outp,'w'); out.write('# local rows, fork D6: words of the 14-word _PPStreamOperation record\n'); n=0
for pf in sorted(glob.glob(os.path.join(d,'part_*.c'))):
    text=open(pf).read(); lines,fns=A.split_functions(text)
    for fn,s,e in fns:
        body=lines[s:e]; txt='\n'.join(body)
        bases=[]
        for m in re.finditer(r'(?:AddOperation|_PPStreamInsertOperation\w*)\(([^;]*?)\)\s*;',txt,re.S):
            for mm in re.finditer(r'&(local_[0-9a-f]+)\b',m.group(1)):
                if mm.group(1) not in bases: bases.append(mm.group(1))
        if not bases: continue
        decl=set(re.findall(r'^\s+(?!return\b)[\w ]+?[ *]+(local_[0-9a-f]+);$',txt,re.M))
        roles={}
        bs=sorted(bases,key=lambda x:-int(x[6:],16)); tags=['op'] if len(bs)==1 else ['op%d'%(i+1) for i in range(len(bs))]
        for idx,b in enumerate(bs):
            base=int(b[6:],16)
            for k in range(14):
                v='local_%x'%(base-4*k)
                if v in decl and (fn,v) not in named: roles.setdefault(v,[]).append((tags[idx],k))
        for v,rs in roles.items():
            nm='Or'.join(((t+F[k]) if i==0 else (t+F[k])[0].upper()+(t+F[k])[1:]) for i,(t,k) in enumerate(rs))
            out.write('local\t%s\t%s\t%s\tINFERRED\t_PPStreamOperation record (14 words) passed by address to the stream: %s\n'%(fn,v,nm,'; also '.join(EV[k] for t,k in rs))); n+=1
out.close(); print(n,'rows')
