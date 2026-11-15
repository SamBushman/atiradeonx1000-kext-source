#!/usr/bin/env python3
"""fault_classify.py STOCK REBUILT LEDGER FUNCS SYMMAP NM NARGS REPRO_DIR: for every saved FAULT_MISMATCH input, run both images and classify the difference:
   DEAD_LOAD     one image faults on a load whose destination register is overwritten before any use (a dead / hoisted load the other image does not issue)
   USED_LOAD     the faulting load's result is used (the other image avoided the access some other way: different error handling or different control flow) -> REAL, needs a look
   STORE         the fault is a store
   BOTH_FAULT    both fault (different kind / address): crash-time order
   OTHER         fetch fault, not a load, ...
Prints one line per row: name, class, faulting image, instruction, pc."""
import sys, os, glob, pickle, collections
sys.path.insert(0, os.path.dirname(__file__)); sys.path.insert(0, os.path.expanduser('~/g5logs/fnf_237/pypkgs'))
import trace_diff as T
from capstone import *
md = Cs(CS_ARCH_PPC, CS_MODE_32 | CS_MODE_BIG_ENDIAN)
a = sys.argv[1:8]; repro = sys.argv[8]
T._init(a[0], a[1], a[4], a[5], a[2], a[3], a[6]); S, R = T._G['S'], T._G['R']; ss, sr = T._G['sims']['A']
def code(img, addr, n):
    for nm_, vm, vs, data in img.segs:
        if vm <= addr < vm + len(data): return data[addr - vm:addr - vm + n]
    return b''
import re
REG = re.compile(r'\b([rf]\d+)\b')
NOWRITE = ('st', 'cmp', 'b', 'mtctr', 'mtlr', 'mtcr', 'tw', 'td', 'dcb', 'icbi', 'sync', 'isync', 'eieio', 'cr', 'fcmp', 'mt')
def rw(n):
    """(registers read, registers written) of one instruction by the PowerPC operand convention: first operand is the destination except for stores / compares / branches / moves to special registers"""
    regs = REG.findall(n.op_str); m = n.mnemonic
    if not regs: return [], []
    if m.startswith(NOWRITE) and not m.startswith(('cntlz', 'cror', 'crand')) or m.startswith('cmp'): return regs, []
    reads = regs[1:] + (regs[:1] if m.startswith(('rlwimi', 'mtcrf')) else [])
    return reads, regs[:1]
def analyse(img, pc):
    ins = list(md.disasm(code(img, pc, 4), pc))
    if not ins: return 'OTHER', '?'
    i = ins[0]; txt = '%s %s' % (i.mnemonic, i.op_str)
    if i.mnemonic.startswith('st'): return 'STORE', txt
    if not (i.mnemonic.startswith('l') and i.mnemonic[1] in 'wbhfa'): return 'OTHER', txt
    regs = REG.findall(i.op_str)
    if not regs: return 'OTHER', txt
    dest = regs[0]; p = pc + 4
    for _ in range(32):
        n = list(md.disasm(code(img, p, 4), p))
        if not n: break
        n = n[0]; r_, w_ = rw(n)
        if dest in r_: return 'USED_LOAD', txt + ' (%s read by %s %s)' % (dest, n.mnemonic, n.op_str)
        if dest in w_: return 'DEAD_LOAD', txt + ' (%s overwritten by %s %s)' % (dest, n.mnemonic, n.op_str)
        if n.mnemonic.startswith('b') and n.mnemonic not in ('bl',): return 'USED_LOAD?', txt + ' (control transfer %s before %s is overwritten)' % (n.mnemonic, dest)
        p += 4
    return 'USED_LOAD?', txt
tot = collections.Counter()
for f in sorted(glob.glob(os.path.join(repro, '*.FAULT_MISMATCH.pkl'))):
    name = os.path.basename(f).split('.FAULT_MISMATCH')[0]
    try: row = T.load_row(a[2], name)
    except SystemExit: continue
    ia, da, sw, arena = pickle.load(open(f, 'rb'))
    x = ss.run(row['stock'], ia, da, sw, arena); y = sr.run(row['reb'], ia, da, sw, arena)
    if x[0] == 'FAULT' and y[0] == 'FAULT': cls, who, txt, pc = 'BOTH_FAULT', '-', 'stock %s rebuilt %s' % ([e[1:] for e in x[1] if e[0] == 'F'], [e[1:] for e in y[1] if e[0] == 'F']), 0
    else:
        who, img, r = ('stock', S, x) if x[0] == 'FAULT' else ('rebuilt', R, y)
        pc = r[2].get('fpc')
        cls, txt = analyse(img, pc) if pc is not None else ('OTHER', 'no pc')
    tot[cls] += 1; print('%-45s %-10s %-8s %s %s' % (name, cls, who, txt[:110], hex(pc) if pc else ''))
print('SUMMARY', dict(tot))
