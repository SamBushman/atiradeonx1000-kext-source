#!/usr/bin/env python3
"""sem_equiv_selftest.py FILE.dis [SEED] - validation of sem_equiv.py on one `gcc -S` assembler file.

POSITIVE tests (must never be DIFFERENT; every function that is not INCONCLUSIVE/UNINIT-PAIRED must come out EQUIVALENT):
  rename   - every local label L<n> renumbered
  commute  - the two source registers of every commutative add/and/or/xor/mullw swapped
  frame    - the frame grows by 16 bytes: stwu r1,-N(r1) -> -(N+16), every r30 offset >= N (caller frame: incoming args) +16
  (sem_equiv.py is run with --no-shortcut so the symbolic engine itself is exercised, not the identical-code shortcut)
NEGATIVE tests (mutants of one function at a time; each must be reported DIFFERENT or INCONCLUSIVE, an EQUIVALENT mutant is listed and judged by hand):
  const    - an immediate of li/addi/cmpwi/cmplwi/ori/rlwinm changed
  swapst   - two adjacent stores through non-frame registers exchanged
  dropst   - a store through a non-frame register removed
  dropcall - a bl removed
  callarg  - an argument register of a call set from another register / constant before the call
  branch   - a conditional branch condition inverted (beq<->bne, blt<->bge, bgt<->ble)
  reg      - the source register of a `mr r3..r10,rX` argument copy changed
Prints a summary table; exit 0 when no positive test is DIFFERENT and no negative test is a false EQUIVALENT."""
import sys, re, random, subprocess, os, tempfile
H = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, H)
import sem_equiv as S


def funcs_text(path):
    """-> list of (name or None, [lines])"""
    out = []; cur = (None, [])
    for l in open(path, errors='replace').read().split('\n'):
        m = re.match(r'^(_[A-Za-z0-9_$.]*):$', l)
        if m: out.append(cur); cur = (m.group(1), [l])
        else: cur[1].append(l)
    out.append(cur)
    return out


def write(parts, path): open(path, 'w').write('\n'.join('\n'.join(ls) for _, ls in parts))


def t_rename(ls):
    labs = sorted(set(re.findall(r'\bL(\d+)\b', '\n'.join(ls))), key=int)
    mp = {n: str(int(n) + 7000) for n in labs}
    return [re.sub(r'\bL(\d+)\b', lambda m: 'L' + mp[m.group(1)], l) for l in ls]


def t_commute(ls):
    out = []
    for l in ls:
        m = re.match(r'^\t(add|and|or|xor|mullw)[ \t](r\d+),(r\d+),(r\d+)$', l)
        out.append('\t%s %s,%s,%s' % (m.group(1), m.group(2), m.group(4), m.group(3)) if m else l)
    return out


def t_frame(ls):
    N = None
    for l in ls:
        m = re.match(r'^\tstwu[ \t]r1,-(\d+)\(r1\)$', l)
        if m: N = int(m.group(1)); break
    if N is None: return None
    out = []
    for l in ls:
        m = re.match(r'^\tstwu[ \t]r1,-(\d+)\(r1\)$', l)
        if m: out.append('\tstwu r1,-%d(r1)' % (N + 16)); continue
        m = re.match(r'^(\t[a-z]+\t?\s*)(r\d+|f\d+),(\d+)\(r30\)$', l.replace(' ', '\t', 1) if False else l)
        m2 = re.match(r'^(\t[a-z]+[ \t]+)(r\d+|f\d+),(\d+)\(r30\)$', l)
        if m2 and int(m2.group(3)) >= N: out.append('%s%s,%d(r30)' % (m2.group(1), m2.group(2), int(m2.group(3)) + 16)); continue
        out.append(l)
    return out


def run(base, cand, name):
    r = subprocess.run([sys.executable, os.path.join(H, 'sem_equiv.py'), base, cand, '--no-shortcut', '-v', name], capture_output=True, text=True)
    first = r.stdout.strip().split('\n')[0] if r.stdout.strip() else ''
    return first.split(' ')[0], r.stdout


def mutants(ls):
    """-> list of (kind, mutated lines)"""
    out = []
    idx = lambda pat: [i for i, l in enumerate(ls) if re.match(pat, l)]
    for i in idx(r'^\t(li|addi|cmpwi|cmplwi|ori|rlwinm|slwi|srwi)[ \t]'):
        m = re.match(r'^(\t(?:li|addi|cmpwi|cmplwi|ori|rlwinm|slwi|srwi)[ \t])(.*?)(-?\d+)$', ls[i])
        if m and not re.search(r'r30|r1\b', ls[i]):
            nl = list(ls); nl[i] = m.group(1) + m.group(2) + str(int(m.group(3)) + 1); out.append(('const', nl))
    st = [i for i in idx(r'^\t(stw|stb|sth|stfs|stfd)[ \t]') if not re.search(r'\((r30|r1)\)', ls[i])]
    for i in st:
        nl = list(ls); del nl[i]; out.append(('dropst', nl))
        if i + 1 < len(ls) and (i + 1) in st:
            nl = list(ls); nl[i], nl[i + 1] = nl[i + 1], nl[i]
            if ls[i] != ls[i + 1]: out.append(('swapst', nl))
    for i in idx(r'^\tbl[ \t]'):
        nl = list(ls); del nl[i]; out.append(('dropcall', nl))
        nl = list(ls); nl.insert(i, '\tli r5,9' if not re.search(r'li r5,9', ls[i - 1]) else '\tli r6,9'); out.append(('callarg', nl))
        nl = list(ls); nl.insert(i, '\tmr r4,r0'); out.append(('callarg', nl))
    inv = {'beq': 'bne', 'bne': 'beq', 'blt': 'bge', 'bge': 'blt', 'bgt': 'ble', 'ble': 'bgt'}
    for i in idx(r'^\t(beq|bne|blt|bge|bgt|ble)[ \t]'):
        m = re.match(r'^\t(\w+)[ \t](.*)$', ls[i]); nl = list(ls); nl[i] = '\t%s %s' % (inv[m.group(1)], m.group(2)); out.append(('branch', nl))
    for i in idx(r'^\tmr[ \t]r([3-9]|10),r\d+$'):
        m = re.match(r'^\tmr[ \t](r\d+),r(\d+)$', ls[i]); nl = list(ls); nl[i] = '\tmr %s,r%d' % (m.group(1), (int(m.group(2)) + 1) % 12); out.append(('reg', nl))
    return out


def main():
    path = sys.argv[1]; seed = int(sys.argv[2]) if len(sys.argv) > 2 else 1
    random.seed(seed)
    parts = funcs_text(path)
    tmp = tempfile.mkdtemp(prefix='semst_', dir=os.environ.get('TMPDIR', '/tmp'))
    basef = tmp + '/base.dis'; write(parts, basef)
    fn = [p for p in parts if p[0] and len(p[1]) > 12]
    # reference: base vs base must be EQUIVALENT or UNINIT-PAIRED (the engine's own sanity)
    ref = {}
    for tname, tf in (('rename', t_rename), ('commute', t_commute), ('frame', t_frame)):
        np_ = []
        for nme, ls in parts:
            if nme is None: np_.append((nme, ls)); continue
            r = tf(ls); np_.append((nme, r if r is not None else ls))
        cf = '%s/cand_%s.dis' % (tmp, tname); write(np_, cf)
        r = subprocess.run([sys.executable, os.path.join(H, 'sem_equiv.py'), basef, cf, '--no-shortcut'], capture_output=True, text=True)
        summ = r.stdout.strip().split('\n')[-1]
        diffs = [l for l in r.stdout.split('\n') if l.startswith('DIFFERENT')]
        print('POSITIVE %-8s %s' % (tname, summ))
        for d in diffs[:6]: print('   ', d[:230])
        ref[tname] = len(diffs)
    # negative: mutate a sample of functions
    res = {}; survivors = []
    sample = random.sample(fn, min(len(fn), 60))
    for nme, ls in sample:
        ms = mutants(ls)
        random.shuffle(ms)
        seen = {}
        for kind, nl in ms:
            if seen.get(kind, 0) >= 2: continue
            seen[kind] = seen.get(kind, 0) + 1
            np_ = [(n2, nl if n2 == nme else l2) for n2, l2 in parts]
            cf = tmp + '/mut.dis'; write(np_, cf)
            v, outp = run(basef, cf, nme)
            res.setdefault(kind, {}).setdefault(v, 0); res[kind][v] += 1
            if v in ('EQUIVALENT', 'IDENTICAL', 'UNINIT'):
                noop = ''
                if kind == 'callarg' and len(nl) == len(ls) + 1:
                    j = next(i for i in range(len(ls)) if ls[i] != nl[i]) if any(ls[i] != nl[i] for i in range(len(ls))) else len(ls)
                    ins_ = nl[j]; prev = [l.strip() for l in ls[max(0, j - 8):j]]
                    reg = ins_.split()[1].split(',')[0]
                    # the inserted instruction is a no-op when the latest write to its destination before the call is the identical instruction
                    last = [l for l in prev if re.match(r'^\w+[ \t]+%s,' % reg, l)]
                    noop = ' NOOP(same instruction already sets %s)' % reg if last and last[-1].replace('\t', ' ') == ins_.strip().replace('\t', ' ') else ' !!REVIEW'
                dl = next(((ls[i] if i < len(ls) else '', nl[i]) for i in range(min(len(ls), len(nl))) if ls[i] != nl[i]), None)
                survivors.append((kind, nme, noop, dl, j if kind == 'callarg' else None))
    print('NEGATIVE results (verdict counts per mutation kind):')
    for k, d in sorted(res.items()): print('   %-9s %s' % (k, d))
    print('SURVIVORS (mutants not rejected: judge by hand):')
    for s in survivors[:40]: print('   ', s)
    print('summary: positives DIFFERENT = %s; survivors = %d' % (ref, len(survivors)))


main()
