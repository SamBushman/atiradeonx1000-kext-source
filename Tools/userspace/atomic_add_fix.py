#!/usr/bin/env python3
"""atomic_add_fix.py DIR... : replace Ghidra's lwarx/add/stwcx. pseudo-call loops with the atomicAddWord macro (ghidra_c.h).

Ghidra shows `lwarx rD,0,rP; add/addi rT,rD,K; stwcx. rT,0,rP; bne- retry` as

    do {
      [OLD = *P;]                           (the lwarx result, sometimes a separate local)
      [NEW = OLD + K;]
      if (RES != '\\0') {
        X = storeWordConditionalIndexed(ARG,0,P);   (ARG = OLD + K | *P + K | NEW | GLOBAL + K)
        [*P = X;]
        CR = 2;
      }
      [extra statements Ghidra placed after the if]
    } while (!(bool)(CR >> 1 & 1));

storeWordConditionalIndexed exists nowhere and RES is never initialised (see GLDriver notes_r17_remaining.md, class A).
Each loop becomes   [OLD = ]atomicAddWord(P,K);   (old value = the lwarx result, exactly what the stock loop leaves in rD),
then the extra statements.  Declarations of locals that are only used by the removed construct are dropped.

  atomic_add_fix.py --dry DIR...   report only
Rewrites part_*.c (and unowned_code/, landing_pads/) in each DIR; prints per-site log lines
`FILE:LINE FUNCTION P K old=OLD` and `NOMATCH` lines for sites it could not parse (left untouched).
Removed declarations are printed as `DECL FILE FUNCTION NAME`.
"""
import re, sys, glob, os

SITE = 'storeWordConditionalIndexed'
HDR = re.compile(r'^/\* (\S+) @ 0x([0-9a-f]+) \((\d+) bytes\)')
NUM = r'-?(?:0x[0-9a-fA-F]+|\d+)'


def parse_block(text):
    """text: the whole do-while as one whitespace-normalised string. Returns dict or None."""
    m = re.match(
        r"do \{ (?P<pre>.*?)if \((?P<res>\w+) != '\\0'\) \{ (?P<lhs>[^;=]+?) = (?:\([^)]*\))?\s*" + SITE +
        r"\s*\((?P<a1>.+?),\s*0,\s*(?P<p>[^;]+?)\);\s*(?P<store>[^;]*?;\s*)?(?P<cr>\w+) = 2; \} (?P<tail>.*?)\} while \(!\(bool\)\((?P<crw>\w+) >> 1(?: & 1)?\)\);$",
        text)
    if not m:
        return None
    d = m.groupdict()
    if d['cr'] != d['crw']:
        return None
    return d


def norm(s):
    return re.sub(r'\s+', ' ', s.strip())


def derive(d):
    """-> (P_expr, delta_str, old_var or None, drop_vars set, tail_stmts) or None"""
    pre = [norm(x) for x in d['pre'].split(';') if x.strip() and not x.strip().startswith('/*')]
    # strip comments inside pre
    pre = [re.sub(r'/\*.*?\*/', '', x).strip() for x in pre]
    pre = [x for x in pre if x]
    old = None
    newdef = None
    for x in pre:
        mm = re.match(r'^(\w+) = \*(?:\(([^)]*)\))?\s*(.+)$', x)
        if mm and old is None and newdef is None:
            old = mm.group(1)
            loadp = mm.group(3)
            continue
        mm = re.match(r'^(\w+) = (\w+) ([+-]) (' + NUM + r')$', x)
        if mm and newdef is None:
            newdef = mm
            continue
        return None
    p = norm(d['p'])
    a1 = norm(d['a1'])
    lhs = norm(d['lhs'])
    drop = {d['res'], d['cr']}
    # P expression: a pointer variable, or an absolute address (global variable case: lhs is the variable itself)
    if re.fullmatch(r'0x[0-9a-fA-F]+', p):
        pexpr = '&' + lhs               # absolute global: lhs is the (declared) global being updated
        if d['store']:
            return None
    else:
        pexpr = p
        if d['store']:
            sm = re.match(r'^\*(?:\(([^)]*)\))?\s*(.+?) = (\w+);$', norm(d['store']))
            if not sm or norm(sm.group(2)) != p and norm(sm.group(2)) != '(' + p + ')' or sm.group(3) != lhs:
                # allow `*(T *)P = X` with possible cast around P
                if not sm or sm.group(3) != lhs:
                    return None
            drop.add(lhs)
        else:
            return None
    # delta
    if newdef is not None and a1 == newdef.group(1):
        base, sign, k = newdef.group(2), newdef.group(3), newdef.group(4)
        drop.add(newdef.group(1))
        if base != old:
            return None
    else:
        am = re.match(r'^(.+?) ([+-]) (' + NUM + r')$', a1)
        if not am:
            return None
        base, sign, k = norm(am.group(1)), am.group(2), am.group(3)
        okbase = {old, '*' + p, '*(' + p + ')'}
        if re.fullmatch(r'0x[0-9a-fA-F]+', d['p'].strip()):
            okbase.add(lhs)
        okbase.discard(None)
        # allow `*(T *)P` forms
        if base not in okbase and not re.fullmatch(r'\*\([^)]*\)\s*' + re.escape(p), base):
            return None
    if k.startswith('-'):
        sign = '+' if sign == '-' else '-'
        k = k[1:]
    delta = (k if sign == '+' else '-' + k)
    delta = delta.replace('--', '')
    tail = [norm(x) + ';' for x in d['tail'].split(';') if x.strip()]
    return pexpr, delta, old, drop, tail


def process_file(path, dry, log):
    src = open(path).read().split('\n')
    out = []
    i = 0
    changed = False
    # function boundaries by header comments
    funcs = []   # (start_idx, name)
    for k, l in enumerate(src):
        m = HDR.match(l)
        if m:
            funcs.append((k, m.group(1)))
    # find sites
    sites = [k for k, l in enumerate(src) if re.search(SITE + r'\s*(\(|$)', l) and not l.startswith('extern')]
    if not sites:
        return 0, 0
    handled = {}
    ok = bad = 0
    for k in sites:
        if k in handled:
            continue
        a = k
        while a > 0 and not re.match(r'\s*do \{\s*$', src[a]):
            a -= 1
        b = k
        while b < len(src) - 1 and not re.match(r'\s*\} while \(!\(bool\)', src[b]):
            b += 1
        text = norm(' '.join(src[a:b + 1])) if b - a <= 16 else ''
        d = parse_block(text) if text else None
        if d is None:
            # loop-less form Ghidra sometimes leaves: if (RES != 0) { GLOBAL = store(GLOBAL + K,0,ADDR); }
            a2 = k
            while a2 > 0 and not re.match(r"\s*if \(\w+ != '\\0'\) \{\s*$", src[a2]):
                a2 -= 1
            b2 = k
            while b2 < len(src) - 1 and not re.match(r'\s*\}\s*$', src[b2]):
                b2 += 1
            t2 = norm(' '.join(src[a2:b2 + 1]))
            m2 = re.match(r"^if \((\w+) != '\\0'\) \{ (\w+) = " + SITE + r"\((\w+) ([+-]) (" + NUM + r"),0,(0x[0-9a-fA-F]+)\); \}$", t2)
            if k - a2 <= 4 and b2 - k <= 4 and m2 and m2.group(2) == m2.group(3):
                kk_ = m2.group(5)
                delta = kk_ if m2.group(4) == '+' else ('-' + kk_.lstrip('-') if not kk_.startswith('-') else kk_[1:])
                fn = [n for (s_, n) in funcs if s_ <= a2][-1] if funcs else '?'
                indent = re.match(r'\s*', src[a2]).group(0)
                log.append('SITE %s:%d %s P=&%s K=%s old=None (loop-less)' % (path, k + 1, fn, m2.group(2), delta))
                v = (a2, b2, [indent + 'atomicAddWord(&%s,%s);' % (m2.group(2), delta)], fn, {m2.group(1)})
                handled[k] = v
                ok += 1
                continue
        r = derive(d) if d else None
        if not r:
            log.append('NOMATCH %s:%d %s' % (path, k + 1, text[:200])); bad += 1; continue
        pexpr, delta, old, drop, tail = r
        indent = re.match(r'\s*', src[a]).group(0)
        stmt = indent + (('%s = ' % old) if old else '') + 'atomicAddWord(%s,%s);' % (pexpr, delta)
        newlines = [stmt] + [indent + t for t in tail]
        fn = [n for (s, n) in funcs if s <= a][-1] if funcs else '?'
        log.append('SITE %s:%d %s P=%s K=%s old=%s' % (path, k + 1, fn, pexpr, delta, old))
        handled[k] = (a, b, newlines, fn, drop)
        for kk in range(a, b + 1):
            if SITE in src[kk]:
                handled[kk] = handled[k]
        ok += 1
    if dry:
        return ok, bad
    # apply back to front
    seen = set()
    todo = []
    for k, v in handled.items():
        if id(v) in seen:
            continue
        seen.add(id(v)); todo.append(v)
    todo.sort(key=lambda v: -v[0])
    dropped = {}
    for a, b, newlines, fn, drop in todo:
        src[a:b + 1] = newlines
        dropped.setdefault(fn, set()).update(drop)
    # drop now-unused declarations, per function
    funcs = [(k, HDR.match(l).group(1)) for k, l in enumerate(src) if HDR.match(l)]
    bounds = {}
    for idx, (s, n) in enumerate(funcs):
        e = funcs[idx + 1][0] if idx + 1 < len(funcs) else len(src)
        bounds.setdefault(n, []).append((s, e))
    for fn, names in dropped.items():
        for (s, e) in bounds.get(fn, []):
            body = '\n'.join(x for x in src[s:e] if x is not None)
            for nme in sorted(names):
                # declaration line: `<type words> NAME;` or `NAME [N];`
                decl = re.compile(r'^\s+[A-Za-z_][\w ]*?[\s*]' + re.escape(nme) + r'(?: ?\[\d+\])?;\s*$')
                cnt = len(re.findall(r'\b' + re.escape(nme) + r'\b', body))
                idxs = [j for j in range(s, e) if src[j] is not None and decl.match(src[j])]
                if len(idxs) == 1 and cnt == 1:
                    src[idxs[0]] = None
                    log.append('DECL %s %s %s' % (path, fn, nme))
                    body = '\n'.join(x for x in src[s:e] if x is not None)
                elif idxs and cnt > 1:
                    log.append('KEEP %s %s %s (still used %d)' % (path, fn, nme, cnt - 1))
        src = [x for x in src if x is not None]
        funcs = [(k, HDR.match(l).group(1)) for k, l in enumerate(src) if HDR.match(l)]
        bounds = {}
        for idx, (s, n) in enumerate(funcs):
            e = funcs[idx + 1][0] if idx + 1 < len(funcs) else len(src)
            bounds.setdefault(n, []).append((s, e))
    open(path, 'w').write('\n'.join(src))
    return ok, bad


def main():
    args = sys.argv[1:]
    dry = '--dry' in args
    args = [a for a in args if a != '--dry']
    log = []
    tot_ok = tot_bad = 0
    for d in args:
        files = sorted(glob.glob(os.path.join(d, 'part_*.c')) + glob.glob(os.path.join(d, 'unowned_code', 'part_*.c')) +
                       glob.glob(os.path.join(d, 'landing_pads', '*.c')))
        for f in files:
            ok, bad = process_file(f, dry, log)
            tot_ok += ok; tot_bad += bad
    print('\n'.join(log))
    print('SITES converted %d, unparsed %d%s' % (tot_ok, tot_bad, ' (dry run)' if dry else ''))


if __name__ == '__main__':
    main()
