#!/usr/bin/env python3
# float_ints.py DUMPDIR - decompiler locals typed float that hold integers / pointers: a denormal literal assigned (the bits of a small integer:
# 2.8026e-45 = 2), or used as `(int)var` in an address / index. Prints RetypeLocals.java arguments for stack locals (stable names) and lists
# register variables (fVarN) separately.
import sys,re,glob,collections
D=sys.argv[1]; stack=collections.defaultdict(set); regs=collections.defaultdict(set)
for f in glob.glob(D+'/*.txt'):
    t=open(f).read(); m=re.search(r'// Function: .* @ (\S+)',t)
    if not m: continue
    ent=int(m.group(1),16)
    fl=set(re.findall(r'(?m)^\s+float\s+(\w+)(?:\s*\[\d+\])?;',t))
    for v in fl:
        den=re.search(r'\b%s(?:\[\d+\])?\s*=\s*-?\d\.\d+e-(?:4[0-5]|39|38)\b'%re.escape(v),t)
        addr=re.search(r'\(int\)\s*%s\b(?:\[\d+\])?\s*[+\]\)]'%re.escape(v),t) or re.search(r'\[\(int\)%s\b'%re.escape(v),t)
        if den or addr:
            (stack if v.startswith(('local_','auStack','fStack','uStack')) else regs)[ent].add(v)
for e,vs in sorted(stack.items()): print('0x%x:%s'%(e,','.join('%s=uint'%v for v in sorted(vs))))
for e,vs in sorted(regs.items()): print('# reg 0x%x %s'%(e,' '.join(sorted(vs))), file=sys.stderr)
