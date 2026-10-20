#!/usr/bin/env python3
"""check_plain_memory_loops.py - list the loops of the sources built with plain (non-volatile) memory accessors (-DGH_PLAIN_MEMORY, see Headers/GhidraCompat.h and
Tools/volatile_memory_sources.txt) that have no function call in their body and read memory in the loop condition: with non-volatile accesses the compiler may
read such a value once, so a loop that waits for memory another agent (the GPU, another thread) changes would never end. Every line printed has to be reviewed by
hand; the intended result is that each one is a counted or list walk over data the function itself owns.
Usage: python3 Tools/check_plain_memory_loops.py            (from the repository root)"""
import re, glob, os
excl = set(l.split('#')[0].strip() for l in open('Tools/volatile_memory_sources.txt') if l.split('#')[0].strip())
CALL = re.compile(r'(GH_\w+|VCALL|->\w+\s*\(|\b[A-Za-z_]\w*::\w+\s*\(|\bIO\w+\s*\(|\b[A-Za-z_]\w*\s*\()')
KW = {'if', 'while', 'for', 'switch', 'return', 'sizeof', 'M', 'UInt32', 'UInt16', 'UInt8', 'SInt32', 'SInt16', 'SInt8', 'char'}
def has_call(body):
    return any(m.group(1).rstrip('( ').split('::')[-1] not in KW and not m.group(1).startswith('M<') for m in CALL.finditer(body))
n = 0
for f in sorted(glob.glob('Sources/*.cpp')):
    if os.path.basename(f) in excl: continue
    s = open(f, errors='replace').read()
    for m in re.finditer(r'\}\s*while\s*\(([^;]*)\)\s*;', s):
        cond = m.group(1)
        if 'M<' not in cond and '*' not in cond: continue
        # find the matching "do {"
        depth, i = 0, m.start()
        while i >= 0:
            if s[i] == '}': depth += 1
            elif s[i] == '{':
                depth -= 1
                if depth == 0: break
            i -= 1
        body = s[i:m.start()]
        if not has_call(body):
            n += 1; print('%s:%d: do { ... } while (%s)' % (f, s[:m.start()].count('\n') + 1, cond.strip()[:110]))
    for m in re.finditer(r'\bwhile\s*\(([^;{]*M<[^;{]*)\)\s*\{', s):
        j, depth = m.end(), 1
        while j < len(s) and depth:
            depth += (s[j] == '{') - (s[j] == '}'); j += 1
        if not has_call(s[m.end():j]):
            n += 1; print('%s:%d: while (%s) {...}' % (f, s[:m.start()].count('\n') + 1, m.group(1).strip()[:110]))
print('%d call-free loops with memory in the condition' % n)
