#!/usr/bin/env python3
"""data_sections.py MACHO OUTDIR [LEDGER.tsv] - transcribe every non-code section of a big-endian 32-bit Mach-O (dylib, bundle or kext object):
  OUTDIR/sections.tsv      every segment/section: address, size, file offset, flags, transcribed-as
  OUTDIR/cstrings.c        __cstring (and similar string sections) as one C string per NUL-terminated string, at its address
  OUTDIR/<seg>_<sect>.c    everything else as `const unsigned int` words (+ tail bytes), with a comment per word that is a pointer:
                           the symbol / function / string it points at, the indirect-symbol name for lazy/non-lazy pointer slots, the float
                           value for __literal4/8, the relocation's target for kext (MH_OBJECT) files
  zerofill sections (__bss, __common) are listed in sections.tsv only (no initial value).
Every emitted word is checked by re-parsing the generated C against the binary."""
import sys, struct, os, re
src, out = sys.argv[1:3]; ledger = sys.argv[3] if len(sys.argv) > 3 else None
os.makedirs(out, exist_ok=True); d = open(src, 'rb').read()
_cs = os.path.join(out, 'cstrings.c')
if os.path.exists(_cs): os.remove(_cs)      # the literals are appended per section: start clean so a rerun does not duplicate them
if struct.unpack('>I', d[:4])[0] == 0xcafebabe:
    for i in range(struct.unpack('>I', d[4:8])[0]):
        cpu, sub, off, size, al = struct.unpack('>5I', d[8 + 20 * i:28 + 20 * i])
        if cpu == 18: d = d[off:off + size]; break
assert struct.unpack('>I', d[:4])[0] == 0xfeedface
ftype = struct.unpack('>I', d[12:16])[0]; nc = struct.unpack('>I', d[16:20])[0]; q = 28
secs = []; symoff = nsyms = stroff = 0; indoff = nind = 0
for _ in range(nc):
    c, cs = struct.unpack('>II', d[q:q + 8])
    if c == 1:
        segname = d[q + 8:q + 24].rstrip(b'\0').decode(); ns = struct.unpack('>I', d[q + 48:q + 52])[0]; r = q + 56
        for _ in range(ns):
            nm = d[r:r + 16].rstrip(b'\0').decode(); sg = d[r + 16:r + 32].rstrip(b'\0').decode()
            a, sz, off, al, reloff, nreloc, flags, r1, r2 = struct.unpack('>9I', d[r + 32:r + 68]); r += 68
            secs.append(dict(name=nm, seg=sg, addr=a, size=sz, off=off, reloff=reloff, nreloc=nreloc, flags=flags, r1=r1, r2=r2))
    elif c == 2: symoff, nsyms, stroff, strsize = struct.unpack('>4I', d[q + 8:q + 24])
    elif c == 0xb: indoff, nind = struct.unpack('>2I', d[q + 56:q + 64])
    q += cs
# load commands: dependencies, install name, segments (the parts of the file that are neither sections nor code)
lcs = []; q = 28
for _ in range(nc):
    c, cs = struct.unpack('>II', d[q:q + 8])
    if c in (0xc, 0xd, 0x1c, 0xe):   # LOAD_DYLIB, ID_DYLIB, LOAD_WEAK_DYLIB, LOAD_DYLINKER
        o = struct.unpack('>I', d[q + 8:q + 12])[0]; lcs.append('%s\t%s' % ({0xc: 'LOAD_DYLIB', 0xd: 'ID_DYLIB', 0x1c: 'LOAD_WEAK_DYLIB', 0xe: 'LOAD_DYLINKER'}[c], d[q + o:q + cs].split(b'\0')[0].decode()))
    elif c == 1:
        sn = d[q + 8:q + 24].rstrip(b'\0').decode(); va, vs, fo, fs, mp, ip, nse, fl = struct.unpack('>8I', d[q + 24:q + 56])
        lcs.append('SEGMENT\t%s vmaddr=0x%x vmsize=0x%x fileoff=0x%x filesize=0x%x maxprot=%d initprot=%d sections=%d' % (sn, va, vs, fo, fs, mp, ip, nse))
    else: lcs.append('LC_0x%x\tsize=%d' % (c, cs))
    q += cs
open(os.path.join(out, 'load_commands.tsv'), 'w').write('\n'.join(lcs) + '\n')
syms = []
for i in range(nsyms):
    n_strx, t, sect, desc, val = struct.unpack('>IBBhI', d[symoff + 12 * i:symoff + 12 * i + 12])
    nm = d[stroff + n_strx:d.index(b'\0', stroff + n_strx)].decode('latin1') if n_strx else ''
    syms.append((nm, t, sect, val))
def indirect(i): return struct.unpack('>I', d[indoff + 4 * i:indoff + 4 * i + 4])[0]
byaddr = {}
for nm, t, sect, val in syms:
    if (t & 0x0e) == 0x0e and nm and ftype != 1: byaddr.setdefault(val, nm)
fn = {}
if ledger:
    for l in open(ledger):
        f = l.rstrip('\n').split('\t')
        if len(f) > 4: fn[int(f[0], 16)] = f[2]
def sec_of(a):
    for s in secs:
        if s['addr'] <= a < s['addr'] + s['size'] and s['size']: return s
def esc(b):
    o = ''
    for c in b:
        if c == 0x22: o += '\\"'
        elif c == 0x5c: o += '\\\\'
        elif c == 0x0a: o += '\\n'
        elif c == 0x09: o += '\\t'
        elif 32 <= c < 127: o += chr(c)
        else: o += '\\%03o' % c
    return o
def label(v):
    if v in fn: return fn[v]
    if v in byaddr: return byaddr[v]
    s = sec_of(v)
    if s and s['name'] not in ('__text',) and s['seg'] != '__TEXT': return '%s+0x%x' % (s['name'], v - s['addr'])
    if s and s['name'] == '__cstring':
        return 'cstring @0x%x' % v
    return None
CODE = ('__text', '__picsymbolstub1', '__picsymbol_stub', '__symbol_stub', '__symbol_stub1', '__textcoal_nt', '__StaticInit')
rows = []; total = 0
for s in secs:
    typ = s['flags'] & 0xff; fname = re.sub(r'\W', '_', (s['seg'] + '_' + s['name']).strip('_'))
    how = ''
    if typ in (1, 12, 0x0c):   # zerofill / gb zerofill
        how = 'zerofill (size only)'
    elif s['name'] in CODE and s['name'] != '__textcoal_nt' or s['name'] == '__text' or typ == 0x80000400 & 0xff:
        how = 'code (see part_*.c / raw/)' if s['name'] in CODE else ''
    if how: rows.append((s, how)); continue
    if s['name'] in CODE: rows.append((s, 'code (functions / raw blocks)')); continue
    body = d[s['off']:s['off'] + s['size']]; a0 = s['addr']
    relocs = {}
    if ftype == 1 and s['nreloc']:
        for i in range(s['nreloc']):
            w0, w1 = struct.unpack('>II', d[s['reloff'] + 8 * i:s['reloff'] + 8 * i + 8])
            if w0 & 0x80000000: continue
            symnum = w1 >> 8; ext = (w1 >> 4) & 1
            if ext and symnum < len(syms): relocs[w0] = syms[symnum][0]
    if typ == 2 or s['name'] == '__cstring' or typ == 0x2:   # cstring literals
        with open(os.path.join(out, 'cstrings.c'), 'a') as f:
            f.write('/* %s,%s  0x%x-0x%x */\n' % (s['seg'], s['name'], a0, a0 + s['size']))
            p = 0
            while p < len(body):
                e = body.find(b'\0', p)
                if e < 0: e = len(body) - 1
                f.write('const char cstr_%x[%d] = "%s";\n' % (a0 + p, e - p + 1, esc(body[p:e])))
                p = e + 1
        how = 'cstrings.c'
    else:
        n = len(body) // 4; words = struct.unpack('>%dI' % n, body[:4 * n]); tail = body[4 * n:]
        ind = None
        if typ in (6, 7) and indoff: ind = s['r1']       # non-lazy / lazy symbol pointers
        lines = []
        for i, w in enumerate(words):
            c = ''
            if ind is not None:
                k = indirect(ind + i)
                if k < len(syms): c = ' /* -> %s */' % syms[k][0]
                elif k == 0x80000000: c = ' /* -> local */'
            elif (a0 + 4 * i - a0) in relocs: c = ' /* -> %s */' % relocs[4 * i]
            elif typ in (4,) or s['name'] == '__literal4': c = ' /* %r */' % struct.unpack('>f', struct.pack('>I', w))[0]
            elif w > 0x1000:
                l = label(w)
                if l: c = ' /* -> %s */' % l
            lines.append('    0x%08x,%s /* +0x%x */\n' % (w, c, 4 * i))
        with open(os.path.join(out, fname + '.c'), 'w') as f:
            f.write('/* %s,%s at 0x%x, %d bytes - generated by Tools/userspace/data_sections.py */\n' % (s['seg'], s['name'], a0, s['size']))
            f.write('const unsigned int %s[%d] = {\n%s};\n' % ('sect' + fname, max(n, 1), ''.join(lines) if n else '    0\n'))
            if tail: f.write('const unsigned char %s_tail[%d] = {%s};\n' % ('sect' + fname, len(tail), ', '.join('0x%02x' % b for b in tail)))
        # verify by re-parsing what was written
        txt = open(os.path.join(out, fname + '.c')).read()
        got = [int(x, 16) for x in re.findall(r'^\s+0x([0-9a-f]{8}),', txt, re.M)]
        assert got == list(words) or n == 0, fname
        how = fname + '.c'
    total += s['size']; rows.append((s, how))
with open(os.path.join(out, 'sections.tsv'), 'w') as f:
    f.write('segment\tsection\taddr\tsize\tfileoff\tflags\ttranscribed_as\n')
    for s, how in rows: f.write('%s\t%s\t0x%x\t%d\t%d\t0x%x\t%s\n' % (s['seg'], s['name'], s['addr'], s['size'], s['off'], s['flags'], how))
print(src.split('/')[-1], len(rows), 'sections;', total, 'data bytes transcribed')
