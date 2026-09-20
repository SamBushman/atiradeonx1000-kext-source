#!/usr/bin/env python3
"""detect_short_calls.py CORPUS_DIR [CORPUS_DIR...] - calls that pass fewer arguments than the callee's definition has parameters (`f(a, b)` for `f(a, b, c)`),
the partial form of the dropped-register-argument rendering (detect_dropped_args.py finds the all-dropped form). A callee parameter that its own body reads only
on some paths can legitimately be unset at a call, so the list is candidates to check against the machine code, not a defect count. Prints one line per call."""
import re, glob, sys, collections

def split_args(a):
    out, d, cur, q = [], 0, '', False
    i = 0
    while i < len(a):
        ch = a[i]
        if ch == '"' and (i == 0 or a[i - 1] != '\\'): q = not q
        if not q:
            if ch in '([': d += 1
            if ch in ')]': d -= 1
            if ch == ',' and d == 0: out.append(cur); cur = ''; i += 1; continue
        cur += ch; i += 1
    if cur.strip(): out.append(cur)
    return out

def main(dirs, quiet=False):
    total = 0
    for d in dirs:
        files = sorted(glob.glob(d + '/part_*.c'))
        texts = {f: open(f).read() for f in files}
        nparams, variadic = {}, set()
        for t in texts.values():
            for m in re.finditer(r'(?m)^/\* (\S+) @ 0x[0-9a-f]+ \(\d+ bytes\) \*/\n((?:[^\n{]*\n)+?)\{', t):
                hdr = re.sub(r'\s+', ' ', m.group(2))
                i = hdr.find(m.group(1) + '(')
                if i < 0: continue
                j = i + len(m.group(1)) + 1; dpt = 1; k = j
                while k < len(hdr) and dpt:
                    dpt += (hdr[k] == '(') - (hdr[k] == ')'); k += 1
                params = split_args(hdr[j:k - 1])
                params = [p for p in params if p.strip() and p.strip() != 'void']
                if any(p.strip() == '...' for p in params): variadic.add(m.group(1))
                nparams[m.group(1)] = len(params)
        rows = []
        rx = re.compile(r'(?:\(\([\w \*]*\(\*\)\(\)\)(\w+)\)|(?<![\w.>&])(\w+))\(')
        for f, t in texts.items():
            for m in rx.finditer(t):
                n = m.group(1) or m.group(2)
                if n not in nparams or n in variadic: continue
                # skip the definition header itself
                ls = t.rfind('\n', 0, m.start()) + 1
                if not t[ls:m.start()].strip() == '' and False: pass
                i = m.end(); dpt = 1; q = False
                while i < len(t) and dpt:
                    ch = t[i]
                    if ch == '"' and t[i - 1] != '\\': q = not q
                    elif not q:
                        if ch == '(': dpt += 1
                        elif ch == ')': dpt -= 1
                    i += 1
                if t[i:i + 1] not in (';', ',', ')', ' ', '\n') and False: continue
                args = [a for a in split_args(t[m.end():i - 1]) if a.strip()]
                # a definition header: `name(p1, p2)` at line start followed by newline and `{` or a K&R declaration line
                if re.match(r'^[\w \*]*$', t[ls:m.start()]) and re.match(r'\s*\n(?:[^\n;{]*;\n)*\{|\s*\n\s*(?:\w[\w \*]*;\n)+\{', t[i:i + 400]): continue
                if len(args) < nparams[n]:
                    rows.append((f.split('/')[-1], n, len(args), nparams[n]))
        if not quiet:
            for r in rows: print('%s: %s called with %d of %d arguments' % r)
        print('%s: %d calls with fewer arguments than parameters (%d callees)' % (d, len(rows), len({r[1] for r in rows})))
        total += len(rows)
    return total

if __name__ == '__main__':
    main(sys.argv[1:])
