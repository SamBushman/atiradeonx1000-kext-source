#!/usr/bin/env python3
"""webs.py - def-use webs of the scalar locals of a Ghidra-decompiled C function (the corpus text), at source level.

A web is a set of definitions of one variable that share a use (the textbook "web" / live-range class). Renaming every occurrence of ONE web to a new name,
and no occurrence of another web of that variable, never changes what the program computes - which is exactly what a per-use split must achieve.
Used by the machine-written `use` rows of Tools/userspace/apply_names.py (names_*.tsv): the generator decides a role for some webs (from an idiom) and
this module makes the segments closed under def-use, so no use is left reading the old variable.

    f = Function(lines, d1, brace, varnames)       lines = the function's lines (any names: pass them already normalised to Ghidra's text)
    f.webs[var] -> list of Web(units=set of (line, part), defs=n, uses=n)       part 0 = left of the statement's first plain `=`, 1 = right (or whole line)
    f.unsplittable -> variables left out (address taken, assigned inside an expression, unparsed)

Parsing covers the shapes Ghidra prints: if / else / else if, while, do-while, for, switch with case/default labels, goto + labels, break, continue,
return, and `if (c) goto L;`-style one-liners. Anything it cannot place makes `ok` False for the function (callers then skip it)."""
import re, collections

KW = {'if', 'else', 'while', 'for', 'do', 'switch', 'return', 'goto', 'break', 'continue', 'case', 'default'}
LABEL = re.compile(r'^\s*([A-Za-z_]\w*):\s*$')
CASE = re.compile(r'^\s*(case\s+[^:]+|default):\s*$')


def split_assign(l):
    for i, ch in enumerate(l):
        if ch == '=' and (i == 0 or l[i - 1] not in '=!<>+-*/&|^%') and l[i + 1:i + 2] != '=': return i
    return -1


class Web:
    def __init__(self, units, defs, uses, defunits=()): self.units, self.defs, self.uses, self.defunits = units, defs, uses, set(defunits)


class Node:
    __slots__ = ('units', 'succ', 'id')
    def __init__(self, i): self.units = []; self.succ = []; self.id = i       # units: ('use'|'def', var, line, col)


class Function:
    def __init__(self, lines, d1, end, varnames):
        self.lines, self.vars = lines, set(varnames)
        self.nodes = []; self.ok = True; self.unsplittable = set(); self.err = ''
        self.labels = {}; self.gotos = []
        self.addr = set(); self.complex = set()
        self.idre = re.compile(r'(?<![A-Za-z0-9_])(%s)(?![A-Za-z0-9_])' % '|'.join(re.escape(v) for v in sorted(self.vars, key=len, reverse=True))) if self.vars else None
        try:
            items = self.tokenize(d1, end)
            self.build(items)
        except (IndexError, KeyError, ValueError, RuntimeError) as ex:
            self.ok = False; self.err = 'parse: %r' % (ex,)
            return
        self.resolve_gotos()
        self.dataflow()

    # ---- tokenizer -------------------------------------------------------------------------------------------------
    def tokenize(self, d1, end):
        items = []; buf = []; pos = []; depth = 0
        def flush(kind, text=None):
            nonlocal buf, pos
            t = ''.join(buf) if text is None else text
            items.append((kind, t, list(pos)))
            buf = []; pos = []
        for ln in range(d1, end):
            raw = self.lines[ln]
            if not ''.join(buf).strip() and depth == 0:
                if CASE.match(raw): items.append(('case', raw.strip(), [])); continue
                m = LABEL.match(raw)
                if m and m.group(1) not in KW: items.append(('label', m.group(1), [])); continue
            i = 0; instr = None
            while i < len(raw):
                ch = raw[i]
                if instr:
                    buf.append(ch); pos.append((ln, i))
                    if ch == '\\':
                        i += 1
                        if i < len(raw): buf.append(raw[i]); pos.append((ln, i))
                    elif ch == instr: instr = None
                    i += 1; continue
                if ch in '"\'': instr = ch; buf.append(ch); pos.append((ln, i)); i += 1; continue
                if ch == '(': depth += 1
                elif ch == ')': depth -= 1
                if depth == 0 and ch == ';':
                    buf.append(ch); pos.append((ln, i)); flush('simple')
                elif depth == 0 and ch == '{':
                    flush('open')
                elif depth == 0 and ch == '}':
                    if ''.join(buf).strip(): raise ValueError('text before }')
                    buf = []; pos = []; items.append(('close', '}', []))
                else:
                    buf.append(ch); pos.append((ln, i))
                i += 1
            buf.append(' '); pos.append((ln, len(raw)))
        if ''.join(buf).strip(): raise ValueError('trailing text')
        return items

    # ---- units of a piece of text ---------------------------------------------------------------------------------
    def occ(self, text, pos, a, b):
        """tracked-variable occurrences of text[a:b] -> [(var, line, col)]"""
        out = []
        if not self.idre: return out
        for m in self.idre.finditer(text, a, b):
            ln, col = pos[m.start()]
            out.append((m.group(1), ln, col, m.start()))
        return out

    def stmt_units(self, text, pos):
        """-> [('use'|'def', var, line, col)] in evaluation order"""
        u = []
        t = text.rstrip().rstrip(';')
        k = split_assign(t)
        for m in re.finditer(r'&\s*(\w+)', t):
            if m.group(1) in self.vars: self.addr.add(m.group(1))
        if k >= 0:
            lhs = t[:k].strip()
            if re.fullmatch(r'\w+', lhs) and lhs in self.vars:
                u.extend(self.cond_units(t[k + 1:], pos[k + 1:]))
                lo = t.index(lhs)
                u.append(('def', lhs, *pos[lo]))
                return u
            # a store through a pointer / into an element: the left side only USES its variables; embedded assignments can only be on the right
            for (v, ln, col, o) in self.occ(t, pos, 0, k): u.append(('use', v, ln, col))
            u.extend(self.cond_units(t[k + 1:], pos[k + 1:]))
            return u
        u.extend(self.cond_units(t, pos))
        return u

    def embedded(self, t, pos, start):
        for m in re.finditer(r'(?<![=!<>+\-*/&|^%])(\w+)\s=\s(?!=)', t[start:]):
            if m.group(1) in self.vars: self.complex.add(m.group(1))

    def cond_units(self, text, pos):
        """uses and (weak) defs of a condition / expression text, in evaluation order. An assignment embedded in the text (`(x = f(y), ...)`, often under
        && / || / the comma operator) becomes a 'wdef': it ADDS its definition to the reaching set without killing the earlier ones (it may not run),
        which only ever merges webs, never splits one wrongly."""
        for m in re.finditer(r'&\s*(\w+)', text):
            if m.group(1) in self.vars: self.addr.add(m.group(1))
        u = []; pending = []
        def flush(limit):
            while pending and pending[0][0] <= limit:
                _, v, ln, col = pending.pop(0); u.append(('wdef', v, ln, col))
        for (v, ln, col, o) in self.occ(text, pos, 0, len(text)):
            flush(o)
            rest = text[o + len(v):]
            mm = re.match(r'\s=(?!=)', rest)
            prev = text[:o].rstrip()[-1:]
            if mm and prev not in ('.', '>', '&') and not text[:o].rstrip().endswith('->'):
                # end of the right-hand side: next ',' / ')' / ';' at depth 0 relative to here
                d = 0; end = len(text)
                for k in range(o + len(v) + mm.end(), len(text)):
                    ch = text[k]
                    if ch == '(': d += 1
                    elif ch == ')':
                        d -= 1
                        if d < 0: end = k; break
                    elif ch in ',;' and d == 0: end = k; break
                pending.append((end, v, ln, col)); pending.sort()
            else:
                u.append(('use', v, ln, col))
        flush(len(text) + 1)
        return u

    # ---- CFG ---------------------------------------------------------------------------------------------------------
    def node(self, units=()):
        n = Node(len(self.nodes)); n.units = list(units); self.nodes.append(n); return n

    @staticmethod
    def link(front, n):
        for f in front: f.succ.append(n)

    def build(self, items):
        self.items = items; self.i = 0
        self.entry = self.node()
        front, _ = self.seq([self.entry], ctx={'break': None, 'cont': None}, stop_close=False)
        self.exit_front = front

    def seq(self, front, ctx, stop_close=True, sw=None):
        first = None
        while self.i < len(self.items):
            kind, text, pos = self.items[self.i]
            if kind == 'close':
                if stop_close: return front, first
                raise ValueError('unbalanced }')
            self.i += 1
            if kind in ('simple', 'open') and pos:
                lead = len(text) - len(text.lstrip()); text = text.strip(); pos = pos[lead:lead + len(text)]
            if kind == 'label':
                n = self.node(); self.labels[text] = n; self.link(front, n); front = [n]
                if first is None: first = n
                continue
            if kind == 'case':
                n = self.node(); sw['cases'].append(n); self.link(front, n); front = [n]
                if first is None: first = n
                continue
            if kind == 'simple':
                t = text.strip()
                if t.startswith('if ') or t.startswith('if('):
                    front, n0 = self.oneline_if(t, pos, front, ctx)
                    first = first or n0; continue
                if t.startswith('do ') or t == 'do': raise ValueError('do')
                n = self.simple(t, pos)
                self.link(front, n); front = [n] if n is not None else front
                if first is None: first = n
                if n is not None and getattr(n, 'kind', None): pass
                front = self.control(t, n, front, ctx)
                continue
            if kind == 'open':
                front, n0 = self.compound(text.strip(), pos, front, ctx)
                if first is None: first = n0
                continue
        return front, first

    def simple(self, t, pos):
        n = self.node()
        if re.match(r'(goto|break|continue|return)\b', t):
            n.units = [(x[0], x[1], x[2], x[3]) for x in self.cond_units(t, pos)]
        else:
            n.units = self.stmt_units(t, pos)
        return n

    def control(self, t, n, front, ctx):
        """goto/break/continue/return end the flow"""
        m = re.match(r'goto\s+(\w+)\s*;?$', t)
        if m: self.gotos.append((n, m.group(1))); return []
        if re.match(r'return\b', t): return []
        if re.match(r'break\s*;?$', t):
            if ctx['break'] is None: raise ValueError('break outside')
            ctx['break'].append(n); return []
        if re.match(r'continue\s*;?$', t):
            if ctx['cont'] is None: raise ValueError('continue outside')
            ctx['cont'].append(n); return []
        return front

    def split_paren(self, t, start):
        """index just after the paren group opening at t[start]"""
        d = 0
        for k in range(start, len(t)):
            if t[k] == '(': d += 1
            elif t[k] == ')':
                d -= 1
                if d == 0: return k + 1
        raise ValueError('paren')

    def oneline_if(self, t, pos, front, ctx):
        k = t.index('(')
        e = self.split_paren(t, k)
        cond = t[k:e]; cpos = pos[k:e]
        c = self.node(self.cond_units(cond, cpos)); self.link(front, c)
        inner = t[e:].strip(); ipos = pos[e + (len(t[e:]) - len(t[e:].lstrip())):]
        n = self.simple(inner, ipos) if inner else None
        if n is None: return [c], c
        c.succ.append(n)
        fr = self.control(inner, n, [n], ctx)
        return fr + [c], c

    def compound(self, h, pos, front, ctx):
        # h is the header text before '{'
        if h == 'do':
            body_entry = self.node(); self.link(front, body_entry)
            brk = []; cont = []
            c2 = {'break': brk, 'cont': cont}
            fr, _ = self.seq([body_entry], c2)
            self.expect_close()
            # while (...); follows
            kind, text, p = self.items[self.i]; self.i += 1
            lead = len(text) - len(text.lstrip()); text = text.strip(); p = p[lead:lead + len(text)]
            m = re.match(r'while\s*(\(.*\))\s*;?$', text)
            if kind != 'simple' or not m: raise ValueError('do-while end')
            ci = text.index('('); cu = self.cond_units(text[ci:], p[ci:])
            c = self.node(cu); self.link(fr, c); self.link(cont, c); c.succ.append(body_entry)
            return [c] + brk, body_entry
        if h.startswith('else if') or h.startswith('else'):
            raise ValueError('dangling else')
        m = re.match(r'(if|while|switch)\s*\(', h)
        if m and m.group(1) == 'if': return self.if_chain(h, pos, front, ctx)
        if m and m.group(1) == 'while':
            k = h.index('('); c = self.node(self.cond_units(h[k:], pos[k:])); self.link(front, c)
            brk = []; cont = [c]
            fr, first = self.seq([c], {'break': brk, 'cont': cont})
            self.expect_close()
            self.link(fr, c)
            return [c] + brk, c
        if m and m.group(1) == 'switch':
            k = h.index('('); s = self.node(self.cond_units(h[k:], pos[k:])); self.link(front, s)
            brk = []; sw = {'cases': []}
            fr, first = self.seq([], {'break': brk, 'cont': ctx['cont']}, sw=sw)
            self.expect_close()
            for cn in sw['cases']: s.succ.append(cn)
            has_default = any(True for it in [] )
            return fr + brk + [s], s
        if h.startswith('for'):
            k = h.index('('); e = self.split_paren(h, k)
            hdr = h[k + 1:e - 1]; hp = pos[k + 1:e - 1]
            parts = []; d = 0; st = 0
            for j, ch in enumerate(hdr):
                if ch == '(': d += 1
                elif ch == ')': d -= 1
                elif ch == ';' and d == 0: parts.append((st, j)); st = j + 1
            parts.append((st, len(hdr)))
            if len(parts) != 3: raise ValueError('for header')
            init = self.node(self.stmt_units(hdr[parts[0][0]:parts[0][1]] + ';', hp[parts[0][0]:parts[0][1]] + [hp[-1] if hp else (0, 0)]))
            cnd = self.node(self.cond_units(hdr[parts[1][0]:parts[1][1]], hp[parts[1][0]:parts[1][1]]))
            inc = self.node(self.stmt_units(hdr[parts[2][0]:parts[2][1]] + ';', hp[parts[2][0]:parts[2][1]] + [hp[-1] if hp else (0, 0)]))
            self.link(front, init); init.succ.append(cnd)
            brk = []; cont = [inc]
            fr, first = self.seq([cnd], {'break': brk, 'cont': cont})
            self.expect_close()
            self.link(fr, inc); inc.succ.append(cnd)
            return [cnd] + brk, init
        raise ValueError('unknown header %r' % h)

    def expect_close(self):
        if self.i >= len(self.items) or self.items[self.i][0] != 'close': raise ValueError('expected }')
        self.i += 1

    def if_chain(self, h, pos, front, ctx):
        k = h.index('('); e = self.split_paren(h, k)
        c = self.node(self.cond_units(h[k:e], pos[k:e])); self.link(front, c)
        fr1, first1 = self.seq([c], ctx)
        self.expect_close()
        exits = list(fr1)
        if first1 is None and fr1 == [c]: pass
        # else branch?
        if self.i < len(self.items) and self.items[self.i][0] == 'open' and self.items[self.i][1].strip().startswith('else'):
            kind, text, p = self.items[self.i]; self.i += 1
            lead = len(text) - len(text.lstrip()); t = text.strip(); p = p[lead:lead + len(t)]
            if t == 'else':
                fr2, _ = self.seq([c], ctx); self.expect_close()
                exits += fr2
            else:
                # else if (...) { ... }
                tail = t[len('else'):].strip(); off = len(t) - len(tail)
                fr2, _ = self.if_chain(tail, p[off:] if p else [], [c], ctx)
                exits += fr2
        else:
            exits.append(c)
        return exits, c

    def resolve_gotos(self):
        for n, lab in self.gotos:
            if lab not in self.labels: self.ok = False; self.err = 'unknown label ' + lab; return
            n.succ.append(self.labels[lab])

    # ---- reaching definitions / webs -------------------------------------------------------------------------------
    def dataflow(self):
        if not self.ok: return
        tracked = self.vars - self.addr - self.complex
        self.unsplittable = (self.addr | self.complex) & self.vars
        defs = {}          # def id -> (var, line, col)
        defid = {}
        for n in self.nodes:
            for (k, v, ln, col) in n.units:
                if k in ('def', 'wdef') and v in tracked: defid[(v, ln, col)] = len(defs); defs[len(defs)] = (v, ln, col)
        UNINIT = {v: len(defs) + i for i, v in enumerate(sorted(tracked))}
        nd = len(self.nodes)
        # ordered transfer per node: 'def' replaces the reaching set of its variable, 'wdef' (an assignment that may not run) adds to it
        def step(cur, k, v, ln, col):
            if k == 'def': cur[v] = {defid[(v, ln, col)]}
            elif k == 'wdef': cur[v] = set(cur.get(v, {UNINIT[v]})) | {defid[(v, ln, col)]}
        IN = [dict() for _ in range(nd)]
        IN[0] = {v: {UNINIT[v]} for v in tracked}
        work = collections.deque(range(nd)); inq = set(work)
        while work:
            i = work.popleft(); inq.discard(i)
            out = {v: set(d) for v, d in IN[i].items()}
            for (k, v, ln, col) in self.nodes[i].units:
                if v in tracked: step(out, k, v, ln, col)
            for s_ in self.nodes[i].succ:
                ch = False
                for v, ds in out.items():
                    cur = IN[s_.id].setdefault(v, set())
                    if not ds <= cur: cur |= ds; ch = True
                if ch and s_.id not in inq: work.append(s_.id); inq.add(s_.id)
        parent = {}
        def find(x):
            while parent.setdefault(x, x) != x: parent[x] = parent[parent[x]]; x = parent[x]
            return x
        def union(a, b):
            ra, rb = find(a), find(b)
            if ra != rb: parent[ra] = rb
        uses = []                          # (def id of any reaching def, var, line, col)
        for n in self.nodes:
            cur = {v: set(ds) for v, ds in IN[n.id].items()}
            for (k, v, ln, col) in n.units:
                if v not in tracked: continue
                if k == 'use':
                    ds = sorted(cur.get(v, {UNINIT[v]}))
                    if not ds: ds = [UNINIT[v]]
                    for d in ds[1:]: union(ds[0], d)
                    uses.append((ds[0], v, ln, col))
                else:
                    step(cur, k, v, ln, col)
        unit_of = lambda ln, col: (ln, 0 if (split_assign(self.lines[ln]) >= 0 and col < split_assign(self.lines[ln])) else 1)
        W = collections.defaultdict(lambda: {'units': set(), 'defs': 0, 'uses': 0, 'var': None, 'du': set()})
        for d, (v, ln, col) in defs.items():
            w = W[find(d)]; w['units'].add(unit_of(ln, col)); w['du'].add(unit_of(ln, col)); w['defs'] += 1; w['var'] = v
        for (d, v, ln, col) in uses:
            w = W[find(d)]; w['units'].add(unit_of(ln, col)); w['uses'] += 1; w['var'] = v
        # webs that share a unit (two occurrences of one variable in one line part belong to one rename) merge
        byunit = collections.defaultdict(list)
        for r, w in W.items():
            for u in w['units']: byunit[(w['var'], u)].append(r)
        for (v, u), rs in byunit.items():
            for r in rs[1:]: union(rs[0], r)
        W2 = collections.defaultdict(lambda: {'units': set(), 'defs': 0, 'uses': 0, 'var': None, 'du': set()})
        for r, w in W.items():
            x = W2[find(r)]; x['units'] |= w['units']; x['defs'] += w['defs']; x['uses'] += w['uses']; x['var'] = w['var']; x['du'] |= w['du']
        self.webs = collections.defaultdict(list)
        for r, w in W2.items(): self.webs[w['var']].append(Web(w['units'], w['defs'], w['uses'], w['du']))
        self.web_of = {}
        for v, ws in self.webs.items():
            for w in ws:
                for u in w.units: self.web_of[(v, u)] = w
