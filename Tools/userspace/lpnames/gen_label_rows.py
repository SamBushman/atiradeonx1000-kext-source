#!/usr/bin/env python3
"""gen_label_rows.py DIR OUT.tsv [--stem NAME] - `local` rows naming the LAB_<addr> goto labels and switchD_<addr>_* case labels of the part_*.c files of DIR.

The name says what the code at the label does, the same scheme as GLDriver names_r03_labels.tsv: <verb><First variable or callee> (set/store/add/call/check/return),
`loop` in front when a goto reaches the label from below it; switch labels are <switch variable>Case<N> / <switch variable>Default. A label whose next statement tells nothing
(`}`, `;`, `do {`, `goto`, `break`, an indirect call, only Ghidra placeholders) is left alone and listed on stderr. Names are unique among the labels of one function."""
import re, sys, glob, os, collections

d, out = sys.argv[1], sys.argv[2]
TYPES = set('int uint char uchar short ushort long ulong float double void unsigned signed bool byte word dword qword code undefined undefined1 undefined2 undefined4 undefined8 size_t const struct'.split())
KW = set('if else while for do switch case default return goto break continue sizeof'.split())
H = re.compile(r'^/\* (\S+) @ 0x[0-9a-f]+')
LABEL = re.compile(r'^(LAB_[0-9a-f]{6,8}|switchD_[0-9a-f]{6,8}_\w+):\s*$')
IDENT = re.compile(r'[A-Za-z_][A-Za-z0-9_]*')
PLACEHOLDER = re.compile(r'^(?:extraout_\w+|\w*Stack_[0-9a-f]+|fparam_\w+|in_\w+|[a-z]{0,4}Var\d+|local_[0-9a-f]+|param_\d+|FUN_[0-9a-f]+|DAT_[0-9a-f]+|PTR_\w+|unaff_\w+)$')


def firstvar(text):
    for m in IDENT.finditer(text):
        w = m.group(0)
        if w in TYPES or w in KW or PLACEHOLDER.match(w) or w.startswith(('LAB_', 'switchD_')):
            continue
        if re.match(r'^[0-9]', w): continue
        return w
    return None


def cap(w):
    w = w.lstrip('_')
    if '__' in w:                                   # Class__method -> Class_method
        w = w.replace('__', '_')
        return w[:1].upper() + w[1:]
    return ''.join(p[:1].upper() + p[1:] for p in w.split('_') if p)


def callee(stmt):
    m = re.match(r'^\(\(\s*[^)]*\(\*\)\([^)]*\)\s*\)\s*([A-Za-z_]\w*)\s*\)\s*\(', stmt)        # ((int (*)())Name)(
    if m: return m.group(1)
    m = re.match(r'^(?:\([^)]*\)\s*)?([A-Za-z_]\w*)\s*\(', stmt)
    if m and m.group(1) not in KW and m.group(1) not in TYPES: return m.group(1)
    return None


def name_for(stmt, backward):
    s = stmt.strip()
    if not s or s in ('}', ';', '{') or s.startswith(('do', 'goto', 'break', 'continue', 'default', 'case', '/*', '//', 'switch')): return None
    verb = obj = None
    m = re.match(r'^(.*?)(\s[-+*/|&^]?=\s|\s(?:<<|>>)=\s)(.*)$', s) if not s.startswith(('if', 'while', 'for', 'return')) else None
    if m:
        lhs, op = m.group(1).strip(), m.group(2).strip()
        deref = lhs.startswith('*') or '[' in lhs or lhs.startswith('(')
        obj = firstvar(lhs)
        verb = 'store' if deref else ('add' if op == '+=' else 'set')
    elif re.match(r'^(\+\+|--)', s) or re.search(r'(\+\+|--);$', s):
        verb, obj = 'add', firstvar(s)
    elif s.startswith('return'):
        verb, obj = 'return', firstvar(s[6:])
    elif s.startswith(('if', 'while', 'for')):
        verb, obj = 'check', firstvar(re.sub(r'^(if|while|for)\s*', '', s))
    else:
        c = callee(s)
        if c: verb, obj = 'call', c
    if not verb or not obj: return None
    base = verb + cap(obj)
    if backward: base = 'loop' + base[:1].upper() + base[1:]
    return base if re.match(r'^[A-Za-z_]\w*$', base) else None


def nextstmt(lines, i):
    j = i + 1
    while j < len(lines):
        t = lines[j].strip()
        if t and not t.startswith(('/*', '//')) and not LABEL.match(t): return t
        if LABEL.match(t):
            j += 1; continue
        j += 1
    return ''


rows = []; skipped = []
for pf in sorted(glob.glob(os.path.join(d, 'part_*.c'))):
    lines = open(pf, errors='replace').read().split('\n')
    heads = [(i, H.match(l).group(1)) for i, l in enumerate(lines) if H.match(l)]
    for k, (hi, fn) in enumerate(heads):
        end = heads[k + 1][0] if k + 1 < len(heads) else len(lines)
        body = lines[hi:end]
        used = collections.Counter(); taken = set()
        labels = [(i, LABEL.match(l).group(1)) for i, l in enumerate(body) if LABEL.match(l)]
        if not labels: continue
        gotos = collections.defaultdict(list)
        for i, l in enumerate(body):
            for m in re.finditer(r'goto\s+((?:LAB|switchD)_\w+)\s*;', l): gotos[m.group(1)].append(i)
        for li, lab in labels:
            fwd = sum(1 for g in gotos[lab] if g < li); bwd = sum(1 for g in gotos[lab] if g > li)
            nm = None; ev = None
            if lab.startswith('switchD_'):
                m = re.match(r'switchD_[0-9a-f]+_(default|caseD_([0-9a-f]+))$', lab)
                sw = None
                for g in gotos[lab]:
                    ind = len(body[g]) - len(body[g].lstrip())
                    for u in range(g - 1, -1, -1):
                        mm = re.match(r'^(\s*)switch\s*\((.*)\)\s*\{?\s*$', body[u])
                        if mm and len(mm.group(1)) < ind:
                            sw = firstvar(mm.group(2)); break
                    if sw: break
                if m and sw:
                    nm = sw + ('Default' if m.group(1) == 'default' else 'Case' + m.group(2))
                    ev = '%s of the switch on %s; %d goto(s)' % ('default' if m.group(1) == 'default' else 'case ' + m.group(2), sw, len(gotos[lab]))
            else:
                st = nextstmt(body, li)
                nm = name_for(st, bwd > 0)
                ev = 'resumes at "%s"; %d forward, %d backward goto(s)' % (st[:70].replace('\t', ' '), fwd, bwd)
            if not nm:
                skipped.append((fn, lab)); continue
            n, cand = 1, nm
            while cand in taken:
                n += 1; cand = nm + str(n)
            taken.add(cand)
            rows.append(('local', fn, lab, cand, 'INFERRED', ev))

with open(out, 'w') as w:
    w.write('# label rows: %s LAB_<addr> goto labels and switchD_<addr>_* case labels (gen_label_rows.py). The new name says what the code at the label does\n' % os.path.basename(os.path.dirname(os.path.abspath(d))) )
    for r in rows: w.write('\t'.join(r) + '\n')
sys.stderr.write('%d rows, %d labels left (no informative next statement)\n' % (len(rows), len(skipped)))
for fn, lab in skipped: sys.stderr.write('SKIP %s %s\n' % (fn, lab))
