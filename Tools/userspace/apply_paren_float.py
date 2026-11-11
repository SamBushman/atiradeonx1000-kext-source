#!/usr/bin/env python3
"""apply_paren_float.py FLAT_DUMP PAREN_DUMP CORPUS_FILE ADDR [--write]

Float-associativity companion of apply_fcmp_atoms.py.  Ghidra's printer marks its float + and * tokens associative, so it prints the right-nested tree
`x + (y + z)` as `x + y + z`; a C compiler reads that as `(x + y) + z`, which rounds differently (the stock's fmadds chains are right-nested).  A
dump made with DECOMP_PAREN_FLOAT=1 (Tools/userspace/gs/DecompAll.java) keeps the parentheses.  This tool takes the ordinary patched dump (FLAT_DUMP) and the
DECOMP_PAREN_FLOAT=1 dump (PAREN_DUMP) of one function, finds every inserted parenthesis pair, expresses it as an interval of operands of an arithmetic CHAIN
(operands joined by + - * /, key = operand count + operator string), finds the same chains in the corpus function (aligned by order among all chains of that
key; the counts must match) and inserts the same parentheses there.  A pair that wraps one operand or a whole chain is a no-op and ignored.  Without --write
only the plan is printed."""
import re, sys

TOK = re.compile(r'0x[0-9a-fA-F]+[uUlL]*|\d+\.\d*(?:[eE][-+]?\d+)?[fF]?|\d+[uUlL]*|[A-Za-z_]\w*|->|<<|>>|<=|>=|==|!=|&&|\|\||[-+*/%&|^~!<>=?:;,.()\[\]{}]')
TYPES = re.compile(r'^(?:const|unsigned|signed|float|double|int|uint|char|uchar|short|ushort|long|ulong|void|byte|bool|undefined\d*|[A-Za-z_]\w*_t|\*)$')

def strip_comments(s):
    s = re.sub(r'/\*.*?\*/', lambda m: re.sub(r'[^\n]', ' ', m.group(0)), s, flags=re.S)
    return re.sub(r'//[^\n]*', lambda m: ' ' * len(m.group(0)), s)

def tokenize(s):
    return [(m.group(0), m.start(), m.end()) for m in TOK.finditer(s)]

class Chains:
    def __init__(self, toks):
        self.t = [x[0] for x in toks]; self.toks = toks; self.n = len(toks)
        self.match = {}; st = []
        for i, t in enumerate(self.t):
            if t in '([{' and len(t) == 1: st.append(i)
            elif t in ')]}' and len(t) == 1 and st: self.match[st.pop()] = i
        self.chains = []       # (leaf spans [(s, e)], ops [str])
        self.scan(0, self.n)

    def is_cast(self, i):
        e = self.match.get(i)
        return e is not None and e > i + 1 and all(TYPES.match(self.t[k]) for k in range(i + 1, e)) and any(self.t[k] != '*' for k in range(i + 1, e))

    def operand(self, i, hi):
        """-> (end, inner ranges) or None"""
        t = self.t; j = i; inner = []
        while j < hi:
            if t[j] in ('-', '!', '~', '&', '*', '+'): j += 1
            elif t[j] == '(' and self.is_cast(j) and self.match[j] + 1 < hi: j = self.match[j] + 1
            else: break
        if j >= hi: return None
        if t[j] == '(':
            e = self.match.get(j)
            if e is None or e >= hi: return None
            inner.append((j + 1, e)); j = e + 1
        elif re.match(r'^(?:0x[0-9a-fA-F]+|\d|[A-Za-z_])', t[j]): j += 1
        else: return None
        while j < hi:
            if t[j] == '[' and j in self.match: inner.append((j + 1, self.match[j])); j = self.match[j] + 1
            elif t[j] == '(' and j in self.match and not self.is_cast(j): inner.append((j + 1, self.match[j])); j = self.match[j] + 1
            elif t[j] in ('.', '->') and j + 1 < hi and re.match(r'^[A-Za-z_]', t[j + 1]): j += 2
            else: break
        return j, inner

    def scan(self, lo, hi):
        i = lo
        while i < hi:
            r = self.operand(i, hi)
            if r is None:
                i += 1; continue
            leaves = [(i, r[0])]; ops = []; inners = list(r[1]); j = r[0]
            while j < hi and self.t[j] in ('+', '-', '*', '/'):
                r2 = self.operand(j + 1, hi)
                if r2 is None: break
                ops.append(self.t[j]); leaves.append((j + 1, r2[0])); inners += r2[1]; j = r2[0]
            self.chains.append((leaves, ops))
            for (a, b) in inners:
                # call arguments are separated by top level commas
                k = a; depth = 0; seg = a
                for m in range(a, b):
                    if self.t[m] in ('(', '[', '{'): depth += 1
                    elif self.t[m] in (')', ']', '}'): depth -= 1
                    elif self.t[m] == ',' and depth == 0: self.scan(seg, m); seg = m + 1
                self.scan(seg, b)
            i = j if j > i else i + 1

def key(c): return (len(c[0]), ''.join(c[1]))

def main():
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    flat, paren, corp, addr = args[:4]; write = '--write' in sys.argv
    addr = addr.lower().replace('0x', '')
    fs = strip_comments(open(flat).read()); ps = strip_comments(open(paren).read())
    ft = tokenize(fs); pt = tokenize(ps)
    import difflib
    sm = difflib.SequenceMatcher(None, [x[0] for x in ft], [x[0] for x in pt], autojunk=False)
    ins = set(); omap = {}      # paren-dump token index inserted? ; paren index -> flat index
    for tag, a0, a1, b0, b1 in sm.get_opcodes():
        if tag == 'equal':
            for k in range(b1 - b0): omap[b0 + k] = a0 + k
        elif tag == 'insert':
            if all(pt[k][0] in '()' for k in range(b0, b1)): ins.update(range(b0, b1))
            else: print('%s: non-paren insert in paren dump at token %d' % (addr, b0)); return
        elif tag == 'delete':
            if not all(ft[k][0] in '()' for k in range(a0, a1)): print('%s: non-paren delete' % addr); return
        else:   # replace
            if all(pt[k][0] in '()' for k in range(b0, b1)) and all(ft[k][0] in '()' for k in range(a0, a1)): ins.update(range(b0, b1))
            else: print('%s: non-paren replace at token %d' % (addr, b0)); return
    # every parenthesis pair of both dumps, as the interval of its non-parenthesis content tokens in FLAT token indices; pairs of the paren dump that the flat dump
    # does not have (by multiplicity) are the new groups
    def np_interval(toks, o, c, mp):
        s = next((k for k in range(o + 1, c) if toks[k][0] not in '()'), None); e = next((k for k in range(c - 1, o, -1) if toks[k][0] not in '()'), None)
        if s is None or e is None: return None
        return mp[s], mp[e] + 1
    def pair_list(toks, mp):
        st = []; out = []
        for k, (t, _, _) in enumerate(toks):
            if t == '(': st.append(k)
            elif t == ')' and st:
                o = st.pop(); iv = np_interval(toks, o, k, mp)
                if iv: out.append(iv)
        return out
    ident = {k: k for k in range(len(ft))}
    fpairs = pair_list(ft, ident); ppairs = pair_list(pt, omap)
    from collections import Counter
    cf = Counter(fpairs); cp = Counter(ppairs); newp = []
    for iv, n in cp.items():
        newp += [iv] * max(0, n - cf.get(iv, 0))
    pairs = newp
    FC = Chains(ft)
    # interval of the pair in flat token indices
    todo = []   # (chain index, leaf i, leaf j)
    FT = [x[0] for x in ft]
    def lstart(a): return next((k for k in range(a, len(FT)) if FT[k] not in '()'), a)
    def lend(b): return next((k for k in range(b - 1, -1, -1) if FT[k] not in '()'), b - 1) + 1
    for fs_, fe_ in pairs:
        best = None
        for ci, (leaves, ops) in enumerate(FC.chains):
            ls = [i for i, (a, b) in enumerate(leaves) if lstart(a) == fs_]; le = [i for i, (a, b) in enumerate(leaves) if lend(b) == fe_]
            if ls and le and ls[0] <= le[0]:
                span = leaves[-1][1] - leaves[0][0]
                if best is None or span < best[0]: best = (span, ci, ls[0], le[0])
        if best is None: print('%s: cannot place pair at flat tokens %d..%d - manual' % (addr, fs_, fe_)); continue
        _, ci, i, j = best
        n = len(FC.chains[ci][0])
        if i == j or (i == 0 and j == n - 1): continue
        todo.append((ci, i, j))
    todo = sorted(set(todo))
    # corpus
    lines = open(corp).read().split('\n')
    start = None
    for k, l in enumerate(lines):
        if re.match(r'/\* \S+ @ 0x%s \(' % re.escape(addr), l): start = k; break
    if start is None: print('%s: function not found' % addr); return
    end = len(lines)
    for k in range(start + 1, len(lines)):
        if re.match(r'/\* \S+ @ 0x[0-9a-f]+ \(', lines[k]): end = k; break
    off = sum(len(l) + 1 for l in lines[:start + 1]); body = '\n'.join(lines[start + 1:end])
    cs = strip_comments(body); CT = tokenize(cs); CC = Chains(CT)
    byk = {}
    for ci, c in enumerate(CC.chains): byk.setdefault(key(c), []).append(ci)
    fk = {}
    for ci, c in enumerate(FC.chains): fk.setdefault(key(c), []).append(ci)
    edits = []; manual = 0
    for ci, i, j in todo:
        k = key(FC.chains[ci])
        if len(fk[k]) != len(byk.get(k, [])):
            print('MANUAL %s chain key %s (%d leaves): dump has %d such chains, corpus %d' % (addr, k, k[0], len(fk[k]), len(byk.get(k, [])))); manual += 1; continue
        cci = byk[k][fk[k].index(ci)]; leaves = CC.chains[cci][0]
        edits.append((CT[leaves[i][0]][1], '(')); edits.append((CT[leaves[j][1] - 1][2], ')'))
        print('APPLY %s key %s leaves %d..%d: %s' % (addr, k, i, j, cs[CT[leaves[0][0]][1]:CT[leaves[-1][1] - 1][2]].replace('\n', ' ')[:200]))
    print('SUMMARY %s pairs %d manual %d applied %d' % (addr, len(todo), manual, len(edits) // 2))
    if write and edits:
        out = list(body)
        for pos, ch in sorted(edits, key=lambda x: (-x[0], 0 if x[1] == ')' else 1)): out.insert(pos, ch)
        lines[start + 1:end] = ''.join(out).split('\n')
        open(corp, 'w').write('\n'.join(lines))

main()
