#!/usr/bin/env python3
"""extract_slices.py FAT_OR_THIN_BINARY OUTDIR - write <name>.ppc / <name>.i386 slices of a Mach-O (the corpora and Ghidra work on single-arch slices).
Input files are the vendor binaries in ATI-X1900-Decomp/tiger-hd-pull (not part of this repo)."""
import sys, struct, os
src, out = sys.argv[1:3]; os.makedirs(out, exist_ok=True); d = open(src, 'rb').read(); base = os.path.basename(src)
if struct.unpack('>I', d[:4])[0] == 0xcafebabe:
    for i in range(struct.unpack('>I', d[4:8])[0]):
        cpu, sub, off, size, al = struct.unpack('>5I', d[8 + 20 * i:28 + 20 * i])
        name = {18: 'ppc', 7: 'i386'}.get(cpu, str(cpu)); open(os.path.join(out, base + '.' + name), 'wb').write(d[off:off + size])
else:
    open(os.path.join(out, base), 'wb').write(d)
