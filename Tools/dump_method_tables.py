#!/usr/bin/env python3
"""
dump_method_tables.py - extract the driver's external-method dispatch tables
(what the kernel's own argument-count check enforces) STATICALLY from the shipped
kext, and optionally audit the #42 test harness against them.

The shipped ATIRadeonX1000.kext is an MH_OBJECT with a full relocation table, so each
table entry's method symbol is named in the file - no hardware needed. Entry layout
(24 bytes, matches Sources/*ExternalMethods.cpp): {object=0, 0xffff, IOMethod ptr, flags,
count0, count1} with the standard IOExternalMethod meaning:
    flags 0 kIOUCScalarIScalarO   count0 = #scalar inputs,   count1 = #scalar outputs
    flags 2 kIOUCScalarIStructO   count0 = #scalar inputs,   count1 = struct output size
    flags 3 kIOUCStructIStructO   count0 = struct input size, count1 = struct output size
    flags 4 kIOUCScalarIStructI   count0 = #scalar inputs,   count1 = struct input size
    0xffffffff = kIOUCVariableStructureSize
(An earlier note in this repo said these counts could not be trusted positionally; that
was a misreading - the table is authoritative and every harness call whose shape matches
it executed, every call that did not was rejected kIOReturnBadArgument.)

Usage:  dump_method_tables.py KEXT_BIN [--audit Tests]     (KEXT_BIN = thin or fat ppc)
"""
import struct, sys, re, os

FLAGS = {0: 'ScalarIScalarO', 2: 'ScalarIStructO', 3: 'StructIStructO', 4: 'ScalarIStructI'}
VAR = 0xffffffff

def load(path):
    d = open(path, 'rb').read()
    if struct.unpack('>I', d[:4])[0] == 0xcafebabe:
        n = struct.unpack('>I', d[4:8])[0]
        for i in range(n):
            cpu, sub, off, size, al = struct.unpack('>5I', d[8+20*i:28+20*i])
            if cpu == 18:
                d = d[off:off+size]; break
    return d

def parse(d):
    nc = struct.unpack('>I', d[16:20])[0]
    p = 28; secs = {}; symoff = None
    for _ in range(nc):
        c, cs = struct.unpack('>II', d[p:p+8])
        if c == 1:
            ns = struct.unpack('>I', d[p+48:p+52])[0]; q = p+56
            for _ in range(ns):
                name = d[q:q+16].rstrip(b'\0').decode(); a, s, o, al, ro, nr = struct.unpack('>6I', d[q+32:q+56])
                secs[name] = (a, s, o, ro, nr); q += 68
        elif c == 2:
            symoff, nsyms, stroff, strsize = struct.unpack('>4I', d[p+8:p+24])
        p += cs
    syms = []
    for i in range(nsyms):
        strx, t, sect, desc, val = struct.unpack('>IBBhI', d[symoff+12*i:symoff+12*i+12])
        syms.append((d[stroff+strx:d.index(b'\0', stroff+strx)].decode('latin1'), sect, val))
    return secs, syms

def tables(d):
    secs, syms = parse(d)
    ca, cs, co, cro, cnr = secs['__const']
    def w(va): o = va-ca+co; return struct.unpack('>I', d[o:o+4])[0]
    rel = {}
    for i in range(cnr):
        w0, w1 = struct.unpack('>II', d[cro+8*i:cro+8*i+8])
        if not (w0 & 0x80000000) and (w1 >> 4) & 1:
            rel[w0+ca] = syms[w1 >> 8][0]
    byaddr = {}
    for n, sect, v in syms:
        if sect == 1: byaddr.setdefault(v, n)
    out = []; va = ca
    while va < ca+cs-24:
        if w(va) == 0 and w(va+4) == 0xffff:
            n = 0
            while va+24*n < ca+cs-24 and w(va+24*n) == 0 and w(va+24*n+4) == 0xffff: n += 1
            if n >= 3:
                rows = []
                for i in range(n):
                    e = va+24*i
                    rows.append((rel.get(e+8) or byaddr.get(w(e+8), '?'), w(e+12), w(e+16), w(e+20)))
                out.append((va, rows)); va += 24*n; continue
        va += 4
    return out

def fmt(x): return 'var' if x == VAR else str(x)

def main():
    a = sys.argv[1:]
    d = load(a[0]); tabs = tables(d)
    # class for each table = first entry's class in its mangled name
    named = []
    for va, rows in tabs:
        m = re.match(r'__ZN(\d+)([A-Za-z0-9_]+)', rows[0][0])
        cls = m.group(2)[:int(m.group(1))] if m else '?'
        named.append((cls, va, rows))
    for cls, va, rows in named:
        print('# %s table @ 0x%x (%d entries)' % (cls, va, len(rows)))
        for i, (fn, fl, c0, c1) in enumerate(rows):
            print('%s %2d flags=%d(%s) count0=%s count1=%s  %s' % (cls, i, fl, FLAGS.get(fl, '?'), fmt(c0), fmt(c1), fn))
    if '--audit' in a:
        audit(named, a[a.index('--audit')+1])

def audit(named, tdir):
    """Compare every IOConnectMethod* call in the harness with its table entry."""
    # selector -> (class-of-connection, table index). GL/Surface: index==selector; 2D: sel<16 base;
    # DVD: sel<10 base, else subclass table index sel-10.
    by = {}
    for cls, va, rows in named: by.setdefault(cls, []).append(rows)
    def lookup(ctx, sel):
        if ctx == 'gl':   return by['IOATIR500GLContext'][0][sel] if sel < 20 else None
        if ctx == 'surface': return by['IOATIR500Surface'][0][sel]
        if ctx == '2d':   return by['IOATIR5002DContext'][0][sel] if sel < 16 else None
        if ctx == 'dvd':
            return by['IOATIR500DVDContext'][0][sel] if sel < 10 else by['ATIR500DVDContext'][0][sel-10]
    kind = {'ScalarIScalarO': 0, 'ScalarIStructureO': 2, 'ScalarIStructureI': 4, 'StructureIStructureO': 3}
    bad = 0
    for ctx, f in (('gl', 'test_gl_context.c'), ('2d', 'test_2d_context.c'), ('dvd', 'test_dvd_context.c'), ('surface', 'test_surface_context.c')):
        s = open(os.path.join(tdir, f)).read()
        for m in re.finditer(r'IOConnectMethod(ScalarIScalarO|ScalarIStructureO|ScalarIStructureI|StructureIStructureO)\(\s*connect,\s*(\d+),\s*([^,]+),\s*([^,;]+)', s):
            k = kind[m.group(1)]; sel = int(m.group(2)); a, b = m.group(3).strip(), m.group(4).strip()
            e = lookup(ctx, sel)
            if e is None: continue
            fn, fl, c0, c1 = e
            problems = []
            if k != fl: problems.append('type %d != table %d' % (k, fl))
            try:
                if int(a) != c0 and c0 != VAR: problems.append('count %s != table %s' % (a, fmt(c0)))
            except ValueError: pass
            try:
                if int(b) != c1 and c1 != VAR and k in (0,): problems.append('count1 %s != table %s' % (b, fmt(c1)))
            except ValueError: pass
            if problems:
                bad += 1
                print('MISMATCH %-7s sel %2d %s: %s' % (ctx, sel, fn[:48], '; '.join(problems)))
    print('%d mismatching call(s)' % bad)

if __name__ == '__main__':
    main()
