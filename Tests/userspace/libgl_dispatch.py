#!/usr/bin/env python3
"""libgl_dispatch.py STOCK_LIBGL REBUILT_LIBGL - issue #65 criterion 2. Runs libgl_dispatch_test (on the G5, over ssh) on the stock and the rebuilt libGL with two sets of sentinel arguments, and
compares them. Every function is called with its REAL prototype (from the GL headers, libgl_dispatch_gen_calls.py) and sentinel arguments that depend on the seed; a position of the stock's
record whose value differs between the two seeds carries an argument. Every live position of every function must carry the same value (same sentinel) in the rebuilt image, at the same dispatch slot;
the positions the stock does not preserve are compared only for information (they are scratch)."""
import sys, subprocess, re, json, os
G = '/Volumes/Test HD/claude_bugwf'
stock, reb = sys.argv[1:3]
PROTO = json.load(open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'dsp_protos.json')))    # written by libgl_dispatch_gen_calls.py: parameter classes i / p / f / d per function
def run(img, seed):
    return subprocess.run(['ssh', 'G5', 'cd "%s/tests" && ./libgl_dispatch_test "%s" x %d 2>&1' % (G, img, seed)], capture_output=True, text=True).stdout
def parse(t):
    out = {}; cur = None
    for l in t.split('\n'):
        m = re.match(r'(\w+): (\d+) record', l)
        if m: cur = m.group(1); out[cur] = []; continue
        m = re.match(r'\s+slot (\d+) gpr (.*) fpr (.*) stack (.*)$', l)
        if m and cur: out[cur].append((int(m.group(1)), m.group(2).split(), m.group(3).split(), m.group(4).split())); continue
        m = re.match(r'(\w+): (SIGNAL|MISSING)(.*)', l)
        if m: out[m.group(1)] = m.group(2)
    return out
S0, S1, R0, R1 = (parse(run(i, s)) for i, s in ((stock, 0), (stock, 1), (reb, 0), (reb, 1)))
def is_sentinel_pair(kind, v0, v1):
    """(v0, v1) = the stock's values with seed 0 and seed 1: do they fit ONE of the generated sentinels (same parameter index k)?"""
    try:
        if kind == 'fpr':
            a, b = float(v0), float(v1)
            return any(abs(a - x) < 1e-3 and abs(b - (x + 1000)) < 1e-3 for x in [100 + 10 * k for k in range(14)] + [2000.5 + 10 * k for k in range(14)])
        a, b = int(v0, 16), int(v1, 16)
    except ValueError: return False
    for k in range(14):
        if a == 0x5a000000 + k * 0x101 and b == 0x5a010000 + k * 0x101: return True
        if a == 0x5b000000 + k * 0x101 and b == 0x5b010000 + k * 0x101: return True
        if a == 0x20 + k * 4 and b == a + 1: return True
        if a == 0x2000 + k * 16 and b == a + 1: return True
    return False
def expected(cls):
    """positions (kind, index) where the dispatch call receives each parameter: the stub inserts the context as the first argument (r3), so integer / pointer parameters go to
    r4.. and a float / double still takes its FPR (f1..) and reserves 1 / 2 GPR slots; parameters that no longer fit in r10 go to the stack (not compared by position)"""
    out = []; slot = 1; nf = 0
    for ch in cls:
        if ch in 'ip':
            out.append(('gpr', slot, ch) if slot <= 7 else ('stack', slot - 8, ch)); slot += 1
        elif ch == 'f': out.append(('fpr', nf, ch)); nf += 1; slot += 1
        else: out.append(('fpr', nf, ch)); nf += 1; slot += 2
    return out
def val(rec, kind, ix): return rec[{'gpr': 1, 'fpr': 2, 'stack': 3}[kind]][ix]
bad = 0; nlive = 0; rule_bad = 0; nstack = 0
for name in S0:
    a0, a1, b0, b1 = S0[name], S1.get(name), R0.get(name), R1.get(name)
    if isinstance(a0, str) or isinstance(b0, str) or a1 is None or b1 is None:
        if a0 != b0: print('%s: stock %s / rebuilt %s' % (name, a0, b0)); bad += 1
        continue
    if len(a0) != len(b0): print('%s: %d records in the stock, %d rebuilt' % (name, len(a0), len(b0))); bad += 1; continue
    for r, (x0, x1, y0, y1) in enumerate(zip(a0, a1, b0, b1)):
        if x0[0] != y0[0]: print('%s: dispatch slot %d stock, %d rebuilt' % (name, x0[0], y0[0])); bad += 1
        exp = expected(PROTO.get(name, ''))
        for (kind, ix, ch) in exp:
            if kind == 'stack': nstack += 1
            v0, v1 = val(x0, kind, ix), val(x1, kind, ix); w0, w1 = val(y0, kind, ix), val(y1, kind, ix)
            if not is_sentinel_pair(kind, v0, v1): print('%s: RULE: stock %s[%d] (%s) = %s/%s is no sentinel' % (name, kind, ix, ch, v0, v1)); rule_bad += 1; continue
            nlive += 1
            if (v0, v1) != (w0, w1): print('%s: %s[%d] stock %s/%s rebuilt %s/%s' % (name, kind, ix, v0, v1, w0, w1)); bad += 1
print('%d functions, %d argument positions compared (%d of them stack-passed), %d positions where the ABI rule did not match the stock, %d mismatches' % (len(S0), nlive, nstack, rule_bad, bad))
print('RESULT:', 'PASS' if not bad else 'FAIL')
