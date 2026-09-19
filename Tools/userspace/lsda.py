#!/usr/bin/env python3
"""lsda.py SLICE LEDGER.tsv OUT.tsv - decode __eh_frame (FDEs) and the __gcc_except_tab LSDAs of a Mach-O PPC binary into the table that says which
call ranges of which function transfer control to which C++ landing pad, and what the pad does (cleanup, or catch of a typeinfo).
Columns: function addr, function name, call-site lo, hi, landing pad addr, action (cleanup | catch <typeinfo> | catch-all | exception-spec ...)."""
import sys, struct, re
d = open(sys.argv[1], 'rb').read(); E = '>'
nc = struct.unpack(E + 'I', d[16:20])[0]; q = 28; secs = {}; segs = []; symoff = nsyms = stroff = 0
for _ in range(nc):
    c, cs = struct.unpack(E + 'II', d[q:q + 8])
    if c == 1:
        ns = struct.unpack(E + 'I', d[q + 48:q + 52])[0]; r = q + 56
        for _ in range(ns):
            nm = d[r:r + 16].rstrip(b'\0').decode(); a, sz, off = struct.unpack(E + '3I', d[r + 32:r + 44]); r += 68
            secs[nm] = (a, sz, off); segs.append((a, a + sz, off))
    elif c == 2: symoff, nsyms, stroff, strsize = struct.unpack(E + '4I', d[q + 8:q + 24])
    q += cs
def foff(a):
    for lo, hi, off in segs:
        if lo <= a < hi: return off + a - lo
    raise KeyError(hex(a))
names = {}
for i in range(nsyms):
    n_strx, t, sect, desc, val = struct.unpack(E + 'IBBhI', d[symoff + 12 * i:symoff + 12 * i + 12])
    if val and (t & 0x0e) == 0x0e:
        s = d[stroff + n_strx:d.index(b'\0', stroff + n_strx)].decode('latin1'); names.setdefault(val, s)
led = {}
for l in open(sys.argv[2]):
    f = l.rstrip('\n').split('\t')
    if len(f) > 4: led[int(f[0], 16)] = f[2]
class R:
    def __init__(s, off): s.o = off
    def u8(s): v = d[s.o]; s.o += 1; return v
    def u16(s): v = struct.unpack(E + 'H', d[s.o:s.o + 2])[0]; s.o += 2; return v
    def u32(s): v = struct.unpack(E + 'I', d[s.o:s.o + 4])[0]; s.o += 4; return v
    def s32(s): v = struct.unpack(E + 'i', d[s.o:s.o + 4])[0]; s.o += 4; return v
    def uleb(s):
        r = sh = 0
        while True:
            b = d[s.o]; s.o += 1; r |= (b & 0x7f) << sh; sh += 7
            if not b & 0x80: return r
    def sleb(s):
        r = sh = 0
        while True:
            b = d[s.o]; s.o += 1; r |= (b & 0x7f) << sh; sh += 7
            if not b & 0x80:
                if b & 0x40: r -= 1 << sh
                return r
def vmaddr(off):   # file offset -> vm address
    for lo, hi, o in segs:
        if o <= off < o + (hi - lo): return lo + off - o
    return 0
def rd_enc(rd, enc, zero_none=False):
    if enc == 0xff: return None
    at = vmaddr(rd.o); f = enc & 0x0f
    v = {0x00: rd.u32, 0x01: rd.uleb, 0x02: rd.u16, 0x03: rd.u32, 0x09: rd.sleb, 0x0b: rd.s32, 0x0a: lambda: struct.unpack(E + 'h', bytes([d[rd.o], d[rd.o + 1]])), }[f]()
    if f == 0x0a: rd.o += 2; v = v[0]
    if zero_none and v == 0: return None
    if enc & 0x70 == 0x10: v += at
    return v & 0xffffffff
ehs = secs['__eh_frame']; ehend = ehs[2] + ehs[1]; rd = R(ehs[2]); cies = {}; fdes = []
while rd.o < ehend:
    start = rd.o; ln = rd.u32()
    if ln == 0: break
    body = rd.o; idp = rd.u32()
    if idp == 0:   # CIE
        ver = rd.u8(); aug = b''
        while d[rd.o]: aug += bytes([d[rd.o]]); rd.o += 1
        rd.o += 1; aug = aug.decode(); rd.uleb(); rd.sleb(); rd.u8() if ver == 1 else rd.uleb()
        info = {'aug': aug, 'R': 0, 'L': 0xff}
        if aug.startswith('z'):
            al = rd.uleb(); ae = rd.o + al
            for ch in aug[1:]:
                if ch == 'R': info['R'] = rd.u8()
                elif ch == 'L': info['L'] = rd.u8()
                elif ch == 'P': pe = rd.u8(); rd_enc(rd, pe & 0x7f)
            rd.o = ae
        cies[start] = info
    else:
        cie = cies.get(body - idp)
        if cie:
            pc = rd_enc(rd, cie['R']); rng = rd_enc(rd, cie['R'] & 0x0f); lsda = None
            if cie['aug'].startswith('z'):
                al = rd.uleb(); ae = rd.o + al
                if 'L' in cie['aug'] and al: lsda = rd_enc(rd, cie['L'], True)
                rd.o = ae
            fdes.append((pc, rng, lsda))
    rd.o = body + ln
rows = []; nfde = 0; nl = 0
for pc, rng, lsda in fdes:
    nfde += 1
    if not lsda: continue
    nl += 1; r = R(foff(lsda)); lp_enc = r.u8(); lpstart = pc
    if lp_enc != 0xff: lpstart = rd_enc(r, lp_enc)
    tt_enc = r.u8(); tt_base = None
    if tt_enc != 0xff: ttoff = r.uleb(); tt_base = r.o + ttoff
    cs_enc = r.u8(); cs_len = r.uleb(); cs_end = r.o + cs_len; cs_start = r.o
    # action table follows the call-site table
    act_start = cs_end
    calls = []
    while r.o < cs_end:
        s = rd_enc(r, cs_enc & 0x0f); l = rd_enc(r, cs_enc & 0x0f); lp = rd_enc(r, cs_enc & 0x0f); act = r.uleb()
        calls.append((pc + s, pc + s + l, (lpstart + lp) if lp else 0, act))
    def action_text(act):
        if act == 0: return 'cleanup'
        outs = []; p = act_start + act - 1; seen = 0
        while seen < 16:
            ar = R(p); filt = ar.sleb(); nxt_pos = ar.o; nxt = ar.sleb(); seen += 1
            if filt > 0 and tt_base is not None:
                tr = R(tt_base - filt * 4); ptr = rd_enc(tr, tt_enc & 0x7f if tt_enc != 0xff else 0)
                outs.append('catch ' + (names.get(ptr, hex(ptr)) if ptr else 'catch-all'))
            elif filt == 0: outs.append('cleanup')
            else: outs.append('exception-spec')
            if nxt == 0: break
            p = nxt_pos + nxt
        return ' | '.join(outs)
    for lo, hi, lp, act in calls:
        rows.append((pc, lo, hi, lp, action_text(act) if lp else 'no-handler'))
with open(sys.argv[3], 'w') as f:
    f.write('function\tname\tcall_lo\tcall_hi\tlanding_pad\taction\n')
    for pc, lo, hi, lp, act in rows:
        f.write('%x\t%s\t%x\t%x\t%s\t%s\n' % (pc, led.get(pc, names.get(pc, '?')), lo, hi, ('%x' % lp) if lp else '-', act))
print('%d FDEs, %d with an LSDA, %d call-site rows, %d with a landing pad' % (nfde, nl, len(rows), sum(1 for r in rows if r[3])))
