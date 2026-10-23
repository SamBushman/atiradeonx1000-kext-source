#!/usr/bin/env python3
"""espec.py DIR FUNCTION SPEC.tsv - emit_webs.py with idiom keywords: in the WEBS column `@COPYIDX` / `@NCPY` stand for all webs of VAR that wsum.py tags COPYIDX / NCPY
(`@COPYIDX,5` mixes keywords and web numbers). Prints rows for apply_names.py."""
import sys, os, re, subprocess, tempfile
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import find_webs as F

def tags(body, brace, v, nodes, entry):
    w, _ = F.webs(nodes, entry, v)
    out = {}
    for k in range(len(w)):
        txt = [body[x].strip() for x in w[k]]
        if any(re.match(r'^%s = 0;$' % v, t) for t in txt) and any(re.search(r'\b%s\b.*= cVar\d+;$' % v, t) for t in txt): out.setdefault('COPYIDX', []).append(k)
        elif txt and '_ncpy' in txt[0]: out.setdefault('NCPY', []).append(k)
        else:
            m = re.match(r'^%s = (\w+) \+ 1;$' % v, txt[0]) if txt else None
            if m and any(t == '%s = %s;' % (m.group(1), v) for t in txt): out.setdefault('NEXTIDX', []).append(k)
    return out

def main():
    d, fn, spec = sys.argv[1:4]
    body, brace = F.load(d, fn); nodes, entry = F.build_cfg(body, brace)
    lines = []
    for l in open(spec):
        if not l.strip() or l.startswith('#'): continue
        c = l.rstrip('\n').split('\t')
        if '@' in c[1]:
            t = tags(body, brace, c[0], nodes, entry); ws = []
            for item in c[1].split(','):
                ws += [str(x) for x in t.get(item[1:], [])] if item.startswith('@') else [item]
            c[1] = ','.join(ws)
            if not c[1]: continue
        lines.append('\t'.join(c))
    tf = tempfile.NamedTemporaryFile('w', suffix='.tsv', delete=False); tf.write('\n'.join(lines) + '\n'); tf.close()
    r = subprocess.run([sys.executable, os.path.join(os.path.dirname(os.path.abspath(__file__)), 'emit_webs.py'), d, fn, tf.name], capture_output=True, text=True)
    os.unlink(tf.name); sys.stdout.write(r.stdout); sys.stderr.write(r.stderr)
    sys.exit(r.returncode)
main()
