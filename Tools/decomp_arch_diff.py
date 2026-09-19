#!/usr/bin/env python3
"""decomp_arch_diff.py PPC_DIR I386_DIR [N]  - compare the Ghidra decompiles of the kext's two slices function by function
(Ghidra names match across slices). Tokens = numeric literals >= 0x20 (minus the PPC byte-swap masks), named callees and string
literals. A token present in one slice's decompile and not the other marks source-level (#ifdef) differences."""
import sys, re, os, collections
pd, idr = sys.argv[1], sys.argv[2]
top = int(sys.argv[3]) if len(sys.argv) > 3 else 60
def index(d):
    m = {}
    for l in open(os.path.join(d, 'INDEX.tsv')):
        a, sz, name = l.rstrip('\n').split('\t')
        m.setdefault(name, []).append((a, int(sz)))
    return m
BSWAP = {0xff00, 0xff0000, 0xff000000, 0xffff00, 0xffffff, 0xffff0000, 0xff00ff00, 0xffffff00, 0xffffffff, 0x18, 0x10, 0x8}
def toks(path):
    t = open(path).read()
    t = re.sub(r'/\*.*?\*/', '', t, flags=re.S)
    c = collections.Counter()
    for m in re.finditer(r'\b0x([0-9a-f]+)\b|\b(\d{2,})\b', t):
        v = int(m.group(1), 16) if m.group(1) else int(m.group(2))
        if v >= 0x20 and v not in BSWAP: c['n%x' % v] += 1
    for m in re.finditer(r'\b([A-Za-z_][\w:]*)\s*\(', t):
        n = m.group(1)
        if n not in ('if', 'while', 'switch', 'return', 'sizeof', 'for') and not n.startswith(('FUN_', 'CONCAT', 'SUB', 'ZEXT', 'SEXT', 'CARRY', 'SBORROW')): c['c:' + n.lstrip('_')] += 1
    for m in re.finditer(r'"([^"]*)"', t): c['s:' + m.group(1)] += 1
    return c
ip, ii = index(pd), index(idr)
res = []
for name in sorted(set(ip) & set(ii)):
    if len(ip[name]) != 1 or len(ii[name]) != 1: continue
    a = toks(os.path.join(pd, ip[name][0][0] + '.txt')); b = toks(os.path.join(idr, ii[name][0][0] + '.txt'))
    onlyp = {k for k in a if k not in b}; onlyi = {k for k in b if k not in a}
    d = len(onlyp) + len(onlyi)
    if d: res.append((d, name, sorted(onlyp)[:10], sorted(onlyi)[:10], ip[name][0][1]))
res.sort(reverse=True)
print(len(res), 'functions differ of', len(set(ip) & set(ii)), '; only-PPC names:', len(set(ip) - set(ii)), 'only-i386 names:', len(set(ii) - set(ip)))
for d, name, a, b, sz in res[:top]: print(d, name, sz, 'PPC-only', a, 'I386-only', b)
