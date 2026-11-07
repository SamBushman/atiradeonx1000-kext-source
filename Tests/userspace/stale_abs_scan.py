#!/usr/bin/env python3
"""stale_abs_scan.py REBUILT_IMAGE STOCK_IMAGE  (issue #227) - static scan of a rebuilt userspace image for absolute addresses of the STOCK image.

A rebuilt image that still holds the stock image's absolute address (a pointer the link left as a raw number, an address built by `lis`) works only while the stock image
happens to be mapped at that address - exactly what the side-by-side tests (stock and rebuilt in one process) provide - and crashes in a process where the address is unmapped
(Godot: libGLProgrammability's token table, `HashString` reading 0x97c23e08). The scan reports
  data  every word-aligned 4-byte big-endian value of the rebuilt image's data sections (misaligned windows are listed as notes only) that lies inside a stock
        segment and outside every rebuilt segment;
  code  every `lis rD,imm` (addis rD,0,imm) whose pair (ori / addi / a load or store displacement on rD) builds a value inside a stock segment (or within 64K of one: the base of a later `d(rX)` access) and outside the rebuilt image; a `lis`
        with no resolvable pair is reported when its high half (or high half + 1, the carry of a negative low half) lies in a stock segment.
The scans can only decide when the two images occupy different address ranges: libGL and libGLProgrammability (stock dylibs prebound at 0x9xxxxxxx / 0xaxxxxxxx; the rebuilt ones at low addresses).
GA / VA / GLDriver are bundles / plug-ins at address 0 in both images - the ranges overlap and the scan prints `RANGES OVERLAP: not decidable` (their protection is the link-time
check of link_corpus.py: every relocated data word must be emitted as a relocation). Exit 0 = clean (or not decidable), 1 = stale addresses found."""
import sys, os, struct
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'Tools', 'userspace'))
import machoutil
reb = machoutil.load(sys.argv[1]); stk = machoutil.load(sys.argv[2])
def ranges(m): return [(s['vmaddr'], s['vmaddr'] + s['vmsize']) for s in m.segs if s['vmsize'] and s['name'] != '__PAGEZERO']
SR, RR = ranges(stk), ranges(reb)
def inside(v, R): return any(a <= v < b for a, b in R)
MARGIN = 0x10000   # a base built by lis/addi is used with a 16-bit signed displacement afterwards: a value within 64K of a stock segment can reach into it
def near(v, R): return any(a - MARGIN <= v < b + MARGIN for a, b in R)
OVERLAP = any(a < d and c < b for a, b in SR for c, d in RR)
if OVERLAP:
    print('RANGES OVERLAP: not decidable (%s vs %s)' % (SR, RR))
bad = 0
for s in reb.secs:
    t = s['flags'] & 0xff
    if not s['size'] or t in (1, 0xc):
        continue
    blob = reb.d[s['off']:s['off'] + s['size']]
    code = s['seg'] == '__TEXT' and s['name'] in ('__text', '__textcoal_nt', '__symbol_stub1', '__picsymbol_stub1')
    if code:
        if OVERLAP:
            continue
        for i in range(0, len(blob) - 3, 4):
            w = struct.unpack('>I', blob[i:i + 4])[0]
            if (w >> 26) == 15 and ((w >> 16) & 31) == 0:      # addis rD,0,imm = lis rD,imm
                hi = w & 0xffff; rD = (w >> 21) & 31
                # the value the pair builds: ori rA,rD,lo / addi rA,rD,lo / a load or store d(rD) within the next few instructions that still use rD
                v = None
                for k in (1, 2, 3, 4, 5, 6):
                    j = i + 4 * k
                    if j + 4 > len(blob): break
                    n = struct.unpack('>I', blob[j:j + 4])[0]; op = n >> 26
                    if ((n >> 16) & 31) == rD and op in (24, 14, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 48, 49, 50, 51, 52, 53, 54, 55):
                        lo = n & 0xffff
                        v = ((hi << 16) | lo) if op == 24 else (((hi << 16) + (lo - 0x10000 if lo & 0x8000 else lo)) & 0xffffffff)
                        break
                    if ((n >> 21) & 31) == rD and op in (15, 14, 32, 34, 40, 48, 50, 24, 31) and not ((n >> 16) & 31) == rD: break     # rD overwritten
                if v is not None:
                    if near(v, SR) and not near(v, RR):
                        bad += 1
                        if bad <= 4000: print('code  %s,%s +0x%x: lis r%d,0x%04x -> 0x%08x (%s a stock segment)' % (s['seg'], s['name'], i, rD, hi, v, 'inside' if inside(v, SR) else 'within 64K of'))
                elif any((a >> 16) <= hi + d <= ((b - 1) >> 16) for a, b in SR for d in (0, 1)) and not any((a >> 16) <= hi <= ((b - 1) >> 16) for a, b in RR):
                    bad += 1
                    if bad <= 4000: print('code  %s,%s +0x%x: lis r%d,0x%04x (value not resolved; high half in/next to a stock segment)' % (s['seg'], s['name'], i, rD, hi))
    else:
        if OVERLAP or t == 2 or s['name'] in ('__cstring',):
            continue
        for i in range(0, len(blob) - 3):
            v = struct.unpack('>I', blob[i:i + 4])[0]
            if inside(v, SR) and not inside(v, RR):
                if i % 4:
                    # a window straddling two aligned words: halfword / byte table data (glprog _strStandardUniforms: `xx xx 00 18` pairs) - a pointer is word-aligned.
                    # link_corpus.py guarantees no relocated word is lost (every relocation of the stock image is emitted as one), which is what a misaligned scan was for
                    print('note  %s,%s +0x%x (addr 0x%x): 0x%08x misaligned window, not counted' % (s['seg'], s['name'], i, s['addr'] + i, v))
                    continue
                bad += 1
                if bad <= 4000: print('data  %s,%s +0x%x (addr 0x%x): 0x%08x' % (s['seg'], s['name'], i, s['addr'] + i, v))
print('%s: %d stale absolute stock address(es) found' % (sys.argv[1], bad))
sys.exit(1 if bad else 0)
