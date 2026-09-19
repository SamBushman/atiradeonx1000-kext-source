#!/usr/bin/env python3
"""emit_data.py KEXT_BIN NAME ADDR SIZE [static|extern] [words|doubles] - emit a C++ array holding SIZE bytes of the stock
PPC image at ADDR as big-endian 32-bit words (default) or doubles."""
import struct, sys, subprocess
sys.argv[0]
K, name, addr, size = sys.argv[1], sys.argv[2], int(sys.argv[3], 16), int(sys.argv[4], 0)
linkage = sys.argv[5] if len(sys.argv) > 5 else 'static'
kind = sys.argv[6] if len(sys.argv) > 6 else 'words'
out = subprocess.run([sys.executable, __file__.rsplit('/', 1)[0] + '/read_mem.py', K, '%x' % addr, str(size), 'w' if kind == 'words' else 'd'],
                     capture_output=True, text=True).stdout.splitlines()[1:]
if kind == 'words':
    ws = [int(l.split(': ')[1], 16) for l in out]
    lines = []
    for i in range(0, len(ws), 8):
        lines.append('    ' + ', '.join('0x%08x' % w for w in ws[i:i+8]) + ',')
    decl = ('static ' if linkage == 'static' else 'extern "C" ') + 'const UInt32 %s[%d] = { /* %d bytes @ 0x%x */\n' % (name, len(ws), size, addr)
    print(decl + '\n'.join(lines) + '\n};')
else:
    vs = [l.split(': ')[1] for l in out]
    lines = ['    ' + ', '.join(vs[i:i+4]) + ',' for i in range(0, len(vs), 4)]
    decl = ('static ' if linkage == 'static' else 'extern "C" ') + 'const double %s[%d] = { /* %d bytes @ 0x%x */\n' % (name, len(vs), size, addr)
    print(decl + '\n'.join(lines) + '\n};')
