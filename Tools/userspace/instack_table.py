#!/usr/bin/env python3
"""instack_table.py DUMP_DIR  - one row per function whose decompile reads `in_stack_XXXXXXXX`: entry, name, parameter count, whether the
signature has float parameters, the positive offsets (0x38 and up: the 9th+ argument words the caller stored at 0x38(r1) - an undeclared stack
parameter) and the negative ones (below the entry stack pointer: over-arity call arguments Ghidra invented, e.g. SysV-stacked fparam_9..13).
Input of stack_params.py."""
import re,sys,glob,os
d=sys.argv[1]
pos=neg=0
for f in sorted(glob.glob(d+'/*.txt')):
    t=open(f).read()
    m=re.search(r'// Function: (\S+) @ (\S+)\n// Signature: (.*)',t)
    if not m: continue
    offs=sorted(set(int(x,16) for x in re.findall(r'\bin_stack_([0-9a-f]{8})\b',t)))
    if not offs: continue
    np=len(re.findall(r'param_\d+|\w+ \w+[,)]',m.group(3).split('(',1)[1])) if '(void)' not in m.group(3) else 0
    fl='float' in m.group(3) or 'double' in m.group(3)
    p=[o for o in offs if o<0x80000000]; n=[o for o in offs if o>=0x80000000]
    print("%s\t%s\tparams=%d\tfp=%d\tpos=%s\tneg=%s"%(m.group(2),m.group(1),np,fl,','.join('%x'%o for o in p),','.join('-%x'%(0x100000000-o) for o in n)))
