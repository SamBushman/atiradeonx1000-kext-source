#!/usr/bin/env python3
"""switch_case_audit.py - does every case of the stock's jump tables appear as a `case` label in the corpus function? (class #267)

  switch_case_audit.py STOCK_MACHO CORPUS_DIR LEDGER.tsv

Ghidra recovers a jump table's cases from the table; when several cases share a target it can drop them (they fall into the
default). The result is a switch with fewer cases than the stock. This audit does not look at the rebuilt image (so it is not
confused by the compiler choosing a compare tree or a different table layout): for every table dispatch of the stock function
(`cmplwi rN,bound; bgt default; ... lwzx; add; mtctr; bctr`, see jumptable_audit.py) it takes the non-default case indices,
adds the selector base that was subtracted before the bound check (`addi rD,rS,-base` / `addis` chains; 0 for a selector that
comes from a bit-field or a load), and looks the resulting case values up among the `case` labels of the corpus function (all of
its switches together; char / hex / negative / escaped literals are parsed, others counted as unparsed). The stock's case groups (indices that share a target) are classified: a group with only some of its values among
the corpus labels, or more than one group with none, means a case was lost (candidate for #267); exactly one group with none
is normal (Ghidra's `default:` stands for it - the default body must then be that group's code, check it once).
Limits: the labels of all switches of a function are pooled (a case in the wrong switch is not seen); a selector whose base
cannot be derived is tried at base 0 only.
"""
import sys, os, re, glob, struct
sys.path.insert(0, __file__.rsplit('/', 1)[0])
import capstone
import fn_norm_diff as fnd
from frame_slot_audit import stock_starts, next_start
import jumptable_audit as ja

MD = ja.MD

def sx(v):
    return v - 0x10000 if v & 0x8000 else v

def selector_base(ins, n_cmp, regname):
    """walk back from the cmplwi at index n_cmp to the instruction that defines the compared register and return the value that was
    subtracted (selector = reg + base). One step only, except that an `addi` may be fed by an `addis` (the pair that builds a big
    constant: addis r2,rS,-1; addi r9,r2,0x782b); further steps would follow writes that are not on the path."""
    base = 0
    reg = regname
    prev = None
    for j in range(n_cmp - 1, max(-1, n_cmp - 15), -1):
        i = ins[j]
        o = [x.strip() for x in i.op_str.split(',')]
        if not o or o[0] != reg:
            continue
        if i.mnemonic == 'addi' and len(o) == 3 and prev is None:
            base -= sx(int(o[2], 0) & 0xffff)
            reg, prev = o[1], 'addi'
        elif i.mnemonic == 'addis' and len(o) == 3 and prev == 'addi':
            base -= sx(int(o[2], 0) & 0xffff) << 16
            break
        elif i.mnemonic == 'subi' and len(o) == 3 and prev is None:
            base += sx(int(o[2], 0) & 0xffff)
            break
        else:
            break  # a load, a bit-field extract, ...: the selector value itself is what the corpus switches on
    return base & 0xffffffff

def stock_cases(raw, addr, get):
    """list of (bound, base, [case values that are not the default target])"""
    detail = []
    disp = ja.tables(raw, addr, get, detail)
    out = []
    for (b, tb, groups), (cmpinfo, ins) in zip(disp, detail):
        if not groups or cmpinfo is None:
            continue
        base = selector_base(ins, cmpinfo[0], cmpinfo[1])
        gv = [tuple(sorted(((k + base) & 0xffffffff) for k in g)) for g in groups]
        g0 = [tuple(sorted(g)) for g in groups]  # Ghidra often keeps the subtraction in the switch expression: the labels are then the raw indices
        out.append((b, base, gv, g0))
    return out

ESC = {'a': 7, 'b': 8, 't': 9, 'n': 10, 'v': 11, 'f': 12, 'r': 13, '0': 0, '\\': 92, "'": 39, '"': 34}

def parse_case(tok):
    tok = tok.strip()
    m = re.fullmatch(r"'(?:\\x([0-9a-fA-F]{1,2})|\\([abtnvfr0\\'\"])|(.))'", tok)
    if m:
        if m.group(1) is not None:
            return int(m.group(1), 16)
        if m.group(2) is not None:
            return ESC[m.group(2)]
        return ord(m.group(3))
    m = re.fullmatch(r"\(?[a-z ]*\*?\)?\s*(-?0x[0-9a-fA-F]+|-?\d+)[uUlL]*", tok)
    if m:
        return int(m.group(1), 0)
    m = re.fullmatch(r"'(\\[0-7]{1,3})'", tok)
    if m:
        return int(m.group(1)[1:], 8)
    return None

def corpus_functions(cdir):
    funcs = {}
    for f in sorted(glob.glob(os.path.join(cdir, 'part_*.c'))):
        text = open(f, errors='replace').read()
        heads = [(m.start(), m.group(1)) for m in re.finditer(r'^/\* (\S+) @ 0x[0-9a-fA-F]+ \(', text, re.M)]
        for k, (pos, name) in enumerate(heads):
            end = heads[k + 1][0] if k + 1 < len(heads) else len(text)
            funcs[name] = text[pos:end]
    return funcs

def case_values(body):
    vals, unparsed = set(), 0
    for m in re.finditer(r'^\s*case\s+([^:\n]+?)\s*:', body, re.M):
        v = parse_case(m.group(1))
        if v is None:
            unparsed += 1
            continue
        for w in (v & 0xffffffff, v & 0xff, v & 0xffff):
            vals.add(w)
    return vals, unparsed

def switches(text):
    """label sets of every switch of the function, each without its nested switches' labels"""
    out = []
    for m in re.finditer(r'\bswitch\s*\(', text):
        i = text.find('{', m.end())
        if i < 0:
            continue
        depth, j = 0, i
        while j < len(text):
            c = text[j]
            depth += (c == '{') - (c == '}')
            if depth == 0:
                break
            j += 1
        body = text[i + 1:j]
        # cut out nested switch bodies
        while True:
            n = re.search(r'\bswitch\s*\(', body)
            if not n:
                break
            k = body.find('{', n.end())
            if k < 0:
                break
            d, q = 0, k
            while q < len(body):
                d += (body[q] == '{') - (body[q] == '}')
                if d == 0:
                    break
                q += 1
            body = body[:n.start()] + body[q + 1:]
        out.append(case_values(body))
    return out

def main():
    stock, cdir, ledger = sys.argv[1:4]
    d = fnd.thin(stock)
    segs = [s for s in fnd.segments(d) if s[0] != '__PAGEZERO']
    def get(a, n):
        for name, vm, vs, fo, fs in segs:
            if vm <= a < vm + vs:
                return d[fo + a - vm:fo + a - vm + n]
        return b''
    funcs = corpus_functions(cdir)
    starts = stock_starts(ledger)
    seen, nfun, nbad, nun = set(), 0, 0, 0
    for l in open(ledger):
        p = l.rstrip('\n').split('\t')
        if len(p) < 5 or p[0].startswith('#') or p[1] in seen:
            continue
        name, sa, ssz = p[1], int(p[2], 16), min(int(p[4]), next_start(starts, int(p[2], 16)) - int(p[2], 16))
        seen.add(name)
        if name not in funcs:
            continue
        disp = stock_cases(get(sa, ssz), sa, get)
        if not disp:
            continue
        nfun += 1
        sw = switches(funcs[name])
        miss = []
        for b, base, gv, g0 in disp:
            best = None
            for cand in ((gv, g0) if g0 != gv else (gv,)):
                for have, unp in sw:
                    partial = [g for g in cand if any(v in have for v in g) and not all(v in have for v in g)]
                    absent = [g for g in cand if not any(v in have for v in g)]
                    score = (len(partial) + max(0, len(absent) - 1), len(absent))
                    if best is None or score < best[0]:
                        best = (score, partial, absent)
            if best is None:
                miss.append((b, base, len(gv), None, None))  # the corpus has no switch at all (an if chain?)
            elif best[0][0]:
                miss.append((b, base, len(gv), best[1], best[2]))
        if miss:
            nbad += 1
            print('%-44s stock %x/%d, %d dispatches, %d corpus switches (%d case labels not parsed as numbers)' % (name, sa, ssz, len(disp), len(sw), sum(u for h, u in sw)))
            for b, base, ng, partial, absent in miss:
                if partial is None:
                    print('      bound %d base 0x%x, %d case groups: NO switch in the corpus function (if chain?) - check by reading' % (b, base, ng))
                else:
                    print('      bound %d base 0x%x, %d case groups: best switch has partial groups %s; absent groups %s' % (
                        b, base, ng, [[hex(v) for v in g] for g in partial][:6], [[hex(v) for v in g][:8] for g in absent][:6]))
    print('# %d functions with a stock table dispatch checked, %d have a case group with lost labels or several absent groups' % (nfun, nbad), file=sys.stderr)

if __name__ == '__main__':
    main()
