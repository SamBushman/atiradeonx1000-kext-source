"""f1cands.py LEDGER... : 'v' rows whose STOCK function defines f1 in the 10 instructions before a blr (candidate float/double return the harness does not compare)"""
import re,glob,sys,bisect
import os
sys.path.insert(0,os.path.dirname(os.path.abspath(__file__)))
import fn_norm_diff as f, capstone
MD=capstone.Cs(capstone.CS_ARCH_PPC,capstone.CS_MODE_32|capstone.CS_MODE_BIG_ENDIAN); MD.skipdata=True
S=os.environ.get('STOCK',os.path.expanduser('~/Documents/ATI-X1900-Decomp/tiger-hd-pull/libGLProgrammability.dylib'))  # the stock Mach-O (env STOCK)
size={}
for fn in glob.glob(os.path.join(os.path.dirname(os.path.abspath(__file__)),'../../Userspace/libGLProgrammability/ppc/part_*.c')):
    for m in re.finditer(r'^/\* (\S+) @ 0x([0-9a-f]+) \((\d+) bytes\)',open(fn,errors='replace').read(),re.M): size[m.group(1)]=int(m.group(2),16)
starts=sorted(set(size.values()))
seen=set()
for led in sys.argv[1:]:
  for l in open(led):
    p=l.rstrip('\n').split('\t')
    if len(p)<7 or p[0].startswith('#') or p[6]!='v' or p[1] in seen: continue
    seen.add(p[1])
    if p[1] not in size: continue
    sa=size[p[1]]; k=bisect.bisect_right(starts,sa); end=starts[k] if k<len(starts) else sa+0x1000
    ins=list(MD.disasm(f.code(S,sa,end-sa),sa)); hit=None
    for k,i in enumerate(ins):
        if i.mnemonic=='blr':
            d=[x for x in ins[max(0,k-10):k] if re.match(r'f1,',x.op_str) and not x.mnemonic.startswith(('fcmp','stf','mt','b'))]
            if d: hit=d[-1].mnemonic+' '+d[-1].op_str; break
    if hit: print(p[1],hit)
