#!/usr/bin/env python3
"""gen_std.py PRISTINE_DIR OUT_SPEC - libstdc++ 4.0 containers instantiated in the dylib: std::vector (pool_allocator) members, COW basic_string members."""
import re,sys,glob,os
d,outp=sys.argv[1:3]
TY=r'(?:\([\w \*]+\))?'
rows=[]
def add(fn,new,tier,ev,pat): rows.append((fn,'*',new,tier,ev,pat))
for pf in sorted(glob.glob(d+'/part_*.c')):
    for m in re.finditer(r'^/\* (\S+) @',open(pf).read(),re.M):
        fn=m.group(1)
        isvec = fn.startswith('std__vector_') or 'NSt6vector' in fn
        isstr = fn.startswith('__ZNSs') or fn.startswith('__ZNKSs') or fn.startswith('__ZNSbIc') or fn.startswith('__ZNKSbIc') or fn.startswith('std__string_')
        if isvec:
            for off,nm,ev in ((4,'start','_M_start'),(8,'finish','_M_finish'),(0xc,'endOfStorage','_M_end_of_storage')):
                add(fn,nm,'CONFIRMED','std::vector %s at this+0x%x (+0 is the pool_allocator pointer)'%(ev,off),r'= %s\*\([\w \*]+\)\(this \+ %d\);$|= %s\*\([\w \*]+\)\(this \+ 0x%x\);$'%(TY,off,TY,off) if off!=4 else r'= %s\*\([\w \*]+\)\(this \+ 4\);$'%TY)
        if isstr:
            add(fn,'data','CONFIRMED','std::string _M_dataplus._M_p: the character pointer at this+0; the _Rep header precedes it',r'= %s\*\([\w \*]+\)this;$|= %s\*\([\w \*]+\)\(this \+ 0\);$'%(TY,TY))
            add(fn,'repLength','CONFIRMED','_Rep::_M_length at data-0xc',r'= %s\*\([\w \*]+\)\(\w+ \+ -0xc\);$'%TY)
            add(fn,'repCapacity','CONFIRMED','_Rep::_M_capacity at data-8',r'= %s\*\([\w \*]+\)\(\w+ \+ -8\);$'%TY)
            add(fn,'repRefCount','CONFIRMED','_Rep::_M_references at data-4',r'= %s\*\([\w \*]+\)\(\w+ \+ -4\);$'%TY)
open(outp,'w').write(''.join('\t'.join(r)+'\n' for r in rows)); print(len(rows),'spec rows')
