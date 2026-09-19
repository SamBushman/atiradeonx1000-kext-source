#!/usr/bin/env python3
"""
vtable_map.py - list the virtual slots of a class in a Tiger kext that are implemented BY THE KEXT ITSELF
(own virtuals and overrides of base-class virtuals), with byte offset and demangled name. Inherited entries
that point at kernel code (OSObject::..., IOService::..., IOUserClient::...) are skipped.

Usage: vtable_map.py KEXT_BIN CLASS [CLASS ...]
With `--all` also prints inherited entries. Works on the shipped kext and on the rebuilt one (both are
MH_OBJECT with relocations), so `diff` of the two outputs is the vtable-layout check.
"""
import struct, sys, subprocess

def load(path):
    d = open(path, 'rb').read()
    if struct.unpack('>I', d[:4])[0] == 0xcafebabe:
        n = struct.unpack('>I', d[4:8])[0]
        for i in range(n):
            cpu, sub, off, size, al = struct.unpack('>5I', d[8+20*i:28+20*i])
            if cpu == 18: d = d[off:off+size]; break
    return d

def parse(d):
    nc = struct.unpack('>I', d[16:20])[0]; p = 28; secs = {}
    for _ in range(nc):
        c, cs = struct.unpack('>II', d[p:p+8])
        if c == 1:
            ns = struct.unpack('>I', d[p+48:p+52])[0]; q = p+56
            for _ in range(ns):
                name = d[q:q+16].rstrip(b'\0').decode()
                a, s, o, al, ro, nr = struct.unpack('>6I', d[q+32:q+56]); secs[name] = (a, s, o, ro, nr); q += 68
        elif c == 2:
            symoff, nsyms, stroff, strsize = struct.unpack('>4I', d[p+8:p+24])
        p += cs
    syms = []
    for i in range(nsyms):
        strx, t, sect, desc, val = struct.unpack('>IBBhI', d[symoff+12*i:symoff+12*i+12])
        syms.append((d[stroff+strx:d.index(b'\0', stroff+strx)].decode('latin1'), sect, val))
    return secs, syms

def demangle(names):
    out = subprocess.run(['c++filt'], input='\n'.join(n[1:] if n.startswith('__Z') else n for n in names) + '\n',
                         capture_output=True, text=True).stdout.split('\n')
    return out

def dn_is_own(dn):
    return dn.startswith(('IOATIR', 'ATIR', 'ATIRadeon', '___cxa_pure_virtual'))

def main():
    path = sys.argv[1]; classes = [a for a in sys.argv[2:] if not a.startswith('--')]; show_all = '--all' in sys.argv
    d = load(path); secs, syms = parse(d)
    # the vtable lives in whichever data section holds it; find by symbol section number
    sect_by_num = sorted(secs.items(), key=lambda kv: kv[1][0])
    ordered = list(secs.items())            # section order == Mach-O section numbering (1-based)
    byaddr = {}
    for n, s, v in syms:
        if s == 1: byaddr.setdefault(v, n)
    names = {n: (s, v) for n, s, v in syms if s}
    for cls in classes:
        vt = '__ZTV%d%s' % (len(cls), cls)
        if vt not in names: print('# %s: no vtable in this binary' % cls); continue
        sect, base = names[vt]
        sname, (sa, ss, so, sro, snr) = ordered[sect-1]
        def word(va): o = va - sa + so; return struct.unpack('>I', d[o:o+4])[0]
        rel = {}
        for i in range(snr):
            w0, w1 = struct.unpack('>II', d[sro+8*i:sro+8*i+8])
            if not (w0 & 0x80000000) and (w1 >> 4) & 1: rel[w0 + sa] = syms[w1 >> 8][0]
        print('# %s vtable @ 0x%x (%s)' % (cls, base, sname))
        off = 0
        ents = []
        end = None
        # vtable extent: up to the next symbol in the same section
        nxt = sorted(v for n, s, v in syms if s == sect and v > base)
        end = nxt[0] if nxt else sa + ss
        while base + off < end:
            a = base + off
            n = rel.get(a) or byaddr.get(word(a)) or ('<0x%x>' % word(a))
            ents.append((off, n)); off += 4
        dm = demangle([n for _, n in ents])
        for (off, n), dn in zip(ents, dm):
            if dn.startswith('IOATIR500Accelerator::ASICSupportsAGP') : dn = '<null slot>'
            local = dn_is_own(dn)
            if show_all or local:
                print('0x%03x %s' % (off, dn))
main()
