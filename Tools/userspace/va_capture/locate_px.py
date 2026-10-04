#!/usr/bin/env python3
"""locate_px.py before.bin after.bin picture_index - issue #140: for a one-macroblock picture, find each changed 16-byte group in the 64x48 slot-0 read-back, match its (word-reversed) bytes to the oracle luma row it
carries, and print luma row -> (memory row, pixel x). Used to calibrate where a macroblock at another position lands in the tiled window surface."""
import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__))); sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
import idct_stream as S, gen_ava_vectors as G, decode_px as D
W, H = 64, 48; RB = W * 4
b = open(sys.argv[1], 'rb').read(); a = open(sys.argv[2], 'rb').read(); name, pt, alt, dst, fwd, mbs = G.PICTURES[int(sys.argv[3])]
addr, blocks, motion, fld = mbs[0]
o, _, _ = S.mb_oracle(blocks, fld, alt, intra=False)
exp = [[max(0, min(255, o[r][x] + 128)) if blocks.get((r // 8) * 2 + x // 8) else 0 for x in range(16)] for r in range(16)]
groups = {}
for gy in range(H):
    for g in range(RB // 16):
        if b[gy * RB + g * 16:gy * RB + g * 16 + 16] != a[gy * RB + g * 16:gy * RB + g * 16 + 16]:
            groups[(47 - gy, g * 16)] = D.swap32(list(a[gy * RB + g * 16:gy * RB + g * 16 + 16]))
print('changed groups:', len(groups))
res = {}
for (m, x), vals in sorted(groups.items()):
    best = min(range(16), key=lambda r: sum(abs(vals[i] - exp[r][i]) for i in range(16)))
    err = sum(abs(vals[i] - exp[best][i]) for i in range(16))
    res.setdefault(best, []).append((m, x // 4, err))
for r in range(16): print('luma row %2d -> %s' % (r, res.get(r)))
