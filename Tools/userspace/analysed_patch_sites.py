#!/usr/bin/env python3
"""analysed_patch_sites.py - per-site record of every edit made to the ANALYSED COPY of a binary (the Ghidra project the dumps come from), issue #69 criterion 4. For each site:
what the stock does there and why the C printed from the edited copy is equivalent. Writes Userspace/<bin>/ppc/analysed_copy_patches.tsv (kind, address, owner, stock behaviour, why equivalent).
Sources: the stock disassembly (millicode call sites), pipeline/failed_switches.json + raw/data_in_text.c (jump tables recovered by FixSwitches), pipeline/b3/constswitch_glprog.txt
(constant-index switches), pipeline/b3/move_entries_*.txt (functions re-created at their true entry), Tools/userspace/gs/*.java for the mechanisms.
  analysed_patch_sites.py   (run from the repo root; needs ~/Documents/ATI-X1900-Decomp/work-bugwf/link/*.dis and dumps/)"""
import re, os, json, bisect
W = os.path.expanduser('~/Documents/ATI-X1900-Decomp/work-bugwf/'); R = os.getcwd() + '/'
IMG = {'glprog': ('libGLProgrammability', 'glprog.dis', 'libGLProgrammability/n_glprog', [(0x97c1a1fc, 0x97c1a26f)]),
       'gld': ('ATIRadeonX1000GLDriver', 'gld_full.dis', 'ATIRadeonX1000GLDriver/n_gld', [(0x1a322c, 0x1a3277)]),
       'libgl': ('libGL', 'libgl.dis', 'libGL/n_libgl', [(0x92f27f90, 0x92f27fdb)]),
       'ga': ('ATIRadeonX1000GA', 'ga.dis', 'ATIRadeonX1000GA/n_ga', []), 'va': ('ATIRadeonX1000VADriver', 'va.dis', 'ATIRadeonX1000VADriver/n_va', [])}
fs = json.load(open(R + 'Tools/userspace/pipeline/failed_switches.json'))
for key, (u, dis, dump, mill) in IMG.items():
    fn = []
    for l in open(W + 'dumps/%s/RANGES.tsv' % dump):
        f = l.rstrip('\n').split('\t')
        if len(f) > 3 and f[2] == 'fn':
            for r in f[3].split(';'):
                if r: lo, hi = (int(x, 16) for x in r.split('-')); fn.append((lo, hi, f[1]))
    fn.sort(); fl = [x[0] for x in fn]
    def owner(a):
        i = bisect.bisect_right(fl, a) - 1
        while i >= 0 and fn[i][0] > a - 0x8000:
            if fn[i][0] <= a < fn[i][1]: return fn[i][2]
            i -= 1
        return '?'
    rows = []
    for lo, hi in mill:            # NopMillicode: `bl` into the register-save chain
        for l in open(W + 'link/' + dis, errors='replace'):
            m = re.match(r'([0-9a-f]{8})\tbl\s+0x([0-9a-f]+)', l)
            if m and lo <= int(m.group(2), 16) <= hi:
                a = int(m.group(1), 16)
                rows.append(('NopMillicode', '0x%x' % a, owner(a), 'bl 0x%s into the FPR-save millicode (stfd f14..f31 chain, 0x%x-0x%x): stores callee-saved FPRs at the frame top, preserves r3..r10' % (m.group(2), lo, hi),
                             'the decompiler modelled the bl as a call clobbering r3..r10 (arguments read back as extraout_rN); nop keeps every value the C can see - the recompiled function saves the FPRs it uses itself'))
    tabs = {}
    rp = R + 'Userspace/%s/ppc/raw/data_in_text.c' % u
    if os.path.exists(rp):
        for l in open(rp):
            m = re.match(r'/\* (0x[0-9a-f]+)-(0x[0-9a-f]+) table switch table of the `bctr` at (0x[0-9a-f]+): entry i -> (\S+) \+ word\[i\]; targets (.*?) \*/', l)
            if m: tabs[int(m.group(3), 16)] = (m.group(1), m.group(2), m.group(5))
    for b in fs.get(key, []):
        a = int(b, 16); t = tabs.get(a)
        rows.append(('FixSwitches', b, owner(a), 'Darwin embedded jump table after the bctr (`lwz/lwzx; add r0,r0,rBase; mtctr; bctr`, offsets relative to the table start' + ((' %s-%s; targets %s' % t) if t else '') + ')',
                     'Ghidra could not recover the table and dropped every case body; the JumpTable override lists the destinations decoded from the stock words, so the decompile contains the same cases (compiled as a C switch / branches)'))
    cp = R + 'Tools/userspace/pipeline/b3/constswitch_%s.txt' % key
    if os.path.exists(cp):
        for l in open(cp):
            b = l.strip()
            if b: a = int(b, 16); rows.append(('PatchConstSwitch', b, owner(a), 'inlined `TInfoSink::prefix(EPrefixError)`: `lwz r0,K(table); add; mtctr; bctr` with a CONSTANT index at this site', 'the bctr becomes `b <the arm the constant selects>` in the analysed copy (RANGES widened to the reachable code): the C carries the one live arm, the other arms belong to the other sites of the shared cleanup code'))
    mp = R + 'Tools/userspace/pipeline/b3/move_entries_%s.txt' % key
    if os.path.exists(mp):
        for tok in open(mp).read().split():
            if ':' in tok:
                o, n = tok.split(':'); rows.append(('MoveEntries', n, owner(int(n, 16)), 'true entry: gcc scheduled instructions (cmpwi / mfcr / stmw ...) BEFORE `mfspr r0,lr`; auto-analysis had started the function at 0x%s' % o.replace('0x', ''), 'the function is re-created at the true entry so the compare is not an orphan and the decompile no longer reads an uninitialised in_cr7 / in_cr0'))
    with open(R + 'Userspace/%s/ppc/analysed_copy_patches.tsv' % u, 'w') as f:
        f.write('# kind\taddress\towner\tstock behaviour at the site\twhy the C from the edited copy is equivalent\n')
        for r in sorted(rows, key=lambda x: (x[0], int(x[1], 16))): f.write('\t'.join(r) + '\n')
    print(key, len(rows), {k: sum(1 for r in rows if r[0] == k) for k in set(r[0] for r in rows)})
