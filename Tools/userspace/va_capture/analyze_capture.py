#!/usr/bin/env python3
"""analyze_capture.py REC.tsv [REC.tsv.mem]   (issue #93)  - summarise a capture made with iokit_record_va.dylib.
Prints: the connections opened per user-client type (0 Surface, 1 GL, 2 2D, 3 DVD), the selector sequence of the DVD connection(s) with counts, the arguments of the set-up calls (set_surface sel 0,
setup_buffers sel 21, write_buffer sel 6, set_macrovision sel 16), every doIDCT-shaped call (structureI_structureO, sel 18, struct >= 0x34 bytes) decoded as sATIDVDIDCTParams
(+0 chromaFlag, +4 fieldFlag, +8 destPlaneIndex, +0xc planeSelector, +0x10 dmaByteCount, +0x14/+0x18/+0x24/+0x28 coefficient addresses; the kext writes +0x1c..+0x30 back), the IOConnectMapMemory
regions, and - with the .mem file - the head of each mapped buffer before the call. Read-only analysis of a text log; touches no hardware."""
import sys, collections, struct, binascii
tsv = sys.argv[1]; mem = sys.argv[2] if len(sys.argv) > 2 else tsv + '.mem'
conn_type = {}; rows = []
for l in open(tsv):
    if l.startswith('#'): continue
    f = l.rstrip('\n').split('\t')
    if len(f) < 9: continue
    rows.append(f)
    if f[3] == 'IOServiceOpen':
        t = f[5].split('=')[1]; conn_type[f[9].split('=')[1]] = int(t)
names = {0: 'Surface', 1: 'GL', 2: '2D', 3: 'DVD'}
print('connections:', {c: names.get(t, t) for c, t in conn_type.items()})
cnt = collections.Counter(); first = {}
for f in rows:
    if f[3] in ('IOServiceOpen', 'IOServiceClose', 'IOConnectAddClient', 'IOConnectMapMemory'): continue
    c = f[4].split('=')[1]; sel = int(f[5].split('=')[1])
    key = (names.get(conn_type.get(c), c), f[3], sel); cnt[key] += 1; first.setdefault(key, f)
print('\ncalls per (context, routine, selector):')
for k, n in sorted(cnt.items(), key=lambda x: (x[0][0], x[0][2])): print('  %-8s %-24s sel %-3d x%d' % (k[0], k[1], k[2], n))
print('\nset-up calls (first occurrence): context / selector / in-hex / out-hex')
for k, f in sorted(first.items(), key=lambda x: int(x[1][0])):
    if k[0] == 'DVD' and k[2] in (0, 21, 6, 16, 1, 2, 3, 4, 5, 7, 8, 9, 10, 11, 12, 13, 15, 17, 19, 20): print('  seq %s DVD sel %d rc=%s in=%s out=%s' % (f[0], k[2], f[8], f[9][:80], f[10][:80]))
print('\nmapped memory:')
for f in rows:
    if f[3] == 'IOConnectMapMemory': print('  connect %s %s %s %s %s' % (f[4], f[5], f[9], f[10], 'rc=' + f[8]))
print('\ndoIDCT-shaped calls (structureI_structureO, sel 18, struct >= 0x34):')
n = 0
for f in rows:
    if f[3] == 'structureI_structureO' and f[5] == 'sel=18' and int(f[6].split('=')[1]) >= 0x34:
        b = binascii.unhexlify(f[9].replace('...TRUNC', '')); n += 1
        w = struct.unpack('>%dI' % (len(b) // 4), b[:len(b) // 4 * 4])
        print('  #%d seq %s rc=%s words=%s' % (n, f[0], f[8], ' '.join('%08x' % x for x in w[:14])))
        if n <= 3: print('     chroma=%d field=%d destPlane=%d planeSel=%d dmaByteCount=0x%x addr14=0x%x addr18=0x%x' % (w[0], w[1], w[2], w[3], w[4], w[5], w[6]))
print('  total doIDCT-shaped calls: %d' % n)
try:
    m = open(mem).read().splitlines(); print('\n.mem: %d lines (CALL/MAP blocks); first MAP heads:' % len(m))
    for l in m[:6]: print('  ' + l[:150] + ('...' if len(l) > 150 else ''))
except IOError: print('\n(no .mem file: no doIDCT-shaped call was made)')
