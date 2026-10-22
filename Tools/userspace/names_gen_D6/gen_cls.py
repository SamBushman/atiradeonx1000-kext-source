#!/usr/bin/env python3
"""gen_cls.py PRISTINE_DIR OUT_SPEC - spec rows for gen_pat.py: (a) loads of accessor-named fields of `this`, (b) virtual calls on `this` named by the class's __ZTV slot method names."""
import re,sys,glob,os
sys.path.insert(0,os.path.expanduser('~/g5logs/D6'))
import vtmap
VT=vtmap.VT
d,outp=sys.argv[1:3]
FIELDS={('TCompiler',4):'infoSink',('TGenericLinker',48):'ppStreamManager',('TGenericLinker',64):'shaderLocalParamRemapTable',('TGenericLinker',72):'numShaderLocalParams',
 ('TIntermBinary',52):'left',('TIntermBinary',56):'right',('TIntermNode',4):'line',('TIntermSelection',48):'condition',('TIntermSelection',52):'trueBlock',('TIntermSelection',56):'falseBlock',
 ('TIntermSymbol',48):'id',('TIntermUnary',52):'operand',('TPPStreamCompiler',116):'ppStream',('TSymbol',4):'mangledName',('TType',12):'fieldName',('TType',16):'typeName'}
TY=r'\([\w \*]+\)'
rows=[]
def cls_of(fn):
    m=re.match(r'^([A-Z]\w*?)__\w',fn)
    if m: return m.group(1)
    m=re.match(r'^__ZN(\d+)',fn)
    if m:
        n=int(m.group(1)); return fn[m.end(1):m.end(1)+n]
    return None
import glob
for pf in sorted(glob.glob(d+'/part_*.c')):
    L=open(pf).read().split('\n'); i=0
    while i<len(L):
        m=re.match(r'^/\* (\S+) @',L[i])
        if not m: i+=1; continue
        fn=m.group(1); j=i+1
        while j<len(L) and not L[j].startswith('/* '): j+=1
        txt='\n'.join(L[i:j]); i=j
        cls=cls_of(fn)
        if not cls: continue
        this=r'this'
        seen=set()
        # (a) field loads
        for (c,off),fld in FIELDS.items():
            if c!=cls and not (c=='TIntermNode' and cls.startswith('TInterm')) : continue
            if re.search(r'\(%s \+ (?:0x%x|%d)\)'%(this,off,off),txt):
                rows.append((fn,'*',fld,'INFERRED','load of %s::%s (+0x%x), named by its accessor %s'%(c,fld,off,'get'+fld[0].upper()+fld[1:]),r'= (?:%s)?\*%s\(%s \+ 0x%x\);$'%(TY,TY,this,off)+'|'+r'= (?:%s)?\*%s\(%s \+ %d\);$'%(TY,TY,this,off)))
        # (b) virtual calls on this
        vt=VT.get(cls)
        if vt:
            for mm in re.finditer(r'= (?:%s)?\(\*\*\(code \*\*\)\(\*\(int \*\)%s \+ (0x[0-9a-f]+|\d+)\)\)\(%s'%(TY,this,this),txt):
                off=int(mm.group(1),0)
                if off in vt and vt[off][0] and vt[off][0]!='~' and (off,) not in seen:
                    seen.add((off,)); meth=vt[off][0]
                    nm=re.sub(r'^get(?=[A-Z])','',meth); nm=nm[0].lower()+nm[1:]
                    if nm in ('type','line','basicType'): nm=nm  # keep
                    rows.append((fn,'*',nm+'Result' if nm==meth else nm,'CONFIRMED','virtual call of %s::%s (vtable symbol __ZTV%d%s slot at +0x%x) on this'%(cls,meth,len(cls),cls,off),r'= (?:%s)?\(\*\*\(code \*\*\)\(\*\(int \*\)%s \+ (?:%s)\)\)\(%s'%(TY,this,re.escape(mm.group(1)).replace('0x','0x') if mm.group(1).startswith('0x') else mm.group(1),this)))
open(outp,'w').write(''.join('\t'.join(r)+'\n' for r in rows)); print(len(rows),'spec rows',len({r[0] for r in rows}),'functions')
