#!/usr/bin/env python3
"""compare_guard.py - issue #140 rung 2.3: compare a guard capture (iokit_guard_va.dylib log + .mem snapshots from ava_drive) with the independent expectations in ava_expected.json
(built by gen_ava_vectors.py from Tools/idct_stream.py, i.e. from findings sections 5-7 only). Prints one line per check; exit 1 if anything differs.
Usage: compare_guard.py run.tsv [run.tsv.mem] [ava_expected.json]"""
import sys, os, json, re, struct

args = [x for x in sys.argv[1:] if not x.startswith('--')]; sel = [int(x) for x in next((a.split('=')[1] for a in sys.argv if a.startswith('--pictures=')), '').split(',') if x]
tsv = args[0]; mem = args[1] if len(args) > 1 else tsv + '.mem'
exp = json.load(open(args[2] if len(args) > 2 else os.path.join(os.path.dirname(os.path.abspath(__file__)), 'ava_expected.json')))

calls = []                                   # (seq, params words)
for l in open(tsv):
    if 'SWALLOW(doIDCT)' in l or 'ABOUT-TO-CALL(doIDCT' in l:
        f = l.rstrip('\n').split('\t'); seq = int(f[0]); m = re.search(r'params=([0-9a-f]+)', l)
        calls.append((seq, struct.unpack('>%dI' % (len(m.group(1)) // 8), bytes.fromhex(m.group(1)))))
snaps = {}                                   # seq -> {type: bytes}
cur = None
for l in open(mem):
    if l.startswith('SNAP'):
        cur = int(re.search(r'seq=(\d+)', l).group(1)); snaps[cur] = {}
    elif l.startswith('MAP') and cur is not None:
        t = int(re.search(r'type=(\d+)', l).group(1)); snaps[cur][t] = bytes.fromhex(l.split()[-1])

want = []
for pi_, p in enumerate(exp['pictures']):
    if sel and pi_ not in sel: continue
    for e in p['expected_doidct']:
        want.append((p, e))
bad = 0
def chk(name, ok, detail=''):
    global bad
    print('  %-58s %s %s' % (name, 'ok' if ok else 'MISMATCH', detail)); bad += (not ok)
print('doIDCT calls captured: %d, expected: %d' % (len(calls), len(want)))
chk('call count', len(calls) == len(want))
for n, ((seq, w), (pic, e)) in enumerate(zip(calls, want)):
    print('call %d (seq %d) - picture "%s", stream %d' % (n, seq, pic['name'], e['stream']))
    chk('fieldPictureFlag=0 bottomFieldFlag=0 (frame picture)', w[0] == 0 and w[1] == 0, '(%d,%d)' % (w[0], w[1]))
    chk('destPlaneIndex = destination surface %d' % pic['dst'], w[2] == pic['dst'], '(%d)' % w[2])
    chk('planeSelector = stream %d' % e['stream'], w[3] == e['stream'], '(%d)' % w[3])
    chk('dmaDwordCount = %d' % e['dwords'], w[4] == e['dwords'], '(%d)' % w[4])
    chk('engineFlagWord = %s' % e['flag'], '%08x' % w[5] == e['flag'], '(%08x)' % w[5])
    chk('planeModeWord = %s' % e['mode'], '%08x' % w[6] == e['mode'], '(%08x)' % w[6])
    chk('dimensionsHeightWidth = (48<<16)|64', w[9] == (exp['height'] << 16 | exp['width']), '(%08x)' % w[9])
    junk = w[7:9] + w[10:14]
    print('  (kernel-computed fields +0x1c/+0x20/+0x28+ as sent by the client, i.e. uninitialised: %s)' % ' '.join('%08x' % x for x in junk))
    s = snaps.get(seq, {}).get(4 if e['stream'] == 0 else 5)
    if s is None: chk('stream buffer snapshot present', False); continue
    hdr = struct.unpack('>8I', s[:0x20])
    data = struct.unpack('>%dI' % e['dwords'], s[0x20:0x20 + 4 * e['dwords']])
    expect = [int(x, 16) for x in (pic['stream0'] if e['stream'] == 0 else pic['stream1'])]
    chk('stream bytes == predicted packets (%d dwords)' % e['dwords'], list(data) == expect)
    if list(data) != expect:
        print('     got      ', ' '.join('%08x' % x for x in data)); print('     expected ', ' '.join('%08x' % x for x in expect))
    print('  (buffer header: %s)' % ' '.join('%08x' % x for x in hdr))
print('RESULT:', 'every parameter field and every stream dword matches the independent prediction' if not bad else '%d mismatch(es)' % bad)
sys.exit(1 if bad else 0)
