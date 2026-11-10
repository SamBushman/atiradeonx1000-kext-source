#!/usr/bin/env python3
"""gleng_data_addrs.py SYMS.xz REBUILT.nm NAME... > data_addrs.tsv - the addresses of image globals (and functions: a pointer a watched word holds is named by the entry it equals) in both images, for fnfuzz FNFUZZ_DATA:
name<TAB>stock address (Ghidra symbol map, ghidra/gleng_data.tsv.syms.xz)<TAB>rebuilt address (nm of the rebuilt image). A name missing on either side is an error."""
import sys, lzma
syms, nm, names = sys.argv[1], sys.argv[2], sys.argv[3:]
st = {}
for l in lzma.open(syms, 'rt'):
    p = l.rstrip('\n').split('\t')
    if len(p) >= 3 and p[2] in names and p[1] in ('__data', '__bss', '__const', '__common', '__text'): st[p[2]] = int(p[0], 16)
rb = {}
for l in open(nm):
    p = l.split()
    if len(p) == 3 and p[2] in names and p[1] in 'dDbBsStT': rb[p[2]] = int(p[0], 16)
for n in names:
    if n not in st or n not in rb: sys.exit('missing %s: stock %s rebuilt %s' % (n, n in st, n in rb))
    print('%s\t%x\t%x' % (n, st[n], rb[n]))
