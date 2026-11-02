#!/usr/bin/env python3
"""strip_fp_passthrough.py [--apply] - remove dead trailing `double` parameters (Ghidra's f1..f13 pass-through slots) from the GLDriver corpus.

Every decompiled function carries the FP argument registers as `double staleFprArgN / unusedFloatArgN / fpPassThroughN / fprFN` parameters, and forwards them to its callees. Stock never
touches them: the rebuilt functions pay for it on every call (callee-saved FPR saves via saveFP/restFP, fmr copies, stack argument space) - issue #209: ffvpValidateProgram and friends
cost ~0.25 us per state-change draw more than stock.

The i-th `double` parameter is the incoming register f(i+1). It is dead when the STOCK function never reads that register before writing it, directly or through the functions it calls
(fpr_livein.py computes that from the stock disassembly: python3 fpr_livein.py stock_text.txt ranges.tsv > livein.json; ranges.tsv = `name<TAB>hexoff<TAB>hexsize` from the `/* name @ 0x.. (N bytes) */`
comments). Only the TRAILING run of dead doubles is removed (an int parameter after a double would otherwise shift in the Darwin parameter area); the same positions are removed from every call
site and from decls.h, and a removed parameter the body still uses (Ghidra's name for a scratch FP register) becomes a local `double NAME = 0.0;`. Idempotent.
Usage: strip_fp_passthrough.py LIVEIN.json [--apply]"""
import re, sys, glob, os, json
D = os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', 'Userspace', 'ATIRadeonX1000GLDriver', 'ppc')
D = os.path.normpath(D)
files = sorted(glob.glob(D + '/part_*.c') + glob.glob(D + '/unowned_code/part_*.c'))
HDR = re.compile(r'(?m)^(?!\s)(?!/\*)(?!typedef)(?!extern)([A-Za-z_][\w\s\*]*?[\s\*])(\w+)\(([^;{}]*?)\)\s*\n\{')

def split_top(s):
    out, d, cur = [], 0, ''
    for ch in s:
        if ch == '(': d += 1
        if ch == ')': d -= 1
        if ch == ',' and d == 0: out.append(cur); cur = ''
        else: cur += ch
    if cur.strip() or out: out.append(cur)
    return out

def pinfo(p):
    m = re.match(r'^(.*?)(\w+)\s*$', p.strip(), re.S)
    return (m.group(1).strip(), m.group(2)) if m else (p.strip(), '')

def find_calls(body):
    for m in re.finditer(r'(?:\(\([^()]*\(\*\)\([^()]*\)\)\s*(\w+)\)|(?<![\w.>])(\w+))\s*\(', body):
        tgt = m.group(1) or m.group(2)
        i = m.end(); d = 1; j = i
        while j < len(body) and d > 0:
            if body[j] == '(': d += 1
            elif body[j] == ')': d -= 1
            j += 1
        yield tgt, i, j - 1            # args text = body[i:j-1]

def analyse():
    funcs = {}
    for f in files:
        t = open(f).read()
        for m in HDR.finditer(t):
            name = m.group(2); ps = [p.strip() for p in split_top(m.group(3))]
            if ps == ['void'] or ps == ['']: ps = []
            i = m.end() - 1; d = 0
            while True:
                c = t[i]
                if c == '{': d += 1
                elif c == '}':
                    d -= 1
                    if d == 0: break
                i += 1
            funcs.setdefault(name, []).append(dict(ps=ps, body=t[m.end():i + 1]))
    dbl = {n: [i for i, p in enumerate(l[0]['ps']) if pinfo(p)[0] == 'double'] for n, l in funcs.items()}
    livein = json.load(open(sys.argv[1]))
    strip = {}
    for n, l in funcs.items():
        ps = l[0]['ps']; ds = dbl[n]
        if not ds or n not in livein: continue
        order = {i: j for j, i in enumerate(ds)}                    # parameter index -> double ordinal
        j = len(ps)
        while j > 0 and (j - 1) in order and (order[j - 1] + 1) not in livein[n]: j -= 1
        if j < len(ps): strip[n] = j
    return funcs, strip

def apply(strip, funcs):
    n_def = n_call = n_decl = n_loc = 0
    names = '|'.join(re.escape(n) for n in strip)
    for f in files + [os.path.join(D, 'decls.h')]:
        t = open(f).read(); orig = t
        if f.endswith('decls.h'):
            def dsub(m):
                nonlocal n_decl
                ps = split_top(m.group(3)); k = strip[m.group(2)]
                if len(ps) <= k: return m.group(0)
                n_decl += 1
                return m.group(1) + m.group(2) + '(' + ','.join(ps[:k]) + ');'
            t = re.sub(r'(?m)^(extern [^;(]*?[\s\*])(%s)\(([^;]*)\);' % names, dsub, t)
        else:
            def hsub(m):
                nonlocal n_def
                if m.group(2) not in strip: return m.group(0)
                ps = split_top(m.group(3)); k = strip[m.group(2)]
                if len(ps) <= k: return m.group(0)
                n_def += 1
                return m.group(1) + m.group(2) + '(' + ','.join(ps[:k]) + ')\n{'
            t = HDR.sub(hsub, t)
            def locsub(m):
                nonlocal n_loc
                if m.group(2) not in strip: return m.group(0)
                k = strip[m.group(2)]; dropped = [pinfo(p)[1] for p in funcs[m.group(2)][0]['ps'][k:]]
                # body = from this header to the matching close brace
                i = m.end() - 1; d = 0
                while True:
                    c = t[i]
                    if c == '{': d += 1
                    elif c == '}':
                        d -= 1
                        if d == 0: break
                    i += 1
                body = t[m.end():i]
                decl = ''.join('  double %s = 0.0;\n' % nm for nm in dropped if re.search(r'(?<![\w.])%s(?!\w)' % re.escape(nm), body))
                n_loc += len(decl.splitlines())
                return m.group(0) + '\n' + decl.rstrip('\n') if decl else m.group(0)
            t = HDR.sub(locsub, t)
            # call sites (any function body, incl. the stripped ones)
            out, pos = [], 0
            for m in re.finditer(r'(?:\(\([^()]*\(\*\)\([^()]*\)\)\s*(%s)\)|(?<![\w.>])(%s))\s*\(' % (names, names), t):
                if m.start() < pos: continue
                tgt = m.group(1) or m.group(2)
                i = m.end(); d = 1; j = i
                while j < len(t) and d > 0:
                    if t[j] == '(': d += 1
                    elif t[j] == ')': d -= 1
                    j += 1
                args = split_top(t[i:j - 1]); k = strip[tgt]
                # a definition/prototype header also matches here: leave it (it was rewritten by HDR above and has k params)
                if len(args) <= k: continue
                out.append(t[pos:i]); out.append(','.join(args[:k])); pos = j - 1; n_call += 1
            out.append(t[pos:]); t = ''.join(out)
        if t != orig: open(f, 'w').write(t)
    return n_def, n_call, n_decl, n_loc

if __name__ == '__main__':
    funcs, strip = analyse()
    print('functions parsed %d, with trailing dead FP params %d, params removed %d' % (len(funcs), len(strip), sum(len(funcs[n][0]['ps']) - k for n, k in strip.items())))
    if '--apply' in sys.argv:
        print('definitions %d, call sites %d, decls.h %d rewritten, %d scratch locals declared' % apply(strip, funcs))
    else:
        for n, k in sorted(strip.items()): print('  %-40s keep %d of %d' % (n, k, len(funcs[n][0]['ps'])))
