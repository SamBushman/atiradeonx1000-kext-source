#!/usr/bin/env python3
"""pngpix.py FILE.png X Y [W H]  - mean RGB of the WxH box at (X,Y) (default 1x1) of an 8-bit RGB/RGBA PNG; no PIL needed (screenshot checks on the dev machine)."""
import sys, zlib, struct
def load(path):
    d = open(path, 'rb').read(); p = 8; idat = b''
    while p < len(d):
        n, t = struct.unpack('>I4s', d[p:p+8]); c = d[p+8:p+8+n]; p += 12 + n
        if t == b'IHDR': w, h, bd, ct = struct.unpack('>IIBB', c[:10])
        elif t == b'IDAT': idat += c
    bpp = {2: 3, 6: 4}[ct]; raw = zlib.decompress(idat); st = w * bpp; rows = []; prev = bytearray(st); o = 0
    for _ in range(h):
        f = raw[o]; line = bytearray(raw[o+1:o+1+st]); o += 1 + st
        for i in range(st):
            a = line[i-bpp] if i >= bpp else 0; b = prev[i]; cc = prev[i-bpp] if i >= bpp else 0
            if f == 1: line[i] = (line[i] + a) & 255
            elif f == 2: line[i] = (line[i] + b) & 255
            elif f == 3: line[i] = (line[i] + (a + b) // 2) & 255
            elif f == 4:
                pa, pb, pc = abs(b - cc), abs(a - cc), abs(a + b - 2*cc)
                line[i] = (line[i] + (a if pa <= pb and pa <= pc else b if pb <= pc else cc)) & 255
        rows.append(line); prev = line
    return w, h, bpp, rows
if __name__ == '__main__':
    w, h, bpp, rows = load(sys.argv[1]); x, y = int(sys.argv[2]), int(sys.argv[3]); bw = int(sys.argv[4]) if len(sys.argv) > 4 else 1; bh = int(sys.argv[5]) if len(sys.argv) > 5 else 1
    px = [rows[j][i*bpp:i*bpp+3] for j in range(y, y+bh) for i in range(x, x+bw)]
    print(w, h, tuple(sum(p[k] for p in px) // len(px) for k in range(3)))
