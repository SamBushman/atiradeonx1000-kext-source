"""machoutil.py - just enough big-endian 32-bit Mach-O parsing for the userspace link step (Tools/userspace/link_corpus.py).

  m = load(path)                       thin PPC slice of a (fat) dylib / bundle
  m.segs   [dict(name, vmaddr, vmsize, fileoff, filesize, initprot)]
  m.secs   [dict(seg, name, addr, size, off, reloff, nreloc, flags, r1, r2)]      (section order = load-command order)
  m.syms   [dict(name, type, sect, desc, value)]      m.indirect [symbol index]     m.dysym (dict of dysymtab fields)
  m.relocs [dict(addr, kind, symnum, ext, rtype, length, pcrel, value)]   local + external relocation entries with absolute addresses
  m.dylibs [(cmd, name, current_version, compat_version)]     m.id_dylib  m.flags  m.filetype
  m.read(addr, n)  bytes at a virtual address (file-backed sections only)     m.sec_at(addr)
"""
import struct


class Macho:
    pass


def load(path):
    d = open(path, 'rb').read()
    if struct.unpack('>I', d[:4])[0] == 0xcafebabe:
        for i in range(struct.unpack('>I', d[4:8])[0]):
            cpu, sub, off, size, al = struct.unpack('>5I', d[8 + 20 * i:28 + 20 * i])
            if cpu == 18:
                d = d[off:off + size]
                break
    assert struct.unpack('>I', d[:4])[0] == 0xfeedface, 'not a thin big-endian 32-bit Mach-O'
    m = Macho()
    m.d = d
    m.cpu, m.cpusub, m.filetype, nc, _, m.flags = struct.unpack('>6I', d[4:28])
    m.segs, m.secs, m.syms, m.dylibs, m.id_dylib, m.indirect = [], [], [], [], None, []
    m.dysym = {}
    symoff = nsyms = stroff = 0
    q = 28
    for _ in range(nc):
        c, cs = struct.unpack('>II', d[q:q + 8])
        if c == 1:
            sn = d[q + 8:q + 24].rstrip(b'\0').decode()
            va, vs, fo, fs, mp, ip, nse, fl = struct.unpack('>8I', d[q + 24:q + 56])
            m.segs.append(dict(name=sn, vmaddr=va, vmsize=vs, fileoff=fo, filesize=fs, initprot=ip))
            r = q + 56
            for _ in range(nse):
                nm = d[r:r + 16].rstrip(b'\0').decode()
                sg = d[r + 16:r + 32].rstrip(b'\0').decode()
                a, sz, off, al, reloff, nreloc, flags, r1, r2 = struct.unpack('>9I', d[r + 32:r + 68])
                m.secs.append(dict(seg=sg, name=nm, addr=a, size=sz, off=off, align=al, reloff=reloff, nreloc=nreloc, flags=flags, r1=r1, r2=r2))
                r += 68
        elif c == 2:
            symoff, nsyms, stroff, _s = struct.unpack('>4I', d[q + 8:q + 24])
        elif c == 0xb:
            names = 'ilocalsym nlocalsym iextdefsym nextdefsym iundefsym nundefsym tocoff ntoc modtaboff nmodtab extrefsymoff nextrefsyms indirectsymoff nindirectsyms extreloff nextrel locreloff nlocrel'.split()
            m.dysym = dict(zip(names, struct.unpack('>18I', d[q + 8:q + 80])))
        elif c in (0xc, 0xd, 0x1c, 0x1f):   # LOAD_DYLIB, ID_DYLIB, LOAD_WEAK_DYLIB, REEXPORT_DYLIB
            o, ts, cur, comp = struct.unpack('>4I', d[q + 8:q + 24])
            ent = (c, d[q + o:q + cs].split(b'\0')[0].decode(), cur, comp)
            if c == 0xd:
                m.id_dylib = ent
            else:
                m.dylibs.append(ent)
        q += cs
    for i in range(nsyms):
        n_strx, t, sect, desc, val = struct.unpack('>IBBhI', d[symoff + 12 * i:symoff + 12 * i + 12])
        nm = d[stroff + n_strx:d.index(b'\0', stroff + n_strx)].decode('latin1') if n_strx else ''
        m.syms.append(dict(name=nm, type=t, sect=sect, desc=desc, value=val))
    if m.dysym:
        io, ni = m.dysym['indirectsymoff'], m.dysym['nindirectsyms']
        m.indirect = [struct.unpack('>I', d[io + 4 * i:io + 4 * i + 4])[0] for i in range(ni)]
    # relocation entries (dylib/bundle: local + external). r_address is relative to the first segment, or to the first writable one, depending on how the
    # image was linked (libGL: writable; the bundles: first segment). Pick the base for which the entries land on data sections.
    raw_rel = []
    if m.dysym:
        for kind, off, n in (('ext', m.dysym['extreloff'], m.dysym['nextrel']), ('loc', m.dysym['locreloff'], m.dysym['nlocrel'])):
            for i in range(n):
                w0, w1 = struct.unpack('>II', d[off + 8 * i:off + 8 * i + 8])
                raw_rel.append((kind, w0, w1))
    def _in_data(a):
        return any(s['size'] and s['addr'] <= a < s['addr'] + s['size'] and not (s['flags'] & 0x80000400) for s in m.secs)
    cands = [m.segs[0]['vmaddr'], next((s['vmaddr'] for s in m.segs if s['initprot'] & 2), m.segs[0]['vmaddr'])]
    def _score(base):
        return sum(1 for kind, w0, w1 in raw_rel if _in_data(base + ((w0 & 0xffffff) if w0 & 0x80000000 else w0)))
    wbase = max(cands, key=_score) if raw_rel else cands[0]
    m.reloc_base = wbase
    m.relocs = []
    for kind, w0, w1 in raw_rel:
        if w0 & 0x80000000:
            m.relocs.append(dict(addr=wbase + (w0 & 0xffffff), kind=kind, scattered=True, rtype=(w0 >> 24) & 0xf, length=(w0 >> 28) & 3, value=w1, symnum=None, ext=0, pcrel=(w0 >> 30) & 1))
        else:
            m.relocs.append(dict(addr=wbase + w0, kind=kind, scattered=False, rtype=w1 & 0xf, length=(w1 >> 5) & 3, value=None, symnum=w1 >> 8, ext=(w1 >> 4) & 1, pcrel=(w1 >> 7) & 1))
    # section-level relocations (MH_OBJECT files: kexts)
    m.sec_relocs = {}
    for s in m.secs:
        lst = []
        for i in range(s['nreloc']):
            w0, w1 = struct.unpack('>II', d[s['reloff'] + 8 * i:s['reloff'] + 8 * i + 8])
            if w0 & 0x80000000:
                lst.append(dict(addr=s['addr'] + (w0 & 0xffffff), scattered=True, rtype=(w0 >> 24) & 0xf, length=(w0 >> 28) & 3, value=w1, symnum=None, ext=0, pcrel=(w0 >> 30) & 1))
            else:
                lst.append(dict(addr=s['addr'] + w0, scattered=False, rtype=w1 & 0xf, length=(w1 >> 5) & 3, value=None, symnum=w1 >> 8, ext=(w1 >> 4) & 1, pcrel=(w1 >> 7) & 1))
        m.sec_relocs[(s['seg'], s['name'])] = lst
    return m


def _sec_at(self, addr):
    for s in self.secs:
        if s['size'] and s['addr'] <= addr < s['addr'] + s['size']:
            return s
    return None


def _read(self, addr, n):
    s = self.sec_at(addr)
    if s is None or (s['flags'] & 0xff) in (1, 0xc):   # S_ZEROFILL / S_GB_ZEROFILL
        return b'\0' * n
    o = s['off'] + addr - s['addr']
    return self.d[o:o + n]


Macho.sec_at = _sec_at
Macho.read = _read

SECTION_TYPE = {0: 'regular', 1: 'zerofill', 2: 'cstring', 3: '4byte', 4: '8byte', 5: 'literal_pointers', 6: 'non_lazy_ptr', 7: 'lazy_ptr', 8: 'stub', 0xb: 'coalesced', 0xc: 'gb_zerofill', 0xe: '16byte_literals'}


def sec_type(s):
    return SECTION_TYPE.get(s['flags'] & 0xff, 'type%x' % (s['flags'] & 0xff))


def is_code(s):
    return bool(s['flags'] & 0x80000000) or bool(s['flags'] & 0x400)   # S_ATTR_PURE_INSTRUCTIONS / S_ATTR_SOME_INSTRUCTIONS


def exports(m):
    """defined external, non-private symbols: [(name, addr, sect)]"""
    out = []
    for s in m.syms:
        if (s['type'] & 0x0e) == 0x0e and (s['type'] & 1) and not (s['type'] & 0x10):
            out.append((s['name'], s['value'], s['sect']))
    return out
