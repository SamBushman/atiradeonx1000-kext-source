#!/usr/bin/env python3
"""clonerows.py TABLE FROMFUNC TOFUNC [old=new ...] - print the rows of TABLE that name FROMFUNC with TOFUNC instead (a byte-for-byte duplicate of a function compiled
twice carries the same Ghidra names); `old=new` pairs rewrite text in the evidence column."""
import sys
t, a, b = sys.argv[1:4]; subs = [s.split('=', 1) for s in sys.argv[4:]]
for l in open(t):
    c = l.rstrip('\n').split('\t')
    if len(c) > 5 and c[0] in ('local', 'use') and c[1] == a:
        c[1] = b
        for o, n in subs: c[5] = c[5].replace(o, n)
        print('\t'.join(c))
