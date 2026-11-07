"""lost_return_audit.py: for every corpus function declared non-void whose body has a bare `return;` (lost return value candidate),
look in the STOCK binary for call sites (bl <stock addr>) whose following instructions READ r3 (or f1 for double) before redefining it.
A function whose stock callers consume the result but whose rebuilt body returns nothing is a lost-return-value defect (class of #233).
usage: python3 Tools/userspace/lost_return_audit.py Userspace/<Binary>/ppc <stock binary, thin or fat> (needs python3-capstone)
Exit status 0 always: read the list. Validated on #233 (the pre-fix VA corpus lists ava_reserve_list_words, the fixed one lists nothing). Known false positive: libGLProgrammability `save_world` (EH millicode).
Limits: sees DIRECT callers only (an indirect `bctrl` caller's use of r3 is invisible) - the fnfuzz result class (fnfuzz_gen.py RETUSED) and the whole-stack runs cover those."""
import re, sys, glob, struct
from capstone import *

corpus, stock = sys.argv[1], sys.argv[2]
verbose = '--verbose' in sys.argv
d = open(stock, 'rb').read()
if d[:4] == b'\xca\xfe\xba\xbe':
    n = struct.unpack('>I', d[4:8])[0]
    for i in range(n):
        cpu, sub, off, size, al = struct.unpack('>5I', d[8 + 20 * i:28 + 20 * i])
        if cpu == 18: d = d[off:off + size]; break
assert d[:4] == b'\xfe\xed\xfa\xce', d[:4].hex()
ncmds = struct.unpack('>I', d[16:20])[0]; off = 28; texts = []
for _ in range(ncmds):
    cmd, sz = struct.unpack('>II', d[off:off + 8])
    if cmd == 1:
        nm = d[off + 8:off + 24].rstrip(b'\0'); vm, vs, fo, fs = struct.unpack('>IIII', d[off + 24:off + 40]); nsect = struct.unpack('>I', d[off + 48:off + 52])[0]
        so = off + 56
        for _s in range(nsect):
            sn = d[so:so + 16].rstrip(b'\0'); saddr, ssize, soff = struct.unpack('>III', d[so + 32:so + 44])
            if sn == b'__text': texts.append((saddr, ssize, soff))
            so += 68
    off += sz
md = Cs(CS_ARCH_PPC, CS_MODE_32 | CS_MODE_BIG_ENDIAN)
ins = []
for saddr, ssize, soff in texts:
    pos = 0
    while pos < ssize:                                   # capstone stops at the first undecodable word (data in text, VMX): skip it and go on
        got = 0
        for i in md.disasm(d[soff + pos:soff + ssize], saddr + pos):
            ins.append((i.address, i.mnemonic, i.op_str)); got += 1
        pos += 4 * got
        if pos < ssize: ins.append((saddr + pos, '.word', '')); pos += 4
idx = {a: k for k, (a, _, _) in enumerate(ins)}
print('stock text instructions:', len(ins), file=sys.stderr)

hdr = re.compile(r'^/\* (\S+) @ 0x([0-9a-f]+) \((\d+) bytes\) \*/\s*$')
cands = {}
for f in sorted(glob.glob(corpus + '/part_*.c')):
    lines = open(f, errors='replace').read().split('\n'); i = 0
    while i < len(lines):
        m = hdr.match(lines[i])
        if m:
            name = m.group(1); j = i + 1; body = []
            while j < len(lines) and not hdr.match(lines[j]): body.append(lines[j]); j += 1
            first = next((l for l in body if l.strip()), '')
            dm = re.match(r'\s*([A-Za-z_][\w \*]*?)\s*\**\s*' + re.escape(name) + r'\s*\(', first)
            decl = dm.group(1).strip() if dm else '?'
            t = '\n'.join(body)
            bare = len(re.findall(r'^\s*return\s*;', t, re.M)); val = len(re.findall(r'^\s*return\s+[^;\s]', t, re.M))
            if decl != 'void' and bare > 0: cands[name] = (int(m.group(2), 16), decl, bare, val, f.split('/')[-1])
            i = j
        else: i += 1

regre = lambda r: re.compile(r'\b' + r + r'\b')
def reads_writes(mn, ops, reg):
    """(reads, writes) of register name `reg` ('r3' / 'f1') by one instruction, textual and conservative."""
    toks = [t.strip() for t in re.split(r',', ops)] if ops else []
    rx = regre(reg)
    if mn.startswith('b') or mn in ('sc', 'trap', 'tw', 'twi'):
        return (mn in ('bctr', 'bctrl') and False), False
    mentions = [bool(rx.search(t)) for t in toks]
    if not any(mentions): return False, False
    if mn.startswith('st') or mn.startswith('cmp') or mn.startswith('fcmp') or mn.startswith('mt') or mn in ('dcbz', 'dcbf', 'dcbst', 'icbi', 'sync', 'eieio'):
        return True, False
    # everything else: operand 0 is the destination, others are sources; "d(rA)" reads rA even as 1st operand if a load
    reads = any(mentions[1:])
    writes = mentions[0]
    if writes and mn.startswith('l') and re.search(r'\(' + reg + r'\)', toks[1] if len(toks) > 1 else ''): reads = True
    if writes and mn in ('rlwimi', 'rlwinm' ) and False: pass
    if writes and mn in ('rlwimi', 'insrwi'): reads = True
    return reads, writes

def consumed(k, reg, window=150):
    """after the call at ins[k]: does the code read `reg` before redefining it?  Returns (True/False/'passthrough', index)"""
    for j in range(k + 1, min(k + 1 + window, len(ins))):
        a, mn, ops = ins[j]
        if mn in ('blr', 'blrl'): return 'passthrough', j
        if mn == 'bl' or mn == 'bctrl' or mn == 'bla': return False, j        # args for the next call overwrite r3 or the next call's own result is used
        if mn == 'b': return False, j
        r, w = reads_writes(mn, ops, reg)
        if r: return True, j
        if w: return False, j
    return False, None

out = []
STAT = {'hascallers': 0}
for name, (addr, decl, bare, val, part) in sorted(cands.items(), key=lambda x: x[1][0]):
    if re.match(r"_(save|rest)(f|gpr|vec)", name): continue
    reg = 'f1' if decl == 'double' or decl == 'float' else 'r3'
    callers = []
    for k, (a, mn, ops) in enumerate(ins):
        if mn == 'bl' and ops.strip().lower() in ('0x%x' % addr,):
            callers.append(k)
    STAT['hascallers'] += 1 if callers else 0
    if not callers: continue
    used = []; pas = 0
    for k in callers:
        c, j = consumed(k, reg)
        if c is True: used.append((ins[k][0], ins[j]))
        elif c == 'passthrough': pas += 1
    if used: out.append((name, decl, reg, bare, val, len(callers), len(used), pas, part, used))
print('candidates with >=1 direct stock call site:', STAT['hascallers'])
print('candidates (non-void decl + bare return):', len(cands), ' with a stock caller consuming the result:', len(out))
for name, decl, reg, bare, val, nc, nu, pas, part, used in out:
    print('%-44s %-7s %s bare=%d val=%d callers=%d consumed=%d passthrough=%d %s  e.g. call@%x -> %x %s %s' % (name, decl, reg, bare, val, nc, nu, pas, part, used[0][0], used[0][1][0], used[0][1][1], used[0][1][2]))
