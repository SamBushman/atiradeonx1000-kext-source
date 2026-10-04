#!/usr/bin/env python3
"""idct_stream.py - issue #140 rung 1: encoder, decoder and software oracle for the DVD IDCT engine's macroblock stream, exactly as derived in
Tests/idct_engine_findings.md (sections 5-7) from the VA driver (client) and Apple's AVA software renderer (producer FUN_00054070, consumer FUN_0000aac0).

  coefficient dword  = level(int16) << 16 | run(15 bit) << 1 | last          (idx = prev + run; prev = idx + 1; block[scan[idx]] = level; last = bit 0)
  macroblock packet  = dword0: field_dct << 31 | alt_scan << 25 | CBP << 6   (Y0 = bit 11 ... Y3 = bit 8, Cb = bit 7, Cr = bit 6)
                       dword1: (mb_addr / mb_width) << 20 | (mb_addr % mb_width) << 4
                       then the coded blocks' coefficient dwords, in order Y0 Y1 Y2 Y3 Cb Cr
  oracle             = reference (double precision) MPEG-2 8x8 IDCT of the dequantised levels, rounded; stream 0 (intra) is clipped to 0..255, stream 1 (residual) is left signed.
The oracle is an expectation to compare hardware output against (the hardware's own rounding may differ by +-1); it is NOT a claim about the hardware.

Usage: idct_stream.py selftest | vectors     (selftest: internal consistency + known values; vectors: the rung 3/4 test packets as hex dwords)"""
import sys, math

ZIGZAG = [0, 1, 8, 16, 9, 2, 3, 10, 17, 24, 32, 25, 18, 11, 4, 5, 12, 19, 26, 33, 40, 48, 41, 34, 27, 20, 13, 6, 7, 14, 21, 28, 35, 42, 49, 56, 57, 50, 43, 36, 29, 22, 15, 23, 30, 37, 44, 51, 58, 59, 52, 45, 38, 31, 39, 46, 53, 60, 61, 54, 47, 55, 62, 63]
ALTERNATE = [0, 8, 16, 24, 1, 9, 2, 10, 17, 25, 32, 40, 48, 56, 57, 49, 41, 33, 26, 18, 3, 11, 4, 12, 19, 27, 34, 42, 50, 58, 35, 43, 51, 59, 20, 28, 5, 13, 6, 14, 21, 29, 36, 44, 52, 60, 37, 45, 53, 61, 22, 30, 7, 15, 23, 31, 38, 46, 54, 62, 39, 47, 55, 63]
CBP_BIT = [11, 10, 9, 8, 7, 6]            # Y0 Y1 Y2 Y3 Cb Cr -> bit in dword0


def pack_coef(level, run, last):
    assert -32768 <= level <= 32767 and 0 <= run < 0x8000
    return ((level & 0xffff) << 16) | (run << 1) | (1 if last else 0)


def unpack_coef(d):
    lv = d >> 16
    return (lv - 0x10000 if lv & 0x8000 else lv), (d >> 1) & 0x7fff, d & 1


def block_dwords(coefs):
    """coefs: list of (scan_index, level), scan_index ascending and unique, level != 0  ->  dwords, last coefficient flagged"""
    out, prev = [], 0
    for n, (idx, lv) in enumerate(coefs):
        assert idx >= prev and 0 <= idx < 64 and lv != 0
        out.append(pack_coef(lv, idx - prev, n == len(coefs) - 1)); prev = idx + 1
    return out


def mb_packet(mb_addr, mb_width, blocks, field_dct=0, alt_scan=0):
    """blocks: dict block_number(0..5) -> list of (scan_index, level); empty/missing = not coded. Returns the list of dwords (empty if no block is coded: such MBs emit nothing)."""
    coded = [b for b in range(6) if blocks.get(b)]
    if not coded: return []
    cbp = 0
    for b in coded: cbp |= 1 << CBP_BIT[b]
    d0 = (0x80000000 if field_dct else 0) | ((alt_scan & 1) << 25) | cbp
    d1 = ((mb_addr // mb_width) << 20) | ((mb_addr % mb_width) << 4)
    pkt = [d0, d1]
    for b in coded: pkt += block_dwords(blocks[b])
    return pkt


def parse_stream(words, mb_width):
    """inverse of mb_packet over a whole stream; block ends are found with the last bit (the packet has no counts). Returns [(mb_addr, field_dct, alt_scan, {blk: [(idx, level)]})]"""
    out, i = [], 0
    while i < len(words):
        d0, d1 = words[i], words[i + 1]; i += 2
        cbp = [b for b in range(6) if d0 >> CBP_BIT[b] & 1]
        mb = {}
        for b in cbp:
            coefs, prev = [], 0
            while True:
                lv, run, last = unpack_coef(words[i]); i += 1
                idx = prev + run; prev = idx + 1
                coefs.append((idx, lv))
                if last: break
            mb[b] = coefs
        out.append(((d1 >> 20) * mb_width + ((d1 >> 4) & 0xff), d0 >> 31, d0 >> 25 & 1, mb))
    return out


def idct8x8(F):
    """reference double-precision 8x8 inverse DCT, F[v][u] -> f[y][x]"""
    c = lambda k: math.sqrt(0.5) if k == 0 else 1.0
    return [[sum(c(u) * c(v) * F[v][u] * math.cos((2 * x + 1) * u * math.pi / 16) * math.cos((2 * y + 1) * v * math.pi / 16) for v in range(8) for u in range(8)) / 4 for x in range(8)] for y in range(8)]


def block_pixels(coefs, alt_scan):
    scan = ALTERNATE if alt_scan else ZIGZAG
    F = [[0] * 8 for _ in range(8)]
    for idx, lv in coefs:
        pos = scan[idx]; F[pos // 8][pos % 8] = lv
    return [[int(math.floor(v + 0.5)) for v in row] for row in idct8x8(F)]


def mb_oracle(blocks, field_dct=0, alt_scan=0, intra=True):
    """expected 16x16 luma + two 8x8 chroma planes for one macroblock (missing blocks are zero)"""
    px = {b: block_pixels(blocks.get(b, []), alt_scan) for b in range(6)}
    clip = (lambda v: max(0, min(255, v))) if intra else (lambda v: v)
    Y = [[0] * 16 for _ in range(16)]
    for b in range(4):
        for y in range(8):
            for x in range(8):
                if field_dct: row = (y * 2) + (b >> 1)           # blocks 0,1 = even lines, 2,3 = odd lines
                else: row = y + 8 * (b >> 1)
                Y[row][x + 8 * (b & 1)] = clip(px[b][y][x])
    return Y, [[clip(v) for v in r] for r in px[4]], [[clip(v) for v in r] for r in px[5]]


def selftest():
    bad = 0
    def check(name, ok):
        nonlocal bad
        print('%-60s %s' % (name, 'ok' if ok else 'FAIL')); bad += (not ok)
    check('scan tables are permutations', sorted(ZIGZAG) == list(range(64)) and sorted(ALTERNATE) == list(range(64)))
    for lv, run, last in ((1, 0, 1), (-1, 0, 0), (2047, 63, 1), (-2048, 5, 0), (-32768, 0x7fff, 1)):
        check('pack/unpack %d,%d,%d' % (lv, run, last), unpack_coef(pack_coef(lv, run, last)) == (lv, run, last))
    check('DC-only L=64 -> every pixel 8', all(v == 8 for r in block_pixels([(0, 64)], 0) for v in r))
    check('DC-only L=-64 -> every pixel -8', all(v == -8 for r in block_pixels([(0, -64)], 1) for v in r))
    check('DC = 1024 -> 128 everywhere (mid grey)', all(v == 128 for r in block_pixels([(0, 1024)], 0) for v in r))
    # scan index 1 is horizontal frequency in zigzag, vertical frequency in alternate scan: the pixel pattern tells the two apart
    h = block_pixels([(1, 160)], 0); v = block_pixels([(1, 160)], 1)
    check('zigzag idx 1 varies along x only', all(h[y][x] == h[0][x] for y in range(8) for x in range(8)) and h[0][0] != h[0][7])
    check('alternate idx 1 varies along y only', all(v[y][x] == v[y][0] for y in range(8) for x in range(8)) and v[0][0] != v[7][0])
    blocks = {0: [(0, 800), (3, -40)], 3: [(0, 64)], 5: [(2, 10), (9, -7), (40, 3)]}
    for field, alt in ((0, 0), (1, 1)):
        pkt = mb_packet(37, 45, blocks, field, alt)
        back = parse_stream(pkt, 45)
        check('packet round trip field=%d alt=%d (%d dwords)' % (field, alt, len(pkt)), back == [(37, field, alt, blocks)])
    check('uncoded MB emits nothing', mb_packet(0, 45, {}) == [])
    two = mb_packet(0, 4, {0: [(0, 64)]}) + mb_packet(5, 4, {4: [(0, 8)], 5: [(0, -8)]})
    check('two MBs in one stream are split by the last bits', [m[0] for m in parse_stream(two, 4)] == [0, 5])
    Y, cb, cr = mb_oracle({0: [(0, 1024)], 3: [(0, 512)]})
    check('oracle places blocks 0 and 3 (frame DCT)', Y[0][0] == 128 and Y[7][7] == 128 and Y[8][8] == 64 and Y[15][15] == 64 and Y[0][8] == 0 and Y[8][0] == 0)
    Y, _, _ = mb_oracle({0: [(0, 1024)], 2: [(0, 512)]}, field_dct=1)
    check('oracle interleaves lines for field DCT', Y[0][0] == 128 and Y[2][0] == 128 and Y[1][0] == 64 and Y[3][0] == 64)
    print('selftest:', 'all ok' if not bad else '%d FAILED' % bad); return bad


# rung 3/4 test vectors: (name, mb_addr, mb_width, blocks, field_dct, alt_scan, stream)
VECTORS = [
    ('V1 DC only, Y0, L=1024 (expect Y0 block = 128)', 0, 1, {0: [(0, 1024)]}, 0, 0, 0),
    ('V2 DC + run, Y0 (tests run/last)', 0, 1, {0: [(0, 1024), (3, 160)]}, 0, 0, 0),
    ('V3a scan idx 1, zigzag (horizontal ramp expected)', 0, 1, {0: [(0, 1024), (1, 160)]}, 0, 0, 0),
    ('V3b scan idx 1, alternate (vertical ramp expected)', 0, 1, {0: [(0, 1024), (1, 160)]}, 0, 1, 0),
    ('V4 all six blocks, distinct DCs (block order / chroma)', 0, 1, {0: [(0, 256)], 1: [(0, 512)], 2: [(0, 768)], 3: [(0, 1024)], 4: [(0, 384)], 5: [(0, 640)]}, 0, 0, 0),
    ('V5 stream 1 residual, Y0 DC = -64 (expect -8 / sign handling)', 0, 1, {0: [(0, -64)]}, 0, 0, 1),
    ('V6 MB at column 1 of a 2-MB-wide picture', 1, 2, {0: [(0, 1024)]}, 0, 0, 0),
]


def vectors():
    for name, addr, w, blocks, fld, alt, stream in VECTORS:
        pkt = mb_packet(addr, w, blocks, fld, alt)
        Y, cb, cr = mb_oracle(blocks, fld, alt, intra=(stream == 0))
        print('%s\n  stream %d, %d dwords: %s\n  oracle Y0 row0: %s | Y0 col0: %s | Cb[0][0]=%d Cr[0][0]=%d' % (
            name, stream, len(pkt), ' '.join('%08x' % d for d in pkt), Y[0][:8], [Y[r][0] for r in range(8)], cb[0][0], cr[0][0]))


if __name__ == '__main__':
    cmd = sys.argv[1] if len(sys.argv) > 1 else 'selftest'
    sys.exit(selftest() if cmd == 'selftest' else vectors() or 0)
