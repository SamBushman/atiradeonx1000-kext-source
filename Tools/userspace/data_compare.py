#!/usr/bin/env python3
"""data_compare.py STOCK_SLICE STOCK_DATA.tsv STOCK_RANGES.tsv REBUILT.out REBUILT_NM.txt [OUT.tsv] - compare the initialised data of a rebuilt image with the stock's (issue #72, criterion 1).

Every data object of the stock's table (`*_data.tsv`: Ghidra name, address, length; the link tree emits each one under the SAME label) that lies in a section with contents is read from the stock
slice and from the rebuilt image (label address from `nm`, bytes through the rebuilt Mach-O's section table) and compared word by word:
  * equal words are equal;
  * a word that is an ADDRESS in both images is a pointer: it is compared by TARGET - (nearest symbol, offset), symbols matched by name (leading underscores ignored) - because every pointer
    moves when the layout does; an address in one image and a plain number in the other is a difference;
  * anything else that differs is a difference.
Symbols of the stock: the data table's objects and the function entries of RANGES.tsv; of the rebuilt image: every `nm` symbol. Zerofill sections compare as zero.
Prints per-section totals and the differing objects (first differing word); OUT.tsv gets one row per differing object."""
import sys, struct, re, bisect, collections
stock_p, tsv, ranges, reb_p, nm_p = sys.argv[1:6]; out_p = sys.argv[6] if len(sys.argv) > 6 else None

def macho(path):
    d = open(path, 'rb').read(); nc = struct.unpack('>I', d[16:20])[0]; p = 28; secs = []
    for _ in range(nc):
        c, cs = struct.unpack('>II', d[p:p + 8])
        if c == 1:
            ns = struct.unpack('>I', d[p + 48:p + 52])[0]; q = p + 56
            for _ in range(ns):
                seg = d[q + 16:q + 32].split(b'\0')[0].decode(); nm = d[q:q + 16].split(b'\0')[0].decode()
                a, sz, off, al, ro, nr, fl = struct.unpack('>7I', d[q + 32:q + 60]); secs.append(dict(seg=seg, name=nm, addr=a, size=sz, off=off, type=fl & 0xff)); q += 68
        p += cs
    return d, secs

def relocs(path):
    """{address: (symbol name, extern)} of the external relocations of a linked image (a word that is 0 on disk and bound by dyld to a symbol)"""
    d = open(path, 'rb').read(); nc = struct.unpack('>I', d[16:20])[0]; p = 28; sym = dsym = None
    for _ in range(nc):
        c, cs = struct.unpack('>II', d[p:p + 8])
        if c == 2: sym = struct.unpack('>4I', d[p + 8:p + 24])
        if c == 0xb: dsym = struct.unpack('>18I', d[p + 8:p + 80])
        p += cs
    out = {}
    if not sym or not dsym: return out
    symoff, nsyms, stroff, strsize = sym
    def name(i):
        strx = struct.unpack('>I', d[symoff + 12 * i:symoff + 12 * i + 4])[0]; e = d.index(b'\0', stroff + strx); return d[stroff + strx:e].decode()
    extreloff, nextrel = dsym[14], dsym[15]
    for i in range(nextrel):
        a, w = struct.unpack('>II', d[extreloff + 8 * i:extreloff + 8 * i + 8])
        if a & 0x80000000: continue
        symnum = w >> 8; ext = (w >> 4) & 1
        if ext: out[a] = name(symnum)
    return out

def read(d, secs, addr, n):
    for s in secs:
        if s['addr'] <= addr and addr + n <= s['addr'] + s['size']:
            if s['type'] in (1, 0xc): return bytes(n)           # zerofill / gb zerofill
            return d[s['off'] + addr - s['addr']: s['off'] + addr - s['addr'] + n]
    return None

_dm = {}
def demangle_all(names):
    import subprocess
    todo = sorted(set(n for n in names if re.match(r'_{0,2}Z[NTKSL0-9]', n.lstrip('_') and n) and n not in _dm))
    if todo:
        out = subprocess.run(['c++filt'], input='\n'.join('_' + n.lstrip('_') if not n.startswith('_Z') else n for n in todo), capture_output=True, text=True).stdout.split('\n')
        for n, o in zip(todo, out): _dm[n] = o
def _clean(o):
    o = re.sub(r'std::basic_string<char, std::char_traits<char>, (?:__gnu_cxx::)?pool_allocator<char> >', 'std::string', o)
    o = re.sub(r'std::basic_string<char, std::char_traits<char>, std::allocator<char> >', 'std::string', o)
    o = re.sub(r'^(?:vtable|typeinfo|typeinfo name|guard variable) for ', lambda m: '', o)
    d = 0; out = ''
    for ch in o:                                     # drop the parameter list: everything from the first top-level '(' on
        if ch == '<': d += 1
        if ch == '>': d -= 1
        if ch == '(' and d == 0: break
        out += ch
    return out.strip()
def norm(n):
    n2 = n.lstrip('_')
    if n in _dm: return _clean(_dm[n]).replace('::', '__')            # Ghidra's C++ names are sanitised: `TIntermUnary__promote`
    return n2.replace('::', '__')

sd, ss = macho(stock_p); rd, rs = macho(reb_p); rrel = relocs(reb_p)
SKIP = {'__la_symbol_ptr', '__nl_symbol_ptr', '__dyld', '__picsymbol_stub', '__picsymbolstub1', '__symbol_stub', '__text', '__textcoal_nt', '__eh_frame', '__gcc_except_tab', '__LINKEDIT', '__jump_table'}
# stock symbols: (addr, size, name)
objs = []; ssyms = []
for l in open(tsv):
    f = l.rstrip('\n').split('\t')
    if len(f) < 5 or not f[0].startswith('0x') or f[2] == '-': continue
    try: a = int(f[0], 16)
    except ValueError: continue
    try: n = int(f[4])
    except ValueError: n = 0                       # length unknown ('-'): still a labelled anchor
    objs.append((a, n, f[2], f[1])); ssyms.append((a, max(n, 1), f[2]))
for l in open(ranges):
    f = l.rstrip('\n').split('\t')
    if len(f) > 3:
        for r in f[3].split(';'):
            if r: lo, hi = (int(x, 16) for x in r.split('-')); ssyms.append((lo, hi - lo, f[1]))
import os
sm = os.environ.get('SYMMAP')                          # the link tree's symbol_map.tsv: every data label the emitter defined (with its stock address) - more anchors than the data table
if sm:
    have = set(o[2] for o in objs)
    for l in open(sm):
        f = l.rstrip('\n').split('\t')
        if len(f) > 7 and f[1].startswith('0x') and f[7] == 'data.s' and f[0] not in have:
            try: n = int(f[4])
            except ValueError: n = 0
            objs.append((int(f[1], 16), n, f[0], f[2].split(',')[-1]))
lg = os.environ.get('LEDGER')
if lg:
    for l in open(lg):
        f = l.rstrip('\n').split('\t')
        if len(f) > 2 and f[0].startswith('0x'):
            try: ssyms.append((int(f[0], 16), int(f[1]), f[2]))
            except ValueError: pass
ssyms.sort(); sa = [x[0] for x in ssyms]; known = set(norm(x[2]) for x in ssyms)
def stock_names(v):
    # every symbol that starts exactly at v (aliases: a clipped entry inside another function, a vtable and its first slot ...)
    i = bisect.bisect_left(sa, v); out = set()
    while i < len(sa) and sa[i] == v: out.add(norm(ssyms[i][2])); i += 1
    return out
def sec_of(secs, v): return next((s for s in secs if s['addr'] <= v < s['addr'] + max(s['size'], 1) and s['seg'] != '__LINKEDIT'), None)
def stock_target(v):
    # nearest preceding symbol of the same section (a pointer into the middle of an object is (object, offset); the rebuilt image lays the same objects out in the same order)
    sec = sec_of(ss, v); i = bisect.bisect_right(sa, v) - 1
    while i >= 0 and (sec is None or ssyms[i][0] >= sec['addr']) :
        if ssyms[i][0] <= v: return (norm(ssyms[i][2]), v - ssyms[i][0])
        i -= 1
    return None
rsyms = []
for l in open(nm_p):
    m = re.match(r'([0-9a-f]{8}) (\w) (\S+)', l)
    if m and m.group(2) in 'tTdDbBsS': rsyms.append((int(m.group(1), 16), m.group(3)))
demangle_all([n for _, n in rsyms] + list(rrel.values()))
rsyms.sort(); ra = [x[0] for x in rsyms]; rname = {}
for a, n in rsyms: rname.setdefault(norm(n), a)
def reb_targets(v):
    """[(name, offset)] for every label at the nearest preceding address of the same section"""
    sec = sec_of(rs, v); i = bisect.bisect_right(ra, v) - 1
    if i < 0 or sec is None or ra[i] < sec['addr']: return []
    out = []; j = i
    while j >= 0 and ra[j] == ra[i]: out.append((norm(rsyms[j][1]), v - ra[j])); j -= 1
    return out
def cstr(d, secs, v):
    sec = sec_of(secs, v)
    if not sec or sec['name'] != '__cstring': return None
    o = sec['off'] + v - sec['addr']; e = d.index(b'\0', o); return d[o:e]
def implied_stock_addr(t):
    """Ghidra names embed the stock address (`DAT_001ada48`, `FUN_001d8874`, `orph_1d8910`, `s_x_001a6a00`, `PTR_..._001e9778`): label + offset = the stock address the pointer had"""
    m = re.search(r'(?:^|_)([0-9a-f]{6,8})$', t[0]) if t else None
    return int(m.group(1), 16) + t[1] if m else None
def in_image(secs, v): return any(s['addr'] <= v < s['addr'] + max(s['size'], 1) for s in secs if s['seg'] != '__LINKEDIT')

anchors = collections.defaultdict(list)                       # stock section -> sorted [(stock addr, rebuilt addr)] of labelled objects
for a, n, nm, sec in objs:
    s_ = next((x for x in ss if x['addr'] <= a < x['addr'] + x['size']), None)
    if s_ and rname.get(norm(nm)) is not None: anchors[s_['name']].append((a, rname[norm(nm)]))
for k in anchors: anchors[k].sort()
def anchor_addr(secname, a):
    """the rebuilt address of an unlabelled stock object: the nearest preceding labelled object of its section fixes the (stock -> rebuilt) displacement; the emitter keeps a section's objects in order"""
    l = anchors.get(secname); 
    if not l: return None
    i = bisect.bisect_right([x[0] for x in l], a) - 1
    j = i if i >= 0 else 0                             # before the first anchor: extrapolate its displacement backwards
    return a + (l[j][1] - l[j][0])
stat = collections.defaultdict(lambda: collections.Counter()); bad = []; absent = []
for a, n, nm, sec in objs:
    s = next((x for x in ss if x['addr'] <= a < x['addr'] + x['size']), None)
    if not s or s['name'] in SKIP or n <= 0: continue
    ra_ = rname.get(norm(nm)); located = False
    if ra_ is None and s['name'] not in ('__cstring', '__literal4', '__literal8'):
        ra_ = anchor_addr(s['name'], a); located = ra_ is not None
    if ra_ is None:
        # no label of that name in the rebuilt image: is the CONTENT there (a C string in the compiler's literal pool, a table the C compiler emitted under its own name)?
        sb = read(sd, ss, a, n)
        if sb is not None and (n >= 4 or s['name'] == '__cstring') and any(x['type'] not in (1, 0xc) and x['seg'] != '__LINKEDIT' and rd.find(sb, x['off'], x['off'] + x['size']) >= 0 for x in rs if x['size']):
            stat[s['name']]['no label, content present'] += 1
        else:
            stat[s['name']]['no label, content ABSENT'] += 1; absent.append((nm, s['name'], a, n, sb[:24] if sb else b''))
        continue
    sb = read(sd, ss, a, n); rb = read(rd, rs, ra_, n)
    if sb is None or rb is None: stat[s['name']]['unreadable'] += 1; continue
    tag = ' (located by anchor)' if located else ''
    if sb == rb: stat[s['name']]['identical' + tag] += 1; continue
    diff = None; ptr = 0; unver = 0
    for i in range(0, n - n % 4, 4):
        w1, = struct.unpack('>I', sb[i:i + 4]); w2, = struct.unpack('>I', rb[i:i + 4])
        if w1 == w2: continue
        rel = rrel.get(ra_ + i)
        if rel is not None and in_image(ss, w1) and w2 < 0x10000:           # bound by dyld to a symbol: the symbol is the target
            t1 = stock_target(w1)
            if t1 and t1[0] == norm(rel) and t1[1] == w2: ptr += 1; continue
            ia = implied_stock_addr((norm(rel), w2))
            if ia == w1: ptr += 1; continue
            if norm(rel) not in known: unver += 1; continue
            diff = (i, w1, w2, t1, ('reloc', rel)); break
        if in_image(ss, w1) and in_image(rs, w2):
            c1, c2 = cstr(sd, ss, w1), cstr(rd, rs, w2)
            if c1 is not None and c2 is not None:          # a pointer to a C string: the string is the identity (the rebuilt image pools them anonymously)
                if c1 == c2: ptr += 1; continue
                diff = (i, w1, w2, c1[:24], c2[:24]); break
            t1, t2s = stock_target(w1), reb_targets(w2)
            aliases = stock_names(w1)
            if any((t1 and t == t1) or implied_stock_addr(t) == w1 or (t[1] == 0 and t[0] in aliases) for t in t2s): ptr += 1; continue
            if t1 is None and t2s: unver += 1; continue     # the stock has no symbol there: not verifiable by name
            if t2s and all(t[0] not in known for t in t2s): unver += 1; continue    # the rebuilt target is a real symbol (vtable, clipped entry, libstdc++ object) the stock table has no name for
            t2 = t2s[0] if t2s else None
            diff = (i, w1, w2, t1, t2); break
        diff = (i, w1, w2, None, None); break
    if diff is None and n % 4 and sb[n - n % 4:] != rb[n - n % 4:]: diff = (n - n % 4, 0, 0, 'tail', 'tail')
    if diff is None: stat[s['name']]['same up to pointer targets' + (' (%d unverified)' % unver if unver else '') + tag] += 1
    else: stat[s['name']]['DIFFERENT' + tag] += 1; bad.append((nm, s['name'], a, n, diff))
for sec in sorted(stat): print('%-14s %s' % (sec, ', '.join('%d %s' % (v, k) for k, v in sorted(stat[sec].items()))))
print('%d objects differ, %d without a label whose content is absent from the rebuilt image' % (len(bad), len(absent)))
if os.environ.get('ABSENT'):
    with open(os.environ['ABSENT'], 'w') as f:
        for nm, sec, a, n, b in absent: f.write('%s\t%s\t0x%x\t%d\t%s\n' % (nm, sec, a, n, b.hex()))
if out_p:
    with open(out_p, 'w') as f:
        for nm, sec, a, n, (i, w1, w2, t1, t2) in bad: f.write('%s\t%s\t0x%x\t%d\t+%d\t%08x\t%08x\t%s\t%s\n' % (nm, sec, a, n, i, w1, w2, t1, t2))
else:
    for nm, sec, a, n, (i, w1, w2, t1, t2) in bad[:40]: print('  %s (%s 0x%x, %d bytes) word +%d: stock %08x %s | rebuilt %08x %s' % (nm, sec, a, n, i, w1, t1, w2, t2))
