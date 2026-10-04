#!/usr/bin/env python3
"""decode_px.py - issue #140: reconstruct the engine's 16x16 luma macroblock from a read-back diff (before/after dumps of the 64x48 window slot) and compare with the oracle.
Established empirically (findings 9f): the destination (slot 0 of the window surface) is tiled, so the engine's 16 linear luma rows (16 bytes each) appear at the (memory row, byte x) positions below
in the de-tiled GL read (memory row = 47 - GL row), and each 32-bit word is byte-reversed. Usage: decode_px.py before.bin after.bin [vector-index]"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
import idct_stream as S
W, H = 64, 48; RB = W * 4
# luma row r -> (memory row, byte x of its 16-byte group)
TILE = {0: (0, 0), 1: (4, 0), 2: (4, 64), 3: (0, 64), 4: (8, 32), 5: (12, 32), 6: (12, 96), 7: (8, 96),
        8: (8, 160), 9: (12, 160), 10: (12, 224), 11: (8, 224), 12: (0, 128), 13: (4, 128), 14: (4, 192), 15: (0, 192)}
def swap32(b): return [b[i + 3 - j] for i in range(0, len(b), 4) for j in range(4)]
def luma(buf):
    rows = []
    for r in range(16):
        m, x = TILE[r]; gl = 47 - m
        rows.append(swap32(list(buf[gl * RB + x: gl * RB + x + 16])))
    return rows
if __name__ == '__main__':
    before = open(sys.argv[1], 'rb').read(); after = open(sys.argv[2], 'rb').read()
    # the changed positions must be exactly the 16 mapped groups
    changed = set((47 - gy, x // 16 * 16) for gy in range(H) for x in range(RB) if before[gy * RB + x] != after[gy * RB + x])
    print('changed groups == mapped groups:', changed == set(TILE.values()), '(%d changed, %d mapped)' % (len(changed), len(TILE)))
    Y = luma(after)
    for r in range(16): print('row %2d:' % r, ' '.join('%3d' % v for v in Y[r]))
    if len(sys.argv) > 3:
        sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
        import gen_ava_vectors as G
        name, ptype, alt, dst, fwd, mbs = G.PICTURES[int(sys.argv[3])]
        blocks = mbs[0][1]; fld = mbs[0][3]
        o, _, _ = S.mb_oracle(blocks, fld, alt, intra=False)     # raw IDCT without clipping
        worst = 0; hist = {}
        for r in range(16):
            for x in range(16):
                # uncoded blocks are written as 0 (observed), coded blocks as IDCT + 128 clipped
                blk = (r // 8) * 2 + (x // 8)
                exp = max(0, min(255, o[r][x] + 128)) if blocks.get(blk) else 0
                d = Y[r][x] - exp; hist[d] = hist.get(d, 0) + 1; worst = max(worst, abs(d))
        print('oracle (coded blocks: IDCT + 128 clipped; uncoded: 0) vs hardware: worst |diff| = %d; diff histogram %s' % (worst, sorted(hist.items())))
