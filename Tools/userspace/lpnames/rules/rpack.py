import os, re, glob
D = os.environ['PACK_DIR']; FN = os.environ['PACK_FN']
EVIDENCE = 'bit-packing temporary of the ARB program record emitter: name = the packed source field, read off the definition expression and the parameter names'
SEM = {}; NAMED = set()
for t in glob.glob(os.path.join(D, 'names*.tsv')):
    for l in open(t, errors='surrogateescape'):
        c = l.rstrip('\n').split('\t')
        if len(c) >= 6 and c[0] == 'local' and c[1] == FN:
            if c[2].startswith('param_'): SEM[c[2]] = c[3]
            else: NAMED.add(c[2])
XYZW = 'XYZW'
ONLY = set(filter(None, os.environ.get('PACK_ONLY', '').split(',')))
PACK = re.compile(r'^\((\*?)(param_\d+)(?:\[(\d)\])? & (?:0x[0-9a-f]+|\d+)\) << (?:0x[0-9a-f]+|\d+)')
def name(var, k, defs, lines, ctx):
    if var in NAMED or var.startswith('param_') or not defs: return None
    if ONLY and var not in ONLY: return None
    d = defs[0].strip().rstrip(';').strip()
    m = PACK.match(d)
    if m:
        star, p, idx = m.groups(); s = SEM.get(p)
        if not s: return None
        if re.match(r'^\(param_\d+\[3\] & 1\) << 0x1c \|', d): return s.replace('Negate', '') + 'Word'
        if star or idx is not None: return '%s%sBits' % (s, XYZW[int(idx or 0)])
        return s + 'Bits'
    m = re.match(r'^(\*?)(param_\d+)(?:\[(\d)\])?$', d)
    if m and m.group(2) in SEM and (m.group(1) or m.group(3) is not None): return SEM[m.group(2)] + XYZW[int(m.group(3) or 0)]
    m = re.match(r'^\((param_\d+) & 0x3f\) << 0x10 \| (param_\d+) & 0xffff$', d)
    if m and m.group(1) in SEM: return SEM[m.group(1)].replace('File', '') + 'Token'
    m = re.match(r'^(param_\d+) & 0xf$', d)
    if m and m.group(1) in SEM: return SEM[m.group(1)] + 'Field'
    m = re.match(r'^(param_\d+)\[3\]$', d)
    if m and m.group(1) in SEM: return SEM[m.group(1)] + 'W'
    m = re.match(r'^\*\(uint \*\)\((?:iVar\d+ \+ (0x[0-9a-f]+|\d+)|iVar\d+ \+ iVar\d+)\)$', d)
    if m: return 'oldWord%d' % (int(m.group(1), 0) // 4 if m.group(1) else 0)
    if 'ARB_instrCapacity' in d and '* 0x10' in d: return 'oldArrayBytes'
    if re.match(r'^\*\(int \*\)\(param_1 \+ ARB_instrCount\)', d): return 'instrCount'
    if re.match(r'^iVar\d+ \+ iVar\d+$', d): return 'instr'
    return None
