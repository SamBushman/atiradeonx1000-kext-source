#!/usr/bin/env python3
"""autoweb.py DIR OUT.tsv [PARTLO PARTHI] [--dry] : name placeholder webs from the parameter names of the named callees they are passed to.

For every function of DIR/part_LO..HI.c and every placeholder variable still present in its current text, find the def-use webs (find_webs.py);
a web whose uses pass the variable ALONE as an argument to a function whose header has real parameter names votes for that name; a web whose votes
are unanimous gets the name (several webs of one function/name get a numeric suffix; names already used in the function are skipped).
Parameters (ENTRY webs) get whole-function `local` rows under the same rule.  Rows are appended to OUT.tsv (apply_names.py `use`/`local` rows)."""
import sys, re, glob, os, collections, subprocess, tempfile
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
import find_webs as F
import apply_names as A
d, out = sys.argv[1:3]
lo = int(sys.argv[3]) if len(sys.argv) > 3 and sys.argv[3].isdigit() else 0
hi = int(sys.argv[4]) if len(sys.argv) > 4 and sys.argv[4].isdigit() else 999
dry = '--dry' in sys.argv
VEC = '--vec' in sys.argv
INSTF = '--instfield' in sys.argv
PH = re.compile(r'^(?:[A-Za-z]{0,4}Var\d+|p+_?[A-Za-z]*Var\d+|local_[0-9a-f]+|param_\d+|in_[a-z]+\d*)$')
SKIP = {'set', 'index', 'size', 'value', 'result', 'p', 'n', 'x', 'a', 'b', 'ptr', 'data', 'count', 'flags', 'ctx', 'param_1', 'param_2', 'param_3', 'param_4', 'this', 'arg', 'val', 'len', 'i', 'j', 'k', 'v', 'obj', 'self', 'state', 'type', 'name', 'buf', 'buffer', 'str', 'string', 'p1', 'p2'}
H = re.compile(r'^/\* (\S+) @ 0x')
sig = {}
funcs = collections.OrderedDict()
for pf in sorted(glob.glob(d + '/part_*.c')):
    L = open(pf, errors='replace').read().split('\n')
    pn = int(re.search(r'part_(\d+)', pf).group(1))
    for i, l in enumerate(L):
        m = H.match(l)
        if m:
            fn = m.group(1); mm = re.match(r'^[\w \*]*?(\w+)\((.*)\)\s*$', L[i + 1])
            sig[fn] = [p.strip().split()[-1].lstrip('*') for p in mm.group(2).split(',')] if mm and mm.group(2).strip() else []
            if lo <= pn <= hi: funcs[fn] = pn
def args(s):
    o = []; dd = 0; c = ''
    for ch in s:
        if ch in '([': dd += 1
        if ch in ')]': dd -= 1
        if ch == ',' and dd == 0: o.append(c.strip()); c = ''
        else: c += ch
    o.append(c.strip()); return o
CALL = re.compile(r'\b(\w+)\(')
INSTF = [r'\(%s \+ 0x(?:11c|120|124|12c|160)\)', r'\b%s\[0x(?:22|47|48|49|4b|58)\]', r'\(%s\[0x22\] \+ 8\)']
VECOBJ = {0: 'vectorCapacity', 1: 'vectorFilledCount', 2: 'vectorData'}
VECALLOC = {1: 'vectorCapacity', 2: 'vectorSize', 3: 'vectorData'}
def vecvote(line, var):
    m = re.match(r'^\s*%s = (?:\([\w ]+\*?\))?(vector\d*|vectorAlloc\d*)\[(\d+)\];$' % re.escape(var), line)
    if m:
        t = VECALLOC if m.group(1).startswith('vectorAlloc') else VECOBJ
        return [t[int(m.group(2))]] if int(m.group(2)) in t else []
    m = re.match(r'^\s*%s = (?:\([\w ]+\*+\))?\(?(?:\w+ \* 4 \+ )(vector\d*)\[2\]\)?;$' % re.escape(var), line)
    if m: return ['elementRef']
    m = re.match(r'^\s*%s = (?:\([\w ]+\*+\))?\(?(?:\w+ \* 4 \+ )(vectorAlloc\d*)\[3\]\)?;$' % re.escape(var), line)
    if m: return ['elementRef']
    return []
IFIELD = {0x84: 'operandCount', 0x120: 'saturate', 0x124: 'resultScaleCode', 0x11c: 'predicateKind', 0x12c: 'compareCondition', 0x160: 'instCounter', 0x14: 'instFlags', 0x94: 'destRegister', 0x98: 'destRegisterOffset', 0xb8: 'source1Flags', 0xd0: 'source2Flags', 0x88: 'opcodeInfo'}
IBASE = r'(?:inst\d*|sourceDef\d*|newInst\d*|afterInst|consumerInst\d*|defInst\d*)'
def ifvote(line, var):
    m = re.match(r'^\s*%s = (?:\([\w ]+\*?\))?\*\((?:int|uint|undefined4) \*\)\(%s \+ (0x[0-9a-f]+)\);$' % (re.escape(var), IBASE), line)
    if m and int(m.group(1), 16) in IFIELD: return [IFIELD[int(m.group(1), 16)]]
    m = re.match(r'^\s*%s = %s\[(0x[0-9a-f]+)\];$' % (re.escape(var), IBASE), line)
    if m and int(m.group(1), 16) * 4 in IFIELD: return [IFIELD[int(m.group(1), 16) * 4]]
    return []
def votes(line, var):
    if INSTF: return ifvote(line, var)
    if VEC: return vecvote(line, var)
    v = []
    for pat in INSTF:
        if re.search(pat % re.escape(var), line): v.append('inst'); break
    for m in CALL.finditer(line):
        cal = m.group(1)
        if cal not in sig: continue
        j = m.end(); dd = 1; k = j
        while k < len(line) and dd > 0:
            if line[k] == '(': dd += 1
            elif line[k] == ')': dd -= 1
            k += 1
        a = args(line[j:k - 1])
        for pos, x in enumerate(a):
            x2 = re.sub(r'^\((?:[\w \*]+)\)', '', x).strip()
            if x2 == var and pos < len(sig[cal]):
                nm = sig[cal][pos]
                if nm and not PH.match(nm) and nm not in SKIP and re.match(r'^[a-z]\w*$', nm): v.append(nm)
    return v
P = re.compile(r'\b(param_[0-9]+|[A-Za-z]{0,4}Var[0-9]+|p+_?[A-Za-z]*Var[0-9]+|local_[0-9a-f]+|in_[a-z]+[0-9]*)\b')
rows = []; stat = collections.Counter()
for fn, pn in funcs.items():
    try:
        body, brace = F.load(d, fn); nodes, entry = F.build_cfg(body, brace)
    except BaseException: continue
    cur = F.CURRENT
    idents = set(re.findall(r'[A-Za-z_]\w*', '\n'.join(cur)))
    names = sorted({m for l in cur[brace + 1:] if not re.match(r'\s*(/\*|\*|//)', l) for m in P.findall(l)})
    used = collections.Counter(); spec = []
    for var in names:
        try: ws, er = F.webs(nodes, entry, var)
        except BaseException: stat['refused'] += 1; continue
        isparam = var.startswith(('param_', 'in_'))
        cand = []
        for k, ls in enumerate(ws):
            if not any(re.search(r'(?<![\w])%s(?![\w])' % re.escape(var), cur[x]) for x in ls): continue   # already renamed
            vs = []
            for x in ls: vs += votes(cur[x], var)
            if VEC or INSTF:
                ndef = sum(1 for x in ls if re.search(r'(?<![\w])%s\s*=(?!=)' % re.escape(var), cur[x]))
                if len(vs) != ndef: continue
            if vs and len(set(vs)) == 1: cand.append((k, vs[0], len(vs)))
        if not cand: continue
        if isparam:
            if len(ws) != 1 or len(cand) != 1: continue
            nm = cand[0][1]
            if nm in idents or used[nm]: nm2 = nm + str(used[nm] + 1)
            else: nm2 = nm
            if nm2 in idents: continue
            used[nm] += 1; idents.add(nm2)
            rows.append('local\t%s\t%s\t%s\tINFERRED\tpassed as parameter %s of callees (%d uses, unanimous)' % (fn, var, nm2, nm, cand[0][2])); stat['param'] += 1
        else:
            for k, nm, nv in cand:
                nm2 = nm if (nm not in idents and not used[nm]) else nm + str(used[nm] + 1)
                while nm2 in idents: used[nm] += 1; nm2 = nm + str(used[nm] + 1)
                used[nm] += 1; idents.add(nm2)
                spec.append('%s\t%d\t%s\tINFERRED\tweb passed only as callee parameter %s (%d uses, unanimous)' % (var, k, nm2, nm, nv)); stat['web'] += 1
    if spec and not dry:
        tf = tempfile.NamedTemporaryFile('w', suffix='.tsv', delete=False); tf.write('\n'.join(spec) + '\n'); tf.close()
        r = subprocess.run([sys.executable, '-I', 'Tools/userspace/emit_webs.py', d, fn, tf.name], capture_output=True, text=True)
        if r.returncode: print('emit failed', fn, r.stderr[-120:]); continue
        rows.append(r.stdout.rstrip('\n'))
print(dict(stat), file=sys.stderr)
if not dry: open(out, 'a').write('\n'.join(x for x in rows if x.strip()) + '\n')
