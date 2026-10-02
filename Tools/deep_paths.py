#!/usr/bin/env python3
"""deep_paths.py STOCK_DIS OURS_DIS [NOTES_TSV] > Tests/deep_paths.md   (issue #100, Step 0 - offline, no hardware)

One section per external method (GL 0-19, 2D 0-17, DVD 0-21, Surface 0-18 - the 81 methods of Tests/method_shapes.txt; the ten of #88-#97 are
marked, the 71 of #100 get the full treatment) with the MACHINE-DERIVED half of the path map:
  * the wire shape from the dispatch table (Tests/method_shapes.txt, byte-dumped from the shipped kext);
  * every IOReturn constant the SHIPPED body can produce (`lis rX,0xe000; ori rX,rX,0x2NN` in the shipped disassembly) next to the constants the
    REBUILT body produces and the constants in the _Port.cpp source - any difference is printed (the "checked against the stock disassembly" of
    criterion 1);
  * ordered direct callees of both bodies (locks, sleeps, allocators, hardware writers) and the properties they imply: SLEEPS (IOLockSleep /
    IOSleep / thread_block), ALLOCATES, HW-WRITE (a store through the MMIO base is not detected - see the manual notes), LOOP (a backward branch);
  * the guard line next to each return-code site in the source.
The MANUAL half (preconditions of each non-guard path, the proven call sequence that builds them, the confirmed tier, reasons) comes from NOTES_TSV
(`key<TAB>field<TAB>text`, key = `<Class> <sel>`), so a hand-written statement can never be mistaken for a derived one."""
import sys, re, bisect, collections, glob, os
sdis, odis = sys.argv[1], sys.argv[2]
notes = collections.defaultdict(dict)
if len(sys.argv) > 3 and os.path.exists(sys.argv[3]):
    for l in open(sys.argv[3]):
        if l.startswith('#') or not l.strip(): continue
        f = l.rstrip('\n').split('\t')
        if len(f) >= 3: notes[f[0]][f[1]] = f[2]
led = [l.rstrip('\n').split('\t') for l in open('Ledger/kext_ppc_ledger.tsv')]
a2s = {int(f[0], 16): (f[5].lstrip('_') if len(f) >= 6 and f[5] else f[4]) for f in led if len(f) >= 5}
sym2row = {f[5]: (int(f[0], 16), int(f[1]), f[4]) for f in led if len(f) >= 6 and f[2] == 'method'}
ledaddrs = sorted(a2s)
INS = re.compile(r'^([0-9a-f]{8})\t(\S+)\s*(.*)$')
srows = []; stub = {}
for l in open(sdis):
    m = INS.match(l)
    if m:
        srows.append((int(m.group(1), 16), m.group(2), m.group(3)))
        if m.group(2) == 'jbsr' and ',' in m.group(3): nm, st = m.group(3).split(',', 1); stub[int(st, 16)] = nm.lstrip('_')
saddr = [r[0] for r in srows]
ofun = {}; cur = None
for l in open(odis):
    s = l.strip()
    if s.endswith(':') and not l.startswith('\t') and not re.match(r'^[0-9a-f]{8}\t', l): cur = s[:-1]; ofun[cur] = []; continue
    m = INS.match(l)
    if m and cur is not None: ofun[cur].append((int(m.group(1), 16), m.group(2), m.group(3)))
def callees(rows, lo=None, hi=None):
    out = []
    for k, (a, op, rest) in enumerate(rows):
        if op == 'jbsr': out.append(rest.split(',')[0].lstrip('_'))
        elif op in ('bl', 'bla'):
            t = rest.split()[0] if rest else ''
            out.append(a2s.get(int(t, 16), t) if t.startswith('0x') else t.lstrip('_'))
        elif op == 'bctrl' or (op == 'bctr' and not (k + 1 < len(rows) and rows[k + 1][1] == '.long')): out.append('<vtable>')
        elif op == 'b' and rest:
            t = rest.split()[0]
            if t.startswith('0x'):
                if lo is not None and not (lo <= int(t, 16) < hi):
                    if int(t, 16) in a2s: out.append(a2s[int(t, 16)])
                    elif int(t, 16) in stub: out.append(stub[int(t, 16)])
            else: out.append(t.lstrip('_'))
    return out
def codes(rows):
    """IOReturn constants materialised in the body: `lis rX,0xe000` followed by `ori rY,rX,0x2NN`, and `li rX,-0x...` is not used for these"""
    out = set(); last = {}
    for a, op, rest in rows:
        ops = [x.strip() for x in rest.split(',')]
        if op == 'lis' and len(ops) == 2 and ops[1].lower() == '0xe000': last[ops[0]] = a
        elif op == 'ori' and len(ops) == 3 and ops[1] in last and re.match(r'^0x[0-9a-f]+$', ops[2]): out.add(0xe0000000 | int(ops[2], 16)) if 0x2b0 <= int(ops[2], 16) <= 0x2ff else None
        elif op in ('or', 'mr') and len(ops) >= 2 and ops[1] in last: last[ops[0]] = last[ops[1]]
    return out
NAMES = {0xe00002bc: 'Error', 0xe00002bd: 'NoMemory', 0xe00002be: 'NoResources', 0xe00002c0: 'NoDevice', 0xe00002c2: 'BadArgument', 0xe00002c7: 'Unsupported', 0xe00002cc: 'CannotLock', 0xe00002d6: 'Timeout?', 0xe00002d8: 'NotReady', 0xe00002d9: 'NotAttached', 0xe00002f0: 'NotFound'}
def nm(c): return '0x%08x %s' % (c, NAMES.get(c, '?'))
SLEEP = ('IOLockSleep', 'IOSleep', 'thread_block', 'IOSleepWithLeeway', 'tsleep', 'IOLockSleepDeadline')
ALLOC = ('IOMalloc', 'IOMallocAligned', 'IOBufferMemoryDescriptor', 'alloc_surfaces', 'alloc_surfaces_retry', 'alloc_surfaces_pageq', 'allocCommandBuffer', 'allocMoreCommandBuffers', 'new_texture', 'new_agp_texture', 'new_surface_texture', 'new_global_texture', 'new_agpref_texture', 'alloc_buf_handle', 'alloc_client_shared', 'declare_image', 'create_transfer', 'prepare_vram', 'alloc_buffer_backing_store', 'withAddress', 'OSObjectnw', 'allocTransfer', 'alloc_and_load', 'alloc_handles', 'addToGART', 'addTransferToGART', 'map_transfer_to_GART', 'mapVendorTransferBuffer')
HW = ('submit_buffer', 'submit_idct', 'write_regs', 'setup_stereo', 'display_change', 'SWDS', 'set_macrovision', 'write_', 'flush_memory', 'resetPCI', 'startupPCIe', 'setupR520', 'setup2D', 'setup3D')
FLAGS = {0: 'scalarI/scalarO', 2: 'scalarI/structO', 3: 'structI/structO', 4: 'scalarI/structI'}
SKIPPED = {('GL', 19), ('2D', 15), ('DVD', 6), ('DVD', 14), ('DVD', 16), ('DVD', 18), ('Surface', 3), ('Surface', 10), ('Surface', 12), ('Surface', 14)}   # #88-#97
LABEL = {'IOATIR500GLContext': 'GL', 'IOATIR5002DContext': '2D', 'ATIR5002DContext': '2D', 'IOATIR500DVDContext': 'DVD', 'ATIR500DVDContext': 'DVD', 'IOATIR500Surface': 'Surface'}
BASE = {'ATIR5002DContext': 16, 'ATIR500DVDContext': 10}      # the subclass tables continue the base class's selector numbering
rows = []
for l in open('Tests/method_shapes.txt'):
    m = re.match(r'^(\S+)\s+(\d+) flags=(\d+)\(\S+\) count0=(\S+) count1=(\S+)\s+(\S+)$', l)
    if m: rows.append((m.group(1), int(m.group(2)) + BASE.get(m.group(1), 0), int(m.group(3)), m.group(4), m.group(5), m.group(6)))
# GL selector 20 is not in the dispatch table: ATIR500GLContext::start installs it in a special slot (+0x360); 0 scalars in, 5 out
rows.append(('IOATIR500GLContext', 20, 0, '0', '5', '__ZN16ATIR500GLContext11get_hw_infoEPmS0_S0_S0_S0_'))
src = {f: open(f).read() for f in glob.glob('Sources/*.cpp')}
def source_of(demangled_name):
    cls, fn = demangled_name.split('::')[-2:]
    best = []
    for f, s in src.items():
        for m in re.finditer(r'(?m)^[\w:<>\*& ]*\b%s::%s\s*\(' % (re.escape(cls), re.escape(fn)), s):
            # body = to the matching closing brace
            i = s.index('{', m.end()) if '{' in s[m.end():m.end()+400] else -1
            if i < 0: continue
            d = 0; k = i
            while k < len(s):
                if s[k] == '{': d += 1
                elif s[k] == '}':
                    d -= 1
                    if d == 0: break
                k += 1
            best.append((f, s[m.start():k + 1]))
    return best
print('# External-method deep paths - Step 0 (issue #100)\n')
conf=sorted(k for k,v in notes.items() if 'CONFIRMED' in v.get('tier',''))
prov=sorted(k for k,v in notes.items() if v.get('tier','').startswith('provisional'))
print('**Coverage summary (from deep_paths_notes.tsv):** %d rows CONFIRMED live on the stock kext: %s. %d rows still only PROVISIONAL (the #100 table\'s own tier, not yet hand-traced).\n' % (len(conf), ', '.join(conf), len(prov)))
print('Generated by `Tools/deep_paths.py` from the shipped kext\'s dispatch tables (`Tests/method_shapes.txt`), the shipped and rebuilt disassemblies and the\n`Sources/` bodies; the hand-written statements (preconditions, proven sequences, confirmed tiers) come from `Tests/deep_paths_notes.tsv` and are\nlabelled **manual**. The machine-derived parts need no hardware; the rows listed as CONFIRMED in the summary were run live on the stock kext by `Tests/test_deep_t1.c` / `test_deep_t2.c`.\n')
nrows = 0; mism = []
for cls, sel, flags, c0, c1, sym in rows:
    key = '%s %d' % (LABEL[cls], sel)
    dm = re.sub(r'^__Z\d+', '', sym)
    name = re.match(r'__ZN(\d+)(\w+)', sym); 
    cname = name.group(2)[:int(name.group(1))]; rest = name.group(2)[int(name.group(1)):]
    mm = re.match(r'(\d+)(\w+)', rest); mname = mm.group(2)[:int(mm.group(1))]
    short = '%s::%s' % (cname, mname)
    ent = sym2row.get(sym)
    skipped = (LABEL[cls], sel) in SKIPPED
    print('## %s sel %d - `%s` %s\n' % (LABEL[cls], sel, short, '(own issue #88-#97, not part of #100)' if skipped else ''))
    print('- wire shape: flags %d (%s), count0=%s, count1=%s' % (flags, FLAGS.get(flags, '?'), c0, c1))
    if not ent:
        print('- **no ledger entry for `%s`** (overload/alias?)\n' % sym); continue
    a, sz, lname = ent
    nxt = ledaddrs[bisect.bisect_right(ledaddrs, a)] if bisect.bisect_right(ledaddrs, a) < len(ledaddrs) else a + sz
    hi = a + max(sz, nxt - a)
    srng = srows[bisect.bisect_left(saddr, a):bisect.bisect_left(saddr, hi)]
    orng = ofun.get(sym, [])
    sc, oc = codes(srng), codes(orng)
    sco, oco = callees(srng, a, hi), callees(orng)
    bodies = source_of(lname)
    qc = set()
    for f, b in bodies: qc |= {int(x, 16) for x in re.findall(r'0xe00002[0-9a-fA-F]{2}', b)}
    print('- shipped body: `0x%x`, %d bytes; rebuilt body: %d bytes; source: %s' % (a, hi - a, len(orng) * 4, ', '.join(sorted({os.path.basename(f) for f, b in bodies})) or '(not found)'))
    print('- IOReturn constants in the shipped body: %s' % (', '.join(nm(c) for c in sorted(sc)) or '(none: returns only 0 / a callee\'s result)'))
    if sc != oc or (qc and sc != qc and not (sc <= qc)):
        mism.append(key)
        print('- **CODE-SET DIFFERENCE**: rebuilt %s | source %s' % (', '.join(nm(c) for c in sorted(oc)) or '(none)', ', '.join(nm(c) for c in sorted(qc)) or '(none)'))
    else: print('- rebuilt body and source produce the same constants')
    props = []
    if any(any(s in c for s in SLEEP) for c in sco): props.append('SLEEPS')
    if any(any(s in c for s in ALLOC) for c in sco): props.append('ALLOCATES')
    if any(any(s in c for s in HW) for c in sco): props.append('HW-ish callee')
    back = sum(1 for k, (aa, op, rest) in enumerate(srng) if op in ('b', 'bne', 'beq', 'blt', 'bgt', 'ble', 'bge', 'bdnz') and rest.split()[-1].startswith('0x') and int(rest.split()[-1], 16) < aa and int(rest.split()[-1], 16) >= a)
    if back: props.append('LOOP (%d backward branch(es))' % back)
    print('- derived properties: %s' % (', '.join(props) or 'none detected'))
    sf = re.sub(r'^(IOATIR500|ATIR500|IOATIR5002D|ATIR5002D|ATIRadeonX1000)', '', '')
    print('- shipped callees (ordered): `%s`' % (' '.join(re.sub(r'^ZN?\d*', '', c)[:36] for c in sco) or '-'))
    # guard lines next to each return-code site in the source
    guards = []
    for f, b in bodies:
        L = b.split('\n')
        for i, line in enumerate(L):
            m = re.search(r'0xe00002[0-9a-fA-F]{2}', line)
            if m:
                ctx = [x.strip() for x in L[max(0, i - 3):i] if re.search(r'\b(if|else|while|for|switch)\b', x)]
                guards.append('%s <- `%s`' % (nm(int(m.group(0), 16)), (ctx[-1] if ctx else line.strip())[:110]))
    if guards: print('- return-code sites in the source (code <- nearest guard): ' + '; '.join(dict.fromkeys(guards)))
    n = notes.get(key, {})
    for fld in ('tier', 'preconditions', 'sequence', 'reason', 'codes'):
        if fld in n: print('- **manual %s**: %s' % (fld, n[fld]))
    if not skipped: nrows += 1
    print()
print('\n---\n%d methods of #100 documented; %d with a code-set difference between shipped / rebuilt / source: %s' % (nrows, len(mism), ', '.join(mism) or 'none'))
