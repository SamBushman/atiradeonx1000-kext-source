"""rewrites.py - link-time semantic fixes for Ghidra-derived corpus text (used by link_corpus.py).

The corpora are compile-clean C that makes the same calls as the stock code; some Ghidra renderings are not executable as they stand:

  * the lwarx/stwcx. read-modify-write idiom (`do { x = *p; if (in_RESERVE != 0) { y = storeWordConditionalIndexed(x - 1, 0, p); *p = y; in_cr0 = 2; } }
    while (!(in_cr0 >> 1 & 1))`): `in_RESERVE`/`in_cr0` are undefined pseudo-registers, the loop never stores. Rewritten as a compare-and-swap loop
    around a real lwarx/stwcx. (`ghidra_cas32`, ghidra_link.h);
  * call sites Ghidra prints by SHORT C++ name (`error(...)`, `TFunction(this, ...)`, `append(...)`): the callee is one of several functions of that
    short name. `bind_calls` resolves each against the callees the stock machine code of the same function really makes.
"""
import re

ATOMIC = re.compile(
    r"(?P<ind>[ \t]*)do \{\n"
    r"(?P<ld>[ \t]*(?P<old>\w+) = (?:\([^)]*\))?\*(?:\([^)]*\))?(?P<lp>\w+);\n)?"
    r"[ \t]*if \(in_RESERVE != '\\0'\) \{\n"
    r"[ \t]*(?P<res>\w+) = (?:\([^)]*\))?storeWordConditionalIndexed\((?P<val>.*),0,(?P<ptr>[^,;]+)\);\n"
    r"(?:[ \t]*\*(?:\([^)]*\))?(?P<sp>\w+) = (?P=res);\n)?"
    r"[ \t]*(?P<cr>\w+) = (?:2|true);\n"
    r"[ \t]*\}\n"
    r"(?P<post>(?:[ \t]*[^\n{}]*;\n)*?)"
    r"[ \t]*\} while \(!(?:\(bool\)\((?P=cr) >> 1(?: & 1)?\)|(?P=cr))\);")


SINGLE = re.compile(
    r"(?P<ind>[ \t]*)if \(in_RESERVE != '\\0'\) \{\n"
    r"[ \t]*(?P<res>\w+) = (?:\([^)]*\))?storeWordConditionalIndexed\((?P<val>.*),0,(?P<ptr>[^,;]+)\);\n"
    r"(?:[ \t]*\*(?:\([^)]*\))?(?P<sp>\w+) = (?P=res);\n)?"
    r"[ \t]*\}\n")


def rewrite_atomics(text):
    n = [0]
    # a call/assignment wrapped over lines
    text = re.sub(r'=\n[ \t]+storeWordConditionalIndexed\n[ \t]+\(', '= storeWordConditionalIndexed(', text)
    text = re.sub(r'storeWordConditionalIndexed\(\n[ \t]+', 'storeWordConditionalIndexed(', text)
    text = re.sub(r'\n[ \t]+(,0,)', r'\1', text)

    def single(m):
        n[0] += 1
        ind = m.group('ind')
        res, val, ptr = m.group('res'), m.group('val'), m.group('ptr').strip()
        if m.group('sp') is None and re.match(r'^0x[0-9a-f]+$', ptr):
            pexpr = '&%s' % res
            val = re.sub(r'\b%s\b' % re.escape(res), 'ghidra_old', val)
        else:
            pexpr = ptr
            val = re.sub(r'\*(?:\([^)]*\))?%s\b' % re.escape(m.group('sp') or ptr), 'ghidra_old', val)
        return '\n'.join([ind + '{', ind + '  int ghidra_old;', ind + '  do {', ind + '    ghidra_old = *(int *)(%s);' % pexpr, ind + '    %s = %s;' % (res, val),
                          ind + '  } while (!ghidra_cas32((void *)(%s), ghidra_old, (int)(%s)));' % (pexpr, res), ind + '}']) + '\n'

    def sub(m):
        n[0] += 1
        ind = m.group('ind')
        res, val, ptr = m.group('res'), m.group('val'), m.group('ptr').strip()
        old = m.group('old')
        if m.group('sp') is None and re.match(r'^0x[0-9a-f]+$|^\(?unsigned', ptr):
            # `DAT_x = storeWordConditionalIndexed(DAT_x + 1, 0, 0xADDR)`: the result variable is the object itself
            pexpr = '&%s' % res
            val = re.sub(r'\b%s\b' % re.escape(res), 'ghidra_old', val)
        else:
            pexpr = ptr
            p = re.escape(m.group('sp') or m.group('lp') or ptr)
            val = re.sub(r'\*(?:\([^)]*\))?%s\b' % p, 'ghidra_old', val)
        lines = [ind + '{', ind + '  int ghidra_old;', ind + '  do {', ind + '    ghidra_old = *(int *)(%s);' % pexpr]
        if old:
            lines.append(ind + '    %s = %s ghidra_old;' % (old, '(int)'))
        lines.append(ind + '    %s = %s;' % (res, val if m.group('sp') is not None or old or True else val))
        if m.group('post'):
            lines.extend(l for l in m.group('post').rstrip('\n').split('\n'))
        lines.append(ind + '  } while (!ghidra_cas32((void *)(%s), ghidra_old, (int)(%s)));' % (pexpr, res))
        lines.append(ind + '}')
        return '\n'.join(lines)

    out = ATOMIC.sub(sub, text)
    out = SINGLE.sub(single, out)
    return out, n[0]


# ------------------------------------------------------------------------------------------------ call binding
KEYWORDS = {'if', 'while', 'for', 'switch', 'return', 'sizeof', 'else', 'do', 'case', 'goto', 'defined'}


def parse_callees(dis_path, ledger, sym_addr=None):
    """{function address: [target address or ('import', name) ... in instruction order]} from an `otool -tV` listing; ledger = [(addr, size, cname)]"""
    import bisect
    starts = [a for a, s, n in ledger]
    ends = {a: a + max(s, 4) for a, s, n in ledger}
    order = sorted(starts)
    res = {a: [] for a in starts}
    rx = re.compile(r'^([0-9a-f]{8})\t(bl|b|bla)\t(0x[0-9a-f]+|[A-Za-z_][^\s;]*)(?:\s*;\s*symbol stub for:\s*(\S+))?')
    sym_addr = sym_addr or {}
    for line in open(dis_path):
        m = rx.match(line)
        if not m:
            continue
        a = int(m.group(1), 16)
        k = bisect.bisect_right(order, a) - 1
        if k < 0:
            continue
        f = order[k]
        if a >= ends[f]:
            continue
        if m.group(3).startswith('0x'):
            tgt = int(m.group(3), 16)
        elif m.group(3) in sym_addr:
            tgt = sym_addr[m.group(3)]
        else:
            res[f].append(('import', m.group(3)))
            continue
        if m.group(4):
            res[f].append(('import', m.group(4)))
        elif m.group(2) == 'bl' or not (f <= tgt < ends[f]):
            res[f].append(tgt)
    return res


def bind_calls(chunk, faddr, ledger_by_addr, short_to_c, siblings, callees, unresolved):
    """Replace short/ambiguous C++ call names in one function's text with the ledger name of the callee the stock code makes."""
    known = set(ledger_by_addr.values())
    addr_of = {n: a for a, n in ledger_by_addr.items()}
    called = [t for t in callees.get(faddr, []) if isinstance(t, int)]
    out = []
    counters = {}

    def pick(token, cands):
        cset = [c for c in cands if addr_of.get(c) in called]
        if len(cset) == 1:
            return cset[0]
        if len(cset) > 1:
            # k-th textual occurrence <-> k-th stock call to any of these candidates, in instruction order
            seq = [ledger_by_addr[t] for t in called if ledger_by_addr.get(t) in cset]
            k = counters.get(token, 0)
            counters[token] = k + 1
            return seq[k] if k < len(seq) else seq[-1]
        return None

    def sub(m):
        token = m.group(1)
        if token in KEYWORDS:
            return m.group(0)
        if token in known:
            sibs = siblings.get(token)
            if sibs and len(sibs) > 1:
                r = pick(token, sibs)
                if r and r != token:
                    return m.group(0).replace(token, r, 1)
            return m.group(0)
        cands = short_to_c.get(token)
        if not cands:
            return m.group(0)
        r = pick(token, cands)
        if r is None and len(cands) == 1:
            r = cands[0]
        if r is None:
            # the caller's own class is the most likely owner of a method of that short name
            cls = (ledger_by_addr.get(faddr) or '').split('__')[0]
            same = [c for c in cands if c.split('__')[0] == cls]
            if same:
                r = same[0]
                unresolved.append((ledger_by_addr.get(faddr), token + ' -> ' + r + ' (same class, not confirmed by the stock call list)', len(cands)))
        if r is None:
            unresolved.append((ledger_by_addr.get(faddr), token, len(cands)))
            return m.group(0)
        return m.group(0).replace(token, r, 1)
    k = chunk.find('\n{')
    head, body = (chunk[:k], chunk[k:]) if k >= 0 else ('', chunk)      # the definition header is not a call
    return head + re.sub(r'(?<![\w.>])(~?[A-Za-z_]\w*)\s*\(', sub, body)
