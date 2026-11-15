#!/usr/bin/env python3
"""int_global_float_audit.py [ROOT=Userspace] - find globals declared as an integer type whose C reads look like float arithmetic (defect class of #286).

#286: GLEngine declared the float statics _vcoeff_c / _uvalue_c ... as `extern int`; the C then read `_vcoeff_c * fVar1` or `(double)_uvalue_c`, which converts the INTEGER value of the
float word (lwz + magic-double subtraction) instead of reading the float. Stores of a float into such a global came out as bit copies, so reads and writes disagreed.
For every `extern <integer type> NAME;` (a data symbol: no parentheses) in */ppc/decls.h and */ppc/extra_decls.h the C of that corpus is scanned for statements that use NAME (also as
`(&NAME)[i]`, `*(&NAME + i)`) outside GH_U2F(...)/GH_F2U(...) and outside `&NAME`, in a float context:
  FLT    the statement multiplies / divides / adds NAME with a float-looking token (fVar*, dVar*, fparam_*, FLOAT_*, DOUBLE_*, a float literal, a (float)/(double) cast)
  CAST   `(float)NAME` / `(double)NAME` (an integer to float conversion of a global)
A hit is a CANDIDATE: check the stock disassembly (lfs/lfd at the symbol -> real defect; lwz + fcfid-style magic -> a true integer). Output: tab separated `KIND file:line symbol statement`.
Exit status 1 when anything is found."""
import re, glob, sys

INT = r'(?:int|uint|long|ulong|short|ushort|char|uchar|byte|undefined\d*|dword|word)'
DECL = re.compile(r'^extern\s+(?:unsigned\s+)?' + INT + r'\s+(?:\*\s*)?([A-Za-z_]\w*)\s*(?:\[[^\]]*\])?\s*(?:asm\([^)]*\))?\s*;')
FLOATISH = re.compile(r'\b(?:fVar\w*|dVar\w*|fparam_\d+|FLOAT_[0-9a-f]+|DOUBLE_[0-9a-f]+|fResult\w*|f[A-Z]\w*)\b|\b\d+\.\d+f?\b|\(\s*(?:float|double)\s*\)')


def main(root):
    found = 0
    for corpus in sorted(glob.glob(root + '/*/ppc')):
        syms = set()
        for h in ('decls.h', 'extra_decls.h'):
            try:
                for ln in open(corpus + '/' + h, errors='replace'):
                    m = DECL.match(ln.strip())
                    if m and '(' not in ln.split(';')[0]:
                        syms.add(m.group(1))
            except OSError:
                pass
        if not syms:
            continue
        alt = '|'.join(sorted(map(re.escape, syms), key=len, reverse=True))
        # a plain read of NAME, or an indexed read `(&NAME)[i]` (the address form alone, `&NAME`, is a pointer and is skipped)
        pat = re.compile(r'(?<![\w&])(' + alt + r')\b|\(\s*&\s*(' + alt + r')\s*\)\s*\[')
        for f in sorted(glob.glob(corpus + '/part_*.c')):
            for i, ln in enumerate(open(f, errors='replace'), 1):
                if 'GH_U2F' in ln and 'GH_U2F' in ln.split(')')[0] and False:
                    continue
                for m in pat.finditer(ln):
                    name = m.group(1) or m.group(2)
                    pre = ln[:m.start()]
                    # skip when the read is already wrapped in a bit-cast
                    if re.search(r'GH_U2F\s*\(\s*\(unsigned int\)\s*\(*\s*\(*&?$', pre) or re.search(r'GH_U2F\s*\([^;]*$', pre) and 'GH_U2F' in pre[-60:]:
                        continue
                    if re.match(r'\s*=[^=]', ln[m.end():]) and not re.search(r'\w\s*$', pre.rstrip()[-1:]):
                        pass
                    post = ln[m.end():]
                    if m.group(2):
                        post = post.split(']', 1)[-1]        # indexed read: the operator follows the closing bracket
                    cast = re.search(r'\(\s*(float|double)\s*\)\s*\(*\s*$', pre)
                    if cast:
                        print('CAST\t%s:%d\t%s\t%s' % (f.split('/Userspace/')[-1] if '/Userspace/' in f else f, i, name, ln.strip()[:160])); found += 1
                        continue
                    stmt = ln.strip()
                    if re.search(r'[*/+-]', pre[-3:] + post[:3]) and FLOATISH.search(stmt):
                        print('FLT\t%s:%d\t%s\t%s' % (f, i, name, stmt[:160])); found += 1
    return 1 if found else 0


if __name__ == '__main__':
    sys.exit(main(sys.argv[1] if len(sys.argv) > 1 else 'Userspace'))
