"""classify_retv.py OUT : for every DIFF row of a ret-compare run (fnfuzz output), look at the STOCK function extent (corpus header address up to the next corpus function; out-of-line switch bodies lie
beyond the Ghidra size): for every blr, is the last r3-defining instruction in the 10 instructions before it a non-call definition?
   L = none (r3 is scratch state at return: the DIFF is an artifact of comparing a void function)   D:... = defined (candidate real return difference, read the function)
usage: [STOCK=<stock Mach-O>] [CORPUS=<Userspace dir name>] classify_retv.py OUT [OUT...]   (defaults: libGLProgrammability)"""
import re,glob,sys,bisect
import os
sys.path.insert(0,os.path.dirname(os.path.abspath(__file__)))
import fn_norm_diff as f, capstone
MD=capstone.Cs(capstone.CS_ARCH_PPC,capstone.CS_MODE_32|capstone.CS_MODE_BIG_ENDIAN); MD.skipdata=True
S=os.environ.get('STOCK',os.path.expanduser('~/Documents/ATI-X1900-Decomp/tiger-hd-pull/libGLProgrammability.dylib'))  # the stock Mach-O (env STOCK)
size={}
for fn in glob.glob(os.path.join(os.path.dirname(os.path.abspath(__file__)),'../../Userspace',os.environ.get('CORPUS','libGLProgrammability'),'ppc/part_*.c')):
    for m in re.finditer(r'^/\* (\S+) @ 0x([0-9a-f]+) \((\d+) bytes\)',open(fn,errors='replace').read(),re.M): size[m.group(1)]=int(m.group(2),16)
starts=sorted(set(size.values()))
for out in sys.argv[1:]:
  for l in open(out):
    if not l.startswith('DIFF'): continue
    n=l.split()[1]
    if n not in size: print('?',n); continue
    sa=size[n]; k=bisect.bisect_right(starts,sa); end=starts[k] if k<len(starts) else sa+0x1000
    ins=list(MD.disasm(f.code(S,sa,end-sa),sa)); res=set(); nb=0
    for k,i in enumerate(ins):
        if i.mnemonic=='blr':
            nb+=1; r='L'
            for x in reversed(ins[max(0,k-40):k]):
                if x.mnemonic in ('bl','bctrl'): r='CALL'; break
                if re.match(r'r3,',x.op_str) and not x.mnemonic.startswith(('cmp','st','mt','b','lmw','tw')): r='D:'+x.mnemonic+' '+x.op_str; break
            res.add(r)
    print('%-46s %2d blr: %s'%(n,nb,' | '.join(sorted(res))))
