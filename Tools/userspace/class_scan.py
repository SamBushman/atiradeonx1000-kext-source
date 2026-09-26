#!/usr/bin/env python3
"""class_scan.py TREE [TREE ...] - residual instances, in the linked sources (link_corpus.py output: the C that is actually compiled), of every Ghidra->C defect class found so far
(issue #68, criterion 3). Each row is one class with the pattern of the UNFIXED form; the count after the rewrites should be 0 unless the row says why not. Numbers per tree.
Usage: python3 Tools/userspace/class_scan.py work/link/b_glprog_w7 work/link/b_gld_w7 ..."""
import sys, re, os, glob

# (id, description, regex, note) - regex is searched per line of every part_*.c / x_*part_*.c
CLASSES = [
 ('C01', 'CONCAT44 built double converted numerically', r'\(double\)\s*CONCAT44\(', ''),
 ('C02', 'halfword / byte CONCATnn left as integer arithmetic (CONCAT22/CONCAT31/CONCAT13)', r'\bCONCAT(?:22|31|13|21|12)\(', 'informational: ghidra_c.h defines them as integer concatenation (correct for words)'),
 ('C03', 'byte/halfword variable minus constant compared with < (promoted to int)', r'(?<![\w.(])[bcs]Var\d+ - (?:0x[0-9a-f]+|\d+) < ', ''),
 ('C04', '64-bit shift helper called through int (*)() (high word only)', r'\(\(int \(\*\)\(\)\)___(?:lshr|ashl|ashr)di3\)', ''),
 ('C05', 'function symbol used as an operand of + / - (a field offset equal to a function address)', r'(?<![\w.>&])(?:FUN_[0-9a-f]{6,8}|thunk_FUN_[0-9a-f]+)\s*[+\-]\s*(?:\w|\()|[+\-]\s+(?:FUN_[0-9a-f]{6,8})\b(?!\s*\()', ''),
 ('C06', 'uRam / iRam / bRam absolute read of an unnamed data address', r'\b[a-z]{1,2}Ram[0-9a-f]{8}\b', ''),
 ('C07', '&MACH_HEADER.field taken as an address', r'MACH_HEADER\.', 'GLDriver _gldPageoffBuffer: a speculative read at +0x16 of a NULL pointer that Ghidra hoisted above the null test; harmless (reads the rebuilt header)'),
 ('C08', 'in_xer_* summary-overflow local left uninitialised', r'^\s*(?:byte|uchar|char|undefined1)\s+in_xer_\w+\s*;', ''),
 ('C09', 'bare NAN token (payload lost: stock words are 0x7fff0000 / 0x7fffffff ...)', r'(?<![\w"])NAN(?![\w"])', ''),
 ('C10', 'alloca (Ghidra models r1 as a variable)', r'\balloca\s*\(', 'only where patched (yyparse -> __builtin_alloca)'),
 ('C11', 'unsigned conversion of a float expression: (uint)(float op ...)', r'\(uint\)\((?:\(float\))?\s*\*?\(?(?:f|pf)Var\d+[^)<>=!]*[-+*/]', ''),
 ('C12', 'STACKARG / in_stack_ read left as an uninitialised local', r'^\s*(?:undefined\d?|int|uint|float)\s+in_stack_[0-9a-f]+\s*;', 'classified by inreg_liveness / ExtendParams'),
 ('C13', 'code-address literal formed with lis/ori kept as a symbol (packet header 0x308c0 style): FUN_ + &DAT_ masks', r'&DAT_001b0000\b', ''),
 ('C14', 'call through an unprototyped cast with a bare float-typed variable as an argument (fix_float_args / GH_ARGF should have rewritten it)', r'\(\(\w[\w ]*\s*\*?\s*\(\*\)\(\)\)\w+\)\([^;]*\b(?:fVar\d+|dVar\d+)\b[^;]*\)', 'informational: legitimate when the callee takes a float in an FPR (GH_ARGF/GH_ARGD wrap those)'),
]

def parts(tree):
    return sorted(glob.glob(os.path.join(tree, 'part_*.c')) + glob.glob(os.path.join(tree, 'x_*part_*.c')))

def scan(tree):
    res = {c[0]: [] for c in CLASSES}
    for f in parts(tree):
        for i, ln in enumerate(open(f, errors='replace'), 1):
            for cid, _d, rx, _n in CLASSES:
                if re.search(rx, ln, re.M if rx.startswith('^') else 0):
                    res[cid].append('%s:%d' % (os.path.basename(f), i))
    return res

if __name__ == '__main__':
    trees = sys.argv[1:]
    out = [scan(t) for t in trees]
    names = [os.path.basename(t.rstrip('/')) for t in trees]
    print('%-4s %-100s %s' % ('id', 'class (residual pattern)', ' '.join('%8s' % n[-14:] for n in names)))
    for cid, desc, _rx, note in CLASSES:
        print('%-4s %-100s %s%s' % (cid, desc[:100], ' '.join('%8d' % len(r[cid]) for r in out), ('   [%s]' % note) if note else ''))
    if os.environ.get('SITES'):
        for cid in os.environ['SITES'].split(','):
            for n, r in zip(names, out):
                print(cid, n, r[cid][:int(os.environ.get('N', '15'))])
