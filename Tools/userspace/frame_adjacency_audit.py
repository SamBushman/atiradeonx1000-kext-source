#!/usr/bin/env python3
"""frame_adjacency_audit.py ROOT - find places where the corpus reads or writes ACROSS two separately declared locals (defect class #282).

Ghidra splits one stack frame object into several locals (a select word and the 4-word array behind it, a 12-word key and the two words it was
declared as, ...) and then prints the access that crosses the split as pointer arithmetic from the neighbouring local:
    *(char *)((int)selectScratch + loopIndex + -4)           the byte that lives in the scalar declared just before the array
    _memset(variantKey, 0, 0x30)                              variantKey is declared as 2 words, the object is 12
    _memcpy(slot, entryRecord, 0x2c)                          the object is entryRecord[4] + entrySources[16] + entryComponents[4] + 2 pad words
Whether the compiler keeps those locals adjacent (and in that order) is not defined: the stock's frame had them adjacent, the rebuilt frame does not
have to (a dead store is dropped, the array moves). The rebuilt function then reads an uninitialised stack word.

Output (tab separated): KIND file:line function variable hint
  NEG   a `(int)ARR + idx + -N` / `(int)ARR + (idx - N)` access; hint = the scalar declared immediately before ARR (the word at ARR-4 in the stock frame)
  MEM   a memcpy/memset/memmove whose constant size exceeds the declared size of an address-taken or array local
The fix is to address the scalar itself (`(int)&operandSelect + idx`) or to declare the whole object as one array. Exit status 1 when anything is found.
"""
import re, glob, sys

SZ = {'undefined1': 1, 'undefined2': 2, 'undefined4': 4, 'undefined8': 8, 'undefined': 1, 'byte': 1, 'char': 1, 'uchar': 1, 'bool': 1, 'ushort': 2, 'short': 2,
      'int': 4, 'uint': 4, 'long': 4, 'ulong': 4, 'float': 4, 'double': 8, 'longlong': 8, 'ulonglong': 8, 'dword': 4, 'word': 2}
NEG = re.compile(r'\(int\)&?([A-Za-z_]\w*)\s*\+\s*(?:([A-Za-z_]\w*)\s*\+\s*-(\d+)|\(([A-Za-z_]\w*)\s*-\s*(\d+)\))\)')
DECL = re.compile(r'^\s+(undefined\d*|byte|char|uchar|bool|ushort|short|int|uint|long|ulong|float|double|longlong|ulonglong|dword|word)\s+([A-Za-z_]\w*)\s*(?:\[\s*(\d+)\s*\])?\s*;')
CALL = re.compile(r'\b(_memcpy|_memset|_memmove|_bcopy|memcpy|memset)\s*\(([^;]*?)\)\s*;')


def functions(lines):
    starts = [i for i, l in enumerate(lines) if re.match(r'^/\* \S+ @ 0x', l)] + [len(lines)]
    for k in range(len(starts) - 1):
        yield starts[k], starts[k + 1], lines[starts[k]].split()[1]


def main(root):
    found = 0
    for f in sorted(glob.glob(root + '/*/ppc/part_*.c')):
        L = open(f, errors='replace').read().split('\n')
        tag = '/'.join(f.split('/')[-3:])
        for a, b, fn in functions(L):
            decls = {}
            order = []
            for ln in range(a, b):
                m = DECL.match(L[ln])
                if m:
                    decls[m.group(2)] = (SZ[m.group(1)] * (int(m.group(3)) if m.group(3) else 1), bool(m.group(3)), ln)
                    order.append((ln, m.group(2), m.group(3) is not None))
            for ln in range(a, b):
                for m in NEG.finditer(L[ln]):
                    arr = m.group(1)
                    if arr not in decls or not decls[arr][1]:
                        continue                      # a pointer / scalar base: ordinary arithmetic
                    prev = ''
                    dl = decls[arr][2] - 1
                    while dl > a and not L[dl].strip():
                        dl -= 1
                    pm = DECL.match(L[dl])
                    if pm and not pm.group(3):
                        prev = pm.group(2)
                    print('NEG\t%s:%d\t%s\t%s\t%s' % (tag, ln + 1, fn, arr, prev or '?'))
                    found += 1
                for m in CALL.finditer(L[ln]):
                    args = [x.strip() for x in re.split(r',(?![^()]*\))', m.group(2))]
                    if len(args) < 3:
                        continue
                    try:
                        n = int(args[2], 0)
                    except ValueError:
                        continue
                    for t in ([args[0]] if 'memset' in m.group(1) else args[:2]):
                        t2 = re.sub(r'^\(.*?\)\s*', '', t).lstrip('&').strip()
                        mm = re.match(r'^([A-Za-z_]\w*)$', t2)
                        if mm and mm.group(1) in decls and decls[mm.group(1)][0] < n and (decls[mm.group(1)][1] or '&' in t):
                            print('MEM\t%s:%d\t%s\t%s\t%s(...,%d) declared %d bytes' % (tag, ln + 1, fn, mm.group(1), m.group(1), n, decls[mm.group(1)][0]))
                            found += 1
    return 1 if found else 0


if __name__ == '__main__':
    sys.exit(main(sys.argv[1] if len(sys.argv) > 1 else 'Userspace'))
