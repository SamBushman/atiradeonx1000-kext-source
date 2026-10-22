#!/usr/bin/env python3
"""gen_slot_func_rows.py - `func` rows (Tools/userspace/apply_names.py) for the virtual-method functions of the GLDriver shader compiler's C++ classes.

Input: the RTTI/vtables of the binary (data/*.c, parsed here), the function texts (part_*.c, unowned_code/part_*.c), the slot-name tables of this file (SLOTS:
what each vtable slot of a class family means, recovered from the default and the override bodies and from the call sites - see notes_compiler_opcodes.md).
Output: `func<TAB>current name<TAB>Class__slotName<TAB>tier<TAB>evidence` for every function that sits in a vtable slot of a named family and has no
real name yet (functions F1 already named as ctor/dtor/deleting_dtor/clone keep that name; F1's `Class__vslotN` placeholders are renamed by a chained row).
A function shared by several classes (or slots) is named after the first class in tree order (base class first) that holds it at the lowest slot.
Usage: gen_slot_func_rows.py DIR(Userspace/ATIRadeonX1000GLDriver/ppc) > names_C1_func.tsv"""
import re, sys, os, glob, collections

D = sys.argv[1]
mem = {}
def load(fn, base):
    a = base
    for l in open(os.path.join(D, 'data', fn)):
        m = re.match(r'\s+0x([0-9a-f]{8}),', l)
        if m: mem[a] = int(m.group(1), 16); a += 4
for fn, base in [('DATA___const_coal.c', 0x1f0f08), ('TEXT___const_coal.c', 0x1cc164), ('DATA___nl_symbol_ptr.c', 0x1e88a4), ('DATA___const.c', 0x1e9150), ('DATA___data.c', 0x1d9000)]:
    load(fn, base)
def cstr(a):
    s = b''
    while True:
        w = mem.get(a & ~3)
        if w is None: break
        b = w.to_bytes(4, 'big')[a & 3]
        if b == 0: break
        s += bytes([b]); a += 1
    return s.decode('latin1')
def demangle(s):
    m = re.match(r'(\d+)(.*)', s)
    return m.group(2)[:int(m.group(1))] if m else s
ti = {a: demangle(cstr(mem[a + 4])) for a in sorted(mem) if 0x1f0f08 <= a < 0x1f0f08 + 22232 and mem.get(a) == 8 and 0x1cc164 <= mem.get(a + 4, 0) < 0x1cc164 + 5376}
vt = {a: ti[mem[a + 4]] for a in sorted(mem) if mem.get(a) == 0 and mem.get(a + 4) in ti and (0x1e9150 <= a < 0x1ebb08 or 0x1f0f08 <= a < 0x1f0f08 + 22232 or 0x1d9000 <= a < 0x1e8740)}
cls2vt = {c: a for a, c in vt.items()}
par = {}
for ta, name in ti.items():
    b = mem.get(ta + 8, 0); par[name] = ti.get(b) if b else None
bounds = sorted(set(list(vt) + list(ti)))
def slots(a):
    nxt = next((b for b in bounds if b > a), None)
    return [mem.get(a + 8 + 4 * i, 0) for i in range((nxt - a - 8) // 4)]
def depth(c):
    n = 0; p = par.get(c)
    while p: n += 1; p = par.get(p)
    return n
def anc(c):
    out = []; p = par.get(c)
    while p: out.append(p); p = par.get(p)
    return out

# function texts: address -> (current name, source)
HDR = re.compile(r'(?m)^/\* (\S+) @ 0x([0-9a-f]+) \((\d+) bytes\) \*/$')
cur = {}; srcfile = {}
for f in sorted(glob.glob(D + '/part_*.c') + glob.glob(D + '/unowned_code/part_*.c')):
    for m in HDR.finditer(open(f).read()): cur[int(m.group(2), 16)] = m.group(1); srcfile[int(m.group(2), 16)] = f

# --- slot-name tables: family root -> {slot: (name, tier, evidence)} ------------------------------------------------------------------------------------------
P = 'INFERRED'
def pred(cls, what=None):
    return ('is' + cls, P, 'default returns 0, only %s overrides it with `return 1` (the slot is a type predicate)' % (what or cls))
SLOTS = {
 'Block': {
  3: ('insertInstruction', P, 'Block default is empty; EntryBlock links the instruction at the head of its list (+0x12c) and sets inst+0x158 = block'),
  4: ('isFuncEnd', P, 'default returns 0, FuncEndBlock overrides it with a nonzero return'),
  5: pred('Any', 'AnyBlock'), 6: pred('Mirror', 'MirrorBlock'), 7: pred('Entry', 'EntryBlock'), 8: pred('Exit', 'ExitBlock'), 9: pred('IfHeader', 'IfHeader and IfHeaderStatic'),
  10: pred('IfFooter', 'IfFooter and IfFooterStatic'), 11: pred('LoopHeader'), 12: pred('LoopFooter'), 13: pred('PostLoopFooter'), 14: pred('Break', 'BreakBlock'),
  15: pred('Continue', 'ContinueBlock'), 16: ('isStatic', P, 'default returns 0, only IfHeaderStatic and IfFooterStatic override it'),
  17: ('accept', P, 'calls a method of the visitor (*(param_2+0x20)) with this+0x90 (instruction list); each subclass calls its own visitor slot (visitBlock/visitIfHeader/...)'),
  18: ('verify', P, 'default walks the predecessor/successor vectors (+0xd0/+0xd4) and the instruction list calling inst slot 2 (validate); the loops that compared the vectors are empty (assertions compiled out)'),
  19: ('getKindName', 'CONFIRMED', 'returns the block kind string ("SIMPLE", "IF_HEADER", ...)')},
 'IRInst': {
  2: ('validate', P, 'loops over the operand records with results unused, tests option bits and calls slots 25/26 whose result is dropped (assertions compiled out); returns 1'),
  3: ('removeFromListEx', P, 'same body as slot 4 with one more argument: unlinks the instruction from the block list and clears the in-list flag (bit 0 of +0x14)'),
  4: ('removeFromList', P, 'unlinks the instruction from the block list (FUN_0019401c), fixes the entry pointer (+300 of the entry block) and the flag bits of +0x14'),
  5: ('getNumSources', P, 'default returns inst+0x84; Mov/Unary return 1, Nop/Zeroary 0 (init sets +0x84 per opcode)'),
  6: ('getNumDests', P, 'default returns inst+0x80; Export returns 0'),
  7: ('accept', P, 'visitor dispatch: ALU classes call visitor slot 0x38 (visitAlu), TextureFetch 0x5c, MemLoad 0x28, ...; the IRInst default dispatches on the opcode category (7 -> 0x50, 6 -> 0x4c, 9 -> 0x38)'),
  8: ('acceptCallPseudo', P, 'only Start/End CallRoutine and Start/End MakeCall override it: they call visitor slots 0xac/0xb0/0xb4/0xb8'),
  9: ('isAlu', P, 'default: opcode category (opcodeInfo+4) in {6,7,8}; the ALU classes override it with return 1'),
  10: ('isFetch', P, 'return 1 in IRFetch/IRMemLoad/IRMemStore/IRTextureFetch/IRVertexFetch'), 11: ('isVertexFetch', P, 'return 1 in IRVertexFetch'),
  12: ('isTextureFetch', P, 'return 1 in IRTextureFetch(+Gradients)'), 13: ('isEntry', P, 'return 1 in IREntry'), 14: ('isExit', P, 'return 1 in IRExit'),
  15: ('isLoopStart', P, 'default opcodeInfo+4 == 4, IRLoopStart returns 1'), 16: ('isLoad', P, 'return 1 in IRLoad and its subclasses'),
  17: ('isLoadTemp', P, 'return 1 in IRLoadTemp'), 18: ('isLoadConst', P, 'return 1 in IRLoadConst'), 19: ('isLoadInterp', P, 'return 1 in IRLoadInterp'),
  20: ('isUndefined', P, 'return 1 in IRUndefined'), 21: ('isProjection', P, 'return 1 in IRProjection'), 22: ('isMerge', P, 'return 1 in IRMerge'),
  23: ('isPresub', P, 'return 1 in IRPresub1 and IRPresub2'), 24: ('isMix', P, 'return 1 in IRMix'), 25: ('isMov', P, 'return 1 in IRMov'),
  26: ('isExport', P, 'return 1 in IRExport and its subclasses'), 27: ('isGeomExport', P, 'return 1 in IRGeomExport'), 29: ('isMemLoad', P, 'return 1 in IRMemLoad'),
  30: ('isMemStore', P, 'return 1 in IRMemStore'), 31: ('isPhi', P, 'only IRPhiNode overrides it (a bare blr: returns this, nonzero)'),
  36: ('appendSource', P, 'default increments inst+0x84 (source count) and stores the new operand into the next record (FUN_001046c8)'),
  38: ('getKindName', 'CONFIRMED', 'returns the instruction kind string ("alu", "fetch", "export", "pseudo", "unknown")')},
 'OpcodeInfo': {
  0: ('init', 'CONFIRMED', 'called right after an IRInst is constructed (FUN_001043f0 stores +0x88 then the factory path): sets inst+0x80 (dest count), +0x84 (source count), OR-s flag bits into inst+0x14 and stores the category in info+4'),
  1: ('fold', P, 'constant folder: writes the result of the op on the operand values (param_3+4, +8) to *param_2 and returns 1 when it could fold (Add: out = a + b)'),
  2: ('foldVector', P, 'constant folder for the dot-product ops (Dot3/Dot4/Dot2Add and the IEEE variants): out = sum of products of two operand vectors'),
  3: ('dtor', 'CONFIRMED', 'stores the OpcodeInfo vtable (complete destructor)'), 4: ('deleting_dtor', 'CONFIRMED', 'stores the OpcodeInfo vtable then operator delete')},
 'VRegInfo': {
  2: ('clone', P, 'allocates an object of the class from the arena and copy-constructs it (same shape as Block::clone)'),
  3: ('isInterpolator', P, 'return 1 in Interpolator'), 4: ('isExportValue', P, 'return 1 in ExportValue'),
  5: ('isFixedValueOrVertexRegister', P, 'return 1 in FixedValue and VertexRegister'), 6: ('isTempValue', P, 'return 1 in TempValue and its subclasses'),
  7: ('isLoopIndexedSet', P, 'return 1 in the LoopIndexed*Set classes'), 8: ('isResource', P, 'return 1 in Resource')},
 'MachineAssembler': {  # visitor slots: names from IRInst::accept / Block::accept (which visitor slot each class calls)
  10: ('visitMemLoad', P, 'called by IRMemLoad::accept (visitor+0x28)'), 11: ('visitMemStore', P, 'IRMemStore::accept (visitor+0x2c)'),
  13: ('visitBlock', P, 'Block::accept default (visitor+0x34): plain/entry/exit/any/func-end blocks'), 14: ('visitAlu', P, 'IRAlu family, IRNop and category-9 instructions call visitor+0x38'),
  15: ('visitExport', P, 'IRExport::accept (visitor+0x3c)'), 16: ('visitExportColorAndFog', P, 'IRExportColorAndFog::accept (visitor+0x40)'), 17: ('visitGeomExport', P, 'IRGeomExport::accept (visitor+0x44)'),
  18: ('visitMov', P, 'IRMov::accept (visitor+0x48)'), 19: ('visitMova', P, 'IRInst::accept default for opcode category 6 (Mova*) calls visitor+0x4c'), 20: ('visitKill', P, 'IRInst::accept default for opcode category 7 (KillE/GT/GE/NE/One) calls visitor+0x50'),
  21: ('visitKill2', P, 'IRKill2::accept (visitor+0x54)'), 22: ('visitVertexFetch', P, 'IRVertexFetch::accept (visitor+0x58)'), 23: ('visitTextureFetch', P, 'IRTextureFetch::accept (visitor+0x5c)'),
  24: ('visitLoopHeader', P, 'LoopHeader::accept (visitor+0x60)'), 25: ('visitIfHeader', P, 'IfHeader::accept (visitor+0x64)'), 26: ('visitIfHeaderStatic', P, 'IfHeaderStatic::accept (visitor+0x68)'),
  28: ('visitIfFooter', P, 'IfFooter::accept (visitor+0x70)'), 29: ('visitIfFooterStatic', P, 'IfFooterStatic::accept (visitor+0x74)'), 30: ('visitLoopFooter', P, 'LoopFooter::accept (visitor+0x78)'),
  31: ('visitPostLoopFooter', P, 'PostLoopFooter::accept (visitor+0x7c)'), 32: ('visitBreak', P, 'BreakBlock::accept (visitor+0x80)'), 33: ('visitContinue', P, 'ContinueBlock::accept (visitor+0x84)'),
  43: ('visitStartCallRoutine', P, 'IRStartCallRoutine::acceptCallPseudo (visitor+0xac)'), 44: ('visitEndCallRoutine', P, 'IREndCallRoutine::acceptCallPseudo (visitor+0xb0)'),
  45: ('visitStartMakeCall', P, 'IRStartMakeCall::acceptCallPseudo (visitor+0xb4)'), 46: ('visitEndMakeCall', P, 'IREndMakeCall::acceptCallPseudo (visitor+0xb8)')},
 'HwLimits': {
  68: ('flattenIfs', P, 'KhanPs/KhanVs call pass_flatten_ifs(program) from this slot; the base class is empty'),
  91: ('getOpcodeTraits', 'CONFIRMED', 'returns the per-opcode record table (0x38-byte records) read by the FUN_001129xx..FUN_00113xxx accessors via *(compiler+0x30c) slot 0x16c')},
}
GENERIC_ROOTS = ['Block', 'IRInst', 'OpcodeInfo', 'VRegInfo', 'MachineAssembler', 'HwLimits', 'HwChip', 'ResourceModel', 'ThreadModel', 'SchedNode', 'DListNode']
MAXSLOT = {'DListNode': 2}                  # the slots DListNode itself declares (its Block/IRInst subclasses are handled by their own family)
DTOR_SLOTS = {'OpcodeInfo': {3: 'dtor', 4: 'deleting_dtor'}}
DTORS = {0: 'dtor', 1: 'deleting_dtor'}

def members(root):
    return sorted((c for c in cls2vt if c == root or root in anc(c)), key=lambda c: (depth(c), c))

# F1's existing names
f1 = {}
for l in open(os.path.join(D, 'names_F1_func.tsv')):
    c = l.rstrip('\n').split('\t')
    if len(c) > 3 and c[0] == 'func': f1[c[1]] = c[2]
def is_real(name):          # a function that already has a meaningful (non-Ghidra, non-vslot) name
    return not re.match(r'(FUN|orph|thunk_FUN)_', name) and 'vslot' not in name

byname = {v: k for k, v in cur.items()}
slot_of = {}
taken = set(); rows = []
done = {}
for root in GENERIC_ROOTS:
    spec = SLOTS.get(root, {})
    dt = DTOR_SLOTS.get(root, DTORS)
    for k in range(min(MAXSLOT.get(root, 999), max((len(slots(cls2vt[c])) for c in members(root)), default=0))):
        for c in members(root):
            s = slots(cls2vt[c])
            if k >= len(s): continue
            a = s[k]
            if not a or a not in cur or a in done: continue
            name = cur[a]
            if is_real(name): done[a] = name; slot_of.setdefault(a, (name, root, k)); continue
            sn, tier, ev = spec.get(k, (None, None, None))
            if k in dt:
                sn, tier, ev = dt[k], 'CONFIRMED', 'vtable slot %d: %s' % (k, 'complete destructor' if dt[k] == 'dtor' else 'deleting destructor (GCC 4 layout)')
            if sn is None:
                sn, tier, ev = 'vslot%d' % k, 'UNKNOWN', 'vtable slot %d of %s (override bodies differ per class; role not derived)' % (k, root)
            new = '%s__%s' % (c, sn)
            if new == name: done[a] = new; taken.add(new); slot_of.setdefault(a, (new, root, k)); continue
            if new in taken or new in byname and byname[new] != a:
                new = '%s_%x' % (new, a)
            taken.add(new); done[a] = new
            slot_of.setdefault(a, (new, root, k))
            if cur[a] != new:
                rows.append(('func', cur[a], new, tier, 'vtable slot %d of %s (first class %s holding it); %s' % (k, root, c, ev)))
PARAMS = {   # (family root, slot) -> {param index: (name, tier, evidence)}; every virtual method gets param_1 = this (the receiver of the vtable call)
 ('IRInst', 2): {2: ('compiler', P, '*(param_2+0x6c4) is the options object of the compiler (the same access as in FUN_001043f0 callers)')},
 ('IRInst', 3): {3: ('compiler', P, '*(param_3+0x6c4) options object')},
 ('IRInst', 4): {2: ('compiler', P, '*(param_2+0x6c4) options object')},
 ('IRInst', 7): {2: ('visitor', P, 'a method of param_2 is called with (param_2, this): visitor pattern')},
 ('IRInst', 8): {2: ('visitor', P, 'a method of param_2 is called with (param_2, this): visitor pattern')},
 ('Block', 17): {2: ('traversal', P, 'the visitor is *(param_2+0x20)')},
 ('Block', 3): {2: ('inst', P, 'the argument is linked into the list head and its +0x158 is set to this block')},
 ('OpcodeInfo', 0): {2: ('inst', 'CONFIRMED', 'its +0x80/+0x84/+0x14 are written (IRInst fields)'), 3: ('compiler', P, 'passed on to FUN_000ee9ac(*(param_3+0x6c4), inst)')},
 ('OpcodeInfo', 1): {2: ('result', P, 'the folded value is stored through it'), 3: ('operands', P, 'operand values are read at +4, +8 (index 0 holds the count/kind)')},
 ('OpcodeInfo', 2): {2: ('result', P, 'the folded value is stored through it'), 3: ('srcA', P, 'dot product operand vector'), 4: ('srcB', P, 'dot product operand vector')},
}
def params_rows(rows_by_addr):
    out = []
    for a, (name, root, k) in rows_by_addr.items():
        if 'unowned_code' in srcfile[a]: continue          # apply_names.py edits part_*.c only (and the gate compiles only those)
        text = open(srcfile[a]).read()
        m = re.search(r'(?m)^/\* %s @ 0x%x \(\d+ bytes\) \*/$' % (re.escape(cur[a]), a), text)
        e = text.find('\n/* ', m.end()); body = text[m.start():e if e > 0 else len(text)]
        ids = set(re.findall(r'[A-Za-z_]\w*', body))
        spec = {1: ('this', 'CONFIRMED', 'receiver of the vtable call (first argument of a C++ member function)')}
        spec.update(PARAMS.get((root, k), {}))
        for i, (nm, tier, ev) in sorted(spec.items()):
            old = 'param_%d' % i
            if old in ids and nm not in ids:
                out.append(('local', cur[a], old, nm, tier, 'vtable slot %d of %s: %s' % (k, root, ev)))
    return out
if '--params' in sys.argv:
    print('# local rows (parameters of the virtual methods) for %s (Tools/userspace/gen_slot_func_rows.py --params)' % D)
    for r in params_rows(slot_of): print('\t'.join(r))
    sys.stderr.write('%d param rows\n' % len([1 for _ in slot_of])); sys.exit(0)
print('# func rows for %s (Tools/userspace/gen_slot_func_rows.py): virtual-method functions named by vtable slot; chained after names_F1_func.tsv' % D)
for r in rows: print('\t'.join(r))
sys.stderr.write('%d rows\n' % len(rows))
