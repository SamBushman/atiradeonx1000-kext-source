#!/usr/bin/env python3
"""autoweb_idiom.py DIR OUT.tsv PARTLO PARTHI [--dry] [--fn FN] : name placeholder webs whose every definition is a recognised idiom.

Idioms (read off the CURRENT text of the definition, so base names that earlier rows gave decide header-vs-vector indexing):
  * inline arena-vector access: `X = vectorAllocN[2]` size, `vectorN[1]` filled count, `*vectorN` capacity, `(T*)(i*4 + vectorN[2])` / `(T*)Vector__elementRefGrow(..)` element reference ...
  * the result of a call to a named function: role table CALLROLE (return value of getOperandRecord is an operand record, ...)
Webs with several definitions all of the same role get that role; a web that reads its own variable on the definition line (`x = f(x)`) is skipped.
Rows (apply_names `use` rows via emit_webs.py) are appended to OUT.tsv; names are made unique per function (numeric suffix) against every identifier of the function."""
import sys, re, glob, os, collections, subprocess, tempfile
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
import find_webs as F
d, out = sys.argv[1:3]
lo, hi = int(sys.argv[3]), int(sys.argv[4])
dry = '--dry' in sys.argv
only = sys.argv[sys.argv.index('--fn') + 1] if '--fn' in sys.argv else None
PHV = re.compile(r'^(?:[A-Za-z]{0,4}Var\d+|p+_?[A-Za-z]*Var\d+|local_[0-9a-f]+)$')
H = re.compile(r'^/\* (\S+) @ 0x')
CALLROLE = {
    'IRInst__getOperandRecord': 'operandRecord', 'IRInst__getOperandSource': 'sourceDef', 'Compiler__exprRecordForValueNumber': 'exprRecord',
    'Arena__alloc': 'allocation', 'Vector__elementRefGrow': 'elementRef', 'IRInst__create': 'newInst', 'RegKind__flagBit0': 'flagBit0',
    'Compiler__isOptionEnabled': 'optionEnabled', 'IRInst__countWrittenComponents': 'writtenComponentCount', 'SelectWord__isSplat': 'isSplat',
    'signToCompareCode': 'compareCode', 'Compiler__findInPtrSet': 'foundEntry', 'Compiler__valueNumberForExpr': 'valueNumber',
    'IRInst__hasSingleUse': 'hasSingleUse', 'Inst__writtenLanesAllMatchValue': 'lanesAllMatch', 'Inst__allWrittenLanesSatisfy': 'lanesAllSatisfy',
    'IRInst__isCoalescableMov': 'isCoalescableMov', 'ValueKey__lanesAreUnset': 'lanesAreUnset', 'Block__getPredecessor': 'predecessor',
    'IRInst__clone': 'clonedInst',
}
CAST = r'(?:\([\w ]+\*?\))?'
def role(rhs, var):
    rhs = rhs.strip().rstrip(';').strip()
    if re.search(r'(?<![\w])%s(?![\w])' % re.escape(var), rhs): return None
    m = re.match(r'^%s(\w+)\(' % CAST, rhs)
    if m and m.group(1) in CALLROLE: return CALLROLE[m.group(1)]
    m = re.match(r'^%s(vectorAlloc\w*)\[(\d)\]$' % CAST, rhs)
    if m: return {'1': 'vectorCapacity', '2': 'vectorSize', '3': 'vectorData'}.get(m.group(2)) if m.group(2) != '3' else 'elementRef' if var.startswith('p') else 'vectorData'
    m = re.match(r'^%s(vector\d*)\[(\d)\]$' % CAST, rhs)
    if m: return {'0': 'vectorCapacity', '1': 'vectorFilledCount', '2': 'vectorData'}.get(m.group(2))
    m = re.match(r'^\*(vector\d*)$', rhs)
    if m: return 'vectorCapacity'
    if re.match(r'^%s\(?[\w\*\+ ]+ \+ vectorAlloc\w*\[3\]\)?$' % CAST, rhs) or re.match(r'^%s\(?[\w\*\+ ]+ \* 4 \+ vector\d*\[2\]\)?$' % CAST, rhs): return 'elementRef'
    return None
sig = {}
funcs = collections.OrderedDict()
for pf in sorted(glob.glob(d + '/part_*.c')):
    pn = int(re.search(r'part_(\d+)', pf).group(1))
    if not lo <= pn <= hi: continue
    for l in open(pf, errors='replace'):
        m = H.match(l)
        if m and (only is None or m.group(1) == only): funcs[m.group(1)] = pn
P = re.compile(r'\b([A-Za-z]{0,4}Var\d+|p+_?[A-Za-z]*Var\d+|local_[0-9a-f]+)\b')
rows = []; stat = collections.Counter()
for fn, pn in funcs.items():
    try:
        body, brace = F.load(d, fn); nodes, entry = F.build_cfg(body, brace)
    except BaseException: stat['refused'] += 1; continue
    cur = F.CURRENT
    idents = set(re.findall(r'[A-Za-z_]\w*', '\n'.join(cur)))
    names = sorted({m for l in cur[brace + 1:] if not re.match(r'\s*(/\*|\*|//)', l) for m in P.findall(l)})
    used = collections.Counter(); spec = []
    for var in names:
        try: ws, er = F.webs(nodes, entry, var)
        except BaseException: stat['refusedvar'] += 1; continue
        by = collections.defaultdict(list)
        for k, ls in enumerate(ws):
            if not any(re.search(r'(?<![\w])%s(?![\w])' % re.escape(var), cur[x]) for x in ls): continue
            roles = set(); ndef = 0
            for x in ls:
                m = re.search(r'(?<![\w.>*])%s\s*=(?!=)\s*(.*)$' % re.escape(var), cur[x])
                if m and not re.search(r'[(,]\s*\(?\w*\s*\*?\s*%s\s*=(?!=)' % re.escape(var), cur[x]):
                    ndef += 1; roles.add(role(m.group(1), var))
            if ndef and len(roles) == 1 and None not in roles: by[roles.pop()].append(k)
        for rl, ks in by.items():
            nm = rl
            if nm in idents or used[rl]:
                used[rl] += 1; nm = rl + str(used[rl] + 1)
                while nm in idents: used[rl] += 1; nm = rl + str(used[rl] + 1)
            else: used[rl] += 0
            idents.add(nm)
            used[rl] = max(used[rl], 0)
            spec.append('%s\t%s\t%s\tINFERRED\tevery definition of these webs is the %s idiom (read off the call/vector access)' % (var, ','.join(map(str, ks)), nm, rl)); stat['rows'] += 1
    if spec and not dry:
        tf = tempfile.NamedTemporaryFile('w', suffix='.tsv', delete=False); tf.write('\n'.join(spec) + '\n'); tf.close()
        r = subprocess.run([sys.executable, '-I', 'Tools/userspace/emit_webs.py', d, fn, tf.name], capture_output=True, text=True)
        os.unlink(tf.name)
        if r.returncode: print('emit failed', fn, r.stderr[-160:]); continue
        rows.append(r.stdout.rstrip('\n'))
    elif spec and dry: print(fn, len(spec), 'rows')
print(dict(stat), file=sys.stderr)
if not dry: open(out, 'a').write('\n'.join(x for x in rows if x.strip()) + '\n')
