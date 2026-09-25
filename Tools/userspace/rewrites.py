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
    r"(?:[ \t]*\n)*"
    r"(?P<mid>(?:[ \t]*\w+ = [^\n{}]*;\n)*)"
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
        if pexpr == '&%s' % res:
            # the result variable IS the object (`DAT_x = storeWordConditionalIndexed(DAT_x + 1, 0, 0xADDR)`): only the CAS may store to it; a plain
            # store of the new value first made every CAS compare old+1 with old and loop forever (glprog std::string empty-rep refcount, issue #69)
            return '\n'.join([ind + '{', ind + '  int ghidra_old, ghidra_new;', ind + '  do {', ind + '    ghidra_old = *(int *)(%s);' % pexpr,
                              ind + '    ghidra_new = %s;' % val, ind + '  } while (!ghidra_cas32((void *)(%s), ghidra_old, ghidra_new));' % pexpr, ind + '}']) + '\n'
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
        if m.group('mid'):
            lines.extend(l for l in m.group('mid').rstrip('\n').split('\n'))     # a value computed from the loaded word before the conditional store
        self_obj = pexpr == '&%s' % res     # the result variable is the object itself: only the CAS may store to it (see single())
        if self_obj:
            lines[1] = ind + '  int ghidra_old, ghidra_new;'
            lines.append(ind + '    ghidra_new = %s;' % val)
        else:
            lines.append(ind + '    %s = %s;' % (res, val))
        if m.group('post'):
            lines.extend(l for l in m.group('post').rstrip('\n').split('\n'))
        lines.append(ind + '  } while (!ghidra_cas32((void *)(%s), ghidra_old, %s));' % (pexpr, 'ghidra_new' if self_obj else '(int)(%s)' % res))
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


def _addr_of_matches(body, nm):
    """positions of a unary address-of on `nm` (not a binary `a & nm`)"""
    res = []
    for m in re.finditer(r'&\s*%s\b(?!\s*\[)' % re.escape(nm), body):
        j = m.start() - 1
        while j >= 0 and body[j] in ' \t\n':
            j -= 1
        if j >= 0 and body[j] == ')':
            # `(unsigned char *)&x` is a cast of an address, `(a + b) & x` a binary and: look at what the parentheses hold
            d, i = 0, j
            while i >= 0:
                if body[i] == ')': d += 1
                elif body[i] == '(':
                    d -= 1
                    if d == 0: break
                i -= 1
            if i >= 0 and re.match(r'^\s*(?:const\s+)?[A-Za-z_][\w ]*?(?:\s*\*)+\s*$', body[i + 1:j]):
                res.append(m)
            continue
        if j >= 0 and (body[j].isalnum() or body[j] in '_]'):
            continue                         # binary and
        res.append(m)
    return res


def _sub_addr_of(body, nm, repl):
    out, last = [], 0
    for m in _addr_of_matches(body, nm):
        out.append(body[last:m.start()])
        out.append(repl)
        last = m.end()
    out.append(body[last:])
    return ''.join(out)


# ------------------------------------------------------------------------------------------------ byte buffers declared as scalars
BYTE_TYPES = ('char', 'undefined1', 'byte', 'uchar', 'undefined', 'unsigned char')
DECL = re.compile(r'(?m)^(\s+)([A-Za-z_][\w ]*?)[\s*]+((?:local|\w+Stack)_([0-9a-f]+))(?:\s*\[\s*(\d+)\s*\])?;')


def fix_byte_buffers(chunk):
    """Ghidra sometimes declares a stack buffer as one byte (`char local_140; undefined1 local_13f;`) and passes `&local_140` to a routine that fills
    a whole string; gcc lays the scalars out separately, so the routine overwrites neighbouring locals. Turn such a scalar (address taken, followed by
    a gap up to the next declared local) into a byte array of that size. Returns (chunk, number converted)."""
    decls = [(m, m.group(2).strip(), m.group(3), int(m.group(4), 16), m.group(5)) for m in DECL.finditer(chunk)]
    if not decls:
        return chunk, 0
    k = chunk.find('\n{')
    head, body = (chunk[:k], chunk[k:]) if k >= 0 else ('', chunk)
    offs = sorted({d[3] for d in decls}, reverse=True)      # X descending = address ascending
    n = 0
    for m, ty, nm, off, cnt in decls:
        if ty not in BYTE_TYPES or cnt is not None:
            continue
        if not _addr_of_matches(body, nm):
            continue
        lower = [o for o in offs if o < off]                 # declared locals at higher addresses
        gap = (off - lower[0]) if lower else 0
        # absorb following single-byte scalars of the run (off-1, off-2, ...)
        absorbed = []
        pos = off - 1
        while True:
            nxt = [d for d in decls if d[3] == pos and d[1] in BYTE_TYPES and d[4] is None]
            if not nxt:
                break
            absorbed.append(nxt[0])
            pos -= 1
        nextoff = [o for o in offs if o < off and o not in {a[3] for a in absorbed}]
        gap = off - nextoff[0] if nextoff else 0
        if gap < 2 + len(absorbed) * 0:
            continue
        size = max(gap, 1 + len(absorbed))
        body = _sub_addr_of(body, nm, '&%s[0]' % nm)
        body = re.sub(r'(?<![\w.])(?<!&)%s\b(?!\s*\[)(?!\[0\])' % re.escape(nm), '%s[0]' % nm, body)      # scalar uses -> element 0
        body = re.sub(r'&\s*%s\[0\]\[0\]' % re.escape(nm), '&%s[0]' % nm, body)
        body = re.sub(r'(?m)^(\s+)%s\s+%s\[0\];' % (re.escape(ty), re.escape(nm)), r'\1char %s[%d];' % (nm, size), body, count=1)
        # the declaration line itself was rewritten first, so restore it (the scalar-use rewrite above must not touch `char nm[size]`)
        for a in absorbed:
            body = re.sub(r'(?m)^\s+[A-Za-z_][\w ]*?\s+%s;\n' % re.escape(a[2]), '', body, count=1)
            body = re.sub(r'(?<![\w.])%s\b(?!\s*\[)' % re.escape(a[2]), '%s[%d]' % (nm, off - a[3]), body)
        n += 1
    return head + body, n


# ------------------------------------------------------------------------------------------------ stack structs declared as separate scalars
SIZE_OF = {'char': 1, 'byte': 1, 'undefined1': 1, 'uchar': 1, 'undefined': 1, 'bool': 1, 'short': 2, 'ushort': 2, 'undefined2': 2, 'word': 2,
           'int': 4, 'uint': 4, 'undefined4': 4, 'ulong': 4, 'long': 4, 'float': 4, 'dword': 4, 'undefined3': 4, 'size_t': 4,
           'undefined8': 8, 'double': 8, 'longlong': 8, 'ulonglong': 8}
CTYPE = {1: 'unsigned char', 2: 'unsigned short', 4: 'unsigned int', 8: 'unsigned long long'}
SIGNED = {'int': 'int', 'long': 'int', 'short': 'short', 'float': 'float', 'double': 'double', 'longlong': 'long long', 'char': 'char'}


def ctype_of(ty):
    return SIGNED.get(ty) or CTYPE[SIZE_OF[ty]]


def fix_struct_blocks(chunk):
    """A stack record Ghidra shows as `undefined4 local_88; undefined4 local_84; ...` whose first member's address is passed on (`&local_88`) is one
    contiguous object; gcc lays separate scalars out in any order. Merge the dense chain of scalar locals that follows an address-taken one into one
    int array and rewrite the members as typed accesses at their byte offsets. Returns (chunk, number of blocks)."""
    k = chunk.find('\n{')
    if k < 0:
        return chunk, 0
    head, body = chunk[:k], chunk[k:]
    decls = []
    for m in DECL.finditer(body):
        ty = m.group(2).strip()
        cnt = m.group(5)
        if '*' in m.group(0).split(m.group(3))[0]:      # pointer-typed local: keeps its own declaration
            continue
        decls.append(dict(m=m, ty=ty, nm=m.group(3), off=int(m.group(4), 16), cnt=cnt))
    by_off = {d['off']: d for d in decls}
    used = set()
    blocks = 0
    for d in sorted(decls, key=lambda d: -d['off']):
        nm = d['nm']
        if d['nm'] in used or d['cnt'] is not None or d['ty'] not in SIZE_OF or d['ty'] in BYTE_TYPES:
            continue
        if not _addr_of_matches(body, nm):
            continue
        # chain: members at decreasing X (increasing address): next member starts at off - size (allow up to 3 bytes of padding)
        chain = [d]
        cur = d
        while True:
            end = cur['off'] - SIZE_OF[cur['ty']]           # X of the byte just past `cur`
            nxt = None
            for pad in range(0, 4):
                c = by_off.get(end - pad)
                if c and c['cnt'] is None and c['ty'] in SIZE_OF and c['nm'] not in used:
                    nxt = c
                    break
            if not nxt:
                break
            chain.append(nxt)
            cur = nxt
        if len(chain) < 2:
            continue
        total = d['off'] - chain[-1]['off'] + SIZE_OF[chain[-1]['ty']]
        nwords = (total + 3) // 4
        base = 'blk_%s' % nm
        for c in chain:
            used.add(c['nm'])
        # a halfword member assigned CONCAT22(...) is really a word store over it and its neighbour
        for c in chain:
            if SIZE_OF[c['ty']] == 2:
                body = re.sub(r'(?m)^(\s*)%s = (CONCAT22\()' % re.escape(c['nm']), r'\1*(unsigned int *)&%s = \2' % c['nm'], body)
        # rewrite uses (members first: `&member` -> pointer, bare -> lvalue)
        for c in chain:
            delta = d['off'] - c['off']
            t = ctype_of(c['ty'])
            ptr = '((%s *)((char *)%s + %d))' % (t, base, delta)
            body = _sub_addr_of(body, c['nm'], ptr)
            body = re.sub(r'(?<![\w.])%s\b(?!\s*\[)' % re.escape(c['nm']), lambda _m, p=ptr: '(*%s)' % p, body)
        # declarations: replace the first, drop the rest
        first = True
        for c in chain:
            pat = r'(?m)^(\s+)%s\s+\(\*\(\(%s \*\)\(\(char \*\)%s \+ \d+\)\)\);\n?' % (re.escape(c['ty']), re.escape(ctype_of(c['ty'])), re.escape(base))
            body, n = re.subn(pat, (lambda mm: '%sunsigned int %s[%d] = { 0 };   /* zeroed: Ghidra splits a stored word into separately typed halves and leaves one half unassigned */\n' % (mm.group(1), base, nwords)) if first else '', body, count=1)
            if n:
                first = False
        blocks += 1
    return head + body, blocks


FRAME_SIZES = dict(SIZE_OF, **{'unsigned char': 1, 'signed char': 1, 'bool': 1, 'uchar': 1, 'unsigned int': 4, 'unsigned short': 2,
                                'unsigned long long': 8, 'long long': 8})


def mirror_frame(chunk):
    """Put every stack-frame variable of a function (`local_NN`, `xStack_NN`: Ghidra names them by their frame offset) into ONE array at its stock
    offset. The decompile shows a stack object as separate scalars (a std::vector as three pointers, a TParseContext as dozens of mixed-width
    fields) and gcc -O0 lays separate scalars out in any order, so a callee handed `&first_member` read the other members from unrelated slots
    (rebuilt ShCompile: _M_insert_aux on a split vector; TParseContext::initializeExtensionBehavior on a map inside a split TParseContext). The
    frame array reproduces the stock layout exactly - records, byte buffers and arrays that overlap their neighbours included - so it subsumes
    fix_byte_buffers / fix_struct_blocks / fix_pointer_records for the functions it handles (a function with a frame variable of unknown size is left
    to them). Returns (chunk, 1 if mirrored else 0)."""
    k = chunk.find('\n{')
    if k < 0:
        return chunk, 0
    head, body = chunk[:k], chunk[k:]
    end_decl = body.find('\n\n', 2)
    decl_part = body[:end_decl] if end_decl > 0 else body
    decls = []
    for m in DECL.finditer(decl_part):
        ty, nm, cnt = m.group(2).strip(), m.group(3), m.group(5)
        if ty in ('return', 'else', 'goto', 'case') or '(' in m.group(0):
            continue
        stars = m.group(0)[m.group(0).index(m.group(2)) + len(m.group(2)):m.group(0).index(nm)].count('*')
        size = 4 if stars else FRAME_SIZES.get(ty)
        if size is None:
            return chunk, 0                 # a struct-typed frame variable (dylib, dwarf_eh_bases): size unknown here
        n = int(cnt) if cnt else 1
        decls.append(dict(line=m.group(0), ty=ty + (' ' + '*' * stars if stars else ''), nm=nm, off=int(m.group(4), 16), size=size, n=n, arr=cnt is not None))
    if not decls:
        return chunk, 0
    top = max(d['off'] for d in decls)                     # lowest address
    total = max(top - d['off'] + d['size'] * d['n'] for d in decls)
    nq = (total + 7) // 8
    first = True
    for d in sorted(decls, key=lambda d: -d['off']):
        repl = ('%sunsigned long long ghidra_frame[%d] = { 0 };   /* the stock frame, variables at their offsets: rewrites.mirror_frame */' % (re.match(r'\s*', d['line']).group(0), nq)) if first else None
        body = body.replace(d['line'] + '\n', (repl + '\n') if repl else '', 1)
        first = False
    for d in decls:
        o = top - d['off']
        t = d['ty'] if (d['ty'].endswith('*') or d['ty'] in SIGNED or d['ty'] in ('unsigned char', 'signed char', 'unsigned int', 'unsigned short', 'long long', 'unsigned long long', 'bool')) else ctype_of(d['ty']) if d['ty'] in SIZE_OF else d['ty']
        if d['arr']:
            ptr = '((%s *)((char *)ghidra_frame + %d))' % (t, o)
            # `&(arr)` (the sub-piece rewrite's form `(unsigned char *)&(x) + k`) is the array's address too
            body = re.sub(r'&\s*\(\s*%s\s*\)' % re.escape(d['nm']), lambda _m, p=ptr: p, body)
            body = _sub_addr_of(body, d['nm'], ptr)
            body = re.sub(r'(?<![\w.])%s\b' % re.escape(d['nm']), lambda _m, p=ptr: p, body)
        else:
            if d['size'] == 2:
                # a halfword assigned CONCAT22(...) is a word store over it and its neighbour (as in fix_struct_blocks)
                body = re.sub(r'(?m)^(\s*)%s = (CONCAT22\()' % re.escape(d['nm']), r'\1(*(unsigned int *)((char *)ghidra_frame + %d)) = \2' % o, body)
            body = re.sub(r'(?<![\w.])%s\b' % re.escape(d['nm']), '(*(%s *)((char *)ghidra_frame + %d))' % (t, o), body)
    return head + body, 1


def fix_pointer_records(chunk):
    """fix_struct_blocks for records with POINTER members, which it leaves alone: a std::vector is three pointers (`void *local_180; int *local_17c;
    int *local_178;`) and `&local_180` is passed as the vector object - at -O0 the three locals were laid out in some other order, so
    vector<TSymbolTableLevel*>::_M_insert_aux read _M_finish/_M_end_of_storage from unrelated stack words and memcpy'd garbage (the rebuilt ShCompile,
    found by the GLSL differential test). Same rule: the dense chain of 4-byte (pointer or scalar) locals that starts at an address-taken one becomes
    one zeroed word array; members are rewritten as typed accesses at their byte offsets. Only chains with a pointer member are handled here, so the
    blocks fix_struct_blocks already made are untouched. Returns (chunk, number of blocks)."""
    k = chunk.find('\n{')
    if k < 0:
        return chunk, 0
    head, body = chunk[:k], chunk[k:]
    decls = []
    for m in DECL.finditer(body):
        if m.group(5) is not None:
            continue
        stars = m.group(0)[m.group(0).index(m.group(2)) + len(m.group(2)):m.group(0).index(m.group(3))].count('*')
        ty = m.group(2).strip()
        if stars:
            decls.append(dict(line=m.group(0), ty=ty + ' ' + '*' * stars, ptr=True, size=4, nm=m.group(3), off=int(m.group(4), 16)))
        elif SIZE_OF.get(ty) == 4:
            decls.append(dict(line=m.group(0), ty=ty, ptr=False, size=4, nm=m.group(3), off=int(m.group(4), 16)))
    by_off = {d['off']: d for d in decls}
    used, blocks = set(), 0
    for d in sorted(decls, key=lambda d: -d['off']):
        if d['nm'] in used or not _addr_of_matches(body, d['nm']):
            continue
        chain, cur = [d], d
        while True:
            nxt = by_off.get(cur['off'] - 4)
            if not nxt or nxt['nm'] in used:
                break
            chain.append(nxt)
            cur = nxt
        if len(chain) < 2 or not any(c['ptr'] for c in chain):
            continue
        base = 'blk_%s' % d['nm']
        # declarations: the first member's line becomes the block, the others go
        for i, c in enumerate(chain):
            used.add(c['nm'])
            indent = re.match(r'\s*', c['line']).group(0)
            repl = ('%sunsigned int %s[%d] = { 0 };   /* one stack record (pointer members): see rewrites.fix_pointer_records */' % (indent, base, len(chain))) if i == 0 else ''
            body = body.replace(c['line'] + '\n', (repl + '\n') if repl else '', 1)
        for c in chain:
            t = c['ty'] if c['ptr'] else ctype_of(c['ty'])
            ptr = '((%s *)((char *)%s + %d))' % (t, base, d['off'] - c['off'])
            body = _sub_addr_of(body, c['nm'], ptr)
            # a pointer member is also used with an index (`local_7c[i]`): that is an ordinary use of the pointer value
            body = re.sub((r'(?<![\w.])%s\b' if c['ptr'] else r'(?<![\w.])%s\b(?!\s*\[)') % re.escape(c['nm']), lambda _m, p=ptr: '(*%s)' % p, body)
        blocks += 1
    return head + body, blocks


def rewrite_double_bits(text):
    """`(double)CONCAT44(hi, lo)` is Ghidra's rendering of building a double from two words (the int->double magic-number idiom, 0x43300000 in the high
    word): a bit-pattern reinterpretation. ghidra_c.h's CONCAT44 yields an integer, so the C cast converted it numerically (~4.5e18)."""
    out, n = text, 0
    # (double)(CONCAT44(hi, lo) ^ K): the xor flips bits of the low word
    out, n0 = re.subn(r'\(double\)\(\s*CONCAT44\(([^,()]+),([^,()]+)\)\s*\^\s*(0x[0-9a-fA-F]+U?)\s*\)', r'GH_BITS_D(\1, (\2) ^ \3)', out)
    out, n1 = re.subn(r'\(double\)\s*CONCAT44\(', 'GH_BITS_D(', out)
    return out, n0 + n1


def rewrite_narrow_compares(text):
    """`bVar5 - 0x30 < 10` with a byte variable: Ghidra means the subtraction wraps in 8 bits (a digit test); C promotes to int, so any non-digit
    below '0' compares as a small negative number and the loop runs on."""
    n = 0
    for m in re.finditer(r'(?m)^\s+(?:byte|uchar|undefined1|char)\s+(bVar\d+|cVar\d+);', text):
        v = m.group(1)
        text, k = re.subn(r'(?<![\w.])%s - (0x[0-9a-f]+|\d+) < (0x[0-9a-f]+|\d+)' % v, r'(unsigned char)(%s - \1) < \2' % v, text)
        n += k
    return text, n


def rewrite_di3_calls(text):
    """libgcc's 64-bit shift helpers return their result in r3:r4. The corpus calls them through `int (*)()`, so the high word is all a caller sees and
    Ghidra's `extraout_r4` (the low word) is never assigned. Call them as returning a 64-bit value and assign extraout_r4 from it."""
    n = 0
    if 'extraout_r4' in text:
        text, k = re.subn(r'(?m)^(\s*)\(\(int \(\*\)\(\)\)(___(?:lshr|ashl|ashr)di3)\)\((.*)\);', r'\1extraout_r4 = (unsigned int)((unsigned long long (*)())\2)(\3);', text)
        n += k
    text, k = re.subn(r'\(\(int \(\*\)\(\)\)(___(?:lshr|ashl|ashr)di3)\)', r'((unsigned long long (*)())\1)', text)
    return text, n + k


def _is_fp_param(p):
    """'float' / 'double' for a by-value floating-point parameter (not a pointer to one), else ''"""
    m = re.match(r'^(float|double)\b([^\[]*)$', p.strip())
    return m.group(1) if m and '*' not in m.group(2) else ''


def float_protos(decl_lines):
    """name -> parameter type list, for the functions whose (typed) declaration has a float/double parameter"""
    protos = {}
    for ln in decl_lines:
        m = re.match(r'^extern [^;(]*?\b(\w+)\(([^;]*?)\)\s*asm\(', ln.replace('\n', ' '))
        if not m: continue
        ps = [p.strip() for p in split_args(m.group(2))]
        if any(_is_fp_param(p) for p in ps):
            protos[m.group(1)] = ps
    return protos


def split_args(a):
    out, d, cur, q = [], 0, '', False
    for ch in a:
        if ch == '"': q = not q
        if not q:
            if ch in '([': d += 1
            if ch in ')]': d -= 1
            if ch == ',' and d == 0: out.append(cur); cur = ''; continue
        cur += ch
    if cur.strip(): out.append(cur)
    return out


def rewrite_float_args(text, protos):
    """Ghidra renders a float held as its bit pattern (`0x3f800000`, `*(undefined4 *)(p + 0x18)`) as an integer expression at a call whose callee takes a `float`
    argument (passed in an FPR). The corpus calls such functions through an unprototyped cast, so the integer went out in a GPR and the callee read garbage from
    the FPR (and gcc turns a call of a `float`-taking function through such a cast into a trap). GH_ARGF/GH_ARGD (ghidra_link.h) pass a float/double expression unchanged and reinterpret an integer one as the float/double it holds."""
    n = 0
    out, pos = [], 0
    for m in re.finditer(r'\(\(\w[\w \*]*\(\*\)\(\)\)(\w+)\)\(', text):
        name = m.group(1)
        if name not in protos or m.start() < pos: continue
        i, d, q = m.end(), 1, False
        while i < len(text) and d:
            ch = text[i]
            if ch == '"' and text[i - 1] != '\\': q = not q
            elif not q:
                if ch == '(': d += 1
                elif ch == ')': d -= 1
            i += 1
        args = split_args(text[m.end():i - 1])
        ps = protos[name]
        new = []
        for k, a in enumerate(args):
            if k < len(ps) and _is_fp_param(ps[k]) == 'float': new.append(' GH_ARGF(%s)' % a.strip()); n += 1
            elif k < len(ps) and _is_fp_param(ps[k]) == 'double': new.append(' GH_ARGD(%s)' % a.strip()); n += 1
            else: new.append(a)
        head = text[pos:m.start()] + (name + '(' if any(_is_fp_param(p_) == 'float' for p_ in ps) else text[m.start():m.end()])   # a call through an unprototyped cast of a function with a float parameter is a gcc trap (float is not compatible with the K&R promotion): call it by its prototype
        out.append(head); out.append(','.join(new).lstrip() if new else ''); out.append(')'); pos = i
    out.append(text[pos:])
    return ''.join(out), n
