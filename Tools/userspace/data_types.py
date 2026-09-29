#!/usr/bin/env python3
"""data_types.py CORPUS_DIR [WIDTHS_JSON]      (issue #82: scalar globals declared one byte wide)

ghidra2c.py declares every data symbol that is neither a table, a pointer nor a function as `extern unsigned char DAT_x;`. Ghidra's C reads such a symbol as a
value (`iVar3 = DAT_001dbd90;`, `param_3[2] = DAT_001dbd84;`), and the stock does it with a 32-bit `lwz` - the rebuilt code did `lbz` and got the MOST significant
byte of a big-endian word (0 for every small value; found by running stock and rebuilt FUN_00090ca0 side by side in an emulator). This retypes the symbols
that are read/written bare:
  1 / 2 byte  when the stock's machine code accesses the address with lbz/stb (lhz/sth) (WIDTHS_JSON: {"0xADDR": {"width": count}} from data_widths.py),
              or the Ghidra C shows a byte context (`(char)`, `cVar = `, `== '\\0'`) and no machine-code evidence says otherwise
  4 byte      otherwise (`unsigned int` when a use is unsigned: `(uint)`, `(undefined4)`, `uVar = `; else `int`)
A symbol whose address is also taken with arithmetic (`&DAT_x + n`, no byte cast) keeps `unsigned char` unless it is only accessed by word: those uses would scale."""
import re, glob, json, os, sys, collections

def scan(corpus):
    decl = {}
    for hf in ('decls.h', 'extra_decls.h'):
        p = os.path.join(corpus, hf)
        if os.path.exists(p):
            for l in open(p):
                m = re.match(r'extern unsigned char (DAT_[0-9a-f]{8});$', l.strip())
                if m: decl[m.group(1)] = hf
    uses = collections.defaultdict(list); addr_arith = set()
    for f in sorted(glob.glob(os.path.join(corpus, 'part_*.c'))):
        s = open(f).read()
        for m in re.finditer(r'(?<![&\w])(DAT_[0-9a-f]{8})\b(?!\s*\[)', s):
            if m.group(1) in decl: uses[m.group(1)].append((s[max(0, m.start() - 60):m.start()], s[m.end():m.end() + 30]))
        for m in re.finditer(r'(?<![\w)])&\s*(DAT_[0-9a-f]{8})\s*[-+]', s):
            if m.group(1) in decl: addr_arith.add(m.group(1))
    return decl, uses, addr_arith

def ctx_width(pre, post):
    m = re.search(r'\((char|byte|uchar|undefined1|bool|short|ushort|undefined2|int|uint|undefined4|float|long|ulong|[\w ]+\s*\*+)\)\s*$', pre)
    if m: return {'char': 1, 'byte': 1, 'uchar': 1, 'undefined1': 1, 'bool': 1, 'short': 2, 'ushort': 2, 'undefined2': 2}.get(m.group(1), 4)
    m = re.search(r'\b(\w+)\s*=\s*$', pre)
    if m:
        v = m.group(1)
        if re.match(r'^(c|b|uc)Var\d*$', v): return 1
        if re.match(r'^(s|us)Var\d*$', v): return 2
    if re.match(r"\s*[!=]=\s*'", post): return 1
    return 4

def unsigned_use(pre):
    return bool(re.search(r'\((?:uint|undefined4|ulong|unsigned int)\)\s*$', pre) or re.search(r'\bu\w*Var\d*\s*=\s*$', pre))

def choose(name, uses, widths):
    mach = widths.get(hex(int(name[4:], 16))) if widths else None
    ws = collections.Counter(ctx_width(a, b) for a, b in uses)
    if mach:
        w = max(int(k) for k in mach) if set(mach) != {'1', '4'} else 4
        w = min(int(k) for k in mach) if min(int(k) for k in mach) < 4 and max(int(k) for k in mach) < 4 else max(int(k) for k in mach)
    else:
        w = 1 if (ws and set(ws) == {1}) else 2 if (ws and set(ws) == {2}) else 4
    if w == 1: return 'unsigned char'
    if w == 2: return 'unsigned short'
    return 'unsigned int' if any(unsigned_use(a) for a, b in uses) else 'int'

def main(corpus, widths_path=None):
    widths = json.load(open(widths_path)) if widths_path else {}
    decl, uses, arith = scan(corpus)
    change = {}
    for n, u in uses.items():
        t = choose(n, u, widths)
        if t != 'unsigned char':
            if n in arith: print('kept unsigned char (address arithmetic):', n); continue
            change[n] = t
    for hf in ('decls.h', 'extra_decls.h'):
        p = os.path.join(corpus, hf)
        if not os.path.exists(p): continue
        t = open(p).read()
        for n, ty in change.items(): t = re.sub(r'(?m)^extern unsigned char %s;$' % n, 'extern %s %s;' % (ty, n), t)
        open(p, 'w').write(t)
    print(len(change), 'symbols retyped', collections.Counter(change.values()))
if __name__ == '__main__': main(*sys.argv[1:3])
