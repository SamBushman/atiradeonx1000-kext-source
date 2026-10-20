#!/usr/bin/env python3
"""negative_control.py REBUILT_IMAGE [COINCIDENCE_IMAGE] - the comparison of the memory a function leaves behind must still catch a real difference.

difftest names a stored word that looks like an address into the image (so two layouts compare) and calls a byte a difference only when the two sides' RAW bytes also differ.
This checks the rule on `ATIR500GLContext::WriteVertexArrayOffset` (it stores a command token 0x1xxxx per loop pass), with `plain_words` forced off so words are canonicalised:
  1. UNCHANGED: REBUILT_IMAGE as built -> must PASS;
  2. MUTATED: one `oris` of the rebuilt function patched to store a different constant (a real difference) -> must FAIL with "memory left behind differs";
  3. COINCIDENCE (optional, needs an image whose layout makes a token equal an address inside it, e.g. ~/g5logs/R1/b1.bin of the Oct 20 session): must PASS with the raw-bytes rule
     and FAIL with DT_CANON_ONLY=1 (the old rule) - proving the rule removes only the layout-coincidence false positive.
Needs $STOCK_KEXT (and unicorn on PYTHONPATH). Run from the repository root; exit 0 = the checks hold."""
import sys, os, struct, importlib
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__))); sys.path.insert(0, 'Tests/difftest')
import difftest as d

img_path = sys.argv[1]; coincidence = sys.argv[2] if len(sys.argv) > 2 else None
stock = d.Image(os.environ['STOCK_KEXT'], 'stock')
reg = d.StubRegistry()
case = next(c for c in d.load_cases('Tests/difftest/all_classes_cases.py') if 'WriteVertexArrayOffset' in c.name)
case.plain_words = False


def verdict(image_path, canon_only=False):
    if canon_only: os.environ['DT_CANON_ONLY'] = '1'
    else: os.environ.pop('DT_CANON_ONLY', None)
    v, lines, rep = d.evaluate(case, stock, d.Image(image_path, 'rebuilt'), reg, False, False, False)
    return v, ' '.join(lines)


img = d.Image(img_path, 'rebuilt')
sym = next(n for n in img.funcs if 'WriteVertexArrayOffset' in n); entry = img.funcs[sym]
text = next(s for s in img.m.secs if s['name'] == '__text')
raw = bytearray(open(img_path, 'rb').read()); patched = None
for a in range(entry, entry + 0x100, 4):
    o = text['off'] + a - text['addr']; w = struct.unpack('>I', raw[o:o + 4])[0]
    if w >> 26 == 25:                                  # oris rA,rS,UI: the high half-word of the token
        w2 = (w & 0xffff0000) | (((w & 0xffff) + 2) & 0xffff); raw[o:o + 4] = struct.pack('>I', w2); patched = (a - entry, w, w2); break
assert patched, 'no oris in %s' % sym
mut = '/tmp/negative_control_mutated.bin'; open(mut, 'wb').write(raw)
print('mutation: %s +0x%x  %08x -> %08x' % (sym, *patched))

ok = True
v, t = verdict(img_path); print('UNCHANGED     ->', v); ok &= v == 'PASS'
v, t = verdict(mut); print('MUTATED       ->', v, '(memory left behind differs)' if 'memory left behind differs' in t else ''); ok &= v == 'FAIL' and 'memory left behind differs' in t
if coincidence and os.path.exists(coincidence):
    v1, _ = verdict(coincidence); v2, _ = verdict(coincidence, canon_only=True)
    print('COINCIDENCE   -> raw-bytes rule %s, canonical-only rule %s' % (v1, v2)); ok &= (v1 == 'PASS' and v2 == 'FAIL')
else:
    print('COINCIDENCE   -> skipped (no coincidence image given)')
print('negative control', 'HOLDS' if ok else 'BROKEN')
sys.exit(0 if ok else 1)
