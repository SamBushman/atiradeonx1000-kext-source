#!/usr/bin/env python3
"""
build_ledger.py - the completeness ledger: every function Ghidra finds in a stock binary, and whether the
rebuild defines a function for it. This is the measure of "100% transcribed"; nothing is counted by assertion.

Input 1: Ledger/<bin>_functions.tsv  (entry address, size in bytes, Ghidra name, symbol names) - dumped from Ghidra.
Input 2: defined.txt - symbols the rebuilt binary defines (on the Tiger box: nm build | awk '$2=="T"||$2=="t"{print $3}').
Input 3: the stock binary (to recognise 16-byte lazy-binding stubs).

Categories
  stub       16-byte `lis r12 / ori r12 / mtctr / bctr` trampoline: a lazy-binding stub to a kernel symbol or a
             long-branch island to a function in this kext. Produced by the compiler/linker, not source.
  generated  constructors, destructors, MetaClass and getMetaClass members, __GLOBAL__ init/fini: produced by
             OSDeclare/OSDefineMetaClassAndStructors and the compiler. Checked for PRESENCE, not hand-written.
  external   Ghidra pseudo-function for an imported symbol (no code)
  toolchain  kmod entry point supplied by libkmod at link time
  method     everything else: real program code that must be transcribed.
Status
  DONE       the rebuild defines the exact mangled symbol
  SIG?       the rebuild defines class::method but with a different parameter encoding (enum vs integer, opaque
             struct vs void*); needs a per-function look
  MISSING    no function in the rebuild
Usage: build_ledger.py LEDGER_TSV STOCK_BIN DEFINED_TXT > ledger.tsv    (summary on stderr)
"""
import sys, re, struct
from collections import Counter

TRAMP_TAIL = bytes.fromhex('7d8903a64e800420')   # mtctr r12 ; bctr

GEN = re.compile(r'(C[12]E|D[012]E|9MetaClass|12getMetaClass|__GLOBAL__|10gMetaClass|10superClass)')

def cm(s):
    m = re.match(r'__ZNK?(\d+)', s)
    if not m: return None
    n = int(m.group(1)); p = m.end(); cls = s[p:p+n]; p += n
    m2 = re.match(r'(\d+)', s[p:])
    if not m2: return (cls, s[p:p+2])
    k = int(m2.group(1)); a = p+len(m2.group(1)); return (cls, s[a:a+k])

def text_bytes(path):
    d = open(path, 'rb').read()
    if struct.unpack('>I', d[:4])[0] == 0xcafebabe:
        n = struct.unpack('>I', d[4:8])[0]
        for i in range(n):
            cpu, sub, off, size, al = struct.unpack('>5I', d[8+20*i:28+20*i])
            if cpu == 18: d = d[off:off+size]; break
    return d

def main():
    led, stock, defd = sys.argv[1:4]
    d = text_bytes(stock)
    text_off = 0x3c4          # __text fileoff in the kext; other binaries pass a different value via env if needed
    defined = set(l.strip() for l in open(defd) if l.strip())
    byname = set(cm(s) for s in defined if s.startswith('__Z')) - {None}
    rows = []; cnt = Counter(); bytes_ = Counter()
    for l in open(led):
        addr, size, gname, syms = l.rstrip('\n').split('\t')
        a = int(addr, 16); size = int(size)
        mangled = [s for s in syms.split(',') if s.startswith('__Z')]
        b = d[a+text_off:a+text_off+16]
        if size == 16 and b[:2] == b'\x3d\x80' and b[4:6] == b'\x61\x8c' and b[8:] == TRAMP_TAIL:
            cat, st = 'stub', 'n/a'
        elif gname.startswith('<EXTERNAL>'):
            cat, st = 'external', 'n/a'      # Ghidra pseudo-function for an imported symbol: no code in this binary
        elif gname == '__start':
            cat, st = 'toolchain', 'n/a'     # kmod entry point, supplied by libkmodc++/libkmod at link time
        elif mangled and GEN.search(mangled[0]):
            cat = 'generated'; st = 'DONE' if any(m in defined for m in mangled) else 'MISSING'
        elif mangled:
            cat = 'method'
            if any(m in defined for m in mangled): st = 'DONE'
            elif cm(mangled[0]) in byname: st = 'SIG?'
            else: st = 'MISSING'
        else:
            cat = 'method'; st = 'MISSING'   # no mangled symbol (local / unnamed function)
        rows.append((addr, size, cat, st, gname, mangled[0] if mangled else ''))
        cnt[(cat, st)] += 1; bytes_[(cat, st)] += size
    for r in rows: print('\t'.join(str(x) for x in r))
    print('%-10s %-8s %6s %9s' % ('category', 'status', 'funcs', 'bytes'), file=sys.stderr)
    for k in sorted(cnt): print('%-10s %-8s %6d %9d' % (k[0], k[1], cnt[k], bytes_[k]), file=sys.stderr)
    print('TOTAL functions %d' % len(rows), file=sys.stderr)
main()
