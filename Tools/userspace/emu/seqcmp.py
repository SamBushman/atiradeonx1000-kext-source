#!/usr/bin/env python3
"""seqcmp.py SQ_STOCK.out SQ_NEW.out - compare two seqtrace logs: the call ORDER (names) and, per call, the register args that are plain small numbers in BOTH (pointers differ with the heap layout).
Prints the first divergence of the order, then the first calls whose small-number args differ."""
import re, sys
def load(f):
    return [(m.group(1), [int(x, 16) for x in m.groups()[1:]]) for l in open(f, errors='replace') for m in [re.search(r'H (\S+) r3=([0-9a-f]+) r4=([0-9a-f]+) r5=([0-9a-f]+) r6=([0-9a-f]+)', l)] if m]
A, B = load(sys.argv[1]), load(sys.argv[2])
print(len(A), len(B), 'calls')
for i, (a, b) in enumerate(zip(A, B)):
    if a[0] != b[0]:
        print('ORDER DIVERGES at call', i); print(' stock  :', [x[0] for x in A[max(0, i-6):i+6]]); print(' rebuilt:', [x[0] for x in B[max(0, i-6):i+6]]); break
else: print('same order over', min(len(A), len(B)), 'calls')
n = 0
for i, (a, b) in enumerate(zip(A, B)):
    if a[0] != b[0]: break
    d = [k for k in range(4) if a[1][k] != b[1][k] and a[1][k] < 0x10000 and b[1][k] < 0x10000]
    if d and n < 15: print('call', i, a[0], 'small args differ:', [(f'r{k+3}', hex(a[1][k]), hex(b[1][k])) for k in d]); n += 1
