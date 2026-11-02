#!/usr/bin/env python3
"""fix_link_tree.py LINK_DIR - make a link_corpus.py output tree linkable now that real names exist (two passes).

link_corpus.py gives every data/function object an assembler label equal to its (Ghidra or renamed) name, written `asm("Name")` in decls.h and as a
plain label in data.s/code.s. Mach-O assemblers treat a label that starts with `L` as FILE-LOCAL ("Undefined local symbol List__freeAllNodes"): a name
like `List__freeAllNodes`, `Loop__unrollExceedsLimits` or `LoopHeader__verify` (all renames of FUN_/DAT_ names) can then be defined in one object and
never seen from another, and even the `L<name>$stub` PIC stub gets confused. Ghidra's own names (FUN_, DAT_, PTR_) never started with `L`.

This pass rewrites only the ASSEMBLER LABEL of every such name (the `asm("...")` string in decls.h/extra_decls.h and the tokens in data.s/code.s) to
`lbl_<name>`. The C identifiers in part_*.c and symbol_map.tsv are untouched, so the corpus and its gates see no change. Idempotent.

Pass 2 - biased bases. data.s defines a few names as `.set NAME, label+-N` (a base pointer the stock code indexes from, e.g. extvsOpEmitFuncTableBase_001b9d04 =
extvsOpEmitFuncTable_001dbb0c - 4*0x8782, or the gcc PIC constant-pool anchors constPoolAnchor_*, which lie outside the section of the object they are measured
from in the rebuilt image). ld64 rejects a symbol whose address is outside its section
("malformed .o file, symbol ... is not with section"), and the stock `ld` cannot link this image at all (picsymbolstub relocation overflow). Such a name is
re-defined as the label itself and every `&NAME` in part_*.c becomes `(&NAME +- N)`, which computes the same address at run time.
"""
import os, re, sys

d = sys.argv[1]
tok = re.compile(r'\bL[A-Za-z0-9_$.]*')
decl_files = [os.path.join(d, f) for f in ('decls.h', 'extra_decls.h') if os.path.exists(os.path.join(d, f))]
asm_files = [os.path.join(d, f) for f in ('data.s', 'code.s', 'aliases.s') if os.path.exists(os.path.join(d, f))]

names = set()
for f in decl_files:
    for m in re.finditer(r'asm\("(L[^"]*)"\)', open(f).read()):
        names.add(m.group(1))
for f in asm_files:
    for ln in open(f):
        m = re.match(r'\s*(?:\.globl\s+|\.set\s+|\.weak_definition\s+)?(L[A-Za-z0-9_$.]*)\s*[:,]?', ln)
        if m and (ln.rstrip().endswith(':') or ln.lstrip().startswith(('.globl', '.set'))):
            names.add(m.group(1))
# keep Apple's own local-label conventions out of the set: compiler-made labels (L1, LC0, Lfoo$stub, L_x$non_lazy_ptr, LBB...) are never in decls.h; the
# data.s/code.s scan only adds names that were DEFINED or declared there with a real name, so drop the ones that look compiler-generated
names = {n for n in names if not re.match(r'^L(\d|C\d|BB|CFI|FB|FE|etext|edata|ehs|ehe|set\d|_)', n) and '$' not in n}

def rep(m):
    return 'lbl_' + m.group(0) if m.group(0) in names else m.group(0)

for f in decl_files:
    s = open(f).read()
    s = re.sub(r'asm\("(L[^"]*)"\)', lambda m: 'asm("%s")' % (('lbl_' + m.group(1)) if m.group(1) in names else m.group(1)), s)
    open(f, 'w').write(s)
for f in asm_files:
    s = open(f).read()
    s = tok.sub(rep, s)
    open(f, 'w').write(s)
print('fix_l_labels: %d L-prefixed assembler labels renamed to lbl_<name> in %s' % (len(names), d))

# ---------------------------------------------------------------------------------------------- pass 2: biased bases
import glob
bias = {}
for f in asm_files:
    out = []
    for ln in open(f):
        m = re.match(r'^\.set\s+(\w+),\s*(\w+)([+-])(\d+)\s*$', ln)
        if m:
            bias[m.group(1)] = int(m.group(4)) * (-1 if m.group(3) == '-' else 1)   # NAME = label + bias
            out.append('.set %s, %s\n' % (m.group(1), m.group(2)))
        else:
            out.append(ln)
    open(f, 'w').write(''.join(out))
for f in sorted(glob.glob(os.path.join(d, '*.c'))):
    s = open(f).read()
    t = s
    for nm, n in bias.items():
        t = re.sub(r'&\s*%s\b' % re.escape(nm), '(&%s %s %d)' % (nm, '+' if n >= 0 else '-', abs(n)), t)
    if t != s:
        open(f, 'w').write(t)
print('fix_link_tree: %d biased base symbol(s) re-expressed in C: %s' % (len(bias), ', '.join('%s%+d' % kv for kv in bias.items())))
