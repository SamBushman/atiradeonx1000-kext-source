#!/usr/bin/env python3
"""fuse_madd.py FILE.s  - rewrite gcc -O0 PowerPC assembly so that a multiply whose only use is the add/subtract that follows it becomes ONE fused
multiply-add (issue #229).

The shipped libGLProgrammability / VADriver were compiled with an optimising gcc, which contracts `a*b + c` into fmadd(s) (one rounding).  The rebuilt images
are built -O0 (stack layout; #212, #226), where GCC never contracts: `fmuls t,a,b ; fadds r,t,c` rounds twice and the result differs from the stock in the last
bit (fnfuzz: _InterpreterNoiseGeneratorInterpolate, 17 of 200 trials).  This pass restores the stock rounding without touching anything else of the -O0 code.

At -O0 every expression temporary is written once and read once, so the pattern is exact: for `fmul[s] D,A,B` find the first later instruction (same basic
block, no call) that reads D; it must be fadd[s]/fsub[s] of the same precision, D must be dead afterwards, and then
    fadd[s]  E,D,C / E,C,D  ->  fmadd[s]  E,A,B,C        (A*B + C)
    fsub[s]  E,D,C          ->  fmsub[s]  E,A,B,C        (A*B - C)
    fsub[s]  E,C,D          ->  fnmsub[s] E,A,B,C        (C - A*B)
The fused instruction reads A and B where the add stood; -O0 often reloads one of them (typically f0) in between, so such an operand is copied to a scratch
FP register (one not mentioned anywhere in the function) at the place of the multiply.  A window containing a call, branch or label is left alone.
Prints '<file>: N fused, M left (reason counts)' to stderr.  Idempotent: already fused code has no fmul left to pair."""
import os, re, sys

BRANCH = re.compile(r'^(b|bl|blr|blrl|bctr|bctrl|bdnz|bdz|b[a-z]{1,3}|b[a-z]{1,3}[+-]?)\b')
FREG = re.compile(r'\bf(\d+)\b')
READ_ONLY = re.compile(r'^(stf|fcmp)')
FOUR = ('fmadd', 'fmadds', 'fmsub', 'fmsubs', 'fnmadd', 'fnmadds', 'fnmsub', 'fnmsubs', 'fsel')

def parse(line):
    """-> (mnemonic, operands list) for an instruction line, None for anything else"""
    s = line.split('#')[0].rstrip()
    if not s.startswith('\t') and not s.startswith(' '):
        return None
    t = s.strip()
    if not t or t.startswith('.') :
        return None
    p = t.split(None, 1)
    return p[0], ([o.strip() for o in p[1].split(',')] if len(p) > 1 else [])

def fregs(ops):
    return [int(m.group(1)) for o in ops for m in [FREG.fullmatch(o)] if m]

def rw(mn, ops):
    """FP registers (reads, writes) of an instruction; None = unknown FP instruction (treated as a barrier)"""
    allf = [int(m.group(1)) for o in ops for m in FREG.finditer(o)]
    if mn.startswith('lf'):
        return set(allf[1:]), set(allf[:1])            # the base register of lfsx is a GPR; f-regs in the operand are only the target
    if mn.startswith('stf'):
        return set(allf[:1]), set()
    if mn.startswith('fcmp'):
        return set(allf), set()
    if mn.startswith('f') or mn.startswith('mffs'):
        if mn in ('mtfsf', 'mtfsb0', 'mtfsb1', 'mtfsfi'):
            return None
        return set(allf[1:]), set(allf[:1])
    if mn in ('mtfsf', 'mtfsb0', 'mtfsb1', 'mtfsfi', 'mffs'):
        return None
    return set(), set()

def fuse(lines, stat):
    n = len(lines)
    ins = [parse(l) for l in lines]
    # basic-block barriers: labels, branches/calls, unknown FP instructions
    def is_barrier(k):
        l = lines[k]
        if l and not l[0] in ' \t' and l.rstrip().endswith(':'):
            return True
        if ins[k] is None:
            return False
        mn = ins[k][0]
        if mn.startswith('b') and not mn.startswith('bi'):
            return True
        return rw(mn, ins[k][1]) is None
    # backward liveness of the FP registers over the function's control-flow graph (bit r = f<r>)
    ALL = (1 << 32) - 1
    VOL = (1 << 14) - 1                      # f0..f13 are call-clobbered
    ARGS = VOL & ~1                          # f1..f13 carry call arguments
    labels = {}
    for k in range(n):
        m = re.match(r'([^\s:]+):\s*$', lines[k])
        if m: labels[m.group(1)] = k
    rd = [0] * n; wr = [0] * n; succ = [None] * n
    for k in range(n):
        succ[k] = [k + 1] if k + 1 < n else []
        if ins[k] is None:
            continue
        mn, ops = ins[k]
        r = rw(mn, ops)
        if r is None:
            rd[k] = ALL; continue
        rd[k] = sum(1 << x for x in r[0]); wr[k] = sum(1 << x for x in r[1])
        if mn.startswith('b') and not mn.startswith('bi'):
            tgt = [o for o in ops if o in labels]
            if mn in ('blr',):
                rd[k] = 1 << 1; succ[k] = []                       # returns f1
            elif mn in ('bctr',):
                rd[k] = 0; succ[k] = []                            # a switch dispatch (-O0 emits bctr only for jump tables): no floating-point register is live across it
            elif mn in ('bl', 'bla', 'bctrl', 'blrl'):
                rd[k] = ARGS; wr[k] = VOL                          # call: reads the argument registers, clobbers the volatile ones
            elif mn == 'b':
                succ[k] = [labels[t] for t in tgt] if tgt else []
                if not tgt: rd[k] = ALL
            else:                                                  # conditional branch (beq, bne, bc, bdnz ...): target and fall through
                succ[k] = succ[k] + [labels[t] for t in tgt]
                if not tgt: rd[k] = ALL
    # what a call reads: at -O0 the argument registers are written in the basic block right before the call; the registers written since the previous call/branch are
    # the arguments being assembled (a region that starts at a label, e.g. a conditional-expression merge, cannot be seen and reads every argument register)
    def call_args(k, conservative=True):
        got = 0
        q = k - 1
        while q >= 0:
            if is_barrier(q):
                if not conservative or not (lines[q] and lines[q][0] not in ' \t'):      # previous call/branch: the region is exactly (q, k)
                    pre = 0                                          # floating-point arguments occupy f1, f2, ... in order: only a written prefix is read
                    while (got >> (pre + 1)) & 1 and pre < 13:
                        pre += 1
                    return ((1 << (pre + 1)) - 2) & ARGS
                return ARGS                                          # label: unknown predecessors
            got |= wr[q]
            q -= 1
        return ARGS
    rdreal = list(rd); rdtemp = list(rd)
    for k in range(n):
        if ins[k] and ins[k][0] in ('bl', 'bla', 'bctrl', 'blrl') and rd[k] == ARGS:
            rdreal[k] = call_args(k); rdtemp[k] = call_args(k, False)
    def liveness(rdl):
        liveout = [0] * n; livein = [0] * n
        changed = True
        while changed:
            changed = False
            for k in range(n - 1, -1, -1):
                lo = 0
                for t in succ[k]:
                    lo |= livein[t]
                li = rdl[k] | (lo & ~wr[k])
                if lo != liveout[k] or li != livein[k]:
                    liveout[k] = lo; livein[k] = li; changed = True
        return liveout
    liveout = liveness(rdreal)            # scratch choice: a call that follows a label may read any argument register
    liveout_real = liveness(rdtemp)       # the mul temporary: only the arguments assembled in the call's own block
    used = set()
    for k in range(n):
        if ins[k]:
            used.update(int(m.group(1)) for o in ins[k][1] for m in FREG.finditer(o))
    out = list(lines)
    reserved = []          # (i, j, reg) windows with a scratch register in use
    done = [False] * n
    for i in range(n):
        if ins[i] is None or ins[i][0] not in ('fmul', 'fmuls') or done[i]:
            continue
        mn, ops = ins[i]
        if len(ops) != 3 or not all(FREG.fullmatch(o) for o in ops):
            continue
        single = mn == 'fmuls'
        D, A, B = [int(FREG.fullmatch(o).group(1)) for o in ops]
        j = None; written = set(); reason = None
        for k in range(i + 1, min(n, i + 16)):
            if is_barrier(k):
                reason = 'barrier'; break
            if ins[k] is None:
                continue
            r = rw(ins[k][0], ins[k][1])
            if D in r[0]:
                m2 = ins[k][0]
                if m2 in (('fadds', 'fsubs') if single else ('fadd', 'fsub')) and len(ins[k][1]) == 3:
                    j = k
                else:
                    reason = 'use is not add/sub'
                break
            if D in r[1]:
                reason = 'result unused'; break
            written |= r[1]
        if j is None:
            stat[reason or 'no use in window'] = stat.get(reason or 'no use in window', 0) + 1
            continue
        mj, oj = ins[j]
        E, X, Y = [int(FREG.fullmatch(o).group(1)) for o in oj]
        if X == D and Y == D:
            stat['both operands'] = stat.get('both operands', 0) + 1; continue
        # D must be dead after j (true liveness over the CFG)
        if E != D and (liveout_real[j] >> D) & 1:
            stat['result live'] = stat.get('result live', 0) + 1
            if os.environ.get('FUSE_DEBUG'): print('RESULT LIVE (D=f%d) window:\n%s\n--- after:\n%s' % (D, '\n'.join(lines[i:j + 1]), '\n'.join(lines[j + 1:j + 12])), file=sys.stderr)
            continue
        if mj.startswith('fadd'):
            C = Y if X == D else X; newmn = 'fmadds' if single else 'fmadd'
        elif X == D:
            C = Y; newmn = 'fmsubs' if single else 'fmsub'
        else:
            C = X; newmn = 'fnmsubs' if single else 'fnmsub'
        # operands the window overwrites must be saved at the multiply
        Ar, Br = A, B
        copies = []
        for which, reg in (('A', A), ('B', B)):
            if reg in written:
                busy = {rg for (a, b, rg) in reserved if not (b < i or a > j)} | {c[1] for c in copies}
                untouched = lambda x: not any(((rd[k] | wr[k]) >> x) & 1 for k in range(i + 1, j + 1))
                free = [x for x in range(13, 1, -1) if x not in used and x not in busy and x != D]
                if not free:                      # every register is mentioned: take one that is dead after the multiply and untouched in the window
                    free = [x for x in range(13, -1, -1) if x not in busy and x != D and x not in (A, B, C, E) and not (liveout[i] >> x) & 1 and untouched(x)]
                if not free:                      # still none: f8..f13 only, judged with the block-local argument model (a call with 8+ floating-point arguments assembled across a label does not occur)
                    free = [x for x in range(13, 7, -1) if x not in busy and x != D and x not in (A, B, C, E) and not (liveout_real[i] >> x) & 1 and untouched(x)]
                if not free:
                    break
                s = free[0]
                copies.append((which, s, reg))
        else:
            for which, s, reg in copies:
                if which == 'A': Ar = s
                else: Br = s
            ind = re.match(r'[ \t]*', lines[i]).group(0)
            if Ar == Br and A == B and copies:
                pass
            rep = ['%sfmr f%d,f%d' % (ind, s, reg) for (_, s, reg) in copies]
            out[i] = '\n'.join(rep)      # no multiply left; no comments (Apple as rejects a trailing '#')
            ind2 = re.match(r'[ \t]*', lines[j]).group(0)
            out[j] = '%s%s f%d,f%d,f%d,f%d' % (ind2, newmn, E, Ar, Br, C)
            for (_, s, _) in copies:
                reserved.append((i, j, s))
            done[i] = True
            stat['fused'] = stat.get('fused', 0) + 1
            if copies:
                stat['fused with scratch copy'] = stat.get('fused with scratch copy', 0) + 1
            continue
        stat['no scratch register'] = stat.get('no scratch register', 0) + 1
        if os.environ.get('FUSE_DEBUG'):
            print('NO SCRATCH (A=f%d B=f%d C=f%d D=f%d E=f%d) liveout(i)=%s real=%s window:\n%s' % (A, B, C, D, E, [x for x in range(14) if (liveout[i] >> x) & 1], [x for x in range(14) if (liveout_real[i] >> x) & 1], '\n'.join(lines[i:j + 1])), file=sys.stderr)
    return out

def main():
    path = sys.argv[1]
    src = open(path).read().split('\n')
    # functions are separated by their .globl/.align; the scratch search ('not mentioned anywhere in the function') needs per-function text
    funcs, cur = [], []
    for l in src:
        if re.match(r'\t\.(globl|private_extern)\b', l) and cur and any(re.match(r'\t\.align', x) for x in cur[-3:]):
            funcs.append(cur); cur = []
        cur.append(l)
    funcs.append(cur)
    stat = {}
    res = []
    for f in funcs:
        res.extend(fuse(f, stat))
    open(path, 'w').write('\n'.join(res))
    print('%s: %s' % (path, ', '.join('%d %s' % (v, k) for k, v in sorted(stat.items())) or 'nothing to fuse'), file=sys.stderr)

if __name__ == '__main__':
    main()
