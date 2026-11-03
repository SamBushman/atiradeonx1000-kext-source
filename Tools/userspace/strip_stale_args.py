#!/usr/bin/env python3
"""strip_stale_args.py [--apply] [--stats] [FUNC ...]   (issue #212 / #209)

Ghidra reconstructs calls with every argument register that *might* be live (r4..r10), so the corpus passes a function's own incoming parameters on to its
callees (`staleArgR6`, `unusedArgR9`, `scratchR6`, ...).  Stock never did: those values are dead, but the rebuilt image keeps them in callee-saved registers
for the whole function (bigger stmw/lmw, one `or rX,rY,rY` per call, register pressure) - +100 `or` in gld_validateDirtyState alone.

This tool finds the parameters that are never really used, program-wide, and removes the TRAILING ones from both the definition and every call site:
  * a parameter is UNUSED iff each of its occurrences in the body is a bare argument `p` at a call `g(..., p, ...)` / `((T (*)())g)(..., p, ...)` of a known corpus
    function whose parameter at that position is itself UNUSED (greatest fixed point, so recursion and long forwarding chains resolve);
  * any other occurrence (arithmetic, store, address-of, comparison, return, indirect callee) is a real use;
  * only a TRAILING run of unused parameters is removed (positions of the others are unchanged => the register/stack ABI of every caller, including callers
    through function pointers and callers that still pass the extra values, stays valid);
  * a function is skipped when its body contains STACKARG / in_r / unaff_ / alloca tricks that read parameter slots indirectly, or when its address is
    compared / stored with a signature-sensitive type (kept conservative: such functions simply keep their parameters).
Dry run unless --apply.  --stats prints the per-function table.  With FUNC names, only those functions' parameter lists are shortened (their call sites too).
"""
import re, sys, glob, os, collections
HERE = os.path.dirname(os.path.abspath(__file__))
CORPUS = os.path.join(HERE, '..', '..', 'Userspace', 'ATIRadeonX1000GLDriver', 'ppc')
apply_ = '--apply' in sys.argv; stats = '--stats' in sys.argv
only = [a for a in sys.argv[1:] if not a.startswith('--')]
files = sorted(glob.glob(os.path.join(CORPUS, '**', 'part_*.c'), recursive=True))
src = {p: open(p).read() for p in files}

DEF = re.compile(r'^([A-Za-z_][\w \*]*?)\b([A-Za-z_]\w*)\(([^()]*)\)[ \t]*\n((?:[ \t]+[^\n;{]*;[ \t]*\n)*)\{\n', re.M)
IDENT = re.compile(r'[A-Za-z_]\w*')

funcs = {}    # name -> dict(file, start, end(body end), params, kr(bool), body)
for p, s in src.items():
    for m in DEF.finditer(s):
        name = m.group(2)
        if name in ('if', 'while', 'for', 'switch', 'return', 'sizeof'): continue
        end = s.find('\n}\n', m.end() - 2)
        if end < 0: continue
        plist = m.group(3).strip()
        if plist in ('', 'void'): params = []
        else:
            params = []
            for part in plist.split(','):
                part = part.strip()
                im = IDENT.findall(part)
                if not im: params = None; break
                params.append(im[-1])
        if params is None: continue
        if name in funcs: funcs[name]['dup'] = True; continue
        funcs[name] = dict(file=p, hdr=(m.start(), m.end()), params=params, body=s[m.end():end], kr=bool(m.group(4)), dup=False, m=m)

BAD_BODY = re.compile(r'STACKARG|\bin_[rf]\d|\bunaff_|__builtin_alloca|__builtin_va|\bva_|asm\s*\(|__asm')

def call_sites(body):
    """yield (callee, arg_spans) for direct and cast-direct calls: arg_spans = list of (start,end) of each top-level argument inside the body string"""
    for m in re.finditer(r'(?:\(\([^()]*\(\*\)\([^()]*\)\)\s*(\w+)\s*\)|\b(\w+))\s*\(', body):
        name = m.group(1) or m.group(2)
        if name not in funcs: continue
        i = m.end()  # just after '('
        depth = 1; j = i; spans = []; a = i
        while j < len(body) and depth:
            c = body[j]
            if c in '([': depth += 1
            elif c in ')]':
                depth -= 1
                if depth == 0: spans.append((a, j)); break
            elif c == ',' and depth == 1: spans.append((a, j)); a = j + 1
            j += 1
        else:
            continue
        if len(spans) == 1 and body[spans[0][0]:spans[0][1]].strip() == '': spans = []
        yield name, m.start(), i, j, spans

# greatest fixed point of "unused"
unused = {(n, i) for n, f in funcs.items() if not f['dup'] and not BAD_BODY.search(f['body']) for i in range(len(f['params']))}
# precompute occurrences
occ = {}
for n, f in funcs.items():
    if f['dup']: continue
    b = f['body']
    sites = list(call_sites(b))
    bare = collections.defaultdict(list)   # param -> list of (callee,pos) for bare-arg occurrences, plus coverage of char spans
    covered = set()
    for callee, ms, ai, aj, spans in sites:
        for pos, (a, e) in enumerate(spans):
            t = b[a:e].strip()
            if IDENT.fullmatch(t) and t in f['params']:
                k = b.index(t, a)
                bare[t].append((callee, pos, k))
                covered.add(k)
    allocc = {}
    for p in set(f['params']):
        allocc[p] = [m.start() for m in re.finditer(r'(?<![\w.>])%s(?!\w)' % re.escape(p), b)]
    occ[n] = (bare, allocc, covered)

changed = True
while changed:
    changed = False
    for (n, i) in list(unused):
        f = funcs[n]; p = f['params'][i]
        bare, allocc, covered = occ[n]
        ok = True
        for k in allocc[p]:
            if k in covered:
                # find which call
                good = False
                for callee, pos, kk in bare[p]:
                    if kk == k and (callee, pos) in unused: good = True
                    elif kk == k and pos >= len(funcs[callee]['params']) and not funcs[callee]['dup'] and not BAD_BODY.search(funcs[callee]['body']): good = True   # extra arg beyond callee's declared params: callee cannot read it (no in_rN / STACKARG tricks)
                if not good: ok = False; break
            else: ok = False; break
        # a duplicated parameter name (same name twice) is a real use
        if f['params'].count(p) > 1: ok = False
        if not ok: unused.discard((n, i)); changed = True

remove = {}
for n, f in funcs.items():
    if f['dup'] or n not in {x for x, _ in unused}: continue
    k = len(f['params'])
    while k > 0 and (n, k - 1) in unused: k -= 1
    # keep >= 1 parameter (ctx) to avoid turning K&R prototypes into `()`
    k = max(k, 1) if f['params'] else 0
    if k < len(f['params']): remove[n] = k
# prototypes with a parameter list in decls.h (a changed definition would conflict with them)
PROTO = set()
dh = os.path.join(CORPUS, 'decls.h')
if os.path.exists(dh):
    for l in open(dh):
        m = re.match(r'extern\s+[^;(]*?\b(\w+)\(([^)]+)\);', l)
        if m and m.group(2).strip() not in ('', 'void'): PROTO.add(m.group(1))
def skip_def(n, f):
    m = f['m']
    if n in PROTO: return 'proto'
    if '(' in m.group(3): return 'fnptr-param'
    if f['kr'] and any(',' in d for d in m.group(4).split('\n')): return 'multi-decl'
    return None
for n in list(remove):
    if skip_def(n, funcs[n]): del remove[n]
# removed call-site arguments must be side-effect free
TYPEWORDS = {'int','uint','char','short','byte','float','double','long','ulong','ushort','uchar','void','sizeof','unsigned','signed','code','bool'}
def has_effect(t):
    if re.search(r'\+\+|--|(?<![=!<>+\-*/&|^%])=(?!=)', t): return True
    for m in re.finditer(r'(\w+)\s*\(', t):
        w = m.group(1)
        if w in TYPEWORDS or re.fullmatch(r'undefined\d*', w): continue
        return True
    return bool(re.search(r'\(\*\)', t)) or bool(re.search(r'\)\s*\(\s*[^)]*\)\s*\(', t))
changed = True
while changed:
    changed = False
    for n, f in funcs.items():
        for callee, ms, ai, aj, spans in call_sites(f['body']):
            if callee not in remove: continue
            k = remove[callee]
            for pos in range(k, len(spans)):
                if has_effect(f['body'][spans[pos][0]:spans[pos][1]]):
                    remove[callee] = pos + 1; changed = True
                    if remove[callee] >= len(funcs[callee]['params']): del remove[callee]
                    break
if only: remove = {n: k for n, k in remove.items() if n in only}

tot = sum(len(funcs[n]['params']) - k for n, k in remove.items())
print('functions parsed %d; with removable trailing params %d; params removed %d' % (len(funcs), len(remove), tot))
if stats:
    for n, k in sorted(remove.items(), key=lambda kv: -(len(funcs[kv[0]]['params']) - kv[1])):
        print('%-44s %d -> %d  (%s)' % (n, len(funcs[n]['params']), k, ','.join(funcs[n]['params'][k:])))

if apply_ and remove:
    # 1. call sites in every body (positions are within the function bodies; rebuild each file)
    for p in files:
        s = src[p]; edits = []   # (start, end, replacement)
        for n, f in funcs.items():
            if f['file'] != p or f['dup']: continue
            base = f['hdr'][1]
            b = f['body']
            for callee, ms, ai, aj, spans in call_sites(b):
                if callee in remove and len(spans) > remove[callee]:
                    k = remove[callee]
                    a0 = spans[k - 1][1] if k > 0 else spans[0][0]
                    edits.append((base + a0, base + aj, ''))
            # 1b. leftover bare uses of f's own removed parameters (forwarded to a callee position that stays) become 0: that position is unused in the callee
            if n in remove:
                rm_spans = [(a, e) for a, e, r in edits if base <= a < base + len(b)]
                for q in set(f['params'][remove[n]:]):
                    for mo in re.finditer(r'(?<![\w.>])%s(?!\w)' % re.escape(q), b):
                        pos = base + mo.start()
                        if any(a <= pos < e for a, e in rm_spans): continue
                        edits.append((pos, pos + len(q), '0'))
            # 2. definition header of f itself
            if n in remove:
                k = remove[n]; m = f['m']; keep = f['params'][:k]
                plist_old = m.group(3)
                if f['kr']:
                    decl = m.group(4).split('\n')
                    newdecl = [d for d in decl if not any(re.search(r'\b%s\b\s*;' % re.escape(q), d) for q in f['params'][k:])]
                    hdr = m.group(1) + m.group(2) + '(' + ', '.join(keep) + ')\n' + '\n'.join(newdecl) + '{\n'
                    hdr = hdr.replace('\n\n{', '\n{')
                else:
                    parts = [x.strip() for x in plist_old.split(',')][:k]
                    hdr = m.group(1) + m.group(2) + '(' + ','.join(parts) + ')\n{\n'
                edits.append((m.start(), m.end(), hdr))
        # apply from the end; drop overlapping edits defensively
        edits.sort(key=lambda e: (e[0], e[1]), reverse=True)
        last = len(s) + 1; out = s
        for a, e, r in edits:
            if e > last: continue
            out = out[:a] + r + out[e:]; last = a
        if out != s: open(p, 'w').write(out)
    print('applied')
